//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// exp.cpp
//
// Code generation for function 'exp'
//

// Include files
#include "exp.h"
#include "exp1.h"
#include "rt_nonfinite.h"

// Function Definitions
//
//
namespace coder {
void b_exp(real_T *x)
{
  internal::scalar::d_exp(x);
}

//
//
void c_exp(real_T x[200])
{
  for (int32_T k{0}; k < 200; k++) {
    internal::scalar::d_exp(&x[k]);
  }
}

} // namespace coder

// End of code generation (exp.cpp)
