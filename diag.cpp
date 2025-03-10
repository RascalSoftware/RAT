//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// diag.cpp
//
// Code generation for function 'diag'
//

// Include files
#include "diag.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static int calclen(const ::coder::array<creal_T, 2U> &A, int &i, int &j);
    static int calclen(const ::coder::array<double, 2U> &A, int &i, int &j);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static int calclen(const ::coder::array<creal_T, 2U> &A, int &i, int &j)
    {
      int dlen;
      if (A.size(1) > 0) {
        int u0;
        u0 = A.size(0);
        dlen = A.size(1);
        if (u0 <= dlen) {
          dlen = u0;
        }

        i = 1;
        j = 1;
      } else {
        dlen = 0;
        i = 1;
        j = 1;
      }

      return dlen;
    }

    static int calclen(const ::coder::array<double, 2U> &A, int &i, int &j)
    {
      int dlen;
      if (A.size(1) > 0) {
        int u0;
        u0 = A.size(0);
        dlen = A.size(1);
        if (u0 <= dlen) {
          dlen = u0;
        }

        i = 1;
        j = 1;
      } else {
        dlen = 0;
        i = 1;
        j = 1;
      }

      return dlen;
    }

    void diag(const ::coder::array<creal_T, 2U> &v, ::coder::array<creal_T, 1U>
              &d)
    {
      int j;
      int k;
      if ((v.size(0) == 1) && (v.size(1) == 1)) {
        d.set_size(1);
        d[0] = v[0];
      } else {
        int dlen;
        dlen = calclen(v, k, j);
        d.set_size(dlen);
        dlen--;
        for (k = 0; k <= dlen; k++) {
          d[k] = v[k + v.size(0) * k];
        }
      }
    }

    void diag(const ::coder::array<double, 1U> &v, ::coder::array<double, 2U> &d)
    {
      int j;
      int nv;
      nv = v.size(0);
      d.set_size(v.size(0), v.size(0));
      j = v.size(0);
      for (int i{0}; i < j; i++) {
        int loop_ub;
        loop_ub = v.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          d[i1 + d.size(0) * i] = 0.0;
        }
      }

      for (j = 0; j < nv; j++) {
        d[j + d.size(0) * j] = v[j];
      }
    }

    void diag(const ::coder::array<double, 2U> &v, ::coder::array<double, 1U> &d)
    {
      int j;
      int k;
      if ((v.size(0) == 1) && (v.size(1) == 1)) {
        d.set_size(1);
        d[0] = v[0];
      } else {
        int dlen;
        dlen = calclen(v, k, j);
        d.set_size(dlen);
        dlen--;
        for (k = 0; k <= dlen; k++) {
          d[k] = v[k + v.size(0) * k];
        }
      }
    }
  }
}

// End of code generation (diag.cpp)
