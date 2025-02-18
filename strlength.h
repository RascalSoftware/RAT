//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strlength.h
//
// Code generation for function 'strlength'
//
#ifndef STRLENGTH_H
#define STRLENGTH_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void intstrlen(const ::coder::array<cell_wrap_10, 2U> &s, int32_T len_data[],
                   int32_T len_size[2]);
  }
}

#endif

// End of code generation (strlength.h)
