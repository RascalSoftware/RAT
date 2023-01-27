//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: loopCppCustlayWrapper_CustLaysingle.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "loopCppCustlayWrapper_CustLaysingle.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Arguments    : real_T numberOfContrasts
//                ::coder::array<cell_wrap_1, 1U> &allLayers
//                ::coder::array<real_T, 1U> &allRoughs
// Return Type  : void
//
namespace RAT
{
  void loopCppCustlayWrapper_CustLaysingle(real_T numberOfContrasts, ::coder::
    array<cell_wrap_1, 1U> &allLayers, ::coder::array<real_T, 1U> &allRoughs)
  {
    int32_T loop_ub_tmp;
    loop_ub_tmp = static_cast<int32_T>(numberOfContrasts);
    allLayers.set_size(loop_ub_tmp);
    allRoughs.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      allLayers[i].f1.size[0] = 2;
      allLayers[i].f1.size[1] = 1;
      allLayers[i].f1.data[0] = 1.0;
      allLayers[i].f1.data[1] = 1.0;
      allRoughs[i] = 0.0;
    }

    // ; % dll name must be same as function name
    // customFiles{1}{3};
    //      strLibName = string(LibName);
    //      strfunctionName = string(functionName);
  }
}

//
// File trailer for loopCppCustlayWrapper_CustLaysingle.cpp
//
// [EOF]
//
