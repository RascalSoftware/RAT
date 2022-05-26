//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// erf.cpp
//
// Code generation for function 'erf'
//

// Include files
#include "erf.h"
#include "eml_erfcore.h"
#include "rt_nonfinite.h"

// Function Definitions
//
//
namespace coder {
void b_erf(const real_T x[200], real_T y[200])
{
  eml_erfcore(x, y);
}

} // namespace coder

// End of code generation (erf.cpp)
