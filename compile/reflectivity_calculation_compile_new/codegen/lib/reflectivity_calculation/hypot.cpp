//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// hypot.cpp
//
// Code generation for function 'hypot'
//

// Include files
#include "hypot.h"
#include "rt_nonfinite.h"
#include "xdlapy2.h"

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
double b_hypot(double x, double y)
{
  return xdlapy2(x, y);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (hypot.cpp)
