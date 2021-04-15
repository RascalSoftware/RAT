//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: abeles_single.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef ABELES_SINGLE_H
#define ABELES_SINGLE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void abeles_single(const coder::array<double, 1U> &x, const coder::array<
  double, 2U> &sld, double nbair, double nbsub, double nrepeats, double rfinal,
  double layers, double points, coder::array<double, 1U> &out);

#endif

//
// File trailer for abeles_single.h
//
// [EOF]
//
