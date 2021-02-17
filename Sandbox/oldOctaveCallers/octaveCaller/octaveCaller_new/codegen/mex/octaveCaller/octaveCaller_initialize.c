/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * octaveCaller_initialize.c
 *
 * Code generation for function 'octaveCaller_initialize'
 *
 */

/* Include files */
#include "octaveCaller_initialize.h"
#include "_coder_octaveCaller_mex.h"
#include "octaveCaller.h"
#include "octaveCaller_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Declarations */
static void octaveCaller_once(void);

/* Function Definitions */
static void octaveCaller_once(void)
{
  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller/octaveCaller_new/octaveCaller.m",
                  0U, 1U, 3U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "octaveCaller", 0, -1, 1146);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 96, -1, 1110);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 67, -1, 80);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 25, -1, 34);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 37, 62, 87, 1120);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void octaveCaller_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    octaveCaller_once();
  }
}

/* End of code generation (octaveCaller_initialize.c) */
