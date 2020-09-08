/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_mexutil.c
 *
 * Code generation for function 'reflectivity_calculation_mexutil'
 *
 */

/* Include files */
#include "reflectivity_calculation_mexutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void MEXGlobalSyncInFunction(void)
{
  /* Marshall in global variables */
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  (void)skipDirtyCheck;

  /* Marshall out global variables */
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  (void)sp;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
}

/* End of code generation (reflectivity_calculation_mexutil.c) */
