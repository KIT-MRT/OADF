/*
 * UNICARSteer.c
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

#include "UNICARSteer_capi.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "UNICARSteer.h"
#include "UNICARSteer_private.h"
#include "UNICARSteer_wrap.h"

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

const cmSteeringOut UNICARSteer_rtZcmSteeringOut = {
  0.0,                                 /* Ang */
  0.0,                                 /* AngVel */
  0.0,                                 /* AngAcc */
  0.0,                                 /* Trq */
  0.0,                                 /* TrqStatic */
  0.0,                                 /* AssistFrc */
  0.0,                                 /* AssistTrqCol */
  0.0,                                 /* AssistTrqPin */
  0.0,                                 /* q_L */
  0.0,                                 /* qp_L */
  0.0,                                 /* qpp_L */
  0.0,                                 /* iSteer2q_L */
  0.0,                                 /* q_R */
  0.0,                                 /* qp_R */
  0.0,                                 /* qpp_R */
  0.0                                  /* iSteer2q_R */
} ;                                    /* cmSteeringOut ground */

/* Model step function */
void UNICARSteer_step(RT_MODEL_UNICARSteer_T *const UNICARSteer_M)
{
  B_UNICARSteer_T *UNICARSteer_B = ((B_UNICARSteer_T *) UNICARSteer_M->blockIO);
  DW_UNICARSteer_T *UNICARSteer_DW = ((DW_UNICARSteer_T *) UNICARSteer_M->dwork);
  ExtY_UNICARSteer_T *UNICARSteer_Y = (ExtY_UNICARSteer_T *)
    UNICARSteer_M->outputs;

  /* local block i/o variables */
  real_T rtb_delta_ist;
  real_T rtb_Switch;
  real_T rtb_delta_ist_b;
  real_T rtb_Switch_k;
  real_T rtb_delta_ist_m;
  real_T rtb_Switch_e;
  real_T rtb_delta_ist_bp;
  real_T rtb_Switch_n;

  {
    real_T *lastU;
    real_T rtb_Divide;
    real_T rtb_Memory;
    real_T rtb_Gain9_m;
    real_T rtb_Gain9_d;
    real_T rtb_Divide_tmp;

    /* S-Function (read_dict): '<S5>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict4_PWORK.Entry;
      if (!UNICARSteer_DW->ReadCMDict4_IWORK.Checked) {
        UNICARSteer_DW->ReadCMDict4_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict4 = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S2>/Read CM Dict8' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict8_PWORK.Entry;
      if (!UNICARSteer_DW->ReadCMDict8_IWORK.Checked) {
        UNICARSteer_DW->ReadCMDict8_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict8 = e->GetFunc(e->Var);
    }

    /* Saturate: '<S2>/Saturation2' */
    if (UNICARSteer_B->ReadCMDict8 > UNICARSteer_P.ste_max_delta_FRRL_rad) {
      rtb_Memory = UNICARSteer_P.ste_max_delta_FRRL_rad;
    } else if (UNICARSteer_B->ReadCMDict8 < UNICARSteer_P.ste_min_delta_FRRL_rad)
    {
      rtb_Memory = UNICARSteer_P.ste_min_delta_FRRL_rad;
    } else {
      rtb_Memory = UNICARSteer_B->ReadCMDict8;
    }

    /* End of Saturate: '<S2>/Saturation2' */

    /* Sum: '<S9>/Sum3' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  Sum: '<S10>/Sum3'
     *  Sum: '<S7>/Sum3'
     *  Sum: '<S8>/Sum3'
     */
    rtb_Divide_tmp = UNICARSteer_P.ste_TPT1_1_s + UNICARSteer_P.ste_t_s;

    /* Product: '<S9>/Divide' incorporates:
     *  Gain: '<S9>/Gain2'
     *  Memory: '<S9>/Memory'
     *  Sum: '<S9>/Sum1'
     *  Sum: '<S9>/Sum3'
     */
    rtb_Divide = (UNICARSteer_P.ste_KPT1 * rtb_Memory -
                  UNICARSteer_DW->Memory_PreviousInput_e) / rtb_Divide_tmp;

    /* Switch: '<S13>/Switch2' incorporates:
     *  Constant: '<S9>/Constant2'
     *  RelationalOperator: '<S13>/LowerRelop1'
     */
    if (rtb_Divide > UNICARSteer_P.ste_delta_p_lim_rad_s) {
      rtb_Divide = UNICARSteer_P.ste_delta_p_lim_rad_s;
    } else {
      /* Gain: '<S9>/Gain9' */
      rtb_Gain9_m = UNICARSteer_P.Gain9_Gain_a *
        UNICARSteer_P.ste_delta_p_lim_rad_s;

      /* Switch: '<S13>/Switch' incorporates:
       *  RelationalOperator: '<S13>/UpperRelop'
       */
      if (rtb_Divide < rtb_Gain9_m) {
        rtb_Divide = rtb_Gain9_m;
      }

      /* End of Switch: '<S13>/Switch' */
    }

    /* End of Switch: '<S13>/Switch2' */

    /* Sum: '<S9>/Sum5' incorporates:
     *  Constant: '<S9>/Constant'
     *  Memory: '<S9>/Memory'
     *  Product: '<S9>/Product3'
     */
    rtb_delta_ist = rtb_Divide * UNICARSteer_P.ste_t_s +
      UNICARSteer_DW->Memory_PreviousInput_e;

    /* Switch: '<S5>/Switch' incorporates:
     *  Memory: '<S5>/Memory'
     */
    if (UNICARSteer_B->ReadCMDict4 > UNICARSteer_P.Switch_Threshold) {
      rtb_Switch = UNICARSteer_DW->Memory_PreviousInput;
    } else {
      rtb_Switch = rtb_delta_ist;
    }

    /* End of Switch: '<S5>/Switch' */

    /* Switch: '<S2>/Switch6' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (UNICARSteer_P.ste_dyn > UNICARSteer_P.Switch6_Threshold) {
      UNICARSteer_B->Switch6 = rtb_Switch;
    } else {
      UNICARSteer_B->Switch6 = rtb_Memory;
    }

    /* End of Switch: '<S2>/Switch6' */

    /* S-Function (write_dict): '<Root>/Write CM Dict' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARSteer_DW->WriteCMDict_PWORK.Entry;
      if (!UNICARSteer_DW->WriteCMDict_IWORK.Checked) {
        UNICARSteer_DW->WriteCMDict_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      value = UNICARSteer_B->Switch6;
      DVA_PokeSL(e, value);
    }

    /* S-Function (read_dict): '<S6>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict4_PWORK_p.Entry;
      if (!UNICARSteer_DW->ReadCMDict4_IWORK_p.Checked) {
        UNICARSteer_DW->ReadCMDict4_IWORK_p.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict4_h = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S2>/Read CM Dict9' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict9_PWORK.Entry;
      if (!UNICARSteer_DW->ReadCMDict9_IWORK.Checked) {
        UNICARSteer_DW->ReadCMDict9_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict9 = e->GetFunc(e->Var);
    }

    /* Saturate: '<S2>/Saturation3' */
    if (UNICARSteer_B->ReadCMDict9 > UNICARSteer_P.ste_max_delta_FLRR_rad) {
      rtb_Memory = UNICARSteer_P.ste_max_delta_FLRR_rad;
    } else if (UNICARSteer_B->ReadCMDict9 < UNICARSteer_P.ste_min_delta_FLRR_rad)
    {
      rtb_Memory = UNICARSteer_P.ste_min_delta_FLRR_rad;
    } else {
      rtb_Memory = UNICARSteer_B->ReadCMDict9;
    }

    /* End of Saturate: '<S2>/Saturation3' */

    /* Product: '<S10>/Divide' incorporates:
     *  Gain: '<S10>/Gain2'
     *  Memory: '<S10>/Memory'
     *  Sum: '<S10>/Sum1'
     */
    rtb_Divide = (UNICARSteer_P.ste_KPT1 * rtb_Memory -
                  UNICARSteer_DW->Memory_PreviousInput_p) / rtb_Divide_tmp;

    /* Switch: '<S14>/Switch2' incorporates:
     *  Constant: '<S10>/Constant2'
     *  RelationalOperator: '<S14>/LowerRelop1'
     */
    if (rtb_Divide > UNICARSteer_P.ste_delta_p_lim_rad_s) {
      rtb_Gain9_m = UNICARSteer_P.ste_delta_p_lim_rad_s;
    } else {
      /* Gain: '<S10>/Gain9' */
      rtb_Gain9_m = UNICARSteer_P.Gain9_Gain_af *
        UNICARSteer_P.ste_delta_p_lim_rad_s;

      /* Switch: '<S14>/Switch' incorporates:
       *  RelationalOperator: '<S14>/UpperRelop'
       */
      if (!(rtb_Divide < rtb_Gain9_m)) {
        rtb_Gain9_m = rtb_Divide;
      }

      /* End of Switch: '<S14>/Switch' */
    }

    /* End of Switch: '<S14>/Switch2' */

    /* Sum: '<S10>/Sum5' incorporates:
     *  Constant: '<S10>/Constant'
     *  Memory: '<S10>/Memory'
     *  Product: '<S10>/Product3'
     */
    rtb_delta_ist_b = rtb_Gain9_m * UNICARSteer_P.ste_t_s +
      UNICARSteer_DW->Memory_PreviousInput_p;

    /* Switch: '<S6>/Switch' incorporates:
     *  Memory: '<S6>/Memory'
     */
    if (UNICARSteer_B->ReadCMDict4_h > UNICARSteer_P.Switch_Threshold_e) {
      rtb_Switch_k = UNICARSteer_DW->Memory_PreviousInput_h;
    } else {
      rtb_Switch_k = rtb_delta_ist_b;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Switch: '<S2>/Switch7' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (UNICARSteer_P.ste_dyn > UNICARSteer_P.Switch7_Threshold) {
      UNICARSteer_B->Switch7 = rtb_Switch_k;
    } else {
      UNICARSteer_B->Switch7 = rtb_Memory;
    }

    /* End of Switch: '<S2>/Switch7' */

    /* S-Function (write_dict): '<Root>/Write CM Dict1' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARSteer_DW->WriteCMDict1_PWORK.Entry;
      if (!UNICARSteer_DW->WriteCMDict1_IWORK.Checked) {
        UNICARSteer_DW->WriteCMDict1_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      value = UNICARSteer_B->Switch7;
      DVA_PokeSL(e, value);
    }

    /* Derivative: '<S2>/Derivative4' incorporates:
     *  Derivative: '<S2>/Derivative'
     *  Derivative: '<S2>/Derivative1'
     *  Derivative: '<S2>/Derivative2'
     *  Derivative: '<S2>/Derivative3'
     *  Derivative: '<S2>/Derivative6'
     */
    rtb_Divide = UNICARSteer_M->Timing.t[0];
    if ((UNICARSteer_DW->TimeStampA >= rtb_Divide) &&
        (UNICARSteer_DW->TimeStampB >= rtb_Divide)) {
      UNICARSteer_B->Derivative4 = 0.0;
    } else {
      rtb_Memory = UNICARSteer_DW->TimeStampA;
      lastU = &UNICARSteer_DW->LastUAtTimeA;
      if (UNICARSteer_DW->TimeStampA < UNICARSteer_DW->TimeStampB) {
        if (UNICARSteer_DW->TimeStampB < rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB;
          lastU = &UNICARSteer_DW->LastUAtTimeB;
        }
      } else {
        if (UNICARSteer_DW->TimeStampA >= rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB;
          lastU = &UNICARSteer_DW->LastUAtTimeB;
        }
      }

      UNICARSteer_B->Derivative4 = (UNICARSteer_B->Switch6 - *lastU) /
        (rtb_Divide - rtb_Memory);
    }

    /* End of Derivative: '<S2>/Derivative4' */

    /* S-Function (write_dict): '<Root>/Write CM Dict2' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARSteer_DW->WriteCMDict2_PWORK.Entry;
      if (!UNICARSteer_DW->WriteCMDict2_IWORK.Checked) {
        UNICARSteer_DW->WriteCMDict2_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      value = UNICARSteer_B->Derivative4;
      DVA_PokeSL(e, value);
    }

    /* Derivative: '<S2>/Derivative6' */
    if ((UNICARSteer_DW->TimeStampA_n >= rtb_Divide) &&
        (UNICARSteer_DW->TimeStampB_g >= rtb_Divide)) {
      UNICARSteer_B->Derivative6 = 0.0;
    } else {
      rtb_Memory = UNICARSteer_DW->TimeStampA_n;
      lastU = &UNICARSteer_DW->LastUAtTimeA_i;
      if (UNICARSteer_DW->TimeStampA_n < UNICARSteer_DW->TimeStampB_g) {
        if (UNICARSteer_DW->TimeStampB_g < rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_g;
          lastU = &UNICARSteer_DW->LastUAtTimeB_p;
        }
      } else {
        if (UNICARSteer_DW->TimeStampA_n >= rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_g;
          lastU = &UNICARSteer_DW->LastUAtTimeB_p;
        }
      }

      UNICARSteer_B->Derivative6 = (UNICARSteer_B->Switch7 - *lastU) /
        (rtb_Divide - rtb_Memory);
    }

    /* S-Function (write_dict): '<Root>/Write CM Dict3' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)UNICARSteer_DW->WriteCMDict3_PWORK.Entry;
      if (!UNICARSteer_DW->WriteCMDict3_IWORK.Checked) {
        UNICARSteer_DW->WriteCMDict3_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      value = UNICARSteer_B->Derivative6;
      DVA_PokeSL(e, value);
    }

    /* S-Function (read_dict): '<S3>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict4_PWORK_f.Entry;
      if (!UNICARSteer_DW->ReadCMDict4_IWORK_c.Checked) {
        UNICARSteer_DW->ReadCMDict4_IWORK_c.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict4_f = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S2>/Read CM Dict' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict_PWORK.Entry;
      if (!UNICARSteer_DW->ReadCMDict_IWORK.Checked) {
        UNICARSteer_DW->ReadCMDict_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict = e->GetFunc(e->Var);
    }

    /* Saturate: '<S2>/Saturation' */
    if (UNICARSteer_B->ReadCMDict > UNICARSteer_P.ste_max_delta_FLRR_rad) {
      rtb_Memory = UNICARSteer_P.ste_max_delta_FLRR_rad;
    } else if (UNICARSteer_B->ReadCMDict < UNICARSteer_P.ste_min_delta_FLRR_rad)
    {
      rtb_Memory = UNICARSteer_P.ste_min_delta_FLRR_rad;
    } else {
      rtb_Memory = UNICARSteer_B->ReadCMDict;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Product: '<S7>/Divide' incorporates:
     *  Gain: '<S7>/Gain2'
     *  Memory: '<S7>/Memory'
     *  Sum: '<S7>/Sum1'
     */
    rtb_Gain9_m = (UNICARSteer_P.ste_KPT1 * rtb_Memory -
                   UNICARSteer_DW->Memory_PreviousInput_l) / rtb_Divide_tmp;

    /* Switch: '<S11>/Switch2' incorporates:
     *  Constant: '<S7>/Constant2'
     *  RelationalOperator: '<S11>/LowerRelop1'
     */
    if (rtb_Gain9_m > UNICARSteer_P.ste_delta_p_lim_rad_s) {
      rtb_Gain9_m = UNICARSteer_P.ste_delta_p_lim_rad_s;
    } else {
      /* Gain: '<S7>/Gain9' */
      rtb_Gain9_d = UNICARSteer_P.Gain9_Gain *
        UNICARSteer_P.ste_delta_p_lim_rad_s;

      /* Switch: '<S11>/Switch' incorporates:
       *  RelationalOperator: '<S11>/UpperRelop'
       */
      if (rtb_Gain9_m < rtb_Gain9_d) {
        rtb_Gain9_m = rtb_Gain9_d;
      }

      /* End of Switch: '<S11>/Switch' */
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Sum: '<S7>/Sum5' incorporates:
     *  Constant: '<S7>/Constant'
     *  Memory: '<S7>/Memory'
     *  Product: '<S7>/Product3'
     */
    rtb_delta_ist_m = rtb_Gain9_m * UNICARSteer_P.ste_t_s +
      UNICARSteer_DW->Memory_PreviousInput_l;

    /* Switch: '<S3>/Switch' incorporates:
     *  Memory: '<S3>/Memory'
     */
    if (UNICARSteer_B->ReadCMDict4_f > UNICARSteer_P.Switch_Threshold_m) {
      rtb_Switch_e = UNICARSteer_DW->Memory_PreviousInput_g;
    } else {
      rtb_Switch_e = rtb_delta_ist_m;
    }

    /* End of Switch: '<S3>/Switch' */

    /* Switch: '<S2>/Switch4' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (UNICARSteer_P.ste_dyn > UNICARSteer_P.Switch4_Threshold) {
      UNICARSteer_B->Switch4 = rtb_Switch_e;
    } else {
      UNICARSteer_B->Switch4 = rtb_Memory;
    }

    /* End of Switch: '<S2>/Switch4' */

    /* Derivative: '<S2>/Derivative' */
    if ((UNICARSteer_DW->TimeStampA_p >= rtb_Divide) &&
        (UNICARSteer_DW->TimeStampB_a >= rtb_Divide)) {
      UNICARSteer_B->Derivative = 0.0;
    } else {
      rtb_Memory = UNICARSteer_DW->TimeStampA_p;
      lastU = &UNICARSteer_DW->LastUAtTimeA_a;
      if (UNICARSteer_DW->TimeStampA_p < UNICARSteer_DW->TimeStampB_a) {
        if (UNICARSteer_DW->TimeStampB_a < rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_a;
          lastU = &UNICARSteer_DW->LastUAtTimeB_k;
        }
      } else {
        if (UNICARSteer_DW->TimeStampA_p >= rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_a;
          lastU = &UNICARSteer_DW->LastUAtTimeB_k;
        }
      }

      UNICARSteer_B->Derivative = (UNICARSteer_B->Switch4 - *lastU) /
        (rtb_Divide - rtb_Memory);
    }

    /* Derivative: '<S2>/Derivative1' */
    if ((UNICARSteer_DW->TimeStampA_k >= rtb_Divide) &&
        (UNICARSteer_DW->TimeStampB_n >= rtb_Divide)) {
      UNICARSteer_Y->ToCM.qpp_L = 0.0;
    } else {
      rtb_Memory = UNICARSteer_DW->TimeStampA_k;
      lastU = &UNICARSteer_DW->LastUAtTimeA_c;
      if (UNICARSteer_DW->TimeStampA_k < UNICARSteer_DW->TimeStampB_n) {
        if (UNICARSteer_DW->TimeStampB_n < rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_n;
          lastU = &UNICARSteer_DW->LastUAtTimeB_h;
        }
      } else {
        if (UNICARSteer_DW->TimeStampA_k >= rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_n;
          lastU = &UNICARSteer_DW->LastUAtTimeB_h;
        }
      }

      UNICARSteer_Y->ToCM.qpp_L = (UNICARSteer_B->Derivative - *lastU) /
        (rtb_Divide - rtb_Memory);
    }

    /* S-Function (read_dict): '<S4>/Read CM Dict4' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict4_PWORK_l.Entry;
      if (!UNICARSteer_DW->ReadCMDict4_IWORK_m.Checked) {
        UNICARSteer_DW->ReadCMDict4_IWORK_m.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict4_b = e->GetFunc(e->Var);
    }

    /* S-Function (read_dict): '<S2>/Read CM Dict7' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)UNICARSteer_DW->ReadCMDict7_PWORK.Entry;
      if (!UNICARSteer_DW->ReadCMDict7_IWORK.Checked) {
        UNICARSteer_DW->ReadCMDict7_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'UNICARSteer'");
      }

      UNICARSteer_B->ReadCMDict7 = e->GetFunc(e->Var);
    }

    /* Saturate: '<S2>/Saturation1' */
    if (UNICARSteer_B->ReadCMDict7 > UNICARSteer_P.ste_max_delta_FRRL_rad) {
      rtb_Memory = UNICARSteer_P.ste_max_delta_FRRL_rad;
    } else if (UNICARSteer_B->ReadCMDict7 < UNICARSteer_P.ste_min_delta_FRRL_rad)
    {
      rtb_Memory = UNICARSteer_P.ste_min_delta_FRRL_rad;
    } else {
      rtb_Memory = UNICARSteer_B->ReadCMDict7;
    }

    /* End of Saturate: '<S2>/Saturation1' */

    /* Product: '<S8>/Divide' incorporates:
     *  Gain: '<S8>/Gain2'
     *  Memory: '<S8>/Memory'
     *  Sum: '<S8>/Sum1'
     */
    rtb_Gain9_m = (UNICARSteer_P.ste_KPT1 * rtb_Memory -
                   UNICARSteer_DW->Memory_PreviousInput_pz) / rtb_Divide_tmp;

    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S8>/Constant2'
     *  RelationalOperator: '<S12>/LowerRelop1'
     */
    if (rtb_Gain9_m > UNICARSteer_P.ste_delta_p_lim_rad_s) {
      rtb_Gain9_m = UNICARSteer_P.ste_delta_p_lim_rad_s;
    } else {
      /* Gain: '<S8>/Gain9' */
      rtb_Gain9_d = UNICARSteer_P.Gain9_Gain_e *
        UNICARSteer_P.ste_delta_p_lim_rad_s;

      /* Switch: '<S12>/Switch' incorporates:
       *  RelationalOperator: '<S12>/UpperRelop'
       */
      if (rtb_Gain9_m < rtb_Gain9_d) {
        rtb_Gain9_m = rtb_Gain9_d;
      }

      /* End of Switch: '<S12>/Switch' */
    }

    /* End of Switch: '<S12>/Switch2' */

    /* Sum: '<S8>/Sum5' incorporates:
     *  Constant: '<S8>/Constant'
     *  Memory: '<S8>/Memory'
     *  Product: '<S8>/Product3'
     */
    rtb_delta_ist_bp = rtb_Gain9_m * UNICARSteer_P.ste_t_s +
      UNICARSteer_DW->Memory_PreviousInput_pz;

    /* Switch: '<S4>/Switch' incorporates:
     *  Memory: '<S4>/Memory'
     */
    if (UNICARSteer_B->ReadCMDict4_b > UNICARSteer_P.Switch_Threshold_g) {
      rtb_Switch_n = UNICARSteer_DW->Memory_PreviousInput_o;
    } else {
      rtb_Switch_n = rtb_delta_ist_bp;
    }

    /* End of Switch: '<S4>/Switch' */

    /* Switch: '<S2>/Switch5' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (UNICARSteer_P.ste_dyn > UNICARSteer_P.Switch5_Threshold) {
      UNICARSteer_B->Switch5 = rtb_Switch_n;
    } else {
      UNICARSteer_B->Switch5 = rtb_Memory;
    }

    /* End of Switch: '<S2>/Switch5' */

    /* Derivative: '<S2>/Derivative2' */
    if ((UNICARSteer_DW->TimeStampA_g >= rtb_Divide) &&
        (UNICARSteer_DW->TimeStampB_a0 >= rtb_Divide)) {
      UNICARSteer_B->Derivative2 = 0.0;
    } else {
      rtb_Memory = UNICARSteer_DW->TimeStampA_g;
      lastU = &UNICARSteer_DW->LastUAtTimeA_j;
      if (UNICARSteer_DW->TimeStampA_g < UNICARSteer_DW->TimeStampB_a0) {
        if (UNICARSteer_DW->TimeStampB_a0 < rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_a0;
          lastU = &UNICARSteer_DW->LastUAtTimeB_j;
        }
      } else {
        if (UNICARSteer_DW->TimeStampA_g >= rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_a0;
          lastU = &UNICARSteer_DW->LastUAtTimeB_j;
        }
      }

      UNICARSteer_B->Derivative2 = (UNICARSteer_B->Switch5 - *lastU) /
        (rtb_Divide - rtb_Memory);
    }

    /* Derivative: '<S2>/Derivative3' */
    if ((UNICARSteer_DW->TimeStampA_gz >= rtb_Divide) &&
        (UNICARSteer_DW->TimeStampB_m >= rtb_Divide)) {
      UNICARSteer_Y->ToCM.qpp_R = 0.0;
    } else {
      rtb_Memory = UNICARSteer_DW->TimeStampA_gz;
      lastU = &UNICARSteer_DW->LastUAtTimeA_jg;
      if (UNICARSteer_DW->TimeStampA_gz < UNICARSteer_DW->TimeStampB_m) {
        if (UNICARSteer_DW->TimeStampB_m < rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_m;
          lastU = &UNICARSteer_DW->LastUAtTimeB_m;
        }
      } else {
        if (UNICARSteer_DW->TimeStampA_gz >= rtb_Divide) {
          rtb_Memory = UNICARSteer_DW->TimeStampB_m;
          lastU = &UNICARSteer_DW->LastUAtTimeB_m;
        }
      }

      UNICARSteer_Y->ToCM.qpp_R = (UNICARSteer_B->Derivative2 - *lastU) /
        (rtb_Divide - rtb_Memory);
    }

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Constant: '<S1>/Ang'
     *  Constant: '<S1>/AngAcc'
     *  Constant: '<S1>/AngVel'
     *  Constant: '<S1>/AssistFrc'
     *  Constant: '<S1>/AssistTrqCol'
     *  Constant: '<S1>/AssistTrqPin'
     *  Constant: '<S1>/Trq'
     *  Constant: '<S1>/TrqStatic'
     *  Constant: '<S1>/iSteer2q_L'
     *  Constant: '<S1>/iSteer2q_R'
     *  Outport: '<Root>/ToCM'
     */
    UNICARSteer_Y->ToCM.Ang = UNICARSteer_P.Ang_Value;
    UNICARSteer_Y->ToCM.AngVel = UNICARSteer_P.AngVel_Value;
    UNICARSteer_Y->ToCM.AngAcc = UNICARSteer_P.AngAcc_Value;
    UNICARSteer_Y->ToCM.Trq = UNICARSteer_P.Trq_Value;
    UNICARSteer_Y->ToCM.TrqStatic = UNICARSteer_P.TrqStatic_Value;
    UNICARSteer_Y->ToCM.AssistFrc = UNICARSteer_P.AssistFrc_Value;
    UNICARSteer_Y->ToCM.AssistTrqCol = UNICARSteer_P.AssistTrqCol_Value;
    UNICARSteer_Y->ToCM.AssistTrqPin = UNICARSteer_P.AssistTrqPin_Value;
    UNICARSteer_Y->ToCM.q_L = UNICARSteer_B->Switch4;
    UNICARSteer_Y->ToCM.qp_L = UNICARSteer_B->Derivative;
    UNICARSteer_Y->ToCM.iSteer2q_L = UNICARSteer_P.iSteer2q_L_Value;
    UNICARSteer_Y->ToCM.q_R = UNICARSteer_B->Switch5;
    UNICARSteer_Y->ToCM.qp_R = UNICARSteer_B->Derivative2;
    UNICARSteer_Y->ToCM.iSteer2q_R = UNICARSteer_P.iSteer2q_R_Value;
  }

  {
    real_T *lastU;

    /* Update for Memory: '<S5>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput = rtb_Switch;

    /* Update for Memory: '<S9>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_e = rtb_delta_ist;

    /* Update for Memory: '<S6>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_h = rtb_Switch_k;

    /* Update for Memory: '<S10>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_p = rtb_delta_ist_b;

    /* Update for Derivative: '<S2>/Derivative4' */
    if (UNICARSteer_DW->TimeStampA == (rtInf)) {
      UNICARSteer_DW->TimeStampA = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA;
    } else if (UNICARSteer_DW->TimeStampB == (rtInf)) {
      UNICARSteer_DW->TimeStampB = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB;
    } else if (UNICARSteer_DW->TimeStampA < UNICARSteer_DW->TimeStampB) {
      UNICARSteer_DW->TimeStampA = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA;
    } else {
      UNICARSteer_DW->TimeStampB = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB;
    }

    *lastU = UNICARSteer_B->Switch6;

    /* End of Update for Derivative: '<S2>/Derivative4' */

    /* Update for Derivative: '<S2>/Derivative6' */
    if (UNICARSteer_DW->TimeStampA_n == (rtInf)) {
      UNICARSteer_DW->TimeStampA_n = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_i;
    } else if (UNICARSteer_DW->TimeStampB_g == (rtInf)) {
      UNICARSteer_DW->TimeStampB_g = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_p;
    } else if (UNICARSteer_DW->TimeStampA_n < UNICARSteer_DW->TimeStampB_g) {
      UNICARSteer_DW->TimeStampA_n = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_i;
    } else {
      UNICARSteer_DW->TimeStampB_g = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_p;
    }

    *lastU = UNICARSteer_B->Switch7;

    /* End of Update for Derivative: '<S2>/Derivative6' */

    /* Update for Memory: '<S3>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_g = rtb_Switch_e;

    /* Update for Memory: '<S7>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_l = rtb_delta_ist_m;

    /* Update for Derivative: '<S2>/Derivative' */
    if (UNICARSteer_DW->TimeStampA_p == (rtInf)) {
      UNICARSteer_DW->TimeStampA_p = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_a;
    } else if (UNICARSteer_DW->TimeStampB_a == (rtInf)) {
      UNICARSteer_DW->TimeStampB_a = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_k;
    } else if (UNICARSteer_DW->TimeStampA_p < UNICARSteer_DW->TimeStampB_a) {
      UNICARSteer_DW->TimeStampA_p = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_a;
    } else {
      UNICARSteer_DW->TimeStampB_a = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_k;
    }

    *lastU = UNICARSteer_B->Switch4;

    /* End of Update for Derivative: '<S2>/Derivative' */

    /* Update for Derivative: '<S2>/Derivative1' */
    if (UNICARSteer_DW->TimeStampA_k == (rtInf)) {
      UNICARSteer_DW->TimeStampA_k = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_c;
    } else if (UNICARSteer_DW->TimeStampB_n == (rtInf)) {
      UNICARSteer_DW->TimeStampB_n = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_h;
    } else if (UNICARSteer_DW->TimeStampA_k < UNICARSteer_DW->TimeStampB_n) {
      UNICARSteer_DW->TimeStampA_k = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_c;
    } else {
      UNICARSteer_DW->TimeStampB_n = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_h;
    }

    *lastU = UNICARSteer_B->Derivative;

    /* End of Update for Derivative: '<S2>/Derivative1' */

    /* Update for Memory: '<S4>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_o = rtb_Switch_n;

    /* Update for Memory: '<S8>/Memory' */
    UNICARSteer_DW->Memory_PreviousInput_pz = rtb_delta_ist_bp;

    /* Update for Derivative: '<S2>/Derivative2' */
    if (UNICARSteer_DW->TimeStampA_g == (rtInf)) {
      UNICARSteer_DW->TimeStampA_g = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_j;
    } else if (UNICARSteer_DW->TimeStampB_a0 == (rtInf)) {
      UNICARSteer_DW->TimeStampB_a0 = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_j;
    } else if (UNICARSteer_DW->TimeStampA_g < UNICARSteer_DW->TimeStampB_a0) {
      UNICARSteer_DW->TimeStampA_g = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_j;
    } else {
      UNICARSteer_DW->TimeStampB_a0 = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_j;
    }

    *lastU = UNICARSteer_B->Switch5;

    /* End of Update for Derivative: '<S2>/Derivative2' */

    /* Update for Derivative: '<S2>/Derivative3' */
    if (UNICARSteer_DW->TimeStampA_gz == (rtInf)) {
      UNICARSteer_DW->TimeStampA_gz = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_jg;
    } else if (UNICARSteer_DW->TimeStampB_m == (rtInf)) {
      UNICARSteer_DW->TimeStampB_m = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_m;
    } else if (UNICARSteer_DW->TimeStampA_gz < UNICARSteer_DW->TimeStampB_m) {
      UNICARSteer_DW->TimeStampA_gz = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeA_jg;
    } else {
      UNICARSteer_DW->TimeStampB_m = UNICARSteer_M->Timing.t[0];
      lastU = &UNICARSteer_DW->LastUAtTimeB_m;
    }

    *lastU = UNICARSteer_B->Derivative2;

    /* End of Update for Derivative: '<S2>/Derivative3' */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++UNICARSteer_M->Timing.clockTick0)) {
    ++UNICARSteer_M->Timing.clockTickH0;
  }

  UNICARSteer_M->Timing.t[0] = UNICARSteer_M->Timing.clockTick0 *
    UNICARSteer_M->Timing.stepSize0 + UNICARSteer_M->Timing.clockTickH0 *
    UNICARSteer_M->Timing.stepSize0 * 4294967296.0;

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
    UNICARSteer_M->Timing.clockTick1++;
    if (!UNICARSteer_M->Timing.clockTick1) {
      UNICARSteer_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void UNICARSteer_initialize(RT_MODEL_UNICARSteer_T *const UNICARSteer_M)
{
  DW_UNICARSteer_T *UNICARSteer_DW = ((DW_UNICARSteer_T *) UNICARSteer_M->dwork);

  /* Start for S-Function (read_dict): '<S5>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.ErrBit.RL", NULL);
    UNICARSteer_DW->ReadCMDict4_IWORK.Checked = 0;
    UNICARSteer_DW->ReadCMDict4_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict8' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.setpoint_Angle.RL", NULL);
    UNICARSteer_DW->ReadCMDict8_IWORK.Checked = 0;
    UNICARSteer_DW->ReadCMDict8_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<Root>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("Steer.RL.q", NULL);
    UNICARSteer_DW->WriteCMDict_IWORK.Checked = 0;
    UNICARSteer_DW->WriteCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S6>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.ErrBit.RR", NULL);
    UNICARSteer_DW->ReadCMDict4_IWORK_p.Checked = 0;
    UNICARSteer_DW->ReadCMDict4_PWORK_p.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict9' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.setpoint_Angle.RR", NULL);
    UNICARSteer_DW->ReadCMDict9_IWORK.Checked = 0;
    UNICARSteer_DW->ReadCMDict9_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<Root>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("Steer.RR.q", NULL);
    UNICARSteer_DW->WriteCMDict1_IWORK.Checked = 0;
    UNICARSteer_DW->WriteCMDict1_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<Root>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("Steer.RL.qp", NULL);
    UNICARSteer_DW->WriteCMDict2_IWORK.Checked = 0;
    UNICARSteer_DW->WriteCMDict2_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<Root>/Write CM Dict3' */
  {
    char **namevec = CM_Names2StrVec("Steer.RR.qp", NULL);
    UNICARSteer_DW->WriteCMDict3_IWORK.Checked = 0;
    UNICARSteer_DW->WriteCMDict3_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.ErrBit.FL", NULL);
    UNICARSteer_DW->ReadCMDict4_IWORK_c.Checked = 0;
    UNICARSteer_DW->ReadCMDict4_PWORK_f.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.setpoint_Angle.FL", NULL);
    UNICARSteer_DW->ReadCMDict_IWORK.Checked = 0;
    UNICARSteer_DW->ReadCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.ErrBit.FR", NULL);
    UNICARSteer_DW->ReadCMDict4_IWORK_m.Checked = 0;
    UNICARSteer_DW->ReadCMDict4_PWORK_l.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict7' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Steer.setpoint_Angle.FR", NULL);
    UNICARSteer_DW->ReadCMDict7_IWORK.Checked = 0;
    UNICARSteer_DW->ReadCMDict7_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* InitializeConditions for Memory: '<S5>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput = UNICARSteer_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_e =
    UNICARSteer_P.Memory_InitialCondition_p;

  /* InitializeConditions for Memory: '<S6>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_h =
    UNICARSteer_P.Memory_InitialCondition_j;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_p =
    UNICARSteer_P.Memory_InitialCondition_c;

  /* InitializeConditions for Derivative: '<S2>/Derivative4' */
  UNICARSteer_DW->TimeStampA = (rtInf);
  UNICARSteer_DW->TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S2>/Derivative6' */
  UNICARSteer_DW->TimeStampA_n = (rtInf);
  UNICARSteer_DW->TimeStampB_g = (rtInf);

  /* InitializeConditions for Memory: '<S3>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_g =
    UNICARSteer_P.Memory_InitialCondition_n;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_l =
    UNICARSteer_P.Memory_InitialCondition_e;

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  UNICARSteer_DW->TimeStampA_p = (rtInf);
  UNICARSteer_DW->TimeStampB_a = (rtInf);

  /* InitializeConditions for Derivative: '<S2>/Derivative1' */
  UNICARSteer_DW->TimeStampA_k = (rtInf);
  UNICARSteer_DW->TimeStampB_n = (rtInf);

  /* InitializeConditions for Memory: '<S4>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_o =
    UNICARSteer_P.Memory_InitialCondition_p2;

  /* InitializeConditions for Memory: '<S8>/Memory' */
  UNICARSteer_DW->Memory_PreviousInput_pz =
    UNICARSteer_P.Memory_InitialCondition_f;

  /* InitializeConditions for Derivative: '<S2>/Derivative2' */
  UNICARSteer_DW->TimeStampA_g = (rtInf);
  UNICARSteer_DW->TimeStampB_a0 = (rtInf);

  /* InitializeConditions for Derivative: '<S2>/Derivative3' */
  UNICARSteer_DW->TimeStampA_gz = (rtInf);
  UNICARSteer_DW->TimeStampB_m = (rtInf);
}

/* Model terminate function */
void UNICARSteer_terminate(RT_MODEL_UNICARSteer_T * UNICARSteer_M)
{
  rt_FREE(UNICARSteer_M->solverInfo);

  /* model code */
  rt_FREE(UNICARSteer_M->blockIO);
  rt_FREE(UNICARSteer_M->inputs);
  rt_FREE(UNICARSteer_M->outputs);
  rt_FREE(UNICARSteer_M->dwork);
  rt_FREE(UNICARSteer_M);
}

/* Model data allocation function */
RT_MODEL_UNICARSteer_T *UNICARSteer(struct tInfos *inf)
{
  RT_MODEL_UNICARSteer_T *UNICARSteer_M;
  UNICARSteer_M = (RT_MODEL_UNICARSteer_T *) malloc(sizeof
    (RT_MODEL_UNICARSteer_T));
  if (UNICARSteer_M == NULL) {
    return NULL;
  }

  (void) memset((char *)UNICARSteer_M, 0,
                sizeof(RT_MODEL_UNICARSteer_T));
  MatSupp_Init();

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(UNICARSteer_M,rt_SolverInfo);
    UNICARSteer_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(UNICARSteer_M->solverInfo,
                          &UNICARSteer_M->Timing.simTimeStep);
    rtsiSetTPtr(UNICARSteer_M->solverInfo, &rtmGetTPtr(UNICARSteer_M));
    rtsiSetStepSizePtr(UNICARSteer_M->solverInfo,
                       &UNICARSteer_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(UNICARSteer_M->solverInfo, (&rtmGetErrorStatus
      (UNICARSteer_M)));
    rtsiSetRTModelPtr(UNICARSteer_M->solverInfo, UNICARSteer_M);
  }

  rtsiSetSolverName(UNICARSteer_M->solverInfo,"FixedStepDiscrete");

  /* block I/O */
  {
    B_UNICARSteer_T *b = (B_UNICARSteer_T *) malloc(sizeof(B_UNICARSteer_T));
    rt_VALIDATE_MEMORY(UNICARSteer_M,b);
    UNICARSteer_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_UNICARSteer_T *dwork = (DW_UNICARSteer_T *) malloc(sizeof
      (DW_UNICARSteer_T));
    rt_VALIDATE_MEMORY(UNICARSteer_M,dwork);
    UNICARSteer_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_UNICARSteer_T *UNICARSteer_U = (ExtU_UNICARSteer_T *) malloc(sizeof
      (ExtU_UNICARSteer_T));
    rt_VALIDATE_MEMORY(UNICARSteer_M,UNICARSteer_U);
    UNICARSteer_M->inputs = (((ExtU_UNICARSteer_T *) UNICARSteer_U));
  }

  /* external outputs */
  {
    ExtY_UNICARSteer_T *UNICARSteer_Y = (ExtY_UNICARSteer_T *) malloc(sizeof
      (ExtY_UNICARSteer_T));
    rt_VALIDATE_MEMORY(UNICARSteer_M,UNICARSteer_Y);
    UNICARSteer_M->outputs = (UNICARSteer_Y);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  UNICARSteer_InitializeDataMapInfo(UNICARSteer_M);

  /* CarMaker parameter tuning */
  {
    const struct tMatSuppMMI *mmi = &(rtmGetDataMapInfo(UNICARSteer_M).mmi);
    tMatSuppTunables *tuns = MatSupp_TunBegin("UNICARSteer", mmi);
    UNICARSteer_SetParams(UNICARSteer_M, tuns, inf);
    MatSupp_TunEnd(tuns);
  }

  {
    B_UNICARSteer_T *UNICARSteer_B = ((B_UNICARSteer_T *) UNICARSteer_M->blockIO);
    DW_UNICARSteer_T *UNICARSteer_DW = ((DW_UNICARSteer_T *)
      UNICARSteer_M->dwork);
    ExtU_UNICARSteer_T *UNICARSteer_U = (ExtU_UNICARSteer_T *)
      UNICARSteer_M->inputs;
    ExtY_UNICARSteer_T *UNICARSteer_Y = (ExtY_UNICARSteer_T *)
      UNICARSteer_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtsiSetSimTimeStep(UNICARSteer_M->solverInfo, MAJOR_TIME_STEP);
    rtmSetTPtr(UNICARSteer_M, &UNICARSteer_M->Timing.tArray[0]);
    UNICARSteer_M->Timing.stepSize0 = 0.001;

    /* block I/O */
    (void) memset(((void *) UNICARSteer_B), 0,
                  sizeof(B_UNICARSteer_T));

    /* states (dwork) */
    (void) memset((void *)UNICARSteer_DW, 0,
                  sizeof(DW_UNICARSteer_T));

    /* external inputs */
    (void)memset(UNICARSteer_U, 0, sizeof(ExtU_UNICARSteer_T));

    /* external outputs */
    UNICARSteer_Y->ToCM = UNICARSteer_rtZcmSteeringOut;
  }

  return UNICARSteer_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *UNICARSteer_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)UNICARSteer_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *UNICARSteer_DictDefines = DictDefines;
tQuantEntry *UNICARSteer_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *UNICARSteer_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)UNICARSteer_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *UNICARSteer_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *UNICARSteer_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
