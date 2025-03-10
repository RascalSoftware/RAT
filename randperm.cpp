//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    void randperm(double n, ::coder::array<double, 2U> &p)
    {
      ::coder::array<int, 2U> idx;
      int p_idx_1;
      b_rand(n, p);
      internal::sortIdx(p, idx);
      p_idx_1 = p.size(1);
      p.set_size(1, p_idx_1);
      for (int i{0}; i < p_idx_1; i++) {
        p[i] = idx[i];
      }
    }
  }
}

// End of code generation (randperm.cpp)
