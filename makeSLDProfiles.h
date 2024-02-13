//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeSLDProfiles.h
//
// Code generation for function 'makeSLDProfiles'
//
#ifndef MAKESLDPROFILES_H
#define MAKESLDPROFILES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void makeSLDProfiles(real_T bulkIn, real_T bulkOut, const ::coder::array<
                       real_T, 2U> &sld, real_T ssub, const real_T repeats[2], ::
                       coder::array<real_T, 2U> &sldProfile);
  void makeSLDProfiles(const ::coder::array<real_T, 2U> &sld, real_T ssub, const
                       real_T repeats[2], ::coder::array<real_T, 2U> &sldProfile);
}

#endif

// End of code generation (makeSLDProfiles.h)
