/*
 * UNICARPTControl_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARPTControl".
 *
 * Model version              : 1.49
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:29:19 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UNICARPTControl.h"
#include "UNICARPTControl_private.h"

/* Block parameters (default storage) */
P_UNICARPTControl_T UNICARPTControl_P = {
  /* Variable: PTC_RotLim
   * Referenced by:
   *   '<S6>/1-D Lookup Table'
   *   '<S10>/1-D Lookup Table'
   *   '<S14>/1-D Lookup Table'
   *   '<S18>/1-D Lookup Table'
   */
  { -1000.0, 0.005, 0.015, 1000.0 },

  /* Variable: PTC_T_1_s
   * Referenced by:
   *   '<S6>/Constant2'
   *   '<S10>/Constant2'
   *   '<S14>/Constant2'
   *   '<S18>/Constant2'
   */
  0.1,

  /* Variable: PTC_weight
   * Referenced by:
   *   '<S6>/1-D Lookup Table'
   *   '<S10>/1-D Lookup Table'
   *   '<S14>/1-D Lookup Table'
   *   '<S18>/1-D Lookup Table'
   */
  { 0.0, 0.0, 1.0, 1.0 },

  /* Expression: 0.01
   * Referenced by: '<S6>/Constant3'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S6>/Switch1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S6>/Switch'
   */
  0.2,

  /* Expression: -1
   * Referenced by: '<S6>/Gain1'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S10>/Constant3'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S10>/Switch1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S10>/Switch'
   */
  0.2,

  /* Expression: -1
   * Referenced by: '<S10>/Gain1'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S14>/Constant3'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S14>/Switch1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S14>/Switch'
   */
  0.2,

  /* Expression: -1
   * Referenced by: '<S14>/Gain1'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S18>/Constant3'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S18>/Switch1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S18>/Switch'
   */
  0.2,

  /* Expression: -1
   * Referenced by: '<S18>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Constant'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S10>/Constant'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Switch2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S14>/Constant'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Switch2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S18>/Constant'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S21>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S21>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Switch2'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<Root>/Constant3'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/StrategyMode'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/EngineOut.set_ISC'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/EngineOut.FuelCutOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/EngineOut.Load'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/EngineOut.Trq_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/EngineOut.rotv_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ISGOut.Load'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ISGOut.Trq_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ISGOut.rotv_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m0.Load'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m0.rotv_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m1.Load'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m1.rotv_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m2.Load'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m2.rotv_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m3.Load'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/MotorOut.m3.rotv_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ClutchOut.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.GearNoTrg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.GearNoTrg_dis'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.i_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.set_ParkBrake'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.rotv_in_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Clutch.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Clutch.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Clutch.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Clutch_dis.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Clutch_dis.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxOut.Clutch_dis.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.GearNoTrg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.GearNoTrg_dis'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.i_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.set_ParkBrake'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.rotv_in_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.GearNoTrg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.GearNoTrg_dis'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.i_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.set_ParkBrake'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.rotv_in_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.GearNoTrg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.GearNoTrg_dis'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.i_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.set_ParkBrake'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.rotv_in_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.GearNoTrg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.GearNoTrg_dis'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.i_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.set_ParkBrake'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.rotv_in_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.Pos'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.rotv_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.Trq_out_trg'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/PwrSupplyOut.Pwr_HV1toLV_trg'
   */
  0.0
};
