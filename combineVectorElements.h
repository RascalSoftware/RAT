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
    double b_combineVectorElements(const ::coder::array<double, 1U> &x, int vlen);
    int c_combineVectorElements(const ::coder::array<boolean_T, 1U> &x);
    int combineVectorElements(const ::coder::array<boolean_T, 2U> &x);
  }
}

#endif

// End of code generation (combineVectorElements.h)
