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

#if defined (IS_CAR) || defined (IS_TRUCK)
# include "Car/PowerTrain.h"
#elif defined(IS_MCYCLE)
# include "MCycle/PowerTrain.h"
#endif

#include "UNICARPTGearBox.h"
#include "UNICARPTGearBox_wrap.h"


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

extern const char UNICARPTGearBox_LibIdent[];
const char UNICARPTGearBox_LibIdent[] = "(@@)" QUOTE(MODEL) " " ARCH " 1.0 " BUILDDATE;

static const char Modelname[] = QUOTE(MODEL);
static const tModelClass Modelclass = ModelClass_PTGearBox;
static tMatSuppSampling SampleParams;


static void
DoOneStep (rtModel_UNICARPTGearBox *rtm)
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
UNICARPTGearBox_DeclQuants (void *MP)
{
    rtModel_UNICARPTGearBox *rtm = (rtModel_UNICARPTGearBox *)MP;
    int i;

    /*Log("%s_DeclQuants()\n", Modelname);*/

    if (rtm == NULL) {
	/* Remember body frames defined in this model for later registration. */
        MdlBdyFrame_Add(UNICARPTGearBox_BdyFrameDefines);

	/* Define dict entries for non-dynamically allocated variables. */
	if ((i = MatSupp_DeclQuants(UNICARPTGearBox_DictDefines)) >= 0) {
	    LogErrF(EC_Init, "Model '%s': Error defining quantity '%s'",
		    Modelname, UNICARPTGearBox_DictDefines[i].Name);
	}

	/* Define dict entries for tunable parameters (with dummy address). */
	DeclParameterQuants(NULL);
    } else {
	/* Define dict entries for dynamically allocated variables. */
    }
}


/*
 * UNICARPTGearBox_SetParams() will be invoked indirectly by the generated
 * model C code each time UNICARPTGearBox_New() is called.
 */
