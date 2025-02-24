//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// metropolisRule.h
//
// Code generation for function 'metropolisRule'
//
#ifndef METROPOLISRULE_H
#define METROPOLISRULE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
}

// Function Declarations
namespace RAT
{
  void metropolisRule(const DreamParams *DREAMPar, const ::coder::array<double,
                      1U> &log_L_xnew, const ::coder::array<double, 1U>
                      &log_PR_xnew, const ::coder::array<double, 1U> &log_L_xold,
                      const ::coder::array<double, 1U> &log_PR_xold, ::coder::
                      array<boolean_T, 1U> &accept, ::coder::array<double, 1U>
                      &idx_accept);
}

#endif

// End of code generation (metropolisRule.h)
