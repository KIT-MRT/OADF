/*
 * UNICARPTGearBox.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARPTGearBox".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:30:00 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UNICARPTGearBox_capi.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "UNICARPTGearBox.h"
#include "UNICARPTGearBox_private.h"
#include "UNICARPTGearBox_wrap.h"

/* CarMaker: Compile- and link-time checks for the right Matlab version. */
#if MATSUPP_NUMVER == 90700

/* The following statement will cause an "unresolved symbol" error when
   linking with a MatSupp library built for the wrong Matlab version. */
extern int MATSUPP_VARNAME(MatSupp, MATSUPP_NUMVER);
void *MATSUPP_VARNAME(MODEL, MATSUPP_NUMVER) = &MATSUPP_VARNAME(MatSupp,
  MATSUPP_NUMVER);

#else
# error Compiler options unsuitable for C code created with Matlab 9.7
#endif

const cmPTGearBoxOut UNICARPTGearBox_rtZcmPTGearBoxOut = {
  0.0,                                 /* GearNo */
  0.0,                                 /* GearNo_dis */
  0.0,                                 /* i */
  0.0,                                 /* rot_in */
  0.0,                                 /* rotv_in */
  0.0,                                 /* Trq_out */
  0.0,                                 /* Inert_out */
  0.0,                                 /* i_TrqIn2Out */
  0.0,                                 /* Trq_SuppInert */

  {
    0.0,                               /* rot_in */
    0.0,                               /* rotv_in */
    0.0,                               /* rot_out */
    0.0,                               /* rotv_out */
    0.0,                               /* Trq_in */
    0.0,                               /* Trq_out */
    0.0                                /* i_TrqIn2Out */
  },                                   /* ClutchOut */

  {
    0.0,                               /* rot_in */
    0.0,                               /* rotv_in */
    0.0,                               /* rot_out */
    0.0,                               /* rotv_out */
    0.0,                               /* Trq_in */
    0.0,                               /* Trq_out */
    0.0                                /* i_TrqIn2Out */
  }                                    /* Clutch_dis_Out */
} ;                                    /* cmPTGearBoxOut ground */

/* Block parameters (default storage) */
P_UNICARPTGearBox_T UNICARPTGearBox_P = {
  /* Variable: GB_i
   * Referenced by:
   *   '<Root>/Gain'
   *   '<Root>/Gain1'
   *   '<Root>/Gain2'
   */
  3.138,

  /* Expression: 0
   * Referenced by: '<S1>/GearNo'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearNo_dis'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/i'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Inert_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/i_TrqIn2Out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Trq_SuppInert'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.rot_in'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.rotv_in'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.rot_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.rotv_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.Trq_in'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.Trq_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.i_TrqIn2Out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.rot_in'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.rotv_in'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.rot_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.rotv_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.Trq_in'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.Trq_out'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clutch_dis_Out.i_TrqIn2Out'
   */
  0.0
};

