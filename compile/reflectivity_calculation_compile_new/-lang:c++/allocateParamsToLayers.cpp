//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: allocateParamsToLayers.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "allocateParamsToLayers.h"
#include "length.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Allocates parameters from the parameter array to the correct layers
//
//  This function takes the list of all layers in 'layersDetails',
//  then loops over all the layers, putting in the correct
//  parameter value from the parameters array into each layer in
//  the 'outLayers' cell array
//
// Arguments    : const real_T params_data[]
//                const cell_wrap_14 layersDetails_data[]
//                const int32_T *layersDetails_size
//                cell_wrap_19 outLayers_data[]
//                int32_T outLayers_size[2]
// Return Type  : void
//
namespace RAT
{
  void allocateParamsToLayers(const real_T params_data[], const cell_wrap_14
    layersDetails_data[], const int32_T *layersDetails_size, cell_wrap_19
    outLayers_data[], int32_T outLayers_size[2])
  {
    real_T thisOutLayer[5];
    int32_T i;
    for (i = 0; i < 5; i++) {
      thisOutLayer[i] = 0.0;
    }

    outLayers_size[0] = 1;
    outLayers_size[1] = *layersDetails_size;
    i = *layersDetails_size;
    for (int32_T b_i{0}; b_i < i; b_i++) {
      int32_T i1;
      i1 = coder::internal::intlength(layersDetails_data[b_i].f1.size(0),
        layersDetails_data[b_i].f1.size(1));
      for (int32_T n{0}; n <= i1 - 2; n++) {
        if (!std::isnan(layersDetails_data[b_i].f1[n])) {
          thisOutLayer[n] = params_data[static_cast<int32_T>
            (layersDetails_data[b_i].f1[n]) - 1];
        } else {
          thisOutLayer[n] = rtNaN;
        }
      }

      thisOutLayer[coder::internal::intlength(layersDetails_data[b_i].f1.size(0),
        layersDetails_data[b_i].f1.size(1)) - 1] = layersDetails_data[b_i]
        .f1[layersDetails_data[b_i].f1.size(0) * layersDetails_data[b_i].f1.size
        (1) - 1];
      for (i1 = 0; i1 < 5; i1++) {
        outLayers_data[b_i].f1[i1] = thisOutLayer[i1];
      }
    }
  }
}

//
// File trailer for allocateParamsToLayers.cpp
//
// [EOF]
//
