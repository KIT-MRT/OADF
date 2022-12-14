/**
 * \file tp_ext_interface.cpp
 * \brief Implementation of tp_ext_interface.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#include "tp_core.h"

namespace tpinterface {

    void tx_pathGCS(pathGCS ext_pathGCS) {

            //Use lock_guard to lock glob_pathGCS
            std::lock_guard<std::mutex> guard_glob_pathGCS{tpinterface::mx_glob_pathGCS};

            if (tpinterface::glob_pathGCS.send_tai_seconds != ext_pathGCS.send_tai_seconds ||
                tpinterface::glob_pathGCS.send_tai_nanoseconds != ext_pathGCS.send_tai_nanoseconds) {

                tpinterface::glob_pathGCS = std::move(ext_pathGCS);

                tpinterface::pathGCS_new = true;

                tpinterface::cv_glob_pathGCS.notify_one();

#ifdef TP_INTERFACE
                std::stringstream ss;
                ss << "tp: pathGCS versendet" << "\n";
                std::lock_guard<std::mutex> guard{mx_cout};
                std::cout << ss.str();
#endif

            }

    }

    void tx_trajGCS(trajGCS ext_trajGCS) {

            //Use lock_guard to lock glob_trajGCS
            std::lock_guard<std::mutex> guard_glob_trajGCS{tpinterface::mx_glob_trajGCS};

            if (tpinterface::glob_trajGCS.send_tai_seconds != ext_trajGCS.send_tai_seconds ||
                tpinterface::glob_trajGCS.send_tai_nanoseconds != ext_trajGCS.send_tai_nanoseconds) {

                tpinterface::glob_trajGCS = std::move(ext_trajGCS);

                tpinterface::trajGCS_new = true;

                tpinterface::cv_glob_trajGCS.notify_one();

#ifdef TP_INTERFACE
                std::stringstream ss;
                ss << "tp: trajGCS versendet" << "\n";
                std::lock_guard<std::mutex> guard{mx_cout};
                std::cout << ss.str();
#endif

            }

    }

    void rx_tp_err(tp_err &ext_tp_err) {

        //Use unique_lock to lock glob_tp_err
        std::unique_lock<std::mutex> lk_glob_tp_err{tpinterface::mx_glob_tp_err};

        if (!(tpinterface::exitCondition || !tpinterface::tp_err_empty)) {

            // Wait for new tp_err or notification to exit thread
            cv_glob_tp_err.wait(lk_glob_tp_err, []() {

                return tpinterface::exitCondition || !tpinterface::tp_err_empty;
            });

        }

        if (!tpinterface::exitCondition) {

            ext_tp_err = glob_tp_err.front();
            glob_tp_err.pop_front();

            if (glob_tp_err.empty()) {

                tpinterface::tp_err_empty = true;

            }

#ifdef TP_INTERFACE
            std::stringstream ss;
            ss << "tp: tp_err empfangen" << "\n";
            std::lock_guard<std::mutex> guard{mx_cout};
            std::cout << ss.str();
#endif

        }

    }

    void rx_pathENU(pathENU &ext_pathENU) {

        //Use unique_lock to lock glob_pathENU
        std::unique_lock<std::mutex> lk_glob_pathENU{tpinterface::mx_glob_pathENU};

        if (!(tpinterface::exitCondition || tpinterface::pathENU_new)) {

            // Wait for new pathENU or notification to exit thread
            cv_glob_pathENU.wait(lk_glob_pathENU, []() {

                return tpinterface::exitCondition || tpinterface::pathENU_new;

            });

        }

        if (!tpinterface::exitCondition) {

            ext_pathENU = tpinterface::glob_pathENU;

            tpinterface::pathENU_new = false;

#ifdef TP_INTERFACE
            std::stringstream ss;
            ss << "tp: pathENU empfangen" << "\n";
            std::lock_guard<std::mutex> guard{mx_cout};
            std::cout << ss.str();
#endif

        }

    }

    void rx_trajENU(trajENU &ext_trajENU) {

        //Use unique_lock to lock glob_trajENU
        std::unique_lock<std::mutex> lk_glob_trajENU{tpinterface::mx_glob_trajENU};

        if (!(tpinterface::exitCondition || tpinterface::trajENU_new)) {

            // Wait for new trajENU or notification to exit thread
            cv_glob_trajENU.wait(lk_glob_trajENU, []() {

                return tpinterface::exitCondition || tpinterface::trajENU_new;

            });

        }

        if (!tpinterface::exitCondition) {

            ext_trajENU = tpinterface::glob_trajENU;

            tpinterface::trajENU_new = false;

#ifdef TP_INTERFACE
            std::stringstream ss;
            ss << "tp: trajENU empfangen" << "\n";
            std::lock_guard<std::mutex> guard{mx_cout};
            std::cout << ss.str();
#endif

        }

    }

    void rx_tpstatus(tpstatus &ext_tpstatus) {

        //Use unique_lock to lock glob_tpstatus
        std::unique_lock<std::mutex> lk_glob_tpstatus{tpinterface::mx_glob_tpstatus};

        if (!(tpinterface::exitCondition || tpinterface::tpstatus_new)) {

            // Wait for new tpstatus or notification to exit thread
            cv_glob_tpstatus.wait(lk_glob_tpstatus, []() {

                return tpinterface::exitCondition || tpinterface::tpstatus_new;

            });

        }

        if (!tpinterface::exitCondition) {

            ext_tpstatus = glob_tpstatus;

            tpinterface::tpstatus_new = false;

#ifdef TP_INTERFACE
            std::stringstream ss;
            ss << "tp: tpstatus received" << "\n";
            std::lock_guard<std::mutex> guard{mx_cout};
            std::cout << ss.str();
#endif

        }

    }

    void read_tpparam(){

#if defined(TUDa_NO_BRAINSTEM_BIG)

        auto data = toml::parse("./config/tpservice/autoX/autoX.toml");

#endif

#if defined(TUDa_NO_BRAINSTEM_SMALL)

        auto data = toml::parse("./config/tpservice/autoX/autoX.toml");

#endif

#if !defined(TUDa_NO_BRAINSTEM_BIG) && !defined(TUDa_NO_BRAINSTEM_SMALL)

        auto data = toml::parse("/ASOA/services/tpservice/autoX.toml");

#endif

        /* Display debug messages */

        tpparam::errmsg = toml::find<std::uint16_t>(data, "debug", "errmsg");
        tpparam::runtime = toml::find<std::uint16_t>(data, "debug", "runtime");

    }

}