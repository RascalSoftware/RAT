/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * chiSquared.h
 *
 * Code generation for function 'chiSquared'
 *
 */

#ifndef CHISQUARED_H
#define CHISQUARED_H

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
#include "standardTF_stanlay_single_types.h"

/* Function Declarations */
extern real_T chiSquared(const emlrtStack *sp, const emxArray_real_T *thisData,
  const emxArray_real_T *thisFit, real_T P);

#ifdef __WATCOMC__

#pragma aux chiSquared value [8087];

#endif
#endif

/* End of code generation (chiSquared.h) */
