//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    double d;
    if (repeats[0] == 0.0) {
      d = 1.0;
    } else {
      d = repeats[1];
    }

    makeSLDProfileXY(ssub, sld, static_cast<double>(sld.size(0)), d, sldProfile);
  }

  void makeSLDProfiles(double bulkIn, double bulkOut, const ::coder::array<
                       double, 2U> &sld, double ssub, const double repeats[2], ::
                       coder::array<double, 2U> &sldProfile)
  {
    double d;
    if (repeats[0] == 0.0) {
      d = 1.0;
    } else {
      d = repeats[1];
    }

    makeSLDProfileXY(bulkIn, bulkOut, ssub, sld, static_cast<double>(sld.size(0)),
                     d, sldProfile);
  }
}

// End of code generation (makeSLDProfiles.cpp)
