//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// vAllOrAny.cpp
//
// Code generation for function 'vAllOrAny'
//

// Include files
#include "vAllOrAny.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void genloops(const ::coder::array<double, 2U> &x, boolean_T *p, int
                    varargin_1, int varargin_2)
      {
        if (*p) {
          double b_x;
          b_x = x[(varargin_1 + x.size(0) * (varargin_2 - 1)) - 1];
          if ((!std::isinf(b_x)) && (!std::isnan(b_x))) {
            *p = true;
          } else {
            *p = false;
          }
        } else {
          *p = false;
        }
      }
    }
  }
}

// End of code generation (vAllOrAny.cpp)
