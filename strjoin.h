//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strjoin.h
//
// Code generation for function 'strjoin'
//
#ifndef STRJOIN_H
#define STRJOIN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_1;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void strjoin(const ::coder::array<cell_wrap_1, 2U> &c, ::coder::array<char_T,
                 2U> &joinedStr);
  }
}

#endif

// End of code generation (strjoin.h)
