/**
 * \file dcm_param.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_PARAM_H
#define DCM_PARAM_H

/*************************************************************************
@brief Namespace for dcm parameter
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
namespace dcmparam {

/*************************************************************************
@brief Time difference between trajectory elements in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern double trajdt;

/*************************************************************************
@brief Number of trajectory elements (without planning pose)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern int ntrajelements;

/*************************************************************************
@brief Flag to activate platform sensors
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 11.05.2022
*************************************************************************/
    extern uint16_t sensorson;

/*************************************************************************
@brief IP adress of the front radar sensor
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 02.08.2021
*************************************************************************/
    extern std::string radarf_ip;

/*************************************************************************
@brief Port number of the front radar sensor
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 02.08.2021
*************************************************************************/
    extern uint16_t radarf_port;

/*************************************************************************
@brief IP adress of the back radar sensor
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 02.08.2021
*************************************************************************/
    extern std::string radarb_ip;

/*************************************************************************
@brief Port number of the back radar sensor
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 02.08.2021
*************************************************************************/
    extern uint16_t radarb_port;

/*************************************************************************
@brief IP adress of the USS ECU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::string ECU_ip;

/*************************************************************************
@brief Port number of the USS ECU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern uint16_t ECU_port;

/*************************************************************************
@brief Position and orientation of radar sensor front (in UNICARagil frame)
@details {x in mm, y in mm, orientation (+-180 in °)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    extern std::vector<int> RF;

/*************************************************************************
@brief Position and orientation of radar sensor back (in UNICARagil frame)
@details {x in mm, y in mm, orientation (+-180 in °)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    extern std::vector<int> RB;

/*************************************************************************
@brief Position and orientation of uss and camera (in UNICARagil frame)
@details {x in mm, y in mm, orientation (+-180 in °)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    extern std::vector<int> USS;

/*************************************************************************
@brief Comfortable deceleration value for distance filtering
@details in m/s²
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.11.2021
*************************************************************************/
    extern float comfortable_deceleration_m_s2;

/*************************************************************************
@brief Assumed maximum speed of target vehicles in the vicinity of the vehicle
@details in m/s
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.11.2021
*************************************************************************/
    extern float target_vmax;

/*************************************************************************
@brief Assumed maximum speed of a static object
@details in m/s
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.11.2021
*************************************************************************/
    extern float static_object_vmax;

/*************************************************************************
@brief Minimal distance of static object to emergency path for filter 2
@details in m
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.11.2021
*************************************************************************/
    extern float static_object_filter_dist;

/*************************************************************************
@brief Closest distance between ego vehicle reference origin and target object
@details in m
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.04.2022
*************************************************************************/
    extern float target_object_dist;

/*************************************************************************
@brief Distance to front left corner of UNICARagil vehicle (x and y in vehicle reference frame)
@details in mm
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 23.11.2021
*************************************************************************/
    extern std::vector<int> fl_corner_dist_xy;

/*************************************************************************
@brief Distance to back right corner of UNICARagil vehicle (x and y in vehicle reference frame)
@details in mm
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.05.2022
*************************************************************************/
	extern std::vector<int> br_corner_dist_xy;

/*************************************************************************
@brief Velocity depended factor for buffer size
@details buffer size per velocity (e.g. 2 m for 20 m/s)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 23.11.2021
*************************************************************************/
    extern float vel_buffer_size;

/*************************************************************************
@brief Buffer safety margin factor
@details in -
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 23.11.2021
*************************************************************************/
    extern float buffer_safety_margin;

/*************************************************************************
@brief Minimal significant distance to check for obstacles in m, even in standstill
@details in m
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 02.12.2021
*************************************************************************/
	extern double min_significant_distance;

/*************************************************************************
@brief Minimal distance to target object when dcm_shpath reacts
@details in m
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.05.2022
*************************************************************************/
	extern double react_distance;

/*************************************************************************
@brief Acceleration for velocity profile, if current velocity is lower than original velocity profile
@details in m/s²
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.12.2021
*************************************************************************/
    extern double acc_velocity_profile;

/*************************************************************************
@brief Maximum velocity for intersection check
@details Value used to generate a linestring that intersects the original velocity profile. Velocity needs to be greater than the actual maximum velocity of the vehicle
@details in m/s²
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.12.2021
*************************************************************************/
    extern double max_velocity_profile;

/*************************************************************************
@brief Minimal deceleration for velocity profile
@details If target object is too far away, no deceleration is triggered. Value is trigger deceleration
@details in m/s²
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.12.2021
*************************************************************************/
    extern double minimal_deceleration;

/*************************************************************************
@brief Maximal deceleration for velocity profile
@details Maximum value for deceleration (e.g. during debuggin phase)
@details in m/s²
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.12.2021
*************************************************************************/
    extern double maximal_deceleration;

/*************************************************************************
@brief Maximal path coordinate s for velocity profile
@details Maximum value for s
@details in m
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    extern double maximal_path_s;

/*************************************************************************
@brief Cutoff object velocity for object following or standstill
@details Maximum value for deceleration (e.g. during debuggin phase)
@details in m
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    extern double minimal_object_velocity;

/*************************************************************************
@brief Minimum deviation for Start of velocity correction
@details in m/s
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    extern double minimal_velocity_deviation;

/*************************************************************************
@brief PT1 jerk optimization time constant tau
@details in s
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 18.01.2022
*************************************************************************/
	extern double pt1_jerk_opt_tau_s;

/*************************************************************************
@brief Flag to display the uss status in the terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern uint16_t disp_ussstatus;

/*************************************************************************
@brief Flag to display the radar front status in the terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern uint16_t disp_radarfstatus;

/*************************************************************************
@brief Flag to display the radar back status in the terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern uint16_t disp_radarbstatus;

/*************************************************************************
@brief Flag to display the operational status of psaservice in the terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern uint16_t disp_operational;

/*************************************************************************
@brief Status time difference in terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern float time;

/*************************************************************************
@brief Flag to activate error message in terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern uint16_t errmsg;

/*************************************************************************
@brief Flag to activate runtime message in terminal
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    extern uint16_t runtime;

/*************************************************************************
@brief Flag to activate target object information
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.03.2022
*************************************************************************/
    extern uint16_t disp_targetobject;

/*************************************************************************
@brief Flag to activate IXXAT gateway error messages for radar sensors
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 28.03.2022
*************************************************************************/
    extern uint16_t disp_Rgatewayerror;

/*************************************************************************
@brief Flag to activate standstill flag in emergency trajectory
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2022
*************************************************************************/
    extern uint16_t standstillon;

}
#endif //DCM_PARAM_H