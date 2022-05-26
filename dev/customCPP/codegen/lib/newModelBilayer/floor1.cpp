//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// floor1.cpp
//
// Code generation for function 'floor1'
//

// Include files
#include "floor1.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
//
namespace coder {
namespace internal {
namespace scalar {
void c_floor(real_T *x)
{
  *x = std::floor(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (floor1.cpp)
