//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// repmat.h
//
// Code generation for function 'repmat'
//
#ifndef REPMAT_H
#define REPMAT_H

// Include files
#include "RATMain_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void repmat(double varargin_1, ::coder::array<j_struct_T, 1U> &b);
    void repmat(const ::coder::array<double, 2U> &a, double varargin_1, ::coder::
                array<double, 2U> &b);
    void repmat(const double a[2], double varargin_1, ::coder::array<double, 2U>
                &b);
  }
}

#endif

// End of code generation (repmat.h)
