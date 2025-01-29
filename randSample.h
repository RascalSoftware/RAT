//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// randSample.h
//
// Code generation for function 'randSample'
//
#ifndef RANDSAMPLE_H
#define RANDSAMPLE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void randSample(real_T numItems, const real_T weights[2], ::coder::array<
                  real_T, 2U> &outputSample);
  void randSample(real_T population_data[], const int32_T population_size[2],
                  real_T numItems, const real_T weights_data[], ::coder::array<
                  real_T, 2U> &outputSample);
}

#endif

// End of code generation (randSample.h)
