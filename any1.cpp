//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// any1.cpp
//
// Code generation for function 'any1'
//

// Include files
#include "any1.h"
#include "allOrAny.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    boolean_T any(const ::coder::array<double, 2U> &x)
    {
      ::coder::array<double, 1U> b_x;
      int x_tmp;
      x_tmp = x.size(0) * x.size(1);
      b_x = x.reshape(x_tmp);
      return internal::b_allOrAny_anonFcn3(x_tmp, b_x);
    }
  }
}

// End of code generation (any1.cpp)
