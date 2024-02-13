//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// applyHydrationReal.cpp
//
// Code generation for function 'applyHydrationReal'
//

// Include files
#include "applyHydrationReal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void applyHydrationReal(::coder::array<real_T, 2U> &thisContrastLayers, real_T
    bulkIn, real_T bulkOut)
  {
    ::coder::array<real_T, 2U> newOutLayers;
    int16_T outSize_idx_0;

    //  Applies the hydration correction to real value of layers
    //  if it is necessary.. (This is for when im(SLD) is not used)
    //  The only guidance we have to whether the user is using hydration
    //  in their custom model is the numbre of columns of the output
    outSize_idx_0 = static_cast<int16_T>(thisContrastLayers.size(0));

    //  [nlayers x nCols]
    if (static_cast<int16_T>(thisContrastLayers.size(1)) == 5) {
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //  we need to calculate the hydrated SLD
      newOutLayers.set_size(static_cast<int32_T>(outSize_idx_0), 3);
      loop_ub = outSize_idx_0;
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          newOutLayers[i1 + newOutLayers.size(0) * i] = 0.0;
        }
      }

      loop_ub = thisContrastLayers.size(0);
      for (i = 0; i < loop_ub; i++) {
        newOutLayers[i] = thisContrastLayers[i];
      }

      //  Thickness'
      loop_ub = thisContrastLayers.size(0);
      for (i = 0; i < loop_ub; i++) {
        newOutLayers[i + newOutLayers.size(0) * 2] = thisContrastLayers[i +
          thisContrastLayers.size(0) * 2];
      }

      //  Roughness
      i = outSize_idx_0;
      for (int32_T n{0}; n < i; n++) {
        real_T thisBulkHydr;
        real_T thisHydration;
        thisHydration = thisContrastLayers[n + thisContrastLayers.size(0) * 3] /
          100.0;

        //  Assume percent for backwards compatability
        if (thisContrastLayers[n + thisContrastLayers.size(0) * 4] == 0.0) {
          thisBulkHydr = bulkIn;
        } else {
          thisBulkHydr = bulkOut;
        }

        newOutLayers[n + newOutLayers.size(0)] = thisHydration * thisBulkHydr +
          (1.0 - thisHydration) * thisContrastLayers[n + thisContrastLayers.size
          (0)];

        //  Reassignment to keep codegen happy
      }

      thisContrastLayers.set_size(newOutLayers.size(0), 3);
      loop_ub = newOutLayers.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          thisContrastLayers[i1 + thisContrastLayers.size(0) * i] =
            newOutLayers[i1 + newOutLayers.size(0) * i];
        }
      }
    }
  }
}

// End of code generation (applyHydrationReal.cpp)
