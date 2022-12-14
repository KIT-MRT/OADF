/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/

#ifndef IS_CAR
# define IS_CAR
#endif

#include "Global.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "simstruc.h"
#include "rt_sim.h"
#include "simstruc_types.h"

#include "InfoUtils.h"
#include "SimCore.h"
#include "Log.h"
#include "MatSupp.h"
#include "ModelManager.h"
#include "LinMap.h"

#if defined (IS_CAR) || defined (IS_TRUCK)
# include "Car/PowerTrain.h"
#elif defined(IS_MCYCLE)
# include "MCycle/PowerTrain.h"
#endif

#include "UNICARPTControl.h"
#include "UNICARPTControl_wrap.h"


#define QUOTE1(name)	#name
#define QUOTE(name)	QUOTE1(name)		/* need to expand name */

#ifndef CLASSIC_INTERFACE
# define EXPAND_CONCAT(name1,name2) name1 ## name2
# define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE CONCAT(MODEL,_initialize)
# define MODEL_STEP       CONCAT(MODEL,_step)
# define MODEL_TERMINATE  CONCAT(MODEL,_terminate)
# define RT_MDL_TYPE      CONCAT(MODEL,_M_TYPE)
#endif

extern const char UNICARPTControl_LibIdent[];
const char UNICARPTControl_LibIdent[] = "(@@)" QUOTE(MODEL) " " ARCH " 1.0 " BUILDDATE;

static const char Modelname[] = QUOTE(MODEL);
static const tModelClass Modelclass = ModelClass_PTControl;
static tMatSuppSampling SampleParams;


static void
DoOneStep (rtModel_UNICARPTControl *rtm)
{
#ifdef CLASSIC_INTERFACE
    real_T tnext;

    tnext = rt_SimGetNextSampleHit(rtmGetTimingData(rtm),
				   rtmGetNumSampleTimes(rtm));
    rtsiSetSolverStopTime(rtmGetRTWSolverInfo(rtm),tnext);

    rtmiOutputs(rtmGetRTWRTModelMethodsInfo(rtm),0);
    rtmiUpdate(rtmGetRTWRTModelMethodsInfo(rtm),0);
    rt_SimUpdateDiscreteTaskSampleHits(rtmGetNumSampleTimes(rtm),
				       rtmGetTimingData(rtm),
				       rtmGetSampleHitPtr(rtm),
				       rtmGetTPtr(rtm));

    if (rtmGetSampleTime(rtm,0) == CONTINUOUS_SAMPLE_TIME) {
	if (rtmGetNumContStates(rtm) > 0) {
	    rt_ODEUpdateContinuousStates(rtmGetRTWSolverInfo(rtm));
	} else {
	    rtsiSetT(rtmGetRTWSolverInfo(rtm), rtsiGetSolverStopTime(rtmGetRTWSolverInfo(rtm)));
	}
    }
#else
    MODEL_STEP(rtm);
#endif
}


/*
 * Define dictionary entries made from tunable parameters.
 * The function will actually be called twice, first with tuns==NULL.
 */
static void
DeclParameterQuants (struct tMatSuppTunables *tuns)
{
    /*MatSupp_TunDDictDefScalar(tuns, "MyParam", INFOMAT_DOUBLE, "kappa", "kg/s");*/
}


static void
UNICARPTControl_DeclQuants (void *MP)
{
    rtModel_UNICARPTControl *rtm = (rtModel_UNICARPTControl *)MP;
    int i;

    /*Log("%s_DeclQuants()\n", Modelname);*/

    if (rtm == NULL) {
	/* Remember body frames defined in this model for later registration. */
        MdlBdyFrame_Add(UNICARPTControl_BdyFrameDefines);

	/* Define dict entries for non-dynamically allocated variables. */
	if ((i = MatSupp_DeclQuants(UNICARPTControl_DictDefines)) >= 0) {
	    LogErrF(EC_Init, "Model '%s': Error defining quantity '%s'\n",
		    Modelname, UNICARPTControl_DictDefines[i].Name);
	}

	/* Define dict entries for tunable parameters (with dummy address). */
	DeclParameterQuants(NULL);
    } else {
	/* Define dict entries for dynamically allocated variables. */
    }
}


/*
 * UNICARPTControl_SetParams() will be invoked indirectly by the generated
 * model C code each time UNICARPTControl_New() is called.
 */
void
UNICARPTControl_SetParams (rtModel_UNICARPTControl *rtm, struct tMatSuppTunables *tuns,
		   struct tInfos *Inf)
{
    /*Log("%s_SetParams()\n", Modelname);*/

    /*
     * Parameter tuning - Part 1
     * This is the place to modify parameters of a storage class
     * other than 'SimulinkGlobal'.
     */

    if (tuns == NULL)
        return;

    /* Define dict entries for tunable parameters (address update). */
    DeclParameterQuants(tuns);

    /*
     * Parameter tuning - Part 2
     * This is the place to modify parameters of storage class
     * 'SimulinkGlobal', e.g. using the CarMaker target's tunable parameter
     * interface.
     */

    const char *prefix = Model_Class2Str(Modelclass);
    MatSupp_TunReadAllOpt(tuns, Inf, prefix);
    /*MatSupp_TunReadAll(tuns, ...);*/
    /*MatSupp_TunReadDef(tuns, ...);*/
    /*MatSupp_TunRead(tuns, ...);*/
}

static void
CfgLinMaptoBus (tLM *CfgInput, int arraydim, char* key, double *BusInputx, double *BusInputz)
{
    int xdim, i;
    tLM *lm;

    if (CfgInput != NULL) {
	lm = LMCopy(CfgInput);
	xdim = LMXGetDim(CfgInput);
	
	if (xdim > arraydim) {
	    Log("Model '%s': %s mapping will be resized to %i points.\n", Modelname, key, arraydim);
	    LMDelete(lm);
	    lm = LMResizeAequi(CfgInput, arraydim);
	    xdim = LMXGetDim(lm);
	}
	
	for (i=0; i<xdim; i++) {
	    BusInputx[i] = LMXGetVal(lm, i);
	    BusInputz[i] = LMEval(lm, BusInputx[i]);
	}
	for (i=xdim; i<arraydim; i++) {
	    BusInputx[i] = BusInputx[xdim-1];
	    BusInputz[i] = BusInputz[xdim-1];
	}
	LMDelete(lm);
    }
}

static void *
assignCfgIF (struct tPTControlCfgIF *CfgIF, void *MP)
{
    rtModel_UNICARPTControl *rtm = (rtModel_UNICARPTControl *)MP;
    int arraydim, nError = GetInfoErrorCount() + Log_nError;
    ExternalInputs_UNICARPTControl  *in  = (ExternalInputs_UNICARPTControl *) rtmGetU(rtm);

    /* CfgIF Input */
    in->CfgInFromCM.PTKind		= CfgIF->PTKind;
    in->CfgInFromCM.ClKind		= CfgIF->ClKind;
    in->CfgInFromCM.nMotor		= CfgIF->nMotor;
    in->CfgInFromCM.nGearBoxM		= CfgIF->nGearBoxM;
    in->CfgInFromCM.nPlanetGear		= CfgIF->nPlanetGear;
    in->CfgInFromCM.WheelRadius		= CfgIF->WheelRadius;
    in->CfgInFromCM.Aero_Frcx		= CfgIF->Aero_Frcx;
    in->CfgInFromCM.DL_iDiff_mean	= CfgIF->DL_iDiff_mean;

#if defined (IS_CAR) || defined (IS_TRUCK)
    in->CfgInFromCM.nWheels		= CfgIF->nWheels;

    in->CfgInFromCM.DriveSourcePos.d0	= CfgIF->DriveSourcePos[0];
    in->CfgInFromCM.DriveSourcePos.d1	= CfgIF->DriveSourcePos[1];
    in->CfgInFromCM.DriveSourcePos.d2	= CfgIF->DriveSourcePos[2];
    in->CfgInFromCM.DriveSourcePos.d3	= CfgIF->DriveSourcePos[3];
#endif
#if defined (IS_TRUCK)
    in->CfgInFromCM.DriveSourcePos.d4	= CfgIF->DriveSourcePos[4];
    in->CfgInFromCM.DriveSourcePos.d5	= CfgIF->DriveSourcePos[5];
    in->CfgInFromCM.DriveSourcePos.d6	= CfgIF->DriveSourcePos[6];
    in->CfgInFromCM.DriveSourcePos.d7	= CfgIF->DriveSourcePos[7];
#endif

    in->CfgInFromCM.BattLV.SOC_min	= CfgIF->BattLV.SOC_min;
    in->CfgInFromCM.BattLV.SOC_max	= CfgIF->BattLV.SOC_max;
    in->CfgInFromCM.BattLV.Capacity	= CfgIF->BattLV.Capacity;
    in->CfgInFromCM.BattLV.Voltage	= CfgIF->BattLV.Voltage;

    in->CfgInFromCM.BattHV.SOC_min	= CfgIF->BattHV.SOC_min;
    in->CfgInFromCM.BattHV.SOC_max	= CfgIF->BattHV.SOC_max;
    in->CfgInFromCM.BattHV.Capacity	= CfgIF->BattHV.Capacity;
    in->CfgInFromCM.BattHV.Voltage	= CfgIF->BattHV.Voltage;

    in->CfgInFromCM.Engine.Fuel_l2kWh	= CfgIF->Engine.Fuel_l2kWh;
    in->CfgInFromCM.Engine.rotv_max	= CfgIF->Engine.rotv_max;
    in->CfgInFromCM.Engine.rotv_idle	= CfgIF->Engine.rotv_idle;
    in->CfgInFromCM.Engine.rotv_opt	= CfgIF->Engine.rotv_opt;

    arraydim = sizeof(in->CfgInFromCM.Engine.TrqFull.x) / sizeof(in->CfgInFromCM.Engine.TrqFull.x[0]);
    CfgLinMaptoBus (CfgIF->Engine.TrqFull, arraydim, "Maximum engine full torque",
    		    in->CfgInFromCM.Engine.TrqFull.x, in->CfgInFromCM.Engine.TrqFull.z);

    arraydim = sizeof(in->CfgInFromCM.Engine.TrqDrag.x) / sizeof(in->CfgInFromCM.Engine.TrqDrag.x[0]);
    CfgLinMaptoBus (CfgIF->Engine.TrqDrag, arraydim, "Maximum engine drag torque",
    		    in->CfgInFromCM.Engine.TrqDrag.x, in->CfgInFromCM.Engine.TrqDrag.z);

    arraydim = sizeof(in->CfgInFromCM.Engine.TrqOpt.x) / sizeof(in->CfgInFromCM.Engine.TrqOpt.x[0]);
    CfgLinMaptoBus (CfgIF->Engine.TrqOpt, arraydim, "Engine torque with opt. consumption",
    		    in->CfgInFromCM.Engine.TrqOpt.x, in->CfgInFromCM.Engine.TrqOpt.z);

    in->CfgInFromCM.ISG.Level		= CfgIF->ISG.Level;
    in->CfgInFromCM.ISG.Ratio		= CfgIF->ISG.Ratio;
    in->CfgInFromCM.ISG.rotv_Mot_max	= CfgIF->ISG.rotv_Mot_max;
    in->CfgInFromCM.ISG.rotv_Gen_max	= CfgIF->ISG.rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.ISG.TrqMot_max.x) / sizeof(in->CfgInFromCM.ISG.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->ISG.TrqMot_max, arraydim, "ISG: Maximum motor torque",
    		    in->CfgInFromCM.ISG.TrqMot_max.x, in->CfgInFromCM.ISG.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.ISG.TrqGen_max.x) / sizeof(in->CfgInFromCM.ISG.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->ISG.TrqGen_max, arraydim, "ISG: Maximum generator torque",
    		    in->CfgInFromCM.ISG.TrqGen_max.x, in->CfgInFromCM.ISG.TrqGen_max.z);

    in->CfgInFromCM.Motor.m0.Level		= CfgIF->Motor[0].Level;
    in->CfgInFromCM.Motor.m0.Ratio		= CfgIF->Motor[0].Ratio;
    in->CfgInFromCM.Motor.m0.rotv_Mot_max	= CfgIF->Motor[0].rotv_Mot_max;
    in->CfgInFromCM.Motor.m0.rotv_Gen_max	= CfgIF->Motor[0].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m0.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m0.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[0].TrqMot_max, arraydim, "Motor: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m0.TrqMot_max.x, in->CfgInFromCM.Motor.m0.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m0.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m0.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[0].TrqGen_max, arraydim, "Motor: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m0.TrqGen_max.x, in->CfgInFromCM.Motor.m0.TrqGen_max.z);

    in->CfgInFromCM.Motor.m1.Level		= CfgIF->Motor[1].Level;
    in->CfgInFromCM.Motor.m1.Ratio		= CfgIF->Motor[1].Ratio;
    in->CfgInFromCM.Motor.m1.rotv_Mot_max	= CfgIF->Motor[1].rotv_Mot_max;
    in->CfgInFromCM.Motor.m1.rotv_Gen_max	= CfgIF->Motor[1].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m1.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m1.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[1].TrqMot_max, arraydim, "Motor1: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m1.TrqMot_max.x, in->CfgInFromCM.Motor.m1.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m1.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m1.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[1].TrqGen_max, arraydim, "Motor1: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m1.TrqGen_max.x, in->CfgInFromCM.Motor.m1.TrqGen_max.z);

