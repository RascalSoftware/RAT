//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// lower.h
//
// Code generation for function 'lower'
//
#ifndef LOWER_H
#define LOWER_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void lower(const char_T x_data[], const int32_T x_size[2], char_T y_data[],
               int32_T y_size[2]);
  }
}

#endif

// End of code generation (lower.h)
