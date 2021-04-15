//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: chiSquared.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef CHISQUARED_H
#define CHISQUARED_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern double chiSquared(const coder::array<double, 2U> &thisData, const coder::
  array<double, 2U> &thisFit, double P);

#endif

//
// File trailer for chiSquared.h
//
// [EOF]
//
