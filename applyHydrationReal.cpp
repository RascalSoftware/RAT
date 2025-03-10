//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void applyHydrationReal(::coder::array<double, 2U> &thisContrastLayers, double
    bulkIn, double bulkOut)
  {
    ::coder::array<double, 2U> newOutLayers;
    short outSize_idx_0;

    //  Applies the hydration correction to real value of layers
    //  if it is necessary.. (This is for when im(SLD) is not used)
    //  The only guidance we have to whether the user is using hydration
    //  in their custom model is the numbre of columns of the output
    outSize_idx_0 = static_cast<short>(thisContrastLayers.size(0));

    //  [nlayers x nCols]
    if (static_cast<short>(thisContrastLayers.size(1)) == 5) {
      int loop_ub;
      int loop_ub_tmp;

      //  we need to calculate the hydrated SLD
      newOutLayers.set_size(static_cast<int>(outSize_idx_0), 3);
      loop_ub_tmp = outSize_idx_0;
      for (int i{0}; i < 3; i++) {
        for (int i1{0}; i1 < loop_ub_tmp; i1++) {
          newOutLayers[i1 + newOutLayers.size(0) * i] = 0.0;
        }
      }

      for (int i{0}; i < loop_ub_tmp; i++) {
        newOutLayers[i] = thisContrastLayers[i];
      }

      //  Thickness'
      loop_ub = newOutLayers.size(0);
      for (int i{0}; i < loop_ub; i++) {
        newOutLayers[i + newOutLayers.size(0) * 2] = thisContrastLayers[i +
          thisContrastLayers.size(0) * 2];
      }

      //  Roughness
      for (int n{0}; n < loop_ub_tmp; n++) {
        double d;
        double thisHydration;
        thisHydration = thisContrastLayers[n + thisContrastLayers.size(0) * 3] /
          100.0;

        //  Assume percent for backwards compatability
        if (thisContrastLayers[n + thisContrastLayers.size(0) * 4] == 0.0) {
          d = bulkIn;
        } else {
          d = bulkOut;
        }

        newOutLayers[n + newOutLayers.size(0)] = thisHydration * d + (1.0 -
          thisHydration) * thisContrastLayers[n + thisContrastLayers.size(0)];

        //  Reassignment to keep codegen happy
      }

      thisContrastLayers.set_size(newOutLayers.size(0), 3);
      loop_ub = newOutLayers.size(0);
      for (int i{0}; i < 3; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          thisContrastLayers[i1 + thisContrastLayers.size(0) * i] =
            newOutLayers[i1 + newOutLayers.size(0) * i];
        }
      }
    }
  }
}

// End of code generation (applyHydrationReal.cpp)
