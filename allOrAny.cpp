//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// allOrAny.cpp
//
// Code generation for function 'allOrAny'
//

// Include files
#include "allOrAny.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T c_anon(int32_T n, const ::coder::array<boolean_T, 1U> &X)
      {
        int32_T k;
        boolean_T exitg1;
        boolean_T varargout_1;
        varargout_1 = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= n - 1)) {
          if (!X[k]) {
            k++;
          } else {
            varargout_1 = true;
            exitg1 = true;
          }
        }

        return varargout_1;
      }

      boolean_T d_anon(int32_T n, const boolean_T X_data[])
      {
        int32_T k;
        boolean_T exitg1;
        boolean_T varargout_1;
        varargout_1 = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= n - 1)) {
          if (!X_data[0]) {
            varargout_1 = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return varargout_1;
      }

      void e_anon(int32_T n, const boolean_T X_data[], boolean_T Y_data[])
      {
        int32_T k;
        boolean_T exitg1;
        Y_data[0] = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= n - 1)) {
          if (!X_data[0]) {
            Y_data[0] = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
    }
  }
}

// End of code generation (allOrAny.cpp)
