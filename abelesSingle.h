//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void abelesSingle(const ::coder::array<real_T, 1U> &q, real_T N, const ::coder::
                    array<real_T, 1U> &layers_thick, const ::coder::array<
                    creal_T, 1U> &layers_rho, const ::coder::array<real_T, 1U>
                    &layers_sig, ::coder::array<real_T, 1U> &ref);
}

#endif

// End of code generation (abelesSingle.h)
