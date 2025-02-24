//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// normalize.h
//
// Code generation for function 'normalize'
//
#ifndef NORMALIZE_H
#define NORMALIZE_H

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
    void normalize(const double a[2], double n[2]);
    void normalize(const double a_data[], double n_data[], int n_size[2]);
  }
}

#endif

// End of code generation (normalize.h)
