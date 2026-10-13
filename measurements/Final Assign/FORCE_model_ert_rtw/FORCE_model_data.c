/*
 * FORCE_model_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FORCE_model".
 *
 * Model version              : 15.42
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Oct 13 12:38:03 2026
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
   * Referenced by: '<S6>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S6>/S-Function'
   */
  { 0.0, 1.0, 0.0, 0.0, 2.6, -1.0, 1.0, 0.0, 0.0, 0.5, 0.5, 0.0,
    0.60000000000000009, 0.60000000000000009, 0.0, 10.0, 10.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S5>/Start setpoint'
   */
  2.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S3>/SPERTE_measurement_samples'
   */
  480000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S3>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S3>/SPERTE_measurement_function'
   */
  2U,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Computed Parameter: Noise_StdDev
   * Referenced by: '<Root>/Noise'
   */
  0.63245553203367588,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Computed Parameter: Dct2lowpass_P1_Size
   * Referenced by: '<Root>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<Root>/Dct2lowpass'
   */
  100.0,

  /* Computed Parameter: Dct2lowpass_P2_Size
   * Referenced by: '<Root>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<Root>/Dct2lowpass'
   */
  0.1,

  /* Computed Parameter: Dct2lowpass_P3_Size
   * Referenced by: '<Root>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<Root>/Dct2lowpass'
   */
  0.001,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S8>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S8>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S8>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S8>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S7>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S7>/ec_Ebox'
   */
  0.0,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S2>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: 0.4
   * Referenced by: '<S1>/Gain1'
   */
  0.4,

  /* Computed Parameter: Dctleadlag_P1_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctleadlag'
   */
  6.0,

  /* Computed Parameter: Dctleadlag_P2_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dctleadlag'
   */
  20.0,

  /* Computed Parameter: Dctleadlag_P3_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size_m
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dct2lowpass'
   */
  100.0,

  /* Computed Parameter: Dct2lowpass_P2_Size_c
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S1>/Dct2lowpass'
   */
  0.7,

  /* Computed Parameter: Dct2lowpass_P3_Size_m
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dct2lowpass'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 2.5
   * Referenced by: '<S2>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S2>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S7>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S7>/Saturation'
   */
  -10.0,

  /* Expression: [0,0]
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 1/100
   * Referenced by: '<S7>/Gain'
   */
  0.01,

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S2>/Constant1'
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
