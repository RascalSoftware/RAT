/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfiles.c
 *
 * Code generation for function 'makeSLDProfiles'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_emxutil.h"
#include "asymconvstep.h"
#include "sum.h"

/* Function Definitions */
void makeSLDProfiles(double nbair, double nbsub, const double sld_data[], double
                     ssub, const double repeats[2], emxArray_real_T *sldProfile)
{
  double nrepeats;
  int sld_size[1];
  double b_sld_data[2];
  emxArray_real_T c_sld_data;
  double lastBoxEdge;
  emxArray_real_T *x;
  int i4;
  int loop_ub;
  emxArray_real_T *Lays;
  emxArray_real_T *airBox;
  double nextLayRough;
  emxArray_real_T *thisBox;
  int n;
  int xoffset;
  int vlen;
  emxArray_real_T *SLD;
  int vstride;
  unsigned int sz_idx_0;
  if (repeats[0] == 0.0) {
    nrepeats = 1.0;
  } else {
    nrepeats = repeats[1];
  }

  sld_size[0] = 2;
  b_sld_data[0] = sld_data[0];
  b_sld_data[1] = sld_data[1];
  c_sld_data.data = &b_sld_data[0];
  c_sld_data.size = &sld_size[0];
  c_sld_data.allocatedSize = 2;
  c_sld_data.numDimensions = 1;
  c_sld_data.canFreeData = false;
  lastBoxEdge = sum(&c_sld_data) * nrepeats + 150.0;
  emxInit_real_T(&x, 2);
  if (rtIsNaN(lastBoxEdge)) {
    i4 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 1;
    emxEnsureCapacity_real_T(x, i4);
    x->data[0] = rtNaN;
  } else if (lastBoxEdge < 0.0) {
    x->size[0] = 1;
    x->size[1] = 0;
  } else if (rtIsInf(lastBoxEdge) && (0.0 == lastBoxEdge)) {
    i4 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 1;
    emxEnsureCapacity_real_T(x, i4);
    x->data[0] = rtNaN;
  } else {
    i4 = x->size[0] * x->size[1];
    x->size[0] = 1;
    loop_ub = (int)floor(lastBoxEdge);
    x->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(x, i4);
    for (i4 = 0; i4 <= loop_ub; i4++) {
      x->data[i4] = i4;
    }
  }

  emxInit_real_T(&Lays, 2);
  i4 = Lays->size[0] * Lays->size[1];
  Lays->size[0] = x->size[1];
  Lays->size[1] = (int)(2.0 * nrepeats + 2.0);
  emxEnsureCapacity_real_T(Lays, i4);
  loop_ub = x->size[1] * (int)(2.0 * nrepeats + 2.0);
  for (i4 = 0; i4 < loop_ub; i4++) {
    Lays->data[i4] = 0.0;
  }

  emxInit_real_T(&airBox, 2);
  nextLayRough = sld_data[4];
  asymconvstep(x, 100.0, 0.0, sld_data[4], sld_data[4], nbair, airBox);
  lastBoxEdge = 50.0;
  i4 = (int)nrepeats;
  emxInit_real_T(&thisBox, 2);
  for (n = 0; n < i4; n++) {
    /*              elseif (i == numberOfLayers) && (n < nrepeats) */
    /*                  nextLayRough = layers(1,3); */
    lastBoxEdge += sld_data[0] / 2.0;
    asymconvstep(x, sld_data[0], lastBoxEdge, sld_data[4], sld_data[5],
                 sld_data[2], thisBox);
    xoffset = 2 * n;
    loop_ub = Lays->size[0];
    for (vlen = 0; vlen < loop_ub; vlen++) {
      Lays->data[vlen + Lays->size[0] * xoffset] = thisBox->data[vlen];
    }

    /* plot(x,Lays(:,i)); */
    nextLayRough = ssub;
    lastBoxEdge = (lastBoxEdge + sld_data[0] / 2.0) + sld_data[1] / 2.0;
    asymconvstep(x, sld_data[1], lastBoxEdge, sld_data[5], ssub, sld_data[3],
                 thisBox);
    xoffset = 2 * n + 1;
    loop_ub = Lays->size[0];
    for (vlen = 0; vlen < loop_ub; vlen++) {
      Lays->data[vlen + Lays->size[0] * xoffset] = thisBox->data[vlen];
    }

    lastBoxEdge += sld_data[1] / 2.0;

    /* plot(x,Lays(:,i)); */
  }

  /* layers(end,3); */
  i4 = (int)(2.0 * nrepeats + 1.0) - 1;
  asymconvstep(x, (x->data[x->size[1] - 1] - lastBoxEdge) * 2.0, x->data[x->
               size[1] - 1], nextLayRough, ssub, nbsub, thisBox);
  loop_ub = Lays->size[0];
  for (xoffset = 0; xoffset < loop_ub; xoffset++) {
    Lays->data[xoffset + Lays->size[0] * i4] = thisBox->data[xoffset];
  }

  emxFree_real_T(&thisBox);

  /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
  i4 = (int)(2.0 * nrepeats + 2.0) - 1;
  loop_ub = Lays->size[0];
  for (xoffset = 0; xoffset < loop_ub; xoffset++) {
    Lays->data[xoffset + Lays->size[0] * i4] = airBox->data[xoffset];
  }

  emxFree_real_T(&airBox);

  /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
  vlen = Lays->size[1];
  emxInit_real_T(&SLD, 1);
  if ((Lays->size[0] == 0) || (Lays->size[1] == 0)) {
    sz_idx_0 = (unsigned int)Lays->size[0];
    i4 = SLD->size[0];
    SLD->size[0] = (int)sz_idx_0;
    emxEnsureCapacity_real_T(SLD, i4);
    loop_ub = (int)sz_idx_0;
    for (i4 = 0; i4 < loop_ub; i4++) {
      SLD->data[i4] = 0.0;
    }
  } else {
    vstride = Lays->size[0];
    i4 = SLD->size[0];
    SLD->size[0] = Lays->size[0];
    emxEnsureCapacity_real_T(SLD, i4);
    for (loop_ub = 0; loop_ub < vstride; loop_ub++) {
      SLD->data[loop_ub] = Lays->data[loop_ub];
    }

    for (n = 2; n <= vlen; n++) {
      xoffset = (n - 1) * vstride;
      for (loop_ub = 0; loop_ub < vstride; loop_ub++) {
        SLD->data[loop_ub] += Lays->data[xoffset + loop_ub];
      }
    }
  }

  emxFree_real_T(&Lays);

  /* plot(x,SLD) */
  loop_ub = x->size[1];
  i4 = sldProfile->size[0] * sldProfile->size[1];
  sldProfile->size[0] = loop_ub;
  sldProfile->size[1] = 2;
  emxEnsureCapacity_real_T(sldProfile, i4);
  for (i4 = 0; i4 < loop_ub; i4++) {
    sldProfile->data[i4] = x->data[i4];
  }

  emxFree_real_T(&x);
  loop_ub = SLD->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    sldProfile->data[i4 + sldProfile->size[0]] = SLD->data[i4];
  }

  emxFree_real_T(&SLD);
}

/* End of code generation (makeSLDProfiles.c) */
