//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// randsample.cpp
//
// Code generation for function 'randsample'
//

// Include files
#include "randsample.h"
#include "blockedSummation.h"
#include "histc.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void randsample(real_T varargin_2, const real_T varargin_4[2], ::coder::
                    array<real_T, 2U> &y)
    {
      ::coder::array<real_T, 1U> idx;
      ::coder::array<real_T, 1U> r;
      real_T a__1[3];
      real_T edges[3];
      real_T x;
      x = std::floor(varargin_2);
      edges[0] = 0.0;
      edges[2] = 1.0;
      edges[1] = std::fmin(varargin_4[0] / (varargin_4[0] + varargin_4[1]), 1.0);
      y.set_size(1, static_cast<int32_T>(x));
      if (static_cast<int32_T>(x) > 0) {
        int32_T y_idx_1;
        b_rand(static_cast<int32_T>(x), r);
        histc(r, edges, a__1, idx);
        y_idx_1 = static_cast<int32_T>(x);
        y.set_size(1, static_cast<int32_T>(x));
        for (int32_T i{0}; i < y_idx_1; i++) {
          y[i] = static_cast<int8_T>(static_cast<int32_T>(idx[i]) - 1);
        }
      }
    }

    void randsample(const real_T varargin_1_data[], real_T varargin_2, const
                    real_T varargin_4_data[], ::coder::array<real_T, 2U> &y)
    {
      ::coder::array<real_T, 1U> b_varargin_4_data;
      ::coder::array<real_T, 1U> idx;
      ::coder::array<real_T, 1U> r;
      real_T a__1_data[4];
      real_T edges_data[4];
      real_T sumw;
      real_T x;
      int32_T a__1_size;
      x = std::floor(varargin_2);
      b_varargin_4_data.set((real_T *)&varargin_4_data[0], 3);
      if (b_varargin_4_data.size(0) == 0) {
        sumw = 0.0;
      } else {
        sumw = nestedIter(b_varargin_4_data, b_varargin_4_data.size(0));
      }

      edges_data[0] = 0.0;
      edges_data[3] = 1.0;
      edges_data[1] = std::fmin(varargin_4_data[0] / sumw, 1.0);
      edges_data[2] = std::fmin(edges_data[1] + varargin_4_data[1] / sumw, 1.0);
      y.set_size(1, static_cast<int32_T>(x));
      if (static_cast<int32_T>(x) > 0) {
        b_rand(static_cast<int32_T>(x), r);
        histc(r, edges_data, a__1_data, &a__1_size, idx);
        a__1_size = static_cast<int32_T>(x);
        y.set_size(1, static_cast<int32_T>(x));
        for (int32_T i{0}; i < a__1_size; i++) {
          y[i] = varargin_1_data[static_cast<int32_T>(idx[i]) - 1];
        }
      }
    }
  }
}

// End of code generation (randsample.cpp)
