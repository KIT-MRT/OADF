/**
 * \file dcm_core_vds_enu.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_VDS_ENU_H
#define DCM_CORE_VDS_ENU_H

/*************************************************************************
@struct vds_enu
@brief Structure for the vehicle dynamic state enu position
@details Valid only for current planning pose of the safe halt path
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2021
*************************************************************************/
typedef struct vds_enu {

    /*************************************************************************
    @brief East value of ENU vds
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.11.2021
    *************************************************************************/
    double pos_enu_east_m;

    /*************************************************************************
    @brief North value of ENU vds
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.11.2021
    *************************************************************************/
    double pos_enu_north_m;

    /*************************************************************************
    @brief Up value of ENU vds
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.01.2022
    *************************************************************************/
    double pos_enu_up_m;

} vds_enu;

#endif //DCM_CORE_VDS_ENU_H
