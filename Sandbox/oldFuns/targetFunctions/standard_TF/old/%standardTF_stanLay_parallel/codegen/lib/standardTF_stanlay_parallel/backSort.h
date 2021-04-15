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
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void backSort(double cBacks, double cShifts, double cScales, double cNbas,
                     double cNbss, double cRes, const emxArray_real_T *backs,
                     const emxArray_real_T *shifts, const emxArray_real_T *sf,
                     const emxArray_real_T *nba, const emxArray_real_T *nbs,
                     const emxArray_real_T *res, double *backg, double *qshift,
                     double *b_sf, double *b_nba, double *b_nbs, double *resol);

#endif

/* End of code generation (backSort.h) */
