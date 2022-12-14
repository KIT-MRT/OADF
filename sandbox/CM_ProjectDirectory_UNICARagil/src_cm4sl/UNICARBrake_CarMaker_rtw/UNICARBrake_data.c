/*
 * UNICARBrake_data.c
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

#include "UNICARBrake.h"
#include "UNICARBrake_private.h"

/* Block parameters (default storage) */
P_UNICARBrake_T UNICARBrake_P = {
  /* Variable: brk_ABS
   * Referenced by:
   *   '<S8>/ABS_on_off'
   *   '<S18>/ABS_on_off'
   *   '<S28>/ABS_on_off'
   *   '<S38>/ABS_on_off'
   */
  1.0,

  /* Variable: brk_Kacc
   * Referenced by:
   *   '<S9>/Constant3'
   *   '<S19>/Constant3'
   *   '<S29>/Constant3'
   *   '<S39>/Constant3'
   */
  0.01,

  /* Variable: brk_Kslip
   * Referenced by:
   *   '<S9>/Gain'
   *   '<S19>/Gain'
   *   '<S29>/Gain'
   *   '<S39>/Gain'
   */
  1.0,

  /* Variable: brk_SKlow
   * Referenced by:
   *   '<S9>/Constant1'
   *   '<S19>/Constant1'
   *   '<S29>/Constant1'
   *   '<S39>/Constant1'
   */
  0.15,

  /* Variable: brk_SKup
   * Referenced by:
   *   '<S9>/Constant4'
   *   '<S19>/Constant4'
   *   '<S29>/Constant4'
   *   '<S39>/Constant4'
   */
  0.2,

  /* Variable: brk_TKeep_1_s
   * Referenced by:
   *   '<S14>/Constant2'
   *   '<S24>/Constant2'
   *   '<S34>/Constant2'
   *   '<S44>/Constant2'
   */
  2.5,

  /* Variable: brk_TRai_1_s
   * Referenced by:
   *   '<S13>/Constant2'
   *   '<S23>/Constant2'
   *   '<S33>/Constant2'
   *   '<S43>/Constant2'
   */
  0.055563169839672,

  /* Variable: brk_TRed_1_s
   * Referenced by:
   *   '<S15>/Constant2'
   *   '<S25>/Constant2'
   *   '<S35>/Constant2'
   *   '<S45>/Constant2'
   */
  0.125,

  /* Variable: brk_area_m_2
   * Referenced by:
   *   '<S11>/Constant'
   *   '<S21>/Constant'
   *   '<S31>/Constant'
   *   '<S41>/Constant'
   */
  0.005000000000000001,

  /* Variable: brk_dyn
   * Referenced by:
   *   '<S11>/Constant4'
   *   '<S21>/Constant4'
   *   '<S31>/Constant4'
   *   '<S41>/Constant4'
   */
  1.0,

  /* Variable: brk_i
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
  3.138,

  /* Variable: brk_mue
   * Referenced by:
   *   '<S11>/Constant2'
   *   '<S21>/Constant2'
   *   '<S31>/Constant2'
   *   '<S41>/Constant2'
   */
  1.5,

  /* Variable: brk_pMax_pa
   * Referenced by:
   *   '<S11>/Constant3'
   *   '<S21>/Constant3'
   *   '<S31>/Constant3'
   *   '<S41>/Constant3'
   */
  1.8E+7,

  /* Variable: brk_parking_trq
   * Referenced by: '<S6>/Constant3'
   */
  { 2000.0, 2000.0, 2000.0, 2000.0 },

  /* Variable: brk_r_m
   * Referenced by:
   *   '<S11>/Constant1'
   *   '<S21>/Constant1'
   *   '<S31>/Constant1'
   *   '<S41>/Constant1'
   */
  0.2,

  /* Variable: brk_tDel_s
   * Referenced by:
   *   '<S11>/Transport Delay'
   *   '<S21>/Transport Delay'
   *   '<S31>/Transport Delay'
   *   '<S41>/Transport Delay'
   */
  0.02,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S17>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S27>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_i
   * Referenced by: '<S37>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Switch1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Switch2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S21>/Switch1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S21>/Switch2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S31>/Switch1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S31>/Switch2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S41>/Switch1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S41>/Switch2'
   */
  1.0,

  /* Expression: [0, 0, 0, 0]
   * Referenced by: '<S6>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S16>/Constant4'
   */
  0.0,

  /* Computed Parameter: ABSon_A
   * Referenced by: '<S11>/ABS on'
   */
  -64.680679413189381,

  /* Computed Parameter: ABSon_C
   * Referenced by: '<S11>/ABS on'
   */
  64.680679413189381,

  /* Computed Parameter: ABSoff_A
   * Referenced by: '<S11>/ABS off'
   */
  { -82.678212723213051, -1164.0926822538388 },

  /* Computed Parameter: ABSoff_C
   * Referenced by: '<S11>/ABS off'
   */
  { 0.0, 1164.0926822538388 },

  /* Expression: 0
   * Referenced by: '<S16>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Transport Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Constant4'
   */
  0.0,

  /* Computed Parameter: ABSon_A_h
   * Referenced by: '<S21>/ABS on'
   */
  -64.680679413189381,

  /* Computed Parameter: ABSon_C_g
   * Referenced by: '<S21>/ABS on'
   */
  64.680679413189381,

  /* Computed Parameter: ABSoff_A_l
   * Referenced by: '<S21>/ABS off'
   */
  { -82.678212723213051, -1164.0926822538388 },

  /* Computed Parameter: ABSoff_C_b
   * Referenced by: '<S21>/ABS off'
   */
  { 0.0, 1164.0926822538388 },

  /* Expression: 0
   * Referenced by: '<S26>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S18>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Transport Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant4'
   */
  0.0,

  /* Computed Parameter: ABSon_A_c
   * Referenced by: '<S31>/ABS on'
   */
  -64.680679413189381,

  /* Computed Parameter: ABSon_C_e
   * Referenced by: '<S31>/ABS on'
   */
  64.680679413189381,

  /* Computed Parameter: ABSoff_A_j
   * Referenced by: '<S31>/ABS off'
   */
  { -82.678212723213051, -1164.0926822538388 },

  /* Computed Parameter: ABSoff_C_n
   * Referenced by: '<S31>/ABS off'
   */
  { 0.0, 1164.0926822538388 },

  /* Expression: 0
   * Referenced by: '<S36>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S32>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S32>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S28>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S31>/Transport Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Constant4'
   */
  0.0,

  /* Computed Parameter: ABSon_A_m
   * Referenced by: '<S41>/ABS on'
   */
  -64.680679413189381,

  /* Computed Parameter: ABSon_C_ed
   * Referenced by: '<S41>/ABS on'
   */
  64.680679413189381,

  /* Computed Parameter: ABSoff_A_h
   * Referenced by: '<S41>/ABS off'
   */
  { -82.678212723213051, -1164.0926822538388 },

  /* Computed Parameter: ABSoff_C_k
   * Referenced by: '<S41>/ABS off'
   */
  { 0.0, 1164.0926822538388 },

  /* Expression: 0
   * Referenced by: '<S46>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S42>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S42>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S38>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S41>/Transport Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Trq_DriveSrc_trg.d0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Trq_DriveSrc_trg.d1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Trq_DriveSrc_trg.d2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Trq_DriveSrc_trg.d3'
   */
  0.0,

  /* Start of '<S39>/keep pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S44>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S39>/keep pressure' */

  /* Start of '<S39>/free pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S43>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S39>/free pressure' */

  /* Start of '<S39>/reduce pressure' */
  {
    /* Expression: 0
     * Referenced by: '<S45>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S39>/reduce pressure' */

  /* Start of '<S29>/keep pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S34>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S29>/keep pressure' */

  /* Start of '<S29>/free pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S33>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S29>/free pressure' */

  /* Start of '<S29>/reduce pressure' */
  {
    /* Expression: 0
     * Referenced by: '<S35>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S29>/reduce pressure' */

  /* Start of '<S19>/keep pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S24>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S19>/keep pressure' */

  /* Start of '<S19>/free pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S23>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S19>/free pressure' */

  /* Start of '<S19>/reduce pressure' */
  {
    /* Expression: 0
     * Referenced by: '<S25>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S19>/reduce pressure' */

  /* Start of '<S9>/keep pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S14>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S9>/keep pressure' */

  /* Start of '<S9>/free pressure' */
  {
    /* Expression: 1
     * Referenced by: '<S13>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S9>/free pressure' */

  /* Start of '<S9>/reduce pressure' */
  {
    /* Expression: 0
     * Referenced by: '<S15>/Constant1'
     */
    0.0
  }
  /* End of '<S9>/reduce pressure' */
};
