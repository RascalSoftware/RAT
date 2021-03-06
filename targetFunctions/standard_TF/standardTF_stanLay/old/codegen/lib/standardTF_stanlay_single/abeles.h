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
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_single_types.h"

/* Function Declarations */
extern void abeles(const emxArray_real_T *x, const emxArray_real_T *sld, double
                   nbair, double nbsub, double nrepeats, double ssub, double
                   layers, double points, emxArray_real_T *out);

#endif

/* End of code generation (abeles.h) */
