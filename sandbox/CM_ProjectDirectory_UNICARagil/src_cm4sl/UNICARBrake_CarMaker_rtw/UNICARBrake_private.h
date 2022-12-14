/*
 * UNICARBrake_private.h
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

#ifndef RTW_HEADER_UNICARBrake_private_h_
#define RTW_HEADER_UNICARBrake_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "UNICARBrake.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(0) { }
#endif

#define rt_FREE(ptr)                   if((ptr) != (NULL)) { free((void *)(ptr)); (ptr) = (NULL); }

real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;
void UNICARBrake_reducepressure(real_T *rty_Out1, real_T *rty_Out2,
  P_reducepressure_UNICARBrake_T *localP, P_UNICARBrake_T *UNICARBrake_P);
void UNICARBrake_freepressure(real_T *rty_Out1, real_T *rty_Out2,
  P_freepressure_UNICARBrake_T *localP, P_UNICARBrake_T *UNICARBrake_P);
void UNICARBrake_keeppressure(real_T *rty_Out1, real_T *rty_Out2,
  P_keeppressure_UNICARBrake_T *localP, P_UNICARBrake_T *UNICARBrake_P);

/* private model entry point functions */
extern void UNICARBrake_derivatives(RT_MODEL_UNICARBrake_T *const UNICARBrake_M);

#endif                                 /* RTW_HEADER_UNICARBrake_private_h_ */
