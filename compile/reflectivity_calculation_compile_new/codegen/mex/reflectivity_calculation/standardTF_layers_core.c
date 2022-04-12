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
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo lh_emlrtRTEI = {
    84,                       /* lineNo */
    47,                       /* colNo */
    "standardTF_layers_core", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_layers_core.m" /* pName */
};

/* Function Definitions */
void b_standardTF_layers_core(
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
    real_T *ssubs)
{
  emlrtStack st;
  emxArray_real_T *b_data;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*    This is the main reflectivity calculation for all Layers models in the
   */
  /*    standard target function.  */
  /*  */
  /*    The function first arranges the  */
  /*    roughness' in the correct order according */
  /*    to geometry. Then, if required it calculates the SLD profile and if */
  /*    requested resamples this into a number of zero-roughness layers */
  /*    (roughness resampling). It the applies any scalefactors and qz shifts */
  /*    the data requires. This is done before calculating the reflectivity to
   */
  /*    ensure that the reflectivity is calculated over the same range in qz as
   */
  /*    the shifted datapoints. The main reflectivity calculation is then */
  /*    called, including the resolution function. The calculation outputs two
   */
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
  /*  ------------------------------------------------------------------------
   */
  /*  */
  /*        (c) Arwel Hughes  -   12/1/21 */
  /*  */
  /*        Last Modified: 12/1/21 by Arwel Hughes. */
  /*  */
  /*  ------------------------------------------------------------------------
   */
  /*  Bulid up the layers matrix for this contrast */
  st.site = &w_emlrtRSI;
  b_groupLayers_Mod(&st, contrastLayers, rough, geometry, nba, nbs, theseLayers,
                    ssubs);
  /*  Make the SLD profiles. */
  /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
  /*  the error af trying to resample a non-existent profile. */
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }
  /*  If calc SLD flag is set, then calculate the SLD profile */
  if (calcSld == 1.0) {
    st.site = &x_emlrtRSI;
    makeSLDProfiles(&st, nba, nbs, theseLayers, *ssubs, repeatLayers,
                    sldProfile);
  } else {
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = 1;
    sldProfile->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &hh_emlrtRTEI);
    sldProfile->data[0] = 0.0;
    sldProfile->data[1] = 0.0;
  }
  /*  If required, then resample the SLD */
  emxInit_real_T(sp, &layerSld, 2, &ph_emlrtRTEI, true);
  if (resample == 1.0) {
    st.site = &y_emlrtRSI;
    resampleLayers(&st, sldProfile, resamPars, layerSld);
    i = resamLayers->size[0] * resamLayers->size[1];
    resamLayers->size[0] = layerSld->size[0];
    resamLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, resamLayers, i, &jh_emlrtRTEI);
    loop_ub = layerSld->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      resamLayers->data[i] = layerSld->data[i];
    }
  } else {
    i = layerSld->size[0] * layerSld->size[1];
    layerSld->size[0] = theseLayers->size[0];
    layerSld->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSld, i, &ih_emlrtRTEI);
    loop_ub = theseLayers->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      layerSld->data[i] = theseLayers->data[i];
    }
    i = resamLayers->size[0] * resamLayers->size[1];
    resamLayers->size[0] = 1;
    resamLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, resamLayers, i, &kh_emlrtRTEI);
    resamLayers->data[0] = 0.0;
    resamLayers->data[1] = 0.0;
    resamLayers->data[2] = 0.0;
  }
  emxInit_real_T(sp, &b_data, 2, &lh_emlrtRTEI, true);
  /*  Apply scale factors and q shifts to the data */
  i = b_data->size[0] * b_data->size[1];
  b_data->size[0] = data->size[0];
  b_data->size[1] = data->size[1];
  emxEnsureCapacity_real_T(sp, b_data, i, &lh_emlrtRTEI);
  loop_ub = data->size[0] * data->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_data->data[i] = data->data[i];
  }
  st.site = &ab_emlrtRSI;
  shiftdata(&st, sf, qshift, dataPresent, b_data, dataLimits, simLimits_data,
            simLimits_size, shifted_dat);
  /*  Calculate the reflectivity */
  st.site = &bb_emlrtRSI;
  callReflectivity(&st, nba, nbs, simLimits_data, simLimits_size, repeatLayers,
                   shifted_dat, layerSld, *ssubs, resol, reflect, Simul);
  /*  Apply background correction, either to the simulation or the data */
  st.site = &cb_emlrtRSI;
  emxFree_real_T(&b_data);
  emxFree_real_T(&layerSld);
  if (backsType != (int32_T)muDoubleScalarFloor(backsType)) {
    emlrtIntegerCheckR2012b(backsType, &db_emlrtDCI, &st);
  }
  switch ((int32_T)backsType) {
  case 1:
    /* Add background to the simulation */
    loop_ub = reflect->size[0] * 2;
    i = reflect->size[0] * reflect->size[1];
    reflect->size[1] = 2;
    emxEnsureCapacity_real_T(&st, reflect, i, &mh_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      reflect->data[i] += background;
    }
    loop_ub = Simul->size[0] * 2;
    i = Simul->size[0] * Simul->size[1];
    Simul->size[1] = 2;
    emxEnsureCapacity_real_T(&st, Simul, i, &oh_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      Simul->data[i] += background;
    }
    break;
  case 2:
    /*          %Subtract the background from the data.. */
    if (2 > shifted_dat->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &wf_emlrtBCI,
                                    &st);
    }
    emxInit_real_T(&st, &b_shifted_dat, 1, &nh_emlrtRTEI, true);
    emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
                                  &shifted_dat->size[0], 1, &emlrtECI, &st);
    loop_ub = shifted_dat->size[0] - 1;
    i = b_shifted_dat->size[0];
    b_shifted_dat->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &nh_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      b_shifted_dat->data[i] =
          shifted_dat->data[i + shifted_dat->size[0]] - background;
    }
    loop_ub = b_shifted_dat->size[0];
    for (i = 0; i < loop_ub; i++) {
      shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
    }
    emxFree_real_T(&b_shifted_dat);
    /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
    break;
  }
  /*  Calculate chi squared. */
  st.site = &db_emlrtRSI;
  *chiSq = chiSquared(&st, shifted_dat, reflect, params);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

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
    real_T *ssubs)
{
  emlrtStack st;
  emxArray_real_T *b_data;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*    This is the main reflectivity calculation for all Layers models in the
   */
  /*    standard target function.  */
  /*  */
  /*    The function first arranges the  */
  /*    roughness' in the correct order according */
  /*    to geometry. Then, if required it calculates the SLD profile and if */
  /*    requested resamples this into a number of zero-roughness layers */
  /*    (roughness resampling). It the applies any scalefactors and qz shifts */
  /*    the data requires. This is done before calculating the reflectivity to
   */
  /*    ensure that the reflectivity is calculated over the same range in qz as
   */
  /*    the shifted datapoints. The main reflectivity calculation is then */
  /*    called, including the resolution function. The calculation outputs two
   */
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
  /*  ------------------------------------------------------------------------
   */
  /*  */
  /*        (c) Arwel Hughes  -   12/1/21 */
  /*  */
  /*        Last Modified: 12/1/21 by Arwel Hughes. */
  /*  */
  /*  ------------------------------------------------------------------------
   */
  /*  Bulid up the layers matrix for this contrast */
  st.site = &w_emlrtRSI;
  groupLayers_Mod(&st, contrastLayers, rough, geometry, nba, nbs, theseLayers,
                  ssubs);
  /*  Make the SLD profiles. */
  /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
  /*  the error af trying to resample a non-existent profile. */
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }
  /*  If calc SLD flag is set, then calculate the SLD profile */
  if (calcSld == 1.0) {
    st.site = &x_emlrtRSI;
    makeSLDProfiles(&st, nba, nbs, theseLayers, *ssubs, repeatLayers,
                    sldProfile);
  } else {
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = 1;
    sldProfile->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &hh_emlrtRTEI);
    sldProfile->data[0] = 0.0;
    sldProfile->data[1] = 0.0;
  }
  /*  If required, then resample the SLD */
  emxInit_real_T(sp, &layerSld, 2, &ph_emlrtRTEI, true);
  if (resample == 1.0) {
    st.site = &y_emlrtRSI;
    resampleLayers(&st, sldProfile, resamPars, layerSld);
    i = resamLayers->size[0] * resamLayers->size[1];
    resamLayers->size[0] = layerSld->size[0];
    resamLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, resamLayers, i, &jh_emlrtRTEI);
    loop_ub = layerSld->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      resamLayers->data[i] = layerSld->data[i];
    }
  } else {
    i = layerSld->size[0] * layerSld->size[1];
    layerSld->size[0] = theseLayers->size[0];
    layerSld->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSld, i, &ih_emlrtRTEI);
    loop_ub = theseLayers->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      layerSld->data[i] = theseLayers->data[i];
    }
    i = resamLayers->size[0] * resamLayers->size[1];
    resamLayers->size[0] = 1;
    resamLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, resamLayers, i, &kh_emlrtRTEI);
    resamLayers->data[0] = 0.0;
    resamLayers->data[1] = 0.0;
    resamLayers->data[2] = 0.0;
  }
  emxInit_real_T(sp, &b_data, 2, &lh_emlrtRTEI, true);
  /*  Apply scale factors and q shifts to the data */
  i = b_data->size[0] * b_data->size[1];
  b_data->size[0] = data->size[0];
  b_data->size[1] = data->size[1];
  emxEnsureCapacity_real_T(sp, b_data, i, &lh_emlrtRTEI);
  loop_ub = data->size[0] * data->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_data->data[i] = data->data[i];
  }
  st.site = &ab_emlrtRSI;
  shiftdata(&st, sf, qshift, dataPresent, b_data, dataLimits, simLimits_data,
            simLimits_size, shifted_dat);
  /*  Calculate the reflectivity */
  st.site = &bb_emlrtRSI;
  callReflectivity(&st, nba, nbs, simLimits_data, simLimits_size, repeatLayers,
                   shifted_dat, layerSld, *ssubs, resol, reflect, Simul);
  /*  Apply background correction, either to the simulation or the data */
  st.site = &cb_emlrtRSI;
  emxFree_real_T(&b_data);
  emxFree_real_T(&layerSld);
  if (backsType != (int32_T)muDoubleScalarFloor(backsType)) {
    emlrtIntegerCheckR2012b(backsType, &db_emlrtDCI, &st);
  }
  switch ((int32_T)backsType) {
  case 1:
    /* Add background to the simulation */
    loop_ub = reflect->size[0] * 2;
    i = reflect->size[0] * reflect->size[1];
    reflect->size[1] = 2;
    emxEnsureCapacity_real_T(&st, reflect, i, &mh_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      reflect->data[i] += background;
    }
    loop_ub = Simul->size[0] * 2;
    i = Simul->size[0] * Simul->size[1];
    Simul->size[1] = 2;
    emxEnsureCapacity_real_T(&st, Simul, i, &oh_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      Simul->data[i] += background;
    }
    break;
  case 2:
    /*          %Subtract the background from the data.. */
    if (2 > shifted_dat->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &wf_emlrtBCI,
                                    &st);
    }
    emxInit_real_T(&st, &b_shifted_dat, 1, &nh_emlrtRTEI, true);
    emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
                                  &shifted_dat->size[0], 1, &emlrtECI, &st);
    loop_ub = shifted_dat->size[0] - 1;
    i = b_shifted_dat->size[0];
    b_shifted_dat->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &nh_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      b_shifted_dat->data[i] =
          shifted_dat->data[i + shifted_dat->size[0]] - background;
    }
    loop_ub = b_shifted_dat->size[0];
    for (i = 0; i < loop_ub; i++) {
      shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
    }
    emxFree_real_T(&b_shifted_dat);
    /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
    break;
  }
  /*  Calculate chi squared. */
  st.site = &db_emlrtRSI;
  *chiSq = chiSquared(&st, shifted_dat, reflect, params);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_layers_core.c) */
