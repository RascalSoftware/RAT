//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: sortLE.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "sortLE.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const coder::array<double, 2U> *v
//                const int dir_data[]
//                int idx1
//                int idx2
// Return Type  : boolean_T
//
boolean_T sortLE(const coder::array<double, 2U> &v, const int dir_data[], int
                 idx1, int idx2)
{
  boolean_T p;
  int k;
  boolean_T exitg1;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    double v1;
    double v2;
    v1 = v[(idx1 + v.size(0) * (dir_data[k] - 1)) - 1];
    v2 = v[(idx2 + v.size(0) * (dir_data[k] - 1)) - 1];
    if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2))) {
      k++;
    } else {
      if ((!(v1 <= v2)) && (!rtIsNaN(v2))) {
        p = false;
      }

      exitg1 = true;
    }
  }

  return p;
}

//
// File trailer for sortLE.cpp
//
// [EOF]
//
