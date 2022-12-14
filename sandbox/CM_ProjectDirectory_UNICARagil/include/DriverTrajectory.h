/*
******************************************************************************
**  CarMaker Driver Trajectory Extension
**
**  Description:
**  - Proof of Concept
**  - Provide a target trajectory to IPGDriver
**  - Currently two different modes are shown (only examples)
**    - Static  -> Read static trajectory from file before simulation starts
**    - Dynamic -> Generate trajectory dynamically while simulation is running
**  - The target trajectory has position/state information dependent on time
**  - IPGDriver controls ego vehicle to follow trajectory
**
**  Copyright (C)   IPG Automotive GmbH
**                  Bannwaldallee 60             Phone  +49.721.98520.0
**                  76185 Karlsruhe              Fax    +49.721.98520.99
**                  Germany                      WWW    www.ipg-automotive.com
******************************************************************************
*/


#ifndef DRIVERTRAJECTORY_H_
#define DRIVERTRAJECTORY_H_

#include "../unicar-definitions/UNICAR_definitions.h"													  

#ifdef __cplusplus
extern "C" {
#endif


/* Mode for Trajectory Module */
typedef enum tDrvTrj_Mode {
    DrvTrj_Mode_Disabled      = 0, /* Following Trajectory is disabled */
    DrvTrj_Mode_Enabled       = 1, /* Following Trajectory is enabled  */
    DrvTrj_Mode_NewActivation = 2, /* First cycle when mode is enabled */
    DrvTrj_Mode_ForcedRecalc  = 3,  /* Recalculation is necessary       */
	DrvTrj_Mode_UpdateGCS     = 4						 
} tDrvTrj_Mode;



/* Return values for the trajectory callback function */
typedef enum tDrvTrj_TrjState {
    DrvTrj_TrjState_Error   = -1,  /* Error when calculating trajectory */
    DrvTrj_TrjState_Valid   = 0,   /* No modification on trajectory, current trajectory is still valid */
    DrvTrj_TrjState_Updated = 1,    /* Trajectory has been updated successfully */
} tDrvTrj_TrjState;



/* Single Trajectory Point
 * parameters are given in two coordinate system in CarMaker (Fr0/Fr1) and must refer to vehicle PoI Position
 * Transformation is needed if user trajectory based on other coordinate system or other reference point
 * Details see docu and CarMaker User's Guide
 *  */
typedef struct tDrvTrj_Pnt {
    double Time;   /* Time for current trajectory point [s]. Has to be set by user */
    double Pos[3]; /* Position of vehicle PoI in Fr0 [m]. Has to be set by user */
    double Vel[3]; /* Velocity of vehicle PoI in Fr1 [m/s]. Optional */
    double VelAbs; /* Absolute velocity [m/s]. Has to be set by user */
    double Acc[3]; /* Acceleration of vehicle PoI in Fr1 [m/s2]. Optional */
    double AccAbs; /* Absolute acceleration [m/s2]. Optional */
    double Yaw;    /* Yaw angle in Fr0 [rad]. Has to be set by user */
    double Kappa;  /* Curvature for current trajectory point [1/m]. Has to be set by user */
} tDrvTrj_Pnt;



/* Trajectory */
typedef struct tDrvTrj_Trj {
    /* Data manipulated by user */
    int          nPnts;      /* Current number of points in trajectory */
    tDrvTrj_Pnt  *Pnts;      /* All points for current trajectory */
    double       dt;         /* Time step for trajectory points [s].
                                - Must be zero or negative if not equidistant
                                - Initial value is parameterizable, see documentation */

    /* Internal Data. Only for reading! Do not manipulate! */
    int          nPntsMax;   /* Max. number of the points in trajectory. Parameterizable, see documentation */
	trajGCS       trj_GCS;
	bool	      trj_GCS_new;
	pathGCS       path_GCS;	
	bool	      path_GCS_new;					  
} tDrvTrj_Trj;



/*
 * Description:
 * - Call this functions in the corresponding functions of CM main cycle e.g. in User.c
 */
int  DrvTrj_Init                  (void);
int  DrvTrj_TestRun_Start_atBegin (struct tInfos *Inf);
int  DrvTrj_TestRun_Start_atEnd   (void);
void DrvTrj_DeclQuants            (void);



/*
 * Description:
 * - Calculation of driver trajectory module
 * - Switches to new mode if requested (DVA or function below)
 * - If the module is active, the callback function "DrvTrj_GetTrajectory()" is called
 * - Updates the Quantities PntTrgt and PntPre
 * - A new calculated trajectory is applied in following cycle
 * - Call this function e.g. in User.c:User_DrivMan_Calc()
 */
int  DrvTrj_Calc (void);



/*
 * Description:
 * - Function pointer to be set by user to own user defined function
 * - Has to be used for calculation of new target trajectory
 * - Automatically called every CarMaker cycle
 * - The trajectory should not be updated every CarMaker Cycle!!!
 *   - e.g. provide 5s trajectory in future, then update after 1-2s
 *   - tPreview and dsPreview can be used as lower boundaries for trajectory generation
 * - Return value with trajectory state has to be managed by user!
 *
 * Arguments:
 * - TrjTrgt    = Target trajectory for IPG Driver (Input/Output)
 * - PntCurrent = Point with current position and state variables, normally located at Vehicle PoI (Input)
 * - tPreview   = Current preview time (relative to time in PntCurrent, Input)
 * - dsPreview  = Current preview distance (relative to position in PntCurrent, Input)
 * - Mode       = Informations to decide if new trajectory has to be generated (Input)
 *
 */
extern tDrvTrj_TrjState (*DrvTrj_GetTrajectory) (tDrvTrj_Trj *TrjTrgt, const tDrvTrj_Pnt *PntCurrent, double tPreview, double dsPreview, tDrvTrj_Mode Mode);



/*
 * Description:
 * - Optional pointer to be set by user to own user defined function
 * - If disabled the trajectory will calculate the state variables for the current target point internally
 */
extern int (*DrvTrj_GetTargetPnt) (tDrvTrj_Pnt *PntTrgt, double Time, const tDrvTrj_Trj *TrjTrgt);



/* Misc */
void DrvTrj_LogPnt     (tDrvTrj_Pnt *Pnt, char *Prefix);
int  DrvTrj_Export     (tDrvTrj_Trj *Trj, char *FName, char *Description, char Mode);
int  DrvTrj_IsActive   (void);
int  DrvTrj_SetModeReq (tDrvTrj_Mode Mode);



#ifdef __cplusplus
}
#endif

#endif /* DRIVERTRAJECTORY_H_ */
