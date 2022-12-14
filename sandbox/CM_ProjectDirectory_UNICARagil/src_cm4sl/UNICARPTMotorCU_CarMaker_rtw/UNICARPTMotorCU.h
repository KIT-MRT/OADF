/*
 * UNICARPTMotorCU.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARPTMotorCU".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:31:01 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UNICARPTMotorCU_h_
#define RTW_HEADER_UNICARPTMotorCU_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef UNICARPTMotorCU_COMMON_INCLUDES_
# define UNICARPTMotorCU_COMMON_INCLUDES_
#include <stdlib.h>
#include <Global.h>
#include <TextUtils.h>
#include <DataDict.h>
#include <DirectVarAccess.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* UNICARPTMotorCU_COMMON_INCLUDES_ */

#include "UNICARPTMotorCU_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
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

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
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

#define UNICARPTMotorCU_M_TYPE         RT_MODEL_UNICARPTMotorCU_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.0002
#endif

/* Block signals for system '<S11>/Calc alpha_An' */
typedef struct {
  real_T alpha_An;                     /* '<S11>/Calc alpha_An' */
} B_Calcalpha_An_UNICARPTMotorCU_T;

/* Block signals for system '<S14>/MATLAB Function' */
typedef struct {
  real_T trigger;                      /* '<S14>/MATLAB Function' */
  real_T I_max;                        /* '<S14>/MATLAB Function' */
  real_T t_mem1;                       /* '<S14>/MATLAB Function' */
  real_T t_mem2;                       /* '<S14>/MATLAB Function' */
  real_T m1;                           /* '<S14>/MATLAB Function' */
} B_MATLABFunction_UNICARPTMotorCU_T;

/* Block signals for system '<S14>/Resettable Subsystem' */
typedef struct {
  real_T Memory;                       /* '<S17>/Memory' */
  real_T Min;                          /* '<S17>/Min' */
} B_ResettableSubsystem_UNICARPTMotorCU_T;

/* Block states (default storage) for system '<S14>/Resettable Subsystem' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S17>/Memory' */
} DW_ResettableSubsystem_UNICARPTMotorCU_T;

