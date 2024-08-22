//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// structConstructorHelper.h
//
// Code generation for function 'structConstructorHelper'
//
#ifndef STRUCTCONSTRUCTORHELPER_H
#define STRUCTCONSTRUCTORHELPER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_38;
  struct cell_wrap_39;
  struct cell_wrap_40;
  struct cell_wrap_41;
  struct cell_wrap_36;
  struct cell_wrap_11;
  struct cell_wrap_12;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void structConstructorHelper(const cell_wrap_38 *varargin_2, const
        cell_wrap_39 *varargin_4, const cell_wrap_40 *varargin_6, const
        cell_wrap_41 *varargin_8, const cell_wrap_36 *varargin_10, ::coder::
        array<cell_wrap_11, 1U> &s_reflectivity, ::coder::array<cell_wrap_11, 2U>
        &s_sld, ::coder::array<cell_wrap_12, 1U> &s_reflectivityXData, ::coder::
        array<cell_wrap_12, 2U> &s_sldXData, real_T s_sampleChi_data[], int32_T *
        s_sampleChi_size);
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
