//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// randperm.h
//
// Code generation for function 'randperm'
//
#ifndef RANDPERM_H
#define RANDPERM_H

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
    void randperm(double n, ::coder::array<double, 2U> &p);
  }
}

#endif

// End of code generation (randperm.h)
