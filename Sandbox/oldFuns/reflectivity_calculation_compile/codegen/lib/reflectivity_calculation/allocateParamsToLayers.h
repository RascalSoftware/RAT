//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: allocateParamsToLayers.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
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
  coder::array<cell_wrap_2, 1U> &layersDetails, coder::array<cell_wrap_16, 2U>
  &outLayers);

#endif

//
// File trailer for allocateParamsToLayers.h
//
// [EOF]
//
