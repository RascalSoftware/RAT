//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rescale.cpp
//
// Code generation for function 'rescale'
//

// Include files
#include "rescale.h"
#include "bsxfun.h"
#include "minOrMax.h"
#include "rescaleKernel.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    real_T anon(real_T x, real_T y)
    {
      real_T varargout_1;
      boolean_T p;
      if (std::isnan(y)) {
        p = !std::isnan(x);
      } else if (std::isnan(x)) {
        p = false;
      } else {
        p = (x < y);
      }

      if (p) {
        varargout_1 = y;
      } else {
        varargout_1 = x;
      }

      return varargout_1;
    }

    real_T b_anon(real_T x, real_T y)
    {
      real_T varargout_1;
      boolean_T p;
      if (std::isnan(y)) {
        p = !std::isnan(x);
      } else if (std::isnan(x)) {
        p = false;
      } else {
        p = (x > y);
      }

      if (p) {
        varargout_1 = y;
      } else {
        varargout_1 = x;
      }

      return varargout_1;
    }

    void rescale(::coder::array<real_T, 1U> &A, const ::coder::array<real_T, 1U>
                 &varargin_2, const ::coder::array<real_T, 1U> &varargin_4, ::
                 coder::array<real_T, 1U> &R)
    {
      ::coder::array<real_T, 1U> b_A;
      if (varargin_2.size(0) == 1) {
        int32_T loop_ub;
        b_A.set_size(A.size(0));
        loop_ub = A.size(0) - 1;
        for (int32_T i{0}; i <= loop_ub; i++) {
          b_A[i] = A[i];
        }

        internal::maximum2(b_A, varargin_2[0], A);
      } else {
        int32_T loop_ub;
        b_A.set_size(A.size(0));
        loop_ub = A.size(0) - 1;
        for (int32_T i{0}; i <= loop_ub; i++) {
          b_A[i] = A[i];
        }

        bsxfun(b_A, varargin_2, A);
      }

      if (varargin_4.size(0) == 1) {
        internal::minimum2(A, varargin_4[0], R);
      } else {
        b_bsxfun(A, varargin_4, R);
      }

      rescaleKernel(R, varargin_2, varargin_4);
    }
  }
}

// End of code generation (rescale.cpp)
