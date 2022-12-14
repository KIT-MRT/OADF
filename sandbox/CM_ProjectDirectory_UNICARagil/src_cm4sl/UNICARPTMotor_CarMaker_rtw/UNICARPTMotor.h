/*
 * UNICARPTMotor.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARPTMotor".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:30:26 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UNICARPTMotor_h_
#define RTW_HEADER_UNICARPTMotor_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef UNICARPTMotor_COMMON_INCLUDES_
# define UNICARPTMotor_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* UNICARPTMotor_COMMON_INCLUDES_ */

#include "UNICARPTMotor_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
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

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define UNICARPTMotor_M_TYPE           RT_MODEL_UNICARPTMotor_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.0002
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Memory;                       /* '<S3>/Memory' */
  real_T Add1;                         /* '<S3>/Add1' */
  real_T Switch4;                      /* '<S2>/Switch4' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T M_ist_p;                      /* '<S4>/Sum' */
  real_T denominator1;                 /* '<S5>/Divide1' */
  real_T M_ist_p_f;                    /* '<S5>/Integrator' */
  real_T numerator1;                   /* '<S5>/Product5' */
  real_T denominator2;                 /* '<S5>/Product8' */
  real_T M_ist_pp;                     /* '<S5>/Sum' */
} B_UNICARPTMotor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S3>/Memory' */
} DW_UNICARPTMotor_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S5>/Integrator' */
} X_UNICARPTMotor_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S5>/Integrator' */
} XDot_UNICARPTMotor_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S5>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S5>/Integrator' */
} XDis_UNICARPTMotor_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmPTMotorIn FromCM;                  /* '<Root>/FromCM' */
  cmPTMotorCfgOut CfgOutFromCM;        /* '<Root>/CfgOutFromCM' */
} ExtU_UNICARPTMotor_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmPTMotorOut ToCM;                   /* '<Root>/ToCM' */
} ExtY_UNICARPTMotor_T;

/* Parameters (default storage) */
struct P_UNICARPTMotor_T_ {
  real_T mot_J_kgm_2;                  /* Variable: mot_J_kgm_2
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T mot_KPT1;                     /* Variable: mot_KPT1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T mot_KPT2;                     /* Variable: mot_KPT2
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T mot_MMax_PT12_Nm[4];          /* Variable: mot_MMax_PT12_Nm
                                        * Referenced by: '<S3>/1-D Lookup Table'
                                        */
  real_T mot_M_Nm[14];                 /* Variable: mot_M_Nm
                                        * Referenced by: '<S2>/Wirkungsgradkennfeld'
                                        */
  real_T mot_PMax_W;                   /* Variable: mot_PMax_W
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T mot_TPT1_1_s;                 /* Variable: mot_TPT1_1_s
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T mot_TPT2_1_s;                 /* Variable: mot_TPT2_1_s
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T mot_dPT2;                     /* Variable: mot_dPT2
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T mot_dyn;                      /* Variable: mot_dyn
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T mot_eta[210];                 /* Variable: mot_eta
                                        * Referenced by: '<S2>/Wirkungsgradkennfeld'
                                        */
  real_T mot_omega_PT12_rad_s[4];      /* Variable: mot_omega_PT12_rad_s
                                        * Referenced by: '<S3>/1-D Lookup Table'
                                        */
  real_T mot_omega_rad_s[15];          /* Variable: mot_omega_rad_s
                                        * Referenced by: '<S2>/Wirkungsgradkennfeld'
                                        */
  real_T mot_weight_PT12[16];          /* Variable: mot_weight_PT12
                                        * Referenced by: '<S3>/1-D Lookup Table'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Constant1_Value;              /* Expression: 0.001
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch4'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S3>/1-D Lookup Table'
                                    */
  uint32_T Wirkungsgradkennfeld_maxIndex[2];
                            /* Computed Parameter: Wirkungsgradkennfeld_maxIndex
                             * Referenced by: '<S2>/Wirkungsgradkennfeld'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_UNICARPTMotor_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  void *blockIO;
  const void *constBlockIO;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][3];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[26];
    int32_T* vardimsAddress[26];
    RTWLoggingFcnPtr loggingPtrs[26];
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_UNICARPTMotor_T UNICARPTMotor_P;

/* External data declarations for dependent source files */
extern const cmPTMotorOut UNICARPTMotor_rtZcmPTMotorOut;/* cmPTMotorOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_UNICARPTMotor_T *UNICARPTMotor(struct tInfos *inf);
extern void UNICARPTMotor_initialize(RT_MODEL_UNICARPTMotor_T *const
  UNICARPTMotor_M);
extern void UNICARPTMotor_step(RT_MODEL_UNICARPTMotor_T *const UNICARPTMotor_M);
extern void UNICARPTMotor_terminate(RT_MODEL_UNICARPTMotor_T * UNICARPTMotor_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTMotor_GetCAPIStaticMap(void);

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
 * '<Root>' : 'UNICARPTMotor'
 * '<S1>'   : 'UNICARPTMotor/IF_Out_Selector'
 * '<S2>'   : 'UNICARPTMotor/Motor'
 * '<S3>'   : 'UNICARPTMotor/Motor/Momentenregelung An'
 * '<S4>'   : 'UNICARPTMotor/Motor/Momentenregelung An/PT1'
 * '<S5>'   : 'UNICARPTMotor/Motor/Momentenregelung An/PT2'
 */
#endif                                 /* RTW_HEADER_UNICARPTMotor_h_ */
