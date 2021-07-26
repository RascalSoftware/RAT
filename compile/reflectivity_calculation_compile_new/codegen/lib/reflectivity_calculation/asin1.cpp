//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// asin1.cpp
//
// Code generation for function 'asin1'
//

// Include files
#include "asin1.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void c_asin(double *x)
{
  *x = std::asin(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (asin1.cpp)