/* Model step function */
void UNICARPTGearBox_step(RT_MODEL_UNICARPTGearBox_T *const UNICARPTGearBox_M)
{
  ExtU_UNICARPTGearBox_T *UNICARPTGearBox_U = (ExtU_UNICARPTGearBox_T *)
    UNICARPTGearBox_M->inputs;
  ExtY_UNICARPTGearBox_T *UNICARPTGearBox_Y = (ExtY_UNICARPTGearBox_T *)
    UNICARPTGearBox_M->outputs;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTGearBox_Y->ToCM.rot_in = UNICARPTGearBox_P.GB_i *
    UNICARPTGearBox_U->FromCM.rot_out;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTGearBox_Y->ToCM.rotv_in = UNICARPTGearBox_P.GB_i *
    UNICARPTGearBox_U->FromCM.rotv_out;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTGearBox_Y->ToCM.Trq_out = UNICARPTGearBox_P.GB_i *
    UNICARPTGearBox_U->FromCM.Trq_in;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/ClutchOut.Trq_in'
   *  Constant: '<S1>/ClutchOut.Trq_out'
   *  Constant: '<S1>/ClutchOut.i_TrqIn2Out'
   *  Constant: '<S1>/ClutchOut.rot_in'
   *  Constant: '<S1>/ClutchOut.rot_out'
   *  Constant: '<S1>/ClutchOut.rotv_in'
   *  Constant: '<S1>/ClutchOut.rotv_out'
   */
  UNICARPTGearBox_Y->ToCM.ClutchOut.rot_in =
    UNICARPTGearBox_P.ClutchOutrot_in_Value;
  UNICARPTGearBox_Y->ToCM.ClutchOut.rotv_in =
    UNICARPTGearBox_P.ClutchOutrotv_in_Value;
  UNICARPTGearBox_Y->ToCM.ClutchOut.rot_out =
    UNICARPTGearBox_P.ClutchOutrot_out_Value;
  UNICARPTGearBox_Y->ToCM.ClutchOut.rotv_out =
    UNICARPTGearBox_P.ClutchOutrotv_out_Value;
  UNICARPTGearBox_Y->ToCM.ClutchOut.Trq_in =
    UNICARPTGearBox_P.ClutchOutTrq_in_Value;
  UNICARPTGearBox_Y->ToCM.ClutchOut.Trq_out =
    UNICARPTGearBox_P.ClutchOutTrq_out_Value;
  UNICARPTGearBox_Y->ToCM.ClutchOut.i_TrqIn2Out =
    UNICARPTGearBox_P.ClutchOuti_TrqIn2Out_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/Clutch_dis_Out.Trq_in'
   *  Constant: '<S1>/Clutch_dis_Out.Trq_out'
   *  Constant: '<S1>/Clutch_dis_Out.i_TrqIn2Out'
   *  Constant: '<S1>/Clutch_dis_Out.rot_in'
   *  Constant: '<S1>/Clutch_dis_Out.rot_out'
   *  Constant: '<S1>/Clutch_dis_Out.rotv_in'
   *  Constant: '<S1>/Clutch_dis_Out.rotv_out'
   */
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.rot_in =
    UNICARPTGearBox_P.Clutch_dis_Outrot_in_Value;
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.rotv_in =
    UNICARPTGearBox_P.Clutch_dis_Outrotv_in_Value;
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.rot_out =
    UNICARPTGearBox_P.Clutch_dis_Outrot_out_Value;
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.rotv_out =
    UNICARPTGearBox_P.Clutch_dis_Outrotv_out_Value;
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.Trq_in =
    UNICARPTGearBox_P.Clutch_dis_OutTrq_in_Value;
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.Trq_out =
    UNICARPTGearBox_P.Clutch_dis_OutTrq_out_Value;
  UNICARPTGearBox_Y->ToCM.Clutch_dis_Out.i_TrqIn2Out =
    UNICARPTGearBox_P.Clutch_dis_Outi_TrqIn2Out_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/GearNo'
   *  Constant: '<S1>/GearNo_dis'
   *  Constant: '<S1>/Inert_out'
   *  Constant: '<S1>/Trq_SuppInert'
   *  Constant: '<S1>/i'
   *  Constant: '<S1>/i_TrqIn2Out'
   *  Outport: '<Root>/ToCM'
   */
  UNICARPTGearBox_Y->ToCM.GearNo = UNICARPTGearBox_P.GearNo_Value;
  UNICARPTGearBox_Y->ToCM.GearNo_dis = UNICARPTGearBox_P.GearNo_dis_Value;
  UNICARPTGearBox_Y->ToCM.i = UNICARPTGearBox_P.i_Value;
  UNICARPTGearBox_Y->ToCM.Inert_out = UNICARPTGearBox_P.Inert_out_Value;
  UNICARPTGearBox_Y->ToCM.i_TrqIn2Out = UNICARPTGearBox_P.i_TrqIn2Out_Value;
  UNICARPTGearBox_Y->ToCM.Trq_SuppInert = UNICARPTGearBox_P.Trq_SuppInert_Value;
}

