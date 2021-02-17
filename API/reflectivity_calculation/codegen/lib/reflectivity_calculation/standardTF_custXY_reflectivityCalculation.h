//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_custXY_reflectivityCalculation.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef STANDARDTF_CUSTXY_REFLECTIVITYCALCULATION_H
#define STANDARDTF_CUSTXY_REFLECTIVITYCALCULATION_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void c_standardTF_custXY_reflectivit(const struct0_T *problemDef, const
  cell_13 *problemDef_cells, const struct2_T *controls, struct4_T *problem,
  coder::array<cell_wrap_14, 1U> &reflectivity, coder::array<cell_wrap_8, 1U>
  &Simulation, coder::array<cell_wrap_9, 1U> &shifted_data, coder::array<
  cell_wrap_9, 1U> &layerSlds, coder::array<cell_wrap_8, 1U> &sldProfiles, coder::
  array<cell_wrap_15, 1U> &allLayers);

#endif

//
// File trailer for standardTF_custXY_reflectivityCalculation.h
//
// [EOF]
//
