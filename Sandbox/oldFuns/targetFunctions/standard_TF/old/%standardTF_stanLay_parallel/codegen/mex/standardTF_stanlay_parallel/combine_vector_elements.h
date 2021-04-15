/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * combine_vector_elements.h
 *
 * Code generation for function 'combine_vector_elements'
 *
 */

#ifndef COMBINE_VECTOR_ELEMENTS_H
#define COMBINE_VECTOR_ELEMENTS_H

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
extern real_T combine_vector_elements(const emlrtStack *sp, const
  emxArray_real_T *x);

#ifdef __WATCOMC__

#pragma aux combine_vector_elements value [8087];

#endif
#endif

/* End of code generation (combine_vector_elements.h) */
