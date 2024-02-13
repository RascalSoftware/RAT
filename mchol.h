//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void mchol(const ::coder::array<real_T, 2U> &G, ::coder::array<real_T, 2U> &L,
             ::coder::array<real_T, 2U> &D);
}

#endif

// End of code generation (mchol.h)
