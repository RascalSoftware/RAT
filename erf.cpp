//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// erf.cpp
//
// Code generation for function 'erf'
//

// Include files
#include "erf.h"
#include "eml_erfcore.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_erf(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
               &y)
    {
      y.set_size(1, x.size(1));
      if (x.size(1) != 0) {
        int i;
        i = x.size(1);
        for (int k{0}; k < i; k++) {
          y[k] = scalar_erf(x[k]);
        }
      }
    }
  }
}

// End of code generation (erf.cpp)
