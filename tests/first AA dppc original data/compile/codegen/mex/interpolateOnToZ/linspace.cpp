//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  linspace.cpp
//
//  Code generation for function 'linspace'
//


// Include files
#include "linspace.h"
#include "interpolateOnToZ.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

// Function Definitions
void linspace(real_T d1, real_T d2, real_T y[100])
{
  y[99] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    for (int32_T k = 0; k < 98; k++) {
      y[k + 1] = d2 * ((2.0 * (static_cast<real_T>(k) + 2.0) - 101.0) / 99.0);
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) && ((muDoubleScalarAbs(d1) >
               8.9884656743115785E+307) || (muDoubleScalarAbs(d2) >
               8.9884656743115785E+307))) {
    real_T delta1;
    real_T delta2;
    delta1 = d1 / 99.0;
    delta2 = d2 / 99.0;
    for (int32_T k = 0; k < 98; k++) {
      y[k + 1] = (d1 + delta2 * (static_cast<real_T>(k) + 1.0)) - delta1 * (
        static_cast<real_T>(k) + 1.0);
    }
  } else {
    real_T delta1;
    delta1 = (d2 - d1) / 99.0;
    for (int32_T k = 0; k < 98; k++) {
      y[k + 1] = d1 + (static_cast<real_T>(k) + 1.0) * delta1;
    }
  }
}

// End of code generation (linspace.cpp)
