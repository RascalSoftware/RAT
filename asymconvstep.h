//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// asymconvstep.h
//
// Code generation for function 'asymconvstep'
//
#ifndef ASYMCONVSTEP_H
#define ASYMCONVSTEP_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void asymconvstep(const ::coder::array<real_T, 2U> &x, real_T xw, real_T xcen,
                    real_T s1, real_T s2, real_T h, ::coder::array<real_T, 2U>
                    &f);
  void asymconvstep(const ::coder::array<real_T, 2U> &x, real_T xw, real_T xcen,
                    real_T s1, real_T s2, ::coder::array<real_T, 2U> &f);
}

#endif

// End of code generation (asymconvstep.h)
