//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abeles_paraPoints.h
//
// Code generation for function 'abeles_paraPoints'
//

#ifndef ABELES_PARAPOINTS_H
#define ABELES_PARAPOINTS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void abeles_paraPoints(const coder::array<double, 1U> &x,
                       const coder::array<double, 2U> &sld, double nbair,
                       double nbsub, double nrepeats, double rsub,
                       double layers, double points,
                       coder::array<double, 1U> &out);

#endif
// End of code generation (abeles_paraPoints.h)
