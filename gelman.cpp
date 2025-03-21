//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// gelman.cpp
//
// Code generation for function 'gelman'
//

// Include files
#include "gelman.h"
#include "RATMain_types.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "var.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, double in2,
    double in3, const ::coder::array<double, 2U> &in4, double in5, const ::coder::
    array<double, 3U> &in6, const ::coder::array<double, 2U> &in7);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, double in2,
    double in3, const ::coder::array<double, 2U> &in4, double in5, const ::coder::
    array<double, 3U> &in6, const ::coder::array<double, 2U> &in7)
  {
    double c_in6;
    int b_in6;
    int loop_ub;
    int stride_0_1_tmp;
    int stride_1_1;
    b_in6 = in6.size(0);
    c_in6 = (static_cast<double>(in6.size(0)) - 1.0) / static_cast<double>
      (in6.size(2)) / static_cast<double>(in6.size(0));
    in1.set_size(1, in1.size(1));
    if (in4.size(1) == 1) {
      if (in7.size(1) == 1) {
        loop_ub = in4.size(1);
      } else {
        loop_ub = in7.size(1);
      }
    } else {
      loop_ub = in4.size(1);
    }

    in1.set_size(in1.size(0), loop_ub);
    stride_0_1_tmp = (in4.size(1) != 1);
    stride_1_1 = (in7.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      double d;
      d = in4[i * stride_0_1_tmp];
      in1[i] = in2 * (in3 * d + in5 * (static_cast<double>(b_in6) * in7[i *
        stride_1_1])) / d - c_in6;
    }
  }

  void gelman(const ::coder::array<double, 3U> &chain, const DreamParams &
              DREAMPar, ::coder::array<double, 2U> &R_stat)
  {
    ::coder::array<double, 3U> r1;
    ::coder::array<double, 2U> W;
    ::coder::array<double, 2U> b_chain;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> var_chain;
    int b_loop_ub_tmp;
    int i;
    int loop_ub_tmp;

    //  ----------------------------------------------------
    //  For more information please refer to: Gelman, A. and D.R. Rubin, 1992.
    //  Inference from Iterative Simulation Using Multiple Chain,
    //  Statistical Science, Volume 7, Issue 4, 457-472.
    //  URL: https://www.jstor.org/stable/2246093
    //
    //  Written by Jasper A. Vrugt
    //  Los Alamos, August 2007
    //  ----------------------------------------------------
    //  Calculate the R-statistic convergence diagnostic.
    //
    //  Parameters
    //  ----------
    //  chain : array
    //      The Markov chains from the optimisation so far.
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //
    //  Returns
    //  -------
    //  R_stat
    //      The R-statistic convergence diagnostic for each parameter.
    //  Compute the dimensions of chain
    loop_ub_tmp = static_cast<int>(DREAMPar.nChains);
    b_loop_ub_tmp = static_cast<int>(DREAMPar.nParams);
    var_chain.set_size(loop_ub_tmp, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub_tmp; i1++) {
        var_chain[i1 + var_chain.size(0) * i] = 0.0;
      }
    }

    if (chain.size(0) < 10) {
      //  Set the R-statistic to a large value
      R_stat.set_size(1, b_loop_ub_tmp);
      for (i = 0; i < b_loop_ub_tmp; i++) {
        R_stat[i] = rtNaN;
      }
    } else {
      double a;
      double b_a;
      double c_a;
      int loop_ub;

      //  Step 1: Determine the _chainuence means
      //  Step 1: Determine the variance between the _chainuence means
      //  Step 2: Compute the variance of the various chain
      for (int zz{0}; zz < loop_ub_tmp; zz++) {
        loop_ub = chain.size(1);
        b_chain.set_size(chain.size(0), chain.size(1));
        for (i = 0; i < loop_ub; i++) {
          int b_loop_ub;
          b_loop_ub = chain.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            b_chain[i1 + b_chain.size(0) * i] = chain[(i1 + chain.size(0) * i) +
              chain.size(0) * chain.size(1) * zz];
          }
        }

        coder::var(b_chain, r);
        loop_ub = var_chain.size(1);
        for (i = 0; i < loop_ub; i++) {
          var_chain[zz + var_chain.size(0) * i] = r[i];
        }
      }

      //  Step 2: Calculate the average of the within _chainuence variances
      coder::mean(var_chain, W);

      //  Step 3: Estimate the target mean
      // mu = mean(mean_chain);
      //  Step 4: Estimate the target variance
      a = (static_cast<double>(chain.size(0)) - 1.0) / static_cast<double>
        (chain.size(0));
      b_a = 1.0 / static_cast<double>(chain.size(0));

      //  Step 5: Compute the R-statistic
      c_a = (static_cast<double>(chain.size(2)) + 1.0) / static_cast<double>
        (chain.size(2));
      coder::mean(chain, r1);
      loop_ub_tmp = chain.size(2);
      b_chain.set_size(chain.size(2), b_loop_ub_tmp);
      for (i = 0; i < b_loop_ub_tmp; i++) {
        for (int i1{0}; i1 < loop_ub_tmp; i1++) {
          b_chain[i1 + b_chain.size(0) * i] = r1[i + b_loop_ub_tmp * i1];
        }
      }

      coder::var(b_chain, r);
      if (W.size(1) == 1) {
        i = r.size(1);
      } else {
        i = W.size(1);
      }

      if ((W.size(1) == r.size(1)) && (i == W.size(1))) {
        double c_chain;
        c_chain = (static_cast<double>(chain.size(0)) - 1.0) / static_cast<
          double>(chain.size(2)) / static_cast<double>(chain.size(0));
        R_stat.set_size(1, W.size(1));
        loop_ub = W.size(1);
        for (i = 0; i < loop_ub; i++) {
          double d;
          d = W[i];
          R_stat[i] = c_a * (a * d + b_a * (static_cast<double>(chain.size(0)) *
            r[i])) / d - c_chain;
        }
      } else {
        binary_expand_op(R_stat, c_a, a, W, b_a, chain, r);
      }

      coder::c_sqrt(R_stat);
    }
  }
}

// End of code generation (gelman.cpp)
