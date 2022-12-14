/*
 * UNICARBrake.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARBrake".
 *
 * Model version              : 1.55
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:41:24 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UNICARBrake_h_
#define RTW_HEADER_UNICARBrake_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef UNICARBrake_COMMON_INCLUDES_
# define UNICARBrake_COMMON_INCLUDES_
#include <stdlib.h>
#include <Global.h>
#include <TextUtils.h>
#include <DataDict.h>
#include <DirectVarAccess.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* UNICARBrake_COMMON_INCLUDES_ */

#include "UNICARBrake_types.h"

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

#define UNICARBrake_M_TYPE             RT_MODEL_UNICARBrake_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.001
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ReadCMDict1;                  /* '<S1>/Read CM Dict1' */
  real_T ReadCMDict;                   /* '<S1>/Read CM Dict' */
  real_T Product;                      /* '<S11>/Product' */
  real_T Product2;                     /* '<S11>/Product2' */
  real_T Add;                          /* '<S8>/Add' */
  real_T Memory;                       /* '<S12>/Memory' */
  real_T ReadCMDict2;                  /* '<S1>/Read CM Dict2' */
  real_T Abs;                          /* '<S9>/Abs' */
  real_T ReadCMDict3;                  /* '<S1>/Read CM Dict3' */
  real_T ReadCMDict4;                  /* '<S1>/Read CM Dict4' */
  real_T Memory_i;                     /* '<S9>/Memory' */
  real_T f_brake;                      /* '<S9>/f_brake' */
  real_T Clock;                        /* '<S12>/Clock' */
  real_T Memory1;                      /* '<S12>/Memory1' */
  real_T T_Filter;                     /* '<S9>/T_Filter' */
  real_T Sum2;                         /* '<S12>/Sum2' */
  real_T Switch1;                      /* '<S8>/Switch1' */
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T Add_e;                        /* '<S1>/Add' */
  real_T Switch;                       /* '<S10>/Switch' */
  real_T TransportDelay;               /* '<S11>/Transport Delay' */
  real_T ReadCMDict1_o;                /* '<S2>/Read CM Dict1' */
  real_T ReadCMDict_b;                 /* '<S2>/Read CM Dict' */
  real_T Product_g;                    /* '<S21>/Product' */
  real_T Product2_m;                   /* '<S21>/Product2' */
  real_T Add_b;                        /* '<S18>/Add' */
  real_T Memory_a;                     /* '<S22>/Memory' */
  real_T ReadCMDict2_l;                /* '<S2>/Read CM Dict2' */
  real_T Abs_c;                        /* '<S19>/Abs' */
  real_T ReadCMDict3_j;                /* '<S2>/Read CM Dict3' */
  real_T ReadCMDict4_i;                /* '<S2>/Read CM Dict4' */
  real_T Memory_b;                     /* '<S19>/Memory' */
  real_T f_brake_h;                    /* '<S19>/f_brake' */
  real_T Clock_i;                      /* '<S22>/Clock' */
  real_T Memory1_a;                    /* '<S22>/Memory1' */
  real_T T_Filter_h;                   /* '<S19>/T_Filter' */
  real_T Sum2_o;                       /* '<S22>/Sum2' */
  real_T Switch1_h;                    /* '<S18>/Switch1' */
  real_T DataTypeConversion_c;         /* '<S2>/Data Type Conversion' */
  real_T Add_p;                        /* '<S2>/Add' */
  real_T Switch1_b;                    /* '<S20>/Switch1' */
  real_T TransportDelay_n;             /* '<S21>/Transport Delay' */
  real_T ReadCMDict1_g;                /* '<S3>/Read CM Dict1' */
  real_T ReadCMDict_l;                 /* '<S3>/Read CM Dict' */
  real_T Product_p;                    /* '<S31>/Product' */
  real_T Product2_i;                   /* '<S31>/Product2' */
  real_T Add_n;                        /* '<S28>/Add' */
  real_T Memory_h;                     /* '<S32>/Memory' */
  real_T ReadCMDict2_f;                /* '<S3>/Read CM Dict2' */
  real_T Abs_h;                        /* '<S29>/Abs' */
  real_T ReadCMDict3_n;                /* '<S3>/Read CM Dict3' */
  real_T ReadCMDict4_g;                /* '<S3>/Read CM Dict4' */
  real_T Memory_p;                     /* '<S29>/Memory' */
  real_T f_brake_f;                    /* '<S29>/f_brake' */
  real_T Clock_m;                      /* '<S32>/Clock' */
  real_T Memory1_j;                    /* '<S32>/Memory1' */
  real_T T_Filter_g;                   /* '<S29>/T_Filter' */
  real_T Sum2_l;                       /* '<S32>/Sum2' */
  real_T Switch1_n;                    /* '<S28>/Switch1' */
  real_T DataTypeConversion_n;         /* '<S3>/Data Type Conversion' */
  real_T Add_a;                        /* '<S3>/Add' */
  real_T Switch1_e;                    /* '<S30>/Switch1' */
  real_T TransportDelay_m;             /* '<S31>/Transport Delay' */
  real_T ReadCMDict1_b;                /* '<S4>/Read CM Dict1' */
  real_T ReadCMDict_c;                 /* '<S4>/Read CM Dict' */
  real_T Product_e;                    /* '<S41>/Product' */
  real_T Product2_g;                   /* '<S41>/Product2' */
  real_T Add_au;                       /* '<S38>/Add' */
  real_T Memory_m;                     /* '<S42>/Memory' */
  real_T ReadCMDict2_g;                /* '<S4>/Read CM Dict2' */
  real_T Abs_j;                        /* '<S39>/Abs' */
  real_T ReadCMDict3_f;                /* '<S4>/Read CM Dict3' */
  real_T ReadCMDict4_p;                /* '<S4>/Read CM Dict4' */
  real_T Memory_f;                     /* '<S39>/Memory' */
  real_T f_brake_m;                    /* '<S39>/f_brake' */
  real_T Clock_e;                      /* '<S42>/Clock' */
  real_T Memory1_p;                    /* '<S42>/Memory1' */
  real_T T_Filter_hd;                  /* '<S39>/T_Filter' */
  real_T Sum2_c;                       /* '<S42>/Sum2' */
  real_T Switch1_f;                    /* '<S38>/Switch1' */
  real_T DataTypeConversion_c0;        /* '<S4>/Data Type Conversion' */
  real_T Add_l;                        /* '<S4>/Add' */
  real_T Switch1_j;                    /* '<S40>/Switch1' */
  real_T TransportDelay_f;             /* '<S41>/Transport Delay' */
  real_T ReadCMDict_f;                 /* '<S6>/Read CM Dict' */
} B_UNICARBrake_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S12>/Memory' */
  real_T TimeStampA;                   /* '<S9>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S9>/Derivative' */
  real_T TimeStampB;                   /* '<S9>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S9>/Derivative' */
  real_T Memory_PreviousInput_f;       /* '<S9>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S12>/Memory1' */
  real_T Memory_PreviousInput_o;       /* '<S22>/Memory' */
  real_T TimeStampA_j;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeA_i;               /* '<S19>/Derivative' */
  real_T TimeStampB_l;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeB_n;               /* '<S19>/Derivative' */
  real_T Memory_PreviousInput_k;       /* '<S19>/Memory' */
  real_T Memory1_PreviousInput_p;      /* '<S22>/Memory1' */
  real_T Memory_PreviousInput_c;       /* '<S32>/Memory' */
  real_T TimeStampA_m;                 /* '<S29>/Derivative' */
  real_T LastUAtTimeA_d;               /* '<S29>/Derivative' */
  real_T TimeStampB_a;                 /* '<S29>/Derivative' */
  real_T LastUAtTimeB_e;               /* '<S29>/Derivative' */
  real_T Memory_PreviousInput_p;       /* '<S29>/Memory' */
  real_T Memory1_PreviousInput_a;      /* '<S32>/Memory1' */
  real_T Memory_PreviousInput_b;       /* '<S42>/Memory' */
  real_T TimeStampA_l;                 /* '<S39>/Derivative' */
  real_T LastUAtTimeA_d1;              /* '<S39>/Derivative' */
  real_T TimeStampB_l3;                /* '<S39>/Derivative' */
  real_T LastUAtTimeB_f;               /* '<S39>/Derivative' */
  real_T Memory_PreviousInput_h;       /* '<S39>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S42>/Memory1' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK;              /* '<S11>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_g;            /* '<S21>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_i;            /* '<S31>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_c;            /* '<S41>/Transport Delay' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK;                 /* '<S1>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK;                  /* '<S1>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK;                 /* '<S1>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK;                 /* '<S1>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict3_PWORK;                 /* '<S1>/Read CM Dict3' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK;                 /* '<S1>/Read CM Dict4' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK;                /* '<S1>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK;                /* '<S1>/Write CM Dict2' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S11>/Transport Delay' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_m;               /* '<S2>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_a;                /* '<S2>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_b;               /* '<S2>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK_a;               /* '<S2>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict3_PWORK_j;               /* '<S2>/Read CM Dict3' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_c;               /* '<S2>/Read CM Dict4' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK_l;              /* '<S2>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK_b;              /* '<S2>/Write CM Dict2' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_j;            /* '<S21>/Transport Delay' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_c;               /* '<S3>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_e;                /* '<S3>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_l;               /* '<S3>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK_l;               /* '<S3>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict3_PWORK_h;               /* '<S3>/Read CM Dict3' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_n;               /* '<S3>/Read CM Dict4' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK_a;              /* '<S3>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK_e;              /* '<S3>/Write CM Dict2' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_o;            /* '<S31>/Transport Delay' */

  struct {
    void *Entry;
  } ReadCMDict1_PWORK_f;               /* '<S4>/Read CM Dict1' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_b;                /* '<S4>/Read CM Dict' */

  struct {
    void *Entry;
  } WriteCMDict_PWORK_e;               /* '<S4>/Write CM Dict' */

  struct {
    void *Entry;
  } ReadCMDict2_PWORK_ay;              /* '<S4>/Read CM Dict2' */

  struct {
    void *Entry;
  } ReadCMDict3_PWORK_f;               /* '<S4>/Read CM Dict3' */

  struct {
    void *Entry;
  } ReadCMDict4_PWORK_d;               /* '<S4>/Read CM Dict4' */

  struct {
    void *Entry;
  } WriteCMDict1_PWORK_n;              /* '<S4>/Write CM Dict1' */

  struct {
    void *Entry;
  } WriteCMDict2_PWORK_l;              /* '<S4>/Write CM Dict2' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_c;            /* '<S41>/Transport Delay' */

  struct {
    void *Entry;
  } ReadCMDict_PWORK_p;                /* '<S6>/Read CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK;                 /* '<S1>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK;                  /* '<S1>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK;                 /* '<S1>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK;                 /* '<S1>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict3_IWORK;                 /* '<S1>/Read CM Dict3' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK;                 /* '<S1>/Read CM Dict4' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK;                /* '<S1>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK;                /* '<S1>/Write CM Dict2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S11>/Transport Delay' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_e;               /* '<S2>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_k;                /* '<S2>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK_n;               /* '<S2>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK_i;               /* '<S2>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict3_IWORK_m;               /* '<S2>/Read CM Dict3' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_b;               /* '<S2>/Read CM Dict4' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK_p;              /* '<S2>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK_o;              /* '<S2>/Write CM Dict2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_e;            /* '<S21>/Transport Delay' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_i;               /* '<S3>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_f;                /* '<S3>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK_g;               /* '<S3>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK_n;               /* '<S3>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict3_IWORK_g;               /* '<S3>/Read CM Dict3' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_e;               /* '<S3>/Read CM Dict4' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK_l;              /* '<S3>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK_f;              /* '<S3>/Write CM Dict2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_m;            /* '<S31>/Transport Delay' */

  struct {
    int_T Checked;
  } ReadCMDict1_IWORK_g;               /* '<S4>/Read CM Dict1' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_fa;               /* '<S4>/Read CM Dict' */

  struct {
    int_T Checked;
  } WriteCMDict_IWORK_f;               /* '<S4>/Write CM Dict' */

  struct {
    int_T Checked;
  } ReadCMDict2_IWORK_l;               /* '<S4>/Read CM Dict2' */

  struct {
    int_T Checked;
  } ReadCMDict3_IWORK_o;               /* '<S4>/Read CM Dict3' */

  struct {
    int_T Checked;
  } ReadCMDict4_IWORK_c;               /* '<S4>/Read CM Dict4' */

  struct {
    int_T Checked;
  } WriteCMDict1_IWORK_f;              /* '<S4>/Write CM Dict1' */

  struct {
    int_T Checked;
  } WriteCMDict2_IWORK_k;              /* '<S4>/Write CM Dict2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_i;            /* '<S41>/Transport Delay' */

  struct {
    int_T Checked;
  } ReadCMDict_IWORK_n;                /* '<S6>/Read CM Dict' */

  int8_T If2_ActiveSubsystem;          /* '<S9>/If2' */
  int8_T If2_ActiveSubsystem_i;        /* '<S19>/If2' */
  int8_T If2_ActiveSubsystem_h;        /* '<S29>/If2' */
  int8_T If2_ActiveSubsystem_e;        /* '<S39>/If2' */
} DW_UNICARBrake_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ABSon_CSTATE;                 /* '<S11>/ABS on' */
  real_T ABSoff_CSTATE[2];             /* '<S11>/ABS off' */
  real_T ABSon_CSTATE_d;               /* '<S21>/ABS on' */
  real_T ABSoff_CSTATE_o[2];           /* '<S21>/ABS off' */
  real_T ABSon_CSTATE_l;               /* '<S31>/ABS on' */
  real_T ABSoff_CSTATE_c[2];           /* '<S31>/ABS off' */
  real_T ABSon_CSTATE_o;               /* '<S41>/ABS on' */
  real_T ABSoff_CSTATE_p[2];           /* '<S41>/ABS off' */
} X_UNICARBrake_T;

