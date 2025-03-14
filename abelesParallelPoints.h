//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// abelesParallelPoints.h
//
// Code generation for function 'abelesParallelPoints'
//
#ifndef ABELESPARALLELPOINTS_H
#define ABELESPARALLELPOINTS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void abelesParallelPoints(const ::coder::array<double, 1U> &q, double N, const
    ::coder::array<double, 1U> &layersThick, const ::coder::array<creal_T, 1U>
    &layersRho, const ::coder::array<double, 1U> &layersSigma, ::coder::array<
    double, 1U> &ref);
}

#endif

// End of code generation (abelesParallelPoints.h)
