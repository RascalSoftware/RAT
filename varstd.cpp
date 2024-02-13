//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// varstd.cpp
//
// Code generation for function 'varstd'
//

// Include files
#include "varstd.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    real_T anon(int32_T n, const ::coder::array<real_T, 1U> &x)
    {
      ::coder::array<real_T, 1U> absdiff;
      real_T varargout_1;
      if (n == 0) {
        varargout_1 = rtNaN;
      } else if (n == 1) {
        if ((!std::isinf(x[0])) && (!std::isnan(x[0]))) {
          varargout_1 = 0.0;
        } else {
          varargout_1 = rtNaN;
        }
      } else {
        real_T xbar;
        xbar = b_combineVectorElements(x, n) / static_cast<real_T>(n);
        absdiff.set_size(x.size(0));
        for (int32_T k{0}; k < n; k++) {
          absdiff[k] = std::abs(x[k] - xbar);
        }

        varargout_1 = internal::blas::b_xnrm2(n, absdiff) / std::sqrt(
          static_cast<real_T>(n - 1));
      }

      return varargout_1;
    }

    real_T b_anon(int32_T n, const ::coder::array<real_T, 1U> &x)
    {
      real_T varargout_1;
      if (n == 0) {
        varargout_1 = rtNaN;
      } else if (n == 1) {
        if ((!std::isinf(x[0])) && (!std::isnan(x[0]))) {
          varargout_1 = 0.0;
        } else {
          varargout_1 = rtNaN;
        }
      } else {
        real_T xbar;
        xbar = b_combineVectorElements(x, n) / static_cast<real_T>(n);
        varargout_1 = 0.0;
        for (int32_T k{0}; k < n; k++) {
          real_T t;
          t = x[k] - xbar;
          varargout_1 += t * t;
        }

        varargout_1 /= static_cast<real_T>(n - 1);
      }

      return varargout_1;
    }
  }
}

// End of code generation (varstd.cpp)
