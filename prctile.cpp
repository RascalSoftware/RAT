//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// prctile.cpp
//
// Code generation for function 'prctile'
//

// Include files
#include "prctile.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void b_percentile_vector(const ::coder::array<double, 1U> &x, double
      pct[2]);
    static void percentile_vector(const ::coder::array<double, 1U> &x, double
      pct[2]);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static void b_percentile_vector(const ::coder::array<double, 1U> &x, double
      pct[2])
    {
      ::coder::array<int, 1U> idx;
      if (x.size(0) == 0) {
        pct[0] = rtNaN;
        pct[1] = rtNaN;
      } else {
        int nj;
        internal::sortIdx(x, idx);
        nj = x.size(0);
        while ((nj > 0) && std::isnan(x[idx[nj - 1] - 1])) {
          nj--;
        }

        if (nj < 1) {
          pct[0] = rtNaN;
          pct[1] = rtNaN;
        } else if (nj == 1) {
          double r;
          r = x[idx[0] - 1];
          pct[0] = r;
          pct[1] = r;
        } else {
          double r;
          int i;
          r = 0.175 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i < 1) {
            pct[0] = x[idx[0] - 1];
          } else if (i >= nj) {
            pct[0] = x[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            pct[0] = (0.5 - r) * x[idx[i - 1] - 1] + (r + 0.5) * x[idx[i] - 1];
          }

          r = 0.825 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i >= nj) {
            pct[1] = x[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            pct[1] = (0.5 - r) * x[idx[i - 1] - 1] + (r + 0.5) * x[idx[i] - 1];
          }
        }
      }
    }

    static void percentile_vector(const ::coder::array<double, 1U> &x, double
      pct[2])
    {
      ::coder::array<int, 1U> idx;
      if (x.size(0) == 0) {
        pct[0] = rtNaN;
        pct[1] = rtNaN;
      } else {
        int nj;
        internal::sortIdx(x, idx);
        nj = x.size(0);
        while ((nj > 0) && std::isnan(x[idx[nj - 1] - 1])) {
          nj--;
        }

        if (nj < 1) {
          pct[0] = rtNaN;
          pct[1] = rtNaN;
        } else if (nj == 1) {
          double r;
          r = x[idx[0] - 1];
          pct[0] = r;
          pct[1] = r;
        } else {
          double r;
          int i;
          r = 0.025 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i < 1) {
            pct[0] = x[idx[0] - 1];
          } else if (i >= nj) {
            pct[0] = x[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            pct[0] = (0.5 - r) * x[idx[i - 1] - 1] + (r + 0.5) * x[idx[i] - 1];
          }

          r = 0.975 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i >= nj) {
            pct[1] = x[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            pct[1] = (0.5 - r) * x[idx[i - 1] - 1] + (r + 0.5) * x[idx[i] - 1];
          }
        }
      }
    }

    void b_prctile(const ::coder::array<double, 2U> &x, ::coder::array<double,
                   2U> &y)
    {
      ::coder::array<double, 1U> wk;
      y.set_size(2, x.size(1));
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        int vlen;
        vlen = x.size(1);
        y.set_size(2, x.size(1));
        for (int k{0}; k < vlen; k++) {
          y[2 * k] = rtNaN;
          y[2 * k + 1] = rtNaN;
        }
      } else {
        int ix;
        int npages;
        int vlen;
        vlen = x.size(0);
        wk.set_size(x.size(0));
        npages = x.size(1);
        ix = -1;
        for (int xi{0}; xi < npages; xi++) {
          double pctv[2];
          int k;
          wk[0] = x[ix + 1];
          for (k = 2; k <= vlen; k++) {
            wk[k - 1] = x[ix + k];
          }

          if (vlen < 2) {
            ix++;
          } else {
            ix += vlen;
          }

          b_percentile_vector(wk, pctv);
          k = xi << 1;
          y[k] = pctv[0];
          y[k + 1] = pctv[1];
        }
      }
    }

    void b_prctile(const double x_data[], int x_size, double y[2])
    {
      ::coder::array<double, 1U> b_x_data;
      ::coder::array<int, 1U> idx;
      if (x_size == 0) {
        y[0] = rtNaN;
        y[1] = rtNaN;
      } else {
        int nj;
        b_x_data.set((double *)&x_data[0], x_size);
        internal::sortIdx(b_x_data, idx);
        nj = x_size;
        while ((nj > 0) && std::isnan(x_data[idx[nj - 1] - 1])) {
          nj--;
        }

        if (nj < 1) {
          y[0] = rtNaN;
          y[1] = rtNaN;
        } else if (nj == 1) {
          double r;
          r = x_data[idx[0] - 1];
          y[0] = r;
          y[1] = r;
        } else {
          double r;
          int i;
          r = 0.175 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i < 1) {
            y[0] = x_data[idx[0] - 1];
          } else if (i >= nj) {
            y[0] = x_data[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            y[0] = (0.5 - r) * x_data[idx[i - 1] - 1] + (r + 0.5) * x_data[idx[i]
              - 1];
          }

          r = 0.825 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i >= nj) {
            y[1] = x_data[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            y[1] = (0.5 - r) * x_data[idx[i - 1] - 1] + (r + 0.5) * x_data[idx[i]
              - 1];
          }
        }
      }
    }

    void prctile(const ::coder::array<double, 2U> &x, double y[2])
    {
      ::coder::array<int, 2U> idx;
      if (x.size(1) == 0) {
        y[0] = rtNaN;
        y[1] = rtNaN;
      } else {
        int nj;
        internal::sortIdx(x, idx);
        nj = x.size(1);
        while ((nj > 0) && std::isnan(x[idx[nj - 1] - 1])) {
          nj--;
        }

        if (nj < 1) {
          y[0] = rtNaN;
          y[1] = rtNaN;
        } else if (nj == 1) {
          double r;
          r = x[idx[0] - 1];
          y[0] = r;
          y[1] = r;
        } else {
          double r;
          int i;
          r = 0.75 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i >= nj) {
            y[0] = x[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            y[0] = (0.5 - r) * x[idx[i - 1] - 1] + (r + 0.5) * x[idx[i] - 1];
          }

          r = 0.25 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i >= nj) {
            y[1] = x[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            y[1] = (0.5 - r) * x[idx[i - 1] - 1] + (r + 0.5) * x[idx[i] - 1];
          }
        }
      }
    }

    void prctile(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
                 &y)
    {
      ::coder::array<double, 1U> wk;
      y.set_size(2, x.size(1));
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        int vlen;
        vlen = x.size(1);
        y.set_size(2, x.size(1));
        for (int k{0}; k < vlen; k++) {
          y[2 * k] = rtNaN;
          y[2 * k + 1] = rtNaN;
        }
      } else {
        int ix;
        int npages;
        int vlen;
        vlen = x.size(0);
        wk.set_size(x.size(0));
        npages = x.size(1);
        ix = -1;
        for (int xi{0}; xi < npages; xi++) {
          double pctv[2];
          int k;
          wk[0] = x[ix + 1];
          for (k = 2; k <= vlen; k++) {
            wk[k - 1] = x[ix + k];
          }

          if (vlen < 2) {
            ix++;
          } else {
            ix += vlen;
          }

          percentile_vector(wk, pctv);
          k = xi << 1;
          y[k] = pctv[0];
          y[k + 1] = pctv[1];
        }
      }
    }

    void prctile(const double x_data[], int x_size, double y[2])
    {
      ::coder::array<double, 1U> b_x_data;
      ::coder::array<int, 1U> idx;
      if (x_size == 0) {
        y[0] = rtNaN;
        y[1] = rtNaN;
      } else {
        int nj;
        b_x_data.set((double *)&x_data[0], x_size);
        internal::sortIdx(b_x_data, idx);
        nj = x_size;
        while ((nj > 0) && std::isnan(x_data[idx[nj - 1] - 1])) {
          nj--;
        }

        if (nj < 1) {
          y[0] = rtNaN;
          y[1] = rtNaN;
        } else if (nj == 1) {
          double r;
          r = x_data[idx[0] - 1];
          y[0] = r;
          y[1] = r;
        } else {
          double r;
          int i;
          r = 0.025 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i < 1) {
            y[0] = x_data[idx[0] - 1];
          } else if (i >= nj) {
            y[0] = x_data[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            y[0] = (0.5 - r) * x_data[idx[i - 1] - 1] + (r + 0.5) * x_data[idx[i]
              - 1];
          }

          r = 0.975 * static_cast<double>(nj);
          i = static_cast<int>(std::round(r));
          if (i >= nj) {
            y[1] = x_data[idx[nj - 1] - 1];
          } else {
            r -= static_cast<double>(i);
            y[1] = (0.5 - r) * x_data[idx[i - 1] - 1] + (r + 0.5) * x_data[idx[i]
              - 1];
          }
        }
      }
    }
  }
}

// End of code generation (prctile.cpp)
