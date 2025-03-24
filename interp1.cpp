//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// interp1.cpp
//
// Code generation for function 'interp1'
//

// Include files
#include "interp1.h"
#include "bsearch.h"
#include "flip.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void interp1Linear(const ::coder::array<double, 1U> &y, int nyrows,
      const ::coder::array<double, 1U> &xi, ::coder::array<double, 1U> &yi,
      const ::coder::array<double, 1U> &varargin_1);
    static void interp1Linear(const ::coder::array<double, 1U> &y, int nyrows,
      const ::coder::array<double, 2U> &xi, ::coder::array<double, 2U> &yi,
      const ::coder::array<double, 1U> &varargin_1);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static void interp1Linear(const ::coder::array<double, 1U> &y, int nyrows,
      const ::coder::array<double, 1U> &xi, ::coder::array<double, 1U> &yi,
      const ::coder::array<double, 1U> &varargin_1)
    {
      double d;
      double maxx;
      double minx;
      double penx;
      double r;
      int n;
      int ub_loop;
      minx = varargin_1[0];
      penx = varargin_1[varargin_1.size(0) - 2];
      maxx = varargin_1[varargin_1.size(0) - 1];
      ub_loop = xi.size(0) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(d,n,r)

      for (int k = 0; k <= ub_loop; k++) {
        if (std::isnan(xi[k])) {
          yi[k] = rtNaN;
        } else if (xi[k] > maxx) {
          if (nyrows > 1) {
            d = y[nyrows - 1];
            yi[k] = d + (xi[k] - maxx) / (maxx - penx) * (d - y[nyrows - 2]);
          }
        } else if (xi[k] < minx) {
          yi[k] = y[0] + (xi[k] - minx) / (varargin_1[1] - minx) * (y[1] - y[0]);
        } else {
          n = internal::b_bsearch(varargin_1, xi[k]) - 1;
          r = (xi[k] - varargin_1[n]) / (varargin_1[n + 1] - varargin_1[n]);
          if (r == 0.0) {
            yi[k] = y[n];
          } else if (r == 1.0) {
            yi[k] = y[n + 1];
          } else {
            d = y[n + 1];
            if (y[n] == d) {
              yi[k] = y[n];
            } else {
              yi[k] = (1.0 - r) * y[n] + r * d;
            }
          }
        }
      }
    }

    static void interp1Linear(const ::coder::array<double, 1U> &y, int nyrows,
      const ::coder::array<double, 2U> &xi, ::coder::array<double, 2U> &yi,
      const ::coder::array<double, 1U> &varargin_1)
    {
      double d;
      double maxx;
      double minx;
      double penx;
      double r;
      int n;
      int ub_loop;
      minx = varargin_1[0];
      penx = varargin_1[varargin_1.size(0) - 2];
      maxx = varargin_1[varargin_1.size(0) - 1];
      ub_loop = xi.size(1) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(d,r,n)

      for (int k = 0; k <= ub_loop; k++) {
        d = xi[k];
        if (std::isnan(d)) {
          yi[k] = rtNaN;
        } else if (d > maxx) {
          if (nyrows > 1) {
            r = y[nyrows - 1];
            yi[k] = r + (d - maxx) / (maxx - penx) * (r - y[nyrows - 2]);
          }
        } else if (d < minx) {
          yi[k] = y[0] + (d - minx) / (varargin_1[1] - minx) * (y[1] - y[0]);
        } else {
          n = internal::b_bsearch(varargin_1, d) - 1;
          r = (d - varargin_1[n]) / (varargin_1[n + 1] - varargin_1[n]);
          if (r == 0.0) {
            yi[k] = y[n];
          } else if (r == 1.0) {
            yi[k] = y[n + 1];
          } else {
            d = y[n + 1];
            if (y[n] == d) {
              yi[k] = y[n];
            } else {
              yi[k] = (1.0 - r) * y[n] + r * d;
            }
          }
        }
      }
    }

    void interp1(const ::coder::array<double, 1U> &varargin_1, const ::coder::
                 array<double, 1U> &varargin_2, const ::coder::array<double, 1U>
                 &varargin_3, ::coder::array<double, 1U> &Vq)
    {
      ::coder::array<double, 1U> x;
      ::coder::array<double, 1U> y;
      int i;
      int k;
      int nx;
      y.set_size(varargin_2.size(0));
      k = varargin_2.size(0);
      for (i = 0; i < k; i++) {
        y[i] = varargin_2[i];
      }

      x.set_size(varargin_1.size(0));
      k = varargin_1.size(0);
      for (i = 0; i < k; i++) {
        x[i] = varargin_1[i];
      }

      nx = varargin_1.size(0) - 1;
      Vq.set_size(varargin_3.size(0));
      k = varargin_3.size(0);
      for (i = 0; i < k; i++) {
        Vq[i] = 0.0;
      }

      if (varargin_3.size(0) != 0) {
        k = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (k <= nx) {
            if (std::isnan(varargin_1[k])) {
              exitg1 = 1;
            } else {
              k++;
            }
          } else {
            if (varargin_1[1] < varargin_1[0]) {
              i = (nx + 1) >> 1;
              for (int b_j1{0}; b_j1 < i; b_j1++) {
                double xtmp;
                xtmp = x[b_j1];
                k = nx - b_j1;
                x[b_j1] = x[k];
                x[k] = xtmp;
              }

              flip(y);
            }

            interp1Linear(y, varargin_2.size(0), varargin_3, Vq, x);
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }

    void interp1(const ::coder::array<double, 1U> &varargin_1, const ::coder::
                 array<double, 1U> &varargin_2, const ::coder::array<double, 2U>
                 &varargin_3, ::coder::array<double, 2U> &Vq)
    {
      ::coder::array<double, 1U> x;
      ::coder::array<double, 1U> y;
      int i;
      int k;
      int nx;
      boolean_T b;
      y.set_size(varargin_2.size(0));
      k = varargin_2.size(0);
      for (i = 0; i < k; i++) {
        y[i] = varargin_2[i];
      }

      x.set_size(varargin_1.size(0));
      k = varargin_1.size(0);
      for (i = 0; i < k; i++) {
        x[i] = varargin_1[i];
      }

      nx = varargin_1.size(0) - 1;
      Vq.set_size(1, varargin_3.size(1));
      k = varargin_3.size(1);
      for (i = 0; i < k; i++) {
        Vq[i] = 0.0;
      }

      b = (varargin_3.size(1) == 0);
      if (!b) {
        k = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (k <= nx) {
            if (std::isnan(varargin_1[k])) {
              exitg1 = 1;
            } else {
              k++;
            }
          } else {
            if (varargin_1[1] < varargin_1[0]) {
              i = (nx + 1) >> 1;
              for (int b_j1{0}; b_j1 < i; b_j1++) {
                double xtmp;
                xtmp = x[b_j1];
                k = nx - b_j1;
                x[b_j1] = x[k];
                x[k] = xtmp;
              }

              flip(y);
            }

            interp1Linear(y, varargin_2.size(0), varargin_3, Vq, x);
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
  }
}

// End of code generation (interp1.cpp)
