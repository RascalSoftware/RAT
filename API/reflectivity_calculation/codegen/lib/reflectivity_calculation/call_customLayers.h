//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: call_customLayers.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef CALL_CUSTOMLAYERS_H
#define CALL_CUSTOMLAYERS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void call_customLayers(const coder::array<double, 2U> &params, double
  contrast, const coder::array<char, 2U> &file, const coder::array<char, 2U>
  &callPath, double bulkIn, double bulkOut, coder::array<double, 2U> &output,
  double *sRough);

#endif

//
// File trailer for call_customLayers.h
//
// [EOF]
//
