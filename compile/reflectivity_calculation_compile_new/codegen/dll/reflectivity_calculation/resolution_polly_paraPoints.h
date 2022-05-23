//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resolution_polly_paraPoints.h
//
// Code generation for function 'resolution_polly_paraPoints'
//

#ifndef RESOLUTION_POLLY_PARAPOINTS_H
#define RESOLUTION_POLLY_PARAPOINTS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void resolution_polly_paraPoints(const coder::array<double, 1U> &xdata,
                                 const coder::array<double, 1U> &ydata,
                                 double res, double points,
                                 coder::array<double, 1U> &out);

#endif
// End of code generation (resolution_polly_paraPoints.h)
