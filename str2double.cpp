//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// str2double.cpp
//
// Code generation for function 'str2double'
//

// Include files
#include "str2double.h"
#include "rt_nonfinite.h"
#include <cstdio>
#include <cstring>

// Variable Definitions
namespace RAT
{
  static const boolean_T bv[128]{ false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static boolean_T b_copysign(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T &success);
      static boolean_T b_readfloat(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T &b_finite, double &nfv, boolean_T &foundsign,
        boolean_T &success);
      static boolean_T copydigits(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T allowpoint);
      static boolean_T copyexponent(char s1_data[], int &idx, const char s_data[],
        int &k, int n);
      static boolean_T isUnitImag(const char s_data[], int k, int n);
      static boolean_T readNonFinite(const char s_data[], int k, int n);
      static boolean_T readNonFinite(const char s_data[], int &k, int n, double
        &fv);
      static boolean_T readfloat(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T &b_finite, double &nfv, boolean_T &foundsign,
        boolean_T &success);
      static int skipspaces(const char s_data[], int n);
      static void skipspaces(const char s_data[], int &k, int n);
      static double sscanfd(const char s_data[]);
      static double sscanfd(const char s_data[], double &out2);
    }
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static boolean_T b_copysign(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T &success)
      {
        boolean_T exitg1;
        boolean_T foundsign;
        boolean_T isneg;
        isneg = false;
        foundsign = false;
        exitg1 = false;
        while ((!exitg1) && (k <= n)) {
          char c;
          c = s_data[k - 1];
          if (c == '-') {
            isneg = !isneg;
            foundsign = true;
            k++;
          } else if (c == ',') {
            k++;
          } else if (c == '+') {
            foundsign = true;
            k++;
          } else if (!bv[static_cast<unsigned char>(c) & 127]) {
            exitg1 = true;
          } else {
            k++;
          }
        }

        success = (k <= n);
        if (success && isneg) {
          if ((idx >= 2) && (s1_data[idx - 2] == '-')) {
            s1_data[idx - 2] = ' ';
          } else {
            s1_data[idx - 1] = '-';
            idx++;
          }
        }

        return foundsign;
      }

      static boolean_T b_readfloat(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T &b_finite, double &nfv, boolean_T &foundsign,
        boolean_T &success)
      {
        int b_idx;
        boolean_T isimag;
        isimag = false;
        b_finite = true;
        nfv = 0.0;
        b_idx = idx;
        foundsign = b_copysign(s1_data, b_idx, s_data, k, n, success);
        idx = b_idx;
        if (success) {
          if (isUnitImag(s_data, k, n)) {
            success = false;
          } else {
            b_finite = readNonFinite(s_data, k, n, nfv);
            if (b_finite) {
              success = copydigits(s1_data, idx, s_data, k, n, true);
              if (success) {
                success = copyexponent(s1_data, idx, s_data, k, n);
              }
            } else if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
              idx = b_idx - 1;
              s1_data[b_idx - 2] = ' ';
              nfv = -nfv;
            }

            skipspaces(s_data, k, n);
            if ((k <= n) && (s_data[k - 1] == '*')) {
              k++;
              skipspaces(s_data, k, n);
            }

            if (k <= n) {
              char c;
              c = s_data[k - 1];
              if ((c == 'i') || (c == 'j')) {
                k++;
                isimag = true;
              }
            }
          }

          skipspaces(s_data, k, n);
        }

