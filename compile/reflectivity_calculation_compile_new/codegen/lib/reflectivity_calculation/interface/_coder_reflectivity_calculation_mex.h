/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: _coder_reflectivity_calculation_mex.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 15-Apr-2021 10:46:16
 */

#ifndef _CODER_REFLECTIVITY_CALCULATION_MEX_H
#define _CODER_REFLECTIVITY_CALCULATION_MEX_H

/* Include Files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "_coder_reflectivity_calculation_api.h"
#define MAX_THREADS                    omp_get_max_threads()

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
  const mxArray *prhs[]);
extern emlrtCTX mexFunctionCreateRootTLS(void);

#endif

/*
 * File trailer for _coder_reflectivity_calculation_mex.h
 *
 * [EOF]
 */
