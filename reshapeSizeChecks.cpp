//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
          if (static_cast<unsigned int>(static_cast<int>(varargin_1)) == 0U) {
            b_calclen = MAX_int32_T;
          } else {
            b_calclen = static_cast<int>(1000000U / static_cast<unsigned int>(
              static_cast<int>(varargin_1)));
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
