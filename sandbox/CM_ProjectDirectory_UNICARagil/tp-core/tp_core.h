/**
* \file tp_core.h
* \brief Header for tp_core.cpp
* @author Stefan Ackermann <stefan.ackermann@tu-darmstadt.de>
* @date 10.02.2022
* @version 1
* @copyright MIT License
* @bug No known bugs.
*
* * <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
* - toml11 (https://github.com/ToruNiina/toml11#finding-a-toml-value), ToruNiina (commit:bf2384d, MIT License)
*
* Copyright (c) Stefan Ackermann (2022) <stefan.ackermann@tu-darmstadt.de>
**********************************************************************/

#ifndef TP_CORE_H
#define TP_CORE_H

// Comment/Uncomment flags for application
//#define TP_INTERFACE          //Show messages regarding data transfer with global variables
//#define CMAP243               //Define for CarMaker Simulation

/* Header includes */
#include <vector> //std:vector
#include <deque> //std::deque
#include <thread> //std::thread
#include <mutex> //std::mutex, std::lock_guard
#include <atomic> //std::atomic_bool
#include <condition_variable>   //std::condition_variable
#include <cstring> // std::strcpy
#include <iostream> //std::cout
#include <sstream>   //std::stringstream

// Geographiclib - Coordinate transformation global ellipsoid to local East North Up (ENU)
#include <GeographicLib/NormalGravity.hpp>
#include <GeographicLib/Math.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <GeographicLib/Geocentric.hpp>

/* toml11 (TOML parser) */
#include "lib/src/toml11/toml.hpp"

// UNICARagil Header
#include"../unicar-definitions/UNICAR_definitions.h" //UNICAR definitions
#include "tp_core_err.h" //error struct
#include "tp_core_tmp_pos_ell_deg_path.h"
#include "tp_core_param_path.h"
#include "tp_core_tmp_pos_ell_deg_traj.h"
#include "tp_core_param_traj.h"
#include "tp_core_tpstatus.h"
#include "tp_core_trajstatus.h"
#include "tp_core_pathstatus.h"
#include "tp_ext_interface.h" // External tp interface
#include "tp_param.h"


/* Includes only for IPG CarMaker */
#ifdef CMAP243
#include "CarMaker.h" //for CarMaker
#endif

/*************************************************************************
@class tpcore
@brief Class for tpcore functionality
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
class tpcore {

/*************************************************************************
@brief This function sends tp_err to glob_tp_err
@param[in] tp_err tp_err struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.04.2021
*************************************************************************/
    static void tx_tp_err(const tp_err &tp_err);

/*************************************************************************
@brief This function receives trajGCS from glob_trajGCS
@param[in,out] trajGCS trajGCS struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void rx_trajGCS(trajGCS &trajGCS);

/*************************************************************************
@brief This function sends trajENU from the tp thread_traj
@param[in] tmp_trajENU pathENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    static void tx_trajENU(trajENU tmp_trajENU);

/*************************************************************************
@brief This function receives pathGCS from glob_pathGCS
@param[in,out] pathGCS pathGCS struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void rx_pathGCS(pathGCS &pathGCS);

/*************************************************************************
@brief This function sends tmp_pathENU from the tp thread_path
@param[in] tmp_pathENU pathENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    static void tx_pathENU(pathENU tmp_pathENU);

/*************************************************************************
@brief This function receives trajstatus from glob_trajstatus
@param[in,out] trajstatus trajstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    void read_trajstatus(trajstatus &trajstatus);

/*************************************************************************
@brief This function receives pathstatus from glob_pathstatus
@param[in,out] pathstatus pathstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    void read_pathstatus(pathstatus &pathstatus);

/*************************************************************************
@brief This function sends tmp_tpstatus from the tp thread_tpstatus
@param[in] tmp_tpstatus Temporary tpstatus struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    static void tx_tpstatus(tpstatus tmp_tpstatus);

    /* Common */

