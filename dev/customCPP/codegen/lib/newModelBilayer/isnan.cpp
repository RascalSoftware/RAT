//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// isnan.cpp
//
// Code generation for function 'isnan'
//

// Include files
#include "isnan.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
//
namespace coder {
boolean_T b_isnan(real_T x)
{
  return std::isnan(x);
}

} // namespace coder

// End of code generation (isnan.cpp)
