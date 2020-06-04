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
#include "standardTF_custlay_single.h"
#include "chiSquared.h"
#include "sum.h"
#include "standardTF_custlay_single_emxutil.h"

/* Function Definitions */
double chiSquared(const double thisData_data[], const int thisData_size[2],
                  const double thisFit_data[], const int thisFit_size[2], double
                  P)
{
  double chi2;
  int mtmp;
  double N;
  int i12;
  double terms_data[51];
  double z_data[51];
  int terms_size[1];
  int k;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *i;
  emxArray_real_T b_terms_data;
  signed char tmp_data[51];

  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  mtmp = (signed char)thisData_size[0];
  if (1 > (signed char)thisData_size[0]) {
    mtmp = 1;
  }

  N = mtmp;
  if (mtmp <= P) {
    N = P + 1.0;
  }

  mtmp = thisData_size[0];
  for (i12 = 0; i12 < mtmp; i12++) {
    z_data[i12] = (thisData_data[i12 + thisData_size[0]] - thisFit_data[i12 +
                   thisFit_size[0]]) / thisData_data[i12 + (thisData_size[0] <<
      1)];
  }

  terms_size[0] = (signed char)thisData_size[0];
  mtmp = thisData_size[0];

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

  for (k = 1; k <= mtmp; k++) {
    terms_data[k - 1] = z_data[k - 1] * z_data[k - 1];
  }

  emxInit_boolean_T(&x, 1);
  i12 = x->size[0];
  x->size[0] = terms_size[0];
  emxEnsureCapacity((emxArray__common *)x, i12, (int)sizeof(boolean_T));
  mtmp = terms_size[0];
  for (i12 = 0; i12 < mtmp; i12++) {
    x->data[i12] = (terms_data[i12] == rtInf);
  }

  emxInit_int32_T(&ii, 1);
  nx = x->size[0];
  idx = 0;
  i12 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i12, (int)sizeof(int));
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
      i12 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i12, (int)sizeof(int));
    }
  } else {
    i12 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i12, (int)sizeof(int));
  }

  emxFree_boolean_T(&x);
  emxInit_int32_T(&i, 1);
  i12 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)i, i12, (int)sizeof(int));
  mtmp = ii->size[0];
  for (i12 = 0; i12 < mtmp; i12++) {
    i->data[i12] = ii->data[i12];
  }

  emxFree_int32_T(&ii);
  if (!(i->size[0] == 0)) {
    nx = i->size[0];
    mtmp = i->size[0];
    for (i12 = 0; i12 < mtmp; i12++) {
      tmp_data[i12] = (signed char)i->data[i12];
    }

    for (i12 = 0; i12 < nx; i12++) {
      terms_data[tmp_data[i12] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&i);
  b_terms_data.data = (double *)&terms_data;
  b_terms_data.size = (int *)&terms_size;
  b_terms_data.allocatedSize = 51;
  b_terms_data.numDimensions = 1;
  b_terms_data.canFreeData = false;
  chi2 = 1.0 / (N - P) * sum(&b_terms_data);

  /* allChis(i) = chi2; */
  return chi2;
}

/* End of code generation (chiSquared.c) */
