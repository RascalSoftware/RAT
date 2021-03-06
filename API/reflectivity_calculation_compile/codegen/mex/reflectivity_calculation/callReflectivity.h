//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  callReflectivity.h
//
//  Code generation for function 'callReflectivity'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
void b_callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs,
  const real_T simLimits[2], const real_T repeatLayers[2], const coder::array<
  real_T, 2U> &this_data, const coder::array<real_T, 2U> &layers, real_T ssubs,
  real_T res, coder::array<real_T, 2U> &reflectivity, coder::array<real_T, 2U>
  &Simulation);
void callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs, const
                      real_T simLimits[2], const real_T repeatLayers[2], const
                      coder::array<real_T, 2U> &this_data, const coder::array<
                      real_T, 2U> &layers, real_T ssubs, real_T res, coder::
                      array<real_T, 2U> &reflectivity, coder::array<real_T, 2U>
                      &Simulation);

// End of code generation (callReflectivity.h)
