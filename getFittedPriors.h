//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// getFittedPriors.h
//
// Code generation for function 'getFittedPriors'
//
#ifndef GETFITTEDPRIORS_H
#define GETFITTEDPRIORS_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

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
