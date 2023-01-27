//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: makeSLDProfiles.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "makeSLDProfiles.h"
#include "makeSLDProfileXY.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : real_T nbair
//                real_T nbsub
//                const ::coder::array<real_T, 2U> &sld
//                real_T ssub
//                const real_T repeats[2]
//                ::coder::array<real_T, 2U> &sldProfile
// Return Type  : void
//
namespace RAT
{
  void makeSLDProfiles(real_T nbair, real_T nbsub, const ::coder::array<real_T,
                       2U> &sld, real_T ssub, const real_T repeats[2], ::coder::
                       array<real_T, 2U> &sldProfile)
  {
    real_T d;
    if (repeats[0] == 0.0) {
      d = 1.0;
    } else {
      d = repeats[1];
    }

    makeSLDProfileXY(nbair, nbsub, ssub, sld, static_cast<real_T>(sld.size(0)),
                     d, sldProfile);
  }
}

//
// File trailer for makeSLDProfiles.cpp
//
// [EOF]
//
