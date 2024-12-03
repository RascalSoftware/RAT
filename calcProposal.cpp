//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "find.h"
#include "rand.h"
#include "randn.h"
#include "randperm.h"
#include "randsample.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void calcProposal(const ::coder::array<real_T, 2U> &X, real_T CR_data[], const
                    struct12_T *DREAMPar, const ::coder::array<real_T, 2U>
                    &Table_gamma, const ::coder::array<real_T, 2U>
                    &paramInfo_min, const ::coder::array<real_T, 2U>
                    &paramInfo_max, const char_T paramInfo_boundhandling_data[],
                    const int32_T paramInfo_boundhandling_size[2], ::coder::
                    array<real_T, 2U> &x_new)
  {
    ::coder::array<real_T, 2U> A;
    ::coder::array<real_T, 2U> a;
    ::coder::array<real_T, 2U> b;
    ::coder::array<real_T, 2U> b_b;
    ::coder::array<real_T, 2U> b_gamma;
    ::coder::array<real_T, 2U> dx;
    ::coder::array<real_T, 2U> eps;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::array<real_T, 2U> r4;
    ::coder::array<real_T, 2U> r5;
    ::coder::array<real_T, 2U> r6;
    ::coder::array<real_T, 2U> rnd_cr;
    ::coder::array<real_T, 2U> rnd_jump;
    ::coder::array<real_T, 1U> DE_pairs;
    ::coder::array<real_T, 1U> r3;
    ::coder::array<int32_T, 2U> iidx;
    ::coder::array<int32_T, 2U> r2;
    ::coder::array<boolean_T, 2U> b_rnd_cr;
    real_T r2_data[6];
    real_T r1_data[3];
    real_T tmp_data[3];
    real_T b_dv[2];
    int32_T b_loop_ub;
    int32_T b_loop_ub_tmp;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T loop_ub_tmp;

    //  Calculate candidate points using discrete proposal distribution
    //  % % % Calculate the ergodicity perturbation
    //  % % eps = DREAMPar.zeta * randn(DREAMPar.nChains,DREAMPar.nParams);
    //  % %
    //  % % % Determine which sequences to evolve with what DE strategy
    //  % % DE_pairs = randsample( [1:DREAMPar.delta ] , DREAMPar.nChains , true , [ 1/DREAMPar.delta*ones(1,DREAMPar.delta) ])';
    //  % %
    //  % % % Generate series of permutations of chains
    //  % % [dummy,tt] = sort(rand(DREAMPar.nChains-1,DREAMPar.nChains));
    //  % %
    //  % % % Generate uniform random numbers for each chain to determine which dimension to update
    //  % % D = rand(DREAMPar.nChains,DREAMPar.nParams);
    //  % %
    //  % % % Ergodicity for each individual chain
    //  % % noise_x = DREAMPar.jumpProbability * (2 * rand(DREAMPar.nChains,DREAMPar.nParams) - 1);
    //  % %
    //  % % % Initialize the delta update to zero
    //  % % delta_x = zeros(DREAMPar.nChains,DREAMPar.nParams);
    //  % %
    //  % % % Each chain evolves using information from other chains to create offspring
    //  % % for qq = 1:DREAMPar.nChains,
    //  % %
    //  % %     % Define ii and remove current member as an option
    //  % %     ii = ones(DREAMPar.nChains,1); ii(qq) = 0; idx = find(ii > 0);
    //  % %
    //  % %     % randomly select two members of ii that have value == 1
    //  % %     rr = idx(tt(1:2*DE_pairs(qq,1),qq));
    //  % %
    //  % %     % --- WHICH DIMENSIONS TO UPDATE? DO SOMETHING WITH CROSSOVER ----
    //  % %     [i] = find(D(qq,1:DREAMPar.nParams) > (1-CR(qq,1)));
    //  % %
    //  % %     % Update at least one dimension
    //  % %     if isempty(i), i = randperm(DREAMPar.nParams); i = i(1); end;
    //  % %     % ----------------------------------------------------------------
    //  % %
    //  % %     % Determine the associated JumpRate and compute the jump
    //  % %     if (rand < (1 - DREAMPar.pJumpRate_one)),
    //  % %
    //  % %         %         % Now determine gamma, the jump factor
    //  % %         %         if ~DREAMPar.ABC
    //  % %         %
    //  % %         % Select the JumpRate (dependent of NrDim and number of pairs)
    //  % %         NrDim = size(i,2); JumpRate = Table_gamma(NrDim,DE_pairs(qq,1));
    //  % %
    //  % %         %           else
    //  % %         %
    //  % %         %                 % Turner (2012) paper -- CU[0.5,1] but needs scaling if
    //  % %         %                 % more than 1 pair is used!
    //  % %         %                 JumpRate = (0.5 + rand/2) * sqrt(1/DREAMPar.delta);
    //  % %
    //  % %         %        end;
    //  % %
    //  % %         % Produce the difference of the pairs used for population evolution
    //  % %         delta = sum(X(rr(1:DE_pairs(qq,1)),1:DREAMPar.nParams) - X(rr(DE_pairs(qq,1)+1:2*DE_pairs(qq,1)),1:DREAMPar.nParams),1);
    //  % %
    //  % %         % Then fill update the dimension
    //  % %         delta_x(qq,i) = (1 + noise_x(qq,i)) * JumpRate.*delta(1,i);
    //  % %
    //  % %     else
    //  % %
    //  % %         % Set the JumpRate to 1 and overwrite CR and DE_pairs
    //  % %         JumpRate = 1; CR(qq,1) = -1;
    //  % %
    //  % %         % Compute delta from one pair
    //  % %         delta = X(rr(1),1:DREAMPar.nParams) - X(rr(2),1:DREAMPar.nParams);
    //  % %
    //  % %         % Now jumprate to facilitate jumping from one mode to the other in all dimensions
    //  % %         delta_x(qq,1:DREAMPar.nParams) = JumpRate * delta;
    //  % %
    //  % %     end;
    //  % %
    //  % %     % Check this line to avoid that jump = 0 and x_new is similar to X
    //  % %     if (sum(delta_x(qq,1:DREAMPar.nParams).^2,2) == 0),
    //  % %
    //  % %         % Compute the Cholesky Decomposition of X
    //  % %         R = (2.38/sqrt(DREAMPar.nParams)) * chol(cov(X(1:end,1:DREAMPar.nParams)) + 1e-5*eye(DREAMPar.nParams));
    //  % %
    //  % %         % Generate jump using multinormal distribution
    //  % %         delta_x(qq,1:DREAMPar.nParams) = randn(1,DREAMPar.nParams) * R;
    //  % %         disp('hello');
    //  % %     end;
    //  % %
    //  % % end;
    //  % %
    //  % % % Generate candidate points by perturbing the current X values with jump and eps
    //  % % x_new = X + delta_x + eps;
    //  % %
    //  % % % If specified do boundary handling ( "Bound","Reflect","Fold")
    //  % % if isfield(paramInfo,'boundhandling'),
    //  % %     [x_new] = BoundaryHandling(x_new,paramInfo,paramInfo.boundhandling);
    //  % % end;
    //  % %
    //  ##################################################
    //  Calculate the ergodicity perturbation
    coder::randn(DREAMPar->nChains, DREAMPar->nParams, b);
    eps.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        eps[i1 + eps.size(0) * i] = 1.0E-12 * b[i1 + b.size(0) * i];
      }
    }

    //  Determine how many chain pairs to use for each individual chain
    r.set_size(1, 3);
    r[0] = 1.0;
    tmp_data[0] = 0.33333333333333331;
    r[1] = 2.0;
    tmp_data[1] = 0.33333333333333331;
    r[2] = 3.0;
    tmp_data[2] = 0.33333333333333331;
    coder::randsample((const real_T *)r.data(), DREAMPar->nChains, tmp_data, r1);
    DE_pairs.set_size(r1.size(1));
    loop_ub = r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      DE_pairs[i] = r1[i];
    }

    //  Generate uniform random numbers for each chain to determine which dimension to update
    coder::b_rand(DREAMPar->nChains, DREAMPar->nParams, rnd_cr);

    //  Ergodicity for each individual chain
    coder::b_rand(DREAMPar->nChains, DREAMPar->nParams, b);
    rnd_jump.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        rnd_jump[i1 + rnd_jump.size(0) * i] = DREAMPar->jumpProbability * (2.0 *
          b[i1 + b.size(0) * i] - 1.0);
      }
    }

    // rnd_jump = DREAMPar.jumpProbability * (2 * rand(DREAMPar.nChains,1) - 1);
    //  Randomly permute numbers [1,...,N-1] N times
    coder::b_rand(DREAMPar->nChains - 1.0, DREAMPar->nChains, b);
    coder::internal::b_sort(b, iidx);

    //  Set jump vectors equal to zero
    loop_ub_tmp = static_cast<int32_T>(DREAMPar->nChains);
    b_loop_ub_tmp = static_cast<int32_T>(DREAMPar->nParams);
    dx.set_size(loop_ub_tmp, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        dx[i1 + dx.size(0) * i] = 0.0;
      }
    }

    //  Determine when jumprate is 1
    b_dv[0] = 1.0 - DREAMPar->pUnitGamma;
    b_dv[1] = DREAMPar->pUnitGamma;
    coder::randsample(DREAMPar->nChains, b_dv, b_gamma);

    //  Create N proposals
    for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
      real_T CR;
      int32_T D;

      //  Derive vector r1
      b_loop_ub_tmp = static_cast<int32_T>(DE_pairs[b_i]);
      for (i = 0; i < b_loop_ub_tmp; i++) {
        r1_data[i] = DREAMPar->R[b_i + DREAMPar->R.size(0) * (iidx[i + iidx.size
          (0) * b_i] - 1)];
      }

      //  Derive vector r2
      CR = 2.0 * DE_pairs[b_i];
      if (DE_pairs[b_i] + 1.0 > CR) {
        i = 0;
        i1 = 0;
      } else {
        i = static_cast<int32_T>(DE_pairs[b_i] + 1.0) - 1;
        i1 = static_cast<int32_T>(CR);
      }

      loop_ub = i1 - i;
      for (i1 = 0; i1 < loop_ub; i1++) {
        r2_data[i1] = DREAMPar->R[b_i + DREAMPar->R.size(0) * (iidx[(i + i1) +
          iidx.size(0) * b_i] - 1)];
      }

      //  Derive subset A with dimensions to sample
      if (1.0 > DREAMPar->nParams) {
        b_loop_ub = 0;
      } else {
        b_loop_ub = static_cast<int32_T>(DREAMPar->nParams);
      }

      CR = CR_data[b_i];
      b_rnd_cr.set_size(1, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        b_rnd_cr[i] = (rnd_cr[b_i + rnd_cr.size(0) * i] < CR);
      }

      coder::g_eml_find(b_rnd_cr, r2);
      A.set_size(1, r2.size(1));
      b_loop_ub = r2.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        A[i] = r2[i];
      }

      //  How many dimensions are sampled?
      D = A.size(1);

      //  Make sure that at least one dimension is selected!
      if (A.size(1) == 0) {
        coder::randperm(DREAMPar->nParams, a);
        A.set_size(1, 1);
        A[0] = a[0];
        D = 1;
      }

      //  Which gamma to use?
      if (b_gamma[b_i] == 1.0) {
        int32_T c_loop_ub;
        int32_T d_loop_ub;

        //  Calculate direct jump
        if (1.0 > DREAMPar->nParams) {
          b_loop_ub = 0;
          c_loop_ub = 0;
          d_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar->nParams);
          c_loop_ub = static_cast<int32_T>(DREAMPar->nParams);
          d_loop_ub = static_cast<int32_T>(DREAMPar->nParams);
        }

        b.set_size(b_loop_ub_tmp, c_loop_ub);
        for (i = 0; i < c_loop_ub; i++) {
          for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
            b[i1 + b.size(0) * i] = X[(static_cast<int32_T>(r1_data[i1]) +
              X.size(0) * i) - 1];
          }
        }

        r5.set_size(loop_ub, d_loop_ub);
        for (i = 0; i < d_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r5[i1 + r5.size(0) * i] = X[(static_cast<int32_T>(r2_data[i1]) +
              X.size(0) * i) - 1];
          }
        }

        b_b.set_size(b.size(0), b.size(1));
        loop_ub = b.size(1);
        for (i = 0; i < loop_ub; i++) {
          c_loop_ub = b.size(0);
          for (i1 = 0; i1 < c_loop_ub; i1++) {
            b_b[i1 + b_b.size(0) * i] = b[i1 + b.size(0) * i] - r5[i1 + r5.size
              (0) * i];
          }
        }

        coder::blockedSummation(b_b, b_loop_ub_tmp, r1);
        for (i = 0; i < b_loop_ub; i++) {
          dx[b_i + dx.size(0) * i] = (rnd_jump[b_i + rnd_jump.size(0) * i] + 1.0)
            * r1[i] + eps[b_i + eps.size(0) * i];
        }

        //  Set CR to -1 so that this jump does not count for calculation of pCR
        CR_data[b_i] = -1.0;
      } else {
        real_T gamma_D;

        //  Unpack jump rate
        gamma_D = Table_gamma[(D + Table_gamma.size(0) * (b_loop_ub_tmp - 1)) -
          1];

        //  Calculate jump
        r3.set_size(A.size(1));
        b_loop_ub = A.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          r3[i] = A[i];
        }

        r4.set_size(b_loop_ub_tmp, r3.size(0));
        b_loop_ub = r3.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
            r4[i1 + r4.size(0) * i] = X[(static_cast<int32_T>(r1_data[i1]) +
              X.size(0) * (static_cast<int32_T>(r3[i]) - 1)) - 1];
          }
        }

        r6.set_size(loop_ub, r3.size(0));
        b_loop_ub = r3.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r6[i1 + r6.size(0) * i] = X[(static_cast<int32_T>(r2_data[i1]) +
              X.size(0) * (static_cast<int32_T>(r3[i]) - 1)) - 1];
          }
        }

        b_b.set_size(r4.size(0), r4.size(1));
        loop_ub = r4.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = r4.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            b_b[i1 + b_b.size(0) * i] = r4[i1 + r4.size(0) * i] - r6[i1 +
              r6.size(0) * i];
          }
        }

        coder::blockedSummation(b_b, b_loop_ub_tmp, r1);
        loop_ub = r3.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int32_T>(r3[i]) - 1;
          dx[b_i + dx.size(0) * b_loop_ub] = (rnd_jump[b_i + rnd_jump.size(0) *
            b_loop_ub] + 1.0) * gamma_D * r1[i] + eps[b_i + eps.size(0) *
            b_loop_ub];
        }
      }
    }

    //  Generate candidate points by perturbing the current X values with jump and eps
    //  If specified do boundary handling ( "Bound","Reflect","Fold")
    b.set_size(X.size(0), X.size(1));
    loop_ub = X.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = X.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b[i1 + b.size(0) * i] = X[i1 + X.size(0) * i] + dx[i1 + dx.size(0) * i];
      }
    }

    boundaryHandling(b, paramInfo_min, paramInfo_max,
                     paramInfo_boundhandling_data, paramInfo_boundhandling_size);
    x_new.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        x_new[i1 + x_new.size(0) * i] = b[i1 + b.size(0) * i];
      }
    }
  }
}

// End of code generation (calcProposal.cpp)
