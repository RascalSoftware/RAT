//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// resampleLayers.cpp
//
// Code generation for function 'resampleLayers'
//

// Include files
#include "resampleLayers.h"
#include "RATMain_internal_types.h"
#include "adaptive.h"
#include "interp1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void resampleLayers(const ::coder::array<double, 2U> &sldProfile, const ::
                      coder::array<double, 2U> &sldProfileIm, double minAngle,
                      double nPoints, ::coder::array<double, 2U> &newSLD)
  {
    ::coder::array<double, 1U> b_expl_temp;
    ::coder::array<double, 1U> b_sldProfileIm;
    ::coder::array<double, 1U> c_sldProfileIm;
    ::coder::array<double, 1U> newYIm;
    cell_57 expl_temp;
    double b_sldProfile[2];
    int i;
    int loop_ub;

    //  Resample the SLD profile. In this case we have an imaginary SLD also, and
    //  so we resample that onto the same points as the real one
    //  Function handle for adaptive resampling
    //  f = @(x) SLDFunction(x);
    //
    b_sldProfile[0] = sldProfile[0];
    b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
    adaptive(sldProfile, b_sldProfile, minAngle * 3.1415926535897931, nPoints,
             expl_temp);

    //  Now interpolate the imaginary profile so that it is on the same x points
    //  as the resampled real one....
    b_sldProfileIm.set_size(sldProfileIm.size(0));
    loop_ub = sldProfileIm.size(0);
    c_sldProfileIm.set_size(sldProfileIm.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_sldProfileIm[i] = sldProfileIm[i];
      c_sldProfileIm[i] = sldProfileIm[i + sldProfileIm.size(0)];
    }

    b_expl_temp.set_size(expl_temp.f1.size(0));
    loop_ub = expl_temp.f1.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_expl_temp[i] = expl_temp.f1[i];
    }

    coder::interp1(b_sldProfileIm, c_sldProfileIm, b_expl_temp, newYIm);
    newSLD.set_size(expl_temp.f1.size(0) - 1, 4);
    loop_ub = expl_temp.f1.size(0) - 1;
    for (i = 0; i < 4; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    i = expl_temp.f1.size(0);
    for (int n{0}; n <= i - 2; n++) {
      double d;
      double d1;
      double thisLayRho;
      double thisLayRhoIm;
      d = expl_temp.f1[(n + expl_temp.f1.size(0)) + 1];
      d1 = expl_temp.f1[n + expl_temp.f1.size(0)];
      if (d > d1) {
        thisLayRho = (d - d1) / 2.0 + d1;
      } else {
        thisLayRho = (d1 - d) / 2.0 + d;
      }

      d = newYIm[n + 1];
      if (d > newYIm[n]) {
        thisLayRhoIm = (d - newYIm[n]) / 2.0 + newYIm[n];
      } else {
        thisLayRhoIm = (newYIm[n] - d) / 2.0 + d;
      }

      newSLD[n] = expl_temp.f1[n + 1] - expl_temp.f1[n];
      newSLD[n + newSLD.size(0)] = thisLayRho;
      newSLD[n + newSLD.size(0) * 2] = thisLayRhoIm;
      newSLD[n + newSLD.size(0) * 3] = 2.2204460492503131E-16;
    }
  }
}

// End of code generation (resampleLayers.cpp)
