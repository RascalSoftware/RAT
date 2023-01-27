//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: rt_nonfinite.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Abstract:
//      MATLAB for code generation function to initialize non-finites,
//      (Inf, NaN and -Inf).
// Include Files
#include "rt_nonfinite.h"
#include <cmath>
#include <limits>

real_T rtNaN { std::numeric_limits<real_T>::quiet_NaN() };

real_T rtInf { std::numeric_limits<real_T>::infinity() };

real_T rtMinusInf { -std::numeric_limits<real_T>::infinity() };

real32_T rtNaNF { std::numeric_limits<real32_T>::quiet_NaN() };

real32_T rtInfF { std::numeric_limits<real32_T>::infinity() };

real32_T rtMinusInfF { -std::numeric_limits<real32_T>::infinity() };

//
// File trailer for rt_nonfinite.cpp
//
// [EOF]
//
