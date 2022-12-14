#ifndef FTR_DEFINITIONS_H
#define FTR_DEFINITIONS_H

#include "../unicar-definitions/UNICAR_definitions.h"


// Struct for integration of pose errors
typedef struct pos_Err {

	double lat;
	double lon;
	double yaw;

} pos_Err;


// Setpoint values for actuators
typedef struct setpointDM {

	struct steering {
		float angle_DM_1;
		float angle_DM_2;
		float angle_DM_3;
		float angle_DM_4;
	} steering;

	struct drive {
		float trq_DM_1;
		float trq_DM_2;
		float trq_DM_3;
		float trq_DM_4;

		float speed_lim_DM_1;
		float speed_lim_DM_2;
		float speed_lim_DM_3;
		float speed_lim_DM_4;

		float wheel_acc_DM_1;
		float wheel_acc_DM_2;
		float wheel_acc_DM_3;
		float wheel_acc_DM_4;

	} drive;

	struct brake {
		float trq_DM_1;
		float trq_DM_2;
		float trq_DM_3;
		float trq_DM_4;
		bool parking_brake_active;
	} brake;

	bool sideways_parking_active;

} setpointDM;

// State of dynamic module
typedef struct dynState {

		uint8_t frame_counter;
		uint64_t tai_seconds;
		uint32_t tai_nanoseconds;
		float drive_torque_Nm;
		float drive_speed_rad_s;
		float continuous_drive_torque_Nm;
		float max_drive_torque_Nm;
		float max_brake_torque_Nm;
		float brake_torque_Nm;
		float max_regen_brake_torque_Nm;
		float steering_torque_nm;
		float steering_angle_rad;
		float max_steering_angle_velocity_rad_s;

} dynState;


// Struct for interpolated trajectory
typedef struct trajInterpolated {

	struct pos {
		double east;
		double north;
		double yaw;
	} pos;

	struct vel {
		double mag;
		double angle;
		double yaw;
	} vel;

	struct acc {
		double mag;
		double angle;
		double yaw;
	} acc;

	// Lateral look-ahead elements for FF control
	struct la_lat {

		struct pos {
			double east;
			double north;
			double yaw;
		} pos;

		struct vel {
			double mag;
			double angle;
			double yaw;
		} vel;

		struct acc {
			double mag;
			double angle;
			double yaw;
		} acc;

	} la_lat;

	// Longitudinal look-ahead elements for FF control
	struct la_lon {

		struct pos {
			double east;
			double north;
			double yaw;
		} pos;

		struct vel {
			double mag;
			double angle;
			double yaw;
		} vel;

		struct acc {
			double mag;
			double angle;
			double yaw;
		} acc;

	} la_lon;

	struct misc {
		uint8_t standstill;
		uint8_t parking;
		double slope_long;
		double slope_lat;
		int run_direction = 1;
		uint16_t use_previous_trj;
		uint16_t use_atlatec;
	} misc;


} trajInterpolated;


// Struct for current state of the vehicle
typedef struct unicarState {

	struct pos {
		double east;
		double north;
		double lat;
		double lon;
		double h;
		double yaw;
	} pos;

	struct vel {
		double east;
		double north;
		double yaw;
	} vel;

	struct acc {
		double east;
		double north;
	} acc;

	struct misc {
		taitime time;
        uint8_t frame;
        uint8_t status;
	} misc;

} unicarState;


// Struct for vehicle pose for offset calculation
typedef struct offsetState {

	double lat;
	double lon;
	double h;
	double yaw;
	taitime time;

} offsetState;


// Struct for vehicle pose offset
typedef struct poseOffset {

	double delta_east;
	double delta_north;
	double delta_yaw;

} poseOffset;


// Force for vehicle
typedef struct forces {

	double F_lon;
	double F_lat;
	double M_z;

} forces;

