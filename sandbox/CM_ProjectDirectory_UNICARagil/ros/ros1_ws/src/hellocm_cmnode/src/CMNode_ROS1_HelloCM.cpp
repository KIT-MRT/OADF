/*!
 ******************************************************************************
 **  CarMaker - Version 8.0.1
 **  Vehicle Dynamics Simulation Toolkit
 **
 **  Copyright (C)   IPG Automotive GmbH
 **                  Bannwaldallee 60             Phone  +49.721.98520.0
 **                  76185 Karlsruhe              Fax    +49.721.98520.99
 **                  Germany                      WWW    www.ipg-automotive.com
 ******************************************************************************
 *
 * Description:
 * - Prototype/Proof of Concept
 * - Unsupported ROS Example with CarMaker
 * - Structure may change in future!
 * - Change general parameters in Infofile for CMRosIF ("Data/Config/CMRosIFParameters")
 * - Basic communication with or without parameterizable synchronization
 *
 *
 * ToDo:
 * - C++!!!
 * - ROS naming/way/namespaces
 * - parameter: CarMaker read, ROS set by service?
 *   -> ROS parameter mechanism seems better solution!
 * - node/topic/... destruction to allow dynamic load/unload
 *   when TestRun starts instead of initialization at CarMaker startup
 * - New Param_Get() function to read parameters from Infofile
 * - ...
 *
 */


/* CarMaker
 * - include other headers e.g. to access to vehicle data
 *   - e.g. "Vehicle.h" or "Vehicle/Sensor_*.h".
 * - additional headers can be found in "<CMInstallDir>/include/"
 * - see Reference Manual, chapter "User Accessible Quantities" to find some variables
 *   that are already defined in DataDictionary and their corresponding C-Code Name
 */
#include "DataDict.h"
#include "InfoUtils.h"
#include "Log.h"
#include "SimCore.h"
#include <string>
#include <iostream>

#include "apo.h"
#include "GuiCmd.h"

#include "Vehicle.h"
#include "Car/Car.h"
#include "Vehicle/Sensor_FSpace.h"
#include "Vehicle/Sensor_GNav.h"
#include "Vehicle/Sensor_LidarRSI.h"
#include "Vehicle/Sensor_Object.h"
#include "Vehicle/Sensor_TSign.h"


// #include "DrivMan.h"
// #include "Vehicle/Sensor_Object.h"
#if defined(CUSTOM_DRIVER_TRAJECTORY)
#define TRAJECTORY_MAX_VIS_PNTS 50
#include <DriverTrajectory.h> /* CarMaker Extension Driver Trajectory */
#include <ros/console.h>
#endif

//#include <automated_driving_msgs/MotionState.h>
//#include <automated_driving_msgs/ObjectStateArray.h>
//#include <boost/filesystem.hpp>
//#include <geometry_msgs/TransformStamped.h>
#include <oadf_msgs/IPGDriverTrajectory.h>
#include <oadf_msgs/trajGCS.h>
#include <oadf_msgs/pathGCS.h>
#include <oadf_msgs/GPSDate.h>
#include <oadf_msgs/Vehicle.h>
#include <oadf_msgs/Obstacle_CarMaker.h>
#include <oadf_msgs/Obstacle_CarMaker_Array.h>
//#include <nav_msgs/Odometry.h>
//#include <tf2_msgs/TFMessage.h>
//#include <tf2_ros/transform_broadcaster.h>
//#include <tf2/LinearMath/Quaternion.h>

//#include <lanelet2_projection/UTM.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <sensor_msgs/PointCloud2.h>


/* ROS */
#include "cmrosutils/CMRemote.h" /* Basic service for CarMaker remote from ROS */
#include "cmrosutils/CMRosIF_Utils.h" /* Only for CarMaker ROS Node!!! Functions are located in library for CarMaker ROS Interface */
#include "cmrosutils/CMRosUtils.h" /* Node independent templates, ...*/

/* Following header from external ROS node can be used to get topic/service/... names
 * Other mechanism:
 * 1. Put names manually independently for each node
 * 2. Using command line arguments or launch files and ROS remapping
 * - Doing so, only general message headers are necessary
 */
#if 1

#include "hellocm/ROS1_HelloCM.h" /* External ROS Node. Topic name, ... */

#else
#include <hellocm_msgs/CM2Ext.h>
#include <hellocm_msgs/Ext2CM.h>
#include <hellocm_msgs/Init.h>
#endif

/*! String and numerical version of this Node
 *  - String:    e.g. <Major>.<Minor>.<Patch>
 *  - Numerical: e.g. <nDigitsMajor><2DigitsMinor><2DigitsPatch>
 */
#define CMNODE_VERSION "0.9.0"
#define CMNODE_NUMVER 900


/* NDEBUG is set in CarMaker Makefile/MakeDefs in OPT_CFLAGS */
#if !defined NDEBUG
#warning "Debug options are enabled!"
#define DBLOG LOG
#else
#define DBLOG(...)
#endif

/* Not beautiful but consistent with external ROS Node
 * where ROS_INFO is used (implicit newline)*/
#define LOG(frmt, ...) Log(frmt "\n", ##__VA_ARGS__)

#include <vector>

//#include <proj.h>

int nume = -1;
std::vector<double *> b;
std::vector<double *> position;
std::vector<double *> rotation;
int lidarinit = 0;
//std::list<bool> lidarinit;
/*double* position0,position1,position2,position3;
double* rotation0,rotation1,rotation2,rotation3;
double* b0, b1, b2, b3;
bool lidarinit0 = false;
bool lidarinit1 = false;
bool lidarinit2 = false;
bool lidarinit3 = false;*/
std::vector<int> lidarsize;
ros::Time lastTime;


/*PJ_CONTEXT *C;
PJ *P;
PJ* P_for_GIS;
PJ_COORD A, B;*/



/* General switches for CarMaker ROS Node */
typedef enum tCMNode_Mode {
    CMNode_Mode_Disabled = 0, /*!< Node is disabled. e.g. don't publish. */
    CMNode_Mode_Default = 1,  /*!< Node is enabled, spinOnce is used  */
    CMNode_Mode_Threaded = 2  /*!< Node is enabled, spin in parallel thread
                                   - Messages are received all the time
                                   - Data is updated at defined position, e.g. *_In()
                                   - Currently not implemented! */
} tCMNode_Mode;


/* Managing synchronization between CarMaker Node and other ROS nodes */
typedef enum tCMNode_SyncMode {
    CMNode_SyncMode_Disabled = 0, /*!< No synchronization on CarMaker side */
    CMNode_SyncMode_Tpc = 1       /*!< Buffer messages or Spin until external Topics are received */
} tCMNode_SyncMode;


/* Global struct for this Node */
static struct {
    unsigned long CycleNoRel; /*!< CarMaker relative cycle number, e.g. since start of TestRun */

    struct {
        double Duration;   /*!< Time spent for synchronization task */
        int nCycles;       /*!< Number of cycles in synchronization loop */
        int CyclePrepDone; /*!< Last cycle when preparation was done */
        int CycleJobDone;  /*!< Last cycle when job was done */
        double SynthDelay; /*!< Synthetic delay in seconds provided to external node to check sync */
    } Sync;                /*!< Synchronization related information */

    struct {
        int CycleNo; /*!< Cycle number of external ROS Node (only for information) */

        /* For debugging */
        int CycleLastOut;   /*!< Cycle number when Topic was published */
        int CycleLastIn;    /*!< Cycle number when Topic from external ROS Node was received */
        int CycleLastFlush; /*!< Cycle number when data from external ROS Node was provided to model */
    } Model;                /*!< Model related information. ROS side! */

    struct {
        struct {
            tRosIF_TpcSub <hellocm_msgs::Ext2CM> Ext2CM; /* For this example also used for Synchronization */
            tRosIF_TpcSub <oadf_msgs::IPGDriverTrajectory> TrjIn;
            tRosIF_TpcSub <oadf_msgs::trajGCS> TrjDarm;
            tRosIF_TpcSub <oadf_msgs::pathGCS> TrjSafeDarm;
        } Sub; /*!< Topics to be subscribed */

        struct {
            tRosIF_TpcPub <hellocm_msgs::CM2Ext> CM2Ext;
            tRosIF_TpcPub <oadf_msgs::IPGDriverTrajectory> TrjOut;
            //tRosIF_TpcPub<automated_driving_msgs::MotionState> MotionStatePub;
            //tRosIF_TpcPub<automated_driving_msgs::ObjectStateArray> Objects;
            //tRosIF_TpcPub<automated_driving_msgs::ObjectStateArray> Static_Objects;
            tRosIF_TpcPub <sensor_msgs::PointCloud2> LidarPub0, LidarPub1, LidarPub2, LidarPub3;
            tRosIF_TpcPub <oadf_msgs::GPSDate> GPSDatePub;
//            tRosIF_TpcPub<geometry_msgs::TransformStamped> Tf;
            tRosIF_TpcPub <oadf_msgs::Vehicle> VehiclePub;
            tRosIF_TpcPub <oadf_msgs::Obstacle_CarMaker_Array> StaticPub;
            tRosIF_TpcPub <oadf_msgs::Obstacle_CarMaker_Array> DynamicPub;

            /*!< CarMaker can be working as ROS Time Server providing simulation time
             *   starting at 0 for each TestRun */
            tRosIF_TpcPub <rosgraph_msgs::Clock> Clock;
        } Pub; /*!< Topics to be published */
    } Topics;  /*!< ROS Topics used by this Node */

    struct {
        /*!< Initialization/Preparation of external ROS Node e.g. when simulation starts */
        tRosIF_Srv <hellocm_msgs::Init> Init;
        tRosIF_Srv <cmrosutils::CMRemote> CMRemote; // Trial
    } Services;                                    /*!< ROS Services used by this Node (client and server)*/

    struct {
        int QueuePub;     /*!< Queue size for Publishers */
        int QueueSub;     /*!< Queue size for Subscribers */
        int nCyclesClock; /*!< Number of cycles publishing /clock topic.
                               CycleTime should be multiple of this value */
        tCMNode_Mode Mode;
        tCMNode_SyncMode SyncMode;
        double SyncTimeMax; /* Maximum Synchronization time */

        tRosIF_Cfg Ros;
    } Cfg; /*!< General configuration for this Node */

    struct {
        int size = 50;
        bool updated = false;
        bool darm_traj_updated = false;
        bool darm_safe_traj_updated = false;

#if defined(CUSTOM_DRIVER_TRAJECTORY)
        /* Data for visualization in IPGMovie */
        struct {
            tDrvTrj_Pnt Pnts[TRAJECTORY_MAX_VIS_PNTS];
            int nPnts; /* Number of available points for visualization. Might be less than provided trajectory to
                          IPGDriver */
        } Vis;
#endif
    } Trajectory;

} CMNode;


/*!
 * Description:
 * - Callback for ROS Topic published by external ROS Node
 *
 */
static void cmnode_HelloCM_CB_TpcIn(const hellocm_msgs::Ext2CM::ConstPtr &msg) {
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
        return;

    int rv;
    auto in = &CMNode.Topics.Sub.Ext2CM;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    in->Msg.header = msg->header;
    in->Msg.time = msg->time;
    in->Msg.cycleno = msg->cycleno;

    /* Stopping simulation is only necessary when synchronization is activated */
    if (CMNode.Cfg.SyncMode == CMNode_SyncMode_Tpc &&
        (rv = CMCRJob_DoPrep_SetDone(in->Job, CMNode.CycleNoRel)) != CMCRJob_RV_Success) {
        LogErrF(
                EC_Sim, "CMNode: Error on DoPrep_SetDone for Job '%s'! rv=%s", CMCRJob_GetName(in->Job),
                CMCRJob_RVStr(rv));
    }

    /* Remember cycle for debugging */
    CMNode.Model.CycleLastIn = CMNode.CycleNoRel;
}


/*!
 * Description:
 * - Callback for subscribed /trj_in topic
 *
 */
static void cmnode_HelloCM_CB_TrjIn(const oadf_msgs::IPGDriverTrajectoryConstPtr &msg) {
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
        return;

    int rv;
    auto in = &CMNode.Topics.Sub.TrjIn;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    in->Msg.header = msg->header;

    if (in->Msg.poses.size() != msg->poses.size()) {
        in->Msg.poses.resize(msg->poses.size());
    }
    in->Msg.poses = msg->poses;

    CMNode.Trajectory.updated = true;
}

/*!
 * Description:
 * - Callback for subscribed /trajGCS topic
 *
 */
