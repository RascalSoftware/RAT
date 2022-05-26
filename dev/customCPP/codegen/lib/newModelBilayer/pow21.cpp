//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// pow21.cpp
//
// Code generation for function 'pow21'
//

// Include files
#include "pow21.h"
#include "newModelBilayer_rtwutil.h"
#include "rt_nonfinite.h"

// Function Definitions
//
//
namespace coder {
namespace internal {
namespace scalar {
real_T b_pow2(real_T a)
{
  return rt_powd_snf(2.0, a);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (pow21.cpp)
