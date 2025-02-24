//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resolutionPolly.h
//
// Code generation for function 'resolutionPolly'
//
#ifndef RESOLUTIONPOLLY_H
#define RESOLUTIONPOLLY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void resolutionPolly(const ::coder::array<double, 1U> &xdata, const ::coder::
                       array<double, 1U> &ydata, const ::coder::array<double, 1U>
                       &resolutionValues, double points, ::coder::array<double,
                       1U> &resolutionCorrection);
}

#endif

// End of code generation (resolutionPolly.h)
