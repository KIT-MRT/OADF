/*
 * UNICARPTMotor_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNICARPTMotor_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "UNICARPTMotor.h"
#include "UNICARPTMotor_capi.h"
#include "UNICARPTMotor_private.h"
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
  { 0, TARGET_STRING("UNICARPTMotor/Motor/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1, TARGET_STRING("UNICARPTMotor/Motor/Wirkungsgradkennfeld"),
    TARGET_STRING("maxIndex"), 1, 1, 0 },

  { 2, TARGET_STRING("UNICARPTMotor/Motor/Switch4"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 3, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 4, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 5, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/1-D Lookup Table"),
    TARGET_STRING("maxIndex"), 1, 1, 0 },

  { 6, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 7, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/PT1/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 8, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/PT2/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 9, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/PT2/Gain2"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 10, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/PT2/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 11, TARGET_STRING("UNICARPTMotor/Motor/Momentenregelung An/PT2/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 12, TARGET_STRING("mot_J_kgm_2"), 0, 0, 0 },

  { 13, TARGET_STRING("mot_KPT1"), 0, 0, 0 },

  { 14, TARGET_STRING("mot_KPT2"), 0, 0, 0 },

  { 15, TARGET_STRING("mot_MMax_PT12_Nm"), 0, 2, 0 },

  { 16, TARGET_STRING("mot_M_Nm"), 0, 3, 0 },

  { 17, TARGET_STRING("mot_PMax_W"), 0, 0, 0 },

  { 18, TARGET_STRING("mot_TPT1_1_s"), 0, 0, 0 },

  { 19, TARGET_STRING("mot_TPT2_1_s"), 0, 0, 0 },

  { 20, TARGET_STRING("mot_dPT2"), 0, 0, 0 },

  { 21, TARGET_STRING("mot_dyn"), 0, 0, 0 },

  { 22, TARGET_STRING("mot_eta"), 0, 4, 0 },

  { 23, TARGET_STRING("mot_omega_PT12_rad_s"), 0, 2, 0 },

  { 24, TARGET_STRING("mot_omega_rad_s"), 0, 5, 0 },

  { 25, TARGET_STRING("mot_weight_PT12"), 0, 6, 0 },

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

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 12, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  2,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  4,                                   /* 5 */
  1,                                   /* 6 */
  14,                                  /* 7 */
  14,                                  /* 8 */
  15,                                  /* 9 */
  1,                                   /* 10 */
  15,                                  /* 11 */
  4,                                   /* 12 */
  4                                    /* 13 */
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

  { rtBlockParameters, 12,
    rtModelParameters, 14 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2186788401U,
    1703520840U,
    4022346332U,
    4085957330U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTMotor_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void UNICARPTMotor_InitializeDataMapInfo(RT_MODEL_UNICARPTMotor_T *const
  UNICARPTMotor_M)
{
  /* run-time setup of addresses */
  void* *rtDataAddrMap;
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(UNICARPTMotor_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(26 * sizeof(void* ));
  if ((rtDataAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTMotor_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtDataAddrMap[0] = (void* )(&UNICARPTMotor_P.Gain_Gain);
  rtDataAddrMap[1] = (void* )(&UNICARPTMotor_P.Wirkungsgradkennfeld_maxIndex[0]);
  rtDataAddrMap[2] = (void* )(&UNICARPTMotor_P.Switch4_Threshold);
  rtDataAddrMap[3] = (void* )(&UNICARPTMotor_P.Constant_Value);
  rtDataAddrMap[4] = (void* )(&UNICARPTMotor_P.Constant1_Value);
  rtDataAddrMap[5] = (void* )(&UNICARPTMotor_P.uDLookupTable_maxIndex[0]);
  rtDataAddrMap[6] = (void* )(&UNICARPTMotor_P.Memory_InitialCondition);
  rtDataAddrMap[7] = (void* )(&UNICARPTMotor_P.Integrator_IC);
  rtDataAddrMap[8] = (void* )(&UNICARPTMotor_P.Constant3_Value);
  rtDataAddrMap[9] = (void* )(&UNICARPTMotor_P.Gain2_Gain);
  rtDataAddrMap[10] = (void* )(&UNICARPTMotor_P.Integrator_IC_e);
  rtDataAddrMap[11] = (void* )(&UNICARPTMotor_P.Integrator1_IC);
  rtDataAddrMap[12] = (void* )(&UNICARPTMotor_P.mot_J_kgm_2);
  rtDataAddrMap[13] = (void* )(&UNICARPTMotor_P.mot_KPT1);
  rtDataAddrMap[14] = (void* )(&UNICARPTMotor_P.mot_KPT2);
  rtDataAddrMap[15] = (void* )(&UNICARPTMotor_P.mot_MMax_PT12_Nm[0]);
  rtDataAddrMap[16] = (void* )(&UNICARPTMotor_P.mot_M_Nm[0]);
  rtDataAddrMap[17] = (void* )(&UNICARPTMotor_P.mot_PMax_W);
  rtDataAddrMap[18] = (void* )(&UNICARPTMotor_P.mot_TPT1_1_s);
  rtDataAddrMap[19] = (void* )(&UNICARPTMotor_P.mot_TPT2_1_s);
  rtDataAddrMap[20] = (void* )(&UNICARPTMotor_P.mot_dPT2);
  rtDataAddrMap[21] = (void* )(&UNICARPTMotor_P.mot_dyn);
  rtDataAddrMap[22] = (void* )(&UNICARPTMotor_P.mot_eta[0]);
  rtDataAddrMap[23] = (void* )(&UNICARPTMotor_P.mot_omega_PT12_rad_s[0]);
  rtDataAddrMap[24] = (void* )(&UNICARPTMotor_P.mot_omega_rad_s[0]);
  rtDataAddrMap[25] = (void* )(&UNICARPTMotor_P.mot_weight_PT12[0]);
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(UNICARPTMotor_M->DataMapInfo.mmi) ) );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  if ((rtVarDimsAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTMotor_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtVarDimsAddrMap[0] = (int32_T* )((NULL));

  /* Set C-API version */
  rtwCAPI_SetVersion(UNICARPTMotor_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(UNICARPTMotor_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(UNICARPTMotor_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(UNICARPTMotor_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(UNICARPTMotor_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(UNICARPTMotor_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(UNICARPTMotor_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(UNICARPTMotor_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void UNICARPTMotor_host_InitializeDataMapInfo(UNICARPTMotor_host_DataMapInfo_T
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

/* EOF: UNICARPTMotor_capi.c */
