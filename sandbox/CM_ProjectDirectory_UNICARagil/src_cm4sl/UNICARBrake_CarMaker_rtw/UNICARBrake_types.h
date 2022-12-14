/*
 * UNICARBrake_types.h
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

#ifndef RTW_HEADER_UNICARBrake_types_h_
#define RTW_HEADER_UNICARBrake_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_cm4BrakeWheelIn_
#define DEFINED_TYPEDEF_FOR_cm4BrakeWheelIn_

typedef struct {
  real_T Trq_BrakeReg_max;
  real_T Trq_BrakeReg;
} cm4BrakeWheelIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm4BrakeWheelInArray_
#define DEFINED_TYPEDEF_FOR_cm4BrakeWheelInArray_

typedef struct {
  cm4BrakeWheelIn FL;
  cm4BrakeWheelIn FR;
  cm4BrakeWheelIn RL;
  cm4BrakeWheelIn RR;
} cm4BrakeWheelInArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmBrakeIn_
#define DEFINED_TYPEDEF_FOR_cmBrakeIn_

typedef struct {
  real_T Pedal;
  real_T Park;
  real_T T_env;
  cm4BrakeWheelInArray WheelIn;
} cmBrakeIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmBrakeCfgIn_
#define DEFINED_TYPEDEF_FOR_cmBrakeCfgIn_

typedef struct {
  real_T VehicleClassId;
  real_T nWheels;
} cmBrakeCfgIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm4BrakeWheelOut_
#define DEFINED_TYPEDEF_FOR_cm4BrakeWheelOut_

typedef struct {
  real_T Trq_WB;
  real_T Trq_PB;
  real_T Trq_BrakeReg_trg;
} cm4BrakeWheelOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm4BrakeWheelOutArray_
#define DEFINED_TYPEDEF_FOR_cm4BrakeWheelOutArray_

typedef struct {
  cm4BrakeWheelOut FL;
  cm4BrakeWheelOut FR;
  cm4BrakeWheelOut RL;
  cm4BrakeWheelOut RR;
} cm4BrakeWheelOutArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm4DriveSrcArray_
#define DEFINED_TYPEDEF_FOR_cm4DriveSrcArray_

typedef struct {
  real_T d0;
  real_T d1;
  real_T d2;
  real_T d3;
} cm4DriveSrcArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmBrakeOut_
#define DEFINED_TYPEDEF_FOR_cmBrakeOut_

typedef struct {
  cm4BrakeWheelOutArray WheelOut;
  cm4DriveSrcArray Trq_DriveSrc_trg;
} cmBrakeOut;

#endif

/* Parameters for system: '<S9>/reduce pressure' */
typedef struct P_reducepressure_UNICARBrake_T_ P_reducepressure_UNICARBrake_T;

/* Parameters for system: '<S9>/free pressure' */
typedef struct P_freepressure_UNICARBrake_T_ P_freepressure_UNICARBrake_T;

/* Parameters for system: '<S9>/keep pressure' */
typedef struct P_keeppressure_UNICARBrake_T_ P_keeppressure_UNICARBrake_T;

/* Parameters (default storage) */
typedef struct P_UNICARBrake_T_ P_UNICARBrake_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UNICARBrake_T RT_MODEL_UNICARBrake_T;

#endif                                 /* RTW_HEADER_UNICARBrake_types_h_ */
