//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sortLE.cpp
//
//  Code generation for function 'sortLE'
//


// Include files
#include "sortLE.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions
boolean_T sortLE(const coder::array<real_T, 2U> &v, const int32_T dir_data[],
                 int32_T idx1, int32_T idx2)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    real_T v1;
    real_T v2;
    v1 = v[(idx1 + v.size(0) * (dir_data[k] - 1)) - 1];
    v2 = v[(idx2 + v.size(0) * (dir_data[k] - 1)) - 1];
    if ((v1 == v2) || (muDoubleScalarIsNaN(v1) && muDoubleScalarIsNaN(v2))) {
      k++;
    } else {
      if ((!(v1 <= v2)) && (!muDoubleScalarIsNaN(v2))) {
        p = false;
      }

      exitg1 = true;
    }
  }

  return p;
}

// End of code generation (sortLE.cpp)
