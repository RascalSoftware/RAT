//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nullAssignment.h
//
// Code generation for function 'nullAssignment'
//
#ifndef NULLASSIGNMENT_H
#define NULLASSIGNMENT_H

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
    namespace internal
    {
      void nullAssignment(::coder::array<real_T, 2U> &x, const ::coder::array<
                          int32_T, 2U> &idx);
      void nullAssignment(real_T x_data[], int32_T x_size[2]);
    }
  }
}

#endif

// End of code generation (nullAssignment.h)
