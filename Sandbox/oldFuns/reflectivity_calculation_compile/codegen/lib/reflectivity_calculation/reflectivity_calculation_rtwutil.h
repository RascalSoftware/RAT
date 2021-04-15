//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation_rtwutil.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//
#ifndef REFLECTIVITY_CALCULATION_RTWUTIL_H
#define REFLECTIVITY_CALCULATION_RTWUTIL_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern double rt_hypotd_snf(double u0, double u1);
extern double rt_powd_snf(double u0, double u1);

#endif

//
// File trailer for reflectivity_calculation_rtwutil.h
//
// [EOF]
//
