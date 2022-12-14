/**
 * \file tp_core_pathstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_PATHSTATUS_H
#define TP_CORE_PATHSTATUS_H

/*************************************************************************
@struct pathstatus
@brief Structure for the status of thread path
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
typedef struct pathstatus {
    /*************************************************************************
    @brief Transmission time of input pathGCS (seconds)
    @date 17.06.2021
    *************************************************************************/
    double pathGCS_transm_time_seconds;

    /*************************************************************************
    @brief Runtime of function func_path (seconds)
    @date 17.06.2021
    *************************************************************************/
    double path_runtime_seconds;

    /*************************************************************************
    @brief Counter for succesfull pathENU transformations
    @date 17.06.2021
    *************************************************************************/
    uint16_t no_pathENU;

    /*************************************************************************
    @brief Time stamp of last valid input pathGCS (seconds)
    @date 17.06.2021
    *************************************************************************/
    uint64_t pathGCS_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input pathGCS (nanoseconds fraction)
    @date 17.06.2021
    *************************************************************************/
    uint32_t pathGCS_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid output pathENU (seconds)
    @date 17.06.2021
    *************************************************************************/
    uint64_t pathENU_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output pathENU (nanoseconds fraction)
    @date 17.06.2021
    *************************************************************************/
    uint32_t pathENU_valid_time_nanoseconds;

    /*************************************************************************
    @brief Number of error codes [0,1]
    @date 17.06.2021
    *************************************************************************/
    uint16_t no_errcode[2];

} pathstatus;

#endif //TP_CORE_PATHSTATUS_H
