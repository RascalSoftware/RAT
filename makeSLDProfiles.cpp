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
  void makeSLDProfiles(const ::coder::array<double, 2U> &sld, double ssub, const
                       double repeats[2], ::coder::array<double, 2U> &sldProfile)
  {
    double b_repeats;
    if (repeats[0] == 0.0) {
      b_repeats = 1.0;
    } else {
      b_repeats = repeats[1];
    }

    makeSLDProfileXY(ssub, sld, static_cast<double>(sld.size(0)), b_repeats,
                     sldProfile);
  }

  void makeSLDProfiles(double bulkIn, double bulkOut, const ::coder::array<
                       double, 2U> &sld, double ssub, const double repeats[2], ::
                       coder::array<double, 2U> &sldProfile)
  {
    double b_repeats;
    if (repeats[0] == 0.0) {
      b_repeats = 1.0;
    } else {
      b_repeats = repeats[1];
    }

    makeSLDProfileXY(bulkIn, bulkOut, ssub, sld, static_cast<double>(sld.size(0)),
                     b_repeats, sldProfile);
  }
}

// End of code generation (makeSLDProfiles.cpp)
