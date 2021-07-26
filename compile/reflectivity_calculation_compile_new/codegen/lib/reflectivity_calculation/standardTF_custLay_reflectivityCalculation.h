//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_custLay_reflectivityCalculation.h
//
// Code generation for function 'standardTF_custLay_reflectivityCalculation'
//

#ifndef STANDARDTF_CUSTLAY_REFLECTIVITYCALCULATION_H
#define STANDARDTF_CUSTLAY_REFLECTIVITYCALCULATION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct0_T;

struct cell_14;

struct struct2_T;

struct struct4_T;

struct cell_wrap_7;

struct cell_wrap_1;

struct cell_wrap_8;

// Function Declarations
void standardTF_custLay_reflectivityCalculation(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, struct4_T *problem,
    coder::array<cell_wrap_7, 1U> &reflectivity,
    coder::array<cell_wrap_7, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_1, 1U> &allLayers);

#endif
// End of code generation (standardTF_custLay_reflectivityCalculation.h)
