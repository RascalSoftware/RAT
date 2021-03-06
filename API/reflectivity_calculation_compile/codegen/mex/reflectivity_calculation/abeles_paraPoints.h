//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  abeles_paraPoints.h
//
//  Code generation for function 'abeles_paraPoints'
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
void abeles_paraPoints(const emlrtStack *sp, const coder::array<real_T, 1U> &x,
  const coder::array<real_T, 2U> &sld, real_T nbair, real_T nbsub, real_T
  nrepeats, real_T rfinal, real_T layers, real_T points, coder::array<real_T, 1U>
  &out);

// End of code generation (abeles_paraPoints.h)