/*************************************************************************
@brief This function initializes the GRS80 ellipsoid of the library "GeogprahicLib".
@details Since ETRS89 was chosen as the reference system for the positions and the corresponding reference ellipsoid is GRS80, GeogprahicLib is initialized with GRS80
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 16.04.2020
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static GeographicLib::Geocentric initgrs80ell();


    /* Reference trajectory preprocessing */
/*************************************************************************
@brief Thread traj variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    std::thread thread_traj;

/*************************************************************************
@brief This function represents the the task for the reference trajectory preprocessing
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void task_traj();

/*************************************************************************
@brief This function initializes the parameters for preprocessing the reference trajectory
@details For example the GRS80 ellipsoid
@param[out] param_traj Parameter for reference trajectory preprocessing (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 16.04.2020
*************************************************************************/
    static void init_traj(param_traj &param_traj);

/*************************************************************************
@brief This is the function for preprocessing the reference trajectory.
@details In an infinite loop the reference trajectories in GCS are received, processed and send in ENU
@param[in] param_traj Parameter for reference trajectory preprocessing (e.g. GRS80 ellipsoid parameters)
@param[in] trajGCS Reference path in global ellipsoidal coordinates
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void func_traj(param_traj &param_traj, trajGCS &trajGCS);

/*************************************************************************
@brief This function checks the plausibility and the content of the received trajGCS
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] trajGCS Reference trajectory in global ellipsoidal coordinates
@param[in] tp_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    static bool check_trajGCS(trajGCS &trajGCS, tp_err &tp_err);

/*************************************************************************
@brief Conversion of trajectory positions from radians in degrees
@details This function performs the conversion of the reference trajectory positions from radians to degrees
@param[in] trajGCS Reference trajectory in global ellipsoidal coordinates
@param[out] tmp_pos_ell_deg_traj Temporary struct for the latitudes and longitudes in degrees
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static void radtodeg_traj(trajGCS &trajGCS, tmp_pos_ell_deg_traj &tmp_pos_ell_deg_traj);

/*************************************************************************
@brief Conversion of trajectory GCS to ENU coordinates
@details This function performs the conversion of the reference trajectory positions from global ellipsoidal
coordinates (ETRS89 -> reference ellipsoid GRS80) into a local coordinate system.
Origin of the local coordinate system is the first position of the emergency path.
@param[in] trajGCS Reference trajectory in global ellipsoidal coordinates
@param[out] tmp_trajENU Temporary trajectory in local ENU coordinate system
@param[in] tmp_pos_ell_deg_traj Temporary struct for the latitudes and longitudes in degrees
@param[in] param_traj Parameter for reference trajectory preprocessing (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static void posell2enu_traj(trajGCS &trajGCS, trajENU &tmp_trajENU, tmp_pos_ell_deg_traj &tmp_pos_ell_deg_traj,
                                param_traj &param_traj);

/*************************************************************************
@brief This function checks the plausibility and the content of the generated trajENU.
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] trajGCS Reference trajectory in global ellipsoidal coordinates
@param[in] tmp_trajENU Temporary trajectory in local ENU coordinate system
@param[in] tp_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    static bool check_trajENU(trajGCS &trajGCS, trajENU &tmp_trajENU, tp_err &tp_err);


    /* Emergency path preprocessing */

/*************************************************************************
@brief Thread path variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    std::thread thread_path;

/*************************************************************************
@brief This function represents the the task for the emergency path preprocessing
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*************************************************************************/
    void task_path();

/*************************************************************************
@brief This function initializes the parameters for preprocessing the emergency path
@details For example the GRS80 ellipsoid
@param[out] param_path Parameter for emergency path preprocessing (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 16.04.2020
*************************************************************************/
    static void init_path(param_path &param_path);

/*************************************************************************
@brief This is the function for preprocessing the emergency path.
@details In an infinite loop the emergency paths in GCS are received, processed and send in ENU
@param[in] param_path Parameter for emergency path preprocessing (e.g. GRS80 ellipsoid parameters)
@param[in] pathGCS Emergency path in global ellipsoidal coordinates
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 25.02.2020
*************************************************************************/
    void func_path(param_path &param_path, pathGCS &pathGCS);

