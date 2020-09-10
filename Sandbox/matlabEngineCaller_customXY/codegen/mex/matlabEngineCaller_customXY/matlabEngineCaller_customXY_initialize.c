/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customXY_initialize.c
 *
 * Code generation for function 'matlabEngineCaller_customXY_initialize'
 *
 */

/* Include files */
#include "matlabEngineCaller_customXY_initialize.h"
#include "_coder_matlabEngineCaller_customXY_mex.h"
#include "matlabEngineCaller_customXY.h"
#include "matlabEngineCaller_customXY_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void c_matlabEngineCaller_customXY_o(void);

/* Function Definitions */
static void c_matlabEngineCaller_customXY_o(void)
{
  const int32_T cond_starts_0_0[1] = { 620 };

  const int32_T cond_ends_0_0[1] = { 633 };

  const int32_T postfix_exprs_0_0[2] = { 0, -1 };

  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller_customXY/matlabEngineCaller_customXY.m",
                  0U, 1U, 10U, 5U, 0U, 0U, 0U, 1U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "matlabEngineCaller_customXY", 0,
               -1, 2815);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 2766, -1, 2800);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 2666, -1, 2719);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 2468, -1, 2609);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 2399, -1, 2424);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 798, -1, 2316);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 685, -1, 782);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 642, -1, 671);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 581, -1, 610);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 488, -1, 567);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 107, -1, 434);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 436, 461, 784, 2814);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 466, 479, -1, 576);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 616, 633, -1, 680);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 2373, 2390, 2753, 2809);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 2623, 2649, -1, 2736);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 619, 633, 1, 0, cond_starts_0_0,
                cond_ends_0_0, 2, postfix_exprs_0_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 2434, 2456, 2748);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void matlabEngineCaller_customXY_initialize(void)
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
    c_matlabEngineCaller_customXY_o();
  }
}

/* End of code generation (matlabEngineCaller_customXY_initialize.c) */
