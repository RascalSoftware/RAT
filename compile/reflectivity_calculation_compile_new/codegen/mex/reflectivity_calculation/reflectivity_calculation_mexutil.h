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
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId, real_T y[2]);

real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                          const emlrtMsgIdentifier *parentId);

const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                         const emlrtMsgIdentifier *msgId, real_T ret[2]);

real_T ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                           const emlrtMsgIdentifier *msgId);

void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                         const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* End of code generation (reflectivity_calculation_mexutil.h) */
