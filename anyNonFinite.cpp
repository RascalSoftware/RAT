//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// anyNonFinite.cpp
//
// Code generation for function 'anyNonFinite'
//

// Include files
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T anyNonFinite(const ::coder::array<real_T, 2U> &x)
      {
        int32_T i;
        boolean_T p;
        p = true;
        i = x.size(1);
        for (int32_T k{0}; k < i; k++) {
          int32_T i1;
          i1 = x.size(0);
          for (int32_T b_k{0}; b_k < i1; b_k++) {
            b_genloops(x, &p, b_k + 1, k + 1);
          }
        }

        return !p;
      }
    }
  }
}

// End of code generation (anyNonFinite.cpp)
