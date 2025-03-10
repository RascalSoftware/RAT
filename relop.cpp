//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// relop.cpp
//
// Code generation for function 'relop'
//

// Include files
#include "relop.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T b_relop(double a, double b)
      {
        boolean_T p;
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(a)) {
          p = true;
        } else {
          p = (a > b);
        }

        return p;
      }

      boolean_T c_relop(double a, double b)
      {
        boolean_T p;
        if (std::isnan(b)) {
          p = !std::isnan(a);
        } else if (std::isnan(a)) {
          p = false;
        } else {
          p = (a < b);
        }

        return p;
      }

      boolean_T relop(double a, double b)
      {
        boolean_T p;
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(a)) {
          p = true;
        } else {
          p = (a < b);
        }

        return p;
      }
    }
  }
}

// End of code generation (relop.cpp)