/* State derivatives (default storage) */
typedef struct {
  real_T ABSon_CSTATE;                 /* '<S11>/ABS on' */
  real_T ABSoff_CSTATE[2];             /* '<S11>/ABS off' */
  real_T ABSon_CSTATE_d;               /* '<S21>/ABS on' */
  real_T ABSoff_CSTATE_o[2];           /* '<S21>/ABS off' */
  real_T ABSon_CSTATE_l;               /* '<S31>/ABS on' */
  real_T ABSoff_CSTATE_c[2];           /* '<S31>/ABS off' */
  real_T ABSon_CSTATE_o;               /* '<S41>/ABS on' */
  real_T ABSoff_CSTATE_p[2];           /* '<S41>/ABS off' */
} XDot_UNICARBrake_T;

/* State disabled  */
typedef struct {
  boolean_T ABSon_CSTATE;              /* '<S11>/ABS on' */
  boolean_T ABSoff_CSTATE[2];          /* '<S11>/ABS off' */
  boolean_T ABSon_CSTATE_d;            /* '<S21>/ABS on' */
  boolean_T ABSoff_CSTATE_o[2];        /* '<S21>/ABS off' */
  boolean_T ABSon_CSTATE_l;            /* '<S31>/ABS on' */
  boolean_T ABSoff_CSTATE_c[2];        /* '<S31>/ABS off' */
  boolean_T ABSon_CSTATE_o;            /* '<S41>/ABS on' */
  boolean_T ABSoff_CSTATE_p[2];        /* '<S41>/ABS off' */
} XDis_UNICARBrake_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmBrakeIn FromCM;                    /* '<Root>/FromCM' */
  cmBrakeCfgIn CfgInFromCM;            /* '<Root>/CfgInFromCM' */
} ExtU_UNICARBrake_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmBrakeOut ToCM;                     /* '<Root>/ToCM' */
} ExtY_UNICARBrake_T;

