//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// discretize.h
//
// Code generation for function 'discretize'
//
#ifndef DISCRETIZE_H
#define DISCRETIZE_H

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
    void b_discretize(const ::coder::array<double, 2U> &x, const double
                      edgesInput[3], ::coder::array<double, 2U> &bins);
    void discretize(const ::coder::array<double, 2U> &x, const double
                    edgesInput_data[], ::coder::array<double, 2U> &bins);
  }
}

#endif

// End of code generation (discretize.h)
