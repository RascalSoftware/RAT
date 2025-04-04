//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// allocateParamsToLayers.cpp
//
// Code generation for function 'allocateParamsToLayers'
//

// Include files
#include "allocateParamsToLayers.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "length.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void allocateParamsToLayers(const ::coder::array<double, 2U> &paramValues,
    const ::coder::array<cell_wrap_9, 2U> &layersDetails, ::coder::array<
    cell_wrap_51, 2U> &layerValues)
  {
    int numberOfLayers;

    //  Allocates parameters from the parameter array to the correct layers
    //
    //  This function takes the list of all layers in 'layersDetails',
    //  then loops over all the layers, putting in the correct
    //  parameter value from the parameters array into each layer in
    //  the 'layerValues' cell array
    numberOfLayers = coder::internal::intlength(layersDetails.size(0),
      layersDetails.size(1));
    layerValues.set_size(1, numberOfLayers);
    for (int i{0}; i < numberOfLayers; i++) {
      int layerLength;
      layerLength = coder::internal::intlength(layersDetails[i].f1.size(0),
        layersDetails[i].f1.size(1));
      for (int b_i{0}; b_i < 6; b_i++) {
        layerValues[i].f1[b_i] = 0.0;
      }

      //  Find thickness, roughness and SLD
      //  Input layer contains either 5 (real SLD) or 6 (complex SLD)
      //  values. If SLD is real, the imaginary column is set to zero
      for (int j{0}; j <= layerLength - 4; j++) {
        layerValues[i].f1[j] = paramValues[static_cast<int>(layersDetails[i]
          .f1[j]) - 1];
      }

      //  Layer Thickness
      layerValues[i].f1[3] = paramValues[static_cast<int>(layersDetails[i]
        .f1[layerLength - 3]) - 1];

      //  Get hydration value, which may be NaN
      if (!std::isnan(layersDetails[i].f1[layerLength - 2])) {
        layerValues[i].f1[4] = paramValues[static_cast<int>(layersDetails[i]
          .f1[layerLength - 2]) - 1];
      } else {
        layerValues[i].f1[4] = 0.0;
      }

      //  Fill in "hydrate with" value
      layerValues[i].f1[5] = layersDetails[i].f1[layersDetails[i].f1.size(0) *
        layersDetails[i].f1.size(1) - 1];
    }
  }
}

// End of code generation (allocateParamsToLayers.cpp)
