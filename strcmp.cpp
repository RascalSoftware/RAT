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
#include "RATMain_data.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T ab_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[6]{ 's', 'h', 'r', 'i', 'n', 'k' };

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

      boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[7]{ 'd', 'o', 'm', 'a', 'i', 'n', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 7) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 7) {
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

      boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[6])
      {
        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 6) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 6) {
              if (a_data[kstr] != b[kstr]) {
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

      boolean_T bb_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[4]{ 'i', 't', 'e', 'r' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 4) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 4) {
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

      boolean_T c_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 9) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 9) {
              if (a_data[kstr] != cv1[kstr]) {
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

      boolean_T c_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[4])
      {
        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 4) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 4) {
              if (a_data[kstr] != b[kstr]) {
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

      void cb_strcmp(const cell_wrap_3 *a, const ::coder::array<cell_wrap_3, 1U>
                     &b, boolean_T bool_data[], int32_T *bool_size)
      {
        int32_T nb;
        *bool_size = b.size(0);
        nb = b.size(0);
        for (int32_T k{0}; k < nb; k++) {
          bool_data[k] = false;
          if (a->f1.size(1) == b[k].f1.size(1)) {
            int32_T kstr;
            kstr = 0;
            int32_T exitg1;
            do {
              exitg1 = 0;
              if (kstr <= b[k].f1.size(1) - 1) {
                if (cv[static_cast<uint8_T>(a->f1[kstr]) & 127] != cv[
                    static_cast<uint8_T>(b[k].f1[kstr]) & 127]) {
                  exitg1 = 1;
                } else {
                  kstr++;
                }
              } else {
                bool_data[k] = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
      }

      boolean_T d_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[7]{ 's', 'i', 'm', 'p', 'l', 'e', 'x' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 7) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 7) {
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

      boolean_T d_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[3])
      {
        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 3) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 3) {
              if (a_data[kstr] != b[kstr]) {
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

      boolean_T db_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[7]{ 'r', 'e', 'f', 'l', 'e', 'c', 't' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 7) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 7) {
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

      boolean_T e_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[5])
      {
        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 5) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 5) {
              if (a_data[kstr] != b[kstr]) {
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

      boolean_T e_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[2]{ 'd', 'e' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 2) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 2) {
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

      boolean_T eb_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[5]{ 'b', 'o', 'u', 'n', 'd' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 5) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 5) {
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

      boolean_T f_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[2]{ 'n', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 2) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 2) {
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

      boolean_T fb_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[4]{ 'f', 'o', 'l', 'd' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 4) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 4) {
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

      boolean_T g_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[5]{ 'd', 'r', 'e', 'a', 'm' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 5) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 5) {
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

      boolean_T h_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[13]{ 'n', 'o', 'n', ' ', 'p', 'o', 'l', 'a',
          'r', 'i', 's', 'e', 'd' };

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

      boolean_T i_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[7]{ 'd', 'o', 'm', 'a', 'i', 'n', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 7) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 7) {
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

      boolean_T j_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[15]{ 's', 't', 'a', 'n', 'd', 'a', 'r', 'd',
          ' ', 'l', 'a', 'y', 'e', 'r', 's' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 15) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 15) {
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

      boolean_T k_strcmp(const char_T a_data[], const int32_T a_size[2])
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

      boolean_T l_strcmp(const char_T a_data[], const int32_T a_size[2])
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

      boolean_T m_strcmp(const char_T a_data[], const int32_T a_size[2])
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

      boolean_T n_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[8]{ 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 8) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 8) {
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

      boolean_T o_strcmp(const char_T a_data[], const int32_T a_size[2])
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

      boolean_T p_strcmp(const char_T a_data[], const int32_T a_size[2])
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

      boolean_T q_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[3]{ 'a', 'd', 'd' };

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

      boolean_T r_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[8]{ 's', 'u', 'b', 't', 'r', 'a', 'c', 't' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 8) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 8) {
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

      void s_strcmp(const ::coder::array<cell_wrap_3, 2U> &a, boolean_T
                    bool_data[], int32_T bool_size[2])
      {
        static const char_T b_cv[8]{ 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n' };

        int32_T nb;
        bool_size[0] = 1;
        bool_size[1] = static_cast<int16_T>(a.size(1));
        nb = static_cast<int16_T>(a.size(1));
        for (int32_T k{0}; k < nb; k++) {
          bool_data[k] = false;
          if (a[k].f1.size(1) == 8) {
            int32_T kstr;
            kstr = 0;
            int32_T exitg1;
            do {
              exitg1 = 0;
              if (kstr < 8) {
                if (cv[static_cast<uint8_T>(a[k].f1[kstr]) & 127] != cv[
                    static_cast<int32_T>(b_cv[kstr])]) {
                  exitg1 = 1;
                } else {
                  kstr++;
                }
              } else {
                bool_data[k] = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
      }

      boolean_T t_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[3]{ 'o', 'f', 'f' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 3) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 3) {
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

      boolean_T u_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[3]{ 'o', 'f', 'f' };

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

      boolean_T v_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[4]{ 'i', 't', 'e', 'r' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 4) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 4) {
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

      boolean_T w_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[6]{ 'n', 'o', 't', 'i', 'f', 'y' };

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

      boolean_T x_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[5]{ 'f', 'i', 'n', 'a', 'l' };

        boolean_T b_bool;
        b_bool = false;
        if (a_size[1] == 5) {
          int32_T kstr;
          kstr = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (kstr < 5) {
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

      boolean_T y_strcmp(const char_T a_data[], const int32_T a_size[2])
      {
        static const char_T b_cv[3]{ 'a', 'l', 'l' };

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

// End of code generation (strcmp.cpp)
