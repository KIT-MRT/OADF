#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include "common_definitions.h"


namespace common_func {

/**
 * Limit the calculated torque request.
 *
 * @param dyn_state Value container of state guarantee provided by dynamic module service.
 * @param DMValues Value container of data to be sent to dynamic modules. Calculated torque to be limited is written here.
 * @param DMnumber Index dedicated to respective dynamic module.
 *
 */
    void limitTorqueRequest (common_def::dynState &dyn_state, common_def::setpointDM &DMValues, int DMnumber);


/**
 * Get current time from PTP demon on R5.
 *
 * @return double.
 */
    double getTimePTP();


/**
 * Get current time from PTP demon on R5.
 *
 * @return taitime.
 */
    taitime getTimePTP_TAI();


/**
 * Compare timestamp of received data with current time.
 *
 * @param data_ts Timestamp of received data in taitime.
 * @param max_age Maximum allowed age of received data.
 *
 * @return True if timestamp of data is within accepted margin.
 */
    bool dataIsSync(taitime &data_ts, const double max_age);

}

#endif //COMMON_FUNCTIONS_H
