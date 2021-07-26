//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// shiftdata.cpp
//
// Code generation for function 'shiftdata'
//

// Include files
#include "shiftdata.h"
#include "find.h"
#include "linspace.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void shiftdata(double scalefac, double horshift, double dataPresent,
               coder::array<double, 2U> &data, const double dataLimits[2],
               const double simLimits[2],
               coder::array<double, 2U> &shifted_data)
{
  coder::array<double, 1U> b_data;
  coder::array<int, 1U> b_lowIndex;
  coder::array<boolean_T, 1U> c_data;
  double b_dv1[300];
  double b_dv[100];
  //  Shifts the data according to scale factor. If there is no data, makes
  //  x-data over the simulation range.
  //  scalefac = problem.scalefactors;
  //  horshift = problem.qshifts;
  //  numberOfContrasts = problem.numberOfContrasts;
  //  dataPresent = problem.dataPresent;
  //  allData = problem.data;
  //  dataLimits = problem.dataLimits;
  // shifted_data = cell(1,numberOfContrasts);
  switch (static_cast<int>(dataPresent)) {
  case 1: {
    int hiIndex;
    int i;
    int loop_ub;
    int lowIndex;
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }
    lowIndex = data.size(0) - 1;
    b_data.set_size(data.size(0));
    for (i = 0; i <= lowIndex; i++) {
      b_data[i] = data[i] + horshift;
    }
    loop_ub = b_data.size(0);
    for (i = 0; i < loop_ub; i++) {
      data[i] = b_data[i];
    }
    lowIndex = data.size(0) - 1;
    b_data.set_size(data.size(0));
    for (i = 0; i <= lowIndex; i++) {
      b_data[i] = data[i + data.size(0)] / scalefac;
    }
    loop_ub = b_data.size(0);
    for (i = 0; i < loop_ub; i++) {
      data[i + data.size(0)] = b_data[i];
    }
    lowIndex = data.size(0) - 1;
    b_data.set_size(data.size(0));
    for (i = 0; i <= lowIndex; i++) {
      b_data[i] = data[i + data.size(0) * 2] / scalefac;
    }
    loop_ub = b_data.size(0);
    for (i = 0; i < loop_ub; i++) {
      data[i + data.size(0) * 2] = b_data[i];
    }
    loop_ub = data.size(0);
    c_data.set_size(data.size(0));
    for (i = 0; i < loop_ub; i++) {
      c_data[i] = (data[i] < dataLimits[0]);
    }
    coder::eml_find(c_data, b_lowIndex);
    if (b_lowIndex.size(0) != 0) {
      lowIndex = b_lowIndex[b_lowIndex.size(0) - 1];
    } else {
      lowIndex = 1;
    }
    loop_ub = data.size(0);
    c_data.set_size(data.size(0));
    for (i = 0; i < loop_ub; i++) {
      c_data[i] = (data[i] > dataLimits[1]);
    }
    coder::eml_find(c_data, b_lowIndex);
    if (b_lowIndex.size(0) != 0) {
      hiIndex = b_lowIndex[0];
    } else {
      hiIndex = data.size(0);
    }
    if (lowIndex > hiIndex) {
      i = 0;
      hiIndex = 0;
    } else {
      i = lowIndex - 1;
    }
    loop_ub = data.size(1);
    lowIndex = hiIndex - i;
    shifted_data.set_size(lowIndex, data.size(1));
    for (hiIndex = 0; hiIndex < loop_ub; hiIndex++) {
      for (int i1{0}; i1 < lowIndex; i1++) {
        shifted_data[i1 + shifted_data.size(0) * hiIndex] =
            data[(i + i1) + data.size(0) * hiIndex];
      }
    }
  } break;
  default: {
    int i;
    coder::linspace(simLimits[0], simLimits[1], b_dv);
    for (i = 0; i < 100; i++) {
      b_dv1[i] = b_dv[i];
      b_dv1[i + 100] = 0.0;
      b_dv1[i + 200] = 0.0;
    }
    shifted_data.set_size(100, 3);
    for (i = 0; i < 300; i++) {
      shifted_data[i] = b_dv1[i];
    }
  } break;
  }
}

// End of code generation (shiftdata.cpp)
