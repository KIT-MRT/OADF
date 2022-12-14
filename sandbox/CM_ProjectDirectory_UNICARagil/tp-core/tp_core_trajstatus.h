/**
 * \file tp_core_trajstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_TRAJSTATUS_H
#define TP_CORE_TRAJSTATUS_H

/*************************************************************************
@struct trajstatus
@brief Structure for the status of thread traj
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
typedef struct trajstatus {

    /*************************************************************************
    @brief Transmission time of input trajGCS (seconds)
    @date 17.06.2021
    *************************************************************************/
    double trajGCS_transm_time_seconds;

    /*************************************************************************
    @brief Runtime of function func_traj (seconds)
    @date 17.06.2021
    *************************************************************************/
    double traj_runtime_seconds;

    /*************************************************************************
    @brief Counter for succesfull trajENU transformations
    @date 17.06.2021
    *************************************************************************/
    uint16_t no_trajENU;

    /*************************************************************************
    @brief Time stamp of last valid input trajGCS (seconds)
    @date 17.06.2021
    *************************************************************************/
    uint64_t trajGCS_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input trajGCS (nanoseconds fraction)
    @date 17.06.2021
    *************************************************************************/
    uint32_t trajGCS_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid output trajENU (seconds)
    @date 17.06.2021
    *************************************************************************/
    uint64_t trajENU_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output trajENU (nanoseconds fraction)
    @date 17.06.2021
    *************************************************************************/
    uint32_t trajENU_valid_time_nanoseconds;

    /*************************************************************************
    @brief Number of error codes [0,1]
    @date 17.06.2021
    *************************************************************************/
    uint16_t no_errcode[2];

} trajstatus;

#endif //TP_CORE_TRAJSTATUS_H
