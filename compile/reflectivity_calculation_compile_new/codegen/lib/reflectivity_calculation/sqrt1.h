//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sqrt1.h
//
// Code generation for function 'sqrt1'
//

#ifndef SQRT1_H
#define SQRT1_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace scalar {
void c_sqrt(double *x);

void c_sqrt(creal_T *x);

} // namespace scalar
} // namespace internal
} // namespace coder

#endif
// End of code generation (sqrt1.h)
