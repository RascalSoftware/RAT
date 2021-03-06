//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: makeSLDProfileXY.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:21:20
//
#ifndef MAKESLDPROFILEXY_H
#define MAKESLDPROFILEXY_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void makeSLDProfileXY(double nbair, double nbsub, double ssub, const
  coder::array<double, 2U> &layers, double numberOfLayers, double nrepeats,
  coder::array<double, 2U> &out);

#endif

//
// File trailer for makeSLDProfileXY.h
//
// [EOF]
//
