//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// nullAssignment.cpp
//
// Code generation for function 'nullAssignment'
//

// Include files
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static void make_bitarray(int n, const ::coder::array<int, 2U> &idx, ::
        coder::array<boolean_T, 2U> &b);
      static int num_true(const ::coder::array<boolean_T, 2U> &b);
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
      static void make_bitarray(int n, const ::coder::array<int, 2U> &idx, ::
        coder::array<boolean_T, 2U> &b)
      {
        int i;
        b.set_size(1, n);
        for (i = 0; i < n; i++) {
          b[i] = false;
        }

        i = idx.size(1);
        for (int k{0}; k < i; k++) {
          b[idx[k] - 1] = true;
        }
      }

      static int num_true(const ::coder::array<boolean_T, 2U> &b)
      {
        int i;
        int n;
        n = 0;
        i = b.size(1);
        for (int k{0}; k < i; k++) {
          n += b[k];
        }

        return n;
      }

      void nullAssignment(::coder::array<double, 2U> &x, const ::coder::array<
                          int, 2U> &idx)
      {
        ::coder::array<boolean_T, 2U> b;
        int k0;
        int nxin;
        int nxout;
        nxin = x.size(1);
        make_bitarray(x.size(1), idx, b);
        nxout = x.size(1) - num_true(b);
        k0 = -1;
        for (int k{0}; k < nxin; k++) {
          if ((k + 1 > b.size(1)) || (!b[k])) {
            k0++;
            x[k0] = x[k];
          }
        }

        if (nxout < 1) {
          nxout = 0;
        }

        x.set_size(x.size(0), nxout);
      }

      void nullAssignment(const ::coder::array<double, 2U> &x, ::coder::array<
                          double, 2U> &b_x)
      {
        ::coder::array<double, 2U> c_x;
        int nrowx;
        c_x.set_size(x.size(0), 4);
        nrowx = x.size(0);
        for (int i{0}; i < 4; i++) {
          for (int b_i{0}; b_i < nrowx; b_i++) {
            c_x[b_i + c_x.size(0) * i] = x[b_i + x.size(0) * i];
          }
        }

        nrowx = x.size(0);
        for (int i{0}; i < nrowx; i++) {
          c_x[i + c_x.size(0) * 2] = c_x[i + c_x.size(0) * 3];
        }

        b_x.set_size(c_x.size(0), 3);
        nrowx = c_x.size(0);
        for (int i{0}; i < 3; i++) {
          for (int b_i{0}; b_i < nrowx; b_i++) {
            b_x[b_i + b_x.size(0) * i] = c_x[b_i + c_x.size(0) * i];
          }
        }
      }

      void nullAssignment(::coder::array<double, 2U> &x, const int idx_data[],
                          const int idx_size[2])
      {
        ::coder::array<int, 2U> b_idx_data;
        ::coder::array<boolean_T, 2U> r;
        int k;
        int ncols;
        int ncolx;
        int nrowx;
        nrowx = x.size(0) - 1;
        ncolx = x.size(1);
        if (idx_size[1] == 1) {
          ncols = x.size(1) - 1;
          k = idx_data[0];
          for (int j{k}; j <= ncols; j++) {
            for (int i{0}; i <= nrowx; i++) {
              x[i + x.size(0) * (j - 1)] = x[i + x.size(0) * j];
            }
          }
        } else {
          int j;
          b_idx_data.set((int *)&idx_data[0], idx_size[0], idx_size[1]);
          make_bitarray(x.size(1), b_idx_data, r);
          ncols = x.size(1) - num_true(r);
          j = 0;
          for (k = 0; k < ncolx; k++) {
            if ((k + 1 > r.size(1)) || (!r[k])) {
              for (int i{0}; i <= nrowx; i++) {
                x[i + x.size(0) * j] = x[i + x.size(0) * k];
              }

              j++;
            }
          }
        }

        if (ncols < 1) {
          ncolx = 0;
        } else {
          ncolx = ncols;
        }

        nrowx = x.size(0);
        for (k = 0; k < ncolx; k++) {
          for (ncols = 0; ncols < nrowx; ncols++) {
            x[ncols + nrowx * k] = x[ncols + x.size(0) * k];
          }
        }

        x.set_size(nrowx, ncolx);
      }

      void nullAssignment(::coder::array<double, 2U> &x)
      {
        int ncols;
        int nrowx;
        nrowx = x.size(0);
        ncols = x.size(1) - 1;
        for (int j{3}; j <= ncols; j++) {
          for (int i{0}; i < nrowx; i++) {
            x[i + x.size(0) * (j - 1)] = x[i + x.size(0) * j];
          }
        }

        if (x.size(1) - 1 < 1) {
          nrowx = 0;
        } else {
          nrowx = x.size(1) - 1;
        }

        ncols = x.size(0);
        for (int j{0}; j < nrowx; j++) {
          for (int i{0}; i < ncols; i++) {
            x[i + ncols * j] = x[i + x.size(0) * j];
          }
        }

        x.set_size(ncols, nrowx);
      }
    }
  }
}

// End of code generation (nullAssignment.cpp)
