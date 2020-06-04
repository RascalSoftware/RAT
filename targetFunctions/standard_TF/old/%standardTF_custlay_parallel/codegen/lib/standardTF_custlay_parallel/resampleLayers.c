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
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "resampleLayers.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "mean.h"
#include "sum.h"
#include "resample_sld.h"

/* Function Definitions */
void resampleLayers(const emxArray_real_T *layerSLD, emxArray_real_T *newSLD)
{
  emxArray_real_T *allNonZero;
  emxArray_real_T *b_yn;
  emxArray_real_T *nx;
  emxArray_real_T *ny;
  emxArray_real_T *thisLayerx;
  emxArray_real_T *thisLayery;
  int i4;
  int i;
  emxArray_real_T *b_nx;
  emxArray_real_T *b_ny;
  int exitg2;
  int idx;
  double diff;
  int nx_idx_0;
  emxArray_real_T *c_nx;
  int loop_ub;
  emxArray_real_T *c_ny;
  emxArray_real_T *newSld;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *b_newSld;
  emxArray_real_T *c_newSld;
  emxInit_real_T1(&allNonZero, 1);
  emxInit_real_T1(&b_yn, 1);
  emxInit_real_T(&nx, 2);
  emxInit_real_T(&ny, 2);
  emxInit_real_T(&thisLayerx, 2);
  emxInit_real_T(&thisLayery, 2);
  resample_sld(layerSLD, allNonZero, b_yn);
  i4 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)nx, i4, (int)sizeof(double));
  i4 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)ny, i4, (int)sizeof(double));
  i4 = thisLayerx->size[0] * thisLayerx->size[1];
  thisLayerx->size[0] = 1;
  thisLayerx->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)thisLayerx, i4, (int)sizeof(double));
  thisLayerx->data[0] = allNonZero->data[0];
  i4 = thisLayery->size[0] * thisLayery->size[1];
  thisLayery->size[0] = 1;
  thisLayery->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)thisLayery, i4, (int)sizeof(double));
  thisLayery->data[0] = b_yn->data[0];
  i = 0;
  emxInit_real_T(&b_nx, 2);
  emxInit_real_T(&b_ny, 2);
  do {
    exitg2 = 0;
    idx = allNonZero->size[0];
    if (i <= idx - 2) {
      diff = fabs(b_yn->data[1 + i] - b_yn->data[i]);
      if (diff <= 1.0E-8) {
        nx_idx_0 = thisLayerx->size[1];
        i4 = thisLayerx->size[0] * thisLayerx->size[1];
        thisLayerx->size[1] = nx_idx_0 + 1;
        emxEnsureCapacity((emxArray__common *)thisLayerx, i4, (int)sizeof(double));
        thisLayerx->data[nx_idx_0] = allNonZero->data[i];
        nx_idx_0 = thisLayery->size[1];
        i4 = thisLayery->size[0] * thisLayery->size[1];
        thisLayery->size[1] = nx_idx_0 + 1;
        emxEnsureCapacity((emxArray__common *)thisLayery, i4, (int)sizeof(double));
        thisLayery->data[nx_idx_0] = b_yn->data[i] + diff / 2.0;
      } else {
        diff = b_sum(thisLayerx);
        i4 = b_nx->size[0] * b_nx->size[1];
        b_nx->size[0] = 1;
        b_nx->size[1] = nx->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)b_nx, i4, (int)sizeof(double));
        loop_ub = nx->size[1];
        for (i4 = 0; i4 < loop_ub; i4++) {
          b_nx->data[b_nx->size[0] * i4] = nx->data[nx->size[0] * i4];
        }

        b_nx->data[b_nx->size[0] * nx->size[1]] = diff;
        i4 = nx->size[0] * nx->size[1];
        nx->size[0] = 1;
        nx->size[1] = b_nx->size[1];
        emxEnsureCapacity((emxArray__common *)nx, i4, (int)sizeof(double));
        loop_ub = b_nx->size[1];
        for (i4 = 0; i4 < loop_ub; i4++) {
          nx->data[nx->size[0] * i4] = b_nx->data[b_nx->size[0] * i4];
        }

        diff = mean(thisLayery);
        i4 = b_ny->size[0] * b_ny->size[1];
        b_ny->size[0] = 1;
        b_ny->size[1] = ny->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)b_ny, i4, (int)sizeof(double));
        loop_ub = ny->size[1];
        for (i4 = 0; i4 < loop_ub; i4++) {
          b_ny->data[b_ny->size[0] * i4] = ny->data[ny->size[0] * i4];
        }

        b_ny->data[b_ny->size[0] * ny->size[1]] = diff;
        i4 = ny->size[0] * ny->size[1];
        ny->size[0] = 1;
        ny->size[1] = b_ny->size[1];
        emxEnsureCapacity((emxArray__common *)ny, i4, (int)sizeof(double));
        loop_ub = b_ny->size[1];
        for (i4 = 0; i4 < loop_ub; i4++) {
          ny->data[ny->size[0] * i4] = b_ny->data[b_ny->size[0] * i4];
        }

        i4 = thisLayerx->size[0] * thisLayerx->size[1];
        thisLayerx->size[0] = 1;
        thisLayerx->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)thisLayerx, i4, (int)sizeof(double));
        thisLayerx->data[0] = allNonZero->data[i];
        i4 = thisLayery->size[0] * thisLayery->size[1];
        thisLayery->size[0] = 1;
        thisLayery->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)thisLayery, i4, (int)sizeof(double));
        thisLayery->data[0] = b_yn->data[i];
      }

      i++;
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_ny);
  emxFree_real_T(&b_nx);
  emxFree_real_T(&b_yn);
  emxInit_real_T(&c_nx, 2);
  diff = b_sum(thisLayerx);
  i4 = c_nx->size[0] * c_nx->size[1];
  c_nx->size[0] = 1;
  c_nx->size[1] = nx->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)c_nx, i4, (int)sizeof(double));
  loop_ub = nx->size[1];
  emxFree_real_T(&thisLayerx);
  for (i4 = 0; i4 < loop_ub; i4++) {
    c_nx->data[c_nx->size[0] * i4] = nx->data[nx->size[0] * i4];
  }

  c_nx->data[c_nx->size[0] * nx->size[1]] = diff;
  i4 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = c_nx->size[1];
  emxEnsureCapacity((emxArray__common *)nx, i4, (int)sizeof(double));
  loop_ub = c_nx->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    nx->data[nx->size[0] * i4] = c_nx->data[c_nx->size[0] * i4];
  }

  emxFree_real_T(&c_nx);
  emxInit_real_T(&c_ny, 2);
  diff = mean(thisLayery);
  i4 = c_ny->size[0] * c_ny->size[1];
  c_ny->size[0] = 1;
  c_ny->size[1] = ny->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)c_ny, i4, (int)sizeof(double));
  loop_ub = ny->size[1];
  emxFree_real_T(&thisLayery);
  for (i4 = 0; i4 < loop_ub; i4++) {
    c_ny->data[c_ny->size[0] * i4] = ny->data[ny->size[0] * i4];
  }

  c_ny->data[c_ny->size[0] * ny->size[1]] = diff;
  i4 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = c_ny->size[1];
  emxEnsureCapacity((emxArray__common *)ny, i4, (int)sizeof(double));
  loop_ub = c_ny->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    ny->data[ny->size[0] * i4] = c_ny->data[c_ny->size[0] * i4];
  }

  emxFree_real_T(&c_ny);
  emxInit_real_T(&newSld, 2);
  nx_idx_0 = nx->size[1];
  i = ny->size[1];
  i4 = newSld->size[0] * newSld->size[1];
  newSld->size[0] = nx_idx_0;
  newSld->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)newSld, i4, (int)sizeof(double));
  for (i4 = 0; i4 < nx_idx_0; i4++) {
    newSld->data[i4] = nx->data[i4];
  }

  emxFree_real_T(&nx);
  for (i4 = 0; i4 < i; i4++) {
    newSld->data[i4 + newSld->size[0]] = ny->data[i4];
  }

  emxFree_real_T(&ny);
  emxInit_int32_T(&ii, 1);
  i4 = newSld->size[0];
  idx = 0;
  nx_idx_0 = newSld->size[0];
  i = ii->size[0];
  ii->size[0] = nx_idx_0;
  emxEnsureCapacity((emxArray__common *)ii, i, (int)sizeof(int));
  nx_idx_0 = 1;
  exitg1 = false;
  while ((!exitg1) && (nx_idx_0 <= i4)) {
    guard1 = false;
    if (newSld->data[nx_idx_0 - 1] != 0.0) {
      idx++;
      ii->data[idx - 1] = nx_idx_0;
      if (idx >= i4) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      nx_idx_0++;
    }
  }

  i4 = newSld->size[0];
  if (i4 == 1) {
    if (idx == 0) {
      i4 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i4, (int)sizeof(int));
    }
  } else {
    i4 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i4, (int)sizeof(int));
  }

  i4 = allNonZero->size[0];
  allNonZero->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)allNonZero, i4, (int)sizeof(double));
  loop_ub = ii->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    allNonZero->data[i4] = ii->data[i4];
  }

  emxFree_int32_T(&ii);
  if (1.0 > allNonZero->data[allNonZero->size[0] - 1]) {
    loop_ub = 0;
  } else {
    loop_ub = (int)allNonZero->data[allNonZero->size[0] - 1];
  }

  if (1.0 > allNonZero->data[allNonZero->size[0] - 1]) {
    nx_idx_0 = 0;
  } else {
    nx_idx_0 = (int)allNonZero->data[allNonZero->size[0] - 1];
  }

  i4 = allNonZero->size[0];
  allNonZero->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)allNonZero, i4, (int)sizeof(double));
  for (i4 = 0; i4 < loop_ub; i4++) {
    allNonZero->data[i4] = 1.0E-20;
  }

  emxInit_real_T1(&b_newSld, 1);
  i4 = b_newSld->size[0];
  b_newSld->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_newSld, i4, (int)sizeof(double));
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_newSld->data[i4] = newSld->data[i4];
  }

  emxInit_real_T1(&c_newSld, 1);
  i4 = c_newSld->size[0];
  c_newSld->size[0] = nx_idx_0;
  emxEnsureCapacity((emxArray__common *)c_newSld, i4, (int)sizeof(double));
  for (i4 = 0; i4 < nx_idx_0; i4++) {
    c_newSld->data[i4] = newSld->data[i4 + newSld->size[0]];
  }

  emxFree_real_T(&newSld);
  idx = allNonZero->size[0];
  i4 = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = loop_ub;
  newSLD->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)newSLD, i4, (int)sizeof(double));
  for (i4 = 0; i4 < loop_ub; i4++) {
    newSLD->data[i4] = b_newSld->data[i4];
  }

  emxFree_real_T(&b_newSld);
  for (i4 = 0; i4 < nx_idx_0; i4++) {
    newSLD->data[i4 + newSLD->size[0]] = c_newSld->data[i4];
  }

  emxFree_real_T(&c_newSld);
  for (i4 = 0; i4 < idx; i4++) {
    newSLD->data[i4 + (newSLD->size[0] << 1)] = allNonZero->data[i4];
  }

  emxFree_real_T(&allNonZero);
}

/* End of code generation (resampleLayers.c) */
