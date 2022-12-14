/*
 * UNICARPTMotorCU_private.h
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

#ifndef RTW_HEADER_UNICARPTMotorCU_private_h_
#define RTW_HEADER_UNICARPTMotorCU_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "UNICARPTMotorCU.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

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

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
void UNICARPTMotorCU_Calcalpha_An(real_T rtu_v_un, real_T rtu_Konst, real_T
  rtu_Konst_c, real_T rtu_Konst_d, real_T rtu_Konst_g, real_T rtu_T_An, real_T
  rtu_CM_Temp, B_Calcalpha_An_UNICARPTMotorCU_T *localB);
void UNICARPTMotorCU_MATLABFunction(real_T rtu_t_reset, real_T rtu_I_ist, real_T
  rtu_t, real_T rtu_delta_t, real_T rtu_Konst, real_T rtu_Konst_g, real_T
  rtu_Konst_b, real_T rtu_t_mem1, real_T rtu_t_mem2, real_T rtu_m1,
  B_MATLABFunction_UNICARPTMotorCU_T *localB);
void UNICARPTMotorCU_ResettableSubsystem_Init
  (DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW, P_UNICARPTMotorCU_T
   *UNICARPTMotorCU_P);
void UNICARPTMotorCU_ResettableSubsystem_Reset
  (DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW, P_UNICARPTMotorCU_T
   *UNICARPTMotorCU_P);
void UNICARPTMotorCU_ResettableSubsystem_Update(RT_MODEL_UNICARPTMotorCU_T *
  const UNICARPTMotorCU_M, B_ResettableSubsystem_UNICARPTMotorCU_T *localB,
  DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW);
void UNICARPTMotorCU_ResettableSubsystem(RT_MODEL_UNICARPTMotorCU_T * const
  UNICARPTMotorCU_M, real_T rtu_t_reset, real_T rtu_Reset,
  B_ResettableSubsystem_UNICARPTMotorCU_T *localB,
  DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW, P_UNICARPTMotorCU_T
  *UNICARPTMotorCU_P, ZCE_ResettableSubsystem_UNICARPTMotorCU_T *localZCE);

/* private model entry point functions */
extern void UNICARPTMotorCU_derivatives(RT_MODEL_UNICARPTMotorCU_T *const
  UNICARPTMotorCU_M);

#endif                               /* RTW_HEADER_UNICARPTMotorCU_private_h_ */
