//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  groupLayers_Mod.h
//
//  Code generation for function 'groupLayers_Mod'
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
void groupLayers_Mod(const emlrtStack *sp, const coder::array<real_T, 2U>
                     &allLayers, real_T allRoughs, const coder::array<char_T, 2U>
                     &geometry, real_T nbair, real_T nbsubs, coder::array<real_T,
                     2U> &outLayers, real_T *outSsubs);

// End of code generation (groupLayers_Mod.h)
