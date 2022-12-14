/*
 * UNICARPTMotorCU_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNICARPTMotorCU_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "UNICARPTMotorCU.h"
#include "UNICARPTMotorCU_capi.h"
#include "UNICARPTMotorCU_private.h"
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
  { 0, TARGET_STRING("UNICARPTMotorCU/IF_Out_Selector/ISGOut.Load"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1, TARGET_STRING("UNICARPTMotorCU/IF_Out_Selector/ISGOut.TrqGen_max"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 2, TARGET_STRING("UNICARPTMotorCU/IF_Out_Selector/ISGOut.TrqMot_max"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 3, TARGET_STRING("UNICARPTMotorCU/IF_Out_Selector/Status"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 4, TARGET_STRING("UNICARPTMotorCU/MCU0/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 5, TARGET_STRING("UNICARPTMotorCU/MCU1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 6, TARGET_STRING("UNICARPTMotorCU/MCU2/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 7, TARGET_STRING("UNICARPTMotorCU/MCU3/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 8, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 9, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Wirkungsgradkennfeld"),
    TARGET_STRING("maxIndex"), 1, 1, 0 },

  { 10, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Numerische Stabilität"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 11, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 12, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 13, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 14, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 15, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 16, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 17, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Momentenbegrenzung/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 18, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Momentenbegrenzung/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 19, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Momentenbegrenzung/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 20, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 21, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Wirkungsgradkennfeld"),
    TARGET_STRING("maxIndex"), 1, 1, 0 },

  { 22, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Numerische Stabilität"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 23, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 24, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 25, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 26, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 27, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 28, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 29, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Momentenbegrenzung/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 30, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Momentenbegrenzung/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 31, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Momentenbegrenzung/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 32, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 33, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Wirkungsgradkennfeld"),
    TARGET_STRING("maxIndex"), 1, 1, 0 },

  { 34, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Numerische Stabilität"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 35, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 36, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 37, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 38, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 39, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 40, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 41, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Momentenbegrenzung/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 42, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Momentenbegrenzung/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 43, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Momentenbegrenzung/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 44, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 45, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Wirkungsgradkennfeld"),
    TARGET_STRING("maxIndex"), 1, 1, 0 },

  { 46, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Numerische Stabilität"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 47, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 48, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 49, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 50, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 51, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 52, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/Transfer Fcn"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 53, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Momentenbegrenzung/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 54, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Momentenbegrenzung/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 55, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Momentenbegrenzung/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 56, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 57, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 58, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 59, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/Memory10"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 60, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/Memory11"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 61, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/Memory7"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 62, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/Memory8"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 63, TARGET_STRING("UNICARPTMotorCU/MCU0/Generic MCU Model/Battery/BCU_I_max/Memory9"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 64, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 65, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 66, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 67, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/Memory10"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 68, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/Memory11"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 69, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/Memory7"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 70, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/Memory8"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 71, TARGET_STRING("UNICARPTMotorCU/MCU1/Generic MCU Model/Battery/BCU_I_max/Memory9"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 72, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 73, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 74, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 75, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/Memory10"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 76, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/Memory11"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 77, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/Memory7"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 78, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/Memory8"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 79, TARGET_STRING("UNICARPTMotorCU/MCU2/Generic MCU Model/Battery/BCU_I_max/Memory9"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 80, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 81, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 82, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Antrieb/Temperaturmodell Antrieb/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 83, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/Memory10"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 84, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/Memory11"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 85, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/Memory7"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 86, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/Memory8"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 87, TARGET_STRING("UNICARPTMotorCU/MCU3/Generic MCU Model/Battery/BCU_I_max/Memory9"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 88, TARGET_STRING("MCU_Pr"), 0, 0, 0 },

  { 89, TARGET_STRING("MCU_alpha_m_2_s"), 0, 0, 0 },

  { 90, TARGET_STRING("MCU_area_m_2"), 0, 0, 0 },

  { 91, TARGET_STRING("MCU_cp_J_kgK"), 0, 0, 0 },

  { 92, TARGET_STRING("MCU_m_kg"), 0, 0, 0 },

  { 93, TARGET_STRING("MCU_nue_Ns_m_2"), 0, 0, 0 },

  { 94, TARGET_STRING("MCU_q_W"), 0, 0, 0 },

  { 95, TARGET_STRING("MCU_r_m"), 0, 0, 0 },

  { 96, TARGET_STRING("bat_C1_F"), 0, 2, 0 },

  { 97, TARGET_STRING("bat_C2_F"), 0, 2, 0 },

  { 98, TARGET_STRING("bat_Call_F"), 0, 3, 0 },

  { 99, TARGET_STRING("bat_ICC_A"), 0, 0, 0 },

  { 100, TARGET_STRING("bat_ILim_A"), 0, 4, 0 },

  { 101, TARGET_STRING("bat_ILoadMax_A"), 0, 0, 0 },

  { 102, TARGET_STRING("bat_IMax_A"), 0, 0, 0 },

  { 103, TARGET_STRING("bat_ItMax_A"), 0, 5, 0 },

  { 104, TARGET_STRING("bat_KtMax"), 0, 5, 0 },

  { 105, TARGET_STRING("bat_P_W"), 0, 3, 0 },

  { 106, TARGET_STRING("bat_R1_Ohm"), 0, 2, 0 },

  { 107, TARGET_STRING("bat_R2_Ohm"), 0, 2, 0 },

  { 108, TARGET_STRING("bat_R_Ohm"), 0, 2, 0 },

  { 109, TARGET_STRING("bat_SOCMax"), 0, 3, 0 },

  { 110, TARGET_STRING("bat_SOCMin"), 0, 3, 0 },

  { 111, TARGET_STRING("bat_SOCini"), 0, 3, 0 },

  { 112, TARGET_STRING("bat_TLim_K"), 0, 4, 0 },

  { 113, TARGET_STRING("bat_Uoc_V"), 0, 6, 0 },

  { 114, TARGET_STRING("bat_alpha_W_Km_2"), 0, 0, 0 },

  { 115, TARGET_STRING("bat_area_m_2"), 0, 0, 0 },

  { 116, TARGET_STRING("bat_cp_J_kgK"), 0, 0, 0 },

  { 117, TARGET_STRING("bat_m_kg"), 0, 0, 0 },

  { 118, TARGET_STRING("bat_nPar"), 0, 0, 0 },

  { 119, TARGET_STRING("bat_nSe"), 0, 0, 0 },

  { 120, TARGET_STRING("bat_q_W"), 0, 0, 0 },

  { 121, TARGET_STRING("bat_tBreak_s"), 0, 0, 0 },

  { 122, TARGET_STRING("bat_tIMax_s"), 0, 0, 0 },

  { 123, TARGET_STRING("mot_MC_Nm"), 0, 3, 0 },

  { 124, TARGET_STRING("mot_MMaxReg_Nm"), 0, 4, 0 },

  { 125, TARGET_STRING("mot_MPeak_Nm"), 0, 6, 0 },

  { 126, TARGET_STRING("mot_M_Nm"), 0, 7, 0 },

  { 127, TARGET_STRING("mot_TMPeak_K"), 0, 3, 0 },

  { 128, TARGET_STRING("mot_eta"), 0, 8, 0 },

  { 129, TARGET_STRING("mot_omegaC_rad_s"), 0, 3, 0 },

  { 130, TARGET_STRING("mot_omegaMaxReg_rad_s"), 0, 4, 0 },

  { 131, TARGET_STRING("mot_omegaPeak_rad_s"), 0, 6, 0 },

  { 132, TARGET_STRING("mot_omega_rad_s"), 0, 9, 0 },

  { 133, TARGET_STRING("mot_weight_T"), 0, 3, 0 },

  { 0, (NULL), 0, 0, 0 }
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0, 0 }
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

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 16, 2, 0 },

  { rtwCAPI_VECTOR, 18, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  2,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  3,                                   /* 5 */
  1,                                   /* 6 */
  4,                                   /* 7 */
  1,                                   /* 8 */
  9,                                   /* 9 */
  1,                                   /* 10 */
  5,                                   /* 11 */
  1,                                   /* 12 */
  6,                                   /* 13 */
  1,                                   /* 14 */
  14,                                  /* 15 */
  14,                                  /* 16 */
  15,                                  /* 17 */
  1,                                   /* 18 */
  15                                   /* 19 */
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

  { rtBlockParameters, 88,
    rtModelParameters, 46 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2501820601U,
    3077957532U,
    2564497458U,
    360412199U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTMotorCU_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void UNICARPTMotorCU_InitializeDataMapInfo(RT_MODEL_UNICARPTMotorCU_T *const
  UNICARPTMotorCU_M)
{
  /* run-time setup of addresses */
  void* *rtDataAddrMap;
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(UNICARPTMotorCU_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(134 * sizeof(void* ));
  if ((rtDataAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTMotorCU_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtDataAddrMap[0] = (void* )(&UNICARPTMotorCU_P.ISGOutLoad_Value);
  rtDataAddrMap[1] = (void* )(&UNICARPTMotorCU_P.ISGOutTrqGen_max_Value);
  rtDataAddrMap[2] = (void* )(&UNICARPTMotorCU_P.ISGOutTrqMot_max_Value);
  rtDataAddrMap[3] = (void* )(&UNICARPTMotorCU_P.Status_Value);
  rtDataAddrMap[4] = (void* )(&UNICARPTMotorCU_P.Constant_Value);
  rtDataAddrMap[5] = (void* )(&UNICARPTMotorCU_P.Constant_Value_e4);
  rtDataAddrMap[6] = (void* )(&UNICARPTMotorCU_P.Constant_Value_ey);
  rtDataAddrMap[7] = (void* )(&UNICARPTMotorCU_P.Constant_Value_fi);
  rtDataAddrMap[8] = (void* )(&UNICARPTMotorCU_P.Constant_Value_e);
  rtDataAddrMap[9] = (void* )(&UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex[0]);
  rtDataAddrMap[10] = (void* )(&UNICARPTMotorCU_P.NumerischeStabilitt_Value);
  rtDataAddrMap[11] = (void* )(&UNICARPTMotorCU_P.Integrator_IC);
  rtDataAddrMap[12] = (void* )(&UNICARPTMotorCU_P.Integrator1_IC);
  rtDataAddrMap[13] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition);
  rtDataAddrMap[14] = (void* )(&UNICARPTMotorCU_P.Switch_Threshold);
  rtDataAddrMap[15] = (void* )(&UNICARPTMotorCU_P.TransferFcn_A);
  rtDataAddrMap[16] = (void* )(&UNICARPTMotorCU_P.TransferFcn_C);
  rtDataAddrMap[17] = (void* )(&UNICARPTMotorCU_P.Constant2_Value);
  rtDataAddrMap[18] = (void* )(&UNICARPTMotorCU_P.Constant3_Value);
  rtDataAddrMap[19] = (void* )(&UNICARPTMotorCU_P.Constant4_Value);
  rtDataAddrMap[20] = (void* )(&UNICARPTMotorCU_P.Constant_Value_f);
  rtDataAddrMap[21] = (void* )
    (&UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex_k[0]);
  rtDataAddrMap[22] = (void* )(&UNICARPTMotorCU_P.NumerischeStabilitt_Value_i);
  rtDataAddrMap[23] = (void* )(&UNICARPTMotorCU_P.Integrator_IC_l);
  rtDataAddrMap[24] = (void* )(&UNICARPTMotorCU_P.Integrator1_IC_h);
  rtDataAddrMap[25] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_b);
  rtDataAddrMap[26] = (void* )(&UNICARPTMotorCU_P.Switch_Threshold_j);
  rtDataAddrMap[27] = (void* )(&UNICARPTMotorCU_P.TransferFcn_A_l);
  rtDataAddrMap[28] = (void* )(&UNICARPTMotorCU_P.TransferFcn_C_c);
  rtDataAddrMap[29] = (void* )(&UNICARPTMotorCU_P.Constant2_Value_k);
  rtDataAddrMap[30] = (void* )(&UNICARPTMotorCU_P.Constant3_Value_e);
  rtDataAddrMap[31] = (void* )(&UNICARPTMotorCU_P.Constant4_Value_c);
  rtDataAddrMap[32] = (void* )(&UNICARPTMotorCU_P.Constant_Value_ea);
  rtDataAddrMap[33] = (void* )
    (&UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex_c[0]);
  rtDataAddrMap[34] = (void* )(&UNICARPTMotorCU_P.NumerischeStabilitt_Value_io);
  rtDataAddrMap[35] = (void* )(&UNICARPTMotorCU_P.Integrator_IC_e);
  rtDataAddrMap[36] = (void* )(&UNICARPTMotorCU_P.Integrator1_IC_hc);
  rtDataAddrMap[37] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_d);
  rtDataAddrMap[38] = (void* )(&UNICARPTMotorCU_P.Switch_Threshold_js);
  rtDataAddrMap[39] = (void* )(&UNICARPTMotorCU_P.TransferFcn_A_m);
  rtDataAddrMap[40] = (void* )(&UNICARPTMotorCU_P.TransferFcn_C_d);
  rtDataAddrMap[41] = (void* )(&UNICARPTMotorCU_P.Constant2_Value_kc);
  rtDataAddrMap[42] = (void* )(&UNICARPTMotorCU_P.Constant3_Value_k);
  rtDataAddrMap[43] = (void* )(&UNICARPTMotorCU_P.Constant4_Value_ct);
  rtDataAddrMap[44] = (void* )(&UNICARPTMotorCU_P.Constant_Value_fd);
  rtDataAddrMap[45] = (void* )
    (&UNICARPTMotorCU_P.Wirkungsgradkennfeld_maxIndex_j[0]);
  rtDataAddrMap[46] = (void* )(&UNICARPTMotorCU_P.NumerischeStabilitt_Value_k);
  rtDataAddrMap[47] = (void* )(&UNICARPTMotorCU_P.Integrator_IC_o);
  rtDataAddrMap[48] = (void* )(&UNICARPTMotorCU_P.Integrator1_IC_a);
  rtDataAddrMap[49] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_m);
  rtDataAddrMap[50] = (void* )(&UNICARPTMotorCU_P.Switch_Threshold_f);
  rtDataAddrMap[51] = (void* )(&UNICARPTMotorCU_P.TransferFcn_A_h);
  rtDataAddrMap[52] = (void* )(&UNICARPTMotorCU_P.TransferFcn_C_cc);
  rtDataAddrMap[53] = (void* )(&UNICARPTMotorCU_P.Constant2_Value_o);
  rtDataAddrMap[54] = (void* )(&UNICARPTMotorCU_P.Constant3_Value_i);
  rtDataAddrMap[55] = (void* )(&UNICARPTMotorCU_P.Constant4_Value_e);
  rtDataAddrMap[56] = (void* )(&UNICARPTMotorCU_P.CompareToConstant_const);
  rtDataAddrMap[57] = (void* )(&UNICARPTMotorCU_P.Gain_Gain);
  rtDataAddrMap[58] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_j);
  rtDataAddrMap[59] = (void* )(&UNICARPTMotorCU_P.Memory10_InitialCondition);
  rtDataAddrMap[60] = (void* )(&UNICARPTMotorCU_P.Memory11_InitialCondition);
  rtDataAddrMap[61] = (void* )(&UNICARPTMotorCU_P.Memory7_InitialCondition);
  rtDataAddrMap[62] = (void* )(&UNICARPTMotorCU_P.Memory8_InitialCondition);
  rtDataAddrMap[63] = (void* )(&UNICARPTMotorCU_P.Memory9_InitialCondition);
  rtDataAddrMap[64] = (void* )(&UNICARPTMotorCU_P.CompareToConstant_const_m);
  rtDataAddrMap[65] = (void* )(&UNICARPTMotorCU_P.Gain_Gain_b);
  rtDataAddrMap[66] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_l);
  rtDataAddrMap[67] = (void* )(&UNICARPTMotorCU_P.Memory10_InitialCondition_p);
  rtDataAddrMap[68] = (void* )(&UNICARPTMotorCU_P.Memory11_InitialCondition_o);
  rtDataAddrMap[69] = (void* )(&UNICARPTMotorCU_P.Memory7_InitialCondition_f);
  rtDataAddrMap[70] = (void* )(&UNICARPTMotorCU_P.Memory8_InitialCondition_h);
  rtDataAddrMap[71] = (void* )(&UNICARPTMotorCU_P.Memory9_InitialCondition_m);
  rtDataAddrMap[72] = (void* )(&UNICARPTMotorCU_P.CompareToConstant_const_d);
  rtDataAddrMap[73] = (void* )(&UNICARPTMotorCU_P.Gain_Gain_d);
  rtDataAddrMap[74] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_a);
  rtDataAddrMap[75] = (void* )(&UNICARPTMotorCU_P.Memory10_InitialCondition_k);
  rtDataAddrMap[76] = (void* )(&UNICARPTMotorCU_P.Memory11_InitialCondition_ox);
  rtDataAddrMap[77] = (void* )(&UNICARPTMotorCU_P.Memory7_InitialCondition_b);
  rtDataAddrMap[78] = (void* )(&UNICARPTMotorCU_P.Memory8_InitialCondition_hu);
  rtDataAddrMap[79] = (void* )(&UNICARPTMotorCU_P.Memory9_InitialCondition_a);
  rtDataAddrMap[80] = (void* )(&UNICARPTMotorCU_P.CompareToConstant_const_h);
  rtDataAddrMap[81] = (void* )(&UNICARPTMotorCU_P.Gain_Gain_l);
  rtDataAddrMap[82] = (void* )(&UNICARPTMotorCU_P.Memory_InitialCondition_o);
  rtDataAddrMap[83] = (void* )(&UNICARPTMotorCU_P.Memory10_InitialCondition_m);
  rtDataAddrMap[84] = (void* )(&UNICARPTMotorCU_P.Memory11_InitialCondition_n);
  rtDataAddrMap[85] = (void* )(&UNICARPTMotorCU_P.Memory7_InitialCondition_n);
  rtDataAddrMap[86] = (void* )(&UNICARPTMotorCU_P.Memory8_InitialCondition_e);
  rtDataAddrMap[87] = (void* )(&UNICARPTMotorCU_P.Memory9_InitialCondition_n);
  rtDataAddrMap[88] = (void* )(&UNICARPTMotorCU_P.MCU_Pr);
  rtDataAddrMap[89] = (void* )(&UNICARPTMotorCU_P.MCU_alpha_m_2_s);
  rtDataAddrMap[90] = (void* )(&UNICARPTMotorCU_P.MCU_area_m_2);
  rtDataAddrMap[91] = (void* )(&UNICARPTMotorCU_P.MCU_cp_J_kgK);
  rtDataAddrMap[92] = (void* )(&UNICARPTMotorCU_P.MCU_m_kg);
  rtDataAddrMap[93] = (void* )(&UNICARPTMotorCU_P.MCU_nue_Ns_m_2);
  rtDataAddrMap[94] = (void* )(&UNICARPTMotorCU_P.MCU_q_W);
  rtDataAddrMap[95] = (void* )(&UNICARPTMotorCU_P.MCU_r_m);
  rtDataAddrMap[96] = (void* )(&UNICARPTMotorCU_P.bat_C1_F[0]);
  rtDataAddrMap[97] = (void* )(&UNICARPTMotorCU_P.bat_C2_F[0]);
  rtDataAddrMap[98] = (void* )(&UNICARPTMotorCU_P.bat_Call_F[0]);
  rtDataAddrMap[99] = (void* )(&UNICARPTMotorCU_P.bat_ICC_A);
  rtDataAddrMap[100] = (void* )(&UNICARPTMotorCU_P.bat_ILim_A[0]);
  rtDataAddrMap[101] = (void* )(&UNICARPTMotorCU_P.bat_ILoadMax_A);
  rtDataAddrMap[102] = (void* )(&UNICARPTMotorCU_P.bat_IMax_A);
  rtDataAddrMap[103] = (void* )(&UNICARPTMotorCU_P.bat_ItMax_A[0]);
  rtDataAddrMap[104] = (void* )(&UNICARPTMotorCU_P.bat_KtMax[0]);
  rtDataAddrMap[105] = (void* )(&UNICARPTMotorCU_P.bat_P_W[0]);
  rtDataAddrMap[106] = (void* )(&UNICARPTMotorCU_P.bat_R1_Ohm[0]);
  rtDataAddrMap[107] = (void* )(&UNICARPTMotorCU_P.bat_R2_Ohm[0]);
  rtDataAddrMap[108] = (void* )(&UNICARPTMotorCU_P.bat_R_Ohm[0]);
  rtDataAddrMap[109] = (void* )(&UNICARPTMotorCU_P.bat_SOCMax[0]);
  rtDataAddrMap[110] = (void* )(&UNICARPTMotorCU_P.bat_SOCMin[0]);
  rtDataAddrMap[111] = (void* )(&UNICARPTMotorCU_P.bat_SOCini[0]);
  rtDataAddrMap[112] = (void* )(&UNICARPTMotorCU_P.bat_TLim_K[0]);
  rtDataAddrMap[113] = (void* )(&UNICARPTMotorCU_P.bat_Uoc_V[0]);
  rtDataAddrMap[114] = (void* )(&UNICARPTMotorCU_P.bat_alpha_W_Km_2);
  rtDataAddrMap[115] = (void* )(&UNICARPTMotorCU_P.bat_area_m_2);
  rtDataAddrMap[116] = (void* )(&UNICARPTMotorCU_P.bat_cp_J_kgK);
  rtDataAddrMap[117] = (void* )(&UNICARPTMotorCU_P.bat_m_kg);
  rtDataAddrMap[118] = (void* )(&UNICARPTMotorCU_P.bat_nPar);
  rtDataAddrMap[119] = (void* )(&UNICARPTMotorCU_P.bat_nSe);
  rtDataAddrMap[120] = (void* )(&UNICARPTMotorCU_P.bat_q_W);
  rtDataAddrMap[121] = (void* )(&UNICARPTMotorCU_P.bat_tBreak_s);
  rtDataAddrMap[122] = (void* )(&UNICARPTMotorCU_P.bat_tIMax_s);
  rtDataAddrMap[123] = (void* )(&UNICARPTMotorCU_P.mot_MC_Nm[0]);
  rtDataAddrMap[124] = (void* )(&UNICARPTMotorCU_P.mot_MMaxReg_Nm[0]);
  rtDataAddrMap[125] = (void* )(&UNICARPTMotorCU_P.mot_MPeak_Nm[0]);
  rtDataAddrMap[126] = (void* )(&UNICARPTMotorCU_P.mot_M_Nm[0]);
  rtDataAddrMap[127] = (void* )(&UNICARPTMotorCU_P.mot_TMPeak_K[0]);
  rtDataAddrMap[128] = (void* )(&UNICARPTMotorCU_P.mot_eta[0]);
  rtDataAddrMap[129] = (void* )(&UNICARPTMotorCU_P.mot_omegaC_rad_s[0]);
  rtDataAddrMap[130] = (void* )(&UNICARPTMotorCU_P.mot_omegaMaxReg_rad_s[0]);
  rtDataAddrMap[131] = (void* )(&UNICARPTMotorCU_P.mot_omegaPeak_rad_s[0]);
  rtDataAddrMap[132] = (void* )(&UNICARPTMotorCU_P.mot_omega_rad_s[0]);
  rtDataAddrMap[133] = (void* )(&UNICARPTMotorCU_P.mot_weight_T[0]);
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(UNICARPTMotorCU_M->DataMapInfo.mmi) )
          );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  if ((rtVarDimsAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTMotorCU_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtVarDimsAddrMap[0] = (int32_T* )((NULL));

  /* Set C-API version */
  rtwCAPI_SetVersion(UNICARPTMotorCU_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(UNICARPTMotorCU_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(UNICARPTMotorCU_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(UNICARPTMotorCU_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(UNICARPTMotorCU_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(UNICARPTMotorCU_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(UNICARPTMotorCU_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(UNICARPTMotorCU_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void UNICARPTMotorCU_host_InitializeDataMapInfo
    (UNICARPTMotorCU_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: UNICARPTMotorCU_capi.c */
