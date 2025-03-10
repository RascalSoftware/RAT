//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      int nonSingletonDim(const ::coder::array<double, 1U> &x)
      {
        int dim;
        dim = 2;
        if (x.size(0) != 1) {
          dim = 1;
        }

        return dim;
      }

      int nonSingletonDim(const ::coder::array<double, 2U> &x)
      {
        int dim;
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
