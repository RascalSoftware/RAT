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
    void diagDiagUpperHessNoImag(::coder::array<double, 2U> &D)
    {
      int n;
      n = D.size(0);
      for (int j{2}; j <= n; j++) {
        D[(j + D.size(0) * (j - 2)) - 1] = 0.0;
        for (int i{0}; i <= j - 2; i++) {
          D[i + D.size(0) * (j - 1)] = 0.0;
        }
      }
    }
  }
}

// End of code generation (eigHermitianStandard.cpp)
