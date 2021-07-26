//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sqrt.cpp
//
// Code generation for function 'sqrt'
//

// Include files
#include "sqrt.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_sqrt(::coder::array<double, 1U> &x)
{
  int nx;
  nx = x.size(0);
  for (int k{0}; k < nx; k++) {
    internal::scalar::c_sqrt(&x[k]);
  }
}

void b_sqrt(creal_T *x)
{
  internal::scalar::c_sqrt(x);
}

} // namespace coder

// End of code generation (sqrt.cpp)
