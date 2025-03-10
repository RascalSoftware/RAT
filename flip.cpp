//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// flip.cpp
//
// Code generation for function 'flip'
//

// Include files
#include "flip.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void flip(::coder::array<double, 1U> &x)
    {
      if (x.size(0) > 1) {
        int lup;
        lup = x.size(0) >> 1;
        for (int k{0}; k < lup; k++) {
          double tmp;
          int i;
          i = x.size(0) - k;
          tmp = x[k];
          x[k] = x[i - 1];
          x[i - 1] = tmp;
        }
      }
    }
  }
}

// End of code generation (flip.cpp)
