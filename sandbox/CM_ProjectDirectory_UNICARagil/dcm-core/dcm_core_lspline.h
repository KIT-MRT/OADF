/**
 * \file dcm_core_lspline.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_LSPLINE_H
#define DCM_CORE_LSPLINE_H

/*************************************************************************
    @struct lspline_pos_enu_vel2_s_splineparam
    @brief Structure for the 1d linear interpolated v²-s spline parameter
    @details v²(s) = C1 * s + C0
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
typedef struct lspline_pos_enu_vel2_s_splineparam {

    /*************************************************************************
    @brief Cummulated length s at the start of the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> si;

    /*************************************************************************
    @brief Cummulated length s at the end of the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> siplus1;

    /*************************************************************************
    @brief C0 of the linear equation of v²-s of linear interpolation for the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> c0;

    /*************************************************************************
    @brief C1 of the linear equation of v²-s of linear interpolation for the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> c1;
} lspline_pos_enu_vel2_s_splineparam;

#endif //DCM_CORE_LSPLINE_H
