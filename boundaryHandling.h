//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// boundaryHandling.h
//
// Code generation for function 'boundaryHandling'
//
#ifndef BOUNDARYHANDLING_H
#define BOUNDARYHANDLING_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void boundaryHandling(::coder::array<real_T, 2U> &x, const ::coder::array<
                        real_T, 2U> &paramInfo_min, const ::coder::array<real_T,
                        2U> &paramInfo_max, const char_T
                        paramInfo_boundhandling_data[], const int32_T
                        paramInfo_boundhandling_size[2]);
}

#endif

// End of code generation (boundaryHandling.h)
