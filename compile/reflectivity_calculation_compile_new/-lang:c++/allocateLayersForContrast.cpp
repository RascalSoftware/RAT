//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: allocateLayersForContrast.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "allocateLayersForContrast.h"
#include "length.h"
#include "nullAssignment.h"
#include "reflectivity_calculation_internal_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Decide which layers are needed for a particular contrast.
//  This function takes the master array of all layers
//  and extracts which parameters are required for
//  a particular contrast.
//
//  INPUTS:
//      outParameterisedLayers - List of all the available layers
//      thisContrastLayers     - Array detailing which layers are required for this contrast
//
// Arguments    : const real_T contrastLayers_data[]
//                const int32_T contrastLayers_size[2]
//                const cell_wrap_19 outParameterisedLayers_data[]
//                real_T thisContrastLayers_data[]
//                int32_T thisContrastLayers_size[2]
// Return Type  : void
//
namespace RAT
{
  void allocateLayersForContrast(const real_T contrastLayers_data[], const
    int32_T contrastLayers_size[2], const cell_wrap_19
    outParameterisedLayers_data[], real_T thisContrastLayers_data[], int32_T
    thisContrastLayers_size[2])
  {
    int32_T n_tmp;
    n_tmp = coder::internal::intlength(contrastLayers_size[0],
      contrastLayers_size[1]);
    thisContrastLayers_size[0] = n_tmp;
    thisContrastLayers_size[1] = 5;
    for (int32_T i{0}; i < 5; i++) {
      for (int32_T i1{0}; i1 < n_tmp; i1++) {
        thisContrastLayers_data[i1 + n_tmp * i] = 0.0;
      }
    }

    for (int32_T b_i{0}; b_i < n_tmp; b_i++) {
      if (contrastLayers_data[b_i] != 0.0) {
        for (int32_T i{0}; i < 5; i++) {
          thisContrastLayers_data[b_i + thisContrastLayers_size[0] * i] =
            outParameterisedLayers_data[static_cast<int32_T>
            (contrastLayers_data[b_i]) - 1].f1[i];
        }
      } else {
        coder::internal::nullAssignment(thisContrastLayers_data,
          thisContrastLayers_size);
      }
    }
  }
}

//
// File trailer for allocateLayersForContrast.cpp
//
// [EOF]
//
