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

#include "UNICARPTMotorCU.h"
#include "UNICARPTMotorCU_wrap.h"


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

extern const char UNICARPTMotorCU_LibIdent[];
const char UNICARPTMotorCU_LibIdent[] = "(@@)" QUOTE(MODEL) " " ARCH " 1.0 " BUILDDATE;

static const char Modelname[] = QUOTE(MODEL);
static const tModelClass Modelclass = ModelClass_PTMotorCU;
static tMatSuppSampling SampleParams;


static void
DoOneStep (rtModel_UNICARPTMotorCU *rtm)
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
UNICARPTMotorCU_DeclQuants (void *MP)
{
    rtModel_UNICARPTMotorCU *rtm = (rtModel_UNICARPTMotorCU *)MP;
    int i;

    /*Log("%s_DeclQuants()\n", Modelname);*/

    if (rtm == NULL) {
	/* Remember body frames defined in this model for later registration. */
        MdlBdyFrame_Add(UNICARPTMotorCU_BdyFrameDefines);

	/* Define dict entries for non-dynamically allocated variables. */
	if ((i = MatSupp_DeclQuants(UNICARPTMotorCU_DictDefines)) >= 0) {
	    LogErrF(EC_Init, "Model '%s': Error defining quantity '%s'\n",
		    Modelname, UNICARPTMotorCU_DictDefines[i].Name);
	}

	/* Define dict entries for tunable parameters (with dummy address). */
	DeclParameterQuants(NULL);
    } else {
	/* Define dict entries for dynamically allocated variables. */
    }
}


/*
 * UNICARPTMotorCU_SetParams() will be invoked indirectly by the generated
 * model C code each time UNICARPTMotorCU_New() is called.
 */
void
UNICARPTMotorCU_SetParams (rtModel_UNICARPTMotorCU *rtm, struct tMatSuppTunables *tuns,
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
assignCfgIF (struct tPTMotorCU_CfgIF *CfgIF, void *MP)
{
    rtModel_UNICARPTMotorCU *rtm = (rtModel_UNICARPTMotorCU *)MP;
    int arraydim, nError = GetInfoErrorCount() + Log_nError;
    ExternalInputs_UNICARPTMotorCU  *in  = (ExternalInputs_UNICARPTMotorCU *) rtmGetU(rtm);

    /* CfgIF Input */
    in->CfgInFromCM.nMotor	= CfgIF->nMotor;

    in->CfgInFromCM.ISG.Ratio		= CfgIF->ISG.Ratio;
    in->CfgInFromCM.ISG.rotv_Mot_max	= CfgIF->ISG.rotv_Mot_max;
    in->CfgInFromCM.ISG.rotv_Gen_max	= CfgIF->ISG.rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.ISG.TrqMot_max.x) / sizeof(in->CfgInFromCM.ISG.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->ISG.TrqMot_max, arraydim, "ISG: Maximum motor torque",
    		    in->CfgInFromCM.ISG.TrqMot_max.x, in->CfgInFromCM.ISG.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.ISG.TrqGen_max.x) / sizeof(in->CfgInFromCM.ISG.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->ISG.TrqGen_max, arraydim, "ISG: Maximum generator torque",
    		    in->CfgInFromCM.ISG.TrqGen_max.x, in->CfgInFromCM.ISG.TrqGen_max.z);

    in->CfgInFromCM.Motor.m0.Ratio		= CfgIF->Motor[0].Ratio;
    in->CfgInFromCM.Motor.m0.rotv_Mot_max	= CfgIF->Motor[0].rotv_Mot_max;
    in->CfgInFromCM.Motor.m0.rotv_Gen_max	= CfgIF->Motor[0].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m0.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m0.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[0].TrqMot_max, arraydim, "Motor: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m0.TrqMot_max.x, in->CfgInFromCM.Motor.m0.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m0.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m0.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[0].TrqGen_max, arraydim, "Motor: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m0.TrqGen_max.x, in->CfgInFromCM.Motor.m0.TrqGen_max.z);

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
    in->CfgInFromCM.Motor.m2.Ratio		= CfgIF->Motor[2].Ratio;
    in->CfgInFromCM.Motor.m2.rotv_Mot_max	= CfgIF->Motor[2].rotv_Mot_max;
    in->CfgInFromCM.Motor.m2.rotv_Gen_max	= CfgIF->Motor[2].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m2.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m2.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[2].TrqMot_max, arraydim, "Motor2: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m2.TrqMot_max.x, in->CfgInFromCM.Motor.m2.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m2.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m2.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[2].TrqGen_max, arraydim, "Motor2: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m2.TrqGen_max.x, in->CfgInFromCM.Motor.m2.TrqGen_max.z);

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
    in->CfgInFromCM.Motor.m4.Ratio		= CfgIF->Motor[4].Ratio;
    in->CfgInFromCM.Motor.m4.rotv_Mot_max	= CfgIF->Motor[4].rotv_Mot_max;
    in->CfgInFromCM.Motor.m4.rotv_Gen_max	= CfgIF->Motor[4].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m4.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m4.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[4].TrqMot_max, arraydim, "Motor4: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m4.TrqMot_max.x, in->CfgInFromCM.Motor.m4.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m4.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m4.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[4].TrqGen_max, arraydim, "Motor4: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m4.TrqGen_max.x, in->CfgInFromCM.Motor.m4.TrqGen_max.z);

    in->CfgInFromCM.Motor.m5.Ratio		= CfgIF->Motor[5].Ratio;
    in->CfgInFromCM.Motor.m5.rotv_Mot_max	= CfgIF->Motor[5].rotv_Mot_max;
    in->CfgInFromCM.Motor.m5.rotv_Gen_max	= CfgIF->Motor[5].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m5.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m5.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[5].TrqMot_max, arraydim, "Motor5: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m5.TrqMot_max.x, in->CfgInFromCM.Motor.m5.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m5.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m5.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[5].TrqGen_max, arraydim, "Motor5: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m5.TrqGen_max.x, in->CfgInFromCM.Motor.m5.TrqGen_max.z);

    in->CfgInFromCM.Motor.m6.Ratio		= CfgIF->Motor[6].Ratio;
    in->CfgInFromCM.Motor.m6.rotv_Mot_max	= CfgIF->Motor[6].rotv_Mot_max;
    in->CfgInFromCM.Motor.m6.rotv_Gen_max	= CfgIF->Motor[6].rotv_Gen_max;

    arraydim = sizeof(in->CfgInFromCM.Motor.m6.TrqMot_max.x) / sizeof(in->CfgInFromCM.Motor.m6.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[6].TrqMot_max, arraydim, "Motor6: Maximum motor torque",
    		    in->CfgInFromCM.Motor.m6.TrqMot_max.x, in->CfgInFromCM.Motor.m6.TrqMot_max.z);

    arraydim = sizeof(in->CfgInFromCM.Motor.m6.TrqGen_max.x) / sizeof(in->CfgInFromCM.Motor.m6.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->Motor[6].TrqGen_max, arraydim, "Motor6: Maximum generator torque",
    		    in->CfgInFromCM.Motor.m6.TrqGen_max.x, in->CfgInFromCM.Motor.m6.TrqGen_max.z);

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

    if (GetInfoErrorCount() + Log_nError != nError) {
    	goto ErrorReturn;
    }

    return rtm;

  ErrorReturn:
    return NULL;
}


