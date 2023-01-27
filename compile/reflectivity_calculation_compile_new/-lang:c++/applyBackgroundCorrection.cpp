//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: applyBackgroundCorrection.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "applyBackgroundCorrection.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &reflect
//                ::coder::array<real_T, 2U> &Simul
//                real_T shifted_dat_data[]
//                const int32_T shifted_dat_size[2]
//                real_T backg
//                real_T backsType
// Return Type  : void
//
namespace RAT
{
  void applyBackgroundCorrection(::coder::array<real_T, 2U> &reflect, ::coder::
    array<real_T, 2U> &Simul, real_T shifted_dat_data[], const int32_T
    shifted_dat_size[2], real_T backg, real_T backsType)
  {
    ::coder::array<real_T, 1U> b_reflect;
    switch (static_cast<int32_T>(backsType)) {
     case 1:
      {
        int32_T loop_ub;

        // Add background to the simulation
        b_reflect.set_size(reflect.size(0));
        loop_ub = reflect.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          b_reflect[i] = reflect[i + reflect.size(0)] + backg;
        }

        loop_ub = b_reflect.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          reflect[i + reflect.size(0)] = b_reflect[i];
        }

        b_reflect.set_size(Simul.size(0));
        loop_ub = Simul.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          b_reflect[i] = Simul[i + Simul.size(0)] + backg;
        }

        loop_ub = b_reflect.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          Simul[i + Simul.size(0)] = b_reflect[i];
        }
      }
      break;

     case 2:
      {
        real_T b_shifted_dat_data[1000];
        int32_T b_shifted_dat_size;
        int32_T loop_ub;

        //          %Subtract the background from the data..
        b_shifted_dat_size = shifted_dat_size[0];
        loop_ub = shifted_dat_size[0];
        for (int32_T i{0}; i < loop_ub; i++) {
          b_shifted_dat_data[i] = shifted_dat_data[i + shifted_dat_size[0]] -
            backg;
        }

        for (int32_T i{0}; i < b_shifted_dat_size; i++) {
          shifted_dat_data[i + shifted_dat_size[0]] = b_shifted_dat_data[i];
        }

        // shifted_dat(:,3) = shifted_dat(:,3) - backg;
      }
      break;
    }
  }
}

//
// File trailer for applyBackgroundCorrection.cpp
//
// [EOF]
//
