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

// Function Declarations
namespace coder {
static void colMajorFlatIter(const ::coder::array<double, 2U> &x, int vlen,
                             ::coder::array<double, 1U> &y);

static double colMajorFlatIter(const ::coder::array<double, 1U> &x, int vlen);

} // namespace coder

// Function Definitions
namespace coder {
static void colMajorFlatIter(const ::coder::array<double, 2U> &x, int vlen,
                             ::coder::array<double, 1U> &y)
{
  array<double, 1U> bsum;
  int bvstride;
  int firstBlockLength;
  int k;
  int lastBlockLength;
  int nblocks;
  int vstride;
  int xj;
  int xoffset;
  vstride = x.size(0) - 1;
  bvstride = x.size(0) << 10;
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
  for (xj = 0; xj <= vstride; xj++) {
    y[xj] = x[xj];
    bsum[xj] = 0.0;
  }
  for (k = 2; k <= firstBlockLength; k++) {
    xoffset = (k - 1) * (vstride + 1);
    for (xj = 0; xj <= vstride; xj++) {
      y[xj] = y[xj] + x[xoffset + xj];
    }
  }
  for (int ib{2}; ib <= nblocks; ib++) {
    int hi;
    firstBlockLength = (ib - 1) * bvstride;
    for (xj = 0; xj <= vstride; xj++) {
      bsum[xj] = x[firstBlockLength + xj];
    }
    if (ib == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }
    for (k = 2; k <= hi; k++) {
      xoffset = firstBlockLength + (k - 1) * (vstride + 1);
      for (xj = 0; xj <= vstride; xj++) {
        bsum[xj] = bsum[xj] + x[xoffset + xj];
      }
    }
    for (xj = 0; xj <= vstride; xj++) {
      y[xj] = y[xj] + bsum[xj];
    }
  }
}

static double colMajorFlatIter(const ::coder::array<double, 1U> &x, int vlen)
{
  double y;
  int firstBlockLength;
  int k;
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
  for (k = 2; k <= firstBlockLength; k++) {
    y += x[k - 1];
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
    for (k = 2; k <= hi; k++) {
      bsum += x[(firstBlockLength + k) - 1];
    }
    y += bsum;
  }
  return y;
}

void blockedSummation(const ::coder::array<double, 2U> &x, int vlen,
                      ::coder::array<double, 1U> &y)
{
  if ((x.size(0) == 0) || (x.size(1) == 0) || (vlen == 0)) {
    int loop_ub;
    y.set_size(x.size(0));
    loop_ub = x.size(0);
    for (int i{0}; i < loop_ub; i++) {
      y[i] = 0.0;
    }
  } else {
    colMajorFlatIter(x, vlen, y);
  }
}

double blockedSummation(const ::coder::array<double, 1U> &x, int vlen)
{
  double y;
  if ((x.size(0) == 0) || (vlen == 0)) {
    y = 0.0;
  } else {
    y = colMajorFlatIter(x, vlen);
  }
  return y;
}

} // namespace coder

// End of code generation (blockedSummation.cpp)
