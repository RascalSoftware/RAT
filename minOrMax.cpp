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
      double b_maximum(const double x[3])
      {
        double ex;
        int idx;
        int k;
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
            double d;
            d = x[k - 1];
            if (ex < d) {
              ex = d;
            }
          }
        }

        return ex;
      }

      void maximum(const ::coder::array<double, 2U> &x, ::coder::array<double,
                   2U> &ex)
      {
        int m;
        int n;
        m = x.size(0);
        n = x.size(1);
        ex.set_size(1, x.size(1));
        if (x.size(1) >= 1) {
          for (int j{0}; j < n; j++) {
            ex[j] = x[x.size(0) * j];
            for (int i{2}; i <= m; i++) {
              double d;
              d = x[(i + x.size(0) * j) - 1];
              if (relop(ex[j], d)) {
                ex[j] = d;
              }
            }
          }
        }
      }

      double maximum(const ::coder::array<double, 1U> &x)
      {
        double ex;
        int last;
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
          int idx;
          int k;
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
              double d;
              d = x[k - 1];
              if (ex < d) {
                ex = d;
              }
            }
          }
        }

        return ex;
      }

      double maximum(const ::coder::array<double, 2U> &x)
      {
        double ex;
        int last;
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
          int idx;
          int k;
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
              double d;
              d = x[k - 1];
              if (ex < d) {
                ex = d;
              }
            }
          }
        }

        return ex;
      }

      void maximum(const ::coder::array<double, 2U> &x, double ex[2])
      {
        int m;
        m = x.size(0);
        for (int j{0}; j < 2; j++) {
          ex[j] = x[x.size(0) * j];
          for (int i{2}; i <= m; i++) {
            double d;
            d = x[(i + x.size(0) * j) - 1];
            if (relop(ex[j], d)) {
              ex[j] = d;
            }
          }
        }
      }

      double maximum(const double x[2])
      {
        double ex;
        if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
          ex = x[1];
        } else {
          ex = x[0];
        }

        return ex;
      }

      void maximum2(const ::coder::array<double, 1U> &x, double y, ::coder::
                    array<double, 1U> &ex)
      {
        int N;
        ex.set_size(x.size(0));
        N = x.size(0);
        for (int k{0}; k < N; k++) {
          if (c_relop(x[k], y)) {
            ex[k] = y;
          } else {
            ex[k] = x[k];
          }
        }
      }

      void maximum2(const ::coder::array<double, 1U> &x, const ::coder::array<
                    double, 1U> &y, ::coder::array<double, 1U> &ex)
      {
        int csz_idx_0;
        if (x.size(0) <= y.size(0)) {
          csz_idx_0 = x.size(0);
        } else {
          csz_idx_0 = y.size(0);
        }

        ex.set_size(csz_idx_0);
        for (int k{0}; k < csz_idx_0; k++) {
          ex[k] = std::fmax(x[k], y[k]);
        }
      }

      void minimum(const ::coder::array<double, 1U> &x, double *ex, int *idx)
      {
        int last;
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
          int k;
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
            int i;
            *ex = x[*idx - 1];
            i = *idx + 1;
            for (k = i; k <= last; k++) {
              double d;
              d = x[k - 1];
              if (*ex > d) {
                *ex = d;
                *idx = k;
              }
            }
          }
        }
      }

      double minimum(const double x[2])
      {
        double ex;
        if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
          ex = x[1];
        } else {
          ex = x[0];
        }

        return ex;
      }

      void minimum(const double x[50], double *ex, int *idx)
      {
        int k;
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
          int i;
          *ex = x[*idx - 1];
          i = *idx + 1;
          for (k = i; k < 51; k++) {
            double d;
            d = x[k - 1];
            if (*ex > d) {
              *ex = d;
              *idx = k;
            }
          }
        }
      }

      void minimum(const ::coder::array<double, 2U> &x, double ex[2])
      {
        int m;
        m = x.size(0);
        for (int j{0}; j < 2; j++) {
          ex[j] = x[x.size(0) * j];
          for (int i{2}; i <= m; i++) {
            double d;
            d = x[(i + x.size(0) * j) - 1];
            if (b_relop(ex[j], d)) {
              ex[j] = d;
            }
          }
        }
      }

      void minimum2(const ::coder::array<double, 1U> &x, double y, ::coder::
                    array<double, 1U> &ex)
      {
        int N;
        ex.set_size(x.size(0));
        N = x.size(0);
        for (int k{0}; k < N; k++) {
          if (d_relop(x[k], y)) {
            ex[k] = y;
          } else {
            ex[k] = x[k];
          }
        }
      }

      void minimum2(const ::coder::array<double, 1U> &y, ::coder::array<double,
                    1U> &ex)
      {
        int N;
        ex.set_size(y.size(0));
        N = y.size(0);
        for (int k{0}; k < N; k++) {
          ex[k] = std::fmin(0.0, y[k]);
        }
      }
    }
  }
}

// End of code generation (minOrMax.cpp)
