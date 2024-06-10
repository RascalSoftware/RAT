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
#include "rt_defines.h"
#include <cfloat>
#include <cmath>
#include <cstddef>

// Variable Definitions
namespace RAT
{
  static RATMainTLS *RATMainTLSGlobal;

#pragma omp threadprivate (RATMainTLSGlobal)

}

// Function Definitions
namespace RAT
{
  void cast(const ::coder::array<cell_wrap_63, 1U> &b, ::coder::array<
            cell_wrap_10, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(5, b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        for (int32_T i3{0}; i3 < 5; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + 5 * i2];
        }
      }
    }
  }

  void cast(const ::coder::array<cell_wrap_63, 2U> &b, ::coder::array<
            cell_wrap_10, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(5, b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        for (int32_T i3{0}; i3 < 5; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + 5 * i2];
        }
      }
    }
  }

  void cast(const ::coder::array<cell_wrap_32, 2U> &b, ::coder::array<
            cell_wrap_10, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(1, b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1[c[i1].f1.size(0) * i2] = b[i1].f1[i2];
      }
    }
  }

  void emlrtFreeThreadStackData()
  {
    int32_T b;
    b = omp_get_max_threads();

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

    for (int32_T i = 1; i <= b; i++) {
      delete RATMainTLSGlobal;
    }
  }

  RATMainTLS *emlrtGetThreadStackData()
  {
    return RATMainTLSGlobal;
  }

  void emlrtInitThreadStackData()
  {
    int32_T b;
    b = omp_get_max_threads();

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

    for (int32_T i = 1; i <= b; i++) {
      RATMainTLSGlobal = new RATMainTLS;
    }
  }

  real_T rt_atan2d_snf(real_T u0, real_T u1)
  {
    real_T y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else if (std::isinf(u0) && std::isinf(u1)) {
      int32_T b_u0;
      int32_T b_u1;
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

      y = std::atan2(static_cast<real_T>(b_u0), static_cast<real_T>(b_u1));
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

  real_T rt_hypotd_snf(real_T u0, real_T u1)
  {
    real_T a;
    real_T y;
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

  real_T rt_powd_snf(real_T u0, real_T u1)
  {
    real_T y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else {
      real_T d;
      real_T d1;
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

  real_T rt_remd_snf(real_T u0, real_T u1)
  {
    real_T y;
    if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
      y = rtNaN;
    } else if (std::isinf(u1)) {
      y = u0;
    } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
      real_T q;
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
