/**
 * \file tp_global.cpp
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/
#include "tp_core.h"

/*************************************************************************
@brief Namespace for tp interface
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
namespace tpinterface {

/* Common */
    std::mutex mx_cout;

/* Thread handling */
    std::atomic_bool exitCondition{};


/* Thread data interface */

/* Global variable glob_trajGCS */

    struct trajGCS glob_trajGCS;
    std::mutex mx_glob_trajGCS;
    std::condition_variable cv_glob_trajGCS;
    std::atomic_bool trajGCS_new;

/* Global variable glob_pathGCS */

    struct pathGCS glob_pathGCS;
    std::mutex mx_glob_pathGCS;
    std::condition_variable cv_glob_pathGCS;
    std::atomic_bool pathGCS_new;

/* Global variable glob_trajENU */

    struct trajENU glob_trajENU;
    std::mutex mx_glob_trajENU;
    std::condition_variable cv_glob_trajENU;
    std::atomic_bool trajENU_new;

/* Global variable glob_pathENU */

    struct pathENU glob_pathENU;
    std::mutex mx_glob_pathENU;
    std::condition_variable cv_glob_pathENU;
    std::atomic_bool pathENU_new;

/* Global tp_err struct */

    std::deque<tp_err> glob_tp_err;
    std::mutex mx_glob_tp_err;
    std::condition_variable cv_glob_tp_err;
    std::atomic_bool tp_err_empty;

/* Global trajstatus struct */

    struct trajstatus glob_trajstatus;
    std::mutex mx_glob_trajstatus;

/* Global pathstatus struct */
    struct pathstatus glob_pathstatus;
    std::mutex mx_glob_pathstatus;

/* Global tpstatus struct */

    struct tpstatus glob_tpstatus;
    std::mutex mx_glob_tpstatus;
    std::condition_variable cv_glob_tpstatus;
    std::atomic_bool tpstatus_new;

}
