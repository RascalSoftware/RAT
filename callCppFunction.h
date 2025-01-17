//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// callCppFunction.h
//
// Code generation for function 'callCppFunction'
//
#ifndef CALLCPPFUNCTION_H
#define CALLCPPFUNCTION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void b_callCppFunction(const char_T pointer_data[], const int32_T
    pointer_size[2], const ::coder::array<real_T, 2U> &varargin_1, real_T
    varargin_2, const ::coder::array<real_T, 2U> &varargin_3, real_T varargin_4,
    ::coder::array<real_T, 2U> &output, real_T *varargout_1);
  void c_callCppFunction(const char_T pointer_data[], const int32_T
    pointer_size[2], const ::coder::array<real_T, 2U> &varargin_1, real_T
    varargin_2, const ::coder::array<real_T, 2U> &varargin_3, real_T varargin_4,
    ::coder::array<real_T, 2U> &output, real_T *varargout_1);
  void callCppFunction(const char_T pointer_data[], const int32_T pointer_size[2],
                       const ::coder::array<real_T, 2U> &varargin_1, real_T
                       varargin_2, const ::coder::array<real_T, 2U> &varargin_3,
                       real_T varargin_4, ::coder::array<real_T, 2U> &output,
                       real_T *varargout_1);
  void callCppFunction(const char_T pointer_data[], const int32_T pointer_size[2],
                       const ::coder::array<real_T, 1U> &varargin_1, const
                       real_T varargin_2_data[], const int32_T varargin_2_size[2],
                       ::coder::array<real_T, 1U> &output);
}

#endif

// End of code generation (callCppFunction.h)
