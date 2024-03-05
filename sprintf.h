//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sprintf.h
//
// Code generation for function 'sprintf'
//
#ifndef SPRINTF_H
#define SPRINTF_H

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
    void b_sprintf(real_T varargin_1, real_T varargin_2, ::coder::array<char_T,
                   2U> &str);
  }
}

#endif

// End of code generation (sprintf.h)
