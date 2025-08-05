//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// nestedSampler.cpp
//
// Code generation for function 'nestedSampler'
//

// Include files
#include "nestedSampler.h"
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
#include "rand.h"
#include "rescaleParameters.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sprintf.h"
#include "sqrt1.h"
#include "strcmp.h"
#include "sum.h"
#include "triggerEvent.h"
#include "useConstantDim.h"
#include "coderException.hpp"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>

// Function Definitions
namespace RAT
{
  double nestedSampler(const ProblemDefinition &data_f1, const Controls &data_f2,
                       double nLive, double nMCMC, double tolerance, const ::
                       coder::array<double, 2U> &prior, ::coder::array<double,
                       2U> &nest_samples, ::coder::array<double, 2U>
                       &post_samples, double &H)
  {
    static const char cv4[99]{ 'N', 'S', ' ', 'E', 'r', 'r', 'o', 'r', ':', ' ',
      'T', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'l',
      'i', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 's', ' ', 'm', 'u', 's', 't',
      ' ', 'b', 'e', ' ', 'l', 'a', 'r', 'g', 'e', 'r', ' ', 't', 'h', 'a', 'n',
      ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ',
      'f', 'i', 't', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', ' ',
      'f', 'o', 'r', ' ', 'M', 'u', 'l', 't', 'i', 'N', 'e', 's', 't', '.' };

    static const char b_cv1[39]{ 'N', 'S', ' ', 'E', 'r', 'r', 'o', 'r', ':',
      ' ', 'n', 'M', 'C', 'M', 'C', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ',
      'a', 'n', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', '>', '=', ' ', '0'
    };

    static const char b_cv3[39]{ 'N', 'S', ' ', 'E', 'r', 'r', 'o', 'r', ':',
      ' ', 'n', 'L', 'i', 'v', 'e', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ',
      'a', 'n', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', '>', '=', ' ', '0'
    };

    ::coder::array<double, 2U> Bs;
    ::coder::array<double, 2U> FS;
    ::coder::array<double, 2U> VEs;
    ::coder::array<double, 2U> Vtot;
    ::coder::array<double, 2U> b_Bs;
    ::coder::array<double, 2U> b_livepoints;
    ::coder::array<double, 2U> b_nest_samples;
    ::coder::array<double, 2U> b_nest_samples_data;
    ::coder::array<double, 2U> b_result;
    ::coder::array<double, 2U> cholmat;
    ::coder::array<double, 2U> l;
    ::coder::array<double, 2U> livepoints;
    ::coder::array<double, 2U> livepoints_sorted;
    ::coder::array<double, 2U> mus;
    ::coder::array<double, 2U> ns;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r3;
    ::coder::array<double, 2U> toAdd;
    ::coder::array<double, 1U> logL;
    ::coder::array<double, 1U> r2;
    ::coder::array<int, 1U> iidx;
    ::coder::array<char, 2U> r1;
    ::coder::array<boolean_T, 2U> b_FS;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    double nest_samples_data[49];
    double b_dv[2];
    double d1;
    double j;
    double logLmax;
    double logZ;
    double logw;
    double tol;
    int D;
    int K;
    int i;
    int i1;
    int i2;
    int iindx;
    int loop_ub;
    int result;
    int sizes_idx_0;
    int sizes_idx_1;
    char b_cv2[99];
    char b_cv[39];
    signed char b_sizes_idx_1;
    boolean_T b;
    boolean_T empty_non_axis_sizes;
    boolean_T exitg1;
    boolean_T tmp_data;

    //  Perform nested sampling on a given likelihood function and set of data with priors.
    //
    //  Parameters
    //  ----------
    //  data : array
    //      The problem struct and controls.
    //  nLive : int
    //      The number of live points to use.
    //  nMCMC : int
    //      If 0, use MultiNest to draw points. if >0, use MCMC and differential evolution
    //      with ``nMCMC`` chains.
    //  tolerance : float
    //      The tolerance of maximum log-likelihood changes between iterations.
    //  flike : function
    //      The log-likelihood function to use.
    //  model : function
    //      The function handle of a model function to pass to the likelihood function.
    //  prior : array
    //      A cell array of parameter names, prior types, prior parameters, and boundary handling.
    //  parnames : array
    //      The names of the parameters to optimise.
    //
    //  Returns
    //  -------
    //  logZ : float
    //      The final log-evidence calculated.
    //  nest_samples : array
    //      The full set of points sampled during the run.
    //  post_samples : array
    //      The posterior values of each point in ``nest_samples``.
    //  H : float
    //      The Shannon entropy of the evidence.
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
    ns.set_size(1, 1);
    ns[0] = 1.0;
    mus.set_size(1, 1);
    mus[0] = 1.0;
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
    if ((coder::b_mod(nMCMC) != 0.0) || (nMCMC < 0.0)) {
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      for (i = 0; i < 39; i++) {
        b_cv[i] = b_cv1[i];
      }

      coderException(2.0, &b_cv[0]);
    }

    if ((coder::b_mod(nLive) != 0.0) || (nLive < 0.0)) {
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      for (i = 0; i < 39; i++) {
        b_cv[i] = b_cv3[i];
      }

      coderException(2.0, &b_cv[0]);
    }

    //  check total number of points is large enough if using MultiNest
    if ((nMCMC == 0.0) && (nLive < static_cast<double>(prior.size(0)) + 1.0)) {
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      std::copy(&cv4[0], &cv4[99], &b_cv2[0]);
      coderException(2.0, &b_cv2[0]);
    }

    //  draw the set of initial live points from the unit hypercube
    //  (they will be rescaled below)
    coder::b_rand(nLive, static_cast<double>(prior.size(0)), livepoints);

    //  calculate the log likelihood of all the live points
    i = static_cast<int>(nLive);
    logL.set_size(i);
    for (int b_i{0}; b_i < i; b_i++) {
      //  rescale parameters based on their priors
      loop_ub = livepoints.size(1);
      b_livepoints.set_size(1, livepoints.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_livepoints[i1] = livepoints[b_i + livepoints.size(0) * i1];
      }

      rescaleParameters(prior, b_livepoints, r);
      logL[b_i] = nsIntraFun(data_f1, data_f2, r);
    }

    //  initial tolerance
    tol = rtInf;

    //  initial width of prior volume (from X_0=1 to X_1=exp(-1/N))
    logw = std::log(1.0 - std::exp(-1.0 / nLive));

    //  initial log evidence (Z=0)
    logZ = rtMinusInf;

    //  initial information
    H = 0.0;

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  some initial values if MCMC nested sampling is used
    //  value to scale down the covariance matrix - CAN CHANGE THIS IF REQUIRED
    // %%%%%%%%%%%%%%
    //  some initial values if MultiNest sampling is used
    //  FS is the ratio of the total volume of all our sample ellipsoids
    //  to the estimated volume of the region from which live points are sampled
    //  we recalculate the ellipsoids if that ratio is larger than h (i.e. the
    //  ellipsoids are more than 10% larger than they need to be)
    //  h is arbitrary; we choose 1.1 in line with
    //  section 5.2 of Feroz, Hobson & Bridges (https://arxiv.org/pdf/0809.3437)
    FS.set_size(1, 1);
    FS[0] = 1.1;

    //  number of ellipsoids; doesn't necessarily need to be defined here,
    //  but coder doesn't recognise that FS >= h is guaranteed on the first iteration
    K = 1;

    //  get maximum likelihood
    logLmax = coder::internal::maximum(logL);
    Bs.set_size(prior.size(0), prior.size(0));
    loop_ub = prior.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      sizes_idx_1 = prior.size(0);
      for (i2 = 0; i2 < sizes_idx_1; i2++) {
        Bs[i2 + Bs.size(0) * i1] = 0.0;
      }
    }

