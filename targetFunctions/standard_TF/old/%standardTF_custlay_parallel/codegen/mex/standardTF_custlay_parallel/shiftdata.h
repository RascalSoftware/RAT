/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * shiftdata.h
 *
 * Code generation for function 'shiftdata'
 *
 */

#ifndef SHIFTDATA_H
#define SHIFTDATA_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_custlay_parallel_types.h"

/* Function Declarations */
extern void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift,
                      real_T dataPresent, emxArray_real_T *data, const real_T
                      dataLimits[2], emxArray_real_T *shifted_data);

#endif

/* End of code generation (shiftdata.h) */
