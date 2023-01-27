//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: blockedSummation.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void nestedIter(const ::coder::array<real_T, 2U> &x, int32_T vlen, ::
      coder::array<real_T, 1U> &y);
  }
}

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &x
//                int32_T vlen
//                ::coder::array<real_T, 1U> &y
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    static void nestedIter(const ::coder::array<real_T, 2U> &x, int32_T vlen, ::
      coder::array<real_T, 1U> &y)
    {
      ::coder::array<real_T, 1U> bsum;
      int32_T bsubs_idx_1;
      int32_T firstBlockLength;
      int32_T i;
      int32_T lastBlockLength;
      int32_T nblocks;
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
      for (int32_T k{0}; k < i; k++) {
        y[k] = x[k];
      }

      for (int32_T k{2}; k <= firstBlockLength; k++) {
        i = x.size(0);
        for (int32_T b_k{0}; b_k < i; b_k++) {
          if (vlen >= 2) {
            y[b_k] = y[b_k] + x[b_k + x.size(0) * (k - 1)];
          }
        }
      }

      for (int32_T ib{2}; ib <= nblocks; ib++) {
        int32_T hi;
        firstBlockLength = (ib - 1) << 10;
        i = x.size(0);
        if (x.size(0) - 1 >= 0) {
          bsubs_idx_1 = firstBlockLength + 1;
        }

        for (int32_T k{0}; k < i; k++) {
          bsum[k] = x[k + x.size(0) * (bsubs_idx_1 - 1)];
        }

        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int32_T k{2}; k <= hi; k++) {
          int32_T varargin_1;
          varargin_1 = firstBlockLength + k;
          i = x.size(0);
          for (int32_T b_k{0}; b_k < i; b_k++) {
            if (vlen >= 2) {
              bsum[b_k] = bsum[b_k] + x[b_k + x.size(0) * (varargin_1 - 1)];
            }
          }
        }

        i = y.size(0);
        for (int32_T k{0}; k < i; k++) {
          y[k] = y[k] + bsum[k];
        }
      }
    }

    //
    // Arguments    : const ::coder::array<real_T, 2U> &x
    //                int32_T vlen
    //                ::coder::array<real_T, 1U> &y
    // Return Type  : void
    //
    void blockedSummation(const ::coder::array<real_T, 2U> &x, int32_T vlen, ::
                          coder::array<real_T, 1U> &y)
    {
      if ((x.size(0) == 0) || (x.size(1) == 0) || (vlen == 0)) {
        int32_T loop_ub;
        y.set_size(x.size(0));
        loop_ub = x.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          y[i] = 0.0;
        }
      } else {
        nestedIter(x, vlen, y);
      }
    }

    //
    // Arguments    : const ::coder::array<real_T, 1U> &x
    //                int32_T vlen
    // Return Type  : real_T
    //
    real_T nestedIter(const ::coder::array<real_T, 1U> &x, int32_T vlen)
    {
      real_T y;
      int32_T firstBlockLength;
      int32_T lastBlockLength;
      int32_T nblocks;
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
      for (int32_T k{2}; k <= firstBlockLength; k++) {
        if (vlen >= 2) {
          y += x[k - 1];
        }
      }

      for (int32_T ib{2}; ib <= nblocks; ib++) {
        real_T bsum;
        int32_T hi;
        firstBlockLength = (ib - 1) << 10;
        bsum = x[firstBlockLength];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (int32_T k{2}; k <= hi; k++) {
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

//
// File trailer for blockedSummation.cpp
//
// [EOF]
//
