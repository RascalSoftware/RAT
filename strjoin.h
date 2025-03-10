//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// strjoin.h
//
// Code generation for function 'strjoin'
//
#ifndef STRJOIN_H
#define STRJOIN_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_strjoin(const ::coder::array<char, 2U> &c_f1, const char c_f2[72], ::
                   coder::array<char, 2U> &joinedStr);
    void strjoin(char joinedStr_data[], int joinedStr_size[2]);
    void strjoin(const ::coder::array<cell_wrap_10, 2U> &c, ::coder::array<char,
                 2U> &joinedStr);
    void strjoin(const ::coder::array<char, 2U> &c_f1, const char c_f2[27], char
                 joinedStr_data[], int joinedStr_size[2]);
    void strjoin(const ::coder::array<char, 2U> &c_f1, const char c_f2[27], ::
                 coder::array<char, 2U> &joinedStr);
    void strjoin(const cell_wrap_10 c[2], ::coder::array<char, 2U> &joinedStr);
  }
}

#endif

// End of code generation (strjoin.h)
