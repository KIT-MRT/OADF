/*
 * UNICARPTMotorCU.c
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

#include "UNICARPTMotorCU_capi.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "UNICARPTMotorCU.h"
#include "UNICARPTMotorCU_private.h"
#include "UNICARPTMotorCU_wrap.h"

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

const cmPTMotorCUOut UNICARPTMotorCU_rtZcmPTMotorCUOut = {
  0.0,                                 /* Status */

  {
    0.0,                               /* Load */
    0.0,                               /* TrqMot_max */
    0.0                                /* TrqGen_max */
  },                                   /* ISGOut */

  {
    {
      0.0,                             /* Load */
      0.0,                             /* TrqMot_max */
      0.0                              /* TrqGen_max */
    },                                 /* m0 */

    {
      0.0,                             /* Load */
      0.0,                             /* TrqMot_max */
      0.0                              /* TrqGen_max */
    },                                 /* m1 */

    {
      0.0,                             /* Load */
      0.0,                             /* TrqMot_max */
      0.0                              /* TrqGen_max */
    },                                 /* m2 */

    {
      0.0,                             /* Load */
      0.0,                             /* TrqMot_max */
      0.0                              /* TrqGen_max */
    }                                  /* m3 */
  }                                    /* MotorOut */
} ;                                    /* cmPTMotorCUOut ground */

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_UNICARPTMotorCU_T *const UNICARPTMotorCU_M)
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 24;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  UNICARPTMotorCU_derivatives(UNICARPTMotorCU_M);
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S11>/Calc alpha_An'
 *    '<S23>/Calc alpha_An'
 *    '<S35>/Calc alpha_An'
 *    '<S47>/Calc alpha_An'
 */
void UNICARPTMotorCU_Calcalpha_An(real_T rtu_v_un, real_T rtu_Konst, real_T
  rtu_Konst_c, real_T rtu_Konst_d, real_T rtu_Konst_g, real_T rtu_T_An, real_T
  rtu_CM_Temp, B_Calcalpha_An_UNICARPTMotorCU_T *localB)
{
  real_T Re;
  real_T Nu_m;

  /* SignalConversion generated from: '<S12>/ SFunction ' */
  Re = rtu_v_un * rtu_Konst / rtu_Konst_c;
  if (rtu_v_un > 0.1) {
    /* SignalConversion generated from: '<S12>/ SFunction ' */
    Nu_m = 0.664 * sqrt(Re) * rt_powd_snf(rtu_Konst_d, 0.33333333333333331);
    Re = 0.037 * rt_powd_snf(Re, 0.8) * rtu_Konst_d / (2.443 * rt_powd_snf(Re,
      -0.1) * (rt_powd_snf(rtu_Konst_d, 0.66666666666666663) - 1.0) + 1.0);
    Nu_m = sqrt(Nu_m * Nu_m + Re * Re) + 2.0;
  } else {
    /* SignalConversion generated from: '<S12>/ SFunction ' */
    Nu_m = rt_powd_snf(fabs(-(1.0 / rtu_CM_Temp) * (rtu_T_An - rtu_CM_Temp) *
      9.81 * rt_powd_snf(rtu_Konst, 3.0) / (rtu_Konst_c * rtu_Konst_c)) *
                       rtu_Konst_d * (rtu_Konst_d / (rtu_Konst_d + 0.846)), 0.25)
      * 0.56 + 2.0;
  }

  /* SignalConversion generated from: '<S12>/ SFunction ' */
  localB->alpha_An = Nu_m * rtu_Konst_g / rtu_Konst;
}

/*
 * Termination for atomic system:
 *    '<S11>/Calc alpha_An'
 *    '<S23>/Calc alpha_An'
 *    '<S35>/Calc alpha_An'
 *    '<S47>/Calc alpha_An'
 */
void UNICARPTMotorCU_Calcalpha_An_Term(void)
{
}

/*
 * Output and update for atomic system:
 *    '<S14>/MATLAB Function'
 *    '<S26>/MATLAB Function'
 *    '<S38>/MATLAB Function'
 *    '<S50>/MATLAB Function'
 */
void UNICARPTMotorCU_MATLABFunction(real_T rtu_t_reset, real_T rtu_I_ist, real_T
  rtu_t, real_T rtu_delta_t, real_T rtu_Konst, real_T rtu_Konst_g, real_T
  rtu_Konst_b, real_T rtu_t_mem1, real_T rtu_t_mem2, real_T rtu_m1,
  B_MATLABFunction_UNICARPTMotorCU_T *localB)
{
  int32_T trigger;
  real_T t_mem1;
  real_T t_mem2;
  real_T I_max2;
  real_T I_max1;
  int32_T trigger1;
  localB->t_mem1 = rtu_t_mem1;
  localB->t_mem2 = rtu_t_mem2;
  localB->m1 = rtu_m1;
  t_mem2 = localB->t_mem2;
  t_mem1 = localB->t_mem1;
  if (rtu_I_ist < -5.0) {
    t_mem1 = localB->t_mem1 + rtu_delta_t;
  } else {
    t_mem2 = localB->t_mem2 + rtu_delta_t;
  }

  /* SignalConversion generated from: '<S16>/ SFunction ' */
  if ((t_mem2 > rtu_Konst_b) && ((rtu_I_ist < -5.0) && (t_mem1 >= rtu_t_reset)))
  {
    t_mem2 = 0.0;
    trigger = 1;
    I_max2 = rtu_Konst;
  } else if ((t_mem2 > rtu_Konst_b) && ((rtu_I_ist < -5.0) && (t_mem1 <
               rtu_t_reset))) {
    trigger = 0;
    I_max2 = rtu_Konst_g;
  } else if ((t_mem2 > rtu_Konst_b) && (rtu_I_ist >= -5.0)) {
    trigger = 0;
    I_max2 = rtu_Konst_g;
  } else if (t_mem2 <= rtu_Konst_b) {
    I_max2 = rtu_Konst;
    trigger = 0;
  } else {
    I_max2 = rtu_Konst_g;
    trigger = 0;
  }

  if (t_mem1 >= rtu_t_reset) {
    t_mem1 = 0.0;

    /* SignalConversion generated from: '<S16>/ SFunction ' */
    I_max1 = rtu_Konst;
    trigger1 = 1;
  } else {
    /* SignalConversion generated from: '<S16>/ SFunction ' */
    I_max1 = rtu_Konst_g;
    trigger1 = 0;
  }

  trigger = (int32_T)fmax(trigger1, trigger);
  localB->I_max = fmin(I_max1, I_max2);
  if (rtu_t > 0.1) {
    I_max2 = fmax(trigger, localB->m1);
    if (I_max2 == 0.0) {
      /* SignalConversion generated from: '<S16>/ SFunction ' */
      localB->I_max = rtu_Konst_g;
    }
  } else {
    I_max2 = 0.0;

    /* SignalConversion generated from: '<S16>/ SFunction ' */
    localB->I_max = rtu_Konst_g;
  }

  localB->trigger = trigger;
  localB->t_mem1 = t_mem1;
  localB->t_mem2 = t_mem2;
  localB->m1 = I_max2;
}

/*
 * Termination for atomic system:
 *    '<S14>/MATLAB Function'
 *    '<S26>/MATLAB Function'
 *    '<S38>/MATLAB Function'
 *    '<S50>/MATLAB Function'
 */
void UNICARPTMotorCU_MATLABFunction_Term(void)
{
}

/*
 * System initialize for atomic system:
 *    '<S14>/Resettable Subsystem'
 *    '<S26>/Resettable Subsystem'
 *    '<S38>/Resettable Subsystem'
 *    '<S50>/Resettable Subsystem'
 */
void UNICARPTMotorCU_ResettableSubsystem_Init
  (DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW, P_UNICARPTMotorCU_T
   *UNICARPTMotorCU_P)
{
  /* InitializeConditions for Memory: '<S17>/Memory' */
  localDW->Memory_PreviousInput = UNICARPTMotorCU_P->bat_tIMax_s / 1.0E-9;
}

/*
 * System reset for atomic system:
 *    '<S14>/Resettable Subsystem'
 *    '<S26>/Resettable Subsystem'
 *    '<S38>/Resettable Subsystem'
 *    '<S50>/Resettable Subsystem'
 */
void UNICARPTMotorCU_ResettableSubsystem_Reset
  (DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW, P_UNICARPTMotorCU_T
   *UNICARPTMotorCU_P)
{
  /* InitializeConditions for Memory: '<S17>/Memory' */
  localDW->Memory_PreviousInput = UNICARPTMotorCU_P->bat_tIMax_s / 1.0E-9;
}

/*
 * Outputs for atomic system:
 *    '<S14>/Resettable Subsystem'
 *    '<S26>/Resettable Subsystem'
 *    '<S38>/Resettable Subsystem'
 *    '<S50>/Resettable Subsystem'
 */
void UNICARPTMotorCU_ResettableSubsystem(RT_MODEL_UNICARPTMotorCU_T * const
  UNICARPTMotorCU_M, real_T rtu_t_reset, real_T rtu_Reset,
  B_ResettableSubsystem_UNICARPTMotorCU_T *localB,
  DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW, P_UNICARPTMotorCU_T
  *UNICARPTMotorCU_P, ZCE_ResettableSubsystem_UNICARPTMotorCU_T *localZCE)
{
  /* Outputs for Resettable SubSystem: '<S14>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S17>/Reset'
   */
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
        &localZCE->ResettableSubsystem_Reset_ZCE,
        (rtu_Reset)) != NO_ZCEVENT)) {
    UNICARPTMotorCU_ResettableSubsystem_Reset(localDW, UNICARPTMotorCU_P);
  }

  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S17>/Memory' */
    localB->Memory = localDW->Memory_PreviousInput;
  }

  /* MinMax: '<S17>/Min' */
  localB->Min = fmin(rtu_t_reset, localB->Memory);

  /* End of Outputs for SubSystem: '<S14>/Resettable Subsystem' */
}

/*
 * Update for atomic system:
 *    '<S14>/Resettable Subsystem'
 *    '<S26>/Resettable Subsystem'
 *    '<S38>/Resettable Subsystem'
 *    '<S50>/Resettable Subsystem'
 */
void UNICARPTMotorCU_ResettableSubsystem_Update(RT_MODEL_UNICARPTMotorCU_T *
  const UNICARPTMotorCU_M, B_ResettableSubsystem_UNICARPTMotorCU_T *localB,
  DW_ResettableSubsystem_UNICARPTMotorCU_T *localDW)
{
  /* Update for Resettable SubSystem: '<S14>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S17>/Reset'
   */
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Update for Memory: '<S17>/Memory' */
    localDW->Memory_PreviousInput = localB->Min;
  }

  /* End of Update for SubSystem: '<S14>/Resettable Subsystem' */
}

/*
 * Termination for atomic system:
 *    '<S14>/Resettable Subsystem'
 *    '<S26>/Resettable Subsystem'
 *    '<S38>/Resettable Subsystem'
 *    '<S50>/Resettable Subsystem'
 */
void UNICARPTMotorCU_ResettableSubsystem_Term(void)
{
}

