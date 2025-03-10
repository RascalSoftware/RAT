//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void diag(const ::coder::array<creal_T, 2U> &v, ::coder::array<creal_T, 1U>
              &d);
    void diag(const ::coder::array<double, 1U> &v, ::coder::array<double, 2U> &d);
    void diag(const ::coder::array<double, 2U> &v, ::coder::array<double, 1U> &d);
  }
}

#endif

// End of code generation (diag.h)
