//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// logPlus.cpp
//
// Code generation for function 'logPlus'
//

// Include files
#include "logPlus.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  real_T logPlus(real_T logx, real_T logy)
  {
    real_T logz;

    //
    //  logz = logPlus(logx, logy)
    //
    //  Given logx and logy, this function returns logz=log(x+y).
    //  It avoids problems of dynamic range when the
    //  exponentiated values of x or y are very large or small.
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if (std::isinf(logx) && std::isinf(logy)) {
      logz = rtMinusInf;
    } else if (logx > logy) {
      logz = logx + std::log(std::exp(logy - logx) + 1.0);
    } else {
      logz = logy + std::log(std::exp(logx - logy) + 1.0);
    }

    return logz;
  }
}

// End of code generation (logPlus.cpp)
