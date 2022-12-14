/*
 * UNICARPTGearBox_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARPTGearBox".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:30:00 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UNICARPTGearBox_types_h_
#define RTW_HEADER_UNICARPTGearBox_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_cm17ClutchIn_
#define DEFINED_TYPEDEF_FOR_cm17ClutchIn_

typedef struct {
  real_T Pos;
} cm17ClutchIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTGearBoxIn_
#define DEFINED_TYPEDEF_FOR_cmPTGearBoxIn_

typedef struct {
  real_T GearNoTrg;
  real_T GearNoTrg_dis;
  real_T set_ParkBrake;
  real_T i_trg;
  real_T Inert_in;
  real_T rot_out;
  real_T rotv_out;
  real_T Trq_in;
  cm17ClutchIn ClutchIn;
  cm17ClutchIn Clutch_dis_In;
} cmPTGearBoxIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm17FGears_
#define DEFINED_TYPEDEF_FOR_cm17FGears_

typedef struct {
  real_T Gear1;
  real_T Gear2;
  real_T Gear3;
  real_T Gear4;
  real_T Gear5;
  real_T Gear6;
  real_T Gear7;
  real_T Gear8;
  real_T Gear9;
  real_T Gear10;
  real_T Gear11;
  real_T Gear12;
  real_T Gear13;
  real_T Gear14;
  real_T Gear15;
  real_T Gear16;
} cm17FGears;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm17BGears_
#define DEFINED_TYPEDEF_FOR_cm17BGears_

typedef struct {
  real_T Gear1;
  real_T Gear2;
  real_T Gear3;
  real_T Gear4;
} cm17BGears;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTGearBoxCfgOut_
#define DEFINED_TYPEDEF_FOR_cmPTGearBoxCfgOut_

typedef struct {
  real_T GBKind;
  real_T ClKind;
  real_T nFGears;
  cm17FGears iFGear;
  real_T nBGears;
  cm17BGears iBGear;
} cmPTGearBoxCfgOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm17ClutchOut_
#define DEFINED_TYPEDEF_FOR_cm17ClutchOut_

typedef struct {
  real_T rot_in;
  real_T rotv_in;
  real_T rot_out;
  real_T rotv_out;
  real_T Trq_in;
  real_T Trq_out;
  real_T i_TrqIn2Out;
} cm17ClutchOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTGearBoxOut_
#define DEFINED_TYPEDEF_FOR_cmPTGearBoxOut_

typedef struct {
  real_T GearNo;
  real_T GearNo_dis;
  real_T i;
  real_T rot_in;
  real_T rotv_in;
  real_T Trq_out;
  real_T Inert_out;
  real_T i_TrqIn2Out;
  real_T Trq_SuppInert;
  cm17ClutchOut ClutchOut;
  cm17ClutchOut Clutch_dis_Out;
} cmPTGearBoxOut;

#endif

/* Parameters (default storage) */
typedef struct P_UNICARPTGearBox_T_ P_UNICARPTGearBox_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UNICARPTGearBox_T RT_MODEL_UNICARPTGearBox_T;

#endif                                 /* RTW_HEADER_UNICARPTGearBox_types_h_ */
