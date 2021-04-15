//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: adaptive.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//
#ifndef ADAPTIVE_H
#define ADAPTIVE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void calculateCentralAngles(const coder::array<double, 2U> &XYdata, const
  double dataBoxSize[2], coder::array<double, 1U> &cornerAngle);
extern void increaseSampling(coder::array<double, 2U> &dataPoints, const coder::
  array<boolean_T, 1U> &segmentsToSplit, const coder::array<double, 2U>
  &sldProfile);

#endif

//
// File trailer for adaptive.h
//
// [EOF]
//
