/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_layers_core.h
 *
 * Code generation for function 'standardTF_layers_core'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void b_standardTF_layers_core(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, real_T rough, const emxArray_char_T *geometry, real_T nba,
  real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T qshift, real_T
  dataPresent, const emxArray_real_T *data, const real_T dataLimits[2], const
  real_T simLimits[2], const real_T repeatLayers[2], real_T background, real_T
  resol, real_T backsType, real_T params, emxArray_real_T *sldProfile,
  emxArray_real_T *reflect, emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
  emxArray_real_T *layerSld, real_T *chiSq, real_T *ssubs);
void c_standardTF_layers_core(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, real_T rough, const emxArray_char_T *geometry, real_T nba,
  real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T qshift, real_T
  dataPresent, const emxArray_real_T *data, const real_T dataLimits[2], const
  real_T simLimits[2], const real_T repeatLayers[2], real_T background, real_T
  resol, real_T backsType, real_T params, emxArray_real_T *sldProfile,
  emxArray_real_T *reflect, emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
  emxArray_real_T *layerSld, real_T *chiSq, real_T *ssubs);
void standardTF_layers_core(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, real_T rough, const emxArray_char_T *geometry, real_T nba,
  real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T qshift, real_T
  dataPresent, const emxArray_real_T *data, const real_T dataLimits[2], const
  real_T simLimits[2], const real_T repeatLayers[2], real_T background, real_T
  resol, real_T backsType, real_T params, emxArray_real_T *sldProfile,
  emxArray_real_T *reflect, emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
  emxArray_real_T *layerSld, real_T *chiSq, real_T *ssubs);

/* End of code generation (standardTF_layers_core.h) */