#if defined (IS_CAR) || defined (IS_TRUCK)
    in->CfgInFromCM.Motor.m2.Level		= CfgIF->Motor[2].Level;
    in->CfgInFromCM.Motor.m2.Ratio		= CfgIF->Motor[2].Ratio;
    in->CfgInFromCM.Motor.m2.rotv_Mot_max	= CfgIF->Motor[2].rotv_Mot_max;
    in->CfgInFromCM.Motor.m2.rotv_Gen_max	= CfgIF->Motor[2].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m2.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m2.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[2].TrqMot_max, arraydim, "Motor2: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m2.TrqMot_max.x, in->CfgInFromCM.Motor.m2.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m2.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m2.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[2].TrqGen_max, arraydim, "Motor2: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m2.TrqGen_max.x, in->CfgInFromCM.Motor.m2.TrqGen_max.z);

    in->CfgInFromCM.Motor.m3.Level		= CfgIF->Motor[3].Level;
    in->CfgInFromCM.Motor.m3.Ratio		= CfgIF->Motor[3].Ratio;
    in->CfgInFromCM.Motor.m3.rotv_Mot_max	= CfgIF->Motor[3].rotv_Mot_max;
    in->CfgInFromCM.Motor.m3.rotv_Gen_max	= CfgIF->Motor[3].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m3.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m3.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[3].TrqMot_max, arraydim, "Motor3: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m3.TrqMot_max.x, in->CfgInFromCM.Motor.m3.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m3.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m3.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[3].TrqGen_max, arraydim, "Motor3: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m3.TrqGen_max.x, in->CfgInFromCM.Motor.m3.TrqGen_max.z);

#endif
#if defined (IS_TRUCK)
    in->CfgInFromCM.Motor.m4.Level		= CfgIF->Motor[4].Level;
    in->CfgInFromCM.Motor.m4.Ratio		= CfgIF->Motor[4].Ratio;
    in->CfgInFromCM.Motor.m4.rotv_Mot_max	= CfgIF->Motor[4].rotv_Mot_max;
    in->CfgInFromCM.Motor.m4.rotv_Gen_max	= CfgIF->Motor[4].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m4.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m4.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[4].TrqMot_max, arraydim, "Motor4: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m4.TrqMot_max.x, in->CfgInFromCM.Motor.m4.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m4.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m4.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[4].TrqGen_max, arraydim, "Motor4: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m4.TrqGen_max.x, in->CfgInFromCM.Motor.m4.TrqGen_max.z);

    in->CfgInFromCM.Motor.m5.Level		= CfgIF->Motor[5].Level;
    in->CfgInFromCM.Motor.m5.Ratio		= CfgIF->Motor[5].Ratio;
    in->CfgInFromCM.Motor.m5.rotv_Mot_max	= CfgIF->Motor[5].rotv_Mot_max;
    in->CfgInFromCM.Motor.m5.rotv_Gen_max	= CfgIF->Motor[5].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m5.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m5.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[5].TrqMot_max, arraydim, "Motor5: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m5.TrqMot_max.x, in->CfgInFromCM.Motor.m5.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m5.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m5.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[5].TrqGen_max, arraydim, "Motor5: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m5.TrqGen_max.x, in->CfgInFromCM.Motor.m5.TrqGen_max.z);

    in->CfgInFromCM.Motor.m6.Level		= CfgIF->Motor[6].Level;
    in->CfgInFromCM.Motor.m6.Ratio		= CfgIF->Motor[6].Ratio;
    in->CfgInFromCM.Motor.m6.rotv_Mot_max	= CfgIF->Motor[6].rotv_Mot_max;
    in->CfgInFromCM.Motor.m6.rotv_Gen_max	= CfgIF->Motor[6].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m6.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m6.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[6].TrqMot_max, arraydim, "Motor6: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m6.TrqMot_max.x, in->CfgInFromCM.Motor.m6.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m6.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m6.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[6].TrqGen_max, arraydim, "Motor6: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m6.TrqGen_max.x, in->CfgInFromCM.Motor.m6.TrqGen_max.z);

    in->CfgInFromCM.Motor.m7.Level		= CfgIF->Motor[7].Level;
    in->CfgInFromCM.Motor.m7.Ratio		= CfgIF->Motor[7].Ratio;
    in->CfgInFromCM.Motor.m7.rotv_Mot_max	= CfgIF->Motor[7].rotv_Mot_max;
    in->CfgInFromCM.Motor.m7.rotv_Gen_max	= CfgIF->Motor[7].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m7.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m7.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[7].TrqMot_max, arraydim, "Motor7: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m7.TrqMot_max.x, in->CfgInFromCM.Motor.m7.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m7.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m7.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[7].TrqGen_max, arraydim, "Motor7: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m7.TrqGen_max.x, in->CfgInFromCM.Motor.m7.TrqGen_max.z);
#endif

    in->CfgInFromCM.GearBox.GBKind		= CfgIF->GearBox.GBKind;
    in->CfgInFromCM.GearBox.ClKind		= CfgIF->GearBox.ClKind;
    in->CfgInFromCM.GearBox.nFGears		= CfgIF->GearBox.nFGears;
    in->CfgInFromCM.GearBox.iFGear.Gear1	= CfgIF->GearBox.iFGear[1];
    in->CfgInFromCM.GearBox.iFGear.Gear2	= CfgIF->GearBox.iFGear[2];
    in->CfgInFromCM.GearBox.iFGear.Gear3	= CfgIF->GearBox.iFGear[3];
    in->CfgInFromCM.GearBox.iFGear.Gear4	= CfgIF->GearBox.iFGear[4];
    in->CfgInFromCM.GearBox.iFGear.Gear5	= CfgIF->GearBox.iFGear[5];
    in->CfgInFromCM.GearBox.iFGear.Gear6	= CfgIF->GearBox.iFGear[6];
    in->CfgInFromCM.GearBox.iFGear.Gear7	= CfgIF->GearBox.iFGear[7];
    in->CfgInFromCM.GearBox.iFGear.Gear8	= CfgIF->GearBox.iFGear[8];
    in->CfgInFromCM.GearBox.iFGear.Gear9	= CfgIF->GearBox.iFGear[9];
    in->CfgInFromCM.GearBox.iFGear.Gear10	= CfgIF->GearBox.iFGear[10];
    in->CfgInFromCM.GearBox.iFGear.Gear11	= CfgIF->GearBox.iFGear[11];
    in->CfgInFromCM.GearBox.iFGear.Gear12	= CfgIF->GearBox.iFGear[12];
    in->CfgInFromCM.GearBox.iFGear.Gear13	= CfgIF->GearBox.iFGear[13];
    in->CfgInFromCM.GearBox.iFGear.Gear14	= CfgIF->GearBox.iFGear[14];
    in->CfgInFromCM.GearBox.iFGear.Gear15	= CfgIF->GearBox.iFGear[15];
    in->CfgInFromCM.GearBox.iFGear.Gear16	= CfgIF->GearBox.iFGear[16];
    in->CfgInFromCM.GearBox.nBGears		= CfgIF->GearBox.nBGears;
    in->CfgInFromCM.GearBox.iBGear.Gear1	= CfgIF->GearBox.iBGear[1];
    in->CfgInFromCM.GearBox.iBGear.Gear2	= CfgIF->GearBox.iBGear[2];
    in->CfgInFromCM.GearBox.iBGear.Gear3	= CfgIF->GearBox.iBGear[3];
    in->CfgInFromCM.GearBox.iBGear.Gear4	= CfgIF->GearBox.iBGear[4];

    in->CfgInFromCM.GearBoxM.GB_m0.GBKind	= CfgIF->GearBoxM[0].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m0.ClKind	= CfgIF->GearBoxM[0].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m0.nFGears	= CfgIF->GearBoxM[0].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear1	= CfgIF->GearBoxM[0].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear2	= CfgIF->GearBoxM[0].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear3	= CfgIF->GearBoxM[0].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear4	= CfgIF->GearBoxM[0].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear5	= CfgIF->GearBoxM[0].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear6	= CfgIF->GearBoxM[0].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear7	= CfgIF->GearBoxM[0].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear8	= CfgIF->GearBoxM[0].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear9	= CfgIF->GearBoxM[0].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear10= CfgIF->GearBoxM[0].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear11= CfgIF->GearBoxM[0].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear12= CfgIF->GearBoxM[0].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear13= CfgIF->GearBoxM[0].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear14= CfgIF->GearBoxM[0].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear15= CfgIF->GearBoxM[0].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m0.iFGear.Gear16= CfgIF->GearBoxM[0].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m0.nBGears	= CfgIF->GearBoxM[0].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m0.iBGear.Gear1	= CfgIF->GearBoxM[0].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m0.iBGear.Gear2	= CfgIF->GearBoxM[0].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m0.iBGear.Gear3	= CfgIF->GearBoxM[0].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m0.iBGear.Gear4	= CfgIF->GearBoxM[0].iBGear[4];
    
    in->CfgInFromCM.GearBoxM.GB_m1.GBKind	= CfgIF->GearBoxM[1].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m1.ClKind	= CfgIF->GearBoxM[1].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m1.nFGears	= CfgIF->GearBoxM[1].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear1	= CfgIF->GearBoxM[1].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear2	= CfgIF->GearBoxM[1].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear3	= CfgIF->GearBoxM[1].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear4	= CfgIF->GearBoxM[1].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear5	= CfgIF->GearBoxM[1].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear6	= CfgIF->GearBoxM[1].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear7	= CfgIF->GearBoxM[1].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear8	= CfgIF->GearBoxM[1].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear9	= CfgIF->GearBoxM[1].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear10= CfgIF->GearBoxM[1].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear11= CfgIF->GearBoxM[1].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear12= CfgIF->GearBoxM[1].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear13= CfgIF->GearBoxM[1].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear14= CfgIF->GearBoxM[1].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear15= CfgIF->GearBoxM[1].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m1.iFGear.Gear16= CfgIF->GearBoxM[1].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m1.nBGears	= CfgIF->GearBoxM[1].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m1.iBGear.Gear1	= CfgIF->GearBoxM[1].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m1.iBGear.Gear2	= CfgIF->GearBoxM[1].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m1.iBGear.Gear3	= CfgIF->GearBoxM[1].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m1.iBGear.Gear4	= CfgIF->GearBoxM[1].iBGear[4];
    