    VEs.set_size(prior.size(0), 1);
    loop_ub = prior.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      VEs[i1] = 0.0;
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  initialise iteration counter
    j = 1.0;

    //  MAIN LOOP
    exitg1 = false;
    while ((!exitg1) && ((tol > tolerance) || (j <= nLive))) {
      double VS;
      double b_b;
      double d;
      double logLmin;
      double logWt;
      double logZold;

      //  expected value of true remaining prior volume X
      VS = std::exp(-j / nLive);

      //  find minimum of likelihoods
      logLmin = coder::internal::minimum(logL, iindx);

      //  set the sample to the minimum value
      //  (Need to do some work brcause we are growing nest_samples in a loop)
      if (j == 1.0) {
        loop_ub = livepoints.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          nest_samples[nest_samples.size(0) * i1] = livepoints[(iindx +
            livepoints.size(0) * i1) - 1];
        }

        nest_samples[nest_samples.size(0) * livepoints.size(1)] = logLmin;
      } else {
        toAdd.set_size(1, livepoints.size(1) + 1);
        loop_ub = livepoints.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          toAdd[i1] = livepoints[(iindx + livepoints.size(0) * i1) - 1];
        }

        toAdd[livepoints.size(1)] = logLmin;
        if (nest_samples.size(1) != 0) {
          sizes_idx_1 = nest_samples.size(1);
        } else {
          sizes_idx_1 = toAdd.size(1);
        }

