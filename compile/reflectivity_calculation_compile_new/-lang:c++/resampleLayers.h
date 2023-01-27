//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: resampleLayers.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef RESAMPLELAYERS_H
#define RESAMPLELAYERS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void resampleLayers(const ::coder::array<real_T, 2U> &sldProfile, const real_T
                      resamPars[2], ::coder::array<real_T, 2U> &newSLD);
  void resampleLayers(const real_T sldProfile_data[], const int32_T
                      sldProfile_size[2], const real_T resamPars[2], ::coder::
                      array<real_T, 2U> &newSLD);
}

#endif

//
// File trailer for resampleLayers.h
//
// [EOF]
//
