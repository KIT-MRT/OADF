/**
 * \file tp_core_param_traj.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_PARAM_TRAJ_H
#define TP_CORE_PARAM_TRAJ_H

/*************************************************************************
@struct param_traj
@brief Structure for the parameter for reference trajectory preprocessing
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct param_traj {

    /*************************************************************************
    @brief GeographicLib datatype for the GRS80 ellipsoid
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    GeographicLib::Geocentric grs80ell;
} param_traj;

#endif //TP_CORE_PARAM_TRAJ_H
