//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// rescaleKernel.h
//
// Code generation for function 'rescaleKernel'
//
#ifndef RESCALEKERNEL_H
#define RESCALEKERNEL_H

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
    void rescaleKernel(::coder::array<double, 1U> &A, const ::coder::array<
                       double, 1U> &inputMin, const ::coder::array<double, 1U>
                       &inputMax);
  }
}

#endif

// End of code generation (rescaleKernel.h)
