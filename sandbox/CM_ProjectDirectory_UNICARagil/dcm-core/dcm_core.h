/**
* \file dcm_core.h
* \brief Header for dcm_core.cpp
* @author Stefan Ackermann <stefan.ackermann@tu-darmstadt.de>
* @date 15.05.2021
* @version 1
* @copyright GPL v3
* @bug No known bugs.
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
* - asio (www.think-async.com), Chrisk Kohlhoff (Version 1.18.2, Boost Software License, Version 1.0)
* - Eigen (eigen.tuxfamily.org), Benoît Jacob (founder) and Gaël Guennebaud (guru) (Version 3.4.0,  Mozilla Public License Version 2.0)
* - Boost (www.boost.org) (Version 1.79,  Boost Software License - Version 1.0)
* - cantools (https://cantools.readthedocs.io/en/latest/#) (Version 36.2.0, MIT License)
*
* Copyright (c) Stefan Ackermann (2022) <stefan.ackermann@tu-darmstadt.de>
**********************************************************************/

#ifndef DCM_CORE_H
#define DCM_CORE_H

// Comment/Uncomment flags for application
//#define DCM_DEBUG                    // For debug messages
//#define DCM_INTERFACE          //Show messages regarding data transfer with global variables
//#define CMAP243               //Define for CarMaker Simulation
//#define DCM_NET_USS_DEBUG     //For uss networking debug messages
//#define DCM_NET_RADAR_DEBUG     //For uss networking debug messages

#define _USE_MATH_DEFINES

/* Header includes */
#include <vector> //std:vector
#include <deque> //std::deque
#include <thread> //std::thread
#include <mutex> //std::mutex, std::lock_guard
#include <atomic> //std::atomic_bool
#include <condition_variable>   //std::condition_variable
#include <cmath> //std::isfinite
#include <algorithm> //std::find
#include <sstream>   //std::stringstream
#include <iostream> //std::cout
#include <string> //std::string, std::stoi
#include <fstream> //ifstream

/* ALGLIB - ALGLIB is a cross-platform numerical analysis and data processing library */
#include "lib/src/ALGLIB/stdafx.h"
#include "lib/src/ALGLIB/interpolation.h"

/* Eigen - Eigen is a high-level C++ library of template headers for linear algebra, matrix and vector operations, geometrical transformations, numerical solvers and related algorithms */
#include "lib/src/Eigen/Dense"

// asio
//#include <asio.hpp>

/* boost geometry */
#include "boost/geometry.hpp"
#include "boost/geometry/geometries/point_xy.hpp"

/* Geographiclib - Coordinate transformation global ellipsoid to local East North Up (ENU) */
#include <GeographicLib/NormalGravity.hpp>
#include <GeographicLib/Math.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <GeographicLib/Geocentric.hpp>

/* toml11 (TOML parser) */
#include "lib/src/toml11/toml.hpp"

/* UNICARagil Header */
#include"../unicar-definitions/UNICAR_definitions.h" //UNICAR definitions
#include "dcm_core_dcmstatus.h"
#include "dcm_core_tmp_pos_ell_deg_shpath.h"
#include "dcm_core_vds_enu.h"
#include "dcm_core_vds.h"
#include "dcm_core_dcm_shpathplot.h" // dcm_shplot (Struct with data to be plotted for dcm_shpath)
#include "dcm_core_interp_shpathstatus.h"
#include "dcm_core_dcm_shpathstatus.h"
#include "dcm_core_ps_Rstatus.h"
#include "dcm_core_ps_ECUstatus.h"
#include "dcm_core_ps_fusionstatus.h"
#include "dcm_core_ecuselect.h"
#include "dcm_core_interp_shpath.h" // interp_shpath struct
#include "dcm_core_lspline.h" // lspline_pos_enu_vel2_s_splineparam
#include "dcm_core_cspline.h" // cspline_pos_enu_vel2_s_splineparam
#include "dcm_core_err.h" //error struct
#include "dcm_core_OL_radar.h" // OL_radar (Object list radar sensor)
#include "dcm_core_FL_uss.h" // FL_uss (Feature list ultrasonic sensor)
#include "dcm_core_sdi_uss.h" // SDI_uss (SDI ultrasonic sensor)
#include "dcm_core_odot_uss.h" // odot_uss (Odometry from ultrasonic sensor ecu)
#include "dcm_core_OL_fus.h" // OL_fus (Fused object list)
#include "dcm_ext_interface.h" // External dcm interface
#include "dcm_param.h" // dcm parameter
//#include "ps/radar/dbc/ARS408.h" //dbc for Continental ARS 408
//#include "ps/uss_camera/ECU1/tmp_pdf.h" // Valeo deserializer for USS and camera
//#include "ps/uss_camera/ECU1/serl_das_data_ids.h" // Valeo deserializer for USS and camera
//#include "ps/uss_camera/ECU1/serl_dstd.h" // Valeo deserializer for USS and camera
//#include "ps/uss_camera/ECU1/serl_das_ulfc.h" // Valeo deserializer for USS and camera
//#include "ps/uss_camera/ECU1/serl_das_odoc.h" // Valeo deserializer for USS and camera
//#include "ps/uss_camera/ECU2/serl_das_data_ids.h" // Valeo deserializer for USS and camera
//#include "ps/uss_camera/ECU2/serl_das_ulfc.h" // Valeo deserializer for USS and camera
//#include "dcm_core_net_tsqueue_datatype_uss.h" // Struct with Valeo ECU datatypes
#include "dcm_core_param_dcm_shpath.h" //param_dcm_shpath
#include "dcm_core_param_ps_fusion.h" //param_ps_fusion
#include "dcm_core_net_tsqueue_radar.h"
//#include "dcm_core_net_tsqueue_uss.h"
//#include "dcm_core_net_radar.h"
//#include "dcm_core_net_uss.h"

/* Includes only for IPG CarMaker */
#ifdef CMAP243
#include "CarMaker.h"
#endif

