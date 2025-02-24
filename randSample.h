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
  void randSample(double numItems, const double weights[2], ::coder::array<
                  double, 2U> &outputSample);
  void randSample(double population_data[], const int population_size[2], double
                  numItems, const double weights_data[], ::coder::array<double,
                  2U> &outputSample);
}

#endif

// End of code generation (randSample.h)
