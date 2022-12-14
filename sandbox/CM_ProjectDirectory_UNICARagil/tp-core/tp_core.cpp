/**
 * \file tp_core.cpp
 * \brief Implementation of tp_core.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

//Main-Header

#include "tp_core.h"

bool tpcore::check_pathENU(pathGCS &pathGCS, pathENU &tmp_pathENU, tp_err &tp_err) {

    bool return_value = true;

    // Check for equal size of all tmp_pathENU vectors
    if (tmp_pathENU.pos_arc_vel_m_s.size() != tmp_pathENU.pos_enu_north_m.size() ||
        tmp_pathENU.pos_enu_north_m.size() != tmp_pathENU.pos_enu_east_m.size() ||
        tmp_pathENU.pos_enu_east_m.size() != tmp_pathENU.n_elements) {

        tp_err.errpathENU = tmp_pathENU;
        tp_err.errpathGCS = pathGCS;
        tp_err.errstring = "tp: Not all vectors in pathENU have the same size or don't match n_elements";
        tp_err.errcode = 3;

        /* Increase number of errors of error code 3 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[1] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }

    // Check if pathENU has at least 2 elements
    if (tmp_pathENU.pos_enu_north_m.size() < 2) {

        tp_err.errpathENU = tmp_pathENU;
        tp_err.errstring = "dcm: pathENU has less than 2 elements";
        tp_err.errcode = 3;

        /* Increase number of errors of error code 3 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[1] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }


    // Check if at least one element of pos_enu_north_m in tmp_pathENU is infinite, NaN, greater 2000 or smaller -2000 (meters)
    for (auto it = tmp_pathENU.pos_enu_north_m.begin(); it != tmp_pathENU.pos_enu_north_m.end(); ++it) {

        if (!(std::isfinite(*it)) || *it > 2000 || *it < -2000) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errpathENU = tmp_pathENU;
            tp_err.errstring = "tp: At least one elements absolute value of pos_enu_north_m in pathENU is greater than 2000, infinite or NaN";
            tp_err.errcode = 3;

            /* Increase number of errors of error code 3 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[1] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of pos_enu_east_m in tmp_pathENU is infinite, NaN, greater 2000 or smaller -2000
    for (auto it = tmp_pathENU.pos_enu_east_m.begin(); it != tmp_pathENU.pos_enu_east_m.end(); ++it) {

        if (!(std::isfinite(*it)) || *it > 2000 || *it < -2000) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errpathENU = tmp_pathENU;
            tp_err.errstring = "tp: At least one elements absolute value of pos_enu_east_m in pathENU is greater than 2000, infinite or NaN";
            tp_err.errcode = 3;

            /* Increase number of errors of error code 3 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[1] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    return return_value;

}

bool tpcore::check_trajENU(trajGCS &trajGCS, trajENU &tmp_trajENU, tp_err &tp_err) {

    bool return_value = true;

    // Check for equal size of all trajGCS vectors
    if (tmp_trajENU.tai_seconds.size() != tmp_trajENU.pos_enu_north_m.size() ||
        tmp_trajENU.pos_enu_north_m.size() != tmp_trajENU.pos_enu_east_m.size() ||
        tmp_trajENU.pos_enu_east_m.size() != 50) {

        tp_err.errtrajGCS = trajGCS;
        tp_err.errtrajENU = tmp_trajENU;
        tp_err.errstring = "tp: Not all vectors in trajENU have the same size or don't have size 50";
        tp_err.errcode = 1;

        /* Increase number of errors of error code 1 to trajstatus */
        {
            std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
            tpinterface::glob_trajstatus.no_errcode[1] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }

    // Check if at least one element of pos_enu_north_m in tmp_trajENU is infinite, NaN, greater 2000 or smaller -2000
    for (auto it = tmp_trajENU.pos_enu_north_m.begin(); it != tmp_trajENU.pos_enu_north_m.end(); ++it) {

        if (!(std::isfinite(*it)) || *it > 2000 || *it < -2000) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errtrajENU = tmp_trajENU;
            tp_err.errstring = "tp: At least one elements absolute value of pos_enu_north_m in trajENU is greater than 2000";
            tp_err.errcode = 1;

            /* Increase number of errors of error code 1 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[1] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of pos_enu_east_m in tmp_trajENU is infinite, NaN, greater 2000 or smaller -2000
    for (auto it = tmp_trajENU.pos_enu_east_m.begin(); it != tmp_trajENU.pos_enu_east_m.end(); ++it) {

        if (!(std::isfinite(*it)) || *it > 2000 || *it < -2000) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errtrajENU = tmp_trajENU;
            tp_err.errstring = "tp: At least one elements absolute value of pos_enu_east_m in trajENU is greater than 2000";
            tp_err.errcode = 1;

            /* Increase number of errors of error code 1 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[1] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    return return_value;

}

void tpcore::posell2enu_path(pathGCS &pathGCS, pathENU &tmp_pathENU, tmp_pos_ell_deg_path &tmp_pos_ell_deg_path,
                             param_path &param_path) {

    double path_pos_enu_east_m;
    double path_pos_enu_north_m;
    double path_pos_enu_up_m;

    // Initialisation of the ENU plane at reference ellipsoid GRS80 (Origin is the first position of the emergency path.)
    GeographicLib::LocalCartesian proj(tmp_pos_ell_deg_path.pos_ell_lat_deg.at(0),
                                       tmp_pos_ell_deg_path.pos_ell_lon_deg.at(0),
                                       pathGCS.pos_ell_h_m.at(0), param_path.grs80ell);

    // Loop for the conversion of all emergency path positions
    for (size_t i = 1; i < tmp_pos_ell_deg_path.pos_ell_lat_deg.size(); i++) {

        /* Geographiclib */
        proj.Forward(tmp_pos_ell_deg_path.pos_ell_lat_deg.at(i), tmp_pos_ell_deg_path.pos_ell_lon_deg.at(i),
                     pathGCS.pos_ell_h_m.at(i),
                     path_pos_enu_east_m, path_pos_enu_north_m,
                     path_pos_enu_up_m);

        /* Save to tmp_pathENU */
        tmp_pathENU.pos_enu_east_m.insert(tmp_pathENU.pos_enu_east_m.end(), path_pos_enu_east_m);

        tmp_pathENU.pos_enu_north_m.insert(tmp_pathENU.pos_enu_north_m.end(), path_pos_enu_north_m);

    }

}

