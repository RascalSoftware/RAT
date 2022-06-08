//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log2.cpp
//
// Code generation for function 'log2'
//

// Include files
#include "log2.h"
#include "log21.h"
#include "rt_nonfinite.h"

// Function Definitions
//
//
namespace coder {
void b_log2(real_T x, real_T *f, real_T *e)
{
  internal::scalar::c_log2(x, f, e);
}

} // namespace coder

// End of code generation (log2.cpp)
