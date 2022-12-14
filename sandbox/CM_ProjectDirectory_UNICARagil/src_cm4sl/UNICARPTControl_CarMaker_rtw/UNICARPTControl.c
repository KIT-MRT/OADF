/*
 * UNICARPTControl.c
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

#include "UNICARPTControl_capi.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "UNICARPTControl.h"
#include "UNICARPTControl_private.h"
#include "UNICARPTControl_wrap.h"

/* CarMaker: Compile- and link-time checks for the right Matlab version. */
#if MATSUPP_NUMVER == 90700

/* The following statement will cause an "unresolved symbol" error when
   linking with a MatSupp library built for the wrong Matlab version. */
extern int MATSUPP_VARNAME(MatSupp, MATSUPP_NUMVER);
void *MATSUPP_VARNAME(MODEL, MATSUPP_NUMVER) = &MATSUPP_VARNAME(MatSupp,
  MATSUPP_NUMVER);

#else
# error Compiler options unsuitable for C code created with Matlab 9.7
#endif

const cmPTControlOut UNICARPTControl_rtZcmPTControlOut = {
  0.0,                                 /* OperationState */
  0.0,                                 /* OperationError */
  0.0,                                 /* StrategyMode */
  0.0,                                 /* Ignition */

  {
    0.0,                               /* set_ISC */
    0.0,                               /* FuelCutOff */
    0.0,                               /* Load */
    0.0,                               /* Trq_trg */
    0.0                                /* rotv_trg */
  },                                   /* EngineOut */

  {
    0.0,                               /* Load */
    0.0,                               /* Trq_trg */
    0.0                                /* rotv_trg */
  },                                   /* ISGOut */

  {
    {
      0.0,                             /* Load */
      0.0,                             /* Trq_trg */
      0.0                              /* rotv_trg */
    },                                 /* m0 */

    {
      0.0,                             /* Load */
      0.0,                             /* Trq_trg */
      0.0                              /* rotv_trg */
    },                                 /* m1 */

    {
      0.0,                             /* Load */
      0.0,                             /* Trq_trg */
      0.0                              /* rotv_trg */
    },                                 /* m2 */

    {
      0.0,                             /* Load */
      0.0,                             /* Trq_trg */
      0.0                              /* rotv_trg */
    }                                  /* m3 */
  },                                   /* MotorOut */

  {
    0.0,                               /* Pos */
    0.0,                               /* rotv_out_trg */
    0.0                                /* Trq_out_trg */
  },                                   /* ClutchOut */

  {
    0.0,                               /* GearNoTrg */
    0.0,                               /* GearNoTrg_dis */
    0.0,                               /* i_trg */
    0.0,                               /* set_ParkBrake */
    0.0,                               /* rotv_in_trg */
    0.0,                               /* Trq_out_trg */

    {
      0.0,                             /* Pos */
      0.0,                             /* rotv_out_trg */
      0.0                              /* Trq_out_trg */
    },                                 /* Clutch */

    {
      0.0,                             /* Pos */
      0.0,                             /* rotv_out_trg */
      0.0                              /* Trq_out_trg */
    }                                  /* Clutch_dis */
  },                                   /* GearBoxOut */

  {
    {
      0.0,                             /* GearNoTrg */
      0.0,                             /* GearNoTrg_dis */
      0.0,                             /* i_trg */
      0.0,                             /* set_ParkBrake */
      0.0,                             /* rotv_in_trg */
      0.0,                             /* Trq_out_trg */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      },                               /* Clutch */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      }                                /* Clutch_dis */
    },                                 /* GB_m0 */

    {
      0.0,                             /* GearNoTrg */
      0.0,                             /* GearNoTrg_dis */
      0.0,                             /* i_trg */
      0.0,                             /* set_ParkBrake */
      0.0,                             /* rotv_in_trg */
      0.0,                             /* Trq_out_trg */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      },                               /* Clutch */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      }                                /* Clutch_dis */
    },                                 /* GB_m1 */

    {
      0.0,                             /* GearNoTrg */
      0.0,                             /* GearNoTrg_dis */
      0.0,                             /* i_trg */
      0.0,                             /* set_ParkBrake */
      0.0,                             /* rotv_in_trg */
      0.0,                             /* Trq_out_trg */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      },                               /* Clutch */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      }                                /* Clutch_dis */
    },                                 /* GB_m2 */

    {
      0.0,                             /* GearNoTrg */
      0.0,                             /* GearNoTrg_dis */
      0.0,                             /* i_trg */
      0.0,                             /* set_ParkBrake */
      0.0,                             /* rotv_in_trg */
      0.0,                             /* Trq_out_trg */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      },                               /* Clutch */

      {
        0.0,                           /* Pos */
        0.0,                           /* rotv_out_trg */
        0.0                            /* Trq_out_trg */
      }                                /* Clutch_dis */
    }                                  /* GB_m3 */
  },                                   /* GearBoxM_Out */

  {
    0.0                                /* Pwr_HV1toLV_trg */
  },                                   /* PwrSupplyOut */

  {
    {
      0.0,                             /* Trq_BrakeReg */
      0.0                              /* Trq_BrakeReg_max */
    },                                 /* FL */

    {
      0.0,                             /* Trq_BrakeReg */
      0.0                              /* Trq_BrakeReg_max */
    },                                 /* FR */

    {
      0.0,                             /* Trq_BrakeReg */
      0.0                              /* Trq_BrakeReg_max */
    },                                 /* RL */

    {
      0.0,                             /* Trq_BrakeReg */
      0.0                              /* Trq_BrakeReg_max */
    }                                  /* RR */
  }                                    /* WheelOut */
} ;                                    /* cmPTControlOut ground */

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model step function */
void UNICARPTControl_step(RT_MODEL_UNICARPTControl_T *const UNICARPTControl_M)
{
  B_UNICARPTControl_T *UNICARPTControl_B = ((B_UNICARPTControl_T *)
    UNICARPTControl_M->blockIO);
  DW_UNICARPTControl_T *UNICARPTControl_DW = ((DW_UNICARPTControl_T *)
    UNICARPTControl_M->dwork);
  ExtU_UNICARPTControl_T *UNICARPTControl_U = (ExtU_UNICARPTControl_T *)
    UNICARPTControl_M->inputs;
  ExtY_UNICARPTControl_T *UNICARPTControl_Y = (ExtY_UNICARPTControl_T *)
    UNICARPTControl_M->outputs;
  real_T rtb_Product1;
  real_T rtb_Gain1_c2;
  real_T Clock_tmp;

  /* S-Function (write_dict): '<S2>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)UNICARPTControl_DW->WriteCMDict_PWORK.Entry;
    if (!UNICARPTControl_DW->WriteCMDict_IWORK.Checked) {
      UNICARPTControl_DW->WriteCMDict_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    value = UNICARPTControl_U->FromCM.MotorIn.m0.Trq;
    DVA_PokeSL(e, value);
  }

  /* S-Function (read_dict): '<S2>/Read CM Dict2' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict2_PWORK.Entry;
    if (!UNICARPTControl_DW->ReadCMDict2_IWORK.Checked) {
      UNICARPTControl_DW->ReadCMDict2_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict2 = e->GetFunc(e->Var);
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  if (UNICARPTControl_B->ReadCMDict2 != 0.0) {
    UNICARPTControl_B->Switch3 = UNICARPTControl_B->ReadCMDict2;
  } else {
    UNICARPTControl_B->Switch3 = UNICARPTControl_P.Constant3_Value;
  }

  /* End of Switch: '<S6>/Switch3' */

  /* S-Function (read_dict): '<S2>/Read CM Dict1' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict1_PWORK.Entry;
    if (!UNICARPTControl_DW->ReadCMDict1_IWORK.Checked) {
      UNICARPTControl_DW->ReadCMDict1_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict1 = e->GetFunc(e->Var);
  }

  /* Abs: '<S6>/Abs1' */
  UNICARPTControl_B->Abs1 = fabs(UNICARPTControl_B->ReadCMDict1);

  /* S-Function (read_dict): '<S2>/Read CM Dict' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict_PWORK.Entry;
    if (!UNICARPTControl_DW->ReadCMDict_IWORK.Checked) {
      UNICARPTControl_DW->ReadCMDict_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict = e->GetFunc(e->Var);
  }

  /* Memory: '<S9>/Memory' */
  UNICARPTControl_B->Memory = UNICARPTControl_DW->Memory_PreviousInput;

  /* Clock: '<S9>/Clock' incorporates:
   *  Clock: '<S13>/Clock'
   *  Clock: '<S17>/Clock'
   *  Clock: '<S21>/Clock'
   */
  Clock_tmp = UNICARPTControl_M->Timing.t[0];
  UNICARPTControl_B->Clock = Clock_tmp;

  /* Memory: '<S9>/Memory1' */
  UNICARPTControl_B->Memory1 = UNICARPTControl_DW->Memory1_PreviousInput;

  /* Sum: '<S9>/Sum3' */
  rtb_Product1 = UNICARPTControl_B->Clock - UNICARPTControl_B->Memory1;

  /* Sum: '<S9>/Sum2' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Lookup_n-D: '<S6>/1-D Lookup Table'
   *  Product: '<S6>/Divide2'
   *  Product: '<S9>/Product5'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S9>/Sum1'
   *  Sum: '<S9>/Sum4'
   */
  UNICARPTControl_B->Sum2 = (look1_binlxpw(1.0 / UNICARPTControl_B->Switch3 *
    (UNICARPTControl_B->ReadCMDict2 - fabs
     (UNICARPTControl_U->FromCM.MotorIn.m0.rotv)), UNICARPTControl_P.PTC_RotLim,
    UNICARPTControl_P.PTC_weight, 3U) - UNICARPTControl_B->Memory) *
    rtb_Product1 / (rtb_Product1 + UNICARPTControl_P.PTC_T_1_s) +
    UNICARPTControl_B->Memory;

  /* Switch: '<S7>/Switch3' incorporates:
   *  Constant: '<S7>/Constant6'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product5'
   *  Switch: '<S6>/Switch'
   *  Switch: '<S6>/Switch1'
   */
  if (UNICARPTControl_B->ReadCMDict > UNICARPTControl_P.Switch3_Threshold) {
    rtb_Product1 = UNICARPTControl_P.Constant6_Value;
  } else {
    if (UNICARPTControl_B->Abs1 >= UNICARPTControl_P.Switch_Threshold) {
      /* Switch: '<S6>/Switch' */
      rtb_Product1 = UNICARPTControl_B->ReadCMDict1;
    } else if (UNICARPTControl_U->FromCM.MotorIn.m0.rotv *
               UNICARPTControl_U->FromCM.WheelIn.FL.Trq_BrakeReg_trg >=
               UNICARPTControl_P.Switch1_Threshold) {
      /* Switch: '<S6>/Switch1' incorporates:
       *  Constant: '<S6>/Constant'
       *  Inport: '<Root>/FromCM'
       *  Product: '<S6>/Product2'
       *  Switch: '<S6>/Switch'
       */
      rtb_Product1 = UNICARPTControl_P.Constant_Value *
        UNICARPTControl_U->FromCM.WheelIn.FL.Trq_BrakeReg_trg;
    } else {
      /* Switch: '<S6>/Switch' incorporates:
       *  Inport: '<Root>/FromCM'
       *  Switch: '<S6>/Switch1'
       */
      rtb_Product1 = UNICARPTControl_U->FromCM.WheelIn.FL.Trq_BrakeReg_trg;
    }

    rtb_Product1 *= UNICARPTControl_B->Sum2;
  }

  /* End of Switch: '<S7>/Switch3' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  Inport: '<Root>/FromCM'
   *  RelationalOperator: '<S8>/LowerRelop1'
   */
  if (rtb_Product1 > UNICARPTControl_U->FromCM.MotorIn.m0.TrqMot_max) {
    UNICARPTControl_Y->ToCM.MotorOut.m0.Trq_trg =
      UNICARPTControl_U->FromCM.MotorIn.m0.TrqMot_max;
  } else {
    /* Gain: '<S6>/Gain1' */
    rtb_Gain1_c2 = UNICARPTControl_P.Gain1_Gain *
      UNICARPTControl_U->FromCM.MotorIn.m0.TrqMot_max;

    /* Switch: '<S8>/Switch' incorporates:
     *  RelationalOperator: '<S8>/UpperRelop'
     */
    if (rtb_Product1 < rtb_Gain1_c2) {
      UNICARPTControl_Y->ToCM.MotorOut.m0.Trq_trg = rtb_Gain1_c2;
    } else {
      UNICARPTControl_Y->ToCM.MotorOut.m0.Trq_trg = rtb_Product1;
    }

    /* End of Switch: '<S8>/Switch' */
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Abs: '<S6>/Abs2'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S6>/Product1'
   */
  if (UNICARPTControl_U->FromCM.MotorIn.m0.rotv *
      UNICARPTControl_U->FromCM.MotorIn.m0.Trq >=
      UNICARPTControl_P.Switch2_Threshold) {
    UNICARPTControl_B->Switch2_l = UNICARPTControl_P.Constant1_Value;
  } else {
    UNICARPTControl_B->Switch2_l = fabs(UNICARPTControl_U->FromCM.MotorIn.m0.Trq);
  }

  /* End of Switch: '<S6>/Switch2' */

  /* S-Function (write_dict): '<S3>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)UNICARPTControl_DW->WriteCMDict_PWORK_m.Entry;
    if (!UNICARPTControl_DW->WriteCMDict_IWORK_n.Checked) {
      UNICARPTControl_DW->WriteCMDict_IWORK_n.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    value = UNICARPTControl_U->FromCM.MotorIn.m1.Trq;
    DVA_PokeSL(e, value);
  }

  /* S-Function (read_dict): '<S3>/Read CM Dict2' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict2_PWORK_i.Entry;
    if (!UNICARPTControl_DW->ReadCMDict2_IWORK_h.Checked) {
      UNICARPTControl_DW->ReadCMDict2_IWORK_h.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict2_h = e->GetFunc(e->Var);
  }

  /* Switch: '<S10>/Switch3' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  if (UNICARPTControl_B->ReadCMDict2_h != 0.0) {
    UNICARPTControl_B->Switch3_e = UNICARPTControl_B->ReadCMDict2_h;
  } else {
    UNICARPTControl_B->Switch3_e = UNICARPTControl_P.Constant3_Value_l;
  }

  /* End of Switch: '<S10>/Switch3' */

  /* S-Function (read_dict): '<S3>/Read CM Dict1' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict1_PWORK_j.Entry;
    if (!UNICARPTControl_DW->ReadCMDict1_IWORK_k.Checked) {
      UNICARPTControl_DW->ReadCMDict1_IWORK_k.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict1_e = e->GetFunc(e->Var);
  }

  /* Abs: '<S10>/Abs1' */
  UNICARPTControl_B->Abs1_p = fabs(UNICARPTControl_B->ReadCMDict1_e);

  /* S-Function (read_dict): '<S3>/Read CM Dict' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict_PWORK_o.Entry;
    if (!UNICARPTControl_DW->ReadCMDict_IWORK_n.Checked) {
      UNICARPTControl_DW->ReadCMDict_IWORK_n.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict_e = e->GetFunc(e->Var);
  }

  /* Memory: '<S13>/Memory' */
  UNICARPTControl_B->Memory_k = UNICARPTControl_DW->Memory_PreviousInput_i;

  /* Clock: '<S13>/Clock' */
  UNICARPTControl_B->Clock_f = Clock_tmp;

  /* Memory: '<S13>/Memory1' */
  UNICARPTControl_B->Memory1_m = UNICARPTControl_DW->Memory1_PreviousInput_d;

  /* Sum: '<S13>/Sum3' */
  rtb_Product1 = UNICARPTControl_B->Clock_f - UNICARPTControl_B->Memory1_m;

  /* Sum: '<S13>/Sum2' incorporates:
   *  Abs: '<S10>/Abs'
   *  Constant: '<S10>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Lookup_n-D: '<S10>/1-D Lookup Table'
   *  Product: '<S10>/Divide2'
   *  Product: '<S13>/Product5'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S13>/Sum1'
   *  Sum: '<S13>/Sum4'
   */
  UNICARPTControl_B->Sum2_a = (look1_binlxpw(1.0 / UNICARPTControl_B->Switch3_e *
    (UNICARPTControl_B->ReadCMDict2_h - fabs
     (UNICARPTControl_U->FromCM.MotorIn.m1.rotv)), UNICARPTControl_P.PTC_RotLim,
    UNICARPTControl_P.PTC_weight, 3U) - UNICARPTControl_B->Memory_k) *
    rtb_Product1 / (rtb_Product1 + UNICARPTControl_P.PTC_T_1_s) +
    UNICARPTControl_B->Memory_k;

  /* Switch: '<S11>/Switch3' incorporates:
   *  Constant: '<S11>/Constant6'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product5'
   *  Switch: '<S10>/Switch'
   *  Switch: '<S10>/Switch1'
   */
  if (UNICARPTControl_B->ReadCMDict_e > UNICARPTControl_P.Switch3_Threshold_o) {
    rtb_Product1 = UNICARPTControl_P.Constant6_Value_i;
  } else {
    if (UNICARPTControl_B->Abs1_p >= UNICARPTControl_P.Switch_Threshold_e) {
      /* Switch: '<S10>/Switch' */
      rtb_Product1 = UNICARPTControl_B->ReadCMDict1_e;
    } else if (UNICARPTControl_U->FromCM.MotorIn.m1.rotv *
               UNICARPTControl_U->FromCM.WheelIn.FR.Trq_BrakeReg_trg >=
               UNICARPTControl_P.Switch1_Threshold_n) {
      /* Switch: '<S10>/Switch1' incorporates:
       *  Constant: '<S10>/Constant'
       *  Inport: '<Root>/FromCM'
       *  Product: '<S10>/Product2'
       *  Switch: '<S10>/Switch'
       */
      rtb_Product1 = UNICARPTControl_P.Constant_Value_e *
        UNICARPTControl_U->FromCM.WheelIn.FR.Trq_BrakeReg_trg;
    } else {
      /* Switch: '<S10>/Switch' incorporates:
       *  Inport: '<Root>/FromCM'
       *  Switch: '<S10>/Switch1'
       */
      rtb_Product1 = UNICARPTControl_U->FromCM.WheelIn.FR.Trq_BrakeReg_trg;
    }

    rtb_Product1 *= UNICARPTControl_B->Sum2_a;
  }

  /* End of Switch: '<S11>/Switch3' */

  /* Switch: '<S12>/Switch2' incorporates:
   *  Inport: '<Root>/FromCM'
   *  RelationalOperator: '<S12>/LowerRelop1'
   */
  if (rtb_Product1 > UNICARPTControl_U->FromCM.MotorIn.m1.TrqMot_max) {
    UNICARPTControl_Y->ToCM.MotorOut.m1.Trq_trg =
      UNICARPTControl_U->FromCM.MotorIn.m1.TrqMot_max;
  } else {
    /* Gain: '<S10>/Gain1' */
    rtb_Gain1_c2 = UNICARPTControl_P.Gain1_Gain_g *
      UNICARPTControl_U->FromCM.MotorIn.m1.TrqMot_max;

    /* Switch: '<S12>/Switch' incorporates:
     *  RelationalOperator: '<S12>/UpperRelop'
     */
    if (rtb_Product1 < rtb_Gain1_c2) {
      UNICARPTControl_Y->ToCM.MotorOut.m1.Trq_trg = rtb_Gain1_c2;
    } else {
      UNICARPTControl_Y->ToCM.MotorOut.m1.Trq_trg = rtb_Product1;
    }

    /* End of Switch: '<S12>/Switch' */
  }

  /* End of Switch: '<S12>/Switch2' */

  /* Switch: '<S10>/Switch2' incorporates:
   *  Abs: '<S10>/Abs2'
   *  Constant: '<S10>/Constant1'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S10>/Product1'
   */
  if (UNICARPTControl_U->FromCM.MotorIn.m1.rotv *
      UNICARPTControl_U->FromCM.MotorIn.m1.Trq >=
      UNICARPTControl_P.Switch2_Threshold_d) {
    UNICARPTControl_B->Switch2_b = UNICARPTControl_P.Constant1_Value_a;
  } else {
    UNICARPTControl_B->Switch2_b = fabs(UNICARPTControl_U->FromCM.MotorIn.m1.Trq);
  }

  /* End of Switch: '<S10>/Switch2' */

  /* S-Function (write_dict): '<S4>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)UNICARPTControl_DW->WriteCMDict_PWORK_a.Entry;
    if (!UNICARPTControl_DW->WriteCMDict_IWORK_e.Checked) {
      UNICARPTControl_DW->WriteCMDict_IWORK_e.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    value = UNICARPTControl_U->FromCM.MotorIn.m2.Trq;
    DVA_PokeSL(e, value);
  }

  /* S-Function (read_dict): '<S4>/Read CM Dict2' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict2_PWORK_f.Entry;
    if (!UNICARPTControl_DW->ReadCMDict2_IWORK_d.Checked) {
      UNICARPTControl_DW->ReadCMDict2_IWORK_d.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict2_c = e->GetFunc(e->Var);
  }

  /* Switch: '<S14>/Switch3' incorporates:
   *  Constant: '<S14>/Constant3'
   */
  if (UNICARPTControl_B->ReadCMDict2_c != 0.0) {
    UNICARPTControl_B->Switch3_h = UNICARPTControl_B->ReadCMDict2_c;
  } else {
    UNICARPTControl_B->Switch3_h = UNICARPTControl_P.Constant3_Value_n;
  }

  /* End of Switch: '<S14>/Switch3' */

  /* S-Function (read_dict): '<S4>/Read CM Dict1' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict1_PWORK_e.Entry;
    if (!UNICARPTControl_DW->ReadCMDict1_IWORK_f.Checked) {
      UNICARPTControl_DW->ReadCMDict1_IWORK_f.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict1_n = e->GetFunc(e->Var);
  }

  /* Abs: '<S14>/Abs1' */
  UNICARPTControl_B->Abs1_n = fabs(UNICARPTControl_B->ReadCMDict1_n);

  /* S-Function (read_dict): '<S4>/Read CM Dict' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict_PWORK_h.Entry;
    if (!UNICARPTControl_DW->ReadCMDict_IWORK_d.Checked) {
      UNICARPTControl_DW->ReadCMDict_IWORK_d.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict_j = e->GetFunc(e->Var);
  }

  /* Memory: '<S17>/Memory' */
  UNICARPTControl_B->Memory_a = UNICARPTControl_DW->Memory_PreviousInput_c;

  /* Clock: '<S17>/Clock' */
  UNICARPTControl_B->Clock_j = Clock_tmp;

  /* Memory: '<S17>/Memory1' */
  UNICARPTControl_B->Memory1_k = UNICARPTControl_DW->Memory1_PreviousInput_i;

  /* Sum: '<S17>/Sum3' */
  rtb_Product1 = UNICARPTControl_B->Clock_j - UNICARPTControl_B->Memory1_k;

  /* Sum: '<S17>/Sum2' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S14>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Lookup_n-D: '<S14>/1-D Lookup Table'
   *  Product: '<S14>/Divide2'
   *  Product: '<S17>/Product5'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S17>/Sum1'
   *  Sum: '<S17>/Sum4'
   */
  UNICARPTControl_B->Sum2_h = (look1_binlxpw(1.0 / UNICARPTControl_B->Switch3_h *
    (UNICARPTControl_B->ReadCMDict2_c - fabs
     (UNICARPTControl_U->FromCM.MotorIn.m2.rotv)), UNICARPTControl_P.PTC_RotLim,
    UNICARPTControl_P.PTC_weight, 3U) - UNICARPTControl_B->Memory_a) *
    rtb_Product1 / (rtb_Product1 + UNICARPTControl_P.PTC_T_1_s) +
    UNICARPTControl_B->Memory_a;

  /* Switch: '<S15>/Switch3' incorporates:
   *  Constant: '<S15>/Constant6'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product5'
   *  Switch: '<S14>/Switch'
   *  Switch: '<S14>/Switch1'
   */
  if (UNICARPTControl_B->ReadCMDict_j > UNICARPTControl_P.Switch3_Threshold_j) {
    rtb_Product1 = UNICARPTControl_P.Constant6_Value_g;
  } else {
    if (UNICARPTControl_B->Abs1_n >= UNICARPTControl_P.Switch_Threshold_k) {
      /* Switch: '<S14>/Switch' */
      rtb_Product1 = UNICARPTControl_B->ReadCMDict1_n;
    } else if (UNICARPTControl_U->FromCM.MotorIn.m2.rotv *
               UNICARPTControl_U->FromCM.WheelIn.RL.Trq_BrakeReg_trg >=
               UNICARPTControl_P.Switch1_Threshold_n2) {
      /* Switch: '<S14>/Switch1' incorporates:
       *  Constant: '<S14>/Constant'
       *  Inport: '<Root>/FromCM'
       *  Product: '<S14>/Product2'
       *  Switch: '<S14>/Switch'
       */
      rtb_Product1 = UNICARPTControl_P.Constant_Value_a *
        UNICARPTControl_U->FromCM.WheelIn.RL.Trq_BrakeReg_trg;
    } else {
      /* Switch: '<S14>/Switch' incorporates:
       *  Inport: '<Root>/FromCM'
       *  Switch: '<S14>/Switch1'
       */
      rtb_Product1 = UNICARPTControl_U->FromCM.WheelIn.RL.Trq_BrakeReg_trg;
    }

    rtb_Product1 *= UNICARPTControl_B->Sum2_h;
  }

  /* End of Switch: '<S15>/Switch3' */

  /* Switch: '<S16>/Switch2' incorporates:
   *  Inport: '<Root>/FromCM'
   *  RelationalOperator: '<S16>/LowerRelop1'
   */
  if (rtb_Product1 > UNICARPTControl_U->FromCM.MotorIn.m2.TrqMot_max) {
    UNICARPTControl_Y->ToCM.MotorOut.m2.Trq_trg =
      UNICARPTControl_U->FromCM.MotorIn.m2.TrqMot_max;
  } else {
    /* Gain: '<S14>/Gain1' */
    rtb_Gain1_c2 = UNICARPTControl_P.Gain1_Gain_m *
      UNICARPTControl_U->FromCM.MotorIn.m2.TrqMot_max;

    /* Switch: '<S16>/Switch' incorporates:
     *  RelationalOperator: '<S16>/UpperRelop'
     */
    if (rtb_Product1 < rtb_Gain1_c2) {
      UNICARPTControl_Y->ToCM.MotorOut.m2.Trq_trg = rtb_Gain1_c2;
    } else {
      UNICARPTControl_Y->ToCM.MotorOut.m2.Trq_trg = rtb_Product1;
    }

    /* End of Switch: '<S16>/Switch' */
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Abs: '<S14>/Abs2'
   *  Constant: '<S14>/Constant1'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S14>/Product1'
   */
  if (UNICARPTControl_U->FromCM.MotorIn.m2.rotv *
      UNICARPTControl_U->FromCM.MotorIn.m2.Trq >=
      UNICARPTControl_P.Switch2_Threshold_m) {
    UNICARPTControl_B->Switch2_p = UNICARPTControl_P.Constant1_Value_m;
  } else {
    UNICARPTControl_B->Switch2_p = fabs(UNICARPTControl_U->FromCM.MotorIn.m2.Trq);
  }

  /* End of Switch: '<S14>/Switch2' */

  /* S-Function (write_dict): '<S5>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)UNICARPTControl_DW->WriteCMDict_PWORK_j.Entry;
    if (!UNICARPTControl_DW->WriteCMDict_IWORK_l.Checked) {
      UNICARPTControl_DW->WriteCMDict_IWORK_l.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    value = UNICARPTControl_U->FromCM.MotorIn.m3.Trq;
    DVA_PokeSL(e, value);
  }

  /* S-Function (read_dict): '<S5>/Read CM Dict2' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict2_PWORK_a.Entry;
    if (!UNICARPTControl_DW->ReadCMDict2_IWORK_m.Checked) {
      UNICARPTControl_DW->ReadCMDict2_IWORK_m.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict2_b = e->GetFunc(e->Var);
  }

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S18>/Constant3'
   */
  if (UNICARPTControl_B->ReadCMDict2_b != 0.0) {
    UNICARPTControl_B->Switch3_n = UNICARPTControl_B->ReadCMDict2_b;
  } else {
    UNICARPTControl_B->Switch3_n = UNICARPTControl_P.Constant3_Value_a;
  }

  /* End of Switch: '<S18>/Switch3' */

  /* S-Function (read_dict): '<S5>/Read CM Dict1' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict1_PWORK_n.Entry;
    if (!UNICARPTControl_DW->ReadCMDict1_IWORK_g.Checked) {
      UNICARPTControl_DW->ReadCMDict1_IWORK_g.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict1_i = e->GetFunc(e->Var);
  }

  /* Abs: '<S18>/Abs1' */
  UNICARPTControl_B->Abs1_g = fabs(UNICARPTControl_B->ReadCMDict1_i);

  /* S-Function (read_dict): '<S5>/Read CM Dict' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)UNICARPTControl_DW->ReadCMDict_PWORK_k.Entry;
    if (!UNICARPTControl_DW->ReadCMDict_IWORK_p.Checked) {
      UNICARPTControl_DW->ReadCMDict_IWORK_p.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'UNICARPTControl'");
    }

    UNICARPTControl_B->ReadCMDict_c = e->GetFunc(e->Var);
  }

  /* Memory: '<S21>/Memory' */
  UNICARPTControl_B->Memory_f = UNICARPTControl_DW->Memory_PreviousInput_m;

  /* Clock: '<S21>/Clock' */
  UNICARPTControl_B->Clock_p = Clock_tmp;

  /* Memory: '<S21>/Memory1' */
  UNICARPTControl_B->Memory1_c = UNICARPTControl_DW->Memory1_PreviousInput_j;

  /* Sum: '<S21>/Sum3' */
  rtb_Product1 = UNICARPTControl_B->Clock_p - UNICARPTControl_B->Memory1_c;

  /* Sum: '<S21>/Sum2' incorporates:
   *  Abs: '<S18>/Abs'
   *  Constant: '<S18>/Constant2'
   *  Inport: '<Root>/FromCM'
   *  Lookup_n-D: '<S18>/1-D Lookup Table'
   *  Product: '<S18>/Divide2'
   *  Product: '<S21>/Product5'
   *  Sum: '<S18>/Add1'
   *  Sum: '<S21>/Sum1'
   *  Sum: '<S21>/Sum4'
   */
  UNICARPTControl_B->Sum2_p = (look1_binlxpw(1.0 / UNICARPTControl_B->Switch3_n *
    (UNICARPTControl_B->ReadCMDict2_b - fabs
     (UNICARPTControl_U->FromCM.MotorIn.m3.rotv)), UNICARPTControl_P.PTC_RotLim,
    UNICARPTControl_P.PTC_weight, 3U) - UNICARPTControl_B->Memory_f) *
    rtb_Product1 / (rtb_Product1 + UNICARPTControl_P.PTC_T_1_s) +
    UNICARPTControl_B->Memory_f;

  /* Switch: '<S19>/Switch3' incorporates:
   *  Constant: '<S19>/Constant6'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product5'
   *  Switch: '<S18>/Switch'
   *  Switch: '<S18>/Switch1'
   */
  if (UNICARPTControl_B->ReadCMDict_c > UNICARPTControl_P.Switch3_Threshold_n) {
    rtb_Product1 = UNICARPTControl_P.Constant6_Value_k;
  } else {
    if (UNICARPTControl_B->Abs1_g >= UNICARPTControl_P.Switch_Threshold_d) {
      /* Switch: '<S18>/Switch' */
      rtb_Product1 = UNICARPTControl_B->ReadCMDict1_i;
    } else if (UNICARPTControl_U->FromCM.MotorIn.m3.rotv *
               UNICARPTControl_U->FromCM.WheelIn.RR.Trq_BrakeReg_trg >=
               UNICARPTControl_P.Switch1_Threshold_c) {
      /* Switch: '<S18>/Switch1' incorporates:
       *  Constant: '<S18>/Constant'
       *  Inport: '<Root>/FromCM'
       *  Product: '<S18>/Product2'
       *  Switch: '<S18>/Switch'
       */
      rtb_Product1 = UNICARPTControl_P.Constant_Value_g *
        UNICARPTControl_U->FromCM.WheelIn.RR.Trq_BrakeReg_trg;
    } else {
      /* Switch: '<S18>/Switch' incorporates:
       *  Inport: '<Root>/FromCM'
       *  Switch: '<S18>/Switch1'
       */
      rtb_Product1 = UNICARPTControl_U->FromCM.WheelIn.RR.Trq_BrakeReg_trg;
    }

    rtb_Product1 *= UNICARPTControl_B->Sum2_p;
  }

  /* End of Switch: '<S19>/Switch3' */

  /* Switch: '<S20>/Switch2' incorporates:
   *  Inport: '<Root>/FromCM'
   *  RelationalOperator: '<S20>/LowerRelop1'
   */
  if (rtb_Product1 > UNICARPTControl_U->FromCM.MotorIn.m3.TrqMot_max) {
    UNICARPTControl_Y->ToCM.MotorOut.m3.Trq_trg =
      UNICARPTControl_U->FromCM.MotorIn.m3.TrqMot_max;
  } else {
    /* Gain: '<S18>/Gain1' */
    rtb_Gain1_c2 = UNICARPTControl_P.Gain1_Gain_o *
      UNICARPTControl_U->FromCM.MotorIn.m3.TrqMot_max;

    /* Switch: '<S20>/Switch' incorporates:
     *  RelationalOperator: '<S20>/UpperRelop'
     */
    if (rtb_Product1 < rtb_Gain1_c2) {
      UNICARPTControl_Y->ToCM.MotorOut.m3.Trq_trg = rtb_Gain1_c2;
    } else {
      UNICARPTControl_Y->ToCM.MotorOut.m3.Trq_trg = rtb_Product1;
    }

    /* End of Switch: '<S20>/Switch' */
  }

  /* End of Switch: '<S20>/Switch2' */

  /* Switch: '<S18>/Switch2' incorporates:
   *  Abs: '<S18>/Abs2'
   *  Constant: '<S18>/Constant1'
   *  Inport: '<Root>/FromCM'
   *  Product: '<S18>/Product1'
   */
  if (UNICARPTControl_U->FromCM.MotorIn.m3.rotv *
      UNICARPTControl_U->FromCM.MotorIn.m3.Trq >=
      UNICARPTControl_P.Switch2_Threshold_j) {
    UNICARPTControl_B->Switch2_g4 = UNICARPTControl_P.Constant1_Value_j;
  } else {
    UNICARPTControl_B->Switch2_g4 = fabs
      (UNICARPTControl_U->FromCM.MotorIn.m3.Trq);
  }

  /* End of Switch: '<S18>/Switch2' */

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/EngineOut.FuelCutOff'
   *  Constant: '<S1>/EngineOut.Load'
   *  Constant: '<S1>/EngineOut.Trq_trg'
   *  Constant: '<S1>/EngineOut.rotv_trg'
   *  Constant: '<S1>/EngineOut.set_ISC'
   */
  UNICARPTControl_Y->ToCM.EngineOut.set_ISC =
    UNICARPTControl_P.EngineOutset_ISC_Value;
  UNICARPTControl_Y->ToCM.EngineOut.FuelCutOff =
    UNICARPTControl_P.EngineOutFuelCutOff_Value;
  UNICARPTControl_Y->ToCM.EngineOut.Load = UNICARPTControl_P.EngineOutLoad_Value;
  UNICARPTControl_Y->ToCM.EngineOut.Trq_trg =
    UNICARPTControl_P.EngineOutTrq_trg_Value;
  UNICARPTControl_Y->ToCM.EngineOut.rotv_trg =
    UNICARPTControl_P.EngineOutrotv_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/ISGOut.Load'
   *  Constant: '<S1>/ISGOut.Trq_trg'
   *  Constant: '<S1>/ISGOut.rotv_trg'
   */
  UNICARPTControl_Y->ToCM.ISGOut.Load = UNICARPTControl_P.ISGOutLoad_Value;
  UNICARPTControl_Y->ToCM.ISGOut.Trq_trg = UNICARPTControl_P.ISGOutTrq_trg_Value;
  UNICARPTControl_Y->ToCM.ISGOut.rotv_trg =
    UNICARPTControl_P.ISGOutrotv_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/MotorOut.m0.Load'
   *  Constant: '<S1>/MotorOut.m0.rotv_trg'
   */
  UNICARPTControl_Y->ToCM.MotorOut.m0.Load =
    UNICARPTControl_P.MotorOutm0Load_Value;
  UNICARPTControl_Y->ToCM.MotorOut.m0.rotv_trg =
    UNICARPTControl_P.MotorOutm0rotv_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/MotorOut.m1.Load'
   *  Constant: '<S1>/MotorOut.m1.rotv_trg'
   */
  UNICARPTControl_Y->ToCM.MotorOut.m1.Load =
    UNICARPTControl_P.MotorOutm1Load_Value;
  UNICARPTControl_Y->ToCM.MotorOut.m1.rotv_trg =
    UNICARPTControl_P.MotorOutm1rotv_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/MotorOut.m2.Load'
   *  Constant: '<S1>/MotorOut.m2.rotv_trg'
   */
  UNICARPTControl_Y->ToCM.MotorOut.m2.Load =
    UNICARPTControl_P.MotorOutm2Load_Value;
  UNICARPTControl_Y->ToCM.MotorOut.m2.rotv_trg =
    UNICARPTControl_P.MotorOutm2rotv_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/MotorOut.m3.Load'
   *  Constant: '<S1>/MotorOut.m3.rotv_trg'
   */
  UNICARPTControl_Y->ToCM.MotorOut.m3.Load =
    UNICARPTControl_P.MotorOutm3Load_Value;
  UNICARPTControl_Y->ToCM.MotorOut.m3.rotv_trg =
    UNICARPTControl_P.MotorOutm3rotv_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/ClutchOut.Pos'
   *  Constant: '<S1>/ClutchOut.Trq_out_trg'
   *  Constant: '<S1>/ClutchOut.rotv_out_trg'
   */
  UNICARPTControl_Y->ToCM.ClutchOut.Pos = UNICARPTControl_P.ClutchOutPos_Value;
  UNICARPTControl_Y->ToCM.ClutchOut.rotv_out_trg =
    UNICARPTControl_P.ClutchOutrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.ClutchOut.Trq_out_trg =
    UNICARPTControl_P.ClutchOutTrq_out_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/GearBoxOut.Clutch.Pos'
   *  Constant: '<S1>/GearBoxOut.Clutch.Trq_out_trg'
   *  Constant: '<S1>/GearBoxOut.Clutch.rotv_out_trg'
   *  Constant: '<S1>/GearBoxOut.Clutch_dis.Pos'
   *  Constant: '<S1>/GearBoxOut.Clutch_dis.Trq_out_trg'
   *  Constant: '<S1>/GearBoxOut.Clutch_dis.rotv_out_trg'
   *  Constant: '<S1>/GearBoxOut.GearNoTrg'
   *  Constant: '<S1>/GearBoxOut.GearNoTrg_dis'
   *  Constant: '<S1>/GearBoxOut.Trq_out_trg'
   *  Constant: '<S1>/GearBoxOut.i_trg'
   *  Constant: '<S1>/GearBoxOut.rotv_in_trg'
   *  Constant: '<S1>/GearBoxOut.set_ParkBrake'
   */
  UNICARPTControl_Y->ToCM.GearBoxOut.GearNoTrg =
    UNICARPTControl_P.GearBoxOutGearNoTrg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.GearNoTrg_dis =
    UNICARPTControl_P.GearBoxOutGearNoTrg_dis_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.i_trg =
    UNICARPTControl_P.GearBoxOuti_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.set_ParkBrake =
    UNICARPTControl_P.GearBoxOutset_ParkBrake_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.rotv_in_trg =
    UNICARPTControl_P.GearBoxOutrotv_in_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Trq_out_trg =
    UNICARPTControl_P.GearBoxOutTrq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Clutch.Pos =
    UNICARPTControl_P.GearBoxOutClutchPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Clutch.rotv_out_trg =
    UNICARPTControl_P.GearBoxOutClutchrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Clutch.Trq_out_trg =
    UNICARPTControl_P.GearBoxOutClutchTrq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Clutch_dis.Pos =
    UNICARPTControl_P.GearBoxOutClutch_disPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Clutch_dis.rotv_out_trg =
    UNICARPTControl_P.GearBoxOutClutch_disrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxOut.Clutch_dis.Trq_out_trg =
    UNICARPTControl_P.GearBoxOutClutch_disTrq_out_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Clutch.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Clutch.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Clutch.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Clutch_dis.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.GearNoTrg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.GearNoTrg_dis'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.i_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.rotv_in_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m0.set_ParkBrake'
   */
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.GearNoTrg =
    UNICARPTControl_P.GearBoxM_OutGB_m0GearNoTrg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.GearNoTrg_dis =
    UNICARPTControl_P.GearBoxM_OutGB_m0GearNoTrg_dis_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.i_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0i_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.set_ParkBrake =
    UNICARPTControl_P.GearBoxM_OutGB_m0set_ParkBrake_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.rotv_in_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0rotv_in_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0Trq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Clutch.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m0ClutchPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Clutch.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0Clutchrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Clutch.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0ClutchTrq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Clutch_dis.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m0Clutch_disPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Clutch_dis.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0Clutch_disrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m0.Clutch_dis.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m0Clutch_disTrq_out_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Clutch.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Clutch.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Clutch.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Clutch_dis.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.GearNoTrg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.GearNoTrg_dis'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.i_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.rotv_in_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m1.set_ParkBrake'
   */
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.GearNoTrg =
    UNICARPTControl_P.GearBoxM_OutGB_m1GearNoTrg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.GearNoTrg_dis =
    UNICARPTControl_P.GearBoxM_OutGB_m1GearNoTrg_dis_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.i_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1i_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.set_ParkBrake =
    UNICARPTControl_P.GearBoxM_OutGB_m1set_ParkBrake_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.rotv_in_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1rotv_in_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1Trq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Clutch.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m1ClutchPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Clutch.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1Clutchrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Clutch.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1ClutchTrq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Clutch_dis.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m1Clutch_disPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Clutch_dis.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1Clutch_disrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m1.Clutch_dis.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m1Clutch_disTrq_out_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Clutch.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Clutch.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Clutch.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Clutch_dis.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.GearNoTrg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.GearNoTrg_dis'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.i_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.rotv_in_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m2.set_ParkBrake'
   */
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.GearNoTrg =
    UNICARPTControl_P.GearBoxM_OutGB_m2GearNoTrg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.GearNoTrg_dis =
    UNICARPTControl_P.GearBoxM_OutGB_m2GearNoTrg_dis_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.i_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2i_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.set_ParkBrake =
    UNICARPTControl_P.GearBoxM_OutGB_m2set_ParkBrake_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.rotv_in_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2rotv_in_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2Trq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Clutch.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m2ClutchPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Clutch.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2Clutchrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Clutch.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2ClutchTrq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Clutch_dis.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m2Clutch_disPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Clutch_dis.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2Clutch_disrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m2.Clutch_dis.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m2Clutch_disTrq_out_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Clutch.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Clutch.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Clutch.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.Pos'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Clutch_dis.rotv_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.GearNoTrg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.GearNoTrg_dis'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.Trq_out_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.i_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.rotv_in_trg'
   *  Constant: '<S1>/GearBoxM_Out.GB_m3.set_ParkBrake'
   */
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.GearNoTrg =
    UNICARPTControl_P.GearBoxM_OutGB_m3GearNoTrg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.GearNoTrg_dis =
    UNICARPTControl_P.GearBoxM_OutGB_m3GearNoTrg_dis_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.i_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3i_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.set_ParkBrake =
    UNICARPTControl_P.GearBoxM_OutGB_m3set_ParkBrake_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.rotv_in_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3rotv_in_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3Trq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Clutch.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m3ClutchPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Clutch.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3Clutchrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Clutch.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3ClutchTrq_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Clutch_dis.Pos =
    UNICARPTControl_P.GearBoxM_OutGB_m3Clutch_disPos_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Clutch_dis.rotv_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3Clutch_disrotv_out_trg_Value;
  UNICARPTControl_Y->ToCM.GearBoxM_Out.GB_m3.Clutch_dis.Trq_out_trg =
    UNICARPTControl_P.GearBoxM_OutGB_m3Clutch_disTrq_out_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S1>/PwrSupplyOut.Pwr_HV1toLV_trg'
   */
  UNICARPTControl_Y->ToCM.PwrSupplyOut.Pwr_HV1toLV_trg =
    UNICARPTControl_P.PwrSupplyOutPwr_HV1toLV_trg_Value;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTControl_Y->ToCM.WheelOut.FL.Trq_BrakeReg =
    UNICARPTControl_B->Switch2_l;
  UNICARPTControl_Y->ToCM.WheelOut.FL.Trq_BrakeReg_max =
    UNICARPTControl_U->FromCM.MotorIn.m0.TrqGen_max;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTControl_Y->ToCM.WheelOut.FR.Trq_BrakeReg =
    UNICARPTControl_B->Switch2_b;
  UNICARPTControl_Y->ToCM.WheelOut.FR.Trq_BrakeReg_max =
    UNICARPTControl_U->FromCM.MotorIn.m1.TrqGen_max;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTControl_Y->ToCM.WheelOut.RL.Trq_BrakeReg =
    UNICARPTControl_B->Switch2_p;
  UNICARPTControl_Y->ToCM.WheelOut.RL.Trq_BrakeReg_max =
    UNICARPTControl_U->FromCM.MotorIn.m2.TrqGen_max;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  UNICARPTControl_Y->ToCM.WheelOut.RR.Trq_BrakeReg =
    UNICARPTControl_B->Switch2_g4;
  UNICARPTControl_Y->ToCM.WheelOut.RR.Trq_BrakeReg_max =
    UNICARPTControl_U->FromCM.MotorIn.m3.TrqGen_max;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S1>/StrategyMode'
   *  Outport: '<Root>/ToCM'
   */
  UNICARPTControl_Y->ToCM.OperationState = UNICARPTControl_P.Constant3_Value_k;
  UNICARPTControl_Y->ToCM.OperationError = UNICARPTControl_P.Constant4_Value;
  UNICARPTControl_Y->ToCM.StrategyMode = UNICARPTControl_P.StrategyMode_Value;
  UNICARPTControl_Y->ToCM.Ignition = UNICARPTControl_P.Constant2_Value;

  /* Update for Memory: '<S9>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput = UNICARPTControl_B->Sum2;

  /* Update for Memory: '<S9>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput = UNICARPTControl_B->Clock;

  /* Update for Memory: '<S13>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput_i = UNICARPTControl_B->Sum2_a;

  /* Update for Memory: '<S13>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput_d = UNICARPTControl_B->Clock_f;

  /* Update for Memory: '<S17>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput_c = UNICARPTControl_B->Sum2_h;

  /* Update for Memory: '<S17>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput_i = UNICARPTControl_B->Clock_j;

  /* Update for Memory: '<S21>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput_m = UNICARPTControl_B->Sum2_p;

  /* Update for Memory: '<S21>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput_j = UNICARPTControl_B->Clock_p;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++UNICARPTControl_M->Timing.clockTick0)) {
    ++UNICARPTControl_M->Timing.clockTickH0;
  }

  UNICARPTControl_M->Timing.t[0] = UNICARPTControl_M->Timing.clockTick0 *
    UNICARPTControl_M->Timing.stepSize0 + UNICARPTControl_M->Timing.clockTickH0 *
    UNICARPTControl_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    UNICARPTControl_M->Timing.clockTick1++;
    if (!UNICARPTControl_M->Timing.clockTick1) {
      UNICARPTControl_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void UNICARPTControl_initialize(RT_MODEL_UNICARPTControl_T *const
  UNICARPTControl_M)
{
  DW_UNICARPTControl_T *UNICARPTControl_DW = ((DW_UNICARPTControl_T *)
    UNICARPTControl_M->dwork);

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.Trq.FL", NULL);
    UNICARPTControl_DW->WriteCMDict_IWORK.Checked = 0;
    UNICARPTControl_DW->WriteCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.RotLim.FL", NULL);
    UNICARPTControl_DW->ReadCMDict2_IWORK.Checked = 0;
    UNICARPTControl_DW->ReadCMDict2_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.setpoint_Trq.FL", NULL);
    UNICARPTControl_DW->ReadCMDict1_IWORK.Checked = 0;
    UNICARPTControl_DW->ReadCMDict1_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.ErrBit.FL", NULL);
    UNICARPTControl_DW->ReadCMDict_IWORK.Checked = 0;
    UNICARPTControl_DW->ReadCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.Trq.FR", NULL);
    UNICARPTControl_DW->WriteCMDict_IWORK_n.Checked = 0;
    UNICARPTControl_DW->WriteCMDict_PWORK_m.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.RotLim.FR", NULL);
    UNICARPTControl_DW->ReadCMDict2_IWORK_h.Checked = 0;
    UNICARPTControl_DW->ReadCMDict2_PWORK_i.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.setpoint_Trq.FR", NULL);
    UNICARPTControl_DW->ReadCMDict1_IWORK_k.Checked = 0;
    UNICARPTControl_DW->ReadCMDict1_PWORK_j.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.ErrBit.FR", NULL);
    UNICARPTControl_DW->ReadCMDict_IWORK_n.Checked = 0;
    UNICARPTControl_DW->ReadCMDict_PWORK_o.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.Trq.RL", NULL);
    UNICARPTControl_DW->WriteCMDict_IWORK_e.Checked = 0;
    UNICARPTControl_DW->WriteCMDict_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.RotLim.RL", NULL);
    UNICARPTControl_DW->ReadCMDict2_IWORK_d.Checked = 0;
    UNICARPTControl_DW->ReadCMDict2_PWORK_f.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.setpoint_Trq.RL", NULL);
    UNICARPTControl_DW->ReadCMDict1_IWORK_f.Checked = 0;
    UNICARPTControl_DW->ReadCMDict1_PWORK_e.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.ErrBit.RL", NULL);
    UNICARPTControl_DW->ReadCMDict_IWORK_d.Checked = 0;
    UNICARPTControl_DW->ReadCMDict_PWORK_h.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S5>/Write CM Dict' incorporates:
   *  Inport: '<Root>/FromCM'
   */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.Trq.RR", NULL);
    UNICARPTControl_DW->WriteCMDict_IWORK_l.Checked = 0;
    UNICARPTControl_DW->WriteCMDict_PWORK_j.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S5>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.RotLim.RR", NULL);
    UNICARPTControl_DW->ReadCMDict2_IWORK_m.Checked = 0;
    UNICARPTControl_DW->ReadCMDict2_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S5>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.setpoint_Trq.RR", NULL);
    UNICARPTControl_DW->ReadCMDict1_IWORK_g.Checked = 0;
    UNICARPTControl_DW->ReadCMDict1_PWORK_n.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S5>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Drive.ErrBit.RR", NULL);
    UNICARPTControl_DW->ReadCMDict_IWORK_p.Checked = 0;
    UNICARPTControl_DW->ReadCMDict_PWORK_k.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* InitializeConditions for Memory: '<S9>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput =
    UNICARPTControl_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S9>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput =
    UNICARPTControl_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S13>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput_i =
    UNICARPTControl_P.Memory_InitialCondition_j;

  /* InitializeConditions for Memory: '<S13>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput_d =
    UNICARPTControl_P.Memory1_InitialCondition_f;

  /* InitializeConditions for Memory: '<S17>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput_c =
    UNICARPTControl_P.Memory_InitialCondition_g;

  /* InitializeConditions for Memory: '<S17>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput_i =
    UNICARPTControl_P.Memory1_InitialCondition_i;

  /* InitializeConditions for Memory: '<S21>/Memory' */
  UNICARPTControl_DW->Memory_PreviousInput_m =
    UNICARPTControl_P.Memory_InitialCondition_n;

  /* InitializeConditions for Memory: '<S21>/Memory1' */
  UNICARPTControl_DW->Memory1_PreviousInput_j =
    UNICARPTControl_P.Memory1_InitialCondition_k;
}

/* Model terminate function */
void UNICARPTControl_terminate(RT_MODEL_UNICARPTControl_T * UNICARPTControl_M)
{
  rt_FREE(UNICARPTControl_M->solverInfo);

  /* model code */
  rt_FREE(UNICARPTControl_M->blockIO);
  rt_FREE(UNICARPTControl_M->inputs);
  rt_FREE(UNICARPTControl_M->outputs);
  rt_FREE(UNICARPTControl_M->dwork);
  rt_FREE(UNICARPTControl_M);
}

/* Model data allocation function */
RT_MODEL_UNICARPTControl_T *UNICARPTControl(struct tInfos *inf)
{
  RT_MODEL_UNICARPTControl_T *UNICARPTControl_M;
  UNICARPTControl_M = (RT_MODEL_UNICARPTControl_T *) malloc(sizeof
    (RT_MODEL_UNICARPTControl_T));
  if (UNICARPTControl_M == NULL) {
    return NULL;
  }

  (void) memset((char *)UNICARPTControl_M, 0,
                sizeof(RT_MODEL_UNICARPTControl_T));
  MatSupp_Init();

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(UNICARPTControl_M,rt_SolverInfo);
    UNICARPTControl_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(UNICARPTControl_M->solverInfo,
                          &UNICARPTControl_M->Timing.simTimeStep);
    rtsiSetTPtr(UNICARPTControl_M->solverInfo, &rtmGetTPtr(UNICARPTControl_M));
    rtsiSetStepSizePtr(UNICARPTControl_M->solverInfo,
                       &UNICARPTControl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(UNICARPTControl_M->solverInfo, (&rtmGetErrorStatus
      (UNICARPTControl_M)));
    rtsiSetRTModelPtr(UNICARPTControl_M->solverInfo, UNICARPTControl_M);
  }

  rtsiSetSolverName(UNICARPTControl_M->solverInfo,"FixedStepDiscrete");

  /* block I/O */
  {
    B_UNICARPTControl_T *b = (B_UNICARPTControl_T *) malloc(sizeof
      (B_UNICARPTControl_T));
    rt_VALIDATE_MEMORY(UNICARPTControl_M,b);
    UNICARPTControl_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_UNICARPTControl_T *dwork = (DW_UNICARPTControl_T *) malloc(sizeof
      (DW_UNICARPTControl_T));
    rt_VALIDATE_MEMORY(UNICARPTControl_M,dwork);
    UNICARPTControl_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_UNICARPTControl_T *UNICARPTControl_U = (ExtU_UNICARPTControl_T *)
      malloc(sizeof(ExtU_UNICARPTControl_T));
    rt_VALIDATE_MEMORY(UNICARPTControl_M,UNICARPTControl_U);
    UNICARPTControl_M->inputs = (((ExtU_UNICARPTControl_T *) UNICARPTControl_U));
  }

  /* external outputs */
  {
    ExtY_UNICARPTControl_T *UNICARPTControl_Y = (ExtY_UNICARPTControl_T *)
      malloc(sizeof(ExtY_UNICARPTControl_T));
    rt_VALIDATE_MEMORY(UNICARPTControl_M,UNICARPTControl_Y);
    UNICARPTControl_M->outputs = (UNICARPTControl_Y);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  UNICARPTControl_InitializeDataMapInfo(UNICARPTControl_M);

  /* CarMaker parameter tuning */
  {
    const struct tMatSuppMMI *mmi = &(rtmGetDataMapInfo(UNICARPTControl_M).mmi);
    tMatSuppTunables *tuns = MatSupp_TunBegin("UNICARPTControl", mmi);
    UNICARPTControl_SetParams(UNICARPTControl_M, tuns, inf);
    MatSupp_TunEnd(tuns);
  }

  {
    B_UNICARPTControl_T *UNICARPTControl_B = ((B_UNICARPTControl_T *)
      UNICARPTControl_M->blockIO);
    DW_UNICARPTControl_T *UNICARPTControl_DW = ((DW_UNICARPTControl_T *)
      UNICARPTControl_M->dwork);
    ExtU_UNICARPTControl_T *UNICARPTControl_U = (ExtU_UNICARPTControl_T *)
      UNICARPTControl_M->inputs;
    ExtY_UNICARPTControl_T *UNICARPTControl_Y = (ExtY_UNICARPTControl_T *)
      UNICARPTControl_M->outputs;
    rtsiSetSimTimeStep(UNICARPTControl_M->solverInfo, MAJOR_TIME_STEP);
    rtmSetTPtr(UNICARPTControl_M, &UNICARPTControl_M->Timing.tArray[0]);
    UNICARPTControl_M->Timing.stepSize0 = 0.001;

    /* block I/O */
    (void) memset(((void *) UNICARPTControl_B), 0,
                  sizeof(B_UNICARPTControl_T));

    /* states (dwork) */
    (void) memset((void *)UNICARPTControl_DW, 0,
                  sizeof(DW_UNICARPTControl_T));

    /* external inputs */
    (void)memset(UNICARPTControl_U, 0, sizeof(ExtU_UNICARPTControl_T));

    /* external outputs */
    UNICARPTControl_Y->ToCM = UNICARPTControl_rtZcmPTControlOut;
  }

  return UNICARPTControl_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *UNICARPTControl_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)UNICARPTControl_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *UNICARPTControl_DictDefines = DictDefines;
tQuantEntry *UNICARPTControl_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *UNICARPTControl_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)UNICARPTControl_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *UNICARPTControl_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *UNICARPTControl_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
