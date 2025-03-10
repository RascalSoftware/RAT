//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// log1p.cpp
//
// Code generation for function 'log1p'
//

// Include files
#include "log1p.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        void b_log1p(double &z)
        {
          double absz;
          absz = std::abs(z);
          if ((absz > 4.503599627370496E+15) || (std::isinf(z) || std::isnan(z)))
          {
            z++;
            z = std::log(z);
          } else if (!(absz < 2.2204460492503131E-16)) {
            z = std::log(z + 1.0) * (z / ((z + 1.0) - 1.0));
          }
        }
      }
    }
  }
}

// End of code generation (log1p.cpp)
