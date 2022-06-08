//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// blockedSummation.cpp
//
// Code generation for function 'blockedSummation'
//

// Include files
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Declarations
namespace coder {
static void nestedIter(const ::coder::array<real_T, 2U> &x, int32_T vlen,
                       real_T y[200]);

}

// Function Definitions
//
//
namespace coder {
static void nestedIter(const ::coder::array<real_T, 2U> &x, int32_T vlen,
                       real_T y[200])
{
  real_T bsum[200];
  int32_T b_k;
  int32_T firstBlockLength;
  int32_T k;
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
  for (k = 0; k < 200; k++) {
    y[k] = x[k];
  }
  for (k = 2; k <= firstBlockLength; k++) {
    for (b_k = 0; b_k < 200; b_k++) {
      if (vlen >= 2) {
        y[b_k] += x[b_k + 200 * (k - 1)];
      }
    }
  }
  for (int32_T ib{2}; ib <= nblocks; ib++) {
    int32_T hi;
    firstBlockLength = (ib - 1) << 10;
    for (k = 0; k < 200; k++) {
      bsum[k] = x[k + 200 * firstBlockLength];
    }
    if (ib == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }
    for (k = 2; k <= hi; k++) {
      int32_T varargin_1;
      varargin_1 = firstBlockLength + k;
      for (b_k = 0; b_k < 200; b_k++) {
        if (vlen >= 2) {
          bsum[b_k] += x[b_k + 200 * (varargin_1 - 1)];
        }
      }
    }
    for (k = 0; k < 200; k++) {
      y[k] += bsum[k];
    }
  }
}

//
//
void blockedSummation(const ::coder::array<real_T, 2U> &x, int32_T vlen,
                      real_T y[200])
{
  if ((x.size(1) == 0) || (vlen == 0)) {
    std::memset(&y[0], 0, 200U * sizeof(real_T));
  } else {
    nestedIter(x, vlen, y);
  }
}

} // namespace coder

// End of code generation (blockedSummation.cpp)
