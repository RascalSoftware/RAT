//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// isrow.cpp
//
// Code generation for function 'isrow'
//

// Include files
#include "isrow.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    boolean_T isrow(const ::coder::array<double, 2U> &x)
    {
      return x.size(0) == 1;
    }
  }
}

// End of code generation (isrow.cpp)