        return isimag;
      }

      static boolean_T copydigits(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T allowpoint)
      {
        boolean_T exitg1;
        boolean_T haspoint;
        boolean_T success;
        success = (k <= n);
        haspoint = false;
        exitg1 = false;
        while ((!exitg1) && (success && (k <= n))) {
          char c;
          c = s_data[k - 1];
          if ((c >= '0') && (c <= '9')) {
            s1_data[idx - 1] = c;
            idx++;
            k++;
          } else if (c == '.') {
            if (allowpoint && (!haspoint)) {
              success = true;
            } else {
              success = false;
            }

            if (success) {
              s1_data[idx - 1] = '.';
              idx++;
              haspoint = true;
            }

            k++;
          } else if (c == ',') {
            k++;
          } else {
            exitg1 = true;
          }
        }

        return success;
      }

      static boolean_T copyexponent(char s1_data[], int &idx, const char s_data[],
        int &k, int n)
      {
        boolean_T success;
        success = true;
        if (k <= n) {
          char c;
          c = s_data[k - 1];
          if ((c == 'E') || (c == 'e')) {
            int kexp;
            boolean_T b_success;
            s1_data[idx - 1] = 'e';
            idx++;
            k++;
            while ((k <= n) && (s_data[k - 1] == ',')) {
              k++;
            }

            if (k <= n) {
              c = s_data[k - 1];
              if (c == '-') {
                s1_data[idx - 1] = '-';
                idx++;
                k++;
              } else if (c == '+') {
                k++;
              }
            }

            kexp = k;
            b_success = copydigits(s1_data, idx, s_data, k, n, false);
            if ((!b_success) || (k <= kexp)) {
              success = false;
            }
          }
        }

        return success;
      }

      static boolean_T isUnitImag(const char s_data[], int k, int n)
      {
        boolean_T p;
        p = false;
        if (k <= n) {
          char c;
          c = s_data[k - 1];
          if (c == 'j') {
            p = true;
          } else if (c == 'i') {
            if (k >= n - 1) {
              p = true;
            } else {
              p = readNonFinite(s_data, k, n);
            }
          }
        }

        return p;
      }

      static boolean_T readNonFinite(const char s_data[], int k, int n)
      {
        int b_k;
        char c[3];
        boolean_T b_finite;
        b_k = k;
        for (int j{0}; j < 3; j++) {
          c[j] = '\x00';
          while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
            b_k++;
          }

          if (b_k <= n) {
            c[j] = s_data[b_k - 1];
          }

          b_k++;
        }

        if (((c[0] == 'I') || (c[0] == 'i')) && ((c[1] == 'N') || (c[1] == 'n'))
            && ((c[2] == 'F') || (c[2] == 'f'))) {
          b_finite = false;
        } else if (((c[0] == 'N') || (c[0] == 'n')) && ((c[1] == 'A') || (c[1] ==
          'a')) && ((c[2] == 'N') || (c[2] == 'n'))) {
          b_finite = false;
        } else {
          b_finite = true;
        }

        return b_finite;
      }

      static boolean_T readNonFinite(const char s_data[], int &k, int n, double
        &fv)
      {
        int ksaved;
        char c[3];
        boolean_T b_finite;
        ksaved = k;
        for (int j{0}; j < 3; j++) {
          c[j] = '\x00';
          while ((k <= n) && (s_data[k - 1] == ',')) {
            k++;
          }

          if (k <= n) {
            c[j] = s_data[k - 1];
          }

          k++;
        }

        if (((c[0] == 'I') || (c[0] == 'i')) && ((c[1] == 'N') || (c[1] == 'n'))
            && ((c[2] == 'F') || (c[2] == 'f'))) {
          b_finite = false;
          fv = rtInf;
        } else if (((c[0] == 'N') || (c[0] == 'n')) && ((c[1] == 'A') || (c[1] ==
          'a')) && ((c[2] == 'N') || (c[2] == 'n'))) {
          b_finite = false;
          fv = rtNaN;
        } else {
          b_finite = true;
          fv = 0.0;
          k = ksaved;
        }

        return b_finite;
      }

      static boolean_T readfloat(char s1_data[], int &idx, const char s_data[],
        int &k, int n, boolean_T &b_finite, double &nfv, boolean_T &foundsign,
        boolean_T &success)
      {
        int b_idx;
        boolean_T a__3;
        boolean_T isimag;
        isimag = false;
        b_finite = true;
        nfv = 0.0;
        b_idx = idx;
        foundsign = b_copysign(s1_data, b_idx, s_data, k, n, success);
        idx = b_idx;
        if (success) {
          if (isUnitImag(s_data, k, n)) {
            isimag = true;
            k++;
            skipspaces(s_data, k, n);
            if ((k <= n) && (s_data[k - 1] == '*')) {
              k++;
              b_readfloat(s1_data, idx, s_data, k, n, b_finite, nfv, a__3,
                          success);
            } else {
              s1_data[b_idx - 1] = '1';
              idx = b_idx + 1;
            }
          } else {
            b_finite = readNonFinite(s_data, k, n, nfv);
            if (b_finite) {
              success = copydigits(s1_data, idx, s_data, k, n, true);
              if (success) {
                success = copyexponent(s1_data, idx, s_data, k, n);
              }
            } else if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
              idx = b_idx - 1;
              s1_data[b_idx - 2] = ' ';
              nfv = -nfv;
            }

            skipspaces(s_data, k, n);
            if ((k <= n) && (s_data[k - 1] == '*')) {
              k++;
              skipspaces(s_data, k, n);
            }

            if (k <= n) {
              char c;
              c = s_data[k - 1];
              if ((c == 'i') || (c == 'j')) {
                k++;
                isimag = true;
              }
            }
          }

          skipspaces(s_data, k, n);
        }

        return isimag;
      }

      static int skipspaces(const char s_data[], int n)
      {
        int k;
        boolean_T exitg1;
        k = 1;
        exitg1 = false;
        while ((!exitg1) && (k <= n)) {
          char c;
          c = s_data[k - 1];
          if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00')) {
            k++;
          } else {
            exitg1 = true;
          }
        }

        return k;
      }

      static void skipspaces(const char s_data[], int &k, int n)
      {
        boolean_T exitg1;
        exitg1 = false;
        while ((!exitg1) && (k <= n)) {
          char c;
          c = s_data[k - 1];
          if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') || (c ==
               ',')) {
            k++;
          } else {
            exitg1 = true;
          }
        }
      }

      static double sscanfd(const char s_data[])
      {
        double out1;
        int nread;
        nread = std::sscanf(&s_data[0], "%lf", &out1);
        if (nread != 1) {
          out1 = rtNaN;
        }

        return out1;
      }

      static double sscanfd(const char s_data[], double &out2)
      {
        double out1;
        int nread;
        nread = std::sscanf(&s_data[0], "%lf %lf", &out1, &out2);
        if (nread != 2) {
          out1 = rtNaN;
          out2 = rtNaN;
        }

        return out1;
      }

      creal_T str2double(const char s_data[], const int s_size[2])
      {
        creal_T x;
        double v1;
        double v2;
        char s1_data[10002];
        boolean_T a__1;
        boolean_T foundsign;
        boolean_T isfinite1;
        boolean_T isfinite2;
        boolean_T success;
        x.re = rtNaN;
        x.im = 0.0;
        if (s_size[1] >= 1) {
          int idx;
          int k;
          int ntoread;
          boolean_T isimag1;
          ntoread = 0;
          k = s_size[1] + 2;
          std::memset(&s1_data[0], 0, static_cast<unsigned int>(k) * sizeof(char));
          idx = 1;
          k = skipspaces(s_data, s_size[1]);
          isimag1 = readfloat(s1_data, idx, s_data, k, s_size[1], isfinite1, v1,
                              a__1, success);
          if (isfinite1) {
            ntoread = 1;
          }

          if (success && (k <= s_size[1])) {
            s1_data[idx - 1] = ' ';
            idx++;
            a__1 = readfloat(s1_data, idx, s_data, k, s_size[1], isfinite2, v2,
                             foundsign, success);
            if (isfinite2) {
              ntoread++;
            }

            if (success && (k > s_size[1]) && (isimag1 ^ a__1) && foundsign) {
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
              v1 = sscanfd(s1_data, v2);
            } else if (ntoread == 1) {
              double a;
              a = sscanfd(s1_data);
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
}

// End of code generation (str2double.cpp)
