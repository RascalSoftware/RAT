/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resampleLayers.c
 *
 * Code generation for function 'resampleLayers'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "resampleLayers.h"
#include "reflectivity_calculation_emxutil.h"
#include "combineVectorElements.h"
#include "sum.h"
#include "resample_sld.h"
#include <string.h>

/* Function Definitions */
void resampleLayers(const emxArray_real_T *layerSLD, emxArray_real_T *newSLD)
{
  emxArray_real_T *allNonZero;
  emxArray_real_T *b_yn;
  emxArray_real_T *nx;
  emxArray_real_T *ny;
  emxArray_real_T *thisLayerx;
  emxArray_real_T *thisLayery;
  int i6;
  emxArray_real_T *b_nx;
  int i;
  double diff;
  int i7;
  int loop_ub;
  emxArray_real_T *newSld;
  emxArray_int32_T *ii;
  int idx;
  boolean_T exitg1;
  emxInit_real_T(&allNonZero, 1);
  emxInit_real_T(&b_yn, 1);
  emxInit_real_T(&nx, 2);
  emxInit_real_T(&ny, 2);
  emxInit_real_T(&thisLayerx, 2);
  emxInit_real_T(&thisLayery, 2);
  resample_sld(layerSLD, allNonZero, b_yn);
  i6 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = 1;
  emxEnsureCapacity_real_T(nx, i6);
  nx->data[0] = 0.0;
  i6 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = 1;
  emxEnsureCapacity_real_T(ny, i6);
  ny->data[0] = 0.0;
  i6 = thisLayerx->size[0] * thisLayerx->size[1];
  thisLayerx->size[0] = 1;
  thisLayerx->size[1] = 1;
  emxEnsureCapacity_real_T(thisLayerx, i6);
  thisLayerx->data[0] = allNonZero->data[0];
  i6 = thisLayery->size[0] * thisLayery->size[1];
  thisLayery->size[0] = 1;
  thisLayery->size[1] = 1;
  emxEnsureCapacity_real_T(thisLayery, i6);
  thisLayery->data[0] = b_yn->data[0];
  i6 = allNonZero->size[0];
  emxInit_real_T(&b_nx, 2);
  for (i = 0; i <= i6 - 2; i++) {
    diff = fabs(b_yn->data[1 + i] - b_yn->data[i]);
    if (diff <= 1.0E-8) {
      i7 = thisLayerx->size[1];
      loop_ub = thisLayerx->size[0] * thisLayerx->size[1];
      thisLayerx->size[1] = i7 + 1;
      emxEnsureCapacity_real_T(thisLayerx, loop_ub);
      thisLayerx->data[i7] = allNonZero->data[i];
      i7 = thisLayery->size[1];
      loop_ub = thisLayery->size[0] * thisLayery->size[1];
      thisLayery->size[1] = i7 + 1;
      emxEnsureCapacity_real_T(thisLayery, loop_ub);
      thisLayery->data[i7] = b_yn->data[i] + diff / 2.0;
    } else {
      diff = b_sum(thisLayerx);
      i7 = b_nx->size[0] * b_nx->size[1];
      b_nx->size[0] = 1;
      b_nx->size[1] = nx->size[1] + 1;
      emxEnsureCapacity_real_T(b_nx, i7);
      loop_ub = nx->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        b_nx->data[i7] = nx->data[i7];
      }

      b_nx->data[nx->size[1]] = diff;
      i7 = nx->size[0] * nx->size[1];
      nx->size[0] = 1;
      nx->size[1] = b_nx->size[1];
      emxEnsureCapacity_real_T(nx, i7);
      loop_ub = b_nx->size[0] * b_nx->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        nx->data[i7] = b_nx->data[i7];
      }

      diff = combineVectorElements(thisLayery);
      i7 = b_nx->size[0] * b_nx->size[1];
      b_nx->size[0] = 1;
      b_nx->size[1] = ny->size[1] + 1;
      emxEnsureCapacity_real_T(b_nx, i7);
      loop_ub = ny->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        b_nx->data[i7] = ny->data[i7];
      }

      b_nx->data[ny->size[1]] = diff / (double)thisLayery->size[1];
      i7 = ny->size[0] * ny->size[1];
      ny->size[0] = 1;
      ny->size[1] = b_nx->size[1];
      emxEnsureCapacity_real_T(ny, i7);
      loop_ub = b_nx->size[0] * b_nx->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        ny->data[i7] = b_nx->data[i7];
      }

      i7 = thisLayerx->size[0] * thisLayerx->size[1];
      thisLayerx->size[0] = 1;
      thisLayerx->size[1] = 1;
      emxEnsureCapacity_real_T(thisLayerx, i7);
      thisLayerx->data[0] = allNonZero->data[i];
      i7 = thisLayery->size[0] * thisLayery->size[1];
      thisLayery->size[0] = 1;
      thisLayery->size[1] = 1;
      emxEnsureCapacity_real_T(thisLayery, i7);
      thisLayery->data[0] = b_yn->data[i];
    }
  }

  emxFree_real_T(&b_yn);
  diff = b_sum(thisLayerx);
  i6 = b_nx->size[0] * b_nx->size[1];
  b_nx->size[0] = 1;
  b_nx->size[1] = nx->size[1] + 1;
  emxEnsureCapacity_real_T(b_nx, i6);
  loop_ub = nx->size[1];
  emxFree_real_T(&thisLayerx);
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_nx->data[i6] = nx->data[i6];
  }

  b_nx->data[nx->size[1]] = diff;
  i6 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = b_nx->size[1];
  emxEnsureCapacity_real_T(nx, i6);
  loop_ub = b_nx->size[0] * b_nx->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    nx->data[i6] = b_nx->data[i6];
  }

  diff = combineVectorElements(thisLayery);
  i6 = b_nx->size[0] * b_nx->size[1];
  b_nx->size[0] = 1;
  b_nx->size[1] = ny->size[1] + 1;
  emxEnsureCapacity_real_T(b_nx, i6);
  loop_ub = ny->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_nx->data[i6] = ny->data[i6];
  }

  b_nx->data[ny->size[1]] = diff / (double)thisLayery->size[1];
  i6 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = b_nx->size[1];
  emxEnsureCapacity_real_T(ny, i6);
  loop_ub = b_nx->size[0] * b_nx->size[1];
  emxFree_real_T(&thisLayery);
  for (i6 = 0; i6 < loop_ub; i6++) {
    ny->data[i6] = b_nx->data[i6];
  }

  emxFree_real_T(&b_nx);
  emxInit_real_T(&newSld, 2);
  i = nx->size[1];
  loop_ub = ny->size[1];
  i6 = newSld->size[0] * newSld->size[1];
  newSld->size[0] = i;
  newSld->size[1] = 2;
  emxEnsureCapacity_real_T(newSld, i6);
  for (i6 = 0; i6 < i; i6++) {
    newSld->data[i6] = nx->data[i6];
  }

  emxFree_real_T(&nx);
  for (i6 = 0; i6 < loop_ub; i6++) {
    newSld->data[i6 + newSld->size[0]] = ny->data[i6];
  }

  emxFree_real_T(&ny);
  emxInit_int32_T(&ii, 1);
  i6 = newSld->size[0];
  idx = 0;
  i7 = newSld->size[0];
  loop_ub = ii->size[0];
  ii->size[0] = i7;
  emxEnsureCapacity_int32_T(ii, loop_ub);
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= i6 - 1)) {
    if (newSld->data[i] != 0.0) {
      idx++;
      ii->data[idx - 1] = i + 1;
      if (idx >= i6) {
        exitg1 = true;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }

  if (1 > idx) {
    ii->size[0] = 0;
  } else {
    i6 = ii->size[0];
    ii->size[0] = idx;
    emxEnsureCapacity_int32_T(ii, i6);
  }

  i6 = allNonZero->size[0];
  allNonZero->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(allNonZero, i6);
  loop_ub = ii->size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    allNonZero->data[i6] = ii->data[i6];
  }

  emxFree_int32_T(&ii);
  loop_ub = (int)allNonZero->data[allNonZero->size[0] - 1];
  i = (int)allNonZero->data[allNonZero->size[0] - 1];
  i6 = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = loop_ub;
  newSLD->size[1] = 3;
  emxEnsureCapacity_real_T(newSLD, i6);
  emxFree_real_T(&allNonZero);
  for (i6 = 0; i6 < loop_ub; i6++) {
    newSLD->data[i6] = newSld->data[i6];
  }

  for (i6 = 0; i6 < i; i6++) {
    newSLD->data[i6 + newSLD->size[0]] = newSld->data[i6 + newSld->size[0]];
  }

  emxFree_real_T(&newSld);
  for (i6 = 0; i6 < loop_ub; i6++) {
    newSLD->data[i6 + (newSLD->size[0] << 1)] = 1.0E-20;
  }
}

/* End of code generation (resampleLayers.c) */
