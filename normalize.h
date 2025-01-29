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
    void normalize(const real_T a[2], real_T n[2]);
    void normalize(const real_T a_data[], real_T n_data[], int32_T n_size[2]);
  }
}

#endif

// End of code generation (normalize.h)
