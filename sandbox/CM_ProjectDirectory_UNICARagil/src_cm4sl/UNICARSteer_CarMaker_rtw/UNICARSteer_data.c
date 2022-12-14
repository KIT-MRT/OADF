/*
 * UNICARSteer_data.c
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

#include "UNICARSteer.h"
#include "UNICARSteer_private.h"

/* Block parameters (default storage) */
P_UNICARSteer_T UNICARSteer_P = {
  /* Variable: ste_KPT1
   * Referenced by:
   *   '<S7>/Gain2'
   *   '<S8>/Gain2'
   *   '<S9>/Gain2'
   *   '<S10>/Gain2'
   */
  1.0,

  /* Variable: ste_TPT1_1_s
   * Referenced by:
   *   '<S7>/Constant1'
   *   '<S8>/Constant1'
   *   '<S9>/Constant1'
   *   '<S10>/Constant1'
   */
  0.13,

  /* Variable: ste_delta_p_lim_rad_s
   * Referenced by:
   *   '<S7>/Constant2'
   *   '<S8>/Constant2'
   *   '<S9>/Constant2'
   *   '<S10>/Constant2'
   */
  1.57,

  /* Variable: ste_dyn
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Variable: ste_max_delta_FLRR_rad
   * Referenced by:
   *   '<S2>/Saturation'
   *   '<S2>/Saturation3'
   */
  1.5707963267948966,

  /* Variable: ste_max_delta_FRRL_rad
   * Referenced by:
   *   '<S2>/Saturation1'
   *   '<S2>/Saturation2'
   */
  1.0471975511965976,

  /* Variable: ste_min_delta_FLRR_rad
   * Referenced by:
   *   '<S2>/Saturation'
   *   '<S2>/Saturation3'
   */
  -1.0471975511965976,

  /* Variable: ste_min_delta_FRRL_rad
   * Referenced by:
   *   '<S2>/Saturation1'
   *   '<S2>/Saturation2'
   */
  -1.5707963267948966,

  /* Variable: ste_t_s
   * Referenced by:
   *   '<S7>/Constant'
   *   '<S8>/Constant'
   *   '<S9>/Constant'
   *   '<S10>/Constant'
   */
  0.001,

  /* Expression: -1
   * Referenced by: '<S7>/Gain9'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S8>/Gain9'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S9>/Gain9'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S10>/Gain9'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Ang'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/AngVel'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/AngAcc'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Trq'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/TrqStatic'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/AssistFrc'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/AssistTrqCol'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/AssistTrqPin'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/iSteer2q_L'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/iSteer2q_R'
   */
  0.0
};
