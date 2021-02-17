//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: linspace.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "linspace.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include <math.h>

// Function Definitions

//
// Arguments    : double d1
//                double d2
//                double y[50]
// Return Type  : void
//
void linspace(double d1, double d2, double y[50])
{
  y[49] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    for (int k = 0; k < 48; k++) {
      y[k + 1] = d2 * ((2.0 * (static_cast<double>(k) + 2.0) - 51.0) / 49.0);
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307)
              || (fabs(d2) > 8.9884656743115785E+307))) {
    double delta1;
    double delta2;
    delta1 = d1 / 49.0;
    delta2 = d2 / 49.0;
    for (int k = 0; k < 48; k++) {
      y[k + 1] = (d1 + delta2 * (static_cast<double>(k) + 1.0)) - delta1 * (
        static_cast<double>(k) + 1.0);
    }
  } else {
    double delta1;
    delta1 = (d2 - d1) / 49.0;
    for (int k = 0; k < 48; k++) {
      y[k + 1] = d1 + (static_cast<double>(k) + 1.0) * delta1;
    }
  }
}

//
// File trailer for linspace.cpp
//
// [EOF]
//
