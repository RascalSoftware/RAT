//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// cov.h
//
// Code generation for function 'cov'
//
#ifndef COV_H
#define COV_H

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
    void cov(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &xy);
  }
}

#endif

// End of code generation (cov.h)
