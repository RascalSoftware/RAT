//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reshapeSizeChecks.cpp
//
// Code generation for function 'reshapeSizeChecks'
//

// Include files
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int computeDimsData(double varargin_1)
      {
        int b_calclen;
        if (static_cast<int>(varargin_1) > 0) {
          if (static_cast<int>(varargin_1) == 0) {
            b_calclen = MAX_int32_T;
          } else {
            b_calclen = 1000000 / static_cast<int>(varargin_1);
          }
        } else {
          b_calclen = 0;
        }

        return b_calclen;
      }
    }
  }
}

// End of code generation (reshapeSizeChecks.cpp)
