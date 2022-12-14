/**
 * \file dcm_core_dcmstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_DCMSTATUS_H
#define DCM_CORE_DCMSTATUS_H

/*************************************************************************
@struct dcmstatus
@brief Structure for the status of dcm
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
typedef struct dcmstatus {

    /*************************************************************************
    @brief Timestamp of sending time for dcmstatus (seconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for dcmstatus (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Input status
    @details Indicates when the last valid input was received. Element 1: ASOA pathENU, Element 2: Internal interp_shpath, Element 3: OL radar front, Element 4: OL radar back, Element 5: FL uss, Element 6: OL fusion
    @details 0 - Never, 1 - Normal, 2 - One dropout, 3 - 3 dropouts, 4 - 6 dropouts, 5 - 10 dropouts, 6 - More than 10 dropouts
    @date 09.08.2021
    *************************************************************************/
    uint16_t input[6];

    /*************************************************************************
    @brief netcon status
    @details Indicates the network connection status with USS ECU and radar sensors. Element 1: TCP radar front connections status, Element 2: TCP radar front last connect, Element 3: TCP radar front last disconnect, Element 4: TCP radar back connections status, Element 5: TCP radar back last connect, Element 6: UDP USS ECU last odot, Element 7: UDP USS ECU last ulfc
    @details Element 1: TCP radar front connections status, Element 2: TCP radar front last connect, Element 3: TCP radar front last disconnect, Element 4: TCP radar front last heartbeat, Element 5: TCP radar front last receive, Element 6: TCP radar back connections status, Element 7: TCP radar back last connect, Element 8: TCP radar front last disconnect, Element 9: TCP radar back last heartbeat, Element 10: TCP radar back last receive, Element 11: UDP uss last receive Odot, Element 12: UDP uss last receive ULF, Element 13: UDP uss last receive SDI
    @details Elements 0,5: 0 - Not connected, 1 - Connected
    @details Elements 1,2,3,6,7,8
    @details Elements 4,9,10,11,12: 0 - Never, 1 - 100 ms, 2 - 200 ms, 3 - 500 ms, 4 - 1 s, 5 - 5 s, 6 - More than 5 s
    @date 09.08.2021
    *************************************************************************/
    uint16_t netcon[13];

    /*************************************************************************
    @brief Output status
    @details Indicates when the last valid output was sent. Element 1: interp_shpath, Element 2: trajENU, Element 3: OL radar front, Element 4: OL radar back, Element 5: FL uss, Element 6: OL fusion
    @details 0 - Never, 1 - Normal, 2 - One dropout, 3 - 3 dropouts, 4 - 6 dropouts, 5 - 10 dropouts, 6 - More than 10 dropouts
    @date 09.08.2021
    *************************************************************************/
    uint16_t output[6];

    /*************************************************************************
    @brief Runtime status
    @details Indicates the runtime of functions for thread and path. Element 1: interp_shpath, Element 2: dcm_shpath, Element 3: ps_RF, Element 4: ps_RB, Element 5: ps_ECU, Element 6: ps_fusion
    @details 0 - Never, 1 - Normal , 2 - < 1 ms, 3 - < 10 ms, 4 - < 50 ms, 5 - <100 ms, 6 - < 100 ms
    @date 09.08.2021
    *************************************************************************/
    uint16_t runtime[6];

    /*************************************************************************
    @brief Input transmission time
    @details Indicates the input transmission time. Element 1: ASOA pathENU, Element 2: Internal interp_shpath, Element 3: OL fusion
    @details 0 - Never, 1 - <10ms, 2 - <50 ms, 3 - < 100ms, 4 - <500ms, 5 - 1 s, 6 - >1s
    @date 09.08.2021
    *************************************************************************/
    uint16_t transm_t[3];

    /*************************************************************************
    @brief Number of error codes
    @details Indicates the overall number of error codes. Element 1 = thread_interp_shpath input, Element 2 = thread_interp_shpath output, Element 3 = thread_dcm_shpath output, Element 4 = thread_ps_RF output, Element 5 = thread_ps_RB output, Element 6 = thread_ps_ECU output, Element 7 = thread_ps_fusion output
    @date 09.08.2021
    *************************************************************************/
    uint16_t errcode[8];

    /*************************************************************************
    @brief Radarstate last update
    @details Indicates the when last RadarState was received
     Element 1: Radar front, Element 2: Radar back
     @details 0 - Never, 1 - < 1.5 s , 2 - < 3 s, 3 - < 5 s, 4 - < 10 s, 5 - < 30 s, 6 - > 30 s
    @date 09.08.2021
    *************************************************************************/
    uint16_t radarstate_update[2];

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
    uint16_t ars408_radarstate_front[16];

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
    uint16_t ars408_radarstate_back[16];

    /*************************************************************************
    @brief Service operational status
    @details Indicates if the service is operational or not
    @details 1 = operational, 0 = not operational
    @date 09.08.2021
    *************************************************************************/
    uint16_t operational;

} dcmstatus;

#endif //DCM_CORE_DCMSTATUS_H