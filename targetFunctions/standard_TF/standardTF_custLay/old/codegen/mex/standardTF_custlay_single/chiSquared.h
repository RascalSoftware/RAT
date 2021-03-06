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
#include "covrt.h"
#include "rtwtypes.h"
#include "standardTF_custlay_single_types.h"

/* Function Declarations */
extern real_T chiSquared(const emlrtStack *sp, const real_T thisData_data[],
  const int32_T thisData_size[2], const real_T thisFit_data[], const int32_T
  thisFit_size[2], real_T P);

#ifdef __WATCOMC__

#pragma aux chiSquared value [8087];

#endif
#endif

/* End of code generation (chiSquared.h) */
