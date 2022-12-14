/*
 * UNICARSteer_types.h
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

#ifndef RTW_HEADER_UNICARSteer_types_h_
#define RTW_HEADER_UNICARSteer_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_cmSteeringIn_
#define DEFINED_TYPEDEF_FOR_cmSteeringIn_

typedef struct {
  real_T SteerByTrq;
  real_T Ang;
  real_T AngVel;
  real_T AngAcc;
  real_T Trq;
  real_T AssistFrc;
  real_T AssistTrqCol;
  real_T AssistTrqPin;
  real_T AssistFrc_Ext;
  real_T AssistTrqCol_Ext;
  real_T AssistTrqPin_Ext;
  real_T Frc_L;
  real_T Inert_L;
  real_T Frc_R;
  real_T Inert_R;
} cmSteeringIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmSteeringCfgIn_
#define DEFINED_TYPEDEF_FOR_cmSteeringCfgIn_

typedef struct {
  real_T Ang;
  real_T PosSign;
} cmSteeringCfgIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmSteeringCfgOut_
#define DEFINED_TYPEDEF_FOR_cmSteeringCfgOut_

typedef struct {
  real_T SInputKind;
  real_T PrefByDriver;
} cmSteeringCfgOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmSteeringOut_
#define DEFINED_TYPEDEF_FOR_cmSteeringOut_

typedef struct {
  real_T Ang;
  real_T AngVel;
  real_T AngAcc;
  real_T Trq;
  real_T TrqStatic;
  real_T AssistFrc;
  real_T AssistTrqCol;
  real_T AssistTrqPin;
  real_T q_L;
  real_T qp_L;
  real_T qpp_L;
  real_T iSteer2q_L;
  real_T q_R;
  real_T qp_R;
  real_T qpp_R;
  real_T iSteer2q_R;
} cmSteeringOut;

#endif

/* Parameters (default storage) */
typedef struct P_UNICARSteer_T_ P_UNICARSteer_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UNICARSteer_T RT_MODEL_UNICARSteer_T;

#endif                                 /* RTW_HEADER_UNICARSteer_types_h_ */
