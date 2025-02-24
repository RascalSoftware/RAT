//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// triu.cpp
//
// Code generation for function 'triu'
//

// Include files
#include "triu.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_triu(::coder::array<double, 2U> &x)
    {
      int m;
      m = x.size(0);
      if ((x.size(0) != 0) && (x.size(1) != 0) && (3 < x.size(0))) {
        int istart;
        int jend;
        istart = 4;
        if (x.size(0) - 4 < x.size(1) - 1) {
          jend = x.size(0) - 3;
        } else {
          jend = x.size(1);
        }

        for (int j{0}; j < jend; j++) {
          for (int i{istart}; i <= m; i++) {
            x[(i + x.size(0) * j) - 1] = 0.0;
          }

          istart++;
        }
      }
    }

    void triu(::coder::array<double, 2U> &x)
    {
      int m;
      m = x.size(0);
      if ((x.size(0) != 0) && (x.size(1) != 0) && (1 < x.size(0))) {
        int istart;
        int jend;
        istart = 2;
        if (x.size(0) - 2 < x.size(1) - 1) {
          jend = x.size(0) - 1;
        } else {
          jend = x.size(1);
        }

        for (int j{0}; j < jend; j++) {
          for (int i{istart}; i <= m; i++) {
            x[(i + x.size(0) * j) - 1] = 0.0;
          }

          istart++;
        }
      }
    }
  }
}

// End of code generation (triu.cpp)
