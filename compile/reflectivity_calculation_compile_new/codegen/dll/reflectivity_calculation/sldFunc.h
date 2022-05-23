//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sldFunc.h
//
// Code generation for function 'sldFunc'
//

#ifndef SLDFUNC_H
#define SLDFUNC_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void sldFunc(double x, const coder::array<double, 2U> &SLD,
             coder::array<double, 1U> &sldVal);

void sldFunc(double x, double sldVal_data[], int *sldVal_size);

#endif
// End of code generation (sldFunc.h)
