/*
 * FORCE_model_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FORCE_model".
 *
 * Model version              : 15.52
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Thu Oct 29 13:35:14 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FORCE_model.h"

/* Block parameters (default storage) */
P_FORCE_model_T FORCE_model_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S7>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S7>/S-Function'
   */
  { 0.0, 1.0, 0.0, 0.05, 0.33933, -1.0, 1.0, 0.0, 0.0, 5.0, 5.0, 0.0,
    0.08933333333333332, 0.08933333333333332, 0.0, 10000.0, 10000.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S6>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S4>/SPERTE_measurement_samples'
   */
  720000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S4>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S4>/SPERTE_measurement_function'
   */
  2U,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S10>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S10>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S10>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S10>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S9>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S9>/ec_Ebox'
   */
  0.0,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S3>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Computed Parameter: Noise_StdDev
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: 0.00028
   * Referenced by: '<S2>/Gain'
   */
  0.00028,

  /* Expression: 0.00068
   * Referenced by: '<S2>/Gain1'
   */
  0.00068,

  /* Expression: 0.006
   * Referenced by: '<S2>/Gain2'
   */
  0.006,

  /* Expression: 0.8
   * Referenced by: '<S8>/Gain1'
   */
  0.8,

  /* Computed Parameter: Dctleadlag2_P1_Size
   * Referenced by: '<S8>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctleadlag2'
   */
  5.0,

  /* Computed Parameter: Dctleadlag2_P2_Size
   * Referenced by: '<S8>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctleadlag2'
   */
  35.0,

  /* Computed Parameter: Dctleadlag2_P3_Size
   * Referenced by: '<S8>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctleadlag2'
   */
  0.001,

  /* Computed Parameter: Dctnotch3_P1_Size
   * Referenced by: '<S8>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctnotch3'
   */
  60.0,

  /* Computed Parameter: Dctnotch3_P2_Size
   * Referenced by: '<S8>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctnotch3'
   */
  0.1,

  /* Computed Parameter: Dctnotch3_P3_Size
   * Referenced by: '<S8>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctnotch3'
   */
  60.0,

  /* Computed Parameter: Dctnotch3_P4_Size
   * Referenced by: '<S8>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dctnotch3'
   */
  0.5,

  /* Computed Parameter: Dctnotch3_P5_Size
   * Referenced by: '<S8>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctnotch3'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass4_P1_Size
   * Referenced by: '<S8>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dct2lowpass4'
   */
  300.0,

  /* Computed Parameter: Dct2lowpass4_P2_Size
   * Referenced by: '<S8>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dct2lowpass4'
   */
  0.7,

  /* Computed Parameter: Dct2lowpass4_P3_Size
   * Referenced by: '<S8>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dct2lowpass4'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S3>/Constant2'
   */
  0.0,

  /* Expression: 2.5
   * Referenced by: '<S3>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S3>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S9>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S9>/Saturation'
   */
  -10.0,

  /* Expression: [0,0]
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 1/100
   * Referenced by: '<S9>/Gain'
   */
  0.01,

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S3>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  0U,

  /* Computed Parameter: ManualTrigger_Value
   * Referenced by: '<Root>/Manual Trigger'
   */
  0U
};
