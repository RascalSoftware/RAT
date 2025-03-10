//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// rescale.cpp
//
// Code generation for function 'rescale'
//

// Include files
#include "rescale.h"
#include "bsxfun.h"
#include "rescaleKernel.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void rescale(::coder::array<double, 1U> &A, const ::coder::array<double, 1U>
                 &varargin_2, const ::coder::array<double, 1U> &varargin_4, ::
                 coder::array<double, 1U> &R)
    {
      ::coder::array<double, 1U> b_A;
      double b_varargin_2;
      double varargin_1;
      int loop_ub;
      boolean_T p;
      if (varargin_2.size(0) == 1) {
        loop_ub = A.size(0);
        for (int i{0}; i < loop_ub; i++) {
          varargin_1 = A[i];
          b_varargin_2 = varargin_2[0];
          if (std::isnan(b_varargin_2)) {
            p = !std::isnan(varargin_1);
          } else if (std::isnan(varargin_1)) {
            p = false;
          } else {
            p = (varargin_1 < b_varargin_2);
          }

          if (p) {
            A[i] = b_varargin_2;
          } else {
            A[i] = varargin_1;
          }
        }
      } else {
        b_A.set_size(A.size(0));
        loop_ub = A.size(0) - 1;
        for (int i{0}; i <= loop_ub; i++) {
          b_A[i] = A[i];
        }

        bsxfun(b_A, varargin_2, A);
      }

      if (varargin_4.size(0) == 1) {
        R.set_size(A.size(0));
        loop_ub = A.size(0);
        for (int i{0}; i < loop_ub; i++) {
          varargin_1 = A[i];
          b_varargin_2 = varargin_4[0];
          if (std::isnan(b_varargin_2)) {
            p = !std::isnan(varargin_1);
          } else if (std::isnan(varargin_1)) {
            p = false;
          } else {
            p = (varargin_1 > b_varargin_2);
          }

          if (p) {
            R[i] = b_varargin_2;
          } else {
            R[i] = varargin_1;
          }
        }
      } else {
        b_bsxfun(A, varargin_4, R);
      }

      rescaleKernel(R, varargin_2, varargin_4);
    }

    double rescale_anonFcn1(double x, double y)
    {
      double varargout_1;
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

    double rescale_anonFcn2(double x, double y)
    {
      double varargout_1;
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
  }
}

// End of code generation (rescale.cpp)
