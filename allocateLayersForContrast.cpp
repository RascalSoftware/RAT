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
  void allocateLayersForContrast(const ::coder::array<double, 2U>
    &contrastLayers, const ::coder::array<cell_wrap_54, 2U>
    &outParameterisedLayers, ::coder::array<double, 2U> &thisContrastLayers)
  {
    int n_tmp;

    //  Decide which layers are needed for a particular contrast.
    //  This function takes the master array of all layers
    //  and extracts which parameters are required for
    //  a particular contrast.
    //
    //  INPUTS:
    //      outParameterisedLayers - List of all the available layers
    //      thisContrastLayers     - Array detailing which layers are required for this contrast
    n_tmp = coder::internal::intlength(contrastLayers.size(0),
      contrastLayers.size(1));
    thisContrastLayers.set_size(n_tmp, 6);
    for (int i{0}; i < 6; i++) {
      for (int i1{0}; i1 < n_tmp; i1++) {
        thisContrastLayers[i1 + thisContrastLayers.size(0) * i] = 0.0;
      }
    }

    for (int b_i{0}; b_i < n_tmp; b_i++) {
      for (int i{0}; i < 6; i++) {
        thisContrastLayers[b_i + thisContrastLayers.size(0) * i] =
          outParameterisedLayers[static_cast<int>(contrastLayers[b_i]) - 1].f1[i];
      }
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
