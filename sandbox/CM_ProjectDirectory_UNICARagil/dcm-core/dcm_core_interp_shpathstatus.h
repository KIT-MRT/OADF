/**
 * \file dcm_core_interp_shpathstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_INTERP_SHPATHSTATUS_H
#define DCM_CORE_INTERP_SHPATHSTATUS_H

/*************************************************************************
@struct interp_shpathstatus
@brief Structure for the status of thread interp_shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
typedef struct interp_shpathstatus {
    /*************************************************************************
    @brief Transmission time of input pathENU (seconds)
    @date 09.08.2021
    *************************************************************************/
    double pathENU_transm_time_seconds;

    /*************************************************************************
    @brief Runtime of function func_interp_shpath (seconds)
    @date 09.08.2021
    *************************************************************************/
    double interp_shpath_runtime_seconds;

    /*************************************************************************
    @brief Counter for succesfull path interpolations
    @date 09.08.2021
    *************************************************************************/
    uint16_t no_interp_shpathinput;

    /*************************************************************************
    @brief Time stamp of last valid input pathENU (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t pathENU_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input pathENU (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t pathENU_valid_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid output interp_shpath (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t interp_shpath_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid input interp_shpath (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t interp_shpath_valid_time_nanoseconds;

    /*************************************************************************
    @brief Number of error codes
    @details 1 Element: pathENU input, 2 Element: interp_shpath output
    @date 20.06.2021
    *************************************************************************/
    uint16_t no_errcode[2];

} interp_shpathstatus;

#endif //DCM_CORE_INTERP_SHPATHSTATUS_H
