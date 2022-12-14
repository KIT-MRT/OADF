/*
******************************************************************************
**  CarMaker - Version 9.0.1
**  Vehicle Dynamics Simulation Toolkit
**
**  Copyright (C)   IPG Automotive GmbH
**                  Bannwaldallee 60             Phone  +49.721.98520.0
**                  76185 Karlsruhe              Fax    +49.721.98520.99
**                  Germany                      WWW    www.ipg-automotive.com
******************************************************************************
**
** Functions
** ---------
**
** Initialization
**
**	User_Init_First ()
**	User_PrintUsage ()
**	User_ScanCmdLine ()
**
**	User_AppLogFilter ()
**
**	User_Init ()
**	User_Register ()
**	User_DeclQuants ()
**
**	User_Param_Add ()
**	User_Param_Get ()
**
**
** Main TestRun Start/End:
**
**	User_TestRun_Start_atBegin ()
**	User_TestRun_Start_atEnd ()
**	User_TestRun_Start_StaticCond_Calc ()
**	User_TestRun_Start_Finalize ()
**	User_TestRun_RampUp ()
**
**	User_TestRun_End_First ()
**	User_TestRun_End ()
**
**
** Main Cycle:
**
**	User_In ()
**
**	User_DrivMan_Calc ()
** 	User_Traffic_Calc ()
**	User_VehicleControl_Calc ()
**	User_Brake_Calc ()           in Vhcl_Calc ()
**	User_Calc ()
**	User_Check_IsIdle ()
**
**	User_Out ()
**
**
** APO Communication:
**
**	User_ApoMsg_Eval ()
**	User_ApoMsg_Send ()
**
**	User_ShutDown ()
**	User_End ()
**	User_Cleanup ()
**
**
******************************************************************************
*/

#include <Global.h>

#if defined(WIN32)
# include <windows.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>

#if defined(XENO)
# include <mio.h>
#endif

#include <CarMaker.h>
#include <Car/Vehicle_Car.h>
#include <Vehicle/Sensor_Inertial.h>									

#include <ADASRP.h>

#include <rbs.h>

#include "IOVec.h"
#include "User.h"

//#include "UnicarModels.h"
#include "MyModels.h"  

#if defined(WITH_CMROSIF)
#  include "CMRosIF.h"
#endif

#if defined (WITH_DRVTRJ)
#  include "DriverTrajectory.h"     /* CarMaker Extension Driver Trajectory */
#endif

	
				 
/* @@PLUGIN-BEGIN-INCLUDE@@ - Automatically generated code - don't edit! */
#include "../src_cm4sl/UNICARSteer_CarMaker_rtw/UNICARSteer_wrap.h"
#include "../src_cm4sl/UNICARBrake_CarMaker_rtw/UNICARBrake_wrap.h"
#include "../src_cm4sl/UNICARPTControl_CarMaker_rtw/UNICARPTControl_wrap.h"
#include "../src_cm4sl/UNICARPTMotor_CarMaker_rtw/UNICARPTMotor_wrap.h"
#include "../src_cm4sl/UNICARPTMotorCU_CarMaker_rtw/UNICARPTMotorCU_wrap.h"														   
#include "../src_cm4sl/UNICARPTGearBox_CarMaker_rtw/UNICARPTGearBox_wrap.h"																	   
																	 
/* @@PLUGIN-END@@ */

/* FTR parameter */
#include "../ftr-core/FTR.h"

/* tp */
#include "tp_cm.h"		

/* dcm */	
#include "dcm_cm.h"		   

int UserCalcCalledByAppTestRunCalc = 0;


tUser	User;
tDynMod	DynMod;
extern controlDiff contrDiff;

/* Switch for Safe Halt */
int sh_status;
tDDictEntry *DDE_status;
int sh_use;
tDDictEntry *DDE_use;


/* InertialSensor: Initialize GCSPos struct */
tGCSPos InertialSensor_Pos_GCS;

