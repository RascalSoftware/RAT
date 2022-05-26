//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log21.cpp
//
// Code generation for function 'log21'
//

// Include files
#include "log21.h"
#include "isfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

// Function Definitions
//
//
namespace coder {
namespace internal {
namespace scalar {
void c_log2(real_T x, real_T *f, real_T *e)
{
  int32_T eint;
  if (b_isfinite(x)) {
    *f = frexp(x, &eint);
    *e = eint;
  } else {
    *f = x;
    *e = 0.0;
  }
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (log21.cpp)
