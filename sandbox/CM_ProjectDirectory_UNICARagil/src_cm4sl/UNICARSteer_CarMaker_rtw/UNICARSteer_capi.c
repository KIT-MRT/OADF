/*
 * UNICARSteer_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNICARSteer_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "UNICARSteer.h"
#include "UNICARSteer_capi.h"
#include "UNICARSteer_private.h"
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
  { 0, TARGET_STRING("UNICARSteer/IF_Out_Selector/Ang"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1, TARGET_STRING("UNICARSteer/IF_Out_Selector/AngAcc"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 2, TARGET_STRING("UNICARSteer/IF_Out_Selector/AngVel"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 3, TARGET_STRING("UNICARSteer/IF_Out_Selector/AssistFrc"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 4, TARGET_STRING("UNICARSteer/IF_Out_Selector/AssistTrqCol"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 5, TARGET_STRING("UNICARSteer/IF_Out_Selector/AssistTrqPin"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 6, TARGET_STRING("UNICARSteer/IF_Out_Selector/Trq"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 7, TARGET_STRING("UNICARSteer/IF_Out_Selector/TrqStatic"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 8, TARGET_STRING("UNICARSteer/IF_Out_Selector/iSteer2q_L"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 9, TARGET_STRING("UNICARSteer/IF_Out_Selector/iSteer2q_R"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 10, TARGET_STRING("UNICARSteer/Subsystem/Switch4"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 11, TARGET_STRING("UNICARSteer/Subsystem/Switch5"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 12, TARGET_STRING("UNICARSteer/Subsystem/Switch6"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 13, TARGET_STRING("UNICARSteer/Subsystem/Switch7"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 14, TARGET_STRING("UNICARSteer/Subsystem/Error Handling/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 15, TARGET_STRING("UNICARSteer/Subsystem/Error Handling/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 16, TARGET_STRING("UNICARSteer/Subsystem/Error Handling1/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 17, TARGET_STRING("UNICARSteer/Subsystem/Error Handling1/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 18, TARGET_STRING("UNICARSteer/Subsystem/Error Handling2/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 19, TARGET_STRING("UNICARSteer/Subsystem/Error Handling2/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 20, TARGET_STRING("UNICARSteer/Subsystem/Error Handling3/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 21, TARGET_STRING("UNICARSteer/Subsystem/Error Handling3/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 22, TARGET_STRING("UNICARSteer/Subsystem/Steer FL/Gain9"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 23, TARGET_STRING("UNICARSteer/Subsystem/Steer FL/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 24, TARGET_STRING("UNICARSteer/Subsystem/Steer FR/Gain9"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 25, TARGET_STRING("UNICARSteer/Subsystem/Steer FR/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 26, TARGET_STRING("UNICARSteer/Subsystem/Steer RL/Gain9"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 27, TARGET_STRING("UNICARSteer/Subsystem/Steer RL/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 28, TARGET_STRING("UNICARSteer/Subsystem/Steer RR/Gain9"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 29, TARGET_STRING("UNICARSteer/Subsystem/Steer RR/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 30, TARGET_STRING("ste_KPT1"), 0, 0, 0 },

  { 31, TARGET_STRING("ste_TPT1_1_s"), 0, 0, 0 },

  { 32, TARGET_STRING("ste_delta_p_lim_rad_s"), 0, 0, 0 },

  { 33, TARGET_STRING("ste_dyn"), 0, 0, 0 },

  { 34, TARGET_STRING("ste_max_delta_FLRR_rad"), 0, 0, 0 },

  { 35, TARGET_STRING("ste_max_delta_FRRL_rad"), 0, 0, 0 },

  { 36, TARGET_STRING("ste_min_delta_FLRR_rad"), 0, 0, 0 },

  { 37, TARGET_STRING("ste_min_delta_FRRL_rad"), 0, 0, 0 },

  { 38, TARGET_STRING("ste_t_s"), 0, 0, 0 },

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
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
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

  { rtBlockParameters, 30,
    rtModelParameters, 9 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2958658495U,
    3996986882U,
    2189067783U,
    2508124468U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  UNICARSteer_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void UNICARSteer_InitializeDataMapInfo(RT_MODEL_UNICARSteer_T *const
  UNICARSteer_M)
{
  /* run-time setup of addresses */
  void* *rtDataAddrMap;
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(UNICARSteer_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(39 * sizeof(void* ));
  if ((rtDataAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARSteer_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtDataAddrMap[0] = (void* )(&UNICARSteer_P.Ang_Value);
  rtDataAddrMap[1] = (void* )(&UNICARSteer_P.AngAcc_Value);
  rtDataAddrMap[2] = (void* )(&UNICARSteer_P.AngVel_Value);
  rtDataAddrMap[3] = (void* )(&UNICARSteer_P.AssistFrc_Value);
  rtDataAddrMap[4] = (void* )(&UNICARSteer_P.AssistTrqCol_Value);
  rtDataAddrMap[5] = (void* )(&UNICARSteer_P.AssistTrqPin_Value);
  rtDataAddrMap[6] = (void* )(&UNICARSteer_P.Trq_Value);
  rtDataAddrMap[7] = (void* )(&UNICARSteer_P.TrqStatic_Value);
  rtDataAddrMap[8] = (void* )(&UNICARSteer_P.iSteer2q_L_Value);
  rtDataAddrMap[9] = (void* )(&UNICARSteer_P.iSteer2q_R_Value);
  rtDataAddrMap[10] = (void* )(&UNICARSteer_P.Switch4_Threshold);
  rtDataAddrMap[11] = (void* )(&UNICARSteer_P.Switch5_Threshold);
  rtDataAddrMap[12] = (void* )(&UNICARSteer_P.Switch6_Threshold);
  rtDataAddrMap[13] = (void* )(&UNICARSteer_P.Switch7_Threshold);
  rtDataAddrMap[14] = (void* )(&UNICARSteer_P.Memory_InitialCondition_n);
  rtDataAddrMap[15] = (void* )(&UNICARSteer_P.Switch_Threshold_m);
  rtDataAddrMap[16] = (void* )(&UNICARSteer_P.Memory_InitialCondition_p2);
  rtDataAddrMap[17] = (void* )(&UNICARSteer_P.Switch_Threshold_g);
  rtDataAddrMap[18] = (void* )(&UNICARSteer_P.Memory_InitialCondition);
  rtDataAddrMap[19] = (void* )(&UNICARSteer_P.Switch_Threshold);
  rtDataAddrMap[20] = (void* )(&UNICARSteer_P.Memory_InitialCondition_j);
  rtDataAddrMap[21] = (void* )(&UNICARSteer_P.Switch_Threshold_e);
  rtDataAddrMap[22] = (void* )(&UNICARSteer_P.Gain9_Gain);
  rtDataAddrMap[23] = (void* )(&UNICARSteer_P.Memory_InitialCondition_e);
  rtDataAddrMap[24] = (void* )(&UNICARSteer_P.Gain9_Gain_e);
  rtDataAddrMap[25] = (void* )(&UNICARSteer_P.Memory_InitialCondition_f);
  rtDataAddrMap[26] = (void* )(&UNICARSteer_P.Gain9_Gain_a);
  rtDataAddrMap[27] = (void* )(&UNICARSteer_P.Memory_InitialCondition_p);
  rtDataAddrMap[28] = (void* )(&UNICARSteer_P.Gain9_Gain_af);
  rtDataAddrMap[29] = (void* )(&UNICARSteer_P.Memory_InitialCondition_c);
  rtDataAddrMap[30] = (void* )(&UNICARSteer_P.ste_KPT1);
  rtDataAddrMap[31] = (void* )(&UNICARSteer_P.ste_TPT1_1_s);
  rtDataAddrMap[32] = (void* )(&UNICARSteer_P.ste_delta_p_lim_rad_s);
  rtDataAddrMap[33] = (void* )(&UNICARSteer_P.ste_dyn);
  rtDataAddrMap[34] = (void* )(&UNICARSteer_P.ste_max_delta_FLRR_rad);
  rtDataAddrMap[35] = (void* )(&UNICARSteer_P.ste_max_delta_FRRL_rad);
  rtDataAddrMap[36] = (void* )(&UNICARSteer_P.ste_min_delta_FLRR_rad);
  rtDataAddrMap[37] = (void* )(&UNICARSteer_P.ste_min_delta_FRRL_rad);
  rtDataAddrMap[38] = (void* )(&UNICARSteer_P.ste_t_s);
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(UNICARSteer_M->DataMapInfo.mmi) ) );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  if ((rtVarDimsAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARSteer_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtVarDimsAddrMap[0] = (int32_T* )((NULL));

  /* Set C-API version */
  rtwCAPI_SetVersion(UNICARSteer_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(UNICARSteer_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(UNICARSteer_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(UNICARSteer_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(UNICARSteer_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(UNICARSteer_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(UNICARSteer_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(UNICARSteer_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void UNICARSteer_host_InitializeDataMapInfo(UNICARSteer_host_DataMapInfo_T
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

/* EOF: UNICARSteer_capi.c */
