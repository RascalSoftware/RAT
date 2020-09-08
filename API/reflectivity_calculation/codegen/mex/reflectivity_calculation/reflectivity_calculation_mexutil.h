/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_mexutil.h
 *
 * Code generation for function 'reflectivity_calculation_mexutil'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void MEXGlobalSyncInFunction(void);
void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);
emlrtCTX emlrtGetRootTLSGlobal(void);
void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData);
void emlrt_synchGlobalsFromML(const emlrtStack *sp);
void emlrt_synchGlobalsToML(const emlrtStack *sp);

/* End of code generation (reflectivity_calculation_mexutil.h) */
