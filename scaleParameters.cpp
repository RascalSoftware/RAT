//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// scaleParameters.cpp
//
// Code generation for function 'scaleParameters'
//

// Include files
#include "scaleParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void scaleParameters(const ::coder::array<double, 2U> &prior, const ::coder::
                       array<double, 2U> &params, ::coder::array<double, 1U>
                       &scaled)
  {
    int i;
    int loop_ub;

    //  scaled = scaleParameters(prior, params)
    //
    //  This function will scale parameters based on their priors. If a prior is
    //  uniform over a range then the parameter will be scaled, such that the
    //  range covers 0->1. If a prior is Gaussian then the parameter will be
    //  scaled such that it will be a Gaussian with zero mean and unit variance.
    scaled.set_size(params.size(1));
    loop_ub = params.size(1);
    for (i = 0; i < loop_ub; i++) {
      scaled[i] = 0.0;
    }

    i = params.size(1);
    for (int b_i{0}; b_i < i; b_i++) {
      double priortype;
      priortype = prior[b_i];
      if (priortype == 1.0) {
        double p3;

        // uniform
        p3 = prior[b_i + prior.size(0) * 3];
        scaled[b_i] = (params[b_i] - p3) / (prior[b_i + prior.size(0) * 4] - p3);
      } else if (priortype == 2.0) {
        // gaussian
        scaled[b_i] = (params[b_i] - prior[b_i + prior.size(0)]) / prior[b_i +
          prior.size(0) * 2];
      } else if (priortype == 3.0) {
        double scaled_tmp;

        // jeffreys
        scaled_tmp = std::log10(prior[b_i + prior.size(0)]);
        scaled[b_i] = (std::log10(params[b_i]) - scaled_tmp) / (std::log10
          (prior[b_i + prior.size(0) * 2]) - scaled_tmp);
      }
    }

    //      priortype = char(prior(i,2));
    //      p3 = prior{i,3};
    //      p4 = prior{i,4};
    //
    //      % currently only handles uniform or Gaussian priors
    //      if strcmp(priortype, coderEnums.priorTypes.Uniform)
    //          scaled(i) = (params(i) - p3)/(p4 - p3);
    //      elseif strcmp(priortype, coderEnums.priorTypes.Gaussian)
    //          scaled(i) = (params(i) - p3)/p4;
    //      elseif strcmp(priortype, coderEnums.priorTypes.Jeffreys)
    //          scaled(i) = (log10(params(i)) - log10(p3))/(log10(p4) - log10(p3));
    //      end
  }
}

// End of code generation (scaleParameters.cpp)
