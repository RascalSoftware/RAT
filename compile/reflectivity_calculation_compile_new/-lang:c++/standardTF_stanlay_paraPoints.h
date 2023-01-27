//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_stanlay_paraPoints.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef STANDARDTF_STANLAY_PARAPOINTS_H
#define STANDARDTF_STANLAY_PARAPOINTS_H

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
  void standardTF_stanlay_paraPoints(const struct0_T *problemDef, const cell_18 *
    problemDef_cells, const struct2_T *controls, ::coder::array<real_T, 1U>
    &outSsubs, ::coder::array<real_T, 1U> &backgs, ::coder::array<real_T, 1U>
    &qshifts, ::coder::array<real_T, 1U> &sfs, ::coder::array<real_T, 1U> &nbas,
    ::coder::array<real_T, 1U> &nbss, ::coder::array<real_T, 1U> &resols, ::
    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_9, 1U>
    &reflectivity, ::coder::array<cell_wrap_9, 1U> &Simulation, ::coder::array<
    cell_wrap_14, 1U> &shifted_data, ::coder::array<cell_wrap_10, 1U> &layerSlds,
    ::coder::array<cell_wrap_14, 1U> &sldProfiles, ::coder::array<cell_wrap_14,
    1U> &allLayers, ::coder::array<real_T, 1U> &allRoughs);
}

#endif

//
// File trailer for standardTF_stanlay_paraPoints.h
//
// [EOF]
//
