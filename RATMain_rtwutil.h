//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  extern void cast(const b_struct_T &r, ::coder::array<cell_wrap_7, 1U>
                   &t0_reflectivity, ::coder::array<cell_wrap_7, 1U>
                   &t0_simulation, ::coder::array<cell_wrap_8, 1U>
                   &t0_shiftedData, ::coder::array<cell_wrap_8, 1U>
                   &t0_backgrounds, ::coder::array<cell_wrap_7, 1U>
                   &t0_resolutions, ::coder::array<cell_wrap_9, 2U>
                   &t0_sldProfiles, ::coder::array<cell_wrap_9, 2U> &t0_layers, ::
                   coder::array<cell_wrap_9, 2U> &t0_resampledLayers, ::coder::
                   array<double, 2U> &t0_fitParams, ::coder::array<cell_wrap_10,
                   1U> &t0_fitNames, CalculationResults &t0_calculationResults,
                   ContrastParams &t0_contrastParams);
  extern void cast(const ::coder::array<cell_wrap_0, 1U> &r, ::coder::array<
                   cell_wrap_10, 1U> &r1);
  extern double rt_hypotd_snf(double u0, double u1);
  extern double rt_powd_snf(double u0, double u1);
  extern double rt_remd_snf(double u0, double u1);
}

#endif

// End of code generation (RATMain_rtwutil.h)
