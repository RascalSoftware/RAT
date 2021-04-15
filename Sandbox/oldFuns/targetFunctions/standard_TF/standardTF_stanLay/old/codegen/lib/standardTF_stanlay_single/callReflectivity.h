/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callReflectivity.h
 *
 * Code generation for function 'callReflectivity'
 *
 */

#ifndef CALLREFLECTIVITY_H
#define CALLREFLECTIVITY_H

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
extern void callReflectivity(double nbairs, double nbsubs, const double
  simLimits[2], const double repeatLayers[2], const emxArray_real_T *this_data,
  const emxArray_real_T *layers, double ssubs, double backgrounds, double res,
  emxArray_real_T *reflectivity, emxArray_real_T *Simulation);

#endif

/* End of code generation (callReflectivity.h) */
