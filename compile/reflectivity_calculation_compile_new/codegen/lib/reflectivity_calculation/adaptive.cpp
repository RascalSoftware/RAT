//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// adaptive.cpp
//
// Code generation for function 'adaptive'
//

// Include files
#include "adaptive.h"
#include "acos.h"
#include "any1.h"
#include "linspace.h"
#include "minOrMax.h"
#include "power.h"
#include "reflectivity_calculation_internal_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortrows.h"
#include "sqrt.h"
#include "coder_array.h"
#include <algorithm>

// Variable Definitions
static const double dv1[50]{10.0,
                            11.836734693877551,
                            13.673469387755102,
                            15.510204081632654,
                            17.346938775510203,
                            19.183673469387756,
                            21.020408163265309,
                            22.857142857142858,
                            24.693877551020407,
                            26.530612244897959,
                            28.367346938775512,
                            30.204081632653061,
                            32.040816326530617,
                            33.877551020408163,
                            35.714285714285715,
                            37.551020408163268,
                            39.387755102040813,
                            41.224489795918373,
                            43.061224489795919,
                            44.897959183673471,
                            46.734693877551024,
                            48.571428571428569,
                            50.408163265306122,
                            52.244897959183675,
                            54.081632653061227,
                            55.91836734693878,
                            57.755102040816325,
                            59.591836734693878,
                            61.428571428571431,
                            63.265306122448983,
                            65.102040816326536,
                            66.938775510204081,
                            68.775510204081627,
                            70.612244897959187,
                            72.448979591836746,
                            74.285714285714292,
                            76.122448979591837,
                            77.959183673469383,
                            79.795918367346943,
                            81.632653061224488,
                            83.469387755102048,
                            85.3061224489796,
                            87.142857142857139,
                            88.9795918367347,
                            90.816326530612244,
                            92.6530612244898,
                            94.489795918367349,
                            96.3265306122449,
                            98.163265306122454,
                            100.0};

// Function Declarations
static void
b_increaseSampling(coder::array<double, 2U> &dataPoints,
                   const coder::array<boolean_T, 1U> &segmentsToSplit);

static void calculateCentralAngles(const coder::array<double, 2U> &XYdata,
                                   const double dataBoxSize[2],
                                   coder::array<double, 1U> &cornerAngle);

static void calculateTrianglesSides(const coder::array<double, 2U> &XYdata,
                                    coder::array<double, 2U> &firstStep,
                                    coder::array<double, 2U> &secondStep,
                                    coder::array<double, 2U> &longStep);

static void increaseSampling(coder::array<double, 2U> &dataPoints,
                             const coder::array<boolean_T, 1U> &segmentsToSplit,
                             const coder::array<double, 2U> &sldProfile);

static void normalizeFunction(const double x[50],
                              const coder::array<double, 2U> &sldProfile,
                              double y[50]);

static void normalizeFunction(const coder::array<double, 1U> &x,
                              const coder::array<double, 2U> &sldProfile,
                              coder::array<double, 1U> &y);

static void normalizeFunction(double y[50]);

static void normalizeFunction(const coder::array<double, 1U> &x,
                              coder::array<double, 1U> &y);

// Function Definitions
static void
b_increaseSampling(coder::array<double, 2U> &dataPoints,
                   const coder::array<boolean_T, 1U> &segmentsToSplit)
{
  coder::array<double, 2U> b_dataPoints;
  coder::array<double, 2U> newDataPoints;
  coder::array<double, 1U> b_newDataPoints;
  coder::array<double, 1U> r4;
  coder::array<int, 1U> r2;
  coder::array<int, 1U> r3;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> r1;
  int b_i;
  int end;
  int i;
  int input_sizes_idx_0;
  //  increaseSampling increase the sampling of an input function
  end = segmentsToSplit.size(0);
  input_sizes_idx_0 = 0;
  for (i = 0; i < end; i++) {
    if (segmentsToSplit[i]) {
      input_sizes_idx_0++;
    }
  }
  newDataPoints.set_size(input_sizes_idx_0, 2);
  input_sizes_idx_0 <<= 1;
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] = 0.0;
  }
  r.set_size(segmentsToSplit.size(0) + 1);
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r[b_i] = segmentsToSplit[b_i];
  }
  r[segmentsToSplit.size(0)] = false;
  r1.set_size(segmentsToSplit.size(0) + 1);
  r1[0] = false;
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r1[b_i + 1] = segmentsToSplit[b_i];
  }
  end = r.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      input_sizes_idx_0++;
    }
  }
  r2.set_size(input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      r2[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }
  end = r1.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      input_sizes_idx_0++;
    }
  }
  r3.set_size(input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      r3[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }
  input_sizes_idx_0 = r2.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] =
        0.5 * (dataPoints[r2[b_i] - 1] + dataPoints[r3[b_i] - 1]);
  }
  input_sizes_idx_0 = newDataPoints.size(0) - 1;
  b_newDataPoints.set_size(newDataPoints.size(0));
  for (b_i = 0; b_i <= input_sizes_idx_0; b_i++) {
    b_newDataPoints[b_i] = newDataPoints[b_i];
  }
  normalizeFunction(b_newDataPoints, r4);
  input_sizes_idx_0 = r4.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i + newDataPoints.size(0)] = r4[b_i];
  }
  //  For simplicity append the new points at the end and then sort.
  if (newDataPoints.size(0) != 0) {
    input_sizes_idx_0 = newDataPoints.size(0);
  } else {
    input_sizes_idx_0 = 0;
  }
  if (dataPoints.size(0) != 0) {
    end = dataPoints.size(0);
  } else {
    end = 0;
  }
  b_dataPoints.set_size(end + input_sizes_idx_0, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i = 0; i < end; i++) {
      b_dataPoints[i + b_dataPoints.size(0) * b_i] =
          dataPoints[i + dataPoints.size(0) * b_i];
    }
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_dataPoints[(i + end) + b_dataPoints.size(0) * b_i] =
          newDataPoints[i + newDataPoints.size(0) * b_i];
    }
  }
  dataPoints.set_size(b_dataPoints.size(0), 2);
  input_sizes_idx_0 = b_dataPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i = 0; i < input_sizes_idx_0; i++) {
      dataPoints[i + dataPoints.size(0) * b_i] =
          b_dataPoints[i + b_dataPoints.size(0) * b_i];
    }
  }
  coder::sortrows(dataPoints);
}

