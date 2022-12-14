/*
 * UNICARPTGearBox.h
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

#ifndef RTW_HEADER_UNICARPTGearBox_h_
#define RTW_HEADER_UNICARPTGearBox_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef UNICARPTGearBox_COMMON_INCLUDES_
# define UNICARPTGearBox_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* UNICARPTGearBox_COMMON_INCLUDES_ */

#include "UNICARPTGearBox_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define UNICARPTGearBox_M_TYPE         RT_MODEL_UNICARPTGearBox_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.0002
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmPTGearBoxIn FromCM;                /* '<Root>/FromCM' */
  cmPTGearBoxCfgOut CfgOutFromCM;      /* '<Root>/CfgOutFromCM' */
} ExtU_UNICARPTGearBox_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmPTGearBoxOut ToCM;                 /* '<Root>/ToCM' */
} ExtY_UNICARPTGearBox_T;

/* Parameters (default storage) */
struct P_UNICARPTGearBox_T_ {
  real_T GB_i;                         /* Variable: GB_i
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain2'
                                        */
  real_T GearNo_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/GearNo'
                                        */
  real_T GearNo_dis_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/GearNo_dis'
                                        */
  real_T i_Value;                      /* Expression: 0
                                        * Referenced by: '<S1>/i'
                                        */
  real_T Inert_out_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Inert_out'
                                        */
  real_T i_TrqIn2Out_Value;            /* Expression: 0
                                        * Referenced by: '<S1>/i_TrqIn2Out'
                                        */
  real_T Trq_SuppInert_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Trq_SuppInert'
                                        */
  real_T ClutchOutrot_in_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.rot_in'
                                        */
  real_T ClutchOutrotv_in_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.rotv_in'
                                        */
  real_T ClutchOutrot_out_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.rot_out'
                                        */
  real_T ClutchOutrotv_out_Value;      /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.rotv_out'
                                        */
  real_T ClutchOutTrq_in_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.Trq_in'
                                        */
  real_T ClutchOutTrq_out_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.Trq_out'
                                        */
  real_T ClutchOuti_TrqIn2Out_Value;   /* Expression: 0
                                        * Referenced by: '<S1>/ClutchOut.i_TrqIn2Out'
                                        */
  real_T Clutch_dis_Outrot_in_Value;   /* Expression: 0
                                        * Referenced by: '<S1>/Clutch_dis_Out.rot_in'
                                        */
  real_T Clutch_dis_Outrotv_in_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/Clutch_dis_Out.rotv_in'
                                        */
  real_T Clutch_dis_Outrot_out_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/Clutch_dis_Out.rot_out'
                                        */
  real_T Clutch_dis_Outrotv_out_Value; /* Expression: 0
                                        * Referenced by: '<S1>/Clutch_dis_Out.rotv_out'
                                        */
  real_T Clutch_dis_OutTrq_in_Value;   /* Expression: 0
                                        * Referenced by: '<S1>/Clutch_dis_Out.Trq_in'
                                        */
  real_T Clutch_dis_OutTrq_out_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/Clutch_dis_Out.Trq_out'
                                        */
  real_T Clutch_dis_Outi_TrqIn2Out_Value;/* Expression: 0
                                          * Referenced by: '<S1>/Clutch_dis_Out.i_TrqIn2Out'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_UNICARPTGearBox_T {
  const char_T *errorStatus;
  const void *constBlockIO;
  void *inputs;
  void *outputs;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[21];
    int32_T* vardimsAddress[21];
    RTWLoggingFcnPtr loggingPtrs[21];
  } DataMapInfo;
};

/* Block parameters (default storage) */
extern P_UNICARPTGearBox_T UNICARPTGearBox_P;

/* External data declarations for dependent source files */
extern const cmPTGearBoxOut UNICARPTGearBox_rtZcmPTGearBoxOut;/* cmPTGearBoxOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_UNICARPTGearBox_T *UNICARPTGearBox(struct tInfos *inf);
extern void UNICARPTGearBox_initialize(RT_MODEL_UNICARPTGearBox_T *const
  UNICARPTGearBox_M);
extern void UNICARPTGearBox_step(RT_MODEL_UNICARPTGearBox_T *const
  UNICARPTGearBox_M);
extern void UNICARPTGearBox_terminate(RT_MODEL_UNICARPTGearBox_T
  * UNICARPTGearBox_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  UNICARPTGearBox_GetCAPIStaticMap(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'UNICARPTGearBox'
 * '<S1>'   : 'UNICARPTGearBox/IF_Out_Selector'
 */
#endif                                 /* RTW_HEADER_UNICARPTGearBox_h_ */
