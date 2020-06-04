/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resampleLayers.h
 *
 * Code generation for function 'resampleLayers'
 *
 */

#ifndef RESAMPLELAYERS_H
#define RESAMPLELAYERS_H

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
extern void resampleLayers(const emlrtStack *sp, const emxArray_real_T *layerSLD,
  emxArray_real_T *newSLD);

#endif

/* End of code generation (resampleLayers.h) */
