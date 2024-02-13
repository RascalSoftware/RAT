//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// groupLayersModImaginary.h
//
// Code generation for function 'groupLayersModImaginary'
//
#ifndef GROUPLAYERSMODIMAGINARY_H
#define GROUPLAYERSMODIMAGINARY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void groupLayersModImaginary(const ::coder::array<real_T, 2U> &allLayers,
    real_T allRoughs, const char_T geometry_data[], const int32_T geometry_size
    [2], real_T bulkIns, real_T bulkOuts, ::coder::array<real_T, 2U> &outLayers,
    real_T *outSsubs);
}

#endif

// End of code generation (groupLayersModImaginary.h)
