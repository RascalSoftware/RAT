//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
    void b_bsxfun(const ::coder::array<real_T, 1U> &a, const ::coder::array<
                  real_T, 1U> &b, ::coder::array<real_T, 1U> &c)
    {
      int32_T acoef;
      int32_T csz_idx_0;
      int32_T u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        csz_idx_0 = a.size(0);
      } else if (a.size(0) == 1) {
        csz_idx_0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        csz_idx_0 = a.size(0);
      } else {
        csz_idx_0 = acoef;
      }

      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        acoef = a.size(0);
      } else if (a.size(0) == 1) {
        acoef = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        acoef = a.size(0);
      }

      c.set_size(acoef);
      if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0 = csz_idx_0 - 1;
        for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
          c[csz_idx_0] = b_anon(a[acoef * csz_idx_0], b[bcoef * csz_idx_0]);
        }
      }
    }

    void b_bsxfun(const ::coder::array<real_T, 1U> &a, ::coder::array<real_T, 1U>
                  &c)
    {
      c.set_size(a.size(0));
      if (a.size(0) != 0) {
        int32_T acoef;
        int32_T i;
        acoef = (a.size(0) != 1);
        i = a.size(0) - 1;
        for (int32_T k{0}; k <= i; k++) {
          real_T x;
          x = a[acoef * k];
          if ((!std::isnan(x)) && (x < 0.0)) {
            c[k] = 0.0;
          } else {
            c[k] = x;
          }
        }
      }
    }

    void bsxfun(const ::coder::array<real_T, 1U> &a, const ::coder::array<real_T,
                1U> &b, ::coder::array<real_T, 1U> &c)
    {
      int32_T acoef;
      int32_T csz_idx_0;
      int32_T u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        csz_idx_0 = a.size(0);
      } else if (a.size(0) == 1) {
        csz_idx_0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        csz_idx_0 = a.size(0);
      } else {
        csz_idx_0 = acoef;
      }

      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        acoef = a.size(0);
      } else if (a.size(0) == 1) {
        acoef = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        acoef = a.size(0);
      }

      c.set_size(acoef);
      if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0 = csz_idx_0 - 1;
        for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
          c[csz_idx_0] = anon(a[acoef * csz_idx_0], b[bcoef * csz_idx_0]);
        }
      }
    }

    void bsxfun(const ::coder::array<real_T, 1U> &a, ::coder::array<real_T, 1U>
                &c)
    {
      c.set_size(a.size(0));
      if (a.size(0) != 0) {
        int32_T acoef;
        int32_T i;
        acoef = (a.size(0) != 1);
        i = a.size(0) - 1;
        for (int32_T k{0}; k <= i; k++) {
          c[k] = a[acoef * k];
        }
      }
    }

    void c_bsxfun(const ::coder::array<real_T, 1U> &a, const ::coder::array<
                  real_T, 1U> &b, ::coder::array<real_T, 1U> &c)
    {
      int32_T acoef;
      int32_T csz_idx_0;
      int32_T u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        csz_idx_0 = a.size(0);
      } else if (a.size(0) == 1) {
        csz_idx_0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        csz_idx_0 = a.size(0);
      } else {
        csz_idx_0 = acoef;
      }

      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        acoef = a.size(0);
      } else if (a.size(0) == 1) {
        acoef = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        acoef = a.size(0);
      }

      c.set_size(acoef);
      if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0 = csz_idx_0 - 1;
        for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
          c[csz_idx_0] = std::fmax(a[acoef * csz_idx_0], b[bcoef * csz_idx_0]);
        }
      }
    }

    void c_bsxfun(const ::coder::array<real_T, 1U> &a, ::coder::array<real_T, 1U>
                  &c)
    {
      c.set_size(a.size(0));
      if (a.size(0) != 0) {
        int32_T acoef;
        int32_T i;
        acoef = (a.size(0) != 1);
        i = a.size(0) - 1;
        for (int32_T k{0}; k <= i; k++) {
          real_T x;
          x = a[acoef * k];
          if ((!std::isnan(x)) && (x > 1.0)) {
            c[k] = 1.0;
          } else {
            c[k] = x;
          }
        }
      }
    }

    void d_bsxfun(const ::coder::array<real_T, 1U> &a, const ::coder::array<
                  real_T, 1U> &b, ::coder::array<real_T, 1U> &c)
    {
      int32_T acoef;
      int32_T csz_idx_0;
      int32_T u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        csz_idx_0 = a.size(0);
      } else if (a.size(0) == 1) {
        csz_idx_0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        csz_idx_0 = a.size(0);
      } else {
        csz_idx_0 = acoef;
      }

      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        acoef = a.size(0);
      } else if (a.size(0) == 1) {
        acoef = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        acoef = a.size(0);
      }

      c.set_size(acoef);
      if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0 = csz_idx_0 - 1;
        for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
          c[csz_idx_0] = a[acoef * csz_idx_0] - b[bcoef * csz_idx_0];
        }
      }
    }

    void e_bsxfun(const ::coder::array<real_T, 1U> &a, const ::coder::array<
                  real_T, 1U> &b, ::coder::array<real_T, 1U> &c)
    {
      int32_T acoef;
      int32_T csz_idx_0;
      int32_T u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        csz_idx_0 = a.size(0);
      } else if (a.size(0) == 1) {
        csz_idx_0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        csz_idx_0 = a.size(0);
      } else {
        csz_idx_0 = acoef;
      }

      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        acoef = a.size(0);
      } else if (a.size(0) == 1) {
        acoef = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        acoef = a.size(0);
      }

      c.set_size(acoef);
      if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0 = csz_idx_0 - 1;
        for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
          c[csz_idx_0] = a[acoef * csz_idx_0] * b[bcoef * csz_idx_0];
        }
      }
    }

    void f_bsxfun(const ::coder::array<real_T, 1U> &a, const ::coder::array<
                  real_T, 1U> &b, ::coder::array<real_T, 1U> &c)
    {
      int32_T acoef;
      int32_T csz_idx_0;
      int32_T u0;
      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        csz_idx_0 = a.size(0);
      } else if (a.size(0) == 1) {
        csz_idx_0 = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        csz_idx_0 = a.size(0);
      } else {
        csz_idx_0 = acoef;
      }

      u0 = b.size(0);
      acoef = a.size(0);
      if (u0 < acoef) {
        acoef = u0;
      }

      if (b.size(0) == 1) {
        acoef = a.size(0);
      } else if (a.size(0) == 1) {
        acoef = b.size(0);
      } else if (a.size(0) == b.size(0)) {
        acoef = a.size(0);
      }

      c.set_size(acoef);
      if (csz_idx_0 != 0) {
        int32_T bcoef;
        acoef = (a.size(0) != 1);
        bcoef = (b.size(0) != 1);
        u0 = csz_idx_0 - 1;
        for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
          c[csz_idx_0] = a[acoef * csz_idx_0] + b[bcoef * csz_idx_0];
        }
      }
    }
  }
}

// End of code generation (bsxfun.cpp)
