/**
 * \file dcm_core_ps_Rstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_PS_RSTATUS_H
#define DCM_CORE_PS_RSTATUS_H

/*************************************************************************
@struct ps_Rstatus
@brief Structure for the status of thread ps_R
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
typedef struct ps_Rstatus {
    /*************************************************************************
    @brief Timestamp of the last successful connection to Radar sensor IP address (seconds)
    @date 14.07.2021
    *************************************************************************/
    uint64_t ps_Rnetcon_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last successful connection to Radar sensor IP address (nanoseconds fraction)
    @date 14.07.2021
    *************************************************************************/
    uint32_t ps_Rnetcon_valid_time_nanoseconds;

    /*************************************************************************
    @brief Timestamp of the last disconnect from Radar sensor IP address (seconds)
    @date 11.08.2021
    *************************************************************************/
    uint64_t ps_Rnetdiscon_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last disconnect from Radar sensor IP address (nanoseconds fraction)
    @date 11.08.2021
    *************************************************************************/
    uint32_t ps_Rnetdiscon_valid_time_nanoseconds;

    /*************************************************************************
    @brief Radar TCP connection established
    @details 0 - not established, 1 - connection established
    @date 14.07.2021
    *************************************************************************/
    uint16_t ps_Rnetcon_established;

    /*************************************************************************
    @brief Time stamp of last valid output OL_radar (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t OL_radar_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output OL_radar (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t OL_radar_valid_time_nanoseconds;

    /*************************************************************************
    @brief Runtime of function func_ps_R (seconds)
    @date 09.08.2021
    *************************************************************************/
    double ps_R_runtime_seconds;

    /*************************************************************************
    @brief Number of error codes
    @details 1 Element: OL radar output
    @date 20.06.2021
    *************************************************************************/
    uint16_t no_errcode[1];

    /*************************************************************************
    @brief Timestamp of the last successful radar state reception (seconds)
    @date 16.12.2021
    *************************************************************************/
    uint64_t ps_Rstate_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last successful radar state reception (nanoseconds fraction)
    @date 16.12.2021
    *************************************************************************/
    uint32_t ps_Rstate_valid_time_nanoseconds;

    /*************************************************************************
    @brief Continental ARS 408 Radar state
    @details 1 Element: RadarState_NVMReadStatus (failed/successful), 2 Element: RadarState_NVMwriteStatus (failed/successful),
     3 Element: RadarState_MaxDistanceCfg (in m), 4 Element: RadarState_Persistent_Error (no error/error),
     5 Element: RadarState_Interference (no interference/interference), 6 Element: RadarState_Temperature_Error (no error/error),
     7 Element: RadarState_Temporary_Error (no error/error), 8 Element: RadarState_Voltage_Error (no error/error),
     9 Element: RadarState_SensorID (number), 10 Element: RadarState_SortIndex (no sorting/by range, by rcs),
     11 Element: RadarState_RadarPowerCfg (Standard/-3dB/-6dB/-9dB), 12 Element: RadarState_CtrlRelayCfg (inactive, active),
     13 Element: RadarState_OutputTypeCfg (none/objects/cluster), 14 Element: RadarState_SendQualityCfg (inactive/active),
     15 Element: RadarState_SendExtInfoCfg (inactive/active),
     16 Element: RadarState_MotionRxState (input ok/speed missing/yaw rate missing/speed+yawrate missing),
     17 Element: RadarState_RCS_Threshold (Standard/High sensitivity)
    @date 16.12.2021
    *************************************************************************/
    uint16_t ars408_radarstate[17];

    /*************************************************************************
    @brief Timestamp of the last successful received heartbeat from radar IP address (seconds)
    @date 14.03.2022
    *************************************************************************/
    uint64_t ps_Rnetcon_heartbeat_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last successful received heartbeat from radar IP address (nanoseconds fraction)
    @date 14.03.2022
    *************************************************************************/
    uint32_t ps_Rnetcon_heartbeat_valid_time_nanoseconds;

} ps_Rstatus;

#endif //DCM_CORE_PS_RSTATUS_H
