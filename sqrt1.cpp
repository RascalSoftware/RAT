//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sqrt1.cpp
//
// Code generation for function 'sqrt1'
//

// Include files
#include "sqrt1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_sqrt(::coder::array<double, 2U> &x)
    {
      int i;
      i = x.size(1);
      for (int k{0}; k < i; k++) {
        int i1;
        i1 = x.size(0);
        for (int b_k{0}; b_k < i1; b_k++) {
          x[b_k + x.size(0) * k] = std::sqrt(x[b_k + x.size(0) * k]);
        }
      }
    }

    void c_sqrt(::coder::array<double, 2U> &x)
    {
      int i;
      i = x.size(1);
      for (int k{0}; k < i; k++) {
        x[k] = std::sqrt(x[k]);
      }
    }
  }
}

// End of code generation (sqrt1.cpp)
