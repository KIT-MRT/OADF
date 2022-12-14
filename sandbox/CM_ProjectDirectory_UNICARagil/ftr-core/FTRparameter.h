#ifndef FTRPARAMETER_H
#define FTRPARAMETER_H

#define _USE_MATH_DEFINES
#include <math.h>


namespace ftr {

	const int m = 2200;							// Vehicle mass
	const int c_a = 100000;						// Cornering stiffness
    const float l = 3.4;  						// Wheelbase
    const float w = 1.78; 						// Track width
    const float c_w = 0.4;						// cW drag coefficient
    const float A = 5;							// Front area of the vehicle
    const float rho_L = 1.2041;					// Air density
    const float f_r = 0.01;						// Roll resistance coefficient
    const float g = 9.81;						// Earth gravity constant
    const int J_z = 4000;						// Moment of inertia (z-axis)
    const float l_psi = (sqrt(l*l+w*w))/2;		// Distance vehicle middle to wheel contact points
    const float h_l = l/sqrt(l*l+w*w);			// Constant for yaw torque
    const float h_w = w/sqrt(l*l+w*w); 			// Constant for yaw torque
    const float delta_max = M_PI/2;				// Max. steering angle
    const float delta_min = M_PI/3;				// Min. steering angle
    const float freq = 50; 						// Frequency of FTR
    const float laTime_lat = 0.091;				// Look ahead time lateral
	const float laTime_lon = 0.0253;			// Look ahead time longitudinal
    const float r_dyn = 0.325;					// Dynamic tire radius
	const bool SF_on = 1;						// State feedback on/off
	const int NoElementsRingbuffer = 256;	// Number of elements in ringbuffer for offset correction
	const float cutoff_freq_lp_acc = 1;		// Cutoff frequency for PT1 filter for acceleration state feedback
	const double max_age_state = 0.1; 			// Max. age of vehicle state to be used for controller
	const float gear_ratio_drive = 1 / 3.138;	// Gear ratio of electric drive
	const float max_rear_angle = 0.0873; 		// Maximum rear angle for Ackermann like steering
	const int high_speed_enabled = 1;				// 0 for max 5 km/h, 1 for max. 15 km/h
	const float max_pos_err_init = 0.5;		// maximum position error at start of trajectory
	const float max_yaw_err_init = 0.25;		// maximum yaw error at start of trajectory
	const int standstill_brk_trq = 1000;	// Brake torque to hold the vehicle in place during standstill
	const int speed_lim_tmp = 200;
	const int wheel_acc_tmp = 20;
	const float standstill_velocity_threshold = 0.2;
	const float a_lat_max = 4;
	const bool use_slope_feedforward = 0;
	const float min_speed_kin_control = 0.5;


    // Time constants for state feedback 

	// Longitudinal
	const float t_v_lon = 0.5;
    const float t_pos_lon = 4 * t_v_lon;
    //const double t_i_lon = 1 / (20 * t_pos_lon);
	const float t_i_lon = 0;

	// Lateral
	const float t_v_lat = 0.5;
	const float t_pos_lat = 4 * t_v_lat;
	//const float t_i_lat = 1 / (20 * t_pos_lat);
	const float t_i_lat = 0;

	// Yaw
	const float t_v_yaw = 0.5;
	const float t_pos_yaw = 4 * t_v_yaw;
	//const float t_i_yaw = 1 / (20 * t_pos_yaw);
	const float t_i_yaw = 0;

}
#endif
