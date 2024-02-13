//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void rescaleKernel(::coder::array<real_T, 1U> &A, const ::coder::array<
                       real_T, 1U> &inputMin, const ::coder::array<real_T, 1U>
                       &inputMax);
  }
}

#endif

// End of code generation (rescaleKernel.h)
