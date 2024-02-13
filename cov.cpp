//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// cov.cpp
//
// Code generation for function 'cov'
//

// Include files
#include "cov.h"
#include "isrow.h"
#include "rt_nonfinite.h"
#include "xgemm.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void local_cov(::coder::array<real_T, 2U> &x, ::coder::array<real_T,
                          2U> &c);
    static real_T local_cov(::coder::array<real_T, 1U> &x);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static void local_cov(::coder::array<real_T, 2U> &x, ::coder::array<real_T,
                          2U> &c)
    {
      int32_T LDA;
      int32_T b_i;
      int32_T i;
      int32_T m;
      int32_T n;
      int32_T nx;
      m = x.size(0);
      n = x.size(1);
      c.set_size(x.size(1), x.size(1));
      LDA = x.size(1);
      for (i = 0; i < LDA; i++) {
        nx = x.size(1);
        for (b_i = 0; b_i < nx; b_i++) {
          c[b_i + c.size(0) * i] = 0.0;
        }
      }

      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        c.set_size(x.size(1), x.size(1));
        LDA = x.size(1);
        for (i = 0; i < LDA; i++) {
          nx = x.size(1);
          for (b_i = 0; b_i < nx; b_i++) {
            c[b_i + c.size(0) * i] = rtNaN;
          }
        }
      } else {
        LDA = x.size(0);
        if (x.size(0) >= 2) {
          nx = x.size(0);
          c.set_size(n, n);
          for (int32_T j{0}; j < n; j++) {
            real_T muj;
            muj = 0.0;
            for (b_i = 0; b_i < m; b_i++) {
              muj += x[b_i + x.size(0) * j];
            }

            muj /= static_cast<real_T>(m);
            for (b_i = 0; b_i < m; b_i++) {
              x[b_i + x.size(0) * j] = x[b_i + x.size(0) * j] - muj;
            }

            for (i = 0; i < n; i++) {
              c[i + c.size(0) * j] = 0.0;
            }
          }

          internal::blas::xgemm(n, n, m, 1.0 / (static_cast<real_T>(nx) - 1.0),
                                x, LDA, x, LDA, c, n);
        }
      }
    }

    static real_T local_cov(::coder::array<real_T, 1U> &x)
    {
      real_T c;
      int32_T m;
      m = x.size(0);
      c = 0.0;
      if (x.size(0) == 0) {
        c = rtNaN;
      } else if (x.size(0) >= 2) {
        real_T muj;
        int32_T i;
        int32_T nx;
        nx = x.size(0);
        muj = 0.0;
        for (i = 0; i < m; i++) {
          muj += x[i];
        }

        muj /= static_cast<real_T>(x.size(0));
        for (i = 0; i < m; i++) {
          x[i] = x[i] - muj;
        }

        internal::blas::xgemm(m, 1.0 / (static_cast<real_T>(nx) - 1.0), x, x, &c);
      }

      return c;
    }

    void cov(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &xy)
    {
      ::coder::array<real_T, 2U> b_x;
      ::coder::array<real_T, 1U> c_x;
      if (isrow(x)) {
        int32_T loop_ub;
        loop_ub = x.size(1);
        c_x.set_size(x.size(1));
        for (int32_T i{0}; i < loop_ub; i++) {
          c_x[i] = x[x.size(0) * i];
        }

        xy.set_size(1, 1);
        xy[0] = local_cov(c_x);
      } else {
        int32_T loop_ub;
        b_x.set_size(x.size(0), x.size(1));
        loop_ub = x.size(1) - 1;
        for (int32_T i{0}; i <= loop_ub; i++) {
          int32_T b_loop_ub;
          b_loop_ub = x.size(0) - 1;
          for (int32_T i1{0}; i1 <= b_loop_ub; i1++) {
            b_x[i1 + b_x.size(0) * i] = x[i1 + x.size(0) * i];
          }
        }

        local_cov(b_x, xy);
      }
    }
  }
}

// End of code generation (cov.cpp)
