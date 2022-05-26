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
#include "newModelBilayer_rtwutil.h"
#include "rt_nonfinite.h"

// Function Definitions
//
//
namespace coder {
void power(const real_T a[200], real_T y[200])
{
  for (int32_T k{0}; k < 200; k++) {
    y[k] = rt_powd_snf(a[k], 2.0);
  }
}

} // namespace coder

// End of code generation (power.cpp)
