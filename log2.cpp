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
    void b_log2(const ::coder::array<real_T, 1U> &x, ::coder::array<real_T, 1U>
                &f, ::coder::array<real_T, 1U> &e)
    {
      f.set_size(x.size(0));
      e.set_size(x.size(0));
      if (x.size(0) != 0) {
        int32_T i;
        i = x.size(0);
        for (int32_T k{0}; k < i; k++) {
          b_log2(x[k], &f[k], &e[k]);
        }
      }
    }

    void b_log2(real_T x, real_T *f, real_T *e)
    {
      int32_T eint;
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
