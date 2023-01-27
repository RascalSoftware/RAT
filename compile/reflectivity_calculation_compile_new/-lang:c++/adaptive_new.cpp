//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: adaptive_new.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "adaptive_new.h"
#include "acos.h"
#include "allOrAny.h"
#include "eml_mtimes_helper.h"
#include "linspace.h"
#include "minOrMax.h"
#include "reflectivity_calculation_internal_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortrows.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void b_binary_expand_op(::coder::array<boolean_T, 1U> &in1, const
    cell_23 *in2, const ::coder::array<real_T, 1U> &in3, real_T in4);
  static void b_increaseSampling(::coder::array<real_T, 2U> &dataPoints, const ::
    coder::array<boolean_T, 1U> &segmentsToSplit, const real_T sldProfile_data[],
    const int32_T sldProfile_size[2]);
  static void binary_expand_op(const ::coder::array<real_T, 2U> &in1, const ::
    coder::array<real_T, 2U> &in2, const ::coder::array<real_T, 2U> &in3, ::
    coder::array<real_T, 2U> &in4, ::coder::array<real_T, 2U> &in5, ::coder::
    array<real_T, 2U> &in6);
  static void binary_expand_op(::coder::array<real_T, 2U> &in1, const ::coder::
    array<real_T, 2U> &in2, int32_T in3, int32_T in4, int32_T in5, int32_T in6);
  static void binary_expand_op(::coder::array<real_T, 2U> &in1, const ::coder::
    array<real_T, 2U> &in2, int32_T in3, int32_T in4, int32_T in5);
  static void binary_expand_op(::coder::array<creal_T, 1U> &in1, const ::coder::
    array<real_T, 1U> &in2, const ::coder::array<real_T, 1U> &in3, const ::coder::
    array<real_T, 1U> &in4, const ::coder::array<real_T, 1U> &in5, const ::coder::
    array<real_T, 1U> &in6);
  static void calculateCentralAngles(const ::coder::array<real_T, 2U> &XYdata,
    const real_T dataBoxSize[2], ::coder::array<real_T, 1U> &cornerAngle);
  static void calculateTrianglesSides(const ::coder::array<real_T, 2U> &XYdata, ::
    coder::array<real_T, 2U> &firstStep, ::coder::array<real_T, 2U> &secondStep,
    ::coder::array<real_T, 2U> &longStep);
  static void increaseSampling(::coder::array<real_T, 2U> &dataPoints, const ::
    coder::array<boolean_T, 1U> &segmentsToSplit, const ::coder::array<real_T,
    2U> &sldProfile);
  static void normalizeFunction(const ::coder::array<real_T, 1U> &x, const ::
    coder::array<real_T, 2U> &sldProfile, ::coder::array<real_T, 1U> &y);
  static void normalizeFunction(const ::coder::array<real_T, 1U> &x, const
    real_T sldProfile_data[], const int32_T sldProfile_size[2], ::coder::array<
    real_T, 1U> &y);
  static void times(::coder::array<real_T, 1U> &in1, const ::coder::array<real_T,
                    1U> &in2, const ::coder::array<real_T, 1U> &in3);
}

// Function Definitions
//
// Arguments    : ::coder::array<boolean_T, 1U> &in1
//                const cell_23 *in2
//                const ::coder::array<real_T, 1U> &in3
//                real_T in4
// Return Type  : void
//
namespace RAT
{
  static void b_binary_expand_op(::coder::array<boolean_T, 1U> &in1, const
    cell_23 *in2, const ::coder::array<real_T, 1U> &in3, real_T in4)
  {
    int32_T i;
    int32_T in2_idx_0;
    int32_T stride_1_0;
    in2_idx_0 = in2->f1.size(0) - 2;
    if (in3.size(0) == 1) {
      i = in2_idx_0;
    } else {
      i = in3.size(0);
    }

    in1.set_size(i);
    stride_1_0 = (in3.size(0) != 1);
    if (in3.size(0) != 1) {
      in2_idx_0 = in3.size(0);
    }

    for (i = 0; i < in2_idx_0; i++) {
      in1[i] = (in3[i * stride_1_0] < in4);
    }
  }

  //
  // increaseSampling increase the sampling of an input function
  //
  // Arguments    : ::coder::array<real_T, 2U> &dataPoints
  //                const ::coder::array<boolean_T, 1U> &segmentsToSplit
  //                const real_T sldProfile_data[]
  //                const int32_T sldProfile_size[2]
  // Return Type  : void
  //
  static void b_increaseSampling(::coder::array<real_T, 2U> &dataPoints, const ::
    coder::array<boolean_T, 1U> &segmentsToSplit, const real_T sldProfile_data[],
    const int32_T sldProfile_size[2])
  {
    ::coder::array<real_T, 2U> b_dataPoints;
    ::coder::array<real_T, 2U> newDataPoints;
    ::coder::array<real_T, 1U> b_newDataPoints;
    ::coder::array<real_T, 1U> r4;
    ::coder::array<int32_T, 1U> r2;
    ::coder::array<int32_T, 1U> r3;
    ::coder::array<boolean_T, 1U> r;
    ::coder::array<boolean_T, 1U> r1;
    int32_T end;
    int32_T input_sizes_idx_0;
    end = segmentsToSplit.size(0);
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i < end; i++) {
      if (segmentsToSplit[i]) {
        input_sizes_idx_0++;
      }
    }

    newDataPoints.set_size(input_sizes_idx_0, 2);
    for (int32_T i{0}; i < 2; i++) {
      for (int32_T b_i{0}; b_i < input_sizes_idx_0; b_i++) {
        newDataPoints[b_i + newDataPoints.size(0) * i] = 0.0;
      }
    }

