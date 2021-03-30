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
#include "rt_nonfinite.h"
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_initialize.h"
#include "_coder_matlabEngineCaller_customLayers_mex.h"
#include "matlabEngineCaller_customLayers_data.h"

/* Function Declarations */
static void c_matlabEngineCaller_customLaye(void);

/* Function Definitions */
static void c_matlabEngineCaller_customLaye(void)
{
  covrtInstanceData *t0_data = NULL;
  emlrtCoverageInstance.data = t0_data;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
                  "EngineCaller_customLayers.m", 0U, 1U, 8U, 4U, 0U, 0U, 0U, 1U,
                  0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "matlabEngineCaller_customLayers",
               0, -1, 2337);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 2290, -1, 2322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 2190, -1, 2243);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1992, -1, 2133);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1923, -1, 1948);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 545, -1, 1840);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 432, -1, 529);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 339, -1, 418);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 111, -1, 285);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 287, 312, 531, 2336);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 317, 330, -1, 427);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 1897, 1914, 2277, 2331);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 2147, 2173, -1, 2260);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1958, 1980, 2272);

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
