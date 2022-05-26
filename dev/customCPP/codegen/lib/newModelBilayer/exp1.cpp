//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// exp1.cpp
//
// Code generation for function 'exp1'
//

// Include files
#include "exp1.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
//
namespace coder {
namespace internal {
namespace scalar {
void d_exp(real_T *x)
{
  *x = std::exp(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (exp1.cpp)
