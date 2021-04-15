//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: callReflectivity.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef CALLREFLECTIVITY_H
#define CALLREFLECTIVITY_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void b_callReflectivity(double nbairs, double nbsubs, const double
  simLimits[2], const double repeatLayers[2], const coder::array<double, 2U>
  &this_data, const coder::array<double, 2U> &layers, double ssubs, double res,
  coder::array<double, 2U> &reflectivity, coder::array<double, 2U> &Simulation);
extern void callReflectivity(double nbairs, double nbsubs, const double
  simLimits[2], const double repeatLayers[2], const coder::array<double, 2U>
  &this_data, const coder::array<double, 2U> &layers, double ssubs, double res,
  coder::array<double, 2U> &reflectivity, coder::array<double, 2U> &Simulation);

#endif

//
// File trailer for callReflectivity.h
//
// [EOF]
//
