//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// gaussianConvolution.cpp
//
// Code generation for function 'gaussianConvolution'
//

// Include files
#include "gaussianConvolution.h"
#include "erf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static double convolveGaussianPoint(const ::coder::array<double, 1U> &xin,
    const ::coder::array<double, 1U> &yin, double k, double n, double xo, double
    limit, double sigma);
}

// Function Definitions
namespace RAT
{
  static double convolveGaussianPoint(const ::coder::array<double, 1U> &xin,
    const ::coder::array<double, 1U> &yin, double k, double n, double xo, double
    limit, double sigma)
  {
    double Glo;
    double erflo;
    double erfmin;
    double invSqrt2Sigma;
    double sigmaOverSqrt2Pi;
    double y;
    double z;

    //  Precompute quantities that are constant for this output point.
    //
    //  These would otherwise be recalculated for every input interval.
    invSqrt2Sigma = 1.0 / (1.4142135623730951 * sigma);
    sigmaOverSqrt2Pi = sigma / 2.5066282746310007;

    //  2*sigma^2, used in the Gaussian exponent.
    //  ---------------------------------------------------------------
    //  Initialise at the first input point.
    //  ---------------------------------------------------------------
    //  Distance from the input point to the output position.
    z = xo - xin[static_cast<int>(k) - 1];

    //  Unnormalised Gaussian at this point:
    //
    //    G = exp(-(xo-x)^2/(2*sigma^2))
    //
    Glo = std::exp(-z * z / (2.0 * sigma * sigma));

    //  The integral of the Gaussian is expressed in terms of erf:
    //
    //    erf(-(xo-x)/(sqrt(2)*sigma))
    //
    erfmin = coder::b_erf(-z * invSqrt2Sigma);
    erflo = erfmin;

    //  Accumulate the convolution integral here.
    y = 0.0;

    //  ---------------------------------------------------------------
    //  Integrate over the piecewise-linear input function.
    //  ---------------------------------------------------------------
    int exitg1;
    do {
      exitg1 = 0;
      if (k < n) {
        double d;
        double d1;
        k++;

        //  Ignore duplicate input points.
        d = xin[static_cast<int>(k) - 1];
        d1 = xin[static_cast<int>(k - 1.0) - 1];
        if (d != d1) {
          double Ghi;
          double erfhi;
          double m;
          double m_tmp;
          double u;

          //  Distance from the new input point to xo.
          //  Dimensionless distance in units of sigma:
          //
          //    u = -(xo-x)/(sqrt(2)*sigma)
          //
          u = -(xo - d) * invSqrt2Sigma;

          //  Unnormalised Gaussian at the new endpoint.
          Ghi = std::exp(-u * u);

          //  Error-function value at the new endpoint.
          erfhi = coder::b_erf(u);

          //  -------------------------------------------------------
          //  Linear interpolation between the two input points.
          //
          //    yin(x) = m*x + b
          //  -------------------------------------------------------
          m_tmp = yin[static_cast<int>(k) - 1];
          m = (m_tmp - yin[static_cast<int>(k - 1.0) - 1]) / (d - d1);

          //  -------------------------------------------------------
          //  Analytically integrate
          //
          //    (m*x + b) * Gaussian(x)
          //
          //  over this input interval.
          //
          //  The first term comes from the integral of the
          //  Gaussian and therefore contains erf().
          //
          //  The second term comes from the integral of
          //  (x-xo)*Gaussian and therefore contains Ghi-Glo.
          //  -------------------------------------------------------
          y = (y + 0.5 * (m * xo + (m_tmp - m * d)) * (erfhi - erflo)) -
            sigmaOverSqrt2Pi * m * (Ghi - Glo);

          //  Current endpoint becomes the lower endpoint for
          //  the next interval.
          Glo = Ghi;
          erflo = erfhi;

          //  Stop once we have reached the upper Gaussian limit.
          //
          //  limit ~= 3.717*sigma, corresponding to a Gaussian
          //  amplitude of approximately 0.1% of its peak.
          if (d >= xo + limit) {
            exitg1 = 1;
          }
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    //  ---------------------------------------------------------------
    //  Normalisation
    //  ---------------------------------------------------------------
    //
    //  The Gaussian has been truncated to approximately +/-3.717*sigma,
    //  so its integrated area is slightly less than one.
    //
    //  The erf difference gives the area of this truncated Gaussian.
    //  Renormalising ensures that a constant input function remains
    //  constant after convolution.
    //  ---------------------------------------------------------------
    return 2.0 * y / (erflo - erfmin);
  }

  void gaussianConvolution(const ::coder::array<double, 1U> &xin, const ::coder::
    array<double, 1U> &yin, const ::coder::array<double, 1U> &x, const ::coder::
    array<double, 1U> &dx, ::coder::array<double, 1U> &y)
  {
    int Nin;
    int i;
    int kin;
    int loop_ub;

    //  Convolve the input function yin(xin) with a Gaussian resolution
    //  function.
    //
    //  For each output point xo = x(kout), the calculation is
    //
    //    y(xo) = integral[ yin(x) * G(xo-x; sigma) dx ]
    //
    //  where
    //
    //    G(xo-x; sigma) = 1/(sqrt(2*pi)*sigma)
    //                     * exp(-(xo-x)^2/(2*sigma^2))
    //
    //  The input function yin(xin) is assumed to be piecewise linear
    //  between the supplied xin points. The convolution integral over
    //  each linear segment can then be evaluated analytically.
    //
    //  sigma = dx(kout) is the Gaussian resolution width associated
    //  with each output point.
    y.set_size(x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      y[i] = 0.0;
    }

    Nin = xin.size(0);

    //  log(0.001). This is used to truncate the Gaussian when its
    //  amplitude has fallen to 0.1% of its maximum.
    //  Index of the input point near the left-hand edge of the
    //  Gaussian integration range. This is carried between output
    //  points to avoid repeatedly searching from the beginning.
    kin = 0;
    i = x.size(0);
    for (int kout{0}; kout < i; kout++) {
      double limit;
      double xo;

      //  Gaussian resolution width for this output point.
      //  Output coordinate at which we want the convolved value.
      xo = x[kout];

      //  Truncate the Gaussian when it has fallen to 0.1% of
      //  its peak value.
      //
      //  exp(-limit^2/(2*sigma^2)) = 0.001
      //
      //  Therefore
      //
      //    limit = sqrt(-2*sigma^2*log(0.001))
      //          ~= 3.717*sigma
      //
      //  so the convolution only needs to consider approximately
      //
      //    xo - 3.717*sigma  <= x <=  xo + 3.717*sigma.
      limit = std::sqrt(-2.0 * dx[kout] * dx[kout] * -6.9077552789821368);

      //  Find the first input point at or just after the left-hand
      //  edge of the Gaussian integration range.
      while ((kin + 1 < Nin) && (xin[kin] < xo - limit)) {
        kin++;
      }

      //  Move back one point if necessary so that kin is the input
      //  point immediately before (or near) xo-limit.
      while ((kin + 1 > 1) && (xin[kin] > xo - limit)) {
        kin--;
      }

      if (dx[kout] > 0.0) {
        //  Perform the actual Gaussian convolution at xo.
        //
        //  convolveGaussianPoint treats yin(xin) as a piecewise
        //  linear function and integrates each linear segment
        //  analytically against the Gaussian resolution function.
        y[kout] = convolveGaussianPoint(xin, yin, static_cast<double>(kin + 1),
          static_cast<double>(Nin), x[kout], limit, dx[kout]);
      } else if (kin + 1 < Nin) {
        double m;

        //  If sigma = 0 there is no resolution broadening.
        //  Simply linearly interpolate yin at xo.
        m = (yin[kin + 1] - yin[kin]) / (xin[kin + 1] - xin[kin]);
        y[kout] = m * x[kout] + (yin[kin] - m * xin[kin]);
      } else if (kin + 1 > 1) {
        double m;

        //  If sigma = 0 and xo lies beyond the final input point,
        //  linearly extrapolate from the final two points.
        m = (yin[kin] - yin[kin - 1]) / (xin[kin] - xin[kin - 1]);
        y[kout] = m * x[kout] + (yin[kin] - m * xin[kin]);
      }
    }
  }
}

// End of code generation (gaussianConvolution.cpp)
