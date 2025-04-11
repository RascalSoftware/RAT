//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// metropolisRule.cpp
//
// Code generation for function 'metropolisRule'
//

// Include files
#include "metropolisRule.h"
#include "RATMain_types.h"
#include "find.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void e_binary_expand_op(::coder::array<boolean_T, 1U> &in1, const ::
    coder::array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::
    coder::array<double, 1U> &in4);
  static void minus(::coder::array<double, 1U> &in1, const ::coder::array<double,
                    1U> &in2, const ::coder::array<double, 1U> &in3);
}

// Function Definitions
namespace RAT
{
  static void e_binary_expand_op(::coder::array<boolean_T, 1U> &in1, const ::
    coder::array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::
    coder::array<double, 1U> &in4)
  {
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    int stride_2_0;
    if (in4.size(0) == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = in4.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_2_0 = (in4.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = (in2[i * stride_0_0] * in3[i * stride_1_0] > in4[i * stride_2_0]);
    }
  }

  static void minus(::coder::array<double, 1U> &in1, const ::coder::array<double,
                    1U> &in2, const ::coder::array<double, 1U> &in3)
  {
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
    }
  }

  void metropolisRule(const DreamParams &DREAMPar, const ::coder::array<double,
                      1U> &log_L_xnew, const ::coder::array<double, 1U>
                      &log_PR_xnew, const ::coder::array<double, 1U> &log_L_xold,
                      const ::coder::array<double, 1U> &log_PR_xold, ::coder::
                      array<boolean_T, 1U> &accept, ::coder::array<double, 1U>
                      &idx_accept)
  {
    ::coder::array<double, 1U> Z;
    ::coder::array<double, 1U> r;
    ::coder::array<double, 1U> r1;
    ::coder::array<int, 1U> r2;
    ::coder::array<boolean_T, 1U> b_accept;
    int i;
    int k;

    //  Calculates candidate acceptance for each point using the Metropolis rule.
    //
    //  Parameters
    //  ----------
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //  log_L_xnew : array
    //      The log-likelihood of the proposed new point for each chain.
    //  log_PR_xnew : array
    //      The log-prior of the proposed new point for each chain.
    //  log_L_xold :  array
    //      The log-likelihood of the current newest point on the chain.
    //  log_PR_xold : array
    //      The log-prior of the current newest point on the chain.
    //
    //  Returns
    //  -------
    //  accept : array
    //      An array of bools of whether the proposal is accepted for each parameter.
    //  idx_accept : array
    //      The parameter indices for which proposals were accepted.
    //
    //  No ABC --> regular MCMC with prior and likelihood
    //  Calculate the likelihood ratio
    //  Calculate the prior ratio
    //  Calculate product of two probability ratios
    //  Generate random numbers
    coder::b_rand(DREAMPar.nChains, Z);

    //  Find which alfa's are greater than Z
    if (log_L_xnew.size(0) == log_L_xold.size(0)) {
      r.set_size(log_L_xnew.size(0));
      k = log_L_xnew.size(0);
      for (i = 0; i < k; i++) {
        r[i] = log_L_xnew[i] - log_L_xold[i];
      }
    } else {
      minus(r, log_L_xnew, log_L_xold);
    }

    i = r.size(0);
    for (k = 0; k < i; k++) {
      r[k] = std::exp(r[k]);
    }

    if (log_PR_xnew.size(0) == log_PR_xold.size(0)) {
      r1.set_size(log_PR_xnew.size(0));
      k = log_PR_xnew.size(0);
      for (i = 0; i < k; i++) {
        r1[i] = log_PR_xnew[i] - log_PR_xold[i];
      }
    } else {
      minus(r1, log_PR_xnew, log_PR_xold);
    }

    i = r1.size(0);
    for (k = 0; k < i; k++) {
      r1[k] = std::exp(r1[k]);
    }

    if (r.size(0) == 1) {
      i = r1.size(0);
    } else {
      i = r.size(0);
    }

    if ((r.size(0) == r1.size(0)) && (i == Z.size(0))) {
      accept.set_size(r.size(0));
      k = r.size(0);
      for (i = 0; i < k; i++) {
        accept[i] = (r[i] * r1[i] > Z[i]);
      }
    } else {
      e_binary_expand_op(accept, r, r1, Z);
    }

    //  ABC --> check if summary metrics as prior (diagnostic Bayes) or likelihood (regular ABC)
    //  Now derive which proposals to accept (row numbers of X)
    b_accept.set_size(accept.size(0));
    k = accept.size(0);
    for (i = 0; i < k; i++) {
      b_accept[i] = accept[i];
    }

    coder::eml_find(b_accept, r2);
    idx_accept.set_size(r2.size(0));
    k = r2.size(0);
    for (i = 0; i < k; i++) {
      idx_accept[i] = r2[i];
    }
  }
}

// End of code generation (metropolisRule.cpp)
