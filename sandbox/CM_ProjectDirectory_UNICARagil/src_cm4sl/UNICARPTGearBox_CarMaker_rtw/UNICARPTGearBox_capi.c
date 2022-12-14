/*
 * UNICARPTGearBox_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNICARPTGearBox_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "UNICARPTGearBox.h"
#include "UNICARPTGearBox_capi.h"
#include "UNICARPTGearBox_private.h"
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
  { 0, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.Trq_in"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.Trq_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 2, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.i_TrqIn2Out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 3, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.rot_in"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 4, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.rot_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 5, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.rotv_in"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 6, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/ClutchOut.rotv_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 7, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.Trq_in"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 8, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.Trq_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 9, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.i_TrqIn2Out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 10, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.rot_in"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 11, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.rot_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 12, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.rotv_in"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 13, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Clutch_dis_Out.rotv_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 14, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/GearNo"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 15, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/GearNo_dis"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 16, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Inert_out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 17, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/Trq_SuppInert"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 18, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/i"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 19, TARGET_STRING("UNICARPTGearBox/IF_Out_Selector/i_TrqIn2Out"),
    TARGET_STRING("Value"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 20, TARGET_STRING("GB_i"), 0, 0, 0 },

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

  { rtBlockParameters, 20,
    rtModelParameters, 1 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2374544632U,
    3999922998U,
    1822851218U,
    2676147564U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTGearBox_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void UNICARPTGearBox_InitializeDataMapInfo(RT_MODEL_UNICARPTGearBox_T *const
  UNICARPTGearBox_M)
{
  /* run-time setup of addresses */
  void* *rtDataAddrMap;
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(UNICARPTGearBox_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(21 * sizeof(void* ));
  if ((rtDataAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTGearBox_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtDataAddrMap[0] = (void* )(&UNICARPTGearBox_P.ClutchOutTrq_in_Value);
  rtDataAddrMap[1] = (void* )(&UNICARPTGearBox_P.ClutchOutTrq_out_Value);
  rtDataAddrMap[2] = (void* )(&UNICARPTGearBox_P.ClutchOuti_TrqIn2Out_Value);
  rtDataAddrMap[3] = (void* )(&UNICARPTGearBox_P.ClutchOutrot_in_Value);
  rtDataAddrMap[4] = (void* )(&UNICARPTGearBox_P.ClutchOutrot_out_Value);
  rtDataAddrMap[5] = (void* )(&UNICARPTGearBox_P.ClutchOutrotv_in_Value);
  rtDataAddrMap[6] = (void* )(&UNICARPTGearBox_P.ClutchOutrotv_out_Value);
  rtDataAddrMap[7] = (void* )(&UNICARPTGearBox_P.Clutch_dis_OutTrq_in_Value);
  rtDataAddrMap[8] = (void* )(&UNICARPTGearBox_P.Clutch_dis_OutTrq_out_Value);
  rtDataAddrMap[9] = (void* )(&UNICARPTGearBox_P.Clutch_dis_Outi_TrqIn2Out_Value);
  rtDataAddrMap[10] = (void* )(&UNICARPTGearBox_P.Clutch_dis_Outrot_in_Value);
  rtDataAddrMap[11] = (void* )(&UNICARPTGearBox_P.Clutch_dis_Outrot_out_Value);
  rtDataAddrMap[12] = (void* )(&UNICARPTGearBox_P.Clutch_dis_Outrotv_in_Value);
  rtDataAddrMap[13] = (void* )(&UNICARPTGearBox_P.Clutch_dis_Outrotv_out_Value);
  rtDataAddrMap[14] = (void* )(&UNICARPTGearBox_P.GearNo_Value);
  rtDataAddrMap[15] = (void* )(&UNICARPTGearBox_P.GearNo_dis_Value);
  rtDataAddrMap[16] = (void* )(&UNICARPTGearBox_P.Inert_out_Value);
  rtDataAddrMap[17] = (void* )(&UNICARPTGearBox_P.Trq_SuppInert_Value);
  rtDataAddrMap[18] = (void* )(&UNICARPTGearBox_P.i_Value);
  rtDataAddrMap[19] = (void* )(&UNICARPTGearBox_P.i_TrqIn2Out_Value);
  rtDataAddrMap[20] = (void* )(&UNICARPTGearBox_P.GB_i);
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(UNICARPTGearBox_M->DataMapInfo.mmi) )
          );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  if ((rtVarDimsAddrMap) == (NULL)) {
    rtmSetErrorStatus(UNICARPTGearBox_M, RT_MEMORY_ALLOCATION_ERROR);
    return;
  }

  rtVarDimsAddrMap[0] = (int32_T* )((NULL));

  /* Set C-API version */
  rtwCAPI_SetVersion(UNICARPTGearBox_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(UNICARPTGearBox_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(UNICARPTGearBox_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(UNICARPTGearBox_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(UNICARPTGearBox_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(UNICARPTGearBox_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(UNICARPTGearBox_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(UNICARPTGearBox_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void UNICARPTGearBox_host_InitializeDataMapInfo
    (UNICARPTGearBox_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: UNICARPTGearBox_capi.c */
