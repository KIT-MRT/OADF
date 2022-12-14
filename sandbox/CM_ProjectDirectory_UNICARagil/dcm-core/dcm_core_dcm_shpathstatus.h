/**
 * \file dcm_core_dcm_shpathstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_DCM_SHPATHSTATUS_H
#define DCM_CORE_DCM_SHPATHSTATUS_H

/*************************************************************************
@struct dcm_shpathstatus
@brief Structure for the status of thread dcm_shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
typedef struct dcm_shpathstatus {
    /*************************************************************************
    @brief Transmission time of input interpolated safe halt path (seconds)
    @date 09.08.2021
    *************************************************************************/
    double interp_shpath_transm_time_seconds;

    /*************************************************************************
    @brief Transmission time of input fused object list (seconds)
    @date 09.08.2021
    *************************************************************************/
    double fus_OL_transm_time_seconds;

    /*************************************************************************
    @brief Runtime of function func_dcm_shpath (seconds)
    @date 09.08.2021
    *************************************************************************/
    double dcm_shpath_runtime_seconds;

    /*************************************************************************
    @brief Counter for succesfull generated safe halt trajectories
    @date 09.08.2021
    *************************************************************************/
    uint16_t no_dcm_shpathinput;

    /*************************************************************************
    @brief Time stamp of last valid input pathENU (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t interp_shpath_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input pathENU (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t interp_shpath_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid input fused object list (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t fus_OL_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input fused object list (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t fus_OL_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid output trajENU (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t trajENU_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output trajENU (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t trajENU_valid_time_nanoseconds;

    /*************************************************************************
    @brief Number of error codes
    @details 1 Element: trajENU output
    @date 09.08.2021
    *************************************************************************/
    uint16_t no_errcode[1];

    /*************************************************************************
    @brief Boolean for target object present
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.11.2021
    *************************************************************************/
    bool target_object;

    /*************************************************************************
    @brief Reference s to avoid collision with target object
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.11.2021
    *************************************************************************/
    double target_object_s;

    /*************************************************************************
    @brief Reference v to avoid collision with target object
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.11.2021
    *************************************************************************/
    double target_object_v;

	/*************************************************************************
	@brief Current arc length velocity (in m/s) on safe halt path
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 29.11.2021
	*************************************************************************/
	double curr_pos_arc_vel_m_s;

	/*************************************************************************
	@brief Current position (s in m) on safe halt path
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 26.11.2021
	*************************************************************************/
	double curr_pos_enu_s_m;

} dcm_shpathstatus;

#endif //DCM_CORE_DCM_SHPATHSTATUS_H