//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// power.cpp
//
// Code generation for function 'power'
//

// Include files
#include "power.h"
#include "RATMain_rtwutil.h"
#include "exp.h"
#include "log.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_power(const ::coder::array<double, 1U> &b, ::coder::array<double, 1U>
                 &y)
    {
      int N;
      y.set_size(b.size(0));
      N = b.size(0);
      for (int k{0}; k < N; k++) {
        y[k] = rt_powd_snf(10.0, b[k]);
      }
    }

    void b_power(const ::coder::array<double, 2U> &a, ::coder::array<double, 2U>
                 &y)
    {
      int N;
      y.set_size(a.size(0), a.size(1));
      N = a.size(1);
      for (int k{0}; k < N; k++) {
        int b_N;
        b_N = y.size(0);
        for (int b_k{0}; b_k < b_N; b_k++) {
          y[b_k + y.size(0) * k] = rt_powd_snf(a[b_k + a.size(0) * k], 2.0);
        }
      }
    }

    void power(const ::coder::array<creal_T, 2U> &a, ::coder::array<creal_T, 2U>
               &y)
    {
      creal_T dc;
      int N;
      y.set_size(1, a.size(1));
      N = a.size(1);
      for (int k{0}; k < N; k++) {
        double ai;
        double ar;
        ar = a[k].re;
        ai = a[k].im;
        if ((ai == 0.0) && (ar >= 0.0)) {
          y[k].re = rt_powd_snf(ar, 2.0);
          y[k].im = 0.0;
        } else if (ar == 0.0) {
          y[k].re = -rt_powd_snf(ai, 2.0);
          y[k].im = 0.0;
        } else {
          dc = a[k];
          b_log(&dc);
          y[k].re = 2.0 * dc.re;
          y[k].im = 2.0 * dc.im;
          b_exp(&y[k]);
        }
      }
    }

    void power(const ::coder::array<double, 2U> &a, ::coder::array<double, 2U>
               &y)
    {
      int N;
      y.set_size(1, a.size(1));
      N = a.size(1);
      for (int k{0}; k < N; k++) {
        y[k] = rt_powd_snf(a[k], 2.0);
      }
    }

    void power(const ::coder::array<double, 1U> &a, ::coder::array<double, 1U>
               &y)
    {
      int N;
      y.set_size(a.size(0));
      N = a.size(0);
      for (int k{0}; k < N; k++) {
        y[k] = rt_powd_snf(a[k], 2.0);
      }
    }
  }
}

// End of code generation (power.cpp)
