/**
 * \file tp_ext_interface.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_EXT_INTERFACE_H
#define TP_EXT_INTERFACE_H

/*************************************************************************
@brief Namespace for tp interface
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
namespace tpinterface {

/*************************************************************************
@brief Threads exit condition
@details Global atomic_flag for thread communication (Threads join if exitCondition is set)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::atomic_bool exitCondition;

/*************************************************************************
@brief Mutex for std::cout
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_cout;

/*************************************************************************
@struct glob_trajGCS
@brief Global variable for trajGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct trajGCS glob_trajGCS;

/*************************************************************************
@brief Mutex for global variable for trajGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_trajGCS;

/*************************************************************************
@brief condition_variable for global variable for trajGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_trajGCS;

/*************************************************************************
@brief Atomic bool for new global variable for trajGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool trajGCS_new;

/*************************************************************************
@struct glob_pathGCS
@brief Global variable for pathGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct pathGCS glob_pathGCS;

/*************************************************************************
@brief Mutex for global variable for pathGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_pathGCS;

/*************************************************************************
@brief condition_variable for global variable for pathGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_pathGCS;

/*************************************************************************
@brief Atomic bool for new global variable for pathGCS
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool pathGCS_new;

/*************************************************************************
@struct glob_trajENU
@brief Global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct trajENU glob_trajENU;

/*************************************************************************
@brief Mutex for global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_trajENU;

/*************************************************************************
@brief condition_variable for global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_trajENU;

/*************************************************************************
@brief Atomic bool for new global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool trajENU_new;

/*************************************************************************
@struct glob_pathENU
@brief Global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct pathENU glob_pathENU;

/*************************************************************************
@brief Mutex for global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_pathENU;

/*************************************************************************
@brief condition_variable for global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_pathENU;

/*************************************************************************
@brief Atomic bool for new global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool pathENU_new;

/*************************************************************************
@struct glob_tp_err
@brief Global variable for tp_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::deque<tp_err> glob_tp_err;

/*************************************************************************
@brief Mutex for global variable for tp_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_tp_err;

/*************************************************************************
@brief condition_variable for global variable for tp_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_tp_err;

/*************************************************************************
@brief Atomic bool for empty global queue for tp_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool tp_err_empty;

/*************************************************************************
@brief This function reads the current TAI_Time
@param[out] taitime Taitime struct for tai_seconds and tai_nanoseconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2020
*************************************************************************/
    void read_taitime(taitime &taitime);

/*************************************************************************
@brief This function reads the TOML configuration file
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.02.2022
*************************************************************************/
    void read_tpparam();

/*************************************************************************
@brief This function sends ext_trajGCS the tp thread_traj
@param[in] ext_trajGCS External trajGCS struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.01.2021
*************************************************************************/
    void tx_trajGCS(trajGCS ext_trajGCS);

/*************************************************************************
@brief This function sends ext_pathGCS the tp thread_path
@param[in] ext_pathGCS External pathGCS struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.01.2021
*************************************************************************/
    void tx_pathGCS(pathGCS ext_pathGCS);

/*************************************************************************
@brief This function receives trajENU from the tp thread_traj
@param[in,out] ext_trajENU External trajENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.01.2021
*************************************************************************/
    void rx_trajENU(trajENU &ext_trajENU);

/*************************************************************************
@brief This function receives pathENU from the tp thread_path
@param[in,out] ext_pathENU External pathENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.01.2021
*************************************************************************/
    void rx_pathENU(pathENU &ext_pathENU);

/*************************************************************************
@brief This function receives tp_err struct from the tp threads
@param[out] ext_tp_err External error std::deque
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    void rx_tp_err(tp_err &ext_tp_err);

/*************************************************************************
@struct glob_trajstatus
@brief Global variable for trajstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern struct trajstatus glob_trajstatus;

/*************************************************************************
@brief Mutex for global variable for trajstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern std::mutex mx_glob_trajstatus;

/*************************************************************************
@struct glob_pathstatus
@brief Global variable for pathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern struct pathstatus glob_pathstatus;

/*************************************************************************
@brief Mutex for global variable for pathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern std::mutex mx_glob_pathstatus;

/*************************************************************************
@struct glob_tpstatus
@brief Global variable for tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern struct tpstatus glob_tpstatus;

/*************************************************************************
@brief Mutex for global variable for tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern std::mutex mx_glob_tpstatus;

/*************************************************************************
@brief condition_variable for global variable for tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    extern std::condition_variable cv_glob_tpstatus;

/*************************************************************************
@brief Atomic bool for new global variable for tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool tpstatus_new;

/*************************************************************************
@brief This function receives tpstatus from the tp thread_tpstatus
@param[in,out] ext_tpstatus External tpstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
    void rx_tpstatus(tpstatus &ext_tpstatus);

}

#endif //TP_EXT_INTERFACE_H
