//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain_rtwutil.h
//
// Code generation for function 'RATMain_rtwutil'
//
#ifndef RATMAIN_RTWUTIL_H
#define RATMAIN_RTWUTIL_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  extern void cast(const ::coder::array<cell_wrap_47, 1U> &b, ::coder::array<
                   cell_wrap_8, 1U> &c);
  extern void cast(const ::coder::array<cell_wrap_47, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c);
  extern void cast(const ::coder::array<cell_wrap_22, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c);
  extern void cast(const ::coder::array<cell_wrap_18, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c);
  extern void emlrtFreeThreadStackData();
  extern RATMainTLS *emlrtGetThreadStackData();
  extern void emlrtInitThreadStackData();
  extern real_T rt_atan2d_snf(real_T u0, real_T u1);
  extern real_T rt_hypotd_snf(real_T u0, real_T u1);
  extern real_T rt_powd_snf(real_T u0, real_T u1);
  extern real_T rt_remd_snf(real_T u0, real_T u1);
}

#endif

// End of code generation (RATMain_rtwutil.h)