tpcore tp;
dcmcore dcm;	




/*
** User_Init_First ()
**
** First, low level initialization of the User module
**
** Call:
** - one times at start of program
** - no realtime conditions
**
*/

int
User_Init_First (void)
{
    memset (&User, 0, sizeof(User));

    return 0;
}



/*
** User_PrintUsage ()
**
** Print the user/application specific programm arguments
*/

void
User_PrintUsage (const char *Pgm)
{
    /* REMARK: 1 log statement for each usage line, no line breaks */
    LogUsage("\n");
    LogUsage("Usage: %s [options] [testrun]\n", Pgm);
    LogUsage("Options:\n");

#if defined(CM_HIL)
    {
	const tIOConfig *cf;
	const char *defio = IO_GetDefault();
	LogUsage(" -io %-12s Default I/O configuration (%s)\n", "default",
	    (defio!=NULL && strcmp(defio, "none")!=0) ? defio : "minimal I/O");
	for (cf=IO_GetConfigurations(); cf->Name!=NULL; cf++)
	    LogUsage(" -io %-12s %s\n", cf->Name, cf->Description);
    }
#endif
}



/*
** User_ScanCmdLine ()
**
** Scan application specific command line arguments
**
** Return:
** - argv: last unscanned argument
** - NULL: error or unknown argument
*/

char **
User_ScanCmdLine (int argc, char **argv)
{
    const char *Pgm = argv[0];

    /* I/O configuration to be used in case no configuration was
       specified on the command line. */
    IO_SelectDefault("default" /* or "demoapp", "demorbs,demofr" etc. */);

    while (*++argv) {
	if (strcmp(*argv, "-io") == 0 && argv[1] != NULL) {
	    if (IO_Select(*++argv) != 0)
		return NULL;
	} else if (strcmp(*argv, "-h") == 0 || strcmp(*argv, "-help") == 0) {
	    User_PrintUsage(Pgm);
	    SimCore_PrintUsage(Pgm); /* Possible exit(), depending on CM-platform! */
	    return  NULL;
	} else if ((*argv)[0] == '-') {
	    LogErrF(EC_General, "Unknown option '%s'", *argv);
	    return NULL;
	} else {
	    break;
	}
    }

    return argv;
}



/*
** User_Init ()
**
** Basic initialization of the module User.o
**
** Call:
** - once at program start
** - no realtime conditions
*/

int
User_Init (void)
{

#if defined (WITH_DRVTRJ)
    DrvTrj_Init();
#endif

#if defined(WITH_CMROSIF)
    int rv;

    if ((rv=CMRosIF_Init()) < 0)  /* Check for zero removed to force Log message of missing symbol */
	return rv;

    /* Example to get own function from CarMaker ROS Node shared library*/
    //void (*myfunc) (char *LogMsg) = CMRosIF_GetSymbol("CMRosIF_CMNode_MyFunc");

    //if (myfunc != NULL)
	//myfunc("Here is my own function from the CarMaker ROS Node library!");

#endif

    return 0;
}



int
User_Register (void)
{

    //Steering_Register_AllWheelSteering();
    //PTControl_Register_WheelControlModel ();
    //VehicleControl_Register_UnicarControl ();
    /* @@PLUGIN-BEGIN-REGISTER@@ - Automatically generated code - don't edit! */
	UNICARSteer_Register();
	UNICARBrake_Register();
	UNICARPTControl_Register();
	UNICARPTMotor_Register();
	UNICARPTMotorCU_Register();				
	UNICARPTGearBox_Register();					  
    /* @@PLUGIN-END@@ */
	VehicleControl_Register_VehicleControl_UNICAR();
	VehicleControl_Register_VehicleControl_SH();	

    return 0;
}



/*
** User_DeclQuants ()
**
** Add user specific quantities to the dictionary
**
** Call:
** - once at program start
** - no realtime conditions
*/

