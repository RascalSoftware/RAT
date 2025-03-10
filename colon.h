//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// colon.h
//
// Code generation for function 'colon'
//
#ifndef COLON_H
#define COLON_H

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
    void eml_float_colon(double a, double d, double b, ::coder::array<double, 2U>
                         &y);
    void eml_integer_colon_dispatcher(int b, ::coder::array<int, 2U> &y);
  }
}

#endif

// End of code generation (colon.h)
