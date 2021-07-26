//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// chiSquared.h
//
// Code generation for function 'chiSquared'
//

#ifndef CHISQUARED_H
#define CHISQUARED_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
double chiSquared(const coder::array<double, 2U> &thisData,
                  const coder::array<double, 2U> &thisFit, double P);

#endif
// End of code generation (chiSquared.h)