    r.set_size(segmentsToSplit.size(0) + 1);
    input_sizes_idx_0 = segmentsToSplit.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      r[i] = segmentsToSplit[i];
    }

    r[segmentsToSplit.size(0)] = false;
    r1.set_size(segmentsToSplit.size(0) + 1);
    r1[0] = false;
    input_sizes_idx_0 = segmentsToSplit.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      r1[i + 1] = segmentsToSplit[i];
    }

    end = r.size(0) - 1;
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r[i]) {
        input_sizes_idx_0++;
      }
    }

    r2.set_size(input_sizes_idx_0);
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r[i]) {
        r2[input_sizes_idx_0] = i + 1;
        input_sizes_idx_0++;
      }
    }

    end = r1.size(0) - 1;
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r1[i]) {
        input_sizes_idx_0++;
      }
    }

    r3.set_size(input_sizes_idx_0);
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r1[i]) {
        r3[input_sizes_idx_0] = i + 1;
        input_sizes_idx_0++;
      }
    }

    if (r2.size(0) == r3.size(0)) {
      input_sizes_idx_0 = r2.size(0);
      for (int32_T i{0}; i < input_sizes_idx_0; i++) {
        newDataPoints[i] = 0.5 * (dataPoints[r2[i] - 1] + dataPoints[r3[i] - 1]);
      }
    } else {
      binary_expand_op(newDataPoints, dataPoints, r2, r3);
    }

    b_newDataPoints.set_size(newDataPoints.size(0));
    input_sizes_idx_0 = newDataPoints.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      b_newDataPoints[i] = newDataPoints[i];
    }

    normalizeFunction(b_newDataPoints, sldProfile_data, sldProfile_size, r4);
    input_sizes_idx_0 = r4.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      newDataPoints[i + newDataPoints.size(0)] = r4[i];
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
    for (int32_T i{0}; i < 2; i++) {
      for (int32_T b_i{0}; b_i < end; b_i++) {
        b_dataPoints[b_i + b_dataPoints.size(0) * i] = dataPoints[b_i +
          dataPoints.size(0) * i];
      }

      for (int32_T b_i{0}; b_i < input_sizes_idx_0; b_i++) {
        b_dataPoints[(b_i + end) + b_dataPoints.size(0) * i] = newDataPoints[b_i
          + newDataPoints.size(0) * i];
      }
    }

    dataPoints.set_size(b_dataPoints.size(0), 2);
    input_sizes_idx_0 = b_dataPoints.size(0);
    for (int32_T i{0}; i < 2; i++) {
      for (int32_T b_i{0}; b_i < input_sizes_idx_0; b_i++) {
        dataPoints[b_i + dataPoints.size(0) * i] = b_dataPoints[b_i +
          b_dataPoints.size(0) * i];
      }
    }

    coder::sortrows(dataPoints);
  }

  //
  // Arguments    : const ::coder::array<real_T, 2U> &in1
  //                const ::coder::array<real_T, 2U> &in2
  //                const ::coder::array<real_T, 2U> &in3
  //                ::coder::array<real_T, 2U> &in4
  //                ::coder::array<real_T, 2U> &in5
  //                ::coder::array<real_T, 2U> &in6
  // Return Type  : void
  //
  static void binary_expand_op(const ::coder::array<real_T, 2U> &in1, const ::
    coder::array<real_T, 2U> &in2, const ::coder::array<real_T, 2U> &in3, ::
    coder::array<real_T, 2U> &in4, ::coder::array<real_T, 2U> &in5, ::coder::
    array<real_T, 2U> &in6)
  {
    ::coder::array<real_T, 2U> b_in1;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    if (in3.size(0) == 1) {
      if (in2.size(0) == 1) {
        i = in1.size(0);
      } else {
        i = in2.size(0);
      }
    } else {
      i = in3.size(0);
    }

    b_in1.set_size(i, 2);
    stride_0_0 = (in1.size(0) != 1);
    stride_1_0 = (in2.size(0) != 1);
    stride_2_0 = (in3.size(0) != 1);
    if (in3.size(0) == 1) {
      if (in2.size(0) == 1) {
        loop_ub = in1.size(0);
      } else {
        loop_ub = in2.size(0);
      }
    } else {
      loop_ub = in3.size(0);
    }

    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        b_in1[i1 + b_in1.size(0) * i] = in1[i1 * stride_0_0 + in1.size(0) * i] /
          in2[i1 * stride_1_0 + in2.size(0) * i] - in3[i1 * stride_2_0 +
          in3.size(0) * i];
      }
    }

    calculateTrianglesSides(b_in1, in4, in5, in6);
  }

  //
  // Arguments    : ::coder::array<real_T, 2U> &in1
  //                const ::coder::array<real_T, 2U> &in2
  //                int32_T in3
  //                int32_T in4
  //                int32_T in5
  //                int32_T in6
  // Return Type  : void
  //
  static void binary_expand_op(::coder::array<real_T, 2U> &in1, const ::coder::
    array<real_T, 2U> &in2, int32_T in3, int32_T in4, int32_T in5, int32_T in6)
  {
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    if ((in6 - in5) + 1 == 1) {
      i = (in4 - in3) + 1;
    } else {
      i = (in6 - in5) + 1;
    }

    in1.set_size(i, 2);
    stride_0_0 = ((in4 - in3) + 1 != 1);
    stride_1_0 = ((in6 - in5) + 1 != 1);
    if ((in6 - in5) + 1 == 1) {
      loop_ub = (in4 - in3) + 1;
    } else {
      loop_ub = (in6 - in5) + 1;
    }

    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[(in3 + i1 * stride_0_0) + in2.size(0) *
          i] - in2[(in5 + i1 * stride_1_0) + in2.size(0) * i];
      }
    }
  }

  //
  // Arguments    : ::coder::array<real_T, 2U> &in1
  //                const ::coder::array<real_T, 2U> &in2
  //                int32_T in3
  //                int32_T in4
  //                int32_T in5
  // Return Type  : void
  //
  static void binary_expand_op(::coder::array<real_T, 2U> &in1, const ::coder::
    array<real_T, 2U> &in2, int32_T in3, int32_T in4, int32_T in5)
  {
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    if (in5 + 1 == 1) {
      i = (in4 - in3) + 1;
    } else {
      i = in5 + 1;
    }

    in1.set_size(i, 2);
    stride_0_0 = ((in4 - in3) + 1 != 1);
    stride_1_0 = (in5 + 1 != 1);
    if (in5 + 1 == 1) {
      loop_ub = (in4 - in3) + 1;
    } else {
      loop_ub = in5 + 1;
    }

    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[(in3 + i1 * stride_0_0) + in2.size(0) *
          i] - in2[i1 * stride_1_0 + in2.size(0) * i];
      }
    }
  }

  //
  // Arguments    : ::coder::array<creal_T, 1U> &in1
  //                const ::coder::array<real_T, 1U> &in2
  //                const ::coder::array<real_T, 1U> &in3
  //                const ::coder::array<real_T, 1U> &in4
  //                const ::coder::array<real_T, 1U> &in5
  //                const ::coder::array<real_T, 1U> &in6
  // Return Type  : void
  //
  static void binary_expand_op(::coder::array<creal_T, 1U> &in1, const ::coder::
    array<real_T, 1U> &in2, const ::coder::array<real_T, 1U> &in3, const ::coder::
    array<real_T, 1U> &in4, const ::coder::array<real_T, 1U> &in5, const ::coder::
    array<real_T, 1U> &in6)
  {
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    int32_T stride_3_0;
    if (in6.size(0) == 1) {
      if (in4.size(0) == 1) {
        if (in3.size(0) == 1) {
          i = in2.size(0);
        } else {
          i = in3.size(0);
        }
      } else {
        i = in4.size(0);
      }
    } else {
      i = in6.size(0);
    }

    in1.set_size(i);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_3_0 = (in6.size(0) != 1);
    if (in6.size(0) == 1) {
      if (in4.size(0) == 1) {
        if (in3.size(0) == 1) {
          loop_ub = in2.size(0);
        } else {
          loop_ub = in3.size(0);
        }
      } else {
        loop_ub = in4.size(0);
      }
    } else {
      loop_ub = in6.size(0);
    }

    for (i = 0; i < loop_ub; i++) {
      int32_T i1;
      i1 = i * stride_2_0;
      in1[i].re = ((in2[i * stride_0_0] + in3[i * stride_1_0]) - (in4[i1] +
        in5[i1])) / 2.0 / in6[i * stride_3_0];
      in1[i].im = 0.0;
    }
  }

  //
  // Calculate the central angle of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  //
  // Arguments    : const ::coder::array<real_T, 2U> &XYdata
  //                const real_T dataBoxSize[2]
  //                ::coder::array<real_T, 1U> &cornerAngle
  // Return Type  : void
  //
  static void calculateCentralAngles(const ::coder::array<real_T, 2U> &XYdata,
    const real_T dataBoxSize[2], ::coder::array<real_T, 1U> &cornerAngle)
  {
    ::coder::array<creal_T, 1U> r4;
    ::coder::array<real_T, 2U> b_XYdata;
    ::coder::array<real_T, 2U> firstStep;
    ::coder::array<real_T, 2U> longStep;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> secondStep;
    ::coder::array<real_T, 1U> firstStepSquared;
    ::coder::array<real_T, 1U> r1;
    ::coder::array<real_T, 1U> r2;
    ::coder::array<real_T, 1U> r3;
    ::coder::array<real_T, 1U> secondStepSquared;
    real_T dv[2];
    real_T varargin_1;
    int32_T i;
    int32_T i1;
    int32_T k;

    //  Normalize data, because angles depend on scaling.
    //  calculate cosine of central angles
    coder::repmat(dataBoxSize, static_cast<real_T>(XYdata.size(0)), b_XYdata);
    coder::internal::minimum(XYdata, dv);
    coder::repmat(dv, static_cast<real_T>(XYdata.size(0)), r);
    if (XYdata.size(0) == 1) {
      i = b_XYdata.size(0);
    } else {
      i = XYdata.size(0);
    }

    if ((XYdata.size(0) == b_XYdata.size(0)) && (i == r.size(0))) {
      b_XYdata.set_size(XYdata.size(0), 2);
      k = XYdata.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < k; i1++) {
          b_XYdata[i1 + b_XYdata.size(0) * i] = XYdata[i1 + XYdata.size(0) * i] /
            b_XYdata[i1 + b_XYdata.size(0) * i] - r[i1 + r.size(0) * i];
        }
      }

      calculateTrianglesSides(b_XYdata, firstStep, secondStep, longStep);
    } else {
      binary_expand_op(XYdata, b_XYdata, r, firstStep, secondStep, longStep);
    }

    //  calculate area of squares of length of triangle sides
    r1.set_size(firstStep.size(0));
    k = firstStep.size(0);
    for (i = 0; i < k; i++) {
      varargin_1 = firstStep[i];
      r1[i] = varargin_1 * varargin_1;
    }

    r2.set_size(firstStep.size(0));
    k = firstStep.size(0);
    for (i = 0; i < k; i++) {
      varargin_1 = firstStep[i + firstStep.size(0)];
      r2[i] = varargin_1 * varargin_1;
    }

    firstStepSquared.set_size(r1.size(0));
    k = r1.size(0);
    for (i = 0; i < k; i++) {
      firstStepSquared[i] = r1[i] + r2[i];
    }

    r1.set_size(secondStep.size(0));
    k = secondStep.size(0);
    for (i = 0; i < k; i++) {
      varargin_1 = secondStep[i];
      r1[i] = varargin_1 * varargin_1;
    }

    r2.set_size(secondStep.size(0));
    k = secondStep.size(0);
    for (i = 0; i < k; i++) {
      varargin_1 = secondStep[i + secondStep.size(0)];
      r2[i] = varargin_1 * varargin_1;
    }

    secondStepSquared.set_size(r1.size(0));
    k = r1.size(0);
    for (i = 0; i < k; i++) {
      secondStepSquared[i] = r1[i] + r2[i];
    }

    r1.set_size(longStep.size(0));
    k = longStep.size(0);
    for (i = 0; i < k; i++) {
      varargin_1 = longStep[i];
      r1[i] = varargin_1 * varargin_1;
    }

    r2.set_size(longStep.size(0));
    k = longStep.size(0);
    for (i = 0; i < k; i++) {
      varargin_1 = longStep[i + longStep.size(0)];
      r2[i] = varargin_1 * varargin_1;
    }

    if (firstStepSquared.size(0) == secondStepSquared.size(0)) {
      r3.set_size(firstStepSquared.size(0));
      k = firstStepSquared.size(0);
      for (i = 0; i < k; i++) {
        r3[i] = firstStepSquared[i] * secondStepSquared[i];
      }
    } else {
      times(r3, firstStepSquared, secondStepSquared);
    }

    i = r3.size(0);
    for (k = 0; k < i; k++) {
      r3[k] = std::sqrt(r3[k]);
    }

    if (firstStepSquared.size(0) == 1) {
      i = secondStepSquared.size(0);
    } else {
      i = firstStepSquared.size(0);
    }

    if (firstStepSquared.size(0) == 1) {
      i1 = secondStepSquared.size(0);
    } else {
      i1 = firstStepSquared.size(0);
    }

    if (i1 == 1) {
      i1 = r1.size(0);
    } else if (firstStepSquared.size(0) == 1) {
      i1 = secondStepSquared.size(0);
    } else {
      i1 = firstStepSquared.size(0);
    }

    if ((firstStepSquared.size(0) == secondStepSquared.size(0)) && (i == r1.size
         (0)) && (i1 == r3.size(0))) {
      r4.set_size(firstStepSquared.size(0));
      k = firstStepSquared.size(0);
      for (i = 0; i < k; i++) {
        r4[i].re = ((firstStepSquared[i] + secondStepSquared[i]) - (r1[i] + r2[i]))
          / 2.0 / r3[i];
        r4[i].im = 0.0;
      }
    } else {
      binary_expand_op(r4, firstStepSquared, secondStepSquared, r1, r2, r3);
    }

    i = r4.size(0);
    for (k = 0; k < i; k++) {
      coder::internal::scalar::b_acos(&r4[k]);
    }

    cornerAngle.set_size(r4.size(0));
    k = r4.size(0);
    for (i = 0; i < k; i++) {
      cornerAngle[i] = r4[i].re;
    }
  }

  //
  // Return the sides (deltaX, deltaY) of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  //
  // Arguments    : const ::coder::array<real_T, 2U> &XYdata
  //                ::coder::array<real_T, 2U> &firstStep
  //                ::coder::array<real_T, 2U> &secondStep
  //                ::coder::array<real_T, 2U> &longStep
  // Return Type  : void
  //
  static void calculateTrianglesSides(const ::coder::array<real_T, 2U> &XYdata, ::
    coder::array<real_T, 2U> &firstStep, ::coder::array<real_T, 2U> &secondStep,
    ::coder::array<real_T, 2U> &longStep)
  {
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T loop_ub;
    if (XYdata.size(0) - 1 < 2) {
      i = 0;
      i1 = 0;
    } else {
      i = 1;
      i1 = XYdata.size(0) - 1;
    }

    if (XYdata.size(0) - 2 < 1) {
      i2 = 0;
    } else {
      i2 = XYdata.size(0) - 2;
    }

    loop_ub = i1 - i;
    if (loop_ub == i2) {
      firstStep.set_size(loop_ub, 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          firstStep[i2 + firstStep.size(0) * i1] = XYdata[(i + i2) + XYdata.size
            (0) * i1] - XYdata[i2 + XYdata.size(0) * i1];
        }
      }
    } else {
      binary_expand_op(firstStep, XYdata, i, i1 - 1, i2 - 1);
    }

    if (XYdata.size(0) < 3) {
      i = 0;
      i1 = 0;
      i2 = 0;
      i3 = 0;
    } else {
      i = 2;
      i1 = XYdata.size(0);
      i2 = 1;
      i3 = XYdata.size(0) - 1;
    }

    loop_ub = i1 - i;
    if (loop_ub == i3 - i2) {
      secondStep.set_size(loop_ub, 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          secondStep[i3 + secondStep.size(0) * i1] = XYdata[(i + i3) +
            XYdata.size(0) * i1] - XYdata[(i2 + i3) + XYdata.size(0) * i1];
        }
      }
    } else {
      binary_expand_op(secondStep, XYdata, i, i1 - 1, i2, i3 - 1);
    }

    if (XYdata.size(0) < 3) {
      i = 0;
      i1 = 0;
    } else {
      i = 2;
      i1 = XYdata.size(0);
    }

    if (XYdata.size(0) - 2 < 1) {
      i2 = 0;
    } else {
      i2 = XYdata.size(0) - 2;
    }

    loop_ub = i1 - i;
    if (loop_ub == i2) {
      longStep.set_size(loop_ub, 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          longStep[i2 + longStep.size(0) * i1] = XYdata[(i + i2) + XYdata.size(0)
            * i1] - XYdata[i2 + XYdata.size(0) * i1];
        }
      }
    } else {
      binary_expand_op(longStep, XYdata, i, i1 - 1, i2 - 1);
    }
  }

  //
  // increaseSampling increase the sampling of an input function
  //
  // Arguments    : ::coder::array<real_T, 2U> &dataPoints
  //                const ::coder::array<boolean_T, 1U> &segmentsToSplit
  //                const ::coder::array<real_T, 2U> &sldProfile
  // Return Type  : void
  //
  static void increaseSampling(::coder::array<real_T, 2U> &dataPoints, const ::
    coder::array<boolean_T, 1U> &segmentsToSplit, const ::coder::array<real_T,
    2U> &sldProfile)
  {
    ::coder::array<real_T, 2U> b_dataPoints;
    ::coder::array<real_T, 2U> newDataPoints;
    ::coder::array<real_T, 1U> b_newDataPoints;
    ::coder::array<real_T, 1U> r4;
    ::coder::array<int32_T, 1U> r2;
    ::coder::array<int32_T, 1U> r3;
    ::coder::array<boolean_T, 1U> r;
    ::coder::array<boolean_T, 1U> r1;
    int32_T end;
    int32_T input_sizes_idx_0;
    end = segmentsToSplit.size(0);
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i < end; i++) {
      if (segmentsToSplit[i]) {
        input_sizes_idx_0++;
      }
    }

    newDataPoints.set_size(input_sizes_idx_0, 2);
    for (int32_T i{0}; i < 2; i++) {
      for (int32_T b_i{0}; b_i < input_sizes_idx_0; b_i++) {
        newDataPoints[b_i + newDataPoints.size(0) * i] = 0.0;
      }
    }

    r.set_size(segmentsToSplit.size(0) + 1);
    input_sizes_idx_0 = segmentsToSplit.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      r[i] = segmentsToSplit[i];
    }

    r[segmentsToSplit.size(0)] = false;
    r1.set_size(segmentsToSplit.size(0) + 1);
    r1[0] = false;
    input_sizes_idx_0 = segmentsToSplit.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      r1[i + 1] = segmentsToSplit[i];
    }

    end = r.size(0) - 1;
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r[i]) {
        input_sizes_idx_0++;
      }
    }

    r2.set_size(input_sizes_idx_0);
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r[i]) {
        r2[input_sizes_idx_0] = i + 1;
        input_sizes_idx_0++;
      }
    }

    end = r1.size(0) - 1;
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r1[i]) {
        input_sizes_idx_0++;
      }
    }

    r3.set_size(input_sizes_idx_0);
    input_sizes_idx_0 = 0;
    for (int32_T i{0}; i <= end; i++) {
      if (r1[i]) {
        r3[input_sizes_idx_0] = i + 1;
        input_sizes_idx_0++;
      }
    }

    if (r2.size(0) == r3.size(0)) {
      input_sizes_idx_0 = r2.size(0);
      for (int32_T i{0}; i < input_sizes_idx_0; i++) {
        newDataPoints[i] = 0.5 * (dataPoints[r2[i] - 1] + dataPoints[r3[i] - 1]);
      }
    } else {
      binary_expand_op(newDataPoints, dataPoints, r2, r3);
    }

    b_newDataPoints.set_size(newDataPoints.size(0));
    input_sizes_idx_0 = newDataPoints.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      b_newDataPoints[i] = newDataPoints[i];
    }

    normalizeFunction(b_newDataPoints, sldProfile, r4);
    input_sizes_idx_0 = r4.size(0);
    for (int32_T i{0}; i < input_sizes_idx_0; i++) {
      newDataPoints[i + newDataPoints.size(0)] = r4[i];
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
    for (int32_T i{0}; i < 2; i++) {
      for (int32_T b_i{0}; b_i < end; b_i++) {
        b_dataPoints[b_i + b_dataPoints.size(0) * i] = dataPoints[b_i +
          dataPoints.size(0) * i];
      }

      for (int32_T b_i{0}; b_i < input_sizes_idx_0; b_i++) {
        b_dataPoints[(b_i + end) + b_dataPoints.size(0) * i] = newDataPoints[b_i
          + newDataPoints.size(0) * i];
      }
    }

    dataPoints.set_size(b_dataPoints.size(0), 2);
    input_sizes_idx_0 = b_dataPoints.size(0);
    for (int32_T i{0}; i < 2; i++) {
      for (int32_T b_i{0}; b_i < input_sizes_idx_0; b_i++) {
        dataPoints[b_i + dataPoints.size(0) * i] = b_dataPoints[b_i +
          b_dataPoints.size(0) * i];
      }
    }

    coder::sortrows(dataPoints);
  }

  //
  // NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //
  // Arguments    : const ::coder::array<real_T, 1U> &x
  //                const ::coder::array<real_T, 2U> &sldProfile
  //                ::coder::array<real_T, 1U> &y
  // Return Type  : void
  //
  static void normalizeFunction(const ::coder::array<real_T, 1U> &x, const ::
    coder::array<real_T, 2U> &sldProfile, ::coder::array<real_T, 1U> &y)
  {
    ::coder::array<real_T, 1U> r;
    int32_T i;

    //  Subfunctions
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
    for (int32_T b_i{0}; b_i < i; b_i++) {
      //  Remove cell array so no need for cell2mat
      //  which won't compile - AVH
      // [newValues{:}] = func(x(i));
      // y(i,:) = cell2mat(newValues);
      sldFunc(x[b_i], sldProfile, r);
      y[b_i] = r[0];
    }

    // end
  }

  //
  // NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //
  // Arguments    : const ::coder::array<real_T, 1U> &x
  //                const real_T sldProfile_data[]
  //                const int32_T sldProfile_size[2]
  //                ::coder::array<real_T, 1U> &y
  // Return Type  : void
  //
  static void normalizeFunction(const ::coder::array<real_T, 1U> &x, const
    real_T sldProfile_data[], const int32_T sldProfile_size[2], ::coder::array<
    real_T, 1U> &y)
  {
    real_T tmp_data[2];
    int32_T i;
    int32_T tmp_size;

    //  Subfunctions
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
    for (int32_T b_i{0}; b_i < i; b_i++) {
      //  Remove cell array so no need for cell2mat
      //  which won't compile - AVH
      // [newValues{:}] = func(x(i));
      // y(i,:) = cell2mat(newValues);
      sldFunc(x[b_i], sldProfile_data, sldProfile_size, tmp_data, &tmp_size);
      y[b_i] = tmp_data[0];
    }

    // end
  }

  //
  // Arguments    : ::coder::array<real_T, 1U> &in1
  //                const ::coder::array<real_T, 1U> &in2
  //                const ::coder::array<real_T, 1U> &in3
  // Return Type  : void
  //
  static void times(::coder::array<real_T, 1U> &in1, const ::coder::array<real_T,
                    1U> &in2, const ::coder::array<real_T, 1U> &in3)
  {
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    if (in3.size(0) == 1) {
      i = in2.size(0);
    } else {
      i = in3.size(0);
    }

    in1.set_size(i);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    for (i = 0; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
    }
  }

  //
  // adaptive: evaluates a matlab function on a given range
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
  //        Refine near the  points which forms, together with their left and right
  //        neighbours, a triangle with central angle smaller than a given value.
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and right
  //        neighbours, a triangle with area larger than a threshold. The threshold
  //        in normalized to the area enclosing th graph:
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
  //        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
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
  //
  // Arguments    : const ::coder::array<real_T, 2U> &sldProfile
  //                const real_T startDomain[2]
  //                real_T minAngle
  //                real_T nPoints
  //                cell_23 *out
  // Return Type  : void
  //
  void adaptive_new(const ::coder::array<real_T, 2U> &sldProfile, const real_T
                    startDomain[2], real_T minAngle, real_T nPoints, cell_23
                    *out)
  {
    ::coder::array<real_T, 2U> b_out;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 1U> cornerAngle;
    ::coder::array<real_T, 1U> hiVal;
    ::coder::array<real_T, 1U> newDomain;
    ::coder::array<boolean_T, 1U> b_trianglesToRefine;
    ::coder::array<boolean_T, 1U> r1;
    ::coder::array<boolean_T, 1U> segmentsToSplit;
    ::coder::array<boolean_T, 1U> trianglesToRefine;
    int32_T loop_ub;
    int32_T nRefinements;
    boolean_T exitg1;

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
    // nPoints = 20;
    // minAngle = 0.8*pi;
    //  units normalized to data range
    //  Test-mode
    //  The test mode is activated by calling 'adaptive.m' with no input.
    //  if nargin==0
    //    initialDomain =  -10:10;
    //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2);
    //    thresholdingAngles = true;
    //    minAngle = 0.8*pi;
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
    //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector');
    //
    // nExtraArgIn = numel(varargin);
    //  if mod(nExtraArgIn,2)==1
    //    error('adaptiveFunctionEvaluation:ArgChk', ...
    //      'At least a key or a value is missing in the key-value arguments list.');
    //  end
    // usingDefaultMethod = true;
    // n = 1;
    // minAngle = 0.7 * pi;
    // thresholdingAngles = true;
    // nPoints = 50;
    //  while n < nExtraArgIn
    //    switch lower(varargin{n})
    //      case 'minangle'
    // minAngle = varargin{n+1};
    // n = n+2;
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
    //  if usingDefaultMethod
    //    thresholdingAngles = true;
    //  end
    //  Initial function evaluation
    //  if initialDomain only contains the start and the end points, create a new
    //  array with 'nPoints' points.
    coder::linspace(startDomain[0], startDomain[1], nPoints, r);
    newDomain.set_size(r.size(1));
    loop_ub = r.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      newDomain[i] = r[i];
    }

    //  Normalize the input function: This step allows to use the same syntax for
    //  functions with single or multiple output parameters.
    //  Remove this syntax for compile - AVH
    // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
    //  Evaluate the input function on the initial set of points.
    normalizeFunction(newDomain, sldProfile, hiVal);

    // dataPoints = [initialDomain(:), func(initialDomain(:))];
    out->f1.set_size(newDomain.size(0), 2);
    loop_ub = newDomain.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      out->f1[i] = newDomain[i];
    }

    loop_ub = hiVal.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      out->f1[i + out->f1.size(0)] = hiVal[i];
    }

    //  Iterative function refinement
    //  if displayWaitbar
    //    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],...
    //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
    //    setappdata(refinementWaitbar,'canceling',false)
    //  end
    nRefinements = 0;
    exitg1 = false;
    while ((!exitg1) && (nRefinements < 10)) {
      real_T dv[2];
      real_T dv1[2];
      boolean_T y;

      //  calculate the box which encloses the current data points:
      //  Each point is considered as the central corner of the triangle formed
      //  with its left and right hand side neighbours. The first and the last
      //  points are not the central corner of any triangle, so for N points
      //  there are only N-2 triangles.
      //    if thresholdingArea
      //      triangleArea = calculateTrianglesArea(dataPoints(:,1:2));
      //      bigTriangles = triangleArea > (maxArea * dataBoxArea);
      //      trianglesToRefine = trianglesToRefine | bigTriangles;
      //    end
      b_out.set_size(out->f1.size(0), 2);
      loop_ub = out->f1.size(0);
      for (int32_T i{0}; i < 2; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          b_out[i1 + b_out.size(0) * i] = out->f1[i1 + out->f1.size(0) * i];
        }
      }

      coder::internal::maximum(b_out, dv);
      b_out.set_size(out->f1.size(0), 2);
      loop_ub = out->f1.size(0);
      for (int32_T i{0}; i < 2; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          b_out[i1 + b_out.size(0) * i] = out->f1[i1 + out->f1.size(0) * i];
        }
      }

      coder::internal::minimum(b_out, dv1);
      b_out.set_size(out->f1.size(0), 2);
      loop_ub = out->f1.size(0);
      for (int32_T i{0}; i < 2; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          b_out[i1 + b_out.size(0) * i] = out->f1[i1 + out->f1.size(0) * i];
        }

        dv[i] -= dv1[i];
      }

      calculateCentralAngles(b_out, dv, cornerAngle);
      if (out->f1.size(0) - 2 == cornerAngle.size(0)) {
        trianglesToRefine.set_size(out->f1.size(0) - 2);
        loop_ub = out->f1.size(0) - 2;
        for (int32_T i{0}; i < loop_ub; i++) {
          trianglesToRefine[i] = (cornerAngle[i] < minAngle);
        }
      } else {
        b_binary_expand_op(trianglesToRefine, out, cornerAngle, minAngle);
      }

      //  For N points there are N-2 triangles and N-1 triangle sides. Each
      //  triangle side is a segment, which can be split or not depending on the
      //  refinement parameters.
      b_trianglesToRefine.set_size(trianglesToRefine.size(0) + 1);
      loop_ub = trianglesToRefine.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        b_trianglesToRefine[i] = trianglesToRefine[i];
      }

      b_trianglesToRefine[trianglesToRefine.size(0)] = false;
      r1.set_size(trianglesToRefine.size(0) + 1);
      r1[0] = false;
      loop_ub = trianglesToRefine.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        r1[i + 1] = trianglesToRefine[i];
      }

      segmentsToSplit.set_size(b_trianglesToRefine.size(0));
      loop_ub = b_trianglesToRefine.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        segmentsToSplit[i] = (b_trianglesToRefine[i] || r1[i]);
      }

      //    if thresholdingLength
      //      dataSegments = diff(dataPoints(:,1:2));
      //      normalizedSegments = bsxfun(@rdivide, dataSegments, dataBoxSize);
      //      segmentsLengthNormalized = hypot(normalizedSegments(:,1), normalizedSegments(:,2));
      //      tooLongSegments = segmentsLengthNormalized > maxLength;
      //      longEnoughSegments = segmentsLengthNormalized > minLength;
      //      segmentsToSplit = (segmentsToSplit | tooLongSegments) & longEnoughSegments;
      //    end
      //    if thresholdingSignal
      //      segmentsCenters = (dataPoints(1:end-1,2)+dataPoints(2:end,2))/2;
      //      centerAboveThreshold = segmentsCenters > minSignal * max(abs(dataPoints(:,2)));
      //      segmentsToSplit = segmentsToSplit & centerAboveThreshold;
      //    end
      y = coder::internal::allOrAny_anonFcn3(segmentsToSplit.size(0),
        segmentsToSplit);
      if (y) {
        increaseSampling(out->f1, segmentsToSplit, sldProfile);

        //  Removed waitbar for compile - AVH
        //    if displayWaitbar
        //      if getappdata(refinementWaitbar,'canceling'), break; end
        //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
        //    end
        nRefinements++;
      } else {
        exitg1 = true;
      }
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
    // if nargout==1
    //  elseif nargout>1
    //    out{1} = dataPoints(:,1);
    //    out{2} = dataPoints(:,2:end);
    //  end
  }

  //
  // adaptive: evaluates a matlab function on a given range
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
  //        Refine near the  points which forms, together with their left and right
  //        neighbours, a triangle with central angle smaller than a given value.
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and right
  //        neighbours, a triangle with area larger than a threshold. The threshold
  //        in normalized to the area enclosing th graph:
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
  //        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
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
  //
  // Arguments    : const real_T sldProfile_data[]
  //                const int32_T sldProfile_size[2]
  //                const real_T startDomain[2]
  //                real_T minAngle
  //                real_T nPoints
  //                cell_23 *out
  // Return Type  : void
  //
  void adaptive_new(const real_T sldProfile_data[], const int32_T
                    sldProfile_size[2], const real_T startDomain[2], real_T
                    minAngle, real_T nPoints, cell_23 *out)
  {
    ::coder::array<real_T, 2U> b_out;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 1U> cornerAngle;
    ::coder::array<real_T, 1U> hiVal;
    ::coder::array<real_T, 1U> newDomain;
    ::coder::array<boolean_T, 1U> b_trianglesToRefine;
    ::coder::array<boolean_T, 1U> r1;
    ::coder::array<boolean_T, 1U> segmentsToSplit;
    ::coder::array<boolean_T, 1U> trianglesToRefine;
    int32_T loop_ub;
    int32_T nRefinements;
    boolean_T exitg1;

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
    // nPoints = 20;
    // minAngle = 0.8*pi;
    //  units normalized to data range
    //  Test-mode
    //  The test mode is activated by calling 'adaptive.m' with no input.
    //  if nargin==0
    //    initialDomain =  -10:10;
    //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2);
    //    thresholdingAngles = true;
    //    minAngle = 0.8*pi;
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
    //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector');
    //
    // nExtraArgIn = numel(varargin);
    //  if mod(nExtraArgIn,2)==1
    //    error('adaptiveFunctionEvaluation:ArgChk', ...
    //      'At least a key or a value is missing in the key-value arguments list.');
    //  end
    // usingDefaultMethod = true;
    // n = 1;
    // minAngle = 0.7 * pi;
    // thresholdingAngles = true;
    // nPoints = 50;
    //  while n < nExtraArgIn
    //    switch lower(varargin{n})
    //      case 'minangle'
    // minAngle = varargin{n+1};
    // n = n+2;
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
    //  if usingDefaultMethod
    //    thresholdingAngles = true;
    //  end
    //  Initial function evaluation
    //  if initialDomain only contains the start and the end points, create a new
    //  array with 'nPoints' points.
    coder::linspace(startDomain[0], startDomain[1], nPoints, r);
    newDomain.set_size(r.size(1));
    loop_ub = r.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      newDomain[i] = r[i];
    }

    //  Normalize the input function: This step allows to use the same syntax for
    //  functions with single or multiple output parameters.
    //  Remove this syntax for compile - AVH
    // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
    //  Evaluate the input function on the initial set of points.
    normalizeFunction(newDomain, sldProfile_data, sldProfile_size, hiVal);

    // dataPoints = [initialDomain(:), func(initialDomain(:))];
    out->f1.set_size(newDomain.size(0), 2);
    loop_ub = newDomain.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      out->f1[i] = newDomain[i];
    }

    loop_ub = hiVal.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      out->f1[i + out->f1.size(0)] = hiVal[i];
    }

    //  Iterative function refinement
    //  if displayWaitbar
    //    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],...
    //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
    //    setappdata(refinementWaitbar,'canceling',false)
    //  end
    nRefinements = 0;
    exitg1 = false;
    while ((!exitg1) && (nRefinements < 10)) {
      real_T dv[2];
      real_T dv1[2];
      boolean_T y;

      //  calculate the box which encloses the current data points:
      //  Each point is considered as the central corner of the triangle formed
      //  with its left and right hand side neighbours. The first and the last
      //  points are not the central corner of any triangle, so for N points
      //  there are only N-2 triangles.
      //    if thresholdingArea
      //      triangleArea = calculateTrianglesArea(dataPoints(:,1:2));
      //      bigTriangles = triangleArea > (maxArea * dataBoxArea);
      //      trianglesToRefine = trianglesToRefine | bigTriangles;
      //    end
      b_out.set_size(out->f1.size(0), 2);
      loop_ub = out->f1.size(0);
      for (int32_T i{0}; i < 2; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          b_out[i1 + b_out.size(0) * i] = out->f1[i1 + out->f1.size(0) * i];
        }
      }

      coder::internal::maximum(b_out, dv);
      b_out.set_size(out->f1.size(0), 2);
      loop_ub = out->f1.size(0);
      for (int32_T i{0}; i < 2; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          b_out[i1 + b_out.size(0) * i] = out->f1[i1 + out->f1.size(0) * i];
        }
      }

      coder::internal::minimum(b_out, dv1);
      b_out.set_size(out->f1.size(0), 2);
      loop_ub = out->f1.size(0);
      for (int32_T i{0}; i < 2; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          b_out[i1 + b_out.size(0) * i] = out->f1[i1 + out->f1.size(0) * i];
        }

        dv[i] -= dv1[i];
      }

      calculateCentralAngles(b_out, dv, cornerAngle);
      if (out->f1.size(0) - 2 == cornerAngle.size(0)) {
        trianglesToRefine.set_size(out->f1.size(0) - 2);
        loop_ub = out->f1.size(0) - 2;
        for (int32_T i{0}; i < loop_ub; i++) {
          trianglesToRefine[i] = (cornerAngle[i] < minAngle);
        }
      } else {
        b_binary_expand_op(trianglesToRefine, out, cornerAngle, minAngle);
      }

      //  For N points there are N-2 triangles and N-1 triangle sides. Each
      //  triangle side is a segment, which can be split or not depending on the
      //  refinement parameters.
      b_trianglesToRefine.set_size(trianglesToRefine.size(0) + 1);
      loop_ub = trianglesToRefine.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        b_trianglesToRefine[i] = trianglesToRefine[i];
      }

      b_trianglesToRefine[trianglesToRefine.size(0)] = false;
      r1.set_size(trianglesToRefine.size(0) + 1);
      r1[0] = false;
      loop_ub = trianglesToRefine.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        r1[i + 1] = trianglesToRefine[i];
      }

      segmentsToSplit.set_size(b_trianglesToRefine.size(0));
      loop_ub = b_trianglesToRefine.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        segmentsToSplit[i] = (b_trianglesToRefine[i] || r1[i]);
      }

      //    if thresholdingLength
      //      dataSegments = diff(dataPoints(:,1:2));
      //      normalizedSegments = bsxfun(@rdivide, dataSegments, dataBoxSize);
      //      segmentsLengthNormalized = hypot(normalizedSegments(:,1), normalizedSegments(:,2));
      //      tooLongSegments = segmentsLengthNormalized > maxLength;
      //      longEnoughSegments = segmentsLengthNormalized > minLength;
      //      segmentsToSplit = (segmentsToSplit | tooLongSegments) & longEnoughSegments;
      //    end
      //    if thresholdingSignal
      //      segmentsCenters = (dataPoints(1:end-1,2)+dataPoints(2:end,2))/2;
      //      centerAboveThreshold = segmentsCenters > minSignal * max(abs(dataPoints(:,2)));
      //      segmentsToSplit = segmentsToSplit & centerAboveThreshold;
      //    end
      y = coder::internal::allOrAny_anonFcn3(segmentsToSplit.size(0),
        segmentsToSplit);
      if (y) {
        b_increaseSampling(out->f1, segmentsToSplit, sldProfile_data,
                           sldProfile_size);

        //  Removed waitbar for compile - AVH
        //    if displayWaitbar
        //      if getappdata(refinementWaitbar,'canceling'), break; end
        //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
        //    end
        nRefinements++;
      } else {
        exitg1 = true;
      }
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
    // if nargout==1
    //  elseif nargout>1
    //    out{1} = dataPoints(:,1);
    //    out{2} = dataPoints(:,2:end);
    //  end
  }
}

//
// File trailer for adaptive_new.cpp
//
// [EOF]
//
