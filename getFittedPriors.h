//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// getFittedPriors.h
//
// Code generation for function 'getFittedPriors'
//
#ifndef GETFITTEDPRIORS_H
#define GETFITTEDPRIORS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_8;
}

// Function Declarations
namespace RAT
{
  void getFittedPriors(const ::coder::array<cell_wrap_8, 1U> &paramNames, const ::
                       coder::array<cell_wrap_8, 1U> &priors_priorNames, const ::
                       coder::array<real_T, 2U> &priors_priorValues, const ::
                       coder::array<real_T, 2U> &fitLimits, ::coder::array<
                       real_T, 2U> &priorFitList);
}

#endif

// End of code generation (getFittedPriors.h)
