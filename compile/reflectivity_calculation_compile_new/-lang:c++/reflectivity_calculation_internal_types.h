//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: reflectivity_calculation_internal_types.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef REFLECTIVITY_CALCULATION_INTERNAL_TYPES_H
#define REFLECTIVITY_CALCULATION_INTERNAL_TYPES_H

// Include Files
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
namespace RAT
{
  struct cell_wrap_19
  {
    real_T f1[5];
  };

  struct cell_wrap_12
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_18
  {
    ::coder::bounded_array<cell_wrap_0, 1000U, 2U> f1;
    ::coder::bounded_array<cell_wrap_14, 1000U, 2U> f2;
    ::coder::bounded_array<cell_wrap_0, 1000U, 2U> f3;
    ::coder::bounded_array<cell_wrap_14, 1000U, 2U> f4;
    ::coder::bounded_array<cell_wrap_14, 1000U, 2U> f5;
    ::coder::bounded_array<cell_wrap_14, 1000U, 1U> f6;
    ::coder::array<cell_wrap_5, 2U> f7;
    ::coder::array<cell_wrap_6, 2U> f8;
    ::coder::array<cell_wrap_6, 2U> f9;
    ::coder::array<cell_wrap_6, 2U> f10;
    ::coder::array<cell_wrap_6, 2U> f11;
    ::coder::array<cell_wrap_6, 2U> f12;
    ::coder::array<cell_wrap_6, 2U> f13;
    ::coder::array<cell_wrap_7, 2U> f14;
  };

  struct cell_wrap_34
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_35
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_23
  {
    ::coder::array<real_T, 2U> f1;
  };
}

#endif

//
// File trailer for reflectivity_calculation_internal_types.h
//
// [EOF]
//