static void *
UNICARPTMotorCU_New (struct tInfos *Inf, struct tPTMotorCU_CfgIF *CfgIF, const char *KindKey)
{
    rtModel_UNICARPTMotorCU *rtm;
    double rtmSampleTime;
    const char *ModelKind;
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, Modelclass, KindKey,
	 				 0, PARAMID, &VersionId)) == NULL)
	return NULL;

    /*Log("%s_New()\n", Modelname);*/
    if (iGetLongOpt (Inf,"PowerTrain.DL.FlexShaft" , 0))
	LogErrF(EC_Init, "Model '%s': Using flex shaft not allowed\n",Modelname);

    MatSupp_ResetQuants(UNICARPTMotorCU_DictDefines);

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
    if (MatSupp_Sampling (&SampleParams, SimCore.DeltaT/PowerTrain.OSRate, rtmSampleTime) !=0) {
	LogErrF(EC_Init, "Model '%s': The sample times of the plugin model and the application have to be integer multiples\n",Modelname);
	return NULL;
    }

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
UNICARPTMotorCU_Delete (void *MP)
{
    rtModel_UNICARPTMotorCU *rtm = (rtModel_UNICARPTMotorCU *)MP;

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
UNICARPTMotorCU_Calc (void *MP, struct tPTMotorCU_IF *IF, double dt)
{
    rtModel_UNICARPTMotorCU *rtm = (rtModel_UNICARPTMotorCU *)MP;
    int osCount=0;
    ExternalInputs_UNICARPTMotorCU  *in  = (ExternalInputs_UNICARPTMotorCU *) rtmGetU(rtm);
    ExternalOutputs_UNICARPTMotorCU *out = (ExternalOutputs_UNICARPTMotorCU *)rtmGetY(rtm);

    in->FromCM.Ignition			= IF->Ignition;

    in->FromCM.ISGIn.Trq_trg		= IF->ISGIn.Trq_trg;
    in->FromCM.ISGIn.Trq		= IF->ISGIn.Trq;
    in->FromCM.ISGIn.rotv_trg		= IF->ISGIn.rotv_trg;
    in->FromCM.ISGIn.rotv		= IF->ISGIn.rotv;
    in->FromCM.ISGIn.PwrElec		= IF->ISGIn.PwrElec;

    in->FromCM.MotorIn.m0.Trq_trg	= IF->MotorIn[0].Trq_trg;
    in->FromCM.MotorIn.m0.Trq		= IF->MotorIn[0].Trq;
    in->FromCM.MotorIn.m0.rotv_trg	= IF->MotorIn[0].rotv_trg;
    in->FromCM.MotorIn.m0.rotv		= IF->MotorIn[0].rotv;
    in->FromCM.MotorIn.m0.PwrElec	= IF->MotorIn[0].PwrElec;

    in->FromCM.MotorIn.m1.Trq_trg	= IF->MotorIn[1].Trq_trg;
    in->FromCM.MotorIn.m1.Trq		= IF->MotorIn[1].Trq;
    in->FromCM.MotorIn.m1.rotv_trg	= IF->MotorIn[1].rotv_trg;
    in->FromCM.MotorIn.m1.rotv		= IF->MotorIn[1].rotv;
    in->FromCM.MotorIn.m1.PwrElec	= IF->MotorIn[1].PwrElec;

#if defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.MotorIn.m2.Trq_trg	= IF->MotorIn[2].Trq_trg;
    in->FromCM.MotorIn.m2.Trq		= IF->MotorIn[2].Trq;
    in->FromCM.MotorIn.m2.rotv_trg	= IF->MotorIn[2].rotv_trg;
    in->FromCM.MotorIn.m2.rotv		= IF->MotorIn[2].rotv;
    in->FromCM.MotorIn.m2.PwrElec	= IF->MotorIn[2].PwrElec;

    in->FromCM.MotorIn.m3.Trq_trg	= IF->MotorIn[3].Trq_trg;
    in->FromCM.MotorIn.m3.Trq		= IF->MotorIn[3].Trq;
    in->FromCM.MotorIn.m3.rotv_trg	= IF->MotorIn[3].rotv_trg;
    in->FromCM.MotorIn.m3.rotv		= IF->MotorIn[3].rotv;
    in->FromCM.MotorIn.m3.PwrElec	= IF->MotorIn[3].PwrElec;
#endif
#if defined (IS_TRUCK)
    in->FromCM.MotorIn.m4.Trq_trg	= IF->MotorIn[4].Trq_trg;
    in->FromCM.MotorIn.m4.Trq		= IF->MotorIn[4].Trq;
    in->FromCM.MotorIn.m4.rotv_trg	= IF->MotorIn[4].rotv_trg;
    in->FromCM.MotorIn.m4.rotv		= IF->MotorIn[4].rotv;
    in->FromCM.MotorIn.m4.PwrElec	= IF->MotorIn[4].PwrElec;

    in->FromCM.MotorIn.m5.Trq_trg	= IF->MotorIn[5].Trq_trg;
    in->FromCM.MotorIn.m5.Trq		= IF->MotorIn[5].Trq;
    in->FromCM.MotorIn.m5.rotv_trg	= IF->MotorIn[5].rotv_trg;
    in->FromCM.MotorIn.m5.rotv		= IF->MotorIn[5].rotv;
    in->FromCM.MotorIn.m5.PwrElec	= IF->MotorIn[5].PwrElec;

    in->FromCM.MotorIn.m6.Trq_trg	= IF->MotorIn[6].Trq_trg;
    in->FromCM.MotorIn.m6.Trq		= IF->MotorIn[6].Trq;
    in->FromCM.MotorIn.m6.rotv_trg	= IF->MotorIn[6].rotv_trg;
    in->FromCM.MotorIn.m6.rotv		= IF->MotorIn[6].rotv;
    in->FromCM.MotorIn.m6.PwrElec	= IF->MotorIn[6].PwrElec;

    in->FromCM.MotorIn.m7.Trq_trg	= IF->MotorIn[7].Trq_trg;
    in->FromCM.MotorIn.m7.Trq		= IF->MotorIn[7].Trq;
    in->FromCM.MotorIn.m7.rotv_trg	= IF->MotorIn[7].rotv_trg;
    in->FromCM.MotorIn.m7.rotv		= IF->MotorIn[7].rotv;
    in->FromCM.MotorIn.m7.PwrElec	= IF->MotorIn[7].PwrElec;
#endif

    in->FromCM.ISGOut.Load		= IF->ISGOut.Load;
    in->FromCM.MotorOut.m0.Load		= IF->MotorOut[0].Load;
    in->FromCM.MotorOut.m1.Load		= IF->MotorOut[1].Load;
#if defined (IS_CAR) || defined (IS_TRUCK)
    in->FromCM.MotorOut.m2.Load		= IF->MotorOut[2].Load;
    in->FromCM.MotorOut.m3.Load		= IF->MotorOut[3].Load;
#endif
#if defined (IS_TRUCK)
    in->FromCM.MotorOut.m4.Load		= IF->MotorOut[4].Load;
    in->FromCM.MotorOut.m5.Load		= IF->MotorOut[5].Load;
    in->FromCM.MotorOut.m6.Load		= IF->MotorOut[6].Load;
    in->FromCM.MotorOut.m7.Load		= IF->MotorOut[7].Load;
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

    IF->Status	= out->ToCM.Status;

    IF->ISGOut.Load		= out->ToCM.ISGOut.Load;
    IF->ISGOut.TrqMot_max	= out->ToCM.ISGOut.TrqMot_max;
    IF->ISGOut.TrqGen_max	= out->ToCM.ISGOut.TrqGen_max;

    IF->MotorOut[0].Load	= out->ToCM.MotorOut.m0.Load;
    IF->MotorOut[0].TrqMot_max	= out->ToCM.MotorOut.m0.TrqMot_max;
    IF->MotorOut[0].TrqGen_max	= out->ToCM.MotorOut.m0.TrqGen_max;

    IF->MotorOut[1].Load	= out->ToCM.MotorOut.m1.Load;
    IF->MotorOut[1].TrqMot_max	= out->ToCM.MotorOut.m1.TrqMot_max;
    IF->MotorOut[1].TrqGen_max	= out->ToCM.MotorOut.m1.TrqGen_max;

#if defined (IS_CAR) || defined (IS_TRUCK)
    IF->MotorOut[2].Load	= out->ToCM.MotorOut.m2.Load;
    IF->MotorOut[2].TrqMot_max	= out->ToCM.MotorOut.m2.TrqMot_max;
    IF->MotorOut[2].TrqGen_max	= out->ToCM.MotorOut.m2.TrqGen_max;

    IF->MotorOut[3].Load	= out->ToCM.MotorOut.m3.Load;
    IF->MotorOut[3].TrqMot_max	= out->ToCM.MotorOut.m3.TrqMot_max;
    IF->MotorOut[3].TrqGen_max	= out->ToCM.MotorOut.m3.TrqGen_max;
#endif
#if defined (IS_TRUCK)
    IF->MotorOut[4].Load	= out->ToCM.MotorOut.m4.Load;
    IF->MotorOut[4].TrqMot_max	= out->ToCM.MotorOut.m4.TrqMot_max;
    IF->MotorOut[4].TrqGen_max	= out->ToCM.MotorOut.m4.TrqGen_max;

    IF->MotorOut[5].Load	= out->ToCM.MotorOut.m5.Load;
    IF->MotorOut[5].TrqMot_max	= out->ToCM.MotorOut.m5.TrqMot_max;
    IF->MotorOut[5].TrqGen_max	= out->ToCM.MotorOut.m5.TrqGen_max;

    IF->MotorOut[6].Load	= out->ToCM.MotorOut.m6.Load;
    IF->MotorOut[6].TrqMot_max	= out->ToCM.MotorOut.m6.TrqMot_max;
    IF->MotorOut[6].TrqGen_max	= out->ToCM.MotorOut.m6.TrqGen_max;

    IF->MotorOut[7].Load	= out->ToCM.MotorOut.m7.Load;
    IF->MotorOut[7].TrqMot_max	= out->ToCM.MotorOut.m7.TrqMot_max;
    IF->MotorOut[7].TrqGen_max	= out->ToCM.MotorOut.m7.TrqGen_max;
#endif

    return 0;
}


int
UNICARPTMotorCU_Register (void)
{
    tModelClassDescr m;

    /*Log("%s_Register()\n", Modelname);*/

    memset(&m, 0, sizeof(m));

    /* Parameter file identification number.
       You may change CompatVersionId to the the lowest parameter
       file version understood by your model code. */
    m.PTMotorCU.VersionId		= PARAMID;
    m.PTMotorCU.CompatVersionId		= m.PTMotorCU.VersionId;

    m.PTMotorCU.DeclQuants		= UNICARPTMotorCU_DeclQuants;
    m.PTMotorCU.New			= UNICARPTMotorCU_New;
    m.PTMotorCU.Calc			= UNICARPTMotorCU_Calc;
    m.PTMotorCU.Delete			= UNICARPTMotorCU_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    // m.PTMotorCU.ParamsChanged	= ParamsChanged_IgnoreCheck;

    return Model_Register(Modelclass, Modelname, &m);
}

