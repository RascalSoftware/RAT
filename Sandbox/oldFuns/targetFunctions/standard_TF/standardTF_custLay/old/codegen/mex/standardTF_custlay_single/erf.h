/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * erf.h
 *
 * Code generation for function 'erf'
 *
 */

#ifndef ERF_H
#define ERF_H

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
extern void b_erf(const emlrtStack *sp, const emxArray_real_T *x,
                  emxArray_real_T *y);

#endif

/* End of code generation (erf.h) */
