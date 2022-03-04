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
void standardTF_layers_core(
    const emlrtStack *sp, const emxArray_real_T *contrastLayers, real_T rough,
    const emxArray_char_T *geometry, real_T nba, real_T nbs, real_T resample,
    real_T calcSld, real_T sf, real_T qshift, real_T dataPresent,
    const emxArray_real_T *data, const real_T dataLimits[2],
    const real_T simLimits_data[], const int32_T simLimits_size[2],
    const real_T repeatLayers[2], real_T background, real_T resol,
    real_T backsType, real_T params, const real_T resamPars[2],
    emxArray_real_T *sldProfile, emxArray_real_T *reflect,
    emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
    emxArray_real_T *theseLayers, emxArray_real_T *resamLayers, real_T *chiSq,
    real_T *ssubs);

/* End of code generation (standardTF_layers_core.h) */
