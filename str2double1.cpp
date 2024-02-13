//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// str2double1.cpp
//
// Code generation for function 'str2double1'
//

// Include files
#include "str2double1.h"
#include "rt_nonfinite.h"
#include <stdio.h>

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
      static void b_copysign(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n, boolean_T *foundsign, boolean_T
        *success);
      static void b_readNonFinite(const char_T s_data[], int32_T *k, int32_T n,
        boolean_T *b_finite, real_T *fv);
      static void b_readfloat(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n, boolean_T *isimag, boolean_T *b_finite,
        real_T *nfv, boolean_T *foundsign, boolean_T *success);
      static void b_skipspaces(const char_T s_data[], int32_T *k, int32_T n);
      static boolean_T copydigits(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
      static boolean_T copyexponent(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n);
      static boolean_T isUnitImag(const char_T s_data[], int32_T k, int32_T n);
      static boolean_T readNonFinite(const char_T s_data[], int32_T k, int32_T n);
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
      static void b_copysign(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n, boolean_T *foundsign, boolean_T
        *success)
      {
        boolean_T exitg1;
        boolean_T isneg;
        isneg = false;
        *foundsign = false;
        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
          char_T c;
          c = s_data[*k - 1];
          if (c == '-') {
            isneg = !isneg;
            *foundsign = true;
            (*k)++;
          } else if (c == ',') {
            (*k)++;
          } else if (c == '+') {
            *foundsign = true;
            (*k)++;
          } else if (!bv[static_cast<uint8_T>(c) & 127]) {
            exitg1 = true;
          } else {
            (*k)++;
          }
        }

        *success = (*k <= n);
        if ((*success) && isneg) {
          if ((*idx >= 2) && (s1_data[*idx - 2] == '-')) {
            s1_data[*idx - 2] = ' ';
          } else {
            s1_data[*idx - 1] = '-';
            (*idx)++;
          }
        }
      }

      static void b_readNonFinite(const char_T s_data[], int32_T *k, int32_T n,
        boolean_T *b_finite, real_T *fv)
      {
        int32_T ksaved;
        char_T c_idx_0;
        char_T c_idx_1;
        char_T c_idx_2;
        ksaved = *k;
        c_idx_0 = '\x00';
        while ((*k <= n) && (s_data[*k - 1] == ',')) {
          (*k)++;
        }

        if (*k <= n) {
          c_idx_0 = s_data[*k - 1];
        }

        (*k)++;
        c_idx_1 = '\x00';
        while ((*k <= n) && (s_data[*k - 1] == ',')) {
          (*k)++;
        }

        if (*k <= n) {
          c_idx_1 = s_data[*k - 1];
        }

        (*k)++;
        c_idx_2 = '\x00';
        while ((*k <= n) && (s_data[*k - 1] == ',')) {
          (*k)++;
        }

        if (*k <= n) {
          c_idx_2 = s_data[*k - 1];
        }

        (*k)++;
        if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
             (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
          *b_finite = false;
          *fv = rtInf;
        } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                    (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n')))
        {
          *b_finite = false;
          *fv = rtNaN;
        } else {
          *b_finite = true;
          *fv = 0.0;
          *k = ksaved;
        }
      }

      static void b_readfloat(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n, boolean_T *isimag, boolean_T *b_finite,
        real_T *nfv, boolean_T *foundsign, boolean_T *success)
      {
        int32_T b_idx;
        *isimag = false;
        *b_finite = true;
        *nfv = 0.0;
        b_idx = *idx;
        b_copysign(s1_data, &b_idx, s_data, k, n, foundsign, success);
        *idx = b_idx;
        if (*success) {
          if (isUnitImag(s_data, *k, n)) {
            *success = false;
          } else {
            b_readNonFinite(s_data, k, n, b_finite, nfv);
            if (*b_finite) {
              *success = copydigits(s1_data, idx, s_data, k, n, true);
              if (*success) {
                *success = copyexponent(s1_data, idx, s_data, k, n);
              }
            } else if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
              *idx = b_idx - 1;
              s1_data[b_idx - 2] = ' ';
              *nfv = -*nfv;
            }

            b_skipspaces(s_data, k, n);
            if ((*k <= n) && (s_data[*k - 1] == '*')) {
              (*k)++;
              b_skipspaces(s_data, k, n);
            }

            if (*k <= n) {
              char_T c;
              c = s_data[*k - 1];
              if ((c == 'i') || (c == 'j')) {
                (*k)++;
                *isimag = true;
              }
            }
          }

          b_skipspaces(s_data, k, n);
        }
      }

      static void b_skipspaces(const char_T s_data[], int32_T *k, int32_T n)
      {
        boolean_T exitg1;
        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
          char_T c;
          c = s_data[*k - 1];
          if (bv[static_cast<uint8_T>(c) & 127] || (c == '\x00') || (c == ','))
          {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
      }

      static boolean_T copydigits(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n, boolean_T allowpoint)
      {
        boolean_T exitg1;
        boolean_T haspoint;
        boolean_T success;
        success = (*k <= n);
        haspoint = false;
        exitg1 = false;
        while ((!exitg1) && (success && (*k <= n))) {
          char_T c;
          c = s_data[*k - 1];
          if ((c >= '0') && (c <= '9')) {
            s1_data[*idx - 1] = c;
            (*idx)++;
            (*k)++;
          } else if (c == '.') {
            if (allowpoint && (!haspoint)) {
              success = true;
            } else {
              success = false;
            }

            if (success) {
              s1_data[*idx - 1] = '.';
              (*idx)++;
              haspoint = true;
            }

            (*k)++;
          } else if (c == ',') {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }

        return success;
      }

      static boolean_T copyexponent(char_T s1_data[], int32_T *idx, const char_T
        s_data[], int32_T *k, int32_T n)
      {
        boolean_T success;
        success = true;
        if (*k <= n) {
          char_T c;
          c = s_data[*k - 1];
          if ((c == 'E') || (c == 'e')) {
            int32_T kexp;
            boolean_T b_success;
            s1_data[*idx - 1] = 'e';
            (*idx)++;
            (*k)++;
            while ((*k <= n) && (s_data[*k - 1] == ',')) {
              (*k)++;
            }

            if (*k <= n) {
              if (s_data[*k - 1] == '-') {
                s1_data[*idx - 1] = '-';
                (*idx)++;
                (*k)++;
              } else if (s_data[*k - 1] == '+') {
                (*k)++;
              }
            }

            kexp = *k;
            b_success = copydigits(s1_data, idx, s_data, k, n, false);
            if ((!b_success) || (*k <= kexp)) {
              success = false;
            }
          }
        }

        return success;
      }

      static boolean_T isUnitImag(const char_T s_data[], int32_T k, int32_T n)
      {
        boolean_T p;
        p = false;
        if (k <= n) {
          char_T c;
          c = s_data[k - 1];
          if (c == 'j') {
            p = true;
          } else if (c == 'i') {
            p = ((k >= n - 1) || readNonFinite(s_data, k, n));
          }
        }

        return p;
      }

      static boolean_T readNonFinite(const char_T s_data[], int32_T k, int32_T n)
      {
        int32_T b_k;
        char_T c_idx_0;
        char_T c_idx_1;
        char_T c_idx_2;
        boolean_T b_finite;
        b_k = k;
        c_idx_0 = '\x00';
        while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
          b_k++;
        }

        if (b_k <= n) {
          c_idx_0 = s_data[b_k - 1];
        }

        b_k++;
        c_idx_1 = '\x00';
        while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
          b_k++;
        }

        if (b_k <= n) {
          c_idx_1 = s_data[b_k - 1];
        }

        b_k++;
        c_idx_2 = '\x00';
        while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
          b_k++;
        }

        if (b_k <= n) {
          c_idx_2 = s_data[b_k - 1];
        }

        if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
             (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
          b_finite = false;
        } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                    (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n')))
        {
          b_finite = false;
        } else {
          b_finite = true;
        }

        return b_finite;
      }

      void readfloat(char_T s1_data[], int32_T *idx, const char_T s_data[],
                     int32_T *k, int32_T n, boolean_T *isimag, boolean_T
                     *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
                     *success)
      {
        int32_T b_idx;
        boolean_T a__2;
        boolean_T a__3;
        *isimag = false;
        *b_finite = true;
        *nfv = 0.0;
        b_idx = *idx;
        b_copysign(s1_data, &b_idx, s_data, k, n, foundsign, success);
        *idx = b_idx;
        if (*success) {
          if (isUnitImag(s_data, *k, n)) {
            *isimag = true;
            (*k)++;
            b_skipspaces(s_data, k, n);
            if ((*k <= n) && (s_data[*k - 1] == '*')) {
              (*k)++;
              b_readfloat(s1_data, idx, s_data, k, n, &a__2, b_finite, nfv,
                          &a__3, success);
            } else {
              s1_data[b_idx - 1] = '1';
              *idx = b_idx + 1;
            }
          } else {
            b_readNonFinite(s_data, k, n, b_finite, nfv);
            if (*b_finite) {
              *success = copydigits(s1_data, idx, s_data, k, n, true);
              if (*success) {
                *success = copyexponent(s1_data, idx, s_data, k, n);
              }
            } else if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
              *idx = b_idx - 1;
              s1_data[b_idx - 2] = ' ';
              *nfv = -*nfv;
            }

            b_skipspaces(s_data, k, n);
            if ((*k <= n) && (s_data[*k - 1] == '*')) {
              (*k)++;
              b_skipspaces(s_data, k, n);
            }

            if (*k <= n) {
              char_T c;
              c = s_data[*k - 1];
              if ((c == 'i') || (c == 'j')) {
                (*k)++;
                *isimag = true;
              }
            }
          }

          b_skipspaces(s_data, k, n);
        }
      }

      void skipspaces(const char_T s_data[], int32_T *k, int32_T n)
      {
        boolean_T exitg1;
        *k = 1;
        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
          char_T c;
          c = s_data[*k - 1];
          if (bv[static_cast<uint8_T>(c) & 127] || (c == '\x00')) {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
      }

      real_T sscanfd(const char_T s_data[])
      {
        real_T out1;
        int32_T nread;
        nread = sscanf(&s_data[0], "%lf", &out1);
        if (nread != 1) {
          out1 = rtNaN;
        }

        return out1;
      }

      void sscanfd(const char_T s_data[], real_T *out1, real_T *out2)
      {
        int32_T nread;
        nread = sscanf(&s_data[0], "%lf %lf", out1, out2);
        if (nread != 2) {
          *out1 = rtNaN;
          *out2 = rtNaN;
        }
      }
    }
  }
}

// End of code generation (str2double1.cpp)
