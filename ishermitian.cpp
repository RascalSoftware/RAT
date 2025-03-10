//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// ishermitian.cpp
//
// Code generation for function 'ishermitian'
//

// Include files
#include "ishermitian.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    boolean_T b_ishermitian(const ::coder::array<double, 2U> &A)
    {
      boolean_T p;
      p = (A.size(0) == A.size(1));
      if (p) {
        int j;
        boolean_T exitg2;
        j = 0;
        exitg2 = false;
        while ((!exitg2) && (j <= A.size(1) - 1)) {
          int exitg1;
          int i;
          i = 0;
          do {
            exitg1 = 0;
            if (i <= j) {
              if (!(A[i + A.size(0) * j] == -A[j + A.size(0) * i])) {
                p = false;
                exitg1 = 1;
              } else {
                i++;
              }
            } else {
              j++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }

      return p;
    }

    boolean_T ishermitian(const ::coder::array<double, 2U> &A)
    {
      boolean_T p;
      p = (A.size(0) == A.size(1));
      if (p) {
        int j;
        boolean_T exitg2;
        j = 0;
        exitg2 = false;
        while ((!exitg2) && (j <= A.size(1) - 1)) {
          int exitg1;
          int i;
          i = 0;
          do {
            exitg1 = 0;
            if (i <= j) {
              if (!(A[i + A.size(0) * j] == A[j + A.size(0) * i])) {
                p = false;
                exitg1 = 1;
              } else {
                i++;
              }
            } else {
              j++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }

      return p;
    }
  }
}

// End of code generation (ishermitian.cpp)
