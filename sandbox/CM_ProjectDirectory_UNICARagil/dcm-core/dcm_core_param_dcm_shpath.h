/**
 * \file dcm_core_param_dcm_shpath.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_PARAM_DCM_SHPATH_H
#define DCM_CORE_PARAM_DCM_SHPATH_H

/*************************************************************************
@struct param_dcm_shpath
@brief Structure for the parameter for dcm trajectory generation
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct param_dcm_shpath {

    /*************************************************************************
    @brief Time difference between trajectory elements in seconds
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double trajdt;

    /*************************************************************************
    @brief Number of trajectory elements (without planning pose)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    int ntrajelements;

    /*************************************************************************
    @brief Time length of trajectory in seconds
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double traj_t_length;

    /*************************************************************************
    @brief GeographicLib datatype for the GRS80 ellipsoid
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.11.2021
    *************************************************************************/
    GeographicLib::Geocentric grs80ell;

    /*************************************************************************
    @brief Comfortable deceleration value for distance filtering
    @details in m/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 17.11.2021
    *************************************************************************/
    float comfortable_deceleration_m_s2;

    /*************************************************************************
    @brief Assumed maximum speed of target vehicles in the vicinity of the vehicle
    @details in m/s
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 17.11.2021
    *************************************************************************/
    float target_vmax;

    /*************************************************************************
    @brief Assumed maximum speed of a static object
    @details in m/s
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 22.11.2021
    *************************************************************************/
    float static_object_vmax;

    /*************************************************************************
    @brief Minimal distance of static object to emergency path for filter 2
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 22.11.2021
    *************************************************************************/
    float static_object_filter_dist;

    /*************************************************************************
    @brief Closest distance between ego vehicle reference origin and target object
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.04.2022
    *************************************************************************/
    float target_object_dist;

    /*************************************************************************
    @brief Distance to front left corner of UNICARagil vehicle (x and y in vehicle reference frame)
    @details in mm
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 23.11.2021
    *************************************************************************/
    std::vector<int> fl_corner_dist_xy;

	/*************************************************************************
	@brief Distance to back right corner of UNICARagil vehicle (x and y in vehicle reference frame)
	@details in mm
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 12.05.2022
	*************************************************************************/
	std::vector<int> br_corner_dist_xy;

    /*************************************************************************
    @brief Velocity depended factor for buffer size
    @details buffer size per velocity (e.g. 2 m for 20 m/s)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 23.11.2021
    *************************************************************************/
    float vel_buffer_size;

    /*************************************************************************
    @brief Buffer safety margin factor
    @details in -
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 23.11.2021
    *************************************************************************/
    float buffer_safety_margin;

	/*************************************************************************
	@brief Minimal significant distance to check for obstacles in m, even in standstill
	@details in m
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 02.12.2021
	*************************************************************************/
	double min_significant_distance;

	/*************************************************************************
	@brief Minimal distance to target object when dcm_shpath reacts
	@details in m
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 12.05.2022
	*************************************************************************/
	double react_distance;

    /*************************************************************************
    @brief Acceleration for velocity profile, if current velocity is lower than original velocity profile
    @details in m/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 09.12.2021
    *************************************************************************/
    double acc_velocity_profile;

    /*************************************************************************
    @brief Maximum velocity for intersection check
    @details Value used to generate a linestring that intersects the original velocity profile. Velocity needs to be greater than the actual maximum velocity of the vehicle
    @details in m/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 09.12.2021
    *************************************************************************/
    double max_velocity_profile;

    /*************************************************************************
    @brief Minimal deceleration for velocity profile
    @details If target object is too far away, no deceleration is triggered. Value is trigger deceleration
    @details in m/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 09.12.2021
    *************************************************************************/
    double minimal_deceleration;

    /*************************************************************************
    @brief Maximal deceleration for velocity profile
    @details Maximum value for deceleration (e.g. during debuggin phase)
    @details in m/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 09.12.2021
    *************************************************************************/
    double maximal_deceleration;

    /*************************************************************************
    @brief Maximal path coordinate s for velocity profile
    @details Maximum value for deceleration (e.g. during debuggin phase)
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.12.2021
    *************************************************************************/
    double maximal_path_s;

    /*************************************************************************
    @brief Cutoff object velocity for object following or standstill
    @details Maximum value for deceleration (e.g. during debuggin phase)
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.12.2021
    *************************************************************************/
    double minimal_object_velocity;

    /*************************************************************************
    @brief Minimum deviation for Start of velocity correction
    @details in m/s
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.12.2021
    *************************************************************************/
    double minimal_velocity_deviation;

	/*************************************************************************
	@brief PT1 jerk optimization time constant tau
	@details in s
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 18.01.2022
	*************************************************************************/
	double pt1_jerk_opt_tau_s;

    /*************************************************************************
    @brief Flag to activate standstill flag in emergency trajectory
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2022
    *************************************************************************/
    uint16_t standstillon;

} param_dcm_shpath;

#endif //DCM_CORE_PARAM_DCM_SHPATH_H
