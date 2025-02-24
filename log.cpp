//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log.cpp
//
// Code generation for function 'log'
//

// Include files
#include "log.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_log(creal_T *x)
    {
      if (x->im == 0.0) {
        if (x->re < 0.0) {
          x->re = std::log(std::abs(x->re));
          x->im = 3.1415926535897931;
        } else {
          x->re = std::log(std::abs(x->re));
          x->im = 0.0;
        }
      } else if ((std::abs(x->re) > 8.9884656743115785E+307) || (std::abs(x->im)
                  > 8.9884656743115785E+307)) {
        double d;
        double d1;
        d = x->im;
        d1 = x->re;
        x->re = std::log(rt_hypotd_snf(x->re / 2.0, x->im / 2.0)) +
          0.69314718055994529;
        x->im = rt_atan2d_snf(d, d1);
      } else {
        double d;
        double d1;
        d = x->im;
        d1 = x->re;
        x->re = std::log(rt_hypotd_snf(x->re, x->im));
        x->im = rt_atan2d_snf(d, d1);
      }
    }
  }
}

// End of code generation (log.cpp)
