//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// randperm.cpp
//
// Code generation for function 'randperm'
//

// Include files
#include "randperm.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void randperm(real_T n, ::coder::array<real_T, 2U> &p)
    {
      ::coder::array<int32_T, 2U> idx;
      int32_T p_idx_1;
      b_rand(n, p);
      internal::sortIdx(p, idx);
      p_idx_1 = p.size(1);
      p.set_size(1, p_idx_1);
      for (int32_T i{0}; i < p_idx_1; i++) {
        p[i] = idx[i];
      }
    }
  }
}

// End of code generation (randperm.cpp)