void tpcore::posell2enu_traj(trajGCS &trajGCS, trajENU &tmp_trajENU, tmp_pos_ell_deg_traj &tmp_pos_ell_deg_traj,
                             param_traj &param_traj) {

    double traj_pos_enu_east_m;
    double traj_pos_enu_north_m;
    double traj_pos_enu_up_m;

    // Initialisation of the ENU plane at reference ellipsoid GRS80 (Origin is the first position of the trajectory)
    GeographicLib::LocalCartesian proj(tmp_pos_ell_deg_traj.pos_ell_lat_deg.at(0),
                                       tmp_pos_ell_deg_traj.pos_ell_lon_deg.at(0),
                                       trajGCS.pos_ell_h_m.at(0), param_traj.grs80ell);

    // Loop for the conversion of all trajectory positions
    for (size_t i = 1; i < tmp_pos_ell_deg_traj.pos_ell_lat_deg.size(); i++) {

        /* Geographiclib */
        proj.Forward(tmp_pos_ell_deg_traj.pos_ell_lat_deg.at(i), tmp_pos_ell_deg_traj.pos_ell_lon_deg.at(i),
                     trajGCS.pos_ell_h_m.at(i),
                     traj_pos_enu_east_m,
                     traj_pos_enu_north_m,
                     traj_pos_enu_up_m);

        /* Save to tmp_trajENU */
        tmp_trajENU.pos_enu_east_m.insert(tmp_trajENU.pos_enu_east_m.end(), traj_pos_enu_east_m);

        tmp_trajENU.pos_enu_north_m.insert(tmp_trajENU.pos_enu_north_m.end(), traj_pos_enu_north_m);

    }

}

void tpcore::radtodeg_path(pathGCS &pathGCS, tmp_pos_ell_deg_path &tmp_pos_ell_deg_path) {

    // Reserve vectors
    tmp_pos_ell_deg_path.pos_ell_lat_deg.reserve(pathGCS.pos_ell_lon_rad.size());
    tmp_pos_ell_deg_path.pos_ell_lon_deg.reserve(pathGCS.pos_ell_lon_rad.size());

    /* Loop for the conversion of emergency path positions from rad to deg */
    for (size_t i = 0; i < pathGCS.pos_ell_lon_rad.size(); i++) {

        tmp_pos_ell_deg_path.pos_ell_lat_deg.insert(tmp_pos_ell_deg_path.pos_ell_lat_deg.end(),
                                                    pathGCS.pos_ell_lat_rad.at(i) /
                                                    GeographicLib::Constants::degree());

        tmp_pos_ell_deg_path.pos_ell_lon_deg.insert(tmp_pos_ell_deg_path.pos_ell_lon_deg.end(),
                                                    pathGCS.pos_ell_lon_rad.at(i) /
                                                    GeographicLib::Constants::degree());

    }

}

void tpcore::radtodeg_traj(trajGCS &trajGCS, tmp_pos_ell_deg_traj &tmp_pos_ell_deg_traj) {

    // Reserve vectors
    tmp_pos_ell_deg_traj.pos_ell_lat_deg.reserve(trajGCS.pos_ell_lon_rad.size());
    tmp_pos_ell_deg_traj.pos_ell_lon_deg.reserve(trajGCS.pos_ell_lon_rad.size());

    /* Loop for the conversion of trajectory positions from rad to deg */
    for (size_t i = 0; i < trajGCS.pos_ell_lon_rad.size(); i++) {

        tmp_pos_ell_deg_traj.pos_ell_lat_deg.insert(tmp_pos_ell_deg_traj.pos_ell_lat_deg.end(),
                                                    trajGCS.pos_ell_lat_rad.at(i) /
                                                    GeographicLib::Constants::degree());

        tmp_pos_ell_deg_traj.pos_ell_lon_deg.insert(tmp_pos_ell_deg_traj.pos_ell_lon_deg.end(),
                                                    trajGCS.pos_ell_lon_rad.at(i) /
                                                    GeographicLib::Constants::degree());

    }

}

