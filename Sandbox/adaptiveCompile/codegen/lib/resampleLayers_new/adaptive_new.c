/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive_new.c
 *
 * Code generation for function 'adaptive_new'
 *
 */

/* Include files */
#include <math.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "adaptive_new.h"
#include "resampleLayers_new_emxutil.h"
#include "sortLE.h"
#include "sldFunc.h"
#include "complexTimes.h"
#include "sqrt1.h"
#include "power.h"
#include "repmat.h"

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void calculateCentralAngles(const emxArray_real_T *XYdata, const double
  dataBoxSize[2], emxArray_real_T *cornerAngle)
{
  int m;
  double minval[2];
  int i;
  double absz;
  emxArray_real_T *normalizedData;
  emxArray_real_T *longStep;
  int loop_ub;
  emxArray_real_T *firstStep;
  int i2;
  emxArray_real_T *secondStep;
  int i3;
  emxArray_real_T *b_firstStep;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *r1;
  emxArray_real_T *secondStepSquared;
  emxArray_real_T *b_longStep;
  emxArray_creal_T *x;
  emxArray_real_T *r2;
  double c_firstStep;
  creal_T v;
  creal_T u;
  double t3;
  double ci;
  double t4;
  boolean_T xneg;
  double scaleA;
  double sbr;
  double sbi;
  double scaleB;

  /*  Calculate the central angle of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  /*  Normalize data, because angles depend on scaling. */
  m = XYdata->size[0];
  minval[0] = XYdata->data[0];
  for (i = 2; i <= m; i++) {
    absz = XYdata->data[i - 1];
    if ((!rtIsNaN(absz)) && (rtIsNaN(minval[0]) || (minval[0] > absz))) {
      minval[0] = XYdata->data[i - 1];
    }
  }

  minval[1] = XYdata->data[XYdata->size[0]];
  for (i = 2; i <= m; i++) {
    absz = XYdata->data[(i + XYdata->size[0]) - 1];
    if ((!rtIsNaN(absz)) && (rtIsNaN(minval[1]) || (minval[1] > absz))) {
      minval[1] = XYdata->data[(i + XYdata->size[0]) - 1];
    }
  }

  emxInit_real_T(&normalizedData, 2);
  emxInit_real_T(&longStep, 2);
  repmat(dataBoxSize, XYdata->size[0], normalizedData);
  repmat(minval, XYdata->size[0], longStep);
  m = XYdata->size[0] * XYdata->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[0] = XYdata->size[0];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(normalizedData, i);
  loop_ub = m - 1;
  for (m = 0; m <= loop_ub; m++) {
    normalizedData->data[m] = XYdata->data[m] / normalizedData->data[m] -
      longStep->data[m];
  }

  /*  calculate cosine of central angles */
  /*  Return the sides (deltaX, deltaY) of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  if (2 > normalizedData->size[0] - 1) {
    m = 0;
    i = 0;
  } else {
    m = 1;
    i = normalizedData->size[0] - 1;
  }

  emxInit_real_T(&firstStep, 2);
  i2 = firstStep->size[0] * firstStep->size[1];
  loop_ub = i - m;
  firstStep->size[0] = loop_ub;
  firstStep->size[1] = 2;
  emxEnsureCapacity_real_T(firstStep, i2);
  for (i = 0; i < loop_ub; i++) {
    firstStep->data[i] = normalizedData->data[m + i] - normalizedData->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    firstStep->data[i + firstStep->size[0]] = normalizedData->data[(m + i) +
      normalizedData->size[0]] - normalizedData->data[i + normalizedData->size[0]];
  }

  if (3 > normalizedData->size[0]) {
    m = 0;
    i = 0;
  } else {
    m = 2;
    i = normalizedData->size[0];
  }

  i2 = (2 <= normalizedData->size[0] - 1);
  emxInit_real_T(&secondStep, 2);
  i3 = secondStep->size[0] * secondStep->size[1];
  loop_ub = i - m;
  secondStep->size[0] = loop_ub;
  secondStep->size[1] = 2;
  emxEnsureCapacity_real_T(secondStep, i3);
  for (i = 0; i < loop_ub; i++) {
    secondStep->data[i] = normalizedData->data[m + i] - normalizedData->data[i2
      + i];
  }

  for (i = 0; i < loop_ub; i++) {
    secondStep->data[i + secondStep->size[0]] = normalizedData->data[(m + i) +
      normalizedData->size[0]] - normalizedData->data[(i2 + i) +
      normalizedData->size[0]];
  }

  if (3 > normalizedData->size[0]) {
    m = 0;
    i = 0;
  } else {
    m = 2;
    i = normalizedData->size[0];
  }

  i2 = longStep->size[0] * longStep->size[1];
  loop_ub = i - m;
  longStep->size[0] = loop_ub;
  longStep->size[1] = 2;
  emxEnsureCapacity_real_T(longStep, i2);
  for (i = 0; i < loop_ub; i++) {
    longStep->data[i] = normalizedData->data[m + i] - normalizedData->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    longStep->data[i + longStep->size[0]] = normalizedData->data[(m + i) +
      normalizedData->size[0]] - normalizedData->data[i + normalizedData->size[0]];
  }

  emxFree_real_T(&normalizedData);
  emxInit_real_T(&b_firstStep, 1);

  /*  calculate area of squares of length of triangle sides */
  loop_ub = firstStep->size[0];
  m = b_firstStep->size[0];
  b_firstStep->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_firstStep, m);
  for (m = 0; m < loop_ub; m++) {
    b_firstStep->data[m] = firstStep->data[m];
  }

  emxInit_real_T(&firstStepSquared, 1);
  power(b_firstStep, firstStepSquared);
  loop_ub = firstStep->size[0];
  m = b_firstStep->size[0];
  b_firstStep->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_firstStep, m);
  for (m = 0; m < loop_ub; m++) {
    b_firstStep->data[m] = firstStep->data[m + firstStep->size[0]];
  }

  emxFree_real_T(&firstStep);
  emxInit_real_T(&r1, 1);
  power(b_firstStep, r1);
  m = firstStepSquared->size[0];
  emxEnsureCapacity_real_T(firstStepSquared, m);
  loop_ub = firstStepSquared->size[0];
  for (m = 0; m < loop_ub; m++) {
    firstStepSquared->data[m] += r1->data[m];
  }

  loop_ub = secondStep->size[0];
  m = b_firstStep->size[0];
  b_firstStep->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_firstStep, m);
  for (m = 0; m < loop_ub; m++) {
    b_firstStep->data[m] = secondStep->data[m];
  }

  emxInit_real_T(&secondStepSquared, 1);
  power(b_firstStep, secondStepSquared);
  loop_ub = secondStep->size[0];
  m = b_firstStep->size[0];
  b_firstStep->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_firstStep, m);
  for (m = 0; m < loop_ub; m++) {
    b_firstStep->data[m] = secondStep->data[m + secondStep->size[0]];
  }

  emxFree_real_T(&secondStep);
  power(b_firstStep, r1);
  m = secondStepSquared->size[0];
  emxEnsureCapacity_real_T(secondStepSquared, m);
  loop_ub = secondStepSquared->size[0];
  for (m = 0; m < loop_ub; m++) {
    secondStepSquared->data[m] += r1->data[m];
  }

  m = b_firstStep->size[0];
  b_firstStep->size[0] = firstStepSquared->size[0];
  emxEnsureCapacity_real_T(b_firstStep, m);
  loop_ub = firstStepSquared->size[0];
  for (m = 0; m < loop_ub; m++) {
    b_firstStep->data[m] = firstStepSquared->data[m] * secondStepSquared->data[m];
  }

  m = b_firstStep->size[0];
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = sqrt(b_firstStep->data[i]);
  }

  emxInit_real_T(&b_longStep, 1);
  loop_ub = longStep->size[0];
  m = b_longStep->size[0];
  b_longStep->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_longStep, m);
  for (m = 0; m < loop_ub; m++) {
    b_longStep->data[m] = longStep->data[m];
  }

  power(b_longStep, r1);
  loop_ub = longStep->size[0];
  m = b_longStep->size[0];
  b_longStep->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_longStep, m);
  for (m = 0; m < loop_ub; m++) {
    b_longStep->data[m] = longStep->data[m + longStep->size[0]];
  }

  emxFree_real_T(&longStep);
  emxInit_creal_T(&x, 1);
  emxInit_real_T(&r2, 1);
  power(b_longStep, r2);
  m = x->size[0];
  x->size[0] = firstStepSquared->size[0];
  emxEnsureCapacity_creal_T(x, m);
  loop_ub = firstStepSquared->size[0];
  emxFree_real_T(&b_longStep);
  for (m = 0; m < loop_ub; m++) {
    absz = (firstStepSquared->data[m] + secondStepSquared->data[m]) - (r1->
      data[m] + r2->data[m]);
    c_firstStep = b_firstStep->data[m];
    x->data[m].re = absz / 2.0 / c_firstStep;
    x->data[m].im = 0.0;
  }

  emxFree_real_T(&b_firstStep);
  emxFree_real_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&secondStepSquared);
  emxFree_real_T(&firstStepSquared);
  m = x->size[0];
  for (i = 0; i < m; i++) {
    if ((x->data[i].im == 0.0) && (!(fabs(x->data[i].re) > 1.0))) {
      absz = x->data[i].re;
      x->data[i].re = acos(absz);
      x->data[i].im = 0.0;
    } else {
      v.re = 1.0 + x->data[i].re;
      v.im = x->data[i].im;
      b_sqrt(&v);
      u.re = 1.0 - x->data[i].re;
      u.im = 0.0 - x->data[i].im;
      b_sqrt(&u);
      if ((-v.im == 0.0) && (u.im == 0.0)) {
        ci = 0.0;
      } else {
        t3 = v.re * u.im;
        t4 = -v.im * u.re;
        ci = t3 + t4;
        if ((rtIsInf(ci) || rtIsNaN(ci)) && (!rtIsNaN(v.re)) && (!rtIsNaN(-v.im))
            && (!rtIsNaN(u.re)) && (!rtIsNaN(u.im))) {
          c_firstStep = v.re;
          absz = -v.im;
          scaleA = rescale(&c_firstStep, &absz);
          sbr = u.re;
          sbi = u.im;
          scaleB = rescale(&sbr, &sbi);
          if ((!rtIsInf(scaleA)) && (!rtIsNaN(scaleA)) && ((!rtIsInf(scaleB)) &&
               (!rtIsNaN(scaleB)))) {
            xneg = true;
          } else {
            xneg = false;
          }

          if (rtIsNaN(ci) || (rtIsInf(ci) && xneg)) {
            ci = c_firstStep * sbi + absz * sbr;
            if (ci != 0.0) {
              ci = ci * scaleA * scaleB;
            } else {
              if ((rtIsInf(scaleA) && ((u.re == 0.0) || (u.im == 0.0))) ||
                  (rtIsInf(scaleB) && ((v.re == 0.0) || (-v.im == 0.0)))) {
                if (rtIsNaN(t3)) {
                  t3 = 0.0;
                }

                if (rtIsNaN(t4)) {
                  t4 = 0.0;
                }

                ci = t3 + t4;
              }
            }
          }
        }
      }

      xneg = (ci < 0.0);
      if (xneg) {
        ci = -ci;
      }

      if (ci >= 2.68435456E+8) {
        ci = log(ci) + 0.69314718055994529;
      } else if (ci > 2.0) {
        ci = log(2.0 * ci + 1.0 / (sqrt(ci * ci + 1.0) + ci));
      } else {
        absz = ci * ci;
        ci += absz / (1.0 + sqrt(1.0 + absz));
        absz = fabs(ci);
        if ((absz > 4.503599627370496E+15) || (rtIsInf(ci) || rtIsNaN(ci))) {
          ci++;
          ci = log(ci);
        } else {
          if (!(absz < 2.2204460492503131E-16)) {
            ci = log(1.0 + ci) * (ci / ((1.0 + ci) - 1.0));
          }
        }
      }

      if (xneg) {
        ci = -ci;
      }

      x->data[i].re = 2.0 * rt_atan2d_snf(u.re, v.re);
      x->data[i].im = ci;
    }
  }

  m = cornerAngle->size[0];
  cornerAngle->size[0] = x->size[0];
  emxEnsureCapacity_real_T(cornerAngle, m);
  loop_ub = x->size[0];
  for (m = 0; m < loop_ub; m++) {
    cornerAngle->data[m] = x->data[m].re;
  }

  emxFree_creal_T(&x);
}

