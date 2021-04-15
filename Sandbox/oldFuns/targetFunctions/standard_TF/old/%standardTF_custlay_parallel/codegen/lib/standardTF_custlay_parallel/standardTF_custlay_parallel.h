/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_parallel.h
 *
 * Code generation for function 'standardTF_custlay_parallel'
 *
 */

#ifndef STANDARDTF_CUSTLAY_PARALLEL_H
#define STANDARDTF_CUSTLAY_PARALLEL_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_custlay_parallel_types.h"

/* Function Declarations */
extern void standardTF_custlay_parallel(const emxArray_real_T *resam, double
  numberOfContrasts, const emxArray_char_T *geometry, const emxArray_real_T
  *nbairs, const emxArray_real_T *nbsubs, const emxArray_cell_wrap_0 *repeats,
  const emxArray_real_T *cBacks, const emxArray_real_T *cShifts, const
  emxArray_real_T *cScales, const emxArray_real_T *cNbas, const emxArray_real_T *
  cNbss, const emxArray_real_T *cRes, const emxArray_real_T *backs, const
  emxArray_real_T *shifts, const emxArray_real_T *sf, const emxArray_real_T *nba,
  const emxArray_real_T *nbs, const emxArray_real_T *res, const emxArray_real_T *
  dataPresent, const emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_0
  *dataLimits, const emxArray_cell_wrap_0 *simLimits, const emxArray_cell_wrap_0
  *repeatLayers, double nParams, const emxArray_real_T *params, const
  emxArray_cell_wrap_2 *contrastLayers, double numberOfLayers, double whichType,
  const emxArray_char_T *fileHandle, const emxArray_char_T *path,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_3
  *reflectivity, emxArray_cell_wrap_3 *Simulation, emxArray_cell_wrap_1
  *shifted_data, emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_3
  *sldProfiles, emxArray_cell_wrap_4 *allLayers, emxArray_real_T *allRoughs);

#endif

/* End of code generation (standardTF_custlay_parallel.h) */
