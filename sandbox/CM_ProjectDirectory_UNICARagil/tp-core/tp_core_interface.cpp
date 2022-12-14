/**
 * \file tp_core_interface.cpp
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#include "tp_core.h"

void tpcore::tx_tp_err(const tp_err &tp_err) {

    {

        //Use lock_guard to lock glob_tp_err
        std::lock_guard<std::mutex> guard_glob_tp_err{tpinterface::mx_glob_tp_err};

        tpinterface::glob_tp_err.push_back(tp_err);

        tpinterface::tp_err_empty = false;

        tpinterface::cv_glob_tp_err.notify_one();

    }

#ifdef TP_INTERFACE
    std::stringstream ss;
    ss << "tp: tp_err versendet" << "\n";
    std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
    std::cout << ss.str();
#endif
}


void tpcore::tx_pathENU(pathENU ext_pathENU) {

    //Use lock_guard to lock glob_pathENU
    std::lock_guard<std::mutex> guard_glob_pathENU{tpinterface::mx_glob_pathENU};

    if (tpinterface::glob_pathENU.send_tai_seconds != ext_pathENU.send_tai_seconds ||
        tpinterface::glob_pathENU.send_tai_nanoseconds != ext_pathENU.send_tai_nanoseconds) {

        tpinterface::glob_pathENU = std::move(ext_pathENU);

        tpinterface::pathENU_new = true;

        tpinterface::cv_glob_pathENU.notify_one();

#ifdef TP_INTERFACE
        std::stringstream ss;
        ss << "tp: pathENU versendet" << "\n";
        std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
        std::cout << ss.str();
#endif

    }

}


void tpcore::tx_trajENU(trajENU ext_trajENU) {

    //Use lock_guard to lock glob_trajENU
    std::lock_guard<std::mutex> guard_glob_trajENU{tpinterface::mx_glob_trajENU};

    if (tpinterface::glob_trajENU.send_tai_seconds != ext_trajENU.send_tai_seconds ||
        tpinterface::glob_trajENU.send_tai_nanoseconds != ext_trajENU.send_tai_nanoseconds) {

        tpinterface::glob_trajENU = std::move(ext_trajENU);

        tpinterface::trajENU_new = true;

        tpinterface::cv_glob_trajENU.notify_one();

#ifdef TP_INTERFACE
        std::stringstream ss;
        ss << "tp: trajENU versendet" << "\n";
        std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
        std::cout << ss.str();
#endif

    }

}

void tpcore::rx_pathGCS(pathGCS &ext_pathGCS) {

    //Use unique_lock to lock glob_pathGCS
    std::unique_lock<std::mutex> lk_glob_pathGCS{tpinterface::mx_glob_pathGCS};

    if (!(tpinterface::exitCondition || tpinterface::pathGCS_new)) {

        // Wait for new pathGCS or notification to exit thread
        tpinterface::cv_glob_pathGCS.wait(lk_glob_pathGCS, []() {

            return tpinterface::exitCondition ||
                   tpinterface::pathGCS_new;
        });

    }

    if (!tpinterface::exitCondition) {

        ext_pathGCS = tpinterface::glob_pathGCS;

        tpinterface::pathGCS_new = false;

        taitime taitime;
        tpinterface::read_taitime(taitime);

        std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};
        tpinterface::glob_pathstatus.pathGCS_transm_time_seconds =
                ((taitime.tai_seconds - ext_pathGCS.send_tai_seconds) * 1e9 +
                 (taitime.tai_nanoseconds - ext_pathGCS.send_tai_nanoseconds)) / 1e9;

#ifdef TP_INTERFACE
        std::stringstream ss;
        ss << "tp: pathGCS empfangen" << "\n";
        std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
        std::cout << ss.str();
#endif

    }

}

void tpcore::rx_trajGCS(trajGCS &ext_trajGCS) {

    //Use unique_lock to lock glob_trajGCS
    std::unique_lock<std::mutex> lk_glob_trajGCS{tpinterface::mx_glob_trajGCS};

    if (!(tpinterface::exitCondition || tpinterface::trajGCS_new)) {

        // Wait for new trajGCS or notification to exit thread
        tpinterface::cv_glob_trajGCS.wait(lk_glob_trajGCS, []() {

            return tpinterface::exitCondition ||
                   tpinterface::trajGCS_new;
        });

    }

    if (!tpinterface::exitCondition) {

        ext_trajGCS = tpinterface::glob_trajGCS;

        tpinterface::trajGCS_new = false;

        taitime taitime;
        tpinterface::read_taitime(taitime);

        std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};
        tpinterface::glob_trajstatus.trajGCS_transm_time_seconds =
                ((taitime.tai_seconds - ext_trajGCS.send_tai_seconds) * 1e9 +
                 (taitime.tai_nanoseconds - ext_trajGCS.send_tai_nanoseconds)) / 1e9;

#ifdef TP_INTERFACE
        std::stringstream ss;
        ss << "tp: trajGCS empfangen" << "\n";
        std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
        std::cout << ss.str();
#endif

    }

}

void tpcore::read_trajstatus(trajstatus &ext_trajstatus) {

    {
        //Use lock_guard to lock glob_trajstatus
        std::lock_guard<std::mutex> guard_glob_trajstatus{tpinterface::mx_glob_trajstatus};

        ext_trajstatus = tpinterface::glob_trajstatus;

    }

#ifdef TP_INTERFACE
    std::stringstream ss;
    ss << "tp: trajstatus read" << "\n";
    std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
    std::cout << ss.str();
#endif

}

void tpcore::read_pathstatus(pathstatus &ext_pathstatus) {

    {
        //Use lock_guard to lock glob_pathstatus
        std::lock_guard<std::mutex> guard_glob_pathstatus{tpinterface::mx_glob_pathstatus};

        ext_pathstatus = tpinterface::glob_pathstatus;

    }

#ifdef TP_INTERFACE
    std::stringstream ss;
    ss << "tp: pathstatus read" << "\n";
    std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
    std::cout << ss.str();
#endif

}

void tpcore::tx_tpstatus(tpstatus ext_tpstatus) {

    //Use lock_guard to lock glob_tpstatus
    std::lock_guard<std::mutex> guard_glob_tpstatus{tpinterface::mx_glob_tpstatus};

    if (tpinterface::glob_tpstatus.send_tai_seconds != ext_tpstatus.send_tai_seconds ||
        tpinterface::glob_tpstatus.send_tai_nanoseconds != ext_tpstatus.send_tai_nanoseconds) {

        tpinterface::glob_tpstatus = std::move(ext_tpstatus);

        tpinterface::tpstatus_new = true;

        tpinterface::cv_glob_tpstatus.notify_one();

#ifdef TP_INTERFACE
        std::stringstream ss;
        ss << "tp: tpstatus sent" << "\n";
        std::lock_guard<std::mutex> guard{tpinterface::mx_cout};
        std::cout << ss.str();
#endif

    }

}