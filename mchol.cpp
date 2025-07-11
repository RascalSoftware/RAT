//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// mchol.cpp
//
// Code generation for function 'mchol'
//

// Include files
#include "mchol.h"
#include "abs.h"
#include "diag.h"
#include "minOrMax.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, const ::
    coder::array<int, 1U> &in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 1U> &in5, const ::coder::array<double, 1U> &in6);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<int, 1U> &in2, int in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 1U> &in5, const ::coder::array<double, 2U> &in6);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 1U> &in2, double in3, const ::coder::array<double, 1U> &in5);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, const ::
    coder::array<int, 1U> &in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 1U> &in5, const ::coder::array<double, 1U> &in6)
  {
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    stride_0_1 = (in5.size(0) != 1);
    stride_1_1 = (in6.size(0) != 1);
    loop_ub = in3.size(0);
    for (int i{0}; i < loop_ub; i++) {
      in1[in2 + in1.size(0) * in3[i]] = in4[in2 + in4.size(0) * (static_cast<int>
        (in5[i * stride_0_1]) - 1)] / in6[i * stride_1_1];
    }
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<int, 1U> &in2, int in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 1U> &in5, const ::coder::array<double, 2U> &in6)
  {
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    stride_0_0 = (in5.size(0) != 1);
    stride_1_0 = (in6.size(1) != 1);
    loop_ub = in2.size(0);
    for (int i{0}; i < loop_ub; i++) {
      in1[in2[i] + in1.size(0) * in3] = in4[(static_cast<int>(in5[i * stride_0_0])
        + in4.size(0) * in3) - 1] - in6[i * stride_1_0];
    }
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 1U> &in2, double in3, const ::coder::array<double, 1U> &in5)
  {
    ::coder::array<double, 1U> b_in1;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in5.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in5.size(0);
    }

    b_in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in5.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      double varargin_1;
      varargin_1 = in5[i * stride_1_0];
      b_in1[i] = in1[static_cast<int>(in2[i * stride_0_0]) - 1] - in3 *
        (varargin_1 * varargin_1);
    }

    loop_ub = b_in1.size(0);
    for (int i{0}; i < loop_ub; i++) {
      in1[static_cast<int>(in2[i]) - 1] = b_in1[i];
    }
  }

  void mchol(const ::coder::array<double, 2U> &G, ::coder::array<double, 2U> &L,
             ::coder::array<double, 2U> &D)
  {
    ::coder::array<double, 2U> C;
    ::coder::array<double, 2U> b_G;
    ::coder::array<double, 2U> b_L;
    ::coder::array<double, 2U> ee;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> theta;
    ::coder::array<double, 2U> y;
    ::coder::array<double, 1U> b_C;
    ::coder::array<double, 1U> ind;
    ::coder::array<double, 1U> varargin_1_tmp;
    ::coder::array<int, 2U> bb;
    ::coder::array<int, 1U> r1;
    double b_dv1[3];
    double dv2[3];
    double b_dv[2];
    double b;
    double b_b;
    double beta2;
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    int n;

    //   Reference: Gill, Murray, and Wright, "Practical Optimization", p111.
    //   Author: Brian Borchers (borchers@nmt.edu)
    //
    //   Copyright (c) 2009, Brian Borchers
    //   All rights reserved.
    //
    //   Redistribution and use in source and binary forms, with or without
    //   modification, are permitted provided that the following conditions are
    //   met:
    //
    //     * Redistributions of source code must retain the above copyright
    //       notice, this list of conditions and the following disclaimer.
    //     * Redistributions in binary form must reproduce the above copyright
    //       notice, this list of conditions and the following disclaimer in
    //       the documentation and/or other materials provided with the distribution
    //     * Neither the name of the New Mexico Inst of Mining & Tech nor the names
    //       of its contributors may be used to endorse or promote products derived
    //       from this software without specific prior written permission.
    //
    //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    //  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    //  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    //  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
    //  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    //  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    //  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    //  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    //  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    //  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    //  POSSIBILITY OF SUCH DAMAGE.
    //  Calculate the Cholesky (LDL) decomposition of a symmetric matrix G.
    //
    //  Includes a potential small perturbation so that we can calculate for non-positive-definite matrices.
    //
    //  Given a symmetric matrix G, find a matrix E of "small" norm, lower-triangular matrix
    //  L, and diagonal matrix D such that G+E is positive definite, and
    //
    //  .. math:: G+E = LDL'
    //
    //  Also, calculate a direction pneg, such that if G is not PD, then
    //
    //  .. math:: \text{pneg}' G \text{pneg} < 0
    //
    //  Note that if G is positive-definite, then the routine will return pneg=[].
    //
    //  Parameters
    //  ----------
    //  G : array
    //      The matrix to calculate the Cholesky decomposition for.
    //
    //  Returns
    //  -------
    //  L : array
    //      The lower-triangular matrix such that G+E = LDL'.
    //  D : array
    //      The diagonal matrix such that G+E = LDL'.
    //  E : array
    //      The perturbation matrix such that G+E = LDL'.
    //  pneg : array
    //      The descent direction when G is not positive-definite.
    //
    //   n gives the size of the matrix.
    //
    n = G.size(0);

    //
    //   gamma, zi, nu, and beta2 are quantities used by the algorithm.
    //
    coder::diag(G, varargin_1_tmp);
    coder::diag(varargin_1_tmp, r);
    if ((G.size(0) == r.size(0)) && (G.size(1) == r.size(1))) {
      b_G.set_size(G.size(0), G.size(1));
      loop_ub = G.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = G.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_G[i1 + b_G.size(0) * i] = G[i1 + G.size(0) * i] - r[i1 + r.size(0) *
            i];
        }
      }

      coder::internal::maximum(b_G, y);
    } else {
      c_binary_expand_op(y, G, r);
    }

    b_dv[0] = 1.0;
    b = static_cast<double>(G.size(0)) * static_cast<double>(G.size(0));
    b_dv[1] = std::sqrt(b - 1.0);
    b_dv1[0] = coder::internal::maximum(varargin_1_tmp);
    b_dv1[1] = coder::internal::maximum(y) / coder::internal::b_maximum(b_dv);
    b_dv1[2] = 1.0E-15;
    beta2 = coder::internal::maximum(b_dv1);

    //
    //   Initialize diag(C) to diag(G).
    //
    C.set_size(r.size(0), r.size(1));
    loop_ub = r.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        C[i1 + C.size(0) * i] = r[i1 + r.size(0) * i];
      }
    }

    //
    //   Loop through, calculating column j of L for j=1:n
    //
    L.set_size(G.size(0), G.size(0));
    loop_ub = G.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = G.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        L[i1 + L.size(0) * i] = 0.0;
      }
    }

    D.set_size(G.size(0), G.size(0));
    loop_ub = G.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = G.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        D[i1 + D.size(0) * i] = 0.0;
      }
    }

    theta.set_size(G.size(0), G.size(0));
    loop_ub = G.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = G.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        theta[i1 + theta.size(0) * i] = 0.0;
      }
    }

    i = G.size(0);
    if (G.size(0) - 1 >= 0) {
      dv2[0] = 2.2204460492503131E-16;
      b_b = b;
    }

    for (int j{0}; j < i; j++) {
      double a;
      int i2;
      if (j < 1) {
        bb.set_size(1, 0);
      } else {
        bb.set_size(1, j);
        for (i1 = 0; i1 < j; i1++) {
          bb[i1] = i1 + 1;
        }
      }

      if (static_cast<unsigned int>(n) < static_cast<unsigned int>(j) + 2U) {
        ee.set_size(1, 0);
      } else {
        i1 = n - j;
        ee.set_size(1, i1 - 1);
        loop_ub = i1 - 2;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          ee[i1] = (static_cast<unsigned int>(j) + static_cast<unsigned int>(i1))
            + 2U;
        }
      }

      //
      //   Calculate the jth row of L.
      //
      if (j + 1 > 1) {
        varargin_1_tmp.set_size(bb.size(1));
        loop_ub = bb.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          varargin_1_tmp[i1] = bb[i1];
        }

        r1.set_size(varargin_1_tmp.size(0));
        loop_ub = varargin_1_tmp.size(0);
        b_G.set_size(varargin_1_tmp.size(0), varargin_1_tmp.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          i2 = static_cast<int>(varargin_1_tmp[i1]) - 1;
          r1[i1] = i2;
          b_loop_ub = varargin_1_tmp.size(0);
          for (int i3{0}; i3 < b_loop_ub; i3++) {
            b_G[i3 + b_G.size(0) * i1] = D[(static_cast<int>(varargin_1_tmp[i3])
              + D.size(0) * i2) - 1];
          }
        }

        coder::diag(b_G, b_C);
        if (varargin_1_tmp.size(0) == b_C.size(0)) {
          loop_ub = r1.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            L[j + L.size(0) * r1[i1]] = C[j + C.size(0) * (static_cast<int>
              (varargin_1_tmp[i1]) - 1)] / b_C[i1];
          }
        } else {
          binary_expand_op(L, j, r1, C, varargin_1_tmp, b_C);
        }
      }

      //
      //   Update the jth column of C.
      //
      if (j + 1 >= 2) {
        if (j + 1 < n) {
          varargin_1_tmp.set_size(bb.size(1));
          loop_ub = bb.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            varargin_1_tmp[i1] = bb[i1];
          }

          r.set_size(ee.size(1), varargin_1_tmp.size(0));
          loop_ub = varargin_1_tmp.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = ee.size(1);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r[i2 + r.size(0) * i1] = C[(static_cast<int>(ee[i2]) + C.size(0) *
                (static_cast<int>(varargin_1_tmp[i1]) - 1)) - 1];
            }
          }

          b_C.set_size(ee.size(1));
          loop_ub = ee.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_C[i1] = ee[i1];
          }

          r1.set_size(b_C.size(0));
          loop_ub = b_C.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            r1[i1] = static_cast<int>(b_C[i1]) - 1;
          }

          b_L.set_size(1, varargin_1_tmp.size(0));
          loop_ub = varargin_1_tmp.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_L[i1] = L[j + L.size(0) * (static_cast<int>(varargin_1_tmp[i1]) -
              1)];
          }

          coder::internal::blas::mtimes(b_L, r, y);
          if (b_C.size(0) == y.size(1)) {
            loop_ub = r1.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              C[r1[i1] + C.size(0) * j] = G[(static_cast<int>(b_C[i1]) + G.size
                (0) * j) - 1] - y[i1];
            }
          } else {
            binary_expand_op(C, r1, j, G, b_C, y);
          }
        }
      } else {
        varargin_1_tmp.set_size(ee.size(1));
        loop_ub = ee.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          varargin_1_tmp[i1] = ee[i1];
        }

        r1.set_size(varargin_1_tmp.size(0));
        loop_ub = varargin_1_tmp.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r1[i1] = static_cast<int>(varargin_1_tmp[i1]) - 1;
        }

        loop_ub = r1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          C[r1[i1]] = G[static_cast<int>(varargin_1_tmp[i1]) - 1];
        }
      }

      //
      //  Update theta.
      //
      if (j + 1 == n) {
        theta[j] = 0.0;
      } else {
        b_C.set_size(ee.size(1));
        loop_ub = ee.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_C[i1] = C[(static_cast<int>(ee[i1]) + C.size(0) * j) - 1];
        }

        coder::b_abs(b_C, varargin_1_tmp);
        theta[j] = coder::internal::maximum(varargin_1_tmp);
      }

      //
      //   Update D
      //
      dv2[1] = std::abs(C[j + C.size(0) * j]);
      dv2[2] = theta[j] * theta[j] / beta2;
      D[j + D.size(0) * j] = coder::internal::maximum(dv2);

      //
      //  Update E.
      //
      //   Update C again...
      //
      // %%%%%%% M.Zibulevsky: begin of changes, old version is commented %%%%%%%%%%%%%
      // for i=j+1:n,
      //     C(i,i)=C(i,i)-C(i,j)^2/D(j,j);
      // end;
      a = (static_cast<double>(j) + 1.0) * (static_cast<double>(n) + 1.0) + 1.0;
      if (b_b < a) {
        y.set_size(1, 0);
      } else {
        loop_ub = static_cast<int>((b_b - a) / (static_cast<double>(n) + 1.0));
        y.set_size(1, loop_ub + 1);
        for (i1 = 0; i1 <= loop_ub; i1++) {
          y[i1] = a + (static_cast<double>(n) + 1.0) * static_cast<double>(i1);
        }
      }

      ind.set_size(y.size(1));
      loop_ub = y.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        ind[i1] = y[i1];
      }

      a = 1.0 / D[j + D.size(0) * j];
      varargin_1_tmp.set_size(ee.size(1));
      loop_ub = ee.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        varargin_1_tmp[i1] = C[(static_cast<int>(ee[i1]) + C.size(0) * j) - 1];
      }

      if (ind.size(0) == varargin_1_tmp.size(0)) {
        b_C.set_size(ind.size(0));
        loop_ub = ind.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          double varargin_1;
          varargin_1 = varargin_1_tmp[i1];
          b_C[i1] = C[static_cast<int>(ind[i1]) - 1] - a * (varargin_1 *
            varargin_1);
        }

        loop_ub = b_C.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          C[static_cast<int>(ind[i1]) - 1] = b_C[i1];
        }
      } else {
        binary_expand_op(C, ind, a, varargin_1_tmp);
      }
    }

    //
    //  Put 1's on the diagonal of L
    //
    // for j=1:n,
    //     L(j,j)=1;
    // end;
    if (b < 1.0) {
      y.set_size(1, 0);
    } else {
      loop_ub = static_cast<int>((b - 1.0) / (static_cast<double>(G.size(0)) +
        1.0));
      y.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        y[i] = (static_cast<double>(G.size(0)) + 1.0) * static_cast<double>(i) +
          1.0;
      }
    }

    r1.set_size(y.size(1));
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      r1[i] = static_cast<int>(y[i]);
    }

    loop_ub = r1.size(0);
    for (i = 0; i < loop_ub; i++) {
      L[r1[i] - 1] = 1.0;
    }

    // %%%%%%%%%%%%%%%%%%%%%%% M.Zibulevsky: end of changes %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //
    //   if needed, find a descent direction.
    //
  }
}

// End of code generation (mchol.cpp)
