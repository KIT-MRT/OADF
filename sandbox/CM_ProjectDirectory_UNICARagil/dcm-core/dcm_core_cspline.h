/**
 * \file dcm_core_cspline.h
 *
 * Copyright (c) Stefan Ackermann (2022) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_CSPLINE_H
#define DCM_CORE_CSPLINE_H

/*************************************************************************
    @struct cspline_pos_enu_vel2_s_splineparam
    @brief Structure for the 1d cubic interpolated v²-s spline parameter
    @details v²(s) = C3 * s³ + C2 * s² + C1 * s + C0
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.03.2022
    *************************************************************************/
typedef struct cspline_pos_enu_vel2_s_splineparam {

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
    @brief C0 of the cubic equation of v²-s of cubic interpolation for the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.03.2022
    *************************************************************************/
    std::vector<double> c0;

    /*************************************************************************
    @brief C1 of the cubic equation of v²-s of cubic interpolation for the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.03.2022
    *************************************************************************/
    std::vector<double> c1;

    /*************************************************************************
    @brief C2 of the cubic equation of v²-s of cubic interpolation for the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.03.2022
    *************************************************************************/
    std::vector<double> c2;

    /*************************************************************************
    @brief C3 of the cubic equation of v²-s of cubic interpolation for the path segments
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.03.2022
    *************************************************************************/
    std::vector<double> c3;

} cspline_pos_enu_vel2_s_splineparam;

#endif //DCM_CORE_CSPLINE_H
