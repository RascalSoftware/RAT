//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// structConstructorHelper.h
//
// Code generation for function 'structConstructorHelper'
//
#ifndef STRUCTCONSTRUCTORHELPER_H
#define STRUCTCONSTRUCTORHELPER_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_33;
  struct cell_wrap_34;
  struct cell_wrap_35;
  struct cell_wrap_36;
  struct cell_wrap_45;
  struct cell_wrap_46;
  struct cell_wrap_49;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int structConstructorHelper(const cell_wrap_45 &varargin_2, const
        cell_wrap_46 &varargin_4, const cell_wrap_49 &varargin_6, ::coder::array<
        cell_wrap_11, 1U> &s_reflectivity, ::coder::array<cell_wrap_11, 2U>
        &s_sld, double s_sampleChi_data[]);
      void structConstructorHelper(const cell_wrap_33 &varargin_2, const
        cell_wrap_33 &varargin_4, const cell_wrap_34 &varargin_6, const
        cell_wrap_34 &varargin_8, const cell_wrap_33 &varargin_10, const
        cell_wrap_35 &varargin_12, const cell_wrap_35 &varargin_14, const
        cell_wrap_35 &varargin_16, const CalculationResults &varargin_18, const
        ContrastParams &varargin_20, const ::coder::array<double, 2U>
        &varargin_22, const cell_wrap_36 &varargin_24, Results &s);
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
