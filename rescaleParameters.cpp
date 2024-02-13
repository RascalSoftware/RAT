//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rescaleParameters.cpp
//
// Code generation for function 'rescaleParameters'
//

// Include files
#include "rescaleParameters.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void rescaleParameters(const ::coder::array<real_T, 2U> &prior, const ::coder::
    array<real_T, 2U> &params, ::coder::array<real_T, 1U> &scaled)
  {
    int32_T i;
    int32_T loop_ub;

    //  scaled = rescaleParameters(prior, params)
    //
    //  This function will do the reverse of scaleParameters.
    scaled.set_size(params.size(1));
    loop_ub = params.size(1);
    for (i = 0; i < loop_ub; i++) {
      scaled[i] = 0.0;
    }

    i = params.size(1);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      real_T priortype;
      priortype = prior[b_i];
      if (priortype == 1.0) {
        real_T p3;

        // uniform
        p3 = prior[b_i + prior.size(0) * 3];
        scaled[b_i] = params[b_i] * (prior[b_i + prior.size(0) * 4] - p3) + p3;
      } else if (priortype == 2.0) {
        // gaussian
        scaled[b_i] = params[b_i] * prior[b_i + prior.size(0) * 2] + prior[b_i +
          prior.size(0)];
      } else if (priortype == 3.0) {
        real_T scaled_tmp;

        // jeffreys
        scaled_tmp = std::log10(prior[b_i + prior.size(0)]);
        scaled[b_i] = rt_powd_snf(10.0, params[b_i] * (std::log10(prior[b_i +
          prior.size(0) * 2]) - scaled_tmp) + scaled_tmp);
      }
    }
  }
}

// End of code generation (rescaleParameters.cpp)
