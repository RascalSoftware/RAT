//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sld_convolute_data.h
//
//  Code generation for function 'sld_convolute_data'
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

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo n_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo v_emlrtRSI;
extern emlrtRSInfo pb_emlrtRSI;
extern emlrtRSInfo qb_emlrtRSI;
extern emlrtRTEInfo g_emlrtRTEI;
extern emlrtRTEInfo h_emlrtRTEI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (sld_convolute_data.h)
