//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eye.cpp
//
// Code generation for function 'eye'
//

// Include files
#include "eye.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eye(int varargin_1, ::coder::array<double, 2U> &b_I)
    {
      int k;
      b_I.set_size(varargin_1, varargin_1);
      for (k = 0; k < varargin_1; k++) {
        for (int i{0}; i < varargin_1; i++) {
          b_I[i + b_I.size(0) * k] = 0.0;
        }
      }

      if (varargin_1 > 0) {
        for (k = 0; k < varargin_1; k++) {
          b_I[k + b_I.size(0) * k] = 1.0;
        }
      }
    }
  }
}

// End of code generation (eye.cpp)
