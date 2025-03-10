//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// abelesSingle.h
//
// Code generation for function 'abelesSingle'
//
#ifndef ABELESSINGLE_H
#define ABELESSINGLE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void abelesSingle(const ::coder::array<double, 1U> &q, double N, const ::coder::
                    array<double, 1U> &layers_thick, const ::coder::array<
                    creal_T, 1U> &layers_rho, const ::coder::array<double, 1U>
                    &layers_sig, ::coder::array<double, 1U> &ref);
}

#endif

// End of code generation (abelesSingle.h)
