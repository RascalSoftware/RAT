//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: shiftdata.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "shiftdata.h"
#include "chiSquared.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

// Function Definitions

//
// Shifts the data according to scale factor
//  scalefac = problem.scalefactors;
//  horshift = problem.qshifts;
//  numberOfContrasts = problem.numberOfContrasts;
//  dataPresent = problem.dataPresent;
//  allData = problem.data;
//  dataLimits = problem.dataLimits;
// shifted_data = cell(1,numberOfContrasts);
// Arguments    : double scalefac
//                double horshift
//                double dataPresent
//                coder::array<double, 2U> *data
//                const double dataLimits[2]
// Return Type  : void
//
void shiftdata(double scalefac, double horshift, double dataPresent, coder::
               array<double, 2U> &data, const double dataLimits[2])
{
  coder::array<double, 1U> b_data;
  coder::array<boolean_T, 1U> x;
  int nx;
  coder::array<int, 1U> ii;
  coder::array<unsigned int, 1U> lowIndex;
  coder::array<double, 2U> c_data;
  switch (static_cast<int>(dataPresent)) {
   case 1:
    {
      int loop_ub;
      int i;
      int idx;
      int b_ii;
      boolean_T exitg1;
      int b_lowIndex;
      if (scalefac == 0.0) {
        scalefac = 1.0E-30;
      }

      loop_ub = data.size(0) - 1;
      b_data.set_size((loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        b_data[i] = data[i] + horshift;
      }

      loop_ub = b_data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data[i] = b_data[i];
      }

      loop_ub = data.size(0) - 1;
      b_data.set_size((loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        b_data[i] = data[i + data.size(0)] / scalefac;
      }

      loop_ub = b_data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data[i + data.size(0)] = b_data[i];
      }

      loop_ub = data.size(0) - 1;
      b_data.set_size((loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        b_data[i] = data[i + data.size(0) * 2] / scalefac;
      }

      loop_ub = b_data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data[i + data.size(0) * 2] = b_data[i];
      }

      loop_ub = data.size(0);
      x.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        x[i] = (data[i] < dataLimits[0]);
      }

      nx = x.size(0);
      idx = 0;
      ii.set_size(x.size(0));
      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= nx - 1)) {
        if (x[b_ii]) {
          idx++;
          ii[idx - 1] = b_ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            b_ii++;
          }
        } else {
          b_ii++;
        }
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          ii.set_size(0);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        ii.set_size(idx);
      }

      lowIndex.set_size(ii.size(0));
      loop_ub = ii.size(0);
      for (i = 0; i < loop_ub; i++) {
        lowIndex[i] = static_cast<unsigned int>(ii[i]);
      }

      if (lowIndex.size(0) != 0) {
        b_lowIndex = static_cast<int>(lowIndex[lowIndex.size(0) - 1]);
      } else {
        b_lowIndex = 1;
      }

      loop_ub = data.size(0);
      x.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        x[i] = (data[i] > dataLimits[1]);
      }

      nx = x.size(0);
      idx = 0;
      ii.set_size(x.size(0));
      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= nx - 1)) {
        if (x[b_ii]) {
          idx++;
          ii[idx - 1] = b_ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            b_ii++;
          }
        } else {
          b_ii++;
        }
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          ii.set_size(0);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        ii.set_size(idx);
      }

      lowIndex.set_size(ii.size(0));
      loop_ub = ii.size(0);
      for (i = 0; i < loop_ub; i++) {
        lowIndex[i] = static_cast<unsigned int>(ii[i]);
      }

      if (lowIndex.size(0) != 0) {
        nx = static_cast<int>(lowIndex[0]);
      } else {
        nx = data.size(0);
      }

      if (b_lowIndex > nx) {
        i = 0;
        nx = 0;
      } else {
        i = b_lowIndex - 1;
      }

      loop_ub = data.size(1) - 1;
      nx -= i;
      c_data.set_size(nx, (loop_ub + 1));
      for (idx = 0; idx <= loop_ub; idx++) {
        for (b_ii = 0; b_ii < nx; b_ii++) {
          c_data[b_ii + c_data.size(0) * idx] = data[(i + b_ii) + data.size(0) *
            idx];
        }
      }

      data.set_size(c_data.size(0), c_data.size(1));
      loop_ub = c_data.size(1);
      for (i = 0; i < loop_ub; i++) {
        nx = c_data.size(0);
        for (idx = 0; idx < nx; idx++) {
          data[idx + data.size(0) * i] = c_data[idx + c_data.size(0) * i];
        }
      }
    }
    break;
  }

  //  function Ref = makeFresnelData(problem,contrast)
  //
  //      this_data = problem.shifted_data{contrast};
  //      xdata = this_data(:,1);
  //      nbair = problem.nbairs(contrast);
  //      nbsub = problem.nbsubs(contrast);
  //      slds = [0 0 0];
  //      resol = problem.resolution;
  //      resolType = problem.resolType;
  //      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol)
  //      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,
  //      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol);
}

//
// File trailer for shiftdata.cpp
//
// [EOF]
//