static void cmnode_HelloCM_CB_TrjDarm(const oadf_msgs::trajGCSConstPtr &msg) {
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
        return;

    int rv;
    auto in = &CMNode.Topics.Sub.TrjDarm;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */

    if (in->Msg.tai_seconds.size() != msg->tai_seconds.size()) {
        in->Msg.tai_seconds.resize(msg->tai_seconds.size());
        in->Msg.tai_nanoseconds.resize(msg->tai_nanoseconds.size());
        in->Msg.standstill.resize(msg->standstill.size());
        in->Msg.parking.resize(msg->parking.size());
        in->Msg.pos_ell_lat_rad.resize(msg->pos_ell_lat_rad.size());
        in->Msg.pos_ell_lon_rad.resize(msg->pos_ell_lon_rad.size());
        in->Msg.pos_ell_h_m.resize(msg->pos_ell_h_m.size());
        in->Msg.slope_long.resize(msg->slope_long.size());
        in->Msg.slope_lat.resize(msg->slope_lat.size());
        in->Msg.vel_enu_mag_m_s.resize(msg->vel_enu_mag_m_s.size());
        in->Msg.vel_enu_angle_rad.resize(msg->vel_enu_angle_rad.size());
        in->Msg.acc_enu_mag_m_s2.resize(msg->acc_enu_mag_m_s2.size());
        in->Msg.acc_enu_angle_rad.resize(msg->acc_enu_angle_rad.size());
        in->Msg.ori_enu_psi_rad.resize(msg->ori_enu_psi_rad.size());
        in->Msg.ori_vel_enu_psi_rad_s.resize(msg->ori_vel_enu_psi_rad_s.size());
        in->Msg.ori_acc_enu_psi_rad_s2.resize(msg->ori_acc_enu_psi_rad_s2.size());
    }
    in->Msg.tai_seconds = msg->tai_seconds;
    in->Msg.tai_nanoseconds = msg->tai_nanoseconds;
    in->Msg.standstill = msg->standstill;
    in->Msg.parking = msg->parking;
    in->Msg.pos_ell_lat_rad = msg->pos_ell_lat_rad;
    in->Msg.pos_ell_lon_rad = msg->pos_ell_lon_rad;
    in->Msg.pos_ell_h_m = msg->pos_ell_h_m;
    in->Msg.slope_long = msg->slope_long;
    in->Msg.slope_lat = msg->slope_lat;
    in->Msg.vel_enu_mag_m_s = msg->vel_enu_mag_m_s;
    in->Msg.vel_enu_angle_rad = msg->vel_enu_angle_rad;
    in->Msg.acc_enu_mag_m_s2 = msg->acc_enu_mag_m_s2;
    in->Msg.acc_enu_angle_rad = msg->acc_enu_angle_rad;
    in->Msg.ori_enu_psi_rad = msg->ori_enu_psi_rad;
    in->Msg.ori_vel_enu_psi_rad_s = msg->ori_vel_enu_psi_rad_s;
    in->Msg.ori_acc_enu_psi_rad_s2 = msg->ori_acc_enu_psi_rad_s2;
    in->Msg.use_atlatec = msg->use_atlatec;
    in->Msg.use_previous_trj = msg->use_previous_trj;
    CMNode.Trajectory.darm_traj_updated = true;

}

/*!
 * Description:
 * - Callback for subscribed /pathGCS topic
 *
 */
static void cmnode_HelloCM_CB_TrjSafeDarm(const oadf_msgs::pathGCSConstPtr &msg) {
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
        return;

    int rv;
    auto in = &CMNode.Topics.Sub.TrjSafeDarm;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    if (in->Msg.pos_ell_lat_rad.size() != msg->pos_ell_lat_rad.size()) {
        in->Msg.pos_ell_lat_rad.resize(msg->pos_ell_lat_rad.size());
        in->Msg.pos_ell_lon_rad.resize(msg->pos_ell_lon_rad.size());
        in->Msg.pos_ell_h_m.resize(msg->pos_ell_h_m.size());
        in->Msg.slope_long.resize(msg->slope_long.size());
        in->Msg.slope_lat.resize(msg->slope_lat.size());
        in->Msg.pos_arc_vel_m_s.resize(msg->pos_arc_vel_m_s.size());
        in->Msg.ori_enu_psi_rad.resize(msg->ori_enu_psi_rad.size());
        in->Msg.dir_ind.resize(msg->dir_ind.size());
    }

    in->Msg.tai_seconds = msg->tai_seconds;
    in->Msg.tai_nanoseconds = msg->tai_nanoseconds;
    in->Msg.n_elements = msg->n_elements;
    in->Msg.use_previous_trj = msg->use_previous_trj;
    in->Msg.use_atlatec = msg->use_atlatec;
    in->Msg.pos_ell_lat_rad = msg->pos_ell_lat_rad;
    in->Msg.pos_ell_lon_rad = msg->pos_ell_lon_rad;
    in->Msg.pos_ell_h_m = msg->pos_ell_h_m;
    in->Msg.slope_long = msg->slope_long;
    in->Msg.slope_lat = msg->slope_lat;
    in->Msg.pos_arc_vel_m_s = msg->pos_arc_vel_m_s;
    in->Msg.ori_enu_psi_rad = msg->ori_enu_psi_rad;
    in->Msg.dir_ind = msg->dir_ind;

    CMNode.Trajectory.darm_safe_traj_updated = true;

}

/*!
 * Description:
 * - Exemplary Service Callback for CarMaker Remote using ROS
 * - e.g. via rqt Service Caller or terminal "rosservice call ..."
 *
 *
 */
static bool cmnode_HelloCM_CB_SrvCMRemote(cmrosutils::CMRemote::Request &req, cmrosutils::CMRemote::Response &resp) {

    int rv = -2;
    char sbuf[512];

    LOG("%s: Service '%s' was triggered with type='%s', msg='%s', data='%s'",
        ros::this_node::getName().c_str(),
        CMNode.Services.CMRemote.Srv.getService().c_str(),
        req.type.c_str(),
        req.msg.c_str(),
        req.data.c_str());


    /* Commands to CarMaker GUI
     * - Tcl commands!
     * - More information see "ProgrammersGuide"
     */
    if (strcasecmp("guicmd", req.type.c_str()) == 0) {
        /* Default: Evaluate command sent with message */
        if (strcasecmp("eval", req.msg.c_str()) == 0) {
            /* e.g. data = 'LoadTestRun CMRosIF/AdaptiveCruiseControl; StartSim' */
            rv = GuiCmd_Eval(req.data.c_str());
        } else {
            if (strcasecmp("start", req.msg.c_str()) == 0) {
                if (req.data.length() == 0)
                    rv = GuiCmd_Eval("LoadTestRun CMRosIF/AdaptiveCruiseControl; StartSim");
                else {
                    sprintf(sbuf, "%s; StartSim", req.data.c_str());
                    rv = GuiCmd_Eval(sbuf);
                }
            }
            if (strcasecmp("stop", req.msg.c_str()) == 0)
                rv = GuiCmd_Eval("StopSim");
        }


        /* Commands directly to CarMaker Executable
         * - Warning:
         *   - Information normally provided by CarMaker GUI might be missing
         */
    } else if (strcasecmp("cmd", req.type.c_str()) == 0) {
        if (strcasecmp("start", req.msg.c_str()) == 0) {
            if (req.data.length() == 0) {
                /* Most strings are normally provided by CarMaker GUI */
                SimStart(NULL, ros::this_node::getName().c_str(), "CMRosIF/AdaptiveCruiseControl", NULL, NULL);
            } else {
                /* Most strings are normally provided by CarMaker GUI */
                SimStart(NULL, ros::this_node::getName().c_str(), req.data.c_str(), NULL, NULL);
            }
        }
        if (strcasecmp("stop", req.msg.c_str()) == 0)
            SimStop2(0);
        rv = 0;
    }

    resp.res = rv;
    return true;
}


