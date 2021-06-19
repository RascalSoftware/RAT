//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  interpolateOnToZ_data.h
//
//  Code generation for function 'interpolateOnToZ_data'
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
#include "interpolateOnToZ_types.h"

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo m_emlrtRSI;
extern emlrtRSInfo u_emlrtRSI;
extern emlrtRTEInfo emlrtRTEI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (interpolateOnToZ_data.h)
