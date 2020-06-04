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
extern void call_StandardLayers(const emlrtStack *sp, const emxArray_real_T
  *params, const emxArray_real_T *contrastLayers, real_T numberOfLayers, const
  emxArray_cell_wrap_0 *layersDetails, emxArray_real_T *layersList, real_T
  *sRough);

#endif

/* End of code generation (call_StandardLayers.h) */
