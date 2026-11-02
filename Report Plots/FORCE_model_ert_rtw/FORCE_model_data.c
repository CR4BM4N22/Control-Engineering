/*
 * FORCE_model_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FORCE_model".
 *
 * Model version              : 15.61
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Mon Nov  2 14:06:05 2026
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
  { 2.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S7>/S-Function'
   */
  { 0.0, 124.8, 0.0, 5.4766, 124.8, 0.0, 23.196, 23.196, 0.096325000000000008,
    0.096325000000000008, 10000.0, 10000.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S6>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S4>/SPERTE_measurement_samples'
   */
  40000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S4>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S4>/SPERTE_measurement_function'
   */
  2U,

  /* Expression: 0.00009
   * Referenced by: '<S9>/Fv forwards'
   */
  9.0E-5,

  /* Expression: 0.0001
   * Referenced by: '<S9>/Fv backwards'
   */
  0.0001,

  /* Expression: 0.002
   * Referenced by: '<S10>/Fc forwards'
   */
  0.002,

  /* Expression: 0.008
   * Referenced by: '<S10>/Fc backwards'
   */
  0.008,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S12>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S12>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S12>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S12>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S11>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S11>/ec_Ebox'
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

  /* Expression: 0.0004
   * Referenced by: '<S2>/Gain'
   */
  0.0004,

  /* Expression: 0
   * Referenced by: '<S9>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Switch'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S8>/Gain1'
   */
  0.5,

  /* Computed Parameter: Dctleadlag2_P1_Size
   * Referenced by: '<S8>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctleadlag2'
   */
  3.0,

  /* Computed Parameter: Dctleadlag2_P2_Size
   * Referenced by: '<S8>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctleadlag2'
   */
  45.0,

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
  0.075,

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

  /* Computed Parameter: Dctnotch5_P1_Size
   * Referenced by: '<S8>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctnotch5'
   */
  3.7,

  /* Computed Parameter: Dctnotch5_P2_Size
   * Referenced by: '<S8>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctnotch5'
   */
  0.34,

  /* Computed Parameter: Dctnotch5_P3_Size
   * Referenced by: '<S8>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctnotch5'
   */
  3.7,

  /* Computed Parameter: Dctnotch5_P4_Size
   * Referenced by: '<S8>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dctnotch5'
   */
  0.01,

  /* Computed Parameter: Dctnotch5_P5_Size
   * Referenced by: '<S8>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctnotch5'
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
   * Referenced by: '<S11>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S11>/Saturation'
   */
  -10.0,

  /* Expression: [0,0]
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 1/100
   * Referenced by: '<S11>/Gain'
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
