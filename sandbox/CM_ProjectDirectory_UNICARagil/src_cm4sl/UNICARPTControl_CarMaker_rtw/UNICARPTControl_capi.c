/*
 * UNICARPTControl_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNICARPTControl_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "UNICARPTControl.h"
#include "UNICARPTControl_capi.h"
#include "UNICARPTControl_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 0, TARGET_STRING("UNICARPTControl/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1, TARGET_STRING("UNICARPTControl/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 2, TARGET_STRING("UNICARPTControl/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 3, TARGET_STRING("UNICARPTControl/IF_Out_Selector/ClutchOut.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 4, TARGET_STRING("UNICARPTControl/IF_Out_Selector/ClutchOut.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 5, TARGET_STRING("UNICARPTControl/IF_Out_Selector/ClutchOut.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 6, TARGET_STRING("UNICARPTControl/IF_Out_Selector/EngineOut.FuelCutOff"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 7, TARGET_STRING("UNICARPTControl/IF_Out_Selector/EngineOut.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 8, TARGET_STRING("UNICARPTControl/IF_Out_Selector/EngineOut.Trq_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 9, TARGET_STRING("UNICARPTControl/IF_Out_Selector/EngineOut.rotv_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 10, TARGET_STRING("UNICARPTControl/IF_Out_Selector/EngineOut.set_ISC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 11, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Clutch.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 12, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Clutch.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 13, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Clutch.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 14, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Clutch_dis.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 15, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Clutch_dis.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 16, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Clutch_dis.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 17, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.GearNoTrg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 18, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.GearNoTrg_dis"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 19, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 20, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.i_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 21, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.rotv_in_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 22, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m0.set_ParkBrake"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 23, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Clutch.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 24, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Clutch.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 25, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Clutch.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 26, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Clutch_dis.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 27, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Clutch_dis.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 28, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Clutch_dis.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 29, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.GearNoTrg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 30, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.GearNoTrg_dis"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 31, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 32, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.i_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 33, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.rotv_in_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 34, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m1.set_ParkBrake"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 35, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Clutch.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 36, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Clutch.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 37, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Clutch.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 38, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Clutch_dis.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 39, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Clutch_dis.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 40, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Clutch_dis.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 41, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.GearNoTrg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 42, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.GearNoTrg_dis"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 43, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 44, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.i_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 45, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.rotv_in_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 46, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m2.set_ParkBrake"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 47, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Clutch.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 48, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Clutch.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 49, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Clutch.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 50, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Clutch_dis.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 51, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Clutch_dis.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 52, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Clutch_dis.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 53, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.GearNoTrg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 54, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.GearNoTrg_dis"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 55, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 56, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.i_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 57, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.rotv_in_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 58, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxM_Out.GB_m3.set_ParkBrake"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 59, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Clutch.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 60, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Clutch.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 61, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Clutch.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 62, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Clutch_dis.Pos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 63, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Clutch_dis.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 64, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Clutch_dis.rotv_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 65, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.GearNoTrg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 66, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.GearNoTrg_dis"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 67, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.Trq_out_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 68, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.i_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 69, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.rotv_in_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 70, TARGET_STRING("UNICARPTControl/IF_Out_Selector/GearBoxOut.set_ParkBrake"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 71, TARGET_STRING("UNICARPTControl/IF_Out_Selector/ISGOut.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 72, TARGET_STRING("UNICARPTControl/IF_Out_Selector/ISGOut.Trq_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 73, TARGET_STRING("UNICARPTControl/IF_Out_Selector/ISGOut.rotv_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 74, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m0.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 75, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m0.rotv_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 76, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m1.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 77, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m1.rotv_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 78, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m2.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 79, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m2.rotv_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 80, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m3.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 81, TARGET_STRING("UNICARPTControl/IF_Out_Selector/MotorOut.m3.rotv_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 82, TARGET_STRING("UNICARPTControl/IF_Out_Selector/PwrSupplyOut.Pwr_HV1toLV_trg"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 83, TARGET_STRING("UNICARPTControl/IF_Out_Selector/StrategyMode"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 84, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 85, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 86, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 87, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 88, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 89, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 90, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 91, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 92, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 93, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 94, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 95, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 96, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 97, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 98, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 99, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 100, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 101, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 102, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 103, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 104, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 105, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 106, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 107, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 108, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 109, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 110, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 111, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 112, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/ErrBit Handling/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 113, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/ErrBit Handling/Switch3"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 114, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Tiefpass/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 115, TARGET_STRING("UNICARPTControl/PTControl0/PTControl Generic/Tiefpass/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 116, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/ErrBit Handling/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 117, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/ErrBit Handling/Switch3"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 118, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Tiefpass/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 119, TARGET_STRING("UNICARPTControl/PTControl1/PTControl Generic/Tiefpass/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 120, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/ErrBit Handling/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 121, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/ErrBit Handling/Switch3"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 122, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Tiefpass/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 123, TARGET_STRING("UNICARPTControl/PTControl2/PTControl Generic/Tiefpass/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 124, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/ErrBit Handling/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 125, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/ErrBit Handling/Switch3"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 126, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Tiefpass/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 127, TARGET_STRING("UNICARPTControl/PTControl3/PTControl Generic/Tiefpass/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 128, TARGET_STRING("PTC_RotLim"), 0, 1, 0 },

  { 129, TARGET_STRING("PTC_T_1_s"), 0, 0, 0 },

  { 130, TARGET_STRING("PTC_weight"), 0, 1, 0 },

  { 0, (NULL), 0, 0, 0 }
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  4                                    /* 3 */
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  {
    (NULL), (NULL), 0, 0
  }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { (NULL), 0,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 128,
    rtModelParameters, 3 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3445310901U,
    974453113U,
    2717992216U,
    23100777U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTControl_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void UNICARPTControl_InitializeDataMapInfo(RT_MODEL_UNICARPTControl_T *const
  UNICARPTControl_M)
{
  /* run-time setup of addresses */
  void* *rtDataAddrMap;
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(UNICARPTControl_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(131 * sizeof(void* ));
  if ((rtDataAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTControl_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtDataAddrMap[0] = (void* )(&UNICARPTControl_P.Constant2_Value);
  rtDataAddrMap[1] = (void* )(&UNICARPTControl_P.Constant3_Value_k);
  rtDataAddrMap[2] = (void* )(&UNICARPTControl_P.Constant4_Value);
  rtDataAddrMap[3] = (void* )(&UNICARPTControl_P.ClutchOutPos_Value);
  rtDataAddrMap[4] = (void* )(&UNICARPTControl_P.ClutchOutTrq_out_trg_Value);
  rtDataAddrMap[5] = (void* )(&UNICARPTControl_P.ClutchOutrotv_out_trg_Value);
  rtDataAddrMap[6] = (void* )(&UNICARPTControl_P.EngineOutFuelCutOff_Value);
  rtDataAddrMap[7] = (void* )(&UNICARPTControl_P.EngineOutLoad_Value);
  rtDataAddrMap[8] = (void* )(&UNICARPTControl_P.EngineOutTrq_trg_Value);
  rtDataAddrMap[9] = (void* )(&UNICARPTControl_P.EngineOutrotv_trg_Value);
  rtDataAddrMap[10] = (void* )(&UNICARPTControl_P.EngineOutset_ISC_Value);
  rtDataAddrMap[11] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0ClutchPos_Value);
  rtDataAddrMap[12] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0ClutchTrq_out_trg_Value);
  rtDataAddrMap[13] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0Clutchrotv_out_trg_Value);
  rtDataAddrMap[14] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0Clutch_disPos_Value);
  rtDataAddrMap[15] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0Clutch_disTrq_out_trg_Value);
  rtDataAddrMap[16] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0Clutch_disrotv_out_trg_Value);
  rtDataAddrMap[17] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0GearNoTrg_Value);
  rtDataAddrMap[18] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0GearNoTrg_dis_Value);
  rtDataAddrMap[19] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0Trq_out_trg_Value);
  rtDataAddrMap[20] = (void* )(&UNICARPTControl_P.GearBoxM_OutGB_m0i_trg_Value);
  rtDataAddrMap[21] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0rotv_in_trg_Value);
  rtDataAddrMap[22] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m0set_ParkBrake_Value);
  rtDataAddrMap[23] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1ClutchPos_Value);
  rtDataAddrMap[24] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1ClutchTrq_out_trg_Value);
  rtDataAddrMap[25] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1Clutchrotv_out_trg_Value);
  rtDataAddrMap[26] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1Clutch_disPos_Value);
  rtDataAddrMap[27] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1Clutch_disTrq_out_trg_Value);
  rtDataAddrMap[28] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1Clutch_disrotv_out_trg_Value);
  rtDataAddrMap[29] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1GearNoTrg_Value);
  rtDataAddrMap[30] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1GearNoTrg_dis_Value);
  rtDataAddrMap[31] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1Trq_out_trg_Value);
  rtDataAddrMap[32] = (void* )(&UNICARPTControl_P.GearBoxM_OutGB_m1i_trg_Value);
  rtDataAddrMap[33] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1rotv_in_trg_Value);
  rtDataAddrMap[34] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m1set_ParkBrake_Value);
  rtDataAddrMap[35] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2ClutchPos_Value);
  rtDataAddrMap[36] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2ClutchTrq_out_trg_Value);
  rtDataAddrMap[37] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2Clutchrotv_out_trg_Value);
  rtDataAddrMap[38] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2Clutch_disPos_Value);
  rtDataAddrMap[39] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2Clutch_disTrq_out_trg_Value);
  rtDataAddrMap[40] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2Clutch_disrotv_out_trg_Value);
  rtDataAddrMap[41] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2GearNoTrg_Value);
  rtDataAddrMap[42] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2GearNoTrg_dis_Value);
  rtDataAddrMap[43] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2Trq_out_trg_Value);
  rtDataAddrMap[44] = (void* )(&UNICARPTControl_P.GearBoxM_OutGB_m2i_trg_Value);
  rtDataAddrMap[45] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2rotv_in_trg_Value);
  rtDataAddrMap[46] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m2set_ParkBrake_Value);
  rtDataAddrMap[47] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3ClutchPos_Value);
  rtDataAddrMap[48] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3ClutchTrq_out_trg_Value);
  rtDataAddrMap[49] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3Clutchrotv_out_trg_Value);
  rtDataAddrMap[50] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3Clutch_disPos_Value);
  rtDataAddrMap[51] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3Clutch_disTrq_out_trg_Value);
  rtDataAddrMap[52] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3Clutch_disrotv_out_trg_Value);
  rtDataAddrMap[53] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3GearNoTrg_Value);
  rtDataAddrMap[54] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3GearNoTrg_dis_Value);
  rtDataAddrMap[55] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3Trq_out_trg_Value);
  rtDataAddrMap[56] = (void* )(&UNICARPTControl_P.GearBoxM_OutGB_m3i_trg_Value);
  rtDataAddrMap[57] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3rotv_in_trg_Value);
  rtDataAddrMap[58] = (void* )
    (&UNICARPTControl_P.GearBoxM_OutGB_m3set_ParkBrake_Value);
  rtDataAddrMap[59] = (void* )(&UNICARPTControl_P.GearBoxOutClutchPos_Value);
  rtDataAddrMap[60] = (void* )
    (&UNICARPTControl_P.GearBoxOutClutchTrq_out_trg_Value);
  rtDataAddrMap[61] = (void* )
    (&UNICARPTControl_P.GearBoxOutClutchrotv_out_trg_Value);
  rtDataAddrMap[62] = (void* )(&UNICARPTControl_P.GearBoxOutClutch_disPos_Value);
  rtDataAddrMap[63] = (void* )
    (&UNICARPTControl_P.GearBoxOutClutch_disTrq_out_trg_Value);
  rtDataAddrMap[64] = (void* )
    (&UNICARPTControl_P.GearBoxOutClutch_disrotv_out_trg_Value);
  rtDataAddrMap[65] = (void* )(&UNICARPTControl_P.GearBoxOutGearNoTrg_Value);
  rtDataAddrMap[66] = (void* )(&UNICARPTControl_P.GearBoxOutGearNoTrg_dis_Value);
  rtDataAddrMap[67] = (void* )(&UNICARPTControl_P.GearBoxOutTrq_out_trg_Value);
  rtDataAddrMap[68] = (void* )(&UNICARPTControl_P.GearBoxOuti_trg_Value);
  rtDataAddrMap[69] = (void* )(&UNICARPTControl_P.GearBoxOutrotv_in_trg_Value);
  rtDataAddrMap[70] = (void* )(&UNICARPTControl_P.GearBoxOutset_ParkBrake_Value);
  rtDataAddrMap[71] = (void* )(&UNICARPTControl_P.ISGOutLoad_Value);
  rtDataAddrMap[72] = (void* )(&UNICARPTControl_P.ISGOutTrq_trg_Value);
  rtDataAddrMap[73] = (void* )(&UNICARPTControl_P.ISGOutrotv_trg_Value);
  rtDataAddrMap[74] = (void* )(&UNICARPTControl_P.MotorOutm0Load_Value);
  rtDataAddrMap[75] = (void* )(&UNICARPTControl_P.MotorOutm0rotv_trg_Value);
  rtDataAddrMap[76] = (void* )(&UNICARPTControl_P.MotorOutm1Load_Value);
  rtDataAddrMap[77] = (void* )(&UNICARPTControl_P.MotorOutm1rotv_trg_Value);
  rtDataAddrMap[78] = (void* )(&UNICARPTControl_P.MotorOutm2Load_Value);
  rtDataAddrMap[79] = (void* )(&UNICARPTControl_P.MotorOutm2rotv_trg_Value);
  rtDataAddrMap[80] = (void* )(&UNICARPTControl_P.MotorOutm3Load_Value);
  rtDataAddrMap[81] = (void* )(&UNICARPTControl_P.MotorOutm3rotv_trg_Value);
  rtDataAddrMap[82] = (void* )
    (&UNICARPTControl_P.PwrSupplyOutPwr_HV1toLV_trg_Value);
  rtDataAddrMap[83] = (void* )(&UNICARPTControl_P.StrategyMode_Value);
  rtDataAddrMap[84] = (void* )(&UNICARPTControl_P.Constant_Value);
  rtDataAddrMap[85] = (void* )(&UNICARPTControl_P.Constant1_Value);
  rtDataAddrMap[86] = (void* )(&UNICARPTControl_P.Constant3_Value);
  rtDataAddrMap[87] = (void* )(&UNICARPTControl_P.Gain1_Gain);
  rtDataAddrMap[88] = (void* )(&UNICARPTControl_P.Switch_Threshold);
  rtDataAddrMap[89] = (void* )(&UNICARPTControl_P.Switch1_Threshold);
  rtDataAddrMap[90] = (void* )(&UNICARPTControl_P.Switch2_Threshold);
  rtDataAddrMap[91] = (void* )(&UNICARPTControl_P.Constant_Value_e);
  rtDataAddrMap[92] = (void* )(&UNICARPTControl_P.Constant1_Value_a);
  rtDataAddrMap[93] = (void* )(&UNICARPTControl_P.Constant3_Value_l);
  rtDataAddrMap[94] = (void* )(&UNICARPTControl_P.Gain1_Gain_g);
  rtDataAddrMap[95] = (void* )(&UNICARPTControl_P.Switch_Threshold_e);
  rtDataAddrMap[96] = (void* )(&UNICARPTControl_P.Switch1_Threshold_n);
  rtDataAddrMap[97] = (void* )(&UNICARPTControl_P.Switch2_Threshold_d);
  rtDataAddrMap[98] = (void* )(&UNICARPTControl_P.Constant_Value_a);
  rtDataAddrMap[99] = (void* )(&UNICARPTControl_P.Constant1_Value_m);
  rtDataAddrMap[100] = (void* )(&UNICARPTControl_P.Constant3_Value_n);
  rtDataAddrMap[101] = (void* )(&UNICARPTControl_P.Gain1_Gain_m);
  rtDataAddrMap[102] = (void* )(&UNICARPTControl_P.Switch_Threshold_k);
  rtDataAddrMap[103] = (void* )(&UNICARPTControl_P.Switch1_Threshold_n2);
  rtDataAddrMap[104] = (void* )(&UNICARPTControl_P.Switch2_Threshold_m);
  rtDataAddrMap[105] = (void* )(&UNICARPTControl_P.Constant_Value_g);
  rtDataAddrMap[106] = (void* )(&UNICARPTControl_P.Constant1_Value_j);
  rtDataAddrMap[107] = (void* )(&UNICARPTControl_P.Constant3_Value_a);
  rtDataAddrMap[108] = (void* )(&UNICARPTControl_P.Gain1_Gain_o);
  rtDataAddrMap[109] = (void* )(&UNICARPTControl_P.Switch_Threshold_d);
  rtDataAddrMap[110] = (void* )(&UNICARPTControl_P.Switch1_Threshold_c);
  rtDataAddrMap[111] = (void* )(&UNICARPTControl_P.Switch2_Threshold_j);
  rtDataAddrMap[112] = (void* )(&UNICARPTControl_P.Constant6_Value);
  rtDataAddrMap[113] = (void* )(&UNICARPTControl_P.Switch3_Threshold);
  rtDataAddrMap[114] = (void* )(&UNICARPTControl_P.Memory_InitialCondition);
  rtDataAddrMap[115] = (void* )(&UNICARPTControl_P.Memory1_InitialCondition);
  rtDataAddrMap[116] = (void* )(&UNICARPTControl_P.Constant6_Value_i);
  rtDataAddrMap[117] = (void* )(&UNICARPTControl_P.Switch3_Threshold_o);
  rtDataAddrMap[118] = (void* )(&UNICARPTControl_P.Memory_InitialCondition_j);
  rtDataAddrMap[119] = (void* )(&UNICARPTControl_P.Memory1_InitialCondition_f);
  rtDataAddrMap[120] = (void* )(&UNICARPTControl_P.Constant6_Value_g);
  rtDataAddrMap[121] = (void* )(&UNICARPTControl_P.Switch3_Threshold_j);
  rtDataAddrMap[122] = (void* )(&UNICARPTControl_P.Memory_InitialCondition_g);
  rtDataAddrMap[123] = (void* )(&UNICARPTControl_P.Memory1_InitialCondition_i);
  rtDataAddrMap[124] = (void* )(&UNICARPTControl_P.Constant6_Value_k);
  rtDataAddrMap[125] = (void* )(&UNICARPTControl_P.Switch3_Threshold_n);
  rtDataAddrMap[126] = (void* )(&UNICARPTControl_P.Memory_InitialCondition_n);
  rtDataAddrMap[127] = (void* )(&UNICARPTControl_P.Memory1_InitialCondition_k);
  rtDataAddrMap[128] = (void* )(&UNICARPTControl_P.PTC_RotLim[0]);
  rtDataAddrMap[129] = (void* )(&UNICARPTControl_P.PTC_T_1_s);
  rtDataAddrMap[130] = (void* )(&UNICARPTControl_P.PTC_weight[0]);
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(UNICARPTControl_M->DataMapInfo.mmi) )
          );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  if ((rtVarDimsAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTControl_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtVarDimsAddrMap[0] = (int32_T* )((NULL));

  /* Set C-API version */
  rtwCAPI_SetVersion(UNICARPTControl_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(UNICARPTControl_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(UNICARPTControl_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(UNICARPTControl_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(UNICARPTControl_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(UNICARPTControl_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(UNICARPTControl_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(UNICARPTControl_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void UNICARPTControl_host_InitializeDataMapInfo
    (UNICARPTControl_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: UNICARPTControl_capi.c */
