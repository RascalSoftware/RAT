//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sldFunc.cpp
//
// Code generation for function 'sldFunc'
//

// Include files
#include "sldFunc.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>

// Function Definitions
void sldFunc(double x, const coder::array<double, 2U> &SLD,
             coder::array<double, 1U> &sldVal)
{
  coder::array<int, 1U> aboveVals;
  coder::array<int, 1U> where;
  coder::array<boolean_T, 1U> b_SLD;
  int i;
  int loop_ub;
  //  sldVal = sldFunc(x,SLD)
  //  SLD = [x rho;....xn rho]
  //    x = value in Angstrom.
  //
  //  This function returns the SLD (y) value associated with the
  //  supplied value of x. SLD is a two column, XY array defining an
  //  SLD profile. This function interpolates the SLD profile
  //  to return the SLD at the specific value of X. X can be a vector of
  //  multiple points.
  //
  //  (c) Arwel Hughes 2019.
  //  Last modified - AVH, 26/11/19.
  //  global sldProfile
  //
  //  SLD = sldProfile;
  // SLD = getappdata(0,'sldFuncSLD');
  loop_ub = SLD.size(0);
  b_SLD.set_size(SLD.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_SLD[i] = (SLD[i] == x);
  }
  coder::eml_find(b_SLD, aboveVals);
  where.set_size(aboveVals.size(0));
  loop_ub = aboveVals.size(0);
  for (i = 0; i < loop_ub; i++) {
    where[i] = aboveVals[i];
  }
  if (where.size(0) != 0) {
    sldVal.set_size(where.size(0));
    loop_ub = where.size(0);
    for (i = 0; i < loop_ub; i++) {
      sldVal[i] = SLD[(where[i] + SLD.size(0)) - 1];
    }
  } else {
    double deltaY;
    double deltaY_tmp;
    loop_ub = SLD.size(0);
    b_SLD.set_size(SLD.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_SLD[i] = (x > SLD[i]);
    }
    coder::eml_find(b_SLD, aboveVals);
    where.set_size(aboveVals.size(0));
    loop_ub = aboveVals.size(0);
    for (i = 0; i < loop_ub; i++) {
      where[i] = aboveVals[i];
    }
    loop_ub = SLD.size(0);
    b_SLD.set_size(SLD.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_SLD[i] = (x < SLD[i]);
    }
    coder::eml_find(b_SLD, aboveVals);
    deltaY_tmp = SLD[(aboveVals[0] + SLD.size(0)) - 1];
    deltaY = (x - SLD[where[where.size(0) - 1] - 1]) *
             (std::abs(deltaY_tmp -
                       SLD[(where[where.size(0) - 1] + SLD.size(0)) - 1]) /
              (SLD[aboveVals[0] - 1] - SLD[where[where.size(0) - 1] - 1]));
    if (SLD[(where[where.size(0) - 1] + SLD.size(0)) - 1] < deltaY_tmp) {
      sldVal.set_size(1);
      sldVal[0] = SLD[(where[where.size(0) - 1] + SLD.size(0)) - 1] + deltaY;
    } else {
      sldVal.set_size(1);
      sldVal[0] = SLD[(where[where.size(0) - 1] + SLD.size(0)) - 1] - deltaY;
    }
    // sldVal = interp1(z,rho,x);
  }
}

void sldFunc(double x, double sldVal_data[], int *sldVal_size)
{
  static const double rho[3]{1.0E-6, 2.0E-6, 1.0E-6};
  static const signed char b_z[3]{10, 50, 100};
  int aboveVals_data[3];
  int where_data[3];
  boolean_T z[3];
  //  sldVal = sldFunc(x,SLD)
  //  SLD = [x rho;....xn rho]
  //    x = value in Angstrom.
  //
  //  This function returns the SLD (y) value associated with the
  //  supplied value of x. SLD is a two column, XY array defining an
  //  SLD profile. This function interpolates the SLD profile
  //  to return the SLD at the specific value of X. X can be a vector of
  //  multiple points.
  //
  //  (c) Arwel Hughes 2019.
  //  Last modified - AVH, 26/11/19.
  //  global sldProfile
  //
  //  SLD = sldProfile;
  // SLD = getappdata(0,'sldFuncSLD');
  z[0] = (10.0 == x);
  z[1] = (50.0 == x);
  z[2] = (100.0 == x);
  coder::b_eml_find(z, aboveVals_data, sldVal_size);
  if (0 <= *sldVal_size - 1) {
    std::copy(&aboveVals_data[0], &aboveVals_data[*sldVal_size],
              &where_data[0]);
  }
  if (*sldVal_size != 0) {
    for (int where_size{0}; where_size < *sldVal_size; where_size++) {
      sldVal_data[where_size] = rho[where_data[where_size] - 1];
    }
  } else {
    double b_deltaY_tmp;
    double deltaY;
    double deltaY_tmp;
    int where_size;
    z[0] = (x > 10.0);
    z[1] = (x > 50.0);
    z[2] = (x > 100.0);
    coder::b_eml_find(z, aboveVals_data, sldVal_size);
    where_size = *sldVal_size;
    if (0 <= *sldVal_size - 1) {
      std::copy(&aboveVals_data[0], &aboveVals_data[*sldVal_size],
                &where_data[0]);
    }
    z[0] = (x < 10.0);
    z[1] = (x < 50.0);
    z[2] = (x < 100.0);
    coder::b_eml_find(z, aboveVals_data, sldVal_size);
    deltaY_tmp = rho[aboveVals_data[0] - 1];
    where_size = where_data[where_size - 1] - 1;
    b_deltaY_tmp = rho[where_size];
    deltaY =
        (x - static_cast<double>(b_z[where_size])) *
        (std::abs(deltaY_tmp - b_deltaY_tmp) /
         static_cast<double>(b_z[aboveVals_data[0] - 1] - b_z[where_size]));
    if (b_deltaY_tmp < deltaY_tmp) {
      *sldVal_size = 1;
      sldVal_data[0] = b_deltaY_tmp + deltaY;
    } else {
      *sldVal_size = 1;
      sldVal_data[0] = b_deltaY_tmp - deltaY;
    }
    // sldVal = interp1(z,rho,x);
  }
}

// End of code generation (sldFunc.cpp)
