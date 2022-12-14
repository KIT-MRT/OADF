/**
 * \file tp_core_tmp_pos_ell_deg_path.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_TMP_POS_ELL_DEG_PATH_H
#define TP_CORE_TMP_POS_ELL_DEG_PATH_H

/*************************************************************************
@struct tmp_pos_ell_deg_path
@brief Structure for the path positions in degrees
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct tmp_pos_ell_deg_path {

    /*************************************************************************
    @brief Vector for GCS latitude positions in degrees
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_lat_deg;

    /*************************************************************************
    @brief Vector for GCS longitude positions in degrees
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_ell_lon_deg;
} tmp_pos_ell_deg_path;

#endif //TP_CORE_TMP_POS_ELL_DEG_PATH_H
