//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
}

// Function Declarations
namespace RAT
{
  void gelman(const ::coder::array<double, 3U> &chain, const DreamParams &
              DREAMPar, ::coder::array<double, 2U> &R_stat);
}

#endif

// End of code generation (gelman.h)
