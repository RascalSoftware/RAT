//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// all.h
//
// Code generation for function 'all'
//
#ifndef ALL_H
#define ALL_H

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
    void all(const boolean_T x_data[], const int x_size[2], boolean_T y_data[],
             int y_size[2]);
    boolean_T b_all(const boolean_T x_data[], const int x_size[2]);
  }
}

#endif

// End of code generation (all.h)
