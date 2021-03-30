//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  backSort.h
//
//  Code generation for function 'backSort'
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
void backSort(const emlrtStack *sp, real_T cBacks, real_T cShifts, real_T
              cScales, real_T cNbas, real_T cNbss, real_T cRes, const coder::
              array<real_T, 2U> &backs, const coder::array<real_T, 2U> &shifts,
              const coder::array<real_T, 2U> &sf, const coder::array<real_T, 2U>
              &nba, const coder::array<real_T, 2U> &nbs, const coder::array<
              real_T, 2U> &res, real_T *backg, real_T *qshift, real_T *b_sf,
              real_T *b_nba, real_T *b_nbs, real_T *resol);

// End of code generation (backSort.h)
