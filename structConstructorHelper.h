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
  struct cell_wrap_27;
  struct cell_wrap_28;
  struct cell_wrap_29;
  struct cell_wrap_30;
  struct struct6_T;
  struct c_struct_T;
  struct cell_wrap_31;
  struct d_struct_T;
  struct cell_wrap_34;
  struct cell_wrap_10;
  struct cell_wrap_36;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void structConstructorHelper(const cell_wrap_27 *varargin_2, const
        cell_wrap_27 *varargin_4, const cell_wrap_28 *varargin_6, const
        cell_wrap_29 *varargin_8, const cell_wrap_29 *varargin_10, const
        cell_wrap_30 *varargin_12, const struct6_T *varargin_14, const
        c_struct_T *varargin_16, const ::coder::array<real_T, 2U> &varargin_18,
        const cell_wrap_31 *varargin_20, d_struct_T *s);
      void structConstructorHelper(const cell_wrap_34 *varargin_2, const
        cell_wrap_29 *varargin_4, const cell_wrap_34 *varargin_8, ::coder::array<
        cell_wrap_10, 1U> &s_reflectivity, ::coder::array<cell_wrap_10, 2U>
        &s_sld, real_T *s_chi, ::coder::array<cell_wrap_10, 1U> &s_data);
      void structConstructorHelper(const cell_wrap_34 *varargin_2, const
        cell_wrap_29 *varargin_4, const cell_wrap_34 *varargin_6, const
        cell_wrap_29 *varargin_8, const cell_wrap_36 *varargin_10, ::coder::
        array<cell_wrap_10, 1U> &s_reflectivity, ::coder::array<cell_wrap_10, 2U>
        &s_sld, ::coder::array<cell_wrap_10, 1U> &s_reflectivityXData, ::coder::
        array<cell_wrap_10, 2U> &s_sldXData, real_T s_sampleChi_data[], int32_T *
        s_sampleChi_size);
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