bool tpcore::check_pathGCS(pathGCS &pathGCS, tp_err &tp_err) {

    bool return_value = true;

    // Check for equal size of all pathGCS vectors
    if (pathGCS.pos_arc_vel_m_s.size() != pathGCS.pos_ell_lat_rad.size() ||
        pathGCS.pos_ell_lat_rad.size() != pathGCS.pos_ell_lon_rad.size() ||
        pathGCS.pos_ell_lon_rad.size() != pathGCS.pos_ell_h_m.size() ||
        pathGCS.pos_ell_h_m.size() != pathGCS.slope_long.size() ||
        pathGCS.slope_long.size() != pathGCS.slope_lat.size() ||
        pathGCS.slope_lat.size() != pathGCS.ori_enu_psi_rad.size() ||
        pathGCS.ori_enu_psi_rad.size() != pathGCS.dir_ind.size() ||
        pathGCS.dir_ind.size() != pathGCS.n_elements) {

        tp_err.errpathGCS = pathGCS;
        tp_err.errstring = "tp: Not all vectors in pathGCS have the same size or differ from n_elements";
        tp_err.errcode = 2;

        /* Increase number of errors of error code 2 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }

    // Check if send_tai_seconds or send_tai_nanoseconds is infinite, NaN or negative
    if ((!std::isfinite(static_cast<double>(pathGCS.send_tai_seconds))) || (!std::isfinite(static_cast<double>(pathGCS.send_tai_nanoseconds))) || pathGCS.send_tai_seconds < 0 || pathGCS.send_tai_nanoseconds < 0) {

        tp_err.errpathGCS = pathGCS;
        tp_err.errstring = "tp: send_tai_seconds or send_tai_nanoseconds of pathGCS is NaN, infinite or negative";
        tp_err.errcode = 2;

        /* Increase number of errors of error code 0 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;

    }

    // Check if tai_seconds or tai_nanoseconds is infinite, NaN or negative
    if ((!std::isfinite(static_cast<double>(pathGCS.tai_seconds))) || (!std::isfinite(static_cast<double>(pathGCS.tai_nanoseconds))) || pathGCS.tai_seconds < 0 || pathGCS.tai_nanoseconds < 0) {

        tp_err.errpathGCS = pathGCS;
        tp_err.errstring = "tp: tai_seconds or tai_nanoseconds of pathGCS is NaN, infinite or negative";
        tp_err.errcode = 2;

        /* Increase number of errors of error code 0 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;

    }

    // Check if n_elements is infinite, NaN or negative
    if ((!std::isfinite(static_cast<double>(pathGCS.n_elements)))) {

        tp_err.errpathGCS = pathGCS;
        tp_err.errstring = "tp: n_elements of pathGCS is NaN or infinite";
        tp_err.errcode = 2;

        /* Increase number of errors of error code 0 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;

    }

    // Check if at least one element of the lat is infinite, NaN, greater than absolute of pi/2 (northpole or southpole)
    for (auto it = pathGCS.pos_ell_lat_rad.begin(); it != pathGCS.pos_ell_lat_rad.end(); ++it) {

        if ((!std::isfinite(*it)) || *it > 1.5708 || *it < -1.5708) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS pos_ell_lat_rad is NaN, infinite, greater than absolute of pi/2 (northpole or southpole)";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the lon is infinite, NaN, greater than absolute of pi (only 180° to West and East allowed)
    for (auto it = pathGCS.pos_ell_lon_rad.begin(); it != pathGCS.pos_ell_lon_rad.end(); ++it) {

        if ((!std::isfinite(*it)) || *it > 3.1415 || *it < - 3.1415) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS pos_ell_lon_rad is NaN, infinite, greater than absolute of pi (only 180° to West and East allowed)";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the h is infinite, NaN or negative
    for (auto it = pathGCS.pos_ell_h_m.begin(); it != pathGCS.pos_ell_h_m.end(); ++it) {

        if ((!std::isfinite(*it)) || *it < 0) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS pos_ell_h_m is NaN, infinite or negative";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }
    // Check if at least one element of the slope_long is infinite or NaN
    for (auto it = pathGCS.slope_long.begin(); it != pathGCS.slope_long.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS slope_long is NaN or infinite";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the slope_lat is infinite or NaN
    for (auto it = pathGCS.slope_lat.begin(); it != pathGCS.slope_lat.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS slope_lat is NaN or infinite";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the planning position is 0
    if ((std::abs(pathGCS.pos_ell_lat_rad.at(0)) < 0.1 &&
         std::abs(pathGCS.pos_ell_lon_rad.at(0)) < 0.1) ||
        std::abs(pathGCS.pos_ell_h_m.at(0)) < 0.1) {

        tp_err.errpathGCS = pathGCS;
        tp_err.errstring = "tp: At least one element of the pathGCS planning pose (lat, lon, h) is (almost) 0";
        tp_err.errcode = 2;

        /* Increase number of errors of error code 2 to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }

    // Check if at least one element of vel_enu_mag_m_s is negative, infinite or NaN
    for (auto it = pathGCS.pos_arc_vel_m_s.begin(); it != pathGCS.pos_arc_vel_m_s.end(); ++it) {

        if ((!std::isfinite(*it)) || *it < 0) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS pos_arc_vel_m_s is negative, infinite or NaN";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of ori_enu_psi_rad is infinite or NaN
    for (auto it = pathGCS.ori_enu_psi_rad.begin(); it != pathGCS.ori_enu_psi_rad.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS ori_enu_psi_rad is infinite or NaN";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of dir_ind is infinite or NaN
    for (auto it = pathGCS.dir_ind.begin(); it != pathGCS.dir_ind.end(); ++it) {

        if ((!std::isfinite(static_cast<double>(*it)))) {

            tp_err.errpathGCS = pathGCS;
            tp_err.errstring = "tp: At least one element of pathGCS dir_ind is infinite or NaN";
            tp_err.errcode = 2;

            /* Increase number of errors of error code 2 to pathstatus */
            {
                std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
                tpinterface::glob_pathstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    return return_value;

}

bool tpcore::check_trajGCS(trajGCS &trajGCS, tp_err &tp_err) {

    bool return_value = true;

    // Check for equal size of all trajGCS vectors
    if (trajGCS.tai_seconds.size() != trajGCS.tai_nanoseconds.size() ||
        trajGCS.tai_nanoseconds.size() != trajGCS.standstill.size() ||
        trajGCS.standstill.size() != trajGCS.parking.size() ||
        trajGCS.parking.size() != trajGCS.pos_ell_lat_rad.size() ||
        trajGCS.pos_ell_lat_rad.size() != trajGCS.pos_ell_lon_rad.size() ||
        trajGCS.pos_ell_lon_rad.size() != trajGCS.pos_ell_h_m.size() ||
        trajGCS.pos_ell_h_m.size() != trajGCS.slope_long.size() ||
        trajGCS.slope_long.size() != trajGCS.slope_lat.size() ||
        trajGCS.slope_lat.size() != trajGCS.vel_enu_mag_m_s.size() ||
        trajGCS.vel_enu_mag_m_s.size() != trajGCS.vel_enu_angle_rad.size() ||
        trajGCS.vel_enu_angle_rad.size() != trajGCS.acc_enu_mag_m_s2.size() ||
        trajGCS.acc_enu_mag_m_s2.size() != trajGCS.acc_enu_angle_rad.size() ||
        trajGCS.acc_enu_angle_rad.size() != trajGCS.ori_enu_psi_rad.size() ||
        trajGCS.ori_enu_psi_rad.size() != trajGCS.ori_vel_enu_psi_rad_s.size() ||
        trajGCS.ori_vel_enu_psi_rad_s.size() != trajGCS.ori_acc_enu_psi_rad_s2.size()) {

        tp_err.errtrajGCS = trajGCS;
        tp_err.errstring = "tp: Not all vectors in trajGCS have the same size";
        tp_err.errcode = 0;

        /* Increase number of errors of error code 0 to trajstatus */
        {
            std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
            tpinterface::glob_trajstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }

    // Check if send_tai_seconds or send_tai_nanoseconds is infinite, NaN or negative
        if ((!std::isfinite(static_cast<double>(trajGCS.send_tai_seconds))) || (!std::isfinite(static_cast<double>(trajGCS.send_tai_nanoseconds))) || trajGCS.send_tai_seconds < 0 || trajGCS.send_tai_nanoseconds < 0) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: send_tai_seconds or send_tai_nanoseconds of trajGCS is NaN, infinite or negative";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    // Check if at least one element of the tai_seconds is infinite, NaN, or negative
    for (auto it = trajGCS.tai_seconds.begin(); it != trajGCS.tai_seconds.end(); ++it) {

        if ((!std::isfinite(static_cast<double>(*it))) || *it < 0) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS tai_seconds is NaN, infinite or negative";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the tai_nanoseconds is infinite, NaN, or negative
    for (auto it = trajGCS.tai_nanoseconds.begin(); it != trajGCS.tai_nanoseconds.end(); ++it) {

        if ((!std::isfinite(static_cast<double>(*it))) ||  *it < 0) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS tai_nanoseconds is NaN, infinite or negative";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the standstill is infinite, NaN, negative or greater 1
    for (auto it = trajGCS.standstill.begin(); it != trajGCS.standstill.end(); ++it) {

        if ((!std::isfinite(static_cast<double>(*it))) || *it < 0 || *it > 1) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS standstill is NaN, infinite, negative or greater 1";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the parking is infinite, NaN, negative or greater 1
    for (auto it = trajGCS.parking.begin(); it != trajGCS.parking.end(); ++it) {

        if ((!std::isfinite(static_cast<double>(*it))) || *it < 0 || *it > 1) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS parking is NaN, infinite, negative or greater 1";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the lat is infinite, NaN, greater than absolute of pi/2 (northpole or southpole)
    for (auto it = trajGCS.pos_ell_lat_rad.begin(); it != trajGCS.pos_ell_lat_rad.end(); ++it) {

        if ((!std::isfinite(*it)) || *it > 1.5708 || *it < -1.5708) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS pos_ell_lat_rad is NaN, infinite, greater than absolute of pi/2 (northpole or southpole)";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the lon is infinite, NaN, greater than absolute of pi (only 180° to West and East allowed)
    for (auto it = trajGCS.pos_ell_lon_rad.begin(); it != trajGCS.pos_ell_lon_rad.end(); ++it) {

        if ((!std::isfinite(*it)) || *it > 3.1415 || *it < - 3.1415) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS pos_ell_lon_rad is NaN, infinite, greater than absolute of pi (only 180° to West and East allowed)";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the h is infinite, NaN or negative
    for (auto it = trajGCS.pos_ell_h_m.begin(); it != trajGCS.pos_ell_h_m.end(); ++it) {

        if ((!std::isfinite(*it)) || *it < 0) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS pos_ell_h_m is NaN, infinite or negative";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the slope_long is infinite or NaN
    for (auto it = trajGCS.slope_long.begin(); it != trajGCS.slope_long.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS slope_long is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the slope_lat is infinite or NaN
    for (auto it = trajGCS.slope_lat.begin(); it != trajGCS.slope_lat.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS slope_lat is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the vel_enu_mag_m_s is infinite or NaN
    for (auto it = trajGCS.vel_enu_mag_m_s.begin(); it != trajGCS.vel_enu_mag_m_s.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS vel_enu_mag_m_s is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the vel_enu_angle_rad is infinite or NaN
    for (auto it = trajGCS.vel_enu_angle_rad.begin(); it != trajGCS.vel_enu_angle_rad.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS vel_enu_angle_rad is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the acc_enu_mag_m_s2 is infinite or NaN
    for (auto it = trajGCS.acc_enu_mag_m_s2.begin(); it != trajGCS.acc_enu_mag_m_s2.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS acc_enu_mag_m_s2 is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the acc_enu_angle_rad is infinite or NaN
    for (auto it = trajGCS.acc_enu_angle_rad.begin(); it != trajGCS.acc_enu_angle_rad.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS acc_enu_angle_rad is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the ori_enu_psi_rad is infinite or NaN
    for (auto it = trajGCS.ori_enu_psi_rad.begin(); it != trajGCS.ori_enu_psi_rad.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS ori_enu_psi_rad is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the ori_vel_enu_psi_rad_s is infinite or NaN
    for (auto it = trajGCS.ori_vel_enu_psi_rad_s.begin(); it != trajGCS.ori_vel_enu_psi_rad_s.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS ori_vel_enu_psi_rad_s is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if at least one element of the ori_acc_enu_psi_rad_s2 is infinite or NaN
    for (auto it = trajGCS.ori_acc_enu_psi_rad_s2.begin(); it != trajGCS.ori_acc_enu_psi_rad_s2.end(); ++it) {

        if ((!std::isfinite(*it))) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS ori_acc_enu_psi_rad_s2 is NaN or infinite";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    // Check if lat and lon or the height of the planning position is 0
    if ((std::abs(trajGCS.pos_ell_lat_rad.at(0)) < 0.1 &&
         std::abs(trajGCS.pos_ell_lon_rad.at(0)) < 0.1) ||
        std::abs(trajGCS.pos_ell_h_m.at(0)) < 0.1) {

        tp_err.errtrajGCS = trajGCS;
        tp_err.errstring = "tp: At least one element of the trajGCS planning pose (lat, lon, h) is 0";
        tp_err.errcode = 0;

        /* Increase number of errors of error code 0 to trajstatus */
        {
            std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
            tpinterface::glob_trajstatus.no_errcode[0] += 1;
        }

        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        return_value = false;

        return return_value;
    }

    // Check if at least on element of vel_enu_mag_m_s is negative
    for (auto it = trajGCS.vel_enu_mag_m_s.begin(); it != trajGCS.vel_enu_mag_m_s.end(); ++it) {

        if (*it < 0) {

            tp_err.errtrajGCS = trajGCS;
            tp_err.errstring = "tp: At least one element of trajGCS vel_enu_mag_m_s is negative";
            tp_err.errcode = 0;

            /* Increase number of errors of error code 0 to trajstatus */
            {
                std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
                tpinterface::glob_trajstatus.no_errcode[0] += 1;
            }

            taitime taitime;
            tpinterface::read_taitime(taitime);

            tp_err.send_tai = taitime;

            return_value = false;

            return return_value;

        }

    }

    return return_value;

}

void tpcore::func_path(param_path &param_path, pathGCS &pathGCS) {

    rx_pathGCS(pathGCS);

    //Start timer for runtime measurement
    auto start_func_path = std::chrono::steady_clock::now();

    // Check if exit of the thread is triggered
    if (tpinterface::exitCondition) {
        return;
    }

    tp_err tp_err{0};

    try {

        if (!check_pathGCS(pathGCS, tp_err)) {

            tx_tp_err(tp_err);

            if (tpparam::errmsg == 1) {

                std::stringstream ss;
                ss << tp_err.errstring.c_str() << "\n";
                std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
                std::cerr << ss.str();

            }
#ifdef CMAP243
            LogErrStr(EC_Sim, tp_err.errstring.c_str());
            this->tpexit();
#endif

            return;
        }

        /* Write global send time of valid pathGCS to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.pathGCS_valid_time_seconds = pathGCS.send_tai_seconds;
            tpinterface::glob_pathstatus.pathGCS_valid_time_nanoseconds = pathGCS.send_tai_nanoseconds;
        }

        /* Create new temporary tmp_pathENU and copy unmodified data from pathGCS in pathENU */
        pathENU tmp_pathENU{};

        tmp_pathENU.plan_tai_seconds = pathGCS.tai_seconds;
        tmp_pathENU.plan_tai_nanoseconds = pathGCS.tai_nanoseconds;
        tmp_pathENU.n_elements = static_cast<uint16_t>(pathGCS.n_elements - 1);
        tmp_pathENU.plan_pos_ell_lat_rad = pathGCS.pos_ell_lat_rad.at(0);
        tmp_pathENU.plan_pos_ell_lon_rad = pathGCS.pos_ell_lon_rad.at(0);
        tmp_pathENU.plan_pos_ell_h_m = pathGCS.pos_ell_h_m.at(0);
        tmp_pathENU.plan_ori_enu_psi_rad = pathGCS.ori_enu_psi_rad.at(0);

        tmp_pathENU.use_previous_trj = static_cast<uint16_t>(pathGCS.use_previous_trj);
        tmp_pathENU.use_atlatec = static_cast<uint16_t>(pathGCS.use_atlatec);

        // Reserve vectors
        tmp_pathENU.slope_long.reserve(pathGCS.pos_ell_lat_rad.size() - 1);
        tmp_pathENU.slope_lat.reserve(pathGCS.pos_ell_lat_rad.size() - 1);
        tmp_pathENU.pos_arc_vel_m_s.reserve(pathGCS.pos_ell_lat_rad.size() - 1);
        tmp_pathENU.dir_ind.reserve(pathGCS.pos_ell_lat_rad.size() - 1);
        tmp_pathENU.ori_enu_psi_rad.reserve(pathGCS.pos_ell_lat_rad.size() - 1);

        // Fill vectors
        tmp_pathENU.slope_long.insert(tmp_pathENU.slope_long.begin(), pathGCS.slope_long.begin() + 1,
                                      pathGCS.slope_long.end());
        tmp_pathENU.slope_lat.insert(tmp_pathENU.slope_lat.begin(), pathGCS.slope_lat.begin() + 1,
                                     pathGCS.slope_lat.end());
        tmp_pathENU.pos_arc_vel_m_s.insert(tmp_pathENU.pos_arc_vel_m_s.begin(), pathGCS.pos_arc_vel_m_s.begin() + 1,
                                           pathGCS.pos_arc_vel_m_s.end());
        tmp_pathENU.dir_ind.insert(tmp_pathENU.dir_ind.begin(), pathGCS.dir_ind.begin() + 1, pathGCS.dir_ind.end());
        tmp_pathENU.ori_enu_psi_rad.insert(tmp_pathENU.ori_enu_psi_rad.begin(), pathGCS.ori_enu_psi_rad.begin() + 1,
                                           pathGCS.ori_enu_psi_rad.end());

        // Temporary struct for pos_ell_deg of the path
        tmp_pos_ell_deg_path tmp_pos_ell_deg_path{};

        // Convert radian to degree
        radtodeg_path(pathGCS, tmp_pos_ell_deg_path);

        // Rotate the local elements into the plane at the ellipsoid in the receptor point
        posell2enu_path(pathGCS, tmp_pathENU, tmp_pos_ell_deg_path, param_path);

        tp_err = {0};

        if (!check_pathENU(pathGCS, tmp_pathENU, tp_err)) {

            tx_tp_err(tp_err);

            if (tpparam::errmsg == 1) {

                std::stringstream ss;
                ss << tp_err.errstring.c_str() << "\n";
                std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
                std::cerr << ss.str();

            }
#ifdef CMAP243
            LogErrStr(EC_Sim, tp_err.errstring.c_str());
            this->tpexit();
#endif

            return;
        }

        /* Set current send TAI time */
        // Read current TAI-Time
        taitime taitime;
        tpinterface::read_taitime(taitime);

        // Add current TAI_Time to tmp_interp_shpath
        tmp_pathENU.send_tai_seconds = taitime.tai_seconds;
        tmp_pathENU.send_tai_nanoseconds = taitime.tai_nanoseconds;

        // Write pre-processed emergency path into ASOA
        tx_pathENU(tmp_pathENU);


        // Stop timer of runtime measurement and display the runtime on the console
        auto stop_func_path = std::chrono::steady_clock::now();
        auto diff_func_path = std::chrono::duration_cast<std::chrono::microseconds>(
                stop_func_path - start_func_path);

                /* Write global send time of valid pathENU and function runtime to pathstatus */
        {
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus.pathENU_valid_time_seconds = tmp_pathENU.send_tai_seconds;
            tpinterface::glob_pathstatus.pathENU_valid_time_nanoseconds = tmp_pathENU.send_tai_nanoseconds;
            tpinterface::glob_pathstatus.path_runtime_seconds = diff_func_path.count() / 1e6;
        }
        if (tpparam::runtime == 1) {

            std::stringstream ss;
            ss << "tp: Emergency path preprocessing runtime in microseconds: " << diff_func_path.count()
               << "\n";
            std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
            std::cout << ss.str();

        }

    }
    catch (std::exception &e) {

        tp_err.errpathGCS = pathGCS;
        tp_err.errcode = 2;
        tp_err.execstring = e.what();
        tp_err.errstring = "tp: Exception in func_path";
        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        tx_tp_err(tp_err);

    }

}

void tpcore::func_traj(param_traj &param_traj, trajGCS &trajGCS) {

    rx_trajGCS(trajGCS);

    //Start timer for runtime measurement
    auto start_func_traj = std::chrono::steady_clock::now();

    // Check if exit of the thread is triggered
    if (tpinterface::exitCondition) {
        return;
    }

    tp_err tp_err{0};

    try {

        if (!check_trajGCS(trajGCS, tp_err)) {

            tx_tp_err(tp_err);

            if (tpparam::errmsg == 1) {

                std::stringstream ss;
                ss << tp_err.errstring.c_str() << "\n";
                std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
                std::cerr << ss.str();

            }
#ifdef CMAP243
            LogErrStr(EC_Sim, tp_err.errstring.c_str());
            this->tpexit();
#endif
            return;
        }

        /* Write global send time of valid trajGCS to trajstatus */
        {
            std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
            tpinterface::glob_trajstatus.trajGCS_valid_time_seconds = trajGCS.send_tai_seconds;
            tpinterface::glob_trajstatus.trajGCS_valid_time_nanoseconds = trajGCS.send_tai_nanoseconds;
        }

        /* Create new temporary tmp_trajENU and copy unmodified data from trajGCS in trajENU */
        trajENU tmp_trajENU{};

        // Copy planning pose
        tmp_trajENU.plan_pos_ell_lat_rad = trajGCS.pos_ell_lat_rad.at(0);
        tmp_trajENU.plan_pos_ell_lon_rad = trajGCS.pos_ell_lon_rad.at(0);
        tmp_trajENU.plan_pos_ell_h_m = trajGCS.pos_ell_h_m.at(0);
        tmp_trajENU.plan_ori_enu_psi_rad = trajGCS.ori_enu_psi_rad.at(0);
        tmp_trajENU.plan_tai_seconds = trajGCS.tai_seconds.at(0);
        tmp_trajENU.plan_tai_nanoseconds = trajGCS.tai_nanoseconds.at(0);

        /* Copy flags */
        tmp_trajENU.use_previous_trj = static_cast<uint16_t>(trajGCS.use_previous_trj);
        tmp_trajENU.use_atlatec = static_cast<uint16_t>(trajGCS.use_atlatec);

        //Reserve vectors
        tmp_trajENU.tai_seconds.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.tai_nanoseconds.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.standstill.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.parking.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.slope_long.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.slope_lat.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.vel_enu_mag_m_s.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.vel_enu_angle_rad.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.acc_enu_mag_m_s2.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.acc_enu_angle_rad.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.ori_vel_enu_psi_rad_s.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.ori_acc_enu_psi_rad_s2.reserve(trajGCS.pos_ell_lat_rad.size() - 1);
        tmp_trajENU.ori_enu_psi_rad.reserve(trajGCS.pos_ell_lat_rad.size() - 1);

        // Fill vectors
        tmp_trajENU.tai_seconds.insert(tmp_trajENU.tai_seconds.begin(), trajGCS.tai_seconds.begin() + 1,
                                       trajGCS.tai_seconds.end());
        tmp_trajENU.tai_nanoseconds.insert(tmp_trajENU.tai_nanoseconds.begin(), trajGCS.tai_nanoseconds.begin() + 1,
                                           trajGCS.tai_nanoseconds.end());
        tmp_trajENU.standstill.insert(tmp_trajENU.standstill.begin(), trajGCS.standstill.begin() + 1,
                                      trajGCS.standstill.end());
        tmp_trajENU.parking.insert(tmp_trajENU.parking.begin(), trajGCS.parking.begin() + 1, trajGCS.parking.end());
        tmp_trajENU.slope_long.insert(tmp_trajENU.slope_long.begin(), trajGCS.slope_long.begin() + 1,
                                      trajGCS.slope_long.end());
        tmp_trajENU.slope_lat.insert(tmp_trajENU.slope_lat.begin(), trajGCS.slope_lat.begin() + 1,
                                     trajGCS.slope_lat.end());
        tmp_trajENU.vel_enu_mag_m_s.insert(tmp_trajENU.vel_enu_mag_m_s.begin(), trajGCS.vel_enu_mag_m_s.begin() + 1,
                                           trajGCS.vel_enu_mag_m_s.end());
        tmp_trajENU.vel_enu_angle_rad.insert(tmp_trajENU.vel_enu_angle_rad.begin(),
                                             trajGCS.vel_enu_angle_rad.begin() + 1,
                                             trajGCS.vel_enu_angle_rad.end());
        tmp_trajENU.acc_enu_mag_m_s2.insert(tmp_trajENU.acc_enu_mag_m_s2.begin(),
                                            trajGCS.acc_enu_mag_m_s2.begin() + 1, trajGCS.acc_enu_mag_m_s2.end());
        tmp_trajENU.acc_enu_angle_rad.insert(tmp_trajENU.acc_enu_angle_rad.begin(),
                                             trajGCS.acc_enu_angle_rad.begin() + 1,
                                             trajGCS.acc_enu_angle_rad.end());
        tmp_trajENU.ori_vel_enu_psi_rad_s.insert(tmp_trajENU.ori_vel_enu_psi_rad_s.begin(),
                                                 trajGCS.ori_vel_enu_psi_rad_s.begin() + 1,
                                                 trajGCS.ori_vel_enu_psi_rad_s.end());
        tmp_trajENU.ori_acc_enu_psi_rad_s2.insert(tmp_trajENU.ori_acc_enu_psi_rad_s2.begin(),
                                                  trajGCS.ori_acc_enu_psi_rad_s2.begin() + 1,
                                                  trajGCS.ori_acc_enu_psi_rad_s2.end());
        tmp_trajENU.ori_enu_psi_rad.insert(tmp_trajENU.ori_enu_psi_rad.begin(), trajGCS.ori_enu_psi_rad.begin() + 1,
                                           trajGCS.ori_enu_psi_rad.end());

        // Temporary struct for pos_ell_deg of the trajectory
        tmp_pos_ell_deg_traj tmp_pos_ell_deg_traj{};

        // Convert radian to degree
        radtodeg_traj(trajGCS, tmp_pos_ell_deg_traj);

        // Rotate the local elements into the plane at the ellipsoid in the receptor point
        posell2enu_traj(trajGCS, tmp_trajENU, tmp_pos_ell_deg_traj, param_traj);

        tp_err = {0};

        if (!check_trajENU(trajGCS, tmp_trajENU, tp_err)) {

            tx_tp_err(tp_err);

            if (tpparam::errmsg == 1) {

                std::stringstream ss;
                ss << tp_err.errstring.c_str() << "\n";
                std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
                std::cerr << ss.str();

            }
#ifdef CMAP243
            LogErrStr(EC_Sim, tp_err.errstring.c_str());
            this->tpexit();
#endif
            return;
        }

        /* Set current send TAI time */
        // Read current TAI-Time
        taitime taitime;
        tpinterface::read_taitime(taitime);

        // Add current TAI_Time to tmp_interp_shpath
        tmp_trajENU.send_tai_seconds = taitime.tai_seconds;
        tmp_trajENU.send_tai_nanoseconds = taitime.tai_nanoseconds;

        // Write pre-processed reference trajectory into ASOA
        tx_trajENU(tmp_trajENU);

        // Stop timer of runtime measurement and display the runtime on the console
        auto stop_func_traj = std::chrono::steady_clock::now();
        auto diff_func_traj = std::chrono::duration_cast<std::chrono::microseconds>(
                stop_func_traj - start_func_traj);

        /* Write global send time of valid trajENU and function runtime to trajstatus */
        {
            std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
            tpinterface::glob_trajstatus.trajENU_valid_time_seconds = tmp_trajENU.send_tai_seconds;
            tpinterface::glob_trajstatus.trajENU_valid_time_nanoseconds = tmp_trajENU.send_tai_nanoseconds;
            tpinterface::glob_trajstatus.traj_runtime_seconds = diff_func_traj.count() / 1e6;
        }

        if (tpparam::runtime == 1) {

            std::stringstream ss;
            ss << "tp: Reference trajectory preprocessing runtime in microseconds: " << diff_func_traj.count()
               << "\n";
            std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
            std::cout << ss.str();

        }

    }

    catch (std::exception &e) {

        tp_err.errtrajGCS = trajGCS;
        tp_err.errcode = 0;
        tp_err.execstring = e.what();
        tp_err.errstring = "tp: Exception in func_traj";
        taitime taitime;
        tpinterface::read_taitime(taitime);

        tp_err.send_tai = taitime;

        tx_tp_err(tp_err);

    }

}

GeographicLib::Geocentric tpcore::initgrs80ell() {

    const GeographicLib::NormalGravity &earth_grs80 = GeographicLib::NormalGravity::GRS80();

    const GeographicLib::Geocentric ellipsoid_grs80(earth_grs80.EquatorialRadius(), earth_grs80.Flattening());

    return ellipsoid_grs80;

}

void tpcore::init_path(param_path &param_path) {

    param_path.grs80ell = initgrs80ell();

}

void tpcore::init_traj(param_traj &param_traj) {

    param_traj.grs80ell = initgrs80ell();

}

void tpcore::task_path() {

    param_path param_path{};

    init_path(param_path);

    pathGCS pathGCS{0};

    while (!tpinterface::exitCondition) {

        func_path(param_path, pathGCS);

    }

}

void tpcore::task_traj() {

    param_traj param_traj{};

    init_traj(param_traj);

    trajGCS trajGCS{0};

    while (!tpinterface::exitCondition) {

        func_traj(param_traj, trajGCS);

    }

}

/*************************************************************************
* thread_tpstatus
*************************************************************************/

void tpcore::calc_pathstatus(pathstatus &pathstatus, tpstatus &tpstatus) {

    taitime taitime;
    tpinterface::read_taitime(taitime);

    double difftime_pathGCS = ((taitime.tai_seconds - pathstatus.pathGCS_valid_time_seconds) * 1e9 + ((double)taitime.tai_nanoseconds - (double)pathstatus.pathGCS_valid_time_nanoseconds)) / 1e9;
    double difftime_pathENU = ((taitime.tai_seconds - pathstatus.pathENU_valid_time_seconds) * 1e9 + ((double)taitime.tai_nanoseconds - (double)pathstatus.pathENU_valid_time_nanoseconds)) / 1e9;


    /* Calculate status of input */
    if (pathstatus.pathGCS_valid_time_seconds == 0 && pathstatus.pathGCS_valid_time_nanoseconds == 0){

        tpstatus.input[1] = 0;

    }
    else if (difftime_pathGCS <= 0.11){

        tpstatus.input[1] = 1;

    }
    else if (difftime_pathGCS < 0.21){

        tpstatus.input[1] = 2;

    }
    else if (difftime_pathGCS < 0.41){

        tpstatus.input[1] = 3;

    }
    else if (difftime_pathGCS < 0.71){

        tpstatus.input[1] = 4;

    }
    else if (difftime_pathGCS < 1.11){

        tpstatus.input[1] = 5;

    }
    else{

        tpstatus.input[1] = 6;

    }

    /* Calculate status of output */
    if (pathstatus.pathENU_valid_time_seconds == 0 && pathstatus.pathENU_valid_time_nanoseconds == 0){

        tpstatus.output[1] = 0;

    }
    else if (difftime_pathENU <= 0.11){

        tpstatus.output[1] = 1;

    }
    else if (difftime_pathENU < 0.21){

        tpstatus.output[1] = 2;

    }
    else if (difftime_pathENU < 0.41){

        tpstatus.output[1] = 3;

    }
    else if (difftime_pathENU < 0.71){

        tpstatus.output[1] = 4;

    }
    else if (difftime_pathENU < 1.11){

        tpstatus.output[1] = 5;

    }
    else{

        tpstatus.output[1] = 6;

    }

    /* Calculate status of transmission time */
    if (pathstatus.pathGCS_valid_time_seconds == 0 && pathstatus.pathGCS_valid_time_nanoseconds == 0){

        tpstatus.transm_t[1] = 0;

    }
    else if (pathstatus.pathGCS_transm_time_seconds <= 0.011){

        tpstatus.transm_t[1] = 1;

    }
    else if (pathstatus.pathGCS_transm_time_seconds < 0.05){

        tpstatus.transm_t[1] = 2;

    }
    else if (pathstatus.pathGCS_transm_time_seconds < 0.1){

        tpstatus.transm_t[1] = 3;

    }
    else if (pathstatus.pathGCS_transm_time_seconds < 0.5){

        tpstatus.transm_t[1] = 4;

    }
    else if (pathstatus.pathGCS_transm_time_seconds < 1){

        tpstatus.transm_t[1] = 5;

    }
    else{

        tpstatus.transm_t[1] = 6;

    }

    /* Calculate status of runtime */
    if (pathstatus.pathGCS_valid_time_seconds == 0 && pathstatus.pathGCS_valid_time_nanoseconds == 0){

        tpstatus.runtime[1] = 0;

    }
    else if (pathstatus.path_runtime_seconds <= 0.0005){

        tpstatus.runtime[1] = 1;

    }
    else if (pathstatus.path_runtime_seconds < 0.001){

        tpstatus.runtime[1] = 2;

    }
    else if (pathstatus.path_runtime_seconds < 0.01){

        tpstatus.runtime[1] = 3;

    }
    else if (pathstatus.path_runtime_seconds < 0.05){

        tpstatus.runtime[1] = 4;

    }
    else if (pathstatus.path_runtime_seconds < 0.1){

        tpstatus.runtime[1] = 5;

    }
    else{

        tpstatus.runtime[1] = 6;

    }

    /* Calculate status of error codes */
    tpstatus.errcode[2] = pathstatus.no_errcode[0];
    tpstatus.errcode[3] = pathstatus.no_errcode[1];

}

bool tpcore::check_pathstatus(pathstatus &pathstatus, tp_err &tp_err) {

    bool return_value = true;

    return return_value;

    //todo: Füllen

    // Check for equal size of all tmp_pathENU vectors
//    if (tmp_pathENU.pos_arc_vel_m_s.size() != tmp_pathENU.pos_enu_north_m.size() ||
//        tmp_pathENU.pos_enu_north_m.size() != tmp_pathENU.pos_enu_east_m.size() ||
//        tmp_pathENU.pos_enu_east_m.size() != tmp_pathENU.n_elements) {
//
//        tp_err.errpathENU = tmp_pathENU;
//        tp_err.errpathGCS = pathGCS;
//        tp_err.errstring = "tp: Not all vectors in pathENU have the same size or don't match n_elements";
//        tp_err.errcode = 3;
//
//        taitime taitime;
//        tpinterface::read_taitime(taitime);
//
//        tp_err.send_tai = taitime;
//
//        return_value = false;
//
//        return return_value;
//    }

}

void tpcore::calc_trajstatus(trajstatus &trajstatus, tpstatus &tpstatus){

        taitime taitime;
        tpinterface::read_taitime(taitime);

        double difftime_trajGCS = ((taitime.tai_seconds - trajstatus.trajGCS_valid_time_seconds) * 1e9 + ((double)taitime.tai_nanoseconds - (double)trajstatus.trajGCS_valid_time_nanoseconds)) / 1e9;
        double difftime_trajENU = ((taitime.tai_seconds - trajstatus.trajENU_valid_time_seconds) * 1e9 + ((double)taitime.tai_nanoseconds - (double)trajstatus.trajENU_valid_time_nanoseconds)) / 1e9;

    /* Calculate status of input */
    if (trajstatus.trajGCS_valid_time_seconds == 0 && trajstatus.trajGCS_valid_time_nanoseconds == 0){

        tpstatus.input[0] = 0;

    }
    else if (difftime_trajGCS <= 0.11){

        tpstatus.input[0] = 1;

    }
    else if (difftime_trajGCS < 0.21){

        tpstatus.input[0] = 2;

    }
    else if (difftime_trajGCS < 0.41){

        tpstatus.input[0] = 3;

    }
    else if (difftime_trajGCS < 0.71){

        tpstatus.input[0] = 4;

    }
    else if (difftime_trajGCS < 1.11){

        tpstatus.input[0] = 5;

    }
    else{

        tpstatus.input[0] = 6;

    }

    /* Calculate status of output */
    if (trajstatus.trajENU_valid_time_seconds == 0 && trajstatus.trajENU_valid_time_nanoseconds == 0){

        tpstatus.output[0] = 0;

    }
    else if (difftime_trajENU <= 0.11){

        tpstatus.output[0] = 1;

    }
    else if (difftime_trajENU < 0.21){

        tpstatus.output[0] = 2;

    }
    else if (difftime_trajENU < 0.41){

        tpstatus.output[0] = 3;

    }
    else if (difftime_trajENU < 0.71){

        tpstatus.output[0] = 4;

    }
    else if (difftime_trajENU < 1.11){

        tpstatus.output[0] = 5;

    }
    else{

        tpstatus.output[0] = 6;

    }

    /* Calculate status of transmission time */
    if (trajstatus.trajGCS_valid_time_seconds == 0 && trajstatus.trajGCS_valid_time_nanoseconds == 0){

        tpstatus.transm_t[0] = 0;

    }
    else if (trajstatus.trajGCS_transm_time_seconds <= 0.011){

        tpstatus.transm_t[0] = 1;

    }
    else if (trajstatus.trajGCS_transm_time_seconds < 0.05){

        tpstatus.transm_t[0] = 2;

    }
    else if (trajstatus.trajGCS_transm_time_seconds < 0.1){

        tpstatus.transm_t[0] = 3;

    }
    else if (trajstatus.trajGCS_transm_time_seconds < 0.5){

        tpstatus.transm_t[0] = 4;

    }
    else if (trajstatus.trajGCS_transm_time_seconds < 1){

        tpstatus.transm_t[0] = 5;

    }
    else{

        tpstatus.transm_t[0] = 6;

    }

    /* Calculate status of runtime */
    if (trajstatus.trajGCS_valid_time_seconds == 0 && trajstatus.trajGCS_valid_time_nanoseconds == 0){

        tpstatus.runtime[0] = 0;

    }
    else if (trajstatus.traj_runtime_seconds <= 0.0005){

        tpstatus.runtime[0] = 1;

    }
    else if (trajstatus.traj_runtime_seconds < 0.001){

        tpstatus.runtime[0] = 2;

    }
    else if (trajstatus.traj_runtime_seconds < 0.01){

        tpstatus.runtime[0] = 3;

    }
    else if (trajstatus.traj_runtime_seconds < 0.05){

        tpstatus.runtime[0] = 4;

    }
    else if (trajstatus.traj_runtime_seconds < 0.1){

        tpstatus.runtime[0] = 5;

    }
    else{

        tpstatus.runtime[0] = 6;

    }

    /* Calculate status of error codes */
    tpstatus.errcode[0] = trajstatus.no_errcode[0];
    tpstatus.errcode[1] = trajstatus.no_errcode[1];

}

bool tpcore::check_trajstatus(trajstatus &trajstatus, tp_err &tp_err) {

    bool return_value = true;

    return return_value;

    //todo: Füllen

    // Check for equal size of all tmp_pathENU vectors
//    if (tmp_pathENU.pos_arc_vel_m_s.size() != tmp_pathENU.pos_enu_north_m.size() ||
//        tmp_pathENU.pos_enu_north_m.size() != tmp_pathENU.pos_enu_east_m.size() ||
//        tmp_pathENU.pos_enu_east_m.size() != tmp_pathENU.n_elements) {
//
//        tp_err.errpathENU = tmp_pathENU;
//        tp_err.errpathGCS = pathGCS;
//        tp_err.errstring = "tp: Not all vectors in pathENU have the same size or don't match n_elements";
//        tp_err.errcode = 3;
//
//        taitime taitime;
//        tpinterface::read_taitime(taitime);
//
//        tp_err.send_tai = taitime;
//
//        return_value = false;
//
//        return return_value;
//    }



}

void tpcore::func_tpstatus(trajstatus &trajstatus, pathstatus &pathstatus) {

    //Start timer for runtime measurement
    auto start_func_tpstatus = std::chrono::steady_clock::now();

    /* Create new temporary tmp_tpstatus */
    tpstatus tmp_tpstatus{};

    read_trajstatus(trajstatus);

    // Check if exit of the thread is triggered
    if (tpinterface::exitCondition) {
        return;
    }

    tp_err tp_err{0};

    try {

        if (!check_trajstatus(trajstatus, tp_err)) {

            tx_tp_err(tp_err);

            if (tpparam::errmsg == 1) {

                std::stringstream ss;
                ss << tp_err.errstring.c_str() << "\n";
                std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
                std::cerr << ss.str();

            }
#ifdef CMAP243
            LogErrStr(EC_Sim, tp_err.errstring.c_str());
            this->tpexit();
#endif
            return;
        }

        calc_trajstatus(trajstatus, tmp_tpstatus);

        read_pathstatus(pathstatus);


            if (!check_pathstatus(pathstatus, tp_err)) {

                tx_tp_err(tp_err);

                if (tpparam::errmsg == 1) {

                    std::stringstream ss;
                    ss << tp_err.errstring.c_str() << "\n";
                    std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
                    std::cerr << ss.str();

                }
#ifdef CMAP243
            LogErrStr(EC_Sim, tp_err.errstring.c_str());
            this->tpexit();
#endif
                return;
            }

        calc_pathstatus(pathstatus, tmp_tpstatus);

        /* Set current send TAI time */
        // Read current TAI-Time
        taitime taitime;
        tpinterface::read_taitime(taitime);

        // Add current TAI_Time to tmp_interp_shpath
        tmp_tpstatus.send_tai_seconds = taitime.tai_seconds;
        tmp_tpstatus.send_tai_nanoseconds = taitime.tai_nanoseconds;

        // Write pre-processed reference trajectory into ASOA
        tx_tpstatus(tmp_tpstatus);


        // Stop timer of runtime measurement and display the runtime on the console
        auto stop_func_tpstatus = std::chrono::steady_clock::now();
        auto diff_func_tpstatus = std::chrono::duration_cast<std::chrono::microseconds>(
                stop_func_tpstatus - start_func_tpstatus);

        if (tpparam::runtime == 1) {

            std::stringstream ss;
            ss << "tp: tp status processing runtime in microseconds: " << diff_func_tpstatus.count()
               << "\n";
            std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
            std::cout << ss.str();

        }

    }

    catch (std::exception &e) {

        //todo: Füllen
//        tp_err.errtrajGCS = trajGCS;
//        tp_err.errcode = 0;
//        tp_err.execstring = e.what();
//        tp_err.errstring = "tp: Exception in func_traj";
//        taitime taitime;
//        tpinterface::read_taitime(taitime);
//
//        tp_err.send_tai = taitime;
//
//        tx_tp_err(tp_err);

    }

}

void tpcore::task_tpstatus() {

    trajstatus trajstatus{0};
    pathstatus pathstatus{0};

    while (!tpinterface::exitCondition) {

        func_tpstatus(trajstatus, pathstatus);

        std::this_thread::sleep_for(std::chrono::milliseconds (100));

    }

}