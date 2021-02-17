//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: chiSquared.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
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
