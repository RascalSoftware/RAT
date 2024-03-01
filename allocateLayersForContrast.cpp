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
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void allocateLayersForContrast(const ::coder::array<real_T, 2U>
    &contrastLayers, const ::coder::array<cell_wrap_17, 2U>
    &outParameterisedLayers, boolean_T useImaginary, real_T
    thisContrastLayers_data[], int32_T thisContrastLayers_size[2])
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
      thisContrastLayers_size[0] = n;
      thisContrastLayers_size[1] = 6;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 < n; i1++) {
          thisContrastLayers_data[i1 + n * i] = 0.0;
        }
      }
    } else {
      n = coder::internal::intlength(contrastLayers.size(0), contrastLayers.size
        (1));
      thisContrastLayers_size[0] = n;
      thisContrastLayers_size[1] = 5;
      for (i = 0; i < 5; i++) {
        for (i1 = 0; i1 < n; i1++) {
          thisContrastLayers_data[i1 + n * i] = 0.0;
        }
      }
    }

    i = coder::internal::intlength(contrastLayers.size(0), contrastLayers.size(1));
    for (int32_T b_i{0}; b_i < i; b_i++) {
      if (contrastLayers[b_i] != 0.0) {
        //          % Check the length of thisLayer. If it's 6, then we have an
        //          % imaginary SLD defined. Combile them into one complex number at
        //          % this point.
        //          if length(thisLayer) == 6
        //              compSLD = complex(thisLayer(2),thisLayer(3));
        //              thisLayer = [thisLayer(1) compSLD thisLayer(4:end)];
        //          end
        n = outParameterisedLayers[static_cast<int32_T>(contrastLayers[b_i]) - 1]
          .f1.size(1);
        for (i1 = 0; i1 < n; i1++) {
          thisContrastLayers_data[b_i + thisContrastLayers_size[0] * i1] =
            outParameterisedLayers[static_cast<int32_T>(contrastLayers[b_i]) - 1]
            .f1[i1];
        }
      } else {
        coder::internal::nullAssignment(thisContrastLayers_data,
          thisContrastLayers_size);
      }
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
