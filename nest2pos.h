//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nest2pos.h
//
// Code generation for function 'nest2pos'
//
#ifndef NEST2POS_H
#define NEST2POS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void nest2pos(const ::coder::array<real_T, 2U> &nest_samples, real_T Nlive, ::
                coder::array<real_T, 2U> &post_samples);
}

#endif

// End of code generation (nest2pos.h)
