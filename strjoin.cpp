//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strjoin.cpp
//
// Code generation for function 'strjoin'
//

// Include files
#include "strjoin.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void strjoin(const ::coder::array<cell_wrap_1, 2U> &c, ::coder::array<char_T,
                 2U> &joinedStr)
    {
      int32_T k;
      int32_T num;
      int32_T outidx;
      outidx = c.size(1);
      num = 0;
      if (c.size(1) > 0) {
        for (k = 0; k < outidx; k++) {
          num += c[k].f1.size(1);
        }
      }

      joinedStr.set_size(1, num);
      outidx = 0;
      if (c.size(1) > 0) {
        int32_T j;
        num = c.size(1);
        for (k = 0; k <= num - 2; k++) {
          int32_T i;
          i = c[k].f1.size(1);
          for (j = 0; j < i; j++) {
            joinedStr[outidx + j] = c[k].f1[j];
          }

          outidx += c[k].f1.size(1);
        }

        num = c[c.size(1) - 1].f1.size(1);
        for (j = 0; j < num; j++) {
          joinedStr[outidx + j] = c[c.size(1) - 1].f1[j];
        }
      }
    }
  }
}

// End of code generation (strjoin.cpp)
