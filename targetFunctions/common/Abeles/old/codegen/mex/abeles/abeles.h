/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles.h
 *
 * Code generation for function 'abeles'
 *
 */

#ifndef ABELES_H
#define ABELES_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "abeles_types.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo b_emlrtRSI;
extern emlrtRSInfo c_emlrtRSI;
extern emlrtRSInfo d_emlrtRSI;
extern emlrtRSInfo e_emlrtRSI;
extern emlrtRSInfo f_emlrtRSI;

/* Function Declarations */
extern void abeles(const emlrtStack *sp, const emxArray_real_T *x, const
                   emxArray_creal_T *sld, const creal_T nbair, const creal_T
                   nbsub, real_T nrepeats, real_T ssub, real_T layers, real_T
                   points, emxArray_real_T *out);
extern void abeles_api(const mxArray * const prhs[8], int32_T nlhs, const
  mxArray *plhs[1]);
extern void abeles_atexit(void);
extern void abeles_initialize(void);
extern void abeles_terminate(void);
MEXFUNCTION_LINKAGE mxArray *emlrtMexFcnProperties(void);
extern const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

#endif

/* End of code generation (abeles.h) */
