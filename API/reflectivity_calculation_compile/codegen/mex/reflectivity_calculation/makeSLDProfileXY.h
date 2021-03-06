//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  makeSLDProfileXY.h
//
//  Code generation for function 'makeSLDProfileXY'
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
void makeSLDProfileXY(const emlrtStack *sp, real_T nbair, real_T nbsub, real_T
                      ssub, const coder::array<real_T, 2U> &layers, real_T
                      numberOfLayers, real_T nrepeats, coder::array<real_T, 2U>
                      &out);

// End of code generation (makeSLDProfileXY.h)
