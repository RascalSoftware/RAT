//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// lower.cpp
//
// Code generation for function 'lower'
//

// Include files
#include "lower.h"
#include "eml_string_transform.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void lower(const ::coder::array<char, 2U> &x, ::coder::array<char, 2U> &y)
{
  eml_string_transform(x, y);
}

char lower(char x)
{
  return eml_string_transform(x);
}

} // namespace coder

// End of code generation (lower.cpp)
