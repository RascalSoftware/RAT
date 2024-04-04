//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// percentileConfidenceIntervals.h
//
// Code generation for function 'percentileConfidenceIntervals'
//
#ifndef PERCENTILECONFIDENCEINTERVALS_H
#define PERCENTILECONFIDENCEINTERVALS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void percentileConfidenceIntervals(const ::coder::array<real_T, 2U> &chain, ::
    coder::array<real_T, 2U> &confidenceIntervals_percentile95, ::coder::array<
    real_T, 2U> &confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &confidenceIntervals_mean);
}

#endif

// End of code generation (percentileConfidenceIntervals.h)
