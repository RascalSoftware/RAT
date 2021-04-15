//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_layers_core.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef STANDARDTF_LAYERS_CORE_H
#define STANDARDTF_LAYERS_CORE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void b_standardTF_layers_core(const coder::array<double, 2U>
  &contrastLayers, double rough, const coder::array<char, 2U> &geometry, double
  nba, double nbs, double resample, double calcSld, double sf, double qshift,
  double dataPresent, const coder::array<double, 2U> &data, const double
  dataLimits[2], const double simLimits[2], const double repeatLayers[2], double
  background, double resol, double backsType, double params, coder::array<double,
  2U> &sldProfile, coder::array<double, 2U> &reflect, coder::array<double, 2U>
  &Simul, coder::array<double, 2U> &shifted_dat, coder::array<double, 2U>
  &layerSld, double *chiSq, double *ssubs);
extern void standardTF_layers_core(const coder::array<double, 2U>
  &contrastLayers, double rough, const coder::array<char, 2U> &geometry, double
  nba, double nbs, double resample, double calcSld, double sf, double qshift,
  double dataPresent, const coder::array<double, 2U> &data, const double
  dataLimits[2], const double simLimits[2], const double repeatLayers[2], double
  background, double resol, double backsType, double params, coder::array<double,
  2U> &sldProfile, coder::array<double, 2U> &reflect, coder::array<double, 2U>
  &Simul, coder::array<double, 2U> &shifted_dat, coder::array<double, 2U>
  &layerSld, double *chiSq, double *ssubs);

#endif

//
// File trailer for standardTF_layers_core.h
//
// [EOF]
//
