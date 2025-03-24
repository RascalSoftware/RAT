//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void interp1(const ::coder::array<double, 1U> &varargin_1, const ::coder::
                 array<double, 1U> &varargin_2, const ::coder::array<double, 1U>
                 &varargin_3, ::coder::array<double, 1U> &Vq);
    void interp1(const ::coder::array<double, 1U> &varargin_1, const ::coder::
                 array<double, 1U> &varargin_2, const ::coder::array<double, 2U>
                 &varargin_3, ::coder::array<double, 2U> &Vq);
  }
}

#endif

// End of code generation (interp1.h)
