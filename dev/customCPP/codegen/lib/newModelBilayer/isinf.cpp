//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// isinf.cpp
//
// Code generation for function 'isinf'
//

// Include files
#include "isinf.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
//
namespace coder {
boolean_T b_isinf(real_T x)
{
  return std::isinf(x);
}

} // namespace coder

// End of code generation (isinf.cpp)
