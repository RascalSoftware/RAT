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
#include "reflectivity_calculation.h"
#include "shiftdata.h"
#include "reflectivity_calculation_emxutil.h"

/* Function Definitions */
void shiftdata(double scalefac, double horshift, double dataPresent,
               emxArray_real_T *data, const double dataLimits[2])
{
  emxArray_real_T *b_data;
  int hiIndex;
  int i18;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_uint32_T *lowIndex;
  int b_lowIndex;
  emxArray_real_T *c_data;

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

    emxInit_real_T(&b_data, 1);
    hiIndex = data->size[0] - 1;
    i18 = b_data->size[0];
    b_data->size[0] = hiIndex + 1;
    emxEnsureCapacity_real_T(b_data, i18);
    for (i18 = 0; i18 <= hiIndex; i18++) {
      b_data->data[i18] = data->data[i18] + horshift;
    }

    hiIndex = b_data->size[0];
    for (i18 = 0; i18 < hiIndex; i18++) {
      data->data[i18] = b_data->data[i18];
    }

    hiIndex = data->size[0] - 1;
    i18 = b_data->size[0];
    b_data->size[0] = hiIndex + 1;
    emxEnsureCapacity_real_T(b_data, i18);
    for (i18 = 0; i18 <= hiIndex; i18++) {
      b_data->data[i18] = data->data[i18 + data->size[0]] / scalefac;
    }

    hiIndex = b_data->size[0];
    for (i18 = 0; i18 < hiIndex; i18++) {
      data->data[i18 + data->size[0]] = b_data->data[i18];
    }

    hiIndex = data->size[0] - 1;
    i18 = b_data->size[0];
    b_data->size[0] = hiIndex + 1;
    emxEnsureCapacity_real_T(b_data, i18);
    for (i18 = 0; i18 <= hiIndex; i18++) {
      b_data->data[i18] = data->data[i18 + (data->size[0] << 1)] / scalefac;
    }

    hiIndex = b_data->size[0];
    for (i18 = 0; i18 < hiIndex; i18++) {
      data->data[i18 + (data->size[0] << 1)] = b_data->data[i18];
    }

    emxFree_real_T(&b_data);
    emxInit_boolean_T(&x, 1);
    hiIndex = data->size[0];
    i18 = x->size[0];
    x->size[0] = hiIndex;
    emxEnsureCapacity_boolean_T(x, i18);
    for (i18 = 0; i18 < hiIndex; i18++) {
      x->data[i18] = (data->data[i18] < dataLimits[0]);
    }

    emxInit_int32_T(&ii, 1);
    nx = x->size[0];
    idx = 0;
    i18 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(ii, i18);
    hiIndex = 0;
    exitg1 = false;
    while ((!exitg1) && (hiIndex <= nx - 1)) {
      if (x->data[hiIndex]) {
        idx++;
        ii->data[idx - 1] = hiIndex + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          hiIndex++;
        }
      } else {
        hiIndex++;
      }
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i18 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i18);
    }

    emxInit_uint32_T(&lowIndex, 1);
    i18 = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_uint32_T(lowIndex, i18);
    hiIndex = ii->size[0];
    for (i18 = 0; i18 < hiIndex; i18++) {
      lowIndex->data[i18] = (unsigned int)ii->data[i18];
    }

    if (lowIndex->size[0] != 0) {
      b_lowIndex = (int)lowIndex->data[lowIndex->size[0] - 1];
    } else {
      b_lowIndex = 1;
    }

    hiIndex = data->size[0];
    i18 = x->size[0];
    x->size[0] = hiIndex;
    emxEnsureCapacity_boolean_T(x, i18);
    for (i18 = 0; i18 < hiIndex; i18++) {
      x->data[i18] = (data->data[i18] > dataLimits[1]);
    }

    nx = x->size[0];
    idx = 0;
    i18 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(ii, i18);
    hiIndex = 0;
    exitg1 = false;
    while ((!exitg1) && (hiIndex <= nx - 1)) {
      if (x->data[hiIndex]) {
        idx++;
        ii->data[idx - 1] = hiIndex + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          hiIndex++;
        }
      } else {
        hiIndex++;
      }
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i18 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i18);
    }

    emxFree_boolean_T(&x);
    i18 = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_uint32_T(lowIndex, i18);
    hiIndex = ii->size[0];
    for (i18 = 0; i18 < hiIndex; i18++) {
      lowIndex->data[i18] = (unsigned int)ii->data[i18];
    }

    emxFree_int32_T(&ii);
    if (lowIndex->size[0] != 0) {
      hiIndex = (int)lowIndex->data[0];
    } else {
      hiIndex = data->size[0];
    }

    emxFree_uint32_T(&lowIndex);
    if (b_lowIndex > hiIndex) {
      b_lowIndex = 1;
      hiIndex = 0;
    }

    emxInit_real_T(&c_data, 2);
    i18 = c_data->size[0] * c_data->size[1];
    hiIndex -= b_lowIndex;
    c_data->size[0] = hiIndex + 1;
    c_data->size[1] = 3;
    emxEnsureCapacity_real_T(c_data, i18);
    for (i18 = 0; i18 < 3; i18++) {
      for (nx = 0; nx <= hiIndex; nx++) {
        c_data->data[nx + c_data->size[0] * i18] = data->data[((b_lowIndex + nx)
          + data->size[0] * i18) - 1];
      }
    }

    i18 = data->size[0] * data->size[1];
    data->size[0] = c_data->size[0];
    data->size[1] = 3;
    emxEnsureCapacity_real_T(data, i18);
    for (i18 = 0; i18 < 3; i18++) {
      hiIndex = c_data->size[0];
      for (nx = 0; nx < hiIndex; nx++) {
        data->data[nx + data->size[0] * i18] = c_data->data[nx + c_data->size[0]
          * i18];
      }
    }

    emxFree_real_T(&c_data);
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
