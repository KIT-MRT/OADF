/*
 * UNICARSteer.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARSteer".
 *
 * Model version              : 1.83
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:31:29 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UNICARSteer_h_
#define RTW_HEADER_UNICARSteer_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef UNICARSteer_COMMON_INCLUDES_
# define UNICARSteer_COMMON_INCLUDES_
#include <stdlib.h>
#include <Global.h>
#include <TextUtils.h>
#include <DataDict.h>
#include <DirectVarAccess.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* UNICARSteer_COMMON_INCLUDES_ */

#include "UNICARSteer_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

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

#define UNICARSteer_M_TYPE             RT_MODEL_UNICARSteer_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.001
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ReadCMDict4;                  /* '<S5>/Read CM Dict4' */
  real_T ReadCMDict8;                  /* '<S2>/Read CM Dict8' */
  real_T Switch6;                      /* '<S2>/Switch6' */
  real_T ReadCMDict4_h;                /* '<S6>/Read CM Dict4' */
  real_T ReadCMDict9;                  /* '<S2>/Read CM Dict9' */
  real_T Switch7;                      /* '<S2>/Switch7' */
  real_T Derivative4;                  /* '<S2>/Derivative4' */
  real_T Derivative6;                  /* '<S2>/Derivative6' */
  real_T ReadCMDict4_f;                /* '<S3>/Read CM Dict4' */
  real_T ReadCMDict;                   /* '<S2>/Read CM Dict' */
  real_T Switch4;                      /* '<S2>/Switch4' */
  real_T Derivative;                   /* '<S2>/Derivative' */
  real_T ReadCMDict4_b;                /* '<S4>/Read CM Dict4' */
  real_T ReadCMDict7;                  /* '<S2>/Read CM Dict7' */
  real_T Switch5;                      /* '<S2>/Switch5' */
  real_T Derivative2;                  /* '<S2>/Derivative2' */
} B_UNICARSteer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S5>/Memory' */
  real_T Memory_PreviousInput_e;       /* '<S9>/Memory' */
  real_T Memory_PreviousInput_h;       /* '<S6>/Memory' */
  real_T Memory_PreviousInput_p;       /* '<S10>/Memory' */
  real_T TimeStampA;                   /* '<S2>/Derivative4' */
  real_T LastUAtTimeA;                 /* '<S2>/Derivative4' */
  real_T TimeStampB;                   /* '<S2>/Derivative4' */
  real_T LastUAtTimeB;                 /* '<S2>/Derivative4' */
  real_T TimeStampA_n;                 /* '<S2>/Derivative6' */
  real_T LastUAtTimeA_i;               /* '<S2>/Derivative6' */
  real_T TimeStampB_g;                 /* '<S2>/Derivative6' */
  real_T LastUAtTimeB_p;               /* '<S2>/Derivative6' */
  real_T Memory_PreviousInput_g;       /* '<S3>/Memory' */
  real_T Memory_PreviousInput_l;       /* '<S7>/Memory' */
  real_T TimeStampA_p;                 /* '<S2>/Derivative' */
  real_T LastUAtTimeA_a;               /* '<S2>/Derivative' */
  real_T TimeStampB_a;                 /* '<S2>/Derivative' */
  real_T LastUAtTimeB_k;               /* '<S2>/Derivative' */
  real_T TimeStampA_k;                 /* '<S2>/Derivative1' */
  real_T LastUAtTimeA_c;               /* '<S2>/Derivative1' */
  real_T TimeStampB_n;                 /* '<S2>/Derivative1' */
  real_T LastUAtTimeB_h;               /* '<S2>/Derivative1' */
  real_T Memory_PreviousInput_o;       /* '<S4>/Memory' */
  real_T Memory_PreviousInput_pz;      /* '<S8>/Memory' */
  real_T TimeStampA_g;                 /* '<S2>/Derivative2' */
  real_T LastUAtTimeA_j;               /* '<S2>/Derivative2' */
  real_T TimeStampB_a0;                /* '<S2>/Derivative2' */
  real_T LastUAtTimeB_j;               /* '<S2>/Derivative2' */
  real_T TimeStampA_gz;                /* '<S2>/Derivative3' */
  real_T LastUAtTimeA_jg;              /* '<S2>/Derivative3' */
  real_T TimeStampB_m;                 /* '<S2>/Derivative3' */
  real_T LastUAtTimeB_m;               /* '<S2>/Derivative3' */
  struct {
    void *Entry;
  } ReadCMDict4_PWORK;                 /* '<S5>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict8_PWORK;                 /* '<S2>/Read CM Dict8' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK;                 /* '<Root>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_p;               /* '<S6>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict9_PWORK;                 /* '<S2>/Read CM Dict9' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK;                /* '<Root>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK;                /* '<Root>/Write CM Dict2' */

  struct {
    void *Entry;
  } WriteCMDict3_PWORK;                /* '<Root>/Write CM Dict3' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_f;               /* '<S3>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK;                  /* '<S2>/Read CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_l;               /* '<S4>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict7_PWORK;                 /* '<S2>/Read CM Dict7' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK;                 /* '<S5>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict8_IWORK;                 /* '<S2>/Read CM Dict8' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK;                 /* '<Root>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_p;               /* '<S6>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict9_IWORK;                 /* '<S2>/Read CM Dict9' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK;                /* '<Root>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK;                /* '<Root>/Write CM Dict2' */

  struct {
    int_T Checked;
  } WriteCMDict3_IWORK;                /* '<Root>/Write CM Dict3' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_c;               /* '<S3>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK;                  /* '<S2>/Read CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_m;               /* '<S4>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict7_IWORK;                 /* '<S2>/Read CM Dict7' */
} DW_UNICARSteer_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmSteeringIn FromCM;                 /* '<Root>/FromCM' */
  cmSteeringCfgIn CfgInFromCM;         /* '<Root>/CfgInFromCM' */
  cmSteeringCfgOut CfgOutFromCM;       /* '<Root>/CfgOutFromCM' */
} ExtU_UNICARSteer_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmSteeringOut ToCM;                  /* '<Root>/ToCM' */
} ExtY_UNICARSteer_T;

