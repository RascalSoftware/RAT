//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// percentileConfidenceIntervals.cpp
//
// Code generation for function 'percentileConfidenceIntervals'
//

// Include files
#include "percentileConfidenceIntervals.h"
#include "mean.h"
#include "prctile.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void percentileConfidenceIntervals(const ::coder::array<double, 2U> &chain, ::
    coder::array<double, 2U> &confidenceIntervals_percentile95, ::coder::array<
    double, 2U> &confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &confidenceIntervals_mean)
  {
    coder::prctile(chain, confidenceIntervals_percentile95);
    coder::b_prctile(chain, confidenceIntervals_percentile65);
    coder::mean(chain, confidenceIntervals_mean);
  }
}

// End of code generation (percentileConfidenceIntervals.cpp)
