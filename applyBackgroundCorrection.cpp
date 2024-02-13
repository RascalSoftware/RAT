//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// applyBackgroundCorrection.cpp
//
// Code generation for function 'applyBackgroundCorrection'
//

// Include files
#include "applyBackgroundCorrection.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void applyBackgroundCorrection(::coder::array<real_T, 2U> &reflect, ::coder::
    array<real_T, 2U> &simul, ::coder::array<real_T, 2U> &shiftedData, real_T
    backgroundParams, real_T contrastBackgroundsType)
  {
    ::coder::array<real_T, 1U> c_reflect;
    switch (static_cast<int32_T>(contrastBackgroundsType)) {
     case 1:
      {
        int32_T b_reflect;
        int32_T i;

        // Add background to the simulation
        b_reflect = reflect.size(0) - 1;
        c_reflect.set_size(b_reflect + 1);
        for (i = 0; i <= b_reflect; i++) {
          c_reflect[i] = reflect[i + reflect.size(0)] + backgroundParams;
        }

        b_reflect = c_reflect.size(0);
        for (i = 0; i < b_reflect; i++) {
          reflect[i + reflect.size(0)] = c_reflect[i];
        }

        b_reflect = simul.size(0) - 1;
        c_reflect.set_size(b_reflect + 1);
        for (i = 0; i <= b_reflect; i++) {
          c_reflect[i] = simul[i + simul.size(0)] + backgroundParams;
        }

        b_reflect = c_reflect.size(0);
        for (i = 0; i < b_reflect; i++) {
          simul[i + simul.size(0)] = c_reflect[i];
        }
      }
      break;

     case 2:
      {
        int32_T b_reflect;
        int32_T i;

        // Subtract the background from the data..
        b_reflect = shiftedData.size(0) - 1;
        c_reflect.set_size(b_reflect + 1);
        for (i = 0; i <= b_reflect; i++) {
          c_reflect[i] = shiftedData[i + shiftedData.size(0)] - backgroundParams;
        }

        b_reflect = c_reflect.size(0);
        for (i = 0; i < b_reflect; i++) {
          shiftedData[i + shiftedData.size(0)] = c_reflect[i];
        }

        // shiftedData(:,3) = shiftedData(:,3) - backgroundParams;
      }
      break;
    }
  }
}

// End of code generation (applyBackgroundCorrection.cpp)
