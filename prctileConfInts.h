//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// prctileConfInts.h
//
// Code generation for function 'prctileConfInts'
//
#ifndef PRCTILECONFINTS_H
#define PRCTILECONFINTS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void prctileConfInts(const ::coder::array<real_T, 2U> &chain, ::coder::array<
                       real_T, 2U> &parConfInts_par95, ::coder::array<real_T, 2U>
                       &parConfInts_par65, ::coder::array<real_T, 2U>
                       &parConfInts_mean);
}

#endif

// End of code generation (prctileConfInts.h)