void
User_DeclQuants (void)
{

    int i;

    for (i=0; i<N_USEROUTPUT; i++) {
	char sbuf[32];
	sprintf (sbuf, "UserOut_%02d", i);
	DDefDouble (NULL, sbuf, "", &User.Out[i], DVA_IO_Out);
    }
	// Control deviation logging
	tDDefault *deq1 = DDefaultCreate("ControlDiff.");
	DDefDouble(deq1, "pos.lon", "m", &contrDiff.pos.lon, DVA_IO_Out);
	DDefDouble(deq1, "pos.lat", "m", &contrDiff.pos.lat, DVA_IO_Out);
	DDefDouble(deq1, "pos.yaw", "rad", &contrDiff.pos.yaw, DVA_IO_Out);
	DDefDouble(deq1, "vel.lon", "m/s", &contrDiff.vel.lon, DVA_IO_Out);
	DDefDouble(deq1, "vel.lat", "m/s", &contrDiff.vel.lat, DVA_IO_Out);
	DDefDouble(deq1, "vel.yaw", "rad/s", &contrDiff.vel.yaw, DVA_IO_Out);
	DDefDouble(deq1, "acc.lon", "m/s^2", &contrDiff.acc.lon, DVA_IO_Out);
	DDefDouble(deq1, "acc.lat", "m/s^2", &contrDiff.acc.lat, DVA_IO_Out);


	// Dynamic Modules
	tDDefault *df = DDefaultCreate("DynMod.");

	// Brake
	DDefPrefix(df, "DynMod.Brake.setpoint_Trq.");
	DDefDouble(df, "FL", "Nm", &DynMod.Brk.setpoint_Trq_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Brk.setpoint_Trq_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Brk.setpoint_Trq_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Brk.setpoint_Trq_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Brake.ErrBit.");
	DDefInt(df, "FL", "", &DynMod.Brk.ErrBit_1, DVA_IO_Out);
	DDefInt(df, "FR", "", &DynMod.Brk.ErrBit_2, DVA_IO_Out);
	DDefInt(df, "RL", "", &DynMod.Brk.ErrBit_3, DVA_IO_Out);
	DDefInt(df, "RR", "", &DynMod.Brk.ErrBit_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Brake.TrqMax.");
	DDefDouble(df, "FL", "Nm", &DynMod.Brk.TrqMax_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Brk.TrqMax_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Brk.TrqMax_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Brk.TrqMax_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Brake.BrakeActive.");
	DDefInt(df, "FL", "", &DynMod.Brk.BrakeActive_1, DVA_IO_Out);
	DDefInt(df, "FR", "", &DynMod.Brk.BrakeActive_2, DVA_IO_Out);
	DDefInt(df, "RL", "", &DynMod.Brk.BrakeActive_3, DVA_IO_Out);
	DDefInt(df, "RR", "", &DynMod.Brk.BrakeActive_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Brake.Trq.");
	DDefDouble(df, "FL", "Nm", &DynMod.Brk.Trq_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Brk.Trq_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Brk.Trq_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Brk.Trq_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Brake.ParkingBrk.");
	DDefUShort(df, "active", "", &DynMod.Brk.parking_brk_active, DVA_IO_Out);										
	// Drive
	DDefPrefix(df, "DynMod.Drive.TrqPeakMax.");
	DDefDouble(df, "FL", "Nm", &DynMod.Drive.TrqPeakMax_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Drive.TrqPeakMax_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Drive.TrqPeakMax_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Drive.TrqPeakMax_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Drive.ErrBit.");
	DDefInt(df, "FL", "", &DynMod.Drive.ErrBit_1, DVA_IO_Out);
	DDefInt(df, "FR", "", &DynMod.Drive.ErrBit_2, DVA_IO_Out);
	DDefInt(df, "RL", "", &DynMod.Drive.ErrBit_3, DVA_IO_Out);
	DDefInt(df, "RR", "", &DynMod.Drive.ErrBit_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Drive.TrqMax.");
	DDefDouble(df, "FL", "Nm", &DynMod.Drive.TrqMax_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Drive.TrqMax_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Drive.TrqMax_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Drive.TrqMax_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Drive.setpoint_Trq.");
	DDefDouble(df, "FL", "Nm", &DynMod.Drive.setpoint_Trq_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Drive.setpoint_Trq_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Drive.setpoint_Trq_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Drive.setpoint_Trq_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Drive.Trq.");
	DDefDouble(df, "FL", "Nm", &DynMod.Drive.Trq_1, DVA_IO_Out);
	DDefDouble(df, "FR", "Nm", &DynMod.Drive.Trq_2, DVA_IO_Out);
	DDefDouble(df, "RL", "Nm", &DynMod.Drive.Trq_3, DVA_IO_Out);
	DDefDouble(df, "RR", "Nm", &DynMod.Drive.Trq_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Drive.RotLim.");
	DDefDouble(df, "FL", "rad/s", &DynMod.Drive.RotLim_1, DVA_IO_Out);
	DDefDouble(df, "FR", "rad/s", &DynMod.Drive.RotLim_2, DVA_IO_Out);
	DDefDouble(df, "RL", "rad/s", &DynMod.Drive.RotLim_3, DVA_IO_Out);
	DDefDouble(df, "RR", "rad/s", &DynMod.Drive.RotLim_4, DVA_IO_Out);

	//SOC
	DDefPrefix(df, "DynMod.SOC.");
	DDefDouble(df, "FL", "", &DynMod.SOC_1, DVA_IO_Out);
	DDefDouble(df, "FR", "", &DynMod.SOC_2, DVA_IO_Out);
	DDefDouble(df, "RL", "", &DynMod.SOC_3, DVA_IO_Out);
	DDefDouble(df, "RR", "", &DynMod.SOC_4, DVA_IO_Out);

	//Steer
	DDefPrefix(df, "DynMod.Steer.setpoint_Angle.");
	DDefDouble(df, "FL", "rad", &DynMod.Steer.setpoint_Angle_1, DVA_IO_Out);
	DDefDouble(df, "FR", "rad", &DynMod.Steer.setpoint_Angle_2, DVA_IO_Out);
	DDefDouble(df, "RL", "rad", &DynMod.Steer.setpoint_Angle_3, DVA_IO_Out);
	DDefDouble(df, "RR", "rad", &DynMod.Steer.setpoint_Angle_4, DVA_IO_Out);

	DDefPrefix(df, "DynMod.Steer.ErrBit.");
	DDefInt(df, "FL", "", &DynMod.Steer.ErrBit_1, DVA_IO_Out);
	DDefInt(df, "FR", "", &DynMod.Steer.ErrBit_2, DVA_IO_Out);
	DDefInt(df, "RL", "", &DynMod.Steer.ErrBit_3, DVA_IO_Out);
	DDefInt(df, "RR", "", &DynMod.Steer.ErrBit_4, DVA_IO_Out);

	//Safe Halt
	tDDefault *df_sh = DDefaultCreate("SafeHalt.");
	DDefPrefix(df_sh, "SafeHalt.");
	DDE_status = DDefInt(df_sh, "status", "", &sh_status, DVA_IO_Out);
	DDefStates(DDE_status,3,0);
	DDE_use = DDefInt(df_sh, "use", "", &sh_use, DVA_IO_Out);
	DDefStates(DDE_use,3,0);
		
	DDefaultDelete(df);
	DDefaultDelete(df_sh);
#if !defined(LABCAR)
    RBS_DeclQuants();
#endif

#if defined(WITH_CMROSIF)
    CMRosIF_DeclQuants();
#endif

#if defined (WITH_DRVTRJ)
    DrvTrj_DeclQuants();
#endif

	df = NULL;		

}


/*
** User_Param_Add ()
**
** Update all modified application specific parameters in the test stand
** parameter file (ECUParameters).
**
** If the variable SimCore.TestRig.ECUParam.Modified set to 1 somewhere else
** CarMaker calls this function to let the user add or change all necessary
** entries before the file is written.
** So, if writing the ECUParam file is necessary, set ECUParam.Modified to 1.
** The next TestRun start or end, CarMaker calls this function and writes
** the file to the harddisk.
**
** Call:
** - in a separate thread (no realtime contitions)
** - when starting a new test run
*/

int
User_Param_Add (void)
{
#if defined(CM_HIL)
    /* ECU parameters */
    if (SimCore.TestRig.ECUParam.Inf == NULL)
	return -1;
#endif

    return 0;
}



/*
** User_Param_Get ()
**
** Update all modified application specific parameters from the test stand
** parameter file (ECUParameters).
**
** Call:
** - in a separate thread (no realtime conditions)
** - if User_Param_Get() wasn't called
** - when starting a new test run, if
**   - the files SimParameters and/or
**   - ECUParameters
**   are modified since last reading
**
** return values:
**  0	ok
** -1	no testrig parameter file
** -2	testrig parameter error
** -3	i/o configuration specific error
** -4	no simulation parameters
** -5	simulation parameters error
** -6	FailSafeTester parameter/init error
*/

int
User_Param_Get (void)
{
    int rv = 0;

#if defined(CM_HIL)
    /*** testrig / ECU parameters */
    if (SimCore.TestRig.ECUParam.Inf == NULL)
	return -1;

    if (IO_Param_Get(SimCore.TestRig.ECUParam.Inf) != 0)
	rv = -2;
#endif

    /*** simulation parameters */
    if (SimCore.TestRig.SimParam.Inf == NULL)
	return -4;

    return rv;
}



/*
** User_TestRun_Start_atBegin ()
**
** Special things before a new simulation starts like
** - reset user variables to their default values
** - reset counters
** - ...
**
** Call:
** - in separate thread (no realtime conditions)
** - when starting a new test run
** - after (standard) infofiles are read in
** - before reading parameters for Environment, DrivMan, Car, ...
**   the models are NOT in the simulation-can-start-now state
**   (after Start(), before StaticCond())
*/

int
User_TestRun_Start_atBegin (void)
{

	if(SimCore.CycleNo == 0) return 0;								
	tp.tpstart();	
	dcm.dcmstart();	  
    int rv = 0;
    int i;

    for (i=0; i<N_USEROUTPUT; i++)
	User.Out[i] = 0.0;

#if defined(WITH_CMROSIF)
    rv = CMRosIF_TestRun_Start_atBegin();
#endif

#if defined (WITH_DRVTRJ)
    DrvTrj_TestRun_Start_atBegin(SimCore.TestRun.Inf);
#endif

    if (IO_None)
	return rv;

#if defined(CM_HIL)
    if (FST_New(SimCore.TestRig.ECUParam.Inf) != 0)
	rv = -6;
#endif

    return rv;
}




/*
** User_TestRun_Start_atEnd ()
**
** Special things before a new simulation starts like
** - reset user variables to there default values
** - reset counters
** - ...
**
** Call:
** - in separate thread (no realtime conditions)
** - when starting a new test run
** - at the end, behind reading parameters for Environment, DrivMan,
**   Car, ...
**   the models are NOT in the simulation-can-start-now state
**   (after Start(), before StaticCond())
*/

int
User_TestRun_Start_atEnd (void)
{
    return 0;
}



/*
** User_TestRun_Start_StaticCond_Calc ()
**
** called in non RT context
*/

int
User_TestRun_Start_StaticCond_Calc (void)
{
    return 0;
}



/*
** User_TestRun_Start_Finalize ()
**
** called in RT context
*/

int
User_TestRun_Start_Finalize (void)
{
    return 0;
}



/*
** User_TestRun_RampUp ()
**
** Perform a smooth transition of variables (e.g. I/O)
** from their current state  to the new testrun.
** This function is called repeatedly, once during each cycle, until
** it returns true (or issues an error message), so the function should
** return true if transitioning is done, false otherwise.
**
** In case of an error the function should issue an apropriate
** error message and return false;
**
** Called in RT context, in state SCState_StartSim,
** after preprocessing is done, before starting the engine.
** Please note, that in this early initialization state no calculation
** of the vehicle model takes place.
*/

int
User_TestRun_RampUp (double dt)
{
    int IsReady = 1;

#if defined(WITH_CMROSIF)
    IsReady = CMRosIF_TestRun_RampUp();
#endif

    return IsReady;
}



/*
** User_TestRun_End_First ()
**
** Invoked immediately after the end of a simulation is initiated,
** but before data storage ends and before transitioning into SCState_Idle.
** - Send Scratchpad-note
** - ...
**
** Call:
** - in main task, in the main loop (real-time conditions!)
** - when a test run is finished (SimCore.State is SCState_End)
*/

int
User_TestRun_End_First (void)
{
    return 0;
}



/*
** User_TestRun_End ()
**
** Special things after the end of a simulation like
** - switch off an air compressor
** - Write something to a file
** - ...
**
** Call:
** - in separate thread (no realtime conditions)
** - when a test run is finished (SimCore.State is SCState_End<xyz>)
*/

int
User_TestRun_End (void)
{
	tpinterface::exitCondition = true;
	dcminterface::exitCondition = true;
	tp.tpexit();
	dcm.dcmexit();
#if defined(WITH_CMROSIF)
    CMRosIF_TestRun_End();
#endif

    return 0;
}



/*
** User_In ()
**
** Assign quantities of the i/o vector to model variables
**
** Call:
** - in the main loop
** - pay attention to realtime condition
** - just after IO_In()
*/

void
User_In (const unsigned CycleNo)
{

#if defined(WITH_CMROSIF)
    CMRosIF_In();
#endif

    if (SimCore.State != SCState_Simulate)
	return;
}



/*
** User_DrivMan_Calc ()
**
** called
** - in RT context
** - after DrivMan_Calc()
*/

int
User_DrivMan_Calc (double dt)
{
    /* Rely on the Vehicle Operator within DrivMan module to get
       the vehicle in driving state using the IPG's
       PowerTrain Control model 'Generic' or similar */
    if (Vehicle.OperationState != OperState_Driving)
       return 0;

#if defined(WITH_CMROSIF)
    CMRosIF_DrivMan_Calc(dt);
#endif

#if defined (WITH_DRVTRJ)
    DrvTrj_Calc();
#endif

    return 0;
}


/*
** User_VehicleControl_Calc ()
**
** called
** - in RT context
** - after VehicleControl_Calc()
*/

int
User_VehicleControl_Calc (double dt)
{
    /* Rely on the Vehicle Operator within DrivMan module to get
       the vehicle in driving state using the IPG's
       PowerTrain Control model 'Generic' or similar */
    if (Vehicle.OperationState != OperState_Driving)
	return 0;

#if defined(WITH_CMROSIF)
    CMRosIF_VehicleControl_Calc(dt);
#endif

    return 0;
}



/*
** User_Brake_Calc ()
**
** called
** - in RT context
** - after Brake_Calc() in Vhcl_Calc()
*/

int
User_Brake_Calc (double dt)
{
    /* Modify the total brake torque from the brake system model Brake.Trq_tot[]
       or the target drive source torque from the brake control unit
       Brake.HydBrakeCU_IF.Trq_DriveSrc_trg[]
    */

    return 0;
}



/*
** User_Traffic_Calc ()
**
** called
** - in RT context
** - after Traffic_Calc()
*/

int
User_Traffic_Calc (double dt)
{
    if (SimCore.State != SCState_Simulate)
	return 0;

    return 0;
}



/*
** User_Calc ()
**
** called in RT context
*/

int
User_Calc (double dt)
{
    /* Starting with CM 6.0 User_Calc() will be invoked in EVERY simulation
       state. Uncomment the following line in order to restore the behaviour
       of CM 5.1 and earlier. */
    /*if (!UserCalcCalledByAppTestRunCalc) return 0;*/

#if defined(WITH_CMROSIF)
    CMRosIF_Calc(dt);
#endif

    return 0;
}



/*
** User_Check_IsIdle ()
**
** Checking, if the simulation model is in idle conditions (stand still,
** steeringwheel angle zero, cluch pedal pressed, ...).
** If reached idle state, the calculation of vehicle model and driving
** manoevers is stopped.
** Ready for start new simulation.
**
** Return:
** 1  idle state reached
** 0  else
**
** Call:
** - in main task, in the main loop
** - pay attention to realtime condition
** - while SimCore.State==SCState_EndIdleGet
*/

int
User_Check_IsIdle (int IsIdle)
{
    double val;

    /*** ECU / carmodel signals */

    /* vehicle and wheels: stand still */
    val = 0.5*kmh2ms;
    if (Vehicle.v > val
     || fabs(Vehicle.Wheel[0]->vBelt) > val || fabs(Vehicle.Wheel[1]->vBelt) > val
     || fabs(Vehicle.Wheel[2]->vBelt) > val || fabs(Vehicle.Wheel[3]->vBelt) > val) {
	IsIdle = 0;
    }

    /* SteerAngle: drive  straight forward position */
    val = 1.0*deg2rad;
    if (Vehicle.Steering.Ang > val || Vehicle.Steering.Ang < -val)
	IsIdle = 0;

    return IsIdle;
}



/*
** User_Out ()
**
** Assigns model quantities to variables of the i/o vector
**
** call:
** - in the main loop
** - pay attention to realtime condition
** - just before IO_Out();
*/

void
User_Out (const unsigned CycleNo)
{
#if !defined(LABCAR)
    RBS_OutMap(CycleNo);
#endif

#if defined(WITH_CMROSIF)
    CMRosIF_Out();
#endif

    if (SimCore.State != SCState_Simulate)
	return;
}



/*
** User_ApoMsg_Eval ()
**
** Communication between the application and connected GUIs.
** Evaluate messages from GUIs
**
** Call:
** - in the main loop
** - pay attention to realtime condition
** - near the end of the main loop, if the function SimCore_ApoMsg_Eval()
**    skips the message
**
** Return:
**   0 : message evaluated
**  -1 : message not handled
*/

int
User_ApoMsg_Eval (int Ch, char *Msg, int len, int who)
{
#if defined(CM_HIL)
    /*** FailSafeTester */
    if (Ch == ApoCh_CarMaker) {
	if (FST_ApoMsgEval(Ch, Msg, len) <= 0)
	    return 0;
    }

#endif
    return -1;
}



/*
** User_ApoMsg_Send ()
**
** Communication between the application and connected GUIs.
** Sends messages to GUIs
**
** Call:
** - near the end of the main loop, in MainThread_FinishCycle()
** - pay attention to realtime condition
*/

void
User_ApoMsg_Send (double T, const unsigned CycleNo)
{
}



/*
** User_ShutDown ()
**
** Prepare application for shut down
**
** Call:
** - at end of program
** - no realtime conditions
*/

int
User_ShutDown (int ShutDownForced)
{
    int IsDown = 0;

    /* Prepare application for shutdown and return that
       shutdown conditions are reached */
    if (1) {
	IsDown = 1;
    }

    return IsDown;
}



/*
** User_End ()
**
** End all models of the user module
**
** Call:
** - one times at end of program
** - no realtime conditions
*/

int
User_End (void)
{

#if defined(WITH_CMROSIF)
    CMRosIF_End();
#endif

    return 0;
}



/*
** User_Cleanup ()
**
** Cleanup function of the User module
**
** Call:
** - one times at end of program, just before exit
** - no realtime conditions
*/

void
User_Cleanup (void)
{
}
