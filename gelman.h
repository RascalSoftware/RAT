//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// gelman.h
//
// Code generation for function 'gelman'
//
#ifndef GELMAN_H
#define GELMAN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct11_T;
}

// Function Declarations
namespace RAT
{
  void gelman(const ::coder::array<real_T, 3U> &chain, const struct11_T
              *DREAMPar, ::coder::array<real_T, 2U> &R_stat);
}

#endif

// End of code generation (gelman.h)
