/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_initialize.c
 *
 * Code generation for function 'reflectivity_calculation_initialize'
 *
 */

/* Include files */
#include "reflectivity_calculation_initialize.h"
#include "_coder_reflectivity_calculation_mex.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void reflectivity_calculation_once(const emlrtStack *sp);

/* Function Definitions */
static void reflectivity_calculation_once(const emlrtStack *sp)
{
  mex_InitInfAndNan();
  emlrtSetGlobalSyncFcn(sp, (void (*)(const void *))&emlrt_synchGlobalsToML);
}

void reflectivity_calculation_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    reflectivity_calculation_once(&st);
  }
}

/* End of code generation (reflectivity_calculation_initialize.c) */
