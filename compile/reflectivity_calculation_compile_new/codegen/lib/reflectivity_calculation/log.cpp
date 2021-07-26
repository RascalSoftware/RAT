//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log.cpp
//
// Code generation for function 'log'
//

// Include files
#include "log.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void b_log(double *x)
{
  *x = std::log(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (log.cpp)
