//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nonSingletonDim.cpp
//
// Code generation for function 'nonSingletonDim'
//

// Include files
#include "nonSingletonDim.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int32_T nonSingletonDim(const ::coder::array<real_T, 1U> &x)
      {
        int32_T dim;
        dim = 2;
        if (x.size(0) != 1) {
          dim = 1;
        }

        return dim;
      }

      int32_T nonSingletonDim(const ::coder::array<real_T, 2U> &x)
      {
        int32_T dim;
        dim = 2;
        if (x.size(0) != 1) {
          dim = 1;
        }

        return dim;
      }
    }
  }
}

// End of code generation (nonSingletonDim.cpp)
