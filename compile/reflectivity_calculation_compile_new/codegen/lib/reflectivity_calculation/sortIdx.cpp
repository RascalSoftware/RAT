//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortIdx.cpp
//
// Code generation for function 'sortIdx'
//

// Include files
#include "sortIdx.h"
#include "mergesort.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
void sortIdx(const ::coder::array<double, 2U> &x, const int col_data[],
             ::coder::array<int, 1U> &idx)
{
  int loop_ub;
  int n;
  n = x.size(0);
  idx.set_size(x.size(0));
  loop_ub = x.size(0);
  for (int i{0}; i < loop_ub; i++) {
    idx[i] = 0;
  }
  if (x.size(0) == 0) {
    for (loop_ub = 0; loop_ub < n; loop_ub++) {
      idx[loop_ub] = loop_ub + 1;
    }
  } else {
    b_mergesort(idx, x, col_data, x.size(0));
  }
}

} // namespace internal
} // namespace coder

// End of code generation (sortIdx.cpp)
