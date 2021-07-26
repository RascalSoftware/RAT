//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortLE.cpp
//
// Code generation for function 'sortLE'
//

// Include files
#include "sortLE.h"
#include "rt_nonfinite.h"
#include "sortrowsLE.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
boolean_T sortLE(const ::coder::array<double, 2U> &v, const int dir_data[],
                 int idx1, int idx2)
{
  return sortrowsLE(v, dir_data, idx1, idx2);
}

} // namespace internal
} // namespace coder

// End of code generation (sortLE.cpp)
