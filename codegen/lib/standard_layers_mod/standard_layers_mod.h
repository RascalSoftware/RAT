/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standard_layers_mod.h
 *
 * Code generation for function 'standard_layers_mod'
 *
 */

#ifndef STANDARD_LAYERS_MOD_H
#define STANDARD_LAYERS_MOD_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "standard_layers_mod_types.h"

/* Function Declarations */
extern void standard_layers_mod(const emxArray_real_T *params, const double
  contrastLayers[2], double numberOfLayers, const emxArray_cell_wrap_0
  *layersDetails, double layersOutput_data[], int layersOutput_size[2], double
  *sRoughOutput);

#endif

/* End of code generation (standard_layers_mod.h) */
