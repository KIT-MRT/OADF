/**
 * \file dcm_core_interp_shpath.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_INTERP_SHPATH_H
#define DCM_CORE_INTERP_SHPATH_H

/*************************************************************************
@struct interp_shpath
@brief Structure for the interpolated emergency path
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
typedef struct interp_shpath {

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
    @brief Temporary number of elements in the emergency path
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.11.2021
    *************************************************************************/
    uint16_t tmp_n_elements;

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
    @brief Current arc length velocity (in m/s) on safe halt path
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 29.11.2021
    *************************************************************************/
    double curr_pos_arc_vel_m_s;

    /*************************************************************************
    @brief Temporary emergency path arc velocity in m/s
    @details First element is always at current s and v²(s). Last element is always at v² = 0 m²/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    std::vector<double> tmp_pos_arc_vel_m_s;

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

    /*************************************************************************
    @brief Parametric cubic spline inteprolant: 2-dimensional curve for ENU positions
    @date 13.05.2021
    *
    * <u>Dependencies:</u>
    * - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
    *************************************************************************/
    alglib::pspline2interpolant cspline_pos_enu_s;

    /*************************************************************************
    @brief 1-dimensional linear spline interpolant for arc length velocity
    @date 13.05.2021
    *
    * <u>Dependencies:</u>
    * - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
    *************************************************************************/
    alglib::spline1dinterpolant lspline_pos_enu_vel2_s;

    /*************************************************************************
    @brief 1-dimensional cubic spline interpolant for arc length velocity
    @date 28.03.2022
    *
    * <u>Dependencies:</u>
    * - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
    *************************************************************************/
    alglib::spline1dinterpolant cspline_pos_enu_vel2_s;

    /*************************************************************************
    @brief boost.geometry LINESTRING for for arc length velocity
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_lspline_pos_enu_vel2_s;

    /*************************************************************************
    @brief Temporary 1-dimensional linear spline interpolant for arc length velocity
    @date 29.11.2021
    *
    * <u>Dependencies:</u>
    * - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
    *************************************************************************/
    alglib::spline1dinterpolant tmp_lspline_pos_enu_vel2_s;

    /*************************************************************************
    @brief Temporary 1-dimensional cubic spline interpolant for arc length velocity
    @date 28.03.2022
    *
    * <u>Dependencies:</u>
    * - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
    *************************************************************************/
    alglib::spline1dinterpolant tmp_cspline_pos_enu_vel2_s;

    /*************************************************************************
    @brief 1-dimensional cubic spline interpolant for orientation
    @date 13.05.2021
    *
    * <u>Dependencies:</u>
    * - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
    *************************************************************************/
    alglib::spline1dinterpolant cspline_ori_enu_psi_s;

    /*************************************************************************
    @brief Cummulated path segment length
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> pos_enu_s_m;

    /*************************************************************************
    @brief Temporary cummulated path segment length
    @details First element is always at current s and v²(s). Last element is always at v² = 0 m²/s²
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    std::vector<double> tmp_pos_enu_s_m;

    /*************************************************************************
    @brief Current position (s in m) on safe halt path
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    double curr_pos_enu_s_m;

    /*************************************************************************
    @brief Cummulated path segment duration
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::vector<double> tmp_pos_enu_t_s;

    /*************************************************************************
    @brief Cummulated linear path segment length
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 04.10.2021
    *************************************************************************/
    std::vector<double> pos_enu_slin_m;

    /*************************************************************************
    @brief North position difference between emergency path elements
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 04.10.2021
    *************************************************************************/
    std::vector<double> pos_enu_dnorth_m;

    /*************************************************************************
    @brief East position difference between emergency path elements
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 04.10.2021
    *************************************************************************/
    std::vector<double> pos_enu_deast_m;

    /*************************************************************************
    @brief Length factor between cubic and linear emergecy path interpolation
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 04.10.2021
    *************************************************************************/
    std::vector<double> pos_enu_slenfactor;

    /*************************************************************************
    @brief boost.geometry LINESTRING for emergency path
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_shpath;

    /*************************************************************************
    @brief boost.geometry MULTI_POLYGON for buffered emergency path
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    boost::geometry::model::multi_polygon<boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double>>> bg_shpath_buffered;

    /*************************************************************************
    @brief boost.geometry MULTI_POLYGON vector for buffered objects
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 26.11.2021
    *************************************************************************/
    std::vector<boost::geometry::model::multi_polygon<boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double>>>> bg_objects_buffered;

    /*************************************************************************
    @brief Boolean for target object present
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.11.2021
    *************************************************************************/
    bool target_object;

    /*************************************************************************
    @brief Reference s to avoid collision with target object
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.11.2021
    *************************************************************************/
    double target_object_s;

    /*************************************************************************
    @brief Reference v to avoid collision with target object
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 27.11.2021
    *************************************************************************/
    double target_object_v;

	/*************************************************************************
	@brief Taitime when significant object was last seen
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 06.05.2022
	*************************************************************************/
	taitime target_last_seen;

	/*************************************************************************
	@brief ALGLIB optimization state minlmstate 
	@date 30.03.2022
	*
	* <u>Dependencies:</u>
	* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
	*************************************************************************/
	alglib::minlmstate state;

	/*************************************************************************
	@brief ALGLIB optimization report minlmreport 
	@date 30.03.2022
	*
	* <u>Dependencies:</u>
	* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
	*************************************************************************/
	alglib::minlmreport rep;

}interp_shpath;

#endif //DCM_CORE_INTERP_SHPATH_H
