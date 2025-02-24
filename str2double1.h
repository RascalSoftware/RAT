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
      void readfloat(char s1_data[], int *idx, const char s_data[], int *k, int
                     n, boolean_T *isimag, boolean_T *b_finite, double *nfv,
                     boolean_T *foundsign, boolean_T *success);
      void skipspaces(const char s_data[], int *k, int n);
      double sscanfd(const char s_data[]);
      void sscanfd(const char s_data[], double *out1, double *out2);
    }
  }
}

#endif

// End of code generation (str2double1.h)
