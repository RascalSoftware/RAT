//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log2.cpp
//
// Code generation for function 'log2'
//

// Include files
#include "log2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_log2(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U>
                &f, ::coder::array<double, 1U> &e)
    {
      f.set_size(x.size(0));
      e.set_size(x.size(0));
      if (x.size(0) != 0) {
        int i;
        i = x.size(0);
        for (int k{0}; k < i; k++) {
          b_log2(x[k], &f[k], &e[k]);
        }
      }
    }

    void b_log2(double x, double *f, double *e)
    {
      int eint;
      if ((!std::isinf(x)) && (!std::isnan(x))) {
        *f = frexp(x, &eint);
        *e = eint;
      } else {
        *f = x;
        *e = 0.0;
      }
    }
  }
}

// End of code generation (log2.cpp)
