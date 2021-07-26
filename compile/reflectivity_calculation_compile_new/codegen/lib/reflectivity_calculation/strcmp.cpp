//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strcmp.cpp
//
// Code generation for function 'strcmp'
//

// Include files
#include "strcmp.h"
#include "lower.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
boolean_T b_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[10]{'s', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T', 'F'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 10) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T c_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[6]{'l', 'a', 'y', 'e', 'r', 's'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T d_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[13]{'c', 'u', 's', 't', 'o', 'm', ' ',
                             'l', 'a', 'y', 'e', 'r', 's'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 13) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T e_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[9]{'c', 'u', 's', 't', 'o', 'm', ' ', 'x', 'y'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 9) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 9) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T f_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[6]{'s', 'i', 'n', 'g', 'l', 'e'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T g_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[6]{'p', 'o', 'i', 'n', 't', 's'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T h_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[9]{'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 9) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 9) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T i_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[13]{'a', 'i', 'r', '/', 's', 'u', 'b',
                             's', 't', 'r', 'a', 't', 'e'};
  boolean_T b_bool;
  b_bool = false;
  if (a.size(1) == 13) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (lower(a[kstr]) != lower(b_cv[kstr])) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

} // namespace internal
} // namespace coder

// End of code generation (strcmp.cpp)