#if defined (IS_CAR) || defined (IS_TRUCK)
    in->CfgInFromCM.GearBoxM.GB_m2.GBKind	= CfgIF->GearBoxM[2].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m2.ClKind	= CfgIF->GearBoxM[2].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m2.nFGears	= CfgIF->GearBoxM[2].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear1	= CfgIF->GearBoxM[2].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear2	= CfgIF->GearBoxM[2].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear3	= CfgIF->GearBoxM[2].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear4	= CfgIF->GearBoxM[2].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear5	= CfgIF->GearBoxM[2].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear6	= CfgIF->GearBoxM[2].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear7	= CfgIF->GearBoxM[2].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear8	= CfgIF->GearBoxM[2].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear9	= CfgIF->GearBoxM[2].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear10= CfgIF->GearBoxM[2].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear11= CfgIF->GearBoxM[2].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear12= CfgIF->GearBoxM[2].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear13= CfgIF->GearBoxM[2].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear14= CfgIF->GearBoxM[2].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear15= CfgIF->GearBoxM[2].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m2.iFGear.Gear16= CfgIF->GearBoxM[2].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m2.nBGears	= CfgIF->GearBoxM[2].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m2.iBGear.Gear1	= CfgIF->GearBoxM[2].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m2.iBGear.Gear2	= CfgIF->GearBoxM[2].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m2.iBGear.Gear3	= CfgIF->GearBoxM[2].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m2.iBGear.Gear4	= CfgIF->GearBoxM[2].iBGear[4];
    
    in->CfgInFromCM.GearBoxM.GB_m3.GBKind	= CfgIF->GearBoxM[3].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m3.ClKind	= CfgIF->GearBoxM[3].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m3.nFGears	= CfgIF->GearBoxM[3].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear1	= CfgIF->GearBoxM[3].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear2	= CfgIF->GearBoxM[3].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear3	= CfgIF->GearBoxM[3].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear4	= CfgIF->GearBoxM[3].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear5	= CfgIF->GearBoxM[3].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear6	= CfgIF->GearBoxM[3].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear7	= CfgIF->GearBoxM[3].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear8	= CfgIF->GearBoxM[3].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear9	= CfgIF->GearBoxM[3].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear10= CfgIF->GearBoxM[3].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear11= CfgIF->GearBoxM[3].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear12= CfgIF->GearBoxM[3].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear13= CfgIF->GearBoxM[3].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear14= CfgIF->GearBoxM[3].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear15= CfgIF->GearBoxM[3].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m3.iFGear.Gear16= CfgIF->GearBoxM[3].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m3.nBGears	= CfgIF->GearBoxM[3].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m3.iBGear.Gear1	= CfgIF->GearBoxM[3].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m3.iBGear.Gear2	= CfgIF->GearBoxM[3].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m3.iBGear.Gear3	= CfgIF->GearBoxM[3].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m3.iBGear.Gear4	= CfgIF->GearBoxM[3].iBGear[4];
    
#endif
#if defined (IS_TRUCK)
    in->CfgInFromCM.GearBoxM.GB_m4.GBKind	= CfgIF->GearBoxM[4].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m4.ClKind	= CfgIF->GearBoxM[4].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m4.nFGears	= CfgIF->GearBoxM[4].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear1	= CfgIF->GearBoxM[4].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear2	= CfgIF->GearBoxM[4].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear3	= CfgIF->GearBoxM[4].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear4	= CfgIF->GearBoxM[4].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear5	= CfgIF->GearBoxM[4].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear6	= CfgIF->GearBoxM[4].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear7	= CfgIF->GearBoxM[4].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear8	= CfgIF->GearBoxM[4].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear9	= CfgIF->GearBoxM[4].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear10= CfgIF->GearBoxM[4].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear11= CfgIF->GearBoxM[4].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear12= CfgIF->GearBoxM[4].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear13= CfgIF->GearBoxM[4].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear14= CfgIF->GearBoxM[4].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear15= CfgIF->GearBoxM[4].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m4.iFGear.Gear16= CfgIF->GearBoxM[4].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m4.nBGears	= CfgIF->GearBoxM[4].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m4.iBGear.Gear1	= CfgIF->GearBoxM[4].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m4.iBGear.Gear2	= CfgIF->GearBoxM[4].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m4.iBGear.Gear3	= CfgIF->GearBoxM[4].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m4.iBGear.Gear4	= CfgIF->GearBoxM[4].iBGear[4];
    
    in->CfgInFromCM.GearBoxM.GB_m5.GBKind	= CfgIF->GearBoxM[5].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m5.ClKind	= CfgIF->GearBoxM[5].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m5.nFGears	= CfgIF->GearBoxM[5].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear1	= CfgIF->GearBoxM[5].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear2	= CfgIF->GearBoxM[5].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear3	= CfgIF->GearBoxM[5].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear4	= CfgIF->GearBoxM[5].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear5	= CfgIF->GearBoxM[5].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear6	= CfgIF->GearBoxM[5].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear7	= CfgIF->GearBoxM[5].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear8	= CfgIF->GearBoxM[5].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear9	= CfgIF->GearBoxM[5].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear10= CfgIF->GearBoxM[5].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear11= CfgIF->GearBoxM[5].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear12= CfgIF->GearBoxM[5].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear13= CfgIF->GearBoxM[5].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear14= CfgIF->GearBoxM[5].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear15= CfgIF->GearBoxM[5].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m5.iFGear.Gear16= CfgIF->GearBoxM[5].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m5.nBGears	= CfgIF->GearBoxM[5].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m5.iBGear.Gear1	= CfgIF->GearBoxM[5].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m5.iBGear.Gear2	= CfgIF->GearBoxM[5].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m5.iBGear.Gear3	= CfgIF->GearBoxM[5].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m5.iBGear.Gear4	= CfgIF->GearBoxM[5].iBGear[4];
    
    in->CfgInFromCM.GearBoxM.GB_m6.GBKind	= CfgIF->GearBoxM[6].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m6.ClKind	= CfgIF->GearBoxM[6].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m6.nFGears	= CfgIF->GearBoxM[6].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear1	= CfgIF->GearBoxM[6].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear2	= CfgIF->GearBoxM[6].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear3	= CfgIF->GearBoxM[6].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear4	= CfgIF->GearBoxM[6].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear5	= CfgIF->GearBoxM[6].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear6	= CfgIF->GearBoxM[6].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear7	= CfgIF->GearBoxM[6].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear8	= CfgIF->GearBoxM[6].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear9	= CfgIF->GearBoxM[6].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear10= CfgIF->GearBoxM[6].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear11= CfgIF->GearBoxM[6].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear12= CfgIF->GearBoxM[6].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear13= CfgIF->GearBoxM[6].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear14= CfgIF->GearBoxM[6].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear15= CfgIF->GearBoxM[6].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m6.iFGear.Gear16= CfgIF->GearBoxM[6].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m6.nBGears	= CfgIF->GearBoxM[6].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m6.iBGear.Gear1	= CfgIF->GearBoxM[6].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m6.iBGear.Gear2	= CfgIF->GearBoxM[6].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m6.iBGear.Gear3	= CfgIF->GearBoxM[6].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m6.iBGear.Gear4	= CfgIF->GearBoxM[6].iBGear[4];
    
    in->CfgInFromCM.GearBoxM.GB_m7.GBKind	= CfgIF->GearBoxM[7].GBKind;
    in->CfgInFromCM.GearBoxM.GB_m7.ClKind	= CfgIF->GearBoxM[7].ClKind;
    in->CfgInFromCM.GearBoxM.GB_m7.nFGears	= CfgIF->GearBoxM[7].nFGears;
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear1	= CfgIF->GearBoxM[7].iFGear[1];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear2	= CfgIF->GearBoxM[7].iFGear[2];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear3	= CfgIF->GearBoxM[7].iFGear[3];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear4	= CfgIF->GearBoxM[7].iFGear[4];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear5	= CfgIF->GearBoxM[7].iFGear[5];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear6	= CfgIF->GearBoxM[7].iFGear[6];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear7	= CfgIF->GearBoxM[7].iFGear[7];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear8	= CfgIF->GearBoxM[7].iFGear[8];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear9	= CfgIF->GearBoxM[7].iFGear[9];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear10= CfgIF->GearBoxM[7].iFGear[10];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear11= CfgIF->GearBoxM[7].iFGear[11];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear12= CfgIF->GearBoxM[7].iFGear[12];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear13= CfgIF->GearBoxM[7].iFGear[13];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear14= CfgIF->GearBoxM[7].iFGear[14];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear15= CfgIF->GearBoxM[7].iFGear[15];
    in->CfgInFromCM.GearBoxM.GB_m7.iFGear.Gear16= CfgIF->GearBoxM[7].iFGear[16];
    in->CfgInFromCM.GearBoxM.GB_m7.nBGears	= CfgIF->GearBoxM[7].nBGears;
    in->CfgInFromCM.GearBoxM.GB_m7.iBGear.Gear1	= CfgIF->GearBoxM[7].iBGear[1];
    in->CfgInFromCM.GearBoxM.GB_m7.iBGear.Gear2	= CfgIF->GearBoxM[7].iBGear[2];
    in->CfgInFromCM.GearBoxM.GB_m7.iBGear.Gear3	= CfgIF->GearBoxM[7].iBGear[3];
    in->CfgInFromCM.GearBoxM.GB_m7.iBGear.Gear4	= CfgIF->GearBoxM[7].iBGear[4];
#endif

    in->CfgInFromCM.PlanetGear.Ratio	= CfgIF->PlanetGear[0].Ratio;

    /* CfgIF Output */
    in->CfgOutFromCM.StartEngineWithSST = CfgIF->StartEngineWithSST;
    in->CfgOutFromCM.Velocity_max       = CfgIF->Velocity_max;

    if (GetInfoErrorCount()+ Log_nError != nError) {
    	goto ErrorReturn;
    }

    return rtm;

  ErrorReturn:
    return NULL;
}


static void *
UNICARPTControl_New (struct tInfos *Inf, tPTControlCfgIF *CfgIF, const char *KindKey)
{
    rtModel_UNICARPTControl *rtm;
    double rtmSampleTime;
    const char *ModelKind;
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, Modelclass, KindKey,
	 				 0, PARAMID, &VersionId)) == NULL)
	return NULL;

    /*Log("%s_New()\n", Modelname);*/
    if (iGetLongOpt (Inf,"PowerTrain.DL.FlexShaft" , 0))
	LogErrF(EC_Init, "Model '%s': Using flex shaft not allowed\n",Modelname);

    MatSupp_ResetQuants(UNICARPTControl_DictDefines);

    rtm = MODEL(Inf);

#ifdef CLASSIC_INTERFACE
    rtmSetT(rtm, 0.0);
    rtmSetTFinal(rtm, -1 /*run forever*/);

    rtmiInitializeSizes(rtmGetRTWRTModelMethodsInfo(rtm));
    rtmiInitializeSampleTimes(rtmGetRTWRTModelMethodsInfo(rtm));
    rt_SimInitTimingEngine(rtmGetNumSampleTimes(rtm),
			   rtmGetStepSize(rtm),
			   rtmGetSampleTimePtr(rtm),
			   rtmGetOffsetTimePtr(rtm),
			   rtmGetSampleHitPtr(rtm),
			   rtmGetSampleTimeTaskIDPtr(rtm),
			   rtmGetTStart(rtm),
			   &rtmGetSimTimeStep(rtm),
			   &rtmGetTimingData(rtm));
    if (rtmGetNumContStates(rtm) > 0) {
	rt_ODECreateIntegrationData(rtmGetRTWSolverInfo(rtm));
    } else {
	rtsiSetSolverName(rtmGetRTWSolverInfo(rtm), "FixedStepDiscrete");
    }
    rtsiSetVariableStepSolver(rtmGetRTWSolverInfo(rtm), 0);
