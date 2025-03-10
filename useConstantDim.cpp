//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      void useConstantDim(::coder::array<double, 2U> &varargin_2, int varargin_3)
      {
        int subsb_idx_1;
        if (varargin_3 == 1) {
          if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
            int i;
            i = varargin_2.size(1);
            for (int k{0}; k < i; k++) {
              int i1;
              i1 = varargin_2.size(0);
              if (i1 - 2 >= 0) {
                subsb_idx_1 = k + 1;
              }

              for (int b_k{0}; b_k <= i1 - 2; b_k++) {
                varargin_2[(b_k + varargin_2.size(0) * (subsb_idx_1 - 1)) + 1] =
                  varargin_2[b_k + varargin_2.size(0) * k] + varargin_2[(b_k +
                  varargin_2.size(0) * (subsb_idx_1 - 1)) + 1];
              }
            }
          }
        } else if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
          int i;
          i = varargin_2.size(1);
          for (int k{0}; k <= i - 2; k++) {
            int i1;
            i1 = varargin_2.size(0);
            for (int b_k{0}; b_k < i1; b_k++) {
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
