//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// refPercentileConfidenceIntervals.cpp
//
// Code generation for function 'refPercentileConfidenceIntervals'
//

// Include files
#include "refPercentileConfidenceIntervals.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "interp1.h"
#include "makeCell.h"
#include "mean.h"
#include "prctile.h"
#include "rand.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void refPercentileConfidenceIntervals(const ::coder::array<double, 2U>
    &bayesOutputs_chain, ProblemDefinition *problemStruct, const Controls
    *controls, const ::coder::array<cell_wrap_7, 1U> &results_reflectivity,
    const ::coder::array<cell_wrap_9, 2U> &results_sldProfiles, ::coder::array<
    cell_wrap_11, 1U> &allPredInts_reflectivity, ::coder::array<cell_wrap_11, 2U>
    &allPredInts_sld, double allPredInts_sampleChi[1000])
  {
    ::coder::array<cell_wrap_9, 2U> r;
    ::coder::array<cell_wrap_9, 2U> refXVals;
    ::coder::array<cell_wrap_9, 2U> refYVals;
    ::coder::array<cell_wrap_9, 2U> sldXVals;
    ::coder::array<cell_wrap_9, 2U> sldYVals;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> refArray;
    ::coder::array<double, 2U> sldArray;
    ::coder::array<double, 2U> sldArray1;
    ::coder::array<double, 2U> sldArray2;
    ::coder::array<double, 1U> b_expl_temp;
    ::coder::array<double, 1U> c_expl_temp;
    Results expl_temp;
    double a[1000];
    double isample[1000];
    double b_dv[3];
    double ci65[2];
    double ci651[2];
    double ci652[2];
    double ci95[2];
    double ci951[2];
    double ci952[2];
    double numberOfContrasts;
    int b_i;
    int b_loop_ub;
    int b_refYVals_size;
    int c_loop_ub;
    int c_refYVals_size;
    int d_loop_ub;
    int i;
    int i1;
    int k;
    int loop_ub;
    int m;
    int points;
    int refYVals_size;
    boolean_T domains;

    //  Need to deal slightly differently with SLDs if there are domains
    domains = coder::internal::b_strcmp(problemStruct->TF.data,
      problemStruct->TF.size);

    //  Prepare some arrays to hold the SLD's and Refs for all the chain, keeping only the Y values.
    //  We'll save x values in a separate array
    numberOfContrasts = problemStruct->numberOfContrasts;
    b_dv[0] = 0.0;
    b_dv[1] = 0.0;
    b_dv[2] = 0.0;
    makeCell(problemStruct->numberOfContrasts, b_dv, refXVals);
    b_dv[0] = 0.0;
    b_dv[1] = 0.0;
    b_dv[2] = 0.0;
    makeCell(problemStruct->numberOfContrasts, b_dv, refYVals);
    if (!domains) {
      b_dv[0] = 0.0;
      b_dv[1] = 0.0;
      b_dv[2] = 0.0;
      makeCell(problemStruct->numberOfContrasts, b_dv, r);
      sldXVals.set_size(r.size(0), 1);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        sldXVals[i] = r[i];
      }

      b_dv[0] = 0.0;
      b_dv[1] = 0.0;
      b_dv[2] = 0.0;
      makeCell(problemStruct->numberOfContrasts, b_dv, r);
      sldYVals.set_size(r.size(0), 1);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        sldYVals[i] = r[i];
      }
    } else {
      b_dv[0] = 0.0;
      b_dv[1] = 0.0;
      b_dv[2] = 0.0;
      b_makeCell(problemStruct->numberOfContrasts, b_dv, r);
      sldXVals.set_size(r.size(0), 2);
      loop_ub = r.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          sldXVals[i1 + sldXVals.size(0) * i] = r[i1 + r.size(0) * i];
        }
      }

      b_dv[0] = 0.0;
      b_dv[1] = 0.0;
      b_dv[2] = 0.0;
      b_makeCell(problemStruct->numberOfContrasts, b_dv, r);
      sldYVals.set_size(r.size(0), 2);
      loop_ub = r.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          sldYVals[i1 + sldYVals.size(0) * i] = r[i1 + r.size(0) * i];
        }
      }
    }

    //  We need to have the yvals interpolated onto the same xvals when we
    //  calculate the sample. So, take the input reflectivity and SLD values
    //  to get the 'base' x for ref and SLD, then all following
    //  interpolations are onto these x values....
    i = static_cast<int>(problemStruct->numberOfContrasts);
    for (b_i = 0; b_i < i; b_i++) {
      loop_ub = results_reflectivity[b_i].f1.size(0);
      refXVals[b_i].f1.set_size(1, results_reflectivity[b_i].f1.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        refXVals[b_i].f1[refXVals[b_i].f1.size(0) * i1] =
          results_reflectivity[b_i].f1[i1];
      }

      //  Transpose these into rows for storage
      if (!domains) {
        loop_ub = results_sldProfiles[b_i].f1.size(0);
        sldXVals[b_i].f1.set_size(1, results_sldProfiles[b_i].f1.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          sldXVals[b_i].f1[sldXVals[b_i].f1.size(0) * i1] =
            results_sldProfiles[b_i].f1[i1];
        }
      } else {
        for (m = 0; m < 2; m++) {
          loop_ub = results_sldProfiles[b_i + results_sldProfiles.size(0) * m].
            f1.size(0);
          sldXVals[b_i + sldXVals.size(0) * m].f1.set_size(1,
            results_sldProfiles[b_i + results_sldProfiles.size(0) * m].f1.size(0));
          for (i1 = 0; i1 < loop_ub; i1++) {
            sldXVals[b_i + sldXVals.size(0) * m].f1[sldXVals[b_i + sldXVals.size
              (0) * m].f1.size(0) * i1] = results_sldProfiles[b_i +
              results_sldProfiles.size(0) * m].f1[i1];
          }
        }
      }
    }

    //  Loop over the whole chain, collecting the Sld's and Refs together into
    //  one array for each contrast.
    // will be = nsimu
    //  To speed things up, we'll take a random sample of the chain, rather than
    //  calculating >20000 reflectivities...
    coder::c_rand(a);
    for (k = 0; k < 1000; k++) {
      isample[k] = std::ceil(a[k] * static_cast<double>(bayesOutputs_chain.size
        (0)));
    }

    //  First, we populate the yVals arrays with zero arrays of the correct size...
    for (b_i = 0; b_i < i; b_i++) {
      refYVals[b_i].f1.set_size(1000, results_reflectivity[b_i].f1.size(0));
      loop_ub = results_reflectivity[b_i].f1.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (k = 0; k < 1000; k++) {
          refYVals[b_i].f1[k + refYVals[b_i].f1.size(0) * i1] = 0.0;
        }
      }

      if (!domains) {
        sldYVals[b_i].f1.set_size(1000, results_sldProfiles[b_i].f1.size(0));
        loop_ub = results_sldProfiles[b_i].f1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 1000; k++) {
            sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * i1] = 0.0;
          }
        }
      } else {
        sldYVals[b_i].f1.set_size(1000, results_sldProfiles[b_i].f1.size(0));
        loop_ub = results_sldProfiles[b_i].f1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 1000; k++) {
            sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * i1] = 0.0;
          }
        }

        sldYVals[b_i + sldYVals.size(0)].f1.set_size(1000,
          results_sldProfiles[b_i + results_sldProfiles.size(0)].f1.size(0));
        loop_ub = results_sldProfiles[b_i + results_sldProfiles.size(0)].f1.size
          (0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 1000; k++) {
            sldYVals[b_i + sldYVals.size(0)].f1[k + sldYVals[b_i + sldYVals.size
              (0)].f1.size(0) * i1] = 0.0;
          }
        }
      }
    }

    //  Calculate all the samples....
    loop_ub = bayesOutputs_chain.size(1);
    for (b_i = 0; b_i < 1000; b_i++) {
      problemStruct->fitParams.set_size(1, loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        problemStruct->fitParams[i1] = bayesOutputs_chain[(static_cast<int>
          (isample[b_i]) + bayesOutputs_chain.size(0) * i1) - 1];
      }

      unpackParams(problemStruct);

      //  Calc the reflectivities....
      b_reflectivityCalculation(problemStruct, controls, &expl_temp);
      allPredInts_sampleChi[b_i] = expl_temp.calculationResults.sumChi;
      for (int n{0}; n < i; n++) {
        k = expl_temp.reflectivity[n].f1.size(0);
        b_expl_temp.set_size(expl_temp.reflectivity[n].f1.size(0));
        for (i1 = 0; i1 < k; i1++) {
          b_expl_temp[i1] = expl_temp.reflectivity[n].f1[i1];
        }

        k = expl_temp.reflectivity[n].f1.size(0);
        c_expl_temp.set_size(expl_temp.reflectivity[n].f1.size(0));
        for (i1 = 0; i1 < k; i1++) {
          c_expl_temp[i1] = expl_temp.reflectivity[n].f1[i1 +
            expl_temp.reflectivity[n].f1.size(0)];
        }

        coder::interp1(b_expl_temp, c_expl_temp, refXVals[n].f1, r1);
        k = r1.size(1);
        for (i1 = 0; i1 < k; i1++) {
          refYVals[n].f1[b_i + refYVals[n].f1.size(0) * i1] = r1[i1];
        }

        //  Automatically comes back as a row from interp1
        if (!domains) {
          k = expl_temp.sldProfiles[n].f1.size(0);
          b_expl_temp.set_size(expl_temp.sldProfiles[n].f1.size(0));
          for (i1 = 0; i1 < k; i1++) {
            b_expl_temp[i1] = expl_temp.sldProfiles[n].f1[i1];
          }

          k = expl_temp.sldProfiles[n].f1.size(0);
          c_expl_temp.set_size(expl_temp.sldProfiles[n].f1.size(0));
          for (i1 = 0; i1 < k; i1++) {
            c_expl_temp[i1] = expl_temp.sldProfiles[n].f1[i1 +
              expl_temp.sldProfiles[n].f1.size(0)];
          }

          coder::interp1(b_expl_temp, c_expl_temp, sldXVals[n].f1, r1);
          k = r1.size(1);
          for (i1 = 0; i1 < k; i1++) {
            sldYVals[n].f1[b_i + sldYVals[n].f1.size(0) * i1] = r1[i1];
          }
        } else {
          for (m = 0; m < 2; m++) {
            k = expl_temp.sldProfiles[n + expl_temp.sldProfiles.size(0) * m].
              f1.size(0);
            b_expl_temp.set_size(expl_temp.sldProfiles[n +
                                 expl_temp.sldProfiles.size(0) * m].f1.size(0));
            for (i1 = 0; i1 < k; i1++) {
              b_expl_temp[i1] = expl_temp.sldProfiles[n +
                expl_temp.sldProfiles.size(0) * m].f1[i1];
            }

            k = expl_temp.sldProfiles[n + expl_temp.sldProfiles.size(0) * m].
              f1.size(0);
            c_expl_temp.set_size(expl_temp.sldProfiles[n +
                                 expl_temp.sldProfiles.size(0) * m].f1.size(0));
            for (i1 = 0; i1 < k; i1++) {
              c_expl_temp[i1] = expl_temp.sldProfiles[n +
                expl_temp.sldProfiles.size(0) * m].f1[i1 +
                expl_temp.sldProfiles[n + expl_temp.sldProfiles.size(0) * m].
                f1.size(0)];
            }

            coder::interp1(b_expl_temp, c_expl_temp, sldXVals[n + sldXVals.size
                           (0) * m].f1, r1);
            k = r1.size(1);
            for (i1 = 0; i1 < k; i1++) {
              sldYVals[n + sldYVals.size(0) * m].f1[b_i + sldYVals[n +
                sldYVals.size(0) * m].f1.size(0) * i1] = r1[i1];
            }
          }
        }
      }
    }

    //  Calculate the percentiles across all the calculated samples for each
    //  point in x... We calculate 95% and 65% CI's for each set of curves
    //  Reflectivity..
    i = static_cast<int>(numberOfContrasts);
    i1 = static_cast<int>(numberOfContrasts);
    allPredInts_reflectivity.set_size(i1);
    for (b_i = 0; b_i < i; b_i++) {
      refArray.set_size(5, refYVals[b_i].f1.size(1));
      loop_ub = refYVals[b_i].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (k = 0; k < 5; k++) {
          refArray[k + 5 * i1] = 0.0;
        }
      }

      //  We could possibly use CIFn in one shot here (rather than loop over
      //  points....)
      i1 = refYVals[b_i].f1.size(1);
      if (0 <= refYVals[b_i].f1.size(1) - 1) {
        refYVals_size = refYVals[b_i].f1.size(0);
        b_loop_ub = refYVals[b_i].f1.size(0);
        b_refYVals_size = refYVals[b_i].f1.size(0);
        c_loop_ub = refYVals[b_i].f1.size(0);
        c_refYVals_size = refYVals[b_i].f1.size(0);
        d_loop_ub = refYVals[b_i].f1.size(0);
      }

      for (points = 0; points < i1; points++) {
        for (k = 0; k < b_loop_ub; k++) {
          a[k] = refYVals[b_i].f1[k + refYVals[b_i].f1.size(0) * points];
        }

        coder::prctile(a, refYVals_size, ci95);
        for (k = 0; k < c_loop_ub; k++) {
          a[k] = refYVals[b_i].f1[k + refYVals[b_i].f1.size(0) * points];
        }

        coder::b_prctile(a, b_refYVals_size, ci65);
        for (k = 0; k < d_loop_ub; k++) {
          a[k] = refYVals[b_i].f1[k + refYVals[b_i].f1.size(0) * points];
        }

        refArray[5 * points] = ci95[0];
        refArray[5 * points + 1] = ci65[0];
        refArray[5 * points + 2] = coder::mean(a, c_refYVals_size);
        refArray[5 * points + 3] = ci65[1];
        refArray[5 * points + 4] = ci95[1];
      }

      allPredInts_reflectivity[b_i].f1.set_size(5, refArray.size(1));
      loop_ub = refArray.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (k = 0; k < 5; k++) {
          allPredInts_reflectivity[b_i].f1[k + 5 * i1] = refArray[k + 5 * i1];
        }
      }
    }

    //  Also the SLD's
    if (!domains) {
      i = static_cast<int>(numberOfContrasts);
      i1 = static_cast<int>(numberOfContrasts);
      allPredInts_sld.set_size(i1, 1);
      for (b_i = 0; b_i < i; b_i++) {
        sldArray.set_size(5, sldYVals[b_i].f1.size(1));
        loop_ub = sldYVals[b_i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 5; k++) {
            sldArray[k + 5 * i1] = 0.0;
          }
        }

        i1 = sldYVals[b_i].f1.size(1);
        for (points = 0; points < i1; points++) {
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * points];
          }

          coder::prctile(a, refYVals_size, ci95);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * points];
          }

          coder::b_prctile(a, refYVals_size, ci65);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * points];
          }

          sldArray[5 * points] = ci95[0];
          sldArray[5 * points + 1] = ci65[0];
          sldArray[5 * points + 2] = coder::mean(a, refYVals_size);
          sldArray[5 * points + 3] = ci65[1];
          sldArray[5 * points + 4] = ci95[1];
        }

        allPredInts_sld[b_i].f1.set_size(5, sldArray.size(1));
        loop_ub = sldArray.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 5; k++) {
            allPredInts_sld[b_i].f1[k + 5 * i1] = sldArray[k + 5 * i1];
          }
        }
      }
    } else {
      i = static_cast<int>(numberOfContrasts);
      i1 = static_cast<int>(numberOfContrasts);
      allPredInts_sld.set_size(i1, 2);
      for (b_i = 0; b_i < i; b_i++) {
        sldArray1.set_size(5, sldYVals[b_i].f1.size(1));
        loop_ub = sldYVals[b_i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 5; k++) {
            sldArray1[k + 5 * i1] = 0.0;
          }
        }

        sldArray2.set_size(5, sldYVals[b_i + sldYVals.size(0)].f1.size(1));
        loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 5; k++) {
            sldArray2[k + 5 * i1] = 0.0;
          }
        }

        i1 = sldYVals[b_i].f1.size(1);
        for (points = 0; points < i1; points++) {
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * points];
          }

          coder::prctile(a, refYVals_size, ci951);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * points];
          }

          coder::b_prctile(a, refYVals_size, ci651);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i].f1[k + sldYVals[b_i].f1.size(0) * points];
          }

          sldArray1[5 * points] = ci951[0];
          sldArray1[5 * points + 1] = ci651[0];
          sldArray1[5 * points + 2] = coder::mean(a, refYVals_size);
          sldArray1[5 * points + 3] = ci651[1];
          sldArray1[5 * points + 4] = ci951[1];
        }

        i1 = sldYVals[b_i + sldYVals.size(0)].f1.size(1);
        for (points = 0; points < i1; points++) {
          loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          refYVals_size = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i + sldYVals.size(0)].f1[k + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * points];
          }

          coder::prctile(a, refYVals_size, ci952);
          loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          refYVals_size = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i + sldYVals.size(0)].f1[k + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * points];
          }

          coder::b_prctile(a, refYVals_size, ci652);
          loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          refYVals_size = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          for (k = 0; k < loop_ub; k++) {
            a[k] = sldYVals[b_i + sldYVals.size(0)].f1[k + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * points];
          }

          sldArray2[5 * points] = ci952[0];
          sldArray2[5 * points + 1] = ci652[0];
          sldArray2[5 * points + 2] = coder::mean(a, refYVals_size);
          sldArray2[5 * points + 3] = ci652[1];
          sldArray2[5 * points + 4] = ci952[1];
        }

        allPredInts_sld[b_i].f1.set_size(5, sldArray1.size(1));
        loop_ub = sldArray1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 5; k++) {
            allPredInts_sld[b_i].f1[k + 5 * i1] = sldArray1[k + 5 * i1];
          }
        }

        allPredInts_sld[b_i + allPredInts_sld.size(0)].f1.set_size(5,
          sldArray2.size(1));
        loop_ub = sldArray2.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (k = 0; k < 5; k++) {
            allPredInts_sld[b_i + allPredInts_sld.size(0)].f1[k + 5 * i1] =
              sldArray2[k + 5 * i1];
          }
        }
      }
    }
  }
}

// End of code generation (refPercentileConfidenceIntervals.cpp)
