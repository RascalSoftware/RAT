//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: shiftdata.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "shiftdata.h"
#include "find.h"
#include "linspace.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>

// Function Definitions
//
// Shifts the data according to scale factor. If there is no data, makes
//  x-data over the simulation range.
//
//  INPUTS:
//
//      * scalefac = problem.scalefactors;
//      * horshift = problem.qshifts;
//      * numberOfContrasts = problem.numberOfContrasts;
//      * dataPresent = problem.dataPresent;
//      * allData = problem.data;
//      * dataLimits = problem.dataLimits;
//
// Arguments    : real_T scalefac
//                real_T horshift
//                real_T dataPresent
//                real_T data_data[]
//                const int32_T data_size[2]
//                const real_T dataLimits[2]
//                const real_T simLimits_data[]
//                real_T shifted_data_data[]
//                int32_T shifted_data_size[2]
// Return Type  : void
//
namespace RAT
{
  void shiftdata(real_T scalefac, real_T horshift, real_T dataPresent, real_T
                 data_data[], const int32_T data_size[2], const real_T
                 dataLimits[2], const real_T simLimits_data[], real_T
                 shifted_data_data[], int32_T shifted_data_size[2])
  {
    ::coder::array<int32_T, 1U> b_i;
    ::coder::array<boolean_T, 1U> d_data_data;
    ::coder::array<boolean_T, 1U> e_data_data;
    real_T b_data_data[1000];
    boolean_T c_data_data[1000];
    if (static_cast<int32_T>(dataPresent) == 1) {
      int32_T b_data_size;
      int32_T hiIndex;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      int32_T lowIndex;
      if (scalefac == 0.0) {
        scalefac = 1.0E-30;
      }

      b_data_size = data_size[0];
      loop_ub = data_size[0];
      for (i = 0; i < loop_ub; i++) {
        b_data_data[i] = data_data[i] + horshift;
      }

      if (b_data_size - 1 >= 0) {
        std::copy(&b_data_data[0], &b_data_data[b_data_size], &data_data[0]);
      }

      b_data_size = data_size[0];
      loop_ub = data_size[0];
      for (i = 0; i < loop_ub; i++) {
        b_data_data[i] = data_data[i + data_size[0]] / scalefac;
      }

      for (i = 0; i < b_data_size; i++) {
        data_data[i + data_size[0]] = b_data_data[i];
      }

      b_data_size = data_size[0];
      loop_ub = data_size[0];
      for (i = 0; i < loop_ub; i++) {
        b_data_data[i] = data_data[i + data_size[0] * 2] / scalefac;
      }

      for (i = 0; i < b_data_size; i++) {
        data_data[i + data_size[0] * 2] = b_data_data[i];
      }

      loop_ub = data_size[0];
      for (i = 0; i < loop_ub; i++) {
        c_data_data[i] = (data_data[i] < dataLimits[0]);
      }

      d_data_data.set(&c_data_data[0], data_size[0]);
      coder::eml_find(d_data_data, b_i);
      if (b_i.size(0) != 0) {
        lowIndex = b_i[b_i.size(0) - 1];
      } else {
        lowIndex = 1;
      }

      loop_ub = data_size[0];
      for (i = 0; i < loop_ub; i++) {
        c_data_data[i] = (data_data[i] > dataLimits[1]);
      }

      e_data_data.set(&c_data_data[0], data_size[0]);
      coder::eml_find(e_data_data, b_i);
      if (b_i.size(0) != 0) {
        hiIndex = b_i[0];
      } else {
        hiIndex = data_size[0];
      }

      if (lowIndex > hiIndex) {
        i = 0;
        i1 = 0;
      } else {
        i = lowIndex - 1;
        i1 = hiIndex;
      }

      loop_ub = i1 - i;
      shifted_data_size[0] = loop_ub;
      shifted_data_size[1] = data_size[1];
      b_data_size = data_size[1];
      for (i1 = 0; i1 < b_data_size; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          shifted_data_data[i2 + loop_ub * i1] = data_data[(i + i2) + data_size
            [0] * i1];
        }
      }
    } else {
      real_T dv1[3][100];
      real_T dv[100];
      coder::linspace(simLimits_data[0], simLimits_data[1], dv);
      for (int32_T i{0}; i < 100; i++) {
        dv1[0][i] = dv[i];
        dv1[1][i] = 0.0;
        dv1[2][i] = 0.0;
      }

      shifted_data_size[0] = 100;
      shifted_data_size[1] = 3;
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < 100; i1++) {
          shifted_data_data[i1 + 100 * i] = dv1[i][i1];
        }
      }
    }
  }
}

//
// File trailer for shiftdata.cpp
//
// [EOF]
//