void
UNICARPTGearBox_SetParams (rtModel_UNICARPTGearBox *rtm, struct tMatSuppTunables *tuns,
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

static void *
assignCfgIF (struct tPTGearBoxCfgIF *CfgIF, void *MP)
{
    rtModel_UNICARPTGearBox *rtm = (rtModel_UNICARPTGearBox *)MP;
    ExternalInputs_UNICARPTGearBox  *in  = (ExternalInputs_UNICARPTGearBox *) rtmGetU(rtm);

    in->CfgOutFromCM.ClKind		= CfgIF->ClKind;
    in->CfgOutFromCM.GBKind		= CfgIF->GBKind;
    in->CfgOutFromCM.nFGears		= CfgIF->nFGears;
    in->CfgOutFromCM.iFGear.Gear1	= CfgIF->iFGear[1];
    in->CfgOutFromCM.iFGear.Gear2	= CfgIF->iFGear[2];
    in->CfgOutFromCM.iFGear.Gear3	= CfgIF->iFGear[3];
    in->CfgOutFromCM.iFGear.Gear4	= CfgIF->iFGear[4];
    in->CfgOutFromCM.iFGear.Gear5	= CfgIF->iFGear[5];
    in->CfgOutFromCM.iFGear.Gear6	= CfgIF->iFGear[6];
    in->CfgOutFromCM.iFGear.Gear7	= CfgIF->iFGear[7];
    in->CfgOutFromCM.iFGear.Gear8	= CfgIF->iFGear[8];
    in->CfgOutFromCM.iFGear.Gear9	= CfgIF->iFGear[9];
    in->CfgOutFromCM.iFGear.Gear10	= CfgIF->iFGear[10];
    in->CfgOutFromCM.iFGear.Gear11	= CfgIF->iFGear[11];
    in->CfgOutFromCM.iFGear.Gear12	= CfgIF->iFGear[12];
    in->CfgOutFromCM.iFGear.Gear13	= CfgIF->iFGear[13];
    in->CfgOutFromCM.iFGear.Gear14	= CfgIF->iFGear[14];
    in->CfgOutFromCM.iFGear.Gear15	= CfgIF->iFGear[15];
    in->CfgOutFromCM.iFGear.Gear16	= CfgIF->iFGear[16];
    in->CfgOutFromCM.nBGears		= CfgIF->nBGears;
    in->CfgOutFromCM.iBGear.Gear1	= CfgIF->iBGear[1];
    in->CfgOutFromCM.iBGear.Gear2	= CfgIF->iBGear[2];
    in->CfgOutFromCM.iBGear.Gear3	= CfgIF->iBGear[3];
    in->CfgOutFromCM.iBGear.Gear4	= CfgIF->iBGear[4];

    return rtm;
}


static void *
UNICARPTGearBox_New (
    struct tInfos *Inf,
    struct tPTGearBoxCfgIF *CfgIF,
    const char *KindKey,
    const char *Ident)
{
    rtModel_UNICARPTGearBox *rtm;
    double rtmSampleTime;
    const char *ModelKind;
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, Modelclass, KindKey,
	 				 0, PARAMID, &VersionId)) == NULL)
	return NULL;

    /*Log("%s_New()\n", Modelname);*/
    if (iGetLongOpt (Inf,"PowerTrain.DL.FlexShaft" , 0))
	LogErrF(EC_Init, "Model '%s': Using flex shaft not allowed",Modelname);

    MatSupp_ResetQuants(UNICARPTGearBox_DictDefines);

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
	LogErrF(EC_Init, "Model '%s': The sample times of the plugin model and the application have to be integer multiples",Modelname);
	return NULL;
    }

    /* get CfgIF parameters */
    if (GearBox_GetCfgOutIF (Inf, CfgIF, ModelKind, Ident) != 0)
	return NULL;

    /* assign CfgIF struct */
    if ((assignCfgIF(CfgIF, rtm)) == NULL)  {
	LogErrF(EC_Init, "Model '%s': failed to assign CfgIF",Modelname);
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
UNICARPTGearBox_Delete (void *MP)
{
    rtModel_UNICARPTGearBox *rtm = (rtModel_UNICARPTGearBox *)MP;

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
UNICARPTGearBox_Calc (void *MP, struct tPTGearBoxIF *IF, double dt)
{
    rtModel_UNICARPTGearBox *rtm = (rtModel_UNICARPTGearBox *)MP;
    int osCount=0;
    ExternalInputs_UNICARPTGearBox  *in  = (ExternalInputs_UNICARPTGearBox *) rtmGetU(rtm);
    ExternalOutputs_UNICARPTGearBox *out = (ExternalOutputs_UNICARPTGearBox *)rtmGetY(rtm);

    in->FromCM.GearNoTrg       = IF->GearNoTrg;
    in->FromCM.GearNoTrg_dis   = IF->GearNoTrg_dis;
    in->FromCM.set_ParkBrake   = IF->set_ParkBrake;
    in->FromCM.i_trg           = IF->i_trg;
    in->FromCM.Inert_in        = IF->Inert_in;
    in->FromCM.rot_out         = IF->rot_out;
    in->FromCM.rotv_out        = IF->rotv_out;
    in->FromCM.Trq_in          = IF->Trq_in;
    in->FromCM.ClutchIn.Pos    = IF->ClutchIn.Pos;
    in->FromCM.Clutch_dis_In.Pos = IF->Clutch_dis_In.Pos;

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

    IF->GearNo			= out->ToCM.GearNo;
    IF->GearNo_dis		= out->ToCM.GearNo_dis;
    IF->i			= out->ToCM.i;
    IF->rot_in			= out->ToCM.rot_in;
    IF->rotv_in			= out->ToCM.rotv_in;
    IF->Trq_out			= out->ToCM.Trq_out;
    IF->Inert_out		= out->ToCM.Inert_out;
    IF->i_TrqIn2Out		= out->ToCM.i_TrqIn2Out;
    IF->Trq_SuppInert		= out->ToCM.Trq_SuppInert;
    IF->ClutchOut.rot_in	= out->ToCM.ClutchOut.rot_in;
    IF->ClutchOut.rotv_in	= out->ToCM.ClutchOut.rotv_in;
    IF->ClutchOut.rot_out	= out->ToCM.ClutchOut.rot_out;
    IF->ClutchOut.rotv_out	= out->ToCM.ClutchOut.rotv_out;
    IF->ClutchOut.Trq_in	= out->ToCM.ClutchOut.Trq_in;
    IF->ClutchOut.Trq_out	= out->ToCM.ClutchOut.Trq_out;
    IF->ClutchOut.i_TrqIn2Out   = out->ToCM.ClutchOut.i_TrqIn2Out;
    IF->Clutch_dis_Out.rot_in	= out->ToCM.Clutch_dis_Out.rot_in;
    IF->Clutch_dis_Out.rotv_in	= out->ToCM.Clutch_dis_Out.rotv_in;
    IF->Clutch_dis_Out.rot_out	= out->ToCM.Clutch_dis_Out.rot_out;
    IF->Clutch_dis_Out.rotv_out	= out->ToCM.Clutch_dis_Out.rotv_out;
    IF->Clutch_dis_Out.Trq_in	= out->ToCM.Clutch_dis_Out.Trq_in;
    IF->Clutch_dis_Out.Trq_out	= out->ToCM.Clutch_dis_Out.Trq_out;
    IF->Clutch_dis_Out.i_TrqIn2Out= out->ToCM.Clutch_dis_Out.i_TrqIn2Out;
    return 0;
}


int
UNICARPTGearBox_Register (void)
{
    tModelClassDescr m;

    /*Log("%s_Register()\n", Modelname);*/

    memset(&m, 0, sizeof(m));

    /* Parameter file identification number.
       You may change CompatVersionId to the the lowest parameter
       file version understood by your model code. */
    m.PTGearBox.VersionId		= PARAMID;
    m.PTGearBox.CompatVersionId		= m.PTGearBox.VersionId;

    m.PTGearBox.DeclQuants		= UNICARPTGearBox_DeclQuants;
    m.PTGearBox.New			= UNICARPTGearBox_New;
    m.PTGearBox.Calc			= UNICARPTGearBox_Calc;
    m.PTGearBox.Delete			= UNICARPTGearBox_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    // m.PTGearBox.ParamsChanged	= ParamsChanged_IgnoreCheck;

    return Model_Register(Modelclass, Modelname, &m);
}