/*************************************************************************
@class dcmcore
@brief Class for dcmcore functionality
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 15.05.2021
*************************************************************************/
class dcmcore {

/*************************************************************************
@brief This function sends ecus from the dcm thread
@param[in] tmp_ecus ecuselect struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 11.08.2021
*************************************************************************/
    static void tx_ecus(ecuselect tmp_ecus);

/*************************************************************************
@brief This function sends dcm_err to glob_dcm_err
@param[in] dcm_err dcm_err struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.04.2021
*************************************************************************/
    static void tx_dcm_err(const dcm_err &dcm_err);

/*************************************************************************
@brief This function receives pathENU from glob_pathENU
@param[in] pathENU pathENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void rx_pathENU(pathENU &pathENU);

/*************************************************************************
@brief This function writes the interpolated emergency path to global int_glob_interp_shpath
@param[in] tmp_interp_shpath interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void write_interp_shpath(interp_shpath tmp_interp_shpath);

/*************************************************************************
@brief This function receives the interpolated emergency path and the platform sensor object list
@param[in] ext_interp_shpath interp_shpath struct
@param[in] ext_OL_fus Fused object list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 21.10.2021
*************************************************************************/
    void read_dcm_shpath_input(struct interp_shpath &ext_interp_shpath, struct OL_fus &ext_OL_fus);

/*************************************************************************
@brief This function reads the current delay time for the trajectory generation
@param[out] delay_time_s Delay time in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void read_delay_time_s(double &delay_time_s);

/*************************************************************************
@brief This function sends trajENU from the dcm threads to glob_trajENU
@param[in,out] tmp_trajENU trajENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void tx_trajENU(trajENU tmp_trajENU);

/*************************************************************************
@brief This function sends OL_ps_RB from the dcm threads to int_glob_OL_ps_RB
@param[in,out] tmp_OL_ps_RB Temporary radar object list for plattform back radar sensor
@param[in] input Origin of this radar data (0: radar front, 1: radar back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void tx_OL_ps_R(OL_radar tmp_OL_ps_R, uint16_t &input);

/*************************************************************************
@brief This function sends FL_ps_ECU from the dcm threads to int_glob_FL_ps_ECU
@param[in,out] tmp_FL_ps_ECU Temporary ultrasonic sensor feature list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    void tx_FL_ps_ECU(FL_uss tmp_FL_ps_ECU);

/*************************************************************************
@brief This function sends FL_ps_ECU from the dcm threads to int_glob_FL_ps_ECU
@param[in,out] tmp_FL_ps_ECU Temporary ultrasonic sensor feature list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    void tx_OL_fus(OL_fus tmp_OL_fus);

/*************************************************************************
@brief This function receives interp_shpathstatus from glob_interp_shpathstatus
@param[in,out] interp_shpathstatus interp_shpathstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void read_interp_shpathstatus(interp_shpathstatus &interp_shpathstatus);

/*************************************************************************
@brief This function receives dcm_shpathstatus from glob_dcm_shpathstatus
@param[in,out] dcm_shpathstatus dcm_shpathstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void read_dcm_shpathstatus(dcm_shpathstatus &dcm_shpathstatus);

/*************************************************************************
@brief This function receives ps_Rstatus from glob_ps_Rstatus
@param[in,out] ps_Rstatus ps_Rstatus struct
@param[in] input Origin of this radar data (0: radar front, 1: radar back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void read_ps_Rstatus(ps_Rstatus &ps_Rstatus, uint16_t &input);

/*************************************************************************
@brief This function receives ps_ECUstatus from glob_ps_ECUstatus
@param[in,out] ps_ECUstatus ps_ECUstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void read_ps_ECUstatus(ps_ECUstatus &ps_ECUstatus);

/*************************************************************************
@brief This function receives ps_fusionstatus from glob_ps_fusionstatus
@param[in,out] ps_fusionstatus ps_fusionstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void read_ps_fusionstatus(ps_fusionstatus &ps_fusionstatus);

/*************************************************************************
@brief This function sends tmp_dcmstatus from the dcm thread_dcmstatus
@param[in] tmp_dcmstatus Temporary dcmstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static void tx_dcmstatus(dcmstatus tmp_dcmstatus);

/*************************************************************************
@brief This function sends fusioned Object List from the dcm thread_dcm_shpath
@param[in] ext_OL_fus Temporary fusioned object list struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    static void tx_FOL_d(OL_fus ext_OL_fus);

/*************************************************************************
@brief This function sends interp shpath from the dcm thread_dcm_shpath
@param[in] ext_interp_shpath Temporary interp shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    static void tx_ishp_d(interp_shpath ext_interp_shpath);

/*************************************************************************
@brief This function sends tmp_RF_OL from the dcm thread_ps_RF
@param[in] ext_OL_radar Temporary OL struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    static void tx_RFOL_d(OL_radar ext_OL_radar);

/*************************************************************************
@brief This function sends tmp_RB_OL from the dcm thread_ps_RB
@param[in] ext_OL_radar Temporary OL struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    static void tx_RBOL_d(OL_radar ext_OL_radar);

/*************************************************************************
@brief This function sends ext_dcm_shpathplot
@param[in] ext_dcm_shpathplot External dcm_shpathplot struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
    void tx_dcm_shpathplot(dcm_shpathplot ext_dcm_shpathplot);

    /* Common */
/*************************************************************************
@brief This function unpacks the 1D spline parameter of the cubic velocity²-s spline
@param[in] tmp_interp_shpath Interp_shpath struct
@param[out] cspline_pos_enu_vel2_s_splineparam Structure for the 1d cubic interpolated v²-s spline parameter
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2022
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void get_cspline_pos_enu_vel2_s_splineparam(struct interp_shpath &tmp_interp_shpath,
                                                cspline_pos_enu_vel2_s_splineparam &cspline_pos_enu_vel2_s_splineparam);

/*************************************************************************
@brief This function unpacks the 1D spline parameter of the linear velocity²-s spline
@param[in] tmp_interp_shpath Interp_shpath struct
@param[out] lspline_pos_enu_vel2_s_splineparam Structure for the 1d linear interpolated v²-s spline parameter
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void get_lspline_pos_enu_vel2_s_splineparam(struct interp_shpath &tmp_interp_shpath,
                                                lspline_pos_enu_vel2_s_splineparam &lspline_pos_enu_vel2_s_splineparam);

    /* Emergency path interpolation  */

/*************************************************************************
@brief Thread thread_interp_shpath variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    std::thread thread_interp_shpath;

/*************************************************************************
@brief This function represents the the task for the emergency path interpolation
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void task_interp_shpath();

/*************************************************************************
@brief This is the function for interpolation of the emergency path
@details In an infinite loop the emergency path in ENU coordinate system is received, processed and send to int_glob_interp_shpath
@param[in] pathENU Emergency path in ENU coordinate system
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void func_interp_shpath(struct pathENU &pathENU);

/*************************************************************************
@brief This function checks the plausibility and the content of the received pathENU.
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] pathENU Emergency path in local ENU coordinate system
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    static bool check_pathENU(pathENU &pathENU, dcm_err &dcm_err);

/*************************************************************************
@brief This function creates parametric cubic splines between the reference positions of the emergency path, parameterized
 according to the path length s.
@details In the first step, a parametric cubic natural spline is created, which connects all
 reference positions. Then the segment lengths between the reference positions are determined using the generated
 spline. These segment lengths are finally used to generate a new parametric cubic spline with parameter arc length s.
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_cspline2d(struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function calculates the segment lengths of the parametric cubic natural spline.
@param[in] s alglib::pspline2interpolant (Parametric cubic spline inteprolant: 2-dimensional curve for ENU positions)
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_seglen(const alglib::pspline2interpolant &s, struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function calculates the linear distance and the difference for north and east of all emergency lane positions
@details The linear distance is used to match the cubic path and the linear path connection. The difference of north and east coordinates are used for the subsequent calculation of the minimum distance of a target object from the linear emergency path.
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 04.10.2021
*
*************************************************************************/
    void path_lspline2d(struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function generates a cubic spline between the included (here squared) velocities of the emergency path.
Spline parameter is the distance s over the previously interpolated cubic position spline.
@param[in,out] tmp_interp_shpath Interp_shpath struct
@param[in] input Original or temporary cubic velocity interpolation (0: Original velocity profile, 1: Temporary velocity profile)
@param[in] curr_s Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2021
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_cvelsquare(struct interp_shpath &tmp_interp_shpath, uint16_t &input, double &curr_s);

/*************************************************************************
@brief This function generates a linear spline between the included (here squared) velocities of the emergency path.
@details A linear connection between the squared velocities results in a constant acceleration (2*a).
Spline parameter is the distance s over the previously interpolated cubic position spline.
@param[in,out] tmp_interp_shpath Interp_shpath struct
@param[in] input Original or temporary linear velocity interpolation (0: Original velocity profile, 1: Temporary velocitry profile)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_lvelsquare(struct interp_shpath &tmp_interp_shpath, uint16_t &input);

/*************************************************************************
@brief This function generates a cubic spline between the included reference orientations of the emergency path.
@details Spline parameter is the distance s over the previously interpolated cubic position spline.
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_csplineori(struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function unwraps the elements of orientation ori_enu_psi_rad in tmp_interp_shpath.
@details With the unwrap elements the vector ori_enu_psi_rad is updated.
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void path_unwrap_ori(struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function calculates the cummulative duration t for each emergency path element with cubic interpolation
@details The speed profile is cubic interpolated. Interpolated is a v²-s relation.
v²(s) = C3 * s³ + C2 * s² + C1 * s + C0
v(s) = sqrt(C3 * s³ + C2 * s² + C1 * s + C0)

Integral dt [t0, t] = Integral ds/v(s) [s0,s]
t0 - t = Integral ds / sqrt(C3 * s³ + C2 * s² + C1 * s + C0) [s0, s]
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2022
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_csegdur(struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function calculates the cummulative duration t for each emergency path element
@details  The speed profile is linearly interpolated. Interpolated is a v²-s relation.
v²(s) = C1 * s + C0
v(s) = sqrt(C1 * s + C0)

Integral dt [t0, t] = Integral ds/v(s) [s0,s]
t0 - t = Integral ds / sqrt(C1 * s + C0)
t0 - t = (2 * sqrt(C1 * s + C0)) / (C1) [s0, s]
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* * <u>Dependencies:</u>
* - ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void path_segdur(struct interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function checks the plausibility and the content of the interpolated interp_shpath
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] pathENU Emergency path in ENU coordinates
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    bool check_interp_shpath(pathENU &pathENU, interp_shpath &tmp_interp_shpath, dcm_err &dcm_err);

    /* Emergency Trajectory generation */

/*************************************************************************
@brief Thread thread_dcm_shpath variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    std::thread thread_dcm_shpath;

/*************************************************************************
@brief This function represents the the task for the dcm trajectory generation
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void task_dcm_shpath();

/*************************************************************************
@brief This function initializes the GRS80 ellipsoid of the library "GeogprahicLib".
@details Since ETRS89 was chosen as the reference system for the positions and the corresponding reference ellipsoid is GRS80, GeogprahicLib is initialized with GRS80
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2021
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static GeographicLib::Geocentric initgrs80ell();

/*************************************************************************
@brief This function initializes the parameters for dcm shpath
@param[out] param_dcm_shpath Parameter for dcm shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 16.04.2020
*************************************************************************/
    void init_dcm_shpath(param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This is the function for the dcm trajectory generation
@details In an infinite loop the interpolated emergency path in ENU coordinate system and the plattform sensors object list are received, a collision free trajectory processed and send to glob_trajENU
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] tmp_OL_fus Fused object list struct
@param[in] param_dcm_shpath Parameter for dcm shpath
@param[in] tmp_ecus ECU selection struct
@param[in] curr_interp_shpath_send_taitime Current tai time of current safe halt path
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.03.2022

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void func_dcm_shpath(struct interp_shpath &tmp_interp_shpath, struct OL_fus &tmp_OL_fus, param_dcm_shpath &param_dcm_shpath, struct ecuselect &tmp_ecus, taitime &curr_interp_shpath_send_taitime);

/*************************************************************************
@brief This function calculates the current arc velocity in m/s of the vehicle on the emergency path cubic interpolation
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] curr_v Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2022

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void cget_v_for_s(struct interp_shpath &tmp_interp_shpath, double &curr_v);

/*************************************************************************
@brief This function calculates the current arc velocity in m/s of the vehicle on the emergency path
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] curr_v Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.11.2021

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void get_v_for_s(struct interp_shpath &tmp_interp_shpath, double &curr_v);

/*************************************************************************
@brief This function calculates the current position s in meter of the vehicle on the emergency path for cubic speed interpolation
@details The calculation is based on the relative time since the beginning of the emergency path, the (always updated) speed profile and the emergency path spline
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] diff_tpath_count_s Time difference between now and the (steady) time at the start of the emergency path
@param[in] curr_s Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2022

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void cget_s_for_t(struct interp_shpath &tmp_interp_shpath, double &diff_tpath_count_s, double &curr_s);

/*************************************************************************
@brief This function calculates the current position s in meter of the vehicle on the emergency path
@details The calculation is based on the relative time since the beginning of the emergency path, the (always updated) speed profile and the emergency path spline
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] diff_tpath_count_s Time difference between now and the (steady) time at the start of the emergency path
@param[in] curr_s Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void get_s_for_t(struct interp_shpath &tmp_interp_shpath, double &diff_tpath_count_s, double &curr_s);

/*************************************************************************
@brief Helper function for trajectory length s integration for cubic velocity interpolation
@details The task of this function is to calculate the distances between two time points by integration over the velocity
     profile of the emergency path.
@param[in] a First time point in seconds (lower integration limit)
@param[in] b Second time point in seconds (Upper integration limit)
@param[in] tmp_interp_shpath Interp_shpath struct
@param[out] curr_s Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2021

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void cs_for_t_integral_helper(double &a, double &b, struct interp_shpath &tmp_interp_shpath, double &curr_s);

/*************************************************************************
@brief Helper function for trajectory length s integration
@details The task of this function is to calculate the distances between two time points by integration over the velocity
     profile of the emergency path.
@param[in] a First time point in seconds (lower integration limit)
@param[in] b Second time point in seconds (Upper integration limit)
@param[in] tmp_interp_shpath Interp_shpath struct
@param[out] curr_s Current position s in meter on the emergency path length
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void s_for_t_integral_helper(double &a, double &b, struct interp_shpath &tmp_interp_shpath, double &curr_s);

/*************************************************************************
@brief This function calculates s(t) with s0=0 and t0=0 for cubic velocity interpolation
@details With the relative t since the beginning of the emergency path, the difference between the current time t and the
     time of the beginning of the segment segm is calculated.

     Formula:
     1.     dt = ds / v(s)
     2.     t - t0 = Integral (ds / v(s) [s0, s]
     3.     v²(s) = C3 * s³ + C2 * s² + C1 * s + C0
     4      v(s) = sqrt(C3 * s³ + C2 * s² + C1 * s + C0)
     5.     t - t0 = Integral (ds / sqrt(C3 * s³ + C2 * s² + C1 * s + C0)) [s0, s]
     6.     t0 = 0 und s0 = 0
     7.     t(s) = Numerical integration
     8.     s(t) = Numerical integration

     t = delta_t_t0
     s = result
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] cspline_pos_enu_vel2_s_splineparam Structure for the 1d cubic interpolated v²-s spline parameter
@param[in] t t (for t - t0)
@param[in] segm Index of current spline segment
@param[out] result s(t), with t0 = 0 and s0 = 0
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.03.2022

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void cs_for_t_integral(struct interp_shpath &tmp_interp_shpath,
                          cspline_pos_enu_vel2_s_splineparam &cspline_pos_enu_vel2_s_splineparam, double &t, int &segm,
                          double &result);

/*************************************************************************
@brief This function calculates s(t) with s0=0 and t0=0.
@details With the relative t since the beginning of the emergency path, the difference between the current time t and the
     time of the beginning of the segment segm is calculated.

     Formula:
     1.     dt = ds / v(s)
     2.     t - t0 = Integral (ds / v(s) [s0, s]
     3.     v²(s) = C1 * s + C0
     4      v(s) sqrt(C1 * s + C0)
     5.     t - t0 = Integral (ds / sqrt(C1 * s + C0)) [s0, s]
     6.     t0 = 0 und s0 = 0
     7.     t(s) = ( (2 * sqrt(c1 * s + c0)) / (C1) ) - ( (2 * sqrt(c0)) / (c1) )
     8.     s(t) = ( (c1 * t²) / (4) ) + sqrt(c0) * t

     t = delta_t_t0
     s = result
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] lspline_pos_enu_vel2_s_splineparam Structure for the 1d linear interpolated v²-s spline parameter
@param[in] t t (for t - t0)
@param[in] segm Index of current spline segment
@param[out] result s(t), with t0 = 0 and s0 = 0
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void s_for_t_integral(struct interp_shpath &tmp_interp_shpath,
                          lspline_pos_enu_vel2_s_splineparam &lspline_pos_enu_vel2_s_splineparam, double &t, int &segm,
                          double &result);

/*************************************************************************
@brief This function searches the intersection between 2 boost.geometry linestring
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] curr_s Current path coordinate s
@return Original velocity at path coordinate s in m/s
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    double find_original_velocity(struct interp_shpath &tmp_interp_shpath, double curr_s);

	/*************************************************************************
	@brief This function adds all temporary safe halt path elements beginning at the current position (object to react to is NOT available)
	@param[in] tmp_interp_shpath Interp_shpath struct
	@param[in] tmp_tmp_pos_enu_s_m Temporary velocity profile
	@param[in] tmp_tmp_pos_arc_vel_m_s Temporary s profile
	@param[in] param_dcm_shpath Parameter for dcm_shpath
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 12.12.2021
	*************************************************************************/
	void add_remain_velocities_wo_object(struct interp_shpath &tmp_interp_shpath, std::vector<double> &tmp_tmp_pos_enu_s_m, std::vector<double> &tmp_tmp_pos_arc_vel_m_s, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function adds all temporary safe halt path elements beginning at the object (object to react to available)
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] tmp_tmp_pos_enu_s_m Temporary velocity profile
@param[in] tmp_tmp_pos_arc_vel_m_s Temporary s profile
@param[in] param_dcm_shpath Parameter for dcm_shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    void add_remain_velocities(struct interp_shpath &tmp_interp_shpath, std::vector<double> &tmp_tmp_pos_enu_s_m, std::vector<double> &tmp_tmp_pos_arc_vel_m_s, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function searches the intersection between 2 boost.geometry linestring
@param[in] ls1 boost.geometry linestring 1
@param[in] ls2 boost.geometry linestring 1
@return Intersection points
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    std::vector<boost::geometry::model::d2::point_xy<double>> find_intersections(boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> &ls1, boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> &ls2);

/*************************************************************************
@brief This function calculates the necessary acceleration between the ego path-velocity and the object path-velocity
@param[in] s_ego Path coordinate s of ego vehicle
@param[in] v2_ego Squared velocity at path coordinate s of ego vehicle
@param[in] s_object Path coordinate s of object
@param[in] v2_object Squared velocity at path coordinate s of object
@return Necessary acceleration
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    double find_neces_acc(double &s_ego, double &v2_ego, double &s_object, double &v2_object);

/*************************************************************************
@brief This function generates a boost.geometry vertical linestring for intersection search
@param[in] s_start Path coordinate s for the vertical boost.geometry linestring
@param[in] param_dcm_shpath Parameter for dcm_shpath
@return Vertical boost.geometry linestring
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.05.2022
*************************************************************************/
	boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_gen_vertic_linestring(double &s_begin, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function generates a boost.geometry parallel linestring for intersection search
@param[in] s_start Path coordinate s for start of parallel boost.geometry linestring
@param[in] v2 Squared velocity at path coordinate s as parallel velocity for parallel line string
@param[in] param_dcm_shpath Parameter for dcm_shpath
@return Parallel boost.geometry linestring
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_gen_paral_linestring(double &s_begin, double &v2, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function generates a boost.geometry deceleration linestring to 0 m/s for intersection search
@param[in] s_begin Path coordinate s for begin of deceleration boost.geometry linestring
@param[in] v2_begin Squared velocity at path coordinate s as start point for deceleration line string
@param[in] dec Requested deceleration for the line string
@return Deceleration boost.geometry linestring
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_gen_dec_linestring_to_zero(double &s_begin, double &v2_begin, double &dec);

/*************************************************************************
@brief This function generates a boost.geometry deceleration linestring for intersection search
@param[in] s_end Path coordinate s for end of deceleration boost.geometry linestring
@param[in] v2_end Squared velocity at path coordinate s as end point for deceleration line string
@param[in] dec Requested deceleration for the line string
@param[in] param_dcm_shpath Parameter for dcm_shpath
@return Deceleration boost.geometry linestring
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_gen_dec_linestring(double &s_end, double &v2_end, double &dec, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function generates a boost.geometry acceleration linestring for intersection search
@param[in] s_start Path coordinate s for start of acceleration boost.geometry linestring
@param[in] v2_start Squared velocity at path coordinate s as starting point for acceleration line string
@param[in] acc Requested acceleration for the line string
@param[in] param_dcm_shpath Parameter for dcm_shpath
@return Acceleration boost.geometry linestring
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.12.2021
*************************************************************************/
    boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>> bg_gen_acc_linestring(double &s_start, double &v2_start, double &acc, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function updated tmp_pos_arc_vel_m_s and tmp_pos_enu_s_m based on current position s on emergency path and detected target object
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.12.2021
*************************************************************************/
    void update_vel(struct interp_shpath &tmp_interp_shpath, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function calculates the arc length velocity of an target object at its position s on the safe halt path
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] obj_index Object index in tmp_OL_fus
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] vds Current vehicle dynamic state
@param[in] tmp_object_s Object position s on safe halt path
@param[out] obj_arc_vel Object absolute arc length velocity
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.04.2022
*************************************************************************/
    void get_obj_arc_vel(struct OL_fus &tmp_OL_fus, size_t &obj_index, struct interp_shpath &tmp_interp_shpath, vds &tmp_vds, double &tmp_object_s, double &obj_arc_vel);

/*************************************************************************
@brief This function calculates the position s on safe halt path for a given position in enu system
@param[in,out] tmp_interp_shpath interp_shpath struct
@param[in] c_point_east East coordinate of closest point on safe halt path
@param[in] c_point_north North coordinate of closest point on safe halt path
@param[in] tmp_object_s s on current safe halt path for input point
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.04.2022
*************************************************************************/
    void get_s_for_pos(struct interp_shpath &tmp_interp_shpath, double &c_point_east, double &c_point_north, double &tmp_object_s);

/*************************************************************************
@brief This function calculates the closest point on the safe halt path
@details Input is a point in enu coordinate system, output is the closest point on the safe halt path in enu coordinate system
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] point_east East coordinate of input point
@param[in] point_north North coordinate of input point
@param[out] c_point_east East coordinate of closest point on safe halt path
@param[out] c_point_north North coordinate of closest point on safe halt path
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 29.04.2022
*************************************************************************/
    void get_closest_points(struct interp_shpath &tmp_interp_shpath, double &point_east, double &point_north, double &c_point_east, double &c_point_north);

/*************************************************************************
@brief This function finds v and s to avoid collision with an target object (if available)
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] vds Current vehicle dynamic state
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@param[out] tmp_dcm_shpathplot Structure with data to plot debug map for thread dcm_shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 05.05.2022
*************************************************************************/
    void get_s_and_v_for_object(struct OL_fus &tmp_OL_fus, struct interp_shpath &tmp_interp_shpath, vds &tmp_vds, param_dcm_shpath &param_dcm_shpath, dcm_shpathplot &tmp_dcm_shpathplot);

/*************************************************************************
@brief This function checks for collisions of the remaining significant objects
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] vds Current vehicle dynamic state
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 23.11.2021
*************************************************************************/
    void filter_rest_extended_with_shpath(struct OL_fus &tmp_OL_fus, struct interp_shpath &tmp_interp_shpath, vds &tmp_vds, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function calculates the boost.geometry linestring for the current emergency path
@param[in,out] tmp_interp_shpath Interp_shpath struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 26.11.2021
*************************************************************************/
    void bg_calculate_path_linestring(interp_shpath &tmp_interp_shpath);

/*************************************************************************
@brief This function filters the remaining objects of the object list with regard to the safe halt path
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] vds Current vehicle dynamic state
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.11.2021
*************************************************************************/
    void filter_static_reference_point_with_shpath(struct OL_fus &tmp_OL_fus, struct interp_shpath &tmp_interp_shpath, vds &tmp_vds, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief Conversion of vehicle dynamic state to the enu plane of the safe halt path
@details This function performs the conversion of the vehicle dynamic state positions from global ellipsoidal
coordinates (ETRS89 -> reference ellipsoid GRS80) into the local coordinate system of the safe halt path
Origin of the local coordinate system is the planning pose of the emergency path.
@param[in] vds Vehicle dynamic state (position in global ellipsoidal coordinates)
@param[out] tmp_vds_enu Temporary vehicle dynamic state in enu system
@param[in] tmp_pos_ell_deg_shpath Temporary struct for the latitudes and longitudes of planning pose in degrees
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2021
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static void posell2enu_vds(vds &tmp_vds, vds_enu &tmp_vds_enu, tmp_pos_ell_deg_shpath &tmp_pos_ell_deg_shpath,
                               param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief Conversion of safe halt planning position from radians in degrees
@details This function performs the conversion of the safe halt planning position from radians to degrees
@param[in] tmp_interp_shpath interp_shpath struct
@param[out] tmp_pos_ell_deg_shpath Temporary struct for the latitudes and longitudes in degrees
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static void radtodeg_shpath(struct interp_shpath &tmp_interp_shpath, tmp_pos_ell_deg_shpath &tmp_pos_ell_deg_shpath);

/*************************************************************************
@brief This function transforms the relevant object list information to the global ENU system of the current safe halt path
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] vds Current vehicle dynamic state
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2021
*************************************************************************/
    void filter_reference_point_and_transform_OL(struct OL_fus &tmp_OL_fus, struct interp_shpath &tmp_interp_shpath, vds &tmp_vds, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function updates the speed profile of the emergency path considering the object list of the platform sensors and the current position of the vehicle
@param[in,out] tmp_interp_shpath interp_shpath struct
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void update_tmp_pos_arc_vel_m_s(struct interp_shpath &tmp_interp_shpath, struct OL_fus &tmp_OL_fus,
                             param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function fills the struct with the plot data
@param[in] tmp_OL_fus Fused object list struct
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] vds Current vehicle dynamic state
@param[out] tmp_dcm_shpathplot Structure with data to plot debug map for thread dcm_shpath
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 05.05.2022
*************************************************************************/
	void fill_dcm_shpathplot(struct OL_fus &tmp_OL_fus, struct interp_shpath &tmp_interp_shpath, vds &tmp_vds, dcm_shpathplot &tmp_dcm_shpathplot, param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function finds the target object (if available) and calculates s|v to avoid collision
@param[in,out] tmp_interp_shpath interp_shpath struct
@param[in,out] tmp_OL_fus Fused object list struct
@param[in] curr_s Current position s in meter on the emergency path length
@param[in] param_dcm_shpath Parameter for conversion (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void find_target_object(struct interp_shpath &tmp_interp_shpath, struct OL_fus &tmp_OL_fus,
                              param_dcm_shpath &param_dcm_shpath);

/*************************************************************************
@brief This function generates a target trajectory
@details The trajectory is based on the position and orientation information of the emergency path,
     the updated path velocity profile and the parameterization of the trajectory (number of trajectory elements, time
     duration between trajectory elements).
@param[in] tmp_interp_shpath Interp_shpath struct
@param[in] param_dcm_shpath Structure for the parameter for dcm trajectory generation
@param[out] tmp_trajENU trajENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020

<u>Dependencies:</u>
- ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
*************************************************************************/
    void gen_traj(struct interp_shpath &tmp_interp_shpath, param_dcm_shpath &param_dcm_shpath,
                  struct trajENU &tmp_trajENU);

/*************************************************************************
@brief This function calculates the ecu selection (ecu front/back or ecu left/right)
@details The selection is based on the side slip angle of the vehicle
@param[out] tmp_trajENU trajENU struct
@param[in] tmp_ecus ECU selection struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 23.01.2022
*************************************************************************/
    void gen_ecus(struct trajENU &tmp_trajENU, struct ecuselect &tmp_ecus);

/*************************************************************************
@brief TThis function calculate the TAI times for all elements of the trajectory (taking into account the delay_time)
@param[in] delay_time_s Delay time in seconds
@param[in] param_dcm_shpath Structure for the parameter for dcm trajectory generation
@param[out] tmp_trajENU trajENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void traj_taitimes(double &delay_time_s, param_dcm_shpath &param_dcm_shpath, struct trajENU &tmp_trajENU);

/*************************************************************************
@brief This function wraps the vehicle orientation to [-pi,pi]
@param[in,out] orientation Orientation angle for wrapping
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 19.08.2021
*************************************************************************/
	void wrap_ori(double &orientation);

/*************************************************************************
@brief This function converts the cartesian velocity and acceleration into polar coordinates
@param[out] tmp_trajENU trajENU struct
@param[in] vel_enu_east Velocity in east direction
@param[in] vel_enu_north Velocity in north direction
@param[in] acc_enu_east Acceleration in east direction
@param[in] acc_enu_north Acceleration in north direction
@param[in] stop Flag if vehicle is stopped. If yes only the velocity angle will be calculated, not the velocity magnitude
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void acc_vel_car_to_pol(struct trajENU &tmp_trajENU, double &vel_enu_east, double &vel_enu_north, double &acc_enu_east, double &acc_enu_north, bool stop);

/*************************************************************************
@brief This function searches the lateral and longitudinal slope for the current position tmp_s on the emergency path
@param[out] tmp_trajENU trajENU struct
@param[in] tmp_interp_shpath interp_shpath struct
@param[in] tmp_s Position s on emergency path (in m)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void slope_for_s(struct trajENU &tmp_trajENU, struct interp_shpath &tmp_interp_shpath, double &tmp_s);

/*************************************************************************
@brief This function checks the plausibility and the content of the generated trajENU.
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] tmp_trajENU Temporary trajectory in local ENU coordinate system
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    static bool check_trajENU(trajENU &tmp_trajENU, dcm_err &dcm_err);


/* Receive and preprocess plattform sensor radar data */

/*************************************************************************
@brief This function returns for a value of a radar sensor RMS (position) from a CAN message the corresponding physical value
@details For more information, see the technical documentation of the Continental ARS 408 used.
@param[in] value Value in a *_rms message of the radar sensor to be rendered into a physical unit.
@return RMS value for the passed value
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    double get_rms_pos(double value);

/*************************************************************************
@brief This function returns for a value of a radar sensor RMS (orientation) from a CAN message the corresponding physical value
@details For more information, see the technical documentation of the Continental ARS 408 used.
@param[in] value Value in a *_rms message of the radar sensor to be rendered into a physical unit.
@return RMS value for the passed value
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    double get_rms_ori(double value);

/*************************************************************************
@brief This function returns for a value of a radar sensor the probaality of existence of an object in percent
@details For more information, see the technical documentation of the Continental ARS 408 used.
@param[in] value Value in a probofexistence message of the radar sensor to be rendered into a percentage value
@return Percentage of probability of existence for passed value
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    double get_ProbOfExist(double value);

/*************************************************************************
@brief This function fills an object list with the received CAN message of a radar sensor.
@details If the check leads to a negative result, it is returned with a boolean false.
@param[out] OL_radar Radar object list
@param[in] message IXXAT Gateway CAN message as string
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    void fill_OL(OL_radar &OL_radar, std::string& message);

/*************************************************************************
@brief This function checks the plausibility and the content of the generated plattform radar sensor object list
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] tmp_OL_radar Temporary radar object list for plattform radar sensor
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    static bool check_OL_ps_R(OL_radar &tmp_OL_radar, dcm_err &dcm_err);

///*************************************************************************
//@brief Thread thread_ps_RF variable
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.06.2021
//*************************************************************************/
//    std::thread thread_ps_RF;
//
///*************************************************************************
//@brief This function represents the task for the radar date receiving and preprocessing (Front sensor)
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.06.2021
//
//<u>Dependencies:</u>
//- asio (www.think-async.com),  Chrisk Kohlhoff (Version 1.18.2, Boost Software License, Version 1.0)
//*************************************************************************/
//    void task_ps_RF();
//
///*************************************************************************
//@brief This is the function for the radar date receiving and preprocessing (Front sensor)
//@details In an infinite loop the data of the plattform radar sensor in the vehicle back is received, processed and send to int_glob_OL_ps_RF
//@param[in] OL_ps_RF Radar object list for plattform front radar sensor
//@param[in] dcm_net_R TCP connection to IXXAT gateway for radar sensors (Radar front IP: 192.168.127.53, Port: 19227; Radar back IP: 192.168.127.55, Port: 19227)
//@param[in] input Origin of this check_vds (0: radar front, 1: radar back)
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 02.08.2021
//
//<u>Dependencies:</u>
//- asio (www.think-async.com), Chrisk Kohlhoff (Version 1.18.2, Boost Software License, Version 1.0)
//    *************************************************************************/
//    void func_ps_R(OL_radar &OL_ps_RF, client_interface &dcm_net_R, uint16_t &input);
//
///*************************************************************************
//@brief Thread thread_ps_RB variable
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.06.2021
//*************************************************************************/
//    std::thread thread_ps_RB;
//
///*************************************************************************
//@brief This function represents the the task for the radar date receiving and preprocessing (Back sensor)
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.06.2021
//
//<u>Dependencies:</u>
//- asio (www.think-async.com),  Chrisk Kohlhoff (Version 1.18.2, Boost Software License, Version 1.0)
//*************************************************************************/
//    void task_ps_RB();
//
//    /* Receive and preprocess plattform sensor ultrasonic data */
//
///*************************************************************************
//@brief Thread thread_ps_ECU variable
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.06.2021
//*************************************************************************/
//    std::thread thread_ps_ECU;
//
///*************************************************************************
//@brief This function represents the the task for the ultrasonic sensor data receiving and preprocessing
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.06.2021
//
//<u>Dependencies:</u>
//- asio (www.think-async.com),  Chrisk Kohlhoff (Version 1.18.2, Boost Software License, Version 1.0)
//*************************************************************************/
//    void task_ps_ECU();
//
///*************************************************************************
//@brief This is the function for the ultrasonic sensor data receiving and preprocessing
//@details In an infinite loop the data of the plattform ultrasonic sensors is received, processed and send to int_glob_FL_ps_ECU
//@param[in] FL_ps_ECU Ultrasonic sensor feature list
//@param[in] odot_ps_ECU Ultrasonic sensor odometry
//@param[in] ext_SDI_uss Ultrasonic sensor SDI
//@param[in] dcm_net_uss UDP connection to USS ECU 1 (Vehicle ECU IP: 192.168.127.56 Port: 7536, Development ECU IP: 192.168.1.5, Port: 7536)
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 15.12.2021
//
//<u>Dependencies:</u>
//- asio (www.think-async.com), Chrisk Kohlhoff (Version 1.18.2, Boost Software License, Version 1.0)
//*************************************************************************/
//    void func_ps_ECU(FL_uss &FL_ps_ECU, odot_uss &odot_ps_ECU, SDI_uss &ext_SDI_uss, client_interface_uss &dcm_net_uss);

///*************************************************************************
//@brief This function fills an uss ecu odometry struct with the received ethernet message of a uss/camera ecu
//@param[out] FL_radar USS/camera feature list
//@param[in] message USS/Camera data struct
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 15.12.2021
//*************************************************************************/
//    void fill_odot(odot_uss &ext_odot_uss, tsqueue_datatype_uss& message);

///*************************************************************************
//@brief This function fills an feature list with the received ethernet message of a uss/camera ecu
//@param[out] ext_FL_uss USS/camera feature list
//@param[in] message USS/Camera data struct
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 15.12.2021
//*************************************************************************/
//    void fill_FL(FL_uss &ext_FL_uss, tsqueue_datatype_uss& message);

///*************************************************************************
//@brief This function fills an sdi with the received ethernet message from the ECU2 via gateway ECU1
//@param[out] ext_SDI_uss USS SDI
//@param[in] message USS SDI data struct
//@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
//@date 01.03.2022
//*************************************************************************/
//    void fill_SDI(SDI_uss &ext_SDI_uss, tsqueue_datatype_uss& message);

/*************************************************************************
@brief This function checks the plausibility and the content of the generated plattform ultrasonic sensor feature list
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] tmp_FL_ps_ECU Temporary ultrasonic sensor feature list
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    static bool check_FL_ps_ECU(FL_uss &tmp_FL_ps_ECU, dcm_err &dcm_err);

/* Fusion of both radar sensor object lists and the ultrasonic sensor feature list */

/*************************************************************************
@brief Thread thread_ps_fusion variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    std::thread thread_ps_fusion;

/*************************************************************************
@brief This function represents the the task for the fusion of of both radar sensor object lists and the ultrasonic sensor feature list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021

*************************************************************************/
    void task_ps_fusion();

/*************************************************************************
@brief This function initializes the parameters for ps_fusion
@param[out] param_ps_fusion Parameter for ps_fusion
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    void init_ps_fusion(param_ps_fusion &param_ps_fusion);

/*************************************************************************
@brief This function receives vehicle dynamic state (vds) from glob_vds
@param[in,out] ext_vds vds struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
    void rx_vds(vds &ext_vds);

/*************************************************************************
@brief This is the function for the fusion of of both radar sensor object lists and the ultrasonic sensor feature list
@details In an infinite loop the data of the plattform sensors (Both radar sensors and the ultrasonic ECU) are received, fused and send to int_glob_fus_OL
@param[in] ext_OL_radar_RF External radar object list for front radar sensor
@param[in] ext_OL_radar_RB External radar object list for back radar sensor
@param[in] ext_FL_uss External ultrasonic sensor feature list
@param[in] param_ps_fusion Parameter struct for sensor fusion function
@param[in] vds vds struct for vehicle state
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021

<u>Dependencies:</u>
- Eigen (eigen.tuxfamily.org), Benoît Jacob (founder) and Gaël Guennebaud (guru) (Version 3.4.0,  Mozilla Public License Version 2.0)
*************************************************************************/
    void func_ps_fusion(OL_radar &ext_OL_radar_RF, OL_radar &ext_OL_radar_RB, FL_uss &ext_FL_uss, param_ps_fusion &param_ps_fusion, vds &vds);

/*************************************************************************
@brief This is the function to transform and add both radar sensor information to the fused object list
@details First the position, velocity and acceleration object information are transformed to the UNICARagil vehicle coordinate system
@param[out] OL_fus Fused object list with both radar sensor information
@param[in] ext_OL_radar_RF External radar object list for front radar sensor
@param[in] ext_OL_radar_RB External radar object list for back radar sensor
@param[in] ext_FL_uss External uss and camera feature list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    void prep_OL_fus(OL_fus &OL_fus, OL_radar &ext_OL_radar_RF, OL_radar &ext_OL_radar_RB, FL_uss &ext_FL_uss);

/*************************************************************************
@brief This is the function to transform and add both radar sensor information to the fused object list
@details First the position, velocity and acceleration object information are transformed to the UNICARagil vehicle coordinate system
@param[out] OL_fus Fused object list with both radar sensor information
@param[in] ext_OL_radar_RF External radar object list for front radar sensor
@param[in] ext_OL_radar_RB External radar object list for back radar sensor
@param[in] param_ps_fusion Parameter struct for sensor fusion function
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    void add_ps_R_OL_fus(OL_fus &OL_fus, OL_radar &ext_OL_radar_RF, OL_radar &ext_OL_radar_RB, param_ps_fusion &param_ps_fusion);

/*************************************************************************
@brief This is the function to transform and add uss and camera information to the fused object list
@details First the position feature information are transformed to the UNICARagil vehicle coordinate system
@param[out] OL_fus Fused object list with all sensor information
@param[in] ext_FL_uss External uss and camera feature list
@param[in] param_ps_fusion Parameter struct for sensor fusion function
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    void add_ps_uss_OL_fus(OL_fus &OL_fus, FL_uss &ext_FL_uss, param_ps_fusion &param_ps_fusion);

/*************************************************************************
@brief This function receives the plattform sensor object lists and ultrasonic feature lists
@param[in] ext_OL_radar_RF Object list (front radar sensor)
@param[in] ext_OL_radar_RB Object list (back radar sensor)
@param[in] ext_FL_uss Feature list (ultrasonic sensors)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    void rx_xL_ps(OL_radar &ext_OL_radar_RF, OL_radar &ext_OL_radar_RB, FL_uss &ext_FL_uss);

/*************************************************************************
@brief This function checks the plausibility and the content of the fused object list
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] tmp_OL_fus Temporary common fused object list
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 01.06.2021
*************************************************************************/
    static bool check_OL_fus(OL_fus &tmp_OL_fus, dcm_err &dcm_err);

    /* dcmstatus processing */
    /*************************************************************************
@brief This function checks the plausibility and the content of the received interp_shpathstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] interp_shpathstatus Struct for interp_shpathstatus
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static bool check_interp_shpathstatus(interp_shpathstatus &interp_shpathstatus, dcm_err &dcm_err);

/*************************************************************************
@brief Calculate the status of thread interp_shpath
@param[in] interp_shpathstatus Struct of interp_shpathstatus
@param[out] dcmstatus Temporary struct for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static void calc_interp_shpathstatus(interp_shpathstatus &interp_shpathstatus, dcmstatus &dcmstatus);

/*************************************************************************
@brief This function checks the plausibility and the content of the received dcm_shpathstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] dcm_shpathstatus Struct for dcm_shpathstatus
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static bool check_dcm_shpathstatus(dcm_shpathstatus &dcm_shpathstatus, dcm_err &dcm_err);

/*************************************************************************
@brief Calculate the status of thread dcm_shpath
@param[in] dcm_shpathstatus Struct of dcm_shpathstatus
@param[out] dcmstatus Temporary struct for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static void calc_dcm_shpathstatus(dcm_shpathstatus &dcm_shpathstatus, dcmstatus &dcmstatus);

/*************************************************************************
@brief This function checks the plausibility and the content of the received ps_Rstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] ps_Rstatus Struct for ps_Rstatus
@param[in] dcm_err Error struct
@param[in] input Origin of this check (0: radar front, 1: radar back)
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static bool check_ps_Rstatus(ps_Rstatus &ps_Rstatus, dcm_err &dcm_err, uint16_t &input);

/*************************************************************************
@brief Calculate the status of thread ps_R
@param[in] ps_Rstatus Struct of ps_Rstatus
@param[out] dcmstatus Temporary struct for dcmstatus
@param[in] input Origin of this check (0: radar front, 1: radar back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static void calc_ps_Rstatus(ps_Rstatus &ps_Rstatus, dcmstatus &dcmstatus, uint16_t &input);

/*************************************************************************
@brief This function checks the plausibility and the content of the received ps_ECUstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] ps_ECUstatus Struct for ps_ECUstatus
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static bool check_ps_ECUstatus(ps_ECUstatus &ps_ECUstatus, dcm_err &dcm_err);

/*************************************************************************
@brief Calculate the status of thread ps_ECU
@param[in] ps_ECUstatus Struct of ps_ECUstatus
@param[out] dcmstatus Temporary struct for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static void calc_ps_ECUstatus(ps_ECUstatus &ps_ECUstatus, dcmstatus &dcmstatus);

/*************************************************************************
@brief This function checks the plausibility and the content of the received ps_fusionstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] ps_fusionstatus Struct for ps_fusionstatus
@param[in] dcm_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static bool check_ps_fusionstatus(ps_fusionstatus &ps_fusionstatus, dcm_err &dcm_err);

/*************************************************************************
@brief Calculate the status of thread ps_fusion
@param[in] ps_fusionstatus Struct of ps_fusionstatus
@param[out] dcmstatus Temporary struct for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    static void calc_ps_fusionstatus(ps_fusionstatus &ps_fusionstatus, dcmstatus &dcmstatus);

/* dcm status thread */

/*************************************************************************
@brief Thread dcmstatus variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    std::thread thread_dcmstatus;

/*************************************************************************
@brief This function represents the the task for the dcmstatus processing
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void task_dcmstatus();

/*************************************************************************
@brief This is the function for processing the dcmstatus.
@details This function collects the status information of the threads to calculates the status of the service
@param[in] interp_shpathstatus Struct for interp_shpathstatus
@param[in] dcm_shpathstatus Struct for dcm_shpathstatus
@param[in] ps_RFstatus Struct for ps_RFstatus
@param[in] ps_RBstatus Struct for ps_RBstatus
@param[in] ps_ECUstatus Struct for ps_ECUstatus
@param[in] ps_fusionstatus Struct for ps_fusionstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void func_dcmstatus(interp_shpathstatus &interp_shpathstatus, dcm_shpathstatus &dcm_shpathstatus, ps_Rstatus &ps_RFstatus, ps_Rstatus &ps_RBstatus, ps_ECUstatus &ps_ECUstatus, ps_fusionstatus &ps_fusionstatus);


public:

/*************************************************************************
@brief This is the constructor of dcmcore
@details The constructor calls method dcmreset to join all (if already running) threads and starts new dcm threads
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    dcmcore() {

        dcmexit();

    }

/*************************************************************************
@brief This is the destructor of dcmcore
@details The destructor calls method dcmexit to join all dcm threads
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    ~dcmcore() {

        dcmexit();

    }

/*************************************************************************
@brief This function resets the threads of dcm
@details In the first step the exitCondition is set to true. Then all conditional_variables are notified.
 In the next step each thread is checked if it is joinable. If it is joinable the thread is joined.
 After joining all threads to exitCondition is set to false and the threads are started again
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    void dcmreset(){

        dcmexit();
        dcmstart();
    }

/*************************************************************************
@brief This function stops the threads of dcm
@details In the first step the exitCondition is set to true. Then all conditional_variables are notified. In the next step each thread is checked if it is joinable. If it is joinable the thread is joined.
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    void dcmexit(){

        dcminterface::exitCondition = true;
        dcminterface::OL_fus_new = false;
        dcminterface::interp_shpath_new = false;
        dcminterface::OL_ps_RF_new = false;
        dcminterface::OL_ps_RB_new = false;
        dcminterface::FL_ps_ECU_new = false;
        dcminterface::pathENU_new = false;
        dcminterface::trajENU_new = false;
        dcminterface::dcm_err_empty = true;
        dcminterface::dcmstatus_new = false;
        dcminterface::ecus_new = false;
        dcminterface::FOL_d_new = false;
        dcminterface::ishp_d_new = false;
        dcminterface::RFOL_d_new = false;
        dcminterface::RBOL_d_new = false;
        dcminterface::dcm_shpathplot_new = false;
        dcminterface::ps_fusion_input_never = true;
        dcminterface::interp_shpath_never = true;
        dcminterface::cv_glob_pathENU.notify_one();
        dcminterface::cv_dcm_shpath_input.notify_one();
        dcminterface::cv_glob_trajENU.notify_one();
        dcminterface::cv_glob_dcm_err.notify_one();
        dcminterface::cv_ps_fusion_input.notify_one();
        dcminterface::cv_glob_dcmstatus.notify_one();
        dcminterface::cv_glob_ecus.notify_one();
        dcminterface::cv_glob_FOL_d.notify_one();
        dcminterface::cv_glob_ishp_d.notify_one();
        dcminterface::cv_glob_RFOL_d.notify_one();
        dcminterface::cv_glob_RBOL_d.notify_one();
        dcminterface::cv_glob_dcm_shpathplot.notify_one();

        /* Join thread_interp_shpath */
        if (thread_interp_shpath.joinable()) {

            thread_interp_shpath.join();

        }

        /* Join thread_dcm_shpath */
        if (thread_dcm_shpath.joinable()) {

            thread_dcm_shpath.join();

        }

//        /* Join thread_ps_RF */
//        if (thread_ps_RF.joinable()) {
//
//            thread_ps_RF.join();
//
//        }
//
//        /* Join thread_ps_RB */
//        if (thread_ps_RB.joinable()) {
//
//            thread_ps_RB.join();
//
//        }
//
//        /* Join thread_ps_ECU */
//        if (thread_ps_ECU.joinable()) {
//
//            thread_ps_ECU.join();
//
//        }

        /* Join thread_ps_fusion */
        if (thread_ps_fusion.joinable()) {

            thread_ps_fusion.join();

        }

		/* Join thread_dcmstatus */
		if (thread_dcmstatus.joinable()) {

			thread_dcmstatus.join();

		}

    }

/*************************************************************************
@brief This function spawns the threads of dcm
@details In the first step all global variables are cleared. Then the exitCondition is set to false and the threads are started.
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    void dcmstart() {

        /* Clear all global variables */

        {
            //Use lock_guard to lock glob_pathENU
            std::lock_guard<std::mutex> guard_glob_pathENU{dcminterface::mx_glob_pathENU};
            dcminterface::glob_pathENU = {0};
        }

        {
            //Use lock_guard to lock int_glob_interp_shpath
            std::lock_guard<std::mutex> guard_int_glob_interp_shpath{dcminterface::mx_dcm_shpath_input};
            dcminterface::int_glob_interp_shpath = {0};
        }

        {
            //Use lock_guard to lock glob_trajENU
            std::lock_guard<std::mutex> guard_glob_trajENU{dcminterface::mx_glob_trajENU};
            dcminterface::glob_trajENU = {0};
        }


        {
            //Use lock_guard to lock glob_dcm_err
            std::lock_guard<std::mutex> guard_glob_dcm_err{dcminterface::mx_glob_dcm_err};
            dcminterface::glob_dcm_err.clear();
        }

        {
            //Use lock_guard to lock int_glob_OL_ps_RF
            std::lock_guard<std::mutex> guard_int_glob_OL_ps_RF{dcminterface::mx_ps_fusion_input};
            dcminterface::int_glob_OL_ps_RF = {0};
        }

        {
            //Use lock_guard to lock int_glob_OL_ps_RB
            std::lock_guard<std::mutex> guard_int_glob_OL_ps_RB{dcminterface::mx_ps_fusion_input};
            dcminterface::int_glob_OL_ps_RB = {0};
        }

        {
            //Use lock_guard to lock int_glob_FL_ps_ECU
            std::lock_guard<std::mutex> guard_int_glob_FL_ps_ECU{dcminterface::mx_ps_fusion_input};
            dcminterface::int_glob_FL_ps_ECU = {0};
        }

        {
            //Use lock_guard to lock int_glob_OL_fus
            std::lock_guard<std::mutex> guard_int_glob_OL_fus{dcminterface::mx_dcm_shpath_input};
            dcminterface::int_glob_OL_fus = {0};
        }

        {
            //Use lock_guard to lock glob_interp_shpathstatus
            std::lock_guard<std::mutex> guard_glob_interp_shpathstatus{dcminterface::mx_glob_interp_shpathstatus};
            dcminterface::glob_interp_shpathstatus = {0};
        }

        {
            //Use lock_guard to lock glob_dcm_shpathstatus
            std::lock_guard<std::mutex> guard_glob_dcm_shpathstatus{dcminterface::mx_glob_dcm_shpathstatus};
            dcminterface::glob_dcm_shpathstatus = {0};
        }

        {
            //Use lock_guard to lock glob_ps_RFstatus
            std::lock_guard<std::mutex> guard_glob_ps_RFstatus{dcminterface::mx_glob_ps_RFstatus};
            dcminterface::glob_ps_RFstatus = {0};
        }

        {
            //Use lock_guard to lock glob_ps_RBstatus
            std::lock_guard<std::mutex> guard_glob_ps_RBstatus{dcminterface::mx_glob_ps_RBstatus};
            dcminterface::glob_ps_RBstatus = {0};
        }

        {
            //Use lock_guard to lock glob_ps_ECUstatus
            std::lock_guard<std::mutex> guard_glob_ps_ECUstatus{dcminterface::mx_glob_ps_ECUstatus};
            dcminterface::glob_ps_ECUstatus = {0};
        }

        {
            //Use lock_guard to lock glob_ps_fusionstatus
            std::lock_guard<std::mutex> guard_glob_ps_fusionstatus{dcminterface::mx_glob_ps_fusionstatus};
            dcminterface::glob_ps_fusionstatus = {0};
        }

        {
            //Use lock_guard to lock glob_FOL_d
            std::lock_guard<std::mutex> guard_glob_FOL_d{dcminterface::mx_glob_FOL_d};
            dcminterface::glob_FOL_d = {0};
        }

        {
            //Use lock_guard to lock glob_ishp_d
            std::lock_guard<std::mutex> guard_glob_ishp_d{dcminterface::mx_glob_ishp_d};
            dcminterface::glob_ishp_d = {0};
        }

        {
            //Use lock_guard to lock glob_RFOL_d
            std::lock_guard<std::mutex> guard_glob_RFOL_d{dcminterface::mx_glob_RFOL_d};
            dcminterface::glob_RFOL_d = {0};
        }

        {
            //Use lock_guard to lock glob_RBOL_d
            std::lock_guard<std::mutex> guard_glob_RBOL_d{dcminterface::mx_glob_RBOL_d};
            dcminterface::glob_RBOL_d = {0};
        }

        {
            //Use lock_guard to lock glob_dcm_shpathplot
            std::lock_guard<std::mutex> guard_glob_dcm_shpathplot{dcminterface::mx_glob_dcm_shpathplot};
            dcminterface::glob_dcm_shpathplot = {0};
        }

        /* Read psa parameter from csv file */
        dcminterface::read_dcmparam();

        /* Start dcm threads */
        dcminterface::exitCondition = false;
        dcminterface::OL_fus_new = false;
        dcminterface::interp_shpath_new = false;
        dcminterface::OL_ps_RF_new = false;
        dcminterface::OL_ps_RB_new = false;
        dcminterface::FL_ps_ECU_new = false;
        dcminterface::pathENU_new = false;
        dcminterface::trajENU_new = false;
        dcminterface::dcm_err_empty = true;
        dcminterface::dcmstatus_new = false;
        dcminterface::ecus_new = false;
        dcminterface::FOL_d_new = false;
        dcminterface::ishp_d_new = false;
        dcminterface::RFOL_d_new = false;
        dcminterface::RBOL_d_new = false;
        dcminterface::dcm_shpathplot_new = false;
        dcminterface::ps_fusion_input_never = true;
        dcminterface::interp_shpath_never = true;
        thread_interp_shpath = std::thread(&dcmcore::task_interp_shpath, this);
        thread_dcm_shpath = std::thread(&dcmcore::task_dcm_shpath, this);

//        if (dcmparam::sensorson) {
//
//            thread_ps_RF = std::thread(&dcmcore::task_ps_RF, this);
//            thread_ps_RB = std::thread(&dcmcore::task_ps_RB, this);
//            thread_ps_ECU = std::thread(&dcmcore::task_ps_ECU, this);
//
//        }

        thread_ps_fusion = std::thread(&dcmcore::task_ps_fusion, this);
        thread_dcmstatus = std::thread(&dcmcore::task_dcmstatus,this);

    }

};

#endif //DCM_CORE_H
