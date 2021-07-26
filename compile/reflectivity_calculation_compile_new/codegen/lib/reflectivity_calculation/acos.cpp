//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// acos.cpp
//
// Code generation for function 'acos'
//

// Include files
#include "acos.h"
#include "acos1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_acos(::coder::array<creal_T, 1U> &x)
{
  int nx;
  nx = x.size(0);
  for (int k{0}; k < nx; k++) {
    internal::scalar::c_acos(&x[k]);
  }
}

} // namespace coder

// End of code generation (acos.cpp)
