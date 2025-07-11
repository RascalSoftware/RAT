//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void nullAssignment(::coder::array<double, 2U> &x, const ::coder::array<
                          int, 2U> &idx);
      void nullAssignment(const ::coder::array<double, 2U> &x, ::coder::array<
                          double, 2U> &b_x);
      void nullAssignment(::coder::array<double, 2U> &x, const int idx_data[],
                          const int idx_size[2]);
      void nullAssignment(::coder::array<double, 2U> &x);
    }
  }
}

#endif

// End of code generation (nullAssignment.h)
