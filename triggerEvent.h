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
  struct cell_wrap_9;
}

// Function Declarations
namespace RAT
{
  void helper_not_empty_init();
  void triggerEvent(const cell_wrap_9 data_f1[6], const ::coder::array<real_T,
                    1U> &data_f2, const char_T data_f3_TF_data[], const int32_T
                    data_f3_TF_size[2], const ::coder::array<real_T, 2U>
                    &data_f3_resample, const ::coder::array<real_T, 2U>
                    &data_f3_dataPresent, const char_T data_f3_modelType_data[],
                    const int32_T data_f3_modelType_size[2]);
  void triggerEvent_init();
}

#endif

// End of code generation (triggerEvent.h)
