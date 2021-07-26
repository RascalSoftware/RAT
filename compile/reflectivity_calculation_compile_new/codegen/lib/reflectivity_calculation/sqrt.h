//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sqrt.h
//
// Code generation for function 'sqrt'
//

#ifndef SQRT_H
#define SQRT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_sqrt(::coder::array<double, 1U> &x);

void b_sqrt(creal_T *x);

} // namespace coder

#endif
// End of code generation (sqrt.h)
