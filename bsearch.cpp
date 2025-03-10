//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      int b_bsearch(const double x_data[], double xi)
      {
        int high_i;
        int low_ip1;
        int n;
        n = 1;
        low_ip1 = 2;
        high_i = 4;
        while (high_i > low_ip1) {
          int mid_i;
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

      int b_bsearch(const ::coder::array<double, 1U> &x, double xi)
      {
        int high_i;
        int low_ip1;
        int n;
        high_i = x.size(0);
        n = 1;
        low_ip1 = 2;
        while (high_i > low_ip1) {
          int mid_i;
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

      int c_bsearch(const double x[3], double xi)
      {
        int n;
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
