//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// triggerEvent.h
//
// Code generation for function 'triggerEvent'
//
#ifndef TRIGGEREVENT_H
#define TRIGGEREVENT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct f_struct_T;
  struct cell_wrap_7;
}

// Function Declarations
namespace RAT
{
  void b_triggerEvent();
  void b_triggerEvent(real_T varargin_2);
  void c_triggerEvent();
  void d_triggerEvent();
  void e_triggerEvent();
  void f_triggerEvent();
  void g_triggerEvent();
  void h_triggerEvent();
  void helper_not_empty_init();
  void i_triggerEvent();
  void j_triggerEvent();
  void triggerEvent();
  void triggerEvent(const f_struct_T *varargin_1, const char_T
                    varargin_2_TF_data[], const int32_T varargin_2_TF_size[2],
                    const ::coder::array<real_T, 2U> &varargin_2_resample, const
                    ::coder::array<real_T, 2U> &varargin_2_dataPresent, const
                    char_T varargin_2_modelType_data[], const int32_T
                    varargin_2_modelType_size[2], const ::coder::array<
                    cell_wrap_7, 2U> &varargin_2_names_contrasts);
  void triggerEvent(const ::coder::array<char_T, 2U> &varargin_1);
  void triggerEvent(real_T varargin_2);
  void triggerEvent_init();
}

#endif

// End of code generation (triggerEvent.h)
