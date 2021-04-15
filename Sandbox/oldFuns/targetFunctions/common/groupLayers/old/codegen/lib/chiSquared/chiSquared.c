/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * chiSquared.c
 *
 * Code generation for function 'chiSquared'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "chiSquared.h"
#include "chiSquared_emxutil.h"

/* Function Definitions */
double chiSquared(const emxArray_real_T *thisData, const emxArray_real_T
                  *thisFit, double P)
{
  double chi2;
  int mtmp;
  double N;
  emxArray_real_T *n;
  int i0;
  emxArray_real_T *terms;
  unsigned int n_idx_0;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  double y;

  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  mtmp = thisData->size[0];
  if (1 > mtmp) {
    mtmp = 1;
  }

  N = mtmp;
  if (mtmp <= P) {
    N = P + 1.0;
  }

  emxInit_real_T(&n, 1);
  mtmp = thisData->size[0];
  i0 = n->size[0];
  n->size[0] = mtmp;
  emxEnsureCapacity((emxArray__common *)n, i0, (int)sizeof(double));
  for (i0 = 0; i0 < mtmp; i0++) {
    n->data[i0] = (thisData->data[i0 + thisData->size[0]] - thisFit->data[i0 +
                   thisFit->size[0]]) / thisData->data[i0 + (thisData->size[0] <<
      1)];
  }

  emxInit_real_T(&terms, 1);
  n_idx_0 = (unsigned int)n->size[0];
  i0 = terms->size[0];
  terms->size[0] = (int)n_idx_0;
  emxEnsureCapacity((emxArray__common *)terms, i0, (int)sizeof(double));
  for (mtmp = 0; mtmp + 1 <= n->size[0]; mtmp++) {
    terms->data[mtmp] = n->data[mtmp] * n->data[mtmp];
  }

  emxInit_boolean_T(&x, 1);
  i0 = x->size[0];
  x->size[0] = terms->size[0];
  emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(boolean_T));
  mtmp = terms->size[0];
  for (i0 = 0; i0 < mtmp; i0++) {
    x->data[i0] = (terms->data[i0] == rtInf);
  }

  emxInit_int32_T(&ii, 1);
  nx = x->size[0];
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
  mtmp = 1;
  exitg1 = false;
  while ((!exitg1) && (mtmp <= nx)) {
    guard1 = false;
    if (x->data[mtmp - 1]) {
      idx++;
      ii->data[idx - 1] = mtmp;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      mtmp++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i0 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
    }
  } else {
    i0 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
  }

  emxFree_boolean_T(&x);
  i0 = n->size[0];
  n->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)n, i0, (int)sizeof(double));
  mtmp = ii->size[0];
  for (i0 = 0; i0 < mtmp; i0++) {
    n->data[i0] = ii->data[i0];
  }

  if (!(n->size[0] == 0)) {
    i0 = ii->size[0];
    ii->size[0] = n->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
    mtmp = n->size[0];
    for (i0 = 0; i0 < mtmp; i0++) {
      ii->data[i0] = (int)n->data[i0];
    }

    mtmp = ii->size[0];
    for (i0 = 0; i0 < mtmp; i0++) {
      terms->data[ii->data[i0] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&n);
  if (terms->size[0] == 0) {
    y = 0.0;
  } else {
    y = terms->data[0];
    for (mtmp = 2; mtmp <= terms->size[0]; mtmp++) {
      y += terms->data[mtmp - 1];
    }
  }

  emxFree_real_T(&terms);
  chi2 = 1.0 / (N - P) * y;

  /* allChis(i) = chi2; */
  return chi2;
}

/* End of code generation (chiSquared.c) */
