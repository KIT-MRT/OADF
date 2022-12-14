/*
 * UNICARPTControl.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARPTControl".
 *
 * Model version              : 1.49
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:29:19 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UNICARPTControl_h_
#define RTW_HEADER_UNICARPTControl_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef UNICARPTControl_COMMON_INCLUDES_
# define UNICARPTControl_COMMON_INCLUDES_
#include <stdlib.h>
#include <Global.h>
#include <TextUtils.h>
#include <DataDict.h>
#include <DirectVarAccess.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* UNICARPTControl_COMMON_INCLUDES_ */

#include "UNICARPTControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define UNICARPTControl_M_TYPE         RT_MODEL_UNICARPTControl_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.001
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ReadCMDict2;                  /* '<S2>/Read CM Dict2' */
  real_T Switch3;                      /* '<S6>/Switch3' */
  real_T ReadCMDict1;                  /* '<S2>/Read CM Dict1' */
  real_T Abs1;                         /* '<S6>/Abs1' */
  real_T ReadCMDict;                   /* '<S2>/Read CM Dict' */
  real_T Memory;                       /* '<S9>/Memory' */
  real_T Clock;                        /* '<S9>/Clock' */
  real_T Memory1;                      /* '<S9>/Memory1' */
  real_T Sum2;                         /* '<S9>/Sum2' */
  real_T Switch2_l;                    /* '<S6>/Switch2' */
  real_T ReadCMDict2_h;                /* '<S3>/Read CM Dict2' */
  real_T Switch3_e;                    /* '<S10>/Switch3' */
  real_T ReadCMDict1_e;                /* '<S3>/Read CM Dict1' */
  real_T Abs1_p;                       /* '<S10>/Abs1' */
  real_T ReadCMDict_e;                 /* '<S3>/Read CM Dict' */
  real_T Memory_k;                     /* '<S13>/Memory' */
  real_T Clock_f;                      /* '<S13>/Clock' */
  real_T Memory1_m;                    /* '<S13>/Memory1' */
  real_T Sum2_a;                       /* '<S13>/Sum2' */
  real_T Switch2_b;                    /* '<S10>/Switch2' */
  real_T ReadCMDict2_c;                /* '<S4>/Read CM Dict2' */
  real_T Switch3_h;                    /* '<S14>/Switch3' */
  real_T ReadCMDict1_n;                /* '<S4>/Read CM Dict1' */
  real_T Abs1_n;                       /* '<S14>/Abs1' */
  real_T ReadCMDict_j;                 /* '<S4>/Read CM Dict' */
  real_T Memory_a;                     /* '<S17>/Memory' */
  real_T Clock_j;                      /* '<S17>/Clock' */
  real_T Memory1_k;                    /* '<S17>/Memory1' */
  real_T Sum2_h;                       /* '<S17>/Sum2' */
  real_T Switch2_p;                    /* '<S14>/Switch2' */
  real_T ReadCMDict2_b;                /* '<S5>/Read CM Dict2' */
  real_T Switch3_n;                    /* '<S18>/Switch3' */
  real_T ReadCMDict1_i;                /* '<S5>/Read CM Dict1' */
  real_T Abs1_g;                       /* '<S18>/Abs1' */
  real_T ReadCMDict_c;                 /* '<S5>/Read CM Dict' */
  real_T Memory_f;                     /* '<S21>/Memory' */
  real_T Clock_p;                      /* '<S21>/Clock' */
  real_T Memory1_c;                    /* '<S21>/Memory1' */
  real_T Sum2_p;                       /* '<S21>/Sum2' */
  real_T Switch2_g4;                   /* '<S18>/Switch2' */
} B_UNICARPTControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S9>/Memory1' */
  real_T Memory_PreviousInput_i;       /* '<S13>/Memory' */
  real_T Memory1_PreviousInput_d;      /* '<S13>/Memory1' */
  real_T Memory_PreviousInput_c;       /* '<S17>/Memory' */
  real_T Memory1_PreviousInput_i;      /* '<S17>/Memory1' */
  real_T Memory_PreviousInput_m;       /* '<S21>/Memory' */
  real_T Memory1_PreviousInput_j;      /* '<S21>/Memory1' */
  struct {
    void *Entry;
  } WriteCMDict_PWORK;                 /* '<S2>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK;                 /* '<S2>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK;                 /* '<S2>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK;                  /* '<S2>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_m;               /* '<S3>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK_i;               /* '<S3>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_j;               /* '<S3>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_o;                /* '<S3>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_a;               /* '<S4>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK_f;               /* '<S4>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_e;               /* '<S4>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_h;                /* '<S4>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_j;               /* '<S5>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK_a;               /* '<S5>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_n;               /* '<S5>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_k;                /* '<S5>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK;                 /* '<S2>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK;                 /* '<S2>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK;                 /* '<S2>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK;                  /* '<S2>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK_n;               /* '<S3>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK_h;               /* '<S3>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_k;               /* '<S3>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_n;                /* '<S3>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK_e;               /* '<S4>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK_d;               /* '<S4>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_f;               /* '<S4>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_d;                /* '<S4>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK_l;               /* '<S5>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK_m;               /* '<S5>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_g;               /* '<S5>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_p;                /* '<S5>/Read CM Dict' */
} DW_UNICARPTControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmPTControlIn FromCM;                /* '<Root>/FromCM' */
  cmPTControlCfgIn CfgInFromCM;        /* '<Root>/CfgInFromCM' */
  cmPTControlCfgOut CfgOutFromCM;      /* '<Root>/CfgOutFromCM' */
} ExtU_UNICARPTControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmPTControlOut ToCM;                 /* '<Root>/ToCM' */
} ExtY_UNICARPTControl_T;