/*****************************************************************************/
/**********          C-Code for interfacing with CarMaker!          **********/
/*****************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#if defined(CUSTOM_DRIVER_TRAJECTORY)
static tDrvTrj_TrjState usertrj_GetTrajectory(
    tDrvTrj_Trj* TrjTrgt, const tDrvTrj_Pnt* PntCurrent, double tPreview, double dsPreview, tDrvTrj_Mode Mode) {
    /* Nothing to do if disabled -> should not happen */
    if (Mode == DrvTrj_Mode_Disabled)
        return DrvTrj_TrjState_Error;

    /* update /trajGCS */
    if (Mode == DrvTrj_Mode_UpdateGCS) {
        if (!CMNode.Trajectory.darm_traj_updated && !CMNode.Trajectory.darm_safe_traj_updated)
            return DrvTrj_TrjState_Valid;

    if(CMNode.Trajectory.darm_traj_updated){

        auto msg = &CMNode.Topics.Sub.TrjDarm.Msg;
        const size_t trj_len = msg->tai_seconds.size();
        if (trj_len != 51) {
            ROS_ERROR("Received /trajGCS only has %lu elements, it should have %lu elements", trj_len, 51);
            return DrvTrj_TrjState_Error;
        }


        if (TrjTrgt->trj_GCS.tai_seconds.size() != msg->tai_seconds.size()) {
            TrjTrgt->trj_GCS.tai_seconds.resize(msg->tai_seconds.size());
            TrjTrgt->trj_GCS.tai_nanoseconds.resize(msg->tai_nanoseconds.size());
            TrjTrgt->trj_GCS.standstill.resize(msg->standstill.size());
            TrjTrgt->trj_GCS.parking.resize(msg->parking.size());
            TrjTrgt->trj_GCS.pos_ell_lat_rad.resize(msg->pos_ell_lat_rad.size());
            TrjTrgt->trj_GCS.pos_ell_lon_rad.resize(msg->pos_ell_lon_rad.size());
            TrjTrgt->trj_GCS.pos_ell_h_m.resize(msg->pos_ell_h_m.size());
            TrjTrgt->trj_GCS.slope_long.resize(msg->slope_long.size());
            TrjTrgt->trj_GCS.slope_lat.resize(msg->slope_lat.size());
            TrjTrgt->trj_GCS.vel_enu_mag_m_s.resize(msg->vel_enu_mag_m_s.size());
            TrjTrgt->trj_GCS.vel_enu_angle_rad.resize(msg->vel_enu_angle_rad.size());
            TrjTrgt->trj_GCS.acc_enu_mag_m_s2.resize(msg->acc_enu_mag_m_s2.size());
            TrjTrgt->trj_GCS.acc_enu_angle_rad.resize(msg->acc_enu_angle_rad.size());
            TrjTrgt->trj_GCS.ori_enu_psi_rad.resize(msg->ori_enu_psi_rad.size());
            TrjTrgt->trj_GCS.ori_vel_enu_psi_rad_s.resize(msg->ori_vel_enu_psi_rad_s.size());
            TrjTrgt->trj_GCS.ori_acc_enu_psi_rad_s2.resize(msg->ori_acc_enu_psi_rad_s2.size()+1);
        }




        for (size_t i = 0; i < trj_len; i++) {

            TrjTrgt->trj_GCS.tai_seconds[i] = msg->tai_seconds[i];
            TrjTrgt->trj_GCS.tai_nanoseconds[i] = msg->tai_nanoseconds[i];
            TrjTrgt->trj_GCS.standstill[i] = msg->standstill[i];
            TrjTrgt->trj_GCS.parking[i] = msg->parking[i];
            TrjTrgt->trj_GCS.pos_ell_lat_rad[i] = msg->pos_ell_lat_rad[i];
            TrjTrgt->trj_GCS.pos_ell_lon_rad[i] = msg->pos_ell_lon_rad[i];
            TrjTrgt->trj_GCS.pos_ell_h_m[i] = msg->pos_ell_h_m[i];
            TrjTrgt->trj_GCS.slope_long[i] = msg->slope_long[i];
            TrjTrgt->trj_GCS.slope_lat[i] = msg->slope_lat[i];
            TrjTrgt->trj_GCS.vel_enu_mag_m_s[i] = msg->vel_enu_mag_m_s[i];
            TrjTrgt->trj_GCS.vel_enu_angle_rad[i] = msg->vel_enu_angle_rad[i];
            TrjTrgt->trj_GCS.acc_enu_mag_m_s2[i] = msg->acc_enu_mag_m_s2[i];
            TrjTrgt->trj_GCS.acc_enu_angle_rad[i] = msg->acc_enu_angle_rad[i];
            TrjTrgt->trj_GCS.ori_enu_psi_rad[i] = msg->ori_enu_psi_rad[i];
            TrjTrgt->trj_GCS.ori_vel_enu_psi_rad_s[i] = msg->ori_vel_enu_psi_rad_s[i];
            TrjTrgt->trj_GCS.ori_acc_enu_psi_rad_s2[i] = msg->ori_acc_enu_psi_rad_s2[i];
        }

        TrjTrgt->trj_GCS.use_atlatec = msg->use_atlatec;
        TrjTrgt->trj_GCS.use_previous_trj = msg->use_previous_trj;

	TrjTrgt->trj_GCS_new = true;
	
        CMNode.Trajectory.darm_traj_updated = false; // reset flag

    }

     if (CMNode.Trajectory.darm_safe_traj_updated){

     auto msg = &CMNode.Topics.Sub.TrjSafeDarm.Msg;

     TrjTrgt->path_GCS.tai_seconds = msg->tai_seconds;
     TrjTrgt->path_GCS.tai_nanoseconds = msg->tai_nanoseconds;
     TrjTrgt->path_GCS.n_elements = msg->n_elements;
     TrjTrgt->path_GCS.use_atlatec = msg->use_atlatec;
     TrjTrgt->path_GCS.use_previous_trj = msg->use_previous_trj;

     if (TrjTrgt->path_GCS.pos_ell_lat_rad.size() != msg->pos_ell_lat_rad.size()) {
         TrjTrgt->path_GCS.pos_ell_lat_rad.resize(msg->pos_ell_lat_rad.size());
        TrjTrgt->path_GCS.pos_ell_lon_rad.resize(msg->pos_ell_lon_rad.size());
         TrjTrgt->path_GCS.pos_ell_h_m.resize(msg->pos_ell_h_m.size());
         TrjTrgt->path_GCS.slope_long.resize(msg->slope_long.size());
         TrjTrgt->path_GCS.slope_lat.resize(msg->slope_lat.size());
         TrjTrgt->path_GCS.pos_arc_vel_m_s.resize(msg->pos_arc_vel_m_s.size());
         TrjTrgt->path_GCS.ori_enu_psi_rad.resize(msg->ori_enu_psi_rad.size());
	 TrjTrgt->path_GCS.dir_ind.resize(msg->dir_ind.size());
     }


     for (size_t i = 0; i < msg->n_elements; i++) {
     TrjTrgt->path_GCS.pos_ell_lat_rad[i] = msg->pos_ell_lat_rad[i];
     TrjTrgt->path_GCS.pos_ell_lon_rad[i] = msg->pos_ell_lon_rad[i];
     TrjTrgt->path_GCS.pos_ell_h_m[i] = msg->pos_ell_h_m[i];
     TrjTrgt->path_GCS.slope_long[i] = msg->slope_long[i];
     TrjTrgt->path_GCS.slope_lat[i] = msg->slope_lat[i];
     TrjTrgt->path_GCS.pos_arc_vel_m_s[i] = msg->pos_arc_vel_m_s[i];
     TrjTrgt->path_GCS.ori_enu_psi_rad[i] = msg->ori_enu_psi_rad[i];
     TrjTrgt->path_GCS.dir_ind[i] = msg->dir_ind[i];

     }

	TrjTrgt->path_GCS_new = true;

         CMNode.Trajectory.darm_safe_traj_updated = false; // reset flag

     }

        return DrvTrj_TrjState_Updated;
    }

    /* Nothing to do if trajectory hasn't been updated */
    if (!CMNode.Trajectory.updated)
        return DrvTrj_TrjState_Valid;

    auto msg = &CMNode.Topics.Sub.TrjIn.Msg;

    for (ulong i = 0; i < static_cast<ulong>(TrjTrgt->nPntsMax) && i < msg->poses.size(); i++) {

        TrjTrgt->Pnts[i].Time = msg->poses[i].time;

        TrjTrgt->Pnts[i].Pos[0] = msg->poses[i].position.x;
        TrjTrgt->Pnts[i].Pos[1] = msg->poses[i].position.y;
        TrjTrgt->Pnts[i].Pos[2] = msg->poses[i].position.z;

        TrjTrgt->Pnts[i].Acc[0] = msg->poses[i].acceleration.x;
        TrjTrgt->Pnts[i].Acc[1] = msg->poses[i].acceleration.y;
        TrjTrgt->Pnts[i].Acc[2] = msg->poses[i].acceleration.z;
        TrjTrgt->Pnts[i].AccAbs = msg->poses[i].abs_acc;

        TrjTrgt->Pnts[i].Vel[0] = msg->poses[i].velocity.x;
        TrjTrgt->Pnts[i].Vel[1] = msg->poses[i].velocity.y;
        TrjTrgt->Pnts[i].Vel[2] = msg->poses[i].velocity.z;
        TrjTrgt->Pnts[i].VelAbs = msg->poses[i].abs_vel;

        TrjTrgt->Pnts[i].Yaw = msg->poses[i].yaw;
        TrjTrgt->Pnts[i].Kappa = msg->poses[i].kappa;
    }
    TrjTrgt->nPnts = msg->poses.size();

    CMNode.Trajectory.updated = false; // reset flag
    Log("  -> Calculated new trajectory from %.3fs to %3fs (tPreview=%.3fs, dsPreview=%.3fm, nPnts=%d)\n",
        TrjTrgt->Pnts[0].Time,
        TrjTrgt->Pnts[TrjTrgt->nPnts - 1].Time,
        tPreview,
        dsPreview,
        TrjTrgt->nPnts);

    /* Update points for visualization in IPG Movie */
    tDrvTrj_Pnt* pnt;
    if (TrjTrgt->nPnts <= TRAJECTORY_MAX_VIS_PNTS) {
        for (int i = 0; i < TrjTrgt->nPnts; i++) {
            pnt = &CMNode.Trajectory.Vis.Pnts[i];

            pnt->Time = TrjTrgt->Pnts[i].Time;
            pnt->Pos[0] = TrjTrgt->Pnts[i].Pos[0];
            pnt->Pos[1] = TrjTrgt->Pnts[i].Pos[1];
            pnt->Pos[2] = TrjTrgt->Pnts[i].Pos[2];
            pnt->Yaw = TrjTrgt->Pnts[i].Yaw;
            pnt->VelAbs = TrjTrgt->Pnts[i].VelAbs;
        }
        CMNode.Trajectory.Vis.nPnts = TrjTrgt->nPnts;
    } else {
        int j = 0;
        int deltaN = TrjTrgt->nPnts / TRAJECTORY_MAX_VIS_PNTS;
        for (int i = 0; i < TRAJECTORY_MAX_VIS_PNTS - 1; i++) {
            pnt = &CMNode.Trajectory.Vis.Pnts[i];

            pnt->Time = TrjTrgt->Pnts[j].Time;
            pnt->Pos[0] = TrjTrgt->Pnts[j].Pos[0];
            pnt->Pos[1] = TrjTrgt->Pnts[j].Pos[1];
            pnt->Pos[2] = TrjTrgt->Pnts[j].Pos[2];
            pnt->Yaw = TrjTrgt->Pnts[j].Yaw;
            pnt->VelAbs = TrjTrgt->Pnts[j].VelAbs;

            j += deltaN;
        }
        // last point
        pnt = &CMNode.Trajectory.Vis.Pnts[TRAJECTORY_MAX_VIS_PNTS - 1];
        pnt->Time = TrjTrgt->Pnts[TrjTrgt->nPnts - 1].Time;
        pnt->Pos[0] = TrjTrgt->Pnts[TrjTrgt->nPnts - 1].Pos[0];
        pnt->Pos[1] = TrjTrgt->Pnts[TrjTrgt->nPnts - 1].Pos[1];
        pnt->Pos[2] = TrjTrgt->Pnts[TrjTrgt->nPnts - 1].Pos[2];
        pnt->Yaw = TrjTrgt->Pnts[TrjTrgt->nPnts - 1].Yaw;
        pnt->VelAbs = TrjTrgt->Pnts[TrjTrgt->nPnts - 1].VelAbs;

        CMNode.Trajectory.Vis.nPnts = TRAJECTORY_MAX_VIS_PNTS;
    }

    return DrvTrj_TrjState_Updated;
}
#endif