/* Parameters for system: '<S9>/reduce pressure' */
struct P_reducepressure_UNICARBrake_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant1'
                                        */
};

/* Parameters for system: '<S9>/free pressure' */
struct P_freepressure_UNICARBrake_T_ {
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S13>/Constant1'
                                        */
};

/* Parameters for system: '<S9>/keep pressure' */
struct P_keeppressure_UNICARBrake_T_ {
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S14>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_UNICARBrake_T_ {
  real_T brk_ABS;                      /* Variable: brk_ABS
                                        * Referenced by:
                                        *   '<S8>/ABS_on_off'
                                        *   '<S18>/ABS_on_off'
                                        *   '<S28>/ABS_on_off'
                                        *   '<S38>/ABS_on_off'
                                        */
  real_T brk_Kacc;                     /* Variable: brk_Kacc
                                        * Referenced by:
                                        *   '<S9>/Constant3'
                                        *   '<S19>/Constant3'
                                        *   '<S29>/Constant3'
                                        *   '<S39>/Constant3'
                                        */
  real_T brk_Kslip;                    /* Variable: brk_Kslip
                                        * Referenced by:
                                        *   '<S9>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S29>/Gain'
                                        *   '<S39>/Gain'
                                        */
  real_T brk_SKlow;                    /* Variable: brk_SKlow
                                        * Referenced by:
                                        *   '<S9>/Constant1'
                                        *   '<S19>/Constant1'
                                        *   '<S29>/Constant1'
                                        *   '<S39>/Constant1'
                                        */
  real_T brk_SKup;                     /* Variable: brk_SKup
                                        * Referenced by:
                                        *   '<S9>/Constant4'
                                        *   '<S19>/Constant4'
                                        *   '<S29>/Constant4'
                                        *   '<S39>/Constant4'
                                        */
  real_T brk_TKeep_1_s;                /* Variable: brk_TKeep_1_s
                                        * Referenced by:
                                        *   '<S14>/Constant2'
                                        *   '<S24>/Constant2'
                                        *   '<S34>/Constant2'
                                        *   '<S44>/Constant2'
                                        */
  real_T brk_TRai_1_s;                 /* Variable: brk_TRai_1_s
                                        * Referenced by:
                                        *   '<S13>/Constant2'
                                        *   '<S23>/Constant2'
                                        *   '<S33>/Constant2'
                                        *   '<S43>/Constant2'
                                        */
  real_T brk_TRed_1_s;                 /* Variable: brk_TRed_1_s
                                        * Referenced by:
                                        *   '<S15>/Constant2'
                                        *   '<S25>/Constant2'
                                        *   '<S35>/Constant2'
                                        *   '<S45>/Constant2'
                                        */
  real_T brk_area_m_2;                 /* Variable: brk_area_m_2
                                        * Referenced by:
                                        *   '<S11>/Constant'
                                        *   '<S21>/Constant'
                                        *   '<S31>/Constant'
                                        *   '<S41>/Constant'
                                        */
  real_T brk_dyn;                      /* Variable: brk_dyn
                                        * Referenced by:
                                        *   '<S11>/Constant4'
                                        *   '<S21>/Constant4'
                                        *   '<S31>/Constant4'
                                        *   '<S41>/Constant4'
                                        */
  real_T brk_i;                        /* Variable: brk_i
                                        * Referenced by:
                                        *   '<S1>/Gain'
                                        *   '<S2>/Gain'
                                        *   '<S3>/Gain'
                                        *   '<S4>/Gain'
                                        *   '<S10>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S30>/Gain'
                                        *   '<S40>/Gain'
                                        */
  real_T brk_mue;                      /* Variable: brk_mue
                                        * Referenced by:
                                        *   '<S11>/Constant2'
                                        *   '<S21>/Constant2'
                                        *   '<S31>/Constant2'
                                        *   '<S41>/Constant2'
                                        */
  real_T brk_pMax_pa;                  /* Variable: brk_pMax_pa
                                        * Referenced by:
                                        *   '<S11>/Constant3'
                                        *   '<S21>/Constant3'
                                        *   '<S31>/Constant3'
                                        *   '<S41>/Constant3'
                                        */
  real_T brk_parking_trq[4];           /* Variable: brk_parking_trq
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T brk_r_m;                      /* Variable: brk_r_m
                                        * Referenced by:
                                        *   '<S11>/Constant1'
                                        *   '<S21>/Constant1'
                                        *   '<S31>/Constant1'
                                        *   '<S41>/Constant1'
                                        */
  real_T brk_tDel_s;                   /* Variable: brk_tDel_s
                                        * Referenced by:
                                        *   '<S11>/Transport Delay'
                                        *   '<S21>/Transport Delay'
                                        *   '<S31>/Transport Delay'
                                        *   '<S41>/Transport Delay'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S17>/Constant'
                                     */
  real_T CompareToConstant_const_b; /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S27>/Constant'
                                     */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S37>/Constant'
                                     */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S11>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 1
                                        * Referenced by: '<S11>/Switch2'
                                        */
  real_T Switch1_Threshold_p;          /* Expression: 1
                                        * Referenced by: '<S21>/Switch1'
                                        */
  real_T Switch2_Threshold_a;          /* Expression: 1
                                        * Referenced by: '<S21>/Switch2'
                                        */
  real_T Switch1_Threshold_n;          /* Expression: 1
                                        * Referenced by: '<S31>/Switch1'
                                        */
  real_T Switch2_Threshold_c;          /* Expression: 1
                                        * Referenced by: '<S31>/Switch2'
                                        */
  real_T Switch1_Threshold_e;          /* Expression: 1
                                        * Referenced by: '<S41>/Switch1'
                                        */
  real_T Switch2_Threshold_m;          /* Expression: 1
                                        * Referenced by: '<S41>/Switch2'
                                        */
  real_T Constant_Value[4];            /* Expression: [0, 0, 0, 0]
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S16>/Constant4'
                                        */
  real_T ABSon_A;                      /* Computed Parameter: ABSon_A
                                        * Referenced by: '<S11>/ABS on'
                                        */
  real_T ABSon_C;                      /* Computed Parameter: ABSon_C
                                        * Referenced by: '<S11>/ABS on'
                                        */
  real_T ABSoff_A[2];                  /* Computed Parameter: ABSoff_A
                                        * Referenced by: '<S11>/ABS off'
                                        */
  real_T ABSoff_C[2];                  /* Computed Parameter: ABSoff_C
                                        * Referenced by: '<S11>/ABS off'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S12>/Memory'
                                        */
  real_T Memory_InitialCondition_b;    /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S12>/Memory1'
                                        */
  real_T Switch1_Threshold_nh;         /* Expression: 1
                                        * Referenced by: '<S8>/Switch1'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S11>/Transport Delay'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S26>/Constant4'
                                        */
  real_T ABSon_A_h;                    /* Computed Parameter: ABSon_A_h
                                        * Referenced by: '<S21>/ABS on'
                                        */
  real_T ABSon_C_g;                    /* Computed Parameter: ABSon_C_g
                                        * Referenced by: '<S21>/ABS on'
                                        */
  real_T ABSoff_A_l[2];                /* Computed Parameter: ABSoff_A_l
                                        * Referenced by: '<S21>/ABS off'
                                        */
  real_T ABSoff_C_b[2];                /* Computed Parameter: ABSoff_C_b
                                        * Referenced by: '<S21>/ABS off'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S26>/Switch'
                                        */
  real_T Memory_InitialCondition_e;    /* Expression: 0
                                        * Referenced by: '<S22>/Memory'
                                        */
  real_T Memory_InitialCondition_b2;   /* Expression: 0
                                        * Referenced by: '<S19>/Memory'
                                        */
  real_T Memory1_InitialCondition_k;   /* Expression: 0
                                        * Referenced by: '<S22>/Memory1'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 1
                                        * Referenced by: '<S18>/Switch1'
                                        */
  real_T TransportDelay_InitOutput_h;  /* Expression: 0
                                        * Referenced by: '<S21>/Transport Delay'
                                        */
  real_T Constant4_Value_g;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant4'
                                        */
  real_T ABSon_A_c;                    /* Computed Parameter: ABSon_A_c
                                        * Referenced by: '<S31>/ABS on'
                                        */
  real_T ABSon_C_e;                    /* Computed Parameter: ABSon_C_e
                                        * Referenced by: '<S31>/ABS on'
                                        */
  real_T ABSoff_A_j[2];                /* Computed Parameter: ABSoff_A_j
                                        * Referenced by: '<S31>/ABS off'
                                        */
  real_T ABSoff_C_n[2];                /* Computed Parameter: ABSoff_C_n
                                        * Referenced by: '<S31>/ABS off'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S36>/Switch'
                                        */
  real_T Memory_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S32>/Memory'
                                        */
  real_T Memory_InitialCondition_m;    /* Expression: 0
                                        * Referenced by: '<S29>/Memory'
                                        */
  real_T Memory1_InitialCondition_m;   /* Expression: 0
                                        * Referenced by: '<S32>/Memory1'
                                        */
  real_T Switch1_Threshold_ef;         /* Expression: 1
                                        * Referenced by: '<S28>/Switch1'
                                        */
  real_T TransportDelay_InitOutput_k;  /* Expression: 0
                                        * Referenced by: '<S31>/Transport Delay'
                                        */
  real_T Constant4_Value_k;            /* Expression: 0
                                        * Referenced by: '<S46>/Constant4'
                                        */
  real_T ABSon_A_m;                    /* Computed Parameter: ABSon_A_m
                                        * Referenced by: '<S41>/ABS on'
                                        */
  real_T ABSon_C_ed;                   /* Computed Parameter: ABSon_C_ed
                                        * Referenced by: '<S41>/ABS on'
                                        */
  real_T ABSoff_A_h[2];                /* Computed Parameter: ABSoff_A_h
                                        * Referenced by: '<S41>/ABS off'
                                        */
  real_T ABSoff_C_k[2];                /* Computed Parameter: ABSoff_C_k
                                        * Referenced by: '<S41>/ABS off'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S46>/Switch'
                                        */
  real_T Memory_InitialCondition_eq;   /* Expression: 0
                                        * Referenced by: '<S42>/Memory'
                                        */
  real_T Memory_InitialCondition_g;    /* Expression: 0
                                        * Referenced by: '<S39>/Memory'
                                        */
  real_T Memory1_InitialCondition_g;   /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T Switch1_Threshold_kn;         /* Expression: 1
                                        * Referenced by: '<S38>/Switch1'
                                        */
  real_T TransportDelay_InitOutput_l;  /* Expression: 0
                                        * Referenced by: '<S41>/Transport Delay'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Trq_DriveSrc_trgd0_Value;     /* Expression: 0
                                        * Referenced by: '<S5>/Trq_DriveSrc_trg.d0'
                                        */
  real_T Trq_DriveSrc_trgd1_Value;     /* Expression: 0
                                        * Referenced by: '<S5>/Trq_DriveSrc_trg.d1'
                                        */
  real_T Trq_DriveSrc_trgd2_Value;     /* Expression: 0
                                        * Referenced by: '<S5>/Trq_DriveSrc_trg.d2'
                                        */
  real_T Trq_DriveSrc_trgd3_Value;     /* Expression: 0
                                        * Referenced by: '<S5>/Trq_DriveSrc_trg.d3'
                                        */
  P_keeppressure_UNICARBrake_T keeppressure_j;/* '<S39>/keep pressure' */
  P_freepressure_UNICARBrake_T freepressure_i;/* '<S39>/free pressure' */
  P_reducepressure_UNICARBrake_T reducepressure_a;/* '<S39>/reduce pressure' */
  P_keeppressure_UNICARBrake_T keeppressure_o;/* '<S29>/keep pressure' */
  P_freepressure_UNICARBrake_T freepressure_c;/* '<S29>/free pressure' */
  P_reducepressure_UNICARBrake_T reducepressure_j;/* '<S29>/reduce pressure' */
  P_keeppressure_UNICARBrake_T keeppressure_k;/* '<S19>/keep pressure' */
  P_freepressure_UNICARBrake_T freepressure_j;/* '<S19>/free pressure' */
  P_reducepressure_UNICARBrake_T reducepressure_f;/* '<S19>/reduce pressure' */
  P_keeppressure_UNICARBrake_T keeppressure;/* '<S9>/keep pressure' */
  P_freepressure_UNICARBrake_T freepressure;/* '<S9>/free pressure' */
  P_reducepressure_UNICARBrake_T reducepressure;/* '<S9>/reduce pressure' */
};

/* Real-time Model Data Structure */
struct tag_RTM_UNICARBrake_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_UNICARBrake_T *blockIO;
  X_UNICARBrake_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  ExtU_UNICARBrake_T *inputs;
  ExtY_UNICARBrake_T *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][12];
  ODE1_IntgData intgData;
  DW_UNICARBrake_T *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[199];
    int32_T* vardimsAddress[199];
    RTWLoggingFcnPtr loggingPtrs[199];
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
extern P_UNICARBrake_T UNICARBrake_P;

