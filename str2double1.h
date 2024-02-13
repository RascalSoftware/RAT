//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// str2double1.h
//
// Code generation for function 'str2double1'
//
#ifndef STR2DOUBLE1_H
#define STR2DOUBLE1_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void readfloat(char_T s1_data[], int32_T *idx, const char_T s_data[],
                     int32_T *k, int32_T n, boolean_T *isimag, boolean_T
                     *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
                     *success);
      void skipspaces(const char_T s_data[], int32_T *k, int32_T n);
      real_T sscanfd(const char_T s_data[]);
      void sscanfd(const char_T s_data[], real_T *out1, real_T *out2);
    }
  }
}

#endif

// End of code generation (str2double1.h)
