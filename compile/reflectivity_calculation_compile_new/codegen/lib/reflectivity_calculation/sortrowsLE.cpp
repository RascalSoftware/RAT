//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortrowsLE.cpp
//
// Code generation for function 'sortrowsLE'
//

// Include files
#include "sortrowsLE.h"
#include "abs.h"
#include "isnan.h"
#include "rt_nonfinite.h"
#include "sortAscendLE.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
boolean_T sortrowsLE(const ::coder::array<double, 2U> &v, const int col_data[],
                     int irow1, int irow2)
{
  int k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    double v1;
    double v2;
    int abscolk;
    abscolk = b_abs(col_data[k]) - 1;
    v1 = v[(irow1 + v.size(0) * abscolk) - 1];
    v2 = v[(irow2 + v.size(0) * abscolk) - 1];
    if ((v1 == v2) || (b_isnan(v1) && b_isnan(v2))) {
      k++;
    } else {
      p = sortAscendLE(v1, v2);
      exitg1 = true;
    }
  }
  return p;
}

} // namespace internal
} // namespace coder

// End of code generation (sortrowsLE.cpp)
