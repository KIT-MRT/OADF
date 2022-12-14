/*
 ******************************************************************************
 **  CarMaker - Version 9.1
 **  Vehicle Dynamics Simulation Toolkit
 **
 **  Copyright (C)   IPG Automotive GmbH
 **                  Bannwaldallee 60             Phone  +49.721.98520.0
 **                  76185 Karlsruhe              Fax    +49.721.98520.99
 **                  Germany                      WWW    www.ipg-automotive.com
 ******************************************************************************
 **
 ** Wrapper for automated driving functions of AP 2.4 within the UNICARagil project
 **
 ******************************************************************************
 */

// Include standard functions
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>

// Include CarMaker specific stuff
#include "CarMaker.h"
#include "Car/Vehicle_Car.h"
#include "MyModels.h"
#include "Vehicle/Sensor_GNav.h"
#include "User.h"


// Include Unicar specific stuff
#include "../unicar-definitions/UNICAR_definitions.h"
#include "../ftr-core/FTR.h"
#include "FTR_CM.h"


//Header trajectory preprocessing
#include "tp_cm.h"

//Header driving corridor monitoring
#include "dcm_cm.h"

#include "cmap24.h"

// Ros data
#include "DriverTrajectory.h"

// Define Dummy IF for CarMaker to use (not needed for any calculations)
struct tUnicarControl_IF {
    double dummy;
} UnicarControl_IF;


static const char ThisModelClass[] = "VehicleControl";
static const char ThisModelKind[] = "VehicleControl_UNICAR";
static const int ThisVersionId = 1;


// Unicar specific static variables
static bool start = 0;
static long Cycles_No_CM = 0;
static trajGCS traj_full_GCS;
static pathGCS path_full_GCS;
static trajGCS traj_GCS;
static trajENU traj_ENU;
static unicarState state;
static trajENU ext_sh_trajENU;
static pathGCS ext_pathGCS;
static pathENU ext_pathENU;
static tp_err ext_tp_err;
static OL_radar ext_OL_ps_RF;
static OL_radar ext_OL_ps_RB;
static FL_uss ext_FL_ps_ECU;


// FTR specific stuff
static setpointDM DMValues;
controlDiff contrDiff;
poseOffset pose_Offset = {0};
bool ext_calculateOffset;


// Start tp threads
//tpcore tp;


/******************************************************************************/


static void
VehicleControl_UNICAR_DeclQuants_dyn(struct tUnicarControl_IF *mp, int park) {

    static struct tUnicarControl_IF MyModel_Dummy;
    mp = &MyModel_Dummy;

}


static void
VehicleControl_UNICAR_DeclQuants(void *MP) {
    struct tUnicarControl_IF *mp = (struct tUnicarControl_IF *) MP;

    if (mp == NULL) {
        /* Define here dict entries for non-dynamically allocated (static) variables. */

    } else {
        VehicleControl_UNICAR_DeclQuants_dyn(mp, 0);
    }
}

// GPStoTAI convertion functions
void GPStoTAI(uint16_t &gpsweeks, double &gpssow, taitime &TAItime) {
    const double sec_per_week = 604800;
    const double sec_gpssow = std::floor(gpssow);
    TAItime.tai_seconds = gpsweeks * sec_per_week + 19 + sec_gpssow;
    TAItime.tai_nanoseconds = (gpssow - sec_gpssow) * 1e9;
}

/**
 * Convert GPS time to Tai time
 *
 * @param gpsweeks
 * @param gpssow
 * @param tai_seconds
 * @param tai_nanoseconds
 */
void GPStoTAI(uint16_t &gpsweeks, double &gpssow, uint64_t &tai_seconds, uint32_t &tai_nanoseconds) {
    taitime time;
    GPStoTAI(gpsweeks, gpssow, time);
    tai_seconds = time.tai_seconds;
    tai_nanoseconds = time.tai_nanoseconds;
}


