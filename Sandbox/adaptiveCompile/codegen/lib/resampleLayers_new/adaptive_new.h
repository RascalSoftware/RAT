/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive_new.h
 *
 * Code generation for function 'adaptive_new'
 *
 */

#ifndef ADAPTIVE_NEW_H
#define ADAPTIVE_NEW_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "resampleLayers_new_types.h"

/* Function Declarations */
extern void calculateCentralAngles(const emxArray_real_T *XYdata, const double
  dataBoxSize[2], emxArray_real_T *cornerAngle);
extern void increaseSampling(emxArray_real_T *dataPoints, const
  emxArray_boolean_T *segmentsToSplit, const emxArray_real_T *sldProfile);

#endif

/* End of code generation (adaptive_new.h) */
