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
#include <cmath>
#include <cstring>

// Function Definitions
namespace RAT
{
  void allocateParamsToLayers(const ::coder::array<real_T, 2U> &params, const ::
    coder::array<cell_wrap_8, 1U> &layersDetails, ::coder::array<cell_wrap_22,
    2U> &outLayers)
  {
    real_T thisOutLayer_data[10];
    int32_T i;

    //  Allocates parameters from the parameter array to the correct layers
    //
    //  This function takes the list of all layers in 'layersDetails',
    //  then loops over all the layers, putting in the correct
    //  parameter value from the parameters array into each layer in
    //  the 'outLayers' cell array
    i = layersDetails.size(0);
    outLayers.set_size(1, static_cast<int32_T>(static_cast<int16_T>
      (layersDetails.size(0))));
    for (int32_T b_i{0}; b_i < i; b_i++) {
      int32_T i1;
      int32_T n;
      n = coder::internal::intlength(layersDetails[b_i].f1.size(0),
        layersDetails[b_i].f1.size(1));
      if (0 <= n - 1) {
        std::memset(&thisOutLayer_data[0], 0, n * sizeof(real_T));
      }

      i1 = coder::internal::intlength(layersDetails[b_i].f1.size(0),
        layersDetails[b_i].f1.size(1));
      for (int32_T b_n{0}; b_n <= i1 - 2; b_n++) {
        if (!std::isnan(layersDetails[b_i].f1[b_n])) {
          thisOutLayer_data[b_n] = params[static_cast<int32_T>(layersDetails[b_i]
            .f1[b_n]) - 1];
        } else {
          thisOutLayer_data[b_n] = rtNaN;
        }
      }

      thisOutLayer_data[coder::internal::intlength(layersDetails[b_i].f1.size(0),
        layersDetails[b_i].f1.size(1)) - 1] = layersDetails[b_i]
        .f1[layersDetails[b_i].f1.size(0) * layersDetails[b_i].f1.size(1) - 1];
      outLayers[outLayers.size(0) * b_i].f1.set_size(1, n);
      for (i1 = 0; i1 < n; i1++) {
        outLayers[b_i].f1[i1] = thisOutLayer_data[i1];
      }
    }
  }
}

// End of code generation (allocateParamsToLayers.cpp)
