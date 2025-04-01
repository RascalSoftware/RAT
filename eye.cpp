//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eye.cpp
//
// Code generation for function 'eye'
//

// Include files
#include "eye.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eye(creal_T b_I[2][2])
    {
      b_I[0][1].re = 0.0;
      b_I[0][1].im = 0.0;
      b_I[1][0].re = 0.0;
      b_I[1][0].im = 0.0;
      b_I[0][0].re = 1.0;
      b_I[0][0].im = 0.0;
      b_I[1][1].re = 1.0;
      b_I[1][1].im = 0.0;
    }
  }
}

// End of code generation (eye.cpp)
