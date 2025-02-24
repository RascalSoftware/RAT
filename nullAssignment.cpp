//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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

        if (1 > nxout) {
          nxout = 0;
        }

        x.set_size(x.size(0), nxout);
      }
    }
  }
}

// End of code generation (nullAssignment.cpp)