static int
VehicleControl_UNICAR_Calc(void *MP, double dt) {

    // FTR variables
    dynState ext_dynStateVL;
    dynState ext_dynStateVR;
    dynState ext_dynStateHL;
    dynState ext_dynStateHR;
    offsetState stateForCorrection;
    trajInterpolated traj_int;


    // Exit calc function if no simulation is running
    if (SimCore.State != SCState_Simulate) return 0;


    static int is_updated = 0;


    tDrvTrj_Trj trj;
    tDrvTrj_Pnt trj_Pnt;

    trj.trj_GCS_new = false;
    trj.path_GCS_new = false;


    // Check for first call of the function and read in trajectory
    if (!start) {

        is_updated = DrvTrj_GetTrajectory(&trj, &trj_Pnt, 0, 0, DrvTrj_Mode_UpdateGCS);

        if (is_updated && trj.trj_GCS_new) {

            start = 1;
            traj_GCS = trj.trj_GCS;
            trj.trj_GCS_new = false;
            taitime taitime;

            tpinterface::read_taitime(taitime);

            traj_GCS.send_tai_seconds = taitime.tai_seconds;
            traj_GCS.send_tai_nanoseconds = taitime.tai_nanoseconds;


            /* Send ext_trajGCS and ext_pathGCS to tp thread and wait for results */
            tpinterface::tx_trajGCS(traj_GCS);


            tpinterface::rx_trajENU(traj_ENU);

            if (tpinterface::exitCondition) {
                return 1;
            }

            // Trigger calculation of offset for correction within FTR
            bool ext_calculateOffset = true;
            ftr_interface::tx_calculateOffset(ext_calculateOffset);

            // Get vehicle dynamics state from CarMaker (later replaced by FZS)
            getState(state);

        }

    } else {

        if (Cycles_No_CM % 10 == 0) {

            // Get vehicle dynamics state from CarMaker (later replaced by FZS)
            getState(state);

        }

    if(sh_use){

        // Update the radar object lists
        if (Cycles_No_CM % 70 == 0) {

            uint16_t input = 0;

            // Radar sensor front
            cm_getObjectList_Radar(ext_OL_ps_RF, input);

            input = 1;

            // Radar sensor back
            cm_getObjectList_Radar(ext_OL_ps_RB, input);

        }

        // Update the uss feature lists
        if (Cycles_No_CM % 70 == 0) {

            // Radar sensor front
            cm_getObjectList_USS(ext_FL_ps_ECU);

        }

    }

        // Update the trajectory every 100ms
        if (Cycles_No_CM % 100 == 0) {

            int new_traj = DrvTrj_GetTrajectory(&trj, &trj_Pnt, 0, 0, DrvTrj_Mode_UpdateGCS);

            if (new_traj && trj.trj_GCS_new) {

                traj_GCS = trj.trj_GCS;
                trj.trj_GCS_new = false;

                taitime taitime;

                tpinterface::read_taitime(taitime);

                traj_GCS.send_tai_seconds = taitime.tai_seconds;
                traj_GCS.send_tai_nanoseconds = taitime.tai_nanoseconds;


                /* Send ext_trajGCS and ext_pathGCS to tp thread and wait for results */
                tpinterface::tx_trajGCS(traj_GCS);
                tpinterface::rx_trajENU(traj_ENU);

                if (tpinterface::exitCondition) {
                    return 1;
                }

            // Trigger calculation of offset for correction within FTR
            bool ext_calculateOffset = true;
            ftr_interface::tx_calculateOffset(ext_calculateOffset);

            }

            if (sh_use) {

                if (sh_status == 1) {

                    if (new_traj && trj.path_GCS_new) {

                        ext_pathGCS = trj.path_GCS;
                        trj.path_GCS_new = false;

                        taitime taitime;

                        dcminterface::read_taitime(taitime);
                        ext_pathGCS.send_tai_seconds = taitime.tai_seconds;
                        ext_pathGCS.send_tai_nanoseconds = taitime.tai_nanoseconds;


                        /* Send ext_pathGCS to tp thread and wait for results */
                        tpinterface::tx_pathGCS(ext_pathGCS);
                        tpinterface::rx_pathENU(ext_pathENU);

                        if (tpinterface::exitCondition) {
                            return 1;
                        }

                        dcminterface::tx_pathENU(ext_pathENU);

                    }

                }

                if (sh_status == 1 || sh_status == 2) {
                    dcminterface::rx_trajENU(ext_sh_trajENU);

		     if (sh_status == 2) {

                         // Trigger calculation of offset for correction within FTR
                         bool ext_calculateOffset = true;
                         ftr_interface::tx_calculateOffset(ext_calculateOffset);

	           }

                }

            }

        }

        if (Cycles_No_CM % 20 == 0) {

            // Convert trajENU to trajENUarray
            trajENU_array traj_ENU_array;

            Vector2Array(traj_ENU, traj_ENU_array);

           ftr_global::curr_time = state.misc.time.tai_seconds + state.misc.time.tai_nanoseconds / 1e9;


            if (sh_use) {

                if (sh_status == 2) {

                    // Convert trajENU to trajENUarray
                    trajENU_array ext_sh_trajENU_array;

                    Vector2Array(ext_sh_trajENU, ext_sh_trajENU_array);

                    // Don't execute FTR if trajectory doesn't include values for the current timestamp
                    if (ftr_global::curr_time < (ext_sh_trajENU_array.tai_seconds[49] + ext_sh_trajENU_array.tai_nanoseconds[49] / 1e9) && ftr_global::curr_time > (ext_sh_trajENU_array.tai_seconds[0] + ext_sh_trajENU_array.tai_nanoseconds[0] / 1e9)) {

                    // Call offset correction wrapper for CarMaker
                    offsetCorrectionCM(state, ext_sh_trajENU_array, stateForCorrection);

                        ftr::FTR(ext_sh_trajENU_array, state, DMValues, pose_Offset, contrDiff, ext_dynStateVL,
                                ext_dynStateVR,
                                ext_dynStateHL, ext_dynStateHR, traj_int);

                    }
                    
                } else {

                     // Don't execute FTR if trajectory doesn't include values for the current timestamp
                    if (ftr_global::curr_time < (traj_ENU_array.tai_seconds[49] + traj_ENU_array.tai_nanoseconds[49] / 1e9) && ftr_global::curr_time > (traj_ENU_array.tai_seconds[0] + traj_ENU_array.tai_nanoseconds[0] / 1e9)) {

                        // Call offset correction wrapper for CarMaker
                        offsetCorrectionCM(state, traj_ENU_array, stateForCorrection);

                        //Call FTR
                        ftr::FTR(traj_ENU_array, state, DMValues, pose_Offset, contrDiff, ext_dynStateVL, ext_dynStateVR,
                                ext_dynStateHL, ext_dynStateHR, traj_int);

                    }

                }

            } else {

                // Don't execute FTR if trajectory doesn't include values for the current timestamp
                if (ftr_global::curr_time < (traj_ENU_array.tai_seconds[49] + traj_ENU_array.tai_nanoseconds[49] / 1e9) && ftr_global::curr_time > (traj_ENU_array.tai_seconds[0] + traj_ENU_array.tai_nanoseconds[0] / 1e9)) {

                    // Call offset correction wrapper for CarMaker
                    offsetCorrectionCM(state, traj_ENU_array, stateForCorrection);

                    //Call FTR
                    ftr::FTR(traj_ENU_array, state, DMValues, pose_Offset, contrDiff, ext_dynStateVL, ext_dynStateVR,
                            ext_dynStateHL, ext_dynStateHR, traj_int);

                }

            }

        }

    }

// Write setpoint actuator values to CM
    writeDM(DMValues);

    Cycles_No_CM++;

    return 0;
}


