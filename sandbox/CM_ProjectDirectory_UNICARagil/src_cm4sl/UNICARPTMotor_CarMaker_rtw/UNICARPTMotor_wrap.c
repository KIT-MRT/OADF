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

#include "UNICARPTMotor.h"
#include "UNICARPTMotor_wrap.h"


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

extern const char UNICARPTMotor_LibIdent[];
const char UNICARPTMotor_LibIdent[] = "(@@)" QUOTE(MODEL) " " ARCH " 1.0 " BUILDDATE;

static const char Modelname[] = QUOTE(MODEL);
static const tModelClass Modelclass = ModelClass_PTMotor;
static tMatSuppSampling SampleParams;

static void
DoOneStep (rtModel_UNICARPTMotor *rtm)
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
UNICARPTMotor_DeclQuants (void *MP)
{
    rtModel_UNICARPTMotor *rtm = (rtModel_UNICARPTMotor *)MP;
    int i;

    /*Log("%s_DeclQuants()\n", Modelname);*/

    if (rtm == NULL) {
	/* Remember body frames defined in this model for later registration. */
        MdlBdyFrame_Add(UNICARPTMotor_BdyFrameDefines);

	/* Define dict entries for non-dynamically allocated variables. */
	if ((i = MatSupp_DeclQuants(UNICARPTMotor_DictDefines)) >= 0) {
	    LogErrF(EC_Init, "Model '%s': Error defining quantity '%s'\n",
		    Modelname, UNICARPTMotor_DictDefines[i].Name);
	}

	/* Define dict entries for tunable parameters (with dummy address). */
	DeclParameterQuants(NULL);
    } else {
	/* Define dict entries for dynamically allocated variables. */
    }
}


/*
 * UNICARPTMotor_SetParams() will be invoked indirectly by the generated
 * model C code each time UNICARPTMotor_New() is called.
 */
void
UNICARPTMotor_SetParams (rtModel_UNICARPTMotor *rtm, struct tMatSuppTunables *tuns,
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
assignCfgIF (struct tPTMotorCfgIF *CfgIF, void *MP)
{
    rtModel_UNICARPTMotor *rtm = (rtModel_UNICARPTMotor *)MP;
    int arraydim, nError = GetInfoErrorCount() + Log_nError;
    ExternalInputs_UNICARPTMotor  *in  = (ExternalInputs_UNICARPTMotor *) rtmGetU(rtm);

    /* CfgIF Output */
    in->CfgOutFromCM.Level	= CfgIF->Level;
    in->CfgOutFromCM.Ratio	= CfgIF->Ratio;

    arraydim = sizeof(in->CfgOutFromCM.TrqMot_max.x) / sizeof(in->CfgOutFromCM.TrqMot_max.x[0]);
    CfgLinMaptoBus (CfgIF->TrqMot_max, arraydim, "Maximum motor torque",
		    in->CfgOutFromCM.TrqMot_max.x, in->CfgOutFromCM.TrqMot_max.z);

    arraydim = sizeof(in->CfgOutFromCM.TrqGen_max.x) / sizeof(in->CfgOutFromCM.TrqGen_max.x[0]);
    CfgLinMaptoBus (CfgIF->TrqGen_max, arraydim, "Maximum generator torque",
		    in->CfgOutFromCM.TrqGen_max.x, in->CfgOutFromCM.TrqGen_max.z);

    in->CfgOutFromCM.rotv_Mot_max	= CfgIF->rotv_Mot_max;
    in->CfgOutFromCM.rotv_Gen_max	= CfgIF->rotv_Gen_max;

    if (GetInfoErrorCount() + Log_nError != nError) {
    	goto ErrorReturn;
    }

    return rtm;

  ErrorReturn:
    return NULL;
}

static void *
UNICARPTMotor_New (struct tInfos *Inf, struct tPTMotorCfgIF  *CfgIF, const char *KindKey, const char *Ident)
{
    rtModel_UNICARPTMotor *rtm;
    double rtmSampleTime;
    const char *ModelKind;
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, Modelclass, KindKey,
	 				 0, PARAMID, &VersionId)) == NULL)
	return NULL;

    /*Log("%s_New()\n", Modelname);*/
    if (iGetLongOpt (Inf,"PowerTrain.DL.FlexShaft" , 0))
	LogErrF(EC_Init, "Model '%s': Using flex shaft not allowed\n",Modelname);

    MatSupp_ResetQuants(UNICARPTMotor_DictDefines);

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

    /* get CfgIF parameters */
    if (Motor_GetCfgOutIF (Inf, CfgIF, ModelKind, Ident) != 0)
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
UNICARPTMotor_Delete (void *MP)
{
    rtModel_UNICARPTMotor *rtm = (rtModel_UNICARPTMotor *)MP;

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
UNICARPTMotor_Calc (void *MP, struct tPTMotorIF *IF, double dt)
{
    rtModel_UNICARPTMotor *rtm = (rtModel_UNICARPTMotor *)MP;
    int osCount=0;
    ExternalInputs_UNICARPTMotor  *in  = (ExternalInputs_UNICARPTMotor *) rtmGetU(rtm);
    ExternalOutputs_UNICARPTMotor *out = (ExternalOutputs_UNICARPTMotor *)rtmGetY(rtm);

    in->FromCM.rot		= IF->rot;
    in->FromCM.rotv		= IF->rotv;
    in->FromCM.Voltage		= IF->Voltage;
    in->FromCM.Load		= IF->Load;

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

    IF->Trq	= out->ToCM.Trq;
    IF->Inert	= out->ToCM.Inert;
    IF->PwrElec	= out->ToCM.PwrElec;

    return 0;
}


int
UNICARPTMotor_Register (void)
{
    tModelClassDescr m;

    /*Log("%s_Register()\n", Modelname);*/

    memset(&m, 0, sizeof(m));

    /* Parameter file identification number.
       You may change CompatVersionId to the the lowest parameter
       file version understood by your model code. */
    m.PTMotor.VersionId		= PARAMID;
    m.PTMotor.CompatVersionId	= m.PTMotor.VersionId;

    m.PTMotor.DeclQuants	= UNICARPTMotor_DeclQuants;
    m.PTMotor.New		= UNICARPTMotor_New;
    m.PTMotor.Calc		= UNICARPTMotor_Calc;
    m.PTMotor.Delete		= UNICARPTMotor_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    // m.PTMotor.ParamsChanged	= ParamsChanged_IgnoreCheck;

    return Model_Register(Modelclass, Modelname, &m);
}

