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
    int loop_ub;
    int n_tmp;

    //  Function handle for adaptive resampling
    //  f = @(x) SLDFunction(x);
    //
    b_sldProfile[0] = sldProfile[0];
    b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
    b_adaptive(sldProfile, b_sldProfile, minAngle * 3.1415926535897931, nPoints,
               expl_temp);
    n_tmp = coder::internal::intlength(expl_temp.f1.size(0), 1);
    newSLD.set_size(n_tmp - 1, 3);
    loop_ub = n_tmp - 1;
    for (int i{0}; i < 3; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    for (int n{0}; n <= n_tmp - 2; n++) {
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
    int loop_ub;
    int n_tmp;

    //  Function handle for adaptive resampling
    //  f = @(x) SLDFunction(x);
    //
    b_sldProfile[0] = sldProfile[0];
    b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
    adaptive(sldProfile, b_sldProfile, minAngle * 3.1415926535897931, nPoints,
             expl_temp);
    n_tmp = coder::internal::intlength(expl_temp.f1.size(0), 1);
    newSLD.set_size(n_tmp - 1, 3);
    loop_ub = n_tmp - 1;
    for (int i{0}; i < 3; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        newSLD[i1 + newSLD.size(0) * i] = 0.0;
      }
    }

    //  Now build a layer model from these resampled points
    for (int n{0}; n <= n_tmp - 2; n++) {
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
