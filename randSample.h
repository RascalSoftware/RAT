//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void randSample(double numItems, const double weights[2], ::coder::array<
                  double, 2U> &outputSample);
  void randSample(double population_data[], int population_size[2], double
                  numItems, const double weights_data[], ::coder::array<double,
                  2U> &outputSample);
}

#endif

// End of code generation (randSample.h)
