//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain_rtwutil.cpp
//
// Code generation for function 'RATMain_rtwutil'
//

// Include files
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "rt_defines.h"
#include <cfloat>
#include <cmath>

// Function Definitions
namespace RAT
{
  void cast(const ::coder::array<cell_wrap_3, 2U> &b, ::coder::array<
            cell_wrap_47, 2U> &c)
  {
    int i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = b[i1].f1.size[1];
      c[c.size(0) * i1].f1.set_size(1, b[b.size(0) * i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1[i2] = b[i1].f1.data[i2];
      }
    }
  }

  void cast(const ::coder::array<cell_wrap_4, 2U> &b, ::coder::array<cell_wrap_9,
            2U> &c)
  {
    int i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = b[i1].f1.size[1];
      c[c.size(0) * i1].f1.set_size(b[b.size(0) * i1].f1.size[0], b[b.size(0) *
        i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = b[i1].f1.size[0];
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[c[i1].f1.size(0) * i2] = b[i1].f1.data[b[i1].f1.size[0] * i2];
        }
      }
    }
  }

  void cast(const ::coder::array<cell_wrap_6, 2U> &b, ::coder::array<cell_wrap_9,
            2U> &c)
  {
    int i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = b[i1].f1.size[1];
      c[i1].f1.set_size(b[i1].f1.size[0], b[i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = b[i1].f1.size[0];
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[c[i1].f1.size(0) * i2] = b[i1].f1.data[b[i1].f1.size[0] * i2];
        }
      }
    }
  }

  void cast(const ::coder::array<cell_wrap_0, 2U> &b, ::coder::array<
            cell_wrap_10, 2U> &c)
  {
    int i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = b[i1].f1.size[1];
      c[c.size(0) * i1].f1.set_size(1, b[b.size(0) * i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1[i2] = b[i1].f1.data[i2];
      }
    }
  }

  void cast(const ::coder::array<cell_wrap_5, 2U> &b, ::coder::array<cell_wrap_9,
            2U> &c)
  {
    int i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[c.size(0) * i1].f1.set_size(b[b.size(0) * i1].f1.size(0), b[b.size(0) *
        i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[c[i1].f1.size(0) * i2] = b[i1].f1[b[i1].f1.size(0) * i2];
        }
      }
    }
  }

  double rt_atan2d_snf(double u0, double u1)
  {
    double y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else if (std::isinf(u0) && std::isinf(u1)) {
      int b_u0;
      int b_u1;
      if (u0 > 0.0) {
        b_u0 = 1;
      } else {
        b_u0 = -1;
      }

      if (u1 > 0.0) {
        b_u1 = 1;
      } else {
        b_u1 = -1;
      }

      y = std::atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
    } else if (u1 == 0.0) {
      if (u0 > 0.0) {
        y = RT_PI / 2.0;
      } else if (u0 < 0.0) {
        y = -(RT_PI / 2.0);
      } else {
        y = 0.0;
      }
    } else {
      y = std::atan2(u0, u1);
    }

    return y;
  }

  double rt_hypotd_snf(double u0, double u1)
  {
    double a;
    double y;
    a = std::abs(u0);
    y = std::abs(u1);
    if (a < y) {
      a /= y;
      y *= std::sqrt(a * a + 1.0);
    } else if (a > y) {
      y /= a;
      y = a * std::sqrt(y * y + 1.0);
    } else if (!std::isnan(y)) {
      y = a * 1.4142135623730951;
    }

    return y;
  }

  double rt_powd_snf(double u0, double u1)
  {
    double y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else {
      double d;
      double d1;
      d = std::abs(u0);
      d1 = std::abs(u1);
      if (std::isinf(u1)) {
        if (d == 1.0) {
          y = 1.0;
        } else if (d > 1.0) {
          if (u1 > 0.0) {
            y = rtInf;
          } else {
            y = 0.0;
          }
        } else if (u1 > 0.0) {
          y = 0.0;
        } else {
          y = rtInf;
        }
      } else if (d1 == 0.0) {
        y = 1.0;
      } else if (d1 == 1.0) {
        if (u1 > 0.0) {
          y = u0;
        } else {
          y = 1.0 / u0;
        }
      } else if (u1 == 2.0) {
        y = u0 * u0;
      } else if ((u1 == 0.5) && (u0 >= 0.0)) {
        y = std::sqrt(u0);
      } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
        y = rtNaN;
      } else {
        y = std::pow(u0, u1);
      }
    }

    return y;
  }

  double rt_remd_snf(double u0, double u1)
  {
    double y;
    if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
      y = rtNaN;
    } else if (std::isinf(u1)) {
      y = u0;
    } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
      double q;
      q = std::abs(u0 / u1);
      if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }

    return y;
  }
}

// End of code generation (RATMain_rtwutil.cpp)
