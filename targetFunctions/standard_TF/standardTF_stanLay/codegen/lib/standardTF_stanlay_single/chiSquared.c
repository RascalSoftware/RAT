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
#include "standardTF_stanlay_single.h"
#include "chiSquared.h"
#include "standardTF_stanlay_single_emxutil.h"
#include "sum.h"

/* Function Definitions */
double chiSquared(const emxArray_real_T *thisData, const emxArray_real_T
                  *thisFit, double P)
{
  double chi2;
  int mtmp;
  double N;
  emxArray_real_T *n;
  int i14;
  emxArray_real_T *terms;
  unsigned int n_idx_0;
  int k;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;

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

  emxInit_real_T1(&n, 1);
  mtmp = thisData->size[0];
  i14 = n->size[0];
  n->size[0] = mtmp;
  emxEnsureCapacity((emxArray__common *)n, i14, (int)sizeof(double));
  for (i14 = 0; i14 < mtmp; i14++) {
    n->data[i14] = (thisData->data[i14 + thisData->size[0]] - thisFit->data[i14
                    + thisFit->size[0]]) / thisData->data[i14 + (thisData->size
      [0] << 1)];
  }

  emxInit_real_T1(&terms, 1);
  n_idx_0 = (unsigned int)n->size[0];
  i14 = terms->size[0];
  terms->size[0] = (int)n_idx_0;
  emxEnsureCapacity((emxArray__common *)terms, i14, (int)sizeof(double));
  mtmp = n->size[0];

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

  for (k = 1; k <= mtmp; k++) {
    terms->data[k - 1] = n->data[k - 1] * n->data[k - 1];
  }

  emxInit_boolean_T(&x, 1);
  i14 = x->size[0];
  x->size[0] = terms->size[0];
  emxEnsureCapacity((emxArray__common *)x, i14, (int)sizeof(boolean_T));
  mtmp = terms->size[0];
  for (i14 = 0; i14 < mtmp; i14++) {
    x->data[i14] = (terms->data[i14] == rtInf);
  }

  emxInit_int32_T(&ii, 1);
  nx = x->size[0];
  idx = 0;
  i14 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i14, (int)sizeof(int));
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
      i14 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i14, (int)sizeof(int));
    }
  } else {
    i14 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i14, (int)sizeof(int));
  }

  emxFree_boolean_T(&x);
  i14 = n->size[0];
  n->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)n, i14, (int)sizeof(double));
  mtmp = ii->size[0];
  for (i14 = 0; i14 < mtmp; i14++) {
    n->data[i14] = ii->data[i14];
  }

  if (!(n->size[0] == 0)) {
    i14 = ii->size[0];
    ii->size[0] = n->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i14, (int)sizeof(int));
    mtmp = n->size[0];
    for (i14 = 0; i14 < mtmp; i14++) {
      ii->data[i14] = (int)n->data[i14];
    }

    mtmp = ii->size[0];
    for (i14 = 0; i14 < mtmp; i14++) {
      terms->data[ii->data[i14] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&n);
  chi2 = 1.0 / (N - P) * sum(terms);

  /* allChis(i) = chi2; */
  emxFree_real_T(&terms);
  return chi2;
}

/* End of code generation (chiSquared.c) */
