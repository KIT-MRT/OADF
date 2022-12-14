/*
 * UNICARBrake.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UNICARBrake".
 *
 * Model version              : 1.55
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Dec  1 14:41:24 2021
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UNICARBrake_capi.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "UNICARBrake.h"
#include "UNICARBrake_private.h"
#include "UNICARBrake_wrap.h"

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

const cmBrakeOut UNICARBrake_rtZcmBrakeOut = {
  {
    {
      0.0,                             /* Trq_WB */
      0.0,                             /* Trq_PB */
      0.0                              /* Trq_BrakeReg_trg */
    },                                 /* FL */

    {
      0.0,                             /* Trq_WB */
      0.0,                             /* Trq_PB */
      0.0                              /* Trq_BrakeReg_trg */
    },                                 /* FR */

    {
      0.0,                             /* Trq_WB */
      0.0,                             /* Trq_PB */
      0.0                              /* Trq_BrakeReg_trg */
    },                                 /* RL */

    {
      0.0,                             /* Trq_WB */
      0.0,                             /* Trq_PB */
      0.0                              /* Trq_BrakeReg_trg */
    }                                  /* RR */
  },                                   /* WheelOut */

  {
    0.0,                               /* d0 */
    0.0,                               /* d1 */
    0.0,                               /* d2 */
    0.0                                /* d3 */
  }                                    /* Trq_DriveSrc_trg */
} ;                                    /* cmBrakeOut ground */

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_UNICARBrake_T *const UNICARBrake_M)
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  UNICARBrake_derivatives(UNICARBrake_M);
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S9>/reduce pressure'
 *    '<S19>/reduce pressure'
 *    '<S29>/reduce pressure'
 *    '<S39>/reduce pressure'
 */
void UNICARBrake_reducepressure(real_T *rty_Out1, real_T *rty_Out2,
  P_reducepressure_UNICARBrake_T *localP, P_UNICARBrake_T *UNICARBrake_P)
{
  if (1) {
    /* SignalConversion generated from: '<S15>/Out1' incorporates:
     *  Constant: '<S15>/Constant1'
     */
    *rty_Out1 = localP->Constant1_Value;

    /* SignalConversion generated from: '<S15>/Out2' incorporates:
     *  Constant: '<S15>/Constant2'
     */
    *rty_Out2 = UNICARBrake_P->brk_TRed_1_s;
  }
}

/*
 * Termination for action system:
 *    '<S9>/reduce pressure'
 *    '<S19>/reduce pressure'
 *    '<S29>/reduce pressure'
 *    '<S39>/reduce pressure'
 */
void UNICARBrake_reducepressure_Term(void)
{
}

/*
 * Output and update for action system:
 *    '<S9>/free pressure'
 *    '<S19>/free pressure'
 *    '<S29>/free pressure'
 *    '<S39>/free pressure'
 */
