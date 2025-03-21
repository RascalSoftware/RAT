//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// drawEllipsoidPoints.cpp
//
// Code generation for function 'drawEllipsoidPoints'
//

// Include files
#include "drawEllipsoidPoints.h"
#include "RATMain_rtwutil.h"
#include "blockedSummation.h"
#include "diag.h"
#include "eig.h"
#include "eml_mtimes_helper.h"
#include "mtimes.h"
#include "rand.h"
#include "randn.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<creal_T, 2U> &in2, const ::coder::array<double, 2U> &in3);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<creal_T, 2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    loop_ub = in1.size(1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_1].re + in3[i * stride_1_1];
    }
  }

  void drawEllipsoidPoints(const ::coder::array<double, 2U> &B, const ::coder::
    array<double, 2U> &mu, ::coder::array<double, 2U> &pnts)
  {
    ::coder::array<creal_T, 2U> E;
    ::coder::array<creal_T, 2U> V;
    ::coder::array<creal_T, 2U> b_pnts;
    ::coder::array<creal_T, 2U> r1;
    ::coder::array<creal_T, 1U> r;
    ::coder::array<double, 2U> pt;
    ::coder::array<double, 2U> x;
    double a;
    int i;
    int k;

    //  Draw points uniformly from an ellipsoid.
    //
    //  Parameters
    //  ----------
    //  B : array
    //      The bounding matrix for the ellipsoid.
    //  mu : float
    //      The centroid of the ellipsoid.
    //  N : int
    //      The number of points to draw.
    //
    //  Returns
    //  -------
    //  pnts : array
    //      An array of N points drawn from the N-dimensional ellipsoid defined
    //      by bounding matrix B and centroid mu.
    //  get number of dimensions from the bounding matrix B
    //  calculate eigenvalues and vectors of the bounding matrix
    coder::eig(B, V, E);

    //  check size of mu and transpose if necessary
    //  generate radii of hyperspheres
    a = coder::b_rand();

    //  generate points
    coder::randn(static_cast<double>(B.size(0)), pt);

    //  get scalings for each point onto the surface of a unit hypersphere
    x.set_size(1, pt.size(1));
    k = pt.size(1);
    for (i = 0; i < k; i++) {
      double varargin_1;
      varargin_1 = pt[i];
      x[i] = rt_powd_snf(varargin_1, 2.0);
    }

    //  calculate scaling for each point to be within the unit hypersphere
    //  with radii rs
    a = rt_powd_snf(a, 1.0 / static_cast<double>(B.size(0))) / std::sqrt(coder::
      blockedSummation(x, x.size(1)));
    pnts.set_size(1, B.size(0));
    k = B.size(0);

    //  scale points to the ellipsoid using the eigenvalues and rotate with
    //  the eigenvectors and add centroid
    //  scale points to a uniform distribution within unit hypersphere
    for (i = 0; i < k; i++) {
      pnts[i] = a * pt[i];
    }

    //  scale and rotate to ellipsoid
    //  ('real' needed for compile....)
    coder::diag(E, r);
    i = r.size(0);
    for (k = 0; k < i; k++) {
      coder::internal::scalar::d_sqrt(&r[k]);
    }

    if (r.size(0) == pnts.size(1)) {
      b_pnts.set_size(1, pnts.size(1));
      k = pnts.size(1);
      for (i = 0; i < k; i++) {
        b_pnts[i].re = pnts[i] * r[i].re;
        b_pnts[i].im = pnts[i] * -r[i].im;
      }

      coder::internal::blas::mtimes(b_pnts, V, r1);
    } else {
      binary_expand_op(r1, pnts, r, V);
    }

    if (r1.size(1) == mu.size(1)) {
      k = pnts.size(1);
      for (i = 0; i < k; i++) {
        pnts[i] = r1[i].re + mu[i];
      }
    } else {
      binary_expand_op(pnts, r1, mu);
    }
  }
}

// End of code generation (drawEllipsoidPoints.cpp)
