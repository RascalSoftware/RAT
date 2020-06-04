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
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void callReflectivity(double nbairs, double nbsubs, const double
  simLimits[2], const double repeatLayers[2], const double this_data_data[],
  const int this_data_size[2], const emxArray_real_T *layers, double ssubs,
  double backgrounds, double res, double reflectivity_data[], int
  reflectivity_size[2], emxArray_real_T *Simulation);

#endif

/* End of code generation (callReflectivity.h) */
