//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanLay_reflectivityCalculation.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef STANDARDTF_STANLAY_REFLECTIVITYCALCULATION_H
#define STANDARDTF_STANLAY_REFLECTIVITYCALCULATION_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void c_standardTF_stanLay_reflectivi(const struct0_T *problemDef, const
  cell_14 *problemDef_cells, const struct2_T *controls, struct4_T *problem,
  coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<cell_wrap_7, 1U>
  &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<
  cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U> &sldProfiles, coder::
  array<cell_wrap_12, 1U> &allLayers);

#endif

//
// File trailer for standardTF_stanLay_reflectivityCalculation.h
//
// [EOF]
//
