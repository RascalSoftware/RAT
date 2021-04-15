//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: groupLayers_Mod.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef GROUPLAYERS_MOD_H
#define GROUPLAYERS_MOD_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void groupLayers_Mod(const coder::array<double, 2U> &allLayers, double
  allRoughs, const coder::array<char, 2U> &geometry, double nbair, double nbsubs,
  coder::array<double, 2U> &outLayers, double *outSsubs);

#endif

//
// File trailer for groupLayers_Mod.h
//
// [EOF]
//
