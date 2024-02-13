//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// minOrMax.cpp
//
// Code generation for function 'minOrMax'
//

// Include files
#include "minOrMax.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      real_T b_maximum(const real_T x[3])
      {
        real_T ex;
        int32_T idx;
        int32_T k;
        if (!std::isnan(x[0])) {
          idx = 1;
        } else {
          boolean_T exitg1;
          idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= 3)) {
            if (!std::isnan(x[k - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (idx == 0) {
          ex = x[0];
        } else {
          ex = x[idx - 1];
          idx++;
          for (k = idx; k < 4; k++) {
            real_T d;
            d = x[k - 1];
            if (ex < d) {
              ex = d;
            }
          }
        }

        return ex;
      }

      void maximum(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T,
                   2U> &ex)
      {
        int32_T m;
        int32_T n;
        m = x.size(0);
        n = x.size(1);
        ex.set_size(1, x.size(1));
        if (x.size(1) >= 1) {
          for (int32_T j{0}; j < n; j++) {
            ex[j] = x[x.size(0) * j];
            for (int32_T i{2}; i <= m; i++) {
              real_T d;
              d = x[(i + x.size(0) * j) - 1];
              if (relop(ex[j], d)) {
                ex[j] = d;
              }
            }
          }
        }
      }

      real_T maximum(const ::coder::array<real_T, 1U> &x)
      {
        real_T ex;
        int32_T last;
        last = x.size(0);
        if (x.size(0) <= 2) {
          if (x.size(0) == 1) {
            ex = x[0];
          } else if ((x[0] < x[x.size(0) - 1]) || (std::isnan(x[0]) && (!std::
                       isnan(x[x.size(0) - 1])))) {
            ex = x[x.size(0) - 1];
          } else {
            ex = x[0];
          }
        } else {
          int32_T idx;
          int32_T k;
          if (!std::isnan(x[0])) {
            idx = 1;
          } else {
            boolean_T exitg1;
            idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= last)) {
              if (!std::isnan(x[k - 1])) {
                idx = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (idx == 0) {
            ex = x[0];
          } else {
            ex = x[idx - 1];
            idx++;
            for (k = idx; k <= last; k++) {
              real_T d;
              d = x[k - 1];
              if (ex < d) {
                ex = d;
              }
            }
          }
        }

        return ex;
      }

      real_T maximum(const ::coder::array<real_T, 2U> &x)
      {
        real_T ex;
        int32_T last;
        last = x.size(1);
        if (x.size(1) <= 2) {
          if (x.size(1) == 1) {
            ex = x[0];
          } else if ((x[0] < x[x.size(1) - 1]) || (std::isnan(x[0]) && (!std::
                       isnan(x[x.size(1) - 1])))) {
            ex = x[x.size(1) - 1];
          } else {
            ex = x[0];
          }
        } else {
          int32_T idx;
          int32_T k;
          if (!std::isnan(x[0])) {
            idx = 1;
          } else {
            boolean_T exitg1;
            idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= last)) {
              if (!std::isnan(x[k - 1])) {
                idx = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (idx == 0) {
            ex = x[0];
          } else {
            ex = x[idx - 1];
            idx++;
            for (k = idx; k <= last; k++) {
              real_T d;
              d = x[k - 1];
              if (ex < d) {
                ex = d;
              }
            }
          }
        }

        return ex;
      }

      void maximum(const ::coder::array<real_T, 2U> &x, real_T ex[2])
      {
        int32_T m;
        m = x.size(0);
        for (int32_T j{0}; j < 2; j++) {
          ex[j] = x[x.size(0) * j];
          for (int32_T i{2}; i <= m; i++) {
            real_T d;
            d = x[(i + x.size(0) * j) - 1];
            if (relop(ex[j], d)) {
              ex[j] = d;
            }
          }
        }
      }

      real_T maximum(const real_T x[2])
      {
        real_T ex;
        if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
          ex = x[1];
        } else {
          ex = x[0];
        }

        return ex;
      }

      void maximum2(const ::coder::array<real_T, 1U> &x, real_T y, ::coder::
                    array<real_T, 1U> &ex)
      {
        int32_T N;
        ex.set_size(x.size(0));
        N = x.size(0);
        for (int32_T k{0}; k < N; k++) {
          if (c_relop(x[k], y)) {
            ex[k] = y;
          } else {
            ex[k] = x[k];
          }
        }
      }

      void maximum2(const ::coder::array<real_T, 1U> &x, const ::coder::array<
                    real_T, 1U> &y, ::coder::array<real_T, 1U> &ex)
      {
        int32_T csz_idx_0;
        if (x.size(0) <= y.size(0)) {
          csz_idx_0 = x.size(0);
        } else {
          csz_idx_0 = y.size(0);
        }

        ex.set_size(csz_idx_0);
        for (int32_T k{0}; k < csz_idx_0; k++) {
          ex[k] = std::fmax(x[k], y[k]);
        }
      }

      void minimum(const ::coder::array<real_T, 1U> &x, real_T *ex, int32_T *idx)
      {
        int32_T last;
        last = x.size(0);
        if (x.size(0) <= 2) {
          if (x.size(0) == 1) {
            *ex = x[0];
            *idx = 1;
          } else if ((x[0] > x[x.size(0) - 1]) || (std::isnan(x[0]) && (!std::
                       isnan(x[x.size(0) - 1])))) {
            *ex = x[x.size(0) - 1];
            *idx = x.size(0);
          } else {
            *ex = x[0];
            *idx = 1;
          }
        } else {
          int32_T k;
          if (!std::isnan(x[0])) {
            *idx = 1;
          } else {
            boolean_T exitg1;
            *idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= last)) {
              if (!std::isnan(x[k - 1])) {
                *idx = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (*idx == 0) {
            *ex = x[0];
            *idx = 1;
          } else {
            int32_T i;
            *ex = x[*idx - 1];
            i = *idx + 1;
            for (k = i; k <= last; k++) {
              real_T d;
              d = x[k - 1];
              if (*ex > d) {
                *ex = d;
                *idx = k;
              }
            }
          }
        }
      }

      real_T minimum(const real_T x[2])
      {
        real_T ex;
        if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
          ex = x[1];
        } else {
          ex = x[0];
        }

        return ex;
      }

      void minimum(const real_T x[50], real_T *ex, int32_T *idx)
      {
        int32_T k;
        if (!std::isnan(x[0])) {
          *idx = 1;
        } else {
          boolean_T exitg1;
          *idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k < 51)) {
            if (!std::isnan(x[k - 1])) {
              *idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (*idx == 0) {
          *ex = x[0];
          *idx = 1;
        } else {
          int32_T i;
          *ex = x[*idx - 1];
          i = *idx + 1;
          for (k = i; k < 51; k++) {
            real_T d;
            d = x[k - 1];
            if (*ex > d) {
              *ex = d;
              *idx = k;
            }
          }
        }
      }

      void minimum(const ::coder::array<real_T, 2U> &x, real_T ex[2])
      {
        int32_T m;
        m = x.size(0);
        for (int32_T j{0}; j < 2; j++) {
          ex[j] = x[x.size(0) * j];
          for (int32_T i{2}; i <= m; i++) {
            real_T d;
            d = x[(i + x.size(0) * j) - 1];
            if (b_relop(ex[j], d)) {
              ex[j] = d;
            }
          }
        }
      }

      void minimum2(const ::coder::array<real_T, 1U> &x, real_T y, ::coder::
                    array<real_T, 1U> &ex)
      {
        int32_T N;
        ex.set_size(x.size(0));
        N = x.size(0);
        for (int32_T k{0}; k < N; k++) {
          if (d_relop(x[k], y)) {
            ex[k] = y;
          } else {
            ex[k] = x[k];
          }
        }
      }

      void minimum2(const ::coder::array<real_T, 1U> &y, ::coder::array<real_T,
                    1U> &ex)
      {
        int32_T N;
        ex.set_size(y.size(0));
        N = y.size(0);
        for (int32_T k{0}; k < N; k++) {
          ex[k] = std::fmin(0.0, y[k]);
        }
      }
    }
  }
}

// End of code generation (minOrMax.cpp)