#endif

    rtmSampleTime = (double) rtmGetStepSize(rtm);
    if (MatSupp_Sampling (&SampleParams, SimCore.DeltaT, rtmSampleTime) !=0) {
	LogErrF(EC_Init, "Model '%s': The sample times of the plugin model and the application have to be integer multiples\n",Modelname);
	return NULL;
    }

    /* get CfgIF parameters */
    if (PTControl_GetCfgOutIF (Inf, CfgIF, ModelKind) != 0)
	return NULL;

    /* assign CfgIF struct */
    if ((assignCfgIF(CfgIF, rtm)) == NULL)  {
	LogErrF(EC_Init, "Model '%s': failed to assign CfgIF\n",Modelname);
	return NULL;
    }

#ifdef CLASSIC_INTERFACE
    rtmiStart(rtmGetRTWRTModelMethodsInfo(rtm));
#else
    MODEL_INITIALIZE(rtm);
#endif

    return rtm; /* Will be passed as MP to the other functions. */
}


static void
UNICARPTControl_Delete (void *MP)
{
    rtModel_UNICARPTControl *rtm = (rtModel_UNICARPTControl *)MP;

    /*Log("%s_Delete()\n", Modelname);*/

#ifdef CLASSIC_INTERFACE
    rt_SimDestroyTimingEngine(rtmGetTimingData(rtm));
    if (rtmGetNumContStates(rtm) > 0)
	rt_ODEDestroyIntegrationData(rtmGetRTWSolverInfo(rtm));
    rtmiTerminate(rtmGetRTWRTModelMethodsInfo(rtm));
#else
    MODEL_TERMINATE(rtm);
#endif
}