/* Zero-crossing (trigger) state for system '<S14>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S14>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_UNICARPTMotorCU_T;

/* Block signals (default storage) */
typedef struct {
  real_T ReadCMDict;                   /* '<S11>/Read CM Dict' */
  real_T T_An;                         /* '<S11>/Integrator' */
  real_T IndexVector2;                 /* '<S10>/Index Vector2' */
  real_T IndexVector;                  /* '<S9>/Index Vector' */
  real_T Product4;                     /* '<S9>/Product4' */
  real_T SOC;                          /* '<S9>/Divide3' */
  real_T Switch;                       /* '<S9>/Switch' */
  real_T Divide;                       /* '<S9>/Divide' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T ReadCMDict_o;                 /* '<S15>/Read CM Dict' */
  real_T Memory10;                     /* '<S14>/Memory10' */
  real_T Clock2;                       /* '<S14>/Clock2' */
  real_T Memory7;                      /* '<S14>/Memory7' */
  real_T Memory9;                      /* '<S14>/Memory9' */
  real_T Memory8;                      /* '<S14>/Memory8' */
  real_T Memory11;                     /* '<S14>/Memory11' */
  real_T IndexVector2_c;               /* '<S8>/Index Vector2' */
  real_T Product9;                     /* '<S10>/Product9' */
  real_T Product8;                     /* '<S10>/Product8' */
  real_T ReadCMDict1;                  /* '<S11>/Read CM Dict1' */
  real_T ReadCMDict4;                  /* '<S11>/Read CM Dict4' */
  real_T v_Car;                        /* '<S11>/Sqrt1' */
  real_T Gain_n;                       /* '<S11>/Gain' */
  real_T q_kuehl;                      /* '<S11>/Product2' */
  real_T Product;                      /* '<S11>/Product' */
  real_T dT_An;                        /* '<S11>/Divide' */
  real_T IndexVector1;                 /* '<S8>/Index Vector1' */
  real_T IndexVector2_j;               /* '<S9>/Index Vector2' */
  real_T Sum;                          /* '<S9>/Sum' */
  real_T Sum2;                         /* '<S9>/Sum2' */
  real_T Product3;                     /* '<S15>/Product3' */
  real_T Product2;                     /* '<S15>/Product2' */
  real_T Product2_a;                   /* '<S10>/Product2' */
  real_T ReadCMDict_k;                 /* '<S23>/Read CM Dict' */
  real_T T_An_o;                       /* '<S23>/Integrator' */
  real_T IndexVector2_a;               /* '<S22>/Index Vector2' */
  real_T IndexVector_i;                /* '<S21>/Index Vector' */
  real_T Product4_m;                   /* '<S21>/Product4' */
  real_T SOC_g;                        /* '<S21>/Divide3' */
  real_T Switch_b;                     /* '<S21>/Switch' */
  real_T Divide_l;                     /* '<S21>/Divide' */
  real_T Gain_b;                       /* '<S21>/Gain' */
  real_T ReadCMDict_kb;                /* '<S27>/Read CM Dict' */
  real_T Memory10_j;                   /* '<S26>/Memory10' */
  real_T Clock2_b;                     /* '<S26>/Clock2' */
  real_T Memory7_a;                    /* '<S26>/Memory7' */
  real_T Memory9_j;                    /* '<S26>/Memory9' */
  real_T Memory8_k;                    /* '<S26>/Memory8' */
  real_T Memory11_i;                   /* '<S26>/Memory11' */
  real_T IndexVector2_k;               /* '<S20>/Index Vector2' */
  real_T Product9_n;                   /* '<S22>/Product9' */
  real_T Product8_k;                   /* '<S22>/Product8' */
  real_T ReadCMDict1_e;                /* '<S23>/Read CM Dict1' */
  real_T ReadCMDict4_i;                /* '<S23>/Read CM Dict4' */
  real_T v_Car_l;                      /* '<S23>/Sqrt1' */
  real_T Gain_j;                       /* '<S23>/Gain' */
  real_T q_kuehl_b;                    /* '<S23>/Product2' */
  real_T Product_a;                    /* '<S23>/Product' */
  real_T dT_An_a;                      /* '<S23>/Divide' */
  real_T IndexVector1_g;               /* '<S20>/Index Vector1' */
  real_T IndexVector2_f;               /* '<S21>/Index Vector2' */
  real_T Sum_h;                        /* '<S21>/Sum' */
  real_T Sum2_m;                       /* '<S21>/Sum2' */
  real_T Product3_i;                   /* '<S27>/Product3' */
  real_T Product2_ax;                  /* '<S27>/Product2' */
  real_T Product2_o;                   /* '<S22>/Product2' */
  real_T ReadCMDict_p;                 /* '<S35>/Read CM Dict' */
  real_T T_An_oc;                      /* '<S35>/Integrator' */
  real_T IndexVector2_d;               /* '<S34>/Index Vector2' */
  real_T IndexVector_n;                /* '<S33>/Index Vector' */
  real_T Product4_b;                   /* '<S33>/Product4' */
  real_T SOC_j;                        /* '<S33>/Divide3' */
  real_T Switch_d;                     /* '<S33>/Switch' */
  real_T Divide_c;                     /* '<S33>/Divide' */
  real_T Gain_e;                       /* '<S33>/Gain' */
  real_T ReadCMDict_c;                 /* '<S39>/Read CM Dict' */
  real_T Memory10_n;                   /* '<S38>/Memory10' */
  real_T Clock2_n;                     /* '<S38>/Clock2' */
  real_T Memory7_o;                    /* '<S38>/Memory7' */
  real_T Memory9_n;                    /* '<S38>/Memory9' */
  real_T Memory8_m;                    /* '<S38>/Memory8' */
  real_T Memory11_g;                   /* '<S38>/Memory11' */
  real_T IndexVector2_l;               /* '<S32>/Index Vector2' */
  real_T Product9_m;                   /* '<S34>/Product9' */
  real_T Product8_j;                   /* '<S34>/Product8' */
  real_T ReadCMDict1_c;                /* '<S35>/Read CM Dict1' */
  real_T ReadCMDict4_m;                /* '<S35>/Read CM Dict4' */
  real_T v_Car_b;                      /* '<S35>/Sqrt1' */
  real_T Gain_nd;                      /* '<S35>/Gain' */
  real_T q_kuehl_m;                    /* '<S35>/Product2' */
  real_T Product_e;                    /* '<S35>/Product' */
  real_T dT_An_l;                      /* '<S35>/Divide' */
  real_T IndexVector1_e;               /* '<S32>/Index Vector1' */
  real_T IndexVector2_i;               /* '<S33>/Index Vector2' */
  real_T Sum_e;                        /* '<S33>/Sum' */
  real_T Sum2_c;                       /* '<S33>/Sum2' */
  real_T Product3_e;                   /* '<S39>/Product3' */
  real_T Product2_b;                   /* '<S39>/Product2' */
  real_T Product2_j;                   /* '<S34>/Product2' */
  real_T ReadCMDict_l;                 /* '<S47>/Read CM Dict' */
  real_T T_An_n;                       /* '<S47>/Integrator' */
  real_T IndexVector2_n;               /* '<S46>/Index Vector2' */
  real_T IndexVector_f;                /* '<S45>/Index Vector' */
  real_T Product4_bm;                  /* '<S45>/Product4' */
  real_T SOC_c;                        /* '<S45>/Divide3' */
  real_T Switch_f;                     /* '<S45>/Switch' */
  real_T Divide_j;                     /* '<S45>/Divide' */
  real_T Gain_by;                      /* '<S45>/Gain' */
  real_T ReadCMDict_j;                 /* '<S51>/Read CM Dict' */
  real_T Memory10_f;                   /* '<S50>/Memory10' */
  real_T Clock2_b1;                    /* '<S50>/Clock2' */
  real_T Memory7_e;                    /* '<S50>/Memory7' */
  real_T Memory9_c;                    /* '<S50>/Memory9' */
  real_T Memory8_o;                    /* '<S50>/Memory8' */
  real_T Memory11_a;                   /* '<S50>/Memory11' */
  real_T IndexVector2_jk;              /* '<S44>/Index Vector2' */
  real_T Product9_mz;                  /* '<S46>/Product9' */
  real_T Product8_c;                   /* '<S46>/Product8' */
  real_T ReadCMDict1_a;                /* '<S47>/Read CM Dict1' */
  real_T ReadCMDict4_h;                /* '<S47>/Read CM Dict4' */
  real_T v_Car_d;                      /* '<S47>/Sqrt1' */
  real_T Gain_a;                       /* '<S47>/Gain' */
  real_T q_kuehl_n;                    /* '<S47>/Product2' */
  real_T Product_e1;                   /* '<S47>/Product' */
  real_T dT_An_b;                      /* '<S47>/Divide' */
  real_T IndexVector1_gb;              /* '<S44>/Index Vector1' */
  real_T IndexVector2_g;               /* '<S45>/Index Vector2' */
  real_T Sum_e5;                       /* '<S45>/Sum' */
  real_T Sum2_h;                       /* '<S45>/Sum2' */
  real_T Product3_j;                   /* '<S51>/Product3' */
  real_T Product2_c;                   /* '<S51>/Product2' */
  real_T Product2_e;                   /* '<S46>/Product2' */
  B_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_f;/* '<S50>/Resettable Subsystem' */
  B_MATLABFunction_UNICARPTMotorCU_T sf_MATLABFunction_ad;/* '<S50>/MATLAB Function' */
  B_Calcalpha_An_UNICARPTMotorCU_T sf_Calcalpha_An_g;/* '<S47>/Calc alpha_An' */
  B_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_nm;/* '<S38>/Resettable Subsystem' */
  B_MATLABFunction_UNICARPTMotorCU_T sf_MATLABFunction_f;/* '<S38>/MATLAB Function' */
  B_Calcalpha_An_UNICARPTMotorCU_T sf_Calcalpha_An_d;/* '<S35>/Calc alpha_An' */
  B_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_n;/* '<S26>/Resettable Subsystem' */
  B_MATLABFunction_UNICARPTMotorCU_T sf_MATLABFunction_a;/* '<S26>/MATLAB Function' */
  B_Calcalpha_An_UNICARPTMotorCU_T sf_Calcalpha_An_j;/* '<S23>/Calc alpha_An' */
  B_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem;/* '<S14>/Resettable Subsystem' */
  B_MATLABFunction_UNICARPTMotorCU_T sf_MATLABFunction;/* '<S14>/MATLAB Function' */
  B_Calcalpha_An_UNICARPTMotorCU_T sf_Calcalpha_An;/* '<S11>/Calc alpha_An' */
} B_UNICARPTMotorCU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T Memory10_PreviousInput;       /* '<S14>/Memory10' */
  real_T Memory7_PreviousInput;        /* '<S14>/Memory7' */
  real_T Memory9_PreviousInput;        /* '<S14>/Memory9' */
  real_T Memory8_PreviousInput;        /* '<S14>/Memory8' */
  real_T Memory11_PreviousInput;       /* '<S14>/Memory11' */
  real_T Memory_PreviousInput_b;       /* '<S11>/Memory' */
  real_T Memory_PreviousInput_bq;      /* '<S21>/Memory' */
  real_T Memory10_PreviousInput_m;     /* '<S26>/Memory10' */
  real_T Memory7_PreviousInput_g;      /* '<S26>/Memory7' */
  real_T Memory9_PreviousInput_o;      /* '<S26>/Memory9' */
  real_T Memory8_PreviousInput_m;      /* '<S26>/Memory8' */
  real_T Memory11_PreviousInput_f;     /* '<S26>/Memory11' */
  real_T Memory_PreviousInput_g;       /* '<S23>/Memory' */
  real_T Memory_PreviousInput_gf;      /* '<S33>/Memory' */
  real_T Memory10_PreviousInput_d;     /* '<S38>/Memory10' */
  real_T Memory7_PreviousInput_m;      /* '<S38>/Memory7' */
  real_T Memory9_PreviousInput_d;      /* '<S38>/Memory9' */
  real_T Memory8_PreviousInput_o;      /* '<S38>/Memory8' */
  real_T Memory11_PreviousInput_g;     /* '<S38>/Memory11' */
  real_T Memory_PreviousInput_j;       /* '<S35>/Memory' */
  real_T Memory_PreviousInput_h;       /* '<S45>/Memory' */
  real_T Memory10_PreviousInput_n;     /* '<S50>/Memory10' */
  real_T Memory7_PreviousInput_l;      /* '<S50>/Memory7' */
  real_T Memory9_PreviousInput_h;      /* '<S50>/Memory9' */
  real_T Memory8_PreviousInput_d;      /* '<S50>/Memory8' */
  real_T Memory11_PreviousInput_gv;    /* '<S50>/Memory11' */
  real_T Memory_PreviousInput_k;       /* '<S47>/Memory' */
  struct {
    void *Entry;
  } ReadCMDict_PWORK;                  /* '<S11>/Read CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_n;                /* '<S15>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK;                 /* '<S2>/Write CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK;                /* '<S2>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK;                /* '<S2>/Write CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK;                 /* '<S11>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK;                 /* '<S11>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_o;                /* '<S23>/Read CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_a;                /* '<S27>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_a;               /* '<S3>/Write CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK_m;              /* '<S3>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK_j;              /* '<S3>/Write CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_b;               /* '<S23>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_i;               /* '<S23>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_k;                /* '<S35>/Read CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_b;                /* '<S39>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_n;               /* '<S4>/Write CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK_c;              /* '<S4>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK_k;              /* '<S4>/Write CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_e;               /* '<S35>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_m;               /* '<S35>/Read CM Dict4' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_f;                /* '<S47>/Read CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_nq;               /* '<S51>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_a2;              /* '<S5>/Write CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK_i;              /* '<S5>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK_f;              /* '<S5>/Write CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_k;               /* '<S47>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_c;               /* '<S47>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK;                  /* '<S11>/Read CM Dict' */

  int_T Integrator_IWORK;              /* '<S11>/Integrator' */
  int_T Integrator2_IWORK;             /* '<S9>/Integrator2' */
  struct {
    int_T Checked;
  } ReadCMDict_IWORK_p;                /* '<S15>/Read CM Dict' */

  int_T Integrator_IWORK_m;            /* '<S15>/Integrator' */
  struct {
    int_T Checked;
  } WriteCMDict_IWORK;                 /* '<S2>/Write CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK;                /* '<S2>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK;                /* '<S2>/Write CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK;                 /* '<S11>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK;                 /* '<S11>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_b;                /* '<S23>/Read CM Dict' */

  int_T Integrator_IWORK_f;            /* '<S23>/Integrator' */
  int_T Integrator2_IWORK_g;           /* '<S21>/Integrator2' */
  struct {
    int_T Checked;
  } ReadCMDict_IWORK_l;                /* '<S27>/Read CM Dict' */

  int_T Integrator_IWORK_g;            /* '<S27>/Integrator' */
  struct {
    int_T Checked;
  } WriteCMDict_IWORK_i;               /* '<S3>/Write CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK_h;              /* '<S3>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK_f;              /* '<S3>/Write CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_d;               /* '<S23>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_j;               /* '<S23>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_h;                /* '<S35>/Read CM Dict' */

  int_T Integrator_IWORK_h;            /* '<S35>/Integrator' */
  int_T Integrator2_IWORK_i;           /* '<S33>/Integrator2' */
  struct {
    int_T Checked;
  } ReadCMDict_IWORK_n;                /* '<S39>/Read CM Dict' */

  int_T Integrator_IWORK_fs;           /* '<S39>/Integrator' */
  struct {
    int_T Checked;
  } WriteCMDict_IWORK_e;               /* '<S4>/Write CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK_g;              /* '<S4>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK_c;              /* '<S4>/Write CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_k;               /* '<S35>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_c;               /* '<S35>/Read CM Dict4' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_i;                /* '<S47>/Read CM Dict' */

  int_T Integrator_IWORK_fg;           /* '<S47>/Integrator' */
  int_T Integrator2_IWORK_d;           /* '<S45>/Integrator2' */
  struct {
    int_T Checked;
  } ReadCMDict_IWORK_c;                /* '<S51>/Read CM Dict' */

  int_T Integrator_IWORK_fq;           /* '<S51>/Integrator' */
  struct {
    int_T Checked;
  } WriteCMDict_IWORK_c;               /* '<S5>/Write CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK_m;              /* '<S5>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK_d;              /* '<S5>/Write CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_kx;              /* '<S47>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_h;               /* '<S47>/Read CM Dict4' */

  DW_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_f;/* '<S50>/Resettable Subsystem' */
  DW_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_nm;/* '<S38>/Resettable Subsystem' */
  DW_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_n;/* '<S26>/Resettable Subsystem' */
  DW_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem;/* '<S14>/Resettable Subsystem' */
} DW_UNICARPTMotorCU_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
  real_T Integrator_CSTATE_f;          /* '<S9>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S9>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S9>/Transfer Fcn' */
  real_T Integrator_CSTATE_h;          /* '<S15>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S23>/Integrator' */
  real_T Integrator2_CSTATE_p;         /* '<S21>/Integrator2' */
  real_T Integrator_CSTATE_g;          /* '<S21>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S21>/Integrator1' */
  real_T TransferFcn_CSTATE_c;         /* '<S21>/Transfer Fcn' */
  real_T Integrator_CSTATE_j;          /* '<S27>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S35>/Integrator' */
  real_T Integrator2_CSTATE_h;         /* '<S33>/Integrator2' */
  real_T Integrator_CSTATE_ga;         /* '<S33>/Integrator' */
  real_T Integrator1_CSTATE_n;         /* '<S33>/Integrator1' */
  real_T TransferFcn_CSTATE_i;         /* '<S33>/Transfer Fcn' */
  real_T Integrator_CSTATE_b;          /* '<S39>/Integrator' */
  real_T Integrator_CSTATE_ci;         /* '<S47>/Integrator' */
  real_T Integrator2_CSTATE_k;         /* '<S45>/Integrator2' */
  real_T Integrator_CSTATE_jg;         /* '<S45>/Integrator' */
  real_T Integrator1_CSTATE_b;         /* '<S45>/Integrator1' */
  real_T TransferFcn_CSTATE_n;         /* '<S45>/Transfer Fcn' */
  real_T Integrator_CSTATE_m;          /* '<S51>/Integrator' */
} X_UNICARPTMotorCU_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
  real_T Integrator_CSTATE_f;          /* '<S9>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S9>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S9>/Transfer Fcn' */
  real_T Integrator_CSTATE_h;          /* '<S15>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S23>/Integrator' */
  real_T Integrator2_CSTATE_p;         /* '<S21>/Integrator2' */
  real_T Integrator_CSTATE_g;          /* '<S21>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S21>/Integrator1' */
  real_T TransferFcn_CSTATE_c;         /* '<S21>/Transfer Fcn' */
  real_T Integrator_CSTATE_j;          /* '<S27>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S35>/Integrator' */
  real_T Integrator2_CSTATE_h;         /* '<S33>/Integrator2' */
  real_T Integrator_CSTATE_ga;         /* '<S33>/Integrator' */
  real_T Integrator1_CSTATE_n;         /* '<S33>/Integrator1' */
  real_T TransferFcn_CSTATE_i;         /* '<S33>/Transfer Fcn' */
  real_T Integrator_CSTATE_b;          /* '<S39>/Integrator' */
  real_T Integrator_CSTATE_ci;         /* '<S47>/Integrator' */
  real_T Integrator2_CSTATE_k;         /* '<S45>/Integrator2' */
  real_T Integrator_CSTATE_jg;         /* '<S45>/Integrator' */
  real_T Integrator1_CSTATE_b;         /* '<S45>/Integrator1' */
  real_T TransferFcn_CSTATE_n;         /* '<S45>/Transfer Fcn' */
  real_T Integrator_CSTATE_m;          /* '<S51>/Integrator' */
} XDot_UNICARPTMotorCU_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S11>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S9>/Integrator2' */
  boolean_T Integrator_CSTATE_f;       /* '<S9>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S9>/Integrator1' */
  boolean_T TransferFcn_CSTATE;        /* '<S9>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_h;       /* '<S15>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S23>/Integrator' */
  boolean_T Integrator2_CSTATE_p;      /* '<S21>/Integrator2' */
  boolean_T Integrator_CSTATE_g;       /* '<S21>/Integrator' */
  boolean_T Integrator1_CSTATE_p;      /* '<S21>/Integrator1' */
  boolean_T TransferFcn_CSTATE_c;      /* '<S21>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_j;       /* '<S27>/Integrator' */
  boolean_T Integrator_CSTATE_c;       /* '<S35>/Integrator' */
  boolean_T Integrator2_CSTATE_h;      /* '<S33>/Integrator2' */
  boolean_T Integrator_CSTATE_ga;      /* '<S33>/Integrator' */
  boolean_T Integrator1_CSTATE_n;      /* '<S33>/Integrator1' */
  boolean_T TransferFcn_CSTATE_i;      /* '<S33>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_b;       /* '<S39>/Integrator' */
  boolean_T Integrator_CSTATE_ci;      /* '<S47>/Integrator' */
  boolean_T Integrator2_CSTATE_k;      /* '<S45>/Integrator2' */
  boolean_T Integrator_CSTATE_jg;      /* '<S45>/Integrator' */
  boolean_T Integrator1_CSTATE_b;      /* '<S45>/Integrator1' */
  boolean_T TransferFcn_CSTATE_n;      /* '<S45>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_m;       /* '<S51>/Integrator' */
} XDis_UNICARPTMotorCU_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_f;/* '<S50>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_nm;/* '<S38>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem_n;/* '<S26>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_UNICARPTMotorCU_T ResettableSubsystem;/* '<S14>/Resettable Subsystem' */
} PrevZCX_UNICARPTMotorCU_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmPTMotorCUIn FromCM;                /* '<Root>/FromCM' */
  cmPTMotorCUCfgIn CfgInFromCM;        /* '<Root>/CfgInFromCM' */
} ExtU_UNICARPTMotorCU_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmPTMotorCUOut ToCM;                 /* '<Root>/ToCM' */
} ExtY_UNICARPTMotorCU_T;

