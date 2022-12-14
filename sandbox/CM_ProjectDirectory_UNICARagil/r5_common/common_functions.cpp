#include "common_functions.h"
#include <cmath>
#ifdef RUN_ON_R5
#include "ptpd.h"
#include "sleep.h"
#include "time.h"
#endif


void common_func::limitTorqueRequest(common_def::dynState &dyn_state, common_def::setpointDM &DMValues, int DMnumber) {

    double* torque_value_Nm;

    switch (DMnumber) {

        case 1:

            torque_value_Nm = &DMValues.torque.DM_1;
            break;

        case 2:

            torque_value_Nm = &DMValues.torque.DM_2;
            break;

        case 3:

            torque_value_Nm = &DMValues.torque.DM_3;
            break;

        case 4:

            torque_value_Nm = &DMValues.torque.DM_4;
            break;

    }

    // Only limiting when wheel is actually requested to move.
    if (dyn_state.spin_direction != 0) {
        // NOTE: Assumes only positive values in dyn_state.max_drive_trq_Nm and dyn_state.max_regen_brake_trq_Nm.
        // Thus not depending on spinning direction of wheel!

        // Drive limit
        if (*torque_value_Nm * dyn_state.spin_direction > dyn_state.max_drive_trq_Nm && std::round(dyn_state.max_drive_trq_Nm) != 0) {
            *torque_value_Nm = dyn_state.max_drive_trq_Nm * dyn_state.spin_direction;
        }

        // Brake limit
        else if (*torque_value_Nm * dyn_state.spin_direction < - dyn_state.max_brake_trq_Nm && std::round(dyn_state.max_brake_trq_Nm) != 0) {
            *torque_value_Nm = - dyn_state.max_brake_trq_Nm * dyn_state.spin_direction;
        }
    }

}

#ifdef RUN_ON_R5
double common_func::getTimePTP() {

	TimeInternal timeTmp;
	getTime(&timeTmp);
	double current_time = double(timeTmp.seconds) + double(timeTmp.nanoseconds) / 1e9;

	return current_time;

}

taitime common_func::getTimePTP_TAI() {

	TimeInternal timeTmp;
	getTime(&timeTmp);
	taitime current_time;
	current_time.tai_seconds = double(timeTmp.seconds);
	current_time.tai_nanoseconds = double(timeTmp.nanoseconds);

	return current_time;

}

bool common_func::dataIsSync(taitime &data_ts, const double max_age) {

    double curr_time = common_func::getTimePTP();
    if (std::abs(curr_time - (data_ts.tai_seconds + data_ts.tai_nanoseconds / 1e9)) >= max_age) return false;
    else return true;

}
#endif
