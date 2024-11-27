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
    void b_strjoin(const ::coder::array<char_T, 2U> &c_f1, const char_T c_f2[72],
                   ::coder::array<char_T, 2U> &joinedStr)
    {
      int32_T i;
      int32_T j;
      joinedStr.set_size(1, c_f1.size(1) + 73);
      i = c_f1.size(1);
      for (j = 0; j < i; j++) {
        joinedStr[j] = c_f1[j];
      }

      joinedStr[c_f1.size(1)] = ' ';
      for (j = 0; j < 72; j++) {
        joinedStr[(i + j) + 1] = c_f2[j];
      }
    }

    void strjoin(const ::coder::array<cell_wrap_3, 2U> &c, ::coder::array<char_T,
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

    void strjoin(const ::coder::array<char_T, 2U> &c_f1, const char_T c_f2[27],
                 char_T joinedStr_data[], int32_T joinedStr_size[2])
    {
      int32_T j;
      joinedStr_size[0] = 1;
      joinedStr_size[1] = 100;
      for (j = 0; j < 72; j++) {
        joinedStr_data[j] = c_f1[j];
      }

      joinedStr_data[72] = ' ';
      for (j = 0; j < 27; j++) {
        joinedStr_data[j + 73] = c_f2[j];
      }
    }

    void strjoin(const ::coder::array<char_T, 2U> &c_f1, const char_T c_f2[27], ::
                 coder::array<char_T, 2U> &joinedStr)
    {
      int32_T i;
      int32_T j;
      joinedStr.set_size(1, c_f1.size(1) + 28);
      i = c_f1.size(1);
      for (j = 0; j < i; j++) {
        joinedStr[j] = c_f1[j];
      }

      joinedStr[c_f1.size(1)] = ' ';
      for (j = 0; j < 27; j++) {
        joinedStr[(i + j) + 1] = c_f2[j];
      }
    }

    void strjoin(const cell_wrap_3 c[2], ::coder::array<char_T, 2U> &joinedStr)
    {
      int32_T i;
      int32_T i1;
      int32_T j;
      joinedStr.set_size(1, (c[0].f1.size(1) + c[1].f1.size(1)) + 1);
      i = c[0].f1.size(1);
      for (j = 0; j < i; j++) {
        joinedStr[j] = c[0].f1[j];
      }

      joinedStr[c[0].f1.size(1)] = ' ';
      i1 = c[1].f1.size(1);
      for (j = 0; j < i1; j++) {
        joinedStr[(i + j) + 1] = c[1].f1[j];
      }
    }
  }
}

// End of code generation (strjoin.cpp)
