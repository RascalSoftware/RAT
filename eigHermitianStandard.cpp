//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eigHermitianStandard.cpp
//
// Code generation for function 'eigHermitianStandard'
//

// Include files
#include "eigHermitianStandard.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void diagDiagUpperHessNoImag(::coder::array<real_T, 2U> &D)
    {
      int32_T n;
      n = D.size(0);
      for (int32_T j{2}; j <= n; j++) {
        D[(j + D.size(0) * (j - 2)) - 1] = 0.0;
        for (int32_T i{0}; i <= j - 2; i++) {
          D[i + D.size(0) * (j - 1)] = 0.0;
        }
      }
    }
  }
}

// End of code generation (eigHermitianStandard.cpp)