void UNICARBrake_freepressure(real_T *rty_Out1, real_T *rty_Out2,
  P_freepressure_UNICARBrake_T *localP, P_UNICARBrake_T *UNICARBrake_P)
{
  if (1) {
    /* SignalConversion generated from: '<S13>/Out1' incorporates:
     *  Constant: '<S13>/Constant1'
     */
    *rty_Out1 = localP->Constant1_Value;

    /* SignalConversion generated from: '<S13>/Out2' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    *rty_Out2 = UNICARBrake_P->brk_TRai_1_s;
  }
}

/*
 * Termination for action system:
 *    '<S9>/free pressure'
 *    '<S19>/free pressure'
 *    '<S29>/free pressure'
 *    '<S39>/free pressure'
 */
void UNICARBrake_freepressure_Term(void)
{
}

/*
 * Output and update for action system:
 *    '<S9>/keep pressure'
 *    '<S19>/keep pressure'
 *    '<S29>/keep pressure'
 *    '<S39>/keep pressure'
 */
void UNICARBrake_keeppressure(real_T *rty_Out1, real_T *rty_Out2,
  P_keeppressure_UNICARBrake_T *localP, P_UNICARBrake_T *UNICARBrake_P)
{
  if (1) {
    /* SignalConversion generated from: '<S14>/Out1' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    *rty_Out1 = localP->Constant1_Value;

    /* SignalConversion generated from: '<S14>/Out2' incorporates:
     *  Constant: '<S14>/Constant2'
     */
    *rty_Out2 = UNICARBrake_P->brk_TKeep_1_s;
  }
}

/*
 * Termination for action system:
 *    '<S9>/keep pressure'
 *    '<S19>/keep pressure'
 *    '<S29>/keep pressure'
 *    '<S39>/keep pressure'
 */
void UNICARBrake_keeppressure_Term(void)
{
}

/* Model step function */
void UNICARBrake_step(RT_MODEL_UNICARBrake_T *const UNICARBrake_M)
{
  B_UNICARBrake_T *UNICARBrake_B = ((B_UNICARBrake_T *) UNICARBrake_M->blockIO);
  DW_UNICARBrake_T *UNICARBrake_DW = ((DW_UNICARBrake_T *) UNICARBrake_M->dwork);
  X_UNICARBrake_T *UNICARBrake_X = ((X_UNICARBrake_T *)
    UNICARBrake_M->contStates);
  ExtU_UNICARBrake_T *UNICARBrake_U = (ExtU_UNICARBrake_T *)
    UNICARBrake_M->inputs;
  ExtY_UNICARBrake_T *UNICARBrake_Y = (ExtY_UNICARBrake_T *)
    UNICARBrake_M->outputs;

  /* local block i/o variables */
  real_T rtb_p_trg;
  real_T rtb_p_trg_o;
  real_T rtb_p_trg_k;
  real_T rtb_p_trg_h;
  if (rtmIsMajorTimeStep(UNICARBrake_M)) {
    /* set solver stop time */
    if (!(UNICARBrake_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(UNICARBrake_M->solverInfo,
                            ((UNICARBrake_M->Timing.clockTickH0 + 1) *
        UNICARBrake_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(UNICARBrake_M->solverInfo,
                            ((UNICARBrake_M->Timing.clockTick0 + 1) *
        UNICARBrake_M->Timing.stepSize0 + UNICARBrake_M->Timing.clockTickH0 *
        UNICARBrake_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(UNICARBrake_M)) {
    UNICARBrake_M->Timing.t[0] = rtsiGetT(UNICARBrake_M->solverInfo);
  }

  {
    real_T *lastU;
    real_T rtb_Gain_i;
    int8_T rtAction;
    real_T rtb_ABSoff;
    real_T rtb_Switch2_m;
    real_T rtb_Switch_m_idx_0;
    real_T rtb_Switch_m_idx_1;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S1>/Read CM Dict1' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict1_PWORK.Entry;
        if (!UNICARBrake_DW->ReadCMDict1_IWORK.Checked) {
          UNICARBrake_DW->ReadCMDict1_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict1 = e->GetFunc(e->Var);
      }
    }

    /* TransferFcn: '<S11>/ABS on' */
    rtb_Switch2_m = UNICARBrake_P.ABSon_C * UNICARBrake_X->ABSon_CSTATE;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S1>/Read CM Dict' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict_PWORK.Entry;
        if (!UNICARBrake_DW->ReadCMDict_IWORK.Checked) {
          UNICARBrake_DW->ReadCMDict_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict = e->GetFunc(e->Var);
      }

      /* Product: '<S11>/Product' incorporates:
       *  Constant: '<S11>/Constant'
       *  Constant: '<S11>/Constant1'
       *  Constant: '<S11>/Constant2'
       */
      UNICARBrake_B->Product = UNICARBrake_P.brk_area_m_2 *
        UNICARBrake_P.brk_r_m * UNICARBrake_P.brk_mue;
    }

    /* Gain: '<S10>/Gain' incorporates:
     *  Inport: '<Root>/FromCM'
     *  Product: '<S10>/Product'
     *  RelationalOperator: '<S10>/GreaterThan'
     *  Sum: '<S10>/Add'
     */
    rtb_Gain_i = (real_T)(UNICARBrake_U->FromCM.WheelIn.FL.Trq_BrakeReg_max <
                          UNICARBrake_B->ReadCMDict) *
      (UNICARBrake_B->ReadCMDict - UNICARBrake_U->FromCM.WheelIn.FL.Trq_BrakeReg)
      * UNICARBrake_P.brk_i;

    /* Product: '<S11>/Divide' */
    rtb_p_trg = rtb_Gain_i / UNICARBrake_B->Product;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Product: '<S11>/Product2' incorporates:
       *  Constant: '<S11>/Constant3'
       */
      UNICARBrake_B->Product2 = UNICARBrake_B->Product *
        UNICARBrake_P.brk_pMax_pa;
    }

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S16>/Constant4'
     *  Product: '<S11>/Product1'
     *  Switch: '<S11>/Switch2'
     */
    if (UNICARBrake_B->ReadCMDict1 > UNICARBrake_P.Switch_Threshold) {
      rtb_Switch_m_idx_0 = UNICARBrake_P.Constant4_Value;
      rtb_Switch_m_idx_1 = UNICARBrake_P.Constant4_Value;
    } else {
      if (UNICARBrake_P.brk_dyn >= UNICARBrake_P.Switch2_Threshold) {
        /* Switch: '<S11>/Switch1' incorporates:
         *  Constant: '<S8>/ABS_on_off'
         *  Switch: '<S11>/Switch2'
         *  TransferFcn: '<S11>/ABS off'
         */
        if (!(UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold)) {
          rtb_Switch2_m = UNICARBrake_P.ABSoff_C[0] *
            UNICARBrake_X->ABSoff_CSTATE[0] + UNICARBrake_P.ABSoff_C[1] *
            UNICARBrake_X->ABSoff_CSTATE[1];
        }

        /* End of Switch: '<S11>/Switch1' */
      } else {
        /* Switch: '<S11>/Switch2' */
        rtb_Switch2_m = rtb_p_trg;
      }

      rtb_Switch_m_idx_0 = rtb_Switch2_m * UNICARBrake_B->Product;
      rtb_Switch_m_idx_1 = UNICARBrake_B->Product2;
    }

    /* End of Switch: '<S16>/Switch' */

    /* Sum: '<S8>/Add' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add = UNICARBrake_U->FromCM.WheelIn.FL.Trq_BrakeReg_max +
      rtb_Switch_m_idx_1;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S1>/Write CM Dict' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict_PWORK.Entry;
        if (!UNICARBrake_DW->WriteCMDict_IWORK.Checked) {
          UNICARBrake_DW->WriteCMDict_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add;
        DVA_PokeSL(e, value);
      }

      /* Memory: '<S12>/Memory' */
      UNICARBrake_B->Memory = UNICARBrake_DW->Memory_PreviousInput;

      /* S-Function (read_dict): '<S1>/Read CM Dict2' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict2_PWORK.Entry;
        if (!UNICARBrake_DW->ReadCMDict2_IWORK.Checked) {
          UNICARBrake_DW->ReadCMDict2_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict2 = e->GetFunc(e->Var);
      }

      /* Abs: '<S9>/Abs' incorporates:
       *  Gain: '<S9>/Gain'
       */
      UNICARBrake_B->Abs = fabs(UNICARBrake_P.brk_Kslip *
        UNICARBrake_B->ReadCMDict2);

      /* S-Function (read_dict): '<S1>/Read CM Dict3' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict3_PWORK.Entry;
        if (!UNICARBrake_DW->ReadCMDict3_IWORK.Checked) {
          UNICARBrake_DW->ReadCMDict3_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict3 = e->GetFunc(e->Var);
      }
    }

    /* Derivative: '<S9>/Derivative' incorporates:
     *  Clock: '<S12>/Clock'
     *  Clock: '<S22>/Clock'
     *  Clock: '<S32>/Clock'
     *  Clock: '<S42>/Clock'
     */
    rtb_Switch2_m = UNICARBrake_M->Timing.t[0];
    if ((UNICARBrake_DW->TimeStampA >= rtb_Switch2_m) &&
        (UNICARBrake_DW->TimeStampB >= rtb_Switch2_m)) {
      rtb_ABSoff = 0.0;
    } else {
      rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampA;
      lastU = &UNICARBrake_DW->LastUAtTimeA;
      if (UNICARBrake_DW->TimeStampA < UNICARBrake_DW->TimeStampB) {
        if (UNICARBrake_DW->TimeStampB < rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB;
          lastU = &UNICARBrake_DW->LastUAtTimeB;
        }
      } else {
        if (UNICARBrake_DW->TimeStampA >= rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB;
          lastU = &UNICARBrake_DW->LastUAtTimeB;
        }
      }

      rtb_ABSoff = (UNICARBrake_B->ReadCMDict3 - *lastU) / (rtb_Switch2_m -
        rtb_Switch_m_idx_1);
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S1>/Read CM Dict4' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict4_PWORK.Entry;
        if (!UNICARBrake_DW->ReadCMDict4_IWORK.Checked) {
          UNICARBrake_DW->ReadCMDict4_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict4 = e->GetFunc(e->Var);
      }

      /* Memory: '<S9>/Memory' */
      UNICARBrake_B->Memory_i = UNICARBrake_DW->Memory_PreviousInput_f;
    }

    /* Product: '<S9>/Product1' incorporates:
     *  Constant: '<S9>/Constant3'
     */
    rtb_ABSoff = rtb_ABSoff * UNICARBrake_B->ReadCMDict4 *
      UNICARBrake_P.brk_Kacc;

    /* Abs: '<S9>/Abs1' */
    rtb_ABSoff = fabs(rtb_ABSoff);

    /* Sum: '<S9>/Sum' */
    rtb_ABSoff += UNICARBrake_B->Abs;

    /* If: '<S9>/If2' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant4'
     */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      if ((rtb_ABSoff > UNICARBrake_P.brk_SKup) || (UNICARBrake_B->Memory_i >
           rtb_Gain_i)) {
        rtAction = 0;
      } else if (rtb_ABSoff < UNICARBrake_P.brk_SKlow) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      UNICARBrake_DW->If2_ActiveSubsystem = rtAction;
    } else {
      rtAction = UNICARBrake_DW->If2_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S9>/reduce pressure' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      UNICARBrake_reducepressure(&UNICARBrake_B->f_brake,
        &UNICARBrake_B->T_Filter, &UNICARBrake_P.reducepressure, &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S9>/reduce pressure' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S9>/free pressure' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      UNICARBrake_freepressure(&UNICARBrake_B->f_brake, &UNICARBrake_B->T_Filter,
        &UNICARBrake_P.freepressure, &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S9>/free pressure' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S9>/keep pressure' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      UNICARBrake_keeppressure(&UNICARBrake_B->f_brake, &UNICARBrake_B->T_Filter,
        &UNICARBrake_P.keeppressure, &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S9>/keep pressure' */
      break;
    }

    /* End of If: '<S9>/If2' */

    /* Clock: '<S12>/Clock' */
    UNICARBrake_B->Clock = rtb_Switch2_m;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Memory: '<S12>/Memory1' */
      UNICARBrake_B->Memory1 = UNICARBrake_DW->Memory1_PreviousInput;
    }

    /* Sum: '<S12>/Sum3' */
    rtb_Gain_i = UNICARBrake_B->Clock - UNICARBrake_B->Memory1;

    /* Sum: '<S12>/Sum2' incorporates:
     *  Product: '<S12>/Product5'
     *  Product: '<S9>/Product2'
     *  Sum: '<S12>/Sum1'
     *  Sum: '<S12>/Sum4'
     */
    UNICARBrake_B->Sum2 = (rtb_Switch_m_idx_0 * UNICARBrake_B->f_brake -
      UNICARBrake_B->Memory) * rtb_Gain_i / (rtb_Gain_i +
      UNICARBrake_B->T_Filter) + UNICARBrake_B->Memory;

    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/ABS_on_off'
     */
    if (UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_nh) {
      UNICARBrake_B->Switch1 = UNICARBrake_B->Sum2;
    } else {
      UNICARBrake_B->Switch1 = rtb_Switch_m_idx_0;
    }

    /* End of Switch: '<S8>/Switch1' */

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    UNICARBrake_B->DataTypeConversion = (UNICARBrake_B->Switch1 >=
      UNICARBrake_P.CompareToConstant_const);
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S1>/Write CM Dict1' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict1_PWORK.Entry;
        if (!UNICARBrake_DW->WriteCMDict1_IWORK.Checked) {
          UNICARBrake_DW->WriteCMDict1_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->DataTypeConversion;
        DVA_PokeSL(e, value);
      }
    }

    /* Sum: '<S1>/Add' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_e = 1.0 / UNICARBrake_P.brk_i * UNICARBrake_B->Switch1 +
      UNICARBrake_U->FromCM.WheelIn.FL.Trq_BrakeReg;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S1>/Write CM Dict2' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict2_PWORK.Entry;
        if (!UNICARBrake_DW->WriteCMDict2_IWORK.Checked) {
          UNICARBrake_DW->WriteCMDict2_IWORK.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_e;
        DVA_PokeSL(e, value);
      }
    }

    /* Switch: '<S10>/Switch' incorporates:
     *  Inport: '<Root>/FromCM'
     *  RelationalOperator: '<S10>/GreaterThan1'
     */
    if (UNICARBrake_U->FromCM.WheelIn.FL.Trq_BrakeReg_max >=
        UNICARBrake_B->ReadCMDict) {
      UNICARBrake_B->Switch = UNICARBrake_B->ReadCMDict;
    } else {
      UNICARBrake_B->Switch = UNICARBrake_U->FromCM.WheelIn.FL.Trq_BrakeReg_max;
    }

    /* End of Switch: '<S10>/Switch' */

    /* TransportDelay: '<S11>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      real_T tMinusDelay = simTime - UNICARBrake_P.brk_tDel_s;
      UNICARBrake_B->TransportDelay = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        UNICARBrake_DW->TransportDelay_IWORK.CircularBufSize,
        &UNICARBrake_DW->TransportDelay_IWORK.Last,
        UNICARBrake_DW->TransportDelay_IWORK.Tail,
        UNICARBrake_DW->TransportDelay_IWORK.Head,
        UNICARBrake_P.TransportDelay_InitOutput,
        0,
        0);
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S2>/Read CM Dict1' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict1_PWORK_m.Entry;
        if (!UNICARBrake_DW->ReadCMDict1_IWORK_e.Checked) {
          UNICARBrake_DW->ReadCMDict1_IWORK_e.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict1_o = e->GetFunc(e->Var);
      }

      /* S-Function (read_dict): '<S2>/Read CM Dict' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict_PWORK_a.Entry;
        if (!UNICARBrake_DW->ReadCMDict_IWORK_k.Checked) {
          UNICARBrake_DW->ReadCMDict_IWORK_k.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict_b = e->GetFunc(e->Var);
      }

      /* Product: '<S21>/Product' incorporates:
       *  Constant: '<S21>/Constant'
       *  Constant: '<S21>/Constant1'
       *  Constant: '<S21>/Constant2'
       */
      UNICARBrake_B->Product_g = UNICARBrake_P.brk_area_m_2 *
        UNICARBrake_P.brk_r_m * UNICARBrake_P.brk_mue;
    }

    /* Gain: '<S20>/Gain' incorporates:
     *  Inport: '<Root>/FromCM'
     *  Product: '<S20>/Product1'
     *  RelationalOperator: '<S20>/GreaterThan2'
     *  Sum: '<S20>/Add1'
     */
    rtb_ABSoff = (real_T)(UNICARBrake_U->FromCM.WheelIn.FR.Trq_BrakeReg_max <
                          UNICARBrake_B->ReadCMDict_b) *
      (UNICARBrake_B->ReadCMDict_b -
       UNICARBrake_U->FromCM.WheelIn.FR.Trq_BrakeReg) * UNICARBrake_P.brk_i;

    /* Product: '<S21>/Divide' */
    rtb_p_trg_o = rtb_ABSoff / UNICARBrake_B->Product_g;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Product: '<S21>/Product2' incorporates:
       *  Constant: '<S21>/Constant3'
       */
      UNICARBrake_B->Product2_m = UNICARBrake_B->Product_g *
        UNICARBrake_P.brk_pMax_pa;
    }

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S21>/Constant4'
     *  Constant: '<S26>/Constant4'
     *  Product: '<S21>/Product1'
     *  Switch: '<S21>/Switch2'
     */
    if (UNICARBrake_B->ReadCMDict1_o > UNICARBrake_P.Switch_Threshold_j) {
      rtb_Switch_m_idx_0 = UNICARBrake_P.Constant4_Value_j;
      rtb_Switch_m_idx_1 = UNICARBrake_P.Constant4_Value_j;
    } else {
      if (UNICARBrake_P.brk_dyn >= UNICARBrake_P.Switch2_Threshold_a) {
        /* Switch: '<S21>/Switch1' incorporates:
         *  Constant: '<S18>/ABS_on_off'
         *  Switch: '<S21>/Switch2'
         *  TransferFcn: '<S21>/ABS off'
         *  TransferFcn: '<S21>/ABS on'
         */
        if (UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_p) {
          rtb_Switch_m_idx_0 = UNICARBrake_P.ABSon_C_g *
            UNICARBrake_X->ABSon_CSTATE_d;
        } else {
          rtb_Switch_m_idx_0 = UNICARBrake_P.ABSoff_C_b[0] *
            UNICARBrake_X->ABSoff_CSTATE_o[0] + UNICARBrake_P.ABSoff_C_b[1] *
            UNICARBrake_X->ABSoff_CSTATE_o[1];
        }

        /* End of Switch: '<S21>/Switch1' */
      } else {
        /* Switch: '<S21>/Switch2' */
        rtb_Switch_m_idx_0 = rtb_p_trg_o;
      }

      rtb_Switch_m_idx_0 *= UNICARBrake_B->Product_g;
      rtb_Switch_m_idx_1 = UNICARBrake_B->Product2_m;
    }

    /* End of Switch: '<S26>/Switch' */

    /* Sum: '<S18>/Add' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_b = UNICARBrake_U->FromCM.WheelIn.FR.Trq_BrakeReg_max +
      rtb_Switch_m_idx_1;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S2>/Write CM Dict' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict_PWORK_b.Entry;
        if (!UNICARBrake_DW->WriteCMDict_IWORK_n.Checked) {
          UNICARBrake_DW->WriteCMDict_IWORK_n.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_b;
        DVA_PokeSL(e, value);
      }

      /* Memory: '<S22>/Memory' */
      UNICARBrake_B->Memory_a = UNICARBrake_DW->Memory_PreviousInput_o;

      /* S-Function (read_dict): '<S2>/Read CM Dict2' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict2_PWORK_a.Entry;
        if (!UNICARBrake_DW->ReadCMDict2_IWORK_i.Checked) {
          UNICARBrake_DW->ReadCMDict2_IWORK_i.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict2_l = e->GetFunc(e->Var);
      }

      /* Abs: '<S19>/Abs' incorporates:
       *  Gain: '<S19>/Gain'
       */
      UNICARBrake_B->Abs_c = fabs(UNICARBrake_P.brk_Kslip *
        UNICARBrake_B->ReadCMDict2_l);

      /* S-Function (read_dict): '<S2>/Read CM Dict3' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict3_PWORK_j.Entry;
        if (!UNICARBrake_DW->ReadCMDict3_IWORK_m.Checked) {
          UNICARBrake_DW->ReadCMDict3_IWORK_m.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict3_j = e->GetFunc(e->Var);
      }
    }

    /* Derivative: '<S19>/Derivative' incorporates:
     *  Derivative: '<S9>/Derivative'
     */
    if ((UNICARBrake_DW->TimeStampA_j >= rtb_Switch2_m) &&
        (UNICARBrake_DW->TimeStampB_l >= rtb_Switch2_m)) {
      rtb_Gain_i = 0.0;
    } else {
      rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampA_j;
      lastU = &UNICARBrake_DW->LastUAtTimeA_i;
      if (UNICARBrake_DW->TimeStampA_j < UNICARBrake_DW->TimeStampB_l) {
        if (UNICARBrake_DW->TimeStampB_l < rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB_l;
          lastU = &UNICARBrake_DW->LastUAtTimeB_n;
        }
      } else {
        if (UNICARBrake_DW->TimeStampA_j >= rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB_l;
          lastU = &UNICARBrake_DW->LastUAtTimeB_n;
        }
      }

      rtb_Gain_i = (UNICARBrake_B->ReadCMDict3_j - *lastU) / (rtb_Switch2_m -
        rtb_Switch_m_idx_1);
    }

    /* End of Derivative: '<S19>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S2>/Read CM Dict4' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict4_PWORK_c.Entry;
        if (!UNICARBrake_DW->ReadCMDict4_IWORK_b.Checked) {
          UNICARBrake_DW->ReadCMDict4_IWORK_b.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict4_i = e->GetFunc(e->Var);
      }

      /* Memory: '<S19>/Memory' */
      UNICARBrake_B->Memory_b = UNICARBrake_DW->Memory_PreviousInput_k;
    }

    /* Product: '<S19>/Product1' incorporates:
     *  Constant: '<S19>/Constant3'
     */
    rtb_Gain_i = rtb_Gain_i * UNICARBrake_B->ReadCMDict4_i *
      UNICARBrake_P.brk_Kacc;

    /* Abs: '<S19>/Abs1' */
    rtb_Gain_i = fabs(rtb_Gain_i);

    /* Sum: '<S19>/Sum' */
    rtb_Gain_i += UNICARBrake_B->Abs_c;

    /* If: '<S19>/If2' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant4'
     */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      if ((rtb_Gain_i > UNICARBrake_P.brk_SKup) || (UNICARBrake_B->Memory_b >
           rtb_ABSoff)) {
        rtAction = 0;
      } else if (rtb_Gain_i < UNICARBrake_P.brk_SKlow) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      UNICARBrake_DW->If2_ActiveSubsystem_i = rtAction;
    } else {
      rtAction = UNICARBrake_DW->If2_ActiveSubsystem_i;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S19>/reduce pressure' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      UNICARBrake_reducepressure(&UNICARBrake_B->f_brake_h,
        &UNICARBrake_B->T_Filter_h, &UNICARBrake_P.reducepressure_f,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S19>/reduce pressure' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S19>/free pressure' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      UNICARBrake_freepressure(&UNICARBrake_B->f_brake_h,
        &UNICARBrake_B->T_Filter_h, &UNICARBrake_P.freepressure_j,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S19>/free pressure' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S19>/keep pressure' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      UNICARBrake_keeppressure(&UNICARBrake_B->f_brake_h,
        &UNICARBrake_B->T_Filter_h, &UNICARBrake_P.keeppressure_k,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S19>/keep pressure' */
      break;
    }

    /* End of If: '<S19>/If2' */

    /* Clock: '<S22>/Clock' */
    UNICARBrake_B->Clock_i = rtb_Switch2_m;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Memory: '<S22>/Memory1' */
      UNICARBrake_B->Memory1_a = UNICARBrake_DW->Memory1_PreviousInput_p;
    }

    /* Sum: '<S22>/Sum3' */
    rtb_Gain_i = UNICARBrake_B->Clock_i - UNICARBrake_B->Memory1_a;

    /* Sum: '<S22>/Sum2' incorporates:
     *  Product: '<S19>/Product2'
     *  Product: '<S22>/Product5'
     *  Sum: '<S22>/Sum1'
     *  Sum: '<S22>/Sum4'
     */
    UNICARBrake_B->Sum2_o = (rtb_Switch_m_idx_0 * UNICARBrake_B->f_brake_h -
      UNICARBrake_B->Memory_a) * rtb_Gain_i / (rtb_Gain_i +
      UNICARBrake_B->T_Filter_h) + UNICARBrake_B->Memory_a;

    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S18>/ABS_on_off'
     */
    if (UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_k) {
      UNICARBrake_B->Switch1_h = UNICARBrake_B->Sum2_o;
    } else {
      UNICARBrake_B->Switch1_h = rtb_Switch_m_idx_0;
    }

    /* End of Switch: '<S18>/Switch1' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S17>/Compare'
     */
    UNICARBrake_B->DataTypeConversion_c = (UNICARBrake_B->Switch1_h >=
      UNICARBrake_P.CompareToConstant_const_h);
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S2>/Write CM Dict1' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict1_PWORK_l.Entry;
        if (!UNICARBrake_DW->WriteCMDict1_IWORK_p.Checked) {
          UNICARBrake_DW->WriteCMDict1_IWORK_p.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->DataTypeConversion_c;
        DVA_PokeSL(e, value);
      }
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Gain: '<S2>/Gain'
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_p = 1.0 / UNICARBrake_P.brk_i * UNICARBrake_B->Switch1_h
      + UNICARBrake_U->FromCM.WheelIn.FR.Trq_BrakeReg;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S2>/Write CM Dict2' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict2_PWORK_b.Entry;
        if (!UNICARBrake_DW->WriteCMDict2_IWORK_o.Checked) {
          UNICARBrake_DW->WriteCMDict2_IWORK_o.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_p;
        DVA_PokeSL(e, value);
      }
    }

    /* Switch: '<S20>/Switch1' incorporates:
     *  Inport: '<Root>/FromCM'
     *  RelationalOperator: '<S20>/GreaterThan3'
     */
    if (UNICARBrake_U->FromCM.WheelIn.FR.Trq_BrakeReg_max >=
        UNICARBrake_B->ReadCMDict_b) {
      UNICARBrake_B->Switch1_b = UNICARBrake_B->ReadCMDict_b;
    } else {
      UNICARBrake_B->Switch1_b =
        UNICARBrake_U->FromCM.WheelIn.FR.Trq_BrakeReg_max;
    }

    /* End of Switch: '<S20>/Switch1' */

    /* TransportDelay: '<S21>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_j.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_j.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      real_T tMinusDelay = simTime - UNICARBrake_P.brk_tDel_s;
      UNICARBrake_B->TransportDelay_n = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        UNICARBrake_DW->TransportDelay_IWORK_e.CircularBufSize,
        &UNICARBrake_DW->TransportDelay_IWORK_e.Last,
        UNICARBrake_DW->TransportDelay_IWORK_e.Tail,
        UNICARBrake_DW->TransportDelay_IWORK_e.Head,
        UNICARBrake_P.TransportDelay_InitOutput_h,
        0,
        0);
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S3>/Read CM Dict1' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict1_PWORK_c.Entry;
        if (!UNICARBrake_DW->ReadCMDict1_IWORK_i.Checked) {
          UNICARBrake_DW->ReadCMDict1_IWORK_i.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict1_g = e->GetFunc(e->Var);
      }
    }

    /* TransferFcn: '<S31>/ABS on' */
    rtb_Gain_i = UNICARBrake_P.ABSon_C_e * UNICARBrake_X->ABSon_CSTATE_l;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S3>/Read CM Dict' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict_PWORK_e.Entry;
        if (!UNICARBrake_DW->ReadCMDict_IWORK_f.Checked) {
          UNICARBrake_DW->ReadCMDict_IWORK_f.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict_l = e->GetFunc(e->Var);
      }

      /* Product: '<S31>/Product' incorporates:
       *  Constant: '<S31>/Constant'
       *  Constant: '<S31>/Constant1'
       *  Constant: '<S31>/Constant2'
       */
      UNICARBrake_B->Product_p = UNICARBrake_P.brk_area_m_2 *
        UNICARBrake_P.brk_r_m * UNICARBrake_P.brk_mue;
    }

    /* Gain: '<S30>/Gain' incorporates:
     *  Inport: '<Root>/FromCM'
     *  Product: '<S30>/Product1'
     *  RelationalOperator: '<S30>/GreaterThan2'
     *  Sum: '<S30>/Add1'
     */
    rtb_ABSoff = (real_T)(UNICARBrake_U->FromCM.WheelIn.RL.Trq_BrakeReg_max <
                          UNICARBrake_B->ReadCMDict_l) *
      (UNICARBrake_B->ReadCMDict_l -
       UNICARBrake_U->FromCM.WheelIn.RL.Trq_BrakeReg) * UNICARBrake_P.brk_i;

    /* Product: '<S31>/Divide' */
    rtb_p_trg_k = rtb_ABSoff / UNICARBrake_B->Product_p;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Product: '<S31>/Product2' incorporates:
       *  Constant: '<S31>/Constant3'
       */
      UNICARBrake_B->Product2_i = UNICARBrake_B->Product_p *
        UNICARBrake_P.brk_pMax_pa;
    }

    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S31>/Constant4'
     *  Constant: '<S36>/Constant4'
     *  Product: '<S31>/Product1'
     *  Switch: '<S31>/Switch2'
     */
    if (UNICARBrake_B->ReadCMDict1_g > UNICARBrake_P.Switch_Threshold_b) {
      rtb_Switch_m_idx_0 = UNICARBrake_P.Constant4_Value_g;
      rtb_Switch_m_idx_1 = UNICARBrake_P.Constant4_Value_g;
    } else {
      if (UNICARBrake_P.brk_dyn >= UNICARBrake_P.Switch2_Threshold_c) {
        /* Switch: '<S31>/Switch1' incorporates:
         *  Constant: '<S28>/ABS_on_off'
         *  Switch: '<S31>/Switch2'
         *  TransferFcn: '<S31>/ABS off'
         */
        if (!(UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_n)) {
          rtb_Gain_i = UNICARBrake_P.ABSoff_C_n[0] *
            UNICARBrake_X->ABSoff_CSTATE_c[0] + UNICARBrake_P.ABSoff_C_n[1] *
            UNICARBrake_X->ABSoff_CSTATE_c[1];
        }

        /* End of Switch: '<S31>/Switch1' */
      } else {
        /* Switch: '<S31>/Switch2' */
        rtb_Gain_i = rtb_p_trg_k;
      }

      rtb_Switch_m_idx_0 = rtb_Gain_i * UNICARBrake_B->Product_p;
      rtb_Switch_m_idx_1 = UNICARBrake_B->Product2_i;
    }

    /* End of Switch: '<S36>/Switch' */

    /* Sum: '<S28>/Add' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_n = UNICARBrake_U->FromCM.WheelIn.RL.Trq_BrakeReg_max +
      rtb_Switch_m_idx_1;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S3>/Write CM Dict' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict_PWORK_l.Entry;
        if (!UNICARBrake_DW->WriteCMDict_IWORK_g.Checked) {
          UNICARBrake_DW->WriteCMDict_IWORK_g.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_n;
        DVA_PokeSL(e, value);
      }

      /* Memory: '<S32>/Memory' */
      UNICARBrake_B->Memory_h = UNICARBrake_DW->Memory_PreviousInput_c;

      /* S-Function (read_dict): '<S3>/Read CM Dict2' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict2_PWORK_l.Entry;
        if (!UNICARBrake_DW->ReadCMDict2_IWORK_n.Checked) {
          UNICARBrake_DW->ReadCMDict2_IWORK_n.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict2_f = e->GetFunc(e->Var);
      }

      /* Abs: '<S29>/Abs' incorporates:
       *  Gain: '<S29>/Gain'
       */
      UNICARBrake_B->Abs_h = fabs(UNICARBrake_P.brk_Kslip *
        UNICARBrake_B->ReadCMDict2_f);

      /* S-Function (read_dict): '<S3>/Read CM Dict3' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict3_PWORK_h.Entry;
        if (!UNICARBrake_DW->ReadCMDict3_IWORK_g.Checked) {
          UNICARBrake_DW->ReadCMDict3_IWORK_g.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict3_n = e->GetFunc(e->Var);
      }
    }

    /* Derivative: '<S29>/Derivative' incorporates:
     *  Derivative: '<S9>/Derivative'
     */
    if ((UNICARBrake_DW->TimeStampA_m >= rtb_Switch2_m) &&
        (UNICARBrake_DW->TimeStampB_a >= rtb_Switch2_m)) {
      rtb_Gain_i = 0.0;
    } else {
      rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampA_m;
      lastU = &UNICARBrake_DW->LastUAtTimeA_d;
      if (UNICARBrake_DW->TimeStampA_m < UNICARBrake_DW->TimeStampB_a) {
        if (UNICARBrake_DW->TimeStampB_a < rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB_a;
          lastU = &UNICARBrake_DW->LastUAtTimeB_e;
        }
      } else {
        if (UNICARBrake_DW->TimeStampA_m >= rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB_a;
          lastU = &UNICARBrake_DW->LastUAtTimeB_e;
        }
      }

      rtb_Gain_i = (UNICARBrake_B->ReadCMDict3_n - *lastU) / (rtb_Switch2_m -
        rtb_Switch_m_idx_1);
    }

    /* End of Derivative: '<S29>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S3>/Read CM Dict4' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict4_PWORK_n.Entry;
        if (!UNICARBrake_DW->ReadCMDict4_IWORK_e.Checked) {
          UNICARBrake_DW->ReadCMDict4_IWORK_e.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict4_g = e->GetFunc(e->Var);
      }

      /* Memory: '<S29>/Memory' */
      UNICARBrake_B->Memory_p = UNICARBrake_DW->Memory_PreviousInput_p;
    }

    /* Product: '<S29>/Product1' incorporates:
     *  Constant: '<S29>/Constant3'
     */
    rtb_Gain_i = rtb_Gain_i * UNICARBrake_B->ReadCMDict4_g *
      UNICARBrake_P.brk_Kacc;

    /* Abs: '<S29>/Abs1' */
    rtb_Gain_i = fabs(rtb_Gain_i);

    /* Sum: '<S29>/Sum' */
    rtb_Gain_i += UNICARBrake_B->Abs_h;

    /* If: '<S29>/If2' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant4'
     */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      if ((rtb_Gain_i > UNICARBrake_P.brk_SKup) || (UNICARBrake_B->Memory_p >
           rtb_ABSoff)) {
        rtAction = 0;
      } else if (rtb_Gain_i < UNICARBrake_P.brk_SKlow) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      UNICARBrake_DW->If2_ActiveSubsystem_h = rtAction;
    } else {
      rtAction = UNICARBrake_DW->If2_ActiveSubsystem_h;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S29>/reduce pressure' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      UNICARBrake_reducepressure(&UNICARBrake_B->f_brake_f,
        &UNICARBrake_B->T_Filter_g, &UNICARBrake_P.reducepressure_j,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S29>/reduce pressure' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S29>/free pressure' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      UNICARBrake_freepressure(&UNICARBrake_B->f_brake_f,
        &UNICARBrake_B->T_Filter_g, &UNICARBrake_P.freepressure_c,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S29>/free pressure' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S29>/keep pressure' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      UNICARBrake_keeppressure(&UNICARBrake_B->f_brake_f,
        &UNICARBrake_B->T_Filter_g, &UNICARBrake_P.keeppressure_o,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S29>/keep pressure' */
      break;
    }

    /* End of If: '<S29>/If2' */

    /* Clock: '<S32>/Clock' */
    UNICARBrake_B->Clock_m = rtb_Switch2_m;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Memory: '<S32>/Memory1' */
      UNICARBrake_B->Memory1_j = UNICARBrake_DW->Memory1_PreviousInput_a;
    }

    /* Sum: '<S32>/Sum3' */
    rtb_Gain_i = UNICARBrake_B->Clock_m - UNICARBrake_B->Memory1_j;

    /* Sum: '<S32>/Sum2' incorporates:
     *  Product: '<S29>/Product2'
     *  Product: '<S32>/Product5'
     *  Sum: '<S32>/Sum1'
     *  Sum: '<S32>/Sum4'
     */
    UNICARBrake_B->Sum2_l = (rtb_Switch_m_idx_0 * UNICARBrake_B->f_brake_f -
      UNICARBrake_B->Memory_h) * rtb_Gain_i / (rtb_Gain_i +
      UNICARBrake_B->T_Filter_g) + UNICARBrake_B->Memory_h;

    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S28>/ABS_on_off'
     */
    if (UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_ef) {
      UNICARBrake_B->Switch1_n = UNICARBrake_B->Sum2_l;
    } else {
      UNICARBrake_B->Switch1_n = rtb_Switch_m_idx_0;
    }

    /* End of Switch: '<S28>/Switch1' */

    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  Constant: '<S27>/Constant'
     *  RelationalOperator: '<S27>/Compare'
     */
    UNICARBrake_B->DataTypeConversion_n = (UNICARBrake_B->Switch1_n >=
      UNICARBrake_P.CompareToConstant_const_b);
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S3>/Write CM Dict1' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict1_PWORK_a.Entry;
        if (!UNICARBrake_DW->WriteCMDict1_IWORK_l.Checked) {
          UNICARBrake_DW->WriteCMDict1_IWORK_l.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->DataTypeConversion_n;
        DVA_PokeSL(e, value);
      }
    }

    /* Sum: '<S3>/Add' incorporates:
     *  Gain: '<S3>/Gain'
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_a = 1.0 / UNICARBrake_P.brk_i * UNICARBrake_B->Switch1_n
      + UNICARBrake_U->FromCM.WheelIn.RL.Trq_BrakeReg;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S3>/Write CM Dict2' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict2_PWORK_e.Entry;
        if (!UNICARBrake_DW->WriteCMDict2_IWORK_f.Checked) {
          UNICARBrake_DW->WriteCMDict2_IWORK_f.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_a;
        DVA_PokeSL(e, value);
      }
    }

    /* Switch: '<S30>/Switch1' incorporates:
     *  Inport: '<Root>/FromCM'
     *  RelationalOperator: '<S30>/GreaterThan3'
     */
    if (UNICARBrake_U->FromCM.WheelIn.RL.Trq_BrakeReg_max >=
        UNICARBrake_B->ReadCMDict_l) {
      UNICARBrake_B->Switch1_e = UNICARBrake_B->ReadCMDict_l;
    } else {
      UNICARBrake_B->Switch1_e =
        UNICARBrake_U->FromCM.WheelIn.RL.Trq_BrakeReg_max;
    }

    /* End of Switch: '<S30>/Switch1' */

    /* TransportDelay: '<S31>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_o.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_o.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      real_T tMinusDelay = simTime - UNICARBrake_P.brk_tDel_s;
      UNICARBrake_B->TransportDelay_m = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        UNICARBrake_DW->TransportDelay_IWORK_m.CircularBufSize,
        &UNICARBrake_DW->TransportDelay_IWORK_m.Last,
        UNICARBrake_DW->TransportDelay_IWORK_m.Tail,
        UNICARBrake_DW->TransportDelay_IWORK_m.Head,
        UNICARBrake_P.TransportDelay_InitOutput_k,
        0,
        0);
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S4>/Read CM Dict1' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict1_PWORK_f.Entry;
        if (!UNICARBrake_DW->ReadCMDict1_IWORK_g.Checked) {
          UNICARBrake_DW->ReadCMDict1_IWORK_g.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict1_b = e->GetFunc(e->Var);
      }
    }

    /* TransferFcn: '<S41>/ABS on' */
    rtb_Gain_i = UNICARBrake_P.ABSon_C_ed * UNICARBrake_X->ABSon_CSTATE_o;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S4>/Read CM Dict' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict_PWORK_b.Entry;
        if (!UNICARBrake_DW->ReadCMDict_IWORK_fa.Checked) {
          UNICARBrake_DW->ReadCMDict_IWORK_fa.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict_c = e->GetFunc(e->Var);
      }

      /* Product: '<S41>/Product' incorporates:
       *  Constant: '<S41>/Constant'
       *  Constant: '<S41>/Constant1'
       *  Constant: '<S41>/Constant2'
       */
      UNICARBrake_B->Product_e = UNICARBrake_P.brk_area_m_2 *
        UNICARBrake_P.brk_r_m * UNICARBrake_P.brk_mue;
    }

    /* Gain: '<S40>/Gain' incorporates:
     *  Inport: '<Root>/FromCM'
     *  Product: '<S40>/Product1'
     *  RelationalOperator: '<S40>/GreaterThan2'
     *  Sum: '<S40>/Add1'
     */
    rtb_ABSoff = (real_T)(UNICARBrake_U->FromCM.WheelIn.RR.Trq_BrakeReg_max <
                          UNICARBrake_B->ReadCMDict_c) *
      (UNICARBrake_B->ReadCMDict_c -
       UNICARBrake_U->FromCM.WheelIn.RR.Trq_BrakeReg) * UNICARBrake_P.brk_i;

    /* Product: '<S41>/Divide' */
    rtb_p_trg_h = rtb_ABSoff / UNICARBrake_B->Product_e;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Product: '<S41>/Product2' incorporates:
       *  Constant: '<S41>/Constant3'
       */
      UNICARBrake_B->Product2_g = UNICARBrake_B->Product_e *
        UNICARBrake_P.brk_pMax_pa;
    }

    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S41>/Constant4'
     *  Constant: '<S46>/Constant4'
     *  Product: '<S41>/Product1'
     *  Switch: '<S41>/Switch2'
     */
    if (UNICARBrake_B->ReadCMDict1_b > UNICARBrake_P.Switch_Threshold_a) {
      rtb_Switch_m_idx_0 = UNICARBrake_P.Constant4_Value_k;
      rtb_Switch_m_idx_1 = UNICARBrake_P.Constant4_Value_k;
    } else {
      if (UNICARBrake_P.brk_dyn >= UNICARBrake_P.Switch2_Threshold_m) {
        /* Switch: '<S41>/Switch1' incorporates:
         *  Constant: '<S38>/ABS_on_off'
         *  Switch: '<S41>/Switch2'
         *  TransferFcn: '<S41>/ABS off'
         */
        if (!(UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_e)) {
          rtb_Gain_i = UNICARBrake_P.ABSoff_C_k[0] *
            UNICARBrake_X->ABSoff_CSTATE_p[0] + UNICARBrake_P.ABSoff_C_k[1] *
            UNICARBrake_X->ABSoff_CSTATE_p[1];
        }

        /* End of Switch: '<S41>/Switch1' */
      } else {
        /* Switch: '<S41>/Switch2' */
        rtb_Gain_i = rtb_p_trg_h;
      }

      rtb_Switch_m_idx_0 = rtb_Gain_i * UNICARBrake_B->Product_e;
      rtb_Switch_m_idx_1 = UNICARBrake_B->Product2_g;
    }

    /* End of Switch: '<S46>/Switch' */

    /* Sum: '<S38>/Add' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_au = UNICARBrake_U->FromCM.WheelIn.RR.Trq_BrakeReg_max +
      rtb_Switch_m_idx_1;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S4>/Write CM Dict' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict_PWORK_e.Entry;
        if (!UNICARBrake_DW->WriteCMDict_IWORK_f.Checked) {
          UNICARBrake_DW->WriteCMDict_IWORK_f.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_au;
        DVA_PokeSL(e, value);
      }

      /* Memory: '<S42>/Memory' */
      UNICARBrake_B->Memory_m = UNICARBrake_DW->Memory_PreviousInput_b;

      /* S-Function (read_dict): '<S4>/Read CM Dict2' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict2_PWORK_ay.Entry;
        if (!UNICARBrake_DW->ReadCMDict2_IWORK_l.Checked) {
          UNICARBrake_DW->ReadCMDict2_IWORK_l.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict2_g = e->GetFunc(e->Var);
      }

      /* Abs: '<S39>/Abs' incorporates:
       *  Gain: '<S39>/Gain'
       */
      UNICARBrake_B->Abs_j = fabs(UNICARBrake_P.brk_Kslip *
        UNICARBrake_B->ReadCMDict2_g);

      /* S-Function (read_dict): '<S4>/Read CM Dict3' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict3_PWORK_f.Entry;
        if (!UNICARBrake_DW->ReadCMDict3_IWORK_o.Checked) {
          UNICARBrake_DW->ReadCMDict3_IWORK_o.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict3_f = e->GetFunc(e->Var);
      }
    }

    /* Derivative: '<S39>/Derivative' incorporates:
     *  Derivative: '<S9>/Derivative'
     */
    if ((UNICARBrake_DW->TimeStampA_l >= rtb_Switch2_m) &&
        (UNICARBrake_DW->TimeStampB_l3 >= rtb_Switch2_m)) {
      rtb_Gain_i = 0.0;
    } else {
      rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampA_l;
      lastU = &UNICARBrake_DW->LastUAtTimeA_d1;
      if (UNICARBrake_DW->TimeStampA_l < UNICARBrake_DW->TimeStampB_l3) {
        if (UNICARBrake_DW->TimeStampB_l3 < rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB_l3;
          lastU = &UNICARBrake_DW->LastUAtTimeB_f;
        }
      } else {
        if (UNICARBrake_DW->TimeStampA_l >= rtb_Switch2_m) {
          rtb_Switch_m_idx_1 = UNICARBrake_DW->TimeStampB_l3;
          lastU = &UNICARBrake_DW->LastUAtTimeB_f;
        }
      }

      rtb_Gain_i = (UNICARBrake_B->ReadCMDict3_f - *lastU) / (rtb_Switch2_m -
        rtb_Switch_m_idx_1);
    }

    /* End of Derivative: '<S39>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S4>/Read CM Dict4' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict4_PWORK_d.Entry;
        if (!UNICARBrake_DW->ReadCMDict4_IWORK_c.Checked) {
          UNICARBrake_DW->ReadCMDict4_IWORK_c.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict4_p = e->GetFunc(e->Var);
      }

      /* Memory: '<S39>/Memory' */
      UNICARBrake_B->Memory_f = UNICARBrake_DW->Memory_PreviousInput_h;
    }

    /* Product: '<S39>/Product1' incorporates:
     *  Constant: '<S39>/Constant3'
     */
    rtb_Gain_i = rtb_Gain_i * UNICARBrake_B->ReadCMDict4_p *
      UNICARBrake_P.brk_Kacc;

    /* Abs: '<S39>/Abs1' */
    rtb_Gain_i = fabs(rtb_Gain_i);

    /* Sum: '<S39>/Sum' */
    rtb_Gain_i += UNICARBrake_B->Abs_j;

    /* If: '<S39>/If2' incorporates:
     *  Constant: '<S39>/Constant1'
     *  Constant: '<S39>/Constant4'
     */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      if ((rtb_Gain_i > UNICARBrake_P.brk_SKup) || (UNICARBrake_B->Memory_f >
           rtb_ABSoff)) {
        rtAction = 0;
      } else if (rtb_Gain_i < UNICARBrake_P.brk_SKlow) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      UNICARBrake_DW->If2_ActiveSubsystem_e = rtAction;
    } else {
      rtAction = UNICARBrake_DW->If2_ActiveSubsystem_e;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S39>/reduce pressure' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      UNICARBrake_reducepressure(&UNICARBrake_B->f_brake_m,
        &UNICARBrake_B->T_Filter_hd, &UNICARBrake_P.reducepressure_a,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S39>/reduce pressure' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S39>/free pressure' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      UNICARBrake_freepressure(&UNICARBrake_B->f_brake_m,
        &UNICARBrake_B->T_Filter_hd, &UNICARBrake_P.freepressure_i,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S39>/free pressure' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S39>/keep pressure' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      UNICARBrake_keeppressure(&UNICARBrake_B->f_brake_m,
        &UNICARBrake_B->T_Filter_hd, &UNICARBrake_P.keeppressure_j,
        &UNICARBrake_P);

      /* End of Outputs for SubSystem: '<S39>/keep pressure' */
      break;
    }

    /* End of If: '<S39>/If2' */

    /* Clock: '<S42>/Clock' */
    UNICARBrake_B->Clock_e = rtb_Switch2_m;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Memory: '<S42>/Memory1' */
      UNICARBrake_B->Memory1_p = UNICARBrake_DW->Memory1_PreviousInput_o;
    }

    /* Sum: '<S42>/Sum3' */
    rtb_Gain_i = UNICARBrake_B->Clock_e - UNICARBrake_B->Memory1_p;

    /* Sum: '<S42>/Sum2' incorporates:
     *  Product: '<S39>/Product2'
     *  Product: '<S42>/Product5'
     *  Sum: '<S42>/Sum1'
     *  Sum: '<S42>/Sum4'
     */
    UNICARBrake_B->Sum2_c = (rtb_Switch_m_idx_0 * UNICARBrake_B->f_brake_m -
      UNICARBrake_B->Memory_m) * rtb_Gain_i / (rtb_Gain_i +
      UNICARBrake_B->T_Filter_hd) + UNICARBrake_B->Memory_m;

    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/ABS_on_off'
     */
    if (UNICARBrake_P.brk_ABS >= UNICARBrake_P.Switch1_Threshold_kn) {
      UNICARBrake_B->Switch1_f = UNICARBrake_B->Sum2_c;
    } else {
      UNICARBrake_B->Switch1_f = rtb_Switch_m_idx_0;
    }

    /* End of Switch: '<S38>/Switch1' */

    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S37>/Constant'
     *  RelationalOperator: '<S37>/Compare'
     */
    UNICARBrake_B->DataTypeConversion_c0 = (UNICARBrake_B->Switch1_f >=
      UNICARBrake_P.CompareToConstant_const_i);
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S4>/Write CM Dict1' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict1_PWORK_n.Entry;
        if (!UNICARBrake_DW->WriteCMDict1_IWORK_f.Checked) {
          UNICARBrake_DW->WriteCMDict1_IWORK_f.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->DataTypeConversion_c0;
        DVA_PokeSL(e, value);
      }
    }

    /* Sum: '<S4>/Add' incorporates:
     *  Gain: '<S4>/Gain'
     *  Inport: '<Root>/FromCM'
     */
    UNICARBrake_B->Add_l = 1.0 / UNICARBrake_P.brk_i * UNICARBrake_B->Switch1_f
      + UNICARBrake_U->FromCM.WheelIn.RR.Trq_BrakeReg;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (write_dict): '<S4>/Write CM Dict2' */
      {
        tDDictEntry *e;
        real_T value;
        e = (tDDictEntry *)UNICARBrake_DW->WriteCMDict2_PWORK_l.Entry;
        if (!UNICARBrake_DW->WriteCMDict2_IWORK_k.Checked) {
          UNICARBrake_DW->WriteCMDict2_IWORK_k.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        value = UNICARBrake_B->Add_l;
        DVA_PokeSL(e, value);
      }
    }

    /* Switch: '<S40>/Switch1' incorporates:
     *  Inport: '<Root>/FromCM'
     *  RelationalOperator: '<S40>/GreaterThan3'
     */
    if (UNICARBrake_U->FromCM.WheelIn.RR.Trq_BrakeReg_max >=
        UNICARBrake_B->ReadCMDict_c) {
      UNICARBrake_B->Switch1_j = UNICARBrake_B->ReadCMDict_c;
    } else {
      UNICARBrake_B->Switch1_j =
        UNICARBrake_U->FromCM.WheelIn.RR.Trq_BrakeReg_max;
    }

    /* End of Switch: '<S40>/Switch1' */

    /* TransportDelay: '<S41>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_c.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_c.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      real_T tMinusDelay = simTime - UNICARBrake_P.brk_tDel_s;
      UNICARBrake_B->TransportDelay_f = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        UNICARBrake_DW->TransportDelay_IWORK_i.CircularBufSize,
        &UNICARBrake_DW->TransportDelay_IWORK_i.Last,
        UNICARBrake_DW->TransportDelay_IWORK_i.Tail,
        UNICARBrake_DW->TransportDelay_IWORK_i.Head,
        UNICARBrake_P.TransportDelay_InitOutput_l,
        0,
        0);
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* S-Function (read_dict): '<S6>/Read CM Dict' */
      {
        tDDictEntry *e;
        e = (tDDictEntry *)UNICARBrake_DW->ReadCMDict_PWORK_p.Entry;
        if (!UNICARBrake_DW->ReadCMDict_IWORK_n.Checked) {
          UNICARBrake_DW->ReadCMDict_IWORK_n.Checked = 1;
          DDictErrorUponFakedEntry(e, "Model 'UNICARBrake'");
        }

        UNICARBrake_B->ReadCMDict_f = e->GetFunc(e->Var);
      }

      /* Switch: '<S6>/Switch' */
      if (UNICARBrake_B->ReadCMDict_f > UNICARBrake_P.Switch_Threshold_f) {
        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant3'
         */
        UNICARBrake_Y->ToCM.WheelOut.FL.Trq_PB = UNICARBrake_P.brk_parking_trq[0];

        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant3'
         */
        UNICARBrake_Y->ToCM.WheelOut.FR.Trq_PB = UNICARBrake_P.brk_parking_trq[1];

        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant3'
         */
        UNICARBrake_Y->ToCM.WheelOut.RL.Trq_PB = UNICARBrake_P.brk_parking_trq[2];

        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant3'
         */
        UNICARBrake_Y->ToCM.WheelOut.RR.Trq_PB = UNICARBrake_P.brk_parking_trq[3];
      } else {
        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant'
         */
        UNICARBrake_Y->ToCM.WheelOut.FL.Trq_PB = UNICARBrake_P.Constant_Value[0];

        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant'
         */
        UNICARBrake_Y->ToCM.WheelOut.FR.Trq_PB = UNICARBrake_P.Constant_Value[1];

        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant'
         */
        UNICARBrake_Y->ToCM.WheelOut.RL.Trq_PB = UNICARBrake_P.Constant_Value[2];

        /* BusCreator generated from: '<Root>/ToCM' incorporates:
         *  Constant: '<S6>/Constant'
         */
        UNICARBrake_Y->ToCM.WheelOut.RR.Trq_PB = UNICARBrake_P.Constant_Value[3];
      }

      /* End of Switch: '<S6>/Switch' */

      /* BusCreator generated from: '<Root>/ToCM' */
      UNICARBrake_Y->ToCM.WheelOut.FL.Trq_WB = UNICARBrake_B->Switch1;
      UNICARBrake_Y->ToCM.WheelOut.FL.Trq_BrakeReg_trg = UNICARBrake_B->Switch;

      /* BusCreator generated from: '<Root>/ToCM' */
      UNICARBrake_Y->ToCM.WheelOut.FR.Trq_WB = UNICARBrake_B->Switch1_h;
      UNICARBrake_Y->ToCM.WheelOut.FR.Trq_BrakeReg_trg =
        UNICARBrake_B->Switch1_b;

      /* BusCreator generated from: '<Root>/ToCM' */
      UNICARBrake_Y->ToCM.WheelOut.RL.Trq_WB = UNICARBrake_B->Switch1_n;
      UNICARBrake_Y->ToCM.WheelOut.RL.Trq_BrakeReg_trg =
        UNICARBrake_B->Switch1_e;

      /* BusCreator generated from: '<Root>/ToCM' */
      UNICARBrake_Y->ToCM.WheelOut.RR.Trq_WB = UNICARBrake_B->Switch1_f;
      UNICARBrake_Y->ToCM.WheelOut.RR.Trq_BrakeReg_trg =
        UNICARBrake_B->Switch1_j;

      /* BusCreator generated from: '<Root>/ToCM' incorporates:
       *  Constant: '<S5>/Trq_DriveSrc_trg.d0'
       *  Constant: '<S5>/Trq_DriveSrc_trg.d1'
       *  Constant: '<S5>/Trq_DriveSrc_trg.d2'
       *  Constant: '<S5>/Trq_DriveSrc_trg.d3'
       */
      UNICARBrake_Y->ToCM.Trq_DriveSrc_trg.d0 =
        UNICARBrake_P.Trq_DriveSrc_trgd0_Value;
      UNICARBrake_Y->ToCM.Trq_DriveSrc_trg.d1 =
        UNICARBrake_P.Trq_DriveSrc_trgd1_Value;
      UNICARBrake_Y->ToCM.Trq_DriveSrc_trg.d2 =
        UNICARBrake_P.Trq_DriveSrc_trgd2_Value;
      UNICARBrake_Y->ToCM.Trq_DriveSrc_trg.d3 =
        UNICARBrake_P.Trq_DriveSrc_trgd3_Value;
    }
  }

  if (rtmIsMajorTimeStep(UNICARBrake_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S12>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput = UNICARBrake_B->Sum2;
    }

    /* Update for Derivative: '<S9>/Derivative' */
    if (UNICARBrake_DW->TimeStampA == (rtInf)) {
      UNICARBrake_DW->TimeStampA = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA;
    } else if (UNICARBrake_DW->TimeStampB == (rtInf)) {
      UNICARBrake_DW->TimeStampB = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB;
    } else if (UNICARBrake_DW->TimeStampA < UNICARBrake_DW->TimeStampB) {
      UNICARBrake_DW->TimeStampA = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA;
    } else {
      UNICARBrake_DW->TimeStampB = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB;
    }

    *lastU = UNICARBrake_B->ReadCMDict3;

    /* End of Update for Derivative: '<S9>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S9>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_f = UNICARBrake_B->Sum2;

      /* Update for Memory: '<S12>/Memory1' */
      UNICARBrake_DW->Memory1_PreviousInput = UNICARBrake_B->Clock;
    }

    /* Update for TransportDelay: '<S11>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      boolean_T bufferisfull = false;
      UNICARBrake_DW->TransportDelay_IWORK.Head =
        ((UNICARBrake_DW->TransportDelay_IWORK.Head <
          (UNICARBrake_DW->TransportDelay_IWORK.CircularBufSize-1)) ?
         (UNICARBrake_DW->TransportDelay_IWORK.Head+1) : 0);
      if (UNICARBrake_DW->TransportDelay_IWORK.Head ==
          UNICARBrake_DW->TransportDelay_IWORK.Tail) {
        bufferisfull = true;
        UNICARBrake_DW->TransportDelay_IWORK.Tail =
          ((UNICARBrake_DW->TransportDelay_IWORK.Tail <
            (UNICARBrake_DW->TransportDelay_IWORK.CircularBufSize-1)) ?
           (UNICARBrake_DW->TransportDelay_IWORK.Tail+1) : 0);
      }

      (*tBuffer)[UNICARBrake_DW->TransportDelay_IWORK.Head] = simTime;
      (*uBuffer)[UNICARBrake_DW->TransportDelay_IWORK.Head] = rtb_p_trg;
      if (bufferisfull) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(UNICARBrake_M->solverInfo,
          true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (UNICARBrake_M->solverInfo, true);
      }
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S22>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_o = UNICARBrake_B->Sum2_o;
    }

    /* Update for Derivative: '<S19>/Derivative' */
    if (UNICARBrake_DW->TimeStampA_j == (rtInf)) {
      UNICARBrake_DW->TimeStampA_j = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA_i;
    } else if (UNICARBrake_DW->TimeStampB_l == (rtInf)) {
      UNICARBrake_DW->TimeStampB_l = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB_n;
    } else if (UNICARBrake_DW->TimeStampA_j < UNICARBrake_DW->TimeStampB_l) {
      UNICARBrake_DW->TimeStampA_j = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA_i;
    } else {
      UNICARBrake_DW->TimeStampB_l = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB_n;
    }

    *lastU = UNICARBrake_B->ReadCMDict3_j;

    /* End of Update for Derivative: '<S19>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S19>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_k = UNICARBrake_B->Sum2_o;

      /* Update for Memory: '<S22>/Memory1' */
      UNICARBrake_DW->Memory1_PreviousInput_p = UNICARBrake_B->Clock_i;
    }

    /* Update for TransportDelay: '<S21>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_j.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_j.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      boolean_T bufferisfull = false;
      UNICARBrake_DW->TransportDelay_IWORK_e.Head =
        ((UNICARBrake_DW->TransportDelay_IWORK_e.Head <
          (UNICARBrake_DW->TransportDelay_IWORK_e.CircularBufSize-1)) ?
         (UNICARBrake_DW->TransportDelay_IWORK_e.Head+1) : 0);
      if (UNICARBrake_DW->TransportDelay_IWORK_e.Head ==
          UNICARBrake_DW->TransportDelay_IWORK_e.Tail) {
        bufferisfull = true;
        UNICARBrake_DW->TransportDelay_IWORK_e.Tail =
          ((UNICARBrake_DW->TransportDelay_IWORK_e.Tail <
            (UNICARBrake_DW->TransportDelay_IWORK_e.CircularBufSize-1)) ?
           (UNICARBrake_DW->TransportDelay_IWORK_e.Tail+1) : 0);
      }

      (*tBuffer)[UNICARBrake_DW->TransportDelay_IWORK_e.Head] = simTime;
      (*uBuffer)[UNICARBrake_DW->TransportDelay_IWORK_e.Head] = rtb_p_trg_o;
      if (bufferisfull) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(UNICARBrake_M->solverInfo,
          true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (UNICARBrake_M->solverInfo, true);
      }
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S32>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_c = UNICARBrake_B->Sum2_l;
    }

    /* Update for Derivative: '<S29>/Derivative' */
    if (UNICARBrake_DW->TimeStampA_m == (rtInf)) {
      UNICARBrake_DW->TimeStampA_m = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA_d;
    } else if (UNICARBrake_DW->TimeStampB_a == (rtInf)) {
      UNICARBrake_DW->TimeStampB_a = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB_e;
    } else if (UNICARBrake_DW->TimeStampA_m < UNICARBrake_DW->TimeStampB_a) {
      UNICARBrake_DW->TimeStampA_m = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA_d;
    } else {
      UNICARBrake_DW->TimeStampB_a = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB_e;
    }

    *lastU = UNICARBrake_B->ReadCMDict3_n;

    /* End of Update for Derivative: '<S29>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S29>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_p = UNICARBrake_B->Sum2_l;

      /* Update for Memory: '<S32>/Memory1' */
      UNICARBrake_DW->Memory1_PreviousInput_a = UNICARBrake_B->Clock_m;
    }

    /* Update for TransportDelay: '<S31>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_o.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_o.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      boolean_T bufferisfull = false;
      UNICARBrake_DW->TransportDelay_IWORK_m.Head =
        ((UNICARBrake_DW->TransportDelay_IWORK_m.Head <
          (UNICARBrake_DW->TransportDelay_IWORK_m.CircularBufSize-1)) ?
         (UNICARBrake_DW->TransportDelay_IWORK_m.Head+1) : 0);
      if (UNICARBrake_DW->TransportDelay_IWORK_m.Head ==
          UNICARBrake_DW->TransportDelay_IWORK_m.Tail) {
        bufferisfull = true;
        UNICARBrake_DW->TransportDelay_IWORK_m.Tail =
          ((UNICARBrake_DW->TransportDelay_IWORK_m.Tail <
            (UNICARBrake_DW->TransportDelay_IWORK_m.CircularBufSize-1)) ?
           (UNICARBrake_DW->TransportDelay_IWORK_m.Tail+1) : 0);
      }

      (*tBuffer)[UNICARBrake_DW->TransportDelay_IWORK_m.Head] = simTime;
      (*uBuffer)[UNICARBrake_DW->TransportDelay_IWORK_m.Head] = rtb_p_trg_k;
      if (bufferisfull) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(UNICARBrake_M->solverInfo,
          true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (UNICARBrake_M->solverInfo, true);
      }
    }

    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S42>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_b = UNICARBrake_B->Sum2_c;
    }

    /* Update for Derivative: '<S39>/Derivative' */
    if (UNICARBrake_DW->TimeStampA_l == (rtInf)) {
      UNICARBrake_DW->TimeStampA_l = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA_d1;
    } else if (UNICARBrake_DW->TimeStampB_l3 == (rtInf)) {
      UNICARBrake_DW->TimeStampB_l3 = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB_f;
    } else if (UNICARBrake_DW->TimeStampA_l < UNICARBrake_DW->TimeStampB_l3) {
      UNICARBrake_DW->TimeStampA_l = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeA_d1;
    } else {
      UNICARBrake_DW->TimeStampB_l3 = UNICARBrake_M->Timing.t[0];
      lastU = &UNICARBrake_DW->LastUAtTimeB_f;
    }

    *lastU = UNICARBrake_B->ReadCMDict3_f;

    /* End of Update for Derivative: '<S39>/Derivative' */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      /* Update for Memory: '<S39>/Memory' */
      UNICARBrake_DW->Memory_PreviousInput_h = UNICARBrake_B->Sum2_c;

      /* Update for Memory: '<S42>/Memory1' */
      UNICARBrake_DW->Memory1_PreviousInput_o = UNICARBrake_B->Clock_e;
    }

    /* Update for TransportDelay: '<S41>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_c.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &UNICARBrake_DW->TransportDelay_PWORK_c.TUbufferPtrs[1];
      real_T simTime = UNICARBrake_M->Timing.t[0];
      boolean_T bufferisfull = false;
      UNICARBrake_DW->TransportDelay_IWORK_i.Head =
        ((UNICARBrake_DW->TransportDelay_IWORK_i.Head <
          (UNICARBrake_DW->TransportDelay_IWORK_i.CircularBufSize-1)) ?
         (UNICARBrake_DW->TransportDelay_IWORK_i.Head+1) : 0);
      if (UNICARBrake_DW->TransportDelay_IWORK_i.Head ==
          UNICARBrake_DW->TransportDelay_IWORK_i.Tail) {
        bufferisfull = true;
        UNICARBrake_DW->TransportDelay_IWORK_i.Tail =
          ((UNICARBrake_DW->TransportDelay_IWORK_i.Tail <
            (UNICARBrake_DW->TransportDelay_IWORK_i.CircularBufSize-1)) ?
           (UNICARBrake_DW->TransportDelay_IWORK_i.Tail+1) : 0);
      }

      (*tBuffer)[UNICARBrake_DW->TransportDelay_IWORK_i.Head] = simTime;
      (*uBuffer)[UNICARBrake_DW->TransportDelay_IWORK_i.Head] = rtb_p_trg_h;
      if (bufferisfull) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(UNICARBrake_M->solverInfo,
          true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (UNICARBrake_M->solverInfo, true);
      }
    }

    /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
    if (rtmIsMajorTimeStep(UNICARBrake_M)) {
      if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
          (UNICARBrake_M->solverInfo)) {
        rtsiSetSimTimeStep(UNICARBrake_M->solverInfo,MINOR_TIME_STEP);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (UNICARBrake_M->solverInfo, false);
        UNICARBrake_step(UNICARBrake_M);
        rtsiSetSimTimeStep(UNICARBrake_M->solverInfo, MAJOR_TIME_STEP);
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(UNICARBrake_M)) {
    rt_ertODEUpdateContinuousStates(UNICARBrake_M->solverInfo, UNICARBrake_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++UNICARBrake_M->Timing.clockTick0)) {
      ++UNICARBrake_M->Timing.clockTickH0;
    }

    UNICARBrake_M->Timing.t[0] = rtsiGetSolverStopTime(UNICARBrake_M->solverInfo);

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
      UNICARBrake_M->Timing.clockTick1++;
      if (!UNICARBrake_M->Timing.clockTick1) {
        UNICARBrake_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void UNICARBrake_derivatives(RT_MODEL_UNICARBrake_T *const UNICARBrake_M)
{
  B_UNICARBrake_T *UNICARBrake_B = ((B_UNICARBrake_T *) UNICARBrake_M->blockIO);
  X_UNICARBrake_T *UNICARBrake_X = ((X_UNICARBrake_T *)
    UNICARBrake_M->contStates);
  XDot_UNICARBrake_T *_rtXdot;
  _rtXdot = ((XDot_UNICARBrake_T *) UNICARBrake_M->derivs);

  /* Derivatives for TransferFcn: '<S11>/ABS on' */
  _rtXdot->ABSon_CSTATE = 0.0;
  _rtXdot->ABSon_CSTATE += UNICARBrake_P.ABSon_A * UNICARBrake_X->ABSon_CSTATE;
  _rtXdot->ABSon_CSTATE += UNICARBrake_B->TransportDelay;

  /* Derivatives for TransferFcn: '<S11>/ABS off' */
  _rtXdot->ABSoff_CSTATE[0] = 0.0;
  _rtXdot->ABSoff_CSTATE[0] += UNICARBrake_P.ABSoff_A[0] *
    UNICARBrake_X->ABSoff_CSTATE[0];
  _rtXdot->ABSoff_CSTATE[1] = 0.0;
  _rtXdot->ABSoff_CSTATE[0] += UNICARBrake_P.ABSoff_A[1] *
    UNICARBrake_X->ABSoff_CSTATE[1];
  _rtXdot->ABSoff_CSTATE[1] += UNICARBrake_X->ABSoff_CSTATE[0];
  _rtXdot->ABSoff_CSTATE[0] += UNICARBrake_B->TransportDelay;

  /* Derivatives for TransferFcn: '<S21>/ABS on' */
  _rtXdot->ABSon_CSTATE_d = 0.0;
  _rtXdot->ABSon_CSTATE_d += UNICARBrake_P.ABSon_A_h *
    UNICARBrake_X->ABSon_CSTATE_d;
  _rtXdot->ABSon_CSTATE_d += UNICARBrake_B->TransportDelay_n;

  /* Derivatives for TransferFcn: '<S21>/ABS off' */
  _rtXdot->ABSoff_CSTATE_o[0] = 0.0;
  _rtXdot->ABSoff_CSTATE_o[0] += UNICARBrake_P.ABSoff_A_l[0] *
    UNICARBrake_X->ABSoff_CSTATE_o[0];
  _rtXdot->ABSoff_CSTATE_o[1] = 0.0;
  _rtXdot->ABSoff_CSTATE_o[0] += UNICARBrake_P.ABSoff_A_l[1] *
    UNICARBrake_X->ABSoff_CSTATE_o[1];
  _rtXdot->ABSoff_CSTATE_o[1] += UNICARBrake_X->ABSoff_CSTATE_o[0];
  _rtXdot->ABSoff_CSTATE_o[0] += UNICARBrake_B->TransportDelay_n;

  /* Derivatives for TransferFcn: '<S31>/ABS on' */
  _rtXdot->ABSon_CSTATE_l = 0.0;
  _rtXdot->ABSon_CSTATE_l += UNICARBrake_P.ABSon_A_c *
    UNICARBrake_X->ABSon_CSTATE_l;
  _rtXdot->ABSon_CSTATE_l += UNICARBrake_B->TransportDelay_m;

  /* Derivatives for TransferFcn: '<S31>/ABS off' */
  _rtXdot->ABSoff_CSTATE_c[0] = 0.0;
  _rtXdot->ABSoff_CSTATE_c[0] += UNICARBrake_P.ABSoff_A_j[0] *
    UNICARBrake_X->ABSoff_CSTATE_c[0];
  _rtXdot->ABSoff_CSTATE_c[1] = 0.0;
  _rtXdot->ABSoff_CSTATE_c[0] += UNICARBrake_P.ABSoff_A_j[1] *
    UNICARBrake_X->ABSoff_CSTATE_c[1];
  _rtXdot->ABSoff_CSTATE_c[1] += UNICARBrake_X->ABSoff_CSTATE_c[0];
  _rtXdot->ABSoff_CSTATE_c[0] += UNICARBrake_B->TransportDelay_m;

  /* Derivatives for TransferFcn: '<S41>/ABS on' */
  _rtXdot->ABSon_CSTATE_o = 0.0;
  _rtXdot->ABSon_CSTATE_o += UNICARBrake_P.ABSon_A_m *
    UNICARBrake_X->ABSon_CSTATE_o;
  _rtXdot->ABSon_CSTATE_o += UNICARBrake_B->TransportDelay_f;

  /* Derivatives for TransferFcn: '<S41>/ABS off' */
  _rtXdot->ABSoff_CSTATE_p[0] = 0.0;
  _rtXdot->ABSoff_CSTATE_p[0] += UNICARBrake_P.ABSoff_A_h[0] *
    UNICARBrake_X->ABSoff_CSTATE_p[0];
  _rtXdot->ABSoff_CSTATE_p[1] = 0.0;
  _rtXdot->ABSoff_CSTATE_p[0] += UNICARBrake_P.ABSoff_A_h[1] *
    UNICARBrake_X->ABSoff_CSTATE_p[1];
  _rtXdot->ABSoff_CSTATE_p[1] += UNICARBrake_X->ABSoff_CSTATE_p[0];
  _rtXdot->ABSoff_CSTATE_p[0] += UNICARBrake_B->TransportDelay_f;
}

