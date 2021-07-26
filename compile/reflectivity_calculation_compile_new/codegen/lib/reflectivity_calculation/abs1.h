//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abs1.h
//
// Code generation for function 'abs1'
//

#ifndef ABS1_H
#define ABS1_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace scalar {
int c_abs(int x);

double c_abs(const creal_T x);

double c_abs(double x);

} // namespace scalar
} // namespace internal
} // namespace coder

#endif
// End of code generation (abs1.h)
