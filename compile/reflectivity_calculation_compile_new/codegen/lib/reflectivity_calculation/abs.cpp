//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abs.cpp
//
// Code generation for function 'abs'
//

// Include files
#include "abs.h"
#include "abs1.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
int b_abs(int x)
{
  return internal::scalar::c_abs(x);
}

double b_abs(const creal_T x)
{
  return internal::scalar::c_abs(x);
}

double b_abs(double x)
{
  return internal::scalar::c_abs(x);
}

} // namespace coder

// End of code generation (abs.cpp)
