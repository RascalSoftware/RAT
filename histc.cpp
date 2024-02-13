//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// histc.cpp
//
// Code generation for function 'histc'
//

// Include files
#include "histc.h"
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static int32_T b_findbin(real_T x, const real_T bin_edges[3]);
    static int32_T findbin(real_T x, const real_T bin_edges_data[]);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static int32_T b_findbin(real_T x, const real_T bin_edges[3])
    {
      int32_T k;
      k = 0;
      if (!std::isnan(x)) {
        k = internal::c_bsearch(bin_edges, x);
      }

      return k;
    }

    static int32_T findbin(real_T x, const real_T bin_edges_data[])
    {
      int32_T k;
      k = 0;
      if (!std::isnan(x)) {
        if ((x >= bin_edges_data[0]) && (x < bin_edges_data[3])) {
          k = internal::b_bsearch(bin_edges_data, x);
        }

        if (x == bin_edges_data[3]) {
          k = 4;
        }
      }

      return k;
    }

    void histc(const ::coder::array<real_T, 1U> &X, const real_T edges[3],
               real_T N[3], ::coder::array<real_T, 1U> &BIN)
    {
      int32_T bin;
      int32_T i;
      N[0] = 0.0;
      N[1] = 0.0;
      N[2] = 0.0;
      BIN.set_size(X.size(0));
      bin = X.size(0);
      for (i = 0; i < bin; i++) {
        BIN[i] = 0.0;
      }

      i = X.size(0);
      for (int32_T k{0}; k < i; k++) {
        bin = b_findbin(X[k], edges);
        if (bin > 0) {
          N[bin - 1]++;
        }

        BIN[k] = bin;
      }
    }

    void histc(const ::coder::array<real_T, 1U> &X, const real_T edges_data[],
               real_T N_data[], int32_T *N_size, ::coder::array<real_T, 1U> &BIN)
    {
      int32_T bin;
      int32_T i;
      *N_size = 4;
      N_data[0] = 0.0;
      N_data[1] = 0.0;
      N_data[2] = 0.0;
      N_data[3] = 0.0;
      BIN.set_size(X.size(0));
      bin = X.size(0);
      for (i = 0; i < bin; i++) {
        BIN[i] = 0.0;
      }

      i = X.size(0);
      for (int32_T k{0}; k < i; k++) {
        bin = findbin(X[k], edges_data);
        if (bin > 0) {
          N_data[bin - 1]++;
        }

        BIN[k] = bin;
      }
    }
  }
}

// End of code generation (histc.cpp)
