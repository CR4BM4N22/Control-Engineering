/*
 * ert_main.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FORCE_model".
 *
 * Model version              : 15.36
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Sep 22 12:17:21 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "FORCE_model.h"
#include "FORCE_model_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "ext_mode.h"
#include "MW_raspi_init.h"
#include "linuxTimeLogger.h"
#include "MW_Pyserver_control.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
extmodeSimulationTime_T getCurrentTaskTime(int_T tid)
{
  extmodeSimulationTime_T extmodeTime = 0;
  switch (tid) {
   case 0:
    extmodeTime = (extmodeSimulationTime_T)(FORCE_model_M->Timing.t[0]);
    break;

   case 1:
    extmodeTime = (extmodeSimulationTime_T)(FORCE_model_M->Timing.t[1]);
    break;

   case 2:
    extmodeTime = (extmodeSimulationTime_T)(((FORCE_model_M->Timing.clockTick2) *
      0.002));
    break;
  }

  return extmodeTime;
}

void *subrateTask(void *arg)
{
  int_T tid = *((int_T *) arg);
  int_T subRateId;
  subRateId = tid + 2;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    extmodeSimulationTime_T currentTime = getCurrentTaskTime(subRateId);
    FORCE_model_step(subRateId);

    /* Get model outputs here */

    /* Trigger External Mode event */
    extmodeEvent(subRateId, currentTime);
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(FORCE_model_M) == (NULL)) &&
    !rtmGetStopRequested(FORCE_model_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(FORCE_model_M, 2)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      FORCE_model_M->Timing.t[1];

    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    FORCE_model_step(0);

    /* Get model outputs here */

    /* Trigger External Mode event */
    extmodeEvent(1, currentTime);
    stopRequested = !((rtmGetErrorStatus(FORCE_model_M) == (NULL)) &&
                      !rtmGetStopRequested(FORCE_model_M));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(FORCE_model_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  MW_killPyserver();
  mwRaspiTerminate();

  /* Terminate model */
  FORCE_model_terminate();
  extmodeReset();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  subratePriority[0] = 39;
  mwRaspiInit();
  MW_launchPyserver();
  rtmSetErrorStatus(FORCE_model_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(argc, (const char_T **)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  /* Initialize model */
  FORCE_model_initialize();

  /* External Mode initialization */
  errorCode = extmodeInit(FORCE_model_M->extModeInfo, &rtmGetTFinal
    (FORCE_model_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(FORCE_model_M, true);
    }
  }

  /* Call RTOS Initialization function */
  myRTOSInit(0.00025, 1);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}
