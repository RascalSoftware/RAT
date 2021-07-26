//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log1p.cpp
//
// Code generation for function 'log1p'
//

// Include files
#include "log1p.h"
#include "abs1.h"
#include "isfinite.h"
#include "log.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void b_log1p(double *z)
{
  double absz;
  absz = c_abs(*z);
  if ((absz > 4.503599627370496E+15) || (!b_isfinite(*z))) {
    (*z)++;
    b_log(z);
  } else if (!(absz < 2.2204460492503131E-16)) {
    absz = *z + 1.0;
    b_log(&absz);
    *z = absz * (*z / ((*z + 1.0) - 1.0));
  }
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (log1p.cpp)