static int
UNICARPTControl_Calc (void *MP, tPTControlIF *IF, double dt)
{
    rtModel_UNICARPTControl *rtm = (rtModel_UNICARPTControl *)MP;
    int osCount=0;
    ExternalInputs_UNICARPTControl  *in  = (ExternalInputs_UNICARPTControl *) rtmGetU(rtm);
    ExternalOutputs_UNICARPTControl *out = (ExternalOutputs_UNICARPTControl *)rtmGetY(rtm);


    in->FromCM.Key 		= IF->Key;
    in->FromCM.SST 		= IF->SST;
    in->FromCM.SelectorCtrl 	= IF->SelectorCtrl;
    in->FromCM.GearNoTrg 	= IF->GearNoTrg;
    in->FromCM.Clutch 		= IF->Clutch;
    in->FromCM.Gas 		= IF->Gas;
    in->FromCM.Brake 		= IF->Brake;
    in->FromCM.Velocity 	= IF->Velocity;


    in->FromCM.UserSignal.s0 = IF->UserSignal[0];
    in->FromCM.UserSignal.s1 = IF->UserSignal[1];
    in->FromCM.UserSignal.s2 = IF->UserSignal[2];
    in->FromCM.UserSignal.s3 = IF->UserSignal[3];
    in->FromCM.UserSignal.s4 = IF->UserSignal[4];

    // Engine
    in->FromCM.ECU_Status = IF->ECU_Status;
    in->FromCM.EngineIn.Engine_on 	= IF->EngineIn.Engine_on;
    in->FromCM.EngineIn.rotv 		= IF->EngineIn.rotv;
    in->FromCM.EngineIn.Trq 		= IF->EngineIn.Trq;
    in->FromCM.EngineIn.TrqDrag 	= IF->EngineIn.TrqDrag;
    in->FromCM.EngineIn.TrqFull 	= IF->EngineIn.TrqFull;
    in->FromCM.EngineIn.TrqOpt 		= IF->EngineIn.TrqOpt;
    in->FromCM.EngineIn.FuelFlow	= IF->EngineIn.FuelFlow;

    // Motor
    in->FromCM.MCU_Status	= IF-> MCU_Status;

    in->FromCM.ISGIn.rotv	= IF->ISGIn.rotv;
    in->FromCM.ISGIn.Trq	= IF->ISGIn.Trq;
    in->FromCM.ISGIn.TrqMot_max	= IF->ISGIn.TrqMot_max;
    in->FromCM.ISGIn.TrqGen_max	= IF->ISGIn.TrqGen_max;
    in->FromCM.ISGIn.PwrElec	= IF->ISGIn.PwrElec;

    in->FromCM.MotorIn.m0.rotv		= IF->MotorIn[0].rotv;
    in->FromCM.MotorIn.m0.Trq		= IF->MotorIn[0].Trq;
    in->FromCM.MotorIn.m0.TrqMot_max	= IF->MotorIn[0].TrqMot_max;
    in->FromCM.MotorIn.m0.TrqGen_max	= IF->MotorIn[0].TrqGen_max;
    in->FromCM.MotorIn.m0.PwrElec	= IF->MotorIn[0].PwrElec;

    in->FromCM.MotorIn.m1.rotv		= IF->MotorIn[1].rotv;
    in->FromCM.MotorIn.m1.Trq		= IF->MotorIn[1].Trq;
    in->FromCM.MotorIn.m1.TrqMot_max	= IF->MotorIn[1].TrqMot_max;
    in->FromCM.MotorIn.m1.TrqGen_max	= IF->MotorIn[1].TrqGen_max;
    in->FromCM.MotorIn.m1.PwrElec	= IF->MotorIn[1].PwrElec;

#if defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.MotorIn.m2.rotv		= IF->MotorIn[2].rotv;
    in->FromCM.MotorIn.m2.Trq		= IF->MotorIn[2].Trq;
    in->FromCM.MotorIn.m2.TrqMot_max	= IF->MotorIn[2].TrqMot_max;
    in->FromCM.MotorIn.m2.TrqGen_max	= IF->MotorIn[2].TrqGen_max;
    in->FromCM.MotorIn.m2.PwrElec	= IF->MotorIn[2].PwrElec;

    in->FromCM.MotorIn.m3.rotv		= IF->MotorIn[3].rotv;
    in->FromCM.MotorIn.m3.Trq		= IF->MotorIn[3].Trq;
    in->FromCM.MotorIn.m3.TrqMot_max	= IF->MotorIn[3].TrqMot_max;
    in->FromCM.MotorIn.m3.TrqGen_max	= IF->MotorIn[3].TrqGen_max;
    in->FromCM.MotorIn.m3.PwrElec	= IF->MotorIn[3].PwrElec;
#endif
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m4.rotv		= IF->MotorIn[4].rotv;
    in->FromCM.MotorIn.m4.Trq		= IF->MotorIn[4].Trq;
    in->FromCM.MotorIn.m4.TrqMot_max	= IF->MotorIn[4].TrqMot_max;
    in->FromCM.MotorIn.m4.TrqGen_max	= IF->MotorIn[4].TrqGen_max;
    in->FromCM.MotorIn.m4.PwrElec	= IF->MotorIn[4].PwrElec;

    in->FromCM.MotorIn.m5.rotv		= IF->MotorIn[5].rotv;
    in->FromCM.MotorIn.m5.Trq		= IF->MotorIn[5].Trq;
    in->FromCM.MotorIn.m5.TrqMot_max	= IF->MotorIn[5].TrqMot_max;
    in->FromCM.MotorIn.m5.TrqGen_max	= IF->MotorIn[5].TrqGen_max;
    in->FromCM.MotorIn.m5.PwrElec	= IF->MotorIn[5].PwrElec;

    in->FromCM.MotorIn.m6.rotv		= IF->MotorIn[6].rotv;
    in->FromCM.MotorIn.m6.Trq		= IF->MotorIn[6].Trq;
    in->FromCM.MotorIn.m6.TrqMot_max	= IF->MotorIn[6].TrqMot_max;
    in->FromCM.MotorIn.m6.TrqGen_max	= IF->MotorIn[6].TrqGen_max;
    in->FromCM.MotorIn.m6.PwrElec	= IF->MotorIn[6].PwrElec;

    in->FromCM.MotorIn.m7.rotv		= IF->MotorIn[7].rotv;
    in->FromCM.MotorIn.m7.Trq		= IF->MotorIn[7].Trq;
    in->FromCM.MotorIn.m7.TrqMot_max	= IF->MotorIn[7].TrqMot_max;
    in->FromCM.MotorIn.m7.TrqGen_max	= IF->MotorIn[7].TrqGen_max;
    in->FromCM.MotorIn.m7.PwrElec	= IF->MotorIn[7].PwrElec;
#endif

#if defined (IS_MCYCLE)
    in->FromCM.ISGIn.i_M2W.F	= IF->ISGIn.i_M2W[0];
    in->FromCM.ISGIn.i_M2W.R	= IF->ISGIn.i_M2W[1];
#elif defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.ISGIn.i_M2W.FL	= IF->ISGIn.i_M2W[0];
    in->FromCM.ISGIn.i_M2W.FR	= IF->ISGIn.i_M2W[1];
    in->FromCM.ISGIn.i_M2W.RL	= IF->ISGIn.i_M2W[2];
    in->FromCM.ISGIn.i_M2W.RR	= IF->ISGIn.i_M2W[3];
#endif
#if defined (IS_TRUCK)
    in->FromCM.ISGIn.i_M2W.RL2	= IF->ISGIn.i_M2W[4];
    in->FromCM.ISGIn.i_M2W.RR2	= IF->ISGIn.i_M2W[5];
    in->FromCM.ISGIn.i_M2W.FL2	= IF->ISGIn.i_M2W[6];
    in->FromCM.ISGIn.i_M2W.FR2	= IF->ISGIn.i_M2W[7];
#endif

#if defined (IS_MCYCLE)
    in->FromCM.MotorIn.m0.i_M2W.F	= IF->MotorIn[0].i_M2W[0];
    in->FromCM.MotorIn.m0.i_M2W.R	= IF->MotorIn[0].i_M2W[1];
#elif defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.MotorIn.m0.i_M2W.FL	= IF->MotorIn[0].i_M2W[0];
    in->FromCM.MotorIn.m0.i_M2W.FR	= IF->MotorIn[0].i_M2W[1];
    in->FromCM.MotorIn.m0.i_M2W.RL	= IF->MotorIn[0].i_M2W[2];
    in->FromCM.MotorIn.m0.i_M2W.RR	= IF->MotorIn[0].i_M2W[3];
#endif
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m0.i_M2W.RL2	= IF->MotorIn[0].i_M2W[4];
    in->FromCM.MotorIn.m0.i_M2W.RR2	= IF->MotorIn[0].i_M2W[5];
    in->FromCM.MotorIn.m0.i_M2W.FL2	= IF->MotorIn[0].i_M2W[6];
    in->FromCM.MotorIn.m0.i_M2W.FR2	= IF->MotorIn[0].i_M2W[7];
#endif

#if defined (IS_MCYCLE)
    in->FromCM.MotorIn.m1.i_M2W.F	= IF->MotorIn[1].i_M2W[0];
    in->FromCM.MotorIn.m1.i_M2W.R	= IF->MotorIn[1].i_M2W[1];
#elif defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.MotorIn.m1.i_M2W.FL	= IF->MotorIn[1].i_M2W[0];
    in->FromCM.MotorIn.m1.i_M2W.FR	= IF->MotorIn[1].i_M2W[1];
    in->FromCM.MotorIn.m1.i_M2W.RL	= IF->MotorIn[1].i_M2W[2];
    in->FromCM.MotorIn.m1.i_M2W.RR	= IF->MotorIn[1].i_M2W[3];
#endif
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m1.i_M2W.RL2	= IF->MotorIn[1].i_M2W[4];
    in->FromCM.MotorIn.m1.i_M2W.RR2	= IF->MotorIn[1].i_M2W[5];
    in->FromCM.MotorIn.m1.i_M2W.FL2	= IF->MotorIn[1].i_M2W[6];
    in->FromCM.MotorIn.m1.i_M2W.FR2	= IF->MotorIn[1].i_M2W[7];
#endif

#if defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.MotorIn.m2.i_M2W.FL	= IF->MotorIn[2].i_M2W[0];
    in->FromCM.MotorIn.m2.i_M2W.FR	= IF->MotorIn[2].i_M2W[1];
    in->FromCM.MotorIn.m2.i_M2W.RL	= IF->MotorIn[2].i_M2W[2];
    in->FromCM.MotorIn.m2.i_M2W.RR	= IF->MotorIn[2].i_M2W[3];
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m2.i_M2W.RL2	= IF->MotorIn[2].i_M2W[4];
    in->FromCM.MotorIn.m2.i_M2W.RR2	= IF->MotorIn[2].i_M2W[5];
    in->FromCM.MotorIn.m2.i_M2W.FL2	= IF->MotorIn[2].i_M2W[6];
    in->FromCM.MotorIn.m2.i_M2W.FR2	= IF->MotorIn[2].i_M2W[7];
#endif

    in->FromCM.MotorIn.m3.i_M2W.FL	= IF->MotorIn[3].i_M2W[0];
    in->FromCM.MotorIn.m3.i_M2W.FR	= IF->MotorIn[3].i_M2W[1];
    in->FromCM.MotorIn.m3.i_M2W.RL	= IF->MotorIn[3].i_M2W[2];
    in->FromCM.MotorIn.m3.i_M2W.RR	= IF->MotorIn[3].i_M2W[3];
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m3.i_M2W.RL2	= IF->MotorIn[3].i_M2W[4];
    in->FromCM.MotorIn.m3.i_M2W.RR2	= IF->MotorIn[3].i_M2W[5];
    in->FromCM.MotorIn.m3.i_M2W.FL2	= IF->MotorIn[3].i_M2W[6];
    in->FromCM.MotorIn.m3.i_M2W.FR2	= IF->MotorIn[3].i_M2W[7];
#endif
#endif
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m4.i_M2W.FL	= IF->MotorIn[4].i_M2W[0];
    in->FromCM.MotorIn.m4.i_M2W.FR	= IF->MotorIn[4].i_M2W[1];
    in->FromCM.MotorIn.m4.i_M2W.RL	= IF->MotorIn[4].i_M2W[2];
    in->FromCM.MotorIn.m4.i_M2W.RR	= IF->MotorIn[4].i_M2W[3];
    in->FromCM.MotorIn.m4.i_M2W.RL2	= IF->MotorIn[4].i_M2W[4];
    in->FromCM.MotorIn.m4.i_M2W.RR2	= IF->MotorIn[4].i_M2W[5];
    in->FromCM.MotorIn.m4.i_M2W.FL2	= IF->MotorIn[4].i_M2W[6];
    in->FromCM.MotorIn.m4.i_M2W.FR2	= IF->MotorIn[4].i_M2W[7];

    in->FromCM.MotorIn.m5.i_M2W.FL	= IF->MotorIn[5].i_M2W[0];
    in->FromCM.MotorIn.m5.i_M2W.FR	= IF->MotorIn[5].i_M2W[1];
    in->FromCM.MotorIn.m5.i_M2W.RL	= IF->MotorIn[5].i_M2W[2];
    in->FromCM.MotorIn.m5.i_M2W.RR	= IF->MotorIn[5].i_M2W[3];
    in->FromCM.MotorIn.m5.i_M2W.RL2	= IF->MotorIn[5].i_M2W[4];
    in->FromCM.MotorIn.m5.i_M2W.RR2	= IF->MotorIn[5].i_M2W[5];
    in->FromCM.MotorIn.m5.i_M2W.FL2	= IF->MotorIn[5].i_M2W[6];
    in->FromCM.MotorIn.m5.i_M2W.FR2	= IF->MotorIn[5].i_M2W[7];

    in->FromCM.MotorIn.m6.i_M2W.FL	= IF->MotorIn[6].i_M2W[0];
    in->FromCM.MotorIn.m6.i_M2W.FR	= IF->MotorIn[6].i_M2W[1];
    in->FromCM.MotorIn.m6.i_M2W.RL	= IF->MotorIn[6].i_M2W[2];
    in->FromCM.MotorIn.m6.i_M2W.RR	= IF->MotorIn[6].i_M2W[3];
    in->FromCM.MotorIn.m6.i_M2W.RL2	= IF->MotorIn[6].i_M2W[4];
    in->FromCM.MotorIn.m6.i_M2W.RR2	= IF->MotorIn[6].i_M2W[5];
    in->FromCM.MotorIn.m6.i_M2W.FL2	= IF->MotorIn[6].i_M2W[6];
    in->FromCM.MotorIn.m6.i_M2W.FR2	= IF->MotorIn[6].i_M2W[7];

    in->FromCM.MotorIn.m7.i_M2W.FL	= IF->MotorIn[7].i_M2W[0];
    in->FromCM.MotorIn.m7.i_M2W.FR	= IF->MotorIn[7].i_M2W[1];
    in->FromCM.MotorIn.m7.i_M2W.RL	= IF->MotorIn[7].i_M2W[2];
    in->FromCM.MotorIn.m7.i_M2W.RR	= IF->MotorIn[7].i_M2W[3];
    in->FromCM.MotorIn.m7.i_M2W.RL2	= IF->MotorIn[7].i_M2W[4];
    in->FromCM.MotorIn.m7.i_M2W.RR2	= IF->MotorIn[7].i_M2W[5];
    in->FromCM.MotorIn.m7.i_M2W.FL2	= IF->MotorIn[7].i_M2W[6];
    in->FromCM.MotorIn.m7.i_M2W.FR2	= IF->MotorIn[7].i_M2W[7];
#endif

    // Clutch
    in->FromCM.TCU_Status 		= IF->TCU_Status;
    in->FromCM.ClutchIn.Pos 		= IF->ClutchIn.Pos;
    in->FromCM.ClutchIn.rotv_in 	= IF->ClutchIn.rotv_in;
    in->FromCM.ClutchIn.rotv_out	= IF->ClutchIn.rotv_out;
    in->FromCM.ClutchIn.Trq_in		= IF->ClutchIn.Trq_in;
    in->FromCM.ClutchIn.Trq_out		= IF->ClutchIn.Trq_out;
    in->FromCM.ClutchIn.i_TrqIn2Out	= IF->ClutchIn.i_TrqIn2Out;

    // GearBox
    in->FromCM.GearBoxIn.GearNo 		= IF->GearBoxIn.GearNo;
    in->FromCM.GearBoxIn.GearNo_dis 		= IF->GearBoxIn.GearNo_dis;
    in->FromCM.GearBoxIn.Trq_DriveSrc_trg	= IF->GearBoxIn.Trq_DriveSrc_trg;
    in->FromCM.GearBoxIn.i 			= IF->GearBoxIn.i;
    in->FromCM.GearBoxIn.rotv_in 		= IF->GearBoxIn.rotv_in;
    in->FromCM.GearBoxIn.rotv_out 		= IF->GearBoxIn.rotv_out;
    in->FromCM.GearBoxIn.Trq_in 		= IF->GearBoxIn.Trq_in;
    in->FromCM.GearBoxIn.Trq_out 		= IF->GearBoxIn.Trq_out;
    in->FromCM.GearBoxIn.Clutch.Pos 		= IF->GearBoxIn.Clutch.Pos;
    in->FromCM.GearBoxIn.Clutch.rotv_in 	= IF->GearBoxIn.Clutch.rotv_in;
    in->FromCM.GearBoxIn.Clutch.rotv_out 	= IF->GearBoxIn.Clutch.rotv_out;
    in->FromCM.GearBoxIn.Clutch.Trq_in 		= IF->GearBoxIn.Clutch.Trq_in;
    in->FromCM.GearBoxIn.Clutch.Trq_out 	= IF->GearBoxIn.Clutch.Trq_out;
    in->FromCM.GearBoxIn.Clutch.i_TrqIn2Out 	= IF->GearBoxIn.Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxIn.Clutch_dis.Pos 	= IF->GearBoxIn.Clutch_dis.Pos;
    in->FromCM.GearBoxIn.Clutch_dis.rotv_in 	= IF->GearBoxIn.Clutch_dis.rotv_in;
    in->FromCM.GearBoxIn.Clutch_dis.rotv_out 	= IF->GearBoxIn.Clutch_dis.rotv_out;
    in->FromCM.GearBoxIn.Clutch_dis.Trq_in 	= IF->GearBoxIn.Clutch_dis.Trq_in;
    in->FromCM.GearBoxIn.Clutch_dis.Trq_out 	= IF->GearBoxIn.Clutch_dis.Trq_out;
    in->FromCM.GearBoxIn.Clutch_dis.i_TrqIn2Out 	= IF->GearBoxIn.Clutch_dis.i_TrqIn2Out;

    in->FromCM.GearBoxM_In.GB_m0.GearNo 		= IF->GearBoxM_In[0].GearNo;
    in->FromCM.GearBoxM_In.GB_m0.GearNo_dis 		= IF->GearBoxM_In[0].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m0.Trq_DriveSrc_trg	= IF->GearBoxM_In[0].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m0.i 			= IF->GearBoxM_In[0].i;
    in->FromCM.GearBoxM_In.GB_m0.rotv_in 		= IF->GearBoxM_In[0].rotv_in;
    in->FromCM.GearBoxM_In.GB_m0.rotv_out 		= IF->GearBoxM_In[0].rotv_out;
    in->FromCM.GearBoxM_In.GB_m0.Trq_in 		= IF->GearBoxM_In[0].Trq_in;
    in->FromCM.GearBoxM_In.GB_m0.Trq_out 		= IF->GearBoxM_In[0].Trq_out;
    in->FromCM.GearBoxM_In.GB_m0.Clutch.Pos 		= IF->GearBoxM_In[0].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m0.Clutch.rotv_in 	= IF->GearBoxM_In[0].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m0.Clutch.rotv_out 	= IF->GearBoxM_In[0].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m0.Clutch.Trq_in 		= IF->GearBoxM_In[0].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m0.Clutch.Trq_out		= IF->GearBoxM_In[0].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m0.Clutch.i_TrqIn2Out	= IF->GearBoxM_In[0].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m0.Clutch_dis.Pos 	= IF->GearBoxM_In[0].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m0.Clutch_dis.rotv_in 	= IF->GearBoxM_In[0].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m0.Clutch_dis.rotv_out 	= IF->GearBoxM_In[0].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m0.Clutch_dis.Trq_in 	= IF->GearBoxM_In[0].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m0.Clutch_dis.Trq_out	= IF->GearBoxM_In[0].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m0.Clutch_dis.i_TrqIn2Out	= IF->GearBoxM_In[0].Clutch_dis.i_TrqIn2Out;

    in->FromCM.GearBoxM_In.GB_m1.GearNo 		= IF->GearBoxM_In[1].GearNo;
    in->FromCM.GearBoxM_In.GB_m1.GearNo_dis 		= IF->GearBoxM_In[1].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m1.Trq_DriveSrc_trg	= IF->GearBoxM_In[1].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m1.i 			= IF->GearBoxM_In[1].i;
    in->FromCM.GearBoxM_In.GB_m1.rotv_in 		= IF->GearBoxM_In[1].rotv_in;
    in->FromCM.GearBoxM_In.GB_m1.rotv_out 		= IF->GearBoxM_In[1].rotv_out;
    in->FromCM.GearBoxM_In.GB_m1.Trq_in 		= IF->GearBoxM_In[1].Trq_in;
    in->FromCM.GearBoxM_In.GB_m1.Trq_out 		= IF->GearBoxM_In[1].Trq_out;
    in->FromCM.GearBoxM_In.GB_m1.Clutch.Pos 		= IF->GearBoxM_In[1].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m1.Clutch.rotv_in 	= IF->GearBoxM_In[1].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m1.Clutch.rotv_out 	= IF->GearBoxM_In[1].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m1.Clutch.Trq_in 		= IF->GearBoxM_In[1].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m1.Clutch.Trq_out 	= IF->GearBoxM_In[1].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m1.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[1].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m1.Clutch_dis.Pos 	= IF->GearBoxM_In[1].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m1.Clutch_dis.rotv_in 	= IF->GearBoxM_In[1].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m1.Clutch_dis.rotv_out 	= IF->GearBoxM_In[1].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m1.Clutch_dis.Trq_in 	= IF->GearBoxM_In[1].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m1.Clutch_dis.Trq_out 	= IF->GearBoxM_In[1].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m1.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[1].Clutch_dis.i_TrqIn2Out;

#if defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.GearBoxM_In.GB_m2.GearNo 		= IF->GearBoxM_In[2].GearNo;
    in->FromCM.GearBoxM_In.GB_m2.GearNo_dis 		= IF->GearBoxM_In[2].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m2.Trq_DriveSrc_trg	= IF->GearBoxM_In[2].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m2.i 			= IF->GearBoxM_In[2].i;
    in->FromCM.GearBoxM_In.GB_m2.rotv_in 		= IF->GearBoxM_In[2].rotv_in;
    in->FromCM.GearBoxM_In.GB_m2.rotv_out 		= IF->GearBoxM_In[2].rotv_out;
    in->FromCM.GearBoxM_In.GB_m2.Trq_in 		= IF->GearBoxM_In[2].Trq_in;
    in->FromCM.GearBoxM_In.GB_m2.Trq_out 		= IF->GearBoxM_In[2].Trq_out;
    in->FromCM.GearBoxM_In.GB_m2.Clutch.Pos 		= IF->GearBoxM_In[2].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m2.Clutch.rotv_in 	= IF->GearBoxM_In[2].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m2.Clutch.rotv_out 	= IF->GearBoxM_In[2].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m2.Clutch.Trq_in 		= IF->GearBoxM_In[2].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m2.Clutch.Trq_out 	= IF->GearBoxM_In[2].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m2.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[2].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m2.Clutch_dis.Pos 	= IF->GearBoxM_In[2].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m2.Clutch_dis.rotv_in 	= IF->GearBoxM_In[2].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m2.Clutch_dis.rotv_out 	= IF->GearBoxM_In[2].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m2.Clutch_dis.Trq_in 	= IF->GearBoxM_In[2].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m2.Clutch_dis.Trq_out 	= IF->GearBoxM_In[2].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m2.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[2].Clutch_dis.i_TrqIn2Out;

    in->FromCM.GearBoxM_In.GB_m3.GearNo 		= IF->GearBoxM_In[3].GearNo;
    in->FromCM.GearBoxM_In.GB_m3.GearNo_dis 		= IF->GearBoxM_In[3].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m3.Trq_DriveSrc_trg	= IF->GearBoxM_In[3].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m3.i 			= IF->GearBoxM_In[3].i;
    in->FromCM.GearBoxM_In.GB_m3.rotv_in 		= IF->GearBoxM_In[3].rotv_in;
    in->FromCM.GearBoxM_In.GB_m3.rotv_out 		= IF->GearBoxM_In[3].rotv_out;
    in->FromCM.GearBoxM_In.GB_m3.Trq_in 		= IF->GearBoxM_In[3].Trq_in;
    in->FromCM.GearBoxM_In.GB_m3.Trq_out 		= IF->GearBoxM_In[3].Trq_out;
    in->FromCM.GearBoxM_In.GB_m3.Clutch.Pos 		= IF->GearBoxM_In[3].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m3.Clutch.rotv_in 	= IF->GearBoxM_In[3].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m3.Clutch.rotv_out 	= IF->GearBoxM_In[3].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m3.Clutch.Trq_in 		= IF->GearBoxM_In[3].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m3.Clutch.Trq_out 	= IF->GearBoxM_In[3].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m3.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[3].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m3.Clutch_dis.Pos 	= IF->GearBoxM_In[3].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m3.Clutch_dis.rotv_in 	= IF->GearBoxM_In[3].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m3.Clutch_dis.rotv_out 	= IF->GearBoxM_In[3].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m3.Clutch_dis.Trq_in 	= IF->GearBoxM_In[3].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m3.Clutch_dis.Trq_out 	= IF->GearBoxM_In[3].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m3.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[3].Clutch_dis.i_TrqIn2Out;
#endif
#if defined (IS_TRUCK)
    in->FromCM.GearBoxM_In.GB_m4.GearNo 		= IF->GearBoxM_In[4].GearNo;
    in->FromCM.GearBoxM_In.GB_m4.GearNo_dis 		= IF->GearBoxM_In[4].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m4.Trq_DriveSrc_trg	= IF->GearBoxM_In[4].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m4.i 			= IF->GearBoxM_In[4].i;
    in->FromCM.GearBoxM_In.GB_m4.rotv_in 		= IF->GearBoxM_In[4].rotv_in;
    in->FromCM.GearBoxM_In.GB_m4.rotv_out 		= IF->GearBoxM_In[4].rotv_out;
    in->FromCM.GearBoxM_In.GB_m4.Trq_in 		= IF->GearBoxM_In[4].Trq_in;
    in->FromCM.GearBoxM_In.GB_m4.Trq_out 		= IF->GearBoxM_In[4].Trq_out;
    in->FromCM.GearBoxM_In.GB_m4.Clutch.Pos 		= IF->GearBoxM_In[4].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m4.Clutch.rotv_in 	= IF->GearBoxM_In[4].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m4.Clutch.rotv_out 	= IF->GearBoxM_In[4].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m4.Clutch.Trq_in 		= IF->GearBoxM_In[4].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m4.Clutch.Trq_out 	= IF->GearBoxM_In[4].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m4.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[4].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m4.Clutch_dis.Pos 	= IF->GearBoxM_In[4].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m4.Clutch_dis.rotv_in 	= IF->GearBoxM_In[4].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m4.Clutch_dis.rotv_out 	= IF->GearBoxM_In[4].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m4.Clutch_dis.Trq_in 	= IF->GearBoxM_In[4].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m4.Clutch_dis.Trq_out 	= IF->GearBoxM_In[4].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m4.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[4].Clutch_dis.i_TrqIn2Out;

    in->FromCM.GearBoxM_In.GB_m5.GearNo 		= IF->GearBoxM_In[5].GearNo;
    in->FromCM.GearBoxM_In.GB_m5.GearNo_dis 		= IF->GearBoxM_In[5].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m5.Trq_DriveSrc_trg	= IF->GearBoxM_In[5].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m5.i 			= IF->GearBoxM_In[5].i;
    in->FromCM.GearBoxM_In.GB_m5.rotv_in 		= IF->GearBoxM_In[5].rotv_in;
    in->FromCM.GearBoxM_In.GB_m5.rotv_out 		= IF->GearBoxM_In[5].rotv_out;
    in->FromCM.GearBoxM_In.GB_m5.Trq_in 		= IF->GearBoxM_In[5].Trq_in;
    in->FromCM.GearBoxM_In.GB_m5.Trq_out 		= IF->GearBoxM_In[5].Trq_out;
    in->FromCM.GearBoxM_In.GB_m5.Clutch.Pos 		= IF->GearBoxM_In[5].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m5.Clutch.rotv_in 	= IF->GearBoxM_In[5].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m5.Clutch.rotv_out 	= IF->GearBoxM_In[5].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m5.Clutch.Trq_in 		= IF->GearBoxM_In[5].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m5.Clutch.Trq_out 	= IF->GearBoxM_In[5].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m5.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[5].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m5.Clutch_dis.Pos 	= IF->GearBoxM_In[5].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m5.Clutch_dis.rotv_in 	= IF->GearBoxM_In[5].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m5.Clutch_dis.rotv_out 	= IF->GearBoxM_In[5].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m5.Clutch_dis.Trq_in 	= IF->GearBoxM_In[5].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m5.Clutch_dis.Trq_out 	= IF->GearBoxM_In[5].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m5.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[5].Clutch_dis.i_TrqIn2Out;

    in->FromCM.GearBoxM_In.GB_m6.GearNo 		= IF->GearBoxM_In[6].GearNo;
    in->FromCM.GearBoxM_In.GB_m6.GearNo_dis 		= IF->GearBoxM_In[6].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m6.Trq_DriveSrc_trg	= IF->GearBoxM_In[6].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m6.i 			= IF->GearBoxM_In[6].i;
    in->FromCM.GearBoxM_In.GB_m6.rotv_in 		= IF->GearBoxM_In[6].rotv_in;
    in->FromCM.GearBoxM_In.GB_m6.rotv_out 		= IF->GearBoxM_In[6].rotv_out;
    in->FromCM.GearBoxM_In.GB_m6.Trq_in 		= IF->GearBoxM_In[6].Trq_in;
    in->FromCM.GearBoxM_In.GB_m6.Trq_out 		= IF->GearBoxM_In[6].Trq_out;
    in->FromCM.GearBoxM_In.GB_m6.Clutch.Pos 		= IF->GearBoxM_In[6].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m6.Clutch.rotv_in 	= IF->GearBoxM_In[6].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m6.Clutch.rotv_out 	= IF->GearBoxM_In[6].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m6.Clutch.Trq_in 		= IF->GearBoxM_In[6].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m6.Clutch.Trq_out 	= IF->GearBoxM_In[6].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m6.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[6].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m6.Clutch_dis.Pos 	= IF->GearBoxM_In[6].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m6.Clutch_dis.rotv_in 	= IF->GearBoxM_In[6].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m6.Clutch_dis.rotv_out 	= IF->GearBoxM_In[6].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m6.Clutch_dis.Trq_in 	= IF->GearBoxM_In[6].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m6.Clutch_dis.Trq_out 	= IF->GearBoxM_In[6].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m6.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[6].Clutch_dis.i_TrqIn2Out;

    in->FromCM.GearBoxM_In.GB_m7.GearNo 		= IF->GearBoxM_In[7].GearNo;
    in->FromCM.GearBoxM_In.GB_m7.GearNo_dis 		= IF->GearBoxM_In[7].GearNo_dis;
    in->FromCM.GearBoxM_In.GB_m7.Trq_DriveSrc_trg	= IF->GearBoxM_In[7].Trq_DriveSrc_trg;
    in->FromCM.GearBoxM_In.GB_m7.i 			= IF->GearBoxM_In[7].i;
    in->FromCM.GearBoxM_In.GB_m7.rotv_in 		= IF->GearBoxM_In[7].rotv_in;
    in->FromCM.GearBoxM_In.GB_m7.rotv_out 		= IF->GearBoxM_In[7].rotv_out;
    in->FromCM.GearBoxM_In.GB_m7.Trq_in 		= IF->GearBoxM_In[7].Trq_in;
    in->FromCM.GearBoxM_In.GB_m7.Trq_out 		= IF->GearBoxM_In[7].Trq_out;
    in->FromCM.GearBoxM_In.GB_m7.Clutch.Pos 		= IF->GearBoxM_In[7].Clutch.Pos;
    in->FromCM.GearBoxM_In.GB_m7.Clutch.rotv_in 	= IF->GearBoxM_In[7].Clutch.rotv_in;
    in->FromCM.GearBoxM_In.GB_m7.Clutch.rotv_out 	= IF->GearBoxM_In[7].Clutch.rotv_out;
    in->FromCM.GearBoxM_In.GB_m7.Clutch.Trq_in 		= IF->GearBoxM_In[7].Clutch.Trq_in;
    in->FromCM.GearBoxM_In.GB_m7.Clutch.Trq_out 	= IF->GearBoxM_In[7].Clutch.Trq_out;
    in->FromCM.GearBoxM_In.GB_m7.Clutch.i_TrqIn2Out 	= IF->GearBoxM_In[7].Clutch.i_TrqIn2Out;
    in->FromCM.GearBoxM_In.GB_m7.Clutch_dis.Pos 	= IF->GearBoxM_In[7].Clutch_dis.Pos;
    in->FromCM.GearBoxM_In.GB_m7.Clutch_dis.rotv_in 	= IF->GearBoxM_In[7].Clutch_dis.rotv_in;
    in->FromCM.GearBoxM_In.GB_m7.Clutch_dis.rotv_out 	= IF->GearBoxM_In[7].Clutch_dis.rotv_out;
    in->FromCM.GearBoxM_In.GB_m7.Clutch_dis.Trq_in 	= IF->GearBoxM_In[7].Clutch_dis.Trq_in;
    in->FromCM.GearBoxM_In.GB_m7.Clutch_dis.Trq_out 	= IF->GearBoxM_In[7].Clutch_dis.Trq_out;
    in->FromCM.GearBoxM_In.GB_m7.Clutch_dis.i_TrqIn2Out = IF->GearBoxM_In[7].Clutch_dis.i_TrqIn2Out;
#endif

    // Battery
    in->FromCM.BCU_Status = IF->BCU_Status;

    in->FromCM.BattLVIn.SOC 	= IF->BattLVIn.SOC;
    in->FromCM.BattLVIn.SOH 	= IF->BattLVIn.SOH;
    in->FromCM.BattLVIn.Current = IF->BattLVIn.Current;
    in->FromCM.BattLVIn.AOC 	= IF->BattLVIn.AOC;
    in->FromCM.BattLVIn.Temp 	= IF->BattLVIn.Temp;
    in->FromCM.BattLVIn.Energy 	= IF->BattLVIn.Energy;
    in->FromCM.BattLVIn.Pwr_max = IF->BattLVIn.Pwr_max;

    in->FromCM.BattHVIn.SOC 	= IF->BattHVIn.SOC;
    in->FromCM.BattHVIn.SOH 	= IF->BattHVIn.SOH;
    in->FromCM.BattHVIn.Current = IF->BattHVIn.Current;
    in->FromCM.BattHVIn.AOC 	= IF->BattHVIn.AOC;
    in->FromCM.BattHVIn.Temp 	= IF->BattHVIn.Temp;
    in->FromCM.BattHVIn.Energy 	= IF->BattHVIn.Energy;
    in->FromCM.BattHVIn.Pwr_max = IF->BattHVIn.Pwr_max;

    // PowerSupply
    in->FromCM.PwrSupplyIn.Pwr_LV		= IF->PwrSupplyIn.Pwr_LV;
    in->FromCM.PwrSupplyIn.Pwr_HV1		= IF->PwrSupplyIn.Pwr_HV1;
    in->FromCM.PwrSupplyIn.Pwr_HV2		= IF->PwrSupplyIn.Pwr_HV2;
    in->FromCM.PwrSupplyIn.Voltage_LV		= IF->PwrSupplyIn.Voltage_LV;
    in->FromCM.PwrSupplyIn.Voltage_HV1		= IF->PwrSupplyIn.Voltage_HV1;
    in->FromCM.PwrSupplyIn.Voltage_HV2		= IF->PwrSupplyIn.Voltage_HV2;
    in->FromCM.PwrSupplyIn.Pwr_HV1toLV		= IF->PwrSupplyIn.Pwr_HV1toLV;
    in->FromCM.PwrSupplyIn.Pwr_HV1toHV2		= IF->PwrSupplyIn.Pwr_HV1toHV2;
    in->FromCM.PwrSupplyIn.Pwr_HV1toLV_max	= IF->PwrSupplyIn.Pwr_HV1toLV_max;
    in->FromCM.PwrSupplyIn.Pwr_HV1toHV2_max	= IF->PwrSupplyIn.Pwr_HV1toHV2_max;
    in->FromCM.PwrSupplyIn.Eta_HV1toLV		= IF->PwrSupplyIn.Eta_HV1toLV;
    in->FromCM.PwrSupplyIn.Eta_HV1toHV2		= IF->PwrSupplyIn.Eta_HV1toHV2;


    // Wheels
#if defined (IS_MCYCLE)
    in->FromCM.WheelIn.F.Trq_BrakeReg_trg  = IF->WheelIn[0].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.R.Trq_BrakeReg_trg  = IF->WheelIn[1].Trq_BrakeReg_trg;
#elif defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.WheelIn.FL.Trq_BrakeReg_trg  = IF->WheelIn[0].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.FR.Trq_BrakeReg_trg  = IF->WheelIn[1].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.RL.Trq_BrakeReg_trg  = IF->WheelIn[2].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.RR.Trq_BrakeReg_trg  = IF->WheelIn[3].Trq_BrakeReg_trg;
#endif
#if defined (IS_TRUCK)
    in->FromCM.WheelIn.RL2.Trq_BrakeReg_trg = IF->WheelIn[4].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.RR2.Trq_BrakeReg_trg = IF->WheelIn[5].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.FL2.Trq_BrakeReg_trg = IF->WheelIn[6].Trq_BrakeReg_trg;
    in->FromCM.WheelIn.FR2.Trq_BrakeReg_trg = IF->WheelIn[7].Trq_BrakeReg_trg;
#endif

    in->FromCM.DriveSrcIn.d0.Trq_trg  = IF->DriveSrcIn[0].Trq_trg;
    in->FromCM.DriveSrcIn.d1.Trq_trg  = IF->DriveSrcIn[1].Trq_trg;
#if defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.DriveSrcIn.d2.Trq_trg  = IF->DriveSrcIn[2].Trq_trg;
    in->FromCM.DriveSrcIn.d3.Trq_trg  = IF->DriveSrcIn[3].Trq_trg;
#endif
#if defined (IS_TRUCK)
    in->FromCM.DriveSrcIn.d4.Trq_trg = IF->DriveSrcIn[4].Trq_trg;
    in->FromCM.DriveSrcIn.d5.Trq_trg = IF->DriveSrcIn[5].Trq_trg;
    in->FromCM.DriveSrcIn.d6.Trq_trg = IF->DriveSrcIn[6].Trq_trg;
    in->FromCM.DriveSrcIn.d7.Trq_trg = IF->DriveSrcIn[7].Trq_trg;
#endif

    if (SampleParams.UnderSampFac) {	// Undersampling
     	if (++SampleParams.UnderSampCount == SampleParams.UnderSampFac) {
	    SampleParams.UnderSampCount=0;
	    DoOneStep(rtm);
     	}
    } else { 				// Oversampling (1..OverSampFac)
	do {
	    DoOneStep(rtm);
	} while (++osCount < SampleParams.OverSampFac);
    }

    IF->OperationState	= out->ToCM.OperationState;
    IF->OperationError	= out->ToCM.OperationError;
    IF->StrategyMode	= out->ToCM.StrategyMode;
    IF->Ignition	= out->ToCM.Ignition;

    // Engine
    IF->EngineOut.set_ISC	= out->ToCM.EngineOut.set_ISC;
    IF->EngineOut.FuelCutOff	= out->ToCM.EngineOut.FuelCutOff;
    IF->EngineOut.Load		= out->ToCM.EngineOut.Load;
    IF->EngineOut.Trq_trg	= out->ToCM.EngineOut.Trq_trg;
    IF->EngineOut.rotv_trg	= out->ToCM.EngineOut.rotv_trg;

    // Motor
    IF->ISGOut.Load 	= out->ToCM.ISGOut.Load;
    IF->ISGOut.Trq_trg 	= out->ToCM.ISGOut.Trq_trg;
    IF->ISGOut.rotv_trg = out->ToCM.ISGOut.rotv_trg;
    IF->MotorOut[0].Load 	= out->ToCM.MotorOut.m0.Load;
    IF->MotorOut[0].Trq_trg     = out->ToCM.MotorOut.m0.Trq_trg;
    IF->MotorOut[0].rotv_trg    = out->ToCM.MotorOut.m0.rotv_trg;
    IF->MotorOut[1].Load 	= out->ToCM.MotorOut.m1.Load;
    IF->MotorOut[1].Trq_trg     = out->ToCM.MotorOut.m1.Trq_trg;
    IF->MotorOut[1].rotv_trg    = out->ToCM.MotorOut.m1.rotv_trg;
#if defined (IS_CAR) || defined (IS_TRUCK)
    IF->MotorOut[2].Load 	= out->ToCM.MotorOut.m2.Load;
    IF->MotorOut[2].Trq_trg     = out->ToCM.MotorOut.m2.Trq_trg;
    IF->MotorOut[2].rotv_trg    = out->ToCM.MotorOut.m2.rotv_trg;
    IF->MotorOut[3].Load 	= out->ToCM.MotorOut.m3.Load;
    IF->MotorOut[3].Trq_trg     = out->ToCM.MotorOut.m3.Trq_trg;
    IF->MotorOut[3].rotv_trg    = out->ToCM.MotorOut.m3.rotv_trg;
#endif
#if defined (IS_TRUCK)
    IF->MotorOut[4].Load 	= out->ToCM.MotorOut.m4.Load;
    IF->MotorOut[4].Trq_trg     = out->ToCM.MotorOut.m4.Trq_trg;
    IF->MotorOut[4].rotv_trg    = out->ToCM.MotorOut.m4.rotv_trg;
    IF->MotorOut[5].Load 	= out->ToCM.MotorOut.m5.Load;
    IF->MotorOut[5].Trq_trg     = out->ToCM.MotorOut.m5.Trq_trg;
    IF->MotorOut[5].rotv_trg    = out->ToCM.MotorOut.m5.rotv_trg;
    IF->MotorOut[6].Load 	= out->ToCM.MotorOut.m6.Load;
    IF->MotorOut[6].Trq_trg     = out->ToCM.MotorOut.m6.Trq_trg;
    IF->MotorOut[6].rotv_trg    = out->ToCM.MotorOut.m6.rotv_trg;
    IF->MotorOut[7].Load 	= out->ToCM.MotorOut.m7.Load;
    IF->MotorOut[7].Trq_trg     = out->ToCM.MotorOut.m7.Trq_trg;
    IF->MotorOut[7].rotv_trg    = out->ToCM.MotorOut.m7.rotv_trg;
#endif

    // Clutch
    IF->ClutchOut.Pos 		= out->ToCM.ClutchOut.Pos;
    IF->ClutchOut.rotv_out_trg 	= out->ToCM.ClutchOut.rotv_out_trg;
    IF->ClutchOut.Trq_out_trg 	= out->ToCM.ClutchOut.Trq_out_trg;

    // GearBox
    IF->GearBoxOut.GearNoTrg 		= out->ToCM.GearBoxOut.GearNoTrg;
    IF->GearBoxOut.GearNoTrg_dis 	= out->ToCM.GearBoxOut.GearNoTrg_dis;
    IF->GearBoxOut.i_trg	 	= out->ToCM.GearBoxOut.i_trg;
    IF->GearBoxOut.set_ParkBrake 	= out->ToCM.GearBoxOut.set_ParkBrake;
    IF->GearBoxOut.rotv_in_trg 		= out->ToCM.GearBoxOut.rotv_in_trg;
    IF->GearBoxOut.Trq_out_trg 		= out->ToCM.GearBoxOut.Trq_out_trg;
    IF->GearBoxOut.Clutch.Pos		= out->ToCM.GearBoxOut.Clutch.Pos;
    IF->GearBoxOut.Clutch.rotv_out_trg	= out->ToCM.GearBoxOut.Clutch.rotv_out_trg;
    IF->GearBoxOut.Clutch.Trq_out_trg	= out->ToCM.GearBoxOut.Clutch.Trq_out_trg;
    IF->GearBoxOut.Clutch_dis.Pos	= out->ToCM.GearBoxOut.Clutch_dis.Pos;
    IF->GearBoxOut.Clutch_dis.rotv_out_trg= out->ToCM.GearBoxOut.Clutch_dis.rotv_out_trg;
    IF->GearBoxOut.Clutch_dis.Trq_out_trg= out->ToCM.GearBoxOut.Clutch_dis.Trq_out_trg;

    IF->GearBoxM_Out[0].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m0.GearNoTrg;
    IF->GearBoxM_Out[0].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m0.GearNoTrg_dis;
    IF->GearBoxM_Out[0].i_trg	 		= out->ToCM.GearBoxM_Out.GB_m0.i_trg;
    IF->GearBoxM_Out[0].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m0.set_ParkBrake;
    IF->GearBoxM_Out[0].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m0.rotv_in_trg;
    IF->GearBoxM_Out[0].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m0.Trq_out_trg;
    IF->GearBoxM_Out[0].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m0.Clutch.Pos;
    IF->GearBoxM_Out[0].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m0.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[0].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m0.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[0].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m0.Clutch_dis.Pos;
    IF->GearBoxM_Out[0].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m0.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[0].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m0.Clutch_dis.Trq_out_trg;

    IF->GearBoxM_Out[1].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m1.GearNoTrg;
    IF->GearBoxM_Out[1].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m1.GearNoTrg_dis;
    IF->GearBoxM_Out[1].i_trg	 		= out->ToCM.GearBoxM_Out.GB_m1.i_trg;
    IF->GearBoxM_Out[1].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m1.set_ParkBrake;
    IF->GearBoxM_Out[1].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m1.rotv_in_trg;
    IF->GearBoxM_Out[1].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m1.Trq_out_trg;
    IF->GearBoxM_Out[1].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m1.Clutch.Pos;
    IF->GearBoxM_Out[1].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m1.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[1].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m1.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[1].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m1.Clutch_dis.Pos;
    IF->GearBoxM_Out[1].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m1.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[1].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m1.Clutch_dis.Trq_out_trg;

#if defined (IS_CAR) || defined (IS_TRUCK)
    IF->GearBoxM_Out[2].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m2.GearNoTrg;
    IF->GearBoxM_Out[2].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m2.GearNoTrg_dis;
    IF->GearBoxM_Out[2].i_trg	 		= out->ToCM.GearBoxM_Out.GB_m2.i_trg;
    IF->GearBoxM_Out[2].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m2.set_ParkBrake;
    IF->GearBoxM_Out[2].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m2.rotv_in_trg;
    IF->GearBoxM_Out[2].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m2.Trq_out_trg;
    IF->GearBoxM_Out[2].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m2.Clutch.Pos;
    IF->GearBoxM_Out[2].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m2.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[2].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m2.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[2].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m2.Clutch_dis.Pos;
    IF->GearBoxM_Out[2].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m2.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[2].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m2.Clutch_dis.Trq_out_trg;

    IF->GearBoxM_Out[3].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m3.GearNoTrg;
    IF->GearBoxM_Out[3].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m3.GearNoTrg_dis;
    IF->GearBoxM_Out[3].i_trg	 	        = out->ToCM.GearBoxM_Out.GB_m3.i_trg;
    IF->GearBoxM_Out[3].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m3.set_ParkBrake;
    IF->GearBoxM_Out[3].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m3.rotv_in_trg;
    IF->GearBoxM_Out[3].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m3.Trq_out_trg;
    IF->GearBoxM_Out[3].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m3.Clutch.Pos;
    IF->GearBoxM_Out[3].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m3.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[3].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m3.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[3].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m3.Clutch_dis.Pos;
    IF->GearBoxM_Out[3].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m3.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[3].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m3.Clutch_dis.Trq_out_trg;
#endif
#if defined (IS_TRUCK)
    IF->GearBoxM_Out[4].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m4.GearNoTrg;
    IF->GearBoxM_Out[4].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m4.GearNoTrg_dis;
    IF->GearBoxM_Out[4].i_trg	 		= out->ToCM.GearBoxM_Out.GB_m4.i_trg;
    IF->GearBoxM_Out[4].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m4.set_ParkBrake;
    IF->GearBoxM_Out[4].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m4.rotv_in_trg;
    IF->GearBoxM_Out[4].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m4.Trq_out_trg;
    IF->GearBoxM_Out[4].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m4.Clutch.Pos;
    IF->GearBoxM_Out[4].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m4.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[4].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m4.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[4].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m4.Clutch_dis.Pos;
    IF->GearBoxM_Out[4].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m4.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[4].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m4.Clutch_dis.Trq_out_trg;

    IF->GearBoxM_Out[5].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m5.GearNoTrg;
    IF->GearBoxM_Out[5].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m5.GearNoTrg_dis;
    IF->GearBoxM_Out[5].i_trg	 	        = out->ToCM.GearBoxM_Out.GB_m5.i_trg;
    IF->GearBoxM_Out[5].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m5.set_ParkBrake;
    IF->GearBoxM_Out[5].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m5.rotv_in_trg;
    IF->GearBoxM_Out[5].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m5.Trq_out_trg;
    IF->GearBoxM_Out[5].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m5.Clutch.Pos;
    IF->GearBoxM_Out[5].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m5.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[5].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m5.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[5].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m5.Clutch_dis.Pos;
    IF->GearBoxM_Out[5].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m5.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[5].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m5.Clutch_dis.Trq_out_trg;

    IF->GearBoxM_Out[6].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m6.GearNoTrg;
    IF->GearBoxM_Out[6].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m6.GearNoTrg_dis;
    IF->GearBoxM_Out[6].i_trg	 	        = out->ToCM.GearBoxM_Out.GB_m6.i_trg;
    IF->GearBoxM_Out[6].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m6.set_ParkBrake;
    IF->GearBoxM_Out[6].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m6.rotv_in_trg;
    IF->GearBoxM_Out[6].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m6.Trq_out_trg;
    IF->GearBoxM_Out[6].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m6.Clutch.Pos;
    IF->GearBoxM_Out[6].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m6.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[6].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m6.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[6].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m6.Clutch_dis.Pos;
    IF->GearBoxM_Out[6].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m6.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[6].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m6.Clutch_dis.Trq_out_trg;

    IF->GearBoxM_Out[7].GearNoTrg 		= out->ToCM.GearBoxM_Out.GB_m7.GearNoTrg;
    IF->GearBoxM_Out[7].GearNoTrg_dis 		= out->ToCM.GearBoxM_Out.GB_m7.GearNoTrg_dis;
    IF->GearBoxM_Out[7].i_trg	 	        = out->ToCM.GearBoxM_Out.GB_m7.i_trg;
    IF->GearBoxM_Out[7].set_ParkBrake 	        = out->ToCM.GearBoxM_Out.GB_m7.set_ParkBrake;
    IF->GearBoxM_Out[7].rotv_in_trg 		= out->ToCM.GearBoxM_Out.GB_m7.rotv_in_trg;
    IF->GearBoxM_Out[7].Trq_out_trg 		= out->ToCM.GearBoxM_Out.GB_m7.Trq_out_trg;
    IF->GearBoxM_Out[7].Clutch.Pos		= out->ToCM.GearBoxM_Out.GB_m7.Clutch.Pos;
    IF->GearBoxM_Out[7].Clutch.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m7.Clutch.rotv_out_trg;
    IF->GearBoxM_Out[7].Clutch.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m7.Clutch.Trq_out_trg;
    IF->GearBoxM_Out[7].Clutch_dis.Pos		= out->ToCM.GearBoxM_Out.GB_m7.Clutch_dis.Pos;
    IF->GearBoxM_Out[7].Clutch_dis.rotv_out_trg	= out->ToCM.GearBoxM_Out.GB_m7.Clutch_dis.rotv_out_trg;
    IF->GearBoxM_Out[7].Clutch_dis.Trq_out_trg	= out->ToCM.GearBoxM_Out.GB_m7.Clutch_dis.Trq_out_trg;
#endif

    // PwrSupply
    IF->PwrSupplyOut.Pwr_HV1toLV_trg	= out->ToCM.PwrSupplyOut.Pwr_HV1toLV_trg;

    // Wheels
#if defined (IS_MCYCLE)
    IF->WheelOut[0].Trq_BrakeReg     = out->ToCM.WheelOut.F.Trq_BrakeReg;
    IF->WheelOut[0].Trq_BrakeReg_max = out->ToCM.WheelOut.F.Trq_BrakeReg_max;
    IF->WheelOut[1].Trq_BrakeReg     = out->ToCM.WheelOut.R.Trq_BrakeReg;
    IF->WheelOut[1].Trq_BrakeReg_max = out->ToCM.WheelOut.R.Trq_BrakeReg_max;
#elif defined (IS_CAR) || defined (IS_TRUCK)
    IF->WheelOut[0].Trq_BrakeReg     = out->ToCM.WheelOut.FL.Trq_BrakeReg;
    IF->WheelOut[0].Trq_BrakeReg_max = out->ToCM.WheelOut.FL.Trq_BrakeReg_max;
    IF->WheelOut[1].Trq_BrakeReg     = out->ToCM.WheelOut.FR.Trq_BrakeReg;
    IF->WheelOut[1].Trq_BrakeReg_max = out->ToCM.WheelOut.FR.Trq_BrakeReg_max;
    IF->WheelOut[2].Trq_BrakeReg     = out->ToCM.WheelOut.RL.Trq_BrakeReg;
    IF->WheelOut[2].Trq_BrakeReg_max = out->ToCM.WheelOut.RL.Trq_BrakeReg_max;
    IF->WheelOut[3].Trq_BrakeReg     = out->ToCM.WheelOut.RR.Trq_BrakeReg;
    IF->WheelOut[3].Trq_BrakeReg_max = out->ToCM.WheelOut.RR.Trq_BrakeReg_max;
#endif
#if defined (IS_TRUCK)
    IF->WheelOut[4].Trq_BrakeReg     = out->ToCM.WheelOut.RL2.Trq_BrakeReg;
    IF->WheelOut[4].Trq_BrakeReg_max = out->ToCM.WheelOut.RL2.Trq_BrakeReg_max;
    IF->WheelOut[5].Trq_BrakeReg     = out->ToCM.WheelOut.RR2.Trq_BrakeReg;
    IF->WheelOut[5].Trq_BrakeReg_max = out->ToCM.WheelOut.RR2.Trq_BrakeReg_max;
    IF->WheelOut[6].Trq_BrakeReg     = out->ToCM.WheelOut.FL2.Trq_BrakeReg;
    IF->WheelOut[6].Trq_BrakeReg_max = out->ToCM.WheelOut.FL2.Trq_BrakeReg_max;
    IF->WheelOut[7].Trq_BrakeReg     = out->ToCM.WheelOut.FR2.Trq_BrakeReg;
    IF->WheelOut[7].Trq_BrakeReg_max = out->ToCM.WheelOut.FR2.Trq_BrakeReg_max;
#endif

    return 0;
}


int
UNICARPTControl_Register (void)
{
    tModelClassDescr m;

    /*Log("%s_Register()\n", Modelname);*/

    memset(&m, 0, sizeof(m));

    /* Parameter file identification number.
       You may change CompatVersionId to the the lowest parameter
       file version understood by your model code. */
    m.PTControl.VersionId		= PARAMID;
    m.PTControl.CompatVersionId		= m.PTControl.VersionId;

    m.PTControl.DeclQuants		= UNICARPTControl_DeclQuants;
    m.PTControl.New			= UNICARPTControl_New;
    m.PTControl.Calc			= UNICARPTControl_Calc;
    m.PTControl.Delete			= UNICARPTControl_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    // m.PTControl.ParamsChanged	= ParamsChanged_IgnoreCheck;

    return Model_Register(Modelclass, Modelname, &m);
}

