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
  struct cell_wrap_48;
  struct cell_wrap_49;
  struct cell_wrap_52;
  struct cell_wrap_11;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void structConstructorHelper(const cell_wrap_48 *varargin_2, const
        cell_wrap_49 *varargin_4, const cell_wrap_52 *varargin_6, ::coder::array<
        cell_wrap_11, 1U> &s_reflectivity, ::coder::array<cell_wrap_11, 2U>
        &s_sld, double s_sampleChi_data[], int *s_sampleChi_size);
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
