//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// mean.h
//
// Code generation for function 'mean'
//
#ifndef MEAN_H
#define MEAN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void mean(const ::coder::array<double, 3U> &x, ::coder::array<double, 3U> &y);
    void mean(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y);
    double mean(const double x_data[], int x_size);
  }
}

#endif

// End of code generation (mean.h)
