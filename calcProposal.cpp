//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcProposal.cpp
//
// Code generation for function 'calcProposal'
//

// Include files
#include "calcProposal.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "boundaryHandling.h"
#include "combineVectorElements.h"
#include "find.h"
#include "rand.h"
#include "randSample.h"
#include "randn.h"
#include "randperm.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, const ::
    coder::array<int, 1U> &in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 1U> &in5, double in6, const ::coder::array<double, 2U>
    &in7, const ::coder::array<double, 2U> &in8);
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, int in3,
    const ::coder::array<double, 2U> &in4, int in5, const ::coder::array<double,
    2U> &in6, const ::coder::array<double, 2U> &in7, int in8);
  static void plus(::coder::array<double, 2U> &in1, const ::coder::array<double,
                   2U> &in2, const ::coder::array<double, 2U> &in3);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, const ::
    coder::array<int, 1U> &in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 1U> &in5, double in6, const ::coder::array<double, 2U>
    &in7, const ::coder::array<double, 2U> &in8)
  {
    int loop_ub;
    int stride_0_1_tmp;
    int stride_1_1;
    stride_0_1_tmp = (in5.size(0) != 1);
    stride_1_1 = (in7.size(1) != 1);
    loop_ub = in3.size(0);
    for (int i{0}; i < loop_ub; i++) {
      int i1;
      i1 = static_cast<int>(in5[i * stride_0_1_tmp]) - 1;
      in1[in2 + in1.size(0) * in3[i]] = (in4[in2 + in4.size(0) * i1] + 1.0) *
        in6 * in7[i * stride_1_1] + in8[in2 + in8.size(0) * i1];
    }
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, int in3,
    const ::coder::array<double, 2U> &in4, int in5, const ::coder::array<double,
    2U> &in6, const ::coder::array<double, 2U> &in7, int in8)
  {
    int stride_0_1;
    int stride_1_1;
    int stride_2_1;
    stride_0_1 = (in5 + 1 != 1);
    stride_1_1 = (in6.size(1) != 1);
    stride_2_1 = (in8 + 1 != 1);
    for (int i{0}; i < in3; i++) {
      in1[in2 + in1.size(0) * i] = (in4[in2 + in4.size(0) * (i * stride_0_1)] +
        1.0) * in6[i * stride_1_1] + in7[in2 + in7.size(0) * (i * stride_2_1)];
    }
  }

  static void plus(::coder::array<double, 2U> &in1, const ::coder::array<double,
                   2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int aux_0_1;
    int aux_1_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in3.size(1) == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = in3.size(1);
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          + in3[i1 * stride_1_0 + in3.size(0) * aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  void calcProposal(const ::coder::array<double, 2U> &X, double CR_data[], const
                    DreamParams &DREAMPar, const ::coder::array<double, 2U>
                    &Table_gamma, const ::coder::array<double, 2U>
                    &paramInfo_min, const ::coder::array<double, 2U>
                    &paramInfo_max, const char paramInfo_boundhandling_data[],
                    const int paramInfo_boundhandling_size[2], ::coder::array<
                    double, 2U> &x_new)
  {
    ::coder::array<double, 2U> A;
    ::coder::array<double, 2U> a;
    ::coder::array<double, 2U> b;
    ::coder::array<double, 2U> b_gamma;
    ::coder::array<double, 2U> dx;
    ::coder::array<double, 2U> eps;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r4;
    ::coder::array<double, 2U> r5;
    ::coder::array<double, 2U> r6;
    ::coder::array<double, 2U> rnd_cr;
    ::coder::array<double, 2U> rnd_jump;
    ::coder::array<double, 1U> DE_pairs;
    ::coder::array<double, 1U> r3;
    ::coder::array<int, 2U> draw;
    ::coder::array<int, 2U> r2;
    ::coder::array<int, 1U> r7;
    ::coder::array<boolean_T, 2U> b_rnd_cr;
    int b_loop_ub;
    int b_loop_ub_tmp;
    int i;
    int i1;
    int loop_ub;
    int loop_ub_tmp;

    //  Calculate candidate points using discrete proposal distribution.
    //
    //  Parameters
    //  ----------
    //  X : array
    //      The current position of each chain.
    //  CR : array
    //      The crossover values for each parameter.
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //  Table_gamma : array
    //      The DE jump length values for each parameter.
    //  paramInfo : struct
    //      Prior, bound, and boundary handling information for each parameter.
    //
    //  Returns
    //  -------
    //  x_new : array
    //      The new points in parameter space.
    //  CR : array
    //      The new crossover values for each parameter.
    //  Calculate the ergodicity perturbation
    coder::randn(DREAMPar.nChains, DREAMPar.nParams, b);
    eps.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        eps[i1 + eps.size(0) * i] = 1.0E-12 * b[i1 + b.size(0) * i];
      }
    }

    double tmp_data[3];
    int iv[2];

    //  Determine how many chain pairs to use for each individual chain
    r.set_size(1, 3);
    r[0] = 1.0;
    tmp_data[0] = 0.33333333333333331;
    r[1] = 2.0;
    tmp_data[1] = 0.33333333333333331;
    r[2] = 3.0;
    tmp_data[2] = 0.33333333333333331;
    r.reserve(3);
    iv[0] = (*(int (*)[2])r.size())[0];
    iv[1] = (*(int (*)[2])r.size())[1];
    randSample((double *)r.data(), iv, DREAMPar.nChains, tmp_data, r1);
    DE_pairs.set_size(r1.size(1));
    loop_ub = r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      DE_pairs[i] = r1[i];
    }

    //  Generate uniform random numbers for each chain to determine which dimension to update
    coder::b_rand(DREAMPar.nChains, DREAMPar.nParams, rnd_cr);

    //  Ergodicity for each individual chain
    coder::b_rand(DREAMPar.nChains, DREAMPar.nParams, b);
    rnd_jump.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        rnd_jump[i1 + rnd_jump.size(0) * i] = DREAMPar.jumpProbability * (2.0 *
          b[i1 + b.size(0) * i] - 1.0);
      }
    }

    // rnd_jump = DREAMPar.jumpProbability * (2 * rand(DREAMPar.nChains,1) - 1);
    //  Randomly permute numbers [1,...,N-1] N times
    coder::b_rand(DREAMPar.nChains - 1.0, DREAMPar.nChains, b);
    coder::internal::sort(b, draw);

    //  Set jump vectors equal to zero
    loop_ub_tmp = static_cast<int>(DREAMPar.nChains);
    b_loop_ub_tmp = static_cast<int>(DREAMPar.nParams);
    dx.set_size(loop_ub_tmp, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        dx[i1 + dx.size(0) * i] = 0.0;
      }
    }

    double b_dv[2];

    //  Determine when jumprate is 1
    b_dv[0] = 1.0 - DREAMPar.pUnitGamma;
    b_dv[1] = DREAMPar.pUnitGamma;
    randSample(DREAMPar.nChains, b_dv, b_gamma);

    //  Create N proposals
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      double r2_data[6];
      double r1_data[3];
      double CR;
      int D;
      int c_loop_ub;
      int c_loop_ub_tmp;

      //  Derive vector r1
      b_loop_ub_tmp = static_cast<int>(DE_pairs[b_i]);
      for (i = 0; i < b_loop_ub_tmp; i++) {
        r1_data[i] = DREAMPar.R[b_i + DREAMPar.R.size(0) * (draw[i + draw.size(0)
          * b_i] - 1)];
      }

      //  Derive vector r2
      CR = 2.0 * DE_pairs[b_i];
      if (DE_pairs[b_i] + 1.0 > CR) {
        i = 0;
        i1 = 0;
      } else {
        i = static_cast<int>(DE_pairs[b_i] + 1.0) - 1;
        i1 = static_cast<int>(CR);
      }

      loop_ub = i1 - i;
      for (c_loop_ub = 0; c_loop_ub < loop_ub; c_loop_ub++) {
        r2_data[c_loop_ub] = DREAMPar.R[b_i + DREAMPar.R.size(0) * (draw[(i +
          c_loop_ub) + draw.size(0) * b_i] - 1)];
      }

      //  Derive subset A with dimensions to sample
      if (DREAMPar.nParams < 1.0) {
        c_loop_ub_tmp = 0;
      } else {
        c_loop_ub_tmp = static_cast<int>(DREAMPar.nParams);
      }

      CR = CR_data[b_i];
      b_rnd_cr.set_size(1, c_loop_ub_tmp);
      for (c_loop_ub = 0; c_loop_ub < c_loop_ub_tmp; c_loop_ub++) {
        b_rnd_cr[c_loop_ub] = (rnd_cr[b_i + rnd_cr.size(0) * c_loop_ub] < CR);
      }

      coder::g_eml_find(b_rnd_cr, r2);
      A.set_size(1, r2.size(1));
      b_loop_ub = r2.size(1);
      for (c_loop_ub = 0; c_loop_ub < b_loop_ub; c_loop_ub++) {
        A[c_loop_ub] = r2[c_loop_ub];
      }

      //  How many dimensions are sampled?
      D = A.size(1);

      //  Make sure that at least one dimension is selected!
      if (A.size(1) == 0) {
        coder::randperm(DREAMPar.nParams, a);
        A.set_size(1, 1);
        A[0] = a[0];
        D = 1;
      }

      //  Which gamma to use?
      if (b_gamma[b_i] == 1.0) {
        //  Calculate direct jump
        b.set_size(b_loop_ub_tmp, c_loop_ub_tmp);
        for (c_loop_ub = 0; c_loop_ub < c_loop_ub_tmp; c_loop_ub++) {
          for (int i2{0}; i2 < b_loop_ub_tmp; i2++) {
            b[i2 + b.size(0) * c_loop_ub] = X[(static_cast<int>(r1_data[i2]) +
              X.size(0) * c_loop_ub) - 1];
          }
        }

        r4.set_size(loop_ub, c_loop_ub_tmp);
        for (c_loop_ub = 0; c_loop_ub < c_loop_ub_tmp; c_loop_ub++) {
          for (int i2{0}; i2 < loop_ub; i2++) {
            r4[i2 + r4.size(0) * c_loop_ub] = X[(static_cast<int>(r2_data[i2]) +
              X.size(0) * c_loop_ub) - 1];
          }
        }

        if ((b.size(0) == r4.size(0)) && (b.size(1) == r4.size(1))) {
          b_loop_ub = b.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            c_loop_ub = b.size(0);
            for (i1 = 0; i1 < c_loop_ub; i1++) {
              b[i1 + b.size(0) * i] = b[i1 + b.size(0) * i] - r4[i1 + r4.size(0)
                * i];
            }
          }

          if (b_loop_ub_tmp == 1) {
            b_loop_ub_tmp = loop_ub;
          }

          coder::blockedSummation(b, b_loop_ub_tmp, r1);
        } else {
          binary_expand_op(r1, b, r4, DE_pairs, b_i, i1, i);
        }

        if (c_loop_ub_tmp == 1) {
          i = r1.size(1);
        } else {
          i = c_loop_ub_tmp;
        }

        if ((c_loop_ub_tmp == r1.size(1)) && (i == c_loop_ub_tmp)) {
          for (i = 0; i < c_loop_ub_tmp; i++) {
            dx[b_i + dx.size(0) * i] = (rnd_jump[b_i + rnd_jump.size(0) * i] +
              1.0) * r1[i] + eps[b_i + eps.size(0) * i];
          }
        } else {
          binary_expand_op(dx, b_i, c_loop_ub_tmp, rnd_jump, c_loop_ub_tmp - 1,
                           r1, eps, c_loop_ub_tmp - 1);
        }

        //  Set CR to -1 so that this jump does not count for calculation of pCR
        CR_data[b_i] = -1.0;
      } else {
        double gamma_D;

        //  Unpack jump rate
        gamma_D = Table_gamma[(D + Table_gamma.size(0) * (b_loop_ub_tmp - 1)) -
          1];

        //  Calculate jump
        r3.set_size(A.size(1));
        b_loop_ub = A.size(1);
        for (c_loop_ub = 0; c_loop_ub < b_loop_ub; c_loop_ub++) {
          r3[c_loop_ub] = A[c_loop_ub];
        }

        r5.set_size(b_loop_ub_tmp, r3.size(0));
        b_loop_ub = r3.size(0);
        r6.set_size(loop_ub, r3.size(0));
        r7.set_size(r3.size(0));
        for (c_loop_ub = 0; c_loop_ub < b_loop_ub; c_loop_ub++) {
          for (int i2{0}; i2 < b_loop_ub_tmp; i2++) {
            r5[i2 + r5.size(0) * c_loop_ub] = X[(static_cast<int>(r1_data[i2]) +
              X.size(0) * (static_cast<int>(r3[c_loop_ub]) - 1)) - 1];
          }

          for (int i2{0}; i2 < loop_ub; i2++) {
            r6[i2 + r6.size(0) * c_loop_ub] = X[(static_cast<int>(r2_data[i2]) +
              X.size(0) * (static_cast<int>(r3[c_loop_ub]) - 1)) - 1];
          }

          r7[c_loop_ub] = static_cast<int>(r3[c_loop_ub]) - 1;
        }

        if (r5.size(0) == r6.size(0)) {
          r4.set_size(r5.size(0), r5.size(1));
          b_loop_ub = r5.size(1);
          c_loop_ub = r5.size(0);
          for (i = 0; i < b_loop_ub; i++) {
            for (i1 = 0; i1 < c_loop_ub; i1++) {
              r4[i1 + r4.size(0) * i] = r5[i1 + r5.size(0) * i] - r6[i1 +
                r6.size(0) * i];
            }
          }

          if (b_loop_ub_tmp == 1) {
            b_loop_ub_tmp = loop_ub;
          }

          coder::blockedSummation(r4, b_loop_ub_tmp, r1);
        } else {
          c_binary_expand_op(r1, r5, r6, DE_pairs, b_i, i1, i);
        }

        if (r3.size(0) == 1) {
          i = r1.size(1);
        } else {
          i = r3.size(0);
        }

        if ((r3.size(0) == r1.size(1)) && (i == r3.size(0))) {
          loop_ub = r7.size(0);
          for (i = 0; i < loop_ub; i++) {
            c_loop_ub = static_cast<int>(r3[i]) - 1;
            dx[b_i + dx.size(0) * r7[i]] = (rnd_jump[b_i + rnd_jump.size(0) *
              c_loop_ub] + 1.0) * gamma_D * r1[i] + eps[b_i + eps.size(0) *
              c_loop_ub];
          }
        } else {
          binary_expand_op(dx, b_i, r7, rnd_jump, r3, gamma_D, r1, eps);
        }
      }
    }

    //  Generate candidate points by perturbing the current X values with jump and eps
    //  If specified do boundary handling ( "Bound","Reflect","Fold")
    if ((X.size(0) == dx.size(0)) && (X.size(1) == dx.size(1))) {
      x_new.set_size(X.size(0), X.size(1));
      loop_ub = X.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = X.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          x_new[i1 + x_new.size(0) * i] = X[i1 + X.size(0) * i] + dx[i1 +
            dx.size(0) * i];
        }
      }
    } else {
      plus(x_new, X, dx);
    }

    boundaryHandling(x_new, paramInfo_min, paramInfo_max,
                     paramInfo_boundhandling_data, paramInfo_boundhandling_size);
  }
}

// End of code generation (calcProposal.cpp)
