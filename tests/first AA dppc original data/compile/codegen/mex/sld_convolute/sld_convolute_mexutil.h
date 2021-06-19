//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sld_convolute_mexutil.h
//
//  Code generation for function 'sld_convolute_mexutil'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "sld_convolute_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM emlrtCTX emlrtGetRootTLSGlobal();
CODEGEN_EXPORT_SYM void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const
  emlrtConstCTX aTLS, void *aData);

// End of code generation (sld_convolute_mexutil.h)
