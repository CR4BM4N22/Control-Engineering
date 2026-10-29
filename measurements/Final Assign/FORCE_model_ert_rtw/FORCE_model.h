/*
 * FORCE_model.h
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

#ifndef FORCE_model_h_
#define FORCE_model_h_
#ifndef FORCE_model_COMMON_INCLUDES_
#define FORCE_model_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* FORCE_model_COMMON_INCLUDES_ */

#include "FORCE_model_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Startsetpoint;                /* '<S6>/Start setpoint' */
  real_T SFunction[3];                 /* '<S7>/S-Function' */
  real_T SFunction_b;                  /* '<S10>/S-Function' */
  real_T ec_Ebox_o1[2];                /* '<S9>/ec_Ebox' */
  real_T ec_Ebox_o2[2];                /* '<S9>/ec_Ebox' */
  real_T ec_Ebox_o3[8];                /* '<S9>/ec_Ebox' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real_T Dctleadlag2;                  /* '<S8>/Dctleadlag2' */
  real_T Dctnotch3;                    /* '<S8>/Dctnotch3' */
  real_T Dct2lowpass4;                 /* '<S8>/Dct2lowpass4' */
  real_T Saturation[2];                /* '<S9>/Saturation' */
  real_T Gain[2];                      /* '<S9>/Gain' */
  real_T Constant1[8];                 /* '<S3>/Constant1' */
  real_T Downsample[3];                /* '<S5>/Downsample' */
  uint8_T status;                      /* '<S4>/SPERTE_measurement_function' */
} B_FORCE_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T NextOutput;                   /* '<Root>/Noise' */
  real_T Downsample_Buffer[3];         /* '<S5>/Downsample' */
  real_T fileID;                       /* '<S4>/SPERTE_measurement_function' */
  real_T SFunction_RWORK[50];          /* '<S7>/S-Function' */
  real_T Dctleadlag2_RWORK[2];         /* '<S8>/Dctleadlag2' */
  real_T Dctnotch3_RWORK[4];           /* '<S8>/Dctnotch3' */
  real_T Dct2lowpass4_RWORK[4];        /* '<S8>/Dct2lowpass4' */
  struct {
    void *LoggedData;
  } Live_Scope_PWORK;                  /* '<S5>/Live_Scope' */

  FILE* eml_openfiles[20];             /* '<S4>/SPERTE_measurement_function' */
  uint32_T RandSeed;                   /* '<Root>/Noise' */
  uint32_T NS;                         /* '<S4>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S4>/SPERTE_measurement_function' */
  uint8_T busy;                        /* '<S4>/SPERTE_measurement_function' */
  boolean_T doneDoubleBufferReInit;    /* '<S4>/SPERTE_measurement_function' */
  boolean_T eml_autoflush[20];         /* '<S4>/SPERTE_measurement_function' */
} DW_FORCE_model_T;

