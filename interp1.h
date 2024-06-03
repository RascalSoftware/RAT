//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// interp1.h
//
// Code generation for function 'interp1'
//
#ifndef INTERP1_H
#define INTERP1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void interp1(const ::coder::array<real_T, 1U> &varargin_1, const ::coder::
                 array<real_T, 1U> &varargin_2, const ::coder::array<real_T, 2U>
                 &varargin_3, ::coder::array<real_T, 2U> &Vq);
    void interp1(const ::coder::array<real_T, 1U> &varargin_1, const ::coder::
                 array<real_T, 1U> &varargin_2, const ::coder::array<real_T, 1U>
                 &varargin_3, ::coder::array<real_T, 1U> &Vq);
  }
}

#endif

// End of code generation (interp1.h)
