//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calcDensity.h
//
// Code generation for function 'calcDensity'
//
#ifndef CALCDENSITY_H
#define CALCDENSITY_H

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
  void calcDensity(const ::coder::array<double, 2U> &x, const ::coder::array<
                   double, 2U> &fx, const DreamParams *DREAMPar, const ::coder::
                   array<double, 2U> &ratInputs_problemStruct_fitLimits, const ::
                   coder::array<double, 2U> &ratInputs_priors, ::coder::array<
                   double, 1U> &log_L, ::coder::array<double, 1U> &log_PR);
}

#endif

// End of code generation (calcDensity.h)
