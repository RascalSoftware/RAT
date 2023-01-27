//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: callReflectivity.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef CALLREFLECTIVITY_H
#define CALLREFLECTIVITY_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void b_callReflectivity(real_T nbairs, real_T nbsubs, const real_T
    simLimits_data[], const real_T repeatLayers[2], const real_T this_data_data[],
    const int32_T this_data_size[2], const ::coder::array<real_T, 2U> &layers,
    real_T ssubs, real_T res, ::coder::array<real_T, 2U> &reflectivity, ::coder::
    array<real_T, 2U> &Simulation);
  void callReflectivity(real_T nbairs, real_T nbsubs, const real_T
                        simLimits_data[], const real_T repeatLayers[2], const
                        real_T this_data_data[], const int32_T this_data_size[2],
                        const ::coder::array<real_T, 2U> &layers, real_T ssubs,
                        real_T res, ::coder::array<real_T, 2U> &reflectivity, ::
                        coder::array<real_T, 2U> &Simulation);
}

#endif

//
// File trailer for callReflectivity.h
//
// [EOF]
//
