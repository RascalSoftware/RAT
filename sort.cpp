//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sort.cpp
//
// Code generation for function 'sort'
//

// Include files
#include "sort.h"
#include "nonSingletonDim.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void sort(::coder::array<double, 2U> &x, int idx_data[], int idx_size[2])
      {
        ::coder::array<double, 1U> xwork;
        double x4[4];
        int iwork_data[10001];
        int i2;
        int i3;
        int i4;
        int ib;
        int n;
        int nNaNs;
        int quartetOffset;
        short idx4[4];
        ib = x.size(1);
        idx_size[0] = 1;
        idx_size[1] = ib;
        if (ib - 1 >= 0) {
          std::memset(&idx_data[0], 0, static_cast<unsigned int>(ib) * sizeof
                      (int));
        }

        n = x.size(1);
        x4[0] = 0.0;
        idx4[0] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        ib = x.size(1);
        xwork.set_size(x.size(1));
        for (i2 = 0; i2 < ib; i2++) {
          iwork_data[i2] = 0;
          xwork[i2] = 0.0;
        }

        nNaNs = 0;
        ib = 0;
        for (int k{0}; k < n; k++) {
          if (std::isnan(x[k])) {
            i3 = (n - nNaNs) - 1;
            idx_data[i3] = k + 1;
            xwork[i3] = x[k];
            nNaNs++;
          } else {
            ib++;
            idx4[ib - 1] = static_cast<short>(k + 1);
            x4[ib - 1] = x[k];
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

              idx_data[quartetOffset - 3] = idx4[i - 1];
              idx_data[quartetOffset - 2] = idx4[i1 - 1];
              idx_data[quartetOffset - 1] = idx4[b_i2 - 1];
              idx_data[quartetOffset] = idx4[b_i3 - 1];
              x[quartetOffset - 3] = x4[i - 1];
              x[quartetOffset - 2] = x4[i1 - 1];
              x[quartetOffset - 1] = x4[b_i2 - 1];
              x[quartetOffset] = x4[b_i3 - 1];
              ib = 0;
            }
          }
        }

        i4 = x.size(1) - nNaNs;
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
            idx_data[quartetOffset] = idx4[i3];
            x[quartetOffset] = x4[i3];
          }
        }

        ib = nNaNs >> 1;
        for (int k{0}; k < ib; k++) {
          quartetOffset = i4 + k;
          i2 = idx_data[quartetOffset];
          i3 = (n - k) - 1;
          idx_data[quartetOffset] = idx_data[i3];
          idx_data[i3] = i2;
          x[quartetOffset] = xwork[i3];
          x[i3] = xwork[quartetOffset];
        }

        if ((nNaNs & 1) != 0) {
          i2 = i4 + ib;
          x[i2] = xwork[i2];
        }

        ib = 2;
        if (i4 > 1) {
          if (x.size(1) >= 256) {
            quartetOffset = i4 >> 8;
            if (quartetOffset > 0) {
              for (ib = 0; ib < quartetOffset; ib++) {
                merge_pow2_block(idx_data, x, ib << 8);
              }

              ib = quartetOffset << 8;
              quartetOffset = i4 - ib;
              if (quartetOffset > 0) {
                merge_block(idx_data, x, ib, quartetOffset, 2, iwork_data, xwork);
              }

              ib = 8;
            }
          }

          merge_block(idx_data, x, 0, i4, ib, iwork_data, xwork);
        }
      }

      void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx)
      {
        ::coder::array<double, 1U> vwork;
        ::coder::array<int, 1U> iidx;
        int dim;
        int i;
        int vlen;
        int vstride;
        dim = nonSingletonDim(x);
        if (dim <= 1) {
          i = x.size(0);
        } else {
          i = 1;
        }

        vlen = i - 1;
        vwork.set_size(i);
        idx.set_size(x.size(0));
        vstride = 1;
        i = static_cast<unsigned char>(dim - 1);
        for (dim = 0; dim < i; dim++) {
          vstride *= x.size(0);
        }

        for (int j{0}; j < vstride; j++) {
          for (dim = 0; dim <= vlen; dim++) {
            vwork[dim] = x[j + dim * vstride];
          }

          b_sortIdx(vwork, iidx);
          for (dim = 0; dim <= vlen; dim++) {
            i = j + dim * vstride;
            x[i] = vwork[dim];
            idx[i] = iidx[dim];
          }
        }
      }

      void sort(::coder::array<double, 2U> &x, ::coder::array<int, 2U> &idx)
      {
        ::coder::array<double, 1U> vwork;
        ::coder::array<int, 1U> iidx;
        int dim;
        int i;
        int lowerDim;
        int npages;
        int vlen;
        int vstride;
        dim = nonSingletonDim(x) - 1;
        vlen = x.size(dim) - 1;
        vwork.set_size(x.size(dim));
        idx.set_size(x.size(0), x.size(1));
        vstride = 1;
        i = static_cast<unsigned char>(dim);
        for (int k{0}; k < i; k++) {
          vstride *= x.size(0);
        }

        npages = 1;
        lowerDim = dim + 2;
        for (int k{lowerDim}; k < 3; k++) {
          npages *= x.size(1);
        }

        lowerDim = x.size(dim) * vstride;
        for (int b_i{0}; b_i < npages; b_i++) {
          dim = b_i * lowerDim;
          for (int j{0}; j < vstride; j++) {
            int idx0;
            idx0 = dim + j;
            for (int k{0}; k <= vlen; k++) {
              vwork[k] = x[idx0 + k * vstride];
            }

            b_sortIdx(vwork, iidx);
            for (int k{0}; k <= vlen; k++) {
              i = idx0 + k * vstride;
              x[i] = vwork[k];
              idx[i] = iidx[k];
            }
          }
        }
      }
    }
  }
}

// End of code generation (sort.cpp)
