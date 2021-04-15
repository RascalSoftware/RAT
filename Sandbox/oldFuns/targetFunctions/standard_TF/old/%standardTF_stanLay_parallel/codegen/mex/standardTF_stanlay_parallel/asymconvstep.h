/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * asymconvstep.h
 *
 * Code generation for function 'asymconvstep'
 *
 */

#ifndef ASYMCONVSTEP_H
#define ASYMCONVSTEP_H

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
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void asymconvstep(const emlrtStack *sp, const emxArray_real_T *x, real_T
  xw, real_T xcen, real_T s1, real_T s2, real_T h, emxArray_real_T *f);
extern void b_asymconvstep(const emlrtStack *sp, const real_T x_data[], real_T
  xw, real_T xcen, real_T s1, real_T s2, real_T h, real_T f_data[], int32_T
  f_size[2]);

#endif

/* End of code generation (asymconvstep.h) */
