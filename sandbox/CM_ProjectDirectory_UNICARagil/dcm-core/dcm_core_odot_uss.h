/**
 * \file dcm_core_odot_uss.h
 *
 * CONFIDENTIAL (Valeo)
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_ODOT_USS_H
#define DCM_CORE_ODOT_USS_H

/*************************************************************************
    @struct odot_uss
    @brief Structure for the plattform sensor ultrasonic sensor feature list
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021
    *************************************************************************/
typedef struct odot_uss {

    /*************************************************************************
    @brief Timestamp of sending time for FL_uss (seconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 03.06.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for FL_uss (nanoseconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 03.06.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Vehicle position x
    @details in mm; Resolution: 1; Range: [SI32_MIN, SI32_MAX]
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    int vhcl_position_x_mm;

    /*************************************************************************
    @brief Vehicle position y
    @details in mm; Resolution: 1; Range: [SI32_MIN, SI32_MAX]
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    int vhcl_position_y_mm;

    /*************************************************************************
    @brief Vehicle Orientation angle
    @details Unit: deg; Resolution: 360 / 2^16; Range: [0, 360[
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t vhcl_ang_u16f;

    /*************************************************************************
    @brief Timestamp of the position
    @details Unit: microseconds; Resolution: 2us; Range: [0, 2*U32_MAX]
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint32_t timestamp_2us;

    /*************************************************************************
    @brief Driven way in mm (direction independent).
    @details Unit: mm; Resolution: 1; Range: [0, U32_MAX]
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint32_t s_mm;

    /*************************************************************************
    @brief Time since no pulses received for the four wheels
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint32_t time_since_no_pulses_2us;

    /*************************************************************************
    @brief Driving distance since change the driving direction
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint32_t dr_dist_since_dr_dir_change;

    /*************************************************************************
    @brief Front wheel angle velocity
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    int16_t fwa_vel_si16f_per_sec;

    /*************************************************************************
    @brief Vehicle speed
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t veh_speed_100thkph;

    /*************************************************************************
    @brief Front wheel angle
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t front_wheel_angle_u16f;

    /*************************************************************************
    @brief Driving distance in the opposite direction of the gear
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t dr_dist_against_gear;

    /*************************************************************************
    @brief Fast standstill indication flag
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    bool fast_standstill;

    /*************************************************************************
    @brief Slow stadstill indication flag
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    bool slow_standstill;

    /*************************************************************************
    @brief Output reliability flag
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    bool is_reliable;

    /*************************************************************************
    @brief Software fault detection flag
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    bool sw_fault_detected;

    /*************************************************************************
    @brief Driving direction
    @details 0: Moving backward or recommended driving direction is backward.; 1: Direction is unknown or no driving direction recommendation.; 2: Moving forward or recommended driving direction is forward.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t driving_dir;

    /*************************************************************************
    @brief Filtered driving direction
    @details 0: Moving backward or recommended driving direction is backward.; 1: Direction is unknown or no driving direction recommendation.; 2: Moving forward or recommended driving direction is forward.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t filt_wheel_driving_dir;

    /*************************************************************************
    @brief Warn direction
    @details 0: Moving backward or recommended driving direction is backward.; 1: Direction is unknown or no driving direction recommendation.; 2: Moving forward or recommended driving direction is forward.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint16_t warn_dir;

} odot_uss;

#endif //DCM_CORE_ODOT_USS_H
