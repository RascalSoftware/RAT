//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_custLay_reflectivityCalculation.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef STANDARDTF_CUSTLAY_REFLECTIVITYCALCULATION_H
#define STANDARDTF_CUSTLAY_REFLECTIVITYCALCULATION_H

// Include Files
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_18;
}

// Function Declarations
namespace RAT
{
  void standardTF_custLay_reflectivityCalculation(const struct0_T *problemDef,
    const cell_18 *problemDef_cells, const struct2_T *controls, struct4_T
    *problem, ::coder::array<cell_wrap_9, 1U> &reflectivity, ::coder::array<
    cell_wrap_9, 1U> &Simulation, ::coder::array<cell_wrap_14, 1U> &shifted_data,
    ::coder::array<cell_wrap_10, 1U> &layerSlds, ::coder::array<cell_wrap_14, 1U>
    &sldProfiles, ::coder::array<cell_wrap_14, 1U> &allLayers);
}

#endif

//
// File trailer for standardTF_custLay_reflectivityCalculation.h
//
// [EOF]
//
