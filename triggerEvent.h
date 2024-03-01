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
  struct cell_wrap_8;
  struct cell_wrap_24;
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  void helper_not_empty_init();
  void triggerEvent(const ::coder::array<cell_wrap_8, 1U> &data_f1_reflectivity,
                    const ::coder::array<cell_wrap_24, 1U> &data_f1_shiftedData,
                    const ::coder::array<cell_wrap_10, 2U> &data_f1_sldProfiles,
                    const ::coder::array<cell_wrap_24, 2U> &data_f1_allLayers,
                    const ::coder::array<real_T, 1U>
                    &data_f1_contrastParams_ssubs, const char_T data_f2_TF_data[],
                    const int32_T data_f2_TF_size[2], const ::coder::array<
                    real_T, 2U> &data_f2_resample, const ::coder::array<real_T,
                    2U> &data_f2_dataPresent, const char_T
                    data_f2_modelType_data[], const int32_T
                    data_f2_modelType_size[2]);
  void triggerEvent_init();
}

#endif

// End of code generation (triggerEvent.h)
