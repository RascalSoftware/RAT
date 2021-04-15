/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_customLayers.h
 *
 * Code generation for function 'call_customLayers'
 *
 */

#ifndef CALL_CUSTOMLAYERS_H
#define CALL_CUSTOMLAYERS_H

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
extern void call_customLayers(const emxArray_real_T *params, double contrast,
  const emxArray_char_T *file, const emxArray_char_T *callPath, double bulkIn,
  double bulkOut, emxArray_real_T *output, double *sRough);

#endif

/* End of code generation (call_customLayers.h) */
