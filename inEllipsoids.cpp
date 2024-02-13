//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// inEllipsoids.cpp
//
// Code generation for function 'inEllipsoids'
//

// Include files
#include "inEllipsoids.h"
#include "RATMain_data.h"
#include "diag.h"
#include "eig.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  real_T inEllipsoids(const ::coder::array<real_T, 2U> &pnt, const ::coder::
                      array<real_T, 2U> &Bs, const ::coder::array<real_T, 2U>
                      &mus)
  {
    ::coder::array<creal_T, 2U> E;
    ::coder::array<creal_T, 2U> V;
    ::coder::array<creal_T, 2U> b_pnt;
    ::coder::array<creal_T, 2U> c_pnt;
    ::coder::array<creal_T, 2U> r1;
    ::coder::array<creal_T, 1U> r;
    ::coder::array<real_T, 2U> b_Bs;
    creal_T dc;
    real_T N;
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    int32_T ndims;

    //  function N = inEllipsoids(pnt, Bs, mus)
    //
    //  This function works out how many of the ellipsoids (defined by the
    //  bounding matrices Bs and centroids mus) contain the point pnt.
    //  This number is returned in N.
    //
    //  Bs is a [(Kxndims) x ndims] array, where K=total number of ellipsoids
    //  and ndims = dimension of the parameter space.
    //  mus is a [K x ndims] array.
    //  pnt is a ndims-dimensional vector.
    //
    //  NOTE: in the future it may be quicker to input precalculated eigenvalues
    //  and eigenvectors into this function rather than the bounding matrices
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    N = 0.0;

    //  total number of ellipsoids and number of dimensions
    ndims = mus.size(1);

    //  loop over number of ellipsiods and work out whether it contains the point
    i = mus.size(0);
    if (0 <= i - 1) {
      loop_ub = Bs.size(1);
      b_loop_ub = pnt.size(1);
    }

    for (int32_T k{0}; k < i; k++) {
      int32_T b_k;
      int32_T c_loop_ub;
      int32_T i1;
      int32_T i2;

      //  set the point to have the same origin as the ellipsoid
      //  extract the bounding matrix
      i1 = k * ndims;
      i2 = (k + 1) * ndims;
      if (i1 + 1 > i2) {
        i1 = 0;
        i2 = 0;
      }

      //  get the eigenvalues and eigenvectors of the ellipsoid
      c_loop_ub = i2 - i1;
      b_Bs.set_size(c_loop_ub, Bs.size(1));
      for (i2 = 0; i2 < loop_ub; i2++) {
        for (b_k = 0; b_k < c_loop_ub; b_k++) {
          b_Bs[b_k + b_Bs.size(0) * i2] = Bs[(i1 + b_k) + Bs.size(0) * i2];
        }
      }

      coder::eig(b_Bs, V, E);

      //  V is matrix of eigenvectors (as columns)
      //  rotate points to be on coordinate axes of the ellipsiod
      //  scale points so that it's equivalent to having unit hyper-spheroids
      //  rather than ellipsiods
      //  get distance to point from centre of hyper-sphere
      coder::diag(E, r);
      i1 = r.size(0);
      for (b_k = 0; b_k < i1; b_k++) {
        coder::internal::scalar::d_sqrt(&r[b_k]);
      }

      b_pnt.set_size(1, pnt.size(1));
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_pnt[i1].re = pnt[i1] - mus[k + mus.size(0) * i1];
        b_pnt[i1].im = 0.0;
      }

      c_loop_ub = V.size(1);
      c_pnt.set_size(1, V.size(1));
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        real_T bi;
        real_T br;
        real_T im;
        real_T re;
        re = 0.0;
        im = 0.0;
        b_k = b_pnt.size(1);
        for (i2 = 0; i2 < b_k; i2++) {
          re += b_pnt[i2].re * V[i2 + V.size(0) * i1].re - b_pnt[i2].im * V[i2 +
            V.size(0) * i1].im;
          im += b_pnt[i2].re * V[i2 + V.size(0) * i1].im + b_pnt[i2].im * V[i2 +
            V.size(0) * i1].re;
        }

        br = r[i1].re;
        bi = -r[i1].im;
        if (bi == 0.0) {
          if (im == 0.0) {
            c_pnt[i1].re = re / br;
            c_pnt[i1].im = 0.0;
          } else if (re == 0.0) {
            c_pnt[i1].re = 0.0;
            c_pnt[i1].im = im / br;
          } else {
            c_pnt[i1].re = re / br;
            c_pnt[i1].im = im / br;
          }
        } else if (br == 0.0) {
          if (re == 0.0) {
            c_pnt[i1].re = im / bi;
            c_pnt[i1].im = 0.0;
          } else if (im == 0.0) {
            c_pnt[i1].re = 0.0;
            c_pnt[i1].im = -(re / bi);
          } else {
            c_pnt[i1].re = im / bi;
            c_pnt[i1].im = -(re / bi);
          }
        } else {
          real_T bim;
          real_T brm;
          brm = std::abs(br);
          bim = std::abs(bi);
          if (brm > bim) {
            real_T s;
            s = bi / br;
            bim = br + s * bi;
            c_pnt[i1].re = (re + s * im) / bim;
            c_pnt[i1].im = (im - s * re) / bim;
          } else if (bim == brm) {
            real_T s;
            if (br > 0.0) {
              s = 0.5;
            } else {
              s = -0.5;
            }

            if (bi > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }

            c_pnt[i1].re = (re * s + im * bim) / brm;
            c_pnt[i1].im = (im * s - re * bim) / brm;
          } else {
            real_T s;
            s = br / bi;
            bim = bi + s * br;
            c_pnt[i1].re = (s * re + im) / bim;
            c_pnt[i1].im = (s * im - re) / bim;
          }
        }
      }

      coder::power(c_pnt, r1);
      dc = coder::sum(r1);
      coder::internal::scalar::d_sqrt(&dc);
      if (dc.re <= 1.0) {
        //  values is within the ellipsiod
        N++;
      }
    }

    return N;
  }
}

// End of code generation (inEllipsoids.cpp)
