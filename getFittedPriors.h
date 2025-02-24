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
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  void getFittedPriors(const ::coder::array<cell_wrap_10, 1U> &paramNames, const
                       ::coder::array<cell_wrap_10, 1U> &priorNames, const ::
                       coder::array<double, 2U> &priorValues, const ::coder::
                       array<double, 2U> &fitLimits, ::coder::array<double, 2U>
                       &priorFitList);
}

#endif

// End of code generation (getFittedPriors.h)
