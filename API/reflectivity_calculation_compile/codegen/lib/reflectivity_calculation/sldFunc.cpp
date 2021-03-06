//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: sldFunc.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//

// Include Files
#include "sldFunc.h"
#include "chiSquared.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include <math.h>

// Function Definitions

//
// sldVal = sldFunc(x,SLD)
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
// Arguments    : double x
//                const coder::array<double, 2U> *SLD
//                coder::array<double, 1U> *sldVal
// Return Type  : void
//
void sldFunc(double x, const coder::array<double, 2U> &SLD, coder::array<double,
             1U> &sldVal)
{
  int nx;
  coder::array<boolean_T, 1U> b_x;
  int idx;
  coder::array<int, 1U> ii;
  int b_ii;
  boolean_T exitg1;
  coder::array<unsigned int, 1U> where;
  coder::array<unsigned int, 1U> aboveVals;

  // SLD = getappdata(0,'sldFuncSLD');
  nx = SLD.size(0);
  b_x.set_size(SLD.size(0));
  for (idx = 0; idx < nx; idx++) {
    b_x[idx] = (SLD[idx] == x);
  }

  nx = b_x.size(0);
  idx = 0;
  ii.set_size(b_x.size(0));
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= nx - 1)) {
    if (b_x[b_ii]) {
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

  if (b_x.size(0) == 1) {
    if (idx == 0) {
      ii.set_size(0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    ii.set_size(idx);
  }

  where.set_size(ii.size(0));
  nx = ii.size(0);
  for (idx = 0; idx < nx; idx++) {
    where[idx] = static_cast<unsigned int>(ii[idx]);
  }

  if (where.size(0) != 0) {
    sldVal.set_size(where.size(0));
    nx = where.size(0);
    for (idx = 0; idx < nx; idx++) {
      sldVal[idx] = SLD[(static_cast<int>(where[idx]) + SLD.size(0)) - 1];
    }
  } else {
    double deltaY_tmp;
    double deltaY;
    nx = SLD.size(0);
    b_x.set_size(SLD.size(0));
    for (idx = 0; idx < nx; idx++) {
      b_x[idx] = (x > SLD[idx]);
    }

    nx = b_x.size(0);
    idx = 0;
    ii.set_size(b_x.size(0));
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (b_x[b_ii]) {
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

    if (b_x.size(0) == 1) {
      if (idx == 0) {
        ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      ii.set_size(idx);
    }

    where.set_size(ii.size(0));
    nx = ii.size(0);
    for (idx = 0; idx < nx; idx++) {
      where[idx] = static_cast<unsigned int>(ii[idx]);
    }

    nx = SLD.size(0);
    b_x.set_size(SLD.size(0));
    for (idx = 0; idx < nx; idx++) {
      b_x[idx] = (x < SLD[idx]);
    }

    nx = b_x.size(0);
    idx = 0;
    ii.set_size(b_x.size(0));
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (b_x[b_ii]) {
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

    if (b_x.size(0) == 1) {
      if (idx == 0) {
        ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      ii.set_size(idx);
    }

    aboveVals.set_size(ii.size(0));
    nx = ii.size(0);
    for (idx = 0; idx < nx; idx++) {
      aboveVals[idx] = static_cast<unsigned int>(ii[idx]);
    }

    nx = static_cast<int>(aboveVals[0]) - 1;
    deltaY_tmp = SLD[nx + SLD.size(0)];
    deltaY = (x - SLD[static_cast<int>(where[where.size(0) - 1]) - 1]) * (fabs
      (deltaY_tmp - SLD[(static_cast<int>(where[where.size(0) - 1]) + SLD.size(0))
       - 1]) / (SLD[nx] - SLD[static_cast<int>(where[where.size(0) - 1]) - 1]));
    if (SLD[(static_cast<int>(where[where.size(0) - 1]) + SLD.size(0)) - 1] <
        deltaY_tmp) {
      sldVal.set_size(1);
      sldVal[0] = SLD[(static_cast<int>(where[where.size(0) - 1]) + SLD.size(0))
        - 1] + deltaY;
    } else {
      sldVal.set_size(1);
      sldVal[0] = SLD[(static_cast<int>(where[where.size(0) - 1]) + SLD.size(0))
        - 1] - deltaY;
    }

    // sldVal = interp1(z,rho,x);
  }
}

//
// File trailer for sldFunc.cpp
//
// [EOF]
//
