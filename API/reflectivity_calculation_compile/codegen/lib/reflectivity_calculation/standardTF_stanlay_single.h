/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single.h
 *
 * Code generation for function 'standardTF_stanlay_single'
 *
 */

#ifndef STANDARDTF_STANLAY_SINGLE_H
#define STANDARDTF_STANLAY_SINGLE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void standardTF_stanlay_single(const double resample[7], double
  numberOfContrasts, const char geometry[13], const cell_wrap_0 repeatLayers[7],
  const double cBacks[7], const double cNbss[7], const double backs[2], double
  shifts, double sf, double nba, const double nbs[2], const double res_data[],
  const double dataPresent[7], const cell_wrap_1 allData[7], const cell_wrap_0
  dataLimits[7], const cell_wrap_0 simLimits[7], const double params[10], const
  cell_wrap_0 contrastLayers[7], const cell_wrap_2 layersDetails[4], const
  double backsType[7], emxArray_real_T *outSsubs, emxArray_real_T *backgs,
  emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
  emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
  emxArray_cell_wrap_11 *reflectivity, emxArray_cell_wrap_11 *Simulation,
  emxArray_cell_wrap_12 *shifted_data, emxArray_cell_wrap_12 *layerSlds,
  emxArray_cell_wrap_11 *sldProfiles, emxArray_cell_wrap_14 *allLayers,
  emxArray_real_T *allRoughs);

#endif

/* End of code generation (standardTF_stanlay_single.h) */
