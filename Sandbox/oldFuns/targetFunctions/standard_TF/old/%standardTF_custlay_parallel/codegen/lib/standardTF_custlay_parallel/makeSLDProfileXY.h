/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfileXY.h
 *
 * Code generation for function 'makeSLDProfileXY'
 *
 */

#ifndef MAKESLDPROFILEXY_H
#define MAKESLDPROFILEXY_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_custlay_parallel_types.h"

/* Function Declarations */
extern void makeSLDProfileXY(double nbair, double nbsub, double ssub, const
  emxArray_real_T *layers, double numberOfLayers, double nrepeats,
  emxArray_real_T *out);

#endif

/* End of code generation (makeSLDProfileXY.h) */
