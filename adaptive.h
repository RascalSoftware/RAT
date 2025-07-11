//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// adaptive.h
//
// Code generation for function 'adaptive'
//
#ifndef ADAPTIVE_H
#define ADAPTIVE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_52;
}

// Function Declarations
namespace RAT
{
  void adaptive(const ::coder::array<double, 2U> &sldProfile, const double
                startDomain[2], double minAngle, double nPoints, cell_52 &out);
}

#endif

// End of code generation (adaptive.h)
