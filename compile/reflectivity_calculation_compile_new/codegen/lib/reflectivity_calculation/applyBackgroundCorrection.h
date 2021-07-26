//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// applyBackgroundCorrection.h
//
// Code generation for function 'applyBackgroundCorrection'
//

#ifndef APPLYBACKGROUNDCORRECTION_H
#define APPLYBACKGROUNDCORRECTION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void applyBackgroundCorrection(coder::array<double, 2U> &reflect,
                               coder::array<double, 2U> &Simul,
                               coder::array<double, 2U> &shifted_dat,
                               double backg, double backsType);

#endif
// End of code generation (applyBackgroundCorrection.h)
