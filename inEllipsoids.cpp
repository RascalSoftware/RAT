//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static creal_T binary_expand_op(const ::coder::array<double, 2U> &in2, const ::
    coder::array<double, 2U> &in3, int in4, const ::coder::array<creal_T, 2U>
    &in5, const ::coder::array<creal_T, 1U> &in6);
}

// Function Definitions
namespace RAT
{
  static creal_T binary_expand_op(const ::coder::array<double, 2U> &in2, const ::
    coder::array<double, 2U> &in3, int in4, const ::coder::array<creal_T, 2U>
    &in5, const ::coder::array<creal_T, 1U> &in6)
  {
    ::coder::array<creal_T, 2U> b_in2;
    ::coder::array<creal_T, 2U> c_in2;
    ::coder::array<creal_T, 2U> d_in2;
    double b_in2_re_tmp;
    double c_in2_re_tmp;
    double d_in2_re_tmp;
    double in2_re_tmp;
    int b_loop_ub;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in3.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    b_in2.set_size(1, loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in2[i].re = in2[i * stride_0_1] - in3[in4 + in3.size(0) * (i *
        stride_1_1)];
      b_in2[i].im = 0.0;
    }

    c_in2.set_size(1, in5.size(1));
    loop_ub = in5.size(1);
    for (int i{0}; i < loop_ub; i++) {
      c_in2[i].re = 0.0;
      c_in2[i].im = 0.0;
      b_loop_ub = b_in2.size(1);
      for (stride_0_1 = 0; stride_0_1 < b_loop_ub; stride_0_1++) {
        in2_re_tmp = b_in2[stride_0_1].re;
        b_in2_re_tmp = in5[stride_0_1 + in5.size(0) * i].im;
        c_in2_re_tmp = b_in2[stride_0_1].im;
        d_in2_re_tmp = in5[stride_0_1 + in5.size(0) * i].re;
        c_in2[i].re = c_in2[i].re + (in2_re_tmp * d_in2_re_tmp - c_in2_re_tmp *
          b_in2_re_tmp);
        c_in2[i].im = c_in2[i].im + (in2_re_tmp * b_in2_re_tmp + c_in2_re_tmp *
          d_in2_re_tmp);
      }
    }

    if (in6.size(0) == 1) {
      loop_ub = c_in2.size(1);
    } else {
      loop_ub = in6.size(0);
    }

    d_in2.set_size(1, loop_ub);
    stride_0_1 = (c_in2.size(1) != 1);
    stride_1_1 = (in6.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      double ai;
      double ar;
      b_loop_ub = i * stride_0_1;
      ar = c_in2[b_loop_ub].re;
      ai = c_in2[b_loop_ub].im;
      b_loop_ub = i * stride_1_1;
      c_in2_re_tmp = in6[b_loop_ub].re;
      d_in2_re_tmp = -in6[b_loop_ub].im;
      if (d_in2_re_tmp == 0.0) {
        if (ai == 0.0) {
          d_in2[i].re = ar / c_in2_re_tmp;
          d_in2[i].im = 0.0;
        } else if (ar == 0.0) {
          d_in2[i].re = 0.0;
          d_in2[i].im = ai / c_in2_re_tmp;
        } else {
          d_in2[i].re = ar / c_in2_re_tmp;
          d_in2[i].im = ai / c_in2_re_tmp;
        }
      } else if (c_in2_re_tmp == 0.0) {
        if (ar == 0.0) {
          d_in2[i].re = ai / d_in2_re_tmp;
          d_in2[i].im = 0.0;
        } else if (ai == 0.0) {
          d_in2[i].re = 0.0;
          d_in2[i].im = -(ar / d_in2_re_tmp);
        } else {
          d_in2[i].re = ai / d_in2_re_tmp;
          d_in2[i].im = -(ar / d_in2_re_tmp);
        }
      } else {
        double brm;
        brm = std::abs(c_in2_re_tmp);
        in2_re_tmp = std::abs(d_in2_re_tmp);
        if (brm > in2_re_tmp) {
          b_in2_re_tmp = d_in2_re_tmp / c_in2_re_tmp;
          in2_re_tmp = c_in2_re_tmp + b_in2_re_tmp * d_in2_re_tmp;
          d_in2[i].re = (ar + b_in2_re_tmp * ai) / in2_re_tmp;
          d_in2[i].im = (ai - b_in2_re_tmp * ar) / in2_re_tmp;
        } else if (in2_re_tmp == brm) {
          if (c_in2_re_tmp > 0.0) {
            b_in2_re_tmp = 0.5;
          } else {
            b_in2_re_tmp = -0.5;
          }

          if (d_in2_re_tmp > 0.0) {
            in2_re_tmp = 0.5;
          } else {
            in2_re_tmp = -0.5;
          }

          d_in2[i].re = (ar * b_in2_re_tmp + ai * in2_re_tmp) / brm;
          d_in2[i].im = (ai * b_in2_re_tmp - ar * in2_re_tmp) / brm;
        } else {
          b_in2_re_tmp = c_in2_re_tmp / d_in2_re_tmp;
          in2_re_tmp = d_in2_re_tmp + b_in2_re_tmp * c_in2_re_tmp;
          d_in2[i].re = (b_in2_re_tmp * ar + ai) / in2_re_tmp;
          d_in2[i].im = (b_in2_re_tmp * ai - ar) / in2_re_tmp;
        }
      }
    }

    c_in2.set_size(1, d_in2.size(1));
    loop_ub = d_in2.size(1);
    for (int i{0}; i < loop_ub; i++) {
      creal_T varargin_1;
      creal_T varargout_1;
      varargin_1 = d_in2[i];
      varargout_1.re = varargin_1.re * varargin_1.re - varargin_1.im *
        varargin_1.im;
      in2_re_tmp = varargin_1.re * varargin_1.im;
      varargout_1.im = in2_re_tmp + in2_re_tmp;
      c_in2[i] = varargout_1;
    }

    return coder::sum(c_in2);
  }

