//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sortLE.cpp
//
// Code generation for function 'sortLE'
//

// Include files
#include "sortLE.h"
#include "rt_nonfinite.h"
#include "sortAscendLE.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T b_sortLE(const ::coder::array<double, 2U> &v, int idx1, int idx2)
      {
        double d;
        boolean_T p;
        d = v[idx2 - 1];
        if ((v[idx1 - 1] <= d) || std::isnan(d)) {
          p = true;
        } else {
          p = false;
        }

        return p;
      }

      boolean_T sortLE(const double v[4], int idx1, int idx2)
      {
        double d;
        boolean_T p;
        d = v[idx2 - 1];
        if ((v[idx1 - 1] <= d) || std::isnan(d)) {
          p = true;
        } else {
          p = false;
        }

        return p;
      }

      boolean_T sortLE(const ::coder::array<double, 2U> &v, int idx1, int idx2)
      {
        int k;
        boolean_T exitg1;
        boolean_T p;
        p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 2)) {
          double v1;
          double v2;
          v1 = v[(idx1 + v.size(0) * k) - 1];
          v2 = v[(idx2 + v.size(0) * k) - 1];
          if ((v1 == v2) || (std::isnan(v1) && std::isnan(v2))) {
            k++;
          } else {
            p = sortAscendLE(v1, v2);
            exitg1 = true;
          }
        }

        return p;
      }

      boolean_T sortLE(const ::coder::array<double, 1U> &v, int idx1, int idx2)
      {
        double d;
        boolean_T p;
        d = v[idx2 - 1];
        if ((v[idx1 - 1] <= d) || std::isnan(d)) {
          p = true;
        } else {
          p = false;
        }

        return p;
      }
    }
  }
}

// End of code generation (sortLE.cpp)
