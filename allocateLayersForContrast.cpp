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
#include "RATMain_types.h"
#include "length.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void allocateLayersForContrast(const ::coder::array<real_T, 2U>
    &contrastLayers, const ::coder::array<cell_wrap_48, 2U>
    &outParameterisedLayers, boolean_T useImaginary, ::coder::array<real_T, 2U>
    &thisContrastLayers)
  {
    int32_T i;
    int32_T i1;
    int32_T n;

    //  Decide which layers are needed for a particular contrast.
    //  This function takes the master array of all layers
    //  and extracts which parameters are required for
    //  a particular contrast.
    //
    //  INPUTS:
    //      outParameterisedLayers - List of all the available layers
    //      thisContrastLayers     - Array detailing which layers are required for this contrast
    if (useImaginary) {
      n = coder::internal::intlength(contrastLayers.size(0), contrastLayers.size
        (1));
      thisContrastLayers.set_size(n, 6);
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 < n; i1++) {
          thisContrastLayers[i1 + thisContrastLayers.size(0) * i] = 0.0;
        }
      }
    } else {
      n = coder::internal::intlength(contrastLayers.size(0), contrastLayers.size
        (1));
      thisContrastLayers.set_size(n, 5);
      for (i = 0; i < 5; i++) {
        for (i1 = 0; i1 < n; i1++) {
          thisContrastLayers[i1 + thisContrastLayers.size(0) * i] = 0.0;
        }
      }
    }

    i = coder::internal::intlength(contrastLayers.size(0), contrastLayers.size(1));
    for (int32_T b_i{0}; b_i < i; b_i++) {
      n = outParameterisedLayers[static_cast<int32_T>(contrastLayers[b_i]) - 1].
        f1.size(1);
      for (i1 = 0; i1 < n; i1++) {
        thisContrastLayers[b_i + thisContrastLayers.size(0) * i1] =
          outParameterisedLayers[static_cast<int32_T>(contrastLayers[b_i]) - 1].
          f1[i1];
      }
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
