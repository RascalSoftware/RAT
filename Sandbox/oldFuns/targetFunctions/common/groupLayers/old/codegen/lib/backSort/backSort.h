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
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "backSort_types.h"

/* Function Declarations */
extern void backSort(double cBacks, double cShifts, double cScales, double cNbas,
                     double cNbss, double cRes, const emxArray_real_T *backs,
                     const emxArray_real_T *shifts, emxArray_real_T *sf,
                     emxArray_real_T *nba, emxArray_real_T *nbs, const
                     emxArray_real_T *res, double *backg, double *qshift, double
                     *resol);

#endif

/* End of code generation (backSort.h) */
