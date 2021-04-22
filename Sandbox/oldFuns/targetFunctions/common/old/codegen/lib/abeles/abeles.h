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
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "abeles_types.h"

/* Function Declarations */
extern void abeles(const emxArray_real_T *x, const emxArray_creal_T *sld, const
                   creal_T nbair, const creal_T nbsub, double nrepeats, double
                   ssub, double layers, double points, emxArray_real_T *out);

#endif

/* End of code generation (abeles.h) */
