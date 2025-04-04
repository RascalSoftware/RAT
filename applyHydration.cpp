//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// applyHydration.cpp
//
// Code generation for function 'applyHydration'
//

// Include files
#include "applyHydration.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void applyHydration(::coder::array<double, 2U> &layers, double bulkIn, double
                      bulkOut)
  {
    int tmp_size[2];

    //  Applies the hydration correction to real value of the SLD of the layers
    //  if it is necessary.
    //  The only guidance we have to whether the user is using hydration
    //  in their custom model is the number of columns of the output
    //  [nlayers x nCols]
    if (static_cast<short>(layers.size(1)) == 6) {
      int tmp_data[9];
      int i;
      int loop_ub;

      //  we need to calculate the hydrated SLD
      i = static_cast<short>(layers.size(0));
      for (int b_i{0}; b_i < i; b_i++) {
        double d;
        double hydration;
        hydration = 0.01 * layers[b_i + layers.size(0) * 4];

        //  Assume percent for backwards compatibility
        //  Index 6 determines what we hydrate with
        //  Hydrate the real component of the SLD.
        //  Note that we never hydrate the imaginary component of the SLD.
        if (layers[b_i + layers.size(0) * 5] == 1.0) {
          d = bulkIn;
        } else {
          d = bulkOut;
        }

        layers[b_i + layers.size(0)] = hydration * d + (1.0 - hydration) *
          layers[b_i + layers.size(0)];
      }

      //  Remove hydration columns
      tmp_size[0] = 1;
      tmp_size[1] = layers.size(1) - 4;
      loop_ub = layers.size(1);
      for (i = 0; i <= loop_ub - 5; i++) {
        tmp_data[i] = i + 5;
      }

      coder::internal::nullAssignment(layers, tmp_data, tmp_size);
    }
  }
}

// End of code generation (applyHydration.cpp)