/* Model step function */
void UNICARPTMotorCU_step(RT_MODEL_UNICARPTMotorCU_T *const UNICARPTMotorCU_M)
{
  B_UNICARPTMotorCU_T *UNICARPTMotorCU_B = ((B_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->blockIO);
  DW_UNICARPTMotorCU_T *UNICARPTMotorCU_DW = ((DW_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->dwork);
  X_UNICARPTMotorCU_T *UNICARPTMotorCU_X = ((X_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->contStates);
  PrevZCX_UNICARPTMotorCU_T *UNICARPTMotorCU_PrevZCX =
    ((PrevZCX_UNICARPTMotorCU_T *) UNICARPTMotorCU_M->prevZCSigState);
  ExtU_UNICARPTMotorCU_T *UNICARPTMotorCU_U = (ExtU_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->inputs;
  ExtY_UNICARPTMotorCU_T *UNICARPTMotorCU_Y = (ExtY_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->outputs;

  /* local block i/o variables */
  real_T rtb_Add1;
  real_T rtb_Divide2;
  real_T rtb_Add1_m;
  real_T rtb_Divide2_e;
  real_T rtb_Add1_h;
  real_T rtb_Divide2_lm;
  real_T rtb_Add1_c;
  real_T rtb_Divide2_o;
  real_T rtb_Product_p;
  real_T rtb_U_S;
  real_T rtb_DataTypeConversion1;
  real_T rtb_R_SSOC;
  real_T rtb_Memory;
  boolean_T rtb_GreaterThan;
  real_T rtb_C_SSOC_tmp;
  int32_T IndexVector2_tmp;
  real_T Clock2_tmp;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* set solver stop time */
    if (!(UNICARPTMotorCU_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(UNICARPTMotorCU_M->solverInfo,
                            ((UNICARPTMotorCU_M->Timing.clockTickH0 + 1) *
        UNICARPTMotorCU_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(UNICARPTMotorCU_M->solverInfo,
                            ((UNICARPTMotorCU_M->Timing.clockTick0 + 1) *
        UNICARPTMotorCU_M->Timing.stepSize0 +
        UNICARPTMotorCU_M->Timing.clockTickH0 *
        UNICARPTMotorCU_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_M->Timing.t[0] = rtsiGetT(UNICARPTMotorCU_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S11>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict = e->GetFunc(e->Var);
    }
  }

  /* Integrator: '<S11>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE = UNICARPTMotorCU_B->ReadCMDict;
  }

  UNICARPTMotorCU_B->T_An = UNICARPTMotorCU_X->Integrator_CSTATE;

  /* End of Integrator: '<S11>/Integrator' */

  /* Abs: '<S10>/Abs3' incorporates:
   *  Abs: '<S7>/Abs2'
   *  Inport: '<Root>/FromCM'
   */
  rtb_C_SSOC_tmp = fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m0.rotv);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S10>/Index Vector2' incorporates:
     *  Constant: '<S10>/Constant10'
     *  Constant: '<S2>/Constant'
     *  MultiPortSwitch: '<S9>/Index Vector'
     *  MultiPortSwitch: '<S9>/Index Vector1'
     */
    IndexVector2_tmp = (int32_T)UNICARPTMotorCU_P.Constant_Value;
    UNICARPTMotorCU_B->IndexVector2 = UNICARPTMotorCU_P.bat_P_W[IndexVector2_tmp];

    /* MultiPortSwitch: '<S9>/Index Vector' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    UNICARPTMotorCU_B->IndexVector =
      UNICARPTMotorCU_P.bat_Call_F[IndexVector2_tmp];

    /* Product: '<S9>/Product4' incorporates:
     *  Constant: '<S9>/Constant'
     *  MultiPortSwitch: '<S9>/Index Vector1'
     */
    UNICARPTMotorCU_B->Product4 = UNICARPTMotorCU_P.bat_SOCini[IndexVector2_tmp]
      * UNICARPTMotorCU_B->IndexVector;
  }

  /* Integrator: '<S9>/Integrator2' */
  if (UNICARPTMotorCU_DW->Integrator2_IWORK != 0) {
    UNICARPTMotorCU_X->Integrator2_CSTATE = UNICARPTMotorCU_B->Product4;
  }

  /* Product: '<S9>/Divide3' incorporates:
   *  Integrator: '<S9>/Integrator2'
   */
  UNICARPTMotorCU_B->SOC = UNICARPTMotorCU_X->Integrator2_CSTATE /
    UNICARPTMotorCU_B->IndexVector;

  /* Fcn: '<S9>/U_OC(SOC)' incorporates:
   *  Constant: '<S9>/Constant7'
   */
  rtb_Product_p = (((exp(UNICARPTMotorCU_P.bat_Uoc_V[1] * UNICARPTMotorCU_B->SOC)
                     * UNICARPTMotorCU_P.bat_Uoc_V[0] +
                     UNICARPTMotorCU_P.bat_Uoc_V[2]) +
                    UNICARPTMotorCU_P.bat_Uoc_V[3] * UNICARPTMotorCU_B->SOC) +
                   UNICARPTMotorCU_P.bat_Uoc_V[4] * rt_powd_snf
                   (UNICARPTMotorCU_B->SOC, 2.0)) + UNICARPTMotorCU_P.bat_Uoc_V
    [5] * rt_powd_snf(UNICARPTMotorCU_B->SOC, 3.0);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S9>/Memory' */
    rtb_Memory = UNICARPTMotorCU_DW->Memory_PreviousInput;

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Numerische Stabilität'
     *  Sum: '<S9>/Add2'
     */
    if (rtb_Memory > UNICARPTMotorCU_P.Switch_Threshold) {
      UNICARPTMotorCU_B->Switch = rtb_Memory;
    } else {
      UNICARPTMotorCU_B->Switch = rtb_Memory +
        UNICARPTMotorCU_P.NumerischeStabilitt_Value;
    }

    /* End of Switch: '<S9>/Switch' */
  }

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<S9>/Constant11'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S9>/Divide6'
   *  Sum: '<S9>/Add'
   *  TransferFcn: '<S9>/Transfer Fcn'
   */
  UNICARPTMotorCU_B->Divide = (UNICARPTMotorCU_U->FromCM.MotorIn.m0.PwrElec -
    UNICARPTMotorCU_P.TransferFcn_C * UNICARPTMotorCU_X->TransferFcn_CSTATE) /
    UNICARPTMotorCU_B->Switch / UNICARPTMotorCU_P.bat_nPar;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Constant5'
   *  Fcn: '<S9>/Fcn'
   *  Fcn: '<S9>/R_Series(SOC)'
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator1'
   *  Sum: '<S9>/Sum1'
   */
  UNICARPTMotorCU_B->Gain = ((exp(UNICARPTMotorCU_P.bat_R_Ohm[1] *
    UNICARPTMotorCU_B->SOC) * UNICARPTMotorCU_P.bat_R_Ohm[0] +
    UNICARPTMotorCU_P.bat_R_Ohm[2]) * UNICARPTMotorCU_B->Divide +
    ((rtb_Product_p + UNICARPTMotorCU_X->Integrator_CSTATE_f) +
     UNICARPTMotorCU_X->Integrator1_CSTATE)) * UNICARPTMotorCU_P.bat_nSe;

  /* Abs: '<S10>/Abs' */
  rtb_U_S = fabs(UNICARPTMotorCU_B->Gain);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S15>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_n.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_p.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_p.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_o = e->GetFunc(e->Var);
    }

    /* Memory: '<S14>/Memory10' */
    UNICARPTMotorCU_B->Memory10 = UNICARPTMotorCU_DW->Memory10_PreviousInput;
  }

  /* Integrator: '<S15>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_m != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_h = UNICARPTMotorCU_B->ReadCMDict_o;
  }

  /* Clock: '<S14>/Clock2' incorporates:
   *  Clock: '<S26>/Clock2'
   *  Clock: '<S38>/Clock2'
   *  Clock: '<S50>/Clock2'
   */
  Clock2_tmp = UNICARPTMotorCU_M->Timing.t[0];
  UNICARPTMotorCU_B->Clock2 = Clock2_tmp;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S14>/Memory7' */
    UNICARPTMotorCU_B->Memory7 = UNICARPTMotorCU_DW->Memory7_PreviousInput;

    /* Memory: '<S14>/Memory9' */
    UNICARPTMotorCU_B->Memory9 = UNICARPTMotorCU_DW->Memory9_PreviousInput;

    /* Memory: '<S14>/Memory8' */
    UNICARPTMotorCU_B->Memory8 = UNICARPTMotorCU_DW->Memory8_PreviousInput;

    /* Memory: '<S14>/Memory11' */
    UNICARPTMotorCU_B->Memory11 = UNICARPTMotorCU_DW->Memory11_PreviousInput;
  }

  /* Sum: '<S14>/Add1' */
  rtb_Add1 = UNICARPTMotorCU_B->Clock2 - UNICARPTMotorCU_B->Memory7;

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  Constant: '<S14>/Constant11'
   *  Constant: '<S14>/Constant12'
   *  Constant: '<S14>/Constant13'
   */
  UNICARPTMotorCU_MATLABFunction(UNICARPTMotorCU_B->Memory10,
    UNICARPTMotorCU_B->Divide, UNICARPTMotorCU_B->Clock2, rtb_Add1,
    UNICARPTMotorCU_P.bat_ICC_A, UNICARPTMotorCU_P.bat_IMax_A,
    UNICARPTMotorCU_P.bat_tBreak_s, UNICARPTMotorCU_B->Memory9,
    UNICARPTMotorCU_B->Memory8, UNICARPTMotorCU_B->Memory11,
    &UNICARPTMotorCU_B->sf_MATLABFunction);

  /* Lookup_n-D: '<S7>/Wirkungsgradkennfeld' incorporates:
   *  Abs: '<S7>/Abs1'
   *  Inport: '<Root>/FromCM'
   */
  rtb_R_SSOC = look2_binlxpw(fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m0.Trq),
    rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_M_Nm,
    UNICARPTMotorCU_P.mot_omega_rad_s, UNICARPTMotorCU_P.mot_eta,
    UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex, 14U);

  /* MinMax: '<S10>/Max2' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  rtb_Memory = fmax(UNICARPTMotorCU_P.Constant4_Value, rtb_R_SSOC);

  /* Product: '<S10>/Product4' incorporates:
   *  Abs: '<S10>/Abs3'
   *  Constant: '<S10>/Constant3'
   *  Gain: '<S14>/Gain'
   *  Integrator: '<S15>/Integrator'
   *  Lookup_n-D: '<S14>/1-D Lookup Table'
   *  MinMax: '<S14>/Max'
   *  Product: '<S10>/Divide'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S10>/Add4'
   */
  rtb_DataTypeConversion1 = (UNICARPTMotorCU_P.bat_nPar * fmin(look1_binlxpw
    (UNICARPTMotorCU_X->Integrator_CSTATE_h, UNICARPTMotorCU_P.bat_TLim_K,
     UNICARPTMotorCU_P.bat_ILim_A, 8U),
    UNICARPTMotorCU_B->sf_MATLABFunction.I_max) -
    UNICARPTMotorCU_B->IndexVector2 / rtb_U_S) * rtb_U_S * rtb_Memory /
    (rtb_C_SSOC_tmp + UNICARPTMotorCU_P.Constant3_Value);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S8>/Constant2'
     */
    UNICARPTMotorCU_B->IndexVector2_c = UNICARPTMotorCU_P.bat_SOCMin[(int32_T)
      UNICARPTMotorCU_P.Constant_Value];
  }

  /* RelationalOperator: '<S8>/GreaterThan1' */
  rtb_GreaterThan = (UNICARPTMotorCU_B->SOC >= UNICARPTMotorCU_B->IndexVector2_c);

  /* Product: '<S10>/Product9' incorporates:
   *  Abs: '<S10>/Abs3'
   *  DataTypeConversion: '<S10>/Data Type Conversion2'
   *  Lookup_n-D: '<S10>/Spitzenmoment Motor'
   *  Lookup_n-D: '<S10>/Spitzenmomentberechnung Motor'
   *  MinMax: '<S10>/Max1'
   *  Product: '<S10>/Product1'
   */
  UNICARPTMotorCU_B->Product9 = fmin(look1_binlxpw(UNICARPTMotorCU_B->T_An,
    UNICARPTMotorCU_P.mot_TMPeak_K, UNICARPTMotorCU_P.mot_weight_T, 3U) *
    look1_binlxpw(rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_omegaPeak_rad_s,
                  UNICARPTMotorCU_P.mot_MPeak_Nm, 5U), rtb_DataTypeConversion1) *
    (real_T)rtb_GreaterThan;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S2>/Write CM Dict' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict_PWORK.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict_IWORK.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product9;
      DVA_PokeSL(e, value);
    }
  }

  /* Product: '<S10>/Product8' incorporates:
   *  Abs: '<S10>/Abs3'
   *  DataTypeConversion: '<S10>/Data Type Conversion2'
   *  Lookup_n-D: '<S10>/Dauermoment Motor'
   *  MinMax: '<S10>/Max'
   */
  UNICARPTMotorCU_B->Product8 = (real_T)rtb_GreaterThan * fmin
    (rtb_DataTypeConversion1, look1_binlxpw(rtb_C_SSOC_tmp,
      UNICARPTMotorCU_P.mot_omegaC_rad_s, UNICARPTMotorCU_P.mot_MC_Nm, 3U));
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S2>/Write CM Dict1' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict1_PWORK.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict1_IWORK.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict1_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product8;
      DVA_PokeSL(e, value);
    }

    /* S-Function (write_dict): '<S2>/Write CM Dict2' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict2_PWORK.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict2_IWORK.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict2_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->SOC;
      DVA_PokeSL(e, value);
    }

    /* S-Function (read_dict): '<S11>/Read CM Dict1' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict1_PWORK.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict1_IWORK.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict1_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict1 = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S11>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict4_PWORK.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict4_IWORK.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict4_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict4 = e->GetFunc(e->Var);
    }

    /* Sqrt: '<S11>/Sqrt1' incorporates:
     *  Math: '<S11>/Square2'
     *  Math: '<S11>/Square3'
     *  Sum: '<S11>/Add2'
     */
    UNICARPTMotorCU_B->v_Car = sqrt(UNICARPTMotorCU_B->ReadCMDict1 *
      UNICARPTMotorCU_B->ReadCMDict1 + UNICARPTMotorCU_B->ReadCMDict4 *
      UNICARPTMotorCU_B->ReadCMDict4);

    /* Gain: '<S11>/Gain' incorporates:
     *  Constant: '<S11>/Constant8'
     */
    UNICARPTMotorCU_B->Gain_n = UNICARPTMotorCU_P.Gain_Gain *
      UNICARPTMotorCU_P.MCU_r_m;
  }

  /* MATLAB Function: '<S11>/Calc alpha_An' incorporates:
   *  Constant: '<S11>/Constant10'
   *  Constant: '<S11>/Constant11'
   *  Constant: '<S11>/Constant9'
   */
  UNICARPTMotorCU_Calcalpha_An(UNICARPTMotorCU_B->v_Car,
    UNICARPTMotorCU_B->Gain_n, UNICARPTMotorCU_P.MCU_nue_Ns_m_2,
    UNICARPTMotorCU_P.MCU_Pr, UNICARPTMotorCU_P.MCU_alpha_m_2_s,
    UNICARPTMotorCU_B->T_An, UNICARPTMotorCU_B->ReadCMDict,
    &UNICARPTMotorCU_B->sf_Calcalpha_An);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Product: '<S11>/Product2' incorporates:
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S13>/Constant'
     *  Memory: '<S11>/Memory'
     *  RelationalOperator: '<S13>/Compare'
     */
    UNICARPTMotorCU_B->q_kuehl = (real_T)
      (UNICARPTMotorCU_DW->Memory_PreviousInput_b >=
       UNICARPTMotorCU_P.CompareToConstant_const) * UNICARPTMotorCU_P.MCU_q_W;

    /* Product: '<S11>/Product' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     */
    UNICARPTMotorCU_B->Product = UNICARPTMotorCU_P.MCU_m_kg *
      UNICARPTMotorCU_P.MCU_cp_J_kgK;

    /* MultiPortSwitch: '<S8>/Index Vector1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S8>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector1 = UNICARPTMotorCU_P.bat_SOCMax[(int32_T)
      UNICARPTMotorCU_P.Constant_Value];
  }

  /* Product: '<S11>/Divide' incorporates:
   *  Abs: '<S7>/Abs3'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S11>/Product1'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product3'
   *  Sum: '<S11>/Add'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   *  Sum: '<S7>/Add'
   */
  UNICARPTMotorCU_B->dT_An = (((UNICARPTMotorCU_P.Constant_Value_e - rtb_R_SSOC)
    * fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m0.rotv *
           UNICARPTMotorCU_U->FromCM.MotorIn.m0.Trq) -
    UNICARPTMotorCU_B->sf_Calcalpha_An.alpha_An * UNICARPTMotorCU_P.MCU_area_m_2
    * (UNICARPTMotorCU_B->T_An - UNICARPTMotorCU_B->ReadCMDict)) -
    UNICARPTMotorCU_B->q_kuehl) / UNICARPTMotorCU_B->Product;

  /* Abs: '<S9>/Abs' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Sum: '<S9>/Add1'
   */
  rtb_DataTypeConversion1 = fabs(UNICARPTMotorCU_P.bat_nSe * rtb_Product_p -
    UNICARPTMotorCU_B->Gain);

  /* Product: '<S14>/Divide2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Lookup_n-D: '<S14>/1-D Lookup Table1'
   */
  rtb_Divide2 = 1.0 / look1_binlxpw(UNICARPTMotorCU_B->Divide,
    UNICARPTMotorCU_P.bat_ItMax_A, UNICARPTMotorCU_P.bat_KtMax, 4U) *
    UNICARPTMotorCU_P.bat_tIMax_s;

  /* Outputs for Resettable SubSystem: '<S14>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem(UNICARPTMotorCU_M, rtb_Divide2,
    UNICARPTMotorCU_B->sf_MATLABFunction.trigger,
    &UNICARPTMotorCU_B->ResettableSubsystem,
    &UNICARPTMotorCU_DW->ResettableSubsystem, &UNICARPTMotorCU_P,
    &UNICARPTMotorCU_PrevZCX->ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S14>/Resettable Subsystem' */

  /* Fcn: '<S9>/C_L(SOC)' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  rtb_R_SSOC = exp(UNICARPTMotorCU_P.bat_C1_F[1] * UNICARPTMotorCU_B->SOC) *
    UNICARPTMotorCU_P.bat_C1_F[0] + UNICARPTMotorCU_P.bat_C1_F[2];

  /* Fcn: '<S9>/C_S(SOC)' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  rtb_Product_p = exp(UNICARPTMotorCU_P.bat_C2_F[1] * UNICARPTMotorCU_B->SOC) *
    UNICARPTMotorCU_P.bat_C2_F[0] + UNICARPTMotorCU_P.bat_C2_F[2];
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S9>/Constant10'
     */
    UNICARPTMotorCU_B->IndexVector2_j = UNICARPTMotorCU_P.bat_P_W[(int32_T)
      UNICARPTMotorCU_P.Constant_Value];

    /* Product: '<S15>/Product3' incorporates:
     *  Constant: '<S15>/Constant4'
     *  Constant: '<S15>/Constant5'
     */
    UNICARPTMotorCU_B->Product3 = UNICARPTMotorCU_P.bat_area_m_2 *
      UNICARPTMotorCU_P.bat_alpha_W_Km_2;
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Fcn: '<S9>/R_L(SOC)'
   *  Integrator: '<S9>/Integrator'
   *  Product: '<S9>/Divide1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   */
  UNICARPTMotorCU_B->Sum = UNICARPTMotorCU_B->Divide / rtb_R_SSOC -
    UNICARPTMotorCU_X->Integrator_CSTATE_f / ((exp(UNICARPTMotorCU_P.bat_R1_Ohm
    [1] * UNICARPTMotorCU_B->SOC) * UNICARPTMotorCU_P.bat_R1_Ohm[0] +
    UNICARPTMotorCU_P.bat_R1_Ohm[2]) * rtb_R_SSOC);

  /* Sum: '<S9>/Sum2' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Fcn: '<S9>/R_S(SOC)'
   *  Integrator: '<S9>/Integrator1'
   *  Product: '<S9>/Divide2'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   */
  UNICARPTMotorCU_B->Sum2 = UNICARPTMotorCU_B->Divide / rtb_Product_p -
    UNICARPTMotorCU_X->Integrator1_CSTATE / ((exp(UNICARPTMotorCU_P.bat_R2_Ohm[1]
    * UNICARPTMotorCU_B->SOC) * UNICARPTMotorCU_P.bat_R2_Ohm[0] +
    UNICARPTMotorCU_P.bat_R2_Ohm[2]) * rtb_Product_p);

  /* Product: '<S15>/Product2' incorporates:
   *  Abs: '<S9>/Abs1'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S9>/Constant12'
   *  Integrator: '<S15>/Integrator'
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   *  Product: '<S9>/Product5'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Sum1'
   */
  UNICARPTMotorCU_B->Product2 = ((fabs(UNICARPTMotorCU_B->Divide *
    UNICARPTMotorCU_P.bat_nPar) * rtb_DataTypeConversion1 +
    UNICARPTMotorCU_P.bat_q_W) - (UNICARPTMotorCU_X->Integrator_CSTATE_h -
    UNICARPTMotorCU_B->ReadCMDict_o) * UNICARPTMotorCU_B->Product3) /
    UNICARPTMotorCU_P.bat_m_kg / UNICARPTMotorCU_P.bat_cp_J_kgK;

  /* Product: '<S10>/Product' incorporates:
   *  Abs: '<S10>/Abs3'
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant2'
   *  Sum: '<S10>/Add1'
   */
  rtb_Memory = 1.0 / rtb_Memory * rtb_U_S * UNICARPTMotorCU_P.bat_ILoadMax_A /
    (rtb_C_SSOC_tmp + UNICARPTMotorCU_P.Constant2_Value);

  /* Product: '<S10>/Product2' incorporates:
   *  Abs: '<S10>/Abs3'
   *  DataTypeConversion: '<S10>/Data Type Conversion1'
   *  Lookup_n-D: '<S10>/1-D Lookup Table'
   *  MinMax: '<S10>/Min'
   *  RelationalOperator: '<S8>/GreaterThan'
   */
  UNICARPTMotorCU_B->Product2_a = (real_T)(UNICARPTMotorCU_B->IndexVector1 >=
    UNICARPTMotorCU_B->SOC) * fmin(look1_binlxpw(rtb_C_SSOC_tmp,
    UNICARPTMotorCU_P.mot_omegaMaxReg_rad_s, UNICARPTMotorCU_P.mot_MMaxReg_Nm,
    8U), rtb_Memory);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S23>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_o.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_b.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_b.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_k = e->GetFunc(e->Var);
    }
  }

  /* Integrator: '<S23>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_f != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_o = UNICARPTMotorCU_B->ReadCMDict_k;
  }

  UNICARPTMotorCU_B->T_An_o = UNICARPTMotorCU_X->Integrator_CSTATE_o;

  /* End of Integrator: '<S23>/Integrator' */

  /* Abs: '<S22>/Abs3' incorporates:
   *  Abs: '<S19>/Abs2'
   *  Inport: '<Root>/FromCM'
   */
  rtb_C_SSOC_tmp = fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m1.rotv);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S22>/Index Vector2' incorporates:
     *  Constant: '<S22>/Constant10'
     *  Constant: '<S3>/Constant'
     *  MultiPortSwitch: '<S21>/Index Vector'
     *  MultiPortSwitch: '<S21>/Index Vector1'
     */
    IndexVector2_tmp = (int32_T)UNICARPTMotorCU_P.Constant_Value_e4;
    UNICARPTMotorCU_B->IndexVector2_a =
      UNICARPTMotorCU_P.bat_P_W[IndexVector2_tmp];

    /* MultiPortSwitch: '<S21>/Index Vector' incorporates:
     *  Constant: '<S21>/Constant1'
     */
    UNICARPTMotorCU_B->IndexVector_i =
      UNICARPTMotorCU_P.bat_Call_F[IndexVector2_tmp];

    /* Product: '<S21>/Product4' incorporates:
     *  Constant: '<S21>/Constant'
     *  MultiPortSwitch: '<S21>/Index Vector1'
     */
    UNICARPTMotorCU_B->Product4_m =
      UNICARPTMotorCU_P.bat_SOCini[IndexVector2_tmp] *
      UNICARPTMotorCU_B->IndexVector_i;
  }

  /* Integrator: '<S21>/Integrator2' */
  if (UNICARPTMotorCU_DW->Integrator2_IWORK_g != 0) {
    UNICARPTMotorCU_X->Integrator2_CSTATE_p = UNICARPTMotorCU_B->Product4_m;
  }

  /* Product: '<S21>/Divide3' incorporates:
   *  Integrator: '<S21>/Integrator2'
   */
  UNICARPTMotorCU_B->SOC_g = UNICARPTMotorCU_X->Integrator2_CSTATE_p /
    UNICARPTMotorCU_B->IndexVector_i;

  /* Fcn: '<S21>/U_OC(SOC)' incorporates:
   *  Constant: '<S21>/Constant7'
   */
  rtb_Memory = (((exp(UNICARPTMotorCU_P.bat_Uoc_V[1] * UNICARPTMotorCU_B->SOC_g)
                  * UNICARPTMotorCU_P.bat_Uoc_V[0] +
                  UNICARPTMotorCU_P.bat_Uoc_V[2]) + UNICARPTMotorCU_P.bat_Uoc_V
                 [3] * UNICARPTMotorCU_B->SOC_g) + UNICARPTMotorCU_P.bat_Uoc_V[4]
                * rt_powd_snf(UNICARPTMotorCU_B->SOC_g, 2.0)) +
    UNICARPTMotorCU_P.bat_Uoc_V[5] * rt_powd_snf(UNICARPTMotorCU_B->SOC_g, 3.0);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S21>/Memory' */
    rtb_Product_p = UNICARPTMotorCU_DW->Memory_PreviousInput_bq;

    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S21>/Numerische Stabilität'
     *  Sum: '<S21>/Add2'
     */
    if (rtb_Product_p > UNICARPTMotorCU_P.Switch_Threshold_j) {
      UNICARPTMotorCU_B->Switch_b = rtb_Product_p;
    } else {
      UNICARPTMotorCU_B->Switch_b = rtb_Product_p +
        UNICARPTMotorCU_P.NumerischeStabilitt_Value_i;
    }

    /* End of Switch: '<S21>/Switch' */
  }

  /* Product: '<S21>/Divide' incorporates:
   *  Constant: '<S21>/Constant11'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S21>/Divide6'
   *  Sum: '<S21>/Add'
   *  TransferFcn: '<S21>/Transfer Fcn'
   */
  UNICARPTMotorCU_B->Divide_l = (UNICARPTMotorCU_U->FromCM.MotorIn.m1.PwrElec -
    UNICARPTMotorCU_P.TransferFcn_C_c * UNICARPTMotorCU_X->TransferFcn_CSTATE_c)
    / UNICARPTMotorCU_B->Switch_b / UNICARPTMotorCU_P.bat_nPar;

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S21>/Constant5'
   *  Fcn: '<S21>/Fcn'
   *  Fcn: '<S21>/R_Series(SOC)'
   *  Integrator: '<S21>/Integrator'
   *  Integrator: '<S21>/Integrator1'
   *  Sum: '<S21>/Sum1'
   */
  UNICARPTMotorCU_B->Gain_b = ((exp(UNICARPTMotorCU_P.bat_R_Ohm[1] *
    UNICARPTMotorCU_B->SOC_g) * UNICARPTMotorCU_P.bat_R_Ohm[0] +
    UNICARPTMotorCU_P.bat_R_Ohm[2]) * UNICARPTMotorCU_B->Divide_l + ((rtb_Memory
    + UNICARPTMotorCU_X->Integrator_CSTATE_g) +
    UNICARPTMotorCU_X->Integrator1_CSTATE_p)) * UNICARPTMotorCU_P.bat_nSe;

  /* Abs: '<S22>/Abs' */
  rtb_U_S = fabs(UNICARPTMotorCU_B->Gain_b);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S27>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_a.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_l.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_l.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_kb = e->GetFunc(e->Var);
    }

    /* Memory: '<S26>/Memory10' */
    UNICARPTMotorCU_B->Memory10_j = UNICARPTMotorCU_DW->Memory10_PreviousInput_m;
  }

  /* Integrator: '<S27>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_g != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_j = UNICARPTMotorCU_B->ReadCMDict_kb;
  }

  /* Clock: '<S26>/Clock2' */
  UNICARPTMotorCU_B->Clock2_b = Clock2_tmp;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S26>/Memory7' */
    UNICARPTMotorCU_B->Memory7_a = UNICARPTMotorCU_DW->Memory7_PreviousInput_g;

    /* Memory: '<S26>/Memory9' */
    UNICARPTMotorCU_B->Memory9_j = UNICARPTMotorCU_DW->Memory9_PreviousInput_o;

    /* Memory: '<S26>/Memory8' */
    UNICARPTMotorCU_B->Memory8_k = UNICARPTMotorCU_DW->Memory8_PreviousInput_m;

    /* Memory: '<S26>/Memory11' */
    UNICARPTMotorCU_B->Memory11_i = UNICARPTMotorCU_DW->Memory11_PreviousInput_f;
  }

  /* Sum: '<S26>/Add1' */
  rtb_Add1_m = UNICARPTMotorCU_B->Clock2_b - UNICARPTMotorCU_B->Memory7_a;

  /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
   *  Constant: '<S26>/Constant11'
   *  Constant: '<S26>/Constant12'
   *  Constant: '<S26>/Constant13'
   */
  UNICARPTMotorCU_MATLABFunction(UNICARPTMotorCU_B->Memory10_j,
    UNICARPTMotorCU_B->Divide_l, UNICARPTMotorCU_B->Clock2_b, rtb_Add1_m,
    UNICARPTMotorCU_P.bat_ICC_A, UNICARPTMotorCU_P.bat_IMax_A,
    UNICARPTMotorCU_P.bat_tBreak_s, UNICARPTMotorCU_B->Memory9_j,
    UNICARPTMotorCU_B->Memory8_k, UNICARPTMotorCU_B->Memory11_i,
    &UNICARPTMotorCU_B->sf_MATLABFunction_a);

  /* Lookup_n-D: '<S19>/Wirkungsgradkennfeld' incorporates:
   *  Abs: '<S19>/Abs1'
   *  Inport: '<Root>/FromCM'
   */
  rtb_R_SSOC = look2_binlxpw(fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m1.Trq),
    rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_M_Nm,
    UNICARPTMotorCU_P.mot_omega_rad_s, UNICARPTMotorCU_P.mot_eta,
    UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex_k, 14U);

  /* MinMax: '<S22>/Max2' incorporates:
   *  Constant: '<S22>/Constant4'
   */
  rtb_Product_p = fmax(UNICARPTMotorCU_P.Constant4_Value_c, rtb_R_SSOC);

  /* Product: '<S22>/Product4' incorporates:
   *  Abs: '<S22>/Abs3'
   *  Constant: '<S22>/Constant3'
   *  Gain: '<S26>/Gain'
   *  Integrator: '<S27>/Integrator'
   *  Lookup_n-D: '<S26>/1-D Lookup Table'
   *  MinMax: '<S26>/Max'
   *  Product: '<S22>/Divide'
   *  Sum: '<S22>/Add3'
   *  Sum: '<S22>/Add4'
   */
  rtb_DataTypeConversion1 = (UNICARPTMotorCU_P.bat_nPar * fmin(look1_binlxpw
    (UNICARPTMotorCU_X->Integrator_CSTATE_j, UNICARPTMotorCU_P.bat_TLim_K,
     UNICARPTMotorCU_P.bat_ILim_A, 8U),
    UNICARPTMotorCU_B->sf_MATLABFunction_a.I_max) -
    UNICARPTMotorCU_B->IndexVector2_a / rtb_U_S) * rtb_U_S * rtb_Product_p /
    (rtb_C_SSOC_tmp + UNICARPTMotorCU_P.Constant3_Value_e);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S20>/Index Vector2' incorporates:
     *  Constant: '<S20>/Constant2'
     *  Constant: '<S3>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector2_k = UNICARPTMotorCU_P.bat_SOCMin[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_e4];
  }

  /* RelationalOperator: '<S20>/GreaterThan1' */
  rtb_GreaterThan = (UNICARPTMotorCU_B->SOC_g >=
                     UNICARPTMotorCU_B->IndexVector2_k);

  /* Product: '<S22>/Product9' incorporates:
   *  Abs: '<S22>/Abs3'
   *  DataTypeConversion: '<S22>/Data Type Conversion2'
   *  Lookup_n-D: '<S22>/Spitzenmoment Motor'
   *  Lookup_n-D: '<S22>/Spitzenmomentberechnung Motor'
   *  MinMax: '<S22>/Max1'
   *  Product: '<S22>/Product1'
   */
  UNICARPTMotorCU_B->Product9_n = fmin(look1_binlxpw(UNICARPTMotorCU_B->T_An_o,
    UNICARPTMotorCU_P.mot_TMPeak_K, UNICARPTMotorCU_P.mot_weight_T, 3U) *
    look1_binlxpw(rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_omegaPeak_rad_s,
                  UNICARPTMotorCU_P.mot_MPeak_Nm, 5U), rtb_DataTypeConversion1) *
    (real_T)rtb_GreaterThan;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S3>/Write CM Dict' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict_PWORK_a.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict_IWORK_i.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict_IWORK_i.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product9_n;
      DVA_PokeSL(e, value);
    }
  }

  /* Product: '<S22>/Product8' incorporates:
   *  Abs: '<S22>/Abs3'
   *  DataTypeConversion: '<S22>/Data Type Conversion2'
   *  Lookup_n-D: '<S22>/Dauermoment Motor'
   *  MinMax: '<S22>/Max'
   */
  UNICARPTMotorCU_B->Product8_k = (real_T)rtb_GreaterThan * fmin
    (rtb_DataTypeConversion1, look1_binlxpw(rtb_C_SSOC_tmp,
      UNICARPTMotorCU_P.mot_omegaC_rad_s, UNICARPTMotorCU_P.mot_MC_Nm, 3U));
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S3>/Write CM Dict1' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict1_PWORK_m.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict1_IWORK_h.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict1_IWORK_h.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product8_k;
      DVA_PokeSL(e, value);
    }

    /* S-Function (write_dict): '<S3>/Write CM Dict2' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict2_PWORK_j.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict2_IWORK_f.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict2_IWORK_f.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->SOC_g;
      DVA_PokeSL(e, value);
    }

    /* S-Function (read_dict): '<S23>/Read CM Dict1' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict1_PWORK_b.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict1_IWORK_d.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict1_IWORK_d.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict1_e = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S23>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict4_PWORK_i.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict4_IWORK_j.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict4_IWORK_j.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict4_i = e->GetFunc(e->Var);
    }

    /* Sqrt: '<S23>/Sqrt1' incorporates:
     *  Math: '<S23>/Square2'
     *  Math: '<S23>/Square3'
     *  Sum: '<S23>/Add2'
     */
    UNICARPTMotorCU_B->v_Car_l = sqrt(UNICARPTMotorCU_B->ReadCMDict1_e *
      UNICARPTMotorCU_B->ReadCMDict1_e + UNICARPTMotorCU_B->ReadCMDict4_i *
      UNICARPTMotorCU_B->ReadCMDict4_i);

    /* Gain: '<S23>/Gain' incorporates:
     *  Constant: '<S23>/Constant8'
     */
    UNICARPTMotorCU_B->Gain_j = UNICARPTMotorCU_P.Gain_Gain_b *
      UNICARPTMotorCU_P.MCU_r_m;
  }

  /* MATLAB Function: '<S23>/Calc alpha_An' incorporates:
   *  Constant: '<S23>/Constant10'
   *  Constant: '<S23>/Constant11'
   *  Constant: '<S23>/Constant9'
   */
  UNICARPTMotorCU_Calcalpha_An(UNICARPTMotorCU_B->v_Car_l,
    UNICARPTMotorCU_B->Gain_j, UNICARPTMotorCU_P.MCU_nue_Ns_m_2,
    UNICARPTMotorCU_P.MCU_Pr, UNICARPTMotorCU_P.MCU_alpha_m_2_s,
    UNICARPTMotorCU_B->T_An_o, UNICARPTMotorCU_B->ReadCMDict_k,
    &UNICARPTMotorCU_B->sf_Calcalpha_An_j);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Product: '<S23>/Product2' incorporates:
     *  Constant: '<S23>/Constant4'
     *  Constant: '<S25>/Constant'
     *  Memory: '<S23>/Memory'
     *  RelationalOperator: '<S25>/Compare'
     */
    UNICARPTMotorCU_B->q_kuehl_b = (real_T)
      (UNICARPTMotorCU_DW->Memory_PreviousInput_g >=
       UNICARPTMotorCU_P.CompareToConstant_const_m) * UNICARPTMotorCU_P.MCU_q_W;

    /* Product: '<S23>/Product' incorporates:
     *  Constant: '<S23>/Constant'
     *  Constant: '<S23>/Constant1'
     */
    UNICARPTMotorCU_B->Product_a = UNICARPTMotorCU_P.MCU_m_kg *
      UNICARPTMotorCU_P.MCU_cp_J_kgK;

    /* MultiPortSwitch: '<S20>/Index Vector1' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S3>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector1_g = UNICARPTMotorCU_P.bat_SOCMax[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_e4];
  }

  /* Product: '<S23>/Divide' incorporates:
   *  Abs: '<S19>/Abs3'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S23>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product3'
   *  Product: '<S23>/Product1'
   *  Sum: '<S19>/Add'
   *  Sum: '<S23>/Add'
   *  Sum: '<S23>/Sum'
   *  Sum: '<S23>/Sum1'
   */
  UNICARPTMotorCU_B->dT_An_a = (((UNICARPTMotorCU_P.Constant_Value_f -
    rtb_R_SSOC) * fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m1.rotv *
                       UNICARPTMotorCU_U->FromCM.MotorIn.m1.Trq) -
    UNICARPTMotorCU_B->sf_Calcalpha_An_j.alpha_An *
    UNICARPTMotorCU_P.MCU_area_m_2 * (UNICARPTMotorCU_B->T_An_o -
    UNICARPTMotorCU_B->ReadCMDict_k)) - UNICARPTMotorCU_B->q_kuehl_b) /
    UNICARPTMotorCU_B->Product_a;

  /* Product: '<S26>/Divide2' incorporates:
   *  Constant: '<S26>/Constant2'
   *  Lookup_n-D: '<S26>/1-D Lookup Table1'
   */
  rtb_Divide2_e = 1.0 / look1_binlxpw(UNICARPTMotorCU_B->Divide_l,
    UNICARPTMotorCU_P.bat_ItMax_A, UNICARPTMotorCU_P.bat_KtMax, 4U) *
    UNICARPTMotorCU_P.bat_tIMax_s;

  /* Outputs for Resettable SubSystem: '<S26>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem(UNICARPTMotorCU_M, rtb_Divide2_e,
    UNICARPTMotorCU_B->sf_MATLABFunction_a.trigger,
    &UNICARPTMotorCU_B->ResettableSubsystem_n,
    &UNICARPTMotorCU_DW->ResettableSubsystem_n, &UNICARPTMotorCU_P,
    &UNICARPTMotorCU_PrevZCX->ResettableSubsystem_n);

  /* End of Outputs for SubSystem: '<S26>/Resettable Subsystem' */

  /* Fcn: '<S21>/C_L(SOC)' incorporates:
   *  Constant: '<S21>/Constant2'
   */
  rtb_R_SSOC = exp(UNICARPTMotorCU_P.bat_C1_F[1] * UNICARPTMotorCU_B->SOC_g) *
    UNICARPTMotorCU_P.bat_C1_F[0] + UNICARPTMotorCU_P.bat_C1_F[2];

  /* Fcn: '<S21>/C_S(SOC)' incorporates:
   *  Constant: '<S21>/Constant3'
   */
  rtb_DataTypeConversion1 = exp(UNICARPTMotorCU_P.bat_C2_F[1] *
    UNICARPTMotorCU_B->SOC_g) * UNICARPTMotorCU_P.bat_C2_F[0] +
    UNICARPTMotorCU_P.bat_C2_F[2];
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S21>/Index Vector2' incorporates:
     *  Constant: '<S21>/Constant10'
     *  Constant: '<S3>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector2_f = UNICARPTMotorCU_P.bat_P_W[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_e4];

    /* Product: '<S27>/Product3' incorporates:
     *  Constant: '<S27>/Constant4'
     *  Constant: '<S27>/Constant5'
     */
    UNICARPTMotorCU_B->Product3_i = UNICARPTMotorCU_P.bat_area_m_2 *
      UNICARPTMotorCU_P.bat_alpha_W_Km_2;
  }

  /* Sum: '<S21>/Sum' incorporates:
   *  Constant: '<S21>/Constant6'
   *  Fcn: '<S21>/R_L(SOC)'
   *  Integrator: '<S21>/Integrator'
   *  Product: '<S21>/Divide1'
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   */
  UNICARPTMotorCU_B->Sum_h = UNICARPTMotorCU_B->Divide_l / rtb_R_SSOC -
    UNICARPTMotorCU_X->Integrator_CSTATE_g / ((exp(UNICARPTMotorCU_P.bat_R1_Ohm
    [1] * UNICARPTMotorCU_B->SOC_g) * UNICARPTMotorCU_P.bat_R1_Ohm[0] +
    UNICARPTMotorCU_P.bat_R1_Ohm[2]) * rtb_R_SSOC);

  /* Sum: '<S21>/Sum2' incorporates:
   *  Constant: '<S21>/Constant4'
   *  Fcn: '<S21>/R_S(SOC)'
   *  Integrator: '<S21>/Integrator1'
   *  Product: '<S21>/Divide2'
   *  Product: '<S21>/Product2'
   *  Product: '<S21>/Product3'
   */
  UNICARPTMotorCU_B->Sum2_m = UNICARPTMotorCU_B->Divide_l /
    rtb_DataTypeConversion1 - UNICARPTMotorCU_X->Integrator1_CSTATE_p / ((exp
    (UNICARPTMotorCU_P.bat_R2_Ohm[1] * UNICARPTMotorCU_B->SOC_g) *
    UNICARPTMotorCU_P.bat_R2_Ohm[0] + UNICARPTMotorCU_P.bat_R2_Ohm[2]) *
    rtb_DataTypeConversion1);

  /* Product: '<S27>/Product2' incorporates:
   *  Abs: '<S21>/Abs'
   *  Abs: '<S21>/Abs1'
   *  Constant: '<S21>/Constant12'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S21>/Gain1'
   *  Integrator: '<S27>/Integrator'
   *  Product: '<S21>/Product5'
   *  Product: '<S27>/Product'
   *  Product: '<S27>/Product1'
   *  Sum: '<S21>/Add1'
   *  Sum: '<S27>/Add'
   *  Sum: '<S27>/Sum1'
   */
  UNICARPTMotorCU_B->Product2_ax = ((fabs(UNICARPTMotorCU_P.bat_nSe * rtb_Memory
    - UNICARPTMotorCU_B->Gain_b) * fabs(UNICARPTMotorCU_B->Divide_l *
    UNICARPTMotorCU_P.bat_nPar) + UNICARPTMotorCU_P.bat_q_W) -
    (UNICARPTMotorCU_X->Integrator_CSTATE_j - UNICARPTMotorCU_B->ReadCMDict_kb) *
    UNICARPTMotorCU_B->Product3_i) / UNICARPTMotorCU_P.bat_m_kg /
    UNICARPTMotorCU_P.bat_cp_J_kgK;

  /* Product: '<S22>/Product' incorporates:
   *  Abs: '<S22>/Abs3'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant2'
   *  Sum: '<S22>/Add1'
   */
  rtb_Product_p = 1.0 / rtb_Product_p * rtb_U_S *
    UNICARPTMotorCU_P.bat_ILoadMax_A / (rtb_C_SSOC_tmp +
    UNICARPTMotorCU_P.Constant2_Value_k);

  /* Product: '<S22>/Product2' incorporates:
   *  Abs: '<S22>/Abs3'
   *  DataTypeConversion: '<S22>/Data Type Conversion1'
   *  Lookup_n-D: '<S22>/1-D Lookup Table'
   *  MinMax: '<S22>/Min'
   *  RelationalOperator: '<S20>/GreaterThan'
   */
  UNICARPTMotorCU_B->Product2_o = (real_T)(UNICARPTMotorCU_B->IndexVector1_g >=
    UNICARPTMotorCU_B->SOC_g) * fmin(look1_binlxpw(rtb_C_SSOC_tmp,
    UNICARPTMotorCU_P.mot_omegaMaxReg_rad_s, UNICARPTMotorCU_P.mot_MMaxReg_Nm,
    8U), rtb_Product_p);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S35>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_k.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_h.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_h.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_p = e->GetFunc(e->Var);
    }
  }

  /* Integrator: '<S35>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_h != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_c = UNICARPTMotorCU_B->ReadCMDict_p;
  }

  UNICARPTMotorCU_B->T_An_oc = UNICARPTMotorCU_X->Integrator_CSTATE_c;

  /* End of Integrator: '<S35>/Integrator' */

  /* Abs: '<S34>/Abs3' incorporates:
   *  Abs: '<S31>/Abs2'
   *  Inport: '<Root>/FromCM'
   */
  rtb_C_SSOC_tmp = fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m2.rotv);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S34>/Index Vector2' incorporates:
     *  Constant: '<S34>/Constant10'
     *  Constant: '<S4>/Constant'
     *  MultiPortSwitch: '<S33>/Index Vector'
     *  MultiPortSwitch: '<S33>/Index Vector1'
     */
    IndexVector2_tmp = (int32_T)UNICARPTMotorCU_P.Constant_Value_ey;
    UNICARPTMotorCU_B->IndexVector2_d =
      UNICARPTMotorCU_P.bat_P_W[IndexVector2_tmp];

    /* MultiPortSwitch: '<S33>/Index Vector' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    UNICARPTMotorCU_B->IndexVector_n =
      UNICARPTMotorCU_P.bat_Call_F[IndexVector2_tmp];

    /* Product: '<S33>/Product4' incorporates:
     *  Constant: '<S33>/Constant'
     *  MultiPortSwitch: '<S33>/Index Vector1'
     */
    UNICARPTMotorCU_B->Product4_b =
      UNICARPTMotorCU_P.bat_SOCini[IndexVector2_tmp] *
      UNICARPTMotorCU_B->IndexVector_n;
  }

  /* Integrator: '<S33>/Integrator2' */
  if (UNICARPTMotorCU_DW->Integrator2_IWORK_i != 0) {
    UNICARPTMotorCU_X->Integrator2_CSTATE_h = UNICARPTMotorCU_B->Product4_b;
  }

  /* Product: '<S33>/Divide3' incorporates:
   *  Integrator: '<S33>/Integrator2'
   */
  UNICARPTMotorCU_B->SOC_j = UNICARPTMotorCU_X->Integrator2_CSTATE_h /
    UNICARPTMotorCU_B->IndexVector_n;

  /* Fcn: '<S33>/U_OC(SOC)' incorporates:
   *  Constant: '<S33>/Constant7'
   */
  rtb_Memory = (((exp(UNICARPTMotorCU_P.bat_Uoc_V[1] * UNICARPTMotorCU_B->SOC_j)
                  * UNICARPTMotorCU_P.bat_Uoc_V[0] +
                  UNICARPTMotorCU_P.bat_Uoc_V[2]) + UNICARPTMotorCU_P.bat_Uoc_V
                 [3] * UNICARPTMotorCU_B->SOC_j) + UNICARPTMotorCU_P.bat_Uoc_V[4]
                * rt_powd_snf(UNICARPTMotorCU_B->SOC_j, 2.0)) +
    UNICARPTMotorCU_P.bat_Uoc_V[5] * rt_powd_snf(UNICARPTMotorCU_B->SOC_j, 3.0);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S33>/Memory' */
    rtb_Product_p = UNICARPTMotorCU_DW->Memory_PreviousInput_gf;

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/Numerische Stabilität'
     *  Sum: '<S33>/Add2'
     */
    if (rtb_Product_p > UNICARPTMotorCU_P.Switch_Threshold_js) {
      UNICARPTMotorCU_B->Switch_d = rtb_Product_p;
    } else {
      UNICARPTMotorCU_B->Switch_d = rtb_Product_p +
        UNICARPTMotorCU_P.NumerischeStabilitt_Value_io;
    }

    /* End of Switch: '<S33>/Switch' */
  }

  /* Product: '<S33>/Divide' incorporates:
   *  Constant: '<S33>/Constant11'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S33>/Divide6'
   *  Sum: '<S33>/Add'
   *  TransferFcn: '<S33>/Transfer Fcn'
   */
  UNICARPTMotorCU_B->Divide_c = (UNICARPTMotorCU_U->FromCM.MotorIn.m2.PwrElec -
    UNICARPTMotorCU_P.TransferFcn_C_d * UNICARPTMotorCU_X->TransferFcn_CSTATE_i)
    / UNICARPTMotorCU_B->Switch_d / UNICARPTMotorCU_P.bat_nPar;

  /* Gain: '<S33>/Gain' incorporates:
   *  Constant: '<S33>/Constant5'
   *  Fcn: '<S33>/Fcn'
   *  Fcn: '<S33>/R_Series(SOC)'
   *  Integrator: '<S33>/Integrator'
   *  Integrator: '<S33>/Integrator1'
   *  Sum: '<S33>/Sum1'
   */
  UNICARPTMotorCU_B->Gain_e = ((exp(UNICARPTMotorCU_P.bat_R_Ohm[1] *
    UNICARPTMotorCU_B->SOC_j) * UNICARPTMotorCU_P.bat_R_Ohm[0] +
    UNICARPTMotorCU_P.bat_R_Ohm[2]) * UNICARPTMotorCU_B->Divide_c + ((rtb_Memory
    + UNICARPTMotorCU_X->Integrator_CSTATE_ga) +
    UNICARPTMotorCU_X->Integrator1_CSTATE_n)) * UNICARPTMotorCU_P.bat_nSe;

  /* Abs: '<S34>/Abs' */
  rtb_U_S = fabs(UNICARPTMotorCU_B->Gain_e);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S39>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_b.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_n.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_n.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_c = e->GetFunc(e->Var);
    }

    /* Memory: '<S38>/Memory10' */
    UNICARPTMotorCU_B->Memory10_n = UNICARPTMotorCU_DW->Memory10_PreviousInput_d;
  }

  /* Integrator: '<S39>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_fs != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_b = UNICARPTMotorCU_B->ReadCMDict_c;
  }

  /* Clock: '<S38>/Clock2' */
  UNICARPTMotorCU_B->Clock2_n = Clock2_tmp;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S38>/Memory7' */
    UNICARPTMotorCU_B->Memory7_o = UNICARPTMotorCU_DW->Memory7_PreviousInput_m;

    /* Memory: '<S38>/Memory9' */
    UNICARPTMotorCU_B->Memory9_n = UNICARPTMotorCU_DW->Memory9_PreviousInput_d;

    /* Memory: '<S38>/Memory8' */
    UNICARPTMotorCU_B->Memory8_m = UNICARPTMotorCU_DW->Memory8_PreviousInput_o;

    /* Memory: '<S38>/Memory11' */
    UNICARPTMotorCU_B->Memory11_g = UNICARPTMotorCU_DW->Memory11_PreviousInput_g;
  }

  /* Sum: '<S38>/Add1' */
  rtb_Add1_h = UNICARPTMotorCU_B->Clock2_n - UNICARPTMotorCU_B->Memory7_o;

  /* MATLAB Function: '<S38>/MATLAB Function' incorporates:
   *  Constant: '<S38>/Constant11'
   *  Constant: '<S38>/Constant12'
   *  Constant: '<S38>/Constant13'
   */
  UNICARPTMotorCU_MATLABFunction(UNICARPTMotorCU_B->Memory10_n,
    UNICARPTMotorCU_B->Divide_c, UNICARPTMotorCU_B->Clock2_n, rtb_Add1_h,
    UNICARPTMotorCU_P.bat_ICC_A, UNICARPTMotorCU_P.bat_IMax_A,
    UNICARPTMotorCU_P.bat_tBreak_s, UNICARPTMotorCU_B->Memory9_n,
    UNICARPTMotorCU_B->Memory8_m, UNICARPTMotorCU_B->Memory11_g,
    &UNICARPTMotorCU_B->sf_MATLABFunction_f);

  /* Lookup_n-D: '<S31>/Wirkungsgradkennfeld' incorporates:
   *  Abs: '<S31>/Abs1'
   *  Inport: '<Root>/FromCM'
   */
  rtb_R_SSOC = look2_binlxpw(fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m2.Trq),
    rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_M_Nm,
    UNICARPTMotorCU_P.mot_omega_rad_s, UNICARPTMotorCU_P.mot_eta,
    UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex_c, 14U);

  /* MinMax: '<S34>/Max2' incorporates:
   *  Constant: '<S34>/Constant4'
   */
  rtb_Product_p = fmax(UNICARPTMotorCU_P.Constant4_Value_ct, rtb_R_SSOC);

  /* Product: '<S34>/Product4' incorporates:
   *  Abs: '<S34>/Abs3'
   *  Constant: '<S34>/Constant3'
   *  Gain: '<S38>/Gain'
   *  Integrator: '<S39>/Integrator'
   *  Lookup_n-D: '<S38>/1-D Lookup Table'
   *  MinMax: '<S38>/Max'
   *  Product: '<S34>/Divide'
   *  Sum: '<S34>/Add3'
   *  Sum: '<S34>/Add4'
   */
  rtb_DataTypeConversion1 = (UNICARPTMotorCU_P.bat_nPar * fmin(look1_binlxpw
    (UNICARPTMotorCU_X->Integrator_CSTATE_b, UNICARPTMotorCU_P.bat_TLim_K,
     UNICARPTMotorCU_P.bat_ILim_A, 8U),
    UNICARPTMotorCU_B->sf_MATLABFunction_f.I_max) -
    UNICARPTMotorCU_B->IndexVector2_d / rtb_U_S) * rtb_U_S * rtb_Product_p /
    (rtb_C_SSOC_tmp + UNICARPTMotorCU_P.Constant3_Value_k);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S32>/Index Vector2' incorporates:
     *  Constant: '<S32>/Constant2'
     *  Constant: '<S4>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector2_l = UNICARPTMotorCU_P.bat_SOCMin[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_ey];
  }

  /* RelationalOperator: '<S32>/GreaterThan1' */
  rtb_GreaterThan = (UNICARPTMotorCU_B->SOC_j >=
                     UNICARPTMotorCU_B->IndexVector2_l);

  /* Product: '<S34>/Product9' incorporates:
   *  Abs: '<S34>/Abs3'
   *  DataTypeConversion: '<S34>/Data Type Conversion2'
   *  Lookup_n-D: '<S34>/Spitzenmoment Motor'
   *  Lookup_n-D: '<S34>/Spitzenmomentberechnung Motor'
   *  MinMax: '<S34>/Max1'
   *  Product: '<S34>/Product1'
   */
  UNICARPTMotorCU_B->Product9_m = fmin(look1_binlxpw(UNICARPTMotorCU_B->T_An_oc,
    UNICARPTMotorCU_P.mot_TMPeak_K, UNICARPTMotorCU_P.mot_weight_T, 3U) *
    look1_binlxpw(rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_omegaPeak_rad_s,
                  UNICARPTMotorCU_P.mot_MPeak_Nm, 5U), rtb_DataTypeConversion1) *
    (real_T)rtb_GreaterThan;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S4>/Write CM Dict' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict_PWORK_n.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict_IWORK_e.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict_IWORK_e.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product9_m;
      DVA_PokeSL(e, value);
    }
  }

  /* Product: '<S34>/Product8' incorporates:
   *  Abs: '<S34>/Abs3'
   *  DataTypeConversion: '<S34>/Data Type Conversion2'
   *  Lookup_n-D: '<S34>/Dauermoment Motor'
   *  MinMax: '<S34>/Max'
   */
  UNICARPTMotorCU_B->Product8_j = (real_T)rtb_GreaterThan * fmin
    (rtb_DataTypeConversion1, look1_binlxpw(rtb_C_SSOC_tmp,
      UNICARPTMotorCU_P.mot_omegaC_rad_s, UNICARPTMotorCU_P.mot_MC_Nm, 3U));
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S4>/Write CM Dict1' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict1_PWORK_c.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict1_IWORK_g.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict1_IWORK_g.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product8_j;
      DVA_PokeSL(e, value);
    }

    /* S-Function (write_dict): '<S4>/Write CM Dict2' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict2_PWORK_k.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict2_IWORK_c.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict2_IWORK_c.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->SOC_j;
      DVA_PokeSL(e, value);
    }

    /* S-Function (read_dict): '<S35>/Read CM Dict1' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict1_PWORK_e.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict1_IWORK_k.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict1_IWORK_k.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict1_c = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S35>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict4_PWORK_m.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict4_IWORK_c.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict4_IWORK_c.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict4_m = e->GetFunc(e->Var);
    }

    /* Sqrt: '<S35>/Sqrt1' incorporates:
     *  Math: '<S35>/Square2'
     *  Math: '<S35>/Square3'
     *  Sum: '<S35>/Add2'
     */
    UNICARPTMotorCU_B->v_Car_b = sqrt(UNICARPTMotorCU_B->ReadCMDict1_c *
      UNICARPTMotorCU_B->ReadCMDict1_c + UNICARPTMotorCU_B->ReadCMDict4_m *
      UNICARPTMotorCU_B->ReadCMDict4_m);

    /* Gain: '<S35>/Gain' incorporates:
     *  Constant: '<S35>/Constant8'
     */
    UNICARPTMotorCU_B->Gain_nd = UNICARPTMotorCU_P.Gain_Gain_d *
      UNICARPTMotorCU_P.MCU_r_m;
  }

  /* MATLAB Function: '<S35>/Calc alpha_An' incorporates:
   *  Constant: '<S35>/Constant10'
   *  Constant: '<S35>/Constant11'
   *  Constant: '<S35>/Constant9'
   */
  UNICARPTMotorCU_Calcalpha_An(UNICARPTMotorCU_B->v_Car_b,
    UNICARPTMotorCU_B->Gain_nd, UNICARPTMotorCU_P.MCU_nue_Ns_m_2,
    UNICARPTMotorCU_P.MCU_Pr, UNICARPTMotorCU_P.MCU_alpha_m_2_s,
    UNICARPTMotorCU_B->T_An_oc, UNICARPTMotorCU_B->ReadCMDict_p,
    &UNICARPTMotorCU_B->sf_Calcalpha_An_d);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Product: '<S35>/Product2' incorporates:
     *  Constant: '<S35>/Constant4'
     *  Constant: '<S37>/Constant'
     *  Memory: '<S35>/Memory'
     *  RelationalOperator: '<S37>/Compare'
     */
    UNICARPTMotorCU_B->q_kuehl_m = (real_T)
      (UNICARPTMotorCU_DW->Memory_PreviousInput_j >=
       UNICARPTMotorCU_P.CompareToConstant_const_d) * UNICARPTMotorCU_P.MCU_q_W;

    /* Product: '<S35>/Product' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     */
    UNICARPTMotorCU_B->Product_e = UNICARPTMotorCU_P.MCU_m_kg *
      UNICARPTMotorCU_P.MCU_cp_J_kgK;

    /* MultiPortSwitch: '<S32>/Index Vector1' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S4>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector1_e = UNICARPTMotorCU_P.bat_SOCMax[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_ey];
  }

  /* Product: '<S35>/Divide' incorporates:
   *  Abs: '<S31>/Abs3'
   *  Constant: '<S31>/Constant'
   *  Constant: '<S35>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S31>/Product'
   *  Product: '<S31>/Product3'
   *  Product: '<S35>/Product1'
   *  Sum: '<S31>/Add'
   *  Sum: '<S35>/Add'
   *  Sum: '<S35>/Sum'
   *  Sum: '<S35>/Sum1'
   */
  UNICARPTMotorCU_B->dT_An_l = (((UNICARPTMotorCU_P.Constant_Value_ea -
    rtb_R_SSOC) * fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m2.rotv *
                       UNICARPTMotorCU_U->FromCM.MotorIn.m2.Trq) -
    UNICARPTMotorCU_B->sf_Calcalpha_An_d.alpha_An *
    UNICARPTMotorCU_P.MCU_area_m_2 * (UNICARPTMotorCU_B->T_An_oc -
    UNICARPTMotorCU_B->ReadCMDict_p)) - UNICARPTMotorCU_B->q_kuehl_m) /
    UNICARPTMotorCU_B->Product_e;

  /* Product: '<S38>/Divide2' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Lookup_n-D: '<S38>/1-D Lookup Table1'
   */
  rtb_Divide2_lm = 1.0 / look1_binlxpw(UNICARPTMotorCU_B->Divide_c,
    UNICARPTMotorCU_P.bat_ItMax_A, UNICARPTMotorCU_P.bat_KtMax, 4U) *
    UNICARPTMotorCU_P.bat_tIMax_s;

  /* Outputs for Resettable SubSystem: '<S38>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem(UNICARPTMotorCU_M, rtb_Divide2_lm,
    UNICARPTMotorCU_B->sf_MATLABFunction_f.trigger,
    &UNICARPTMotorCU_B->ResettableSubsystem_nm,
    &UNICARPTMotorCU_DW->ResettableSubsystem_nm, &UNICARPTMotorCU_P,
    &UNICARPTMotorCU_PrevZCX->ResettableSubsystem_nm);

  /* End of Outputs for SubSystem: '<S38>/Resettable Subsystem' */

  /* Fcn: '<S33>/C_L(SOC)' incorporates:
   *  Constant: '<S33>/Constant2'
   */
  rtb_R_SSOC = exp(UNICARPTMotorCU_P.bat_C1_F[1] * UNICARPTMotorCU_B->SOC_j) *
    UNICARPTMotorCU_P.bat_C1_F[0] + UNICARPTMotorCU_P.bat_C1_F[2];

  /* Fcn: '<S33>/C_S(SOC)' incorporates:
   *  Constant: '<S33>/Constant3'
   */
  rtb_DataTypeConversion1 = exp(UNICARPTMotorCU_P.bat_C2_F[1] *
    UNICARPTMotorCU_B->SOC_j) * UNICARPTMotorCU_P.bat_C2_F[0] +
    UNICARPTMotorCU_P.bat_C2_F[2];
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S33>/Index Vector2' incorporates:
     *  Constant: '<S33>/Constant10'
     *  Constant: '<S4>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector2_i = UNICARPTMotorCU_P.bat_P_W[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_ey];

    /* Product: '<S39>/Product3' incorporates:
     *  Constant: '<S39>/Constant4'
     *  Constant: '<S39>/Constant5'
     */
    UNICARPTMotorCU_B->Product3_e = UNICARPTMotorCU_P.bat_area_m_2 *
      UNICARPTMotorCU_P.bat_alpha_W_Km_2;
  }

  /* Sum: '<S33>/Sum' incorporates:
   *  Constant: '<S33>/Constant6'
   *  Fcn: '<S33>/R_L(SOC)'
   *  Integrator: '<S33>/Integrator'
   *  Product: '<S33>/Divide1'
   *  Product: '<S33>/Product'
   *  Product: '<S33>/Product1'
   */
  UNICARPTMotorCU_B->Sum_e = UNICARPTMotorCU_B->Divide_c / rtb_R_SSOC -
    UNICARPTMotorCU_X->Integrator_CSTATE_ga / ((exp
    (UNICARPTMotorCU_P.bat_R1_Ohm[1] * UNICARPTMotorCU_B->SOC_j) *
    UNICARPTMotorCU_P.bat_R1_Ohm[0] + UNICARPTMotorCU_P.bat_R1_Ohm[2]) *
    rtb_R_SSOC);

  /* Sum: '<S33>/Sum2' incorporates:
   *  Constant: '<S33>/Constant4'
   *  Fcn: '<S33>/R_S(SOC)'
   *  Integrator: '<S33>/Integrator1'
   *  Product: '<S33>/Divide2'
   *  Product: '<S33>/Product2'
   *  Product: '<S33>/Product3'
   */
  UNICARPTMotorCU_B->Sum2_c = UNICARPTMotorCU_B->Divide_c /
    rtb_DataTypeConversion1 - UNICARPTMotorCU_X->Integrator1_CSTATE_n / ((exp
    (UNICARPTMotorCU_P.bat_R2_Ohm[1] * UNICARPTMotorCU_B->SOC_j) *
    UNICARPTMotorCU_P.bat_R2_Ohm[0] + UNICARPTMotorCU_P.bat_R2_Ohm[2]) *
    rtb_DataTypeConversion1);

  /* Product: '<S39>/Product2' incorporates:
   *  Abs: '<S33>/Abs'
   *  Abs: '<S33>/Abs1'
   *  Constant: '<S33>/Constant12'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/Constant2'
   *  Gain: '<S33>/Gain1'
   *  Integrator: '<S39>/Integrator'
   *  Product: '<S33>/Product5'
   *  Product: '<S39>/Product'
   *  Product: '<S39>/Product1'
   *  Sum: '<S33>/Add1'
   *  Sum: '<S39>/Add'
   *  Sum: '<S39>/Sum1'
   */
  UNICARPTMotorCU_B->Product2_b = ((fabs(UNICARPTMotorCU_P.bat_nSe * rtb_Memory
    - UNICARPTMotorCU_B->Gain_e) * fabs(UNICARPTMotorCU_B->Divide_c *
    UNICARPTMotorCU_P.bat_nPar) + UNICARPTMotorCU_P.bat_q_W) -
    (UNICARPTMotorCU_X->Integrator_CSTATE_b - UNICARPTMotorCU_B->ReadCMDict_c) *
    UNICARPTMotorCU_B->Product3_e) / UNICARPTMotorCU_P.bat_m_kg /
    UNICARPTMotorCU_P.bat_cp_J_kgK;

  /* Product: '<S34>/Product' incorporates:
   *  Abs: '<S34>/Abs3'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/Constant2'
   *  Sum: '<S34>/Add1'
   */
  rtb_Product_p = 1.0 / rtb_Product_p * rtb_U_S *
    UNICARPTMotorCU_P.bat_ILoadMax_A / (rtb_C_SSOC_tmp +
    UNICARPTMotorCU_P.Constant2_Value_kc);

  /* Product: '<S34>/Product2' incorporates:
   *  Abs: '<S34>/Abs3'
   *  DataTypeConversion: '<S34>/Data Type Conversion1'
   *  Lookup_n-D: '<S34>/1-D Lookup Table'
   *  MinMax: '<S34>/Min'
   *  RelationalOperator: '<S32>/GreaterThan'
   */
  UNICARPTMotorCU_B->Product2_j = (real_T)(UNICARPTMotorCU_B->IndexVector1_e >=
    UNICARPTMotorCU_B->SOC_j) * fmin(look1_binlxpw(rtb_C_SSOC_tmp,
    UNICARPTMotorCU_P.mot_omegaMaxReg_rad_s, UNICARPTMotorCU_P.mot_MMaxReg_Nm,
    8U), rtb_Product_p);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S47>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_f.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_i.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_i.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_l = e->GetFunc(e->Var);
    }
  }

  /* Integrator: '<S47>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_fg != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_ci = UNICARPTMotorCU_B->ReadCMDict_l;
  }

  UNICARPTMotorCU_B->T_An_n = UNICARPTMotorCU_X->Integrator_CSTATE_ci;

  /* End of Integrator: '<S47>/Integrator' */

  /* Abs: '<S46>/Abs3' incorporates:
   *  Abs: '<S43>/Abs2'
   *  Inport: '<Root>/FromCM'
   */
  rtb_C_SSOC_tmp = fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m3.rotv);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S46>/Index Vector2' incorporates:
     *  Constant: '<S46>/Constant10'
     *  Constant: '<S5>/Constant'
     *  MultiPortSwitch: '<S45>/Index Vector'
     *  MultiPortSwitch: '<S45>/Index Vector1'
     */
    IndexVector2_tmp = (int32_T)UNICARPTMotorCU_P.Constant_Value_fi;
    UNICARPTMotorCU_B->IndexVector2_n =
      UNICARPTMotorCU_P.bat_P_W[IndexVector2_tmp];

    /* MultiPortSwitch: '<S45>/Index Vector' incorporates:
     *  Constant: '<S45>/Constant1'
     */
    UNICARPTMotorCU_B->IndexVector_f =
      UNICARPTMotorCU_P.bat_Call_F[IndexVector2_tmp];

    /* Product: '<S45>/Product4' incorporates:
     *  Constant: '<S45>/Constant'
     *  MultiPortSwitch: '<S45>/Index Vector1'
     */
    UNICARPTMotorCU_B->Product4_bm =
      UNICARPTMotorCU_P.bat_SOCini[IndexVector2_tmp] *
      UNICARPTMotorCU_B->IndexVector_f;
  }

  /* Integrator: '<S45>/Integrator2' */
  if (UNICARPTMotorCU_DW->Integrator2_IWORK_d != 0) {
    UNICARPTMotorCU_X->Integrator2_CSTATE_k = UNICARPTMotorCU_B->Product4_bm;
  }

  /* Product: '<S45>/Divide3' incorporates:
   *  Integrator: '<S45>/Integrator2'
   */
  UNICARPTMotorCU_B->SOC_c = UNICARPTMotorCU_X->Integrator2_CSTATE_k /
    UNICARPTMotorCU_B->IndexVector_f;

  /* Fcn: '<S45>/U_OC(SOC)' incorporates:
   *  Constant: '<S45>/Constant7'
   */
  rtb_Memory = (((exp(UNICARPTMotorCU_P.bat_Uoc_V[1] * UNICARPTMotorCU_B->SOC_c)
                  * UNICARPTMotorCU_P.bat_Uoc_V[0] +
                  UNICARPTMotorCU_P.bat_Uoc_V[2]) + UNICARPTMotorCU_P.bat_Uoc_V
                 [3] * UNICARPTMotorCU_B->SOC_c) + UNICARPTMotorCU_P.bat_Uoc_V[4]
                * rt_powd_snf(UNICARPTMotorCU_B->SOC_c, 2.0)) +
    UNICARPTMotorCU_P.bat_Uoc_V[5] * rt_powd_snf(UNICARPTMotorCU_B->SOC_c, 3.0);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S45>/Memory' */
    rtb_Product_p = UNICARPTMotorCU_DW->Memory_PreviousInput_h;

    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S45>/Numerische Stabilität'
     *  Sum: '<S45>/Add2'
     */
    if (rtb_Product_p > UNICARPTMotorCU_P.Switch_Threshold_f) {
      UNICARPTMotorCU_B->Switch_f = rtb_Product_p;
    } else {
      UNICARPTMotorCU_B->Switch_f = rtb_Product_p +
        UNICARPTMotorCU_P.NumerischeStabilitt_Value_k;
    }

    /* End of Switch: '<S45>/Switch' */
  }

  /* Product: '<S45>/Divide' incorporates:
   *  Constant: '<S45>/Constant11'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S45>/Divide6'
   *  Sum: '<S45>/Add'
   *  TransferFcn: '<S45>/Transfer Fcn'
   */
  UNICARPTMotorCU_B->Divide_j = (UNICARPTMotorCU_U->FromCM.MotorIn.m3.PwrElec -
    UNICARPTMotorCU_P.TransferFcn_C_cc * UNICARPTMotorCU_X->TransferFcn_CSTATE_n)
    / UNICARPTMotorCU_B->Switch_f / UNICARPTMotorCU_P.bat_nPar;

  /* Gain: '<S45>/Gain' incorporates:
   *  Constant: '<S45>/Constant5'
   *  Fcn: '<S45>/Fcn'
   *  Fcn: '<S45>/R_Series(SOC)'
   *  Integrator: '<S45>/Integrator'
   *  Integrator: '<S45>/Integrator1'
   *  Sum: '<S45>/Sum1'
   */
  UNICARPTMotorCU_B->Gain_by = ((exp(UNICARPTMotorCU_P.bat_R_Ohm[1] *
    UNICARPTMotorCU_B->SOC_c) * UNICARPTMotorCU_P.bat_R_Ohm[0] +
    UNICARPTMotorCU_P.bat_R_Ohm[2]) * UNICARPTMotorCU_B->Divide_j + ((rtb_Memory
    + UNICARPTMotorCU_X->Integrator_CSTATE_jg) +
    UNICARPTMotorCU_X->Integrator1_CSTATE_b)) * UNICARPTMotorCU_P.bat_nSe;

  /* Abs: '<S46>/Abs' */
  rtb_U_S = fabs(UNICARPTMotorCU_B->Gain_by);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (read_dict): '<S51>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict_PWORK_nq.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict_IWORK_c.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict_IWORK_c.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict_j = e->GetFunc(e->Var);
    }

    /* Memory: '<S50>/Memory10' */
    UNICARPTMotorCU_B->Memory10_f = UNICARPTMotorCU_DW->Memory10_PreviousInput_n;
  }

  /* Integrator: '<S51>/Integrator' */
  if (UNICARPTMotorCU_DW->Integrator_IWORK_fq != 0) {
    UNICARPTMotorCU_X->Integrator_CSTATE_m = UNICARPTMotorCU_B->ReadCMDict_j;
  }

  /* Clock: '<S50>/Clock2' */
  UNICARPTMotorCU_B->Clock2_b1 = Clock2_tmp;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Memory: '<S50>/Memory7' */
    UNICARPTMotorCU_B->Memory7_e = UNICARPTMotorCU_DW->Memory7_PreviousInput_l;

    /* Memory: '<S50>/Memory9' */
    UNICARPTMotorCU_B->Memory9_c = UNICARPTMotorCU_DW->Memory9_PreviousInput_h;

    /* Memory: '<S50>/Memory8' */
    UNICARPTMotorCU_B->Memory8_o = UNICARPTMotorCU_DW->Memory8_PreviousInput_d;

    /* Memory: '<S50>/Memory11' */
    UNICARPTMotorCU_B->Memory11_a =
      UNICARPTMotorCU_DW->Memory11_PreviousInput_gv;
  }

  /* Sum: '<S50>/Add1' */
  rtb_Add1_c = UNICARPTMotorCU_B->Clock2_b1 - UNICARPTMotorCU_B->Memory7_e;

  /* MATLAB Function: '<S50>/MATLAB Function' incorporates:
   *  Constant: '<S50>/Constant11'
   *  Constant: '<S50>/Constant12'
   *  Constant: '<S50>/Constant13'
   */
  UNICARPTMotorCU_MATLABFunction(UNICARPTMotorCU_B->Memory10_f,
    UNICARPTMotorCU_B->Divide_j, UNICARPTMotorCU_B->Clock2_b1, rtb_Add1_c,
    UNICARPTMotorCU_P.bat_ICC_A, UNICARPTMotorCU_P.bat_IMax_A,
    UNICARPTMotorCU_P.bat_tBreak_s, UNICARPTMotorCU_B->Memory9_c,
    UNICARPTMotorCU_B->Memory8_o, UNICARPTMotorCU_B->Memory11_a,
    &UNICARPTMotorCU_B->sf_MATLABFunction_ad);

  /* Lookup_n-D: '<S43>/Wirkungsgradkennfeld' incorporates:
   *  Abs: '<S43>/Abs1'
   *  Inport: '<Root>/FromCM'
   */
  rtb_R_SSOC = look2_binlxpw(fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m3.Trq),
    rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_M_Nm,
    UNICARPTMotorCU_P.mot_omega_rad_s, UNICARPTMotorCU_P.mot_eta,
    UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex_j, 14U);

  /* MinMax: '<S46>/Max2' incorporates:
   *  Constant: '<S46>/Constant4'
   */
  rtb_Product_p = fmax(UNICARPTMotorCU_P.Constant4_Value_e, rtb_R_SSOC);

  /* Product: '<S46>/Product4' incorporates:
   *  Abs: '<S46>/Abs3'
   *  Constant: '<S46>/Constant3'
   *  Gain: '<S50>/Gain'
   *  Integrator: '<S51>/Integrator'
   *  Lookup_n-D: '<S50>/1-D Lookup Table'
   *  MinMax: '<S50>/Max'
   *  Product: '<S46>/Divide'
   *  Sum: '<S46>/Add3'
   *  Sum: '<S46>/Add4'
   */
  rtb_DataTypeConversion1 = (UNICARPTMotorCU_P.bat_nPar * fmin(look1_binlxpw
    (UNICARPTMotorCU_X->Integrator_CSTATE_m, UNICARPTMotorCU_P.bat_TLim_K,
     UNICARPTMotorCU_P.bat_ILim_A, 8U),
    UNICARPTMotorCU_B->sf_MATLABFunction_ad.I_max) -
    UNICARPTMotorCU_B->IndexVector2_n / rtb_U_S) * rtb_U_S * rtb_Product_p /
    (rtb_C_SSOC_tmp + UNICARPTMotorCU_P.Constant3_Value_i);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S44>/Index Vector2' incorporates:
     *  Constant: '<S44>/Constant2'
     *  Constant: '<S5>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector2_jk = UNICARPTMotorCU_P.bat_SOCMin[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_fi];
  }

  /* RelationalOperator: '<S44>/GreaterThan1' */
  rtb_GreaterThan = (UNICARPTMotorCU_B->SOC_c >=
                     UNICARPTMotorCU_B->IndexVector2_jk);

  /* Product: '<S46>/Product9' incorporates:
   *  Abs: '<S46>/Abs3'
   *  DataTypeConversion: '<S46>/Data Type Conversion2'
   *  Lookup_n-D: '<S46>/Spitzenmoment Motor'
   *  Lookup_n-D: '<S46>/Spitzenmomentberechnung Motor'
   *  MinMax: '<S46>/Max1'
   *  Product: '<S46>/Product1'
   */
  UNICARPTMotorCU_B->Product9_mz = fmin(look1_binlxpw(UNICARPTMotorCU_B->T_An_n,
    UNICARPTMotorCU_P.mot_TMPeak_K, UNICARPTMotorCU_P.mot_weight_T, 3U) *
    look1_binlxpw(rtb_C_SSOC_tmp, UNICARPTMotorCU_P.mot_omegaPeak_rad_s,
                  UNICARPTMotorCU_P.mot_MPeak_Nm, 5U), rtb_DataTypeConversion1) *
    (real_T)rtb_GreaterThan;
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S5>/Write CM Dict' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict_PWORK_a2.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict_IWORK_c.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict_IWORK_c.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product9_mz;
      DVA_PokeSL(e, value);
    }
  }

  /* Product: '<S46>/Product8' incorporates:
   *  Abs: '<S46>/Abs3'
   *  DataTypeConversion: '<S46>/Data Type Conversion2'
   *  Lookup_n-D: '<S46>/Dauermoment Motor'
   *  MinMax: '<S46>/Max'
   */
  UNICARPTMotorCU_B->Product8_c = (real_T)rtb_GreaterThan * fmin
    (rtb_DataTypeConversion1, look1_binlxpw(rtb_C_SSOC_tmp,
      UNICARPTMotorCU_P.mot_omegaC_rad_s, UNICARPTMotorCU_P.mot_MC_Nm, 3U));
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* S-Function (write_dict): '<S5>/Write CM Dict1' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict1_PWORK_i.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict1_IWORK_m.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict1_IWORK_m.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->Product8_c;
      DVA_PokeSL(e, value);
    }

    /* S-Function (write_dict): '<S5>/Write CM Dict2' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->WriteCMDict2_PWORK_f.Entry;
      if (!UNICARPTMotorCU_DW->WriteCMDict2_IWORK_d.Checked) {
        UNICARPTMotorCU_DW->WriteCMDict2_IWORK_d.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      value = UNICARPTMotorCU_B->SOC_c;
      DVA_PokeSL(e, value);
    }

    /* S-Function (read_dict): '<S47>/Read CM Dict1' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict1_PWORK_k.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict1_IWORK_kx.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict1_IWORK_kx.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict1_a = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S47>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARPTMotorCU_DW->ReadCMDict4_PWORK_c.Entry;
      if (!UNICARPTMotorCU_DW->ReadCMDict4_IWORK_h.Checked) {
        UNICARPTMotorCU_DW->ReadCMDict4_IWORK_h.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARPTMotorCU'");
      }

      UNICARPTMotorCU_B->ReadCMDict4_h = e->GetFunc(e->Var);
    }

    /* Sqrt: '<S47>/Sqrt1' incorporates:
     *  Math: '<S47>/Square2'
     *  Math: '<S47>/Square3'
     *  Sum: '<S47>/Add2'
     */
    UNICARPTMotorCU_B->v_Car_d = sqrt(UNICARPTMotorCU_B->ReadCMDict1_a *
      UNICARPTMotorCU_B->ReadCMDict1_a + UNICARPTMotorCU_B->ReadCMDict4_h *
      UNICARPTMotorCU_B->ReadCMDict4_h);

    /* Gain: '<S47>/Gain' incorporates:
     *  Constant: '<S47>/Constant8'
     */
    UNICARPTMotorCU_B->Gain_a = UNICARPTMotorCU_P.Gain_Gain_l *
      UNICARPTMotorCU_P.MCU_r_m;
  }

  /* MATLAB Function: '<S47>/Calc alpha_An' incorporates:
   *  Constant: '<S47>/Constant10'
   *  Constant: '<S47>/Constant11'
   *  Constant: '<S47>/Constant9'
   */
  UNICARPTMotorCU_Calcalpha_An(UNICARPTMotorCU_B->v_Car_d,
    UNICARPTMotorCU_B->Gain_a, UNICARPTMotorCU_P.MCU_nue_Ns_m_2,
    UNICARPTMotorCU_P.MCU_Pr, UNICARPTMotorCU_P.MCU_alpha_m_2_s,
    UNICARPTMotorCU_B->T_An_n, UNICARPTMotorCU_B->ReadCMDict_l,
    &UNICARPTMotorCU_B->sf_Calcalpha_An_g);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Product: '<S47>/Product2' incorporates:
     *  Constant: '<S47>/Constant4'
     *  Constant: '<S49>/Constant'
     *  Memory: '<S47>/Memory'
     *  RelationalOperator: '<S49>/Compare'
     */
    UNICARPTMotorCU_B->q_kuehl_n = (real_T)
      (UNICARPTMotorCU_DW->Memory_PreviousInput_k >=
       UNICARPTMotorCU_P.CompareToConstant_const_h) * UNICARPTMotorCU_P.MCU_q_W;

    /* Product: '<S47>/Product' incorporates:
     *  Constant: '<S47>/Constant'
     *  Constant: '<S47>/Constant1'
     */
    UNICARPTMotorCU_B->Product_e1 = UNICARPTMotorCU_P.MCU_m_kg *
      UNICARPTMotorCU_P.MCU_cp_J_kgK;

    /* MultiPortSwitch: '<S44>/Index Vector1' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S5>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector1_gb = UNICARPTMotorCU_P.bat_SOCMax[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_fi];
  }

  /* Product: '<S47>/Divide' incorporates:
   *  Abs: '<S43>/Abs3'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S47>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S43>/Product'
   *  Product: '<S43>/Product3'
   *  Product: '<S47>/Product1'
   *  Sum: '<S43>/Add'
   *  Sum: '<S47>/Add'
   *  Sum: '<S47>/Sum'
   *  Sum: '<S47>/Sum1'
   */
  UNICARPTMotorCU_B->dT_An_b = (((UNICARPTMotorCU_P.Constant_Value_fd -
    rtb_R_SSOC) * fabs(UNICARPTMotorCU_U->FromCM.MotorIn.m3.rotv *
                       UNICARPTMotorCU_U->FromCM.MotorIn.m3.Trq) -
    UNICARPTMotorCU_B->sf_Calcalpha_An_g.alpha_An *
    UNICARPTMotorCU_P.MCU_area_m_2 * (UNICARPTMotorCU_B->T_An_n -
    UNICARPTMotorCU_B->ReadCMDict_l)) - UNICARPTMotorCU_B->q_kuehl_n) /
    UNICARPTMotorCU_B->Product_e1;

  /* Product: '<S50>/Divide2' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Lookup_n-D: '<S50>/1-D Lookup Table1'
   */
  rtb_Divide2_o = 1.0 / look1_binlxpw(UNICARPTMotorCU_B->Divide_j,
    UNICARPTMotorCU_P.bat_ItMax_A, UNICARPTMotorCU_P.bat_KtMax, 4U) *
    UNICARPTMotorCU_P.bat_tIMax_s;

  /* Outputs for Resettable SubSystem: '<S50>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem(UNICARPTMotorCU_M, rtb_Divide2_o,
    UNICARPTMotorCU_B->sf_MATLABFunction_ad.trigger,
    &UNICARPTMotorCU_B->ResettableSubsystem_f,
    &UNICARPTMotorCU_DW->ResettableSubsystem_f, &UNICARPTMotorCU_P,
    &UNICARPTMotorCU_PrevZCX->ResettableSubsystem_f);

  /* End of Outputs for SubSystem: '<S50>/Resettable Subsystem' */

  /* Fcn: '<S45>/C_L(SOC)' incorporates:
   *  Constant: '<S45>/Constant2'
   */
  rtb_R_SSOC = exp(UNICARPTMotorCU_P.bat_C1_F[1] * UNICARPTMotorCU_B->SOC_c) *
    UNICARPTMotorCU_P.bat_C1_F[0] + UNICARPTMotorCU_P.bat_C1_F[2];

  /* Fcn: '<S45>/C_S(SOC)' incorporates:
   *  Constant: '<S45>/Constant3'
   */
  rtb_DataTypeConversion1 = exp(UNICARPTMotorCU_P.bat_C2_F[1] *
    UNICARPTMotorCU_B->SOC_c) * UNICARPTMotorCU_P.bat_C2_F[0] +
    UNICARPTMotorCU_P.bat_C2_F[2];
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* MultiPortSwitch: '<S45>/Index Vector2' incorporates:
     *  Constant: '<S45>/Constant10'
     *  Constant: '<S5>/Constant'
     */
    UNICARPTMotorCU_B->IndexVector2_g = UNICARPTMotorCU_P.bat_P_W[(int32_T)
      UNICARPTMotorCU_P.Constant_Value_fi];

    /* Product: '<S51>/Product3' incorporates:
     *  Constant: '<S51>/Constant4'
     *  Constant: '<S51>/Constant5'
     */
    UNICARPTMotorCU_B->Product3_j = UNICARPTMotorCU_P.bat_area_m_2 *
      UNICARPTMotorCU_P.bat_alpha_W_Km_2;
  }

  /* Sum: '<S45>/Sum' incorporates:
   *  Constant: '<S45>/Constant6'
   *  Fcn: '<S45>/R_L(SOC)'
   *  Integrator: '<S45>/Integrator'
   *  Product: '<S45>/Divide1'
   *  Product: '<S45>/Product'
   *  Product: '<S45>/Product1'
   */
  UNICARPTMotorCU_B->Sum_e5 = UNICARPTMotorCU_B->Divide_j / rtb_R_SSOC -
    UNICARPTMotorCU_X->Integrator_CSTATE_jg / ((exp
    (UNICARPTMotorCU_P.bat_R1_Ohm[1] * UNICARPTMotorCU_B->SOC_c) *
    UNICARPTMotorCU_P.bat_R1_Ohm[0] + UNICARPTMotorCU_P.bat_R1_Ohm[2]) *
    rtb_R_SSOC);

  /* Sum: '<S45>/Sum2' incorporates:
   *  Constant: '<S45>/Constant4'
   *  Fcn: '<S45>/R_S(SOC)'
   *  Integrator: '<S45>/Integrator1'
   *  Product: '<S45>/Divide2'
   *  Product: '<S45>/Product2'
   *  Product: '<S45>/Product3'
   */
  UNICARPTMotorCU_B->Sum2_h = UNICARPTMotorCU_B->Divide_j /
    rtb_DataTypeConversion1 - UNICARPTMotorCU_X->Integrator1_CSTATE_b / ((exp
    (UNICARPTMotorCU_P.bat_R2_Ohm[1] * UNICARPTMotorCU_B->SOC_c) *
    UNICARPTMotorCU_P.bat_R2_Ohm[0] + UNICARPTMotorCU_P.bat_R2_Ohm[2]) *
    rtb_DataTypeConversion1);

  /* Product: '<S51>/Product2' incorporates:
   *  Abs: '<S45>/Abs'
   *  Abs: '<S45>/Abs1'
   *  Constant: '<S45>/Constant12'
   *  Constant: '<S51>/Constant'
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S51>/Constant2'
   *  Gain: '<S45>/Gain1'
   *  Integrator: '<S51>/Integrator'
   *  Product: '<S45>/Product5'
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S51>/Add'
   *  Sum: '<S51>/Sum1'
   */
  UNICARPTMotorCU_B->Product2_c = ((fabs(UNICARPTMotorCU_P.bat_nSe * rtb_Memory
    - UNICARPTMotorCU_B->Gain_by) * fabs(UNICARPTMotorCU_B->Divide_j *
    UNICARPTMotorCU_P.bat_nPar) + UNICARPTMotorCU_P.bat_q_W) -
    (UNICARPTMotorCU_X->Integrator_CSTATE_m - UNICARPTMotorCU_B->ReadCMDict_j) *
    UNICARPTMotorCU_B->Product3_j) / UNICARPTMotorCU_P.bat_m_kg /
    UNICARPTMotorCU_P.bat_cp_J_kgK;

  /* Product: '<S46>/Product' incorporates:
   *  Abs: '<S46>/Abs3'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S46>/Constant2'
   *  Sum: '<S46>/Add1'
   */
  rtb_Product_p = 1.0 / rtb_Product_p * rtb_U_S *
    UNICARPTMotorCU_P.bat_ILoadMax_A / (rtb_C_SSOC_tmp +
    UNICARPTMotorCU_P.Constant2_Value_o);

  /* Product: '<S46>/Product2' incorporates:
   *  Abs: '<S46>/Abs3'
   *  DataTypeConversion: '<S46>/Data Type Conversion1'
   *  Lookup_n-D: '<S46>/1-D Lookup Table'
   *  MinMax: '<S46>/Min'
   *  RelationalOperator: '<S44>/GreaterThan'
   */
  UNICARPTMotorCU_B->Product2_e = (real_T)(UNICARPTMotorCU_B->IndexVector1_gb >=
    UNICARPTMotorCU_B->SOC_c) * fmin(look1_binlxpw(rtb_C_SSOC_tmp,
    UNICARPTMotorCU_P.mot_omegaMaxReg_rad_s, UNICARPTMotorCU_P.mot_MMaxReg_Nm,
    8U), rtb_Product_p);
  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Constant: '<S1>/ISGOut.Load'
     *  Constant: '<S1>/ISGOut.TrqGen_max'
     *  Constant: '<S1>/ISGOut.TrqMot_max'
     */
    UNICARPTMotorCU_Y->ToCM.ISGOut.Load = UNICARPTMotorCU_P.ISGOutLoad_Value;
    UNICARPTMotorCU_Y->ToCM.ISGOut.TrqMot_max =
      UNICARPTMotorCU_P.ISGOutTrqMot_max_Value;
    UNICARPTMotorCU_Y->ToCM.ISGOut.TrqGen_max =
      UNICARPTMotorCU_P.ISGOutTrqGen_max_Value;

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARPTMotorCU_Y->ToCM.MotorOut.m0.Load =
      UNICARPTMotorCU_U->FromCM.MotorIn.m0.Trq_trg;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m0.TrqMot_max = UNICARPTMotorCU_B->Product9;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m0.TrqGen_max =
      UNICARPTMotorCU_B->Product2_a;

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARPTMotorCU_Y->ToCM.MotorOut.m1.Load =
      UNICARPTMotorCU_U->FromCM.MotorIn.m1.Trq_trg;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m1.TrqMot_max =
      UNICARPTMotorCU_B->Product9_n;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m1.TrqGen_max =
      UNICARPTMotorCU_B->Product2_o;

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARPTMotorCU_Y->ToCM.MotorOut.m2.Load =
      UNICARPTMotorCU_U->FromCM.MotorIn.m2.Trq_trg;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m2.TrqMot_max =
      UNICARPTMotorCU_B->Product9_m;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m2.TrqGen_max =
      UNICARPTMotorCU_B->Product2_j;

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARPTMotorCU_Y->ToCM.MotorOut.m3.Load =
      UNICARPTMotorCU_U->FromCM.MotorIn.m3.Trq_trg;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m3.TrqMot_max =
      UNICARPTMotorCU_B->Product9_mz;
    UNICARPTMotorCU_Y->ToCM.MotorOut.m3.TrqGen_max =
      UNICARPTMotorCU_B->Product2_e;

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Constant: '<S1>/Status'
     *  Outport: '<Root>/ToCM'
     */
    UNICARPTMotorCU_Y->ToCM.Status = UNICARPTMotorCU_P.Status_Value;
  }

  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    /* Update for Integrator: '<S11>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK = 0;

    /* Update for Integrator: '<S9>/Integrator2' */
    UNICARPTMotorCU_DW->Integrator2_IWORK = 0;
    if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
      /* Update for Memory: '<S9>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput = UNICARPTMotorCU_B->Gain;

      /* Update for Memory: '<S14>/Memory10' */
      UNICARPTMotorCU_DW->Memory10_PreviousInput =
        UNICARPTMotorCU_B->ResettableSubsystem.Min;

      /* Update for Memory: '<S14>/Memory7' */
      UNICARPTMotorCU_DW->Memory7_PreviousInput = UNICARPTMotorCU_B->Clock2;

      /* Update for Memory: '<S14>/Memory9' */
      UNICARPTMotorCU_DW->Memory9_PreviousInput =
        UNICARPTMotorCU_B->sf_MATLABFunction.t_mem1;

      /* Update for Memory: '<S14>/Memory8' */
      UNICARPTMotorCU_DW->Memory8_PreviousInput =
        UNICARPTMotorCU_B->sf_MATLABFunction.t_mem2;

      /* Update for Memory: '<S14>/Memory11' */
      UNICARPTMotorCU_DW->Memory11_PreviousInput =
        UNICARPTMotorCU_B->sf_MATLABFunction.m1;

      /* Update for Memory: '<S11>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_b = UNICARPTMotorCU_B->T_An;
    }

    /* Update for Integrator: '<S15>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_m = 0;

    /* Update for Resettable SubSystem: '<S14>/Resettable Subsystem' */
    UNICARPTMotorCU_ResettableSubsystem_Update(UNICARPTMotorCU_M,
      &UNICARPTMotorCU_B->ResettableSubsystem,
      &UNICARPTMotorCU_DW->ResettableSubsystem);

    /* End of Update for SubSystem: '<S14>/Resettable Subsystem' */

    /* Update for Integrator: '<S23>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_f = 0;

    /* Update for Integrator: '<S21>/Integrator2' */
    UNICARPTMotorCU_DW->Integrator2_IWORK_g = 0;
    if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
      /* Update for Memory: '<S21>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_bq = UNICARPTMotorCU_B->Gain_b;

      /* Update for Memory: '<S26>/Memory10' */
      UNICARPTMotorCU_DW->Memory10_PreviousInput_m =
        UNICARPTMotorCU_B->ResettableSubsystem_n.Min;

      /* Update for Memory: '<S26>/Memory7' */
      UNICARPTMotorCU_DW->Memory7_PreviousInput_g = UNICARPTMotorCU_B->Clock2_b;

      /* Update for Memory: '<S26>/Memory9' */
      UNICARPTMotorCU_DW->Memory9_PreviousInput_o =
        UNICARPTMotorCU_B->sf_MATLABFunction_a.t_mem1;

      /* Update for Memory: '<S26>/Memory8' */
      UNICARPTMotorCU_DW->Memory8_PreviousInput_m =
        UNICARPTMotorCU_B->sf_MATLABFunction_a.t_mem2;

      /* Update for Memory: '<S26>/Memory11' */
      UNICARPTMotorCU_DW->Memory11_PreviousInput_f =
        UNICARPTMotorCU_B->sf_MATLABFunction_a.m1;

      /* Update for Memory: '<S23>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_g = UNICARPTMotorCU_B->T_An_o;
    }

    /* Update for Integrator: '<S27>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_g = 0;

    /* Update for Resettable SubSystem: '<S26>/Resettable Subsystem' */
    UNICARPTMotorCU_ResettableSubsystem_Update(UNICARPTMotorCU_M,
      &UNICARPTMotorCU_B->ResettableSubsystem_n,
      &UNICARPTMotorCU_DW->ResettableSubsystem_n);

    /* End of Update for SubSystem: '<S26>/Resettable Subsystem' */

    /* Update for Integrator: '<S35>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_h = 0;

    /* Update for Integrator: '<S33>/Integrator2' */
    UNICARPTMotorCU_DW->Integrator2_IWORK_i = 0;
    if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
      /* Update for Memory: '<S33>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_gf = UNICARPTMotorCU_B->Gain_e;

      /* Update for Memory: '<S38>/Memory10' */
      UNICARPTMotorCU_DW->Memory10_PreviousInput_d =
        UNICARPTMotorCU_B->ResettableSubsystem_nm.Min;

      /* Update for Memory: '<S38>/Memory7' */
      UNICARPTMotorCU_DW->Memory7_PreviousInput_m = UNICARPTMotorCU_B->Clock2_n;

      /* Update for Memory: '<S38>/Memory9' */
      UNICARPTMotorCU_DW->Memory9_PreviousInput_d =
        UNICARPTMotorCU_B->sf_MATLABFunction_f.t_mem1;

      /* Update for Memory: '<S38>/Memory8' */
      UNICARPTMotorCU_DW->Memory8_PreviousInput_o =
        UNICARPTMotorCU_B->sf_MATLABFunction_f.t_mem2;

      /* Update for Memory: '<S38>/Memory11' */
      UNICARPTMotorCU_DW->Memory11_PreviousInput_g =
        UNICARPTMotorCU_B->sf_MATLABFunction_f.m1;

      /* Update for Memory: '<S35>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_j = UNICARPTMotorCU_B->T_An_oc;
    }

    /* Update for Integrator: '<S39>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_fs = 0;

    /* Update for Resettable SubSystem: '<S38>/Resettable Subsystem' */
    UNICARPTMotorCU_ResettableSubsystem_Update(UNICARPTMotorCU_M,
      &UNICARPTMotorCU_B->ResettableSubsystem_nm,
      &UNICARPTMotorCU_DW->ResettableSubsystem_nm);

    /* End of Update for SubSystem: '<S38>/Resettable Subsystem' */

    /* Update for Integrator: '<S47>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_fg = 0;

    /* Update for Integrator: '<S45>/Integrator2' */
    UNICARPTMotorCU_DW->Integrator2_IWORK_d = 0;
    if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
      /* Update for Memory: '<S45>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_h = UNICARPTMotorCU_B->Gain_by;

      /* Update for Memory: '<S50>/Memory10' */
      UNICARPTMotorCU_DW->Memory10_PreviousInput_n =
        UNICARPTMotorCU_B->ResettableSubsystem_f.Min;

      /* Update for Memory: '<S50>/Memory7' */
      UNICARPTMotorCU_DW->Memory7_PreviousInput_l = UNICARPTMotorCU_B->Clock2_b1;

      /* Update for Memory: '<S50>/Memory9' */
      UNICARPTMotorCU_DW->Memory9_PreviousInput_h =
        UNICARPTMotorCU_B->sf_MATLABFunction_ad.t_mem1;

      /* Update for Memory: '<S50>/Memory8' */
      UNICARPTMotorCU_DW->Memory8_PreviousInput_d =
        UNICARPTMotorCU_B->sf_MATLABFunction_ad.t_mem2;

      /* Update for Memory: '<S50>/Memory11' */
      UNICARPTMotorCU_DW->Memory11_PreviousInput_gv =
        UNICARPTMotorCU_B->sf_MATLABFunction_ad.m1;

      /* Update for Memory: '<S47>/Memory' */
      UNICARPTMotorCU_DW->Memory_PreviousInput_k = UNICARPTMotorCU_B->T_An_n;
    }

    /* Update for Integrator: '<S51>/Integrator' */
    UNICARPTMotorCU_DW->Integrator_IWORK_fq = 0;

    /* Update for Resettable SubSystem: '<S50>/Resettable Subsystem' */
    UNICARPTMotorCU_ResettableSubsystem_Update(UNICARPTMotorCU_M,
      &UNICARPTMotorCU_B->ResettableSubsystem_f,
      &UNICARPTMotorCU_DW->ResettableSubsystem_f);

    /* End of Update for SubSystem: '<S50>/Resettable Subsystem' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(UNICARPTMotorCU_M)) {
    rt_ertODEUpdateContinuousStates(UNICARPTMotorCU_M->solverInfo,
      UNICARPTMotorCU_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++UNICARPTMotorCU_M->Timing.clockTick0)) {
      ++UNICARPTMotorCU_M->Timing.clockTickH0;
    }

    UNICARPTMotorCU_M->Timing.t[0] = rtsiGetSolverStopTime
      (UNICARPTMotorCU_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      UNICARPTMotorCU_M->Timing.clockTick1++;
      if (!UNICARPTMotorCU_M->Timing.clockTick1) {
        UNICARPTMotorCU_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void UNICARPTMotorCU_derivatives(RT_MODEL_UNICARPTMotorCU_T *const
  UNICARPTMotorCU_M)
{
  B_UNICARPTMotorCU_T *UNICARPTMotorCU_B = ((B_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->blockIO);
  X_UNICARPTMotorCU_T *UNICARPTMotorCU_X = ((X_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->contStates);
  XDot_UNICARPTMotorCU_T *_rtXdot;
  _rtXdot = ((XDot_UNICARPTMotorCU_T *) UNICARPTMotorCU_M->derivs);

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE = UNICARPTMotorCU_B->dT_An;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = UNICARPTMotorCU_B->Divide;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = UNICARPTMotorCU_B->Sum;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = UNICARPTMotorCU_B->Sum2;

  /* Derivatives for TransferFcn: '<S9>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += UNICARPTMotorCU_P.TransferFcn_A *
    UNICARPTMotorCU_X->TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += UNICARPTMotorCU_B->IndexVector2_j;

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = UNICARPTMotorCU_B->Product2;

  /* Derivatives for Integrator: '<S23>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = UNICARPTMotorCU_B->dT_An_a;

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_p = UNICARPTMotorCU_B->Divide_l;

  /* Derivatives for Integrator: '<S21>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = UNICARPTMotorCU_B->Sum_h;

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = UNICARPTMotorCU_B->Sum2_m;

  /* Derivatives for TransferFcn: '<S21>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_c = 0.0;
  _rtXdot->TransferFcn_CSTATE_c += UNICARPTMotorCU_P.TransferFcn_A_l *
    UNICARPTMotorCU_X->TransferFcn_CSTATE_c;
  _rtXdot->TransferFcn_CSTATE_c += UNICARPTMotorCU_B->IndexVector2_f;

  /* Derivatives for Integrator: '<S27>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = UNICARPTMotorCU_B->Product2_ax;

  /* Derivatives for Integrator: '<S35>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = UNICARPTMotorCU_B->dT_An_l;

  /* Derivatives for Integrator: '<S33>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_h = UNICARPTMotorCU_B->Divide_c;

  /* Derivatives for Integrator: '<S33>/Integrator' */
  _rtXdot->Integrator_CSTATE_ga = UNICARPTMotorCU_B->Sum_e;

  /* Derivatives for Integrator: '<S33>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_n = UNICARPTMotorCU_B->Sum2_c;

  /* Derivatives for TransferFcn: '<S33>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_i = 0.0;
  _rtXdot->TransferFcn_CSTATE_i += UNICARPTMotorCU_P.TransferFcn_A_m *
    UNICARPTMotorCU_X->TransferFcn_CSTATE_i;
  _rtXdot->TransferFcn_CSTATE_i += UNICARPTMotorCU_B->IndexVector2_i;

  /* Derivatives for Integrator: '<S39>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = UNICARPTMotorCU_B->Product2_b;

  /* Derivatives for Integrator: '<S47>/Integrator' */
  _rtXdot->Integrator_CSTATE_ci = UNICARPTMotorCU_B->dT_An_b;

  /* Derivatives for Integrator: '<S45>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_k = UNICARPTMotorCU_B->Divide_j;

  /* Derivatives for Integrator: '<S45>/Integrator' */
  _rtXdot->Integrator_CSTATE_jg = UNICARPTMotorCU_B->Sum_e5;

  /* Derivatives for Integrator: '<S45>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_b = UNICARPTMotorCU_B->Sum2_h;

  /* Derivatives for TransferFcn: '<S45>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_n = 0.0;
  _rtXdot->TransferFcn_CSTATE_n += UNICARPTMotorCU_P.TransferFcn_A_h *
    UNICARPTMotorCU_X->TransferFcn_CSTATE_n;
  _rtXdot->TransferFcn_CSTATE_n += UNICARPTMotorCU_B->IndexVector2_g;

  /* Derivatives for Integrator: '<S51>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = UNICARPTMotorCU_B->Product2_c;
}

/* Model initialize function */
void UNICARPTMotorCU_initialize(RT_MODEL_UNICARPTMotorCU_T *const
  UNICARPTMotorCU_M)
{
  DW_UNICARPTMotorCU_T *UNICARPTMotorCU_DW = ((DW_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->dwork);
  X_UNICARPTMotorCU_T *UNICARPTMotorCU_X = ((X_UNICARPTMotorCU_T *)
    UNICARPTMotorCU_M->contStates);

  /* Start for S-Function (read_dict): '<S11>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S15>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_p.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_n.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqPeakMax.FL", NULL);
    UNICARPTMotorCU_DW->WriteCMDict_IWORK.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqMax.FL", NULL);
    UNICARPTMotorCU_DW->WriteCMDict1_IWORK.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict1_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.SOC.FL", NULL);
    UNICARPTMotorCU_DW->WriteCMDict2_IWORK.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict2_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S11>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vx", NULL);
    UNICARPTMotorCU_DW->ReadCMDict1_IWORK.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict1_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S11>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vy", NULL);
    UNICARPTMotorCU_DW->ReadCMDict4_IWORK.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict4_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S23>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_b.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_o.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S27>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_l.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqPeakMax.FR", NULL);
    UNICARPTMotorCU_DW->WriteCMDict_IWORK_i.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqMax.FR", NULL);
    UNICARPTMotorCU_DW->WriteCMDict1_IWORK_h.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict1_PWORK_m.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.SOC.FR", NULL);
    UNICARPTMotorCU_DW->WriteCMDict2_IWORK_f.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict2_PWORK_j.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S23>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vx", NULL);
    UNICARPTMotorCU_DW->ReadCMDict1_IWORK_d.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict1_PWORK_b.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S23>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vy", NULL);
    UNICARPTMotorCU_DW->ReadCMDict4_IWORK_j.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict4_PWORK_i.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S35>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_h.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_k.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S39>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_n.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_b.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqPeakMax.RL", NULL);
    UNICARPTMotorCU_DW->WriteCMDict_IWORK_e.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict_PWORK_n.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqMax.RL", NULL);
    UNICARPTMotorCU_DW->WriteCMDict1_IWORK_g.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict1_PWORK_c.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.SOC.RL", NULL);
    UNICARPTMotorCU_DW->WriteCMDict2_IWORK_c.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict2_PWORK_k.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S35>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vx", NULL);
    UNICARPTMotorCU_DW->ReadCMDict1_IWORK_k.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict1_PWORK_e.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S35>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vy", NULL);
    UNICARPTMotorCU_DW->ReadCMDict4_IWORK_c.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict4_PWORK_m.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S47>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_i.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_f.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S51>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Env.Temperature", NULL);
    UNICARPTMotorCU_DW->ReadCMDict_IWORK_c.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict_PWORK_nq.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S5>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqPeakMax.RR", NULL);
    UNICARPTMotorCU_DW->WriteCMDict_IWORK_c.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict_PWORK_a2.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S5>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.TrqMax.RR", NULL);
    UNICARPTMotorCU_DW->WriteCMDict1_IWORK_m.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict1_PWORK_i.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S5>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.SOC.RR", NULL);
    UNICARPTMotorCU_DW->WriteCMDict2_IWORK_d.Checked = 0;
    UNICARPTMotorCU_DW->WriteCMDict2_PWORK_f.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S47>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vx", NULL);
    UNICARPTMotorCU_DW->ReadCMDict1_IWORK_kx.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict1_PWORK_k.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S47>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Vhcl.PoI.vy", NULL);
    UNICARPTMotorCU_DW->ReadCMDict4_IWORK_h.Checked = 0;
    UNICARPTMotorCU_DW->ReadCMDict4_PWORK_c.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* InitializeConditions for Integrator: '<S11>/Integrator' incorporates:
   *  Integrator: '<S9>/Integrator2'
   */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_X->Integrator_CSTATE = 0.0;
    UNICARPTMotorCU_X->Integrator2_CSTATE = 0.0;
  }

  UNICARPTMotorCU_DW->Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S11>/Integrator' */

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  UNICARPTMotorCU_DW->Integrator2_IWORK = 1;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  UNICARPTMotorCU_X->Integrator_CSTATE_f = UNICARPTMotorCU_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  UNICARPTMotorCU_X->Integrator1_CSTATE = UNICARPTMotorCU_P.Integrator1_IC;

  /* InitializeConditions for TransferFcn: '<S9>/Transfer Fcn' */
  UNICARPTMotorCU_X->TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput =
    UNICARPTMotorCU_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S15>/Integrator' incorporates:
   *  Integrator: '<S23>/Integrator'
   */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_X->Integrator_CSTATE_h = 0.0;
    UNICARPTMotorCU_X->Integrator_CSTATE_o = 0.0;
  }

  UNICARPTMotorCU_DW->Integrator_IWORK_m = 1;

  /* End of InitializeConditions for Integrator: '<S15>/Integrator' */

  /* InitializeConditions for Memory: '<S14>/Memory10' */
  UNICARPTMotorCU_DW->Memory10_PreviousInput =
    UNICARPTMotorCU_P.Memory10_InitialCondition;

  /* InitializeConditions for Memory: '<S14>/Memory7' */
  UNICARPTMotorCU_DW->Memory7_PreviousInput =
    UNICARPTMotorCU_P.Memory7_InitialCondition;

  /* InitializeConditions for Memory: '<S14>/Memory9' */
  UNICARPTMotorCU_DW->Memory9_PreviousInput =
    UNICARPTMotorCU_P.Memory9_InitialCondition;

  /* InitializeConditions for Memory: '<S14>/Memory8' */
  UNICARPTMotorCU_DW->Memory8_PreviousInput =
    UNICARPTMotorCU_P.Memory8_InitialCondition;

  /* InitializeConditions for Memory: '<S14>/Memory11' */
  UNICARPTMotorCU_DW->Memory11_PreviousInput =
    UNICARPTMotorCU_P.Memory11_InitialCondition;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_b =
    UNICARPTMotorCU_P.Memory_InitialCondition_j;

  /* InitializeConditions for Integrator: '<S23>/Integrator' */
  UNICARPTMotorCU_DW->Integrator_IWORK_f = 1;

  /* InitializeConditions for Integrator: '<S21>/Integrator2' incorporates:
   *  Integrator: '<S27>/Integrator'
   */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_X->Integrator2_CSTATE_p = 0.0;
    UNICARPTMotorCU_X->Integrator_CSTATE_j = 0.0;
  }

  UNICARPTMotorCU_DW->Integrator2_IWORK_g = 1;

  /* End of InitializeConditions for Integrator: '<S21>/Integrator2' */

  /* InitializeConditions for Integrator: '<S21>/Integrator' */
  UNICARPTMotorCU_X->Integrator_CSTATE_g = UNICARPTMotorCU_P.Integrator_IC_l;

  /* InitializeConditions for Integrator: '<S21>/Integrator1' */
  UNICARPTMotorCU_X->Integrator1_CSTATE_p = UNICARPTMotorCU_P.Integrator1_IC_h;

  /* InitializeConditions for TransferFcn: '<S21>/Transfer Fcn' */
  UNICARPTMotorCU_X->TransferFcn_CSTATE_c = 0.0;

  /* InitializeConditions for Memory: '<S21>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_bq =
    UNICARPTMotorCU_P.Memory_InitialCondition_b;

  /* InitializeConditions for Integrator: '<S27>/Integrator' */
  UNICARPTMotorCU_DW->Integrator_IWORK_g = 1;

  /* InitializeConditions for Memory: '<S26>/Memory10' */
  UNICARPTMotorCU_DW->Memory10_PreviousInput_m =
    UNICARPTMotorCU_P.Memory10_InitialCondition_p;

  /* InitializeConditions for Memory: '<S26>/Memory7' */
  UNICARPTMotorCU_DW->Memory7_PreviousInput_g =
    UNICARPTMotorCU_P.Memory7_InitialCondition_f;

  /* InitializeConditions for Memory: '<S26>/Memory9' */
  UNICARPTMotorCU_DW->Memory9_PreviousInput_o =
    UNICARPTMotorCU_P.Memory9_InitialCondition_m;

  /* InitializeConditions for Memory: '<S26>/Memory8' */
  UNICARPTMotorCU_DW->Memory8_PreviousInput_m =
    UNICARPTMotorCU_P.Memory8_InitialCondition_h;

  /* InitializeConditions for Memory: '<S26>/Memory11' */
  UNICARPTMotorCU_DW->Memory11_PreviousInput_f =
    UNICARPTMotorCU_P.Memory11_InitialCondition_o;

  /* InitializeConditions for Memory: '<S23>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_g =
    UNICARPTMotorCU_P.Memory_InitialCondition_l;

  /* InitializeConditions for Integrator: '<S35>/Integrator' incorporates:
   *  Integrator: '<S33>/Integrator2'
   */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_X->Integrator_CSTATE_c = 0.0;
    UNICARPTMotorCU_X->Integrator2_CSTATE_h = 0.0;
  }

  UNICARPTMotorCU_DW->Integrator_IWORK_h = 1;

  /* End of InitializeConditions for Integrator: '<S35>/Integrator' */

  /* InitializeConditions for Integrator: '<S33>/Integrator2' */
  UNICARPTMotorCU_DW->Integrator2_IWORK_i = 1;

  /* InitializeConditions for Integrator: '<S33>/Integrator' */
  UNICARPTMotorCU_X->Integrator_CSTATE_ga = UNICARPTMotorCU_P.Integrator_IC_e;

  /* InitializeConditions for Integrator: '<S33>/Integrator1' */
  UNICARPTMotorCU_X->Integrator1_CSTATE_n = UNICARPTMotorCU_P.Integrator1_IC_hc;

  /* InitializeConditions for TransferFcn: '<S33>/Transfer Fcn' */
  UNICARPTMotorCU_X->TransferFcn_CSTATE_i = 0.0;

  /* InitializeConditions for Memory: '<S33>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_gf =
    UNICARPTMotorCU_P.Memory_InitialCondition_d;

  /* InitializeConditions for Integrator: '<S39>/Integrator' incorporates:
   *  Integrator: '<S47>/Integrator'
   */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_X->Integrator_CSTATE_b = 0.0;
    UNICARPTMotorCU_X->Integrator_CSTATE_ci = 0.0;
  }

  UNICARPTMotorCU_DW->Integrator_IWORK_fs = 1;

  /* End of InitializeConditions for Integrator: '<S39>/Integrator' */

  /* InitializeConditions for Memory: '<S38>/Memory10' */
  UNICARPTMotorCU_DW->Memory10_PreviousInput_d =
    UNICARPTMotorCU_P.Memory10_InitialCondition_k;

  /* InitializeConditions for Memory: '<S38>/Memory7' */
  UNICARPTMotorCU_DW->Memory7_PreviousInput_m =
    UNICARPTMotorCU_P.Memory7_InitialCondition_b;

  /* InitializeConditions for Memory: '<S38>/Memory9' */
  UNICARPTMotorCU_DW->Memory9_PreviousInput_d =
    UNICARPTMotorCU_P.Memory9_InitialCondition_a;

  /* InitializeConditions for Memory: '<S38>/Memory8' */
  UNICARPTMotorCU_DW->Memory8_PreviousInput_o =
    UNICARPTMotorCU_P.Memory8_InitialCondition_hu;

  /* InitializeConditions for Memory: '<S38>/Memory11' */
  UNICARPTMotorCU_DW->Memory11_PreviousInput_g =
    UNICARPTMotorCU_P.Memory11_InitialCondition_ox;

  /* InitializeConditions for Memory: '<S35>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_j =
    UNICARPTMotorCU_P.Memory_InitialCondition_a;

  /* InitializeConditions for Integrator: '<S47>/Integrator' */
  UNICARPTMotorCU_DW->Integrator_IWORK_fg = 1;

  /* InitializeConditions for Integrator: '<S45>/Integrator2' incorporates:
   *  Integrator: '<S51>/Integrator'
   */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    UNICARPTMotorCU_X->Integrator2_CSTATE_k = 0.0;
    UNICARPTMotorCU_X->Integrator_CSTATE_m = 0.0;
  }

  UNICARPTMotorCU_DW->Integrator2_IWORK_d = 1;

  /* End of InitializeConditions for Integrator: '<S45>/Integrator2' */

  /* InitializeConditions for Integrator: '<S45>/Integrator' */
  UNICARPTMotorCU_X->Integrator_CSTATE_jg = UNICARPTMotorCU_P.Integrator_IC_o;

  /* InitializeConditions for Integrator: '<S45>/Integrator1' */
  UNICARPTMotorCU_X->Integrator1_CSTATE_b = UNICARPTMotorCU_P.Integrator1_IC_a;

  /* InitializeConditions for TransferFcn: '<S45>/Transfer Fcn' */
  UNICARPTMotorCU_X->TransferFcn_CSTATE_n = 0.0;

  /* InitializeConditions for Memory: '<S45>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_h =
    UNICARPTMotorCU_P.Memory_InitialCondition_m;

  /* InitializeConditions for Integrator: '<S51>/Integrator' */
  UNICARPTMotorCU_DW->Integrator_IWORK_fq = 1;

  /* InitializeConditions for Memory: '<S50>/Memory10' */
  UNICARPTMotorCU_DW->Memory10_PreviousInput_n =
    UNICARPTMotorCU_P.Memory10_InitialCondition_m;

  /* InitializeConditions for Memory: '<S50>/Memory7' */
  UNICARPTMotorCU_DW->Memory7_PreviousInput_l =
    UNICARPTMotorCU_P.Memory7_InitialCondition_n;

  /* InitializeConditions for Memory: '<S50>/Memory9' */
  UNICARPTMotorCU_DW->Memory9_PreviousInput_h =
    UNICARPTMotorCU_P.Memory9_InitialCondition_n;

  /* InitializeConditions for Memory: '<S50>/Memory8' */
  UNICARPTMotorCU_DW->Memory8_PreviousInput_d =
    UNICARPTMotorCU_P.Memory8_InitialCondition_e;

  /* InitializeConditions for Memory: '<S50>/Memory11' */
  UNICARPTMotorCU_DW->Memory11_PreviousInput_gv =
    UNICARPTMotorCU_P.Memory11_InitialCondition_n;

  /* InitializeConditions for Memory: '<S47>/Memory' */
  UNICARPTMotorCU_DW->Memory_PreviousInput_k =
    UNICARPTMotorCU_P.Memory_InitialCondition_o;

  /* SystemInitialize for Resettable SubSystem: '<S14>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem_Init
    (&UNICARPTMotorCU_DW->ResettableSubsystem, &UNICARPTMotorCU_P);

  /* End of SystemInitialize for SubSystem: '<S14>/Resettable Subsystem' */

  /* SystemInitialize for Resettable SubSystem: '<S26>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem_Init
    (&UNICARPTMotorCU_DW->ResettableSubsystem_n, &UNICARPTMotorCU_P);

  /* End of SystemInitialize for SubSystem: '<S26>/Resettable Subsystem' */

  /* SystemInitialize for Resettable SubSystem: '<S38>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem_Init
    (&UNICARPTMotorCU_DW->ResettableSubsystem_nm, &UNICARPTMotorCU_P);

  /* End of SystemInitialize for SubSystem: '<S38>/Resettable Subsystem' */

  /* SystemInitialize for Resettable SubSystem: '<S50>/Resettable Subsystem' */
  UNICARPTMotorCU_ResettableSubsystem_Init
    (&UNICARPTMotorCU_DW->ResettableSubsystem_f, &UNICARPTMotorCU_P);

  /* End of SystemInitialize for SubSystem: '<S50>/Resettable Subsystem' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(UNICARPTMotorCU_M)) {
    rtmSetFirstInitCond(UNICARPTMotorCU_M, 0);
  }
}

/* Model terminate function */
void UNICARPTMotorCU_terminate(RT_MODEL_UNICARPTMotorCU_T * UNICARPTMotorCU_M)
{
  rt_FREE(UNICARPTMotorCU_M->solverInfo);

  /* model code */
  rt_FREE(UNICARPTMotorCU_M->blockIO);
  rt_FREE(UNICARPTMotorCU_M->contStates);
  rt_FREE(UNICARPTMotorCU_M->inputs);
  rt_FREE(UNICARPTMotorCU_M->outputs);
  rt_FREE(UNICARPTMotorCU_M->dwork);
  rt_FREE(UNICARPTMotorCU_M->prevZCSigState);
  rt_FREE(UNICARPTMotorCU_M);
}

