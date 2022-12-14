/**
 * \file tp_core_param_path.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_PARAM_PATH_H
#define TP_CORE_PARAM_PATH_H

/*************************************************************************
@struct param_path
@brief Structure for the parameter for emergency path preprocessing
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct param_path {

    /*************************************************************************
    @brief GeographicLib datatype for the GRS80 ellipsoid
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    GeographicLib::Geocentric grs80ell;
} param_path;

#endif //TP_CORE_PARAM_PATH_H
