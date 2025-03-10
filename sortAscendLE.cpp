//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sortAscendLE.cpp
//
// Code generation for function 'sortAscendLE'
//

// Include files
#include "sortAscendLE.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T sortAscendLE(double a, double b)
      {
        boolean_T p;
        if ((a <= b) || std::isnan(b)) {
          p = true;
        } else {
          p = false;
        }

        return p;
      }
    }
  }
}

// End of code generation (sortAscendLE.cpp)