void increaseSampling(emxArray_real_T *dataPoints, const emxArray_boolean_T
                      *segmentsToSplit, const emxArray_real_T *sldProfile)
{
  int input_sizes_idx_0;
  int b_input_sizes_idx_0;
  int i;
  emxArray_real_T *newDataPoints;
  int pEnd;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r4;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *ycol;
  emxArray_real_T *r5;
  emxArray_real_T *b_dataPoints;
  int col_data[2];
  int n;
  int k;
  int p;
  int q;
  int qEnd;
  int kEnd;

  /*  increaseSampling increase the sampling of an input function */
  input_sizes_idx_0 = segmentsToSplit->size[0];
  b_input_sizes_idx_0 = 0;
  for (i = 0; i < input_sizes_idx_0; i++) {
    if (segmentsToSplit->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_real_T(&newDataPoints, 2);
  pEnd = newDataPoints->size[0] * newDataPoints->size[1];
  newDataPoints->size[0] = b_input_sizes_idx_0;
  newDataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(newDataPoints, pEnd);
  b_input_sizes_idx_0 <<= 1;
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    newDataPoints->data[pEnd] = 0.0;
  }

  emxInit_boolean_T(&r3, 1);
  pEnd = r3->size[0];
  r3->size[0] = segmentsToSplit->size[0] + 1;
  emxEnsureCapacity_boolean_T(r3, pEnd);
  b_input_sizes_idx_0 = segmentsToSplit->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    r3->data[pEnd] = segmentsToSplit->data[pEnd];
  }

  emxInit_boolean_T(&r4, 1);
  r3->data[segmentsToSplit->size[0]] = false;
  pEnd = r4->size[0];
  r4->size[0] = 1 + segmentsToSplit->size[0];
  emxEnsureCapacity_boolean_T(r4, pEnd);
  r4->data[0] = false;
  b_input_sizes_idx_0 = segmentsToSplit->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    r4->data[pEnd + 1] = segmentsToSplit->data[pEnd];
  }

  input_sizes_idx_0 = r3->size[0] - 1;
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r3->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(&idx, 1);
  pEnd = idx->size[0];
  idx->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_int32_T(idx, pEnd);
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r3->data[i]) {
      idx->data[b_input_sizes_idx_0] = i + 1;
      b_input_sizes_idx_0++;
    }
  }

  emxFree_boolean_T(&r3);
  input_sizes_idx_0 = r4->size[0] - 1;
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r4->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(&iwork, 1);
  pEnd = iwork->size[0];
  iwork->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_int32_T(iwork, pEnd);
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r4->data[i]) {
      iwork->data[b_input_sizes_idx_0] = i + 1;
      b_input_sizes_idx_0++;
    }
  }

  emxFree_boolean_T(&r4);
  b_input_sizes_idx_0 = idx->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    newDataPoints->data[pEnd] = 0.5 * (dataPoints->data[idx->data[pEnd] - 1] +
      dataPoints->data[iwork->data[pEnd] - 1]);
  }

  emxInit_real_T(&ycol, 1);

  /*  Subfunctions */
  /*  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N */
  /*  is the number of elements of x and M is the number of outputs of func. */
  /*  All the outputs of func must be scalar. */
  /*  The optional parameter 'vectorizable' (default false) allows to specify */
  /*  that the input function can be vectorized. */
  /*  Modified by AVH for use with coder */
  /* if (~exist('vectorizable','var') || isempty(vectorizable)) */
  /*  end */
  /* abs(nargout(func)); %for anonymous functions nargout<0 */
  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  pEnd = newDataPoints->size[0];
  b_input_sizes_idx_0 = newDataPoints->size[0];
  input_sizes_idx_0 = ycol->size[0];
  ycol->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_real_T(ycol, input_sizes_idx_0);
  emxInit_real_T(&r5, 1);
  for (i = 0; i < pEnd; i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    sldFunc(newDataPoints->data[i], sldProfile, r5);
    ycol->data[i] = r5->data[0];
  }

  emxFree_real_T(&r5);

  /* end */
  b_input_sizes_idx_0 = ycol->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    newDataPoints->data[pEnd + newDataPoints->size[0]] = ycol->data[pEnd];
  }

  /*  For simplicity append the new points at the end and then sort. */
  if (dataPoints->size[0] != 0) {
    b_input_sizes_idx_0 = dataPoints->size[0];
  } else {
    b_input_sizes_idx_0 = 0;
  }

  if (newDataPoints->size[0] != 0) {
    input_sizes_idx_0 = newDataPoints->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }

  emxInit_real_T(&b_dataPoints, 2);
  pEnd = b_dataPoints->size[0] * b_dataPoints->size[1];
  b_dataPoints->size[0] = b_input_sizes_idx_0 + input_sizes_idx_0;
  b_dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(b_dataPoints, pEnd);
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    b_dataPoints->data[pEnd] = dataPoints->data[pEnd];
  }

  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    b_dataPoints->data[pEnd + b_dataPoints->size[0]] = dataPoints->data[pEnd +
      dataPoints->size[0]];
  }

  for (pEnd = 0; pEnd < input_sizes_idx_0; pEnd++) {
    b_dataPoints->data[pEnd + b_input_sizes_idx_0] = newDataPoints->data[pEnd];
  }

  for (pEnd = 0; pEnd < input_sizes_idx_0; pEnd++) {
    b_dataPoints->data[(pEnd + b_input_sizes_idx_0) + b_dataPoints->size[0]] =
      newDataPoints->data[pEnd + newDataPoints->size[0]];
  }

  emxFree_real_T(&newDataPoints);
  pEnd = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = b_dataPoints->size[0];
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(dataPoints, pEnd);
  b_input_sizes_idx_0 = b_dataPoints->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    dataPoints->data[pEnd] = b_dataPoints->data[pEnd];
  }

  b_input_sizes_idx_0 = b_dataPoints->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    dataPoints->data[pEnd + dataPoints->size[0]] = b_dataPoints->data[pEnd +
      b_dataPoints->size[0]];
  }

  emxFree_real_T(&b_dataPoints);
  col_data[0] = 1;
  col_data[1] = 2;
  n = dataPoints->size[0] + 1;
  pEnd = idx->size[0];
  idx->size[0] = dataPoints->size[0];
  emxEnsureCapacity_int32_T(idx, pEnd);
  b_input_sizes_idx_0 = dataPoints->size[0];
  for (pEnd = 0; pEnd < b_input_sizes_idx_0; pEnd++) {
    idx->data[pEnd] = 0;
  }

  if (dataPoints->size[0] == 0) {
    for (k = 0; k <= n - 2; k++) {
      idx->data[k] = k + 1;
    }
  } else {
    pEnd = iwork->size[0];
    iwork->size[0] = dataPoints->size[0];
    emxEnsureCapacity_int32_T(iwork, pEnd);
    pEnd = dataPoints->size[0] - 1;
    for (k = 1; k <= pEnd; k += 2) {
      if (sortLE(dataPoints, col_data, k, k + 1)) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((dataPoints->size[0] & 1) != 0) {
      idx->data[dataPoints->size[0] - 1] = dataPoints->size[0];
    }

    i = 2;
    while (i < n - 1) {
      b_input_sizes_idx_0 = i << 1;
      input_sizes_idx_0 = 1;
      for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
        p = input_sizes_idx_0;
        q = pEnd;
        qEnd = input_sizes_idx_0 + b_input_sizes_idx_0;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - input_sizes_idx_0;
        while (k + 1 <= kEnd) {
          if (sortLE(dataPoints, col_data, idx->data[p - 1], idx->data[q - 1]))
          {
            iwork->data[k] = idx->data[p - 1];
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork->data[k] = idx->data[q - 1];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q - 1];
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k < kEnd; k++) {
          idx->data[(input_sizes_idx_0 + k) - 1] = iwork->data[k];
        }

        input_sizes_idx_0 = qEnd;
      }

      i = b_input_sizes_idx_0;
    }
  }

  emxFree_int32_T(&iwork);
  input_sizes_idx_0 = dataPoints->size[0] - 1;
  b_input_sizes_idx_0 = dataPoints->size[0];
  pEnd = ycol->size[0];
  ycol->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_real_T(ycol, pEnd);
  for (i = 0; i <= input_sizes_idx_0; i++) {
    ycol->data[i] = dataPoints->data[idx->data[i] - 1];
  }

  for (i = 0; i <= input_sizes_idx_0; i++) {
    dataPoints->data[i] = ycol->data[i];
  }

  for (i = 0; i <= input_sizes_idx_0; i++) {
    ycol->data[i] = dataPoints->data[(idx->data[i] + dataPoints->size[0]) - 1];
  }

  for (i = 0; i <= input_sizes_idx_0; i++) {
    dataPoints->data[i + dataPoints->size[0]] = ycol->data[i];
  }

  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
}

/* End of code generation (adaptive_new.c) */
