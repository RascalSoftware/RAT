//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeD.h
//
// Code generation for function 'makeD'
//
#ifndef MAKED_H
#define MAKED_H

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
    void makeD(const ::coder::array<creal_T, 1U> &alpha1, const ::coder::array<
               creal_T, 1U> &beta1, ::coder::array<creal_T, 2U> &D);
  }
}

#endif

// End of code generation (makeD.h)
