//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// bsxfun.cpp
//
// Code generation for function 'bsxfun'
//

// Include files
#include "bsxfun.h"
#include "rescale.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_bsxfun(const ::coder::array<double, 1U> &a, const ::coder::array<
                  double, 1U> &b, ::coder::array<double, 1U> &c)
    {
      int acoef;
      int u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 <= acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        u0 = a.size(0);
      } else if (a.size(0) == 1) {
        u0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        u0 = a.size(0);
      } else {
        u0 = acoef;
      }

      c.set_size(u0);
      if (u0 != 0) {
        int bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0--;
        for (int k{0}; k <= u0; k++) {
          c[k] = rescale_anonFcn2(a[acoef * k], b[bcoef * k]);
        }
      }
    }

    void b_bsxfun(const ::coder::array<double, 1U> &a, ::coder::array<double, 1U>
                  &c)
    {
      c.set_size(a.size(0));
      if (a.size(0) != 0) {
        int acoef;
        int i;
        acoef = (a.size(0) != 1);
        i = a.size(0) - 1;
        for (int k{0}; k <= i; k++) {
          double x;
          x = a[acoef * k];
          if ((!std::isnan(x)) && (x < 0.0)) {
            c[k] = 0.0;
          } else {
            c[k] = x;
          }
        }
      }
    }

    void bsxfun(const ::coder::array<double, 1U> &a, const ::coder::array<double,
                1U> &b, ::coder::array<double, 1U> &c)
    {
      int acoef;
      int u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 <= acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        u0 = a.size(0);
      } else if (a.size(0) == 1) {
        u0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        u0 = a.size(0);
      } else {
        u0 = acoef;
      }

      c.set_size(u0);
      if (u0 != 0) {
        int bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0--;
        for (int k{0}; k <= u0; k++) {
          c[k] = rescale_anonFcn1(a[acoef * k], b[bcoef * k]);
        }
      }
    }

    void bsxfun(const ::coder::array<double, 1U> &a, ::coder::array<double, 1U>
                &c)
    {
      c.set_size(a.size(0));
      if (a.size(0) != 0) {
        int acoef;
        int i;
        acoef = (a.size(0) != 1);
        i = a.size(0) - 1;
        for (int k{0}; k <= i; k++) {
          c[k] = a[acoef * k];
        }
      }
    }

    void c_bsxfun(const ::coder::array<double, 1U> &a, const ::coder::array<
                  double, 1U> &b, ::coder::array<double, 1U> &c)
    {
      int acoef;
      int u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 <= acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        u0 = a.size(0);
      } else if (a.size(0) == 1) {
        u0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        u0 = a.size(0);
      } else {
        u0 = acoef;
      }

      c.set_size(u0);
      if (u0 != 0) {
        int bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0--;
        for (int k{0}; k <= u0; k++) {
          c[k] = std::fmax(a[acoef * k], b[bcoef * k]);
        }
      }
    }

    void c_bsxfun(const ::coder::array<double, 1U> &a, ::coder::array<double, 1U>
                  &c)
    {
      c.set_size(a.size(0));
      if (a.size(0) != 0) {
        int acoef;
        int i;
        acoef = (a.size(0) != 1);
        i = a.size(0) - 1;
        for (int k{0}; k <= i; k++) {
          double x;
          x = a[acoef * k];
          if ((!std::isnan(x)) && (x > 1.0)) {
            c[k] = 1.0;
          } else {
            c[k] = x;
          }
        }
      }
    }

    void d_bsxfun(const ::coder::array<double, 1U> &a, const ::coder::array<
                  double, 1U> &b, ::coder::array<double, 1U> &c)
    {
      int acoef;
      int u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 <= acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        u0 = a.size(0);
      } else if (a.size(0) == 1) {
        u0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        u0 = a.size(0);
      } else {
        u0 = acoef;
      }

      c.set_size(u0);
      if (u0 != 0) {
        int bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0--;
        for (int k{0}; k <= u0; k++) {
          c[k] = a[acoef * k] - b[bcoef * k];
        }
      }
    }

    void e_bsxfun(const ::coder::array<double, 1U> &a, const ::coder::array<
                  double, 1U> &b, ::coder::array<double, 1U> &c)
    {
      int acoef;
      int u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 <= acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        u0 = a.size(0);
      } else if (a.size(0) == 1) {
        u0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        u0 = a.size(0);
      } else {
        u0 = acoef;
      }

      c.set_size(u0);
      if (u0 != 0) {
        int bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0--;
        for (int k{0}; k <= u0; k++) {
          c[k] = a[acoef * k] * b[bcoef * k];
        }
      }
    }

    void f_bsxfun(const ::coder::array<double, 1U> &a, const ::coder::array<
                  double, 1U> &b, ::coder::array<double, 1U> &c)
    {
      int acoef;
      int u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 <= acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        u0 = a.size(0);
      } else if (a.size(0) == 1) {
        u0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        u0 = a.size(0);
      } else {
        u0 = acoef;
      }

      c.set_size(u0);
      if (u0 != 0) {
        int bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0--;
        for (int k{0}; k <= u0; k++) {
          c[k] = a[acoef * k] + b[bcoef * k];
        }
      }
    }
  }
}

// End of code generation (bsxfun.cpp)
