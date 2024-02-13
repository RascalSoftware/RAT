//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// length.cpp
//
// Code generation for function 'length'
//

// Include files
#include "length.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int32_T intlength(int32_T varargin_1, int32_T varargin_2)
      {
        int32_T n;
        if ((varargin_1 == 0) || (varargin_2 == 0)) {
          n = 0;
        } else if (varargin_1 > varargin_2) {
          n = varargin_1;
        } else {
          n = varargin_2;
        }

        return n;
      }
    }
  }
}

// End of code generation (length.cpp)
