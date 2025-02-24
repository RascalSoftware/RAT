//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// linspace.h
//
// Code generation for function 'linspace'
//
#ifndef LINSPACE_H
#define LINSPACE_H

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
    void linspace(double d1, double d2, double n, ::coder::array<double, 2U> &y);
    void linspace(double d1, double d2, double y[500]);
  }
}

#endif

// End of code generation (linspace.h)
