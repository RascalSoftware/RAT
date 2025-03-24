//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// drawMultiNest.cpp
//
// Code generation for function 'drawMultiNest'
//

// Include files
#include "drawMultiNest.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "drawEllipsoidPoints.h"
#include "inEllipsoids.h"
#include "nsIntraFun.h"
#include "rand.h"
#include "rescaleParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  double drawMultiNest(const ::coder::array<double, 1U> &fracvol, const ::coder::
                       array<double, 2U> &Bs, const ::coder::array<double, 2U>
                       &mus, double logLmin, const ::coder::array<double, 2U>
                       &prior, const ProblemDefinition &data_f1, const Controls
                       &data_f2, ::coder::array<double, 2U> &sample)
  {
    ::coder::array<double, 2U> B;
    ::coder::array<double, 2U> mu;
    ::coder::array<double, 2U> pnt;
    ::coder::array<double, 2U> r;
    double logL;
    int b_loop_ub;
    int loop_ub;
    int ndims;

    //  Draw a sample from the prior volume using the MultiNest algorithm.
    //
    //  The new point will be found by
    //  drawing a random multi-dimensional sample from within the set of optimal
    //  ellipsoids constructed using the MultiNest algorithm.
    //
    //  Parameters
    //  ----------
    //  fracvol : float
    //      The cumulative fractional volume of the ellipsoids.
    //  Bs : array
    //      The bounding matrices of the ellipsoids to draw from.
    //  mus : array
    //      The centroids of the ellipsoids to draw from.
    //  logLmin : float
    //      The worst likelihood permitted in this iteration.
    //  prior : array
    //      The prior information for the parameters.
    //  data : array
    //      The problem struct and controls.
    //  likelihood : function
    //      The likelihood function for the problem.
    //  model : unknown
    //      Unused.
    //  nMCMC : int
    //      The number of chains to use.
    //  parnames : array
    //      The names of the parameters.
    //  extraparvals : array
    //      A vector of additional parameters needed by the model.
    //
    //  Returns
    //  -------
    //  sample : array
    //      The new point sampled by the algorithm.
    //  logL : float
    //      The log-likelihood of the new sample.
    //
    //  extra number of ellipsoids, number of dimensions
    ndims = mus.size(1);
    pnt.set_size(1, 2);
    pnt[0] = 1.0;
    pnt[1] = 1.0;
    sample.set_size(1, 0);
    loop_ub = Bs.size(1);
    b_loop_ub = mus.size(1);
    double inN;
    double rval;
    int k;
    int k0;
    boolean_T exitg1;
    do {
      int c_loop_ub;
      int i;
      int i1;

      //  find the ellipsoid from which to draw a new point
      rval = coder::b_rand();
      k0 = 0;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= mus.size(0) - 1)) {
        k0 = k;
        if (rval < fracvol[k]) {
          k++;
        } else {
          exitg1 = true;
        }
      }

      //  extract bounding matrix and centroid for that ellipsoid
      i = k0 * ndims;
      i1 = (k0 + 1) * ndims;
      if (i + 1 > i1) {
        i = 0;
        i1 = 0;
      }

      c_loop_ub = i1 - i;
      B.set_size(c_loop_ub, Bs.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (int i2{0}; i2 < c_loop_ub; i2++) {
          B[i2 + B.size(0) * i1] = Bs[(i + i2) + Bs.size(0) * i1];
        }
      }

      mu.set_size(1, mus.size(1));
      for (i = 0; i < b_loop_ub; i++) {
        mu[i] = mus[k0 + mus.size(0) * i];
      }

      //  draw points from that ellipsoid until logL >= logLmin
      logL = rtMinusInf;
      while (logL < logLmin) {
        int in_range;
        in_range = 1;

        //  default value
        //  draw one point from the ellipsoid
        drawEllipsoidPoints(B, mu, pnt);

        //  make sure that the point lies in unit hypercube
        for (int ii{0}; ii < ndims; ii++) {
          double d;
          d = pnt[ii];
          if ((d < 0.0) || (d > 1.0)) {
            in_range = 0;
          }
        }

        if (in_range != 0) {
          //  assign as candidate replacement live point
          sample.set_size(1, pnt.size(1));
          c_loop_ub = pnt.size(1);
          for (i = 0; i < c_loop_ub; i++) {
            sample[sample.size(0) * i] = pnt[i];
          }

          //  rescale point back to full range
          //  get new likelihood
          rescaleParameters(prior, pnt, r);
          logL = nsIntraFun(data_f1, data_f2, r);
        }
      }

      //  check how many ellipsoids this point lies in
      inN = inEllipsoids(pnt, Bs, mus);

      //  only accept sample with 1/inN probability
    } while (!(coder::b_rand() < 1.0 / inN));

    return logL;
  }
}

// End of code generation (drawMultiNest.cpp)