static void calculateCentralAngles(const coder::array<double, 2U> &XYdata,
                                   const double dataBoxSize[2],
                                   coder::array<double, 1U> &cornerAngle)
{
  coder::array<creal_T, 1U> r2;
  coder::array<double, 2U> b_XYdata;
  coder::array<double, 2U> firstStep;
  coder::array<double, 2U> longStep;
  coder::array<double, 2U> secondStep;
  coder::array<double, 1U> b_firstStep;
  coder::array<double, 1U> firstStepSquared;
  coder::array<double, 1U> r;
  coder::array<double, 1U> r1;
  coder::array<double, 1U> secondStepSquared;
  double b_dv[2];
  int i;
  int loop_ub;
  //  Calculate the central angle of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  //  Normalize data, because angles depend on scaling.
  //  calculate cosine of central angles
  coder::repmat(dataBoxSize, static_cast<double>(XYdata.size(0)), firstStep);
  coder::internal::minimum(XYdata, b_dv);
  coder::repmat(b_dv, static_cast<double>(XYdata.size(0)), secondStep);
  b_XYdata.set_size(XYdata.size(0), 2);
  loop_ub = XYdata.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_XYdata[i] = XYdata[i] / firstStep[i] - secondStep[i];
  }
  calculateTrianglesSides(b_XYdata, firstStep, secondStep, longStep);
  //  calculate area of squares of length of triangle sides
  loop_ub = firstStep.size(0);
  b_firstStep.set_size(firstStep.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = firstStep[i];
  }
  coder::power(b_firstStep, firstStepSquared);
  loop_ub = firstStep.size(0);
  b_firstStep.set_size(firstStep.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = firstStep[i + firstStep.size(0)];
  }
  coder::power(b_firstStep, r);
  loop_ub = firstStepSquared.size(0);
  for (i = 0; i < loop_ub; i++) {
    firstStepSquared[i] = firstStepSquared[i] + r[i];
  }
  loop_ub = secondStep.size(0);
  b_firstStep.set_size(secondStep.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = secondStep[i];
  }
  coder::power(b_firstStep, secondStepSquared);
  loop_ub = secondStep.size(0);
  b_firstStep.set_size(secondStep.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = secondStep[i + secondStep.size(0)];
  }
  coder::power(b_firstStep, r);
  loop_ub = secondStepSquared.size(0);
  for (i = 0; i < loop_ub; i++) {
    secondStepSquared[i] = secondStepSquared[i] + r[i];
  }
  loop_ub = longStep.size(0);
  b_firstStep.set_size(longStep.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = longStep[i];
  }
  coder::power(b_firstStep, r);
  loop_ub = longStep.size(0);
  b_firstStep.set_size(longStep.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = longStep[i + longStep.size(0)];
  }
  coder::power(b_firstStep, r1);
  b_firstStep.set_size(firstStepSquared.size(0));
  loop_ub = firstStepSquared.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_firstStep[i] = firstStepSquared[i] * secondStepSquared[i];
  }
  coder::b_sqrt(b_firstStep);
  r2.set_size(firstStepSquared.size(0));
  loop_ub = firstStepSquared.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i].re = ((firstStepSquared[i] + secondStepSquared[i]) - (r[i] + r1[i])) /
               2.0 / b_firstStep[i];
    r2[i].im = 0.0;
  }
  coder::b_acos(r2);
  cornerAngle.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    cornerAngle[i] = r2[i].re;
  }
}

