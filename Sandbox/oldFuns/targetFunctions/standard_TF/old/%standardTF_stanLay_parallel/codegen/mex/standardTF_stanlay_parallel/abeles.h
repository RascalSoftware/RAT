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
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void abeles(const emlrtStack *sp, const emxArray_real_T *x, const
                   emxArray_real_T *sld, real_T nbair, real_T nbsub, real_T
                   nrepeats, real_T ssub, real_T layers, real_T points,
                   emxArray_real_T *out);

#endif

/* End of code generation (abeles.h) */
