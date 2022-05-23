//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_layers_core.h
//
// Code generation for function 'standardTF_layers_core'
//

#ifndef STANDARDTF_LAYERS_CORE_H
#define STANDARDTF_LAYERS_CORE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void standardTF_layers_core(
    const coder::array<double, 2U> &contrastLayers, double rough,
    const coder::array<char, 2U> &geometry, double nba, double nbs,
    double resample, double calcSld, double sf, double qshift,
    double dataPresent, const coder::array<double, 2U> &data,
    const double dataLimits[2], const double simLimits[2],
    const double repeatLayers[2], double background, double resol,
    double backsType, double params, coder::array<double, 2U> &sldProfile,
    coder::array<double, 2U> &reflect, coder::array<double, 2U> &Simul,
    coder::array<double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld,
    double *chiSq, double *ssubs);

void standardTF_layers_core(
    const coder::array<char, 2U> &geometry, double nba, double nbs,
    double resample, double calcSld, double sf, double qshift,
    double dataPresent, const coder::array<double, 2U> &data,
    const double dataLimits[2], const double simLimits[2],
    const double repeatLayers[2], double background, double resol,
    double backsType, double params, coder::array<double, 2U> &sldProfile,
    coder::array<double, 2U> &reflect, coder::array<double, 2U> &Simul,
    coder::array<double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld,
    double *chiSq, double *ssubs);

#endif
// End of code generation (standardTF_layers_core.h)
