//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortIdx.cpp
//
// Code generation for function 'sortIdx'
//

// Include files
#include "sortIdx.h"
#include "mergesort.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static void merge(::coder::array<int, 2U> &idx, ::coder::array<double, 2U>
                        &x, int offset, int np, int nq, ::coder::array<int, 1U>
                        &iwork, ::coder::array<double, 1U> &xwork);
      static void merge(::coder::array<int, 1U> &idx, ::coder::array<double, 1U>
                        &x, int offset, int np, int nq, ::coder::array<int, 1U>
                        &iwork, ::coder::array<double, 1U> &xwork);
      static void merge_block(::coder::array<int, 1U> &idx, ::coder::array<
        double, 1U> &x, int offset, int n, int preSortLevel, ::coder::array<int,
        1U> &iwork, ::coder::array<double, 1U> &xwork);
      static void merge_pow2_block(::coder::array<int, 1U> &idx, ::coder::array<
        double, 1U> &x, int offset);
    }
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static void merge(::coder::array<int, 2U> &idx, ::coder::array<double, 2U>
                        &x, int offset, int np, int nq, ::coder::array<int, 1U>
                        &iwork, ::coder::array<double, 1U> &xwork)
      {
        if (nq != 0) {
          int iout;
          int j;
          int n_tmp;
          int p;
          int q;
          n_tmp = np + nq;
          for (j = 0; j < n_tmp; j++) {
            iout = offset + j;
            iwork[j] = idx[iout];
            xwork[j] = x[iout];
          }

          p = 0;
          q = np;
          iout = offset - 1;
          int exitg1;
          do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
              idx[iout] = iwork[p];
              x[iout] = xwork[p];
              if (p + 1 < np) {
                p++;
              } else {
                exitg1 = 1;
              }
            } else {
              idx[iout] = iwork[q];
              x[iout] = xwork[q];
              if (q + 1 < n_tmp) {
                q++;
              } else {
                q = iout - p;
                for (j = p + 1; j <= np; j++) {
                  iout = q + j;
                  idx[iout] = iwork[j - 1];
                  x[iout] = xwork[j - 1];
                }

                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
      }

      static void merge(::coder::array<int, 1U> &idx, ::coder::array<double, 1U>
                        &x, int offset, int np, int nq, ::coder::array<int, 1U>
                        &iwork, ::coder::array<double, 1U> &xwork)
      {
        if (nq != 0) {
          int iout;
          int j;
          int n_tmp;
          int p;
          int q;
          n_tmp = np + nq;
          for (j = 0; j < n_tmp; j++) {
            iout = offset + j;
            iwork[j] = idx[iout];
            xwork[j] = x[iout];
          }

          p = 0;
          q = np;
          iout = offset - 1;
          int exitg1;
          do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
              idx[iout] = iwork[p];
              x[iout] = xwork[p];
              if (p + 1 < np) {
                p++;
              } else {
                exitg1 = 1;
              }
            } else {
              idx[iout] = iwork[q];
              x[iout] = xwork[q];
              if (q + 1 < n_tmp) {
                q++;
              } else {
                q = iout - p;
                for (j = p + 1; j <= np; j++) {
                  iout = q + j;
                  idx[iout] = iwork[j - 1];
                  x[iout] = xwork[j - 1];
                }

                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
      }

      static void merge_block(::coder::array<int, 1U> &idx, ::coder::array<
        double, 1U> &x, int offset, int n, int preSortLevel, ::coder::array<int,
        1U> &iwork, ::coder::array<double, 1U> &xwork)
      {
        int bLen;
        int nPairs;
        nPairs = n >> preSortLevel;
        bLen = 1 << preSortLevel;
        while (nPairs > 1) {
          int nTail;
          int tailOffset;
          if ((nPairs & 1) != 0) {
            nPairs--;
            tailOffset = bLen * nPairs;
            nTail = n - tailOffset;
            if (nTail > bLen) {
              merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                    xwork);
            }
          }

          tailOffset = bLen << 1;
          nPairs >>= 1;
          for (nTail = 0; nTail < nPairs; nTail++) {
            merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
          }

          bLen = tailOffset;
        }

        if (n > bLen) {
          merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
        }
      }

      static void merge_pow2_block(::coder::array<int, 1U> &idx, ::coder::array<
        double, 1U> &x, int offset)
      {
        double xwork[256];
        int iwork[256];
        for (int b{0}; b < 6; b++) {
          int bLen;
          int bLen2;
          int nPairs;
          bLen = 1 << (b + 2);
          bLen2 = bLen << 1;
          nPairs = 256 >> (b + 3);
          for (int k{0}; k < nPairs; k++) {
            int blockOffset;
            int iout;
            int j;
            int p;
            int q;
            blockOffset = offset + k * bLen2;
            for (j = 0; j < bLen2; j++) {
              iout = blockOffset + j;
              iwork[j] = idx[iout];
              xwork[j] = x[iout];
            }

            p = 0;
            q = bLen;
            iout = blockOffset - 1;
            int exitg1;
            do {
              exitg1 = 0;
              iout++;
              if (xwork[p] <= xwork[q]) {
                idx[iout] = iwork[p];
                x[iout] = xwork[p];
                if (p + 1 < bLen) {
                  p++;
                } else {
                  exitg1 = 1;
                }
              } else {
                idx[iout] = iwork[q];
                x[iout] = xwork[q];
                if (q + 1 < bLen2) {
                  q++;
                } else {
                  iout -= p;
                  for (j = p + 1; j <= bLen; j++) {
                    q = iout + j;
                    idx[q] = iwork[j - 1];
                    x[q] = xwork[j - 1];
                  }

                  exitg1 = 1;
                }
              }
            } while (exitg1 == 0);
          }
        }
      }

      void b_sortIdx(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx)
      {
        ::coder::array<double, 1U> b_x;
        ::coder::array<double, 1U> xwork;
        ::coder::array<int, 1U> b_idx;
        ::coder::array<int, 1U> iwork;
        double x4[4];
        int idx4[4];
        int i;
        int ib;
        signed char perm[4];
        ib = x.size(0);
        idx.set_size(ib);
        for (i = 0; i < ib; i++) {
          idx[i] = 0;
        }

        if (x.size(0) != 0) {
          int i2;
          int i3;
          int i4;
          int k;
          int n;
          int nNaNs;
          int quartetOffset;
          b_idx.set_size(ib);
          for (i = 0; i < ib; i++) {
            b_idx[i] = 0;
          }

          i2 = x.size(0);
          b_x.set_size(i2);
          for (i = 0; i < i2; i++) {
            b_x[i] = x[i];
          }

          i = x.size(0);
          n = x.size(0);
          x4[0] = 0.0;
          idx4[0] = 0;
          x4[1] = 0.0;
          idx4[1] = 0;
          x4[2] = 0.0;
          idx4[2] = 0;
          x4[3] = 0.0;
          idx4[3] = 0;
          iwork.set_size(ib);
          for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
            iwork[quartetOffset] = 0;
          }

          i2 = x.size(0);
          xwork.set_size(i2);
          for (quartetOffset = 0; quartetOffset < i2; quartetOffset++) {
            xwork[quartetOffset] = 0.0;
          }

          nNaNs = 0;
          ib = -1;
          for (k = 0; k < n; k++) {
            if (std::isnan(b_x[k])) {
              i4 = (i - nNaNs) - 1;
              b_idx[i4] = k + 1;
              xwork[i4] = b_x[k];
              nNaNs++;
            } else {
              ib++;
              idx4[ib] = k + 1;
              x4[ib] = b_x[k];
              if (ib + 1 == 4) {
                double d;
                double d1;
                quartetOffset = k - nNaNs;
                if (x4[0] <= x4[1]) {
                  ib = 1;
                  i2 = 2;
                } else {
                  ib = 2;
                  i2 = 1;
                }

                if (x4[2] <= x4[3]) {
                  i3 = 3;
                  i4 = 4;
                } else {
                  i3 = 4;
                  i4 = 3;
                }

                d = x4[ib - 1];
                d1 = x4[i3 - 1];
                if (d <= d1) {
                  d = x4[i2 - 1];
                  if (d <= d1) {
                    perm[0] = static_cast<signed char>(ib);
                    perm[1] = static_cast<signed char>(i2);
                    perm[2] = static_cast<signed char>(i3);
                    perm[3] = static_cast<signed char>(i4);
                  } else if (d <= x4[i4 - 1]) {
                    perm[0] = static_cast<signed char>(ib);
                    perm[1] = static_cast<signed char>(i3);
                    perm[2] = static_cast<signed char>(i2);
                    perm[3] = static_cast<signed char>(i4);
                  } else {
                    perm[0] = static_cast<signed char>(ib);
                    perm[1] = static_cast<signed char>(i3);
                    perm[2] = static_cast<signed char>(i4);
                    perm[3] = static_cast<signed char>(i2);
                  }
                } else {
                  d1 = x4[i4 - 1];
                  if (d <= d1) {
                    if (x4[i2 - 1] <= d1) {
                      perm[0] = static_cast<signed char>(i3);
                      perm[1] = static_cast<signed char>(ib);
                      perm[2] = static_cast<signed char>(i2);
                      perm[3] = static_cast<signed char>(i4);
                    } else {
                      perm[0] = static_cast<signed char>(i3);
                      perm[1] = static_cast<signed char>(ib);
                      perm[2] = static_cast<signed char>(i4);
                      perm[3] = static_cast<signed char>(i2);
                    }
                  } else {
                    perm[0] = static_cast<signed char>(i3);
                    perm[1] = static_cast<signed char>(i4);
                    perm[2] = static_cast<signed char>(ib);
                    perm[3] = static_cast<signed char>(i2);
                  }
                }

                b_idx[quartetOffset - 3] = idx4[perm[0] - 1];
                b_idx[quartetOffset - 2] = idx4[perm[1] - 1];
                b_idx[quartetOffset - 1] = idx4[perm[2] - 1];
                b_idx[quartetOffset] = idx4[perm[3] - 1];
                b_x[quartetOffset - 3] = x4[perm[0] - 1];
                b_x[quartetOffset - 2] = x4[perm[1] - 1];
                b_x[quartetOffset - 1] = x4[perm[2] - 1];
                b_x[quartetOffset] = x4[perm[3] - 1];
                ib = -1;
              }
            }
          }

          i3 = (x.size(0) - nNaNs) - 1;
          if (ib + 1 > 0) {
            perm[1] = 0;
            perm[2] = 0;
            perm[3] = 0;
            if (ib + 1 == 1) {
              perm[0] = 1;
            } else if (ib + 1 == 2) {
              if (x4[0] <= x4[1]) {
                perm[0] = 1;
                perm[1] = 2;
              } else {
                perm[0] = 2;
                perm[1] = 1;
              }
            } else if (x4[0] <= x4[1]) {
              if (x4[1] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 2;
                perm[2] = 3;
              } else if (x4[0] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 3;
                perm[2] = 2;
              } else {
                perm[0] = 3;
                perm[1] = 1;
                perm[2] = 2;
              }
            } else if (x4[0] <= x4[2]) {
              perm[0] = 2;
              perm[1] = 1;
              perm[2] = 3;
            } else if (x4[1] <= x4[2]) {
              perm[0] = 2;
              perm[1] = 3;
              perm[2] = 1;
            } else {
              perm[0] = 3;
              perm[1] = 2;
              perm[2] = 1;
            }

            for (k = 0; k <= ib; k++) {
              i4 = perm[k] - 1;
              i2 = (i3 - ib) + k;
              b_idx[i2] = idx4[i4];
              b_x[i2] = x4[i4];
            }
          }

          i2 = (nNaNs >> 1) + 1;
          for (k = 0; k <= i2 - 2; k++) {
            quartetOffset = (i3 + k) + 1;
            ib = b_idx[quartetOffset];
            i4 = (i - k) - 1;
            b_idx[quartetOffset] = b_idx[i4];
            b_idx[i4] = ib;
            b_x[quartetOffset] = xwork[i4];
            b_x[i4] = xwork[quartetOffset];
          }

          if ((nNaNs & 1) != 0) {
            i2 += i3;
            b_x[i2] = xwork[i2];
          }

          quartetOffset = x.size(0) - nNaNs;
          i2 = 2;
          if (quartetOffset > 1) {
            if (x.size(0) >= 256) {
              ib = quartetOffset >> 8;
              if (ib > 0) {
                for (i2 = 0; i2 < ib; i2++) {
                  merge_pow2_block(b_idx, b_x, i2 << 8);
                }

                i2 = ib << 8;
                ib = quartetOffset - i2;
                if (ib > 0) {
                  merge_block(b_idx, b_x, i2, ib, 2, iwork, xwork);
                }

                i2 = 8;
              }
            }

            merge_block(b_idx, b_x, 0, quartetOffset, i2, iwork, xwork);
          }

          i2 = b_idx.size(0);
          for (i = 0; i < i2; i++) {
            idx[i] = b_idx[i];
          }

          i2 = b_x.size(0);
          for (i = 0; i < i2; i++) {
            x[i] = b_x[i];
          }
        }
      }

      void merge_block(::coder::array<int, 2U> &idx, ::coder::array<double, 2U>
                       &x, int offset, int n, int preSortLevel, ::coder::array<
                       int, 1U> &iwork, ::coder::array<double, 1U> &xwork)
      {
        int bLen;
        int nPairs;
        nPairs = n >> preSortLevel;
        bLen = 1 << preSortLevel;
        while (nPairs > 1) {
          int nTail;
          int tailOffset;
          if ((nPairs & 1) != 0) {
            nPairs--;
            tailOffset = bLen * nPairs;
            nTail = n - tailOffset;
            if (nTail > bLen) {
              merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                    xwork);
            }
          }

          tailOffset = bLen << 1;
          nPairs >>= 1;
          for (nTail = 0; nTail < nPairs; nTail++) {
            merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
          }

          bLen = tailOffset;
        }

        if (n > bLen) {
          merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
        }
      }

      void merge_pow2_block(::coder::array<int, 2U> &idx, ::coder::array<double,
                            2U> &x, int offset)
      {
        double xwork[256];
        int iwork[256];
        for (int b{0}; b < 6; b++) {
          int bLen;
          int bLen2;
          int nPairs;
          bLen = 1 << (b + 2);
          bLen2 = bLen << 1;
          nPairs = 256 >> (b + 3);
          for (int k{0}; k < nPairs; k++) {
            int blockOffset;
            int iout;
            int j;
            int p;
            int q;
            blockOffset = offset + k * bLen2;
            for (j = 0; j < bLen2; j++) {
              iout = blockOffset + j;
              iwork[j] = idx[iout];
              xwork[j] = x[iout];
            }

            p = 0;
            q = bLen;
            iout = blockOffset - 1;
            int exitg1;
            do {
              exitg1 = 0;
              iout++;
              if (xwork[p] <= xwork[q]) {
                idx[iout] = iwork[p];
                x[iout] = xwork[p];
                if (p + 1 < bLen) {
                  p++;
                } else {
                  exitg1 = 1;
                }
              } else {
                idx[iout] = iwork[q];
                x[iout] = xwork[q];
                if (q + 1 < bLen2) {
                  q++;
                } else {
                  iout -= p;
                  for (j = p + 1; j <= bLen; j++) {
                    q = iout + j;
                    idx[q] = iwork[j - 1];
                    x[q] = xwork[j - 1];
                  }

                  exitg1 = 1;
                }
              }
            } while (exitg1 == 0);
          }
        }
      }

      void sortIdx(const ::coder::array<double, 2U> &x, ::coder::array<int, 2U>
                   &idx)
      {
        int loop_ub;
        idx.set_size(1, x.size(1));
        loop_ub = x.size(1);
        for (int i{0}; i < loop_ub; i++) {
          idx[i] = 0;
        }

        if (x.size(1) != 0) {
          b_mergesort(idx, x, x.size(1));
        }
      }

      void sortIdx(const ::coder::array<double, 1U> &x, ::coder::array<int, 1U>
                   &idx)
      {
        ::coder::array<double, 1U> b_x;
        ::coder::array<int, 1U> r;
        int i;
        int loop_ub;
        idx.set_size(x.size(0));
        loop_ub = x.size(0);
        for (i = 0; i < loop_ub; i++) {
          idx[i] = 0;
        }

        loop_ub = x.size(0);
        r.set_size(x.size(0));
        for (i = 0; i < loop_ub; i++) {
          r[i] = 0;
        }

        loop_ub = x.size(0);
        b_x.set_size(x.size(0));
        for (i = 0; i < loop_ub; i++) {
          b_x[i] = x[i];
        }

        b_mergesort(r, b_x, x.size(0));
        loop_ub = r.size(0);
        for (i = 0; i < loop_ub; i++) {
          idx[i] = r[i];
        }
      }

      void sortIdx(const ::coder::array<double, 2U> &x, ::coder::array<int, 1U>
                   &idx)
      {
        int k;
        int n;
        n = x.size(0);
        idx.set_size(x.size(0));
        k = x.size(0);
        for (int i{0}; i < k; i++) {
          idx[i] = 0;
        }

        if (x.size(0) == 0) {
          for (k = 0; k < n; k++) {
            idx[k] = k + 1;
          }
        } else {
          b_mergesort(idx, x, x.size(0));
        }
      }
    }
  }
}

// End of code generation (sortIdx.cpp)
