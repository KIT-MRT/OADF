/*
 * UNICARPTControl_types.h
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

#ifndef RTW_HEADER_UNICARPTControl_types_h_
#define RTW_HEADER_UNICARPTControl_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_cm12UserSignal_
#define DEFINED_TYPEDEF_FOR_cm12UserSignal_

typedef struct {
  real_T s0;
  real_T s1;
  real_T s2;
  real_T s3;
  real_T s4;
} cm12UserSignal;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12EngineIn_
#define DEFINED_TYPEDEF_FOR_cm12EngineIn_

typedef struct {
  real_T Engine_on;
  real_T rotv;
  real_T Trq;
  real_T TrqDrag;
  real_T TrqFull;
  real_T TrqOpt;
  real_T FuelFlow;
} cm12EngineIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12Wheels_
#define DEFINED_TYPEDEF_FOR_cm12Wheels_

typedef struct {
  real_T FL;
  real_T FR;
  real_T RL;
  real_T RR;
} cm12Wheels;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12MotorIn_
#define DEFINED_TYPEDEF_FOR_cm12MotorIn_

typedef struct {
  real_T rotv;
  real_T Trq;
  real_T TrqMot_max;
  real_T TrqGen_max;
  real_T PwrElec;
  cm12Wheels i_M2W;
} cm12MotorIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12MotorInArray_
#define DEFINED_TYPEDEF_FOR_cm12MotorInArray_

typedef struct {
  cm12MotorIn m0;
  cm12MotorIn m1;
  cm12MotorIn m2;
  cm12MotorIn m3;
} cm12MotorInArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12ClutchIn_
#define DEFINED_TYPEDEF_FOR_cm12ClutchIn_

typedef struct {
  real_T Pos;
  real_T rotv_in;
  real_T rotv_out;
  real_T Trq_in;
  real_T Trq_out;
  real_T i_TrqIn2Out;
} cm12ClutchIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12GearBoxIn_
#define DEFINED_TYPEDEF_FOR_cm12GearBoxIn_

typedef struct {
  real_T GearNo;
  real_T GearNo_dis;
  real_T Trq_DriveSrc_trg;
  real_T i;
  real_T rotv_in;
  real_T rotv_out;
  real_T Trq_in;
  real_T Trq_out;
  cm12ClutchIn Clutch;
  cm12ClutchIn Clutch_dis;
} cm12GearBoxIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12GearBoxInArray_
#define DEFINED_TYPEDEF_FOR_cm12GearBoxInArray_

typedef struct {
  cm12GearBoxIn GB_m0;
  cm12GearBoxIn GB_m1;
  cm12GearBoxIn GB_m2;
  cm12GearBoxIn GB_m3;
} cm12GearBoxInArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12BattIn_
#define DEFINED_TYPEDEF_FOR_cm12BattIn_

typedef struct {
  real_T SOC;
  real_T SOH;
  real_T Current;
  real_T AOC;
  real_T Temp;
  real_T Energy;
  real_T Pwr_max;
} cm12BattIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PwrSupplyIn_
#define DEFINED_TYPEDEF_FOR_cm12PwrSupplyIn_

typedef struct {
  real_T Pwr_LV;
  real_T Pwr_HV1;
  real_T Pwr_HV2;
  real_T Voltage_LV;
  real_T Voltage_HV1;
  real_T Voltage_HV2;
  real_T Pwr_HV1toLV;
  real_T Pwr_HV1toHV2;
  real_T Pwr_HV1toLV_max;
  real_T Pwr_HV1toHV2_max;
  real_T Eta_HV1toLV;
  real_T Eta_HV1toHV2;
} cm12PwrSupplyIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PTControlWheelIn_
#define DEFINED_TYPEDEF_FOR_cm12PTControlWheelIn_

typedef struct {
  real_T Trq_BrakeReg_trg;
} cm12PTControlWheelIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PTControlWheelInArray_
#define DEFINED_TYPEDEF_FOR_cm12PTControlWheelInArray_

typedef struct {
  cm12PTControlWheelIn FL;
  cm12PTControlWheelIn FR;
  cm12PTControlWheelIn RL;
  cm12PTControlWheelIn RR;
} cm12PTControlWheelInArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12DriveSrcIn_
#define DEFINED_TYPEDEF_FOR_cm12DriveSrcIn_

typedef struct {
  real_T Trq_trg;
} cm12DriveSrcIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12DriveSrcInArray_
#define DEFINED_TYPEDEF_FOR_cm12DriveSrcInArray_

typedef struct {
  cm12DriveSrcIn d0;
  cm12DriveSrcIn d1;
  cm12DriveSrcIn d2;
  cm12DriveSrcIn d3;
} cm12DriveSrcInArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTControlIn_
#define DEFINED_TYPEDEF_FOR_cmPTControlIn_

typedef struct {
  real_T Key;
  real_T SST;
  real_T SelectorCtrl;
  real_T GearNoTrg;
  real_T Clutch;
  real_T Gas;
  real_T Brake;
  real_T Velocity;
  cm12UserSignal UserSignal;
  real_T ECU_Status;
  cm12EngineIn EngineIn;
  real_T MCU_Status;
  cm12MotorIn ISGIn;
  cm12MotorInArray MotorIn;
  real_T TCU_Status;
  cm12ClutchIn ClutchIn;
  cm12GearBoxIn GearBoxIn;
  cm12GearBoxInArray GearBoxM_In;
  real_T BCU_Status;
  cm12BattIn BattLVIn;
  cm12BattIn BattHVIn;
  cm12PwrSupplyIn PwrSupplyIn;
  cm12PTControlWheelInArray WheelIn;
  cm12DriveSrcInArray DriveSrcIn;
} cmPTControlIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12DriveSourcePosArray_
#define DEFINED_TYPEDEF_FOR_cm12DriveSourcePosArray_

typedef struct {
  real_T d0;
  real_T d1;
  real_T d2;
  real_T d3;
} cm12DriveSourcePosArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12Batt_
#define DEFINED_TYPEDEF_FOR_cm12Batt_

typedef struct {
  real_T SOC_min;
  real_T SOC_max;
  real_T Capacity;
  real_T Voltage;
} cm12Batt;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PTEngineMap_
#define DEFINED_TYPEDEF_FOR_cm12PTEngineMap_

typedef struct {
  real_T x[100];
  real_T z[100];
} cm12PTEngineMap;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12Engine_
#define DEFINED_TYPEDEF_FOR_cm12Engine_

typedef struct {
  real_T Fuel_l2kWh;
  real_T rotv_max;
  real_T rotv_idle;
  real_T rotv_opt;
  cm12PTEngineMap TrqFull;
  cm12PTEngineMap TrqDrag;
  cm12PTEngineMap TrqOpt;
} cm12Engine;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PTMotorMap_
#define DEFINED_TYPEDEF_FOR_cm12PTMotorMap_

typedef struct {
  real_T x[100];
  real_T z[100];
} cm12PTMotorMap;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12Motor_
#define DEFINED_TYPEDEF_FOR_cm12Motor_

typedef struct {
  real_T Level;
  real_T Ratio;
  cm12PTMotorMap TrqMot_max;
  real_T rotv_Mot_max;
  cm12PTMotorMap TrqGen_max;
  real_T rotv_Gen_max;
} cm12Motor;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12MotorArray_
#define DEFINED_TYPEDEF_FOR_cm12MotorArray_

typedef struct {
  cm12Motor m0;
  cm12Motor m1;
  cm12Motor m2;
  cm12Motor m3;
} cm12MotorArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12FGearArray_
#define DEFINED_TYPEDEF_FOR_cm12FGearArray_

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
} cm12FGearArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12BGearArray_
#define DEFINED_TYPEDEF_FOR_cm12BGearArray_

typedef struct {
  real_T Gear1;
  real_T Gear2;
  real_T Gear3;
  real_T Gear4;
} cm12BGearArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12GearBox_
#define DEFINED_TYPEDEF_FOR_cm12GearBox_

typedef struct {
  real_T GBKind;
  real_T ClKind;
  real_T nFGears;
  cm12FGearArray iFGear;
  real_T nBGears;
  cm12BGearArray iBGear;
} cm12GearBox;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12GearBoxArray_
#define DEFINED_TYPEDEF_FOR_cm12GearBoxArray_

typedef struct {
  cm12GearBox GB_m0;
  cm12GearBox GB_m1;
  cm12GearBox GB_m2;
  cm12GearBox GB_m3;
} cm12GearBoxArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PlanetGear_
#define DEFINED_TYPEDEF_FOR_cm12PlanetGear_

typedef struct {
  real_T Ratio;
} cm12PlanetGear;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTControlCfgIn_
#define DEFINED_TYPEDEF_FOR_cmPTControlCfgIn_

typedef struct {
  real_T PTKind;
  real_T ClKind;
  real_T nMotor;
  real_T nGearBoxM;
  real_T nPlanetGear;
  real_T nWheels;
  real_T WheelRadius;
  real_T Aero_Frcx;
  real_T DL_iDiff_mean;
  cm12DriveSourcePosArray DriveSourcePos;
  cm12Batt BattLV;
  cm12Batt BattHV;
  cm12Engine Engine;
  cm12Motor ISG;
  cm12MotorArray Motor;
  cm12GearBox GearBox;
  cm12GearBoxArray GearBoxM;
  cm12PlanetGear PlanetGear;
} cmPTControlCfgIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTControlCfgOut_
#define DEFINED_TYPEDEF_FOR_cmPTControlCfgOut_

typedef struct {
  real_T StartEngineWithSST;
  real_T Velocity_max;
} cmPTControlCfgOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12EngineOut_
#define DEFINED_TYPEDEF_FOR_cm12EngineOut_

typedef struct {
  real_T set_ISC;
  real_T FuelCutOff;
  real_T Load;
  real_T Trq_trg;
  real_T rotv_trg;
} cm12EngineOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12MotorOut_
#define DEFINED_TYPEDEF_FOR_cm12MotorOut_

typedef struct {
  real_T Load;
  real_T Trq_trg;
  real_T rotv_trg;
} cm12MotorOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12MotorOutArray_
#define DEFINED_TYPEDEF_FOR_cm12MotorOutArray_

typedef struct {
  cm12MotorOut m0;
  cm12MotorOut m1;
  cm12MotorOut m2;
  cm12MotorOut m3;
} cm12MotorOutArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12ClutchOut_
#define DEFINED_TYPEDEF_FOR_cm12ClutchOut_

typedef struct {
  real_T Pos;
  real_T rotv_out_trg;
  real_T Trq_out_trg;
} cm12ClutchOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12GearBoxOut_
#define DEFINED_TYPEDEF_FOR_cm12GearBoxOut_

typedef struct {
  real_T GearNoTrg;
  real_T GearNoTrg_dis;
  real_T i_trg;
  real_T set_ParkBrake;
  real_T rotv_in_trg;
  real_T Trq_out_trg;
  cm12ClutchOut Clutch;
  cm12ClutchOut Clutch_dis;
} cm12GearBoxOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12GearBoxOutArray_
#define DEFINED_TYPEDEF_FOR_cm12GearBoxOutArray_

typedef struct {
  cm12GearBoxOut GB_m0;
  cm12GearBoxOut GB_m1;
  cm12GearBoxOut GB_m2;
  cm12GearBoxOut GB_m3;
} cm12GearBoxOutArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PwrSupplyOut_
#define DEFINED_TYPEDEF_FOR_cm12PwrSupplyOut_

typedef struct {
  real_T Pwr_HV1toLV_trg;
} cm12PwrSupplyOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PTControlWheelOut_
#define DEFINED_TYPEDEF_FOR_cm12PTControlWheelOut_

typedef struct {
  real_T Trq_BrakeReg;
  real_T Trq_BrakeReg_max;
} cm12PTControlWheelOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cm12PTControlWheelOutArray_
#define DEFINED_TYPEDEF_FOR_cm12PTControlWheelOutArray_

typedef struct {
  cm12PTControlWheelOut FL;
  cm12PTControlWheelOut FR;
  cm12PTControlWheelOut RL;
  cm12PTControlWheelOut RR;
} cm12PTControlWheelOutArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cmPTControlOut_
#define DEFINED_TYPEDEF_FOR_cmPTControlOut_

typedef struct {
  real_T OperationState;
  real_T OperationError;
  real_T StrategyMode;
  real_T Ignition;
  cm12EngineOut EngineOut;
  cm12MotorOut ISGOut;
  cm12MotorOutArray MotorOut;
  cm12ClutchOut ClutchOut;
  cm12GearBoxOut GearBoxOut;
  cm12GearBoxOutArray GearBoxM_Out;
  cm12PwrSupplyOut PwrSupplyOut;
  cm12PTControlWheelOutArray WheelOut;
} cmPTControlOut;

#endif

/* Parameters (default storage) */
typedef struct P_UNICARPTControl_T_ P_UNICARPTControl_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UNICARPTControl_T RT_MODEL_UNICARPTControl_T;

#endif                                 /* RTW_HEADER_UNICARPTControl_types_h_ */
