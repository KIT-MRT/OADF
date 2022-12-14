/**
 * \file dcm_core_OL_radar.h
 *
 * CONFIDENTIAL (Continental)
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_OL_RADAR_H
#define DCM_CORE_OL_RADAR_H

/*************************************************************************
    @struct OL_radar
    @brief Structure for the plattform sensor radar object list
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021
    *************************************************************************/
typedef struct OL_radar {

    /*************************************************************************
    @brief Timestamp of sending time for OL_radar (seconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 03.06.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for OL_radar (nanoseconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 03.06.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief State of reading the configuration parameters from non-volatile memory at startup
    @details 0x0: failed, 0x1: successful
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_NVMReadStatus;

    /*************************************************************************
    @brief State of storing a configuration parameter to non-volatile memory
    @details Initially this value is set to 0x0 and set to 0x1 after a configuration has been sent and successfully stored
     0x0: failed, 0x1: successful
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_NVMwriteStatus;

    /*************************************************************************
    @brief Current configuration of maximum distance of far scan – different of ARS 404 and ARS 408
    @details ARS408: - Standard Range:   196 m – 260 m - Extended Range:   196 m – 1200 m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_MaxDistanceCfg;

    /*************************************************************************
    @brief An internal error which might not disappear after a reset has been detected.
    @details 0x0: No error, 0x1: Persistent error active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_Persistent_Error;

    /*************************************************************************
    @brief Interference with another radar sensor has been detected.
    @details In case of Interference there is no change in any interface function of the radar.
     Internally the background noise increases which decreases the performance slowly depending on the strength
     of interference, but the radar will go on in sending Clusters or Objects to the interface as long as any obstacle
     is detected. It does always automatically quit after it has gone. It should be used as an indication that the
     measurement of the radar is influenced by another radar and the performance will probably decrease a little bit.
     Every radar is protected against the effect of interference by a randomly unbalanced length of interrupts between
     the measurements. This avoids a permanent interference with another radar and it only creates partly interference
     with the assurance to leave immediately after appearing.To create full radar performance any interference should
     be avoided / kept as less as possible !!
     0x0: No interference, 0x1: Interference detected
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_Interference;

    /*************************************************************************
    @brief A temporary error which will most probably disappear after a sensor reset has been detected.
    @details 0x0: No error 0x1: Temporary error active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_Temporary_Error;

    /*************************************************************************
    @brief Error will be active if the temperature is below or above the defined range. It does automatically quit after it has gone.
    @details 0x0: No error 0x1: Temperature error active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_Temperature_Error;

    /*************************************************************************
    @brief Error will be active if the operating voltage is below or above the defined range for more than 5 seconds.
    @details U1 = < 7.1 VDC     ---> Radar switches off
     U2 = 7.3-7.4 VDC  ---> voltage error = 1
     U3 = 7.5-7.6 VDC  ---> voltage error = 0 Radar works
     U4 = 7.6-32.8 VDC---> Radars sends telegram
     U5 = 32.8 VDC      ---> voltage error = 0
     U6 = 32.9 VDC      ---> voltage error = 1
     U7 = > 32,9 VDC   ---> Radar switches off It does always automatically quit after it has gone.
     0x0: No error, 0x1: Voltage error active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_Voltage_Error;

    /*************************************************************************
    @brief Sensor ID 0 - 7
    @details Current sensor ID (0-7)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_SensorID;

    /*************************************************************************
    @brief Current configuration of sorting index for object list
    @details 0x0: no sorting 0x1: sorted by range 0x2: sorted by RCS
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_SortIndex;

    /*************************************************************************
    @brief Current configuration of transmitted radar power parameter
    @details 0x0: Standard 0x1: -3dB Tx gain 0x2: -6dB Tx gain 0x3: -9dB Tx gain
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_RadarPowerCfg;

    /*************************************************************************
    @brief True if relay control message is sent
    @details 0x0: inactive 0x1: active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_CtrlRelayCfg;

    /*************************************************************************
    @brief Currently selected output type as either clusters or objects
    @details 0x0: none 0x1: send objects 0x2: send clusters
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_OutputTypeCfg;

    /*************************************************************************
    @brief True if quality information is sent for clusters or objects
    @details 0x0: inactive 0x1: active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_SendQualityCfg;

    /*************************************************************************
    @brief True if extended information is sent for objects
    @details 0x0: inactive 0x1: active
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_SendExtInfoCfg;

    /*************************************************************************
    @brief Shows the state of the speed and yaw rate input signals
    @details 0x0: input ok 0x1: speed missing 0x2: yaw rate missing 0x3: speed and yaw rate missing
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_MotionRxState;

    /*************************************************************************
    @brief If true the sensors high sensitivity mode is active
    @details 0x0 Standard 0x1 High sensitivity
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 29
    *************************************************************************/
    uint16_t RadarState_RCS_Threshold;

    /*************************************************************************
    @brief Number of objects (max. 100 Objects)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 62
    *************************************************************************/
    uint16_t Object_NofObjects;

    /*************************************************************************
    @brief Measurement cycle counter (counting up since startup of sensor and restarting at 0 when > 65535)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 62
    *************************************************************************/
    uint16_t Object_MeasCounter;

    /*************************************************************************
    @brief Object list CAN interface Version-No. It is always “1” till any Object Identifier will be changed in any coming SW-update.
    @details always “1”
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 62
    *************************************************************************/
    uint16_t Object_InterfaceVersion;

    /*************************************************************************
    @brief Object ID (since objects are tracked, the ID is kept throughout measurement cycles and does not have to be consecutive)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<uint16_t> Object_ID;

    /*************************************************************************
    @brief Longitudinal (x) coordinate
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<double> Object_DistLong;

    /*************************************************************************
    @brief Lateral (y) coordinate
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<double> Object_DistLat;

    /*************************************************************************
    @brief Relative velocity in longitudinal direction (x)
    @details in m/s
    stationary candidates
    => vrel (y) made by own speed and yaw rate
    => rest of speed projected to (x)
    Math.: f_VrelY = - (f_DistX + LongPosToRot) * YawRate
    f_VrelX = (f_VrelRad - sin_( f_AzAngle ) * f_VrelY)/cos_( f_AzAngle )
    otherwise (moving candidates):
    => projected to (x)
    Math.: f_VrelY = 0.0
    f_VrelX = f_VrelRad/COS_( f_AzAngle )

    if cos_( f_AzAngle ) = 0, => f_VrelRad is used
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<double> Object_VrelLong;

    /*************************************************************************
    @brief Relative velocity in lateral direction (y) (see (x) above)
    @details in m/s
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<double> Object_VrelLat;

    /*************************************************************************
    @brief Dynamic property of the object indicating if the object is moving or stationary
    @details 0x0: moving, 0x1: stationary, 0x2: oncoming, 0x3: stationary, candidate, 0x4: unknown, 0x5: crossing stationary, 0x6: crossing, moving 0x7: stopped
    This value can only be determined correctly if the speed and yaw rate is given correctly
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<uint16_t> Object_DynProp;

    /*************************************************************************
    @brief Radar cross section
    @details in dBm²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 63
    *************************************************************************/
    std::vector<double> Object_RCS;

    /*************************************************************************
    @brief Standard deviation of longitudinal distance
    @details in m, refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_DistLong_rms;

    /*************************************************************************
    @brief Standard deviation of longitudinal relative velocity
    @details in m/s, refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_VrelLong_rms;

    /*************************************************************************
    @brief Standard deviation of lateral distance
    @details in m, refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_DistLat_rms;

    /*************************************************************************
    @brief Standard deviation of lateral relative velocity
    @details in m/s, refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_VrelLat_rms;

    /*************************************************************************
    @brief Standard deviation of lateral relative acceleration
    @details in m/s², refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_ArelLat_rms;

    /*************************************************************************
    @brief Standard deviation of longitudinal relative acceleration
    @details in m/s², refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_ArelLong_rms;

    /*************************************************************************
    @brief Standard deviation of orientation angle (see: figure 3)
    @details in deg, refer to signal value table on p. 67
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Obj_Orientation_rms;

    /*************************************************************************
    @brief Measurement state indicating if the object is valid and has been confirmed by clusters in the new measurement cycle
    @details 0x0: deleted, 0x1: new, 0x2: measured, 0x3: predicted, 0x4: deleted for merge, 0x5: new from merge
     0x0:  Deleted Object – Object has been deleted – is displayed during the last cycles of transmission just before the object ID disappears.
     0x1:  New Object is created – is displayed during the first cycles of transmission just after the object ID is created. Can also be checked by the character Object_MeasCounter.
     0x2:  Measured – Object creation has been confirmed by the actual measurement. Cluster could be created.
     0x3:  Predicted - Object creation could not be confirmed by the actual measurement. Cluster could not be created.
     0x4:  Deleted for merge - Object became deleted in order to be merged with another Object.
     0x5:  New from merge – new Object became created after a merge.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<uint16_t> Obj_MeasState;

    /*************************************************************************
    @brief Probability of existence
    @details 0x0: invalid, 0x1: <25%, 0x2: <50%, 0x3: <75%, 0x4: <90%, 0x5: <99%, 0x6: <99.9%, 0x7: <=100%
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<uint16_t> Obj_ProbOfExist;

    /*************************************************************************
    @brief Relative acceleration in longitudinal direction
    @details in m/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Object_ArelLong;

    /*************************************************************************
    @brief Object class
    @details 0x0: point 0x1: car 0x2: truck 0x3: not in use 0x4: motorcycle 0x5: bicycle 0x6: wide 0x7: reserved
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<uint16_t> Object_Class;

    /*************************************************************************
    @brief Relative acceleration in lateral direction (y)
    @details in m/s², always “0”
    This value is permanently set to “Zero” see Cluster_VrelLat (Table 33)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Object_ArelLat;

    /*************************************************************************
    @brief Orientation angle of the object (see: figure 3 - picture above)
    @details
    The change of an angle created by turning movement of a tracked obstacle over time.
    The creation of that value always starts at “0” and increases depending on a certain rotation of the obstacle.
    It keeps “0” if a rotation does not happen
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Object_OrientationAngel;

    /*************************************************************************
    @brief Length of the tracked object
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Object_Length;

    /*************************************************************************
    @brief Width of the tracked object
    @details in m
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - ARS40X_Technical_Documentation.pdf (18.05.2018), p. 65
    *************************************************************************/
    std::vector<double> Object_Width;

} OL_radar;

#endif //DCM_CORE_OL_RADAR_H