//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  void drawMCMC(const ::coder::array<real_T, 2U> &livepoints, const ::coder::
                array<real_T, 2U> &cholmat, real_T logLmin, const ::coder::array<
                real_T, 2U> &prior, const d_struct_T *data_f1, const struct2_T
                *data_f2, const struct1_T *data_f3, const cell_11 *data_f4,
                real_T nMCMC, ::coder::array<real_T, 2U> &sample, real_T *logL)
  {
    ::coder::array<real_T, 2U> sampletmp;
    ::coder::array<real_T, 1U> gasdevs;
    ::coder::array<real_T, 1U> r;
    real_T a[2];
    real_T Ntimes;
    real_T acc;
    int32_T i;
    int32_T loop_ub;
    int32_T nLive;
    int32_T nParams;

    //  This function will draw a multi-dimensional sample from the prior volume
    //  for use in the nested sampling algorithm. The new point will have a
    //  likelihood greater than the value logLmin. The new point will be found by
    //  evolving a random multi-dimensional sample from within the sample array,
    //  livepoints, using an MCMC with nMCMC iterations. The MCMC will use a
    //  Students-t (with N=2 degrees of freedom) proposal distribution based on
    //  the Cholesky decomposed covariance matrix of the array, cholmat. 10% of
    //  the samples will actually be drawn using differential evolution by taking
    //  two random points from the current live points. extraparvals is a vector
    //  of additional parameters needed by the model.
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  global verbose;
    *logL = logLmin;

    //  useful constant
    nLive = livepoints.size(0);
    nParams = livepoints.size(1) - 1;

    //  degrees of freedom of Students't distribution
    //  initialise counters
    Ntimes = 1.0;
    loop_ub = livepoints.size(1);
    i = static_cast<int32_T>(nMCMC);
    real_T sampidx;
    int32_T exitg1;
    do {
      real_T currentPrior;
      real_T priortype;
      real_T pv_tmp;
      int32_T i1;
      int32_T j;
      exitg1 = 0;
      acc = 0.0;

      //  get random point from live point array
      sampidx = coder::b_rand() * static_cast<real_T>(nLive);
      sampidx = std::ceil(sampidx);
      sample.set_size(1, loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        sample[i1] = livepoints[(static_cast<int32_T>(sampidx) + livepoints.size
          (0) * i1) - 1];
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
          real_T p4;
          p4 = prior[j + prior.size(0) * 2];
          pv_tmp = sample[j] - prior[j + prior.size(0)];
          currentPrior = logPlus(currentPrior, (-0.91893853320467267 - std::log
            (p4)) - pv_tmp * pv_tmp / (2.0 * (p4 * p4)));
        } else if (priortype == 3.0) {
          pv_tmp = std::log10(prior[j + prior.size(0)]);
          currentPrior = logPlus(currentPrior, -std::log(rt_powd_snf(10.0,
            sample[j] * (std::log10(prior[j + prior.size(0) * 2]) - pv_tmp) +
            pv_tmp)));
        }
      }

      for (int32_T b_i{0}; b_i < i; b_i++) {
        real_T newPrior;
        int32_T b_loop_ub;
        boolean_T exitg2;
        if (coder::b_rand() < 0.9) {
          //  use Students-t proposal
          //  draw points from mulitvariate Gaussian distribution
          coder::randn(static_cast<real_T>(nParams + 1), gasdevs);

          //  calculate chi-square distributed value
          coder::randn(a);

          //  add value onto old sample
          pv_tmp = std::sqrt(2.0 / (rt_powd_snf(a[0], 2.0) + rt_powd_snf(a[1],
            2.0)));
          coder::internal::blas::mtimes(cholmat, gasdevs, r);
          b_loop_ub = sample.size(1);
          sampletmp.set_size(1, sample.size(1));
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            sampletmp[i1] = sample[i1] + r[i1] * pv_tmp;
          }
        } else {
          real_T idx1;
          real_T idx2;

          //  use differential evolution
          //  draw two random (different points) A and B and add (B-A) to
          //  the current sample
          idx1 = coder::b_rand() * static_cast<real_T>(nLive);
          idx1 = std::ceil(idx1);
          idx2 = idx1;
          while (idx2 == idx1) {
            idx2 = coder::b_rand() * static_cast<real_T>(nLive);
            idx2 = std::ceil(idx2);
          }

          b_loop_ub = sample.size(1);
          sampletmp.set_size(1, sample.size(1));
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            sampletmp[i1] = sample[i1] + (livepoints[(static_cast<int32_T>(idx2)
              + livepoints.size(0) * i1) - 1] - livepoints[(static_cast<int32_T>
              (idx1) + livepoints.size(0) * i1) - 1]);
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
            newPrior = logPlus(newPrior, -0.91893853320467267 - sampletmp[j] *
                               sampletmp[j] / 2.0);
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
          real_T logLnew;

          //  rescale sample back to its proper range for likelihood
          //  get the likelihood of the new sample
          // likestart = tic;
          //  logLnew = likelihood(data, model, parnames, ...
          //                loopCell(sc));
          rescaleParameters(prior, sampletmp, r);
          logLnew = nsIntraFun(data_f1, data_f2, data_f3, data_f4, r);

          // likedur = toc(likestart);
          // fprintf(1, 'liketime = %.6f\n', likedur);
          //  if logLnew is greater than logLmin accept point
          if (logLnew > logLmin) {
            acc++;
            currentPrior = newPrior;
            sample.set_size(1, sampletmp.size(1));
            b_loop_ub = sampletmp.size(1);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              sample[i1] = sampletmp[i1];
            }

            *logL = logLnew;
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
    if (!coder::internal::p_strcmp(data_f2->display.data, data_f2->display.size))
    {
      printf("Acceptance ratio: %1.4f, \n\n", acc / (Ntimes * nMCMC));
      fflush(stdout);
    }
  }
}

// End of code generation (drawMCMC.cpp)
