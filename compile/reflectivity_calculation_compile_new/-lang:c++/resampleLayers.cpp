//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: resampleLayers.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "resampleLayers.h"
#include "adaptive_new.h"
#include "length.h"
#include "reflectivity_calculation_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Function handle for adaptive resampling
//  f = @(x) sldFunc(x);
//
//
// Arguments    : const ::coder::array<real_T, 2U> &sldProfile
//                const real_T resamPars[2]
//                ::coder::array<real_T, 2U> &newSLD
// Return Type  : void
//
namespace RAT
{
  void resampleLayers(const ::coder::array<real_T, 2U> &sldProfile, const real_T
                      resamPars[2], ::coder::array<real_T, 2U> &newSLD)
  {
    cell_23 expl_temp;
    real_T b_sldProfile[2];
    int32_T i;
    int32_T n;

    //  Keep points and minangle as constants for now
    //  will fix later
    b_sldProfile[0] = sldProfile[0];
    b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
    adaptive_new(sldProfile, b_sldProfile, resamPars[0] * 3.1415926535897931,
                 resamPars[1], &expl_temp);
    n = coder::internal::intlength(expl_temp.f1.size(0), 1);
    newSLD.set_size(n - 1, 3);
    n--;
    for (i = 0; i < 3; i++) {
      for (int32_T i1{0}; i1 < n; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    i = coder::internal::intlength(expl_temp.f1.size(0), 1);
    for (n = 0; n <= i - 2; n++) {
      real_T d;
      real_T d1;
      real_T thisLayRho;
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

  //
  // Function handle for adaptive resampling
  //  f = @(x) sldFunc(x);
  //
  //
  // Arguments    : const real_T sldProfile_data[]
  //                const int32_T sldProfile_size[2]
  //                const real_T resamPars[2]
  //                ::coder::array<real_T, 2U> &newSLD
  // Return Type  : void
  //
  void resampleLayers(const real_T sldProfile_data[], const int32_T
                      sldProfile_size[2], const real_T resamPars[2], ::coder::
                      array<real_T, 2U> &newSLD)
  {
    cell_23 expl_temp;
    real_T sldProfile[2];
    int32_T i;
    int32_T n;

    //  Keep points and minangle as constants for now
    //  will fix later
    sldProfile[0] = sldProfile_data[0];
    sldProfile[1] = sldProfile_data[sldProfile_size[0] - 1];
    adaptive_new(sldProfile_data, sldProfile_size, sldProfile, resamPars[0] *
                 3.1415926535897931, resamPars[1], &expl_temp);
    n = coder::internal::intlength(expl_temp.f1.size(0), 1);
    newSLD.set_size(n - 1, 3);
    n--;
    for (i = 0; i < 3; i++) {
      for (int32_T i1{0}; i1 < n; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    i = coder::internal::intlength(expl_temp.f1.size(0), 1);
    for (n = 0; n <= i - 2; n++) {
      real_T d;
      real_T d1;
      real_T thisLayRho;
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

//
// File trailer for resampleLayers.cpp
//
// [EOF]
//
