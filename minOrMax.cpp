//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
    double, 2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    ::coder::array<double, 2U> b_in2;
    int aux_0_1;
    int aux_1_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    if (in3.size(1) == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = in3.size(1);
    }

    b_in2.set_size(loop_ub, b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) *
          aux_0_1] - in3[i1 * stride_1_0 + in3.size(0) * aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    coder::internal::maximum(b_in2, in1);
  }

  namespace coder
  {
    namespace internal
    {
      double b_maximum(const double x[2])
      {
        double ex;
        if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
          ex = x[1];
        } else {
          ex = x[0];
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
          } else {
            ex = x[x.size(0) - 1];
            if ((!(x[0] < ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
              ex = x[0];
            }
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
          } else {
            ex = x[x.size(1) - 1];
            if ((!(x[0] < ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
              ex = x[0];
            }
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

      double maximum(const double x[3])
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

      double minimum(const ::coder::array<double, 1U> &x, int &idx)
      {
        double ex;
        int last;
        last = x.size(0);
        if (x.size(0) <= 2) {
          if (x.size(0) == 1) {
            ex = x[0];
            idx = 1;
          } else {
            ex = x[x.size(0) - 1];
            if ((x[0] > ex) || (std::isnan(x[0]) && (!std::isnan(ex)))) {
              idx = x.size(0);
            } else {
              ex = x[0];
              idx = 1;
            }
          }
        } else {
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
            idx = 1;
          } else {
            int i;
            ex = x[idx - 1];
            i = idx + 1;
            for (k = i; k <= last; k++) {
              double d;
              d = x[k - 1];
              if (ex > d) {
                ex = d;
                idx = k;
              }
            }
          }
        }

        return ex;
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

      double minimum(const double x[50], int &idx)
      {
        double ex;
        int k;
        if (!std::isnan(x[0])) {
          idx = 1;
        } else {
          boolean_T exitg1;
          idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k < 51)) {
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
          idx = 1;
        } else {
          int i;
          ex = x[idx - 1];
          i = idx + 1;
          for (k = i; k < 51; k++) {
            double d;
            d = x[k - 1];
            if (ex > d) {
              ex = d;
              idx = k;
            }
          }
        }

        return ex;
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
    }
  }
}

// End of code generation (minOrMax.cpp)
