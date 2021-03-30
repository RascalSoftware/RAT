//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: resolution_polly_paraPoints.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//
#ifndef RESOLUTION_POLLY_PARAPOINTS_H
#define RESOLUTION_POLLY_PARAPOINTS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void resolution_polly_paraPoints(const coder::array<double, 1U> &xdata,
  const coder::array<double, 1U> &ydata, double res, double points, coder::array<
  double, 1U> &out);

#endif

//
// File trailer for resolution_polly_paraPoints.h
//
// [EOF]
//
