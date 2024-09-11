//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nest2pos.cpp
//
// Code generation for function 'nest2pos'
//

// Include files
#include "nest2pos.h"
#include "find.h"
#include "minOrMax.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void nest2pos(const ::coder::array<real_T, 2U> &nest_samples, real_T nLive, ::
                coder::array<real_T, 2U> &post_samples)
  {
    ::coder::array<real_T, 2U> b_nest_samples;
    ::coder::array<real_T, 2U> y;
    ::coder::array<real_T, 1U> b_i;
    ::coder::array<real_T, 1U> c_logWt;
    ::coder::array<real_T, 1U> logWt;
    ::coder::array<real_T, 1U> logrand;
    ::coder::array<int32_T, 1U> idx;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<boolean_T, 1U> b_logWt;
    real_T b;
    real_T logWtmax;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T result;
    int32_T sizes_idx_1;
    int8_T input_sizes_idx_1;
    boolean_T empty_non_axis_sizes;

    //
    //  post_samples = nest2pos(nest_samples, nLive)
    //
    //  Convert nested samples with nLive livepoints
    //  to samples from the posterior distribution
    //  (logL values in last column of nest_samples)
    //
    //  John Veitch 2009 (modified by J. Romano 2012)
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  calculate logWt = log(L*w) = logL + logw = logL - i/nLive
    b = static_cast<real_T>(nest_samples.size(0)) - nLive;
    if (std::isnan(b)) {
      sizes_idx_1 = 1;
    } else if (b < 1.0) {
      sizes_idx_1 = 0;
    } else if (std::isinf(b) && (1.0 == b)) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = static_cast<int32_T>(std::floor(b - 1.0)) + 1;
    }

    b = static_cast<real_T>(nest_samples.size(0)) - nLive;
    if (std::isnan(b)) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else if (b < 1.0) {
      y.set_size(1, 0);
    } else if (std::isinf(b) && (1.0 == b)) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else {
      loop_ub = static_cast<int32_T>(std::floor(b - 1.0));
      y.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        y[i] = static_cast<real_T>(i) + 1.0;
      }
    }

    b = static_cast<real_T>(nest_samples.size(0)) - nLive;
    i = static_cast<int32_T>(nLive) + sizes_idx_1;
    logWt.set_size(i);
    for (i1 = 0; i1 < sizes_idx_1; i1++) {
      logWt[i1] = nest_samples[i1 + nest_samples.size(0) * (nest_samples.size(1)
        - 1)] + -y[i1] / nLive;
    }

    loop_ub = i - sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      logWt[i + sizes_idx_1] = nest_samples[(sizes_idx_1 + i) +
        nest_samples.size(0) * (nest_samples.size(1) - 1)] + -b / nLive;
    }

    //  posterior samples are given by the normalized weight
    logWtmax = coder::internal::maximum(logWt);
    loop_ub = logWt.size(0);
    for (i = 0; i < loop_ub; i++) {
      logWt[i] = logWt[i] - logWtmax;
    }

    //  Wt -> Wt/Wtmax
    //  accept a nested sample as a posterior sample only if its
    //  value is > than a random number drawn from a unif distribution
    coder::b_rand(static_cast<real_T>(nest_samples.size(0)), b_i);
    logrand.set_size(b_i.size(0));
    loop_ub = b_i.size(0);
    for (i = 0; i < loop_ub; i++) {
      logrand[i] = b_i[i];
    }

    i = logrand.size(0);
    for (sizes_idx_1 = 0; sizes_idx_1 < i; sizes_idx_1++) {
      logrand[sizes_idx_1] = std::log(logrand[sizes_idx_1]);
    }

    b_logWt.set_size(logWt.size(0));
    loop_ub = logWt.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_logWt[i] = (logWt[i] > logrand[i]);
    }

    coder::eml_find(b_logWt, r);
    b_i.set_size(r.size(0));
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_i[i] = r[i];
    }

    b_logWt.set_size(logWt.size(0));
    loop_ub = logWt.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_logWt[i] = (logWt[i] > logrand[i]);
    }

    coder::eml_find(b_logWt, r);
    idx.set_size(r.size(0));
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      idx[i] = r[i];
    }

    //  attach log of posterior probabilities as final column of
    //  the posterior samples
    // post_samples(:,Ncol+1) = logWt(idx);
    if ((b_i.size(0) != 0) && (nest_samples.size(1) != 0)) {
      result = b_i.size(0);
    } else if (b_i.size(0) != 0) {
      result = idx.size(0);
    } else {
      result = 0;
      if (idx.size(0) > 0) {
        result = idx.size(0);
      }
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || ((b_i.size(0) != 0) && (nest_samples.size(1) !=
          0))) {
      input_sizes_idx_1 = static_cast<int8_T>(nest_samples.size(1));
    } else {
      input_sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || (b_i.size(0) != 0)) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }

    loop_ub = nest_samples.size(1);
    b_nest_samples.set_size(idx.size(0), nest_samples.size(1));
    for (i = 0; i < loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = idx.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_nest_samples[i1 + b_nest_samples.size(0) * i] = nest_samples[(idx[i1]
          + nest_samples.size(0) * i) - 1];
      }
    }

    c_logWt.set_size(b_i.size(0));
    loop_ub = b_i.size(0);
    for (i = 0; i < loop_ub; i++) {
      c_logWt[i] = logWt[static_cast<int32_T>(b_i[i]) - 1];
    }

    post_samples.set_size(result, input_sizes_idx_1 + sizes_idx_1);
    loop_ub = input_sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < result; i1++) {
        post_samples[i1 + post_samples.size(0) * i] = b_nest_samples[i1 + result
          * i];
      }
    }

    for (i = 0; i < sizes_idx_1; i++) {
      for (i1 = 0; i1 < result; i1++) {
        post_samples[i1 + post_samples.size(0) * input_sizes_idx_1] = c_logWt[i1];
      }
    }
  }
}

// End of code generation (nest2pos.cpp)
