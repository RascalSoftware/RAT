//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void boundaryHandling(::coder::array<double, 2U> &x, const ::coder::array<
                        double, 2U> &paramInfo_min, const ::coder::array<double,
                        2U> &paramInfo_max, const char
                        paramInfo_boundhandling_data[], const int
                        paramInfo_boundhandling_size[2]);
}

#endif

// End of code generation (boundaryHandling.h)
