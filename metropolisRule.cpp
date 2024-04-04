//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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

// Function Definitions
namespace RAT
{
  void metropolisRule(const struct12_T *DREAMPar, const ::coder::array<real_T,
                      1U> &log_L_xnew, const ::coder::array<real_T, 1U>
                      &log_PR_xnew, const ::coder::array<real_T, 1U> &log_L_xold,
                      const ::coder::array<real_T, 1U> &log_PR_xold, ::coder::
                      array<boolean_T, 1U> &accept, ::coder::array<real_T, 1U>
                      &idx_accept)
  {
    ::coder::array<real_T, 1U> Z;
    ::coder::array<real_T, 1U> r;
    ::coder::array<real_T, 1U> r1;
    ::coder::array<int32_T, 1U> r2;
    ::coder::array<boolean_T, 1U> b_accept;
    int32_T i;
    int32_T k;

    //  Metropolis rule for acceptance or rejection
    //  No ABC --> regular MCMC with prior and likelihood
    //  Calculate the likelihood ratio
    //  Calculate the prior ration
    //  Calculate product of two probabily ratios
    //  Generate random numbers
    coder::b_rand(DREAMPar->nChains, Z);

    //  Find which alfa's are greater than Z
    r.set_size(log_L_xnew.size(0));
    k = log_L_xnew.size(0);
    for (i = 0; i < k; i++) {
      r[i] = log_L_xnew[i] - log_L_xold[i];
    }

    i = r.size(0);
    for (k = 0; k < i; k++) {
      r[k] = std::exp(r[k]);
    }

    r1.set_size(log_PR_xnew.size(0));
    k = log_PR_xnew.size(0);
    for (i = 0; i < k; i++) {
      r1[i] = log_PR_xnew[i] - log_PR_xold[i];
    }

    i = r1.size(0);
    for (k = 0; k < i; k++) {
      r1[k] = std::exp(r1[k]);
    }

    accept.set_size(r.size(0));
    k = r.size(0);
    for (i = 0; i < k; i++) {
      accept[i] = (r[i] * r1[i] > Z[i]);
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
