//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// dataResolutionPolly.h
//
// Code generation for function 'dataResolutionPolly'
//
#ifndef DATARESOLUTIONPOLLY_H
#define DATARESOLUTIONPOLLY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void dataResolutionPolly(const ::coder::array<real_T, 1U> &xdata, const ::
    coder::array<real_T, 1U> &ydata, const ::coder::array<real_T, 1U> &resData,
    real_T points, ::coder::array<real_T, 1U> &out);
}

#endif

// End of code generation (dataResolutionPolly.h)
