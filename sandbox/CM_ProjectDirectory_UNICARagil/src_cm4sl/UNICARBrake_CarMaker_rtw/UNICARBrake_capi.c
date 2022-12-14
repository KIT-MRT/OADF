/*
 * UNICARBrake_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNICARBrake_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "UNICARBrake.h"
#include "UNICARBrake_capi.h"
#include "UNICARBrake_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("UNICARBrake/Brake FL/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("UNICARBrake/Brake FL/Read CM Dict"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 0, TARGET_STRING("UNICARBrake/Brake FL/Read CM Dict1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 3, 0, TARGET_STRING("UNICARBrake/Brake FL/Read CM Dict2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 4, 0, TARGET_STRING("UNICARBrake/Brake FL/Read CM Dict3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("UNICARBrake/Brake FL/Read CM Dict4"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("UNICARBrake/Brake FL/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("UNICARBrake/Brake FR/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("UNICARBrake/Brake FR/Read CM Dict"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("UNICARBrake/Brake FR/Read CM Dict1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 10, 0, TARGET_STRING("UNICARBrake/Brake FR/Read CM Dict2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 11, 0, TARGET_STRING("UNICARBrake/Brake FR/Read CM Dict3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 12, 0, TARGET_STRING("UNICARBrake/Brake FR/Read CM Dict4"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 13, 0, TARGET_STRING("UNICARBrake/Brake FR/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("UNICARBrake/Brake RL/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("UNICARBrake/Brake RL/Read CM Dict"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 16, 0, TARGET_STRING("UNICARBrake/Brake RL/Read CM Dict1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 17, 0, TARGET_STRING("UNICARBrake/Brake RL/Read CM Dict2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 0, TARGET_STRING("UNICARBrake/Brake RL/Read CM Dict3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 19, 0, TARGET_STRING("UNICARBrake/Brake RL/Read CM Dict4"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 20, 0, TARGET_STRING("UNICARBrake/Brake RL/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("UNICARBrake/Brake RR/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("UNICARBrake/Brake RR/Read CM Dict"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 23, 0, TARGET_STRING("UNICARBrake/Brake RR/Read CM Dict1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 24, 0, TARGET_STRING("UNICARBrake/Brake RR/Read CM Dict2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 25, 0, TARGET_STRING("UNICARBrake/Brake RR/Read CM Dict3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 26, 0, TARGET_STRING("UNICARBrake/Brake RR/Read CM Dict4"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 27, 0, TARGET_STRING("UNICARBrake/Brake RR/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 28, 0, TARGET_STRING("UNICARBrake/ParkingBrake/Read CM Dict"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 29, 0, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 30, 0, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 31, 0, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 32, 0, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 33, 0, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 34, 0, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 35, 0, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 36, 0, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 37, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 38, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 39, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 40, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 41, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 42, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 43, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 44, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 45, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/T_Filter"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 46, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/f_brake"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 47, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/BrakeController/Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 48, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 49, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Product2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 50, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 51, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 52, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 53, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 54, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 55, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 56, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 57, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 58, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 59, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/T_Filter"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 60, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/f_brake"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 61, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/BrakeController/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 62, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 63, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Product2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 64, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 65, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 66, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 67, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 68, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 69, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 70, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 71, 0, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 72, 0, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 73, 0, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/T_Filter"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 74, 0, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/f_brake"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 75, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/BrakeController/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 76, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 77, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Product2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 78, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 79, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 80, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/free pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 81, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 82, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/keep pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 83, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 84, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/reduce pressure"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 85, 0, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 86, 0, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 87, 0, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/T_Filter"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 88, 0, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/f_brake"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 89, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/BrakeController/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 90, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 91, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Product2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 92, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 93, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 94, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 95, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 96, 0, TARGET_STRING(
    "UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 97, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 98, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 99, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 100, 0, TARGET_STRING(
    "UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 101, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 102, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 103, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 104, 0, TARGET_STRING(
    "UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 105, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 106, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 107, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 108, 0, TARGET_STRING(
    "UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 109, TARGET_STRING("UNICARBrake/Brake FL/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 110, TARGET_STRING("UNICARBrake/Brake FR/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 111, TARGET_STRING("UNICARBrake/Brake RL/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 112, TARGET_STRING("UNICARBrake/Brake RR/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 113, TARGET_STRING("UNICARBrake/IF_Out_Selector/Trq_DriveSrc_trg.d0"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 114, TARGET_STRING("UNICARBrake/IF_Out_Selector/Trq_DriveSrc_trg.d1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 115, TARGET_STRING("UNICARBrake/IF_Out_Selector/Trq_DriveSrc_trg.d2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 116, TARGET_STRING("UNICARBrake/IF_Out_Selector/Trq_DriveSrc_trg.d3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 117, TARGET_STRING("UNICARBrake/ParkingBrake/Constant"),
    TARGET_STRING("Value"), 0, 1, 0 },

  { 118, TARGET_STRING("UNICARBrake/ParkingBrake/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 119, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 120, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 121, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 122, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 123, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 124, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 125, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 126, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("A"), 0, 2, 0 },

  { 127, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("C"), 0, 3, 0 },

  { 128, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 129, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 130, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 131, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 132, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 133, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 134, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("A"), 0, 2, 0 },

  { 135, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("C"), 0, 3, 0 },

  { 136, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 137, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 138, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 139, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 140, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 141, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 142, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("A"), 0, 2, 0 },

  { 143, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("C"), 0, 3, 0 },

  { 144, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 145, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 146, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 147, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 148, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 149, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 150, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("A"), 0, 2, 0 },

  { 151, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/ABS off"),
    TARGET_STRING("C"), 0, 3, 0 },

  { 152, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 153, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/ABS on"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 154, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Transport Delay"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 155, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 156, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 157, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/free pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 158, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/keep pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 159, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/ABS System/reduce pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 160, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Error Handling/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 161, TARGET_STRING("UNICARBrake/Brake FL/Generic Brake Subsystem/Hydraulic Brake/Error Handling/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 162, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 163, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 164, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/free pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 165, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/keep pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 166, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/ABS System/reduce pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 167, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Error Handling/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 168, TARGET_STRING("UNICARBrake/Brake FR/Generic Brake Subsystem/Hydraulic Brake/Error Handling/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 169, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 170, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 171, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/free pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 172, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/keep pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 173, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/ABS System/reduce pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 174, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Error Handling/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 175, TARGET_STRING("UNICARBrake/Brake RL/Subsystem/Hydraulic Brake/Error Handling/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 176, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 177, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/Tiefpassfilter/Memory1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 178, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/free pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 179, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/keep pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 180, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/ABS System/reduce pressure/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 181, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Error Handling/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 182, TARGET_STRING("UNICARBrake/Brake RR/Subsystem/Hydraulic Brake/Error Handling/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 183, TARGET_STRING("brk_ABS"), 0, 0, 0 },

  { 184, TARGET_STRING("brk_Kacc"), 0, 0, 0 },

  { 185, TARGET_STRING("brk_Kslip"), 0, 0, 0 },

  { 186, TARGET_STRING("brk_SKlow"), 0, 0, 0 },

  { 187, TARGET_STRING("brk_SKup"), 0, 0, 0 },

  { 188, TARGET_STRING("brk_TKeep_1_s"), 0, 0, 0 },

  { 189, TARGET_STRING("brk_TRai_1_s"), 0, 0, 0 },

  { 190, TARGET_STRING("brk_TRed_1_s"), 0, 0, 0 },

  { 191, TARGET_STRING("brk_area_m_2"), 0, 0, 0 },

  { 192, TARGET_STRING("brk_dyn"), 0, 0, 0 },

  { 193, TARGET_STRING("brk_i"), 0, 0, 0 },

  { 194, TARGET_STRING("brk_mue"), 0, 0, 0 },

  { 195, TARGET_STRING("brk_pMax_pa"), 0, 0, 0 },

  { 196, TARGET_STRING("brk_parking_trq"), 0, 1, 0 },

  { 197, TARGET_STRING("brk_r_m"), 0, 0, 0 },

  { 198, TARGET_STRING("brk_tDel_s"), 0, 0, 0 },

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

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  4,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  2                                    /* 7 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.001
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
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
  { rtBlockSignals, 109,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 74,
    rtModelParameters, 16 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 886524856U,
    2327381728U,
    3705417142U,
    2671412396U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  UNICARBrake_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void UNICARBrake_InitializeDataMapInfo(RT_MODEL_UNICARBrake_T *const
  UNICARBrake_M)
{
  /* run-time setup of addresses */
  B_UNICARBrake_T *UNICARBrake_B = (B_UNICARBrake_T *) UNICARBrake_M->blockIO;
  void* *rtDataAddrMap;
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(UNICARBrake_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(199 * sizeof(void* ));
  if ((rtDataAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARBrake_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtDataAddrMap[0] = (void* )(&UNICARBrake_B->DataTypeConversion);
  rtDataAddrMap[1] = (void* )(&UNICARBrake_B->ReadCMDict);
  rtDataAddrMap[2] = (void* )(&UNICARBrake_B->ReadCMDict1);
  rtDataAddrMap[3] = (void* )(&UNICARBrake_B->ReadCMDict2);
  rtDataAddrMap[4] = (void* )(&UNICARBrake_B->ReadCMDict3);
  rtDataAddrMap[5] = (void* )(&UNICARBrake_B->ReadCMDict4);
  rtDataAddrMap[6] = (void* )(&UNICARBrake_B->Add_e);
  rtDataAddrMap[7] = (void* )(&UNICARBrake_B->DataTypeConversion_c);
  rtDataAddrMap[8] = (void* )(&UNICARBrake_B->ReadCMDict_b);
  rtDataAddrMap[9] = (void* )(&UNICARBrake_B->ReadCMDict1_o);
  rtDataAddrMap[10] = (void* )(&UNICARBrake_B->ReadCMDict2_l);
  rtDataAddrMap[11] = (void* )(&UNICARBrake_B->ReadCMDict3_j);
  rtDataAddrMap[12] = (void* )(&UNICARBrake_B->ReadCMDict4_i);
  rtDataAddrMap[13] = (void* )(&UNICARBrake_B->Add_p);
  rtDataAddrMap[14] = (void* )(&UNICARBrake_B->DataTypeConversion_n);
  rtDataAddrMap[15] = (void* )(&UNICARBrake_B->ReadCMDict_l);
  rtDataAddrMap[16] = (void* )(&UNICARBrake_B->ReadCMDict1_g);
  rtDataAddrMap[17] = (void* )(&UNICARBrake_B->ReadCMDict2_f);
  rtDataAddrMap[18] = (void* )(&UNICARBrake_B->ReadCMDict3_n);
  rtDataAddrMap[19] = (void* )(&UNICARBrake_B->ReadCMDict4_g);
  rtDataAddrMap[20] = (void* )(&UNICARBrake_B->Add_a);
  rtDataAddrMap[21] = (void* )(&UNICARBrake_B->DataTypeConversion_c0);
  rtDataAddrMap[22] = (void* )(&UNICARBrake_B->ReadCMDict_c);
  rtDataAddrMap[23] = (void* )(&UNICARBrake_B->ReadCMDict1_b);
  rtDataAddrMap[24] = (void* )(&UNICARBrake_B->ReadCMDict2_g);
  rtDataAddrMap[25] = (void* )(&UNICARBrake_B->ReadCMDict3_f);
  rtDataAddrMap[26] = (void* )(&UNICARBrake_B->ReadCMDict4_p);
  rtDataAddrMap[27] = (void* )(&UNICARBrake_B->Add_l);
  rtDataAddrMap[28] = (void* )(&UNICARBrake_B->ReadCMDict_f);
  rtDataAddrMap[29] = (void* )(&UNICARBrake_B->Add);
  rtDataAddrMap[30] = (void* )(&UNICARBrake_B->Switch1);
  rtDataAddrMap[31] = (void* )(&UNICARBrake_B->Add_b);
  rtDataAddrMap[32] = (void* )(&UNICARBrake_B->Switch1_h);
  rtDataAddrMap[33] = (void* )(&UNICARBrake_B->Add_n);
  rtDataAddrMap[34] = (void* )(&UNICARBrake_B->Switch1_n);
  rtDataAddrMap[35] = (void* )(&UNICARBrake_B->Add_au);
  rtDataAddrMap[36] = (void* )(&UNICARBrake_B->Switch1_f);
  rtDataAddrMap[37] = (void* )(&UNICARBrake_B->f_brake);
  rtDataAddrMap[38] = (void* )(&UNICARBrake_B->T_Filter);
  rtDataAddrMap[39] = (void* )(&UNICARBrake_B->f_brake);
  rtDataAddrMap[40] = (void* )(&UNICARBrake_B->T_Filter);
  rtDataAddrMap[41] = (void* )(&UNICARBrake_B->f_brake);
  rtDataAddrMap[42] = (void* )(&UNICARBrake_B->T_Filter);
  rtDataAddrMap[43] = (void* )(&UNICARBrake_B->Abs);
  rtDataAddrMap[44] = (void* )(&UNICARBrake_B->Memory_i);
  rtDataAddrMap[45] = (void* )(&UNICARBrake_B->T_Filter);
  rtDataAddrMap[46] = (void* )(&UNICARBrake_B->f_brake);
  rtDataAddrMap[47] = (void* )(&UNICARBrake_B->Switch);
  rtDataAddrMap[48] = (void* )(&UNICARBrake_B->Product);
  rtDataAddrMap[49] = (void* )(&UNICARBrake_B->Product2);
  rtDataAddrMap[50] = (void* )(&UNICARBrake_B->TransportDelay);
  rtDataAddrMap[51] = (void* )(&UNICARBrake_B->f_brake_h);
  rtDataAddrMap[52] = (void* )(&UNICARBrake_B->T_Filter_h);
  rtDataAddrMap[53] = (void* )(&UNICARBrake_B->f_brake_h);
  rtDataAddrMap[54] = (void* )(&UNICARBrake_B->T_Filter_h);
  rtDataAddrMap[55] = (void* )(&UNICARBrake_B->f_brake_h);
  rtDataAddrMap[56] = (void* )(&UNICARBrake_B->T_Filter_h);
  rtDataAddrMap[57] = (void* )(&UNICARBrake_B->Abs_c);
  rtDataAddrMap[58] = (void* )(&UNICARBrake_B->Memory_b);
  rtDataAddrMap[59] = (void* )(&UNICARBrake_B->T_Filter_h);
  rtDataAddrMap[60] = (void* )(&UNICARBrake_B->f_brake_h);
  rtDataAddrMap[61] = (void* )(&UNICARBrake_B->Switch1_b);
  rtDataAddrMap[62] = (void* )(&UNICARBrake_B->Product_g);
  rtDataAddrMap[63] = (void* )(&UNICARBrake_B->Product2_m);
  rtDataAddrMap[64] = (void* )(&UNICARBrake_B->TransportDelay_n);
  rtDataAddrMap[65] = (void* )(&UNICARBrake_B->f_brake_f);
  rtDataAddrMap[66] = (void* )(&UNICARBrake_B->T_Filter_g);
  rtDataAddrMap[67] = (void* )(&UNICARBrake_B->f_brake_f);
  rtDataAddrMap[68] = (void* )(&UNICARBrake_B->T_Filter_g);
  rtDataAddrMap[69] = (void* )(&UNICARBrake_B->f_brake_f);
  rtDataAddrMap[70] = (void* )(&UNICARBrake_B->T_Filter_g);
  rtDataAddrMap[71] = (void* )(&UNICARBrake_B->Abs_h);
  rtDataAddrMap[72] = (void* )(&UNICARBrake_B->Memory_p);
  rtDataAddrMap[73] = (void* )(&UNICARBrake_B->T_Filter_g);
  rtDataAddrMap[74] = (void* )(&UNICARBrake_B->f_brake_f);
  rtDataAddrMap[75] = (void* )(&UNICARBrake_B->Switch1_e);
  rtDataAddrMap[76] = (void* )(&UNICARBrake_B->Product_p);
  rtDataAddrMap[77] = (void* )(&UNICARBrake_B->Product2_i);
  rtDataAddrMap[78] = (void* )(&UNICARBrake_B->TransportDelay_m);
  rtDataAddrMap[79] = (void* )(&UNICARBrake_B->f_brake_m);
  rtDataAddrMap[80] = (void* )(&UNICARBrake_B->T_Filter_hd);
  rtDataAddrMap[81] = (void* )(&UNICARBrake_B->f_brake_m);
  rtDataAddrMap[82] = (void* )(&UNICARBrake_B->T_Filter_hd);
  rtDataAddrMap[83] = (void* )(&UNICARBrake_B->f_brake_m);
  rtDataAddrMap[84] = (void* )(&UNICARBrake_B->T_Filter_hd);
  rtDataAddrMap[85] = (void* )(&UNICARBrake_B->Abs_j);
  rtDataAddrMap[86] = (void* )(&UNICARBrake_B->Memory_f);
  rtDataAddrMap[87] = (void* )(&UNICARBrake_B->T_Filter_hd);
  rtDataAddrMap[88] = (void* )(&UNICARBrake_B->f_brake_m);
  rtDataAddrMap[89] = (void* )(&UNICARBrake_B->Switch1_j);
  rtDataAddrMap[90] = (void* )(&UNICARBrake_B->Product_e);
  rtDataAddrMap[91] = (void* )(&UNICARBrake_B->Product2_g);
  rtDataAddrMap[92] = (void* )(&UNICARBrake_B->TransportDelay_f);
  rtDataAddrMap[93] = (void* )(&UNICARBrake_B->Clock);
  rtDataAddrMap[94] = (void* )(&UNICARBrake_B->Memory);
  rtDataAddrMap[95] = (void* )(&UNICARBrake_B->Memory1);
  rtDataAddrMap[96] = (void* )(&UNICARBrake_B->Sum2);
  rtDataAddrMap[97] = (void* )(&UNICARBrake_B->Clock_i);
  rtDataAddrMap[98] = (void* )(&UNICARBrake_B->Memory_a);
  rtDataAddrMap[99] = (void* )(&UNICARBrake_B->Memory1_a);
  rtDataAddrMap[100] = (void* )(&UNICARBrake_B->Sum2_o);
  rtDataAddrMap[101] = (void* )(&UNICARBrake_B->Clock_m);
  rtDataAddrMap[102] = (void* )(&UNICARBrake_B->Memory_h);
  rtDataAddrMap[103] = (void* )(&UNICARBrake_B->Memory1_j);
  rtDataAddrMap[104] = (void* )(&UNICARBrake_B->Sum2_l);
  rtDataAddrMap[105] = (void* )(&UNICARBrake_B->Clock_e);
  rtDataAddrMap[106] = (void* )(&UNICARBrake_B->Memory_m);
  rtDataAddrMap[107] = (void* )(&UNICARBrake_B->Memory1_p);
  rtDataAddrMap[108] = (void* )(&UNICARBrake_B->Sum2_c);
  rtDataAddrMap[109] = (void* )(&UNICARBrake_P.CompareToConstant_const);
  rtDataAddrMap[110] = (void* )(&UNICARBrake_P.CompareToConstant_const_h);
  rtDataAddrMap[111] = (void* )(&UNICARBrake_P.CompareToConstant_const_b);
  rtDataAddrMap[112] = (void* )(&UNICARBrake_P.CompareToConstant_const_i);
  rtDataAddrMap[113] = (void* )(&UNICARBrake_P.Trq_DriveSrc_trgd0_Value);
  rtDataAddrMap[114] = (void* )(&UNICARBrake_P.Trq_DriveSrc_trgd1_Value);
  rtDataAddrMap[115] = (void* )(&UNICARBrake_P.Trq_DriveSrc_trgd2_Value);
  rtDataAddrMap[116] = (void* )(&UNICARBrake_P.Trq_DriveSrc_trgd3_Value);
  rtDataAddrMap[117] = (void* )(&UNICARBrake_P.Constant_Value[0]);
  rtDataAddrMap[118] = (void* )(&UNICARBrake_P.Switch_Threshold_f);
  rtDataAddrMap[119] = (void* )(&UNICARBrake_P.Switch1_Threshold_nh);
  rtDataAddrMap[120] = (void* )(&UNICARBrake_P.Switch1_Threshold_k);
  rtDataAddrMap[121] = (void* )(&UNICARBrake_P.Switch1_Threshold_ef);
  rtDataAddrMap[122] = (void* )(&UNICARBrake_P.Switch1_Threshold_kn);
  rtDataAddrMap[123] = (void* )(&UNICARBrake_P.Memory_InitialCondition_b);
  rtDataAddrMap[124] = (void* )(&UNICARBrake_P.Switch1_Threshold);
  rtDataAddrMap[125] = (void* )(&UNICARBrake_P.Switch2_Threshold);
  rtDataAddrMap[126] = (void* )(&UNICARBrake_P.ABSoff_A[0]);
  rtDataAddrMap[127] = (void* )(&UNICARBrake_P.ABSoff_C[0]);
  rtDataAddrMap[128] = (void* )(&UNICARBrake_P.ABSon_A);
  rtDataAddrMap[129] = (void* )(&UNICARBrake_P.ABSon_C);
  rtDataAddrMap[130] = (void* )(&UNICARBrake_P.TransportDelay_InitOutput);
  rtDataAddrMap[131] = (void* )(&UNICARBrake_P.Memory_InitialCondition_b2);
  rtDataAddrMap[132] = (void* )(&UNICARBrake_P.Switch1_Threshold_p);
  rtDataAddrMap[133] = (void* )(&UNICARBrake_P.Switch2_Threshold_a);
  rtDataAddrMap[134] = (void* )(&UNICARBrake_P.ABSoff_A_l[0]);
  rtDataAddrMap[135] = (void* )(&UNICARBrake_P.ABSoff_C_b[0]);
  rtDataAddrMap[136] = (void* )(&UNICARBrake_P.ABSon_A_h);
  rtDataAddrMap[137] = (void* )(&UNICARBrake_P.ABSon_C_g);
  rtDataAddrMap[138] = (void* )(&UNICARBrake_P.TransportDelay_InitOutput_h);
  rtDataAddrMap[139] = (void* )(&UNICARBrake_P.Memory_InitialCondition_m);
  rtDataAddrMap[140] = (void* )(&UNICARBrake_P.Switch1_Threshold_n);
  rtDataAddrMap[141] = (void* )(&UNICARBrake_P.Switch2_Threshold_c);
  rtDataAddrMap[142] = (void* )(&UNICARBrake_P.ABSoff_A_j[0]);
  rtDataAddrMap[143] = (void* )(&UNICARBrake_P.ABSoff_C_n[0]);
  rtDataAddrMap[144] = (void* )(&UNICARBrake_P.ABSon_A_c);
  rtDataAddrMap[145] = (void* )(&UNICARBrake_P.ABSon_C_e);
  rtDataAddrMap[146] = (void* )(&UNICARBrake_P.TransportDelay_InitOutput_k);
  rtDataAddrMap[147] = (void* )(&UNICARBrake_P.Memory_InitialCondition_g);
  rtDataAddrMap[148] = (void* )(&UNICARBrake_P.Switch1_Threshold_e);
  rtDataAddrMap[149] = (void* )(&UNICARBrake_P.Switch2_Threshold_m);
  rtDataAddrMap[150] = (void* )(&UNICARBrake_P.ABSoff_A_h[0]);
  rtDataAddrMap[151] = (void* )(&UNICARBrake_P.ABSoff_C_k[0]);
  rtDataAddrMap[152] = (void* )(&UNICARBrake_P.ABSon_A_m);
  rtDataAddrMap[153] = (void* )(&UNICARBrake_P.ABSon_C_ed);
  rtDataAddrMap[154] = (void* )(&UNICARBrake_P.TransportDelay_InitOutput_l);
  rtDataAddrMap[155] = (void* )(&UNICARBrake_P.Memory_InitialCondition);
  rtDataAddrMap[156] = (void* )(&UNICARBrake_P.Memory1_InitialCondition);
  rtDataAddrMap[157] = (void* )(&UNICARBrake_P.freepressure.Constant1_Value);
  rtDataAddrMap[158] = (void* )(&UNICARBrake_P.keeppressure.Constant1_Value);
  rtDataAddrMap[159] = (void* )(&UNICARBrake_P.reducepressure.Constant1_Value);
  rtDataAddrMap[160] = (void* )(&UNICARBrake_P.Constant4_Value);
  rtDataAddrMap[161] = (void* )(&UNICARBrake_P.Switch_Threshold);
  rtDataAddrMap[162] = (void* )(&UNICARBrake_P.Memory_InitialCondition_e);
  rtDataAddrMap[163] = (void* )(&UNICARBrake_P.Memory1_InitialCondition_k);
  rtDataAddrMap[164] = (void* )(&UNICARBrake_P.freepressure_j.Constant1_Value);
  rtDataAddrMap[165] = (void* )(&UNICARBrake_P.keeppressure_k.Constant1_Value);
  rtDataAddrMap[166] = (void* )(&UNICARBrake_P.reducepressure_f.Constant1_Value);
  rtDataAddrMap[167] = (void* )(&UNICARBrake_P.Constant4_Value_j);
  rtDataAddrMap[168] = (void* )(&UNICARBrake_P.Switch_Threshold_j);
  rtDataAddrMap[169] = (void* )(&UNICARBrake_P.Memory_InitialCondition_p);
  rtDataAddrMap[170] = (void* )(&UNICARBrake_P.Memory1_InitialCondition_m);
  rtDataAddrMap[171] = (void* )(&UNICARBrake_P.freepressure_c.Constant1_Value);
  rtDataAddrMap[172] = (void* )(&UNICARBrake_P.keeppressure_o.Constant1_Value);
  rtDataAddrMap[173] = (void* )(&UNICARBrake_P.reducepressure_j.Constant1_Value);
  rtDataAddrMap[174] = (void* )(&UNICARBrake_P.Constant4_Value_g);
  rtDataAddrMap[175] = (void* )(&UNICARBrake_P.Switch_Threshold_b);
  rtDataAddrMap[176] = (void* )(&UNICARBrake_P.Memory_InitialCondition_eq);
  rtDataAddrMap[177] = (void* )(&UNICARBrake_P.Memory1_InitialCondition_g);
  rtDataAddrMap[178] = (void* )(&UNICARBrake_P.freepressure_i.Constant1_Value);
  rtDataAddrMap[179] = (void* )(&UNICARBrake_P.keeppressure_j.Constant1_Value);
  rtDataAddrMap[180] = (void* )(&UNICARBrake_P.reducepressure_a.Constant1_Value);
  rtDataAddrMap[181] = (void* )(&UNICARBrake_P.Constant4_Value_k);
  rtDataAddrMap[182] = (void* )(&UNICARBrake_P.Switch_Threshold_a);
  rtDataAddrMap[183] = (void* )(&UNICARBrake_P.brk_ABS);
  rtDataAddrMap[184] = (void* )(&UNICARBrake_P.brk_Kacc);
  rtDataAddrMap[185] = (void* )(&UNICARBrake_P.brk_Kslip);
  rtDataAddrMap[186] = (void* )(&UNICARBrake_P.brk_SKlow);
  rtDataAddrMap[187] = (void* )(&UNICARBrake_P.brk_SKup);
  rtDataAddrMap[188] = (void* )(&UNICARBrake_P.brk_TKeep_1_s);
  rtDataAddrMap[189] = (void* )(&UNICARBrake_P.brk_TRai_1_s);
  rtDataAddrMap[190] = (void* )(&UNICARBrake_P.brk_TRed_1_s);
  rtDataAddrMap[191] = (void* )(&UNICARBrake_P.brk_area_m_2);
  rtDataAddrMap[192] = (void* )(&UNICARBrake_P.brk_dyn);
  rtDataAddrMap[193] = (void* )(&UNICARBrake_P.brk_i);
  rtDataAddrMap[194] = (void* )(&UNICARBrake_P.brk_mue);
  rtDataAddrMap[195] = (void* )(&UNICARBrake_P.brk_pMax_pa);
  rtDataAddrMap[196] = (void* )(&UNICARBrake_P.brk_parking_trq[0]);
  rtDataAddrMap[197] = (void* )(&UNICARBrake_P.brk_r_m);
  rtDataAddrMap[198] = (void* )(&UNICARBrake_P.brk_tDel_s);
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(UNICARBrake_M->DataMapInfo.mmi) ) );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  if ((rtVarDimsAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARBrake_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtVarDimsAddrMap[0] = (int32_T* )((NULL));

  /* Set C-API version */
  rtwCAPI_SetVersion(UNICARBrake_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(UNICARBrake_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(UNICARBrake_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(UNICARBrake_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(UNICARBrake_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(UNICARBrake_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(UNICARBrake_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(UNICARBrake_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void UNICARBrake_host_InitializeDataMapInfo(UNICARBrake_host_DataMapInfo_T
    *dataMap, const char *path)
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

/* EOF: UNICARBrake_capi.c */
