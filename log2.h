//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// log2.h
//
// Code generation for function 'log2'
//
#ifndef LOG2_H
#define LOG2_H

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
    void b_log2(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U>
                &f, ::coder::array<double, 1U> &e);
    double b_log2(double x, double *e);
  }
}

#endif

// End of code generation (log2.h)
