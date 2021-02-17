//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: applyBackgroundCorrection.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "applyBackgroundCorrection.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_reflectivityCalculation.h"

// Function Definitions

//
// Arguments    : coder::array<double, 2U> *reflect
//                coder::array<double, 2U> *Simul
//                coder::array<double, 2U> *shifted_dat
//                double backg
//                double backsType
// Return Type  : void
//
void applyBackgroundCorrection(coder::array<double, 2U> &reflect, coder::array<
  double, 2U> &Simul, coder::array<double, 2U> &shifted_dat, double backg,
  double backsType)
{
  coder::array<double, 1U> b_shifted_dat;
  switch (static_cast<int>(backsType)) {
   case 1:
    {
      int loop_ub;
      int i;

      // Add background to the simulation
      reflect.set_size(reflect.size(0), 2);
      Simul.set_size(Simul.size(0), 2);
      loop_ub = reflect.size(0);
      for (i = 0; i < loop_ub; i++) {
        reflect[i] = reflect[i] + backg;
      }

      loop_ub = Simul.size(0);
      for (i = 0; i < loop_ub; i++) {
        Simul[i] = Simul[i] + backg;
      }

      loop_ub = reflect.size(0);
      for (i = 0; i < loop_ub; i++) {
        reflect[i + reflect.size(0)] = reflect[i + reflect.size(0)] + backg;
      }

      loop_ub = Simul.size(0);
      for (i = 0; i < loop_ub; i++) {
        Simul[i + Simul.size(0)] = Simul[i + Simul.size(0)] + backg;
      }
    }
    break;

   case 2:
    {
      int loop_ub;
      int i;

      //          %Subtract the background from the data..
      loop_ub = shifted_dat.size(0) - 1;
      b_shifted_dat.set_size((loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - backg;
      }

      loop_ub = b_shifted_dat.size(0);
      for (i = 0; i < loop_ub; i++) {
        shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
      }

      // shifted_dat(:,3) = shifted_dat(:,3) - backg;
    }
    break;
  }
}

//
// File trailer for applyBackgroundCorrection.cpp
//
// [EOF]
//
