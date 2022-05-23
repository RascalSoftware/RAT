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
#include "minOrMax.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else if (std::isinf(u0) && std::isinf(u1)) {
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
    y = std::atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

void calculateCentralAngles(const coder::array<double, 2U> &XYdata,
                            const double dataBoxSize[2],
                            coder::array<double, 1U> &cornerAngle)
{
  coder::array<creal_T, 1U> b_x;
  coder::array<double, 2U> b;
  coder::array<double, 2U> firstStep;
  coder::array<double, 2U> normalizedData;
  coder::array<double, 2U> secondStep;
  coder::array<double, 1U> b_y;
  coder::array<double, 1U> firstStepSquared;
  coder::array<double, 1U> secondStepSquared;
  coder::array<double, 1U> x;
  coder::array<double, 1U> y;
  creal_T u;
  creal_T v;
  double a[2];
  int N;
  int i;
  int i1;
  int k;
  //  Calculate the central angle of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  //  Normalize data, because angles depend on scaling.
  normalizedData.set_size(XYdata.size(0), 2);
  if (XYdata.size(0) != 0) {
    i = XYdata.size(0) - 1;
    for (k = 0; k < 2; k++) {
      for (N = 0; N <= i; N++) {
        normalizedData[N + normalizedData.size(0) * k] = dataBoxSize[k];
      }
    }
  }
  coder::internal::minimum(XYdata, a);
  b.set_size(XYdata.size(0), 2);
  if (XYdata.size(0) != 0) {
    i = XYdata.size(0) - 1;
    for (k = 0; k < 2; k++) {
      for (N = 0; N <= i; N++) {
        b[N + b.size(0) * k] = a[k];
      }
    }
  }
  normalizedData.set_size(XYdata.size(0), 2);
  N = XYdata.size(0);
  for (i = 0; i < 2; i++) {
    for (k = 0; k < N; k++) {
      normalizedData[k + normalizedData.size(0) * i] =
          XYdata[k + XYdata.size(0) * i] /
              normalizedData[k + normalizedData.size(0) * i] -
          b[k + b.size(0) * i];
    }
  }
  //  calculate cosine of central angles
  //  Return the sides (deltaX, deltaY) of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  if (2 > normalizedData.size(0) - 1) {
    i = 0;
    k = 0;
  } else {
    i = 1;
    k = normalizedData.size(0) - 1;
  }
  N = k - i;
  firstStep.set_size(N, 2);
  for (k = 0; k < 2; k++) {
    for (i1 = 0; i1 < N; i1++) {
      firstStep[i1 + firstStep.size(0) * k] =
          normalizedData[(i + i1) + normalizedData.size(0) * k] -
          normalizedData[i1 + normalizedData.size(0) * k];
    }
  }
  if (3 > normalizedData.size(0)) {
    i = 0;
    k = 0;
    i1 = 0;
  } else {
    i = 2;
    k = normalizedData.size(0);
    i1 = 1;
  }
  N = k - i;
  secondStep.set_size(N, 2);
  for (k = 0; k < 2; k++) {
    for (int i2{0}; i2 < N; i2++) {
      secondStep[i2 + secondStep.size(0) * k] =
          normalizedData[(i + i2) + normalizedData.size(0) * k] -
          normalizedData[(i1 + i2) + normalizedData.size(0) * k];
    }
  }
  if (3 > normalizedData.size(0)) {
    i = 0;
    k = 0;
  } else {
    i = 2;
    k = normalizedData.size(0);
  }
  N = k - i;
  b.set_size(N, 2);
  for (k = 0; k < 2; k++) {
    for (i1 = 0; i1 < N; i1++) {
      b[i1 + b.size(0) * k] =
          normalizedData[(i + i1) + normalizedData.size(0) * k] -
          normalizedData[i1 + normalizedData.size(0) * k];
    }
  }
  //  calculate area of squares of length of triangle sides
  firstStepSquared.set_size(firstStep.size(0));
  N = firstStep.size(0);
  for (k = 0; k < N; k++) {
    firstStepSquared[k] = rt_powd_snf(firstStep[k], 2.0);
  }
  y.set_size(firstStep.size(0));
  N = firstStep.size(0);
  for (k = 0; k < N; k++) {
    y[k] = rt_powd_snf(firstStep[k + firstStep.size(0)], 2.0);
  }
  N = firstStepSquared.size(0);
  for (i = 0; i < N; i++) {
    firstStepSquared[i] = firstStepSquared[i] + y[i];
  }
  secondStepSquared.set_size(secondStep.size(0));
  N = secondStep.size(0);
  for (k = 0; k < N; k++) {
    secondStepSquared[k] = rt_powd_snf(secondStep[k], 2.0);
  }
  y.set_size(secondStep.size(0));
  N = secondStep.size(0);
  for (k = 0; k < N; k++) {
    y[k] = rt_powd_snf(secondStep[k + secondStep.size(0)], 2.0);
  }
  N = secondStepSquared.size(0);
  for (i = 0; i < N; i++) {
    secondStepSquared[i] = secondStepSquared[i] + y[i];
  }
  x.set_size(firstStepSquared.size(0));
  N = firstStepSquared.size(0);
  for (i = 0; i < N; i++) {
    x[i] = firstStepSquared[i] * secondStepSquared[i];
  }
  i = x.size(0);
  for (k = 0; k < i; k++) {
    x[k] = std::sqrt(x[k]);
  }
  y.set_size(b.size(0));
  N = b.size(0);
  for (k = 0; k < N; k++) {
    y[k] = rt_powd_snf(b[k], 2.0);
  }
  b_y.set_size(b.size(0));
  N = b.size(0);
  for (k = 0; k < N; k++) {
    b_y[k] = rt_powd_snf(b[k + b.size(0)], 2.0);
  }
  b_x.set_size(firstStepSquared.size(0));
  N = firstStepSquared.size(0);
  for (i = 0; i < N; i++) {
    b_x[i].re =
        ((firstStepSquared[i] + secondStepSquared[i]) - (y[i] + b_y[i])) / 2.0 /
        x[i];
    b_x[i].im = 0.0;
  }
  i = b_x.size(0);
  for (k = 0; k < i; k++) {
    if ((b_x[k].im == 0.0) && (!(std::abs(b_x[k].re) > 1.0))) {
      b_x[k].re = std::acos(b_x[k].re);
      b_x[k].im = 0.0;
    } else {
      double absre;
      double ci;
      boolean_T xneg;
      v.re = b_x[k].re + 1.0;
      v.im = b_x[k].im;
      coder::internal::scalar::b_sqrt(&v);
      u.re = 1.0 - b_x[k].re;
      u.im = 0.0 - b_x[k].im;
      coder::internal::scalar::b_sqrt(&u);
      if ((-v.im == 0.0) && (u.im == 0.0)) {
        ci = 0.0;
      } else {
        double t3;
        double t4;
        t3 = v.re * u.im;
        t4 = -v.im * u.re;
        ci = t3 + t4;
        if ((std::isinf(ci) || std::isnan(ci)) && (!std::isnan(v.re)) &&
            (!std::isnan(-v.im)) && (!std::isnan(u.re)) &&
            (!std::isnan(u.im))) {
          double absim;
          double b_absre;
          double sai;
          double sar;
          double sbi;
          double sbr;
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
          if ((!std::isinf(absre)) && (!std::isnan(absre)) &&
              ((!std::isinf(b_absre)) && (!std::isnan(b_absre)))) {
            xneg = true;
          } else {
            xneg = false;
          }
          if (std::isnan(ci) || (std::isinf(ci) && xneg)) {
            ci = sar * sbi + sai * sbr;
            if (ci != 0.0) {
              ci = ci * absre * b_absre;
            } else if ((std::isinf(absre) &&
                        ((u.re == 0.0) || (u.im == 0.0))) ||
                       (std::isinf(b_absre) &&
                        ((v.re == 0.0) || (-v.im == 0.0)))) {
              if (std::isnan(t3)) {
                t3 = 0.0;
              }
              if (std::isnan(t4)) {
                t4 = 0.0;
              }
              ci = t3 + t4;
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
        if ((absre > 4.503599627370496E+15) ||
            (std::isinf(ci) || std::isnan(ci))) {
          ci++;
          ci = std::log(ci);
        } else if (!(absre < 2.2204460492503131E-16)) {
          ci = std::log(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
        }
      }
      if (xneg) {
        ci = -ci;
      }
      b_x[k].re = 2.0 * rt_atan2d_snf(u.re, v.re);
      b_x[k].im = ci;
    }
  }
  cornerAngle.set_size(b_x.size(0));
  N = b_x.size(0);
  for (i = 0; i < N; i++) {
    cornerAngle[i] = b_x[i].re;
  }
}

// End of code generation (adaptive.cpp)
