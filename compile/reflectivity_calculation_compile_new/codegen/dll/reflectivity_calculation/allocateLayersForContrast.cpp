//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// allocateLayersForContrast.cpp
//
// Code generation for function 'allocateLayersForContrast'
//

// Include files
#include "allocateLayersForContrast.h"
#include "reflectivity_calculation_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void allocateLayersForContrast(
    const coder::array<double, 2U> &contrastLayers,
    const coder::array<cell_wrap_15, 2U> &outParameterisedLayers,
    coder::array<double, 2U> &thisContrastLayers)
{
  int i;
  int i1;
  int loop_ub;
  //  Decide which layers are needed for a particular contrast
  //  This function takes the master array of all layers
  //  and extracts which parameters are requires for
  //  a particular contrast.
  //  outParameterisedLayers - List of all the available layers
  //  thisContrastLayers     - Array detailing which layers are required
  //                           for this contrast
  thisContrastLayers.set_size(contrastLayers.size(1), 5);
  loop_ub = contrastLayers.size(1);
  for (i = 0; i < 5; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      thisContrastLayers[i1 + thisContrastLayers.size(0) * i] = 0.0;
    }
  }
  i = contrastLayers.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    for (i1 = 0; i1 < 5; i1++) {
      thisContrastLayers[loop_ub + thisContrastLayers.size(0) * i1] =
          outParameterisedLayers[static_cast<int>(contrastLayers[loop_ub]) - 1]
              .f1[i1];
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
