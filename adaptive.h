//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_58;
}

// Function Declarations
namespace RAT
{
  void adaptive(const ::coder::array<real_T, 2U> &sldProfile, const real_T
                startDomain[2], real_T minAngle, real_T nPoints, cell_58 *out);
  void b_adaptive(const ::coder::array<real_T, 2U> &sldProfile, const real_T
                  startDomain[2], real_T minAngle, real_T nPoints, cell_58 *out);
}

#endif

// End of code generation (adaptive.h)
