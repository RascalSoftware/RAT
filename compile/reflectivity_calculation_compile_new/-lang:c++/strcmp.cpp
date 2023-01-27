//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: strcmp.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "strcmp.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const char_T a_data[]
//                const int32_T a_size[2]
// Return Type  : boolean_T
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[10]{ 's', 't', 'a', 'n', 'd', 'a', 'r', 'd',
          'T', 'F' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 10) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 10) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T c_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[6]{ 'l', 'a', 'y', 'e', 'r', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 6) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 6) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T d_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[13]{ 'c', 'u', 's', 't', 'o', 'm', ' ', 'l',
          'a', 'y', 'e', 'r', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 13) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 13) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T e_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[9]{ 'c', 'u', 's', 't', 'o', 'm', ' ', 'x', 'y'
        };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 9) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 9) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T f_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[6]{ 's', 'i', 'n', 'g', 'l', 'e' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 6) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 6) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T g_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[6]{ 'p', 'o', 'i', 'n', 't', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 6) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 6) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T h_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[9]{ 'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's'
        };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 9) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 9) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T i_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[13]{ 'a', 'i', 'r', '/', 's', 'u', 'b', 's',
          't', 'r', 'a', 't', 'e' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 13) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 13) {
              if (cv[static_cast<uint8_T>(a_data[kstr]) & 127] != cv[
                  static_cast<int32_T>(b_cv[kstr])]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T j_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[6]{ 'm', 'a', 't', 'l', 'a', 'b' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 6) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 6) {
              if (a_data[kstr] != b_cv[kstr]) {
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

      //
      // Arguments    : const char_T a_data[]
      //                const int32_T a_size[2]
      // Return Type  : boolean_T
      //
      boolean_T k_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[3]{ 'c', 'p', 'p' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 3) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 3) {
              if (a_data[kstr] != b_cv[kstr]) {
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
    }
  }
}

//
// File trailer for strcmp.cpp
//
// [EOF]
//