/* Parameters (default storage) */
struct P_UNICARSteer_T_ {
  real_T ste_KPT1;                     /* Variable: ste_KPT1
                                        * Referenced by:
                                        *   '<S7>/Gain2'
                                        *   '<S8>/Gain2'
                                        *   '<S9>/Gain2'
                                        *   '<S10>/Gain2'
                                        */
  real_T ste_TPT1_1_s;                 /* Variable: ste_TPT1_1_s
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S8>/Constant1'
                                        *   '<S9>/Constant1'
                                        *   '<S10>/Constant1'
                                        */
  real_T ste_delta_p_lim_rad_s;        /* Variable: ste_delta_p_lim_rad_s
                                        * Referenced by:
                                        *   '<S7>/Constant2'
                                        *   '<S8>/Constant2'
                                        *   '<S9>/Constant2'
                                        *   '<S10>/Constant2'
                                        */
  real_T ste_dyn;                      /* Variable: ste_dyn
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T ste_max_delta_FLRR_rad;       /* Variable: ste_max_delta_FLRR_rad
                                        * Referenced by:
                                        *   '<S2>/Saturation'
                                        *   '<S2>/Saturation3'
                                        */
  real_T ste_max_delta_FRRL_rad;       /* Variable: ste_max_delta_FRRL_rad
                                        * Referenced by:
                                        *   '<S2>/Saturation1'
                                        *   '<S2>/Saturation2'
                                        */
  real_T ste_min_delta_FLRR_rad;       /* Variable: ste_min_delta_FLRR_rad
                                        * Referenced by:
                                        *   '<S2>/Saturation'
                                        *   '<S2>/Saturation3'
                                        */
  real_T ste_min_delta_FRRL_rad;       /* Variable: ste_min_delta_FRRL_rad
                                        * Referenced by:
                                        *   '<S2>/Saturation1'
                                        *   '<S2>/Saturation2'
                                        */
  real_T ste_t_s;                      /* Variable: ste_t_s
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S8>/Constant'
                                        *   '<S9>/Constant'
                                        *   '<S10>/Constant'
                                        */
  real_T Gain9_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain9'
                                        */
  real_T Gain9_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S8>/Gain9'
                                        */
  real_T Gain9_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain9'
                                        */
  real_T Gain9_Gain_af;                /* Expression: -1
                                        * Referenced by: '<S10>/Gain9'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S5>/Memory'
                                        */
  real_T Memory_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch6'
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S6>/Memory'
                                        */
  real_T Memory_InitialCondition_c;    /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch7'
                                        */
  real_T Ang_Value;                    /* Expression: 0
                                        * Referenced by: '<S1>/Ang'
                                        */
  real_T AngVel_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/AngVel'
                                        */
  real_T AngAcc_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/AngAcc'
                                        */
  real_T Trq_Value;                    /* Expression: 0
                                        * Referenced by: '<S1>/Trq'
                                        */
  real_T TrqStatic_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/TrqStatic'
                                        */
  real_T AssistFrc_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/AssistFrc'
                                        */
  real_T AssistTrqCol_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/AssistTrqCol'
                                        */
  real_T AssistTrqPin_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/AssistTrqPin'
                                        */
  real_T Memory_InitialCondition_n;    /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Memory_InitialCondition_e;    /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch4'
                                        */
  real_T iSteer2q_L_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/iSteer2q_L'
                                        */
  real_T Memory_InitialCondition_p2;   /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T Memory_InitialCondition_f;    /* Expression: 0
                                        * Referenced by: '<S8>/Memory'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch5'
                                        */
  real_T iSteer2q_R_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/iSteer2q_R'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_UNICARSteer_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_UNICARSteer_T *blockIO;
  ExtU_UNICARSteer_T *inputs;
  ExtY_UNICARSteer_T *outputs;
  DW_UNICARSteer_T *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[39];
    int32_T* vardimsAddress[39];
    RTWLoggingFcnPtr loggingPtrs[39];
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
extern P_UNICARSteer_T UNICARSteer_P;

/* External data declarations for dependent source files */
extern const cmSteeringOut UNICARSteer_rtZcmSteeringOut;/* cmSteeringOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern P_UNICARSteer_T UNICARSteer_P;  /* parameters */

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_UNICARSteer_T *UNICARSteer(struct tInfos *inf);
extern void UNICARSteer_initialize(RT_MODEL_UNICARSteer_T *const UNICARSteer_M);
extern void UNICARSteer_step(RT_MODEL_UNICARSteer_T *const UNICARSteer_M);
extern void UNICARSteer_terminate(RT_MODEL_UNICARSteer_T * UNICARSteer_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  UNICARSteer_GetCAPIStaticMap(void);

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
 * '<Root>' : 'UNICARSteer'
 * '<S1>'   : 'UNICARSteer/IF_Out_Selector'
 * '<S2>'   : 'UNICARSteer/Subsystem'
 * '<S3>'   : 'UNICARSteer/Subsystem/Error Handling'
 * '<S4>'   : 'UNICARSteer/Subsystem/Error Handling1'
 * '<S5>'   : 'UNICARSteer/Subsystem/Error Handling2'
 * '<S6>'   : 'UNICARSteer/Subsystem/Error Handling3'
 * '<S7>'   : 'UNICARSteer/Subsystem/Steer FL'
 * '<S8>'   : 'UNICARSteer/Subsystem/Steer FR'
 * '<S9>'   : 'UNICARSteer/Subsystem/Steer RL'
 * '<S10>'  : 'UNICARSteer/Subsystem/Steer RR'
 * '<S11>'  : 'UNICARSteer/Subsystem/Steer FL/Saturation Dynamic2'
 * '<S12>'  : 'UNICARSteer/Subsystem/Steer FR/Saturation Dynamic2'
 * '<S13>'  : 'UNICARSteer/Subsystem/Steer RL/Saturation Dynamic2'
 * '<S14>'  : 'UNICARSteer/Subsystem/Steer RR/Saturation Dynamic2'
 */
#endif                                 /* RTW_HEADER_UNICARSteer_h_ */
