/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_layers_core.c
 *
 * Code generation for function 'standardTF_layers_core'
 *
 */

/* Include files */
#include "standardTF_layers_core.h"
#include "applyBackgroundCorrection.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfileXY.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"

/* Function Definitions */
void b_standardTF_layers_core(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, real_T rough, const emxArray_char_T *geometry, real_T nba,
  real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T qshift, real_T
  dataPresent, const emxArray_real_T *data, const real_T dataLimits[2], const
  real_T simLimits[2], const real_T repeatLayers[2], real_T background, real_T
  resol, real_T backsType, real_T params, emxArray_real_T *sldProfile,
  emxArray_real_T *reflect, emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
  emxArray_real_T *layerSld, real_T *chiSq, real_T *ssubs)
{
  emxArray_real_T *b_sldProfile;
  int32_T i;
  real_T reps;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);

  /*  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... */
  /*      standardTF_stanlay_core(contrastLayers, rough, ... */
  /*      geometry, nba, nbs, resample, calcSld, sf, qshift,... */
  /*      dataPresent, data, dataLimits, simLimits, repeatLayers,... */
  /*      background,resol,backsType,params,paralellPoints) */
  /*  */
  /*    This is the main reflectivity calculation for Layers models in the  */
  /*    standard target function. The function first arranges the  */
  /*    roughness' in the correct order according */
  /*    to geometry. Then, if required it calculates the SLD profile and if */
  /*    requested resamples this into a number of zero-roughness layers */
  /*    (roughness resampling). It the applies any scalefactors and qz shifts */
  /*    the data requires. This is done before calculating the reflectivity to */
  /*    ensure that the reflectivity is calculated over the same range in qz as */
  /*    the shifted datapoints. The main reflectivity calculation is then */
  /*    called, including the resolution function. The calculation outputs two */
  /*    profiles - 'reflect' which is the same range as the points, and */
  /*    'Simulation' which can be a different range to allow extrapolation. */
  /*    The background correction is the applied, and finally chi-squared is  */
  /*    calculated. */
  /*  */
  /*  Inputs: */
  /*    contrastLayers  : */
  /*    rough           : */
  /*    geometry        : */
  /*    nba             : */
  /*    nbs             : */
  /*    resample        : */
  /*    calcSld         : */
  /*    sf              : */
  /*    qshift          : */
  /*    dataPresent     : */
  /*    data            : */
  /*    dataLimits      : */
  /*    simLimits       : */
  /*    repeatLayers    : */
  /*    background      : */
  /*    resol           : */
  /*    backsType       : */
  /*    params          : */
  /*    paralellPoints  : */
  /*  */
  /*  Outputs: */
  /*  */
  /*  */
  /*  */
  /*  ------------------------------------------------------------------------ */
  /*  */
  /*        (c) Arwel Hughes  -   12/1/21 */
  /*  */
  /*        Last Modified: 12/1/21 by Arwel Hughes. */
  /*  */
  /*  ------------------------------------------------------------------------ */
  /*  Bulid up the layers matrix for this contrast */
  st.site = &o_emlrtRSI;
  groupLayers_Mod(&st, contrastLayers, rough, geometry, nba, nbs, layerSld,
                  ssubs);

  /*  Make the SLD profiles. */
  /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
  /*  the error af trying to resample a non-existent profile. */
  if (covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 0, resample == 1.0) &&
      covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 1, calcSld == 0.0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
    calcSld = 1.0;
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, false);
  }

  /*  If cal SLD flag is set, then calculate the SLD profile */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, calcSld == 1.0)) {
    emxInit_real_T(sp, &b_sldProfile, 2, &yg_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);
    st.site = &p_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 11U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0U);
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, repeatLayers[0] == 0.0))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1U);
      reps = 1.0;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2U);
      reps = repeatLayers[1];
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3U);
    b_st.site = &jb_emlrtRSI;
    makeSLDProfileXY(&b_st, nba, nbs, *ssubs, layerSld, layerSld->size[0], reps,
                     b_sldProfile);
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = b_sldProfile->size[0];
    sldProfile->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &wg_emlrtRTEI);
    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    for (i = 0; i < loop_ub; i++) {
      sldProfile->data[i] = b_sldProfile->data[i];
    }

    emxFree_real_T(&b_sldProfile);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = 1;
    sldProfile->size[1] = 3;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &vg_emlrtRTEI);
    sldProfile->data[0] = 0.0;
    sldProfile->data[1] = 0.0;
    sldProfile->data[2] = 0.0;
  }

  /*  If required, then resample the SLD */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 2, resample == 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4U);
    st.site = &q_emlrtRSI;
    resampleLayers(&st, sldProfile, layerSld);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5U);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6U);

  /*  Apply scale factors and q shifts to the data */
  i = shifted_dat->size[0] * shifted_dat->size[1];
  shifted_dat->size[0] = data->size[0];
  shifted_dat->size[1] = 3;
  emxEnsureCapacity_real_T(sp, shifted_dat, i, &xg_emlrtRTEI);
  loop_ub = data->size[0] * data->size[1];
  for (i = 0; i < loop_ub; i++) {
    shifted_dat->data[i] = data->data[i];
  }

  st.site = &r_emlrtRSI;
  shiftdata(&st, sf, qshift, dataPresent, shifted_dat, dataLimits);

  /*  Calculate the reflectivity */
  st.site = &s_emlrtRSI;
  b_callReflectivity(&st, nba, nbs, simLimits, repeatLayers, shifted_dat,
                     layerSld, *ssubs, resol, reflect, Simul);

  /*  Apply background correction, either to the simulation or the data */
  st.site = &t_emlrtRSI;
  applyBackgroundCorrection(&st, reflect, Simul, shifted_dat, background,
    backsType);

  /*  Calculate chi squared. */
  st.site = &u_emlrtRSI;
  *chiSq = chiSquared(&st, shifted_dat, reflect, params);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_standardTF_layers_core(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, real_T rough, const emxArray_char_T *geometry, real_T nba,
  real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T qshift, real_T
  dataPresent, const emxArray_real_T *data, const real_T dataLimits[2], const
  real_T simLimits[2], const real_T repeatLayers[2], real_T background, real_T
  resol, real_T backsType, real_T params, emxArray_real_T *sldProfile,
  emxArray_real_T *reflect, emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
  emxArray_real_T *layerSld, real_T *chiSq, real_T *ssubs)
{
  emxArray_real_T *b_sldProfile;
  int32_T i;
  real_T reps;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);

  /*  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... */
  /*      standardTF_stanlay_core(contrastLayers, rough, ... */
  /*      geometry, nba, nbs, resample, calcSld, sf, qshift,... */
  /*      dataPresent, data, dataLimits, simLimits, repeatLayers,... */
  /*      background,resol,backsType,params,paralellPoints) */
  /*  */
  /*    This is the main reflectivity calculation for Layers models in the  */
  /*    standard target function. The function first arranges the  */
  /*    roughness' in the correct order according */
  /*    to geometry. Then, if required it calculates the SLD profile and if */
  /*    requested resamples this into a number of zero-roughness layers */
  /*    (roughness resampling). It the applies any scalefactors and qz shifts */
  /*    the data requires. This is done before calculating the reflectivity to */
  /*    ensure that the reflectivity is calculated over the same range in qz as */
  /*    the shifted datapoints. The main reflectivity calculation is then */
  /*    called, including the resolution function. The calculation outputs two */
  /*    profiles - 'reflect' which is the same range as the points, and */
  /*    'Simulation' which can be a different range to allow extrapolation. */
  /*    The background correction is the applied, and finally chi-squared is  */
  /*    calculated. */
  /*  */
  /*  Inputs: */
  /*    contrastLayers  : */
  /*    rough           : */
  /*    geometry        : */
  /*    nba             : */
  /*    nbs             : */
  /*    resample        : */
  /*    calcSld         : */
  /*    sf              : */
  /*    qshift          : */
  /*    dataPresent     : */
  /*    data            : */
  /*    dataLimits      : */
  /*    simLimits       : */
  /*    repeatLayers    : */
  /*    background      : */
  /*    resol           : */
  /*    backsType       : */
  /*    params          : */
  /*    paralellPoints  : */
  /*  */
  /*  Outputs: */
  /*  */
  /*  */
  /*  */
  /*  ------------------------------------------------------------------------ */
  /*  */
  /*        (c) Arwel Hughes  -   12/1/21 */
  /*  */
  /*        Last Modified: 12/1/21 by Arwel Hughes. */
  /*  */
  /*  ------------------------------------------------------------------------ */
  /*  Bulid up the layers matrix for this contrast */
  st.site = &o_emlrtRSI;
  b_groupLayers_Mod(&st, contrastLayers, rough, geometry, layerSld, ssubs);

  /*  Make the SLD profiles. */
  /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
  /*  the error af trying to resample a non-existent profile. */
  if (covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 0, resample == 1.0) &&
      covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 1, calcSld == 0.0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
    calcSld = 1.0;
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, false);
  }

  /*  If cal SLD flag is set, then calculate the SLD profile */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, calcSld == 1.0)) {
    emxInit_real_T(sp, &b_sldProfile, 2, &yg_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);
    st.site = &p_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 11U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0U);
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, repeatLayers[0] == 0.0))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1U);
      reps = 1.0;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2U);
      reps = repeatLayers[1];
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3U);
    b_st.site = &jb_emlrtRSI;
    makeSLDProfileXY(&b_st, nba, nbs, *ssubs, layerSld, layerSld->size[0], reps,
                     b_sldProfile);
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = b_sldProfile->size[0];
    sldProfile->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &wg_emlrtRTEI);
    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    for (i = 0; i < loop_ub; i++) {
      sldProfile->data[i] = b_sldProfile->data[i];
    }

    emxFree_real_T(&b_sldProfile);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = 1;
    sldProfile->size[1] = 3;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &vg_emlrtRTEI);
    sldProfile->data[0] = 0.0;
    sldProfile->data[1] = 0.0;
    sldProfile->data[2] = 0.0;
  }

  /*  If required, then resample the SLD */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 2, resample == 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4U);
    st.site = &q_emlrtRSI;
    resampleLayers(&st, sldProfile, layerSld);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5U);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6U);

  /*  Apply scale factors and q shifts to the data */
  i = shifted_dat->size[0] * shifted_dat->size[1];
  shifted_dat->size[0] = data->size[0];
  shifted_dat->size[1] = 3;
  emxEnsureCapacity_real_T(sp, shifted_dat, i, &xg_emlrtRTEI);
  loop_ub = data->size[0] * data->size[1];
  for (i = 0; i < loop_ub; i++) {
    shifted_dat->data[i] = data->data[i];
  }

  st.site = &r_emlrtRSI;
  shiftdata(&st, sf, qshift, dataPresent, shifted_dat, dataLimits);

  /*  Calculate the reflectivity */
  st.site = &s_emlrtRSI;
  callReflectivity(&st, nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   *ssubs, resol, reflect, Simul);

  /*  Apply background correction, either to the simulation or the data */
  st.site = &t_emlrtRSI;
  applyBackgroundCorrection(&st, reflect, Simul, shifted_dat, background,
    backsType);

  /*  Calculate chi squared. */
  st.site = &u_emlrtRSI;
  *chiSq = chiSquared(&st, shifted_dat, reflect, params);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void standardTF_layers_core(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, real_T rough, const emxArray_char_T *geometry, real_T nba,
  real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T qshift, real_T
  dataPresent, const emxArray_real_T *data, const real_T dataLimits[2], const
  real_T simLimits[2], const real_T repeatLayers[2], real_T background, real_T
  resol, real_T backsType, real_T params, emxArray_real_T *sldProfile,
  emxArray_real_T *reflect, emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
  emxArray_real_T *layerSld, real_T *chiSq, real_T *ssubs)
{
  emxArray_real_T *b_sldProfile;
  int32_T i;
  real_T reps;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);

  /*  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... */
  /*      standardTF_stanlay_core(contrastLayers, rough, ... */
  /*      geometry, nba, nbs, resample, calcSld, sf, qshift,... */
  /*      dataPresent, data, dataLimits, simLimits, repeatLayers,... */
  /*      background,resol,backsType,params,paralellPoints) */
  /*  */
  /*    This is the main reflectivity calculation for Layers models in the  */
  /*    standard target function. The function first arranges the  */
  /*    roughness' in the correct order according */
  /*    to geometry. Then, if required it calculates the SLD profile and if */
  /*    requested resamples this into a number of zero-roughness layers */
  /*    (roughness resampling). It the applies any scalefactors and qz shifts */
  /*    the data requires. This is done before calculating the reflectivity to */
  /*    ensure that the reflectivity is calculated over the same range in qz as */
  /*    the shifted datapoints. The main reflectivity calculation is then */
  /*    called, including the resolution function. The calculation outputs two */
  /*    profiles - 'reflect' which is the same range as the points, and */
  /*    'Simulation' which can be a different range to allow extrapolation. */
  /*    The background correction is the applied, and finally chi-squared is  */
  /*    calculated. */
  /*  */
  /*  Inputs: */
  /*    contrastLayers  : */
  /*    rough           : */
  /*    geometry        : */
  /*    nba             : */
  /*    nbs             : */
  /*    resample        : */
  /*    calcSld         : */
  /*    sf              : */
  /*    qshift          : */
  /*    dataPresent     : */
  /*    data            : */
  /*    dataLimits      : */
  /*    simLimits       : */
  /*    repeatLayers    : */
  /*    background      : */
  /*    resol           : */
  /*    backsType       : */
  /*    params          : */
  /*    paralellPoints  : */
  /*  */
  /*  Outputs: */
  /*  */
  /*  */
  /*  */
  /*  ------------------------------------------------------------------------ */
  /*  */
  /*        (c) Arwel Hughes  -   12/1/21 */
  /*  */
  /*        Last Modified: 12/1/21 by Arwel Hughes. */
  /*  */
  /*  ------------------------------------------------------------------------ */
  /*  Bulid up the layers matrix for this contrast */
  st.site = &o_emlrtRSI;
  groupLayers_Mod(&st, contrastLayers, rough, geometry, nba, nbs, layerSld,
                  ssubs);

  /*  Make the SLD profiles. */
  /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
  /*  the error af trying to resample a non-existent profile. */
  if (covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 0, resample == 1.0) &&
      covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 1, calcSld == 0.0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
    calcSld = 1.0;
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, false);
  }

  /*  If cal SLD flag is set, then calculate the SLD profile */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, calcSld == 1.0)) {
    emxInit_real_T(sp, &b_sldProfile, 2, &yg_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);
    st.site = &p_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 11U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0U);
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, repeatLayers[0] == 0.0))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1U);
      reps = 1.0;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2U);
      reps = repeatLayers[1];
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3U);
    b_st.site = &jb_emlrtRSI;
    makeSLDProfileXY(&b_st, nba, nbs, *ssubs, layerSld, layerSld->size[0], reps,
                     b_sldProfile);
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = b_sldProfile->size[0];
    sldProfile->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &wg_emlrtRTEI);
    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    for (i = 0; i < loop_ub; i++) {
      sldProfile->data[i] = b_sldProfile->data[i];
    }

    emxFree_real_T(&b_sldProfile);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = 1;
    sldProfile->size[1] = 3;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &vg_emlrtRTEI);
    sldProfile->data[0] = 0.0;
    sldProfile->data[1] = 0.0;
    sldProfile->data[2] = 0.0;
  }

  /*  If required, then resample the SLD */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 2, resample == 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4U);
    st.site = &q_emlrtRSI;
    resampleLayers(&st, sldProfile, layerSld);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5U);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6U);

  /*  Apply scale factors and q shifts to the data */
  i = shifted_dat->size[0] * shifted_dat->size[1];
  shifted_dat->size[0] = data->size[0];
  shifted_dat->size[1] = 3;
  emxEnsureCapacity_real_T(sp, shifted_dat, i, &xg_emlrtRTEI);
  loop_ub = data->size[0] * data->size[1];
  for (i = 0; i < loop_ub; i++) {
    shifted_dat->data[i] = data->data[i];
  }

  st.site = &r_emlrtRSI;
  shiftdata(&st, sf, qshift, dataPresent, shifted_dat, dataLimits);

  /*  Calculate the reflectivity */
  st.site = &s_emlrtRSI;
  callReflectivity(&st, nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   *ssubs, resol, reflect, Simul);

  /*  Apply background correction, either to the simulation or the data */
  st.site = &t_emlrtRSI;
  applyBackgroundCorrection(&st, reflect, Simul, shifted_dat, background,
    backsType);

  /*  Calculate chi squared. */
  st.site = &u_emlrtRSI;
  *chiSq = chiSquared(&st, shifted_dat, reflect, params);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_layers_core.c) */
