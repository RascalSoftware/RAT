//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: makeSLDProfiles.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef MAKESLDPROFILES_H
#define MAKESLDPROFILES_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void makeSLDProfiles(double nbair, double nbsub, const coder::array<
  double, 2U> &sld, double ssub, const double repeats[2], coder::array<double,
  2U> &sldProfile);

#endif

//
// File trailer for makeSLDProfiles.h
//
// [EOF]
//
