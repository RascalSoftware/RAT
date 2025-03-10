//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// randn.h
//
// Code generation for function 'randn'
//
#ifndef RANDN_H
#define RANDN_H

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
    void randn(double varargin_2, ::coder::array<double, 2U> &r);
    void randn(double varargin_1, ::coder::array<double, 1U> &r);
    void randn(double r[2]);
    void randn(double varargin_1, double varargin_2, ::coder::array<double, 2U>
               &r);
  }
}

#endif

// End of code generation (randn.h)
