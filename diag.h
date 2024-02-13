//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// diag.h
//
// Code generation for function 'diag'
//
#ifndef DIAG_H
#define DIAG_H

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
    void diag(const ::coder::array<creal_T, 2U> &v, ::coder::array<creal_T, 1U>
              &d);
    void diag(const ::coder::array<real_T, 1U> &v, ::coder::array<real_T, 2U> &d);
    void diag(const ::coder::array<real_T, 2U> &v, ::coder::array<real_T, 1U> &d);
  }
}

#endif

// End of code generation (diag.h)
