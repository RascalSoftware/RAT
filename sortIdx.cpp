//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      static void merge(int idx_data[], ::coder::array<double, 2U> &x, int
                        offset, int np, int nq, int iwork_data[], ::coder::array<
                        double, 1U> &xwork);
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
      static void merge(int idx_data[], ::coder::array<double, 2U> &x, int
                        offset, int np, int nq, int iwork_data[], ::coder::array<
                        double, 1U> &xwork)
      {
        if (nq != 0) {
          int iout;
          int n_tmp;
          int p;
          int q;
          n_tmp = np + nq;
          for (int j{0}; j < n_tmp; j++) {
            iout = offset + j;
            iwork_data[j] = idx_data[iout];
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
              idx_data[iout] = iwork_data[p];
              x[iout] = xwork[p];
              if (p + 1 < np) {
                p++;
              } else {
                exitg1 = 1;
              }
            } else {
              idx_data[iout] = iwork_data[q];
              x[iout] = xwork[q];
              if (q + 1 < n_tmp) {
                q++;
              } else {
                q = iout - p;
                for (int j{p + 1}; j <= np; j++) {
                  iout = q + j;
                  idx_data[iout] = iwork_data[j - 1];
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
          int n_tmp;
          int p;
          int q;
          n_tmp = np + nq;
          for (int j{0}; j < n_tmp; j++) {
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
                for (int j{p + 1}; j <= np; j++) {
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
          int i;
          bLen = 1 << (b + 2);
          bLen2 = bLen << 1;
          i = 256 >> (b + 3);
          for (int k{0}; k < i; k++) {
            int blockOffset;
            int iout;
            int p;
            int q;
            blockOffset = offset + k * bLen2;
            for (int j{0}; j < bLen2; j++) {
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
                  for (int j{p + 1}; j <= bLen; j++) {
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
        int i2;
        int loop_ub_tmp;
        unsigned int unnamed_idx_0;
        unnamed_idx_0 = static_cast<unsigned int>(x.size(0));
        idx.set_size(static_cast<int>(unnamed_idx_0));
        loop_ub_tmp = static_cast<int>(unnamed_idx_0);
        for (i2 = 0; i2 < loop_ub_tmp; i2++) {
          idx[i2] = 0;
        }

        if (x.size(0) != 0) {
          double x4[4];
          int idx4[4];
          int i3;
          int i4;
          int ib;
          int n;
          int nNaNs;
          int quartetOffset;
          b_idx.set_size(static_cast<int>(unnamed_idx_0));
          for (i2 = 0; i2 < loop_ub_tmp; i2++) {
            b_idx[i2] = 0;
          }

          b_x.set_size(x.size(0));
          ib = x.size(0);
          for (i2 = 0; i2 < ib; i2++) {
            b_x[i2] = x[i2];
          }

          n = x.size(0);
          x4[0] = 0.0;
          idx4[0] = 0;
          x4[1] = 0.0;
          idx4[1] = 0;
          x4[2] = 0.0;
          idx4[2] = 0;
          x4[3] = 0.0;
          idx4[3] = 0;
          iwork.set_size(static_cast<int>(unnamed_idx_0));
          for (i2 = 0; i2 < loop_ub_tmp; i2++) {
            iwork[i2] = 0;
          }

          ib = x.size(0);
          xwork.set_size(ib);
          for (i2 = 0; i2 < ib; i2++) {
            xwork[i2] = 0.0;
          }

          nNaNs = 0;
          ib = 0;
          for (int k{0}; k < n; k++) {
            if (std::isnan(b_x[k])) {
              i3 = (n - nNaNs) - 1;
              b_idx[i3] = k + 1;
              xwork[i3] = b_x[k];
              nNaNs++;
            } else {
              ib++;
              idx4[ib - 1] = k + 1;
              x4[ib - 1] = b_x[k];
              if (ib == 4) {
                double d;
                double d1;
                signed char b_i2;
                signed char b_i3;
                signed char i;
                signed char i1;
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

                d = x4[i3 - 1];
                d1 = x4[ib - 1];
                if (d1 <= d) {
                  d1 = x4[i2 - 1];
                  if (d1 <= d) {
                    i = static_cast<signed char>(ib);
                    i1 = static_cast<signed char>(i2);
                    b_i2 = static_cast<signed char>(i3);
                    b_i3 = static_cast<signed char>(i4);
                  } else if (d1 <= x4[i4 - 1]) {
                    i = static_cast<signed char>(ib);
                    i1 = static_cast<signed char>(i3);
                    b_i2 = static_cast<signed char>(i2);
                    b_i3 = static_cast<signed char>(i4);
                  } else {
                    i = static_cast<signed char>(ib);
                    i1 = static_cast<signed char>(i3);
                    b_i2 = static_cast<signed char>(i4);
                    b_i3 = static_cast<signed char>(i2);
                  }
                } else {
                  d = x4[i4 - 1];
                  if (d1 <= d) {
                    if (x4[i2 - 1] <= d) {
                      i = static_cast<signed char>(i3);
                      i1 = static_cast<signed char>(ib);
                      b_i2 = static_cast<signed char>(i2);
                      b_i3 = static_cast<signed char>(i4);
                    } else {
                      i = static_cast<signed char>(i3);
                      i1 = static_cast<signed char>(ib);
                      b_i2 = static_cast<signed char>(i4);
                      b_i3 = static_cast<signed char>(i2);
                    }
                  } else {
                    i = static_cast<signed char>(i3);
                    i1 = static_cast<signed char>(i4);
                    b_i2 = static_cast<signed char>(ib);
                    b_i3 = static_cast<signed char>(i2);
                  }
                }

                b_idx[quartetOffset - 3] = idx4[i - 1];
                b_idx[quartetOffset - 2] = idx4[i1 - 1];
                b_idx[quartetOffset - 1] = idx4[b_i2 - 1];
                b_idx[quartetOffset] = idx4[b_i3 - 1];
                b_x[quartetOffset - 3] = x4[i - 1];
                b_x[quartetOffset - 2] = x4[i1 - 1];
                b_x[quartetOffset - 1] = x4[b_i2 - 1];
                b_x[quartetOffset] = x4[b_i3 - 1];
                ib = 0;
              }
            }
          }

          i4 = b_x.size(0) - nNaNs;
          if (ib > 0) {
            signed char perm[4];
            perm[1] = 0;
            perm[2] = 0;
            perm[3] = 0;
            if (ib == 1) {
              perm[0] = 1;
            } else if (ib == 2) {
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

            i2 = static_cast<unsigned char>(ib);
            for (int k{0}; k < i2; k++) {
              i3 = perm[k] - 1;
              quartetOffset = (i4 - ib) + k;
              b_idx[quartetOffset] = idx4[i3];
              b_x[quartetOffset] = x4[i3];
            }
          }

          ib = nNaNs >> 1;
          for (int k{0}; k < ib; k++) {
            quartetOffset = i4 + k;
            i2 = b_idx[quartetOffset];
            i3 = (n - k) - 1;
            b_idx[quartetOffset] = b_idx[i3];
            b_idx[i3] = i2;
            b_x[quartetOffset] = xwork[i3];
            b_x[i3] = xwork[quartetOffset];
          }

          if ((nNaNs & 1) != 0) {
            ib += i4;
            b_x[ib] = xwork[ib];
          }

          ib = 2;
          if (i4 > 1) {
            if (b_x.size(0) >= 256) {
              quartetOffset = i4 >> 8;
              if (quartetOffset > 0) {
                for (ib = 0; ib < quartetOffset; ib++) {
                  merge_pow2_block(b_idx, b_x, ib << 8);
                }

                ib = quartetOffset << 8;
                quartetOffset = i4 - ib;
                if (quartetOffset > 0) {
                  merge_block(b_idx, b_x, ib, quartetOffset, 2, iwork, xwork);
                }

                ib = 8;
              }
            }

            merge_block(b_idx, b_x, 0, i4, ib, iwork, xwork);
          }

          for (i2 = 0; i2 < loop_ub_tmp; i2++) {
            idx[i2] = b_idx[i2];
          }

          ib = x.size(0);
          for (i2 = 0; i2 < ib; i2++) {
            x[i2] = b_x[i2];
          }
        }
      }

      void merge_block(int idx_data[], ::coder::array<double, 2U> &x, int offset,
                       int n, int preSortLevel, int iwork_data[], ::coder::array<
                       double, 1U> &xwork)
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
              merge(idx_data, x, offset + tailOffset, bLen, nTail - bLen,
                    iwork_data, xwork);
            }
          }

          tailOffset = bLen << 1;
          nPairs >>= 1;
          for (nTail = 0; nTail < nPairs; nTail++) {
            merge(idx_data, x, offset + nTail * tailOffset, bLen, bLen,
                  iwork_data, xwork);
          }

          bLen = tailOffset;
        }

        if (n > bLen) {
          merge(idx_data, x, offset, bLen, n - bLen, iwork_data, xwork);
        }
      }

      void merge_pow2_block(int idx_data[], ::coder::array<double, 2U> &x, int
                            offset)
      {
        double xwork[256];
        int iwork[256];
        for (int b{0}; b < 6; b++) {
          int bLen;
          int bLen2;
          int i;
          bLen = 1 << (b + 2);
          bLen2 = bLen << 1;
          i = 256 >> (b + 3);
          for (int k{0}; k < i; k++) {
            int blockOffset;
            int iout;
            int p;
            int q;
            blockOffset = offset + k * bLen2;
            for (int j{0}; j < bLen2; j++) {
              iout = blockOffset + j;
              iwork[j] = idx_data[iout];
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
                idx_data[iout] = iwork[p];
                x[iout] = xwork[p];
                if (p + 1 < bLen) {
                  p++;
                } else {
                  exitg1 = 1;
                }
              } else {
                idx_data[iout] = iwork[q];
                x[iout] = xwork[q];
                if (q + 1 < bLen2) {
                  q++;
                } else {
                  iout -= p;
                  for (int j{p + 1}; j <= bLen; j++) {
                    q = iout + j;
                    idx_data[q] = iwork[j - 1];
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

      void sortIdx(const ::coder::array<double, 1U> &x, ::coder::array<int, 1U>
                   &idx)
      {
        ::coder::array<double, 1U> b_x;
        ::coder::array<int, 1U> r;
        int loop_ub;
        idx.set_size(x.size(0));
        loop_ub = x.size(0);
        for (int i{0}; i < loop_ub; i++) {
          idx[i] = 0;
        }

        loop_ub = x.size(0);
        r.set_size(x.size(0));
        for (int i{0}; i < loop_ub; i++) {
          r[i] = 0;
        }

        b_x.set_size(x.size(0));
        loop_ub = x.size(0);
        for (int i{0}; i < loop_ub; i++) {
          b_x[i] = x[i];
        }

        b_mergesort(r, b_x, x.size(0));
        loop_ub = x.size(0);
        for (int i{0}; i < loop_ub; i++) {
          idx[i] = r[i];
        }
      }
    }
  }
}

// End of code generation (sortIdx.cpp)
