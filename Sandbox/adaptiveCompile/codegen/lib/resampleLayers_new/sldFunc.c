/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sldFunc.c
 *
 * Code generation for function 'sldFunc'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "sldFunc.h"
#include "resampleLayers_new_emxutil.h"

/* Function Definitions */
void sldFunc(double x, const emxArray_real_T *SLD, emxArray_real_T *sldVal)
{
  emxArray_boolean_T *b_x;
  int loop_ub;
  int i1;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_uint32_T *where;
  emxArray_uint32_T *aboveVals;
  double deltaY;
  emxInit_boolean_T(&b_x, 1);

  /*  sldVal = sldFunc(x,SLD) */
  /*  SLD = [x rho;....xn rho] */
  /*    x = value in Angstrom. */
  /*  */
  /*  This function returns the SLD (y) value associated with the */
  /*  supplied value of x. SLD is a two column, XY array defining an */
  /*  SLD profile. This function interpolates the SLD profile */
  /*  to return the SLD at the specific value of X. X can be a vector of */
  /*  multiple points. */
  /*  */
  /*  (c) Arwel Hughes 2019. */
  /*  Last modified - AVH, 26/11/19. */
  /*  global sldProfile */
  /*   */
  /*  SLD = sldProfile; */
  /* SLD = getappdata(0,'sldFuncSLD'); */
  loop_ub = SLD->size[0];
  i1 = b_x->size[0];
  b_x->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(b_x, i1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_x->data[i1] = (SLD->data[i1] == x);
  }

  emxInit_int32_T(&ii, 1);
  nx = b_x->size[0];
  idx = 0;
  i1 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity_int32_T(ii, i1);
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= nx - 1)) {
    if (b_x->data[loop_ub]) {
      idx++;
      ii->data[idx - 1] = loop_ub + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        loop_ub++;
      }
    } else {
      loop_ub++;
    }
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      ii->size[0] = 0;
    }
  } else if (1 > idx) {
    ii->size[0] = 0;
  } else {
    i1 = ii->size[0];
    ii->size[0] = idx;
    emxEnsureCapacity_int32_T(ii, i1);
  }

  emxInit_uint32_T(&where, 1);
  i1 = where->size[0];
  where->size[0] = ii->size[0];
  emxEnsureCapacity_uint32_T(where, i1);
  loop_ub = ii->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    where->data[i1] = (unsigned int)ii->data[i1];
  }

  if (where->size[0] != 0) {
    i1 = sldVal->size[0];
    sldVal->size[0] = where->size[0];
    emxEnsureCapacity_real_T(sldVal, i1);
    loop_ub = where->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      sldVal->data[i1] = SLD->data[((int)where->data[i1] + SLD->size[0]) - 1];
    }
  } else {
    loop_ub = SLD->size[0];
    i1 = b_x->size[0];
    b_x->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T(b_x, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_x->data[i1] = (x > SLD->data[i1]);
    }

    nx = b_x->size[0];
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i1);
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= nx - 1)) {
      if (b_x->data[loop_ub]) {
        idx++;
        ii->data[idx - 1] = loop_ub + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      } else {
        loop_ub++;
      }
    }

    if (b_x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i1 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i1);
    }

    i1 = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_uint32_T(where, i1);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      where->data[i1] = (unsigned int)ii->data[i1];
    }

    loop_ub = SLD->size[0];
    i1 = b_x->size[0];
    b_x->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T(b_x, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_x->data[i1] = (x < SLD->data[i1]);
    }

    nx = b_x->size[0];
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i1);
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= nx - 1)) {
      if (b_x->data[loop_ub]) {
        idx++;
        ii->data[idx - 1] = loop_ub + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      } else {
        loop_ub++;
      }
    }

    if (b_x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i1 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i1);
    }

    emxInit_uint32_T(&aboveVals, 1);
    i1 = aboveVals->size[0];
    aboveVals->size[0] = ii->size[0];
    emxEnsureCapacity_uint32_T(aboveVals, i1);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      aboveVals->data[i1] = (unsigned int)ii->data[i1];
    }

    deltaY = (x - SLD->data[(int)where->data[where->size[0] - 1] - 1]) * (fabs
      (SLD->data[((int)aboveVals->data[0] + SLD->size[0]) - 1] - SLD->data[((int)
      where->data[where->size[0] - 1] + SLD->size[0]) - 1]) / (SLD->data[(int)
      aboveVals->data[0] - 1] - SLD->data[(int)where->data[where->size[0] - 1] -
      1]));
    if (SLD->data[((int)where->data[where->size[0] - 1] + SLD->size[0]) - 1] <
        SLD->data[((int)aboveVals->data[0] + SLD->size[0]) - 1]) {
      i1 = sldVal->size[0];
      sldVal->size[0] = 1;
      emxEnsureCapacity_real_T(sldVal, i1);
      sldVal->data[0] = SLD->data[((int)where->data[where->size[0] - 1] +
        SLD->size[0]) - 1] + deltaY;
    } else {
      i1 = sldVal->size[0];
      sldVal->size[0] = 1;
      emxEnsureCapacity_real_T(sldVal, i1);
      sldVal->data[0] = SLD->data[((int)where->data[where->size[0] - 1] +
        SLD->size[0]) - 1] - deltaY;
    }

    emxFree_uint32_T(&aboveVals);

    /* sldVal = interp1(z,rho,x); */
  }

  emxFree_int32_T(&ii);
  emxFree_boolean_T(&b_x);
  emxFree_uint32_T(&where);
}

/* End of code generation (sldFunc.c) */
