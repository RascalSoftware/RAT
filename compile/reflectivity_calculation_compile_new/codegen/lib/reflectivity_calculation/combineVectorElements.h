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
namespace coder {
void combineVectorElements(const ::coder::array<double, 2U> &x,
                           ::coder::array<double, 1U> &y);

double combineVectorElements(const ::coder::array<double, 1U> &x);

} // namespace coder

#endif
// End of code generation (combineVectorElements.h)
