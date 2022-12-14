/*
 * UNICARPTMotor.c
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

#include "UNICARPTMotor_capi.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "UNICARPTMotor.h"
#include "UNICARPTMotor_private.h"
#include "UNICARPTMotor_wrap.h"

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

const cmPTMotorOut UNICARPTMotor_rtZcmPTMotorOut = {
  0.0,                                 /* Trq */
  0.0,                                 /* Inert */
  0.0                                  /* PwrElec */
} ;                                    /* cmPTMotorOut ground */

/* Block parameters (default storage) */
P_UNICARPTMotor_T UNICARPTMotor_P = {
  /* Variable: mot_J_kgm_2
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Variable: mot_KPT1
   * Referenced by: '<S4>/Constant1'
   */
  27.662489001392924,

  /* Variable: mot_KPT2
   * Referenced by: '<S5>/Constant1'
   */
  1.0,

  /* Variable: mot_MMax_PT12_Nm
   * Referenced by: '<S3>/1-D Lookup Table'
   */
  { 0.0, 0.79, 0.82, 1.5 },

  /* Variable: mot_M_Nm
   * Referenced by: '<S2>/Wirkungsgradkennfeld'
   */
  { 0.0, 5.0, 10.0, 20.0, 30.0, 40.0, 47.0, 60.771428571428572, 76.0,
    92.685714285714283, 110.82857142857142, 130.42857142857142,
    151.48571428571429, 174.0 },

  /* Variable: mot_PMax_W
   * Referenced by: '<S3>/Constant6'
   */
  14576.98991265664,

  /* Variable: mot_TPT1_1_s
   * Referenced by: '<S4>/Constant4'
   */
  27.662489001392924,

  /* Variable: mot_TPT2_1_s
   * Referenced by: '<S5>/Constant2'
   */
  0.013999994238804,

  /* Variable: mot_dPT2
   * Referenced by: '<S5>/Constant4'
   */
  0.189901320353302,

  /* Variable: mot_dyn
   * Referenced by: '<S2>/Constant7'
   */
  1.0,

  /* Variable: mot_eta
   * Referenced by: '<S2>/Wirkungsgradkennfeld'
   */
  { 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001,
    0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.8671, 0.8466,
    0.78909999999999991, 0.7459, 0.70480000000000009, 0.6694, 0.6321, 0.6038,
    0.5703, 0.5462, 0.5143, 0.4925, 0.4583, 0.0001, 0.8929, 0.8978, 0.8736,
    0.84829999999999994, 0.8203, 0.79709999999999992, 0.77, 0.74900000000000011,
    0.723, 0.7033, 0.679, 0.6597, 0.6297, 0.0001, 0.8989, 0.9158, 0.9039,
    0.88709999999999989, 0.8683, 0.8515, 0.8316, 0.81349999999999989,
    0.79489999999999994, 0.77760000000000007, 0.7569, 0.7386, 0.7187, 0.0001,
    0.9061, 0.9288, 0.92280000000000006, 0.9081, 0.8948, 0.8803, 0.8641, 0.8499,
    0.8343, 0.8207, 0.80319999999999991, 0.7877, 0.7698, 0.0001, 0.9122, 0.9405,
    0.94480000000000008, 0.94090000000000007, 0.935, 0.9286, 0.9203, 0.9129,
    0.904, 0.8961, 0.8856, 0.8763, 0.8649, 0.0001, 0.91099999999999992,
    0.94459999999999988, 0.953, 0.95219999999999994, 0.9488, 0.9457, 0.94,
    0.9353, 0.9303, 0.92409999999999992, 0.917, 0.9107, 0.9025, 0.0001, 0.8937,
    0.9386, 0.9553, 0.95590000000000008, 0.9555, 0.9537, 0.9508, 0.9472, 0.9433,
    0.93900000000000006, 0.9354, 0.92909999999999993, 0.9227, 0.0001, 0.9062,
    0.9386, 0.9547, 0.9611, 0.9604, 0.9598, 0.9576, 0.95459999999999989,
    0.95200000000000007, 0.94609999999999994, 0.938, 0.9322, 0.9, 0.0001, 0.8979,
    0.9384, 0.9561, 0.9616, 0.96310000000000007, 0.9614, 0.9594, 0.9539, 0.9458,
    0.9373999999999999, 0.9, 0.9, 0.9, 0.0001, 0.9031, 0.93409999999999993,
    0.9561, 0.96129999999999993, 0.9599, 0.95739999999999992, 0.9534, 0.9456,
    0.9, 0.9, 0.9, 0.9, 0.9, 0.0001, 0.8715, 0.92319999999999991, 0.953,
    0.95519999999999994, 0.95519999999999994, 0.9515, 0.9442, 0.9, 0.9, 0.9, 0.9,
    0.9, 0.9, 0.0001, 0.8737, 0.91909999999999992, 0.94709999999999994, 0.9503,
    0.94680000000000009, 0.9434, 0.93099999999999994, 0.9, 0.9, 0.9, 0.9, 0.9,
    0.9, 0.0001, 0.85939999999999994, 0.90870000000000006, 0.9423999999999999,
    0.948, 0.946, 0.9383, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.0001,
    0.83900000000000008, 0.8987, 0.935, 0.945, 0.94400000000000006, 0.937, 0.9,
    0.9, 0.9, 0.9, 0.9, 0.9, 0.9 },

  /* Variable: mot_omega_PT12_rad_s
   * Referenced by: '<S3>/1-D Lookup Table'
   */
  { 0.0, 83.775804095727821, 83.880523850847467, 1047.1975511965977 },

  /* Variable: mot_omega_rad_s
   * Referenced by: '<S2>/Wirkungsgradkennfeld'
   */
  { 0.0, 5.23598775598299, 10.471975511965979, 15.707963267948967,
    20.943951023931959, 41.887902047863918, 62.831853071795869,
    83.775804095727835, 157.07963267948966, 188.4955592153876,
    219.91148575128554, 251.32741228718345, 282.74333882308139,
    298.45130209103036, 314.15926535897933 },

  /* Variable: mot_weight_PT12
   * Referenced by: '<S3>/1-D Lookup Table'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    1.0 },

  /* Expression: 0
   * Referenced by: '<S5>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<S3>/Constant1'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch4'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant3'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S5>/Gain2'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Computed Parameter: uDLookupTable_maxIndex
   * Referenced by: '<S3>/1-D Lookup Table'
   */
  { 3U, 3U },

  /* Computed Parameter: Wirkungsgradkennfeld_maxIndex
   * Referenced by: '<S2>/Wirkungsgradkennfeld'
   */
  { 13U, 14U }
};

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
  RT_MODEL_UNICARPTMotor_T *const UNICARPTMotor_M)
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  UNICARPTMotor_derivatives(UNICARPTMotor_M);
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void UNICARPTMotor_step(RT_MODEL_UNICARPTMotor_T *const UNICARPTMotor_M)
{
  B_UNICARPTMotor_T *UNICARPTMotor_B = ((B_UNICARPTMotor_T *)
    UNICARPTMotor_M->blockIO);
  DW_UNICARPTMotor_T *UNICARPTMotor_DW = ((DW_UNICARPTMotor_T *)
    UNICARPTMotor_M->dwork);
  X_UNICARPTMotor_T *UNICARPTMotor_X = ((X_UNICARPTMotor_T *)
    UNICARPTMotor_M->contStates);
  ExtU_UNICARPTMotor_T *UNICARPTMotor_U = (ExtU_UNICARPTMotor_T *)
    UNICARPTMotor_M->inputs;
  ExtY_UNICARPTMotor_T *UNICARPTMotor_Y = (ExtY_UNICARPTMotor_T *)
    UNICARPTMotor_M->outputs;
  real_T rtb_M_ist_i;
  real_T rtb_Square2;
  if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
    /* set solver stop time */
    if (!(UNICARPTMotor_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(UNICARPTMotor_M->solverInfo,
                            ((UNICARPTMotor_M->Timing.clockTickH0 + 1) *
        UNICARPTMotor_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(UNICARPTMotor_M->solverInfo,
                            ((UNICARPTMotor_M->Timing.clockTick0 + 1) *
        UNICARPTMotor_M->Timing.stepSize0 + UNICARPTMotor_M->Timing.clockTickH0 *
        UNICARPTMotor_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(UNICARPTMotor_M)) {
    UNICARPTMotor_M->Timing.t[0] = rtsiGetT(UNICARPTMotor_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
    /* Memory: '<S3>/Memory' */
    UNICARPTMotor_B->Memory = UNICARPTMotor_DW->Memory_PreviousInput;
  }

  /* Abs: '<S3>/Abs' incorporates:
   *  Abs: '<S2>/Abs'
   *  Inport: '<Root>/FromCM'
   */
  rtb_Square2 = fabs(UNICARPTMotor_U->FromCM.rotv);

  /* Lookup_n-D: '<S3>/1-D Lookup Table' incorporates:
   *  Abs: '<S3>/Abs'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant6'
   *  Product: '<S3>/Divide'
   *  Product: '<S3>/Product11'
   *  Sum: '<S3>/Add2'
   */
  rtb_M_ist_i = look2_binlxpw(UNICARPTMotor_B->Memory /
    (UNICARPTMotor_P.mot_PMax_W / (UNICARPTMotor_P.Constant1_Value + rtb_Square2)),
    rtb_Square2, UNICARPTMotor_P.mot_MMax_PT12_Nm,
    UNICARPTMotor_P.mot_omega_PT12_rad_s, UNICARPTMotor_P.mot_weight_PT12,
    UNICARPTMotor_P.uDLookupTable_maxIndex, 4U);

  /* Sum: '<S3>/Add1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Integrator: '<S4>/Integrator'
   *  Integrator: '<S5>/Integrator1'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Add'
   */
  UNICARPTMotor_B->Add1 = (UNICARPTMotor_P.Constant_Value - rtb_M_ist_i) *
    UNICARPTMotor_X->Integrator_CSTATE + UNICARPTMotor_X->Integrator1_CSTATE *
    rtb_M_ist_i;

  /* Switch: '<S2>/Switch4' incorporates:
   *  Constant: '<S2>/Constant7'
   *  Inport: '<Root>/FromCM'
   */
  if (UNICARPTMotor_P.mot_dyn > UNICARPTMotor_P.Switch4_Threshold) {
    UNICARPTMotor_B->Switch4 = UNICARPTMotor_B->Add1;
  } else {
    UNICARPTMotor_B->Switch4 = UNICARPTMotor_U->FromCM.Load;
  }

  /* End of Switch: '<S2>/Switch4' */

  /* Gain: '<S2>/Gain' incorporates:
   *  Abs: '<S2>/Abs1'
   *  Inport: '<Root>/FromCM'
   *  Lookup_n-D: '<S2>/Wirkungsgradkennfeld'
   *  Product: '<S2>/Product'
   */
  UNICARPTMotor_B->Gain = UNICARPTMotor_B->Switch4 / look2_binlxpw(fabs
    (UNICARPTMotor_B->Switch4), rtb_Square2, UNICARPTMotor_P.mot_M_Nm,
    UNICARPTMotor_P.mot_omega_rad_s, UNICARPTMotor_P.mot_eta,
    UNICARPTMotor_P.Wirkungsgradkennfeld_maxIndex, 14U) *
    UNICARPTMotor_U->FromCM.rotv * UNICARPTMotor_P.Gain_Gain;
  if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Constant: '<Root>/Constant'
     *  Outport: '<Root>/ToCM'
     */
    UNICARPTMotor_Y->ToCM.Trq = UNICARPTMotor_B->Switch4;
    UNICARPTMotor_Y->ToCM.Inert = UNICARPTMotor_P.mot_J_kgm_2;
    UNICARPTMotor_Y->ToCM.PwrElec = UNICARPTMotor_B->Gain;

    /* Product: '<S5>/Divide1' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Constant: '<S5>/Constant4'
     *  Gain: '<S5>/Gain2'
     */
    UNICARPTMotor_B->denominator1 = 1.0 / UNICARPTMotor_P.mot_TPT2_1_s *
      (UNICARPTMotor_P.Gain2_Gain * UNICARPTMotor_P.mot_dPT2);
  }

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant4'
   *  Inport: '<Root>/FromCM'
   *  Integrator: '<S4>/Integrator'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   */
  UNICARPTMotor_B->M_ist_p = UNICARPTMotor_U->FromCM.Load *
    UNICARPTMotor_P.mot_KPT1 - UNICARPTMotor_X->Integrator_CSTATE *
    UNICARPTMotor_P.mot_TPT1_1_s;

  /* Integrator: '<S5>/Integrator' */
  UNICARPTMotor_B->M_ist_p_f = UNICARPTMotor_X->Integrator_CSTATE_i;
  if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
    /* Math: '<S5>/Square2' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    rtb_Square2 = UNICARPTMotor_P.mot_TPT2_1_s * UNICARPTMotor_P.mot_TPT2_1_s;

    /* Product: '<S5>/Product5' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    UNICARPTMotor_B->numerator1 = UNICARPTMotor_P.mot_KPT2 / rtb_Square2;

    /* Product: '<S5>/Product8' incorporates:
     *  Constant: '<S5>/Constant3'
     */
    UNICARPTMotor_B->denominator2 = 1.0 / rtb_Square2 *
      UNICARPTMotor_P.Constant3_Value;
  }

  /* Sum: '<S5>/Sum' incorporates:
   *  Inport: '<Root>/FromCM'
   *  Integrator: '<S5>/Integrator1'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   */
  UNICARPTMotor_B->M_ist_pp = (UNICARPTMotor_U->FromCM.Load *
    UNICARPTMotor_B->numerator1 - UNICARPTMotor_B->M_ist_p_f *
    UNICARPTMotor_B->denominator1) - UNICARPTMotor_X->Integrator1_CSTATE *
    UNICARPTMotor_B->denominator2;
  if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
    if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
      /* Update for Memory: '<S3>/Memory' */
      UNICARPTMotor_DW->Memory_PreviousInput = UNICARPTMotor_B->Add1;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(UNICARPTMotor_M)) {
    rt_ertODEUpdateContinuousStates(UNICARPTMotor_M->solverInfo, UNICARPTMotor_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++UNICARPTMotor_M->Timing.clockTick0)) {
      ++UNICARPTMotor_M->Timing.clockTickH0;
    }

    UNICARPTMotor_M->Timing.t[0] = rtsiGetSolverStopTime
      (UNICARPTMotor_M->solverInfo);

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
      UNICARPTMotor_M->Timing.clockTick1++;
      if (!UNICARPTMotor_M->Timing.clockTick1) {
        UNICARPTMotor_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void UNICARPTMotor_derivatives(RT_MODEL_UNICARPTMotor_T *const UNICARPTMotor_M)
{
  B_UNICARPTMotor_T *UNICARPTMotor_B = ((B_UNICARPTMotor_T *)
    UNICARPTMotor_M->blockIO);
  XDot_UNICARPTMotor_T *_rtXdot;
  _rtXdot = ((XDot_UNICARPTMotor_T *) UNICARPTMotor_M->derivs);

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = UNICARPTMotor_B->M_ist_p_f;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = UNICARPTMotor_B->M_ist_p;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = UNICARPTMotor_B->M_ist_pp;
}

/* Model initialize function */
void UNICARPTMotor_initialize(RT_MODEL_UNICARPTMotor_T *const UNICARPTMotor_M)
{
  DW_UNICARPTMotor_T *UNICARPTMotor_DW = ((DW_UNICARPTMotor_T *)
    UNICARPTMotor_M->dwork);
  X_UNICARPTMotor_T *UNICARPTMotor_X = ((X_UNICARPTMotor_T *)
    UNICARPTMotor_M->contStates);

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  UNICARPTMotor_X->Integrator1_CSTATE = UNICARPTMotor_P.Integrator1_IC;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  UNICARPTMotor_DW->Memory_PreviousInput =
    UNICARPTMotor_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  UNICARPTMotor_X->Integrator_CSTATE = UNICARPTMotor_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  UNICARPTMotor_X->Integrator_CSTATE_i = UNICARPTMotor_P.Integrator_IC_e;
}

/* Model terminate function */
void UNICARPTMotor_terminate(RT_MODEL_UNICARPTMotor_T * UNICARPTMotor_M)
{
  rt_FREE(UNICARPTMotor_M->solverInfo);

  /* model code */
  rt_FREE(UNICARPTMotor_M->blockIO);
  rt_FREE(UNICARPTMotor_M->contStates);
  rt_FREE(UNICARPTMotor_M->inputs);
  rt_FREE(UNICARPTMotor_M->outputs);
  rt_FREE(UNICARPTMotor_M->dwork);
  rt_FREE(UNICARPTMotor_M);
}

/* Model data allocation function */
RT_MODEL_UNICARPTMotor_T *UNICARPTMotor(struct tInfos *inf)
{
  RT_MODEL_UNICARPTMotor_T *UNICARPTMotor_M;
  UNICARPTMotor_M = (RT_MODEL_UNICARPTMotor_T *) malloc(sizeof
    (RT_MODEL_UNICARPTMotor_T));
  if (UNICARPTMotor_M == NULL) {
    return NULL;
  }

  (void) memset((char *)UNICARPTMotor_M, 0,
                sizeof(RT_MODEL_UNICARPTMotor_T));
  MatSupp_Init();

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(UNICARPTMotor_M,rt_SolverInfo);
    UNICARPTMotor_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(UNICARPTMotor_M->solverInfo,
                          &UNICARPTMotor_M->Timing.simTimeStep);
    rtsiSetTPtr(UNICARPTMotor_M->solverInfo, &rtmGetTPtr(UNICARPTMotor_M));
    rtsiSetStepSizePtr(UNICARPTMotor_M->solverInfo,
                       &UNICARPTMotor_M->Timing.stepSize0);
    rtsiSetdXPtr(UNICARPTMotor_M->solverInfo, &UNICARPTMotor_M->derivs);
    rtsiSetContStatesPtr(UNICARPTMotor_M->solverInfo, (real_T **)
                         &UNICARPTMotor_M->contStates);
    rtsiSetNumContStatesPtr(UNICARPTMotor_M->solverInfo,
      &UNICARPTMotor_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(UNICARPTMotor_M->solverInfo,
      &UNICARPTMotor_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(UNICARPTMotor_M->solverInfo,
      &UNICARPTMotor_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(UNICARPTMotor_M->solverInfo,
      &UNICARPTMotor_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(UNICARPTMotor_M->solverInfo, (&rtmGetErrorStatus
      (UNICARPTMotor_M)));
    rtsiSetRTModelPtr(UNICARPTMotor_M->solverInfo, UNICARPTMotor_M);
  }

  rtsiSetSolverName(UNICARPTMotor_M->solverInfo,"ode1");

  /* block I/O */
  {
    B_UNICARPTMotor_T *b = (B_UNICARPTMotor_T *) malloc(sizeof(B_UNICARPTMotor_T));
    rt_VALIDATE_MEMORY(UNICARPTMotor_M,b);
    UNICARPTMotor_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    real_T *x = (real_T *) malloc(sizeof(X_UNICARPTMotor_T));
    rt_VALIDATE_MEMORY(UNICARPTMotor_M,x);
    UNICARPTMotor_M->contStates = (x);
  }

  /* states (dwork) */
  {
    DW_UNICARPTMotor_T *dwork = (DW_UNICARPTMotor_T *) malloc(sizeof
      (DW_UNICARPTMotor_T));
    rt_VALIDATE_MEMORY(UNICARPTMotor_M,dwork);
    UNICARPTMotor_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_UNICARPTMotor_T *UNICARPTMotor_U = (ExtU_UNICARPTMotor_T *) malloc
      (sizeof(ExtU_UNICARPTMotor_T));
    rt_VALIDATE_MEMORY(UNICARPTMotor_M,UNICARPTMotor_U);
    UNICARPTMotor_M->inputs = (((ExtU_UNICARPTMotor_T *) UNICARPTMotor_U));
  }

  /* external outputs */
  {
    ExtY_UNICARPTMotor_T *UNICARPTMotor_Y = (ExtY_UNICARPTMotor_T *) malloc
      (sizeof(ExtY_UNICARPTMotor_T));
    rt_VALIDATE_MEMORY(UNICARPTMotor_M,UNICARPTMotor_Y);
    UNICARPTMotor_M->outputs = (UNICARPTMotor_Y);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  UNICARPTMotor_InitializeDataMapInfo(UNICARPTMotor_M);

  /* CarMaker parameter tuning */
  {
    const struct tMatSuppMMI *mmi = &(rtmGetDataMapInfo(UNICARPTMotor_M).mmi);
    tMatSuppTunables *tuns = MatSupp_TunBegin("UNICARPTMotor", mmi);
    UNICARPTMotor_SetParams(UNICARPTMotor_M, tuns, inf);
    MatSupp_TunEnd(tuns);
  }

  {
    B_UNICARPTMotor_T *UNICARPTMotor_B = ((B_UNICARPTMotor_T *)
      UNICARPTMotor_M->blockIO);
    DW_UNICARPTMotor_T *UNICARPTMotor_DW = ((DW_UNICARPTMotor_T *)
      UNICARPTMotor_M->dwork);
    X_UNICARPTMotor_T *UNICARPTMotor_X = ((X_UNICARPTMotor_T *)
      UNICARPTMotor_M->contStates);
    ExtU_UNICARPTMotor_T *UNICARPTMotor_U = (ExtU_UNICARPTMotor_T *)
      UNICARPTMotor_M->inputs;
    ExtY_UNICARPTMotor_T *UNICARPTMotor_Y = (ExtY_UNICARPTMotor_T *)
      UNICARPTMotor_M->outputs;
    rtsiSetSimTimeStep(UNICARPTMotor_M->solverInfo, MAJOR_TIME_STEP);
    UNICARPTMotor_M->intgData.f[0] = UNICARPTMotor_M->odeF[0];
    UNICARPTMotor_M->contStates = ((real_T *) UNICARPTMotor_X);
    rtsiSetSolverData(UNICARPTMotor_M->solverInfo, (void *)
                      &UNICARPTMotor_M->intgData);
    rtmSetTPtr(UNICARPTMotor_M, &UNICARPTMotor_M->Timing.tArray[0]);
    UNICARPTMotor_M->Timing.stepSize0 = 0.0002;

    /* block I/O */
    (void) memset(((void *) UNICARPTMotor_B), 0,
                  sizeof(B_UNICARPTMotor_T));

    /* states (continuous) */
    {
      (void) memset((void *)UNICARPTMotor_X, 0,
                    sizeof(X_UNICARPTMotor_T));
    }

    /* states (dwork) */
    (void) memset((void *)UNICARPTMotor_DW, 0,
                  sizeof(DW_UNICARPTMotor_T));

    /* external inputs */
    (void)memset(UNICARPTMotor_U, 0, sizeof(ExtU_UNICARPTMotor_T));

    /* external outputs */
    UNICARPTMotor_Y->ToCM = UNICARPTMotor_rtZcmPTMotorOut;
  }

  return UNICARPTMotor_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *UNICARPTMotor_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)UNICARPTMotor_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *UNICARPTMotor_DictDefines = DictDefines;
tQuantEntry *UNICARPTMotor_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *UNICARPTMotor_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)UNICARPTMotor_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *UNICARPTMotor_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *UNICARPTMotor_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
