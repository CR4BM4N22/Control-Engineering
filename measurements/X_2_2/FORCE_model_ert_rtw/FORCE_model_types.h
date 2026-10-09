/*
 * FORCE_model_types.h
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

#ifndef FORCE_model_types_h_
#define FORCE_model_types_h_
#include "rtwtypes.h"
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_FORCE_model_T
#define typedef_emxArray_char_T_FORCE_model_T

typedef struct emxArray_char_T emxArray_char_T_FORCE_model_T;

#endif                               /* typedef_emxArray_char_T_FORCE_model_T */

/* Parameters (default storage) */
typedef struct P_FORCE_model_T_ P_FORCE_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_FORCE_model_T RT_MODEL_FORCE_model_T;

#endif                                 /* FORCE_model_types_h_ */
