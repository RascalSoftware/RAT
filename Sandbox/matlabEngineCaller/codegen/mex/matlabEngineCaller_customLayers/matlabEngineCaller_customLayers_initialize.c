/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customLayers_initialize.c
 *
 * Code generation for function 'matlabEngineCaller_customLayers_initialize'
 *
 */

/* Include files */
#include "matlabEngineCaller_customLayers_initialize.h"
#include "_coder_matlabEngineCaller_customLayers_mex.h"
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void c_matlabEngineCaller_customLaye(void);

/* Function Definitions */
static void c_matlabEngineCaller_customLaye(void)
{
  const int32_T cond_starts_0_0[1] = { 624 };

  const int32_T cond_ends_0_0[1] = { 637 };

  const int32_T postfix_exprs_0_0[2] = { 0, -1 };

  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m",
                  0U, 1U, 10U, 5U, 0U, 0U, 0U, 1U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "matlabEngineCaller_customLayers",
               0, -1, 2886);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 2835, -1, 2871);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 2735, -1, 2788);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 2537, -1, 2678);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 2468, -1, 2493);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 802, -1, 2385);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 689, -1, 786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 646, -1, 675);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 585, -1, 614);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 492, -1, 571);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 111, -1, 438);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 440, 465, 788, 2885);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 470, 483, -1, 580);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 620, 637, -1, 684);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 2442, 2459, 2822, 2880);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 2692, 2718, -1, 2805);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 623, 637, 1, 0, cond_starts_0_0,
                cond_ends_0_0, 2, postfix_exprs_0_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 2503, 2525, 2817);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void matlabEngineCaller_customLayers_initialize(void)
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
    c_matlabEngineCaller_customLaye();
  }
}

/* End of code generation (matlabEngineCaller_customLayers_initialize.c) */
