//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void randn(real_T varargin_2, ::coder::array<real_T, 2U> &r);
    void randn(real_T varargin_1, ::coder::array<real_T, 1U> &r);
    void randn(real_T r[2]);
    void randn(real_T varargin_1, real_T varargin_2, ::coder::array<real_T, 2U>
               &r);
  }
}

#endif

// End of code generation (randn.h)
