//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: allocateLayersForContrast.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:21:20
//

// Include Files
#include "allocateLayersForContrast.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Take the layers list for a contrast and build an
//  array of real valued layers
// Arguments    : const coder::array<double, 2U> *contrastLayers
//                const coder::array<cell_wrap_17, 2U> *outParameterisedLayers
//                coder::array<double, 2U> *thisContrastLayers
// Return Type  : void
//
void allocateLayersForContrast(const coder::array<double, 2U> &contrastLayers,
  const coder::array<cell_wrap_17, 2U> &outParameterisedLayers, coder::array<
  double, 2U> &thisContrastLayers)
{
  int n;
  int i;
  if ((contrastLayers.size(0) == 0) || (contrastLayers.size(1) == 0)) {
    n = 0;
  } else {
    n = contrastLayers.size(1);
  }

  thisContrastLayers.set_size(n, 5);
  n *= 5;
  for (i = 0; i < n; i++) {
    thisContrastLayers[i] = 0.0;
  }

  if ((contrastLayers.size(0) == 0) || (contrastLayers.size(1) == 0)) {
    n = 0;
  } else {
    n = contrastLayers.size(1);
  }

  for (int b_i = 0; b_i < n; b_i++) {
    for (i = 0; i < 5; i++) {
      thisContrastLayers[b_i + thisContrastLayers.size(0) * i] =
        outParameterisedLayers[static_cast<int>(contrastLayers[b_i]) - 1].f1[i];
    }
  }
}

//
// File trailer for allocateLayersForContrast.cpp
//
// [EOF]
//