/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Get versions from shared library
 * - Set the returned Version to 0 if there is no dependency!
 * - Compatibility check should be done by calling procedure
 *   as early as possible(e.g. before CMRosIF_CMNode_Init()
 *
 * Arguments:
 * - CMRosIFVer = CMRosIF shared library version (User defined)
 *                - Initially filled with version of CMRosIF management library
 * - CMNumVer   = CarMaker version used for shared library at compile time (normally CM_NUMVER)
 *                - Initially filled with version of CMRosIF management library
 * - RosVersion = ROS version used for shared library at compile time (normally ROS_VERSION)
 *                - Initially filled with version requested by CMRosIF management library (0 if no request)
 *
 */
int CMRosIF_CMNode_GetVersion(unsigned long *CMRosIFCMNodeNumVer, unsigned long *CMNumVer, unsigned long *RosNumVer) {

    *CMRosIFCMNodeNumVer = CMNODE_NUMVER;
    *CMNumVer = CM_NUMVER;
    *RosNumVer = ROS_VERSION;

    return 0;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Basic Initialization
 * - e.g. create ROS Node, subscriptions, ...
 * - Return values
 *   - "rv <  0" = Error at initialization, CarMaker executable will stop
 *   - "rv >= 0" = Everything OK, CarMaker executable will continue
 *
 * Arguments:
 * - Argc/Argv  = Arguments normally provided to ROS executable are not be provided
 *                to CM executable directly, but can be set in Infofile for CMRosIF
 *                with key "Node.Args" in "Data/Config/CMRosIFParameters"
 *
 * - CMNodeName = Default CarMaker Node name
 *                - Can be parameterized in Infofile for CMRosIF
 *                - Final node name might be different (argument remapping, ...)
 *
 * - Inf        = Handle to CarMaker Infofile with parameters for this interface
 *                - Please note that pointer may change, e.g. before TestRun begins
 *
 * ToDo:
 * - Possible to create/initialize node/... before each TestRun start instead of CM startup?
 * - New Param_Get() function to read parameters from Infofile
 */
int CMRosIF_CMNode_Init(int Argc, char **Argv, char *CMNodeName, struct tInfos *Inf) {

    int rv;
    bool rvb = false;
    char sbuf[512] = "";
    char keybuf[256] = "";
    ros::NodeHandlePtr node = NULL;
    ros::V_string names;


    LOG("Initialize CarMaker ROS Node");
    LOG("  -> Node Version = %05d", CMNODE_NUMVER);
    LOG("  -> ROS Version  = %05d", ROS_VERSION);
    LOG("  -> CM Version   = %05d", CM_NUMVER);

    /* ROS initialization. Name of Node might be different after remapping! */
    if (ros::isInitialized() == false) {
        /* "Remapping arguments" functionality (launchfiles, ...)? */
        ros::init(Argc, Argv, CMNodeName);
    } else {
        // node.reset(); ToDo!
    }

    if (ros::master::check() == false) {
        LogErrF(EC_Init, "Can't contact ROS Master!\n Start roscore or run launch file e.g. via Extras->CMRosIF\n");
        ros::shutdown();
        return -1;
    }

    /* Node specific */
    CMNode.Cfg.Ros.Node = ros::NodeHandlePtr(boost::make_shared<ros::NodeHandle>());
    node = CMNode.Cfg.Ros.Node;

    /* Publish specific */
    CMNode.Cfg.QueuePub = iGetIntOpt(Inf, "Node.QueuePub", 1000); /* ToDo: Influence of queue length relevant? */

    /* Prepare the node to provide simulation time. CarMaker will be /clock server */
    strcpy(sbuf, "/use_sim_time");

    if ((rv = node->hasParam(sbuf)) == true) {
        node->getParam(sbuf, rvb);
        LOG("  -> Has param '%s' with value '%d'", sbuf, rvb);
    }

    /* Additional switch to provide simulation Time */
    strcpy(keybuf, "Node.UseSimTime");

    if ((rv = iGetIntOpt(Inf, keybuf, 1)) > 0) {
        /* Parameter must be set before other nodes start
         * - set parameter outside to be independent from execution order?
         */
        LOG("  -> Provide simulation time!");
        node->setParam("/use_sim_time", true); /* enable parameter if not already done */

        CMNode.Cfg.nCyclesClock = iGetIntOpt(Inf, "Node.nCyclesClock", 10);

        strcpy(sbuf, "/clock");
        LOG("    -> Publish '%s' every %dms", sbuf, CMNode.Cfg.nCyclesClock);
        CMNode.Topics.Pub.Clock.Pub = node->advertise<rosgraph_msgs::Clock>(sbuf, CMNode.Cfg.QueuePub);


        /* ToDo: Necessary/Possible to ensure /clock is zeroed? */
        CMNode.Topics.Pub.Clock.Msg.clock = ros::Time(0.0);
        CMNode.Topics.Pub.Clock.Pub.publish(CMNode.Topics.Pub.Clock.Msg);
    } else {
        LOG("  -> Don't provide simulation time!");
        CMNode.Cfg.nCyclesClock = 0;
    }

    strcpy(sbuf, hellocm::tpc_in_name.c_str() /*! Opposite in/out compared to external node */);
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.CM2Ext.Pub = node->advertise<hellocm_msgs::CM2Ext>(sbuf, CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.CM2Ext.Job = CMCRJob_Create(sbuf);
    CMNode.Topics.Pub.CM2Ext.CycleTime = 50;
    CMNode.Topics.Pub.CM2Ext.CycleOffset = 0;

    strcpy(sbuf, "trj_out");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.TrjOut.Pub = node->advertise<oadf_msgs::IPGDriverTrajectory>(sbuf, CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.TrjOut.Job = CMCRJob_Create(sbuf);
    CMNode.Topics.Pub.TrjOut.CycleTime = 50;
    CMNode.Topics.Pub.TrjOut.CycleOffset = 0;
    CMNode.Topics.Pub.TrjOut.Msg.poses.clear();
    CMNode.Topics.Pub.TrjOut.Msg.poses.reserve(CMNode.Trajectory.size);

/*    CMNode.Topics.Pub.MotionStatePub.Pub =
        node->advertise<automated_driving_msgs::MotionState>("motion_state", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.MotionStatePub.Job = CMCRJob_Create("MotionState");
    CMNode.Topics.Pub.MotionStatePub.CycleTime = 50;
    CMNode.Topics.Pub.MotionStatePub.CycleOffset = 0;*/

    /*CMNode.Topics.Pub.Objects.Pub =
        node->advertise<automated_driving_msgs::ObjectStateArray>("objects", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.Objects.Job = CMCRJob_Create("Objects");
    CMNode.Topics.Pub.Objects.CycleTime = 50;
    CMNode.Topics.Pub.Objects.CycleOffset = 0;

    CMNode.Topics.Pub.Static_Objects.Pub =
        node->advertise<automated_driving_msgs::ObjectStateArray>("static_objects", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.Static_Objects.Job = CMCRJob_Create("Static_Objects");
    CMNode.Topics.Pub.Static_Objects.CycleTime = 50;
    CMNode.Topics.Pub.Static_Objects.CycleOffset = 0;*/

/*    CMNode.Topics.Pub.Tf.Pub = node->advertise<tf2_msgs::TFMessage>("tf", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.Tf.Job = CMCRJob_Create("Tf");
    CMNode.Topics.Pub.Tf.CycleTime = 50;
    CMNode.Topics.Pub.Tf.CycleOffset = 0;*/

    CMNode.Topics.Pub.LidarPub0.Pub = node->advertise<sensor_msgs::PointCloud2>("lidar0", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.LidarPub0.Job = CMCRJob_Create("Lidar");
    CMNode.Topics.Pub.LidarPub0.CycleTime = 50;
    CMNode.Topics.Pub.LidarPub0.CycleOffset = 0;

    CMNode.Topics.Pub.LidarPub1.Pub = node->advertise<sensor_msgs::PointCloud2>("lidar1", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.LidarPub1.Job = CMCRJob_Create("Lidar");
    CMNode.Topics.Pub.LidarPub1.CycleTime = 50;
    CMNode.Topics.Pub.LidarPub1.CycleOffset = 0;

    CMNode.Topics.Pub.LidarPub2.Pub = node->advertise<sensor_msgs::PointCloud2>("lidar2", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.LidarPub2.Job = CMCRJob_Create("Lidar");
    CMNode.Topics.Pub.LidarPub2.CycleTime = 50;
    CMNode.Topics.Pub.LidarPub2.CycleOffset = 0;

    CMNode.Topics.Pub.LidarPub3.Pub = node->advertise<sensor_msgs::PointCloud2>("lidar3", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.LidarPub3.Job = CMCRJob_Create("Lidar");
    CMNode.Topics.Pub.LidarPub3.CycleTime = 50;
    CMNode.Topics.Pub.LidarPub3.CycleOffset = 0;

    CMNode.Topics.Pub.VehiclePub.Pub = node->advertise<oadf_msgs::Vehicle>("vehicle", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.VehiclePub.Job = CMCRJob_Create("Vehicle");
    CMNode.Topics.Pub.VehiclePub.CycleTime = 50;
    CMNode.Topics.Pub.VehiclePub.CycleOffset = 0;

    CMNode.Topics.Pub.StaticPub.Pub = node->advertise<oadf_msgs::Obstacle_CarMaker_Array>(
            "static_obstacles_carmaker", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.StaticPub.Job = CMCRJob_Create("Static_Obstacles");
    CMNode.Topics.Pub.StaticPub.CycleTime = 50;
    CMNode.Topics.Pub.StaticPub.CycleOffset = 0;

    CMNode.Topics.Pub.DynamicPub.Pub = node->advertise<oadf_msgs::Obstacle_CarMaker_Array>(
            "dynamic_obstacles_carmaker", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.DynamicPub.Job = CMCRJob_Create("Dynamic_Obstacles");
    CMNode.Topics.Pub.DynamicPub.CycleTime = 50;
    CMNode.Topics.Pub.DynamicPub.CycleOffset = 0;

    CMNode.Topics.Pub.GPSDatePub.Pub = node->advertise<oadf_msgs::GPSDate>("GPSDate", CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.GPSDatePub.Job = CMCRJob_Create("GPSDate");
    CMNode.Topics.Pub.GPSDatePub.CycleTime = 50;
    CMNode.Topics.Pub.GPSDatePub.CycleOffset = 0;

    /* Subscribe specific */
    CMNode.Cfg.QueueSub = iGetIntOpt(Inf, "Node.QueueSub", 1); /* ToDo: Effect of queue length for subscriber? */


    strcpy(sbuf, hellocm::tpc_out_name.c_str() /*! Opposite in/out compared to external node */);
    LOG("  -> Subscribe '%s'", sbuf);
    CMNode.Topics.Sub.Ext2CM.Sub = node->subscribe(sbuf, CMNode.Cfg.QueueSub, cmnode_HelloCM_CB_TpcIn);
    CMNode.Topics.Sub.Ext2CM.Job = CMCRJob_Create("Ext2CM_for_Sync");

    /* In this example cycle time might be updated with value of external ROS Node
     * - See CMRosIF_CMNode_TestRun_Start_atBegin() */
    CMNode.Topics.Sub.Ext2CM.CycleTime = 15000;


    strcpy(sbuf, "trj_in" /*! Opposite in/out compared to external node */);
    LOG("  -> Subscribe '%s'", sbuf);
    CMNode.Topics.Sub.TrjIn.Sub = node->subscribe(sbuf, CMNode.Cfg.QueueSub, cmnode_HelloCM_CB_TrjIn);
    CMNode.Topics.Sub.TrjDarm.Sub = node->subscribe("/trajGCS", CMNode.Cfg.QueueSub,
                                                    cmnode_HelloCM_CB_TrjDarm);
    CMNode.Topics.Sub.TrjSafeDarm.Sub = node->subscribe("/pathGCS", CMNode.Cfg.QueueSub,
                                                        cmnode_HelloCM_CB_TrjSafeDarm);
    CMNode.Topics.Sub.TrjIn.Job = CMCRJob_Create(sbuf);
    CMNode.Topics.Sub.TrjDarm.Job = CMCRJob_Create("/trajGCS");
    CMNode.Topics.Sub.TrjSafeDarm.Job = CMCRJob_Create("/pathGCS");
    CMNode.Topics.Sub.TrjIn.CycleTime = 500;
    CMNode.Topics.Sub.TrjDarm.CycleTime = 500;
    CMNode.Topics.Sub.TrjSafeDarm.CycleTime = 500;
    CMNode.Topics.Sub.TrjIn.Msg.poses.clear();
    CMNode.Topics.Sub.TrjIn.Msg.poses.reserve(CMNode.Trajectory.size);

    /* Services */
    strcpy(sbuf, hellocm::srv_init_name.c_str());
    LOG("  -> Service Client '%s'", sbuf);
    CMNode.Services.Init.Clnt = node->serviceClient<hellocm_msgs::Init>(sbuf);


    strcpy(sbuf, "CMRemote");
    LOG("  -> Create Service '%s'", sbuf);
    CMNode.Services.CMRemote.Srv = node->advertiseService(sbuf, cmnode_HelloCM_CB_SrvCMRemote);


    /* Print general information after everything is done */
    LOG("Initialization of ROS Node finished!");
    LOG("  -> Node Name = '%s'", ros::this_node::getName().c_str());
    LOG("  -> Namespace = '%s'", ros::this_node::getNamespace().c_str());


    /* Advertised Topics */
    ros::this_node::getAdvertisedTopics(names);
    LOG("  -> Advertised Topics (%lu)", names.size());

    auto it = names.begin();
    for (; it != names.end(); ++it)
        LOG("    -> %s", (*it).c_str());


    /* Subscribed Topics */
    names.clear();
    ros::this_node::getSubscribedTopics(names);
    LOG("  -> Subscribed Topics (%lu)", names.size());
    it = names.begin();
    for (; it != names.end(); ++it)
        LOG("    -> %s", (*it).c_str());


#if defined(CUSTOM_DRIVER_TRAJECTORY)
    /* Set the callback functions for Trajectory Module*/
    DrvTrj_GetTrajectory = &usertrj_GetTrajectory; /* (required) */
    LOG("set: DrvTrj_GetTrajectory = &usertrj_GetTrajectory");
#endif

/*	C = proj_context_create();
	P = proj_create_crs_to_crs (C,
                            "EPSG:4326",
                            "+proj=tmerc +a=6378137 +b=6378137 +lon_0=6.1220672108322036 +x_0=-0 +y_0=-5657021.5228711963 +k=1.0 +units=m +nadgrids=@null +wktext +no_defs",
                            NULL);*/

    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Add user specific Quantities for data storage
 *   and visualization to DataDictionary
 * - Called once at program start
 * - no realtime conditions
 *
 */
void CMRosIF_CMNode_DeclQuants(void) {

    tDDefault *df = DDefaultCreate("CMRosIF.");

    DDefULong(df, "CycleNoRel", "ms", &CMNode.CycleNoRel, DVA_None);
    DDefInt(df, "Sync.Cycles", "-", &CMNode.Sync.nCycles, DVA_None);
    DDefDouble(df, "Sync.Time", "s", &CMNode.Sync.Duration, DVA_None);
    DDefInt(df, "Sync.CyclePrepDone", "-", &CMNode.Sync.CyclePrepDone, DVA_None);
    DDefInt(df, "Sync.CycleJobDone", "-", &CMNode.Sync.CycleJobDone, DVA_None);
    DDefDouble4(df, "Sync.SynthDelay", "s", &CMNode.Sync.SynthDelay, DVA_IO_In);

    DDefUChar(df, "Cfg.Mode", "-", (unsigned char *) &CMNode.Cfg.Mode, DVA_None);
    DDefInt(df, "Cfg.nCyclesClock", "ms", &CMNode.Cfg.nCyclesClock, DVA_None);
    DDefChar(df, "Cfg.SyncMode", "-", (char *) &CMNode.Cfg.SyncMode, DVA_None);
    DDefDouble4(df, "Cfg.SyncTimeMax", "s", &CMNode.Cfg.SyncTimeMax, DVA_IO_In);

    DDefInt(df, "Mdl.CycleNo", "-", &CMNode.Model.CycleNo, DVA_None);
    DDefInt(df, "Mdl.CycleLastOut", "ms", &CMNode.Model.CycleLastOut, DVA_None);
    DDefInt(df, "Mdl.CycleLastIn", "ms", &CMNode.Model.CycleLastIn, DVA_None);
    DDefInt(df, "Mdl.CycleLastFlush", "ms", &CMNode.Model.CycleLastFlush, DVA_None);


#if defined(CUSTOM_DRIVER_TRAJECTORY)
    /* Create UAQs for visualization in IPGMovie */
    tDrvTrj_Pnt* pnt;

    const char* prefix = "DrvTrj.User";
    DDefPrefix(df, "%s.VisPnts.", prefix);
    DDefInt(df, "n", "-", &CMNode.Trajectory.Vis.nPnts, DVA_DM);

    for (int i = 0; i < TRAJECTORY_MAX_VIS_PNTS; i++) {
        pnt = &CMNode.Trajectory.Vis.Pnts[i];

        DDefPrefix(df, "%s.VisPnts.%02d.", prefix, i);

        DDefDouble(df, "x", "m", &pnt->Pos[0], DVA_None);
        DDefDouble(df, "y", "m", &pnt->Pos[1], DVA_None);
        DDefDouble(df, "z", "m", &pnt->Pos[2], DVA_None);
        DDefDouble(df, "Time", "s", &pnt->Time, DVA_None);
        DDefDouble(df, "VelAbs", "m/s", &pnt->VelAbs, DVA_None);
        DDefDouble(df, "Yaw", "rad", &pnt->Yaw, DVA_None);
    }
#endif

    DDefaultDelete(df);
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called when starting a new TestRun
 * - In separate Thread (no realtime conditions)
 * - After standard Infofiles are read in
 * - Return values
 *   - "rv <  0" = Error, TestRun start will be aborted
 *   - "rv >= 0" = Everything OK
 *
 * Arguments:
 * - Inf = CarMaker Infofile for CMRosIF with content after TestRun start
 *         - Please note that the Infofile provided at initialization might have been updated!
 *
 * ToDo:
 * - New Param_Get() function to read parameters from Infofile
 *
 */
int CMRosIF_CMNode_TestRun_Start_atBegin(struct tInfos *Inf) {

    /* Node can be disabled via Infofile */
    tCMNode_Mode *pmode = &CMNode.Cfg.Mode;
    tCMNode_SyncMode *psyncmode = &CMNode.Cfg.SyncMode;

    if (Inf != NULL) {
        *pmode = (tCMNode_Mode) iGetIntOpt(Inf, "Node.Mode", CMNode_Mode_Disabled);
        *psyncmode = (tCMNode_SyncMode) iGetIntOpt(Inf, "Node.Sync.Mode", CMNode_SyncMode_Disabled);
    }

    if (SimCore.CycleNo == 0 || Inf == NULL || *pmode == CMNode_Mode_Disabled) {
        *pmode = CMNode_Mode_Disabled;
        LOG("CarMaker ROS Node is disabled!");
        return 0;
    }

    char sbuf[512];
    char key[256];
    char *str = NULL;
    int rv = 0;
    bool rvb = false;

    int cycletime = 0;
    int *pcycletime = NULL;
    int cycleoff = 0;
    tCMCRJob *job = NULL;
    auto srv = &CMNode.Services.Init;

    LOG("CarMaker ROS Node is enabled! Mode=%d, SyncMode=%d", *pmode, *psyncmode);
    LOG("  -> Node Name = %s", ros::this_node::getName().c_str());


    /* Update synchronization */
    if (*psyncmode != CMNode_SyncMode_Disabled && *psyncmode != CMNode_SyncMode_Tpc) {
        LogErrF(EC_Sim, "CMNode: Invalid synchronization mode '%d'!", *psyncmode);
        *pmode = CMNode_Mode_Disabled;
        return -1;
    }

    CMNode.Cfg.SyncTimeMax = iGetDblOpt(Inf, "Node.Sync.TimeMax", 1.0);


    /* Reset for next cycle */
    CMNode.CycleNoRel = 0;
    CMNode.Sync.Duration = 0.0;
    CMNode.Sync.nCycles = -1;
    CMNode.Sync.CycleJobDone = -1;
    CMNode.Sync.CyclePrepDone = -1;
    CMNode.Model.CycleNo = -1;
    CMNode.Model.CycleLastIn = -1;
    CMNode.Model.CycleLastOut = -1;
    CMNode.Model.CycleLastFlush = -1;


    /* Allow an update of the clock only if it was enabled before! */
    if (CMNode.Cfg.nCyclesClock > 0) {
        if ((rv = iGetIntOpt(Inf, "Node.nCyclesClock", 1000)) > 0)
            CMNode.Cfg.nCyclesClock = rv;
    }

    /* Necessary to ensure /clock is zeroed here?
     * ToDo: Create function? */
    if (CMNode.Cfg.nCyclesClock > 0) {
        LOG("  -> Publish /clock every %dms", CMNode.Cfg.nCyclesClock);
        CMNode.Topics.Pub.Clock.Msg.clock = ros::Time(0.0);
        CMNode.Topics.Pub.Clock.Pub.publish(CMNode.Topics.Pub.Clock.Msg);
    }


    /* Prepare external node for next simulation */
    if (!srv->Clnt.exists()) {
        // ToDo: possible to get update if external ROS Node name changes?
        LogErrF(EC_Sim,
                "ROS Service is not ready! Please start external ROS Node providing Service '%s'!",
                srv->Clnt.getService().c_str());
        *pmode = CMNode_Mode_Disabled;
        return -1;
    }

    LOG("  -> Send Service Request");

    /* ToDo: Async?*/
    if (!srv->Clnt.call(srv->Msg)) {
        LogErrF(EC_Sim, "ROS Service error!");
        *pmode = CMNode_Mode_Disabled;
        return -1;
    }

    /* Update cycle time with information of external node */
#if 1
    /* Variant 1:
     * - Receiving parameters via ROS Parameter Server
     * - Parameter may be set externally e.g. by other node or arguments to command
     * - ROS parameters are more flexible than ROS services!
     */
    strcpy(sbuf, hellocm::prm_cycletime_name.c_str());
    if ((rv = CMNode.Cfg.Ros.Node->hasParam(sbuf)) == true) {
        CMNode.Cfg.Ros.Node->getParam(sbuf, rv);
    }
#else
    /* Variant 2:
     * - Receiving parameters from external Node via Service
     * - Services might be too "static"
     * - Not recommended!
     */
    rv = srv->Msg.response.cycletime;
#endif

    pcycletime = &CMNode.Topics.Sub.Ext2CM.CycleTime;

    if (*pcycletime != rv) {
        LOG("  -> Cycle time of external node changed from %dms to %dms", *pcycletime, rv);
        *pcycletime = rv;
    }


    /* Plausibility check for Cycle Time */
    if (CMNode.Cfg.nCyclesClock > 0 &&
        (*pcycletime < CMNode.Cfg.nCyclesClock || *pcycletime % CMNode.Cfg.nCyclesClock != 0)) {

        LogErrF(EC_Sim,
                "Ext. ROS Node has invalid cycle time! Expected multiple of %dms but got %dms",
                CMNode.Cfg.nCyclesClock,
                *pcycletime);

        *pmode = CMNode_Mode_Disabled;
        return -1;
    }


    /* Prepare Jobs for publish and subscribe
     * - Special use case:
     *   - Topic in and Topic out use same cycle time with relative shift!
     */

    /* Start to publish when simulation starts */
    job = CMNode.Topics.Pub.CM2Ext.Job;
    cycletime = CMNode.Topics.Pub.CM2Ext.CycleTime;
    cycleoff = CMNode.Topics.Pub.CM2Ext.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Default);

    //    job       = CMNode.Topics.Pub.TrjOut.Job;
    //    cycletime = CMNode.Topics.Pub.TrjOut.CycleTime;
    //    cycleoff  = CMNode.Topics.Pub.TrjOut.CycleOffset;

    //    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Default);


    /* Synchronization with external node
     * - external node provides cycle time (see service above)
     * - other parameterization methods (e.g. ROS parameter, ...) are possible!
     * - Expect sync Topic are delayed (communication time, ...)
     * - This example shows sync via ROS Timer in external node
     *   - Therefore "/clock" topic needs to be published by CarMaker!
     *   - Other mechanism, e.g. data triggered on external node side
     *     via publishing Topic directly inside subscription callback is also possible!
     * - time=0.0 can't be detected by external node, therefore
     *   first receive needs to start after expected cycle time
     *   of external ROS node
     */

    job = CMNode.Topics.Sub.Ext2CM.Job;
    cycletime = CMNode.Topics.Sub.Ext2CM.CycleTime;
    cycleoff = CMNode.Topics.Sub.Ext2CM.CycleOffset = 0; /* No offset allowed if ROS Timer is used for sync!*/

    /* Create the synchronization jobs */
    if (*psyncmode == CMNode_SyncMode_Tpc) {
        CMCRJob_Init(job, cycletime + 1, cycletime, CMCRJob_Mode_Ext);

        LOG("  -> Synchronize on Topic '%s' (cycletime=%d, cycleoff=%d)",
            CMNode.Topics.Sub.Ext2CM.Sub.getTopic().c_str(),
            cycletime,
            cycleoff);

    } else
        CMCRJob_Init(job, cycletime + 1, cycletime, CMCRJob_Mode_Default);


    job = CMNode.Topics.Sub.TrjIn.Job;
    cycletime = CMNode.Topics.Sub.TrjIn.CycleTime;
    cycleoff = CMNode.Topics.Sub.TrjIn.CycleOffset = 0; /* No offset allowed if ROS Timer is used for sync!*/
    CMCRJob_Init(job, cycletime + 1, cycletime, CMCRJob_Mode_Default);

    job = CMNode.Topics.Sub.TrjDarm.Job;
    cycletime = CMNode.Topics.Sub.TrjDarm.CycleTime;
    cycleoff = CMNode.Topics.Sub.TrjDarm.CycleOffset = 0; /* No offset allowed if ROS Timer is used for sync!*/
    CMCRJob_Init(job, cycletime + 1, cycletime, CMCRJob_Mode_Default);

    job = CMNode.Topics.Sub.TrjSafeDarm.Job;
    cycletime = CMNode.Topics.Sub.TrjSafeDarm.CycleTime;
    cycleoff = CMNode.Topics.Sub.TrjSafeDarm.CycleOffset = 0; /* No offset allowed if ROS Timer is used for sync!*/
    CMCRJob_Init(job, cycletime + 1, cycletime, CMCRJob_Mode_Default);
    LOG("External ROS Node is ready to simulate");

/*    tInfos* Inf_Vehicle = nullptr;
    Inf_Vehicle = InfoNew();

    const char* FName;
    FName = InfoGetFilename(SimCore.Vhcl.Inf);
    std::cout << FName << std::endl;
    tErrorMsg* err;
    int VehicleInfo_Err = iRead2(&err, Inf_Vehicle, FName, "SensorReadCode");
    std::cout << LidarRSICount << std::endl;
    if (VehicleInfo_Err == 0) {
	std::cout << "No error" << std::endl;
        if (LidarRSICount > 0) {
	    std::cout << "Hay lidar" << std::endl;
            position = iGetFixedTable2(Inf_Vehicle, "Sensor.LidarRSI.0.pos", 3, 1);
            rotation = iGetFixedTable2(Inf_Vehicle, "Sensor.LidarRSI.0.rot", 3, 1);
//	    auto filename = iGetFixedTable2(Inf_Vehicle, "Sensor.LidarRSI.0.BeamsFName");
        }
    }

//    std::cout << position[0] << std::endl;

    InfoDelete(Inf_Vehicle);*/

    return 1;
}


/*!
 * ToDo:
 * - Put everything to TestRun_Start_atBegin?
 *
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Repeating call for several CarMaker cycles until return value is 1
 * - May be called even previous return value was 1
 * - See "User.c:User_TestRun_RampUp()"
 *
 */
int CMRosIF_CMNode_TestRun_RampUp(void) {

    /* Return immediately if node is disabled */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
        return 1;

    /* Put your code here */
    // if (NotReady) return 0;


    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called when TestRun ends (no realtime conditions)
 * - See "User.c:User_TestRun_End()"
 *
 */
int CMRosIF_CMNode_TestRun_End(void) {


    /* Put your code here */

    /* Disable after simulation has finished */
    CMNode.Cfg.Mode = CMNode_Mode_Disabled;

    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called at very beginning of CarMaker cycle
 * - Process all topics/services using different modes or synchronization modes
 * - See "User.c:User_In()"
 *
 * ToDo:
 * - Additional spin mechanism
 *   - e.g. for HIL
 *   - e.g. spinning in new thread, copying incoming data here, ...
 *
 */
int CMRosIF_CMNode_In(void) {

    int rv = 0;
    int rx_done = 0;
    const char *job_name = NULL;
    tCMCRJob *job = NULL;
    ros::WallTime tStart = ros::WallTime::now();
    ros::WallDuration tDelta = ros::WallDuration(0.0);
    CMNode.Sync.nCycles = 0;
    CMNode.Sync.Duration = 0.0;

    switch (CMNode.Cfg.Mode) {
        case CMNode_Mode_Disabled:
            /* Comment next line if no messages/services
             * shall be processed in disabled Node state
             */
            ros::spinOnce();
            break;

        case CMNode_Mode_Default:

            if (CMNode.Cfg.SyncMode != CMNode_SyncMode_Tpc) {
                /* Process messages in queue, but do not block */
                ros::spinOnce();

            } else {
                /* Synchronization based on expected Topics
                 * - Blocking call (process publish and wait for answer)
                 * - Stop simulation if maximum time is exceeded
                 */
                do {
                    ros::spinOnce();

                    /* Only do anything if simulation is running */
                    if (SimCore.State != SCState_Simulate) {
                        rx_done = 1;
                        break;
                    }

                    rx_done = 0;

                    /* Check all jobs if preparation is done */
                    job = CMNode.Topics.Sub.Ext2CM.Job;

                    if ((rv = CMCRJob_DoPrep(job, CMNode.CycleNoRel, 0, NULL, NULL)) < CMCRJob_RV_OK) {
                        LogErrF(
                                EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(job),
                                CMCRJob_RVStr(rv));
                        rx_done = 0;
                        break;
                    }

                    /* If job is not done, remember name and prevent loop to finish */
                    job_name = (rv != CMCRJob_RV_DoSomething ? NULL : CMCRJob_GetName(job));
                    rx_done = rv == CMCRJob_RV_DoNothing ? 1 : 0;

                    if (rx_done == 1)
                        break;

                    /* Wait a little that data can arrive. WallTime, NOT ROS time!!!*/
                    ros::WallDuration(0.0).sleep();
                    tDelta = ros::WallTime::now() - tStart;
                    CMNode.Sync.nCycles++;

                } while (ros::ok() && rx_done == 0 && tDelta.toSec() < CMNode.Cfg.SyncTimeMax);

                /* Final calculation to get duration including last cycle before receive */
                tDelta = ros::WallTime::now() - tStart;

                CMNode.Sync.Duration = tDelta.toSec();

                if (rx_done != 1 && CMNode.Cfg.SyncTimeMax > 0.0 && tDelta.toSec() >= CMNode.Cfg.SyncTimeMax)
                    LogErrF(EC_Sim,
                            "CMNode: Synchronization error! tDelta=%.3f, Last invalid Job='%s'\n",
                            tDelta.toSec(),
                            job_name);
            }

            break;

        case CMNode_Mode_Threaded:
            /* ToDo
             * - Spinning in parallel thread started before
             * - Lock variables!
             * - e.g. for HIL
             */
            break;

        default:
            /* Invalid!!! */;
    }

    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called after driving maneuver calculation
 * - before CMRosIF_CMNode_VehicleControl_Calc()
 * - See "User.c:User_DrivManCalc()"
 */
int CMRosIF_CMNode_DrivMan_Calc(double dt) {
    /* Only do something if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled || SimCore.State != SCState_Simulate)
        return 0;

    /* Put your code here */

    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called after CMRosIF_CMNode_DrivManCalc
 * - before CMRosIF_CMNode_VehicleControl_Calc()
 * - See "User.c:User_VehicleControl_Calc()"
 */
int CMRosIF_CMNode_VehicleControl_Calc(double dt) {
    /* Only do something if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled || SimCore.State != SCState_Simulate)
        return 0;

    /* Put your code here */
    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called after vehicle model has been calculated
 * - See "User.c:User_Calc()"
 */
int CMRosIF_CMNode_Calc(double dt) {

    /* Only do something if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled || SimCore.State != SCState_Simulate)
        return 0;

    /* Put your code here
     * - Update model parameters here?
     * - Do some calculation...
     */

    /* Update model with values from external node only in specific cycle?
     * - This data handling is optionl, but necessary for deterministic behaviour
     * - if synchronization is active, incoming data remains in msg buffer until correct cycle
     */
    int rv;
    auto sync = &CMNode.Topics.Sub.Ext2CM;

    if ((rv = CMCRJob_DoJob(sync->Job, CMNode.CycleNoRel, 1, NULL, NULL)) != CMCRJob_RV_DoNothing &&
        rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s", CMCRJob_GetName(sync->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
        /* Something to do in sync cycle? */
        // CMCRJob_Info(in->Job, CMNode.CycleNoRel, "CMNode: Do Something for Sync: ");

        /* Update model parameters here? */
        // CMNode.Model.CycleNo = CMNode.Topics.Sub.Ext2CM.Msg.cycleno;


        /* Remember cycle for debugging */
        CMNode.Sync.CycleJobDone = CMNode.CycleNoRel;
        CMNode.Model.CycleLastFlush = CMNode.CycleNoRel;
    }

    /* Do some calculation... */

    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called close to end of CarMaker cycle
 * - See "User.c:User_Out()"
 */
int CMRosIF_CMNode_Out(void) {
    ros::WallTime wtime = ros::WallTime::now();
    ros::Time time = ros::Time(SimCore.Time);

    /* Only do anything if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled || SimCore.State != SCState_Simulate || time.toSec() == lastTime.toSec())
    {
	lastTime = time;
        return 0;
    }

    lastTime = time;
    int rv;
    auto out = &CMNode.Topics.Pub.CM2Ext;
    oadf_msgs::Vehicle VehicleMsg;
    VehicleMsg.header.stamp = time;
//    std::cout << Vehicle.PoI_Pos << std::endl;
    VehicleMsg.position.x = Vehicle.PoI_GCS.Lat * 180 / M_PI;
//    VehicleMsg.position.x = Vehicle.PoI_Pos[0];
//    VehicleMsg.position.y = Vehicle.PoI_Pos[1];
    VehicleMsg.position.y = Vehicle.PoI_GCS.Long * 180 / M_PI;
    VehicleMsg.position.z = Vehicle.PoI_Pos[2];
    VehicleMsg.position.roll = Vehicle.Roll;
    VehicleMsg.position.pitch = Vehicle.Pitch;
    VehicleMsg.position.yaw = Vehicle.Yaw;
    VehicleMsg.velx = Vehicle.PoI_Vel_1[0];
    VehicleMsg.vely = Vehicle.PoI_Vel_1[1];
    VehicleMsg.velz = Vehicle.PoI_Vel_1[2];
    VehicleMsg.accx = Vehicle.PoI_Acc_1[0];
    VehicleMsg.accy = Vehicle.PoI_Acc_1[1];
    VehicleMsg.accz = Vehicle.PoI_Acc_1[2];
    VehicleMsg.velyaw = Vehicle.YawRate;
    VehicleMsg.accyaw = Vehicle.YawAcc;

    oadf_msgs::Transformation Transform;
    Transform.header.stamp = time;
    Transform.header.frame_id = "Fr1A";
    Transform.child_frame_id = "Fr1";
    Transform.x = -Vehicle.Cfg.PoI_Pos_1[0];
    Transform.y = -Vehicle.Cfg.PoI_Pos_1[1];
    Transform.z = -Vehicle.Cfg.PoI_Pos_1[2];
    Transform.roll = 0;
    Transform.pitch = 0;
    Transform.yaw = 0;
    VehicleMsg.frames.push_back(Transform);

    Transform.header.stamp = time;
    Transform.header.frame_id = "vehicle";
    Transform.child_frame_id = "Fr1A";
    Transform.x = 0;
    Transform.y = 0;
    Transform.z = Vehicle.Cfg.PoI_Pos_1[2];
    Transform.roll = 0;
    Transform.pitch = 0;
    Transform.yaw = 0;
    VehicleMsg.frames.push_back(Transform);

    Transform.header.stamp = time;
    Transform.header.frame_id = "odom";
    Transform.child_frame_id = "map";
    Transform.x = 0;
    Transform.y = 0;
    Transform.z = 0;
    Transform.roll = 0;
    Transform.pitch = 0;
    Transform.yaw = 0;
    VehicleMsg.frames.push_back(Transform);



/*        transformStamped.header.stamp = time;
        transformStamped.header.frame_id = "Fr1A";
        transformStamped.child_frame_id = "Fr1";
        transformStamped.transform.translation.x = -Vehicle.Cfg.PoI_Pos_1[0];
        transformStamped.transform.translation.y = -Vehicle.Cfg.PoI_Pos_1[1];
        transformStamped.transform.translation.z = -Vehicle.Cfg.PoI_Pos_1[2];
        transformStamped.transform.rotation.x = 0;
        transformStamped.transform.rotation.y = 0;
        transformStamped.transform.rotation.z = 0;
        transformStamped.transform.rotation.w = 1.0;*/

/*        transformStamped.header.stamp = time;
        transformStamped.header.frame_id = "odom";
        transformStamped.child_frame_id = "vehicle";
        transformStamped.transform.translation.x = x;
        transformStamped.transform.translation.y = y;
	transformStamped.transform.translation.z = 0;
        transformStamped.transform.rotation.x = myQuaternion[0];
        transformStamped.transform.rotation.y = myQuaternion[1];
        transformStamped.transform.rotation.z = myQuaternion[2];
        transformStamped.transform.rotation.w = myQuaternion[3];
        transforms.transforms.push_back(transformStamped);*/





    /* Communicate to External ROS Node in this cycle?
     * - The job mechanism is optional and can be e.g. replaced by simple modulo on current cycle
     */
    if ((rv = CMCRJob_DoJob(out->Job, CMNode.CycleNoRel, 1, NULL, NULL)) != CMCRJob_RV_DoNothing &&
        rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s", CMCRJob_GetName(out->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {

        out->Msg.cycleno = CMNode.CycleNoRel;
        out->Msg.time = ros::Time(SimCore.Time);
        out->Msg.synthdelay = CMNode.Sync.SynthDelay;

        /* Header stamp and frame needs to be set manually! */

        /* provide system time close to data is sent */
        wtime = ros::WallTime::now();
//	out->Msg.header.stamp = time;
        out->Msg.header.stamp.sec = wtime.sec;
        out->Msg.header.stamp.nsec = wtime.nsec;

        out->Pub.publish(out->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;


        //lanelet::Origin origin{{48.4168779326184, 9.96278952297286, 0.}};
        /* lanelet::Origin origin{{50.817888965882858, 6.122067210832204, 0.}};
         automated_driving_msgs::ObjectStateArray objects;
         automated_driving_msgs::ObjectStateArray static_objects;

         auto gps = GNavSensor.Receiver;

         auto Lat = gps.UserPosLlhTsa[0] * 180 / M_PI;
         auto Lon = gps.UserPosLlhTsa[1] * 180 / M_PI;
         lanelet::projection::UtmProjector::Ptr projector = std::make_shared<lanelet::projection::UtmProjector>(origin);
         lanelet::GPSPoint gpspoint;
         gpspoint.lat = Vehicle.PoI_GCS.Lat * 180 / M_PI;
         gpspoint.lon = Vehicle.PoI_GCS.Long * 180 / M_PI;
 //        gpspoint.ele = Vehicle.PoI_Pos[2];
     gpspoint.ele = 0;

         Lat = gpspoint.lat;
         Lon = gpspoint.lon;

     B.enu.e = Vehicle.PoI_Pos[0];
     B.enu.n = Vehicle.PoI_Pos[1];
     B = proj_trans (P, PJ_INV, B);
 //	std::cout << "X Y" << Vehicle.PoI_Pos[0] << " -- " << Vehicle.PoI_Pos[1] << std::endl;
 //        std::cout << "GPS From CarMaker " << std::setprecision(15) << Vehicle.PoI_GCS.Lat * 180 / M_PI << "," << Vehicle.PoI_GCS.Long * 180 / M_PI << "," << Vehicle.PoI_Pos[2] << std::endl;
 //	std::cout << "LONGITUDE AFTER TRANSFORM " << B.lp.lam << "LATITUDE" << B.lp.phi << std::endl;
 //	std::cout << "X Y Blabla " << B.enu.e << " -- " << B.enu.n << std::endl;
         //Lat = B.lp.lam;
         //Lon = B.lp.phi;
 //        gpspoint.lat = Lat;
 //        gpspoint.lon = Lon;
         gpspoint.ele = Vehicle.PoI_Pos[2];
 //        std::cout << A << std::endl;


     B.lp.lam = Vehicle.PoI_GCS.Long;
     B.lp.phi = Vehicle.PoI_GCS.Lat;
     B.enu.n = 0;
     B.enu.e = 0;
     auto a = proj_coord (Vehicle.PoI_GCS.Lat*180/M_PI, Vehicle.PoI_GCS.Long*180/M_PI, 0, 0);
     A = proj_trans(P,PJ_FWD, a);*/
//	std::cout << "X Y AFTER TRANSFORM" << A.enu.e << " -- " << A.enu.n << std::endl;
//	std::cout << "Supuesto lat lon" << a.lp.lam << " -- " << a.lp.phi  << std::endl;

        /*lanelet::BasicPoint3d point;
        try {
     //         std::cout << "GPS From CarMaker" << std::setprecision(15) << Vehicle.PoI_GCS.Lat * 180 / M_PI << "," << Vehicle.PoI_GCS.Long * 180 / M_PI << "," << Vehicle.PoI_Pos[2] << std::endl;
	  //  std::cout << "GPS From transform" << std::setprecision(15) << Lat << ", " << Lon << std::endl;
	  //  std::cout << std::setprecision(15) << "Vehicle in xy" << Vehicle.Fr1A.t_0[0] << "," << Vehicle.Fr1A.t_0[1] << std::endl;
            point = projector->forward(gpspoint);
        } catch (...) {
            std::cout << "Error in gps coordinates" << std::endl;
        }
	//std::cout << Vehicle.Yaw << std::endl;
	/** UNCOMMENT FOR MAP CONSTRUCTION **/
        /*auto x = gpspoint.lat;
            auto y = gpspoint.lon;
            auto z = Vehicle.PoI_Pos[2] - Vehicle.Cfg.PoI_Pos_1[2];*/
        /************************************/
        /** UNCOMMENT FOR NORMAL MODE **/
/*        auto x = point[0] - Vehicle.Cfg.PoI_Pos_1[0] * cos(Vehicle.Yaw);
        auto y = point[1] - Vehicle.Cfg.PoI_Pos_1[0] * sin(Vehicle.Yaw);*/
        /*auto x = point[0];
        auto y = point[1];

    //        auto z = Vehicle.PoI_Pos[2] - Vehicle.Cfg.PoI_Pos_1[2];
        auto z = 0;*/


//        auto motionState = &CMNode.Topics.Pub.MotionStatePub;
        /*motionState->Msg.header.stamp = time;

        motionState->Msg.header.frame_id = "odom";
        motionState->Msg.child_frame_id = "vehicle";

        motionState->Msg.pose.pose.position.x = x;
        motionState->Msg.pose.pose.position.y = y;
        motionState->Msg.pose.pose.position.z = z;

        tf2::Quaternion myQuaternion;
        myQuaternion.setRPY(Vehicle.Roll, Vehicle.Pitch, Vehicle.Yaw);

        motionState->Msg.pose.pose.orientation.x = myQuaternion[0];
        motionState->Msg.pose.pose.orientation.y = myQuaternion[1];
        motionState->Msg.pose.pose.orientation.z = myQuaternion[2];
        motionState->Msg.pose.pose.orientation.w = myQuaternion[3];

        motionState->Msg.twist.twist.linear.x = Vehicle.PoI_Vel_1[0];
        motionState->Msg.twist.twist.linear.y = Vehicle.PoI_Vel_1[1];
        motionState->Msg.twist.twist.linear.z = Vehicle.PoI_Vel_1[2];

        motionState->Msg.twist.twist.angular.z = Vehicle.YawRate;

        motionState->Msg.accel.accel.linear.x = Vehicle.PoI_Acc_1[0];
        motionState->Msg.accel.accel.linear.y = Vehicle.PoI_Acc_1[1];
        motionState->Msg.accel.accel.linear.z = Vehicle.PoI_Acc_1[2];

        motionState->Msg.accel.accel.angular.z = Vehicle.YawAcc;*/

        //motionState->Pub.publish(motionState->Msg);

        /* auto Tf = &CMNode.Topics.Pub.Tf;
         tf2_msgs::TFMessage transforms;
         geometry_msgs::TransformStamped transformStamped;

         transformStamped.header.stamp = time;
         transformStamped.header.frame_id = "odom";
         transformStamped.child_frame_id = "vehicle";
         transformStamped.transform.translation.x = x;
         transformStamped.transform.translation.y = y;
 //      transformStamped.transform.translation.z = z;
     transformStamped.transform.translation.z = 0;
         transformStamped.transform.rotation.x = myQuaternion[0];
         transformStamped.transform.rotation.y = myQuaternion[1];
         transformStamped.transform.rotation.z = myQuaternion[2];
         transformStamped.transform.rotation.w = myQuaternion[3];
         //transforms.transforms.push_back(transformStamped);

         transformStamped.header.stamp = time;
         transformStamped.header.frame_id = "Fr1A";
         transformStamped.child_frame_id = "Fr1";
         transformStamped.transform.translation.x = -Vehicle.Cfg.PoI_Pos_1[0];
         transformStamped.transform.translation.y = -Vehicle.Cfg.PoI_Pos_1[1];
         transformStamped.transform.translation.z = -Vehicle.Cfg.PoI_Pos_1[2];
         transformStamped.transform.rotation.x = 0;
         transformStamped.transform.rotation.y = 0;
         transformStamped.transform.rotation.z = 0;
         transformStamped.transform.rotation.w = 1.0;
         //transforms.transforms.push_back(transformStamped);

         transformStamped.header.stamp = time;
         transformStamped.header.frame_id = "vehicle";
         transformStamped.child_frame_id = "Fr1A";
         transformStamped.transform.translation.x = 0;
         transformStamped.transform.translation.y = 0;
         transformStamped.transform.translation.z = Vehicle.Cfg.PoI_Pos_1[2];
         transformStamped.transform.rotation.x = 0;
         transformStamped.transform.rotation.y = 0;
         transformStamped.transform.rotation.z = 0;
         transformStamped.transform.rotation.w = 1.0;
         //transforms.transforms.push_back(transformStamped);

         transformStamped.header.stamp = time;
         transformStamped.header.frame_id = "odom";
         transformStamped.child_frame_id = "map";
         transformStamped.transform.translation.x = 0;
         transformStamped.transform.translation.y = 0;
         transformStamped.transform.translation.z = 0;
         transformStamped.transform.rotation.x = 0;
         transformStamped.transform.rotation.y = 0;
         transformStamped.transform.rotation.z = 0;
         transformStamped.transform.rotation.w = 1.0;
         //transforms.transforms.push_back(transformStamped);*/

        oadf_msgs::Obstacle_CarMaker_Array static_obstacles_array;
        oadf_msgs::Obstacle_CarMaker_Array dynamic_obstacles_array;
        if (ObjectSensorCount > 0) {


            auto pOS = ObjectSensor_GetByIndex(0);

            for (int i = 0; i < pOS->nObsvObjects; i++) {

                auto obj = ObjectSensor_GetObjectByObjId(0, pOS->ObsvObjects[i]);
                auto traffic = Traffic_GetByObjId(obj->ObjId);
                oadf_msgs::Obstacle_CarMaker obstacle;
                obstacle.position.x = traffic->t_GCS.Lat * 180 / M_PI;
                obstacle.position.y = traffic->t_GCS.Long * 180 / M_PI;
                obstacle.position.z = traffic->t_0[2];
                obstacle.position.roll = traffic->r_zyx[0];
                obstacle.position.pitch = traffic->r_zyx[1];
                obstacle.position.yaw = traffic->r_zyx[2];
                obstacle.type = 4;
                obstacle.width = obj->w;
                obstacle.height = obj->h;
                obstacle.length = obj->l;
                obstacle.velx = traffic->LongVel;

                obstacle.position.header.stamp = time;
                obstacle.position.header.frame_id = "odom";
                obstacle.position.child_frame_id = std::to_string(obj->ObjId);

                obstacle.header.stamp = time;
                obstacle.header.frame_id = "odom";


/*                object.motion_state.header.stamp = time;
                object.motion_state.header.frame_id = "odom";
                object.motion_state.child_frame_id = std::to_string(i);*/

                if (traffic->Cfg.ObjectKind == 0) {
                    dynamic_obstacles_array.obstacles.push_back(obstacle);
                } else {
                    static_obstacles_array.obstacles.push_back(obstacle);
                }


                /*automated_driving_msgs::ObjectState object;
                object.object_id = obj->ObjId;
                //	std::cout << "Object id" << obj->ObjId << std::endl;
                //auto traffic = Traffic_GetByObjId(obj->ObjId);
                //	std::cout << "Traffic offset" << traffic->Cfg.lOff << std::endl;
                double dLat = traffic->t_GCS.Lat * 180 / M_PI;
                double dLon = traffic->t_GCS.Long * 180 / M_PI;

                lanelet::GPSPoint gpspoint;
                gpspoint.lat = traffic->t_GCS.Lat * 180 / M_PI;
                gpspoint.lon = traffic->t_GCS.Long * 180 / M_PI;
                gpspoint.ele = traffic->t_0[2];


                Lat = gpspoint.lat;
                Lon = gpspoint.lon;
                //	std::cout << gpspoint.lat << "," << gpspoint.lon << std::endl;
                //	std::cout << "Position" << traffic->t_0[0] << "," << traffic->t_0[1] << std::endl;

                lanelet::BasicPoint3d point;
                try {
                    // std::cout << Lat << "," << Lon << std::endl;
                    point = projector->forward(gpspoint);
                } catch (...) {
                    std::cout << "Error in gps coordinates" << std::endl;
                }
                auto x = point[0];
                auto y = point[1];
//                auto z = traffic->t_0[2];
		auto z = 0;

                tf2::Quaternion q;


                automated_driving_msgs::ClassWithProbability clas;
                clas.classification = 4;
                clas.probability = 1;
                object.classification.classes_with_probabilities.push_back(clas);
		object.motion_state.pose.pose.position.x = point[0];
                object.motion_state.pose.pose.position.y = point[1];*/
                /*object.motion_state.pose.pose.position.x = point[0] + traffic->Cfg.l / 2 * cos(traffic->r_zyx[0]);
                object.motion_state.pose.pose.position.y = point[1] + traffic->Cfg.l / 2 * sin(traffic->r_zyx[0]);*/
//                object.motion_state.pose.pose.position.z = traffic->t_0[2];
/*		object.motion_state.pose.pose.position.z = 0;
                q.setRPY(traffic->r_zyx[0], traffic->r_zyx[1], traffic->r_zyx[2]);
                object.motion_state.pose.pose.orientation.x = q.x();
                object.motion_state.pose.pose.orientation.y = q.y();
                object.motion_state.pose.pose.orientation.z = q.z();
                object.motion_state.pose.pose.orientation.w = q.w();

                geometry_msgs::Point point1;
                //point1.x = -traffic->Cfg.l / 2;
	        point1.x = 0;
                point1.y = obj->w / 2;
                point1.z = -obj->h / 2;

                geometry_msgs::Point point2;
                //point2.x = -obj->l / 2;
		point2.x = 0;
                point2.y = -obj->w / 2;
                point2.z = -obj->h / 2;

                geometry_msgs::Point point3;
                //point3.x = obj->l / 2;
		point3.x = obj->l;
                point3.y = -obj->w / 2;
                point3.z = -obj->h / 2;

                geometry_msgs::Point point4;
//                point4.x = obj->l / 2;
                point4.x = obj->l;
                point4.y = obj->w / 2;
                point4.z = -obj->h / 2;

                geometry_msgs::Point point5;
//                point5.x = -obj->l / 2;
		point5.x = 0;
                point5.y = obj->w / 2;
                point5.z = obj->h / 2;

                geometry_msgs::Point point6;
//                point6.x = -obj->l / 2;
		point6.x = 0;
                point6.y = -obj->w / 2;
                point6.z = obj->h / 2;

                geometry_msgs::Point point7;
//                point7.x = obj->l / 2;
                point7.x = obj->l;
                point7.y = -obj->w / 2;
                point7.z = obj->h / 2;

                geometry_msgs::Point point8;
//                point8.x = obj->l / 2;
                point8.x = obj->l;
                point8.y = obj->w / 2;
                point8.z = obj->h / 2;

                object.hull.vertices.push_back(point1);
                object.hull.vertices.push_back(point2);
                object.hull.vertices.push_back(point3);
                object.hull.vertices.push_back(point4);
                object.hull.vertices.push_back(point5);
                object.hull.vertices.push_back(point6);
                object.hull.vertices.push_back(point7);
                object.hull.vertices.push_back(point8);

                shape_msgs::MeshTriangle triangle;
                triangle.vertex_indices[0] = 0;
                triangle.vertex_indices[1] = 1;
                triangle.vertex_indices[2] = 2;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 0;
                triangle.vertex_indices[1] = 2;
                triangle.vertex_indices[2] = 3;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 4;
                triangle.vertex_indices[1] = 5;
                triangle.vertex_indices[2] = 6;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 4;
                triangle.vertex_indices[1] = 6;
                triangle.vertex_indices[2] = 7;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 0;
                triangle.vertex_indices[1] = 3;
                triangle.vertex_indices[2] = 7;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 0;
                triangle.vertex_indices[1] = 7;
                triangle.vertex_indices[2] = 4;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 1;
                triangle.vertex_indices[1] = 2;
                triangle.vertex_indices[2] = 6;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 1;
                triangle.vertex_indices[1] = 6;
                triangle.vertex_indices[2] = 5;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 2;
                triangle.vertex_indices[1] = 3;
                triangle.vertex_indices[2] = 7;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 2;
                triangle.vertex_indices[1] = 7;
                triangle.vertex_indices[2] = 6;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 0;
                triangle.vertex_indices[1] = 1;
                triangle.vertex_indices[2] = 5;
                object.hull.triangles.push_back(triangle);

                triangle.vertex_indices[0] = 0;
                triangle.vertex_indices[1] = 5;
                triangle.vertex_indices[2] = 4;
                object.hull.triangles.push_back(triangle);


                object.motion_state.twist.twist.linear.x = traffic->v_1[0];
                object.motion_state.twist.twist.linear.y = traffic->v_1[1];
                object.motion_state.twist.twist.linear.z = traffic->v_1[2];
                //		std::cout << "Velocity" << traffic->v_1[0] << "," << traffic->v_1[1] << "," << traffic->v_1[2] <<
                //"," << std::endl;

                object.header.stamp = time;
                object.header.frame_id = "odom";

                object.motion_state.header.stamp = time;
                object.motion_state.header.frame_id = "odom";
                object.motion_state.child_frame_id = std::to_string(i);*/

/*                if (traffic->Cfg.ObjectKind == 0) {
                    objects.objects.push_back(object);
                } else {
                    static_objects.objects.push_back(object);
                }*/
            }

            /*          objects.header.stamp = time;
                      objects.header.frame_id = "odom";
                      static_objects.header.stamp = time;
                      static_objects.header.frame_id = "odom";*/

        }

        auto trj_out = &CMNode.Topics.Pub.TrjOut;

        //   if ((rv = CMCRJob_DoJob(trj_out->Job, CMNode.CycleNoRel, 1, NULL, NULL)) != CMCRJob_RV_DoNothing
        //          && rv != CMCRJob_RV_DoSomething) {
        //      LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(trj_out->Job),
        //      CMCRJob_RVStr(rv));
        //  } else if (rv == CMCRJob_RV_DoSomething) {

        /* Header stamp and frame needs to be set manually! */
        /* provide system time close to data is sent */
        wtime = ros::WallTime::now();
        //      wtime = ros::Time(SimCore.Time);

        oadf_msgs::IPGDriverPose ipgdriver_pose;
//	ipgdriver_pose.header.stamp = time;
        ipgdriver_pose.header.stamp.sec = wtime.sec;
        ipgdriver_pose.header.stamp.nsec = wtime.nsec;
        ipgdriver_pose.header.frame_id = "/cm_world";

        ipgdriver_pose.time = SimCore.Time;

        ipgdriver_pose.position.x = Vehicle.PoI_Pos[0];
        ipgdriver_pose.position.y = Vehicle.PoI_Pos[1];
        ipgdriver_pose.position.z = Vehicle.PoI_Pos[2];

        ipgdriver_pose.velocity.x = Vehicle.PoI_Vel_1[0];
        ipgdriver_pose.velocity.y = Vehicle.PoI_Vel_1[1];
        ipgdriver_pose.velocity.z = Vehicle.PoI_Vel_1[2];
        ipgdriver_pose.abs_vel = Vehicle.v;

        ipgdriver_pose.acceleration.x = Vehicle.PoI_Acc_1[0];
        ipgdriver_pose.acceleration.y = Vehicle.PoI_Acc_1[1];
        ipgdriver_pose.acceleration.z = Vehicle.PoI_Acc_1[2];

        ipgdriver_pose.abs_acc =
                sqrt(pow(Vehicle.PoI_Acc_1[0], 2) + pow(Vehicle.PoI_Acc_1[1], 2) + pow(Vehicle.PoI_Acc_1[2], 2));

        ipgdriver_pose.yaw = Vehicle.Yaw;
        ipgdriver_pose.kappa = Car.ConBdy1.TrackCurv; // not ideal: TrackCurv is calculated from vehicle dynamics

        trj_out->Msg.poses.push_back(ipgdriver_pose);

        if (trj_out->Msg.poses.size() >= CMNode.Trajectory.size) {
            trj_out->Msg.header = trj_out->Msg.poses.front().header;
            trj_out->Pub.publish(trj_out->Msg);
            trj_out->Msg.poses.erase(trj_out->Msg.poses.begin());
        }


        //        /* Remember cycle for debugging */
        //        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
        //    }




        if (LidarRSICount > 0) {

            for (int lidarid = 0; lidarid < LidarRSICount; lidarid++) {

                if (lidarinit < LidarRSICount) {
                    tInfos *Inf_Vehicle = nullptr;
                    Inf_Vehicle = InfoNew();
                    auto Inf_Sensor = InfoNew();
                    const char *FName;
                    FName = InfoGetFilename(SimCore.Vhcl.Inf);
                    tErrorMsg *err;
                    int VehicleInfo_Err = iRead2(&err, Inf_Vehicle, FName, "SensorReadCode");
                    std::string positionstring = "Sensor.LidarRSI." + std::to_string(lidarid) + ".pos";
                    std::string rotationstring = "Sensor.LidarRSI." + std::to_string(lidarid) + ".rot";
                    position.push_back(iGetFixedTable2(Inf_Vehicle, positionstring.c_str(), 3, 1));
                    rotation.push_back(iGetFixedTable2(Inf_Vehicle, rotationstring.c_str(), 3, 1));
                    std::string beamstring = "Sensor.LidarRSI." + std::to_string(lidarid) + ".BeamsFName";
                    auto filename = iGetStr(Inf_Vehicle, beamstring.c_str());
                    std::string sensorfilename = "Data/Sensor/" + std::string(filename);
                    auto File2 = InfoRead(&err, Inf_Sensor, sensorfilename.c_str());
                    auto lidarsized = iGetFixedTable2(Inf_Sensor, "Beams.N", 2, 1);
                    lidarsize.push_back(lidarsized[0] * lidarsized[1]);
                    auto a = iGetStr(Inf_Sensor, "Beams.Type");
                    b.push_back(iGetFixedTable2(Inf_Sensor, "Beams", 6, lidarsize[lidarid]));
                    InfoDelete(Inf_Vehicle);
                    InfoDelete(Inf_Sensor);
                    lidarinit++;
                }

                sensor_msgs::PointCloud2 cloud;
                cloud.header.stamp = time;
                cloud.header.frame_id = "lidar" + std::to_string(lidarid);
                pcl::PointCloud <pcl::PointXYZI> cloudPCL;
                auto pLR = LidarRSI[lidarid];
                //  std::cout << "Number of points" << pLR.nScanPoints << std::endl;
                if (pLR.nScanPoints > 0) {
                    for (int i = 0; i < pLR.nScanPoints; i++) {

                        pcl::PointXYZI point;
                        int ii = pLR.ScanPoint[i].BeamID;
                        //  std::cout << "Angulo del laser" << b[lidarid][ii + (lidarsize[lidarid]*4)] << std::endl;
                        point.x = (pLR.ScanPoint[i].LengthOF / 2) *
                                  cos((b[lidarid][ii + (lidarsize[lidarid] * 5)] * M_PI / 180)) *
                                  cos((b[lidarid][ii + (lidarsize[lidarid] * 4)] * M_PI / 180));
                        point.y = (pLR.ScanPoint[i].LengthOF) / 2 *
                                  cos((b[lidarid][ii + (lidarsize[lidarid] * 5)] * M_PI / 180)) *
                                  sin((b[lidarid][ii + (lidarsize[lidarid] * 4)] * M_PI / 180));
                        point.z = (pLR.ScanPoint[i].LengthOF / 2) *
                                  sin((b[lidarid][ii + (lidarsize[lidarid] * 5)] * M_PI / 180));
                        point.intensity = pLR.ScanPoint[i].Intensity;
                        cloudPCL.points.push_back(point);
                    }

/*                transformStamped.header.stamp = time;
                transformStamped.header.frame_id = "Fr1";
                transformStamped.child_frame_id = "lidar" + std::to_string(lidarid);
                transformStamped.transform.translation.x = position[lidarid][0];
                transformStamped.transform.translation.y = position[lidarid][1];
                transformStamped.transform.translation.z = position[lidarid][2];
                tf2::Quaternion q;
                q.setRPY(rotation[lidarid][0], rotation[lidarid][1], rotation[lidarid][2]);
                transformStamped.transform.rotation.x = q.x();
                transformStamped.transform.rotation.y = q.y();
                transformStamped.transform.rotation.z = q.z();
                transformStamped.transform.rotation.w = q.w();
                transforms.transforms.push_back(transformStamped);*/


                    Transform.header.stamp = time;
                    Transform.header.frame_id = "Fr1";
                    Transform.child_frame_id = "lidar" + std::to_string(lidarid);
                    Transform.x = position[lidarid][0];
                    Transform.y = position[lidarid][1];
                    Transform.z = position[lidarid][2];
                    Transform.roll = rotation[lidarid][0];
                    Transform.pitch = rotation[lidarid][1];
                    Transform.yaw = rotation[lidarid][2];
                    VehicleMsg.frames.push_back(Transform);


                    pcl::toROSMsg(cloudPCL, cloud);
                    cloud.header.frame_id = "lidar" + std::to_string(lidarid);
                    cloud.header.stamp = time;

                    switch (lidarid) {
                        case 0: {
                            auto Cloud = &CMNode.Topics.Pub.LidarPub0;
                            Cloud->Pub.publish(cloud);
                            break;
                        }
                        case 1: {
                            auto Cloud = &CMNode.Topics.Pub.LidarPub1;
                            Cloud->Pub.publish(cloud);
                            break;
                        }
                        case 2: {
                            auto Cloud = &CMNode.Topics.Pub.LidarPub2;
                            Cloud->Pub.publish(cloud);
                            break;
                        }
                        case 3: {
                            auto Cloud = &CMNode.Topics.Pub.LidarPub3;
                            Cloud->Pub.publish(cloud);
                            break;
                        }

                    }
                }
            }
        }

        /*    auto TSign = TSignSensor[0];
            std::cout << "Num signs detected" << TSign.nSign << std::endl;
            for (int i=0;i<TSign.nSign;i++)
            {
            std::cout << "Senial" << TSign.Sign[i].objId << std::endl;

            }*/


        //Tf->Pub.publish(transforms);
        auto gps = GNavSensor.Receiver;
        oadf_msgs::GPSDate gpsdate;
        gpsdate.week = gps.Time_GpsWeek;
        gpsdate.sec = gps.Time_secsOfWeek;
        auto GPSDatePublisher = &CMNode.Topics.Pub.GPSDatePub;
        GPSDatePublisher->Pub.publish(gpsdate);

        auto Vehicle_Publisher = &CMNode.Topics.Pub.VehiclePub;
        Vehicle_Publisher->Pub.publish(VehicleMsg);

/*        auto Objects = &CMNode.Topics.Pub.Objects;
        auto Static_Objects = &CMNode.Topics.Pub.Static_Objects;
        Objects->Pub.publish(objects);
        Static_Objects->Pub.publish(static_objects);*/

        auto Static_Obstacles = &CMNode.Topics.Pub.StaticPub;
        static_obstacles_array.header.stamp = time;
        static_obstacles_array.header.frame_id = "odom";
        Static_Obstacles->Pub.publish(static_obstacles_array);

        auto Dynamic_Obstacles = &CMNode.Topics.Pub.DynamicPub;
        dynamic_obstacles_array.header.stamp = time;
        dynamic_obstacles_array.header.frame_id = "odom";
        Dynamic_Obstacles->Pub.publish(dynamic_obstacles_array);


        /* Publish "/clock" topic after all other other topics are published
         * - Is the order of arrival in other node identical? */
        if (CMNode.Cfg.nCyclesClock > 0 && CMNode.CycleNoRel % CMNode.Cfg.nCyclesClock == 0) {
            CMNode.Topics.Pub.Clock.Msg.clock = time;
            CMNode.Topics.Pub.Clock.Pub.publish(CMNode.Topics.Pub.Clock.Msg);
        }

    }

    /* ToDo: When increase? */
    CMNode.CycleNoRel++;

    return 1;
}


/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called one Time when CarMaker ends
 * - See "User.c:User_End()"
 */
int CMRosIF_CMNode_End(void) {

    LOG("%s: End", __func__);

    if (ros::isInitialized()) {

        /* Needs to be called before program exists, otherwise
         * "boost" error due to shared library and default deconstructor */
        CMNode.Cfg.Ros.Node->shutdown();

        /* ToDo:
         * - Blocking call? Wait until shutdown has finished?
         * - Optional? */
        ros::shutdown();
    }

    return 1;
}


/*!
 * Important:
 * - NOT automatically called by CMRosIF extension
 *
 * Description:
 * - Example of user generated function
 * - Can be accessed in other sources, e.g. User.c
 * - Use "CMRosIF_GetSymbol()" to get symbol (see "lib/CMRosIF.h")
 *
 */
int CMRosIF_CMNode_MyFunc(char *LogMsg) {

    LOG("%s: %s", __func__, LogMsg);
    return 1;
}

#ifdef __cplusplus
}
#endif
