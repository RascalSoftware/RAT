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
  struct cell_wrap_14;
  struct cell_wrap_15;
  struct cell_wrap_16;
  struct cell_wrap_17;
  struct struct6_T;
  struct b_struct_T;
  struct cell_wrap_18;
  struct c_struct_T;
  struct cell_wrap_21;
  struct cell_wrap_10;
  struct cell_wrap_23;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void structConstructorHelper(const cell_wrap_14 *varargin_2, const
        cell_wrap_14 *varargin_4, const cell_wrap_15 *varargin_6, const
        cell_wrap_16 *varargin_8, const cell_wrap_16 *varargin_10, const
        cell_wrap_17 *varargin_12, const struct6_T *varargin_14, const
        b_struct_T *varargin_16, const ::coder::array<real_T, 2U> &varargin_18,
        const cell_wrap_18 *varargin_20, c_struct_T *s);
      void structConstructorHelper(const cell_wrap_21 *varargin_2, const
        cell_wrap_16 *varargin_4, const cell_wrap_21 *varargin_8, ::coder::array<
        cell_wrap_10, 1U> &s_ref, ::coder::array<cell_wrap_10, 2U> &s_sld,
        real_T *s_chi, ::coder::array<cell_wrap_10, 1U> &s_data);
      void structConstructorHelper(const cell_wrap_21 *varargin_2, const
        cell_wrap_16 *varargin_4, const cell_wrap_21 *varargin_6, const
        cell_wrap_16 *varargin_8, const cell_wrap_23 *varargin_10, ::coder::
        array<cell_wrap_10, 1U> &s_refPredInts, ::coder::array<cell_wrap_10, 2U>
        &s_sldPredInts, ::coder::array<cell_wrap_10, 1U> &s_refXdata, ::coder::
        array<cell_wrap_10, 2U> &s_sldXdata, real_T s_sampleChi_data[], int32_T *
        s_sampleChi_size);
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