/* Model data allocation function */
RT_MODEL_UNICARPTMotorCU_T *UNICARPTMotorCU(struct tInfos *inf)
{
  RT_MODEL_UNICARPTMotorCU_T *UNICARPTMotorCU_M;
  UNICARPTMotorCU_M = (RT_MODEL_UNICARPTMotorCU_T *) malloc(sizeof
    (RT_MODEL_UNICARPTMotorCU_T));
  if (UNICARPTMotorCU_M == NULL) {
    return NULL;
  }

  (void) memset((char *)UNICARPTMotorCU_M, 0,
                sizeof(RT_MODEL_UNICARPTMotorCU_T));
  MatSupp_Init();

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,rt_SolverInfo);
    UNICARPTMotorCU_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(UNICARPTMotorCU_M->solverInfo,
                          &UNICARPTMotorCU_M->Timing.simTimeStep);
    rtsiSetTPtr(UNICARPTMotorCU_M->solverInfo, &rtmGetTPtr(UNICARPTMotorCU_M));
    rtsiSetStepSizePtr(UNICARPTMotorCU_M->solverInfo,
                       &UNICARPTMotorCU_M->Timing.stepSize0);
    rtsiSetdXPtr(UNICARPTMotorCU_M->solverInfo, &UNICARPTMotorCU_M->derivs);
    rtsiSetContStatesPtr(UNICARPTMotorCU_M->solverInfo, (real_T **)
                         &UNICARPTMotorCU_M->contStates);
    rtsiSetNumContStatesPtr(UNICARPTMotorCU_M->solverInfo,
      &UNICARPTMotorCU_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(UNICARPTMotorCU_M->solverInfo,
      &UNICARPTMotorCU_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(UNICARPTMotorCU_M->solverInfo,
      &UNICARPTMotorCU_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(UNICARPTMotorCU_M->solverInfo,
      &UNICARPTMotorCU_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(UNICARPTMotorCU_M->solverInfo, (&rtmGetErrorStatus
      (UNICARPTMotorCU_M)));
    rtsiSetRTModelPtr(UNICARPTMotorCU_M->solverInfo, UNICARPTMotorCU_M);
  }

  rtsiSetSolverName(UNICARPTMotorCU_M->solverInfo,"ode1");

  /* block I/O */
  {
    B_UNICARPTMotorCU_T *b = (B_UNICARPTMotorCU_T *) malloc(sizeof
      (B_UNICARPTMotorCU_T));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,b);
    UNICARPTMotorCU_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    X_UNICARPTMotorCU_T *x = (X_UNICARPTMotorCU_T *) malloc(sizeof
      (X_UNICARPTMotorCU_T));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,x);
    UNICARPTMotorCU_M->contStates = (x);
  }

  /* states (dwork) */
  {
    DW_UNICARPTMotorCU_T *dwork = (DW_UNICARPTMotorCU_T *) malloc(sizeof
      (DW_UNICARPTMotorCU_T));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,dwork);
    UNICARPTMotorCU_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_UNICARPTMotorCU_T *UNICARPTMotorCU_U = (ExtU_UNICARPTMotorCU_T *)
      malloc(sizeof(ExtU_UNICARPTMotorCU_T));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,UNICARPTMotorCU_U);
    UNICARPTMotorCU_M->inputs = (((ExtU_UNICARPTMotorCU_T *) UNICARPTMotorCU_U));
  }

  /* external outputs */
  {
    ExtY_UNICARPTMotorCU_T *UNICARPTMotorCU_Y = (ExtY_UNICARPTMotorCU_T *)
      malloc(sizeof(ExtY_UNICARPTMotorCU_T));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,UNICARPTMotorCU_Y);
    UNICARPTMotorCU_M->outputs = (UNICARPTMotorCU_Y);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_UNICARPTMotorCU_T *zc = (PrevZCX_UNICARPTMotorCU_T *) malloc(sizeof
      (PrevZCX_UNICARPTMotorCU_T));
    rt_VALIDATE_MEMORY(UNICARPTMotorCU_M,zc);
    UNICARPTMotorCU_M->prevZCSigState = (zc);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  UNICARPTMotorCU_InitializeDataMapInfo(UNICARPTMotorCU_M);

  /* CarMaker parameter tuning */
  {
    const struct tMatSuppMMI *mmi = &(rtmGetDataMapInfo(UNICARPTMotorCU_M).mmi);
    tMatSuppTunables *tuns = MatSupp_TunBegin("UNICARPTMotorCU", mmi);
    UNICARPTMotorCU_SetParams(UNICARPTMotorCU_M, tuns, inf);
    MatSupp_TunEnd(tuns);
  }

  {
    B_UNICARPTMotorCU_T *UNICARPTMotorCU_B = ((B_UNICARPTMotorCU_T *)
      UNICARPTMotorCU_M->blockIO);
    DW_UNICARPTMotorCU_T *UNICARPTMotorCU_DW = ((DW_UNICARPTMotorCU_T *)
      UNICARPTMotorCU_M->dwork);
    X_UNICARPTMotorCU_T *UNICARPTMotorCU_X = ((X_UNICARPTMotorCU_T *)
      UNICARPTMotorCU_M->contStates);
    PrevZCX_UNICARPTMotorCU_T *UNICARPTMotorCU_PrevZCX =
      ((PrevZCX_UNICARPTMotorCU_T *) UNICARPTMotorCU_M->prevZCSigState);
    ExtU_UNICARPTMotorCU_T *UNICARPTMotorCU_U = (ExtU_UNICARPTMotorCU_T *)
      UNICARPTMotorCU_M->inputs;
    ExtY_UNICARPTMotorCU_T *UNICARPTMotorCU_Y = (ExtY_UNICARPTMotorCU_T *)
      UNICARPTMotorCU_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtsiSetSimTimeStep(UNICARPTMotorCU_M->solverInfo, MAJOR_TIME_STEP);
    UNICARPTMotorCU_M->intgData.f[0] = UNICARPTMotorCU_M->odeF[0];
    UNICARPTMotorCU_M->contStates = ((X_UNICARPTMotorCU_T *) UNICARPTMotorCU_X);
    rtsiSetSolverData(UNICARPTMotorCU_M->solverInfo, (void *)
                      &UNICARPTMotorCU_M->intgData);
    rtmSetTPtr(UNICARPTMotorCU_M, &UNICARPTMotorCU_M->Timing.tArray[0]);
    UNICARPTMotorCU_M->Timing.stepSize0 = 0.0002;
    rtmSetFirstInitCond(UNICARPTMotorCU_M, 1);

    /* block I/O */
    (void) memset(((void *) UNICARPTMotorCU_B), 0,
                  sizeof(B_UNICARPTMotorCU_T));

    /* states (continuous) */
    {
      (void) memset((void *)UNICARPTMotorCU_X, 0,
                    sizeof(X_UNICARPTMotorCU_T));
    }

    /* states (dwork) */
    (void) memset((void *)UNICARPTMotorCU_DW, 0,
                  sizeof(DW_UNICARPTMotorCU_T));

    /* external inputs */
    (void)memset(UNICARPTMotorCU_U, 0, sizeof(ExtU_UNICARPTMotorCU_T));

    /* external outputs */
    UNICARPTMotorCU_Y->ToCM = UNICARPTMotorCU_rtZcmPTMotorCUOut;

    /* previous zero-crossing states */
    {
      UNICARPTMotorCU_PrevZCX->ResettableSubsystem_f.ResettableSubsystem_Reset_ZCE
        = UNINITIALIZED_ZCSIG;
      UNICARPTMotorCU_PrevZCX->ResettableSubsystem_nm.ResettableSubsystem_Reset_ZCE
        = UNINITIALIZED_ZCSIG;
      UNICARPTMotorCU_PrevZCX->ResettableSubsystem_n.ResettableSubsystem_Reset_ZCE
        = UNINITIALIZED_ZCSIG;
      UNICARPTMotorCU_PrevZCX->ResettableSubsystem.ResettableSubsystem_Reset_ZCE
        = UNINITIALIZED_ZCSIG;
    }
  }

  return UNICARPTMotorCU_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *UNICARPTMotorCU_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)UNICARPTMotorCU_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *UNICARPTMotorCU_DictDefines = DictDefines;
tQuantEntry *UNICARPTMotorCU_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *UNICARPTMotorCU_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)UNICARPTMotorCU_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *UNICARPTMotorCU_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *UNICARPTMotorCU_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
