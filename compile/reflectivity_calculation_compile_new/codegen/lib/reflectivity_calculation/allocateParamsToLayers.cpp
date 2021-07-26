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
#include "isnan.h"
#include "length.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void allocateParamsToLayers(const coder::array<double, 2U> &params,
                            const coder::array<cell_wrap_2, 1U> &layersDetails,
                            coder::array<cell_wrap_15, 2U> &outLayers)
{
  double thisOutLayer[5];
  double numberOfLayers;
  int i;
  //  Allocates parameters from the parameter array to the correct layers
  //
  //  This function takes the list of all layers in 'layersDetails',
  //  then loops over all the layers, putting in the correct
  //  parameter value from the parameters array into each layer in
  //  the 'outLayers' cell array
  numberOfLayers = coder::internal::varargin_numel(layersDetails.size(0));
  for (i = 0; i < 5; i++) {
    thisOutLayer[i] = 0.0;
  }
  outLayers.set_size(1, static_cast<int>(numberOfLayers));
  i = static_cast<int>(numberOfLayers);
  for (int b_i{0}; b_i < i; b_i++) {
    int i1;
    i1 = layersDetails[b_i].f1.size(1);
    for (int n{0}; n <= i1 - 2; n++) {
      if (!coder::b_isnan(layersDetails[b_i].f1[n])) {
        thisOutLayer[n] =
            params[static_cast<int>(layersDetails[b_i].f1[n]) - 1];
      } else {
        thisOutLayer[n] = rtNaN;
      }
    }
    thisOutLayer[layersDetails[b_i].f1.size(1) - 1] =
        layersDetails[b_i].f1[layersDetails[b_i].f1.size(1) - 1];
    for (i1 = 0; i1 < 5; i1++) {
      outLayers[b_i].f1[i1] = thisOutLayer[i1];
    }
  }
}

// End of code generation (allocateParamsToLayers.cpp)
