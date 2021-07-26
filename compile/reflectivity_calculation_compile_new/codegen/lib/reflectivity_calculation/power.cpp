//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// power.cpp
//
// Code generation for function 'power'
//

// Include files
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void power(const ::coder::array<double, 1U> &a, ::coder::array<double, 1U> &y)
{
  int nx;
  y.set_size(a.size(0));
  nx = a.size(0);
  for (int k{0}; k < nx; k++) {
    y[k] = a[k] * a[k];
  }
}

} // namespace coder

// End of code generation (power.cpp)
