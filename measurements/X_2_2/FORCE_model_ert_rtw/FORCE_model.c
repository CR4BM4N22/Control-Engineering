/*
 * FORCE_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FORCE_model".
 *
 * Model version              : 15.41
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Fri Oct  9 17:19:12 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FORCE_model.h"
#include "FORCE_model_types.h"
#include "rtwtypes.h"
#include "FORCE_model_private.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <stdlib.h>

/* Block signals (default storage) */
B_FORCE_model_T FORCE_model_B;

/* Block states (default storage) */
DW_FORCE_model_T FORCE_model_DW;

/* Real-time model */
static RT_MODEL_FORCE_model_T FORCE_model_M_;
RT_MODEL_FORCE_model_T *const FORCE_model_M = &FORCE_model_M_;

/* Forward declaration for local functions */
static void FORCE_model_emxInit_char_T(emxArray_char_T_FORCE_model_T **pEmxArray,
  int32_T numDimensions);
static void FORCE__emxEnsureCapacity_char_T(emxArray_char_T_FORCE_model_T
  *emxArray, int32_T oldNumel);
static void FORCE_model_emxFree_char_T(emxArray_char_T_FORCE_model_T **pEmxArray);
static int8_T FORCE_model_filedata(void);
static int8_T FORCE_model_cfopen(const emxArray_char_T_FORCE_model_T *cfilename,
  const char_T *cpermission);
