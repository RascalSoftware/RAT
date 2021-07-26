//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// extractProblemParams.h
//
// Code generation for function 'extractProblemParams'
//

#ifndef EXTRACTPROBLEMPARAMS_H
#define EXTRACTPROBLEMPARAMS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct0_T;

// Function Declarations
void extractProblemParams(
    const struct0_T *problemDef, double *numberOfContrasts,
    coder::array<char, 2U> &geometry, coder::array<double, 2U> &cBacks,
    coder::array<double, 2U> &cShifts, coder::array<double, 2U> &cScales,
    coder::array<double, 2U> &cNbas, coder::array<double, 2U> &cNbss,
    coder::array<double, 2U> &cRes, coder::array<double, 2U> &backs,
    coder::array<double, 2U> &shifts, coder::array<double, 2U> &sf,
    coder::array<double, 2U> &nba, coder::array<double, 2U> &nbs,
    coder::array<double, 2U> &res, coder::array<double, 2U> &dataPresent,
    double *nParams, coder::array<double, 2U> &params, double *numberOfLayers,
    coder::array<double, 2U> &resample, coder::array<double, 2U> &backsType);

void extractProblemParams(
    const struct0_T *problemDef, double *numberOfContrasts,
    coder::array<char, 2U> &geometry, coder::array<double, 2U> &cBacks,
    coder::array<double, 2U> &cShifts, coder::array<double, 2U> &cScales,
    coder::array<double, 2U> &cNbas, coder::array<double, 2U> &cNbss,
    coder::array<double, 2U> &cRes, coder::array<double, 2U> &backs,
    coder::array<double, 2U> &shifts, coder::array<double, 2U> &sf,
    coder::array<double, 2U> &nba, coder::array<double, 2U> &nbs,
    coder::array<double, 2U> &res, coder::array<double, 2U> &dataPresent,
    double *nParams, coder::array<double, 2U> &params, double *numberOfLayers,
    coder::array<double, 2U> &resample, coder::array<double, 2U> &backsType,
    coder::array<double, 2U> &cFiles);

#endif
// End of code generation (extractProblemParams.h)
