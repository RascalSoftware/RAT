//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sprintf.h
//
// Code generation for function 'sprintf'
//
#ifndef SPRINTF_H
#define SPRINTF_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_snPrint(real_T varargin_1, ::coder::array<char_T, 2U> &str);
    void b_sprintf(real_T varargin_1, real_T varargin_2, ::coder::array<char_T,
                   2U> &str);
    void b_sprintf(real_T varargin_1, real_T varargin_2, int32_T varargin_3,
                   int32_T varargin_4, real_T varargin_5, ::coder::array<char_T,
                   2U> &str);
    void c_snPrint(real_T varargin_1, ::coder::array<char_T, 2U> &str);
    void snPrint(real_T varargin_1, real_T varargin_2, real_T varargin_3, const
                 char_T varargin_4_data[], const int32_T varargin_4_size[2], ::
                 coder::array<char_T, 2U> &str);
    void snPrint(const ::coder::array<char_T, 2U> &varargin_1, ::coder::array<
                 char_T, 2U> &str);
    void snPrint(real_T varargin_1, real_T varargin_2, real_T varargin_3, real_T
                 varargin_4, real_T varargin_5, ::coder::array<char_T, 2U> &str);
    void snPrint(real_T varargin_1, ::coder::array<char_T, 2U> &str);
    void snPrint(const char_T varargin_1[4], ::coder::array<char_T, 2U> &str);
    void snPrint(const char_T varargin_1_data[], const int32_T varargin_1_size[2],
                 ::coder::array<char_T, 2U> &str);
    void snPrint(real_T varargin_1, real_T varargin_2, const char_T *varargin_3,
                 ::coder::array<char_T, 2U> &str);
  }
}

#endif

// End of code generation (sprintf.h)
