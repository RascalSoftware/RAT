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
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
