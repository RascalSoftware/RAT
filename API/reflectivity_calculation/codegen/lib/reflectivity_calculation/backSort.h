//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: backSort.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef BACKSORT_H
#define BACKSORT_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void backSort(double cBacks, double cShifts, double cScales, double cNbas,
                     double cNbss, double cRes, const coder::array<double, 2U>
                     &backs, const coder::array<double, 2U> &shifts, const coder::
                     array<double, 2U> &sf, const coder::array<double, 2U> &nba,
                     const coder::array<double, 2U> &nbs, const coder::array<
                     double, 2U> &res, double *backg, double *qshift, double
                     *b_sf, double *b_nba, double *b_nbs, double *resol);

#endif

//
// File trailer for backSort.h
//
// [EOF]
//
