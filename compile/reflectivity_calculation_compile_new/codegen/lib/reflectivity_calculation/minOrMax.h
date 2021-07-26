//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// minOrMax.h
//
// Code generation for function 'minOrMax'
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
double b_maximum(const double x[2]);

double maximum(const double x_data[]);

void maximum(const ::coder::array<double, 2U> &x, double ex[2]);

void minimum(const ::coder::array<double, 2U> &x, double ex[2]);

} // namespace internal
} // namespace coder

#endif
// End of code generation (minOrMax.h)
