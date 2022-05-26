//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// isfinite.cpp
//
// Code generation for function 'isfinite'
//

// Include files
#include "isfinite.h"
#include "isinf.h"
#include "isnan.h"
#include "rt_nonfinite.h"

// Function Definitions
//
//
namespace coder {
boolean_T b_isfinite(real_T x)
{
  return (!b_isinf(x)) && (!b_isnan(x));
}

} // namespace coder

// End of code generation (isfinite.cpp)