/* External data declarations for dependent source files */
extern const cmBrakeOut UNICARBrake_rtZcmBrakeOut;/* cmBrakeOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern P_UNICARBrake_T UNICARBrake_P;  /* parameters */

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_UNICARBrake_T *UNICARBrake(struct tInfos *inf);
extern void UNICARBrake_initialize(RT_MODEL_UNICARBrake_T *const UNICARBrake_M);
extern void UNICARBrake_step(RT_MODEL_UNICARBrake_T *const UNICARBrake_M);
extern void UNICARBrake_terminate(RT_MODEL_UNICARBrake_T * UNICARBrake_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  UNICARBrake_GetCAPIStaticMap(void);

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
 * '<Root>' : 'UNICARBrake'
 * '<S1>'   : 'UNICARBrake/Brake FL'
 * '<S2>'   : 'UNICARBrake/Brake FR'
 * '<S3>'   : 'UNICARBrake/Brake RL'
 * '<S4>'   : 'UNICARBrake/Brake RR'
 * '<S5>'   : 'UNICARBrake/IF_Out_Selector'
 * '<S6>'   : 'UNICARBrake/ParkingBrake'
 * '<S7>'   : 'UNICARBrake/Brake FL/Compare To Constant'
 * '<S8>'   : 'UNICARBrake/Brake FL/Generic Brake Subsystem'
 * '<S9>'   : 'UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System'
 * '<S10>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/BrakeController'
 * '<S11>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake'
 * '<S12>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter'
 * '<S13>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/free pressure'
 * '<S14>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/keep pressure'
 * '<S15>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/reduce pressure'
 * '<S16>'  : 'UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Error Handling'
 * '<S17>'  : 'UNICARBrake/Brake FR/Compare To Constant'
 * '<S18>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem'
 * '<S19>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System'
 * '<S20>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/BrakeController'
 * '<S21>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake'
 * '<S22>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter'
 * '<S23>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/free pressure'
 * '<S24>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/keep pressure'
 * '<S25>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/reduce pressure'
 * '<S26>'  : 'UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Error Handling'
 * '<S27>'  : 'UNICARBrake/Brake RL/Compare To Constant'
 * '<S28>'  : 'UNICARBrake/Brake RL/Subsystem'
 * '<S29>'  : 'UNICARBrake/Brake RL/Subsystem/ABS System'
 * '<S30>'  : 'UNICARBrake/Brake RL/Subsystem/BrakeController'
 * '<S31>'  : 'UNICARBrake/Brake RL/Subsystem/Hydraulic Brake'
 * '<S32>'  : 'UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter'
 * '<S33>'  : 'UNICARBrake/Brake RL/Subsystem/ABS System/free pressure'
 * '<S34>'  : 'UNICARBrake/Brake RL/Subsystem/ABS System/keep pressure'
 * '<S35>'  : 'UNICARBrake/Brake RL/Subsystem/ABS System/reduce pressure'
 * '<S36>'  : 'UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Error Handling'
 * '<S37>'  : 'UNICARBrake/Brake RR/Compare To Constant'
 * '<S38>'  : 'UNICARBrake/Brake RR/Subsystem'
 * '<S39>'  : 'UNICARBrake/Brake RR/Subsystem/ABS System'
 * '<S40>'  : 'UNICARBrake/Brake RR/Subsystem/BrakeController'
 * '<S41>'  : 'UNICARBrake/Brake RR/Subsystem/Hydraulic Brake'
 * '<S42>'  : 'UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter'
 * '<S43>'  : 'UNICARBrake/Brake RR/Subsystem/ABS System/free pressure'
 * '<S44>'  : 'UNICARBrake/Brake RR/Subsystem/ABS System/keep pressure'
 * '<S45>'  : 'UNICARBrake/Brake RR/Subsystem/ABS System/reduce pressure'
 * '<S46>'  : 'UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Error Handling'
 */
#endif                                 /* RTW_HEADER_UNICARBrake_h_ */
