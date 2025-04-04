//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// allocateLayersForContrast.cpp
//
// Code generation for function 'allocateLayersForContrast'
//

// Include files
#include "allocateLayersForContrast.h"
#include "RATMain_internal_types.h"
#include "length.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void allocateLayersForContrast(const ::coder::array<double, 2U> &layerIndices,
    const ::coder::array<cell_wrap_51, 2U> &layerValues, ::coder::array<double,
    2U> &layers)
  {
    int n_tmp;

    //  Decide which layers are needed for a particular contrast.
    //  This function takes the master array of all layers
    //  and extracts which parameters are required for
    //  a particular contrast.
    //
    //  INPUTS:
    //      layerValues      - List of all the available layers
    //      layerIndices     - Array detailing which layers are required for this contrast
    n_tmp = coder::internal::intlength(layerIndices.size(0), layerIndices.size(1));
    layers.set_size(n_tmp, 6);
    for (int i{0}; i < 6; i++) {
      for (int i1{0}; i1 < n_tmp; i1++) {
        layers[i1 + layers.size(0) * i] = 0.0;
      }
    }

    for (int b_i{0}; b_i < n_tmp; b_i++) {
      for (int i{0}; i < 6; i++) {
        layers[b_i + layers.size(0) * i] = layerValues[static_cast<int>
          (layerIndices[b_i]) - 1].f1[i];
      }
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
