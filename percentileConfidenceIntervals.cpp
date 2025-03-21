//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// percentileConfidenceIntervals.cpp
//
// Code generation for function 'percentileConfidenceIntervals'
//

// Include files
#include "percentileConfidenceIntervals.h"
#include "blockedSummation.h"
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
    ::coder::array<double, 2U> r;
    int loop_ub;

    //  Calculate percentile confidence intervals for a chain.
    //
    //  Parameters
    //  ----------
    //  chain : array
    //      The chain from an MCMC calculation.
    //
    //  Returns
    //  -------
    //  confidenceIntervals : array
    //      The mean and the 65% and 95% confidence intervals for the chain.
    coder::prctile(chain, confidenceIntervals_percentile95);
    coder::b_prctile(chain, confidenceIntervals_percentile65);
    coder::blockedSummation(chain, chain.size(0), r);
    confidenceIntervals_mean.set_size(1, r.size(1));
    loop_ub = r.size(1);
    for (int i{0}; i < loop_ub; i++) {
      confidenceIntervals_mean[i] = r[i] / static_cast<double>(chain.size(0));
    }
  }
}

// End of code generation (percentileConfidenceIntervals.cpp)
