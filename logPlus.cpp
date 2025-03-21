//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// logPlus.cpp
//
// Code generation for function 'logPlus'
//

// Include files
#include "logPlus.h"
#include "log1p.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  double logPlus(double logx, double logy)
  {
    double d;
    double logz;

    //  Calculate log(x+y) given logx and logy.
    //
    //  It avoids problems of dynamic range when the
    //  exponentiated values of x or y are very large or small.
    //
    //  Parameters
    //  ----------
    //  logx, logy : float
    //      The two logarithmic values to add.
    //
    //  Returns
    //  -------
    //  logz : float
    //      The value of log(x+y).
    //
    if (std::isinf(logx) && std::isinf(logy)) {
      logz = rtMinusInf;
    } else if (logx > logy) {
      d = std::exp(logy - logx);
      coder::internal::scalar::b_log1p(d);
      logz = logx + d;
    } else {
      d = std::exp(logx - logy);
      coder::internal::scalar::b_log1p(d);
      logz = logy + d;
    }

    return logz;
  }
}

// End of code generation (logPlus.cpp)