static void *
VehicleControl_UNICAR_New(struct tInfos *Inf, const char *KindKey) {
    struct tUnicarControl_IF *mp = NULL;
    const char *ModelKind;// *key;
    char MsgPre[64];
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_VehicleControl, KindKey,
                                         0, ThisVersionId, &VersionId)) == NULL)
        return NULL;

    mp = (struct tUnicarControl_IF *) calloc(1, sizeof(*mp));

    sprintf(MsgPre, "%s %s", ThisModelClass, ThisModelKind);


    // Reset Unicar specific variables before each new test run
    start = 0;
    Cycles_No_CM = 0;

    traj_full_GCS.tai_nanoseconds.clear();
    traj_full_GCS.tai_seconds.clear();
    traj_full_GCS.standstill.clear();
    traj_full_GCS.pos_ell_lat_rad.clear();
    traj_full_GCS.pos_ell_lon_rad.clear();
    traj_full_GCS.pos_ell_h_m.clear();
    traj_full_GCS.vel_enu_mag_m_s.clear();
    traj_full_GCS.vel_enu_angle_rad.clear();
    traj_full_GCS.acc_enu_mag_m_s2.clear();
    traj_full_GCS.acc_enu_angle_rad.clear();
    traj_full_GCS.ori_enu_psi_rad.clear();
    traj_full_GCS.ori_vel_enu_psi_rad_s.clear();
    traj_full_GCS.ori_acc_enu_psi_rad_s2.clear();
    traj_full_GCS.parking.clear();
    traj_full_GCS.slope_lat.clear();
    traj_full_GCS.slope_long.clear();
    traj_full_GCS.send_tai_nanoseconds = 0;
    traj_full_GCS.send_tai_seconds = 0;

    traj_GCS = {0};
    traj_ENU = {0};

    state = {0};
    DMValues = {0};
    contrDiff = {0};
    ftr_interface::glob_offsetStateBuffer.remove(ftr::NoElementsRingbuffer);

    ftr_global::timestamps.setlength(50);
	ftr_global::pos_east.setlength(50);
	ftr_global::pos_north.setlength(50);
	ftr_global::pos_yaw.setlength(50);
	ftr_global::vel_mag.setlength(50);
	ftr_global::vel_angle.setlength(50);
	ftr_global::vel_yaw.setlength(50);
	ftr_global::acc_mag.setlength(50);
	ftr_global::acc_angle.setlength(50);
	ftr_global::acc_yaw.setlength(50);
	ftr_global::misc_standstill.setlength(50);
	ftr_global::misc_parking.setlength(50);
	ftr_global::slope_lon.setlength(50);
	ftr_global::slope_lat.setlength(50);

    // tp global variables
    ext_pathENU = {0};
    ext_pathGCS = {0};
    ext_tp_err = {0};

    // dcm global variables
    ext_sh_trajENU = { 0 };
    tpathbegin = { 0 };
    tdcmshpathinput = { 0 };
    txL_psinput = { 0 };
    sh_use = 0;
    sh_status = 0;
    ext_OL_ps_RF = {0};
    ext_OL_ps_RB = {0};
    ext_FL_ps_ECU = {0};


    return mp;

}


static void
VehicleControl_UNICAR_Delete(void *MP) {
    struct tUnicarControl_IF *mp = (struct tUnicarControl_IF *) MP;

    /* Park the dict entries for dynamically allocated variables before deleting */
    VehicleControl_UNICAR_DeclQuants_dyn(mp, 1);
    free(mp);

}


int
VehicleControl_Register_VehicleControl_UNICAR(void) {
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.VehicleControl.VersionId = ThisVersionId;
    m.VehicleControl.New = VehicleControl_UNICAR_New;
    m.VehicleControl.Calc = VehicleControl_UNICAR_Calc;
    m.VehicleControl.DeclQuants = VehicleControl_UNICAR_DeclQuants;
    m.VehicleControl.Delete = VehicleControl_UNICAR_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    m.VehicleControl.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_VehicleControl, ThisModelKind, &m);
}
