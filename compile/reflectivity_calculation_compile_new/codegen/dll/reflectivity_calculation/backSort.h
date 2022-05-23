//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// backSort.h
//
// Code generation for function 'backSort'
//

#ifndef BACKSORT_H
#define BACKSORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void backSort(double cBacks, double cShifts, double cScales, double cNbas,
              double cNbss, double cRes, const coder::array<double, 2U> &backs,
              const coder::array<double, 2U> &shifts,
              const coder::array<double, 2U> &sf,
              const coder::array<double, 2U> &nba,
              const coder::array<double, 2U> &nbs,
              const coder::array<double, 2U> &res, double *backg,
              double *qshift, double *b_sf, double *b_nba, double *b_nbs,
              double *resol);

#endif
// End of code generation (backSort.h)
