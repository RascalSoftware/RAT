//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// length.cpp
//
// Code generation for function 'length'
//

// Include files
#include "length.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
int intlength(int varargin_1)
{
  int n;
  if (varargin_1 > 1) {
    n = varargin_1;
  } else {
    n = 1;
  }
  if (varargin_1 == 0) {
    n = 0;
  }
  return n;
}

double varargin_numel(int varargin_2)
{
  return varargin_2;
}

} // namespace internal
} // namespace coder

// End of code generation (length.cpp)
