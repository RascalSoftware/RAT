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
    void b_snPrint(double varargin_1, ::coder::array<char, 2U> &str);
    void b_sprintf(double varargin_1, double varargin_2, ::coder::array<char, 2U>
                   &str);
    void b_sprintf(double varargin_1, double varargin_2, int varargin_3, int
                   varargin_4, double varargin_5, ::coder::array<char, 2U> &str);
    void c_snPrint(double varargin_1, ::coder::array<char, 2U> &str);
    void snPrint(double varargin_1, double varargin_2, double varargin_3, const
                 char varargin_4_data[], const int varargin_4_size[2], ::coder::
                 array<char, 2U> &str);
    void snPrint(const ::coder::array<char, 2U> &varargin_1, ::coder::array<char,
                 2U> &str);
    void snPrint(double varargin_1, double varargin_2, double varargin_3, double
                 varargin_4, double varargin_5, ::coder::array<char, 2U> &str);
    void snPrint(double varargin_1, ::coder::array<char, 2U> &str);
    void snPrint(const char varargin_1[4], ::coder::array<char, 2U> &str);
    void snPrint(const char varargin_1_data[], const int varargin_1_size[2], ::
                 coder::array<char, 2U> &str);
    void snPrint(double varargin_1, double varargin_2, const char *varargin_3, ::
                 coder::array<char, 2U> &str);
  }
}

#endif

// End of code generation (sprintf.h)
