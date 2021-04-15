//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: adaptive.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "adaptive.h"
#include "chiSquared.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortLE.h"
#include "sqrt.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include <cmath>
#include <math.h>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int b_u0;
    int b_u1;
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

    y = atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
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

//
// Calculate the central angle of the triangles formed by data points.
//  For input size NxM, the output size is (N-2)xN, because the first and the
//  last point are not the central corner of any triangle.
// Arguments    : const coder::array<double, 2U> *XYdata
//                const double dataBoxSize[2]
//                coder::array<double, 1U> *cornerAngle
// Return Type  : void
//
void calculateCentralAngles(const coder::array<double, 2U> &XYdata, const double
  dataBoxSize[2], coder::array<double, 1U> &cornerAngle)
{
  int m;
  coder::array<double, 2U> normalizedData;
  int ntilerows;
  coder::array<double, 2U> b;
  int b_ntilerows;
  double absre;
  int i;
  double absim;
  coder::array<double, 2U> firstStep;
  coder::array<double, 2U> secondStep;
  coder::array<double, 1U> firstStepSquared;
  coder::array<double, 1U> y;
  coder::array<double, 1U> secondStepSquared;
  coder::array<double, 1U> x;
  coder::array<double, 1U> b_y;
  coder::array<creal_T, 1U> b_x;
  creal_T v;
  creal_T u;
  double ci;

  //  Normalize data, because angles depend on scaling.
  m = XYdata.size(0);
  normalizedData.set_size(XYdata.size(0), 2);
  ntilerows = XYdata.size(0);
  b.set_size(XYdata.size(0), 2);
  b_ntilerows = XYdata.size(0);
  absre = XYdata[0];
  for (i = 2; i <= m; i++) {
    absim = XYdata[i - 1];
    if ((!rtIsNaN(absim)) && (rtIsNaN(absre) || (absre > absim))) {
      absre = absim;
    }
  }

  for (i = 0; i < ntilerows; i++) {
    normalizedData[i] = dataBoxSize[0];
  }

  for (i = 0; i < b_ntilerows; i++) {
    b[i] = absre;
  }

  absre = XYdata[XYdata.size(0)];
  for (i = 2; i <= m; i++) {
    absim = XYdata[(i + XYdata.size(0)) - 1];
    if ((!rtIsNaN(absim)) && (rtIsNaN(absre) || (absre > absim))) {
      absre = absim;
    }
  }

  for (i = 0; i < ntilerows; i++) {
    normalizedData[ntilerows + i] = dataBoxSize[1];
  }

  for (i = 0; i < b_ntilerows; i++) {
    b[b_ntilerows + i] = absre;
  }

  m = XYdata.size(0) * XYdata.size(1);
  normalizedData.set_size(XYdata.size(0), 2);
  for (b_ntilerows = 0; b_ntilerows < m; b_ntilerows++) {
    normalizedData[b_ntilerows] = XYdata[b_ntilerows] /
      normalizedData[b_ntilerows] - b[b_ntilerows];
  }

  //  calculate cosine of central angles
  //  Return the sides (deltaX, deltaY) of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  if (2 > normalizedData.size(0) - 1) {
    b_ntilerows = 0;
    i = 0;
  } else {
    b_ntilerows = 1;
    i = normalizedData.size(0) - 1;
  }

  m = i - b_ntilerows;
  firstStep.set_size(m, 2);
  for (i = 0; i < m; i++) {
    firstStep[i] = normalizedData[b_ntilerows + i] - normalizedData[i];
  }

  for (i = 0; i < m; i++) {
    firstStep[i + firstStep.size(0)] = normalizedData[(b_ntilerows + i) +
      normalizedData.size(0)] - normalizedData[i + normalizedData.size(0)];
  }

  if (3 > normalizedData.size(0)) {
    b_ntilerows = 0;
    i = 0;
  } else {
    b_ntilerows = 2;
    i = normalizedData.size(0);
  }

  ntilerows = (2 <= normalizedData.size(0) - 1);
  m = i - b_ntilerows;
  secondStep.set_size(m, 2);
  for (i = 0; i < m; i++) {
    secondStep[i] = normalizedData[b_ntilerows + i] - normalizedData[ntilerows +
      i];
  }

  for (i = 0; i < m; i++) {
    secondStep[i + secondStep.size(0)] = normalizedData[(b_ntilerows + i) +
      normalizedData.size(0)] - normalizedData[(ntilerows + i) +
      normalizedData.size(0)];
  }

  if (3 > normalizedData.size(0)) {
    b_ntilerows = 0;
    i = 0;
  } else {
    b_ntilerows = 2;
    i = normalizedData.size(0);
  }

  m = i - b_ntilerows;
  b.set_size(m, 2);
  for (i = 0; i < m; i++) {
    b[i] = normalizedData[b_ntilerows + i] - normalizedData[i];
  }

  for (i = 0; i < m; i++) {
    b[i + b.size(0)] = normalizedData[(b_ntilerows + i) + normalizedData.size(0)]
      - normalizedData[i + normalizedData.size(0)];
  }

  //  calculate area of squares of length of triangle sides
  firstStepSquared.set_size(firstStep.size(0));
  m = firstStep.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    firstStepSquared[ntilerows] = rt_powd_snf(firstStep[ntilerows], 2.0);
  }

  y.set_size(firstStep.size(0));
  m = firstStep.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    y[ntilerows] = rt_powd_snf(firstStep[ntilerows + firstStep.size(0)], 2.0);
  }

  m = firstStepSquared.size(0);
  for (b_ntilerows = 0; b_ntilerows < m; b_ntilerows++) {
    firstStepSquared[b_ntilerows] = firstStepSquared[b_ntilerows] +
      y[b_ntilerows];
  }

  secondStepSquared.set_size(secondStep.size(0));
  m = secondStep.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    secondStepSquared[ntilerows] = rt_powd_snf(secondStep[ntilerows], 2.0);
  }

  y.set_size(secondStep.size(0));
  m = secondStep.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    y[ntilerows] = rt_powd_snf(secondStep[ntilerows + secondStep.size(0)], 2.0);
  }

  m = secondStepSquared.size(0);
  for (b_ntilerows = 0; b_ntilerows < m; b_ntilerows++) {
    secondStepSquared[b_ntilerows] = secondStepSquared[b_ntilerows] +
      y[b_ntilerows];
  }

  x.set_size(firstStepSquared.size(0));
  m = firstStepSquared.size(0);
  for (b_ntilerows = 0; b_ntilerows < m; b_ntilerows++) {
    x[b_ntilerows] = firstStepSquared[b_ntilerows] *
      secondStepSquared[b_ntilerows];
  }

  m = x.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    x[ntilerows] = std::sqrt(x[ntilerows]);
  }

  y.set_size(b.size(0));
  m = b.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    y[ntilerows] = rt_powd_snf(b[ntilerows], 2.0);
  }

  b_y.set_size(b.size(0));
  m = b.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    b_y[ntilerows] = rt_powd_snf(b[ntilerows + b.size(0)], 2.0);
  }

  b_x.set_size(firstStepSquared.size(0));
  m = firstStepSquared.size(0);
  for (b_ntilerows = 0; b_ntilerows < m; b_ntilerows++) {
    b_x[b_ntilerows].re = ((firstStepSquared[b_ntilerows] +
      secondStepSquared[b_ntilerows]) - (y[b_ntilerows] + b_y[b_ntilerows])) /
      2.0 / x[b_ntilerows];
    b_x[b_ntilerows].im = 0.0;
  }

  m = b_x.size(0);
  for (ntilerows = 0; ntilerows < m; ntilerows++) {
    if ((b_x[ntilerows].im == 0.0) && (!(std::abs(b_x[ntilerows].re) > 1.0))) {
      b_x[ntilerows].re = std::acos(b_x[ntilerows].re);
      b_x[ntilerows].im = 0.0;
    } else {
      boolean_T xneg;
      v.re = b_x[ntilerows].re + 1.0;
      v.im = b_x[ntilerows].im;
      b_sqrt(&v);
      u.re = 1.0 - b_x[ntilerows].re;
      u.im = 0.0 - b_x[ntilerows].im;
      b_sqrt(&u);
      if ((-v.im == 0.0) && (u.im == 0.0)) {
        ci = 0.0;
      } else {
        double t3;
        double t4;
        t3 = v.re * u.im;
        t4 = -v.im * u.re;
        ci = t3 + t4;
        if ((rtIsInf(ci) || rtIsNaN(ci)) && (!rtIsNaN(v.re)) && (!rtIsNaN(-v.im))
            && (!rtIsNaN(u.re)) && (!rtIsNaN(u.im))) {
          double sar;
          double sai;
          double b_absre;
          double sbr;
          double sbi;
          absre = std::abs(v.re);
          absim = std::abs(-v.im);
          if (absre > absim) {
            if (v.re < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            sai = -v.im / absre;
          } else if (absim > absre) {
            sar = v.re / absim;
            if (-v.im < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }

            absre = absim;
          } else {
            if (v.re < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            if (-v.im < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }
          }

          b_absre = std::abs(u.re);
          absim = std::abs(u.im);
          if (b_absre > absim) {
            if (u.re < 0.0) {
              sbr = -1.0;
            } else {
              sbr = 1.0;
            }

            sbi = u.im / b_absre;
          } else if (absim > b_absre) {
            sbr = u.re / absim;
            if (u.im < 0.0) {
              sbi = -1.0;
            } else {
              sbi = 1.0;
            }

            b_absre = absim;
          } else {
            if (u.re < 0.0) {
              sbr = -1.0;
            } else {
              sbr = 1.0;
            }

            if (u.im < 0.0) {
              sbi = -1.0;
            } else {
              sbi = 1.0;
            }
          }

          if ((!rtIsInf(absre)) && (!rtIsNaN(absre)) && ((!rtIsInf(b_absre)) &&
               (!rtIsNaN(b_absre)))) {
            xneg = true;
          } else {
            xneg = false;
          }

          if (rtIsNaN(ci) || (rtIsInf(ci) && xneg)) {
            ci = sar * sbi + sai * sbr;
            if (ci != 0.0) {
              ci = ci * absre * b_absre;
            } else {
              if ((rtIsInf(absre) && ((u.re == 0.0) || (u.im == 0.0))) ||
                  (rtIsInf(b_absre) && ((v.re == 0.0) || (-v.im == 0.0)))) {
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
        ci = std::log(ci) + 0.69314718055994529;
      } else if (ci > 2.0) {
        ci = std::log(2.0 * ci + 1.0 / (std::sqrt(ci * ci + 1.0) + ci));
      } else {
        absre = ci * ci;
        ci += absre / (std::sqrt(absre + 1.0) + 1.0);
        absre = std::abs(ci);
        if ((absre > 4.503599627370496E+15) || (rtIsInf(ci) || rtIsNaN(ci))) {
          ci++;
          ci = std::log(ci);
        } else {
          if (!(absre < 2.2204460492503131E-16)) {
            ci = std::log(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
          }
        }
      }

      if (xneg) {
        ci = -ci;
      }

      b_x[ntilerows].re = 2.0 * rt_atan2d_snf(u.re, v.re);
      b_x[ntilerows].im = ci;
    }
  }

  cornerAngle.set_size(b_x.size(0));
  m = b_x.size(0);
  for (b_ntilerows = 0; b_ntilerows < m; b_ntilerows++) {
    cornerAngle[b_ntilerows] = b_x[b_ntilerows].re;
  }
}

//
// increaseSampling increase the sampling of an input function
// Arguments    : coder::array<double, 2U> *dataPoints
//                const coder::array<boolean_T, 1U> *segmentsToSplit
//                const coder::array<double, 2U> *sldProfile
// Return Type  : void
//
void increaseSampling(coder::array<double, 2U> &dataPoints, const coder::array<
                      boolean_T, 1U> &segmentsToSplit, const coder::array<double,
                      2U> &sldProfile)
{
  int j;
  int input_sizes_idx_0;
  int i;
  coder::array<double, 2U> newDataPoints;
  int b_i;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> r1;
  coder::array<int, 1U> idx;
  coder::array<int, 1U> r2;
  coder::array<double, 1U> ycol;
  coder::array<double, 1U> r3;
  coder::array<double, 2U> b_dataPoints;
  int col_data[2];
  int n;
  coder::array<int, 1U> iwork;
  int k;
  int qEnd;
  j = segmentsToSplit.size(0);
  input_sizes_idx_0 = 0;
  for (i = 0; i < j; i++) {
    if (segmentsToSplit[i]) {
      input_sizes_idx_0++;
    }
  }

  newDataPoints.set_size(input_sizes_idx_0, 2);
  input_sizes_idx_0 <<= 1;
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] = 0.0;
  }

  r.set_size((segmentsToSplit.size(0) + 1));
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r[b_i] = segmentsToSplit[b_i];
  }

  r[segmentsToSplit.size(0)] = false;
  r1.set_size((segmentsToSplit.size(0) + 1));
  r1[0] = false;
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r1[b_i + 1] = segmentsToSplit[b_i];
  }

  j = r.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= j; i++) {
    if (r[i]) {
      input_sizes_idx_0++;
    }
  }

  idx.set_size(input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= j; i++) {
    if (r[i]) {
      idx[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  j = r1.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= j; i++) {
    if (r1[i]) {
      input_sizes_idx_0++;
    }
  }

  r2.set_size(input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= j; i++) {
    if (r1[i]) {
      r2[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  input_sizes_idx_0 = idx.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] = 0.5 * (dataPoints[idx[b_i] - 1] + dataPoints[r2[b_i] -
      1]);
  }

  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Subfunctions
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  ycol.set_size(newDataPoints.size(0));

  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  b_i = newDataPoints.size(0) - 1;
  for (i = 0; i <= b_i; i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    sldFunc(newDataPoints[i], sldProfile, r3);
    ycol[i] = r3[0];
  }

  // end
  input_sizes_idx_0 = ycol.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i + newDataPoints.size(0)] = ycol[b_i];
  }

  //  For simplicity append the new points at the end and then sort.
  if (newDataPoints.size(0) != 0) {
    input_sizes_idx_0 = newDataPoints.size(0);
  } else {
    input_sizes_idx_0 = 0;
  }

  if (dataPoints.size(0) != 0) {
    j = dataPoints.size(0);
  } else {
    j = 0;
  }

  b_dataPoints.set_size((j + input_sizes_idx_0), 2);
  for (b_i = 0; b_i < j; b_i++) {
    b_dataPoints[b_i] = dataPoints[b_i];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints[b_i + j] = newDataPoints[b_i];
  }

  for (b_i = 0; b_i < j; b_i++) {
    b_dataPoints[b_i + b_dataPoints.size(0)] = dataPoints[b_i + dataPoints.size
      (0)];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints[(b_i + j) + b_dataPoints.size(0)] = newDataPoints[b_i +
      newDataPoints.size(0)];
  }

  dataPoints.set_size(b_dataPoints.size(0), 2);
  input_sizes_idx_0 = b_dataPoints.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    dataPoints[b_i] = b_dataPoints[b_i];
  }

  col_data[0] = 1;
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    dataPoints[b_i + dataPoints.size(0)] = b_dataPoints[b_i + b_dataPoints.size
      (0)];
  }

  col_data[1] = 2;
  n = dataPoints.size(0) + 1;
  idx.set_size(dataPoints.size(0));
  input_sizes_idx_0 = dataPoints.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    idx[b_i] = 0;
  }

  if (dataPoints.size(0) == 0) {
    for (k = 0; k <= n - 2; k++) {
      idx[k] = k + 1;
    }
  } else {
    iwork.set_size(dataPoints.size(0));
    b_i = dataPoints.size(0) - 1;
    for (k = 1; k <= b_i; k += 2) {
      if (sortLE(dataPoints, col_data, k, k + 1)) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }

    if ((dataPoints.size(0) & 1) != 0) {
      idx[dataPoints.size(0) - 1] = dataPoints.size(0);
    }

    i = 2;
    while (i < n - 1) {
      input_sizes_idx_0 = i << 1;
      j = 1;
      for (int pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        int p;
        int q;
        int kEnd;
        p = j;
        q = pEnd;
        qEnd = j + input_sizes_idx_0;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          int i1;
          b_i = idx[q - 1];
          i1 = idx[p - 1];
          if (sortLE(dataPoints, col_data, i1, b_i)) {
            iwork[k] = i1;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork[k] = idx[q - 1];
                q++;
              }
            }
          } else {
            iwork[k] = b_i;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }

        j = qEnd;
      }

      i = input_sizes_idx_0;
    }
  }

  input_sizes_idx_0 = dataPoints.size(0) - 1;
  ycol.set_size(dataPoints.size(0));
  for (i = 0; i <= input_sizes_idx_0; i++) {
    ycol[i] = dataPoints[idx[i] - 1];
  }

  for (i = 0; i <= input_sizes_idx_0; i++) {
    dataPoints[i] = ycol[i];
  }

  for (i = 0; i <= input_sizes_idx_0; i++) {
    ycol[i] = dataPoints[(idx[i] + dataPoints.size(0)) - 1];
  }

  for (i = 0; i <= input_sizes_idx_0; i++) {
    dataPoints[i + dataPoints.size(0)] = ycol[i];
  }
}

//
// File trailer for adaptive.cpp
//
// [EOF]
//
