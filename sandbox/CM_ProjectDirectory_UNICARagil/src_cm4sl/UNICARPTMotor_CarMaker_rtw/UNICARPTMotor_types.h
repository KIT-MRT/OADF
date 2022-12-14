/*
 * UNICARPTMotor_types.h
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

#ifndef RTW_HEADER_UNICARPTMotor_types_h_
#define RTW_HEADER_UNICARPTMotor_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_cmPTMotorIn_
#define DEFINED_TYPEDEF_FOR_cmPTMotorIn_

typedef struct {
  real_T rot;
  real_T rotv;
  real_T Voltage;
  real_T Load;
} cmPTMotorIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm19PTMotorMap_
#define DEFINED_TYPEDEF_FOR_cm19PTMotorMap_

typedef struct {
  real_T x[100];
  real_T z[100];
} cm19PTMotorMap;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTMotorCfgOut_
#define DEFINED_TYPEDEF_FOR_cmPTMotorCfgOut_

typedef struct {
  real_T Level;
  real_T Ratio;
  cm19PTMotorMap TrqMot_max;
  real_T rotv_Mot_max;
  cm19PTMotorMap TrqGen_max;
  real_T rotv_Gen_max;
} cmPTMotorCfgOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTMotorOut_
#define DEFINED_TYPEDEF_FOR_cmPTMotorOut_

typedef struct {
  real_T Trq;
  real_T Inert;
  real_T PwrElec;
} cmPTMotorOut;

#endif

/* Parameters (default storage) */
typedef struct P_UNICARPTMotor_T_ P_UNICARPTMotor_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UNICARPTMotor_T RT_MODEL_UNICARPTMotor_T;

#endif                                 /* RTW_HEADER_UNICARPTMotor_types_h_ */
