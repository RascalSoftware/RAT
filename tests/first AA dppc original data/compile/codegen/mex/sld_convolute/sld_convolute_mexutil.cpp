//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sld_convolute_mexutil.cpp
//
//  Code generation for function 'sld_convolute_mexutil'
//


// Include files
#include "sld_convolute_mexutil.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"
#include "sld_convolute_data.h"

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

// End of code generation (sld_convolute_mexutil.cpp)
