//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// adaptive.h
//
// Code generation for function 'adaptive'
//

#ifndef ADAPTIVE_H
#define ADAPTIVE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct cell_17;

// Function Declarations
void adaptive(const coder::array<double, 2U> &sldProfile,
              const double startDomain[2], cell_17 *out);

void adaptive(cell_17 *out);

#endif
// End of code generation (adaptive.h)
