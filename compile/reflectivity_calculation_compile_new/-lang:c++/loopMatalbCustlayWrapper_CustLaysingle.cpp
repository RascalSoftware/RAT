//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: loopMatalbCustlayWrapper_CustLaysingle.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "loopMatalbCustlayWrapper_CustLaysingle.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// This is a dummy file to allow source code generation to proceed...
//
// Arguments    : real_T numberOfContrasts
//                ::coder::array<cell_wrap_14, 1U> &allLayers
//                ::coder::array<real_T, 1U> &allRoughs
// Return Type  : void
//
namespace RAT
{
  void loopMatalbCustlayWrapper_CustLaysingle(real_T numberOfContrasts, ::coder::
    array<cell_wrap_14, 1U> &allLayers, ::coder::array<real_T, 1U> &allRoughs)
  {
    ::coder::array<cell_wrap_34, 1U> tempAllLayers;
    ::coder::array<int8_T, 1U> tempAllRoughs;
    int32_T i;
    int32_T loop_ub;
    i = static_cast<int32_T>(numberOfContrasts);
    tempAllRoughs.set_size(i);

    //  Dummy values to allow code generation to proceed....
    tempAllLayers.set_size(i);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      tempAllLayers[b_i].f1.set_size(1, 3);
      tempAllLayers[b_i].f1[0] = 0.0;
      tempAllLayers[b_i].f1[tempAllLayers[b_i].f1.size(0)] = 0.0;
      tempAllLayers[b_i].f1[tempAllLayers[b_i].f1.size(0) * 2] = 0.0;
      tempAllRoughs[b_i] = 1;
    }

    //  All the following is intended to be casting from mxArray's to doubles.
    //  I'm not sure if all of this is necessary, but it compiles...
    allLayers.set_size(i);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      allLayers[b_i].f1.set_size(1, 3);
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        allLayers[b_i].f1[allLayers[b_i].f1.size(0) * loop_ub] =
          tempAllLayers[b_i].f1[tempAllLayers[b_i].f1.size(0) * loop_ub];
      }
    }

    // allLayers = tempAllLayers;
    allRoughs.set_size(tempAllRoughs.size(0));
    loop_ub = tempAllRoughs.size(0);
    for (i = 0; i < loop_ub; i++) {
      allRoughs[i] = 1.0;
    }
  }
}

//
// File trailer for loopMatalbCustlayWrapper_CustLaysingle.cpp
//
// [EOF]
//
