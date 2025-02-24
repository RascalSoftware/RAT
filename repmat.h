//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// repmat.h
//
// Code generation for function 'repmat'
//
#ifndef REPMAT_H
#define REPMAT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct_T;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void repmat(double varargin_1, ::coder::array<struct_T, 1U> &b);
    void repmat(const ::coder::array<double, 2U> &a, double varargin_1, ::coder::
                array<double, 2U> &b);
    void repmat(const double a[2], double varargin_1, ::coder::array<double, 2U>
                &b);
  }
}

#endif

// End of code generation (repmat.h)
