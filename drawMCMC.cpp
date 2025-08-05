//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// drawMCMC.cpp
//
// Code generation for function 'drawMCMC'
//

// Include files
#include "drawMCMC.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "logPlus.h"
#include "mtimes.h"
#include "nsIntraFun.h"
#include "rand.h"
#include "randn.h"
#include "rescaleParameters.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, double in4,
    double in5);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 1U> &in3, double in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, double in4,
    double in5)
  {
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    in1.set_size(1, in1.size(1));
    if (in3.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    in1.set_size(in1.size(0), loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      int i1;
      i1 = i * stride_1_1;
      in1[i] = in2[i * stride_0_1] + (in3[(static_cast<int>(in4) + in3.size(0) *
        i1) - 1] - in3[(static_cast<int>(in5) + in3.size(0) * i1) - 1]);
    }
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 1U> &in3, double in4)
  {
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    in1.set_size(1, in1.size(1));
    if (in3.size(0) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(in1.size(0), loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_1] + in3[i * stride_1_1] * in4;
    }
  }

  double drawMCMC(const ::coder::array<double, 2U> &livepoints, const ::coder::
                  array<double, 2U> &cholmat, double logLmin, const ::coder::
                  array<double, 2U> &prior, const ProblemDefinition &data_f1,
                  const Controls &data_f2, double nMCMC, ::coder::array<double,
                  2U> &sample)
  {
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> sampletmp;
    ::coder::array<double, 1U> gasdevs;
    ::coder::array<double, 1U> r;
    ::coder::array<char, 2U> charStr;
    double Ntimes;
    double acc;
    double logL;
    int i;
    int loop_ub;
    int nLive;
    int nParams;

    //  Draw a sample from the prior volume using MCMC chains.
    //
    //  The new point will be found by
    //  evolving a random multi-dimensional sample from within the sample array,
    //  livepoints, using an MCMC with nMCMC iterations. The MCMC proposals will use a
    //  Student's t-distribution (with 2 degrees of freedom) based on
    //  the Cholesky decomposed covariance matrix of the array, cholmat. 10% of
    //  the samples will actually be drawn using differential evolution by taking
    //  two random points from the current live points.
    //
    //  Parameters
    //  ----------
    //  livepoints : array
    //      The live points in the current iteration of the nested sampler.
    //  cholmat : array
    //      The Cholesky decomposed covariance matrix of ``livepoints``.
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
    logL = logLmin;

    //  useful constant
    nLive = livepoints.size(0);
    nParams = livepoints.size(1) - 1;

    //  degrees of freedom of Student's t-distribution
    //  initialise counters
    Ntimes = 1.0;
    loop_ub = livepoints.size(1);
    i = static_cast<int>(nMCMC);
    double sampidx;
    int exitg1;
    do {
      double currentPrior;
      double priortype;
      double pv_tmp;
      int j;
      exitg1 = 0;
      acc = 0.0;

      //  get random point from live point array
      sampidx = coder::b_rand() * static_cast<double>(nLive);
      sampidx = std::ceil(sampidx);
      sample.set_size(1, livepoints.size(1));
      for (int i1{0}; i1 < loop_ub; i1++) {
        sample[i1] = livepoints[(static_cast<int>(sampidx) + livepoints.size(0) *
          i1) - 1];
      }

      //  get the sample prior
      currentPrior = rtMinusInf;
      for (j = 0; j <= nParams; j++) {
        priortype = prior[j];

        //          p3 = prior{j,3};
        //          p4 = prior{j,4};
        if (priortype == 1.0) {
          currentPrior = logPlus(currentPrior, -std::log(prior[j + prior.size(0)
            * 4] - prior[j + prior.size(0) * 3]));
        } else if (priortype == 2.0) {
          double p4;
          p4 = prior[j + prior.size(0) * 2];
          pv_tmp = sample[j] - prior[j + prior.size(0)];
          currentPrior = logPlus(currentPrior, (-0.91893853320467267 - std::log
            (p4)) - pv_tmp * pv_tmp / (2.0 * (p4 * p4)));
        } else if (priortype == 3.0) {
          pv_tmp = std::log10(prior[j + prior.size(0) * 3]);
          currentPrior = logPlus(currentPrior, -std::log(rt_powd_snf(10.0,
            sample[j] * (std::log10(prior[j + prior.size(0) * 4]) - pv_tmp) +
            pv_tmp)));
        }
      }

      for (int b_i{0}; b_i < i; b_i++) {
        double newPrior;
        int b_loop_ub;
        boolean_T exitg2;
        if (coder::b_rand() < 0.9) {
          double a[2];

          //  use Students-t proposal
          //  draw points from mulitvariate Gaussian distribution
          coder::randn(static_cast<double>(nParams + 1), gasdevs);

          //  calculate chi-square distributed value
          coder::randn(a);

          //  add value onto old sample
          pv_tmp = std::sqrt(2.0 / (rt_powd_snf(a[0], 2.0) + rt_powd_snf(a[1],
            2.0)));
          coder::internal::blas::mtimes(cholmat, gasdevs, r);
          b_loop_ub = sample.size(1);
          if (r.size(0) == sample.size(1)) {
            sampletmp.set_size(1, sample.size(1));
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              sampletmp[i1] = sample[i1] + r[i1] * pv_tmp;
            }
          } else {
            binary_expand_op(sampletmp, sample, r, pv_tmp);
          }
        } else {
          double idx1;
          double idx2;

          //  use differential evolution
          //  draw two random (different points) A and B and add (B-A) to
          //  the current sample
          idx1 = coder::b_rand() * static_cast<double>(nLive);
          idx1 = std::ceil(idx1);
          idx2 = idx1;
          while (idx2 == idx1) {
            idx2 = coder::b_rand() * static_cast<double>(nLive);
            idx2 = std::ceil(idx2);
          }

          b_loop_ub = sample.size(1);
          if (sample.size(1) == livepoints.size(1)) {
            sampletmp.set_size(1, sample.size(1));
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              sampletmp[i1] = sample[i1] + (livepoints[(static_cast<int>(idx2) +
                livepoints.size(0) * i1) - 1] - livepoints[(static_cast<int>
                (idx1) + livepoints.size(0) * i1) - 1]);
            }
          } else {
            binary_expand_op(sampletmp, sample, livepoints, idx2, idx1);
          }
        }

        //  check sample is within the (scaled) prior
        newPrior = rtMinusInf;
        j = 0;
        exitg2 = false;
        while ((!exitg2) && (j <= nParams)) {
          priortype = prior[j];

          //  p3 = prior{j,3};
          //  p4 = prior{j,4};
          if (priortype == 1.0) {
            //  uniform
            if ((sampletmp[j] < 0.0) || (sampletmp[j] > 1.0)) {
              //  wrap parameter from one side to the other
              while (sampletmp[j] > 1.0) {
                sampletmp[j] = sampletmp[j] - 1.0;
              }

              while (sampletmp[j] < 0.0) {
                sampletmp[j] = sampletmp[j] + 1.0;
              }
            }

            newPrior = logPlus(newPrior, -std::log(prior[j + prior.size(0) * 4]
              - prior[j + prior.size(0) * 3]));
            j++;
          } else if (priortype == 2.0) {
            //  gaussian
            newPrior = logPlus(newPrior, -0.91893853320467267 - 0.5 *
                               (sampletmp[j] * sampletmp[j]));
            j++;
          } else if (priortype == 3.0) {
            //  'jeffreys'
            //  behaviour = char(prior(j,5));
            if ((sampletmp[j] < 0.0) || (sampletmp[j] > 1.0)) {
              newPrior = rtMinusInf;
              exitg2 = true;
            } else {
              pv_tmp = std::log10(prior[j + prior.size(0)]);
              newPrior = logPlus(newPrior, -std::log(rt_powd_snf(10.0,
                sampletmp[j] * (std::log10(prior[j + prior.size(0) * 2]) -
                                pv_tmp) + pv_tmp)));
              j++;
            }
          } else {
            j++;
          }
        }

        pv_tmp = coder::b_rand();
        if (!(std::log(pv_tmp) > newPrior - currentPrior)) {
          double logLnew;

          //  rescale sample back to its proper range for likelihood
          //  get the likelihood of the new sample
          // likestart = tic;
          rescaleParameters(prior, sampletmp, r1);
          logLnew = nsIntraFun(data_f1, data_f2, r1);

          // likedur = toc(likestart);
          // fprintf(1, 'liketime = %.6f\n', likedur);
          //  if logLnew is greater than logLmin accept point
          if (logLnew > logLmin) {
            acc++;
            currentPrior = newPrior;
            sample.set_size(1, sampletmp.size(1));
            b_loop_ub = sampletmp.size(1);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              sample[i1] = sampletmp[i1];
            }

            logL = logLnew;
          }
        } else {
          //  reject point
        }
      }

      //  only break if at least one point was accepted otherwise try again
      if (acc > 0.0) {
        exitg1 = 1;
      } else {
        Ntimes++;
      }
    } while (exitg1 == 0);

    //  print out acceptance ratio
    if (!coder::internal::d_strcmp(data_f2.display.data, data_f2.display.size))
    {
      coder::b_snPrint(acc / (Ntimes * nMCMC), charStr);
      triggerEvent(charStr);
    }

    return logL;
  }
}

// End of code generation (drawMCMC.cpp)
