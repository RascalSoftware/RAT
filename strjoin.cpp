//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    void b_strjoin(const ::coder::array<char, 2U> &c_f1, const char c_f2[72], ::
                   coder::array<char, 2U> &joinedStr)
    {
      int i;
      joinedStr.set_size(1, c_f1.size(1) + 73);
      i = c_f1.size(1);
      for (int j{0}; j < i; j++) {
        joinedStr[j] = c_f1[j];
      }

      joinedStr[c_f1.size(1)] = ' ';
      for (int j{0}; j < 72; j++) {
        joinedStr[(i + j) + 1] = c_f2[j];
      }
    }

    void strjoin(char joinedStr_data[], int joinedStr_size[2])
    {
      static const char c_f1[9]{ 'C', 'a', 'l', 'c', 'u', 'l', 'a', 't', 'e' };

      static const char c_f2[7]{ 'S', 'i', 'm', 'p', 'l', 'e', 'x' };

      static const char c_f5[5]{ 'D', 'r', 'e', 'a', 'm' };

      joinedStr_size[0] = 1;
      joinedStr_size[1] = 41;
      for (int j{0}; j < 9; j++) {
        joinedStr_data[j] = c_f1[j];
      }

      joinedStr_data[9] = '\"';
      joinedStr_data[10] = ',';
      joinedStr_data[11] = ' ';
      joinedStr_data[12] = '\"';
      for (int j{0}; j < 7; j++) {
        joinedStr_data[j + 13] = c_f2[j];
      }

      joinedStr_data[20] = '\"';
      joinedStr_data[21] = ',';
      joinedStr_data[22] = ' ';
      joinedStr_data[23] = '\"';
      joinedStr_data[24] = 'D';
      joinedStr_data[25] = 'E';
      joinedStr_data[26] = '\"';
      joinedStr_data[27] = ',';
      joinedStr_data[28] = ' ';
      joinedStr_data[29] = '\"';
      joinedStr_data[30] = 'N';
      joinedStr_data[31] = 'S';
      joinedStr_data[32] = '\"';
      joinedStr_data[33] = ',';
      joinedStr_data[34] = ' ';
      joinedStr_data[35] = '\"';
      for (int j{0}; j < 5; j++) {
        joinedStr_data[j + 36] = c_f5[j];
      }
    }

    void strjoin(const ::coder::array<cell_wrap_10, 2U> &c, ::coder::array<char,
                 2U> &joinedStr)
    {
      int num;
      int outidx;
      outidx = c.size(1);
      num = 0;
      if (c.size(1) > 0) {
        for (int k{0}; k < outidx; k++) {
          num += c[k].f1.size(1);
        }
      }

      joinedStr.set_size(1, num);
      outidx = 0;
      if (c.size(1) > 0) {
        num = c.size(1);
        for (int k{0}; k <= num - 2; k++) {
          int i;
          i = c[k].f1.size(1);
          for (int j{0}; j < i; j++) {
            joinedStr[outidx + j] = c[k].f1[j];
          }

          if (c[k].f1.size(1) - 1 >= 0) {
            outidx += c[k].f1.size(1);
          }
        }

        num = c[c.size(1) - 1].f1.size(1);
        for (int j{0}; j < num; j++) {
          joinedStr[outidx + j] = c[c.size(1) - 1].f1[j];
        }
      }
    }

    void strjoin(const ::coder::array<char, 2U> &c_f1, const char c_f2[27], char
                 joinedStr_data[], int joinedStr_size[2])
    {
      joinedStr_size[0] = 1;
      joinedStr_size[1] = 100;
      for (int j{0}; j < 72; j++) {
        joinedStr_data[j] = c_f1[j];
      }

      joinedStr_data[72] = ' ';
      for (int j{0}; j < 27; j++) {
        joinedStr_data[j + 73] = c_f2[j];
      }
    }

    void strjoin(const ::coder::array<char, 2U> &c_f1, const char c_f2[27], ::
                 coder::array<char, 2U> &joinedStr)
    {
      int i;
      joinedStr.set_size(1, c_f1.size(1) + 28);
      i = c_f1.size(1);
      for (int j{0}; j < i; j++) {
        joinedStr[j] = c_f1[j];
      }

      joinedStr[c_f1.size(1)] = ' ';
      for (int j{0}; j < 27; j++) {
        joinedStr[(i + j) + 1] = c_f2[j];
      }
    }

    void strjoin(const cell_wrap_10 c[2], ::coder::array<char, 2U> &joinedStr)
    {
      int i;
      int i1;
      joinedStr.set_size(1, (c[0].f1.size(1) + c[1].f1.size(1)) + 1);
      i = c[0].f1.size(1);
      for (int j{0}; j < i; j++) {
        joinedStr[j] = c[0].f1[j];
      }

      joinedStr[c[0].f1.size(1)] = ' ';
      i1 = c[1].f1.size(1);
      for (int j{0}; j < i1; j++) {
        joinedStr[(i + j) + 1] = c[1].f1[j];
      }
    }
  }
}

// End of code generation (strjoin.cpp)