/* Parameters (default storage) */
struct P_FORCE_model_T_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S7>/S-Function'
                                        */
  real_T ref_part[18];                 /* Variable: ref_part
                                        * Referenced by: '<S7>/S-Function'
                                        */
  real_T Refpower_stat;                /* Mask Parameter: Refpower_stat
                                        * Referenced by: '<S6>/Start setpoint'
                                        */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S4>/SPERTE_measurement_samples'
                                    */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S4>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S4>/SPERTE_measurement_function'
                                  */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T SFunction_P1_Size_k[2];      /* Computed Parameter: SFunction_P1_Size_k
                                       * Referenced by: '<S10>/S-Function'
                                       */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S10>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S10>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S10>/S-Function'
                                        */
  real_T ec_Ebox_P1_Size[2];           /* Computed Parameter: ec_Ebox_P1_Size
                                        * Referenced by: '<S9>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1;                   /* Expression: link_id
                                        * Referenced by: '<S9>/ec_Ebox'
                                        */
  real_T Quantizer1_Interval;          /* Expression: (2*pi)/(500*4)
                                        * Referenced by: '<Root>/Quantizer1'
                                        */
  real_T count2rad_Gain;               /* Expression: (2*pi)/(4*500)
                                        * Referenced by: '<S3>/count2rad'
                                        */
  real_T Noise_Mean;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_StdDev;                 /* Computed Parameter: Noise_StdDev
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_Seed;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.00028
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.00068
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.006
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 0.8
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Dctleadlag2_P1_Size[2];      /* Computed Parameter: Dctleadlag2_P1_Size
                                       * Referenced by: '<S8>/Dctleadlag2'
                                       */
  real_T Dctleadlag2_P1;               /* Expression: f_num
                                        * Referenced by: '<S8>/Dctleadlag2'
                                        */
  real_T Dctleadlag2_P2_Size[2];      /* Computed Parameter: Dctleadlag2_P2_Size
                                       * Referenced by: '<S8>/Dctleadlag2'
                                       */
  real_T Dctleadlag2_P2;               /* Expression: f_den
                                        * Referenced by: '<S8>/Dctleadlag2'
                                        */
  real_T Dctleadlag2_P3_Size[2];      /* Computed Parameter: Dctleadlag2_P3_Size
                                       * Referenced by: '<S8>/Dctleadlag2'
                                       */
  real_T Dctleadlag2_P3;               /* Expression: 0.001
                                        * Referenced by: '<S8>/Dctleadlag2'
                                        */
  real_T Dctnotch3_P1_Size[2];         /* Computed Parameter: Dctnotch3_P1_Size
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P1;                 /* Expression: f_num
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P2_Size[2];         /* Computed Parameter: Dctnotch3_P2_Size
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P2;                 /* Expression: b_num
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P3_Size[2];         /* Computed Parameter: Dctnotch3_P3_Size
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P3;                 /* Expression: f_den
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P4_Size[2];         /* Computed Parameter: Dctnotch3_P4_Size
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P4;                 /* Expression: b_den
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P5_Size[2];         /* Computed Parameter: Dctnotch3_P5_Size
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dctnotch3_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S8>/Dctnotch3'
                                        */
  real_T Dct2lowpass4_P1_Size[2];    /* Computed Parameter: Dct2lowpass4_P1_Size
                                      * Referenced by: '<S8>/Dct2lowpass4'
                                      */
  real_T Dct2lowpass4_P1;              /* Expression: f_den
                                        * Referenced by: '<S8>/Dct2lowpass4'
                                        */
  real_T Dct2lowpass4_P2_Size[2];    /* Computed Parameter: Dct2lowpass4_P2_Size
                                      * Referenced by: '<S8>/Dct2lowpass4'
                                      */
  real_T Dct2lowpass4_P2;              /* Expression: b_den
                                        * Referenced by: '<S8>/Dct2lowpass4'
                                        */
  real_T Dct2lowpass4_P3_Size[2];    /* Computed Parameter: Dct2lowpass4_P3_Size
                                      * Referenced by: '<S8>/Dct2lowpass4'
                                      */
  real_T Dct2lowpass4_P3;              /* Expression: 0.001
                                        * Referenced by: '<S8>/Dct2lowpass4'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 10
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -10
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1/100
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Constant1_Value[8];           /* Expression: [0,0,0,0,0,0,0,0]
                                        * Referenced by: '<S3>/Constant1'
                                        */
  uint8_T Selectencoder_CurrentSetting;
                             /* Computed Parameter: Selectencoder_CurrentSetting
                              * Referenced by: '<Root>/Select encoder'
                              */
  uint8_T ManualTrigger_Value;        /* Computed Parameter: ManualTrigger_Value
                                       * Referenced by: '<Root>/Manual Trigger'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_FORCE_model_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[6];
    SimStruct *childSFunctionPtrs[6];
    struct _ssBlkInfo2 blkInfo2[6];
    struct _ssSFcnModelMethods2 methods2[6];
    struct _ssSFcnModelMethods3 methods3[6];
    struct _ssSFcnModelMethods4 methods4[6];
    struct _ssStatesInfo2 statesInfo2[6];
    ssPeriodicStatesInfo periodicStatesInfo[6];
    struct _ssPortInfo2 inputOutputPortInfo2[6];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T stepSize1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_FORCE_model_T FORCE_model_P;

/* Block signals (default storage) */
extern B_FORCE_model_T FORCE_model_B;

/* Block states (default storage) */
extern DW_FORCE_model_T FORCE_model_DW;

/* External function called from main */
extern void FORCE_model_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void FORCE_model_initialize(void);
extern void FORCE_model_step0(void);   /* Sample time: [0.0s, 0.0s] */
extern void FORCE_model_step2(void);   /* Sample time: [0.002s, 0.0s] */
extern void FORCE_model_step(int_T tid);
extern void FORCE_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FORCE_model_T *const FORCE_model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'FORCE_model'
 * '<S1>'   : 'FORCE_model/Controller (motor side)'
 * '<S2>'   : 'FORCE_model/Feedforward '
 * '<S3>'   : 'FORCE_model/Fourth-Order Motion System'
 * '<S4>'   : 'FORCE_model/Measurement Block'
 * '<S5>'   : 'FORCE_model/Real-time scope'
 * '<S6>'   : 'FORCE_model/Ref power'
 * '<S7>'   : 'FORCE_model/Subsystem'
 * '<S8>'   : 'FORCE_model/Controller (motor side)/temp'
 * '<S9>'   : 'FORCE_model/Fourth-Order Motion System/Ethercat E-box'
 * '<S10>'  : 'FORCE_model/Fourth-Order Motion System/Ethercat Supervisor'
 * '<S11>'  : 'FORCE_model/Measurement Block/SPERTE_measurement_function'
 */
#endif                                 /* FORCE_model_h_ */
