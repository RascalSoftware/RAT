//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// asymconvstep.h
//
// Code generation for function 'asymconvstep'
//
#ifndef ASYMCONVSTEP_H
#define ASYMCONVSTEP_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void asymconvstep(const ::coder::array<double, 2U> &x, double xw, double xcen,
                    double s1, double s2, double h, ::coder::array<double, 2U>
                    &f);
  void asymconvstep(const ::coder::array<double, 2U> &x, double xw, double xcen,
                    double s1, double s2, ::coder::array<double, 2U> &f);
}

#endif

// End of code generation (asymconvstep.h)
