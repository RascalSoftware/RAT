//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// allocateParamsToLayers.cpp
//
// Code generation for function 'allocateParamsToLayers'
//

// Include files
#include "allocateParamsToLayers.h"
#include "RATMain_types.h"
#include "length.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace RAT
{
  void allocateParamsToLayers(const ::coder::array<real_T, 2U> &params, const ::
    coder::array<cell_wrap_12, 2U> &layersDetails, ::coder::array<cell_wrap_14,
    2U> &outLayers)
  {
    real_T thisOutLayer_data[10];
    int32_T numberOfLayers;

    //  Allocates parameters from the parameter array to the correct layers
    //
    //  This function takes the list of all layers in 'layersDetails',
    //  then loops over all the layers, putting in the correct
    //  parameter value from the parameters array into each layer in
    //  the 'outLayers' cell array
    numberOfLayers = coder::internal::intlength(layersDetails.size(0),
      layersDetails.size(1));
    outLayers.set_size(1, numberOfLayers);
    for (int32_T i{0}; i < numberOfLayers; i++) {
      int32_T b_i;
      int32_T n;
      n = coder::internal::intlength(layersDetails[i].f1.size(0),
        layersDetails[i].f1.size(1));
      if (0 <= n - 1) {
        std::memset(&thisOutLayer_data[0], 0, n * sizeof(real_T));
      }

      b_i = coder::internal::intlength(layersDetails[i].f1.size(0),
        layersDetails[i].f1.size(1));
      for (int32_T b_n{0}; b_n <= b_i - 2; b_n++) {
        if (!std::isnan(layersDetails[i].f1[b_n])) {
          thisOutLayer_data[b_n] = params[static_cast<int32_T>(layersDetails[i].
            f1[b_n]) - 1];
        } else {
          thisOutLayer_data[b_n] = rtNaN;
        }
      }

      thisOutLayer_data[coder::internal::intlength(layersDetails[i].f1.size(0),
        layersDetails[i].f1.size(1)) - 1] = layersDetails[i].f1[layersDetails[i]
        .f1.size(0) * layersDetails[i].f1.size(1) - 1];
      outLayers[i].f1.size[0] = 1;
      outLayers[i].f1.size[1] = n;
      for (b_i = 0; b_i < n; b_i++) {
        outLayers[i].f1.data[b_i] = thisOutLayer_data[b_i];
      }
    }
  }
}

// End of code generation (allocateParamsToLayers.cpp)