  double inEllipsoids(const ::coder::array<double, 2U> &pnt, const ::coder::
                      array<double, 2U> &Bs, const ::coder::array<double, 2U>
                      &mus)
  {
    ::coder::array<creal_T, 2U> E;
    ::coder::array<creal_T, 2U> V;
    ::coder::array<creal_T, 2U> b_pnt;
    ::coder::array<creal_T, 2U> c_pnt;
    ::coder::array<creal_T, 1U> r;
    ::coder::array<double, 2U> b_Bs;
    creal_T varargin_1;
    double N;
    int i;
    int ndims;

    //  Calculate how many of the ellipsoids contain the point ``pnt``.
    //
    //  Parameters
    //  ----------
    //  pnt : array
    //      The point to calculate ellipsoid membership for.
    //  Bs : array
    //      The bounding matrices of the ellipsoids.
    //  mus : array
    //      The centroids of the ellipsoids.
    //
    //  Returns
    //  -------
    //  N : int
    //      The number of ellipsoids containing ``pnt``.
    //
    N = 0.0;

    //  total number of ellipsoids and number of dimensions
    ndims = mus.size(1);

    //  loop over number of ellipsiods and work out whether it contains the point
    i = mus.size(0);
    for (int k{0}; k < i; k++) {
      int b_k;
      int i1;
      int i2;
      int loop_ub;

      //  set the point to have the same origin as the ellipsoid
      //  extract the bounding matrix
      i1 = k * ndims;
      i2 = (k + 1) * ndims;
      if (i1 + 1 > i2) {
        i1 = 0;
        i2 = 0;
      }

      //  get the eigenvalues and eigenvectors of the ellipsoid
      b_k = i2 - i1;
      loop_ub = Bs.size(1);
      b_Bs.set_size(b_k, Bs.size(1));
      for (i2 = 0; i2 < loop_ub; i2++) {
        for (int i3{0}; i3 < b_k; i3++) {
          b_Bs[i3 + b_Bs.size(0) * i2] = Bs[(i1 + i3) + Bs.size(0) * i2];
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

      b_k = pnt.size(1);
      if ((pnt.size(1) == mus.size(1)) && (r.size(0) == V.size(1))) {
        double pnt_re_tmp;
        b_pnt.set_size(1, pnt.size(1));
        for (i1 = 0; i1 < b_k; i1++) {
          b_pnt[i1].re = pnt[i1] - mus[k + mus.size(0) * i1];
          b_pnt[i1].im = 0.0;
        }

        b_k = V.size(1);
        c_pnt.set_size(1, V.size(1));
        for (i1 = 0; i1 < b_k; i1++) {
          double b_pnt_re_tmp;
          double c_pnt_re_tmp;
          double d_pnt_re_tmp;
          double im;
          double re;
          re = 0.0;
          im = 0.0;
          loop_ub = b_pnt.size(1);
          for (i2 = 0; i2 < loop_ub; i2++) {
            pnt_re_tmp = b_pnt[i2].re;
            d_pnt_re_tmp = V[i2 + V.size(0) * i1].im;
            b_pnt_re_tmp = b_pnt[i2].im;
            c_pnt_re_tmp = V[i2 + V.size(0) * i1].re;
            re += pnt_re_tmp * c_pnt_re_tmp - b_pnt_re_tmp * d_pnt_re_tmp;
            im += pnt_re_tmp * d_pnt_re_tmp + b_pnt_re_tmp * c_pnt_re_tmp;
          }

          b_pnt_re_tmp = r[i1].re;
          c_pnt_re_tmp = -r[i1].im;
          if (c_pnt_re_tmp == 0.0) {
            if (im == 0.0) {
              c_pnt[i1].re = re / b_pnt_re_tmp;
              c_pnt[i1].im = 0.0;
            } else if (re == 0.0) {
              c_pnt[i1].re = 0.0;
              c_pnt[i1].im = im / b_pnt_re_tmp;
            } else {
              c_pnt[i1].re = re / b_pnt_re_tmp;
              c_pnt[i1].im = im / b_pnt_re_tmp;
            }
          } else if (b_pnt_re_tmp == 0.0) {
            if (re == 0.0) {
              c_pnt[i1].re = im / c_pnt_re_tmp;
              c_pnt[i1].im = 0.0;
            } else if (im == 0.0) {
              c_pnt[i1].re = 0.0;
              c_pnt[i1].im = -(re / c_pnt_re_tmp);
            } else {
              c_pnt[i1].re = im / c_pnt_re_tmp;
              c_pnt[i1].im = -(re / c_pnt_re_tmp);
            }
          } else {
            double brm;
            brm = std::abs(b_pnt_re_tmp);
            pnt_re_tmp = std::abs(c_pnt_re_tmp);
            if (brm > pnt_re_tmp) {
              d_pnt_re_tmp = c_pnt_re_tmp / b_pnt_re_tmp;
              pnt_re_tmp = b_pnt_re_tmp + d_pnt_re_tmp * c_pnt_re_tmp;
              c_pnt[i1].re = (re + d_pnt_re_tmp * im) / pnt_re_tmp;
              c_pnt[i1].im = (im - d_pnt_re_tmp * re) / pnt_re_tmp;
            } else if (pnt_re_tmp == brm) {
              if (b_pnt_re_tmp > 0.0) {
                d_pnt_re_tmp = 0.5;
              } else {
                d_pnt_re_tmp = -0.5;
              }

              if (c_pnt_re_tmp > 0.0) {
                pnt_re_tmp = 0.5;
              } else {
                pnt_re_tmp = -0.5;
              }

              c_pnt[i1].re = (re * d_pnt_re_tmp + im * pnt_re_tmp) / brm;
              c_pnt[i1].im = (im * d_pnt_re_tmp - re * pnt_re_tmp) / brm;
            } else {
              d_pnt_re_tmp = b_pnt_re_tmp / c_pnt_re_tmp;
              pnt_re_tmp = c_pnt_re_tmp + d_pnt_re_tmp * b_pnt_re_tmp;
              c_pnt[i1].re = (d_pnt_re_tmp * re + im) / pnt_re_tmp;
              c_pnt[i1].im = (d_pnt_re_tmp * im - re) / pnt_re_tmp;
            }
          }
        }

        c_pnt.set_size(1, c_pnt.size(1));
        b_k = c_pnt.size(1);
        for (i1 = 0; i1 < b_k; i1++) {
          creal_T varargout_1;
          varargin_1 = c_pnt[i1];
          varargout_1.re = varargin_1.re * varargin_1.re - varargin_1.im *
            varargin_1.im;
          pnt_re_tmp = varargin_1.re * varargin_1.im;
          varargout_1.im = pnt_re_tmp + pnt_re_tmp;
          c_pnt[i1] = varargout_1;
        }

        varargin_1 = coder::sum(c_pnt);
      } else {
        varargin_1 = binary_expand_op(pnt, mus, k, V, r);
      }

      coder::internal::scalar::d_sqrt(&varargin_1);
      if (varargin_1.re <= 1.0) {
        //  values is within the ellipsiod
        N++;
      }
    }

    return N;
  }
}

// End of code generation (inEllipsoids.cpp)
