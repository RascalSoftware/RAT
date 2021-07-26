//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sin1.cpp
//
// Code generation for function 'sin1'
//

// Include files
#include "sin1.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void c_sin(double *x)
{
  *x = std::sin(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (sin1.cpp)
