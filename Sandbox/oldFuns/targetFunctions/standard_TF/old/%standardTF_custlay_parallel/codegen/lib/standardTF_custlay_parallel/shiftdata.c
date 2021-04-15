/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * shiftdata.c
 *
 * Code generation for function 'shiftdata'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "shiftdata.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "rdivide.h"

/* Function Definitions */
void shiftdata(double scalefac, double horshift, double dataPresent,
               emxArray_real_T *data, const double dataLimits[2],
               emxArray_real_T *shifted_data)
{
  int i6;
  emxArray_real_T *b_data;
  int c_data;
  int idx;
  emxArray_real_T *d_data;
  emxArray_real_T *r5;
  emxArray_real_T *e_data;
  emxArray_real_T *r6;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  boolean_T exitg2;
  boolean_T guard2 = false;
  emxArray_int32_T *lowIndex;
  int b_lowIndex;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int hiIndex;

  /* Shifts the data according to scale factor */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  switch ((int)dataPresent) {
   case 1:
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }

    emxInit_real_T1(&b_data, 1);
    c_data = data->size[0];
    i6 = b_data->size[0];
    b_data->size[0] = c_data;
    emxEnsureCapacity((emxArray__common *)b_data, i6, (int)sizeof(double));
    for (i6 = 0; i6 < c_data; i6++) {
      b_data->data[i6] = data->data[i6] + horshift;
    }

    idx = b_data->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      data->data[i6] = b_data->data[i6];
    }

    emxFree_real_T(&b_data);
    emxInit_real_T1(&d_data, 1);
    idx = data->size[0];
    i6 = d_data->size[0];
    d_data->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)d_data, i6, (int)sizeof(double));
    for (i6 = 0; i6 < idx; i6++) {
      d_data->data[i6] = data->data[i6 + data->size[0]];
    }

    emxInit_real_T1(&r5, 1);
    rdivide(d_data, scalefac, r5);
    idx = r5->size[0];
    emxFree_real_T(&d_data);
    for (i6 = 0; i6 < idx; i6++) {
      data->data[i6 + data->size[0]] = r5->data[i6];
    }

    emxFree_real_T(&r5);
    emxInit_real_T1(&e_data, 1);
    idx = data->size[0];
    i6 = e_data->size[0];
    e_data->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)e_data, i6, (int)sizeof(double));
    for (i6 = 0; i6 < idx; i6++) {
      e_data->data[i6] = data->data[i6 + (data->size[0] << 1)];
    }

    emxInit_real_T1(&r6, 1);
    rdivide(e_data, scalefac, r6);
    idx = r6->size[0];
    emxFree_real_T(&e_data);
    for (i6 = 0; i6 < idx; i6++) {
      data->data[i6 + (data->size[0] << 1)] = r6->data[i6];
    }

    emxFree_real_T(&r6);
    emxInit_boolean_T(&x, 1);
    idx = data->size[0];
    i6 = x->size[0];
    x->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)x, i6, (int)sizeof(boolean_T));
    for (i6 = 0; i6 < idx; i6++) {
      x->data[i6] = (data->data[i6] < dataLimits[0]);
    }

    emxInit_int32_T(&ii, 1);
    nx = x->size[0];
    idx = 0;
    i6 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
    c_data = 1;
    exitg2 = false;
    while ((!exitg2) && (c_data <= nx)) {
      guard2 = false;
      if (x->data[c_data - 1]) {
        idx++;
        ii->data[idx - 1] = c_data;
        if (idx >= nx) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        c_data++;
      }
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        i6 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
      }
    } else {
      i6 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
    }

    emxInit_int32_T(&lowIndex, 1);
    i6 = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity((emxArray__common *)lowIndex, i6, (int)sizeof(int));
    idx = ii->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      lowIndex->data[i6] = ii->data[i6];
    }

    if (!(lowIndex->size[0] == 0)) {
      b_lowIndex = lowIndex->data[lowIndex->size[0] - 1];
    } else {
      b_lowIndex = 1;
    }

    idx = data->size[0];
    i6 = x->size[0];
    x->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)x, i6, (int)sizeof(boolean_T));
    for (i6 = 0; i6 < idx; i6++) {
      x->data[i6] = (data->data[i6] > dataLimits[1]);
    }

    nx = x->size[0];
    idx = 0;
    i6 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
    c_data = 1;
    exitg1 = false;
    while ((!exitg1) && (c_data <= nx)) {
      guard1 = false;
      if (x->data[c_data - 1]) {
        idx++;
        ii->data[idx - 1] = c_data;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        c_data++;
      }
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        i6 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
      }
    } else {
      i6 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
    }

    emxFree_boolean_T(&x);
    i6 = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity((emxArray__common *)lowIndex, i6, (int)sizeof(int));
    idx = ii->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      lowIndex->data[i6] = ii->data[i6];
    }

    emxFree_int32_T(&ii);
    if (!(lowIndex->size[0] == 0)) {
      hiIndex = lowIndex->data[0];
    } else {
      hiIndex = data->size[0];
    }

    emxFree_int32_T(&lowIndex);
    if (b_lowIndex > hiIndex) {
      i6 = 0;
      hiIndex = 0;
    } else {
      i6 = b_lowIndex - 1;
    }

    c_data = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = hiIndex - i6;
    shifted_data->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)shifted_data, c_data, (int)sizeof
                      (double));
    for (c_data = 0; c_data < 3; c_data++) {
      idx = hiIndex - i6;
      for (nx = 0; nx < idx; nx++) {
        shifted_data->data[nx + shifted_data->size[0] * c_data] = data->data[(i6
          + nx) + data->size[0] * c_data];
      }
    }
    break;

   default:
    i6 = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = data->size[0];
    shifted_data->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)shifted_data, i6, (int)sizeof(double));
    idx = data->size[0] * data->size[1];
    for (i6 = 0; i6 < idx; i6++) {
      shifted_data->data[i6] = data->data[i6];
    }
    break;
  }

  /*  function Ref = makeFresnelData(problem,contrast) */
  /*   */
  /*      this_data = problem.shifted_data{contrast}; */
  /*      xdata = this_data(:,1); */
  /*      nbair = problem.nbairs(contrast); */
  /*      nbsub = problem.nbsubs(contrast); */
  /*      slds = [0 0 0]; */
  /*      resol = problem.resolution; */
  /*      resolType = problem.resolType; */
  /*      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol) */
  /*      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats, */
  /*      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); */
}

/* End of code generation (shiftdata.c) */
