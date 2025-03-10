//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void percentileConfidenceIntervals(const ::coder::array<double, 2U> &chain, ::
    coder::array<double, 2U> &confidenceIntervals_percentile95, ::coder::array<
    double, 2U> &confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &confidenceIntervals_mean);
}

#endif

// End of code generation (percentileConfidenceIntervals.h)