/* Model initialize function */
void UNICARPTGearBox_initialize(RT_MODEL_UNICARPTGearBox_T *const
  UNICARPTGearBox_M)
{
  UNUSED_PARAMETER(UNICARPTGearBox_M);
}

/* Model terminate function */
void UNICARPTGearBox_terminate(RT_MODEL_UNICARPTGearBox_T * UNICARPTGearBox_M)
{
  /* model code */
  rt_FREE(UNICARPTGearBox_M->inputs);
  rt_FREE(UNICARPTGearBox_M->outputs);
  rt_FREE(UNICARPTGearBox_M);
}

/* Model data allocation function */
RT_MODEL_UNICARPTGearBox_T *UNICARPTGearBox(struct tInfos *inf)
{
  RT_MODEL_UNICARPTGearBox_T *UNICARPTGearBox_M;
  UNICARPTGearBox_M = (RT_MODEL_UNICARPTGearBox_T *) malloc(sizeof
    (RT_MODEL_UNICARPTGearBox_T));
  if (UNICARPTGearBox_M == NULL) {
    return NULL;
  }

  (void) memset((char *)UNICARPTGearBox_M, 0,
                sizeof(RT_MODEL_UNICARPTGearBox_T));
  MatSupp_Init();

  /* external inputs */
  {
    ExtU_UNICARPTGearBox_T *UNICARPTGearBox_U = (ExtU_UNICARPTGearBox_T *)
      malloc(sizeof(ExtU_UNICARPTGearBox_T));
    rt_VALIDATE_MEMORY(UNICARPTGearBox_M,UNICARPTGearBox_U);
    UNICARPTGearBox_M->inputs = (((ExtU_UNICARPTGearBox_T *) UNICARPTGearBox_U));
  }

  /* external outputs */
  {
    ExtY_UNICARPTGearBox_T *UNICARPTGearBox_Y = (ExtY_UNICARPTGearBox_T *)
      malloc(sizeof(ExtY_UNICARPTGearBox_T));
    rt_VALIDATE_MEMORY(UNICARPTGearBox_M,UNICARPTGearBox_Y);
    UNICARPTGearBox_M->outputs = (UNICARPTGearBox_Y);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  UNICARPTGearBox_InitializeDataMapInfo(UNICARPTGearBox_M);

  /* CarMaker parameter tuning */
  {
    const struct tMatSuppMMI *mmi = &(rtmGetDataMapInfo(UNICARPTGearBox_M).mmi);
    tMatSuppTunables *tuns = MatSupp_TunBegin("UNICARPTGearBox", mmi);
    UNICARPTGearBox_SetParams(UNICARPTGearBox_M, tuns, inf);
    MatSupp_TunEnd(tuns);
  }

  {
    ExtU_UNICARPTGearBox_T *UNICARPTGearBox_U = (ExtU_UNICARPTGearBox_T *)
      UNICARPTGearBox_M->inputs;
    ExtY_UNICARPTGearBox_T *UNICARPTGearBox_Y = (ExtY_UNICARPTGearBox_T *)
      UNICARPTGearBox_M->outputs;

    /* external inputs */
    (void)memset(UNICARPTGearBox_U, 0, sizeof(ExtU_UNICARPTGearBox_T));

    /* external outputs */
    UNICARPTGearBox_Y->ToCM = UNICARPTGearBox_rtZcmPTGearBoxOut;
  }

  return UNICARPTGearBox_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *UNICARPTGearBox_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)UNICARPTGearBox_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *UNICARPTGearBox_DictDefines = DictDefines;
tQuantEntry *UNICARPTGearBox_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *UNICARPTGearBox_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)UNICARPTGearBox_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *UNICARPTGearBox_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *UNICARPTGearBox_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
