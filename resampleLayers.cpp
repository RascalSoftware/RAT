//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resampleLayers.cpp
//
// Code generation for function 'resampleLayers'
//

// Include files
#include "resampleLayers.h"
#include "RATMain_internal_types.h"
#include "adaptive.h"
#include "length.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void b_resampleLayers(const ::coder::array<double, 2U> &sldProfile, double
                        minAngle, double nPoints, ::coder::array<double, 2U>
                        &newSLD)
  {
    cell_56 expl_temp;
    double b_sldProfile[2];
    int i;
    int n;

    //  Function handle for adaptive resampling
    //  f = @(x) SLDFunction(x);
    //
    b_sldProfile[0] = sldProfile[0];
    b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
    b_adaptive(sldProfile, b_sldProfile, minAngle * 3.1415926535897931, nPoints,
               &expl_temp);
    n = coder::internal::intlength(expl_temp.f1.size(0), 1);
    newSLD.set_size(n - 1, 3);
    n--;
    for (i = 0; i < 3; i++) {
      for (int i1{0}; i1 < n; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    i = coder::internal::intlength(expl_temp.f1.size(0), 1);
    for (n = 0; n <= i - 2; n++) {
      double d;
      double d1;
      double thisLayRho;
      d = expl_temp.f1[(n + expl_temp.f1.size(0)) + 1];
      d1 = expl_temp.f1[n + expl_temp.f1.size(0)];
      if (d > d1) {
        thisLayRho = (d - d1) / 2.0 + d1;
      } else {
        thisLayRho = (d1 - d) / 2.0 + d;
      }

      newSLD[n] = expl_temp.f1[n + 1] - expl_temp.f1[n];
      newSLD[n + newSLD.size(0)] = thisLayRho;
      newSLD[n + newSLD.size(0) * 2] = 2.2204460492503131E-16;
    }
  }

  void resampleLayers(const ::coder::array<double, 2U> &sldProfile, double
                      minAngle, double nPoints, ::coder::array<double, 2U>
                      &newSLD)
  {
    cell_56 expl_temp;
    double b_sldProfile[2];
    int i;
    int n;

    //  Function handle for adaptive resampling
    //  f = @(x) SLDFunction(x);
    //
    b_sldProfile[0] = sldProfile[0];
    b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
    adaptive(sldProfile, b_sldProfile, minAngle * 3.1415926535897931, nPoints,
             &expl_temp);
    n = coder::internal::intlength(expl_temp.f1.size(0), 1);
    newSLD.set_size(n - 1, 3);
    n--;
    for (i = 0; i < 3; i++) {
      for (int i1{0}; i1 < n; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    i = coder::internal::intlength(expl_temp.f1.size(0), 1);
    for (n = 0; n <= i - 2; n++) {
      double d;
      double d1;
      double thisLayRho;
      d = expl_temp.f1[(n + expl_temp.f1.size(0)) + 1];
      d1 = expl_temp.f1[n + expl_temp.f1.size(0)];
      if (d > d1) {
        thisLayRho = (d - d1) / 2.0 + d1;
      } else {
        thisLayRho = (d1 - d) / 2.0 + d;
      }

      newSLD[n] = expl_temp.f1[n + 1] - expl_temp.f1[n];
      newSLD[n + newSLD.size(0)] = thisLayRho;
      newSLD[n + newSLD.size(0) * 2] = 2.2204460492503131E-16;
    }
  }
}

// End of code generation (resampleLayers.cpp)
