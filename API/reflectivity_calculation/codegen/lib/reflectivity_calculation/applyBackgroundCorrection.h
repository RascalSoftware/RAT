//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: applyBackgroundCorrection.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef APPLYBACKGROUNDCORRECTION_H
#define APPLYBACKGROUNDCORRECTION_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void applyBackgroundCorrection(coder::array<double, 2U> &reflect, coder::
  array<double, 2U> &Simul, coder::array<double, 2U> &shifted_dat, double backg,
  double backsType);

#endif

//
// File trailer for applyBackgroundCorrection.h
//
// [EOF]
//
