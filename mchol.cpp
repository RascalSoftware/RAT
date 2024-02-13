//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mchol.cpp
//
// Code generation for function 'mchol'
//

// Include files
#include "mchol.h"
#include "abs.h"
#include "colon.h"
#include "diag.h"
#include "minOrMax.h"
#include "mtimes.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void mchol(const ::coder::array<real_T, 2U> &G, ::coder::array<real_T, 2U> &L,
             ::coder::array<real_T, 2U> &D)
  {
    ::coder::array<real_T, 2U> C;
    ::coder::array<real_T, 2U> a;
    ::coder::array<real_T, 2U> b_G;
    ::coder::array<real_T, 2U> bb;
    ::coder::array<real_T, 2U> ee;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> theta;
    ::coder::array<real_T, 2U> y;
    ::coder::array<real_T, 1U> b_C;
    ::coder::array<real_T, 1U> ind;
    ::coder::array<real_T, 1U> varargin_1_tmp;
    ::coder::array<int32_T, 1U> r1;
    real_T b_dv1[3];
    real_T dv2[3];
    real_T b_dv[2];
    real_T b;
    real_T beta2;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T n;

    //
    //   [L,D,E,pneg]=mchol(G)
    //
    //   Given a symmetric matrix G, find a matrix E of "small" norm and c
    //   L, and D such that  G+E is Positive Definite, and
    //
    //       G+E = L*D*L'
    //
    //   Also, calculate a direction pneg, such that if G is not PD, then
    //
    //       pneg'*G*pneg < 0
    //
    //   Note that if G is PD, then the routine will return pneg=[].
    //
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
    //
    //   n gives the size of the matrix.
    //
    n = G.size(0);

    //
    //   gamma, zi, nu, and beta2 are quantities used by the algorithm.
    //
    coder::diag(G, varargin_1_tmp);
    coder::diag(varargin_1_tmp, r);
    b_G.set_size(G.size(0), G.size(1));
    loop_ub = G.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = G.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_G[i1 + b_G.size(0) * i] = G[i1 + G.size(0) * i] - r[i1 + r.size(0) * i];
      }
    }

    b_dv[0] = 1.0;
    b_dv[1] = std::sqrt(static_cast<real_T>(G.size(0)) * static_cast<real_T>
                        (G.size(0)) - 1.0);
    b_dv1[0] = coder::internal::maximum(varargin_1_tmp);
    coder::internal::maximum(b_G, y);
    b_dv1[1] = coder::internal::maximum(y) / coder::internal::maximum(b_dv);
    b_dv1[2] = 1.0E-15;
    beta2 = coder::internal::b_maximum(b_dv1);

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
    if (0 <= G.size(0) - 1) {
      dv2[0] = 2.2204460492503131E-16;
      b = static_cast<real_T>(G.size(0)) * static_cast<real_T>(G.size(0));
    }

    for (int32_T j{0}; j < i; j++) {
      real_T b_a;
      int32_T i2;
      if (j < 1) {
        bb.set_size(1, 0);
      } else {
        bb.set_size(1, j);
        loop_ub = j - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          bb[i1] = static_cast<real_T>(i1) + 1.0;
        }
      }

      if (static_cast<uint32_T>(n) < j + 2U) {
        ee.set_size(1, 0);
      } else {
        i1 = n - j;
        ee.set_size(1, i1 - 1);
        loop_ub = i1 - 2;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          ee[i1] = (static_cast<uint32_T>(j) + i1) + 2U;
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

        b_G.set_size(varargin_1_tmp.size(0), varargin_1_tmp.size(0));
        loop_ub = varargin_1_tmp.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = varargin_1_tmp.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            b_G[i2 + b_G.size(0) * i1] = D[(static_cast<int32_T>
              (varargin_1_tmp[i2]) + D.size(0) * (static_cast<int32_T>
              (varargin_1_tmp[i1]) - 1)) - 1];
          }
        }

        coder::diag(b_G, b_C);
        loop_ub = varargin_1_tmp.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = static_cast<int32_T>(varargin_1_tmp[i1]) - 1;
          L[j + L.size(0) * b_loop_ub] = C[j + C.size(0) * b_loop_ub] / b_C[i1];
        }
      }

      //
      //   Update the jth column of C.
      //
      if (j + 1 >= 2) {
        if (j + 1 < n) {
          r.set_size(ee.size(1), bb.size(1));
          loop_ub = bb.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = ee.size(1);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r[i2 + r.size(0) * i1] = C[(static_cast<int32_T>(ee[i2]) + C.size
                (0) * (static_cast<int32_T>(bb[i1]) - 1)) - 1];
            }
          }

          varargin_1_tmp.set_size(ee.size(1));
          loop_ub = ee.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            varargin_1_tmp[i1] = ee[i1];
          }

          a.set_size(1, bb.size(1));
          loop_ub = bb.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            a[i1] = L[j + L.size(0) * (static_cast<int32_T>(bb[i1]) - 1)];
          }

          coder::internal::blas::mtimes(a, r, y);
          loop_ub = varargin_1_tmp.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = static_cast<int32_T>(varargin_1_tmp[i1]) - 1;
            C[b_loop_ub + C.size(0) * j] = G[b_loop_ub + G.size(0) * j] - y[i1];
          }
        }
      } else {
        varargin_1_tmp.set_size(ee.size(1));
        loop_ub = ee.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          varargin_1_tmp[i1] = ee[i1];
        }

        loop_ub = varargin_1_tmp.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = static_cast<int32_T>(varargin_1_tmp[i1]) - 1;
          C[b_loop_ub] = G[b_loop_ub];
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
          b_C[i1] = C[(static_cast<int32_T>(ee[i1]) + C.size(0) * j) - 1];
        }

        coder::b_abs(b_C, varargin_1_tmp);
        theta[j] = coder::internal::maximum(varargin_1_tmp);
      }

      //
      //   Update D
      //
      dv2[1] = std::abs(C[j + C.size(0) * j]);
      dv2[2] = theta[j] * theta[j] / beta2;
      D[j + D.size(0) * j] = coder::internal::b_maximum(dv2);

      //
      //  Update E.
      //
      //
      //   Update C again...
      //
      // %%%%%%% M.Zibulevsky: begin of changes, old version is commented %%%%%%%%%%%%%
      // for i=j+1:n,
      //     C(i,i)=C(i,i)-C(i,j)^2/D(j,j);
      // end;
      b_a = (static_cast<real_T>(j) + 1.0) * (static_cast<real_T>(n) + 1.0) +
        1.0;
      if (b < b_a) {
        y.set_size(1, 0);
      } else if (b_a == b_a) {
        loop_ub = static_cast<int32_T>(std::floor((b - b_a) /
          (static_cast<real_T>(n) + 1.0)));
        y.set_size(1, loop_ub + 1);
        for (i1 = 0; i1 <= loop_ub; i1++) {
          y[i1] = b_a + (static_cast<real_T>(n) + 1.0) * static_cast<real_T>(i1);
        }
      } else {
        coder::eml_float_colon(b_a, static_cast<real_T>(n) + 1.0, b, y);
      }

      ind.set_size(y.size(1));
      loop_ub = y.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        ind[i1] = y[i1];
      }

      b_a = 1.0 / D[j + D.size(0) * j];
      b_C.set_size(ee.size(1));
      loop_ub = ee.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_C[i1] = C[(static_cast<int32_T>(ee[i1]) + C.size(0) * j) - 1];
      }

      coder::power(b_C, varargin_1_tmp);
      b_C.set_size(ind.size(0));
      loop_ub = ind.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_C[i1] = C[static_cast<int32_T>(ind[i1]) - 1] - b_a * varargin_1_tmp[i1];
      }

      loop_ub = b_C.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        C[static_cast<int32_T>(ind[i1]) - 1] = b_C[i1];
      }
    }

    //
    //  Put 1's on the diagonal of L
    //
    // for j=1:n,
    //     L(j,j)=1;
    // end;
    b = static_cast<real_T>(G.size(0)) * static_cast<real_T>(G.size(0));
    if (b < 1.0) {
      y.set_size(1, 0);
    } else {
      y.set_size(1, static_cast<int32_T>(std::floor((b - 1.0) /
        (static_cast<real_T>(G.size(0)) + 1.0))) + 1);
      loop_ub = static_cast<int32_T>(std::floor((b - 1.0) / (static_cast<real_T>
        (G.size(0)) + 1.0)));
      for (i = 0; i <= loop_ub; i++) {
        y[i] = (static_cast<real_T>(G.size(0)) + 1.0) * static_cast<real_T>(i) +
          1.0;
      }
    }

    r1.set_size(y.size(1));
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      r1[i] = static_cast<int32_T>(y[i]);
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