        if (nest_samples.size(1) != 0) {
          sizes_idx_0 = nest_samples.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        b_nest_samples.set_size(sizes_idx_0 + 1, sizes_idx_1);
        for (i1 = 0; i1 < sizes_idx_1; i1++) {
          for (i2 = 0; i2 < sizes_idx_0; i2++) {
            b_nest_samples[i2 + b_nest_samples.size(0) * i1] = nest_samples[i2 +
              sizes_idx_0 * i1];
          }
        }

        for (i1 = 0; i1 < sizes_idx_1; i1++) {
          b_nest_samples[sizes_idx_0 + b_nest_samples.size(0) * i1] = toAdd[i1];
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
      }

      //  get the log weight (Wt = L*w)
      logWt = logLmin + logw;

      //  save old evidence and information
      logZold = logZ;

      //  update evidence, information, and width
      logZ = logPlus(logZ, logWt);
      if (std::isnan(H)) {
        d = 0.0;
      } else {
        d = H;
      }

      H = (std::exp(logWt - logZ) * logLmin + std::exp(logZold - logZ) * (d +
            logZold)) - logZ;

      // logw = logw - logt(nLive);
      logw -= 1.0 / nLive;

      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      if (nMCMC > 0.0) {
        //  do MCMC nested sampling
        //  get the Cholesky decomposed covariance of the live points
        //  (we do this every 100th iteration - this is arbitrary!)
        if (coder::c_mod(j - 1.0) == 0.0) {
          //  NOTE that for numbers of parameters >~10 covariances are often
          //  not positive definite and cholcov will have "problems".
          //  use modified Cholesky decomposition, which works even for
          //  matrices that are not quite positive definite
          //  (via http://stats.stackexchange.com/questions/6364
          //  /making-square-root-of-covariance-matrix-positive-definite-matlab
          coder::cov(livepoints, b_result);
          b_Bs.set_size(b_result.size(0), b_result.size(1));
          loop_ub = b_result.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            sizes_idx_1 = b_result.size(0);
            for (i2 = 0; i2 < sizes_idx_1; i2++) {
              b_Bs[i2 + b_Bs.size(0) * i1] = 0.1 * b_result[i2 + b_result.size(0)
                * i1];
            }
          }

          mchol(b_Bs, l, b_result);
          coder::b_sqrt(b_result);
          coder::internal::blas::b_mtimes(l, b_result, cholmat);
        }

        //  draw a new sample using mcmc algorithm
        logL[iindx - 1] = drawMCMC(livepoints, cholmat, logLmin, prior, data_f1,
          data_f2, nMCMC, b_livepoints);
        loop_ub = livepoints.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          livepoints[(iindx + livepoints.size(0) * i1) - 1] = b_livepoints[i1];
        }
      } else {
        // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //  do MultiNest nested sampling
        b_FS.set_size(1, FS.size(1));
        loop_ub = FS.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_FS[b_FS.size(0) * i1] = (FS[i1] >= 1.1);
        }

        if (coder::internal::b_ifWhileCond(b_FS)) {
          //  NOTE: THIS CODE IS GUARANTEED TO RUN THE 1ST TIME THROUGH
          //  calculate optimal ellipsoids
          optimalEllipsoids(livepoints, VS, Bs, mus, VEs, ns);
          K = coder::internal::intlength(VEs.size(0), VEs.size(1));

          //  number of ellipsoids (subclusters)
        } else {
          //  simply rescale the bounding ellipsoids
          if (K - 1 >= 0) {
            d1 = std::exp(-(j + 1.0) / nLive);
            b_dv[0] = 1.0;
          }

          for (int k{0}; k < K; k++) {
            double scalefac;
            b_dv[1] = d1 * ns[k] / nLive / VEs[k];
            scalefac = coder::internal::b_maximum(b_dv);

            //  scale bounding matrix and volume
            if (scalefac != 1.0) {
              b_b = ((static_cast<double>(k) + 1.0) - 1.0) * static_cast<double>
                (D) + 1.0;
              d = (static_cast<double>(k) + 1.0) * static_cast<double>(D);
              if (b_b > d) {
                i1 = 0;
                i2 = 0;
                result = 0;
                sizes_idx_0 = 0;
              } else {
                i1 = static_cast<int>(b_b) - 1;
                i2 = static_cast<int>(d);
                result = static_cast<int>(b_b) - 1;
                sizes_idx_0 = static_cast<int>(d);
              }

              b_b = rt_powd_snf(scalefac, 2.0 / static_cast<double>(D));
              loop_ub = i2 - i1;
              sizes_idx_1 = Bs.size(1);
              b_Bs.set_size(loop_ub, Bs.size(1));
              for (i2 = 0; i2 < sizes_idx_1; i2++) {
                for (int i3{0}; i3 < loop_ub; i3++) {
                  b_Bs[i3 + b_Bs.size(0) * i2] = Bs[(i1 + i3) + Bs.size(0) * i2]
                    * b_b;
                }
              }

              sizes_idx_0 -= result;
              loop_ub = Bs.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                for (i2 = 0; i2 < sizes_idx_0; i2++) {
                  Bs[(result + i2) + Bs.size(0) * i1] = b_Bs[i2 + sizes_idx_0 *
                    i1];
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
        for (i1 = 0; i1 < loop_ub; i1++) {
          FS[i1] = Vtot[i1] / VS;
        }

        //  draw a new sample using multinest algorithm
        b_result.set_size(VEs.size(0), VEs.size(1));
        loop_ub = VEs.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          sizes_idx_1 = VEs.size(0);
          for (i2 = 0; i2 < sizes_idx_1; i2++) {
            b_result[i2 + b_result.size(0) * i1] = VEs[i2 + VEs.size(0) * i1];
          }
        }

        coder::internal::useConstantDim(b_result, coder::internal::
          nonSingletonDim(VEs));
        coder::internal::mrdiv(b_result, Vtot, r2);
        logL[iindx - 1] = drawMultiNest(r2, Bs, mus, logLmin, prior, data_f1,
          data_f2, r3);
        loop_ub = livepoints.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          livepoints[(iindx + livepoints.size(0) * i1) - 1] = r3[i1];
        }
      }

      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      //  update maximum likelihood if appropriate
      b_b = logL[iindx - 1];
      if (b_b > logLmax) {
        logLmax = b_b;
      }

      //  work out tolerance for stopping criterion
      tol = logPlus(logZ, logLmax - j / nLive) - logZ;

      //  display progress (optional)
      b = !coder::internal::d_strcmp(data_f2.display.data, data_f2.display.size);
      if (b) {
        if (j < 2.147483648E+9) {
          i1 = static_cast<int>(j);
        } else {
          i1 = MAX_int32_T;
        }

        coder::b_sprintf(logZ, tol, K, i1, H, r1);
        triggerEvent(r1);
      }

      sizes_idx_1 = isRATStopped(data_f2.IPCFilePath.data,
        data_f2.IPCFilePath.size, (boolean_T *)&tmp_data);
      b_tmp_data.set(&tmp_data, sizes_idx_1);
      if (coder::internal::ifWhileCond(b_tmp_data)) {
        if (b) {
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
    livepoints_sorted.set_size(iidx.size(0), livepoints.size(1));
    loop_ub = livepoints.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      sizes_idx_1 = iidx.size(0);
      for (i2 = 0; i2 < sizes_idx_1; i2++) {
        livepoints_sorted[i2 + livepoints_sorted.size(0) * i1] = livepoints
          [(iidx[i2] + livepoints.size(0) * i1) - 1];
      }
    }

    for (int b_i{0}; b_i < i; b_i++) {
      logZ = logPlus(logZ, logL[b_i] + logw);
    }

    //  append the additional livepoints to the nested samples
    b = ((iidx.size(0) != 0) && (livepoints.size(1) != 0));
    if (b) {
      result = iidx.size(0);
    } else if (logL.size(0) != 0) {
      result = logL.size(0);
    } else {
      result = iidx.size(0);
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || b) {
      sizes_idx_1 = livepoints.size(1);
    } else {
      sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || (logL.size(0) != 0)) {
      b_sizes_idx_1 = 1;
    } else {
      b_sizes_idx_1 = 0;
    }

    b_result.set_size(result, sizes_idx_1 + b_sizes_idx_1);
    for (i = 0; i < sizes_idx_1; i++) {
      for (i1 = 0; i1 < result; i1++) {
        b_result[i1 + b_result.size(0) * i] = livepoints_sorted[i1 + result * i];
      }
    }

    loop_ub = b_sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < result; i1++) {
        b_result[i1 + b_result.size(0) * sizes_idx_1] = logL[i1];
      }
    }

    if (nest_samples.size(1) != 0) {
      result = nest_samples.size(1);
    } else if ((b_result.size(0) != 0) && (b_result.size(1) != 0)) {
      result = b_result.size(1);
    } else {
      result = 0;
      if (b_result.size(1) > 0) {
        result = b_result.size(1);
      }
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || (nest_samples.size(1) != 0)) {
      sizes_idx_1 = nest_samples.size(0);
    } else {
      sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || ((b_result.size(0) != 0) && (b_result.size(1) !=
          0))) {
      sizes_idx_0 = b_result.size(0);
    } else {
      sizes_idx_0 = 0;
    }

    i = sizes_idx_1 + sizes_idx_0;
    b_nest_samples.set_size(i, result);
    for (i1 = 0; i1 < result; i1++) {
      for (i2 = 0; i2 < sizes_idx_1; i2++) {
        b_nest_samples[i2 + b_nest_samples.size(0) * i1] = nest_samples[i2 +
          sizes_idx_1 * i1];
      }

      for (i2 = 0; i2 < sizes_idx_0; i2++) {
        b_nest_samples[(i2 + sizes_idx_1) + b_nest_samples.size(0) * i1] =
          b_result[i2 + sizes_idx_0 * i1];
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
    i = coder::internal::intlength(i, result);
    for (int b_i{0}; b_i < i; b_i++) {
      if (nest_samples.size(1) - 1 < 1) {
        sizes_idx_1 = 0;
      } else {
        sizes_idx_1 = nest_samples.size(1) - 1;
      }

      for (i1 = 0; i1 < sizes_idx_1; i1++) {
        nest_samples_data[i1] = nest_samples[b_i + nest_samples.size(0) * i1];
      }

      b_nest_samples_data.set(&nest_samples_data[0], 1, sizes_idx_1);
      rescaleParameters(prior, b_nest_samples_data, b_livepoints);
      for (i1 = 0; i1 < sizes_idx_1; i1++) {
        nest_samples[b_i + nest_samples.size(0) * i1] = b_livepoints[i1];
      }
    }

    //  convert nested samples into posterior samples - nest2pos assumes that the
    //  final column in the sample chain is the log likelihood
    nest2pos(nest_samples, nLive, post_samples);
    return logZ;
  }
}

// End of code generation (nestedSampler.cpp)
