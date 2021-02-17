//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: groupLayers_Mod.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
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
extern void b_groupLayers_Mod(const coder::array<double, 2U> &allLayers, double
  allRoughs, const coder::array<char, 2U> &geometry, coder::array<double, 2U>
  &outLayers, double *outSsubs);
extern void groupLayers_Mod(const coder::array<double, 2U> &allLayers, double
  allRoughs, const coder::array<char, 2U> &geometry, double nbair, double nbsubs,
  coder::array<double, 2U> &outLayers, double *outSsubs);

#endif

//
// File trailer for groupLayers_Mod.h
//
// [EOF]
//
