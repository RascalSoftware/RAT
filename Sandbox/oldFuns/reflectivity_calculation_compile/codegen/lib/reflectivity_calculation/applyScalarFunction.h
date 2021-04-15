//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: applyScalarFunction.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//
#ifndef APPLYSCALARFUNCTION_H
#define APPLYSCALARFUNCTION_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void applyScalarFunction(const coder::array<double, 2U> &x, coder::array<
  double, 2U> &z1);

#endif

//
// File trailer for applyScalarFunction.h
//
// [EOF]
//