/*************************************************************************
@brief This function checks the plausibility and the content of the received pathGCS
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] pathGCS Emergency path in global ellipsoidal coordinates
@param[in] tp_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    static bool check_pathGCS(pathGCS &pathGCS, tp_err &tp_err);

/*************************************************************************
@brief Conversion of path positions from radians in degrees
@details This function performs the conversion of the emergency path positions from radians to degrees
@param[in] pathGCS Emergency path in global ellipsoidal coordinates
@param[out] tmp_pos_ell_deg_path Temporary struct for the latitudes and longitudes in degrees
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 08.12.2020
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static void radtodeg_path(pathGCS &pathGCS, tmp_pos_ell_deg_path &tmp_pos_ell_deg_path);

/*************************************************************************
@brief Conversion of path GCS to ENU coordinates
@details This function performs the conversion of the emergency path positions from global ellipsoidal
coordinates (ETRS89 -> reference ellipsoid GRS80) into a local coordinate system.
Origin of the local coordinate system is the first position of the emergency path.
@param[in] pathGCS Emergency path in global ellipsoidal coordinates
@param[out] tmp_pathENU Emergency Path in local ENU coordinates
@param[in] tmp_pos_ell_deg_path Temporary struct for the latitudes and longitudes in degrees
@param[in] param_path Parameter for emergency path preprocessing (e.g. GRS80 ellipsoid parameters)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*
* <u>Dependencies:</u>
* - GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.51, MIT/X11)
*************************************************************************/
    static void posell2enu_path(pathGCS &pathGCS, pathENU &tmp_pathENU, tmp_pos_ell_deg_path &tmp_pos_ell_deg_path,
                                param_path &param_path);

/*************************************************************************
@brief This function checks the plausibility and the content of the generated pathENU.
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] pathGCS Emergency path in global ellipsoidal coordinates
@param[in] tmp_pathENU Temporary path in local ENU coordinate system
@param[in] tp_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    static bool check_pathENU(pathGCS &pathGCS, pathENU &tmp_pathENU, tp_err &tp_err);

    /* tpstatus processing */

/*************************************************************************
@brief Thread tpstatus variable
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    std::thread thread_tpstatus;

/*************************************************************************
@brief This function represents the the task for the tpstatus processing
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    void task_tpstatus();

/*************************************************************************
@brief This is the function for processing the tpstatus.
@details This function collects the status information of the traj and path threads to calculates the status of the service
@param[in] trajstatus Struct for trajstatus
@param[in] pathstatus Struct for pathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    void func_tpstatus(trajstatus &trajstatus, pathstatus &pathstatus);

/*************************************************************************
@brief This function checks the plausibility and the content of the received trajstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] trajstatus Struct for trajstatus
@param[in] tp_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    static bool check_trajstatus(trajstatus &trajstatus, tp_err &tp_err);

/*************************************************************************
@brief Calculate the status of thread traj
@param[in] trajstatus Struct of trajstatus
@param[out] tpstatus Temporary struct for tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    static void calc_trajstatus(trajstatus &trajstatus, tpstatus &tpstatus);

/*************************************************************************
@brief This function checks the plausibility and the content of the received pathstatus
@details If the check leads to a negative result, it is returned with a boolean false.
@param[in] pathstatus Struct for pathstatus
@param[in] tp_err Error struct
@return Boolean if check is passed (true) oder not (false)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    static bool check_pathstatus(pathstatus &pathstatus, tp_err &tp_err);

/*************************************************************************
@brief Calculate the status of thread path
@param[in] pathstatus Struct of pathstatus
@param[out] tpstatus Temporary struct for tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    static void calc_pathstatus(pathstatus &pathstatus, tpstatus &tpstatus);


public:

/*************************************************************************
@brief This is the constructor of tpcore
@details The constructor calls method tpreset to join all (if already running) threads and starts new tp threads
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    tpcore() {

        tpexit();

    }

/*************************************************************************
@brief This is the destructor of tpcore
@details The destructor calls method tpexit to join all tp threads
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    ~tpcore() {

        tpexit();

    }

/*************************************************************************
@brief This function resets the threads thread_path and thread_traj
@details In the first step the exitCondition is set to true. Then all conditional_variables are notified.
 In the next step each thread is checked if it is joinable. If it is joinable the thread is joined.
 After joining all threads to exitCondition is set to false and the threads are started again
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    void tpreset() {

        tpexit();
        tpstart();

    }

/*************************************************************************
@brief This function stops the threads thread_path and thread_traj
@details In the first step the exitCondition is set to true. Then all conditional_variables are notified. In the next step each thread is checked if it is joinable. If it is joinable the thread is joined.
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    void tpexit() {

        tpinterface::exitCondition = true;
        tpinterface::trajGCS_new = false;
        tpinterface::pathGCS_new = false;
        tpinterface::trajENU_new = false;
        tpinterface::pathENU_new = false;
        tpinterface::tp_err_empty = true;
        tpinterface::tpstatus_new = false;
        tpinterface::cv_glob_trajGCS.notify_one();
        tpinterface::cv_glob_pathGCS.notify_one();
        tpinterface::cv_glob_trajENU.notify_one();
        tpinterface::cv_glob_pathENU.notify_one();
        tpinterface::cv_glob_tp_err.notify_one();
        tpinterface::cv_glob_tpstatus.notify_one();

        /* Join thread_traj */
        if (thread_traj.joinable()) {

            thread_traj.join();

        }

        /* Join thread_path */
        if (thread_path.joinable()) {

            thread_path.join();

        }

        /* Join thread_tpstatus */
        if (thread_tpstatus.joinable()) {

            thread_tpstatus.join();

        }

    }

