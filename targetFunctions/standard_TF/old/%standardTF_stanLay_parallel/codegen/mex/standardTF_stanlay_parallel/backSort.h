/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * backSort.h
 *
 * Code generation for function 'backSort'
 *
 */

#ifndef BACKSORT_H
#define BACKSORT_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void backSort(const emlrtStack *sp, real_T cBacks, real_T cShifts, real_T
                     cScales, real_T cNbas, real_T cNbss, real_T cRes, const
                     emxArray_real_T *backs, const emxArray_real_T *shifts,
                     const emxArray_real_T *sf, const emxArray_real_T *nba,
                     const emxArray_real_T *nbs, const emxArray_real_T *res,
                     real_T *backg, real_T *qshift, real_T *b_sf, real_T *b_nba,
                     real_T *b_nbs, real_T *resol);

#endif

/* End of code generation (backSort.h) */
