//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// str2double.cpp
//
// Code generation for function 'str2double'
//

// Include files
#include "str2double.h"
#include "rt_nonfinite.h"
#include "str2double1.h"
#include <cstring>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    creal_T str2double(const char s_data[], const int s_size[2])
    {
      creal_T x;
      double v1;
      double v2;
      int idx;
      int k;
      char s1_data[10002];
      boolean_T a__1;
      boolean_T foundsign;
      boolean_T isfinite1;
      boolean_T isfinite2;
      boolean_T isimag1;
      boolean_T success;
      x.re = rtNaN;
      x.im = 0.0;
      if (s_size[1] >= 1) {
        int ntoread;
        ntoread = 0;
        k = 1;
        internal::skipspaces(s_data, &k, s_size[1]);
        idx = static_cast<short>(s_size[1] + 2);
        if (0 <= idx - 1) {
          std::memset(&s1_data[0], 0, idx * sizeof(char));
        }

        idx = 1;
        internal::readfloat(s1_data, &idx, s_data, &k, s_size[1], &isimag1,
                            &isfinite1, &v1, &a__1, &success);
        if (isfinite1) {
          ntoread = 1;
        }

        if (success && (k <= s_size[1])) {
          s1_data[idx - 1] = ' ';
          idx++;
          internal::readfloat(s1_data, &idx, s_data, &k, s_size[1], &a__1,
                              &isfinite2, &v2, &foundsign, &success);
          if (isfinite2) {
            ntoread++;
          }

          if (success && (k > s_size[1]) && (isimag1 != a__1) && foundsign) {
            success = true;
          } else {
            success = false;
          }
        } else {
          v2 = 0.0;
        }

        if (success) {
          s1_data[idx - 1] = '\x00';
          if (ntoread == 2) {
            internal::sscanfd(s1_data, &v1, &v2);
          } else if (ntoread == 1) {
            double a;
            a = internal::sscanfd(s1_data);
            if (isfinite1) {
              v1 = a;
            } else {
              v2 = a;
            }
          }

          if (isimag1) {
            x.re = v2;
            x.im = v1;
          } else {
            x.re = v1;
            x.im = v2;
          }
        }
      }

      return x;
    }
  }
}

// End of code generation (str2double.cpp)
