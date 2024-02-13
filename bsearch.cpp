//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// bsearch.cpp
//
// Code generation for function 'bsearch'
//

// Include files
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int32_T b_bsearch(const real_T x_data[], real_T xi)
      {
        int32_T high_i;
        int32_T low_ip1;
        int32_T n;
        n = 1;
        low_ip1 = 2;
        high_i = 4;
        while (high_i > low_ip1) {
          int32_T mid_i;
          mid_i = (n >> 1) + (high_i >> 1);
          if (((n & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }

          if (xi >= x_data[mid_i - 1]) {
            n = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        return n;
      }

      int32_T b_bsearch(const ::coder::array<real_T, 1U> &x, real_T xi)
      {
        int32_T high_i;
        int32_T low_ip1;
        int32_T n;
        high_i = x.size(0);
        n = 1;
        low_ip1 = 2;
        while (high_i > low_ip1) {
          int32_T mid_i;
          mid_i = (n >> 1) + (high_i >> 1);
          if (((n & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }

          if (xi >= x[mid_i - 1]) {
            n = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        return n;
      }

      int32_T c_bsearch(const real_T x[3], real_T xi)
      {
        int32_T n;
        n = 1;
        if (xi >= x[1]) {
          n = 2;
        }

        return n;
      }
    }
  }
}

// End of code generation (bsearch.cpp)
