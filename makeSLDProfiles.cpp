//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeSLDProfiles.cpp
//
// Code generation for function 'makeSLDProfiles'
//

// Include files
#include "makeSLDProfiles.h"
#include "makeSLDProfileXY.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void makeSLDProfiles(const ::coder::array<real_T, 2U> &sld, real_T ssub, const
                       real_T repeats[2], ::coder::array<real_T, 2U> &sldProfile)
  {
    real_T b_repeats;
    if (repeats[0] == 0.0) {
      b_repeats = 1.0;
    } else {
      b_repeats = repeats[1];
    }

    makeSLDProfileXY(ssub, sld, static_cast<real_T>(sld.size(0)), b_repeats,
                     sldProfile);
  }

  void makeSLDProfiles(real_T bulkIn, real_T bulkOut, const ::coder::array<
                       real_T, 2U> &sld, real_T ssub, const real_T repeats[2], ::
                       coder::array<real_T, 2U> &sldProfile)
  {
    real_T b_repeats;
    if (repeats[0] == 0.0) {
      b_repeats = 1.0;
    } else {
      b_repeats = repeats[1];
    }

    makeSLDProfileXY(bulkIn, bulkOut, ssub, sld, static_cast<real_T>(sld.size(0)),
                     b_repeats, sldProfile);
  }
}

// End of code generation (makeSLDProfiles.cpp)
