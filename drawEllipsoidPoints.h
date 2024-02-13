//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// drawEllipsoidPoints.h
//
// Code generation for function 'drawEllipsoidPoints'
//
#ifndef DRAWELLIPSOIDPOINTS_H
#define DRAWELLIPSOIDPOINTS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void drawEllipsoidPoints(const ::coder::array<real_T, 2U> &B, const ::coder::
    array<real_T, 2U> &mu, ::coder::array<real_T, 2U> &pnts);
}

#endif

// End of code generation (drawEllipsoidPoints.h)
