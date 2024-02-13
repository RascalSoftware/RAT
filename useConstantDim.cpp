//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// useConstantDim.cpp
//
// Code generation for function 'useConstantDim'
//

// Include files
#include "useConstantDim.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void useConstantDim(::coder::array<real_T, 2U> &varargin_2, int32_T
                          varargin_3)
      {
        int32_T subsb_idx_1;
        if (1 == varargin_3) {
          if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
            int32_T i;
            i = varargin_2.size(1);
            for (int32_T k{0}; k < i; k++) {
              int32_T i1;
              i1 = varargin_2.size(0);
              if (0 <= i1 - 2) {
                subsb_idx_1 = k + 1;
              }

              for (int32_T b_k{0}; b_k <= i1 - 2; b_k++) {
                varargin_2[(b_k + varargin_2.size(0) * (subsb_idx_1 - 1)) + 1] =
                  varargin_2[b_k + varargin_2.size(0) * k] + varargin_2[(b_k +
                  varargin_2.size(0) * (subsb_idx_1 - 1)) + 1];
              }
            }
          }
        } else if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
          int32_T i;
          i = varargin_2.size(1);
          for (int32_T k{0}; k <= i - 2; k++) {
            int32_T i1;
            i1 = varargin_2.size(0);
            for (int32_T b_k{0}; b_k < i1; b_k++) {
              varargin_2[b_k + varargin_2.size(0) * (k + 1)] = varargin_2[b_k +
                varargin_2.size(0) * k] + varargin_2[b_k + varargin_2.size(0) *
                (k + 1)];
            }
          }
        }
      }
    }
  }
}

// End of code generation (useConstantDim.cpp)
