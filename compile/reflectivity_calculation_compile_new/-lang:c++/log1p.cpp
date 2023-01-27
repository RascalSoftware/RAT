//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: log1p.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "log1p.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T *z
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        void b_log1p(real_T *z)
        {
          real_T absz;
          absz = std::abs(*z);
          if ((absz > 4.503599627370496E+15) || (std::isinf(*z) || std::isnan(*z)))
          {
            (*z)++;
            *z = std::log(*z);
          } else if (!(absz < 2.2204460492503131E-16)) {
            *z = std::log(*z + 1.0) * (*z / ((*z + 1.0) - 1.0));
          }
        }
      }
    }
  }
}

//
// File trailer for log1p.cpp
//
// [EOF]
//
