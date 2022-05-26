//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sqrt1.cpp
//
// Code generation for function 'sqrt1'
//

// Include files
#include "sqrt1.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
//
namespace coder {
namespace internal {
namespace scalar {
void c_sqrt(real_T *x)
{
  *x = std::sqrt(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (sqrt1.cpp)
