//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: resampleLayers.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//
#ifndef RESAMPLELAYERS_H
#define RESAMPLELAYERS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void resampleLayers(const coder::array<double, 2U> &sldProfile, coder::
  array<double, 2U> &newSLD);

#endif

//
// File trailer for resampleLayers.h
//
// [EOF]
//