static void calculateTrianglesSides(const coder::array<double, 2U> &XYdata,
                                    coder::array<double, 2U> &firstStep,
                                    coder::array<double, 2U> &secondStep,
                                    coder::array<double, 2U> &longStep)
{
  int i;
  int i1;
  int i2;
  int loop_ub;
  //  Return the sides (deltaX, deltaY) of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  if (2 > XYdata.size(0) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = XYdata.size(0) - 1;
  }
  loop_ub = i1 - i;
  firstStep.set_size(loop_ub, 2);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      firstStep[i2 + firstStep.size(0) * i1] =
          XYdata[(i + i2) + XYdata.size(0) * i1] -
          XYdata[i2 + XYdata.size(0) * i1];
    }
  }
  if (3 > XYdata.size(0)) {
    i = 0;
    i1 = 0;
    i2 = 0;
  } else {
    i = 2;
    i1 = XYdata.size(0);
    i2 = 1;
  }
  loop_ub = i1 - i;
  secondStep.set_size(loop_ub, 2);
  for (i1 = 0; i1 < 2; i1++) {
    for (int i3{0}; i3 < loop_ub; i3++) {
      secondStep[i3 + secondStep.size(0) * i1] =
          XYdata[(i + i3) + XYdata.size(0) * i1] -
          XYdata[(i2 + i3) + XYdata.size(0) * i1];
    }
  }
  if (3 > XYdata.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = 2;
    i1 = XYdata.size(0);
  }
  loop_ub = i1 - i;
  longStep.set_size(loop_ub, 2);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      longStep[i2 + longStep.size(0) * i1] =
          XYdata[(i + i2) + XYdata.size(0) * i1] -
          XYdata[i2 + XYdata.size(0) * i1];
    }
  }
}

static void increaseSampling(coder::array<double, 2U> &dataPoints,
                             const coder::array<boolean_T, 1U> &segmentsToSplit,
                             const coder::array<double, 2U> &sldProfile)
{
  coder::array<double, 2U> b_dataPoints;
  coder::array<double, 2U> newDataPoints;
  coder::array<double, 1U> b_newDataPoints;
  coder::array<double, 1U> r4;
  coder::array<int, 1U> r2;
  coder::array<int, 1U> r3;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> r1;
  int b_i;
  int end;
  int i;
  int input_sizes_idx_0;
  //  increaseSampling increase the sampling of an input function
  end = segmentsToSplit.size(0);
  input_sizes_idx_0 = 0;
  for (i = 0; i < end; i++) {
    if (segmentsToSplit[i]) {
      input_sizes_idx_0++;
    }
  }
  newDataPoints.set_size(input_sizes_idx_0, 2);
  input_sizes_idx_0 <<= 1;
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] = 0.0;
  }
  r.set_size(segmentsToSplit.size(0) + 1);
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r[b_i] = segmentsToSplit[b_i];
  }
  r[segmentsToSplit.size(0)] = false;
  r1.set_size(segmentsToSplit.size(0) + 1);
  r1[0] = false;
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r1[b_i + 1] = segmentsToSplit[b_i];
  }
  end = r.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      input_sizes_idx_0++;
    }
  }
  r2.set_size(input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      r2[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }
  end = r1.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      input_sizes_idx_0++;
    }
  }
  r3.set_size(input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      r3[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }
  input_sizes_idx_0 = r2.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] =
        0.5 * (dataPoints[r2[b_i] - 1] + dataPoints[r3[b_i] - 1]);
  }
  input_sizes_idx_0 = newDataPoints.size(0) - 1;
  b_newDataPoints.set_size(newDataPoints.size(0));
  for (b_i = 0; b_i <= input_sizes_idx_0; b_i++) {
    b_newDataPoints[b_i] = newDataPoints[b_i];
  }
  normalizeFunction(b_newDataPoints, sldProfile, r4);
  input_sizes_idx_0 = r4.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i + newDataPoints.size(0)] = r4[b_i];
  }
  //  For simplicity append the new points at the end and then sort.
  if (newDataPoints.size(0) != 0) {
    input_sizes_idx_0 = newDataPoints.size(0);
  } else {
    input_sizes_idx_0 = 0;
  }
  if (dataPoints.size(0) != 0) {
    end = dataPoints.size(0);
  } else {
    end = 0;
  }
  b_dataPoints.set_size(end + input_sizes_idx_0, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i = 0; i < end; i++) {
      b_dataPoints[i + b_dataPoints.size(0) * b_i] =
          dataPoints[i + dataPoints.size(0) * b_i];
    }
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_dataPoints[(i + end) + b_dataPoints.size(0) * b_i] =
          newDataPoints[i + newDataPoints.size(0) * b_i];
    }
  }
  dataPoints.set_size(b_dataPoints.size(0), 2);
  input_sizes_idx_0 = b_dataPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i = 0; i < input_sizes_idx_0; i++) {
      dataPoints[i + dataPoints.size(0) * b_i] =
          b_dataPoints[i + b_dataPoints.size(0) * b_i];
    }
  }
  coder::sortrows(dataPoints);
}

static void normalizeFunction(const double x[50],
                              const coder::array<double, 2U> &sldProfile,
                              double y[50])
{
  coder::array<double, 1U> r;
  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  for (int i{0}; i < 50; i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    sldFunc(x[i], sldProfile, r);
    y[i] = r[0];
  }
  // end
}

