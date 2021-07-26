//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// lower.h
//
// Code generation for function 'lower'
//

#ifndef LOWER_H
#define LOWER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void lower(const ::coder::array<char, 2U> &x, ::coder::array<char, 2U> &y);

char lower(char x);

} // namespace coder

#endif
// End of code generation (lower.h)
