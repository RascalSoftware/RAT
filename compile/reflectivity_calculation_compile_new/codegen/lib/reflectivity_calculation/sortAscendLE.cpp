//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortAscendLE.cpp
//
// Code generation for function 'sortAscendLE'
//

// Include files
#include "sortAscendLE.h"
#include "relop.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
boolean_T sortAscendLE(double a, double b)
{
  return c_relop(a, b);
}

} // namespace internal
} // namespace coder

// End of code generation (sortAscendLE.cpp)
