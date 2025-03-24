//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// blockedSummation.cpp
//
// Code generation for function 'blockedSummation'
//

// Include files
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static double b_nestedIter(const ::coder::array<double, 2U> &x, int vlen);
    static void nestedIter(const ::coder::array<double, 2U> &x, int vlen, ::
      coder::array<double, 1U> &y);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static double b_nestedIter(const ::coder::array<double, 2U> &x, int vlen)
    {
      double y;
      int firstBlockLength;
      int lastBlockLength;
      int nblocks;
      if (vlen <= 1024) {
        firstBlockLength = vlen;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = vlen / 1024;
        lastBlockLength = vlen - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      y = x[0];
      for (int k{2}; k <= firstBlockLength; k++) {
        if (vlen >= 2) {
          y += x[k - 1];
        }
      }

      for (int ib{2}; ib <= nblocks; ib++) {
        double bsum;
        int hi;
        firstBlockLength = (ib - 1) << 10;
        bsum = x[firstBlockLength];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int k{2}; k <= hi; k++) {
          if (vlen >= 2) {
            bsum += x[(firstBlockLength + k) - 1];
          }
        }

        y += bsum;
      }

      return y;
    }

    static void nestedIter(const ::coder::array<double, 2U> &x, int vlen, ::
      coder::array<double, 1U> &y)
    {
      ::coder::array<double, 1U> bsum;
      int bsubs_idx_1;
      int firstBlockLength;
      int i;
      int lastBlockLength;
      int nblocks;
      y.set_size(x.size(0));
      bsum.set_size(x.size(0));
      if (vlen <= 1024) {
        firstBlockLength = vlen;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = vlen / 1024;
        lastBlockLength = vlen - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      i = x.size(0);
      for (int k{0}; k < i; k++) {
        y[k] = x[k];
      }

      for (int k{2}; k <= firstBlockLength; k++) {
        i = x.size(0);
        for (int b_k{0}; b_k < i; b_k++) {
          if (vlen >= 2) {
            y[b_k] = y[b_k] + x[b_k + x.size(0) * (k - 1)];
          }
        }
      }

      for (int ib{2}; ib <= nblocks; ib++) {
        int hi;
        firstBlockLength = (ib - 1) << 10;
        i = x.size(0);
        if (x.size(0) - 1 >= 0) {
          bsubs_idx_1 = firstBlockLength + 1;
        }

        for (int k{0}; k < i; k++) {
          bsum[k] = x[k + x.size(0) * (bsubs_idx_1 - 1)];
        }

        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int k{2}; k <= hi; k++) {
          int varargin_1;
          varargin_1 = firstBlockLength + k;
          i = x.size(0);
          for (int b_k{0}; b_k < i; b_k++) {
            if (vlen >= 2) {
              bsum[b_k] = bsum[b_k] + x[b_k + x.size(0) * (varargin_1 - 1)];
            }
          }
        }

        i = y.size(0);
        for (int k{0}; k < i; k++) {
          y[k] = y[k] + bsum[k];
        }
      }
    }

    double blockedSummation(const ::coder::array<double, 2U> &x, int vlen)
    {
      double y;
      if ((x.size(1) == 0) || (vlen == 0)) {
        y = 0.0;
      } else {
        y = b_nestedIter(x, vlen);
      }

      return y;
    }

    void blockedSummation(const ::coder::array<double, 2U> &x, int vlen, ::coder::
                          array<double, 2U> &y)
    {
      if ((x.size(0) == 0) || (x.size(1) == 0) || (vlen == 0)) {
        int loop_ub;
        y.set_size(1, x.size(1));
        loop_ub = x.size(1);
        for (int i{0}; i < loop_ub; i++) {
          y[i] = 0.0;
        }
      } else {
        nestedIter(x, vlen, y);
      }
    }

    void blockedSummation(const ::coder::array<double, 2U> &x, int vlen, ::coder::
                          array<double, 1U> &y)
    {
      if ((x.size(0) == 0) || (x.size(1) == 0) || (vlen == 0)) {
        int loop_ub;
        y.set_size(x.size(0));
        loop_ub = x.size(0);
        for (int i{0}; i < loop_ub; i++) {
          y[i] = 0.0;
        }
      } else {
        nestedIter(x, vlen, y);
      }
    }

    creal_T nestedIter(const ::coder::array<creal_T, 2U> &x, int vlen)
    {
      creal_T y;
      int firstBlockLength;
      int lastBlockLength;
      int nblocks;
      if (vlen <= 1024) {
        firstBlockLength = vlen;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = vlen / 1024;
        lastBlockLength = vlen - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      y = x[0];
      for (int k{2}; k <= firstBlockLength; k++) {
        if (vlen >= 2) {
          y.re += x[k - 1].re;
          y.im += x[k - 1].im;
        }
      }

      for (int ib{2}; ib <= nblocks; ib++) {
        double xk_im;
        double xk_re;
        int hi;
        firstBlockLength = (ib - 1) << 10;
        xk_re = x[firstBlockLength].re;
        xk_im = x[firstBlockLength].im;
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int k{2}; k <= hi; k++) {
          if (vlen >= 2) {
            int xk_re_tmp;
            xk_re_tmp = (firstBlockLength + k) - 1;
            xk_re += x[xk_re_tmp].re;
            xk_im += x[xk_re_tmp].im;
          }
        }

        y.re += xk_re;
        y.im += xk_im;
      }

      return y;
    }

    void nestedIter(const ::coder::array<double, 3U> &x, int vlen, ::coder::
                    array<double, 3U> &y)
    {
      int firstBlockLength;
      int i;
      int i1;
      int lastBlockLength;
      int nblocks;
      y.set_size(1, x.size(1), x.size(2));
      i = x.size(2);
      if (x.size(2) - 1 >= 0) {
        i1 = x.size(1);
        if (x.size(1) - 1 >= 0) {
          if (vlen <= 1024) {
            firstBlockLength = vlen;
            lastBlockLength = 0;
            nblocks = 1;
          } else {
            firstBlockLength = 1024;
            nblocks = vlen / 1024;
            lastBlockLength = vlen - (nblocks << 10);
            if (lastBlockLength > 0) {
              nblocks++;
            } else {
              lastBlockLength = 1024;
            }
          }
        }
      }

      for (int k{0}; k < i; k++) {
        for (int b_k{0}; b_k < i1; b_k++) {
          y[b_k + y.size(1) * k] = x[x.size(0) * b_k + x.size(0) * x.size(1) * k];
          for (int c_k{2}; c_k <= firstBlockLength; c_k++) {
            if (vlen >= 2) {
              y[b_k + y.size(1) * k] = y[b_k + y.size(1) * k] + x[((c_k + x.size
                (0) * b_k) + x.size(0) * x.size(1) * k) - 1];
            }
          }

          for (int ib{2}; ib <= nblocks; ib++) {
            double bsum;
            int hi;
            int offset;
            offset = (ib - 1) << 10;
            bsum = x[(offset + x.size(0) * b_k) + x.size(0) * x.size(1) * k];
            if (ib == nblocks) {
              hi = lastBlockLength;
            } else {
              hi = 1024;
            }

            for (int c_k{2}; c_k <= hi; c_k++) {
              if (vlen >= 2) {
                bsum += x[(((offset + c_k) + x.size(0) * b_k) + x.size(0) *
                           x.size(1) * k) - 1];
              }
            }

            y[b_k + y.size(1) * k] = y[b_k + y.size(1) * k] + bsum;
          }
        }
      }
    }

    void nestedIter(const ::coder::array<double, 2U> &x, int vlen, ::coder::
                    array<double, 2U> &y)
    {
      int firstBlockLength;
      int i;
      int lastBlockLength;
      int nblocks;
      y.set_size(1, x.size(1));
      i = x.size(1);
      if (x.size(1) - 1 >= 0) {
        if (vlen <= 1024) {
          firstBlockLength = vlen;
          lastBlockLength = 0;
          nblocks = 1;
        } else {
          firstBlockLength = 1024;
          nblocks = vlen / 1024;
          lastBlockLength = vlen - (nblocks << 10);
          if (lastBlockLength > 0) {
            nblocks++;
          } else {
            lastBlockLength = 1024;
          }
        }
      }

      for (int k{0}; k < i; k++) {
        y[k] = x[x.size(0) * k];
        for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
          if (vlen >= 2) {
            y[k] = y[k] + x[(b_k + x.size(0) * k) - 1];
          }
        }

        for (int ib{2}; ib <= nblocks; ib++) {
          double bsum;
          int hi;
          int offset;
          offset = (ib - 1) << 10;
          bsum = x[offset + x.size(0) * k];
          if (ib == nblocks) {
            hi = lastBlockLength;
          } else {
            hi = 1024;
          }

          for (int b_k{2}; b_k <= hi; b_k++) {
            if (vlen >= 2) {
              bsum += x[((offset + b_k) + x.size(0) * k) - 1];
            }
          }

          y[k] = y[k] + bsum;
        }
      }
    }

    double nestedIter(const ::coder::array<double, 2U> &x, int vlen)
    {
      double y;
      int firstBlockLength;
      int lastBlockLength;
      int nblocks;
      if (vlen <= 1024) {
        firstBlockLength = vlen;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = vlen / 1024;
        lastBlockLength = vlen - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      y = x[0];
      for (int k{2}; k <= firstBlockLength; k++) {
        if (vlen >= 2) {
          y += x[k - 1];
        }
      }

      for (int ib{2}; ib <= nblocks; ib++) {
        double bsum;
        int hi;
        firstBlockLength = (ib - 1) << 10;
        bsum = x[firstBlockLength];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int k{2}; k <= hi; k++) {
          if (vlen >= 2) {
            bsum += x[(firstBlockLength + k) - 1];
          }
        }

        y += bsum;
      }

      return y;
    }

    double nestedIter(const ::coder::array<double, 1U> &x, int vlen)
    {
      double y;
      int firstBlockLength;
      int lastBlockLength;
      int nblocks;
      if (vlen <= 1024) {
        firstBlockLength = vlen;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = vlen / 1024;
        lastBlockLength = vlen - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      y = x[0];
      for (int k{2}; k <= firstBlockLength; k++) {
        if (vlen >= 2) {
          y += x[k - 1];
        }
      }

      for (int ib{2}; ib <= nblocks; ib++) {
        double bsum;
        int hi;
        firstBlockLength = (ib - 1) << 10;
        bsum = x[firstBlockLength];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int k{2}; k <= hi; k++) {
          if (vlen >= 2) {
            bsum += x[(firstBlockLength + k) - 1];
          }
        }

        y += bsum;
      }

      return y;
    }
  }
}

// End of code generation (blockedSummation.cpp)
