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
void applyBackgroundCorrection(coder::array<double, 2U> &reflect,
                               coder::array<double, 2U> &Simul,
                               coder::array<double, 2U> &shifted_dat,
                               double backg, double backsType)
{
  coder::array<double, 1U> b_shifted_dat;
  switch (static_cast<int>(backsType)) {
  case 1: {
    // Add background to the simulation
    reflect.set_size(reflect.size(0), 2);
    Simul.set_size(Simul.size(0), 2);
    for (int i{0}; i < 2; i++) {
      int i1;
      int loop_ub;
      loop_ub = reflect.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        reflect[i1 + reflect.size(0) * i] =
            reflect[i1 + reflect.size(0) * i] + backg;
      }
      loop_ub = Simul.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        Simul[i1 + Simul.size(0) * i] = Simul[i1 + Simul.size(0) * i] + backg;
      }
    }
  } break;
  case 2: {
    int i;
    int loop_ub;
    //          %Subtract the background from the data..
    loop_ub = shifted_dat.size(0) - 1;
    b_shifted_dat.set_size(loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - backg;
    }
    loop_ub = b_shifted_dat.size(0);
    for (i = 0; i < loop_ub; i++) {
      shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
    }
    // shifted_dat(:,3) = shifted_dat(:,3) - backg;
  } break;
  }
}

// End of code generation (applyBackgroundCorrection.cpp)
