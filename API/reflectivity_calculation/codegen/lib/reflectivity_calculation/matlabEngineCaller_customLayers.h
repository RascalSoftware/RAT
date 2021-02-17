//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: matlabEngineCaller_customLayers.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef MATLABENGINECALLER_CUSTOMLAYERS_H
#define MATLABENGINECALLER_CUSTOMLAYERS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void matlabEngineCaller_customLayers(const coder::array<double, 2U>
  &params, double contrast, const coder::array<char, 2U> &funcName, const coder::
  array<char, 2U> &funcPath, double bulkIn, double bulkOut, coder::array<double,
  2U> &output, double *sRough);

#endif

//
// File trailer for matlabEngineCaller_customLayers.h
//
// [EOF]
//
