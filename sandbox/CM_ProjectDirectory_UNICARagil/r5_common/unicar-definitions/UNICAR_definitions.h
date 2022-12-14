/**
* \file UNICAR_definitions.h
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.04.2022
@version 2
@copyright MIT License
@bug No known bugs.
*
* Copyright (c) Tobias Homolla, Grischa Gottschalg and Stefan Ackermann (2022) <firstname.lastname@tu-darmstadt.de>
**********************************************************************/

#ifndef UNICAR_DEFINITONS_H
#define UNICAR_DEFINITONS_H
#include <vector>
#include <cstdint>

// Define structs for Unicar algorithms

/*************************************************************************
@struct trajGCS
@brief Structure for trajGCS
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct trajGCS {

    /*************************************************************************
    @brief Timestamp of sending time for trajGCS (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for trajGCS (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Reference trajectory time vector (seconds fraction)
    @details First entry of the vector is the planning pose time in seconds
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint64_t> tai_seconds;

    /*************************************************************************
    @brief Reference trajectory time vector (nanoseconds fraction)
    @details First entry of the vector is the planning pose time in nanoseconds
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint32_t> tai_nanoseconds;

    /*************************************************************************
    @brief Flag to distinguish whether this trajectory was planned using previous trajectory or the current vehicle pose
    @details 0 - current vehicle pose used, 1 - previous trajectory used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_previous_trj;

    /*************************************************************************
    @brief Flag to distinguish whether atlatec localization or FZS localization was used to plan this trajectory
    @details 0 - FZS localization used, 1 - atlatec localization used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_atlatec;

    /*************************************************************************
    @brief Standstill flag
    @details Can be 0 (no vehicle standstill) or 1 (vehicle standstill)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint16_t> standstill;

    /*************************************************************************
    @brief Parking flag
    @details Can be 0 (no sideways parking) or 1 (prepare for sideways parking)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint16_t> parking;

    /*************************************************************************
    @brief Reference trajectory latitude in global ellipsoidic coordinates (ETRS89)
    @details First entry of the vector is the planning pose latitude
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_lat_rad;

    /*************************************************************************
    @brief Reference trajectory longitude in global ellipsoidic coordinates (ETRS89)
    @details First entry of the vector is the planning pose longitude
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_lon_rad;

    /*************************************************************************
    @brief Reference trajectory height in global ellipsoidic coordinates (ETRS89)
    @details First entry of the vector is the planning pose height
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_h_m;

    /*************************************************************************
    @brief Reference trajectory longitudinal slope
    @details Longitudinal slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> slope_long;

    /*************************************************************************
    @brief Reference trajectory lateral slope
    @details Lateral slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> slope_lat;

    /*************************************************************************
    @brief Reference trajectory velocity magnitude in m/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> vel_enu_mag_m_s;

    /*************************************************************************
    @brief Reference trajectory velocity angle in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> vel_enu_angle_rad;

    /*************************************************************************
    @brief Reference trajectory acceleration magnitude in m/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> acc_enu_mag_m_s2;

    /*************************************************************************
    @brief Reference trajectory acceleration angle in m/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> acc_enu_angle_rad;

    /*************************************************************************
    @brief Reference trajectory vehicle orientation in rad
    @details First entry of the vector is the planning orientation
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_enu_psi_rad;

    /*************************************************************************
    @brief Reference trajectory vehicle yaw rate in rad/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_vel_enu_psi_rad_s;

    /*************************************************************************
    @brief Reference trajectory vehicle yaw acceleration in rad/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_acc_enu_psi_rad_s2;

} trajGCS;


/*************************************************************************
@struct trajENU
@brief Structure for trajENU
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct trajENU {

    /*************************************************************************
    @brief Timestamp of sending time for trajENU (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for trajENU (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Reference trajectory time vector (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint64_t> tai_seconds;

    /*************************************************************************
    @brief Reference trajectory time vector (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint32_t> tai_nanoseconds;

    /*************************************************************************
    @brief Flag to distinguish whether this trajectory was planned using previous trajectory or the current vehicle pose
    @details 0 - current vehicle pose used, 1 - previous trajectory used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_previous_trj;

    /*************************************************************************
    @brief Flag to distinguish whether atlatec localization or FZS localization was used to plan this trajectory
    @details 0 - FZS localization used, 1 - atlatec localization used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_atlatec;

    /*************************************************************************
    @brief Standstill flag
    @details Can be 0 (no vehicle standstill) or 1 (vehicle standstill)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint16_t> standstill;

    /*************************************************************************
    @brief Parking flag
    @details Can be 0 (no sideways parking) or 1 (prepare for sideways parking)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint16_t> parking;

    /*************************************************************************
    @brief Reference trajectory east in local ENU coordinates
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_enu_east_m;

    /*************************************************************************
    @brief Reference trajectory north in local ENU coordinates
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_enu_north_m;

    /*************************************************************************
    @brief Reference trajectory planning latitude in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_lat_rad;

    /*************************************************************************
    @brief Reference trajectory planning longitude in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_lon_rad;

    /*************************************************************************
    @brief Reference trajectory planning height in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_h_m;

    /*************************************************************************
    @brief Reference trajectory planning vehicle orientation in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_ori_enu_psi_rad;

    /*************************************************************************
    @brief Timestamp of planning pose (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t plan_tai_seconds;

    /*************************************************************************
    @brief Timestamp of planning pose (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t plan_tai_nanoseconds;

    /*************************************************************************
    @brief Reference trajectory longitudinal slope
    @details Longitudinal slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> slope_long;

    /*************************************************************************
     @brief Reference trajectory lateral slope
     @details Lateral slope between two adjacent reference trajectory elements
     @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
     @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
     @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
     @date 13.05.2021
     *************************************************************************/
    std::vector<double> slope_lat;

    /*************************************************************************
    @brief Reference trajectory velocity magnitude in m/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> vel_enu_mag_m_s;

    /*************************************************************************
    @brief Reference trajectory velocity angle in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> vel_enu_angle_rad;

    /*************************************************************************
    @brief Reference trajectory acceleration magnitude in m/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> acc_enu_mag_m_s2;

    /*************************************************************************
    @brief Reference trajectory acceleration angle in m/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> acc_enu_angle_rad;

    /*************************************************************************
    @brief Reference trajectory vehicle orientation in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_enu_psi_rad;

    /*************************************************************************
    @brief Reference trajectory vehicle yaw rate in rad/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_vel_enu_psi_rad_s;

    /*************************************************************************
    @brief Reference trajectory vehicle yaw acceleration in rad/s²
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_acc_enu_psi_rad_s2;

} trajENU;

/*************************************************************************
@struct pathGCS
@brief Structure for pathGCS
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct pathGCS {

    /*************************************************************************
    @brief Timestamp of sending time for pathGCS (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for pathGCS (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Timestamp of planning pose (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t tai_seconds;

    /*************************************************************************
    @brief Timestamp of planning pose (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t tai_nanoseconds;

    /*************************************************************************
    @brief Number of elements in emergency path
    @details To verify, that all path elements are received correctly
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint16_t n_elements;

    /*************************************************************************
    @brief Flag to distinguish whether this path was planned using previous path or the current vehicle pose
    @details 0 - current vehicle pose used, 1 - previous path used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_previous_trj;

    /*************************************************************************
    @brief Flag to distinguish whether atlatec localization or FZS localization was used to plan this path
    @details 0 - FZS localization used, 1 - atlatec localization used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_atlatec;

    /*************************************************************************
    @brief Emergeny path latitude in global ellipsoidic coordinates (ETRS89)
    @details First entry of the vector is the planning pose latitude
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_lat_rad;

    /*************************************************************************
    @brief Emergeny path longitude in global ellipsoidic coordinates (ETRS89)
    @details First entry of the vector is the planning pose longitude
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_lon_rad;

    /*************************************************************************
    @brief Emergeny path height in global ellipsoidic coordinates (ETRS89)
    @details First entry of the vector is the planning pose height
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_h_m;

    /*************************************************************************
    @brief Emergeny path longitudinal slope
    @details Longitudinal slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> slope_long;

    /*************************************************************************
    @brief Emergeny path lateral slope
    @details Lateral slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> slope_lat;

    /*************************************************************************
    @brief Emergency path arc velocity in m/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_arc_vel_m_s;

    /*************************************************************************
    @brief Emergency path vehicle orientation in rad
    @details First entry of the vector is the planning orientation
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_enu_psi_rad;

    /*************************************************************************
    @brief Direction indicator flag
    @details Can be 0 (off), 1 (left) or 2 (right)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint16_t> dir_ind;
} pathGCS;

/*************************************************************************
@struct pathENU
@brief Structure for pathENU
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct pathENU {

    /*************************************************************************
    @brief Timestamp of sending time for pathENU (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for pathENU (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Number of elements in the emergency path
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint16_t n_elements;

    /*************************************************************************
    @brief Flag to distinguish whether this path was planned using previous path or the current vehicle pose
    @details 0 - current vehicle pose used, 1 - previous path used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_previous_trj;

    /*************************************************************************
    @brief Flag to distinguish whether atlatec localization or FZS localization was used to plan this path
    @details 0 - FZS localization used, 1 - atlatec localization used
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.04.2022
    *************************************************************************/
    uint16_t use_atlatec;

    /*************************************************************************
    @brief Emergency path east in local ENU coordinates
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_enu_east_m;

    /*************************************************************************
    @brief Emergency path north in local ENU coordinates
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_enu_north_m;

    /*************************************************************************
    @brief Emergency path planning latitude in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_lat_rad;

    /*************************************************************************
    @brief Emergency path planning longitude in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_lon_rad;

    /*************************************************************************
    @brief Emergency path planning height in global ellipsoidic coordinates (ETRS89)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_pos_ell_h_m;

    /*************************************************************************
    @brief Emergency path planning vehicle orientation in rad
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    double plan_ori_enu_psi_rad;

    /*************************************************************************
    @brief Timestamp of planning pose (seconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t plan_tai_seconds;

    /*************************************************************************
    @brief Timestamp of planning pose (nanoseconds fraction)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t plan_tai_nanoseconds;

    /*************************************************************************
    @brief Emergency path longitudinal slope
    @details Longitudinal slope between two adjacent reference trajectory elements
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> slope_long;

    /*************************************************************************
     @brief Emergency path lateral slope
     @details Lateral slope between two adjacent reference trajectory elements
     @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
     @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
     @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
     @date 13.05.2021
     *************************************************************************/
    std::vector<double> slope_lat;

    /*************************************************************************
    @brief Emergency path arc velocity in m/s
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_arc_vel_m_s;

    /*************************************************************************
    @brief Emergency path vehicle orientation in rad
    @details First entry of the vector is the planning orientation
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> ori_enu_psi_rad;

    /*************************************************************************
    @brief Direction indicator flag
    @details Can be 0 (off), 1 (left) or 2 (right)
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<uint16_t> dir_ind;
} pathENU;

/*************************************************************************
@struct taitime
@brief Structure for TAI time
@author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct taitime {
    /*************************************************************************
    @brief Tai time seconds fraction
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint64_t tai_seconds;

    /*************************************************************************
    @brief Tai time nanoseconds fraction
    @author Tobias Homolla, <tobias.homolla@tu-darmstadt.de>
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint32_t tai_nanoseconds;
} taitime;

/**
 * Convert GPS time to PTP time
 * @param gpsweeks  GPS weeks
 * @param gpssow    GPS second of week
 * @param TAItime   PTP time involves seconds and nanonseconds
 */
void GPStoTAI(uint16_t& gpsweeks, double& gpssow, taitime& TAItime);
void GPStoTAI(uint16_t& gpsweeks, double& gpssow, uint64_t& tai_seconds, uint32_t& tai_nanoseconds);

#endif //UNICAR_DEFINITONS_H
