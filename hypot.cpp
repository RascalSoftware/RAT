//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// hypot.cpp
//
// Code generation for function 'hypot'
//

// Include files
#include "hypot.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_hypot(const ::coder::array<double, 1U> &x, const ::coder::array<
                 double, 1U> &y, ::coder::array<double, 1U> &r)
    {
      int csz_idx_0;
      int k;
      k = x.size(0);
      csz_idx_0 = y.size(0);
      if (k <= csz_idx_0) {
        csz_idx_0 = k;
      }

      r.set_size(csz_idx_0);
      for (k = 0; k < csz_idx_0; k++) {
        r[k] = rt_hypotd_snf(x[k], y[k]);
      }
    }
  }
}

// End of code generation (hypot.cpp)
