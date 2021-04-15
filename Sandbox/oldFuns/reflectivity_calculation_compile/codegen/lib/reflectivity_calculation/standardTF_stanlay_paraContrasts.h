//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanlay_paraContrasts.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//
#ifndef STANDARDTF_STANLAY_PARACONTRASTS_H
#define STANDARDTF_STANLAY_PARACONTRASTS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void c_standardTF_stanlay_paraContra(const struct0_T *problemDef, const
  cell_15 *problemDef_cells, const struct2_T *controls, coder::array<double, 1U>
  &outSsubs, coder::array<double, 1U> &backgs, coder::array<double, 1U> &qshifts,
  coder::array<double, 1U> &sfs, coder::array<double, 1U> &nbas, coder::array<
  double, 1U> &nbss, coder::array<double, 1U> &resols, coder::array<double, 1U>
  &chis, coder::array<cell_wrap_8, 1U> &reflectivity, coder::array<cell_wrap_8,
  1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<
  cell_wrap_9, 1U> &layerSlds, coder::array<cell_wrap_1, 1U> &sldProfiles, coder::
  array<cell_wrap_13, 1U> &allLayers, coder::array<double, 1U> &allRoughs);

#endif

//
// File trailer for standardTF_stanlay_paraContrasts.h
//
// [EOF]
//
