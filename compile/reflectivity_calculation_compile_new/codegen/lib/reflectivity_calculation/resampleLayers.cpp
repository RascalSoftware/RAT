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
#include "adaptive.h"
#include "length.h"
#include "reflectivity_calculation_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void resampleLayers(const coder::array<double, 2U> &sldProfile,
                    coder::array<double, 2U> &newSLD)
{
  cell_17 expl_temp;
  double b_sldProfile[2];
  int i;
  int n;
  //  Function handle for adaptive resampling
  //  f = @(x) sldFunc(x);
  //
  //  Keep points and minangle as constants for now
  //  will fix later
  b_sldProfile[0] = sldProfile[0];
  b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
  adaptive(sldProfile, b_sldProfile, &expl_temp);
  // , 'nPoints', 50);
  n = coder::internal::intlength(expl_temp.f1.size(0));
  newSLD.set_size(n - 1, 3);
  n = (n - 1) * 3;
  for (i = 0; i < n; i++) {
    newSLD[i] = 0.0;
  }
  //  Now build a layer model from these resampled points
  i = coder::internal::intlength(expl_temp.f1.size(0));
  for (n = 0; n <= i - 2; n++) {
    double d;
    double thisLayRho;
    thisLayRho = expl_temp.f1[(n + expl_temp.f1.size(0)) + 1];
    d = expl_temp.f1[n + expl_temp.f1.size(0)];
    if (thisLayRho > d) {
      thisLayRho = (thisLayRho - d) / 2.0 + d;
    } else {
      thisLayRho += (d - thisLayRho) / 2.0;
    }
    newSLD[n] = expl_temp.f1[n + 1] - expl_temp.f1[n];
    newSLD[n + newSLD.size(0)] = thisLayRho;
    newSLD[n + newSLD.size(0) * 2] = 2.2204460492503131E-16;
  }
}

void resampleLayers(coder::array<double, 2U> &newSLD)
{
  cell_17 expl_temp;
  int i;
  int n;
  //  Function handle for adaptive resampling
  //  f = @(x) sldFunc(x);
  //
  //  Keep points and minangle as constants for now
  //  will fix later
  adaptive(&expl_temp);
  // , 'nPoints', 50);
  n = coder::internal::intlength(expl_temp.f1.size(0));
  newSLD.set_size(n - 1, 3);
  n = (n - 1) * 3;
  for (i = 0; i < n; i++) {
    newSLD[i] = 0.0;
  }
  //  Now build a layer model from these resampled points
  i = coder::internal::intlength(expl_temp.f1.size(0));
  for (n = 0; n <= i - 2; n++) {
    double d;
    double thisLayRho;
    thisLayRho = expl_temp.f1[(n + expl_temp.f1.size(0)) + 1];
    d = expl_temp.f1[n + expl_temp.f1.size(0)];
    if (thisLayRho > d) {
      thisLayRho = (thisLayRho - d) / 2.0 + d;
    } else {
      thisLayRho += (d - thisLayRho) / 2.0;
    }
    newSLD[n] = expl_temp.f1[n + 1] - expl_temp.f1[n];
    newSLD[n + newSLD.size(0)] = thisLayRho;
    newSLD[n + newSLD.size(0) * 2] = 2.2204460492503131E-16;
  }
}

// End of code generation (resampleLayers.cpp)
