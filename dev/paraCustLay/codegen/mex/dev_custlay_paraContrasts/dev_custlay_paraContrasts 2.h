/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * dev_custlay_paraContrasts.h
 *
 * Code generation for function 'dev_custlay_paraContrasts'
 *
 */

#pragma once

/* Include files */
#include "dev_custlay_paraContrasts_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void dev_custlay_paraContrasts(
    const emlrtStack *sp, const struct0_T *problemDef,
    const cell_8 *problemDef_cells, const struct1_T *problemDef_limits,
    const struct2_T *controls, emxArray_real_T *outSsubs,
    emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *sfs,
    emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
    emxArray_real_T *chis, emxArray_cell_wrap_9 *reflectivity,
    emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_10 *shifted_data,
    emxArray_cell_wrap_11 *layerSlds, emxArray_cell_wrap_9 *sldProfiles,
    emxArray_cell_wrap_10 *allLayers, emxArray_real_T *allRoughs);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (dev_custlay_paraContrasts.h) */
