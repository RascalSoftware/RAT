//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// scaledGaussPrior.h
//
// Code generation for function 'scaledGaussPrior'
//
#ifndef SCALEDGAUSSPRIOR_H
#define SCALEDGAUSSPRIOR_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  real_T scaledGaussPrior(const ::coder::array<real_T, 2U> &m, const ::coder::
    array<real_T, 2U> &extras_problemStruct_fitLimits, const ::coder::array<
    real_T, 2U> &extras_priors);
}

#endif

// End of code generation (scaledGaussPrior.h)
