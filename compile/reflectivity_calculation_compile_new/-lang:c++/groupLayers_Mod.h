//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: groupLayers_Mod.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef GROUPLAYERS_MOD_H
#define GROUPLAYERS_MOD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void groupLayers_Mod(const real_T allLayers_data[], const int32_T
                       allLayers_size[2], real_T allRoughs, const char_T
                       geometry_data[], const int32_T geometry_size[2], real_T
                       nbair, real_T nbsubs, real_T outLayers_data[], int32_T
                       outLayers_size[2], real_T *outSsubs);
  void groupLayers_Mod(const ::coder::array<real_T, 2U> &allLayers, real_T
                       allRoughs, const char_T geometry_data[], const int32_T
                       geometry_size[2], ::coder::array<real_T, 2U> &outLayers,
                       real_T *outSsubs);
}

#endif

//
// File trailer for groupLayers_Mod.h
//
// [EOF]
//
