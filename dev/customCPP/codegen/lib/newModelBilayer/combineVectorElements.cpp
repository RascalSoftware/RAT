//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// combineVectorElements.cpp
//
// Code generation for function 'combineVectorElements'
//

// Include files
#include "combineVectorElements.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
//
namespace coder {
void combineVectorElements(const ::coder::array<real_T, 2U> &x, real_T y[200])
{
  blockedSummation(x, x.size(1), y);
}

} // namespace coder

// End of code generation (combineVectorElements.cpp)
