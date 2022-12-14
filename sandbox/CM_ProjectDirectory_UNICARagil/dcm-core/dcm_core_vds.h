#ifndef DCM_CORE_VDS_H
#define DCM_CORE_VDS_H

/**
\file dcm_core_vds.h
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@date 10.11.2021
@version 1
@copyright MIT License
@bug No known bugs.
*
* Copyright (c) Grischa Gottschalg (2021) <firstname.lastname@tu-darmstadt.de>
**********************************************************************/

/*************************************************************************
@struct vds
@brief Structure for vds
@author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
typedef struct vds {

    /*************************************************************************
    @brief Send timestamp for vds (seconds fraction)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Send timestamp for vds (nanoseconds fraction)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Timestamp for vds (seconds fraction)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    uint64_t tai_seconds;

    /*************************************************************************
    @brief Timestamp for vds (nanoseconds fraction)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    uint32_t tai_nanoseconds;

    /*************************************************************************
    @brief Vehicle dynamic state estimation status
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    bool vds_valid;

    /*************************************************************************
    @brief Vehicle position latitude in global ellipsoidic coordinates (ETRS89)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    double pos_ell_lat_rad;

    /*************************************************************************
    @brief Vehicle position longitude in global ellipsoidic coordinates (ETRS89)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    double pos_ell_lon_rad;

    /*************************************************************************
    @brief Vehicle position height in global ellipsoidic coordinates (ETRS89)
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    double pos_ell_h_m;

    /*************************************************************************
    @brief Vehicle velocity in ENU plane east in m/s
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    float vel_enu_east_m_s;

    /*************************************************************************
    @brief Vehicle velocity in ENU plane north in m/s
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    float vel_enu_north_m_s;

    /*************************************************************************
    @brief Vehicle velocity in ENU plane up in m/s
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 12.01.2022
    *************************************************************************/
    float vel_enu_up_m_s;

    /*************************************************************************
    @brief Vehicle acceleration in ENU plane east in m/s²
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    float acc_enu_east_m_s;

    /*************************************************************************
    @brief Vehicle acceleration in ENU plane north in m/s²
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    float acc_enu_north_m_s;

    /*************************************************************************
    @brief Vehicle yaw angle in ENU plane in rad
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    double ori_enu_psi_rad;

    /*************************************************************************
    @brief Vehicle pitch angle in ENU plane in rad
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 12.01.2022
    *************************************************************************/
    double pit_enu_psi_rad;

    /*************************************************************************
    @brief Vehicle roll angle in ENU plane in rad
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 12.01.2022
    *************************************************************************/
    double rol_enu_psi_rad;

    /*************************************************************************
    @brief Vehicle yawrate in rad/s
    @author Grischa Gottschalg, <grischa.gottschalg@tu-darmstadt.de>
    @date 10.11.2021
    *************************************************************************/
    double ori_vel_enu_psi_rad_s;

} vds;

#endif //DCM_CORE_VDS_H