//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// combineVectorElements.h
//
// Code generation for function 'combineVectorElements'
//
#ifndef COMBINEVECTORELEMENTS_H
#define COMBINEVECTORELEMENTS_H

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
    real_T b_combineVectorElements(const ::coder::array<real_T, 1U> &x, int32_T
      vlen);
    int32_T c_combineVectorElements(const ::coder::array<boolean_T, 1U> &x);
    int32_T combineVectorElements(const ::coder::array<boolean_T, 2U> &x);
  }
}

#endif

// End of code generation (combineVectorElements.h)