static void normalizeFunction(const coder::array<double, 1U> &x,
                              const coder::array<double, 2U> &sldProfile,
                              coder::array<double, 1U> &y)
{
  coder::array<double, 1U> r;
  int i;
  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  y.set_size(x.size(0));
  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  i = x.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    sldFunc(x[b_i], sldProfile, r);
    y[b_i] = r[0];
  }
  // end
}

static void normalizeFunction(double y[50])
{
  double tmp_data[3];
  int tmp_size;
  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  for (int i{0}; i < 50; i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    sldFunc(dv1[i], tmp_data, &tmp_size);
    y[i] = tmp_data[0];
  }
  // end
}

static void normalizeFunction(const coder::array<double, 1U> &x,
                              coder::array<double, 1U> &y)
{
  double tmp_data[3];
  int i;
  int tmp_size;
  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  y.set_size(x.size(0));
  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  i = x.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    sldFunc(x[b_i], tmp_data, &tmp_size);
    y[b_i] = tmp_data[0];
  }
  // end
}

void adaptive(const coder::array<double, 2U> &sldProfile,
              const double startDomain[2], cell_17 *out)
{
  coder::array<double, 2U> b_dataPoints;
  coder::array<double, 2U> dataPoints;
  coder::array<double, 1U> cornerAngle;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> segmentsToSplit;
  coder::array<boolean_T, 1U> trianglesToRefine;
  double b_newDomain[100];
  double hiVal[50];
  double newDomain[50];
  double b_dv[2];
  double b_dv1[2];
  int i;
  int loop_ub;
  //  adaptive: evaluates a matlab function on a given range
  //
  //  'adaptive.m' allows to sample a function using a reduced number of
  //  points. It works iteratively adding new points where needed.
  //  It is especially useful for functions which are computationally intensive
  //  (e.g. involve solving a differential equation).
  //
  //  Usage:
  //  XY = adaptive(func, [xstart, xend])
  //   evaluates 'func' in the range [xstart, xend]. Key-value arguments are
  //   used to control the function evaluation. If the function 'func' returns
  //   multiple output values, only the first one is used for the refinement
  //   process, but all of them are calculated and returned as additional
  //   columns in the output matrix. The output matrix XY contains the new
  //   domain points in the first column and the output values in the other
  //   columns.
  //  [x,yy] = adaptive(func, [xstart, xend])
  //    as before but separately returns the array with the domain points and
  //    the array/matrix with the function output values.
  //  [x,yy] = adaptive(func, xarray, ...)
  //    as before but explicitly provide an initial array of domain points.
  //
  //  Methods:
  //    'adaptive' provides three methods for refining the function evaluation:
  //    1) add more points near the sharp corners, which are found by
  //     considering the triangles formed by three successive points and
  //     measuring the central angle.
  //    2) measure the area of the same triangles and add more points when the
  //     area is bigger than a threshold.
  //    3) measure the length of the segments formed by pairs of successive
  //     and split the segments which are longer than a threshold.
  //    If no methods is explicitly specified, the 'angle' method is used.
  //
  //  Input parameters
  //   - func: input function (function handle)
  //   - initialDomain: initial domain points (1D array)
  //
  //  Optional key-value input parameters
  //   - 'nPoints': (default 20)
  //        initial number of domain points, only used if an initial domain
  //        array is not excplitely provided.
  //   - 'maxRefinements': (default 10)
  //        Specifies the maximum number of refinement steps.
  //   - 'minAngle': (default 0.8*pi)
  //        Refine near the  points which forms, together with their left and
  //        right neighbours, a triangle with central angle smaller than a given
  //        value.
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and
  //        right neighbours, a triangle with area larger than a threshold. The
  //        threshold in normalized to the area enclosing th graph:
  //        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x)))
  //   - 'maxLength': (default Inf)
  //        Refine all the sements which are longer than a given threshold. The
  //        threshold is relative to the input and output ranges. Specifically,
  //        before applying the threshold, the data are normalized so that
  //        max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
  //   - 'minLength': (default 0)
  //        Exclude from the refinement process the segments which are shorter
  //        than a given threshold. The threshold is relative to the input and
  //        output ranges. Specifically, before applying the threshold, the
  //        data are normalized so that max(x)-min(x)==1 and
  //        max(f(x))-min(f(x))==1.
  //   - 'minSignal': (default 0.2)
  //        Exclude from the refinement process the points where the function is
  //        below a threshold. The threshold is relative to the output range: In
  //        this example threshold == 0.01*(max(f(x))-min(f(x))).
  //   - 'vectorizable': (default false)
  //        Specifies whether the input function accepts arrays as input
  //        (e.g. f(x)==x.^2).
  //   - 'waitbar': (default false)
  //        Display a waitbar.
  //
  //  Output parameters
  //   - a NxM array where N is the number of domain points and M is the number
  //     of output parameters of the input function.
  //
  //
  //  Examples:
  //
  //    % Refine a function near sharp corners. The option 'minAngle' is useful
  //    % for having more points near the peaks of the function.
  //    f = @(x) exp(-x.^2/4).*sin(3*x);
  //    % for test-purpose also evaluate the function directly
  //    x2 = -10:0.01:10;
  //    y2 = f(x2);
  //    y = adaptive(f, [-5,5], 'minAngle',0.8*pi);
  //    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('high sampling','adaptive')
  //    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)')
  //    % as before but starting with an inital array of domain points
  //    x = -5:5;
  //    y = adaptive(f, x, 'minAngle',0.8*pi);
  //    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi)')
  //
  //    % Refine a function near sharp corners, but do not split segments which
  //    % are already shorter than 'minLength'.
  //    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05);
  //    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)');
  //
  //    % Refine a function until the areas of the triangles formed by
  //    % triplets of successive points are smaller than 'maxArea'.
  //    y = adaptive(f, x, 'maxArea',1e-3);
  //    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxArea'',1e-3)')
  //
  //    % Refine a function until the segments formed by pairs of successive
  //    % points are shorter than 'maxLength'.
  //    y = adaptive(f, x, 'maxLength',0.1);
  //    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxLength'',0.1)');
  //  Copyright
  //  2017, Alberto Comin -  LMU Muenchen
  //  Version changes:
  //
  //  24/01/2017: 1) new default: when no optional argument is given, use the
  //   'angle' method as default 2) it is now possible to provide just the
  //   start and the end of the function domain, instead of having to
  //   explicitly provide an initial array 3) a new key-word argument
  //   'nPoints' controls the number of initial domain points in the cases when
  //   the initial array is not explicitly provided. 4) it is now possible to
  //   return the domain points and the function values either as a single 2D
  //   array or as two separate arrays.
  //  25/01/2017: fixed defaults for the case when no method is specified
  //  Default settings
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  Test-mode
  //  The test mode is activated by calling 'adaptive.m' with no input.
  //  if nargin==0
  //    initialDomain =  -10:10;
  //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+
  //    20*exp(-10*(x-5.8).^2); thresholdingAngles = true; minAngle = 0.8*pi;
  //    thresholdingLength = true;
  //    minLength = 0.02;
  //    disp('Running adaptive.m in test mode');
  //    fprintf('input function: %s\n',func2str(input_func));
  //    disp('Plotting the function on a initial set of points');
  //    testFigureHandle = figure();
  //    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5);
  //    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example');
  //  end
  //  Processing input arguments
  //  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',...
  //    'the first argument must be a function handle');
  //  assert(isnumeric(initialDomain) && isvector(initialDomain),...
  //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as
  //    a numeric vector');
  //
  //  if mod(nExtraArgIn,2)==1
  //    error('adaptiveFunctionEvaluation:ArgChk', ...
  //      'At least a key or a value is missing in the key-value arguments
  //      list.');
  //  end
  //  while n < nExtraArgIn
  //    switch lower(varargin{n})
  //      case 'minangle'
  //      case 'maxarea'
  //        maxArea = varargin{n+1};
  //        thresholdingArea = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'maxlength'
  //        maxLength = varargin{n+1};
  //        thresholdingLength = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'minlength'
  //        minLength = varargin{n+1};
  //        thresholdingLength = true;
  //        n = n+2;
  //      case 'minsignal'
  //        minSignal = varargin{n+1};
  //        thresholdingSignal = true;
  //        n = n+2;
  //      case 'npoints'
  //        nPoints = varargin{n+1};
  //        n = n+2;
  //      case 'vectorize'
  //        vectorizable = varargin{n+1};
  //        n = n+2;
  //      case 'maxrefinements'
  //        maxRefinements = varargin{n+1};
  //        n = n+2;
  //      case 'waitbar'
  //        displayWaitbar = varargin{n+1};
  //        n = n+2;
  //      otherwise
  //        error('adaptiveFunctionEvaluation:ArgChk',...
  //          ['unknown keyword argument: ', varargin{n}]);
  //    end
  //  end
  //  if no method is specified use the 'angle' method as default
  //  Initial function evaluation
  //  if initialDomain only contains the start and the end points, create a new
  //  array with 'nPoints' points.
  coder::b_linspace(startDomain[0], startDomain[1], hiVal);
  //  Normalize the input function: This step allows to use the same syntax for
  //  functions with single or multiple output parameters.
  //  Remove this syntax for compile - AVH
  // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
  //  Evaluate the input function on the initial set of points.
  // dataPoints = [initialDomain(:), func(initialDomain(:))];
  for (i = 0; i < 50; i++) {
    double d;
    d = hiVal[i];
    newDomain[i] = d;
    b_newDomain[i] = d;
  }
  normalizeFunction(newDomain, sldProfile, hiVal);
  std::copy(&hiVal[0], &hiVal[50], &b_newDomain[50]);
  dataPoints.set_size(50, 2);
  for (i = 0; i < 100; i++) {
    dataPoints[i] = b_newDomain[i];
  }
  //  Iterative function refinement
  //  if displayWaitbar
  //    refinementWaitbar = waitbar(0,['Evaluating function
  //    ',func2str(func)],...
  //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
  //    setappdata(refinementWaitbar,'canceling',false)
  //  end
  for (int nRefinements{0}; nRefinements < 10; nRefinements++) {
    int i1;
    //  calculate the box which encloses the current data points:
    //  Each point is considered as the central corner of the triangle formed
    //  with its left and right hand side neighbours. The first and the last
    //  points are not the central corner of any triangle, so for N points
    //  there are only N-2 triangles.
    loop_ub = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dataPoints[i1 + b_dataPoints.size(0) * i] =
            dataPoints[i1 + dataPoints.size(0) * i];
      }
    }
    coder::internal::maximum(b_dataPoints, b_dv);
    loop_ub = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dataPoints[i1 + b_dataPoints.size(0) * i] =
            dataPoints[i1 + dataPoints.size(0) * i];
      }
    }
    coder::internal::minimum(b_dataPoints, b_dv1);
    loop_ub = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dataPoints[i1 + b_dataPoints.size(0) * i] =
            dataPoints[i1 + dataPoints.size(0) * i];
      }
      b_dv[i] -= b_dv1[i];
    }
    calculateCentralAngles(b_dataPoints, b_dv, cornerAngle);
    loop_ub = dataPoints.size(0);
    trianglesToRefine.set_size(dataPoints.size(0) - 2);
    for (i = 0; i <= loop_ub - 3; i++) {
      trianglesToRefine[i] = (cornerAngle[i] < 2.9845130209103035);
    }
    //  For N points there are N-2 triangles and N-1 triangle sides. Each
    //  triangle side is a segment, which can be split or not depending on the
    //  refinement parameters.
    segmentsToSplit.set_size(trianglesToRefine.size(0) + 1);
    loop_ub = trianglesToRefine.size(0);
    for (i = 0; i < loop_ub; i++) {
      segmentsToSplit[i] = trianglesToRefine[i];
    }
    segmentsToSplit[trianglesToRefine.size(0)] = false;
    r.set_size(trianglesToRefine.size(0) + 1);
    r[0] = false;
    loop_ub = trianglesToRefine.size(0);
    for (i = 0; i < loop_ub; i++) {
      r[i + 1] = trianglesToRefine[i];
    }
    loop_ub = segmentsToSplit.size(0);
    for (i = 0; i < loop_ub; i++) {
      segmentsToSplit[i] = (segmentsToSplit[i] || r[i]);
    }
    if (coder::any(segmentsToSplit)) {
      increaseSampling(dataPoints, segmentsToSplit, sldProfile);
      //    else
      //      break;
    }
    //  Removed waitbar for compile - AVH
    //    if displayWaitbar
    //      if getappdata(refinementWaitbar,'canceling'), break; end
    //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
    //    end
  }
  //  if displayWaitbar
  //    delete(refinementWaitbar);
  //  end
  //  Plotting refined function
  //  Removed for compile - AVH
  //  if nargin==0 % test mode
  //    figure(testFigureHandle);
  //    hold on;
  //    plot(dataPoints(:,1), dataPoints(:,2),'ro-');
  //    legend('initial', 'refiniment');
  //  end
  out->f1.set_size(dataPoints.size(0), 2);
  loop_ub = dataPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    out->f1[i] = dataPoints[i];
  }
}