static int32_T FORCE_model_cfclose(real_T fid);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void FORCE_model_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(FORCE_model_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (FORCE_model_M->Timing.TaskCounters.TID[1] == 0) {
    FORCE_model_M->Timing.RateInteraction.TID1_2 =
      (FORCE_model_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    FORCE_model_M->Timing.perTaskSampleHits[5] =
      FORCE_model_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FORCE_model_M->Timing.TaskCounters.TID[2])++;
  if ((FORCE_model_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.002s, 0.0s] */
    FORCE_model_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void FORCE_model_emxInit_char_T(emxArray_char_T_FORCE_model_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_char_T_FORCE_model_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_FORCE_model_T *)malloc(sizeof
    (emxArray_char_T_FORCE_model_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void FORCE__emxEnsureCapacity_char_T(emxArray_char_T_FORCE_model_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void FORCE_model_emxFree_char_T(emxArray_char_T_FORCE_model_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_FORCE_model_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_FORCE_model_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int8_T FORCE_model_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (FORCE_model_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int8_T FORCE_model_cfopen(const emxArray_char_T_FORCE_model_T *cfilename,
  const char_T *cpermission)
{
  FILE *filestar;
  emxArray_char_T_FORCE_model_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = FORCE_model_filedata();
  if (j >= 1) {
    FORCE_model_emxInit_char_T(&ccfilename, 2);
    loop_ub = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    FORCE__emxEnsureCapacity_char_T(ccfilename, loop_ub);
    loop_ub = cfilename->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename->data[0], &cfilename->data[0], (uint32_T)loop_ub *
             sizeof(char_T));
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    filestar = fopen(&ccfilename->data[0], cpermission);
    FORCE_model_emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      FORCE_model_DW.eml_openfiles[j - 1] = filestar;
      FORCE_model_DW.eml_autoflush[j - 1] = true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int32_T FORCE_model_cfclose(real_T fid)
{
  FILE *f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
  st = -1;
  fileid = (int8_T)fid;
  if (((int8_T)fid < 0) || (fid != (int8_T)fid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = FORCE_model_DW.eml_openfiles[b_fileid - 3];
  } else {
    switch (b_fileid) {
     case 0:
      f = stdin;
      break;

     case 1:
      f = stdout;
      break;

     case 2:
      f = stderr;
      break;

     default:
      f = NULL;
      break;
    }
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      st = 0;
      FORCE_model_DW.eml_openfiles[fileid - 3] = NULL;
      FORCE_model_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function for TID0 */
void FORCE_model_step0(void)           /* Sample time: [0.0s, 0.0s] */
{
  FILE *f;
  size_t bytesOutSizet;
  emxArray_char_T_FORCE_model_T *str;
  emxArray_char_T_FORCE_model_T *str_0;
  real_T rtb_Quantizer1;
  real_T rtb_e;
  real_T rtb_u;
  int32_T nbytes;
  int32_T tmp;
  real32_T xout[3];
  int8_T b_fileid;
  boolean_T autoflush;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RandomNumber: '<Root>/Noise' */
  FORCE_model_B.d = FORCE_model_DW.NextOutput;

  /* S-Function (dlowpass2): '<Root>/Dct2lowpass' */

  /* Level2 S-Function Block: '<Root>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S6>/Start setpoint' */
  FORCE_model_B.Startsetpoint = FORCE_model_P.Refpower_stat;

  /* S-Function (ref3b): '<S7>/S-Function' */

  /* Level2 S-Function Block: '<S7>/S-Function' (ref3b) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Supervisor): '<S9>/S-Function' */

  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S8>/ec_Ebox' */

  /* Level2 S-Function Block: '<S8>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Quantizer: '<Root>/Quantizer1' */
  rtb_Quantizer1 = rt_roundd_snf(FORCE_model_B.SFunction[2] /
    FORCE_model_P.Quantizer1_Interval) * FORCE_model_P.Quantizer1_Interval;

  /* ManualSwitch: '<Root>/Select encoder' incorporates:
   *  Gain: '<S3>/count2rad'
   */
  if (FORCE_model_P.Selectencoder_CurrentSetting == 1) {
    rtb_e = FORCE_model_P.count2rad_Gain * FORCE_model_B.ec_Ebox_o2[0];
  } else {
    rtb_e = FORCE_model_P.count2rad_Gain * FORCE_model_B.ec_Ebox_o2[1];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  ManualSwitch: '<Root>/Select encoder'
   */
  rtb_e = rtb_Quantizer1 - rtb_e;

  /* Gain: '<S1>/Gain1' */
  FORCE_model_B.Gain1 = FORCE_model_P.Gain1_Gain_b * rtb_e;

  /* S-Function (dleadlag): '<S1>/Dctleadlag' */

  /* Level2 S-Function Block: '<S1>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S1>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   *  Sum: '<S2>/Add'
   */
  rtb_u = (((FORCE_model_P.Gain_Gain * FORCE_model_B.SFunction[0] +
             FORCE_model_P.Gain1_Gain * FORCE_model_B.SFunction[1]) +
            FORCE_model_P.Gain2_Gain * FORCE_model_B.SFunction[1]) +
           FORCE_model_B.Dct2lowpass) + FORCE_model_B.Dct2lowpass_h;

  /* MATLAB Function: '<S4>/SPERTE_measurement_function' incorporates:
   *  Constant: '<Root>/Manual Trigger'
   *  Constant: '<S4>/SPERTE_measurement_samples'
   *  Constant: '<S4>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S10>/ SFunction '
   */
  if ((((FORCE_model_P.MeasurementBlock_triggertype == 0) &&
        (FORCE_model_P.ManualTrigger_Value == 1)) ||
       ((FORCE_model_P.MeasurementBlock_triggertype == 1) &&
        (FORCE_model_P.MeasurementBlock_trigger_comman == 1)) ||
       ((FORCE_model_P.MeasurementBlock_triggertype == 2) &&
        ((FORCE_model_P.MeasurementBlock_trigger_comman == 1) ||
         (FORCE_model_P.ManualTrigger_Value == 1)))) && (FORCE_model_DW.busy !=
       1)) {
    nbytes = (int32_T)snprintf(NULL, 0, "measurement_%d.bin", FORCE_model_DW.NF)
      + 1;
    FORCE_model_emxInit_char_T(&str, 2);
    tmp = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = nbytes;
    FORCE__emxEnsureCapacity_char_T(str, tmp);
    snprintf(&str->data[0], (size_t)nbytes, "measurement_%d.bin",
             FORCE_model_DW.NF);
    if (nbytes - 1 < 1) {
      nbytes = -1;
    } else {
      nbytes -= 2;
    }

    FORCE_model_emxInit_char_T(&str_0, 2);
    tmp = str_0->size[0] * str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = nbytes + 1;
    FORCE__emxEnsureCapacity_char_T(str_0, tmp);
    if (nbytes >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)(nbytes + 1) * sizeof
             (char_T));
    }

    FORCE_model_emxFree_char_T(&str);
    b_fileid = FORCE_model_cfopen(str_0, "wb");
    FORCE_model_emxFree_char_T(&str_0);
    FORCE_model_DW.fileID = b_fileid;
    nbytes = FORCE_model_DW.NF + 1;
    if (FORCE_model_DW.NF + 1 > 32767) {
      nbytes = 32767;
    }

    FORCE_model_DW.NF = (int16_T)nbytes;
    FORCE_model_DW.busy = 1U;
    FORCE_model_DW.NS = 0U;
  }

  if (FORCE_model_DW.busy == 1) {
    if (FORCE_model_DW.NS < FORCE_model_P.MeasurementBlock_N_samples) {
      b_fileid = (int8_T)FORCE_model_DW.fileID;
      if (((int8_T)FORCE_model_DW.fileID < 0) || (FORCE_model_DW.fileID !=
           (int8_T)FORCE_model_DW.fileID)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        autoflush = FORCE_model_DW.eml_autoflush[b_fileid - 3];
        f = FORCE_model_DW.eml_openfiles[b_fileid - 3];
      } else {
        switch (b_fileid) {
         case 0:
          f = stdin;
          autoflush = true;
          break;

         case 1:
          f = stdout;
          autoflush = true;
          break;

         case 2:
          f = stderr;
          autoflush = true;
          break;

         default:
          f = NULL;
          autoflush = true;
          break;
        }
      }

      if (!(FORCE_model_DW.fileID != 0.0)) {
        f = NULL;
      }

      if (!(f == NULL)) {
        xout[0] = (real32_T)FORCE_model_B.Dct2lowpass;
        xout[1] = (real32_T)rtb_u;
        xout[2] = (real32_T)rtb_e;
        bytesOutSizet = fwrite(&xout[0], sizeof(real32_T), (size_t)3, f);
        if (((real_T)bytesOutSizet > 0.0) && autoflush) {
          fflush(f);
        }
      }

      FORCE_model_DW.NS++;
    } else {
      FORCE_model_cfclose(FORCE_model_DW.fileID);
      FORCE_model_DW.busy = 0U;
      FORCE_model_DW.NS = 0U;
    }
  }

  FORCE_model_B.status = FORCE_model_DW.busy;

  /* End of MATLAB Function: '<S4>/SPERTE_measurement_function' */

  /* RateTransition: '<S5>/Downsample' incorporates:
   *  SignalConversion: '<S5>/Buffer'
   */
  if (FORCE_model_M->Timing.RateInteraction.TID1_2) {
    FORCE_model_DW.Downsample_Buffer[0] = rtb_Quantizer1;
    FORCE_model_DW.Downsample_Buffer[1] = rtb_e;
    FORCE_model_DW.Downsample_Buffer[2] = 0.0;
  }

  /* End of RateTransition: '<S5>/Downsample' */

  /* Saturate: '<S3>/Saturation' */
  if (rtb_u > FORCE_model_P.Saturation_UpperSat) {
    rtb_u = FORCE_model_P.Saturation_UpperSat;
  } else if (rtb_u < FORCE_model_P.Saturation_LowerSat) {
    rtb_u = FORCE_model_P.Saturation_LowerSat;
  }

  /* Saturate: '<S8>/Saturation' */
  if (rtb_u > FORCE_model_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    FORCE_model_B.Saturation[0] = FORCE_model_P.Saturation_UpperSat_d;
  } else if (rtb_u < FORCE_model_P.Saturation_LowerSat_e) {
    /* Saturate: '<S8>/Saturation' */
    FORCE_model_B.Saturation[0] = FORCE_model_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S8>/Saturation' */
    FORCE_model_B.Saturation[0] = rtb_u;
  }

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  if (FORCE_model_P.Constant2_Value > FORCE_model_P.Saturation_UpperSat) {
    rtb_Quantizer1 = FORCE_model_P.Saturation_UpperSat;
  } else if (FORCE_model_P.Constant2_Value < FORCE_model_P.Saturation_LowerSat)
  {
    rtb_Quantizer1 = FORCE_model_P.Saturation_LowerSat;
  } else {
    rtb_Quantizer1 = FORCE_model_P.Constant2_Value;
  }

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Quantizer1 > FORCE_model_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    FORCE_model_B.Saturation[1] = FORCE_model_P.Saturation_UpperSat_d;
  } else if (rtb_Quantizer1 < FORCE_model_P.Saturation_LowerSat_e) {
    /* Saturate: '<S8>/Saturation' */
    FORCE_model_B.Saturation[1] = FORCE_model_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S8>/Saturation' */
    FORCE_model_B.Saturation[1] = rtb_Quantizer1;
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FORCE_model_B.Gain[0] = FORCE_model_P.Gain_Gain_g *
    FORCE_model_P.Constant_Value[0];
  FORCE_model_B.Gain[1] = FORCE_model_P.Gain_Gain_g *
    FORCE_model_P.Constant_Value[1];

  /* Constant: '<S3>/Constant1' */
  memcpy(&FORCE_model_B.Constant1[0], &FORCE_model_P.Constant1_Value[0], sizeof
         (real_T) << 3U);

  /* Update for RandomNumber: '<Root>/Noise' */
  FORCE_model_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&FORCE_model_DW.RandSeed) * FORCE_model_P.Noise_StdDev +
    FORCE_model_P.Noise_Mean;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  FORCE_model_M->Timing.t[0] =
    ((time_T)(++FORCE_model_M->Timing.clockTick0)) *
    FORCE_model_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   */
  FORCE_model_M->Timing.t[1] =
    ((time_T)(++FORCE_model_M->Timing.clockTick1)) *
    FORCE_model_M->Timing.stepSize1;
}

/* Model step function for TID2 */
void FORCE_model_step2(void)           /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S5>/Downsample' */
  FORCE_model_B.Downsample[0] = FORCE_model_DW.Downsample_Buffer[0];
  FORCE_model_B.Downsample[1] = FORCE_model_DW.Downsample_Buffer[1];
  FORCE_model_B.Downsample[2] = FORCE_model_DW.Downsample_Buffer[2];

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FORCE_model_M->Timing.clockTick2++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void FORCE_model_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FORCE_model_step0();
    break;

   case 2 :
    FORCE_model_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void FORCE_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FORCE_model_M, 0,
                sizeof(RT_MODEL_FORCE_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&FORCE_model_M->solverInfo,
                          &FORCE_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&FORCE_model_M->solverInfo, &rtmGetTPtr(FORCE_model_M));
    rtsiSetStepSizePtr(&FORCE_model_M->solverInfo,
                       &FORCE_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&FORCE_model_M->solverInfo, (&rtmGetErrorStatus
      (FORCE_model_M)));
    rtsiSetRTModelPtr(&FORCE_model_M->solverInfo, FORCE_model_M);
  }

  rtsiSetSimTimeStep(&FORCE_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&FORCE_model_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&FORCE_model_M->solverInfo, false);
  rtsiSetSolverName(&FORCE_model_M->solverInfo,"FixedStepDiscrete");
  FORCE_model_M->solverInfoPtr = (&FORCE_model_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = FORCE_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    FORCE_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    FORCE_model_M->Timing.sampleTimes = (&FORCE_model_M->
      Timing.sampleTimesArray[0]);
    FORCE_model_M->Timing.offsetTimes = (&FORCE_model_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    FORCE_model_M->Timing.sampleTimes[0] = (0.0);
    FORCE_model_M->Timing.sampleTimes[1] = (0.00025);
    FORCE_model_M->Timing.sampleTimes[2] = (0.002);

    /* task offsets */
    FORCE_model_M->Timing.offsetTimes[0] = (0.0);
    FORCE_model_M->Timing.offsetTimes[1] = (0.0);
    FORCE_model_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(FORCE_model_M, &FORCE_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = FORCE_model_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = FORCE_model_M->Timing.perTaskSampleHitsArray;
    FORCE_model_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    FORCE_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(FORCE_model_M, 10.0);
  FORCE_model_M->Timing.stepSize0 = 0.00025;
  FORCE_model_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  FORCE_model_M->Sizes.checksums[0] = (483007881U);
  FORCE_model_M->Sizes.checksums[1] = (2447851475U);
  FORCE_model_M->Sizes.checksums[2] = (2503834648U);
  FORCE_model_M->Sizes.checksums[3] = (677218993U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    FORCE_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(FORCE_model_M->extModeInfo,
      &FORCE_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FORCE_model_M->extModeInfo,
                        FORCE_model_M->Sizes.checksums);
    rteiSetTPtr(FORCE_model_M->extModeInfo, rtmGetTPtr(FORCE_model_M));
  }

  FORCE_model_M->solverInfoPtr = (&FORCE_model_M->solverInfo);
  FORCE_model_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&FORCE_model_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&FORCE_model_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &FORCE_model_B), 0,
                sizeof(B_FORCE_model_T));

  /* states (dwork) */
  (void) memset((void *)&FORCE_model_DW, 0,
                sizeof(DW_FORCE_model_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &FORCE_model_M->NonInlinedSFcns.sfcnInfo;
    FORCE_model_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(FORCE_model_M)));
    FORCE_model_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &FORCE_model_M->Sizes.numSampTimes);
    FORCE_model_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr(FORCE_model_M)
      [0]);
    FORCE_model_M->NonInlinedSFcns.taskTimePtrs[1] = (&rtmGetTPtr(FORCE_model_M)
      [1]);
    FORCE_model_M->NonInlinedSFcns.taskTimePtrs[2] = (&rtmGetTPtr(FORCE_model_M)
      [2]);
    rtssSetTPtrPtr(sfcnInfo,FORCE_model_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(FORCE_model_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(FORCE_model_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(FORCE_model_M));
    rtssSetStepSizePtr(sfcnInfo, &FORCE_model_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(FORCE_model_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &FORCE_model_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &FORCE_model_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &FORCE_model_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &FORCE_model_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &FORCE_model_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &FORCE_model_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &FORCE_model_M->solverInfoPtr);
  }

  FORCE_model_M->Sizes.numSFcns = (6);

  /* register each child */
  {
    (void) memset((void *)&FORCE_model_M->NonInlinedSFcns.childSFunctions[0], 0,
                  6*sizeof(SimStruct));
    FORCE_model_M->childSfunctions =
      (&FORCE_model_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 6; i++) {
        FORCE_model_M->childSfunctions[i] =
          (&FORCE_model_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: FORCE_model/<Root>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = FORCE_model_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = FORCE_model_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = FORCE_model_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FORCE_model_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FORCE_model_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FORCE_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FORCE_model_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FORCE_model_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FORCE_model_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FORCE_model_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &FORCE_model_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &FORCE_model_B.d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &FORCE_model_B.Dct2lowpass));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts, "FORCE_model/Dct2lowpass");
      ssSetRTModel(rts,FORCE_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)FORCE_model_P.Dct2lowpass_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)FORCE_model_P.Dct2lowpass_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)FORCE_model_P.Dct2lowpass_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &FORCE_model_DW.Dct2lowpass_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FORCE_model_DW.Dct2lowpass_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FORCE_model/<S7>/S-Function (ref3b) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = FORCE_model_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = FORCE_model_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = FORCE_model_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FORCE_model_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FORCE_model_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FORCE_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FORCE_model_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FORCE_model_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FORCE_model_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FORCE_model_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &FORCE_model_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &FORCE_model_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) FORCE_model_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "FORCE_model/Subsystem/S-Function");
      ssSetRTModel(rts,FORCE_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)FORCE_model_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &FORCE_model_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FORCE_model_DW.SFunction_RWORK[0]);
      }

      /* registration */
      ref3b(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FORCE_model/<S9>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = FORCE_model_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = FORCE_model_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = FORCE_model_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FORCE_model_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FORCE_model_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FORCE_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FORCE_model_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FORCE_model_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FORCE_model_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FORCE_model_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &FORCE_model_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &FORCE_model_B.SFunction_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "FORCE_model/Fourth-Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,FORCE_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FORCE_model_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)FORCE_model_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)FORCE_model_P.SFunction_P2_Size);
      }

      /* registration */
      ec_Supervisor(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: FORCE_model/<S8>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = FORCE_model_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = FORCE_model_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = FORCE_model_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FORCE_model_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FORCE_model_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FORCE_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FORCE_model_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FORCE_model_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FORCE_model_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FORCE_model_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &FORCE_model_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = FORCE_model_B.Saturation;
          sfcnUPtrs[1] = &FORCE_model_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = FORCE_model_B.Gain;
          sfcnUPtrs[1] = &FORCE_model_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn3.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = FORCE_model_B.Constant1;
            for (i1=0; i1 < 8; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) FORCE_model_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *) FORCE_model_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *) FORCE_model_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "FORCE_model/Fourth-Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,FORCE_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FORCE_model_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)FORCE_model_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: FORCE_model/<S1>/Dctleadlag (dleadlag) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = FORCE_model_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = FORCE_model_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = FORCE_model_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FORCE_model_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FORCE_model_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FORCE_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FORCE_model_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FORCE_model_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FORCE_model_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FORCE_model_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &FORCE_model_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &FORCE_model_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &FORCE_model_B.Dctleadlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag");
      ssSetPath(rts, "FORCE_model/Controller (motor side)/Dctleadlag");
      ssSetRTModel(rts,FORCE_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)FORCE_model_P.Dctleadlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)FORCE_model_P.Dctleadlag_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)FORCE_model_P.Dctleadlag_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &FORCE_model_DW.Dctleadlag_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FORCE_model_DW.Dctleadlag_RWORK[0]);
      }

      /* registration */
      dleadlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FORCE_model/<S1>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = FORCE_model_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = FORCE_model_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = FORCE_model_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &FORCE_model_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FORCE_model_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FORCE_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &FORCE_model_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &FORCE_model_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &FORCE_model_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &FORCE_model_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &FORCE_model_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FORCE_model_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &FORCE_model_B.Dctleadlag;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &FORCE_model_B.Dct2lowpass_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts, "FORCE_model/Controller (motor side)/Dct2lowpass");
      ssSetRTModel(rts,FORCE_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)FORCE_model_P.Dct2lowpass_P1_Size_m);
        ssSetSFcnParam(rts, 1, (mxArray*)FORCE_model_P.Dct2lowpass_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)FORCE_model_P.Dct2lowpass_P3_Size_m);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &FORCE_model_DW.Dct2lowpass_RWORK_e[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FORCE_model_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FORCE_model_DW.Dct2lowpass_RWORK_e[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  {
    real_T tmp;
    int32_T i;
    uint32_T r;
    uint32_T t;
    uint32_T tseed;

    /* Start for S-Function (dlowpass2): '<Root>/Dct2lowpass' */
    /* Level2 S-Function Block: '<Root>/Dct2lowpass' (dlowpass2) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S6>/Start setpoint' */
    FORCE_model_B.Startsetpoint = FORCE_model_P.Refpower_stat;

    /* Start for S-Function (ec_Supervisor): '<S9>/S-Function' */
    /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (dleadlag): '<S1>/Dctleadlag' */
    /* Level2 S-Function Block: '<S1>/Dctleadlag' (dleadlag) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[4];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (dlowpass2): '<S1>/Dct2lowpass' */
    /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[5];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S3>/Constant1' */
    memcpy(&FORCE_model_B.Constant1[0], &FORCE_model_P.Constant1_Value[0],
           sizeof(real_T) << 3U);

    /* InitializeConditions for RandomNumber: '<Root>/Noise' */
    tmp = floor(FORCE_model_P.Noise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = tseed >> 16U;
    t = tseed & 32768U;
    FORCE_model_DW.RandSeed = ((((tseed - (r << 16U)) + t) << 16U) + t) + r;
    if (FORCE_model_DW.RandSeed < 1U) {
      FORCE_model_DW.RandSeed = 1144108930U;
    } else if (FORCE_model_DW.RandSeed > 2147483646U) {
      FORCE_model_DW.RandSeed = 2147483646U;
    }

    FORCE_model_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&FORCE_model_DW.RandSeed) * FORCE_model_P.Noise_StdDev +
      FORCE_model_P.Noise_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Noise' */

    /* InitializeConditions for S-Function (ref3b): '<S7>/S-Function' */
    /* Level2 S-Function Block: '<S7>/S-Function' (ref3b) */
    {
      SimStruct *rts = FORCE_model_M->childSfunctions[1];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* SystemInitialize for MATLAB Function: '<S4>/SPERTE_measurement_function' */
    for (i = 0; i < 20; i++) {
      FORCE_model_DW.eml_autoflush[i] = false;
    }

    for (i = 0; i < 20; i++) {
      FORCE_model_DW.eml_openfiles[i] = NULL;
    }

    FORCE_model_DW.NF = 0;
    FORCE_model_DW.NS = 0U;
    FORCE_model_DW.fileID = 0.0;
    FORCE_model_DW.busy = 0U;

    /* End of SystemInitialize for MATLAB Function: '<S4>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void FORCE_model_terminate(void)
{
  /* Terminate for S-Function (dlowpass2): '<Root>/Dct2lowpass' */
  /* Level2 S-Function Block: '<Root>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ref3b): '<S7>/S-Function' */
  /* Level2 S-Function Block: '<S7>/S-Function' (ref3b) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Supervisor): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S8>/ec_Ebox' */
  /* Level2 S-Function Block: '<S8>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S1>/Dctleadlag' */
  /* Level2 S-Function Block: '<S1>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S1>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FORCE_model_M->childSfunctions[5];
    sfcnTerminate(rts);
  }
}
