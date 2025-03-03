//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  void drawMultiNest(const ::coder::array<double, 1U> &fracvol, const ::coder::
                     array<double, 2U> &Bs, const ::coder::array<double, 2U>
                     &mus, double logLmin, const ::coder::array<double, 2U>
                     &prior, const ProblemDefinition *data_f1, const Controls
                     *data_f2, ::coder::array<double, 2U> &sample, double *logL)
  {
    ::coder::array<double, 2U> b_Bs;
    ::coder::array<double, 2U> b_mus;
    ::coder::array<double, 2U> b_pnt;
    ::coder::array<double, 2U> pnt;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> rescaledpnt;
    int ndims;

    //  This function draws a multi-dimensional sample from the prior volume
    //  for use in the nested sampling algorithm. The new point will have a
    //  likelihood greater than the value logLmin. The new point will be found by
    //  drawing a random multi-dimensional sample from within the set of optimal
    //  ellipsoids constructed using the MultiNest algorithm.  The bounding
    //  ellipsoids are defined by their bounding matrices Bs and centroids mus.
    //  extraparvals is a vector of additional parameters needed by the model.
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  extra number of ellipsoids, number of dimensions
    ndims = mus.size(1);
    pnt.set_size(1, 2);
    pnt[0] = 1.0;
    pnt[1] = 1.0;
    sample.set_size(1, 0);
    double inN;
    double rval;
    int k;
    int k0;
    boolean_T exitg1;
    do {
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

      //  draw points from that ellipsoid until logL >= logLmin
      *logL = rtMinusInf;
      while (*logL < logLmin) {
        int b_loop_ub;
        int i2;
        int in_range;
        int loop_ub;
        in_range = 1;

        //  default value
        //  draw one point from the ellipsoid
        loop_ub = Bs.size(1);
        b_loop_ub = i1 - i;
        b_Bs.set_size(b_loop_ub, Bs.size(1));
        for (i2 = 0; i2 < loop_ub; i2++) {
          for (int i3{0}; i3 < b_loop_ub; i3++) {
            b_Bs[i3 + b_Bs.size(0) * i2] = Bs[(i + i3) + Bs.size(0) * i2];
          }
        }

        loop_ub = mus.size(1);
        b_mus.set_size(1, mus.size(1));
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_mus[i2] = mus[k0 + mus.size(0) * i2];
        }

        drawEllipsoidPoints(b_Bs, b_mus, b_pnt);
        pnt.set_size(1, b_pnt.size(1));
        loop_ub = b_pnt.size(1);
        for (i2 = 0; i2 < loop_ub; i2++) {
          pnt[i2] = b_pnt[i2];
        }

        //  make sure that the point lies in unit hypercube
        for (int ii{0}; ii < ndims; ii++) {
          double d;
          d = b_pnt[ii];
          if ((d < 0.0) || (d > 1.0)) {
            in_range = 0;
          }
        }

        if (in_range != 0) {
          //  assign as candidate replacement live point
          sample.set_size(1, b_pnt.size(1));
          loop_ub = b_pnt.size(1);
          for (i2 = 0; i2 < loop_ub; i2++) {
            sample[sample.size(0) * i2] = b_pnt[i2];
          }

          //  rescale point back to full range
          rescaleParameters(prior, b_pnt, r);
          rescaledpnt.set_size(1, r.size(1));
          loop_ub = r.size(1);
          for (i2 = 0; i2 < loop_ub; i2++) {
            rescaledpnt[i2] = r[i2];
          }

          //  get new likelihood
          *logL = nsIntraFun(data_f1, data_f2, rescaledpnt);
        }
      }

      //  check how many ellipsoids this point lies in
      inN = inEllipsoids(pnt, Bs, mus);

      //  only accept sample with 1/inN probability
    } while (!(coder::b_rand() < 1.0 / inN));
  }
}

// End of code generation (drawMultiNest.cpp)
