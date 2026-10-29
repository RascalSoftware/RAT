//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// bsxfun.cpp
//
// Code generation for function 'bsxfun'
//

// Include files
#include "bsxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void bsxfun(const ::coder::array<double, 2U> &a, const double b[2], ::coder::
                array<double, 2U> &c)
    {
      c.set_size(a.size(0), 2);
      if (a.size(0) != 0) {
        int acoef;
        acoef = (a.size(0) != 1);
        for (int k{0}; k < 2; k++) {
          int i;
          i = c.size(0) - 1;
          for (int b_k{0}; b_k <= i; b_k++) {
            c[b_k + c.size(0) * k] = a[acoef * b_k + a.size(0) * k] / b[k];
          }
        }
      }
    }
  }
}

// End of code generation (bsxfun.cpp)