// Forces for each wheel
typedef struct wheelForces {

	struct wheelFL {
		double F_x;
		double F_y;
	} wheelFL;

	struct wheelFR {
		double F_x;
		double F_y;
	} wheelFR;

	struct wheelRL {
		double F_x;
		double F_y;
	} wheelRL;

	struct wheelRR {
		double F_x;
		double F_y;
	} wheelRR;


} wheelForces;


// Struct for current control deviation of FTR
typedef struct controlDiff {

	struct pos {
		double lat;
		double lon;
		double yaw;
	} pos;

	struct vel {
		double lat;
		double lon;
		double yaw;
	} vel;

	struct acc {
		double lat;
		double lon;
	} acc;
} controlDiff;


/*************************************************************************
@struct trajENU_array
@brief Structure for trajENU
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct trajENU_array {

    /*************************************************************************
    @brief Timestamp of sending time for trajENU (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for trajENU (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Reference trajectory time array (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t tai_seconds[50];

    /*************************************************************************
    @brief Reference trajectory time array (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t tai_nanoseconds[50];

	/*************************************************************************
	@brief Flag to distinguish whether this trajectory was planned using previous trajectory or the current vehicle pose
	@details 0 - current vehicle pose used, 1 - previous trajectory used
	@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
	@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 27.04.2022
	*************************************************************************/
	uint16_t use_previous_trj;

	/*************************************************************************
	@brief Flag to distinguish whether atlatec localization or FZS localization was used to plan this trajectory
	@details 0 - FZS localization used, 1 - atlatec localization used
	@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
	@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 27.04.2022
	*************************************************************************/
	uint16_t use_atlatec;

    /*************************************************************************
    @brief Standstill flag
    @details Can be 0 (no vehicle standstill) or 1 (vehicle standstill)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint16_t standstill[50];

    /*************************************************************************
    @brief Parking flag
    @details Can be 0 (no sideways parking) or 1 (prepare for sideways parking)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint16_t parking[50];

    /*************************************************************************
    @brief Reference trajectory east in local ENU coordinates
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double pos_enu_east_m[50];

    /*************************************************************************
    @brief Reference trajectory north in local ENU coordinates
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double pos_enu_north_m[50];

    /*************************************************************************
    @brief Reference trajectory planning latitude in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_lat_rad;

    /*************************************************************************
    @brief Reference trajectory planning longitude in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_lon_rad;

    /*************************************************************************
    @brief Reference trajectory planning height in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_h_m;

    /*************************************************************************
    @brief Reference trajectory planning vehicle orientation in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_ori_enu_psi_rad;

    /*************************************************************************
    @brief Timestamp of planning pose (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t plan_tai_seconds;

    /*************************************************************************
    @brief Timestamp of planning pose (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t plan_tai_nanoseconds;

    /*************************************************************************
    @brief Reference trajectory longitudinal slope
    @details Longitudinal slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double slope_long[50];

    /*************************************************************************
     @brief Reference trajectory lateral slope
     @details Lateral slope between two adjacent reference trajectory elements
     @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
     @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
     @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
     @date 13.05.2021
     *************************************************************************/
    double slope_lat[50];

    /*************************************************************************
    @brief Reference trajectory velocity magnitude in m/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double vel_enu_mag_m_s[50];

    /*************************************************************************
    @brief Reference trajectory velocity angle in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double vel_enu_angle_rad[50];

    /*************************************************************************
    @brief Reference trajectory acceleration magnitude in m/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double acc_enu_mag_m_s2[50];

    /*************************************************************************
    @brief Reference trajectory acceleration angle in m/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double acc_enu_angle_rad[50];

    /*************************************************************************
    @brief Reference trajectory vehicle orientation in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double ori_enu_psi_rad[50];

    /*************************************************************************
    @brief Reference trajectory vehicle yaw rate in rad/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double ori_vel_enu_psi_rad_s[50];

    /*************************************************************************
    @brief Reference trajectory vehicle yaw acceleration in rad/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double ori_acc_enu_psi_rad_s2[50];

} trajENU_array;

#endif