/* Model initialize function */
void UNICARBrake_initialize(RT_MODEL_UNICARBrake_T *const UNICARBrake_M)
{
  DW_UNICARBrake_T *UNICARBrake_DW = ((DW_UNICARBrake_T *) UNICARBrake_M->dwork);
  X_UNICARBrake_T *UNICARBrake_X = ((X_UNICARBrake_T *)
    UNICARBrake_M->contStates);

  /* Start for S-Function (read_dict): '<S1>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.ErrBit.FL", NULL);
    UNICARBrake_DW->ReadCMDict1_IWORK.Checked = 0;
    UNICARBrake_DW->ReadCMDict1_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S1>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.setpoint_Trq.FL", NULL);
    UNICARBrake_DW->ReadCMDict_IWORK.Checked = 0;
    UNICARBrake_DW->ReadCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S1>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.TrqMax.FL", NULL);
    UNICARBrake_DW->WriteCMDict_IWORK.Checked = 0;
    UNICARBrake_DW->WriteCMDict_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S1>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("Car.LongSlipFL", NULL);
    UNICARBrake_DW->ReadCMDict2_IWORK.Checked = 0;
    UNICARBrake_DW->ReadCMDict2_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S1>/Read CM Dict3' */
  {
    char **namevec = CM_Names2StrVec("Car.WheelSpd_FL", NULL);
    UNICARBrake_DW->ReadCMDict3_IWORK.Checked = 0;
    UNICARBrake_DW->ReadCMDict3_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S1>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Car.WFL.Radius", NULL);
    UNICARBrake_DW->ReadCMDict4_IWORK.Checked = 0;
    UNICARBrake_DW->ReadCMDict4_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for If: '<S9>/If2' */
  UNICARBrake_DW->If2_ActiveSubsystem = -1;

  /* Start for S-Function (write_dict): '<S1>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.BrakeActive.FL", NULL);
    UNICARBrake_DW->WriteCMDict1_IWORK.Checked = 0;
    UNICARBrake_DW->WriteCMDict1_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S1>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.Trq.FL", NULL);
    UNICARBrake_DW->WriteCMDict2_IWORK.Checked = 0;
    UNICARBrake_DW->WriteCMDict2_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for TransportDelay: '<S11>/Transport Delay' */
  {
    real_T *pBuffer = &UNICARBrake_DW->TransportDelay_RWORK.TUbufferArea[0];
    UNICARBrake_DW->TransportDelay_IWORK.Tail = 0;
    UNICARBrake_DW->TransportDelay_IWORK.Head = 0;
    UNICARBrake_DW->TransportDelay_IWORK.Last = 0;
    UNICARBrake_DW->TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = UNICARBrake_P.TransportDelay_InitOutput;
    pBuffer[1024] = UNICARBrake_M->Timing.t[0];
    UNICARBrake_DW->TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    UNICARBrake_DW->TransportDelay_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [1024];
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.ErrBit.FR", NULL);
    UNICARBrake_DW->ReadCMDict1_IWORK_e.Checked = 0;
    UNICARBrake_DW->ReadCMDict1_PWORK_m.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.setpoint_Trq.FR", NULL);
    UNICARBrake_DW->ReadCMDict_IWORK_k.Checked = 0;
    UNICARBrake_DW->ReadCMDict_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.TrqMax.FR", NULL);
    UNICARBrake_DW->WriteCMDict_IWORK_n.Checked = 0;
    UNICARBrake_DW->WriteCMDict_PWORK_b.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("Car.LongSlipFR", NULL);
    UNICARBrake_DW->ReadCMDict2_IWORK_i.Checked = 0;
    UNICARBrake_DW->ReadCMDict2_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict3' */
  {
    char **namevec = CM_Names2StrVec("Car.WheelSpd_FR", NULL);
    UNICARBrake_DW->ReadCMDict3_IWORK_m.Checked = 0;
    UNICARBrake_DW->ReadCMDict3_PWORK_j.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S2>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Car.WFR.Radius", NULL);
    UNICARBrake_DW->ReadCMDict4_IWORK_b.Checked = 0;
    UNICARBrake_DW->ReadCMDict4_PWORK_c.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for If: '<S19>/If2' */
  UNICARBrake_DW->If2_ActiveSubsystem_i = -1;

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.BrakeActive.FR", NULL);
    UNICARBrake_DW->WriteCMDict1_IWORK_p.Checked = 0;
    UNICARBrake_DW->WriteCMDict1_PWORK_l.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S2>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.Trq.FR", NULL);
    UNICARBrake_DW->WriteCMDict2_IWORK_o.Checked = 0;
    UNICARBrake_DW->WriteCMDict2_PWORK_b.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for TransportDelay: '<S21>/Transport Delay' */
  {
    real_T *pBuffer = &UNICARBrake_DW->TransportDelay_RWORK_g.TUbufferArea[0];
    UNICARBrake_DW->TransportDelay_IWORK_e.Tail = 0;
    UNICARBrake_DW->TransportDelay_IWORK_e.Head = 0;
    UNICARBrake_DW->TransportDelay_IWORK_e.Last = 0;
    UNICARBrake_DW->TransportDelay_IWORK_e.CircularBufSize = 1024;
    pBuffer[0] = UNICARBrake_P.TransportDelay_InitOutput_h;
    pBuffer[1024] = UNICARBrake_M->Timing.t[0];
    UNICARBrake_DW->TransportDelay_PWORK_j.TUbufferPtrs[0] = (void *) &pBuffer[0];
    UNICARBrake_DW->TransportDelay_PWORK_j.TUbufferPtrs[1] = (void *) &pBuffer
      [1024];
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.ErrBit.RL", NULL);
    UNICARBrake_DW->ReadCMDict1_IWORK_i.Checked = 0;
    UNICARBrake_DW->ReadCMDict1_PWORK_c.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.setpoint_Trq.RL", NULL);
    UNICARBrake_DW->ReadCMDict_IWORK_f.Checked = 0;
    UNICARBrake_DW->ReadCMDict_PWORK_e.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.TrqMax.RL", NULL);
    UNICARBrake_DW->WriteCMDict_IWORK_g.Checked = 0;
    UNICARBrake_DW->WriteCMDict_PWORK_l.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("Car.LongSlipRL", NULL);
    UNICARBrake_DW->ReadCMDict2_IWORK_n.Checked = 0;
    UNICARBrake_DW->ReadCMDict2_PWORK_l.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict3' */
  {
    char **namevec = CM_Names2StrVec("Car.WheelSpd_RL", NULL);
    UNICARBrake_DW->ReadCMDict3_IWORK_g.Checked = 0;
    UNICARBrake_DW->ReadCMDict3_PWORK_h.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S3>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Car.WRL.Radius", NULL);
    UNICARBrake_DW->ReadCMDict4_IWORK_e.Checked = 0;
    UNICARBrake_DW->ReadCMDict4_PWORK_n.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for If: '<S29>/If2' */
  UNICARBrake_DW->If2_ActiveSubsystem_h = -1;

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.BrakeActive.RL", NULL);
    UNICARBrake_DW->WriteCMDict1_IWORK_l.Checked = 0;
    UNICARBrake_DW->WriteCMDict1_PWORK_a.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.Trq.RL", NULL);
    UNICARBrake_DW->WriteCMDict2_IWORK_f.Checked = 0;
    UNICARBrake_DW->WriteCMDict2_PWORK_e.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for TransportDelay: '<S31>/Transport Delay' */
  {
    real_T *pBuffer = &UNICARBrake_DW->TransportDelay_RWORK_i.TUbufferArea[0];
    UNICARBrake_DW->TransportDelay_IWORK_m.Tail = 0;
    UNICARBrake_DW->TransportDelay_IWORK_m.Head = 0;
    UNICARBrake_DW->TransportDelay_IWORK_m.Last = 0;
    UNICARBrake_DW->TransportDelay_IWORK_m.CircularBufSize = 1024;
    pBuffer[0] = UNICARBrake_P.TransportDelay_InitOutput_k;
    pBuffer[1024] = UNICARBrake_M->Timing.t[0];
    UNICARBrake_DW->TransportDelay_PWORK_o.TUbufferPtrs[0] = (void *) &pBuffer[0];
    UNICARBrake_DW->TransportDelay_PWORK_o.TUbufferPtrs[1] = (void *) &pBuffer
      [1024];
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.ErrBit.RR", NULL);
    UNICARBrake_DW->ReadCMDict1_IWORK_g.Checked = 0;
    UNICARBrake_DW->ReadCMDict1_PWORK_f.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.setpoint_Trq.RR", NULL);
    UNICARBrake_DW->ReadCMDict_IWORK_fa.Checked = 0;
    UNICARBrake_DW->ReadCMDict_PWORK_b.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.TrqMax.RR", NULL);
    UNICARBrake_DW->WriteCMDict_IWORK_f.Checked = 0;
    UNICARBrake_DW->WriteCMDict_PWORK_e.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("Car.LongSlipRR", NULL);
    UNICARBrake_DW->ReadCMDict2_IWORK_l.Checked = 0;
    UNICARBrake_DW->ReadCMDict2_PWORK_ay.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict3' */
  {
    char **namevec = CM_Names2StrVec("Car.WheelSpd_RR", NULL);
    UNICARBrake_DW->ReadCMDict3_IWORK_o.Checked = 0;
    UNICARBrake_DW->ReadCMDict3_PWORK_f.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S4>/Read CM Dict4' */
  {
    char **namevec = CM_Names2StrVec("Car.WRR.Radius", NULL);
    UNICARBrake_DW->ReadCMDict4_IWORK_c.Checked = 0;
    UNICARBrake_DW->ReadCMDict4_PWORK_d.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for If: '<S39>/If2' */
  UNICARBrake_DW->If2_ActiveSubsystem_e = -1;

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict1' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.BrakeActive.RR", NULL);
    UNICARBrake_DW->WriteCMDict1_IWORK_f.Checked = 0;
    UNICARBrake_DW->WriteCMDict1_PWORK_n.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S4>/Write CM Dict2' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.Trq.RR", NULL);
    UNICARBrake_DW->WriteCMDict2_IWORK_k.Checked = 0;
    UNICARBrake_DW->WriteCMDict2_PWORK_l.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for TransportDelay: '<S41>/Transport Delay' */
  {
    real_T *pBuffer = &UNICARBrake_DW->TransportDelay_RWORK_c.TUbufferArea[0];
    UNICARBrake_DW->TransportDelay_IWORK_i.Tail = 0;
    UNICARBrake_DW->TransportDelay_IWORK_i.Head = 0;
    UNICARBrake_DW->TransportDelay_IWORK_i.Last = 0;
    UNICARBrake_DW->TransportDelay_IWORK_i.CircularBufSize = 1024;
    pBuffer[0] = UNICARBrake_P.TransportDelay_InitOutput_l;
    pBuffer[1024] = UNICARBrake_M->Timing.t[0];
    UNICARBrake_DW->TransportDelay_PWORK_c.TUbufferPtrs[0] = (void *) &pBuffer[0];
    UNICARBrake_DW->TransportDelay_PWORK_c.TUbufferPtrs[1] = (void *) &pBuffer
      [1024];
  }

  /* Start for S-Function (read_dict): '<S6>/Read CM Dict' */
  {
    char **namevec = CM_Names2StrVec("DynMod.Brake.ParkingBrk.active", NULL);
    UNICARBrake_DW->ReadCMDict_IWORK_n.Checked = 0;
    UNICARBrake_DW->ReadCMDict_PWORK_p.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* InitializeConditions for TransferFcn: '<S11>/ABS on' */
  UNICARBrake_X->ABSon_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/ABS off' */
  UNICARBrake_X->ABSoff_CSTATE[0] = 0.0;
  UNICARBrake_X->ABSoff_CSTATE[1] = 0.0;

  /* InitializeConditions for Memory: '<S12>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput = UNICARBrake_P.Memory_InitialCondition;

  /* InitializeConditions for Derivative: '<S9>/Derivative' */
  UNICARBrake_DW->TimeStampA = (rtInf);
  UNICARBrake_DW->TimeStampB = (rtInf);

  /* InitializeConditions for Memory: '<S9>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_f =
    UNICARBrake_P.Memory_InitialCondition_b;

  /* InitializeConditions for Memory: '<S12>/Memory1' */
  UNICARBrake_DW->Memory1_PreviousInput = UNICARBrake_P.Memory1_InitialCondition;

  /* InitializeConditions for TransferFcn: '<S21>/ABS on' */
  UNICARBrake_X->ABSon_CSTATE_d = 0.0;

  /* InitializeConditions for TransferFcn: '<S21>/ABS off' */
  UNICARBrake_X->ABSoff_CSTATE_o[0] = 0.0;
  UNICARBrake_X->ABSoff_CSTATE_o[1] = 0.0;

  /* InitializeConditions for Memory: '<S22>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_o =
    UNICARBrake_P.Memory_InitialCondition_e;

  /* InitializeConditions for Derivative: '<S19>/Derivative' */
  UNICARBrake_DW->TimeStampA_j = (rtInf);
  UNICARBrake_DW->TimeStampB_l = (rtInf);

  /* InitializeConditions for Memory: '<S19>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_k =
    UNICARBrake_P.Memory_InitialCondition_b2;

  /* InitializeConditions for Memory: '<S22>/Memory1' */
  UNICARBrake_DW->Memory1_PreviousInput_p =
    UNICARBrake_P.Memory1_InitialCondition_k;

  /* InitializeConditions for TransferFcn: '<S31>/ABS on' */
  UNICARBrake_X->ABSon_CSTATE_l = 0.0;

  /* InitializeConditions for TransferFcn: '<S31>/ABS off' */
  UNICARBrake_X->ABSoff_CSTATE_c[0] = 0.0;
  UNICARBrake_X->ABSoff_CSTATE_c[1] = 0.0;

  /* InitializeConditions for Memory: '<S32>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_c =
    UNICARBrake_P.Memory_InitialCondition_p;

  /* InitializeConditions for Derivative: '<S29>/Derivative' */
  UNICARBrake_DW->TimeStampA_m = (rtInf);
  UNICARBrake_DW->TimeStampB_a = (rtInf);

  /* InitializeConditions for Memory: '<S29>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_p =
    UNICARBrake_P.Memory_InitialCondition_m;

  /* InitializeConditions for Memory: '<S32>/Memory1' */
  UNICARBrake_DW->Memory1_PreviousInput_a =
    UNICARBrake_P.Memory1_InitialCondition_m;

  /* InitializeConditions for TransferFcn: '<S41>/ABS on' */
  UNICARBrake_X->ABSon_CSTATE_o = 0.0;

  /* InitializeConditions for TransferFcn: '<S41>/ABS off' */
  UNICARBrake_X->ABSoff_CSTATE_p[0] = 0.0;
  UNICARBrake_X->ABSoff_CSTATE_p[1] = 0.0;

  /* InitializeConditions for Memory: '<S42>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_b =
    UNICARBrake_P.Memory_InitialCondition_eq;

  /* InitializeConditions for Derivative: '<S39>/Derivative' */
  UNICARBrake_DW->TimeStampA_l = (rtInf);
  UNICARBrake_DW->TimeStampB_l3 = (rtInf);

  /* InitializeConditions for Memory: '<S39>/Memory' */
  UNICARBrake_DW->Memory_PreviousInput_h =
    UNICARBrake_P.Memory_InitialCondition_g;

  /* InitializeConditions for Memory: '<S42>/Memory1' */
  UNICARBrake_DW->Memory1_PreviousInput_o =
    UNICARBrake_P.Memory1_InitialCondition_g;
}

/* Model terminate function */
void UNICARBrake_terminate(RT_MODEL_UNICARBrake_T * UNICARBrake_M)
{
  rt_FREE(UNICARBrake_M->solverInfo);

  /* model code */
  rt_FREE(UNICARBrake_M->blockIO);
  rt_FREE(UNICARBrake_M->contStates);
  rt_FREE(UNICARBrake_M->inputs);
  rt_FREE(UNICARBrake_M->outputs);
  rt_FREE(UNICARBrake_M->dwork);
  rt_FREE(UNICARBrake_M);
}

/* Model data allocation function */
RT_MODEL_UNICARBrake_T *UNICARBrake(struct tInfos *inf)
{
  RT_MODEL_UNICARBrake_T *UNICARBrake_M;
  UNICARBrake_M = (RT_MODEL_UNICARBrake_T *) malloc(sizeof
    (RT_MODEL_UNICARBrake_T));
  if (UNICARBrake_M == NULL) {
    return NULL;
  }

  (void) memset((char *)UNICARBrake_M, 0,
                sizeof(RT_MODEL_UNICARBrake_T));
  MatSupp_Init();

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(UNICARBrake_M,rt_SolverInfo);
    UNICARBrake_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(UNICARBrake_M->solverInfo,
                          &UNICARBrake_M->Timing.simTimeStep);
    rtsiSetTPtr(UNICARBrake_M->solverInfo, &rtmGetTPtr(UNICARBrake_M));
    rtsiSetStepSizePtr(UNICARBrake_M->solverInfo,
                       &UNICARBrake_M->Timing.stepSize0);
    rtsiSetdXPtr(UNICARBrake_M->solverInfo, &UNICARBrake_M->derivs);
    rtsiSetContStatesPtr(UNICARBrake_M->solverInfo, (real_T **)
                         &UNICARBrake_M->contStates);
    rtsiSetNumContStatesPtr(UNICARBrake_M->solverInfo,
      &UNICARBrake_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(UNICARBrake_M->solverInfo,
      &UNICARBrake_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(UNICARBrake_M->solverInfo,
      &UNICARBrake_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(UNICARBrake_M->solverInfo,
      &UNICARBrake_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(UNICARBrake_M->solverInfo, (&rtmGetErrorStatus
      (UNICARBrake_M)));
    rtsiSetRTModelPtr(UNICARBrake_M->solverInfo, UNICARBrake_M);
  }

  rtsiSetSolverName(UNICARBrake_M->solverInfo,"ode1");

  /* block I/O */
  {
    B_UNICARBrake_T *b = (B_UNICARBrake_T *) malloc(sizeof(B_UNICARBrake_T));
    rt_VALIDATE_MEMORY(UNICARBrake_M,b);
    UNICARBrake_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    X_UNICARBrake_T *x = (X_UNICARBrake_T *) malloc(sizeof(X_UNICARBrake_T));
    rt_VALIDATE_MEMORY(UNICARBrake_M,x);
    UNICARBrake_M->contStates = (x);
  }

  /* states (dwork) */
  {
    DW_UNICARBrake_T *dwork = (DW_UNICARBrake_T *) malloc(sizeof
      (DW_UNICARBrake_T));
    rt_VALIDATE_MEMORY(UNICARBrake_M,dwork);
    UNICARBrake_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_UNICARBrake_T *UNICARBrake_U = (ExtU_UNICARBrake_T *) malloc(sizeof
      (ExtU_UNICARBrake_T));
    rt_VALIDATE_MEMORY(UNICARBrake_M,UNICARBrake_U);
    UNICARBrake_M->inputs = (((ExtU_UNICARBrake_T *) UNICARBrake_U));
  }

  /* external outputs */
  {
    ExtY_UNICARBrake_T *UNICARBrake_Y = (ExtY_UNICARBrake_T *) malloc(sizeof
      (ExtY_UNICARBrake_T));
    rt_VALIDATE_MEMORY(UNICARBrake_M,UNICARBrake_Y);
    UNICARBrake_M->outputs = (UNICARBrake_Y);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  UNICARBrake_InitializeDataMapInfo(UNICARBrake_M);

  /* CarMaker parameter tuning */
  {
    const struct tMatSuppMMI *mmi = &(rtmGetDataMapInfo(UNICARBrake_M).mmi);
    tMatSuppTunables *tuns = MatSupp_TunBegin("UNICARBrake", mmi);
    UNICARBrake_SetParams(UNICARBrake_M, tuns, inf);
    MatSupp_TunEnd(tuns);
  }

  {
    B_UNICARBrake_T *UNICARBrake_B = ((B_UNICARBrake_T *) UNICARBrake_M->blockIO);
    DW_UNICARBrake_T *UNICARBrake_DW = ((DW_UNICARBrake_T *)
      UNICARBrake_M->dwork);
    X_UNICARBrake_T *UNICARBrake_X = ((X_UNICARBrake_T *)
      UNICARBrake_M->contStates);
    ExtU_UNICARBrake_T *UNICARBrake_U = (ExtU_UNICARBrake_T *)
      UNICARBrake_M->inputs;
    ExtY_UNICARBrake_T *UNICARBrake_Y = (ExtY_UNICARBrake_T *)
      UNICARBrake_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtsiSetSimTimeStep(UNICARBrake_M->solverInfo, MAJOR_TIME_STEP);
    UNICARBrake_M->intgData.f[0] = UNICARBrake_M->odeF[0];
    UNICARBrake_M->contStates = ((X_UNICARBrake_T *) UNICARBrake_X);
    rtsiSetSolverData(UNICARBrake_M->solverInfo, (void *)
                      &UNICARBrake_M->intgData);
    rtmSetTPtr(UNICARBrake_M, &UNICARBrake_M->Timing.tArray[0]);
    UNICARBrake_M->Timing.stepSize0 = 0.001;

    /* block I/O */
    (void) memset(((void *) UNICARBrake_B), 0,
                  sizeof(B_UNICARBrake_T));

    /* states (continuous) */
    {
      (void) memset((void *)UNICARBrake_X, 0,
                    sizeof(X_UNICARBrake_T));
    }

    /* states (dwork) */
    (void) memset((void *)UNICARBrake_DW, 0,
                  sizeof(DW_UNICARBrake_T));

    /* external inputs */
    (void)memset(UNICARBrake_U, 0, sizeof(ExtU_UNICARBrake_T));

    /* external outputs */
    UNICARBrake_Y->ToCM = UNICARBrake_rtZcmBrakeOut;
  }

  return UNICARBrake_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *UNICARBrake_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)UNICARBrake_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *UNICARBrake_DictDefines = DictDefines;
tQuantEntry *UNICARBrake_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *UNICARBrake_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)UNICARBrake_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *UNICARBrake_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *UNICARBrake_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
