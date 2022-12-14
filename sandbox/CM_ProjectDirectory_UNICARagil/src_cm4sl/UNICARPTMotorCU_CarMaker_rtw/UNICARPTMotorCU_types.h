/*
 * UNICARPTMotorCU_types.h
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

#ifndef RTW_HEADER_UNICARPTMotorCU_types_h_
#define RTW_HEADER_UNICARPTMotorCU_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorIn_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorIn_

typedef struct {
  real_T Trq_trg;
  real_T Trq;
  real_T rotv_trg;
  real_T rotv;
  real_T PwrElec;
} cm20PTMotorIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorInArray_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorInArray_

typedef struct {
  cm20PTMotorIn m0;
  cm20PTMotorIn m1;
  cm20PTMotorIn m2;
  cm20PTMotorIn m3;
} cm20PTMotorInArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorOut_In_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorOut_In_

typedef struct {
  real_T Load;
} cm20PTMotorOut_In;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorOut_InArray_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorOut_InArray_

typedef struct {
  cm20PTMotorOut_In m0;
  cm20PTMotorOut_In m1;
  cm20PTMotorOut_In m2;
  cm20PTMotorOut_In m3;
} cm20PTMotorOut_InArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTMotorCUIn_
#define DEFINED_TYPEDEF_FOR_cmPTMotorCUIn_

typedef struct {
  real_T Ignition;
  cm20PTMotorIn ISGIn;
  cm20PTMotorInArray MotorIn;
  cm20PTMotorOut_In ISGOut;
  cm20PTMotorOut_InArray MotorOut;
} cmPTMotorCUIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorMap_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorMap_

typedef struct {
  real_T x[100];
  real_T z[100];
} cm20PTMotorMap;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotor_
#define DEFINED_TYPEDEF_FOR_cm20PTMotor_

typedef struct {
  real_T Ratio;
  cm20PTMotorMap TrqMot_max;
  real_T rotv_Mot_max;
  cm20PTMotorMap TrqGen_max;
  real_T rotv_Gen_max;
} cm20PTMotor;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorArray_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorArray_

typedef struct {
  cm20PTMotor m0;
  cm20PTMotor m1;
  cm20PTMotor m2;
  cm20PTMotor m3;
} cm20PTMotorArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTMotorCUCfgIn_
#define DEFINED_TYPEDEF_FOR_cmPTMotorCUCfgIn_

typedef struct {
  real_T nMotor;
  cm20PTMotor ISG;
  cm20PTMotorArray Motor;
} cmPTMotorCUCfgIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorOut_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorOut_

typedef struct {
  real_T Load;
  real_T TrqMot_max;
  real_T TrqGen_max;
} cm20PTMotorOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm20PTMotorOutArray_
#define DEFINED_TYPEDEF_FOR_cm20PTMotorOutArray_

typedef struct {
  cm20PTMotorOut m0;
  cm20PTMotorOut m1;
  cm20PTMotorOut m2;
  cm20PTMotorOut m3;
} cm20PTMotorOutArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTMotorCUOut_
#define DEFINED_TYPEDEF_FOR_cmPTMotorCUOut_

typedef struct {
  real_T Status;
  cm20PTMotorOut ISGOut;
  cm20PTMotorOutArray MotorOut;
} cmPTMotorCUOut;

#endif

/* Parameters (default storage) */
typedef struct P_UNICARPTMotorCU_T_ P_UNICARPTMotorCU_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UNICARPTMotorCU_T RT_MODEL_UNICARPTMotorCU_T;

#endif                                 /* RTW_HEADER_UNICARPTMotorCU_types_h_ */