/* Parameters (default storage) */
struct P_UNICARPTMotorCU_T_ {
  real_T MCU_Pr;                       /* Variable: MCU_Pr
                                        * Referenced by:
                                        *   '<S11>/Constant10'
                                        *   '<S23>/Constant10'
                                        *   '<S35>/Constant10'
                                        *   '<S47>/Constant10'
                                        */
  real_T MCU_alpha_m_2_s;              /* Variable: MCU_alpha_m_2_s
                                        * Referenced by:
                                        *   '<S11>/Constant11'
                                        *   '<S23>/Constant11'
                                        *   '<S35>/Constant11'
                                        *   '<S47>/Constant11'
                                        */
  real_T MCU_area_m_2;                 /* Variable: MCU_area_m_2
                                        * Referenced by:
                                        *   '<S11>/Constant2'
                                        *   '<S23>/Constant2'
                                        *   '<S35>/Constant2'
                                        *   '<S47>/Constant2'
                                        */
  real_T MCU_cp_J_kgK;                 /* Variable: MCU_cp_J_kgK
                                        * Referenced by:
                                        *   '<S11>/Constant1'
                                        *   '<S23>/Constant1'
                                        *   '<S35>/Constant1'
                                        *   '<S47>/Constant1'
                                        */
  real_T MCU_m_kg;                     /* Variable: MCU_m_kg
                                        * Referenced by:
                                        *   '<S11>/Constant'
                                        *   '<S23>/Constant'
                                        *   '<S35>/Constant'
                                        *   '<S47>/Constant'
                                        */
  real_T MCU_nue_Ns_m_2;               /* Variable: MCU_nue_Ns_m_2
                                        * Referenced by:
                                        *   '<S11>/Constant9'
                                        *   '<S23>/Constant9'
                                        *   '<S35>/Constant9'
                                        *   '<S47>/Constant9'
                                        */
  real_T MCU_q_W;                      /* Variable: MCU_q_W
                                        * Referenced by:
                                        *   '<S11>/Constant4'
                                        *   '<S23>/Constant4'
                                        *   '<S35>/Constant4'
                                        *   '<S47>/Constant4'
                                        */
  real_T MCU_r_m;                      /* Variable: MCU_r_m
                                        * Referenced by:
                                        *   '<S11>/Constant8'
                                        *   '<S23>/Constant8'
                                        *   '<S35>/Constant8'
                                        *   '<S47>/Constant8'
                                        */
  real_T bat_C1_F[3];                  /* Variable: bat_C1_F
                                        * Referenced by:
                                        *   '<S9>/Constant2'
                                        *   '<S21>/Constant2'
                                        *   '<S33>/Constant2'
                                        *   '<S45>/Constant2'
                                        */
  real_T bat_C2_F[3];                  /* Variable: bat_C2_F
                                        * Referenced by:
                                        *   '<S9>/Constant3'
                                        *   '<S21>/Constant3'
                                        *   '<S33>/Constant3'
                                        *   '<S45>/Constant3'
                                        */
  real_T bat_Call_F[4];                /* Variable: bat_Call_F
                                        * Referenced by:
                                        *   '<S9>/Constant1'
                                        *   '<S21>/Constant1'
                                        *   '<S33>/Constant1'
                                        *   '<S45>/Constant1'
                                        */
  real_T bat_ICC_A;                    /* Variable: bat_ICC_A
                                        * Referenced by:
                                        *   '<S14>/Constant11'
                                        *   '<S26>/Constant11'
                                        *   '<S38>/Constant11'
                                        *   '<S50>/Constant11'
                                        */
  real_T bat_ILim_A[9];                /* Variable: bat_ILim_A
                                        * Referenced by:
                                        *   '<S14>/1-D Lookup Table'
                                        *   '<S26>/1-D Lookup Table'
                                        *   '<S38>/1-D Lookup Table'
                                        *   '<S50>/1-D Lookup Table'
                                        */
  real_T bat_ILoadMax_A;               /* Variable: bat_ILoadMax_A
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S22>/Constant'
                                        *   '<S34>/Constant'
                                        *   '<S46>/Constant'
                                        */
  real_T bat_IMax_A;                   /* Variable: bat_IMax_A
                                        * Referenced by:
                                        *   '<S14>/Constant12'
                                        *   '<S26>/Constant12'
                                        *   '<S38>/Constant12'
                                        *   '<S50>/Constant12'
                                        */
  real_T bat_ItMax_A[5];               /* Variable: bat_ItMax_A
                                        * Referenced by:
                                        *   '<S14>/1-D Lookup Table1'
                                        *   '<S26>/1-D Lookup Table1'
                                        *   '<S38>/1-D Lookup Table1'
                                        *   '<S50>/1-D Lookup Table1'
                                        */
  real_T bat_KtMax[5];                 /* Variable: bat_KtMax
                                        * Referenced by:
                                        *   '<S14>/1-D Lookup Table1'
                                        *   '<S26>/1-D Lookup Table1'
                                        *   '<S38>/1-D Lookup Table1'
                                        *   '<S50>/1-D Lookup Table1'
                                        */
  real_T bat_P_W[4];                   /* Variable: bat_P_W
                                        * Referenced by:
                                        *   '<S9>/Constant10'
                                        *   '<S10>/Constant10'
                                        *   '<S21>/Constant10'
                                        *   '<S22>/Constant10'
                                        *   '<S33>/Constant10'
                                        *   '<S34>/Constant10'
                                        *   '<S45>/Constant10'
                                        *   '<S46>/Constant10'
                                        */
  real_T bat_R1_Ohm[3];                /* Variable: bat_R1_Ohm
                                        * Referenced by:
                                        *   '<S9>/Constant6'
                                        *   '<S21>/Constant6'
                                        *   '<S33>/Constant6'
                                        *   '<S45>/Constant6'
                                        */
  real_T bat_R2_Ohm[3];                /* Variable: bat_R2_Ohm
                                        * Referenced by:
                                        *   '<S9>/Constant4'
                                        *   '<S21>/Constant4'
                                        *   '<S33>/Constant4'
                                        *   '<S45>/Constant4'
                                        */
  real_T bat_R_Ohm[3];                 /* Variable: bat_R_Ohm
                                        * Referenced by:
                                        *   '<S9>/Constant5'
                                        *   '<S21>/Constant5'
                                        *   '<S33>/Constant5'
                                        *   '<S45>/Constant5'
                                        */
  real_T bat_SOCMax[4];                /* Variable: bat_SOCMax
                                        * Referenced by:
                                        *   '<S8>/Constant'
                                        *   '<S20>/Constant'
                                        *   '<S32>/Constant'
                                        *   '<S44>/Constant'
                                        */
  real_T bat_SOCMin[4];                /* Variable: bat_SOCMin
                                        * Referenced by:
                                        *   '<S8>/Constant2'
                                        *   '<S20>/Constant2'
                                        *   '<S32>/Constant2'
                                        *   '<S44>/Constant2'
                                        */
  real_T bat_SOCini[4];                /* Variable: bat_SOCini
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S21>/Constant'
                                        *   '<S33>/Constant'
                                        *   '<S45>/Constant'
                                        */
  real_T bat_TLim_K[9];                /* Variable: bat_TLim_K
                                        * Referenced by:
                                        *   '<S14>/1-D Lookup Table'
                                        *   '<S26>/1-D Lookup Table'
                                        *   '<S38>/1-D Lookup Table'
                                        *   '<S50>/1-D Lookup Table'
                                        */
  real_T bat_Uoc_V[6];                 /* Variable: bat_Uoc_V
                                        * Referenced by:
                                        *   '<S9>/Constant7'
                                        *   '<S21>/Constant7'
                                        *   '<S33>/Constant7'
                                        *   '<S45>/Constant7'
                                        */
  real_T bat_alpha_W_Km_2;             /* Variable: bat_alpha_W_Km_2
                                        * Referenced by:
                                        *   '<S15>/Constant5'
                                        *   '<S27>/Constant5'
                                        *   '<S39>/Constant5'
                                        *   '<S51>/Constant5'
                                        */
  real_T bat_area_m_2;                 /* Variable: bat_area_m_2
                                        * Referenced by:
                                        *   '<S15>/Constant4'
                                        *   '<S27>/Constant4'
                                        *   '<S39>/Constant4'
                                        *   '<S51>/Constant4'
                                        */
  real_T bat_cp_J_kgK;                 /* Variable: bat_cp_J_kgK
                                        * Referenced by:
                                        *   '<S15>/Constant1'
                                        *   '<S27>/Constant1'
                                        *   '<S39>/Constant1'
                                        *   '<S51>/Constant1'
                                        */
  real_T bat_m_kg;                     /* Variable: bat_m_kg
                                        * Referenced by:
                                        *   '<S15>/Constant'
                                        *   '<S27>/Constant'
                                        *   '<S39>/Constant'
                                        *   '<S51>/Constant'
                                        */
  real_T bat_nPar;                     /* Variable: bat_nPar
                                        * Referenced by:
                                        *   '<S9>/Constant11'
                                        *   '<S9>/Constant12'
                                        *   '<S21>/Constant11'
                                        *   '<S21>/Constant12'
                                        *   '<S33>/Constant11'
                                        *   '<S33>/Constant12'
                                        *   '<S45>/Constant11'
                                        *   '<S45>/Constant12'
                                        *   '<S14>/Gain'
                                        *   '<S26>/Gain'
                                        *   '<S38>/Gain'
                                        *   '<S50>/Gain'
                                        */
  real_T bat_nSe;                      /* Variable: bat_nSe
                                        * Referenced by:
                                        *   '<S9>/Gain'
                                        *   '<S9>/Gain1'
                                        *   '<S21>/Gain'
                                        *   '<S21>/Gain1'
                                        *   '<S33>/Gain'
                                        *   '<S33>/Gain1'
                                        *   '<S45>/Gain'
                                        *   '<S45>/Gain1'
                                        */
  real_T bat_q_W;                      /* Variable: bat_q_W
                                        * Referenced by:
                                        *   '<S15>/Constant2'
                                        *   '<S27>/Constant2'
                                        *   '<S39>/Constant2'
                                        *   '<S51>/Constant2'
                                        */
  real_T bat_tBreak_s;                 /* Variable: bat_tBreak_s
                                        * Referenced by:
                                        *   '<S14>/Constant13'
                                        *   '<S26>/Constant13'
                                        *   '<S38>/Constant13'
                                        *   '<S50>/Constant13'
                                        */
  real_T bat_tIMax_s;                  /* Variable: bat_tIMax_s
                                        * Referenced by:
                                        *   '<S14>/Constant2'
                                        *   '<S26>/Constant2'
                                        *   '<S38>/Constant2'
                                        *   '<S50>/Constant2'
                                        *   '<S17>/Memory'
                                        *   '<S29>/Memory'
                                        *   '<S41>/Memory'
                                        *   '<S53>/Memory'
                                        */
  real_T mot_MC_Nm[4];                 /* Variable: mot_MC_Nm
                                        * Referenced by:
                                        *   '<S10>/Dauermoment Motor'
                                        *   '<S22>/Dauermoment Motor'
                                        *   '<S34>/Dauermoment Motor'
                                        *   '<S46>/Dauermoment Motor'
                                        */
  real_T mot_MMaxReg_Nm[9];            /* Variable: mot_MMaxReg_Nm
                                        * Referenced by:
                                        *   '<S10>/1-D Lookup Table'
                                        *   '<S22>/1-D Lookup Table'
                                        *   '<S34>/1-D Lookup Table'
                                        *   '<S46>/1-D Lookup Table'
                                        */
  real_T mot_MPeak_Nm[6];              /* Variable: mot_MPeak_Nm
                                        * Referenced by:
                                        *   '<S10>/Spitzenmoment Motor'
                                        *   '<S22>/Spitzenmoment Motor'
                                        *   '<S34>/Spitzenmoment Motor'
                                        *   '<S46>/Spitzenmoment Motor'
                                        */
  real_T mot_M_Nm[14];                 /* Variable: mot_M_Nm
                                        * Referenced by:
                                        *   '<S7>/Wirkungsgradkennfeld'
                                        *   '<S19>/Wirkungsgradkennfeld'
                                        *   '<S31>/Wirkungsgradkennfeld'
                                        *   '<S43>/Wirkungsgradkennfeld'
                                        */
  real_T mot_TMPeak_K[4];              /* Variable: mot_TMPeak_K
                                        * Referenced by:
                                        *   '<S10>/Spitzenmomentberechnung Motor'
                                        *   '<S22>/Spitzenmomentberechnung Motor'
                                        *   '<S34>/Spitzenmomentberechnung Motor'
                                        *   '<S46>/Spitzenmomentberechnung Motor'
                                        */
  real_T mot_eta[210];                 /* Variable: mot_eta
                                        * Referenced by:
                                        *   '<S7>/Wirkungsgradkennfeld'
                                        *   '<S19>/Wirkungsgradkennfeld'
                                        *   '<S31>/Wirkungsgradkennfeld'
                                        *   '<S43>/Wirkungsgradkennfeld'
                                        */
  real_T mot_omegaC_rad_s[4];          /* Variable: mot_omegaC_rad_s
                                        * Referenced by:
                                        *   '<S10>/Dauermoment Motor'
                                        *   '<S22>/Dauermoment Motor'
                                        *   '<S34>/Dauermoment Motor'
                                        *   '<S46>/Dauermoment Motor'
                                        */
  real_T mot_omegaMaxReg_rad_s[9];     /* Variable: mot_omegaMaxReg_rad_s
                                        * Referenced by:
                                        *   '<S10>/1-D Lookup Table'
                                        *   '<S22>/1-D Lookup Table'
                                        *   '<S34>/1-D Lookup Table'
                                        *   '<S46>/1-D Lookup Table'
                                        */
  real_T mot_omegaPeak_rad_s[6];       /* Variable: mot_omegaPeak_rad_s
                                        * Referenced by:
                                        *   '<S10>/Spitzenmoment Motor'
                                        *   '<S22>/Spitzenmoment Motor'
                                        *   '<S34>/Spitzenmoment Motor'
                                        *   '<S46>/Spitzenmoment Motor'
                                        */
  real_T mot_omega_rad_s[15];          /* Variable: mot_omega_rad_s
                                        * Referenced by:
                                        *   '<S7>/Wirkungsgradkennfeld'
                                        *   '<S19>/Wirkungsgradkennfeld'
                                        *   '<S31>/Wirkungsgradkennfeld'
                                        *   '<S43>/Wirkungsgradkennfeld'
                                        */
  real_T mot_weight_T[4];              /* Variable: mot_weight_T
                                        * Referenced by:
                                        *   '<S10>/Spitzenmomentberechnung Motor'
                                        *   '<S22>/Spitzenmomentberechnung Motor'
                                        *   '<S34>/Spitzenmomentberechnung Motor'
                                        *   '<S46>/Spitzenmomentberechnung Motor'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S13>/Constant'
                                       */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S25>/Constant'
                                     */
  real_T CompareToConstant_const_d; /* Mask Parameter: CompareToConstant_const_d
                                     * Referenced by: '<S37>/Constant'
                                     */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S49>/Constant'
                                     */
  real_T NumerischeStabilitt_Value;    /* Expression: 0.00001
                                        * Referenced by: '<S9>/Numerische Stabilität'
                                        */
  real_T NumerischeStabilitt_Value_i;  /* Expression: 0.00001
                                        * Referenced by: '<S21>/Numerische Stabilität'
                                        */
  real_T NumerischeStabilitt_Value_io; /* Expression: 0.00001
                                        * Referenced by: '<S33>/Numerische Stabilität'
                                        */
  real_T NumerischeStabilitt_Value_k;  /* Expression: 0.00001
                                        * Referenced by: '<S45>/Numerische Stabilität'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S9>/Integrator1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T Memory10_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S14>/Memory10'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S14>/Memory7'
                                        */
  real_T Memory9_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S14>/Memory9'
                                        */
  real_T Memory8_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S14>/Memory8'
                                        */
  real_T Memory11_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S14>/Memory11'
                                        */
  real_T Constant4_Value;              /* Expression: 0.8
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 0.1
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  real_T Constant2_Value;              /* Expression: 0.1
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant_Value_e4;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S21>/Integrator'
                                        */
  real_T Integrator1_IC_h;             /* Expression: 0
                                        * Referenced by: '<S21>/Integrator1'
                                        */
  real_T TransferFcn_A_l;              /* Computed Parameter: TransferFcn_A_l
                                        * Referenced by: '<S21>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_c;              /* Computed Parameter: TransferFcn_C_c
                                        * Referenced by: '<S21>/Transfer Fcn'
                                        */
  real_T Memory_InitialCondition_b;    /* Expression: 0
                                        * Referenced by: '<S21>/Memory'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S21>/Switch'
                                        */
  real_T Memory10_InitialCondition_p;  /* Expression: 0
                                        * Referenced by: '<S26>/Memory10'
                                        */
  real_T Memory7_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S26>/Memory7'
                                        */
  real_T Memory9_InitialCondition_m;   /* Expression: 0
                                        * Referenced by: '<S26>/Memory9'
                                        */
  real_T Memory8_InitialCondition_h;   /* Expression: 0
                                        * Referenced by: '<S26>/Memory8'
                                        */
  real_T Memory11_InitialCondition_o;  /* Expression: 0
                                        * Referenced by: '<S26>/Memory11'
                                        */
  real_T Constant4_Value_c;            /* Expression: 0.8
                                        * Referenced by: '<S22>/Constant4'
                                        */
  real_T Constant3_Value_e;            /* Expression: 0.1
                                        * Referenced by: '<S22>/Constant3'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 2
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Memory_InitialCondition_l;    /* Expression: 0
                                        * Referenced by: '<S23>/Memory'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0.1
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant_Value_ey;            /* Expression: 2
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S33>/Integrator'
                                        */
  real_T Integrator1_IC_hc;            /* Expression: 0
                                        * Referenced by: '<S33>/Integrator1'
                                        */
  real_T TransferFcn_A_m;              /* Computed Parameter: TransferFcn_A_m
                                        * Referenced by: '<S33>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_d;              /* Computed Parameter: TransferFcn_C_d
                                        * Referenced by: '<S33>/Transfer Fcn'
                                        */
  real_T Memory_InitialCondition_d;    /* Expression: 0
                                        * Referenced by: '<S33>/Memory'
                                        */
  real_T Switch_Threshold_js;          /* Expression: 0
                                        * Referenced by: '<S33>/Switch'
                                        */
  real_T Memory10_InitialCondition_k;  /* Expression: 0
                                        * Referenced by: '<S38>/Memory10'
                                        */
  real_T Memory7_InitialCondition_b;   /* Expression: 0
                                        * Referenced by: '<S38>/Memory7'
                                        */
  real_T Memory9_InitialCondition_a;   /* Expression: 0
                                        * Referenced by: '<S38>/Memory9'
                                        */
  real_T Memory8_InitialCondition_hu;  /* Expression: 0
                                        * Referenced by: '<S38>/Memory8'
                                        */
  real_T Memory11_InitialCondition_ox; /* Expression: 0
                                        * Referenced by: '<S38>/Memory11'
                                        */
  real_T Constant4_Value_ct;           /* Expression: 0.8
                                        * Referenced by: '<S34>/Constant4'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0.1
                                        * Referenced by: '<S34>/Constant3'
                                        */
  real_T Constant_Value_ea;            /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 2
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S35>/Memory'
                                        */
  real_T Constant2_Value_kc;           /* Expression: 0.1
                                        * Referenced by: '<S34>/Constant2'
                                        */
  real_T Constant_Value_fi;            /* Expression: 3
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S45>/Integrator'
                                        */
  real_T Integrator1_IC_a;             /* Expression: 0
                                        * Referenced by: '<S45>/Integrator1'
                                        */
  real_T TransferFcn_A_h;              /* Computed Parameter: TransferFcn_A_h
                                        * Referenced by: '<S45>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_cc;             /* Computed Parameter: TransferFcn_C_cc
                                        * Referenced by: '<S45>/Transfer Fcn'
                                        */
  real_T Memory_InitialCondition_m;    /* Expression: 0
                                        * Referenced by: '<S45>/Memory'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S45>/Switch'
                                        */
  real_T Memory10_InitialCondition_m;  /* Expression: 0
                                        * Referenced by: '<S50>/Memory10'
                                        */
  real_T Memory7_InitialCondition_n;   /* Expression: 0
                                        * Referenced by: '<S50>/Memory7'
                                        */
  real_T Memory9_InitialCondition_n;   /* Expression: 0
                                        * Referenced by: '<S50>/Memory9'
                                        */
  real_T Memory8_InitialCondition_e;   /* Expression: 0
                                        * Referenced by: '<S50>/Memory8'
                                        */
  real_T Memory11_InitialCondition_n;  /* Expression: 0
                                        * Referenced by: '<S50>/Memory11'
                                        */
  real_T Constant4_Value_e;            /* Expression: 0.8
                                        * Referenced by: '<S46>/Constant4'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0.1
                                        * Referenced by: '<S46>/Constant3'
                                        */
  real_T Constant_Value_fd;            /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 2
                                        * Referenced by: '<S47>/Gain'
                                        */
  real_T Memory_InitialCondition_o;    /* Expression: 0
                                        * Referenced by: '<S47>/Memory'
                                        */
  real_T Constant2_Value_o;            /* Expression: 0.1
                                        * Referenced by: '<S46>/Constant2'
                                        */
  real_T Status_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/Status'
                                        */
  real_T ISGOutLoad_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/ISGOut.Load'
                                        */
  real_T ISGOutTrqMot_max_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ISGOut.TrqMot_max'
                                        */
  real_T ISGOutTrqGen_max_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ISGOut.TrqGen_max'
                                        */
  uint32_T Wirkungsgradkennfeld_maxIndex[2];
                            /* Computed Parameter: Wirkungsgradkennfeld_maxIndex
                             * Referenced by: '<S7>/Wirkungsgradkennfeld'
                             */
  uint32_T Wirkungsgradkennfeld_maxIndex_k[2];
                          /* Computed Parameter: Wirkungsgradkennfeld_maxIndex_k
                           * Referenced by: '<S19>/Wirkungsgradkennfeld'
                           */
  uint32_T Wirkungsgradkennfeld_maxIndex_c[2];
                          /* Computed Parameter: Wirkungsgradkennfeld_maxIndex_c
                           * Referenced by: '<S31>/Wirkungsgradkennfeld'
                           */
  uint32_T Wirkungsgradkennfeld_maxIndex_j[2];
                          /* Computed Parameter: Wirkungsgradkennfeld_maxIndex_j
                           * Referenced by: '<S43>/Wirkungsgradkennfeld'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_UNICARPTMotorCU_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_UNICARPTMotorCU_T *blockIO;
  PrevZCX_UNICARPTMotorCU_T *prevZCSigState;
  X_UNICARPTMotorCU_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  ExtU_UNICARPTMotorCU_T *inputs;
  ExtY_UNICARPTMotorCU_T *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][24];
  ODE1_IntgData intgData;
  DW_UNICARPTMotorCU_T *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[134];
    int32_T* vardimsAddress[134];
    RTWLoggingFcnPtr loggingPtrs[134];
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
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_UNICARPTMotorCU_T UNICARPTMotorCU_P;

/* External data declarations for dependent source files */
extern const cmPTMotorCUOut UNICARPTMotorCU_rtZcmPTMotorCUOut;/* cmPTMotorCUOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern P_UNICARPTMotorCU_T UNICARPTMotorCU_P;/* parameters */

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_UNICARPTMotorCU_T *UNICARPTMotorCU(struct tInfos *inf);
extern void UNICARPTMotorCU_initialize(RT_MODEL_UNICARPTMotorCU_T *const
  UNICARPTMotorCU_M);
extern void UNICARPTMotorCU_step(RT_MODEL_UNICARPTMotorCU_T *const
  UNICARPTMotorCU_M);
extern void UNICARPTMotorCU_terminate(RT_MODEL_UNICARPTMotorCU_T
  * UNICARPTMotorCU_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTMotorCU_GetCAPIStaticMap(void);

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
 * '<Root>' : 'UNICARPTMotorCU'
 * '<S1>'   : 'UNICARPTMotorCU/IF_Out_Selector'
 * '<S2>'   : 'UNICARPTMotorCU/MCU0'
 * '<S3>'   : 'UNICARPTMotorCU/MCU1'
 * '<S4>'   : 'UNICARPTMotorCU/MCU2'
 * '<S5>'   : 'UNICARPTMotorCU/MCU3'
 * '<S6>'   : 'UNICARPTMotorCU/MCU0/Generic MCU Model'
 * '<S7>'   : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb'
 * '<S8>'   : 'UNICARPTMotorCU/MCU0/Generic MCU Model/BCU'
 * '<S9>'   : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Battery'
 * '<S10>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Momentenbegrenzung'
 * '<S11>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Temperaturmodell Antrieb'
 * '<S12>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Calc alpha_An'
 * '<S13>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant'
 * '<S14>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max'
 * '<S15>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Temperaturmodell'
 * '<S16>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/MATLAB Function'
 * '<S17>'  : 'UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/Resettable Subsystem'
 * '<S18>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model'
 * '<S19>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb'
 * '<S20>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/BCU'
 * '<S21>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Battery'
 * '<S22>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Momentenbegrenzung'
 * '<S23>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Temperaturmodell Antrieb'
 * '<S24>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Calc alpha_An'
 * '<S25>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant'
 * '<S26>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max'
 * '<S27>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Temperaturmodell'
 * '<S28>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/MATLAB Function'
 * '<S29>'  : 'UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/Resettable Subsystem'
 * '<S30>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model'
 * '<S31>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb'
 * '<S32>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/BCU'
 * '<S33>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Battery'
 * '<S34>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Momentenbegrenzung'
 * '<S35>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Temperaturmodell Antrieb'
 * '<S36>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Calc alpha_An'
 * '<S37>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant'
 * '<S38>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max'
 * '<S39>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Temperaturmodell'
 * '<S40>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/MATLAB Function'
 * '<S41>'  : 'UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/Resettable Subsystem'
 * '<S42>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model'
 * '<S43>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb'
 * '<S44>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/BCU'
 * '<S45>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Battery'
 * '<S46>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Momentenbegrenzung'
 * '<S47>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Temperaturmodell Antrieb'
 * '<S48>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Calc alpha_An'
 * '<S49>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant'
 * '<S50>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max'
 * '<S51>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Temperaturmodell'
 * '<S52>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/MATLAB Function'
 * '<S53>'  : 'UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/Resettable Subsystem'
 */
#endif                                 /* RTW_HEADER_UNICARPTMotorCU_h_ */
