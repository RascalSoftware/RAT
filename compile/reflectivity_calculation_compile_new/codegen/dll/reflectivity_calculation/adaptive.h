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

// Function Declarations
void calculateCentralAngles(const coder::array<double, 2U> &XYdata,
                            const double dataBoxSize[2],
                            coder::array<double, 1U> &cornerAngle);

#endif
// End of code generation (adaptive.h)
