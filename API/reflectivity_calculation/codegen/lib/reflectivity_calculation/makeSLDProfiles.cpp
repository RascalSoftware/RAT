//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: makeSLDProfiles.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "makeSLDProfiles.h"
#include "makeSLDProfileXY.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : double nbair
//                double nbsub
//                const coder::array<double, 2U> *sld
//                double ssub
//                const double repeats[2]
//                coder::array<double, 2U> *sldProfile
// Return Type  : void
//
void makeSLDProfiles(double nbair, double nbsub, const coder::array<double, 2U>
                     &sld, double ssub, const double repeats[2], coder::array<
                     double, 2U> &sldProfile)
{
  double b_repeats;
  if (repeats[0] == 0.0) {
    b_repeats = 1.0;
  } else {
    b_repeats = repeats[1];
  }

  makeSLDProfileXY(nbair, nbsub, ssub, sld, static_cast<double>(sld.size(0)),
                   b_repeats, sldProfile);
}

//
// File trailer for makeSLDProfiles.cpp
//
// [EOF]
//
