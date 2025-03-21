//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, const int
    in4[2], double in5, double in6);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, const int
    in4[2], double in5, double in6)
  {
    ::coder::array<double, 1U> c_in2;
    int b_in2;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    b_in2 = in2.size(1);
    in1.set_size(static_cast<int>(in5) + in4[1]);
    loop_ub = in4[1];
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = -in3[i] / in5;
    }

    loop_ub = static_cast<int>(in5);
    for (int i{0}; i < loop_ub; i++) {
      in1[i + in4[1]] = -in6 / in5;
    }

    if (in1.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in1.size(0);
    }

    c_in2.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in1.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      c_in2[i] = in2[i * stride_0_0 + in2.size(0) * (b_in2 - 1)] + in1[i *
        stride_1_0];
    }

    in1.set_size(c_in2.size(0));
    loop_ub = c_in2.size(0);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = c_in2[i];
    }
  }

  void nest2pos(const ::coder::array<double, 2U> &nest_samples, double nLive, ::
                coder::array<double, 2U> &post_samples)
  {
    ::coder::array<double, 2U> b_nest_samples;
    ::coder::array<double, 2U> y;
    ::coder::array<double, 1U> b_y;
    ::coder::array<double, 1U> logWt;
    ::coder::array<int, 1U> idx;
    ::coder::array<boolean_T, 1U> b_logWt;
    double b_tmp;
    double logWtmax;
    int sizes[2];
    int i;
    int k;
    int result;
    signed char input_sizes_idx_1;
    boolean_T b;
    boolean_T empty_non_axis_sizes;

    //  John Veitch 2009 (modified by J. Romano 2012)
    //  Convert nested samples to samples from the posterior distribution.
    //
    //  Parameters
    //  ----------
    //  nest_samples : array
    //      The samples from the nested sampler.
    //  nLive : int
    //      The number of live points.
    //
    //  Returns
    //  -------
    //  post_samples
    //      The samples from the posterior distribution for each of ``nest_samples``.
    //  calculate logWt = log(L*w) = logL + logw = logL - i/nLive
    b_tmp = static_cast<double>(nest_samples.size(0)) - nLive;
    if (std::isnan(b_tmp)) {
      sizes[0] = 1;
      sizes[1] = 1;
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else if (b_tmp < 1.0) {
      sizes[0] = 1;
      sizes[1] = 0;
      y.set_size(1, 0);
    } else {
      sizes[0] = 1;
      k = static_cast<int>(b_tmp - 1.0) + 1;
      sizes[1] = static_cast<int>(b_tmp - 1.0) + 1;
      y.set_size(1, k);
      k = static_cast<int>(b_tmp - 1.0);
      for (i = 0; i <= k; i++) {
        y[i] = static_cast<double>(i) + 1.0;
      }
    }

    i = static_cast<int>(nLive) + sizes[1];
    if (nest_samples.size(0) == i) {
      b_y.set_size(i);
      k = sizes[1];
      for (i = 0; i < k; i++) {
        b_y[i] = -y[i] / nLive;
      }

      k = static_cast<int>(nLive);
      for (i = 0; i < k; i++) {
        b_y[i + sizes[1]] = -b_tmp / nLive;
      }

      logWt.set_size(nest_samples.size(0));
      k = nest_samples.size(0);
      for (i = 0; i < k; i++) {
        logWt[i] = nest_samples[i + nest_samples.size(0) * (nest_samples.size(1)
          - 1)] + b_y[i];
      }
    } else {
      binary_expand_op(logWt, nest_samples, y, sizes, nLive, b_tmp);
    }

    //  posterior samples are given by the normalized weight
    logWtmax = coder::internal::maximum(logWt);
    k = logWt.size(0);
    for (i = 0; i < k; i++) {
      logWt[i] = logWt[i] - logWtmax;
    }

    //  Wt -> Wt/Wtmax
    //  accept a nested sample as a posterior sample only if its
    //  value is > than a random number drawn from a unif distribution
    coder::b_rand(static_cast<double>(nest_samples.size(0)), b_y);
    i = b_y.size(0);
    for (k = 0; k < i; k++) {
      b_y[k] = std::log(b_y[k]);
    }

    if (logWt.size(0) == b_y.size(0)) {
      b_logWt.set_size(logWt.size(0));
      k = logWt.size(0);
      for (i = 0; i < k; i++) {
        b_logWt[i] = (logWt[i] > b_y[i]);
      }

      coder::eml_find(b_logWt, idx);
    } else {
      binary_expand_op(idx, logWt, b_y);
    }

    //  attach log of posterior probabilities as final column of
    //  the posterior samples
    // post_samples(:,Ncol+1) = logWt(idx);
    b = ((idx.size(0) != 0) && (nest_samples.size(1) != 0));
    if (b) {
      result = idx.size(0);
    } else if (idx.size(0) != 0) {
      result = idx.size(0);
    } else {
      result = 0;
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || b) {
      input_sizes_idx_1 = static_cast<signed char>(nest_samples.size(1));
    } else {
      input_sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || (idx.size(0) != 0)) {
      sizes[1] = 1;
    } else {
      sizes[1] = 0;
    }

    b_nest_samples.set_size(idx.size(0), nest_samples.size(1));
    k = nest_samples.size(1);
    for (i = 0; i < k; i++) {
      int loop_ub;
      loop_ub = idx.size(0);
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_nest_samples[i1 + b_nest_samples.size(0) * i] = nest_samples[(idx[i1]
          + nest_samples.size(0) * i) - 1];
      }
    }

    b_y.set_size(idx.size(0));
    k = idx.size(0);
    for (i = 0; i < k; i++) {
      b_y[i] = logWt[idx[i] - 1];
    }

    post_samples.set_size(result, input_sizes_idx_1 + sizes[1]);
    k = input_sizes_idx_1;
    for (i = 0; i < k; i++) {
      for (int i1{0}; i1 < result; i1++) {
        post_samples[i1 + post_samples.size(0) * i] = b_nest_samples[i1 + result
          * i];
      }
    }

    k = sizes[1];
    for (i = 0; i < k; i++) {
      for (int i1{0}; i1 < result; i1++) {
        post_samples[i1 + post_samples.size(0) * input_sizes_idx_1] = b_y[i1];
      }
    }
  }
}

// End of code generation (nest2pos.cpp)
