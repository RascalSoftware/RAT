//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// rescaleParameters.cpp
//
// Code generation for function 'rescaleParameters'
//

// Include files
#include "rescaleParameters.h"
#include "RATMain_rtwutil.h"
#include "erfinv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void rescaleParameters(const ::coder::array<double, 2U> &prior, const ::coder::
    array<double, 2U> &params, ::coder::array<double, 2U> &scaled)
  {
    int loop_ub;

    //  Convert a uniform value from the unit hypercube to a value from the parameter priors.
    //
    //  Parameters
    //  ----------
    //  prior : array
    //      The prior information for the parameters.
    //  params : array
    //      The values of the sample from the unit hypercube.
    //
    //  Returns
    //  -------
    //  scaled : array
    //      The values of ``params`` scaled to the priors.
    //
    scaled.set_size(1, params.size(1));
    loop_ub = params.size(1);
    for (int i{0}; i < loop_ub; i++) {
      double priortype;
      scaled[i] = 0.0;
      priortype = prior[i];
      if (priortype == 1.0) {
        double p3;

        // uniform
        p3 = prior[i + prior.size(0) * 3];
        scaled[i] = params[i] * (prior[i + prior.size(0) * 4] - p3) + p3;
      } else if (priortype == 2.0) {
        // gaussian
        //  we use inverse transform sampling
        scaled[i] = prior[i + prior.size(0)] + prior[i + prior.size(0) * 2] *
          1.4142135623730951 * coder::erfinv(2.0 * params[i] - 1.0);
      } else if (priortype == 3.0) {
        double d;

        // jeffreys
        d = std::log10(prior[i + prior.size(0) * 3]);
        scaled[i] = rt_powd_snf(10.0, params[i] * (std::log10(prior[i +
          prior.size(0) * 4]) - d) + d);
      }
    }
  }
}

// End of code generation (rescaleParameters.cpp)
