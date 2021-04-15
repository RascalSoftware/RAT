/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_StandardLayers.h
 *
 * Code generation for function 'call_StandardLayers'
 *
 */

#ifndef CALL_STANDARDLAYERS_H
#define CALL_STANDARDLAYERS_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void call_StandardLayers(const emxArray_real_T *params, const double
  contrastLayers[2], double numberOfLayers, const emxArray_cell_wrap_2
  *layersDetails, double layersList_data[], int layersList_size[2], double
  *sRough);

#endif

/* End of code generation (call_StandardLayers.h) */
