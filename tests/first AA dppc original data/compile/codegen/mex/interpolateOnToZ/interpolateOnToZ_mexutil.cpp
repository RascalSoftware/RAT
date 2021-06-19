//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  interpolateOnToZ_mexutil.cpp
//
//  Code generation for function 'interpolateOnToZ_mexutil'
//


// Include files
#include "interpolateOnToZ_mexutil.h"
#include "interpolateOnToZ.h"
#include "interpolateOnToZ_data.h"
#include "rt_nonfinite.h"

// Function Definitions
emlrtCTX emlrtGetRootTLSGlobal()
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

// End of code generation (interpolateOnToZ_mexutil.cpp)
