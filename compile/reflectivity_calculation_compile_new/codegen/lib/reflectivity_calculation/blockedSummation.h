//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// blockedSummation.h
//
// Code generation for function 'blockedSummation'
//

#ifndef BLOCKEDSUMMATION_H
#define BLOCKEDSUMMATION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void blockedSummation(const ::coder::array<double, 2U> &x, int vlen,
                      ::coder::array<double, 1U> &y);

double blockedSummation(const ::coder::array<double, 1U> &x, int vlen);

} // namespace coder

#endif
// End of code generation (blockedSummation.h)
