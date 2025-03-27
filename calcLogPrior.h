//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcLogPrior.h
//
// Code generation for function 'calcLogPrior'
//
#ifndef CALCLOGPRIOR_H
#define CALCLOGPRIOR_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void calcLogPrior(::coder::array<double, 2U> &x, const ::coder::array<double,
                    2U> &priors, ::coder::array<double, 1U> &log_PR);
}

#endif

// End of code generation (calcLogPrior.h)
