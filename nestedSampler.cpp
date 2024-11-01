//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nestedSampler.cpp
//
// Code generation for function 'nestedSampler'
//

// Include files
#include "nestedSampler.h"
#include "RATMain_data.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "cov.h"
#include "drawMCMC.h"
#include "drawMultiNest.h"
#include "ifWhileCond.h"
#include "isRATStopped.h"
#include "length.h"
#include "logPlus.h"
#include "mchol.h"
#include "minOrMax.h"
#include "mod.h"
#include "mrdivide_helper.h"
#include "mtimes.h"
#include "nest2pos.h"
#include "nonSingletonDim.h"
#include "nsIntraFun.h"
#include "optimalEllipsoids.h"
#include "power.h"
#include "rand.h"
#include "randn.h"
#include "rescaleParameters.h"
#include "rt_nonfinite.h"
#include "scaleParameters.h"
#include "sort.h"
#include "sprintf.h"
#include "sqrt1.h"
#include "strcmp.h"
#include "sum.h"
#include "triggerEvent.h"
#include "useConstantDim.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void nestedSampler(const d_struct_T *data_f1, const struct2_T *data_f2, const
                     struct1_T *data_f3, const cell_12 *data_f4, real_T nLive,
                     real_T nMCMC, real_T tolerance, const ::coder::array<real_T,
                     2U> &prior, real_T *logZ, ::coder::array<real_T, 2U>
                     &nest_samples, ::coder::array<real_T, 2U> &post_samples,
                     real_T *H)
  {
    ::coder::array<real_T, 2U> Bs;
    ::coder::array<real_T, 2U> FS;
    ::coder::array<real_T, 2U> VEs;
    ::coder::array<real_T, 2U> Vtot;
    ::coder::array<real_T, 2U> b_Bs;
    ::coder::array<real_T, 2U> b_livepoints;
    ::coder::array<real_T, 2U> b_nest_samples;
    ::coder::array<real_T, 2U> b_ns;
    ::coder::array<real_T, 2U> cholmat;
    ::coder::array<real_T, 2U> l;
    ::coder::array<real_T, 2U> livepoints;
    ::coder::array<real_T, 2U> livepoints_sorted;
    ::coder::array<real_T, 2U> mus;
    ::coder::array<real_T, 2U> nest_samples_data;
    ::coder::array<real_T, 2U> ns;
    ::coder::array<real_T, 2U> r2;
    ::coder::array<real_T, 2U> result;
    ::coder::array<real_T, 2U> toAdd;
    ::coder::array<real_T, 1U> b;
    ::coder::array<real_T, 1U> logL;
    ::coder::array<real_T, 1U> r;
    ::coder::array<real_T, 1U> r3;
    ::coder::array<int32_T, 1U> iidx;
    ::coder::array<char_T, 2U> r1;
    ::coder::array<boolean_T, 2U> b_FS;
    real_T b_nest_samples_data[49];
    real_T b_dv[2];
    real_T a;
    real_T a_tmp;
    real_T d;
    real_T j;
    real_T logLmax;
    real_T logLmin;
    real_T logw;
    real_T tol;
    int32_T D;
    int32_T K;
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T iindx;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    int32_T sizes_idx_1;
    int8_T b_sizes_idx_1;
    boolean_T empty_non_axis_sizes;
    boolean_T exitg1;
    boolean_T tmp_data;

    //  function [logZ, nest_samples, post_samples] = nestedSampler(data, ...
    //            nLive, nMCMC, tolerance, likelihood, model, prior, extraparams)
    //
    //  This function performs nested sampling of the likelihood function from
    //  the given prior (given a set of data, a model, and a set of extra model
    //  parameters).
    //
    //  If nMCMC > 0, new samples will be drawn from a proposal using an MCMC
    //  and differential evolution. The sampling will stop once the
    //  tolerance critereon has been reached. This method is that of Veitch &
    //  Vecchio.
    //
    //  If nMCMC = 0, new samples will be drawn from a set of bounding ellipsoids
    //  constructed using the MultiNest algorithm for partitioning live points.
    //
    //  The likelihood should be the function handle of a likelihood function to
    //  use. This should return the log likelihood of the model parameters given
    //  the data.
    //
    //  The model should be the function handle of the model function to be
    //  passed to the likelihood function.
    //
    //  ------------------- STRUCTURE OF PRIOR CHANGED FOR RAT ----------------
    //  The prior should be a cell array with each cell containing five values:
    //    parameter name (string)
    //    prior type (string) e.g. 'uniform', 'gaussian' of 'jeffreys'
    //    minimum value (for uniform prior), or mean value (for Gaussian prior)
    //    maximum value (for uniform prior), or width (for Gaussian prior)
    //    parameter behaviour (string):
    //        'reflect' - if the parameters reflect off the boundaries
    //        'cyclic'  - if the parameter space is cyclic
    //        'fixed'   - if the parameters have fixe boundaries
    //        ''        - for gaussian priors
    //    e.g., prior = {'h0', 'uniform', 0, 1, 'reflect';
    //                   'r', 'gaussian', 0, 5, '';
    //                   'phi', 'uniform', 0, 2*pi, 'cyclic'};
    //
    //  -----------------------------------------------------------------------
    //
    //  extraparams is a cell array of fixed extra parameters (in addition
    //  to those specified by prior) used by the model
    //  e.g.  extraparams = {'phi', 2;
    //                       'x', 4};
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  global verbose;
    //  verbose = 1;
    DEBUG = 0.0;

    //  get the number of parameters from the prior array
    ns.set_size(1, 1);
    ns[0] = 1.0;

    //  coder.varsize('ns');
    mus.set_size(1, 1);
    mus[0] = 1.0;

    //  coder.varsize('mus');
    cholmat.set_size(1, 1);
    cholmat[0] = 1.0;

    //  get the number of parameters from the prior array
    D = prior.size(0);

    //  initialise array of samples for posterior
    nest_samples.set_size(1, prior.size(0) + 1);
    loop_ub = prior.size(0) + 1;
    for (i = 0; i < loop_ub; i++) {
      nest_samples[nest_samples.size(0) * i] = 0.0;
    }

    //  check certain values are positive integers or zero
    //  draw the set of initial live points from the prior
    loop_ub_tmp = static_cast<int32_T>(nLive);
    livepoints.set_size(loop_ub_tmp, prior.size(0));
    loop_ub = prior.size(0);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        livepoints[i1 + livepoints.size(0) * i] = 0.0;
      }
    }

    i = prior.size(0);
    for (b_i = 0; b_i < i; b_i++) {
      real_T priortype;
      priortype = prior[b_i];
      if (priortype == 1.0) {
        real_T p3;

        // uniform
        p3 = prior[b_i + prior.size(0) * 3];
        a = prior[b_i + prior.size(0) * 4] - p3;
        coder::b_rand(nLive, b);
        loop_ub = b.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          livepoints[i1 + livepoints.size(0) * b_i] = p3 + a * b[i1];
        }
      } else if (priortype == 2.0) {
        real_T p3;

        // gaussian
        p3 = prior[b_i + prior.size(0)];
        a = prior[b_i + prior.size(0) * 2];
        coder::randn(nLive, b);
        loop_ub = b.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          livepoints[i1 + livepoints.size(0) * b_i] = p3 + a * b[i1];
        }
      } else if (priortype == 3.0) {
        // jeffreys
        a_tmp = std::log10(prior[b_i + prior.size(0)]);
        a = std::log10(prior[b_i + prior.size(0) * 2]) - a_tmp;
        coder::b_rand(nLive, b);
        loop_ub = b.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b[i1] = a_tmp + a * b[i1];
        }

        coder::b_power(b, r);
        loop_ub = r.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          livepoints[i1 + livepoints.size(0) * b_i] = r[i1];
        }
      }
    }

    //  calculate the log likelihood of all the live points
    logL.set_size(loop_ub_tmp);
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      // parvals = loopCell(livepoints(i,:));
      loop_ub = livepoints.size(1);
      b_livepoints.set_size(1, livepoints.size(1));
      for (i = 0; i < loop_ub; i++) {
        b_livepoints[i] = livepoints[b_i + livepoints.size(0) * i];
      }

      logL[b_i] = nsIntraFun(data_f1, data_f2, data_f3, data_f4, b_livepoints);
    }

    //  now scale the parameters, so that uniform parameters range from 0->1,
    //  and Gaussian parameters have a mean of zero and unit standard deviation
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      loop_ub = livepoints.size(1);
      b_livepoints.set_size(1, livepoints.size(1));
      for (i = 0; i < loop_ub; i++) {
        b_livepoints[i] = livepoints[b_i + livepoints.size(0) * i];
      }

      scaleParameters(prior, b_livepoints, b);
      loop_ub = livepoints.size(1);
      for (i = 0; i < loop_ub; i++) {
        livepoints[b_i + livepoints.size(0) * i] = b[i];
      }
    }

    //  initial tolerance
    tol = rtInf;

    //  initial width of prior volume (from X_0=1 to X_1=exp(-1/N))
    logw = std::log(1.0 - std::exp(-1.0 / nLive));

    //  initial log evidence (Z=0)
    *logZ = rtMinusInf;

    //  initial information
    *H = 0.0;

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  some initial values if MCMC nested sampling is used
    //  value to scale down the covariance matrix - CAN CHANGE THIS IF REQUIRED
    // %%%%%%%%%%%%%%
    //  some initial values if MultiNest sampling is used
    //  h values from bottom of p. 1605 of Feroz and Hobson
    FS.set_size(1, 1);
    FS[0] = 1.1;

    //  start FS at h, so ellipsoidal partitioning is done first time
    K = 1;

    //  start with one cluster of live points
    //  get maximum likelihood
    logLmax = coder::internal::maximum(logL);
    Bs.set_size(prior.size(0), prior.size(0));
    loop_ub = prior.size(0);
    for (i = 0; i < loop_ub; i++) {
      sizes_idx_1 = prior.size(0);
      for (i1 = 0; i1 < sizes_idx_1; i1++) {
        Bs[i1 + Bs.size(0) * i] = 0.0;
      }
    }

    VEs.set_size(prior.size(0), 1);
    loop_ub = prior.size(0);
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        VEs[i1] = 0.0;
      }
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  initialise iteration counter
    j = 1.0;

    //  MAIN LOOP
    exitg1 = false;
    while ((!exitg1) && ((tol > tolerance) || (j <= nLive))) {
      real_T VS;
      real_T logWt;
      real_T logZold;

      //  expected value of true remaining prior volume X
      VS = std::exp(-j / nLive);

      //  find minimum of likelihoods
      coder::internal::minimum(logL, &logLmin, &iindx);

      //  set the sample to the minimum value
      //  (Need to do some work brcause we are growing nest_samples in a loop)
      if (j == 1.0) {
        loop_ub = livepoints.size(1);
        for (i = 0; i < loop_ub; i++) {
          nest_samples[nest_samples.size(0) * i] = livepoints[(iindx +
            livepoints.size(0) * i) - 1];
        }

        nest_samples[nest_samples.size(0) * livepoints.size(1)] = logLmin;
      } else {
        loop_ub = livepoints.size(1);
        toAdd.set_size(1, livepoints.size(1) + 1);
        for (i = 0; i < loop_ub; i++) {
          toAdd[i] = livepoints[(iindx + livepoints.size(0) * i) - 1];
        }

        toAdd[livepoints.size(1)] = logLmin;
        if (nest_samples.size(1) != 0) {
          sizes_idx_1 = nest_samples.size(1);
        } else {
          sizes_idx_1 = toAdd.size(1);
        }

        if (nest_samples.size(1) != 0) {
          loop_ub = nest_samples.size(0);
        } else {
          loop_ub = 0;
        }

        if (nest_samples.size(1) != 0) {
          i = nest_samples.size(0);
        } else {
          i = 0;
        }

        b_nest_samples.set_size(i + 1, sizes_idx_1);
        for (i = 0; i < sizes_idx_1; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_nest_samples[i1 + b_nest_samples.size(0) * i] = nest_samples[i1 +
              loop_ub * i];
          }
        }

        for (i = 0; i < sizes_idx_1; i++) {
          for (i1 = 0; i1 < 1; i1++) {
            b_nest_samples[loop_ub + b_nest_samples.size(0) * i] = toAdd[i];
          }
        }

        nest_samples.set_size(b_nest_samples.size(0), b_nest_samples.size(1));
        loop_ub = b_nest_samples.size(1);
        for (i = 0; i < loop_ub; i++) {
          sizes_idx_1 = b_nest_samples.size(0);
          for (i1 = 0; i1 < sizes_idx_1; i1++) {
            nest_samples[i1 + nest_samples.size(0) * i] = b_nest_samples[i1 +
              b_nest_samples.size(0) * i];
          }
        }
      }

      //  get the log weight (Wt = L*w)
      logWt = logLmin + logw;

      //  save old evidence and information
      logZold = *logZ;

      //  update evidence, information, and width
      *logZ = logPlus(*logZ, logWt);
      if (std::isnan(*H)) {
        a_tmp = 0.0;
      } else {
        a_tmp = *H;
      }

      *H = (std::exp(logWt - *logZ) * logLmin + std::exp(logZold - *logZ) *
            (a_tmp + logZold)) - *logZ;

      // logw = logw - logt(nLive);
      logw -= 1.0 / nLive;

      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      if (nMCMC > 0.0) {
        //  do MCMC nested sampling
        //  get the Cholesky decomposed covariance of the live points
        //  (do every 100th iteration - CAN CHANGE THIS IF REQUIRED)
        if (coder::b_mod(j - 1.0) == 0.0) {
          //  NOTE that for numbers of parameters >~10 covariances are often
          //  not positive definite and cholcov will have "problems".
          // cholmat = cholcov(propscale*cov(livepoints));
          //  use modified Cholesky decomposition, which works even for
          //  matrices that are not quite positive definite
          //  from http://infohost.nmt.edu/~borchers/ldlt.html
          //  (via http://stats.stackexchange.com/questions/6364
          //  /making-square-root-of-covariance-matrix-positive-definite-matlab
          coder::cov(livepoints, result);
          b_Bs.set_size(result.size(0), result.size(1));
          loop_ub = result.size(1);
          for (i = 0; i < loop_ub; i++) {
            sizes_idx_1 = result.size(0);
            for (i1 = 0; i1 < sizes_idx_1; i1++) {
              b_Bs[i1 + b_Bs.size(0) * i] = 0.1 * result[i1 + result.size(0) * i];
            }
          }

          mchol(b_Bs, l, result);
          coder::b_sqrt(result);
          coder::internal::blas::b_mtimes(l, result, cholmat);

          // plot3(livepoints(:,1), livepoints(:,2), livepoints(:,3), 'r.');
          // drawnow();
        }

        //  draw a new sample using mcmc algorithm
        drawMCMC(livepoints, cholmat, logLmin, prior, data_f1, data_f2, data_f3,
                 data_f4, nMCMC, b_livepoints, &logL[iindx - 1]);
        loop_ub = b_livepoints.size(1);
        for (i = 0; i < loop_ub; i++) {
          livepoints[(iindx + livepoints.size(0) * i) - 1] = b_livepoints[i];
        }
      } else {
        // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //  do MultiNest nested sampling
        //  separate out ellipsoids
        b_FS.set_size(1, FS.size(1));
        loop_ub = FS.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FS[b_FS.size(0) * i] = (FS[i] >= 1.1);
        }

        if (coder::internal::b_ifWhileCond(b_FS)) {
          //  NOTE: THIS CODE IS GUARANTEED TO RUN THE 1ST TIME THROUGH
          //  calculate optimal ellipsoids
          optimalEllipsoids(livepoints, VS, Bs, mus, VEs, b_ns);
          ns.set_size(b_ns.size(0), b_ns.size(1));
          loop_ub = b_ns.size(1);
          for (i = 0; i < loop_ub; i++) {
            sizes_idx_1 = b_ns.size(0);
            for (i1 = 0; i1 < sizes_idx_1; i1++) {
              ns[i1 + ns.size(0) * i] = b_ns[i1 + b_ns.size(0) * i];
            }
          }

          K = coder::internal::intlength(VEs.size(0), VEs.size(1));

          //  number of ellipsoids (subclusters)
        } else {
          //  simply rescale the bounding ellipsoids
          if (0 <= K - 1) {
            d = std::exp(-(j + 1.0) / nLive);
            b_dv[0] = 1.0;
          }

          for (int32_T k{0}; k < K; k++) {
            real_T scalefac;
            b_dv[1] = d * ns[k] / nLive / VEs[k];
            scalefac = coder::internal::maximum(b_dv);

            //  scale bounding matrix and volume
            if (scalefac != 1.0) {
              a_tmp = ((static_cast<real_T>(k) + 1.0) - 1.0) *
                static_cast<real_T>(D) + 1.0;
              a = (static_cast<real_T>(k) + 1.0) * static_cast<real_T>(D);
              if (a_tmp > a) {
                i = 0;
                i1 = 0;
                i2 = 1;
              } else {
                i = static_cast<int32_T>(a_tmp) - 1;
                i1 = static_cast<int32_T>(a);
                i2 = static_cast<int32_T>(a_tmp);
              }

              a_tmp = rt_powd_snf(scalefac, 2.0 / static_cast<real_T>(D));
              sizes_idx_1 = Bs.size(1) - 1;
              loop_ub = i1 - i;
              b_Bs.set_size(loop_ub, Bs.size(1));
              for (i1 = 0; i1 <= sizes_idx_1; i1++) {
                for (int32_T i3{0}; i3 < loop_ub; i3++) {
                  b_Bs[i3 + b_Bs.size(0) * i1] = Bs[(i + i3) + Bs.size(0) * i1] *
                    a_tmp;
                }
              }

              loop_ub = b_Bs.size(1);
              for (i = 0; i < loop_ub; i++) {
                sizes_idx_1 = b_Bs.size(0);
                for (i1 = 0; i1 < sizes_idx_1; i1++) {
                  Bs[((i2 + i1) + Bs.size(0) * i) - 1] = b_Bs[i1 + b_Bs.size(0) *
                    i];
                }
              }

              VEs[k] = scalefac * VEs[k];
            }
          }
        }

        //  calculate ratio of volumes (FS>=1) and cumulative fractional volume
        coder::sum(VEs, Vtot);
        FS.set_size(1, Vtot.size(1));
        loop_ub = Vtot.size(1);
        for (i = 0; i < loop_ub; i++) {
          FS[i] = Vtot[i] / VS;
        }

        //  draw a new sample using multinest algorithm
        result.set_size(VEs.size(0), VEs.size(1));
        loop_ub = VEs.size(1);
        for (i = 0; i < loop_ub; i++) {
          sizes_idx_1 = VEs.size(0);
          for (i1 = 0; i1 < sizes_idx_1; i1++) {
            result[i1 + result.size(0) * i] = VEs[i1 + VEs.size(0) * i];
          }
        }

        coder::internal::useConstantDim(result, coder::internal::nonSingletonDim
          (VEs));
        coder::internal::mrdiv(result, Vtot, r);
        drawMultiNest(r, Bs, mus, logLmin, prior, data_f1, data_f2, data_f3,
                      data_f4, r2, &logL[iindx - 1]);
        loop_ub = r2.size(1);
        for (i = 0; i < loop_ub; i++) {
          sizes_idx_1 = r2.size(0);
          for (i1 = 0; i1 < sizes_idx_1; i1++) {
            livepoints[(iindx + livepoints.size(0) * i) - 1] = r2[r2.size(0) * i];
          }
        }
      }

      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      //  update maximum likelihood if appropriate
      a_tmp = logL[iindx - 1];
      if (a_tmp > logLmax) {
        logLmax = a_tmp;
      }

      //  work out tolerance for stopping criterion
      tol = logPlus(*logZ, logLmax - j / nLive) - *logZ;

      //  display progress (optional)
      empty_non_axis_sizes = coder::internal::p_strcmp(data_f2->display.data,
        data_f2->display.size);
      if (!empty_non_axis_sizes) {
        if (j < 2.147483648E+9) {
          i = static_cast<int32_T>(j);
        } else {
          i = MAX_int32_T;
        }

        coder::b_sprintf(*logZ, tol, K, i, *H, r1);
        triggerEvent(r1);
      }

      isRATStopped(data_f2->IPCFilePath.data, data_f2->IPCFilePath.size,
                   (boolean_T *)&tmp_data, &sizes_idx_1);
      if (coder::internal::ifWhileCond((const boolean_T *)&tmp_data, sizes_idx_1))
      {
        if (!empty_non_axis_sizes) {
          h_triggerEvent();
        }

        exitg1 = true;
      } else {
        //  update counter
        j++;
      }
    }

    //  sort the remaining points (in order of likelihood) and add them on to
    //  the evidence
    coder::internal::sort(logL, iidx);
    loop_ub = livepoints.size(1);
    livepoints_sorted.set_size(iidx.size(0), livepoints.size(1));
    for (i = 0; i < loop_ub; i++) {
      sizes_idx_1 = iidx.size(0);
      for (i1 = 0; i1 < sizes_idx_1; i1++) {
        livepoints_sorted[i1 + livepoints_sorted.size(0) * i] = livepoints
          [(iidx[i1] + livepoints.size(0) * i) - 1];
      }
    }

    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      *logZ = logPlus(*logZ, logL[b_i] + logw);
    }

    //  append the additional livepoints to the nested samples
    if ((iidx.size(0) != 0) && (livepoints.size(1) != 0)) {
      iindx = iidx.size(0);
    } else if (logL.size(0) != 0) {
      iindx = logL.size(0);
    } else {
      iindx = iidx.size(0);
    }

    empty_non_axis_sizes = (iindx == 0);
    if (empty_non_axis_sizes || ((iidx.size(0) != 0) && (livepoints.size(1) != 0)))
    {
      sizes_idx_1 = livepoints.size(1);
    } else {
      sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || (logL.size(0) != 0)) {
      b_sizes_idx_1 = 1;
    } else {
      b_sizes_idx_1 = 0;
    }

    result.set_size(iindx, sizes_idx_1 + b_sizes_idx_1);
    for (i = 0; i < sizes_idx_1; i++) {
      for (i1 = 0; i1 < iindx; i1++) {
        result[i1 + result.size(0) * i] = livepoints_sorted[i1 + iindx * i];
      }
    }

    loop_ub = b_sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < iindx; i1++) {
        result[i1 + result.size(0) * sizes_idx_1] = logL[i1];
      }
    }

    if (nest_samples.size(1) != 0) {
      iindx = nest_samples.size(1);
    } else if ((result.size(0) != 0) && (result.size(1) != 0)) {
      iindx = result.size(1);
    } else {
      iindx = 0;
      if (result.size(1) > 0) {
        iindx = result.size(1);
      }
    }

    empty_non_axis_sizes = (iindx == 0);
    if (empty_non_axis_sizes || (nest_samples.size(1) != 0)) {
      loop_ub = nest_samples.size(0);
    } else {
      loop_ub = 0;
    }

    if (empty_non_axis_sizes || ((result.size(0) != 0) && (result.size(1) != 0)))
    {
      sizes_idx_1 = result.size(0);
    } else {
      sizes_idx_1 = 0;
    }

    i = loop_ub + sizes_idx_1;
    b_nest_samples.set_size(i, iindx);
    for (i1 = 0; i1 < iindx; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_nest_samples[i2 + b_nest_samples.size(0) * i1] = nest_samples[i2 +
          loop_ub * i1];
      }
    }

    for (i1 = 0; i1 < iindx; i1++) {
      for (i2 = 0; i2 < sizes_idx_1; i2++) {
        b_nest_samples[(i2 + loop_ub) + b_nest_samples.size(0) * i1] = result[i2
          + sizes_idx_1 * i1];
      }
    }

    nest_samples.set_size(b_nest_samples.size(0), b_nest_samples.size(1));
    loop_ub = b_nest_samples.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      sizes_idx_1 = b_nest_samples.size(0);
      for (i2 = 0; i2 < sizes_idx_1; i2++) {
        nest_samples[i2 + nest_samples.size(0) * i1] = b_nest_samples[i2 +
          b_nest_samples.size(0) * i1];
      }
    }

    //  rescale the samples back to their true ranges
    i = coder::internal::intlength(i, iindx);
    for (b_i = 0; b_i < i; b_i++) {
      if (1 > nest_samples.size(1) - 1) {
        loop_ub = 0;
      } else {
        loop_ub = nest_samples.size(1) - 1;
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        b_nest_samples_data[i1] = nest_samples[b_i + nest_samples.size(0) * i1];
      }

      nest_samples_data.set(&b_nest_samples_data[0], 1, loop_ub);
      rescaleParameters(prior, nest_samples_data, b);
      r3.set_size(b.size(0));
      loop_ub = b.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        r3[i1] = b[i1];
      }

      if (1 > nest_samples.size(1) - 1) {
        loop_ub = 0;
      } else {
        loop_ub = nest_samples.size(1) - 1;
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        nest_samples[b_i + nest_samples.size(0) * i1] = r3[i1];
      }
    }

    //  convert nested samples into posterior samples - nest2pos assumes that the
    //  final column in the sample chain is the log likelihood
    nest2pos(nest_samples, nLive, post_samples);
  }
}

// End of code generation (nestedSampler.cpp)
