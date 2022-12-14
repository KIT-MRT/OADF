/**
 * \file dcm_core_ps_fusionstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_PS_FUSIONSTATUS_H
#define DCM_CORE_PS_FUSIONSTATUS_H

/*************************************************************************
@struct ps_fusionstatus
@brief Structure for the status of thread ps_fusion
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
typedef struct ps_fusionstatus {

    /*************************************************************************
    @brief Transmission time of input OL_ps_RF (seconds)
    @date 21.10.2021
    *************************************************************************/
    double OL_ps_RF_transm_time_seconds;

    /*************************************************************************
    @brief Transmission time of input OL_ps_RB (seconds)
    @date 21.10.2021
    *************************************************************************/
    double OL_ps_RB_transm_time_seconds;

    /*************************************************************************
    @brief Transmission time of input FL_ps_ECU (seconds)
    @date 21.10.2021
    *************************************************************************/
    double FL_ps_ECU_transm_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input OL_radar_RF (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t OL_radar_RF_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output OL_radar_RF (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t OL_radar_RF_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid input OL_radar_RB (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t OL_radar_RB_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output OL_radar_RB (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t OL_radar_RB_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid input FL_uss (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t FL_uss_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output FL_uss (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t FL_uss_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid output OL_fus (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t OL_fus_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output OL_fus (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t OL_fus_valid_time_nanoseconds;

    /*************************************************************************
    @brief Runtime of function func_ps_fusion (seconds)
    @date 09.08.2021
    *************************************************************************/
    double ps_fusion_runtime_seconds;

    /*************************************************************************
    @brief Number of error codes
    @details 1 Element: output
    @date 20.06.2021
    *************************************************************************/
    uint16_t no_errcode[1];

} ps_fusionstatus;

#endif //DCM_CORE_PS_FUSIONSTATUS_H
