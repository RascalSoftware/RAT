//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strjoin.h
//
// Code generation for function 'strjoin'
//
#ifndef STRJOIN_H
#define STRJOIN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_7;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_strjoin(const ::coder::array<char_T, 2U> &c_f1, const char_T c_f2[72],
                   ::coder::array<char_T, 2U> &joinedStr);
    void strjoin(const ::coder::array<cell_wrap_7, 2U> &c, ::coder::array<char_T,
                 2U> &joinedStr);
    void strjoin(const ::coder::array<char_T, 2U> &c_f1, const char_T c_f2[27],
                 char_T joinedStr_data[], int32_T joinedStr_size[2]);
    void strjoin(const ::coder::array<char_T, 2U> &c_f1, const char_T c_f2[27], ::
                 coder::array<char_T, 2U> &joinedStr);
    void strjoin(const cell_wrap_7 c[2], ::coder::array<char_T, 2U> &joinedStr);
  }
}

#endif

// End of code generation (strjoin.h)
