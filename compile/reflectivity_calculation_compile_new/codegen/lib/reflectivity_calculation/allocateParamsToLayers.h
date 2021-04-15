//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: allocateParamsToLayers.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef ALLOCATEPARAMSTOLAYERS_H
#define ALLOCATEPARAMSTOLAYERS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void allocateParamsToLayers(const coder::array<double, 2U> &params, const
  coder::array<cell_wrap_2, 1U> &layersDetails, coder::array<cell_wrap_15, 2U>
  &outLayers);

#endif

//
// File trailer for allocateParamsToLayers.h
//
// [EOF]
//
