//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// cos1.cpp
//
// Code generation for function 'cos1'
//

// Include files
#include "cos1.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void c_cos(double *x)
{
  *x = std::cos(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (cos1.cpp)
