//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void nest2pos(const ::coder::array<double, 2U> &nest_samples, double nLive, ::
                coder::array<double, 2U> &post_samples);
}

#endif

// End of code generation (nest2pos.h)
