//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      boolean_T allOrAny_anonFcn2(int n, const boolean_T X_data[])
      {
        int k;
        boolean_T exitg1;
        boolean_T varargout_1;
        varargout_1 = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= static_cast<unsigned char>(n) - 1)) {
          if (!X_data[0]) {
            varargout_1 = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return varargout_1;
      }

      boolean_T allOrAny_anonFcn3(int n, const ::coder::array<boolean_T, 1U> &X)
      {
        int k;
        boolean_T exitg1;
        boolean_T varargout_1;
        varargout_1 = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= n - 1)) {
          if (X[k]) {
            varargout_1 = true;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return varargout_1;
      }

      void b_allOrAny_anonFcn2(int n, const boolean_T X_data[], boolean_T
        Y_data[])
      {
        int k;
        boolean_T exitg1;
        Y_data[0] = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= static_cast<unsigned char>(n) - 1)) {
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
