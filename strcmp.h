//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strcmp.h
//
// Code generation for function 'strcmp'
//
#ifndef STRCMP_H
#define STRCMP_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_1;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T ab_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[6]);
      boolean_T bb_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T c_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T c_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[4]);
      boolean_T d_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T d_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[3]);
      boolean_T e_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T e_strcmp(const char_T a_data[], const int32_T a_size[2], const
                         char_T b[5]);
      boolean_T f_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T g_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T h_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T i_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T j_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T k_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T l_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T m_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T n_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T o_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T p_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T q_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T r_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T s_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T t_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T u_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T v_strcmp(const char_T a_data[], const int32_T a_size[2]);
      boolean_T w_strcmp(const char_T a_data[], const int32_T a_size[2]);
      void x_strcmp(const cell_wrap_1 *a, const ::coder::array<cell_wrap_1, 1U>
                    &b, ::coder::array<boolean_T, 1U> &b_bool);
      boolean_T y_strcmp(const char_T a_data[], const int32_T a_size[2]);
    }
  }
}

#endif

// End of code generation (strcmp.h)
