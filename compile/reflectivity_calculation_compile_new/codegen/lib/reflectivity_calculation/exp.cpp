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
namespace coder {
void b_exp(creal_T *x)
{
  internal::scalar::c_exp(x);
}

void b_exp(double *x)
{
  internal::scalar::c_exp(x);
}

} // namespace coder

// End of code generation (exp.cpp)
