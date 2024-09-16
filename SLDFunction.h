//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// SLDFunction.h
//
// Code generation for function 'SLDFunction'
//
#ifndef SLDFUNCTION_H
#define SLDFUNCTION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void SLDFunction(real_T x, const ::coder::array<real_T, 2U> &SLD, ::coder::
                   array<real_T, 1U> &sldVal);
  void b_SLDFunction(real_T x, const ::coder::array<real_T, 2U> &SLD, ::coder::
                     array<real_T, 1U> &sldVal);
}

#endif

// End of code generation (SLDFunction.h)
