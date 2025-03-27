//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcLogPrior.cpp
//
// Code generation for function 'calcLogPrior'
//

// Include files
#include "calcLogPrior.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void calcLogPrior(::coder::array<double, 2U> &x, const ::coder::array<double,
                    2U> &priors, ::coder::array<double, 1U> &log_PR)
  {
    ::coder::array<double, 1U> r;
    int i;

    //  Calculate the log-prior over a set of points.
    //
    //  Parameters
    //  ----------
    //  x : array
    //      A [nChains x nParams] array, where each row is a point in parameter
    //      space.
    //  priors : array
    //      The RAT input prior array, which is an [nParams x 5] array, where row
    //      ``i`` is the prior type, mu, sigma, min, max for parameter ``i``.
    //
    //  Returns
    //  -------
    //  log_PR : array
    //      An [nChains x 1] array of the log-prior for each point.
    //
    //  Our prior is independent for each parameter,
    //  so for point (x1, ... xn) in parameter space,
    //  log(pr(x1, ... xn)) = log(pr1(x1)) + log(pr2(x2)) + ...
    //  where pr1 is the prior for parameter 1, etc.
    //  useful constant for gaussian priors
    //  first calculate log(pri(xi)) for each parameter
    //  we iterate over dimensions as each dimension has consistent prior
    i = priors.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double d;
      d = priors[b_i];
      if (d == 1.0) {
        double b_x;
        int k;

        //  uniform
        b_x = std::log(priors[b_i + priors.size(0) * 4] - priors[b_i +
                       priors.size(0) * 3]);
        k = x.size(0);
        for (int i1{0}; i1 < k; i1++) {
          x[i1 + x.size(0) * b_i] = -b_x;
        }
      } else if (d == 2.0) {
        double b_priors;
        double b_x;
        int k;

        //  gaussian
        //  log of Gaussian is -(x - mu)^2 / 2 sigma^2 - log(sqrt(2pi)*sigma)
        d = priors[b_i + priors.size(0) * 2];
        b_x = std::log(2.5066282746310002 * d);
        b_priors = priors[b_i + priors.size(0)];
        d = 2.0 * (d * d);
        r.set_size(x.size(0));
        k = x.size(0);
        for (int i1{0}; i1 < k; i1++) {
          double varargin_1;
          varargin_1 = x[i1 + x.size(0) * b_i] - b_priors;
          r[i1] = -(varargin_1 * varargin_1 / d) - b_x;
        }

        k = r.size(0);
        for (int i1{0}; i1 < k; i1++) {
          x[i1 + x.size(0) * b_i] = r[i1];
        }
      } else if (d == 3.0) {
        double b_x;
        int i1;
        int k;

        //  jeffreys (1/x with a normalisation constant)
        b_x = std::log(std::log(priors[b_i + priors.size(0) * 4] / priors[b_i +
          priors.size(0) * 3]));
        k = x.size(0);
        r.set_size(x.size(0));
        for (i1 = 0; i1 < k; i1++) {
          r[i1] = x[i1 + x.size(0) * b_i];
        }

        i1 = r.size(0);
        for (k = 0; k < i1; k++) {
          r[k] = std::log(r[k]);
        }

        k = x.size(0);
        for (i1 = 0; i1 < k; i1++) {
          x[i1 + x.size(0) * b_i] = -b_x - r[i1];
        }
      }
    }

    //  finally, sum log(pr1(x1)) + log(pr2(x2)) + ... to get log(pr) for each chain
    coder::blockedSummation(x, x.size(1), log_PR);
  }
}

// End of code generation (calcLogPrior.cpp)
