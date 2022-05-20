/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * callReflectivity.h
 *
 * Code generation for function 'callReflectivity'
 *
 */

#pragma once

/* Include files */
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs,
  const real_T simLimits_data[], const int32_T simLimits_size[2], const real_T
  repeatLayers[2], const emxArray_real_T *this_data, const emxArray_real_T
  *layers, real_T ssubs, real_T res, emxArray_real_T *reflectivity,
  emxArray_real_T *Simulation);
void callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs, const
                      real_T simLimits_data[], const int32_T simLimits_size[2],
                      const real_T repeatLayers[2], const emxArray_real_T
                      *this_data, const emxArray_real_T *layers, real_T ssubs,
                      real_T res, emxArray_real_T *reflectivity, emxArray_real_T
                      *Simulation);

/* End of code generation (callReflectivity.h) */
