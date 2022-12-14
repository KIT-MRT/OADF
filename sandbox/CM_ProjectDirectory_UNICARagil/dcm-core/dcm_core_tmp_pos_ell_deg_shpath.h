/**
 * \file dcm_core_tmp_pos_ell_deg_traj.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_TMP_POS_ELL_DEG_SHPATH_H
#define DCM_CORE_TMP_POS_ELL_DEG_SHPATH_H

/*************************************************************************
@struct tmp_pos_ell_deg_shpath
@brief Structure for the reference trajectory positions in degrees
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2021
*************************************************************************/
typedef struct tmp_pos_ell_deg_shpath {

    /*************************************************************************
    @brief Vector for GCS latitude positions in degrees
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.11.2021
    *************************************************************************/
    std::vector<double> pos_ell_lat_deg;

    /*************************************************************************
    @brief Vector for GCS longitude positions in degrees
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 12.11.2021
    *************************************************************************/
    std::vector<double> pos_ell_lon_deg;

} tmp_pos_ell_deg_shpath;

#endif //DCM_CORE_TMP_POS_ELL_DEG_SHPATH_H
