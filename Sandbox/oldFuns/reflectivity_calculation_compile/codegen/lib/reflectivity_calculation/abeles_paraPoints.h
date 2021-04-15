//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: abeles_paraPoints.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//
#ifndef ABELES_PARAPOINTS_H
#define ABELES_PARAPOINTS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void abeles_paraPoints(const coder::array<double, 1U> &x, const coder::
  array<double, 2U> &sld, double nbair, double nbsub, double nrepeats, double
  rfinal, double layers, double points, coder::array<double, 1U> &out);

#endif

//
// File trailer for abeles_paraPoints.h
//
// [EOF]
//