/* Parameters (default storage) */
struct P_UNICARPTControl_T_ {
  real_T PTC_RotLim[4];                /* Variable: PTC_RotLim
                                        * Referenced by:
                                        *   '<S6>/1-D Lookup Table'
                                        *   '<S10>/1-D Lookup Table'
                                        *   '<S14>/1-D Lookup Table'
                                        *   '<S18>/1-D Lookup Table'
                                        */
  real_T PTC_T_1_s;                    /* Variable: PTC_T_1_s
                                        * Referenced by:
                                        *   '<S6>/Constant2'
                                        *   '<S10>/Constant2'
                                        *   '<S14>/Constant2'
                                        *   '<S18>/Constant2'
                                        */
  real_T PTC_weight[4];                /* Variable: PTC_weight
                                        * Referenced by:
                                        *   '<S6>/1-D Lookup Table'
                                        *   '<S10>/1-D Lookup Table'
                                        *   '<S14>/1-D Lookup Table'
                                        *   '<S18>/1-D Lookup Table'
                                        */
  real_T Constant3_Value;              /* Expression: 0.01
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.2
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Constant3_Value_l;            /* Expression: 0.01
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Switch1_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0.2
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Constant3_Value_n;            /* Expression: 0.01
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Switch1_Threshold_n2;         /* Expression: 0
                                        * Referenced by: '<S14>/Switch1'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0.2
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Constant3_Value_a;            /* Expression: 0.01
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0
                                        * Referenced by: '<S18>/Switch1'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0.2
                                        * Referenced by: '<S18>/Switch'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S7>/Switch3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch2'
                                        */
  real_T Constant_Value_e;             /* Expression: -1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant6_Value_i;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant6'
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S13>/Memory'
                                        */
  real_T Memory1_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S13>/Memory1'
                                        */
  real_T Switch3_Threshold_o;          /* Expression: 0
                                        * Referenced by: '<S11>/Switch3'
                                        */
  real_T Switch2_Threshold_d;          /* Expression: 0
                                        * Referenced by: '<S10>/Switch2'
                                        */
  real_T Constant_Value_a;             /* Expression: -1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant6_Value_g;            /* Expression: 0
                                        * Referenced by: '<S15>/Constant6'
                                        */
  real_T Memory_InitialCondition_g;    /* Expression: 0
                                        * Referenced by: '<S17>/Memory'
                                        */
  real_T Memory1_InitialCondition_i;   /* Expression: 0
                                        * Referenced by: '<S17>/Memory1'
                                        */
  real_T Switch3_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S15>/Switch3'
                                        */
  real_T Switch2_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S14>/Switch2'
                                        */
  real_T Constant_Value_g;             /* Expression: -1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant6_Value_k;            /* Expression: 0
                                        * Referenced by: '<S19>/Constant6'
                                        */
  real_T Memory_InitialCondition_n;    /* Expression: 0
                                        * Referenced by: '<S21>/Memory'
                                        */
  real_T Memory1_InitialCondition_k;   /* Expression: 0
                                        * Referenced by: '<S21>/Memory1'
                                        */
  real_T Switch3_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S19>/Switch3'
                                        */
  real_T Switch2_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S18>/Switch2'
                                        */
  real_T Constant3_Value_k;            /* Expression: 4
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T StrategyMode_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/StrategyMode'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T EngineOutset_ISC_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/EngineOut.set_ISC'
                                        */
  real_T EngineOutFuelCutOff_Value;    /* Expression: 0
                                        * Referenced by: '<S1>/EngineOut.FuelCutOff'
                                        */
  real_T EngineOutLoad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/EngineOut.Load'
                                        */
  real_T EngineOutTrq_trg_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/EngineOut.Trq_trg'
                                        */
  real_T EngineOutrotv_trg_Value;      /* Expression: 0
                                        * Referenced by: '<S1>/EngineOut.rotv_trg'
                                        */
  real_T ISGOutLoad_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/ISGOut.Load'
                                        */
  real_T ISGOutTrq_trg_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/ISGOut.Trq_trg'
                                        */
  real_T ISGOutrotv_trg_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/ISGOut.rotv_trg'
                                        */
  real_T MotorOutm0Load_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m0.Load'
                                        */
  real_T MotorOutm0rotv_trg_Value;     /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m0.rotv_trg'
                                        */
  real_T MotorOutm1Load_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m1.Load'
                                        */
  real_T MotorOutm1rotv_trg_Value;     /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m1.rotv_trg'
                                        */
  real_T MotorOutm2Load_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m2.Load'
                                        */
  real_T MotorOutm2rotv_trg_Value;     /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m2.rotv_trg'
                                        */
  real_T MotorOutm3Load_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m3.Load'
                                        */
  real_T MotorOutm3rotv_trg_Value;     /* Expression: 0
                                        * Referenced by: '<S1>/MotorOut.m3.rotv_trg'
                                        */
  real_T ClutchOutPos_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.Pos'
                                        */
  real_T ClutchOutrotv_out_trg_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.rotv_out_trg'
                                        */
  real_T ClutchOutTrq_out_trg_Value;   /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.Trq_out_trg'
                                        */
  real_T GearBoxOutGearNoTrg_Value;    /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.GearNoTrg'
                                        */
  real_T GearBoxOutGearNoTrg_dis_Value;/* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.GearNoTrg_dis'
                                        */
  real_T GearBoxOuti_trg_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.i_trg'
                                        */
  real_T GearBoxOutset_ParkBrake_Value;/* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.set_ParkBrake'
                                        */
  real_T GearBoxOutrotv_in_trg_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.rotv_in_trg'
                                        */
  real_T GearBoxOutTrq_out_trg_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.Trq_out_trg'
                                        */
  real_T GearBoxOutClutchPos_Value;    /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.Clutch.Pos'
                                        */
  real_T GearBoxOutClutchrotv_out_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxOut.Clutch.rotv_out_trg'
                                             */
  real_T GearBoxOutClutchTrq_out_trg_Value;/* Expression: 0
                                            * Referenced by: '<S1>/GearBoxOut.Clutch.Trq_out_trg'
                                            */
  real_T GearBoxOutClutch_disPos_Value;/* Expression: 0
                                        * Referenced by: '<S1>/GearBoxOut.Clutch_dis.Pos'
                                        */
  real_T GearBoxOutClutch_disrotv_out_trg_Value;/* Expression: 0
                                                 * Referenced by: '<S1>/GearBoxOut.Clutch_dis.rotv_out_trg'
                                                 */
  real_T GearBoxOutClutch_disTrq_out_trg_Value;/* Expression: 0
                                                * Referenced by: '<S1>/GearBoxOut.Clutch_dis.Trq_out_trg'
                                                */
  real_T GearBoxM_OutGB_m0GearNoTrg_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m0.GearNoTrg'
                                           */
  real_T GearBoxM_OutGB_m0GearNoTrg_dis_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m0.GearNoTrg_dis'
                                               */
  real_T GearBoxM_OutGB_m0i_trg_Value; /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m0.i_trg'
                                        */
  real_T GearBoxM_OutGB_m0set_ParkBrake_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m0.set_ParkBrake'
                                               */
  real_T GearBoxM_OutGB_m0rotv_in_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m0.rotv_in_trg'
                                             */
  real_T GearBoxM_OutGB_m0Trq_out_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Trq_out_trg'
                                             */
  real_T GearBoxM_OutGB_m0ClutchPos_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch.Pos'
                                           */
  real_T GearBoxM_OutGB_m0Clutchrotv_out_trg_Value;/* Expression: 0
                                                    * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch.rotv_out_trg'
                                                    */
  real_T GearBoxM_OutGB_m0ClutchTrq_out_trg_Value;/* Expression: 0
                                                   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch.Trq_out_trg'
                                                   */
  real_T GearBoxM_OutGB_m0Clutch_disPos_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.Pos'
                                               */
  real_T GearBoxM_OutGB_m0Clutch_disrotv_out_trg_Value;/* Expression: 0
                                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.rotv_out_trg'
                                                        */
  real_T GearBoxM_OutGB_m0Clutch_disTrq_out_trg_Value;/* Expression: 0
                                                       * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.Trq_out_trg'
                                                       */
  real_T GearBoxM_OutGB_m1GearNoTrg_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m1.GearNoTrg'
                                           */
  real_T GearBoxM_OutGB_m1GearNoTrg_dis_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m1.GearNoTrg_dis'
                                               */
  real_T GearBoxM_OutGB_m1i_trg_Value; /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m1.i_trg'
                                        */
  real_T GearBoxM_OutGB_m1set_ParkBrake_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m1.set_ParkBrake'
                                               */
  real_T GearBoxM_OutGB_m1rotv_in_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m1.rotv_in_trg'
                                             */
  real_T GearBoxM_OutGB_m1Trq_out_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Trq_out_trg'
                                             */
  real_T GearBoxM_OutGB_m1ClutchPos_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch.Pos'
                                           */
  real_T GearBoxM_OutGB_m1Clutchrotv_out_trg_Value;/* Expression: 0
                                                    * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch.rotv_out_trg'
                                                    */
  real_T GearBoxM_OutGB_m1ClutchTrq_out_trg_Value;/* Expression: 0
                                                   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch.Trq_out_trg'
                                                   */
  real_T GearBoxM_OutGB_m1Clutch_disPos_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.Pos'
                                               */
  real_T GearBoxM_OutGB_m1Clutch_disrotv_out_trg_Value;/* Expression: 0
                                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.rotv_out_trg'
                                                        */
  real_T GearBoxM_OutGB_m1Clutch_disTrq_out_trg_Value;/* Expression: 0
                                                       * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.Trq_out_trg'
                                                       */
  real_T GearBoxM_OutGB_m2GearNoTrg_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m2.GearNoTrg'
                                           */
  real_T GearBoxM_OutGB_m2GearNoTrg_dis_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m2.GearNoTrg_dis'
                                               */
  real_T GearBoxM_OutGB_m2i_trg_Value; /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m2.i_trg'
                                        */
  real_T GearBoxM_OutGB_m2set_ParkBrake_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m2.set_ParkBrake'
                                               */
  real_T GearBoxM_OutGB_m2rotv_in_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m2.rotv_in_trg'
                                             */
  real_T GearBoxM_OutGB_m2Trq_out_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Trq_out_trg'
                                             */
  real_T GearBoxM_OutGB_m2ClutchPos_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch.Pos'
                                           */
  real_T GearBoxM_OutGB_m2Clutchrotv_out_trg_Value;/* Expression: 0
                                                    * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch.rotv_out_trg'
                                                    */
  real_T GearBoxM_OutGB_m2ClutchTrq_out_trg_Value;/* Expression: 0
                                                   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch.Trq_out_trg'
                                                   */
  real_T GearBoxM_OutGB_m2Clutch_disPos_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.Pos'
                                               */
  real_T GearBoxM_OutGB_m2Clutch_disrotv_out_trg_Value;/* Expression: 0
                                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.rotv_out_trg'
                                                        */
  real_T GearBoxM_OutGB_m2Clutch_disTrq_out_trg_Value;/* Expression: 0
                                                       * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.Trq_out_trg'
                                                       */
  real_T GearBoxM_OutGB_m3GearNoTrg_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m3.GearNoTrg'
                                           */
  real_T GearBoxM_OutGB_m3GearNoTrg_dis_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m3.GearNoTrg_dis'
                                               */
  real_T GearBoxM_OutGB_m3i_trg_Value; /* Expression: 0
                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m3.i_trg'
                                        */
  real_T GearBoxM_OutGB_m3set_ParkBrake_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m3.set_ParkBrake'
                                               */
  real_T GearBoxM_OutGB_m3rotv_in_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m3.rotv_in_trg'
                                             */
  real_T GearBoxM_OutGB_m3Trq_out_trg_Value;/* Expression: 0
                                             * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Trq_out_trg'
                                             */
  real_T GearBoxM_OutGB_m3ClutchPos_Value;/* Expression: 0
                                           * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch.Pos'
                                           */
  real_T GearBoxM_OutGB_m3Clutchrotv_out_trg_Value;/* Expression: 0
                                                    * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch.rotv_out_trg'
                                                    */
  real_T GearBoxM_OutGB_m3ClutchTrq_out_trg_Value;/* Expression: 0
                                                   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch.Trq_out_trg'
                                                   */
  real_T GearBoxM_OutGB_m3Clutch_disPos_Value;/* Expression: 0
                                               * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.Pos'
                                               */
  real_T GearBoxM_OutGB_m3Clutch_disrotv_out_trg_Value;/* Expression: 0
                                                        * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.rotv_out_trg'
                                                        */
  real_T GearBoxM_OutGB_m3Clutch_disTrq_out_trg_Value;/* Expression: 0
                                                       * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.Trq_out_trg'
                                                       */
  real_T PwrSupplyOutPwr_HV1toLV_trg_Value;/* Expression: 0
                                            * Referenced by: '<S1>/PwrSupplyOut.Pwr_HV1toLV_trg'
                                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_UNICARPTControl_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_UNICARPTControl_T *blockIO;
  ExtU_UNICARPTControl_T *inputs;
  ExtY_UNICARPTControl_T *outputs;
  DW_UNICARPTControl_T *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[131];
    int32_T* vardimsAddress[131];
    RTWLoggingFcnPtr loggingPtrs[131];
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_UNICARPTControl_T UNICARPTControl_P;

/* External data declarations for dependent source files */
extern const cmPTControlOut UNICARPTControl_rtZcmPTControlOut;/* cmPTControlOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern P_UNICARPTControl_T UNICARPTControl_P;/* parameters */

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_UNICARPTControl_T *UNICARPTControl(struct tInfos *inf);
extern void UNICARPTControl_initialize(RT_MODEL_UNICARPTControl_T *const
  UNICARPTControl_M);
extern void UNICARPTControl_step(RT_MODEL_UNICARPTControl_T *const
  UNICARPTControl_M);
extern void UNICARPTControl_terminate(RT_MODEL_UNICARPTControl_T
  * UNICARPTControl_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTControl_GetCAPIStaticMap(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'UNICARPTControl'
 * '<S1>'   : 'UNICARPTControl/IF_Out_Selector'
 * '<S2>'   : 'UNICARPTControl/PTControl0'
 * '<S3>'   : 'UNICARPTControl/PTControl1'
 * '<S4>'   : 'UNICARPTControl/PTControl2'
 * '<S5>'   : 'UNICARPTControl/PTControl3'
 * '<S6>'   : 'UNICARPTControl/PTControl0/PTControl Generic'
 * '<S7>'   : 'UNICARPTControl/PTControl0/PTControl Generic/ErrBit Handling'
 * '<S8>'   : 'UNICARPTControl/PTControl0/PTControl Generic/Saturation Dynamic'
 * '<S9>'   : 'UNICARPTControl/PTControl0/PTControl Generic/Tiefpass'
 * '<S10>'  : 'UNICARPTControl/PTControl1/PTControl Generic'
 * '<S11>'  : 'UNICARPTControl/PTControl1/PTControl Generic/ErrBit Handling'
 * '<S12>'  : 'UNICARPTControl/PTControl1/PTControl Generic/Saturation Dynamic'
 * '<S13>'  : 'UNICARPTControl/PTControl1/PTControl Generic/Tiefpass'
 * '<S14>'  : 'UNICARPTControl/PTControl2/PTControl Generic'
 * '<S15>'  : 'UNICARPTControl/PTControl2/PTControl Generic/ErrBit Handling'
 * '<S16>'  : 'UNICARPTControl/PTControl2/PTControl Generic/Saturation Dynamic'
 * '<S17>'  : 'UNICARPTControl/PTControl2/PTControl Generic/Tiefpass'
 * '<S18>'  : 'UNICARPTControl/PTControl3/PTControl Generic'
 * '<S19>'  : 'UNICARPTControl/PTControl3/PTControl Generic/ErrBit Handling'
 * '<S20>'  : 'UNICARPTControl/PTControl3/PTControl Generic/Saturation Dynamic'
 * '<S21>'  : 'UNICARPTControl/PTControl3/PTControl Generic/Tiefpass'
 */
#endif                                 /* RTW_HEADER_UNICARPTControl_h_ */