/*************************************************************************
@brief This function spawns the threads thread_path and thread_traj
@details In the first step all global variables are cleared. Then the exitCondition is set to false and thread_traj and thread_path are started.
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    void tpstart() {

        /* Clear all global variables */

        {
            //Use lock_guard to lock glob_pathGCS
            std::lock_guard<std::mutex> guard_glob_pathGCS{tpinterface::mx_glob_pathGCS};
            tpinterface::glob_pathGCS = {0};
        }

        {
            //Use lock_guard to lock glob_trajGCS
            std::lock_guard<std::mutex> guard_glob_trajGCS{tpinterface::mx_glob_trajGCS};
            tpinterface::glob_trajGCS = {0};
        }

        {
            //Use lock_guard to lock glob_trajENU
            std::lock_guard<std::mutex> guard_glob_trajENU{tpinterface::mx_glob_trajENU};
            tpinterface::glob_trajENU = {0};
        }

        {
            //Use lock_guard to lock glob_trajENU
            std::lock_guard<std::mutex> guard_glob_pathENU{tpinterface::mx_glob_pathENU};
            tpinterface::glob_pathENU = {0};
        }

        {
            //Use lock_guard to lock glob_tp_err
            std::lock_guard<std::mutex> guard_glob_tp_err{tpinterface::mx_glob_tp_err};
            tpinterface::glob_tp_err.clear();
        }

        {
            //Use lock_guard to lock glob_trajstatus
            std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
            tpinterface::glob_trajstatus = {0};
        }

        {
            //Use lock_guard to lock glob_pathstatus
            std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
            tpinterface::glob_pathstatus = {0};
        }

        {
            //Use lock_guard to lock glob_tpstatus
            std::lock_guard<std::mutex> guard_glob_tpstatus{tpinterface::mx_glob_tpstatus};
            tpinterface::glob_tpstatus = {0};
        }

        /* Read psa parameter from csv file */
        tpinterface::read_tpparam();

        /* Start tp threads */
        tpinterface::exitCondition = false;
        tpinterface::trajGCS_new = false;
        tpinterface::pathGCS_new = false;
        tpinterface::trajENU_new = false;
        tpinterface::pathENU_new = false;
        tpinterface::tp_err_empty = true;
        tpinterface::tpstatus_new = false;
        thread_traj = std::thread(&tpcore::task_traj, this);
        thread_path = std::thread(&tpcore::task_path, this);
        thread_tpstatus = std::thread(&tpcore::task_tpstatus, this);

    }

};

#endif //TP_CORE_H