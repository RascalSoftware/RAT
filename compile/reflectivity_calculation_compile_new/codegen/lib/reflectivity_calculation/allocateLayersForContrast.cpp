//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: allocateLayersForContrast.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
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
//                const coder::array<cell_wrap_15, 2U> *outParameterisedLayers
//                coder::array<double, 2U> *thisContrastLayers
// Return Type  : void
//
void allocateLayersForContrast(const coder::array<double, 2U> &contrastLayers,
  const coder::array<cell_wrap_15, 2U> &outParameterisedLayers, coder::array<
  double, 2U> &thisContrastLayers)
{
  int loop_ub;
  int i;
  thisContrastLayers.set_size(contrastLayers.size(1), 5);
  loop_ub = contrastLayers.size(1) * 5;
  for (i = 0; i < loop_ub; i++) {
    thisContrastLayers[i] = 0.0;
  }

  i = contrastLayers.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    for (int i1 = 0; i1 < 5; i1++) {
      thisContrastLayers[loop_ub + thisContrastLayers.size(0) * i1] =
        outParameterisedLayers[static_cast<int>(contrastLayers[loop_ub]) - 1]
        .f1[i1];
    }
  }
}

//
// File trailer for allocateLayersForContrast.cpp
//
// [EOF]
//
