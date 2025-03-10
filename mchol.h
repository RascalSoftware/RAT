//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// mchol.h
//
// Code generation for function 'mchol'
//
#ifndef MCHOL_H
#define MCHOL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void mchol(const ::coder::array<double, 2U> &G, ::coder::array<double, 2U> &L,
             ::coder::array<double, 2U> &D);
}

#endif

// End of code generation (mchol.h)
