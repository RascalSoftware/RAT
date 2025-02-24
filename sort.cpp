//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void b_sort(::coder::array<double, 2U> &x, ::coder::array<int, 2U> &idx)
      {
        ::coder::array<double, 1U> vwork;
        ::coder::array<int, 1U> iidx;
        int dim;
        int i;
        int k;
        int npages;
        int vlen;
        int vstride;
        dim = nonSingletonDim(x) - 1;
        vlen = x.size(dim) - 1;
        vwork.set_size(x.size(dim));
        idx.set_size(x.size(0), x.size(1));
        vstride = 1;
        for (k = 0; k < dim; k++) {
          vstride *= x.size(0);
        }

        npages = 1;
        i = dim + 2;
        for (k = i; k < 3; k++) {
          npages *= x.size(1);
        }

        dim = x.size(dim) * vstride;
        for (int b_i{0}; b_i < npages; b_i++) {
          int pageoffset;
          pageoffset = b_i * dim;
          for (int j{0}; j < vstride; j++) {
            int idx0;
            idx0 = pageoffset + j;
            for (k = 0; k <= vlen; k++) {
              vwork[k] = x[idx0 + k * vstride];
            }

            b_sortIdx(vwork, iidx);
            for (k = 0; k <= vlen; k++) {
              i = idx0 + k * vstride;
              x[i] = vwork[k];
              idx[i] = iidx[k];
            }
          }
        }
      }

      void sort(::coder::array<double, 2U> &x, ::coder::array<int, 2U> &idx)
      {
        ::coder::array<double, 1U> xwork;
        ::coder::array<int, 1U> iwork;
        double x4[4];
        int idx4[4];
        int b_n;
        int i1;
        int i3;
        int i4;
        int ib;
        int k;
        int n;
        int nNaNs;
        int quartetOffset;
        signed char perm[4];
        ib = x.size(1);
        idx.set_size(1, ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
          idx[quartetOffset] = 0;
        }

        n = x.size(1);
        b_n = x.size(1);
        x4[0] = 0.0;
        idx4[0] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        ib = x.size(1);
        iwork.set_size(ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
          iwork[quartetOffset] = 0;
        }

        ib = x.size(1);
        xwork.set_size(ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
          xwork[quartetOffset] = 0.0;
        }

        nNaNs = 0;
        ib = -1;
        for (k = 0; k < b_n; k++) {
          if (std::isnan(x[k])) {
            i3 = (b_n - nNaNs) - 1;
            idx[i3] = k + 1;
            xwork[i3] = x[k];
            nNaNs++;
          } else {
            ib++;
            idx4[ib] = k + 1;
            x4[ib] = x[k];
            if (ib + 1 == 4) {
              double d;
              double d1;
              quartetOffset = k - nNaNs;
              if (x4[0] <= x4[1]) {
                i1 = 1;
                ib = 2;
              } else {
                i1 = 2;
                ib = 1;
              }

              if (x4[2] <= x4[3]) {
                i3 = 3;
                i4 = 4;
              } else {
                i3 = 4;
                i4 = 3;
              }

              d = x4[i1 - 1];
              d1 = x4[i3 - 1];
              if (d <= d1) {
                d = x4[ib - 1];
                if (d <= d1) {
                  perm[0] = static_cast<signed char>(i1);
                  perm[1] = static_cast<signed char>(ib);
                  perm[2] = static_cast<signed char>(i3);
                  perm[3] = static_cast<signed char>(i4);
                } else if (d <= x4[i4 - 1]) {
                  perm[0] = static_cast<signed char>(i1);
                  perm[1] = static_cast<signed char>(i3);
                  perm[2] = static_cast<signed char>(ib);
                  perm[3] = static_cast<signed char>(i4);
                } else {
                  perm[0] = static_cast<signed char>(i1);
                  perm[1] = static_cast<signed char>(i3);
                  perm[2] = static_cast<signed char>(i4);
                  perm[3] = static_cast<signed char>(ib);
                }
              } else {
                d1 = x4[i4 - 1];
                if (d <= d1) {
                  if (x4[ib - 1] <= d1) {
                    perm[0] = static_cast<signed char>(i3);
                    perm[1] = static_cast<signed char>(i1);
                    perm[2] = static_cast<signed char>(ib);
                    perm[3] = static_cast<signed char>(i4);
                  } else {
                    perm[0] = static_cast<signed char>(i3);
                    perm[1] = static_cast<signed char>(i1);
                    perm[2] = static_cast<signed char>(i4);
                    perm[3] = static_cast<signed char>(ib);
                  }
                } else {
                  perm[0] = static_cast<signed char>(i3);
                  perm[1] = static_cast<signed char>(i4);
                  perm[2] = static_cast<signed char>(i1);
                  perm[3] = static_cast<signed char>(ib);
                }
              }

              idx[quartetOffset - 3] = idx4[perm[0] - 1];
              idx[quartetOffset - 2] = idx4[perm[1] - 1];
              idx[quartetOffset - 1] = idx4[perm[2] - 1];
              idx[quartetOffset] = idx4[perm[3] - 1];
              x[quartetOffset - 3] = x4[perm[0] - 1];
              x[quartetOffset - 2] = x4[perm[1] - 1];
              x[quartetOffset - 1] = x4[perm[2] - 1];
              x[quartetOffset] = x4[perm[3] - 1];
              ib = -1;
            }
          }
        }

        i4 = (b_n - nNaNs) - 1;
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
            i3 = perm[k] - 1;
            quartetOffset = (i4 - ib) + k;
            idx[quartetOffset] = idx4[i3];
            x[quartetOffset] = x4[i3];
          }
        }

        ib = (nNaNs >> 1) + 1;
        for (k = 0; k <= ib - 2; k++) {
          quartetOffset = (i4 + k) + 1;
          i1 = idx[quartetOffset];
          i3 = (b_n - k) - 1;
          idx[quartetOffset] = idx[i3];
          idx[i3] = i1;
          x[quartetOffset] = xwork[i3];
          x[i3] = xwork[quartetOffset];
        }

        if ((nNaNs & 1) != 0) {
          quartetOffset = i4 + ib;
          x[quartetOffset] = xwork[quartetOffset];
        }

        i1 = n - nNaNs;
        ib = 2;
        if (i1 > 1) {
          if (n >= 256) {
            quartetOffset = i1 >> 8;
            if (quartetOffset > 0) {
              for (ib = 0; ib < quartetOffset; ib++) {
                merge_pow2_block(idx, x, ib << 8);
              }

              ib = quartetOffset << 8;
              quartetOffset = i1 - ib;
              if (quartetOffset > 0) {
                merge_block(idx, x, ib, quartetOffset, 2, iwork, xwork);
              }

              ib = 8;
            }
          }

          merge_block(idx, x, 0, i1, ib, iwork, xwork);
        }
      }

      void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx)
      {
        ::coder::array<double, 1U> vwork;
        ::coder::array<int, 1U> iidx;
        int dim;
        int i;
        int k;
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
        for (k = 0; k <= dim - 2; k++) {
          vstride *= x.size(0);
        }

        for (dim = 0; dim < vstride; dim++) {
          for (k = 0; k <= vlen; k++) {
            vwork[k] = x[dim + k * vstride];
          }

          b_sortIdx(vwork, iidx);
          for (k = 0; k <= vlen; k++) {
            i = dim + k * vstride;
            x[i] = vwork[k];
            idx[i] = iidx[k];
          }
        }
      }
    }
  }
}

// End of code generation (sort.cpp)