void adaptive(cell_17 *out)
{
  coder::array<double, 2U> b_dataPoints;
  coder::array<double, 2U> dataPoints;
  coder::array<double, 1U> cornerAngle;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> segmentsToSplit;
  coder::array<boolean_T, 1U> trianglesToRefine;
  double initialDomain[100];
  double hiVal[50];
  double b_dv[2];
  double b_dv1[2];
  int i;
  int loop_ub;
  //  adaptive: evaluates a matlab function on a given range
  //
  //  'adaptive.m' allows to sample a function using a reduced number of
  //  points. It works iteratively adding new points where needed.
  //  It is especially useful for functions which are computationally intensive
  //  (e.g. involve solving a differential equation).
  //
  //  Usage:
  //  XY = adaptive(func, [xstart, xend])
  //   evaluates 'func' in the range [xstart, xend]. Key-value arguments are
  //   used to control the function evaluation. If the function 'func' returns
  //   multiple output values, only the first one is used for the refinement
  //   process, but all of them are calculated and returned as additional
  //   columns in the output matrix. The output matrix XY contains the new
  //   domain points in the first column and the output values in the other
  //   columns.
  //  [x,yy] = adaptive(func, [xstart, xend])
  //    as before but separately returns the array with the domain points and
  //    the array/matrix with the function output values.
  //  [x,yy] = adaptive(func, xarray, ...)
  //    as before but explicitly provide an initial array of domain points.
  //
  //  Methods:
  //    'adaptive' provides three methods for refining the function evaluation:
  //    1) add more points near the sharp corners, which are found by
  //     considering the triangles formed by three successive points and
  //     measuring the central angle.
  //    2) measure the area of the same triangles and add more points when the
  //     area is bigger than a threshold.
  //    3) measure the length of the segments formed by pairs of successive
  //     and split the segments which are longer than a threshold.
  //    If no methods is explicitly specified, the 'angle' method is used.
  //
  //  Input parameters
  //   - func: input function (function handle)
  //   - initialDomain: initial domain points (1D array)
  //
  //  Optional key-value input parameters
  //   - 'nPoints': (default 20)
  //        initial number of domain points, only used if an initial domain
  //        array is not excplitely provided.
  //   - 'maxRefinements': (default 10)
  //        Specifies the maximum number of refinement steps.
  //   - 'minAngle': (default 0.8*pi)
  //        Refine near the  points which forms, together with their left and
  //        right neighbours, a triangle with central angle smaller than a given
  //        value.
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and
  //        right neighbours, a triangle with area larger than a threshold. The
  //        threshold in normalized to the area enclosing th graph:
  //        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x)))
  //   - 'maxLength': (default Inf)
  //        Refine all the sements which are longer than a given threshold. The
  //        threshold is relative to the input and output ranges. Specifically,
  //        before applying the threshold, the data are normalized so that
  //        max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
  //   - 'minLength': (default 0)
  //        Exclude from the refinement process the segments which are shorter
  //        than a given threshold. The threshold is relative to the input and
  //        output ranges. Specifically, before applying the threshold, the
  //        data are normalized so that max(x)-min(x)==1 and
  //        max(f(x))-min(f(x))==1.
  //   - 'minSignal': (default 0.2)
  //        Exclude from the refinement process the points where the function is
  //        below a threshold. The threshold is relative to the output range: In
  //        this example threshold == 0.01*(max(f(x))-min(f(x))).
  //   - 'vectorizable': (default false)
  //        Specifies whether the input function accepts arrays as input
  //        (e.g. f(x)==x.^2).
  //   - 'waitbar': (default false)
  //        Display a waitbar.
  //
  //  Output parameters
  //   - a NxM array where N is the number of domain points and M is the number
  //     of output parameters of the input function.
  //
  //
  //  Examples:
  //
  //    % Refine a function near sharp corners. The option 'minAngle' is useful
  //    % for having more points near the peaks of the function.
  //    f = @(x) exp(-x.^2/4).*sin(3*x);
  //    % for test-purpose also evaluate the function directly
  //    x2 = -10:0.01:10;
  //    y2 = f(x2);
  //    y = adaptive(f, [-5,5], 'minAngle',0.8*pi);
  //    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('high sampling','adaptive')
  //    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)')
  //    % as before but starting with an inital array of domain points
  //    x = -5:5;
  //    y = adaptive(f, x, 'minAngle',0.8*pi);
  //    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi)')
  //
  //    % Refine a function near sharp corners, but do not split segments which
  //    % are already shorter than 'minLength'.
  //    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05);
  //    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)');
  //
  //    % Refine a function until the areas of the triangles formed by
  //    % triplets of successive points are smaller than 'maxArea'.
  //    y = adaptive(f, x, 'maxArea',1e-3);
  //    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxArea'',1e-3)')
  //
  //    % Refine a function until the segments formed by pairs of successive
  //    % points are shorter than 'maxLength'.
  //    y = adaptive(f, x, 'maxLength',0.1);
  //    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxLength'',0.1)');
  //  Copyright
  //  2017, Alberto Comin -  LMU Muenchen
  //  Version changes:
  //
  //  24/01/2017: 1) new default: when no optional argument is given, use the
  //   'angle' method as default 2) it is now possible to provide just the
  //   start and the end of the function domain, instead of having to
  //   explicitly provide an initial array 3) a new key-word argument
  //   'nPoints' controls the number of initial domain points in the cases when
  //   the initial array is not explicitly provided. 4) it is now possible to
  //   return the domain points and the function values either as a single 2D
  //   array or as two separate arrays.
  //  25/01/2017: fixed defaults for the case when no method is specified
  //  Default settings
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  Test-mode
  //  The test mode is activated by calling 'adaptive.m' with no input.
  //  if nargin==0
  //    initialDomain =  -10:10;
  //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+
  //    20*exp(-10*(x-5.8).^2); thresholdingAngles = true; minAngle = 0.8*pi;
  //    thresholdingLength = true;
  //    minLength = 0.02;
  //    disp('Running adaptive.m in test mode');
  //    fprintf('input function: %s\n',func2str(input_func));
  //    disp('Plotting the function on a initial set of points');
  //    testFigureHandle = figure();
  //    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5);
  //    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example');
  //  end
  //  Processing input arguments
  //  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',...
  //    'the first argument must be a function handle');
  //  assert(isnumeric(initialDomain) && isvector(initialDomain),...
  //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as
  //    a numeric vector');
  //
  //  if mod(nExtraArgIn,2)==1
  //    error('adaptiveFunctionEvaluation:ArgChk', ...
  //      'At least a key or a value is missing in the key-value arguments
  //      list.');
  //  end
  //  while n < nExtraArgIn
  //    switch lower(varargin{n})
  //      case 'minangle'
  //      case 'maxarea'
  //        maxArea = varargin{n+1};
  //        thresholdingArea = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'maxlength'
  //        maxLength = varargin{n+1};
  //        thresholdingLength = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'minlength'
  //        minLength = varargin{n+1};
  //        thresholdingLength = true;
  //        n = n+2;
  //      case 'minsignal'
  //        minSignal = varargin{n+1};
  //        thresholdingSignal = true;
  //        n = n+2;
  //      case 'npoints'
  //        nPoints = varargin{n+1};
  //        n = n+2;
  //      case 'vectorize'
  //        vectorizable = varargin{n+1};
  //        n = n+2;
  //      case 'maxrefinements'
  //        maxRefinements = varargin{n+1};
  //        n = n+2;
  //      case 'waitbar'
  //        displayWaitbar = varargin{n+1};
  //        n = n+2;
  //      otherwise
  //        error('adaptiveFunctionEvaluation:ArgChk',...
  //          ['unknown keyword argument: ', varargin{n}]);
  //    end
  //  end
  //  if no method is specified use the 'angle' method as default
  //  Initial function evaluation
  //  if initialDomain only contains the start and the end points, create a new
  //  array with 'nPoints' points.
  //  Normalize the input function: This step allows to use the same syntax for
  //  functions with single or multiple output parameters.
  //  Remove this syntax for compile - AVH
  // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
  //  Evaluate the input function on the initial set of points.
  normalizeFunction(hiVal);
  // dataPoints = [initialDomain(:), func(initialDomain(:))];
  for (i = 0; i < 50; i++) {
    initialDomain[i] = dv1[i];
    initialDomain[i + 50] = hiVal[i];
  }
  dataPoints.set_size(50, 2);
  for (i = 0; i < 100; i++) {
    dataPoints[i] = initialDomain[i];
  }
  //  Iterative function refinement
  //  if displayWaitbar
  //    refinementWaitbar = waitbar(0,['Evaluating function
  //    ',func2str(func)],...
  //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
  //    setappdata(refinementWaitbar,'canceling',false)
  //  end
  for (int nRefinements{0}; nRefinements < 10; nRefinements++) {
    int i1;
    //  calculate the box which encloses the current data points:
    //  Each point is considered as the central corner of the triangle formed
    //  with its left and right hand side neighbours. The first and the last
    //  points are not the central corner of any triangle, so for N points
    //  there are only N-2 triangles.
    loop_ub = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dataPoints[i1 + b_dataPoints.size(0) * i] =
            dataPoints[i1 + dataPoints.size(0) * i];
      }
    }
    coder::internal::maximum(b_dataPoints, b_dv);
    loop_ub = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dataPoints[i1 + b_dataPoints.size(0) * i] =
            dataPoints[i1 + dataPoints.size(0) * i];
      }
    }
    coder::internal::minimum(b_dataPoints, b_dv1);
    loop_ub = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dataPoints[i1 + b_dataPoints.size(0) * i] =
            dataPoints[i1 + dataPoints.size(0) * i];
      }
      b_dv[i] -= b_dv1[i];
    }
    calculateCentralAngles(b_dataPoints, b_dv, cornerAngle);
    loop_ub = dataPoints.size(0);
    trianglesToRefine.set_size(dataPoints.size(0) - 2);
    for (i = 0; i <= loop_ub - 3; i++) {
      trianglesToRefine[i] = (cornerAngle[i] < 2.9845130209103035);
    }
    //  For N points there are N-2 triangles and N-1 triangle sides. Each
    //  triangle side is a segment, which can be split or not depending on the
    //  refinement parameters.
    segmentsToSplit.set_size(trianglesToRefine.size(0) + 1);
    loop_ub = trianglesToRefine.size(0);
    for (i = 0; i < loop_ub; i++) {
      segmentsToSplit[i] = trianglesToRefine[i];
    }
    segmentsToSplit[trianglesToRefine.size(0)] = false;
    r.set_size(trianglesToRefine.size(0) + 1);
    r[0] = false;
    loop_ub = trianglesToRefine.size(0);
    for (i = 0; i < loop_ub; i++) {
      r[i + 1] = trianglesToRefine[i];
    }
    loop_ub = segmentsToSplit.size(0);
    for (i = 0; i < loop_ub; i++) {
      segmentsToSplit[i] = (segmentsToSplit[i] || r[i]);
    }
    if (coder::any(segmentsToSplit)) {
      b_increaseSampling(dataPoints, segmentsToSplit);
      //    else
      //      break;
    }
    //  Removed waitbar for compile - AVH
    //    if displayWaitbar
    //      if getappdata(refinementWaitbar,'canceling'), break; end
    //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
    //    end
  }
  //  if displayWaitbar
  //    delete(refinementWaitbar);
  //  end
  //  Plotting refined function
  //  Removed for compile - AVH
  //  if nargin==0 % test mode
  //    figure(testFigureHandle);
  //    hold on;
  //    plot(dataPoints(:,1), dataPoints(:,2),'ro-');
  //    legend('initial', 'refiniment');
  //  end
  out->f1.set_size(dataPoints.size(0), 2);
  loop_ub = dataPoints.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    out->f1[i] = dataPoints[i];
  }
}

// End of code generation (adaptive.cpp)
