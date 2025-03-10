//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    double b_varstd_anonFcn3(int n, const ::coder::array<double, 1U> &x)
    {
      double varargout_1;
      if (n == 0) {
        varargout_1 = rtNaN;
      } else if (n == 1) {
        if ((!std::isinf(x[0])) && (!std::isnan(x[0]))) {
          varargout_1 = 0.0;
        } else {
          varargout_1 = rtNaN;
        }
      } else {
        double xbar;
        xbar = b_combineVectorElements(x, n) / static_cast<double>(n);
        varargout_1 = 0.0;
        for (int k{0}; k < n; k++) {
          double t;
          t = x[k] - xbar;
          varargout_1 += t * t;
        }

        varargout_1 /= static_cast<double>(n - 1);
      }

      return varargout_1;
    }

    double varstd_anonFcn3(int n, const ::coder::array<double, 1U> &x)
    {
      ::coder::array<double, 1U> absdiff;
      double varargout_1;
      if (n == 0) {
        varargout_1 = rtNaN;
      } else if (n == 1) {
        if ((!std::isinf(x[0])) && (!std::isnan(x[0]))) {
          varargout_1 = 0.0;
        } else {
          varargout_1 = rtNaN;
        }
      } else {
        double xbar;
        xbar = b_combineVectorElements(x, n) / static_cast<double>(n);
        absdiff.set_size(x.size(0));
        for (int k{0}; k < n; k++) {
          absdiff[k] = std::abs(x[k] - xbar);
        }

        varargout_1 = internal::blas::xnrm2(n, absdiff) / std::sqrt(static_cast<
          double>(n - 1));
      }

      return varargout_1;
    }
  }
}

// End of code generation (varstd.cpp)
