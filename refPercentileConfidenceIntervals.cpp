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
  void refPercentileConfidenceIntervals(const ::coder::array<real_T, 2U>
    &bayesOutputs_chain, f_struct_T *problemStruct, const cell_11 *problemCells,
    const struct1_T *problemLimits, const struct2_T *controlsStruct, g_struct_T *
    allPredInts)
  {
    ::coder::array<cell_wrap_10, 2U> r1;
    ::coder::array<cell_wrap_10, 2U> refYVals;
    ::coder::array<cell_wrap_10, 2U> sldYVals;
    ::coder::array<cell_wrap_32, 2U> r;
    ::coder::array<real_T, 2U> r2;
    ::coder::array<real_T, 2U> refArray;
    ::coder::array<real_T, 2U> rowVals;
    ::coder::array<real_T, 2U> sldArray;
    ::coder::array<real_T, 2U> sldArray1;
    ::coder::array<real_T, 2U> sldArray2;
    ::coder::array<real_T, 2U> vals;
    ::coder::array<real_T, 1U> c_expl_temp;
    ::coder::array<real_T, 1U> d_expl_temp;
    struct5_T b_expl_temp;
    struct5_T expl_temp;
    real_T a[1000];
    real_T isample[1000];
    real_T ci65[2];
    real_T ci651[2];
    real_T ci652[2];
    real_T ci95[2];
    real_T ci951[2];
    real_T ci952[2];
    real_T numberOfContrasts;
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T b_refYVals_size;
    int32_T c_loop_ub;
    int32_T c_refYVals_size;
    int32_T d_loop_ub;
    int32_T e_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T k;
    int32_T loop_ub;
    int32_T m;
    int32_T points;
    int32_T refYVals_size;
    boolean_T domains;

    //  Need to deal slightly differently with SLDs if there are domains
    domains = coder::internal::b_strcmp(problemStruct->TF.data,
      problemStruct->TF.size);

    //  Calc the ref and SLD for the first row of the chain. This 'sticks' the x
    //  values of each that we then interpolate the values from the rest of the
    //  cain onto....
    loop_ub = bayesOutputs_chain.size(1);
    problemStruct->fitParams.set_size(1, bayesOutputs_chain.size(1));
    for (i = 0; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] =
        bayesOutputs_chain[bayesOutputs_chain.size(0) * i];
    }

    unpackParams(problemStruct, controlsStruct->checks.fitParam,
                 controlsStruct->checks.fitBackgroundParam,
                 controlsStruct->checks.fitQzshift,
                 controlsStruct->checks.fitScalefactor,
                 controlsStruct->checks.fitBulkIn,
                 controlsStruct->checks.fitBulkOut,
                 controlsStruct->checks.fitResolutionParam,
                 controlsStruct->checks.fitDomainRatio);

    //  Calc the reflectivities....
    reflectivityCalculation(problemStruct, problemCells, problemLimits,
      controlsStruct, &expl_temp);

    //  so each is a {n x 1} cell array, because of n contrasts.
    //  Prepare some arrays to hold the SLD's and Refs for all the chain, keeping only the Y vales.
    //  We'll save x values in a separate array
    numberOfContrasts = problemStruct->numberOfContrasts;
    vals.set_size(1, 3);
    rowVals.set_size(1, 3);
    vals[0] = 0.0;
    rowVals[0] = 0.0;
    vals[vals.size(0)] = 0.0;
    rowVals[1] = 0.0;
    vals[vals.size(0) * 2] = 0.0;
    rowVals[2] = 0.0;
    makeCell(problemStruct->numberOfContrasts, (const real_T *)rowVals.data(),
             allPredInts->reflectivityXData);

    // cell(numberOfContrasts,1);
    makeCell(problemStruct->numberOfContrasts, (const real_T *)vals.data(),
             refYVals);

    // cell(numberOfContrasts,1);
    if (!domains) {
      makeCell(problemStruct->numberOfContrasts, (const real_T *)rowVals.data(),
               r);
      allPredInts->sldXData.set_size(r.size(0), 1);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        allPredInts->sldXData[i] = r[i];
      }

      makeCell(problemStruct->numberOfContrasts, (const real_T *)vals.data(), r1);
      sldYVals.set_size(r1.size(0), 1);
      loop_ub = r1.size(0);
      for (i = 0; i < loop_ub; i++) {
        sldYVals[i] = r1[i];
      }
    } else {
      b_makeCell(problemStruct->numberOfContrasts, (const real_T *)rowVals.data(),
                 r);
      allPredInts->sldXData.set_size(r.size(0), 2);
      b_makeCell(problemStruct->numberOfContrasts, (const real_T *)vals.data(),
                 r1);
      sldYVals.set_size(r1.size(0), 2);
      loop_ub = r.size(0);
      b_loop_ub = r1.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          allPredInts->sldXData[i1 + allPredInts->sldXData.size(0) * i] = r[i1 +
            r.size(0) * i];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          sldYVals[i1 + sldYVals.size(0) * i] = r1[i1 + r1.size(0) * i];
        }
      }
    }

    //  We need to have the yvals interpolated onto the same xvals when we
    //  calculate the sample. So, take the current reflectivity value from above
    //  to get the 'base' x for ref and SLD, then all following
    //  interpelations are onto these x values....
    i = static_cast<int32_T>(problemStruct->numberOfContrasts);
    for (b_i = 0; b_i < i; b_i++) {
      loop_ub = expl_temp.reflectivity[b_i].f1.size(0);
      allPredInts->reflectivityXData[b_i].f1.set_size(1,
        expl_temp.reflectivity[b_i].f1.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        allPredInts->reflectivityXData[b_i].f1[i1] = expl_temp.reflectivity[b_i]
          .f1[i1];
      }

      //  Transpose these into rows for storage
      if (!domains) {
        loop_ub = expl_temp.sldProfiles[b_i].f1.size(0);
        allPredInts->sldXData[b_i].f1.set_size(1, expl_temp.sldProfiles[b_i].
          f1.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          allPredInts->sldXData[b_i].f1[i1] = expl_temp.sldProfiles[b_i].f1[i1];
        }
      } else {
        for (m = 0; m < 2; m++) {
          loop_ub = expl_temp.sldProfiles[b_i + expl_temp.sldProfiles.size(0) *
            m].f1.size(0);
          allPredInts->sldXData[b_i + allPredInts->sldXData.size(0) * m].
            f1.set_size(1, expl_temp.sldProfiles[b_i +
                        expl_temp.sldProfiles.size(0) * m].f1.size(0));
          for (i1 = 0; i1 < loop_ub; i1++) {
            allPredInts->sldXData[b_i + allPredInts->sldXData.size(0) * m].f1[i1]
              = expl_temp.sldProfiles[b_i + expl_temp.sldProfiles.size(0) * m].
              f1[i1];
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
      isample[k] = std::ceil(a[k] * static_cast<real_T>(bayesOutputs_chain.size
        (0)));
    }

    //  First, we populate the yVals arrays with zero arrays of the correct size...
    for (b_i = 0; b_i < i; b_i++) {
      refYVals[b_i].f1.set_size(1000, expl_temp.reflectivity[b_i].f1.size(0));
      loop_ub = expl_temp.reflectivity[b_i].f1.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < 1000; i2++) {
          refYVals[b_i].f1[i2 + refYVals[b_i].f1.size(0) * i1] = 0.0;
        }
      }

      if (!domains) {
        sldYVals[b_i].f1.set_size(1000, expl_temp.sldProfiles[b_i].f1.size(0));
        loop_ub = expl_temp.sldProfiles[b_i].f1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 1000; i2++) {
            sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * i1] = 0.0;
          }
        }
      } else {
        sldYVals[b_i].f1.set_size(1000, expl_temp.sldProfiles[b_i].f1.size(0));
        loop_ub = expl_temp.sldProfiles[b_i].f1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 1000; i2++) {
            sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * i1] = 0.0;
          }
        }

        sldYVals[b_i + sldYVals.size(0)].f1.set_size(1000,
          expl_temp.sldProfiles[b_i + expl_temp.sldProfiles.size(0)].f1.size(0));
        loop_ub = expl_temp.sldProfiles[b_i + expl_temp.sldProfiles.size(0)].
          f1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 1000; i2++) {
            sldYVals[b_i + sldYVals.size(0)].f1[i2 + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * i1] = 0.0;
          }
        }
      }
    }

    //  Calculate all the samples....
    loop_ub = bayesOutputs_chain.size(1);
    for (b_i = 0; b_i < 1000; b_i++) {
      problemStruct->fitParams.set_size(1, loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        problemStruct->fitParams[problemStruct->fitParams.size(0) * i1] =
          bayesOutputs_chain[(static_cast<int32_T>(isample[b_i]) +
                              bayesOutputs_chain.size(0) * i1) - 1];
      }

      unpackParams(problemStruct, controlsStruct->checks.fitParam,
                   controlsStruct->checks.fitBackgroundParam,
                   controlsStruct->checks.fitQzshift,
                   controlsStruct->checks.fitScalefactor,
                   controlsStruct->checks.fitBulkIn,
                   controlsStruct->checks.fitBulkOut,
                   controlsStruct->checks.fitResolutionParam,
                   controlsStruct->checks.fitDomainRatio);

      //  Calc the reflectivities....
      reflectivityCalculation(problemStruct, problemCells, problemLimits,
        controlsStruct, &b_expl_temp);
      expl_temp.reflectivity.set_size(b_expl_temp.reflectivity.size(0));
      b_loop_ub = b_expl_temp.reflectivity.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        expl_temp.reflectivity[i1] = b_expl_temp.reflectivity[i1];
      }

      expl_temp.sldProfiles.set_size(b_expl_temp.sldProfiles.size(0),
        b_expl_temp.sldProfiles.size(1));
      b_loop_ub = b_expl_temp.sldProfiles.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        k = b_expl_temp.sldProfiles.size(0);
        for (i2 = 0; i2 < k; i2++) {
          expl_temp.sldProfiles[i2 + expl_temp.sldProfiles.size(0) * i1] =
            b_expl_temp.sldProfiles[i2 + b_expl_temp.sldProfiles.size(0) * i1];
        }
      }

      allPredInts->sampleChi[b_i] = b_expl_temp.calculationResults.sumChi;
      for (int32_T n{0}; n < i; n++) {
        b_loop_ub = expl_temp.reflectivity[n].f1.size(0);
        c_expl_temp.set_size(expl_temp.reflectivity[n].f1.size(0));
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          c_expl_temp[i1] = expl_temp.reflectivity[n].f1[i1];
        }

        b_loop_ub = expl_temp.reflectivity[n].f1.size(0);
        d_expl_temp.set_size(expl_temp.reflectivity[n].f1.size(0));
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          d_expl_temp[i1] = expl_temp.reflectivity[n].f1[i1 +
            expl_temp.reflectivity[n].f1.size(0)];
        }

        coder::interp1(c_expl_temp, d_expl_temp, allPredInts->
                       reflectivityXData[n].f1, r2);
        b_loop_ub = r2.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          refYVals[n].f1[b_i + refYVals[n].f1.size(0) * i1] = r2[i1];
        }

        //  Automatically comes back as a row from inpterp1
        if (!domains) {
          b_loop_ub = expl_temp.sldProfiles[n].f1.size(0);
          c_expl_temp.set_size(expl_temp.sldProfiles[n].f1.size(0));
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            c_expl_temp[i1] = expl_temp.sldProfiles[n].f1[i1];
          }

          b_loop_ub = expl_temp.sldProfiles[n].f1.size(0);
          d_expl_temp.set_size(expl_temp.sldProfiles[n].f1.size(0));
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            d_expl_temp[i1] = expl_temp.sldProfiles[n].f1[i1 +
              expl_temp.sldProfiles[n].f1.size(0)];
          }

          coder::interp1(c_expl_temp, d_expl_temp, allPredInts->sldXData[n].f1,
                         r2);
          b_loop_ub = r2.size(1);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            sldYVals[n].f1[b_i + sldYVals[n].f1.size(0) * i1] = r2[i1];
          }
        } else {
          for (m = 0; m < 2; m++) {
            b_loop_ub = expl_temp.sldProfiles[n + expl_temp.sldProfiles.size(0) *
              m].f1.size(0);
            c_expl_temp.set_size(expl_temp.sldProfiles[n +
                                 expl_temp.sldProfiles.size(0) * m].f1.size(0));
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              c_expl_temp[i1] = expl_temp.sldProfiles[n +
                expl_temp.sldProfiles.size(0) * m].f1[i1];
            }

            b_loop_ub = expl_temp.sldProfiles[n + expl_temp.sldProfiles.size(0) *
              m].f1.size(0);
            d_expl_temp.set_size(expl_temp.sldProfiles[n +
                                 expl_temp.sldProfiles.size(0) * m].f1.size(0));
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              d_expl_temp[i1] = expl_temp.sldProfiles[n +
                expl_temp.sldProfiles.size(0) * m].f1[i1 +
                expl_temp.sldProfiles[n + expl_temp.sldProfiles.size(0) * m].
                f1.size(0)];
            }

            coder::interp1(c_expl_temp, d_expl_temp, allPredInts->sldXData[n +
                           allPredInts->sldXData.size(0) * m].f1, r2);
            b_loop_ub = r2.size(1);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              sldYVals[n + sldYVals.size(0) * m].f1[b_i + sldYVals[n +
                sldYVals.size(0) * m].f1.size(0) * i1] = r2[i1];
            }
          }
        }
      }
    }

    //  Calculate the percentiles across all the calculated samples for each
    //  point in x... We calculate 95% and 65% CI's for each set of curves
    //  Reflectivity..
    i = static_cast<int32_T>(numberOfContrasts);
    i1 = static_cast<int32_T>(numberOfContrasts);
    allPredInts->reflectivity.set_size(i1);
    for (b_i = 0; b_i < i; b_i++) {
      refArray.set_size(5, refYVals[b_i].f1.size(1));
      loop_ub = refYVals[b_i].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < 5; i2++) {
          refArray[i2 + 5 * i1] = 0.0;
        }
      }

      //  We could possibly use CIFn in one shot here (rather than loop over
      //  points....)
      i1 = refYVals[b_i].f1.size(1);
      if (0 <= refYVals[b_i].f1.size(1) - 1) {
        refYVals_size = refYVals[b_i].f1.size(0);
        c_loop_ub = refYVals[b_i].f1.size(0);
        b_refYVals_size = refYVals[b_i].f1.size(0);
        d_loop_ub = refYVals[b_i].f1.size(0);
        c_refYVals_size = refYVals[b_i].f1.size(0);
        e_loop_ub = refYVals[b_i].f1.size(0);
      }

      for (points = 0; points < i1; points++) {
        for (i2 = 0; i2 < c_loop_ub; i2++) {
          a[i2] = refYVals[b_i].f1[i2 + refYVals[b_i].f1.size(0) * points];
        }

        coder::prctile(a, refYVals_size, ci95);
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          a[i2] = refYVals[b_i].f1[i2 + refYVals[b_i].f1.size(0) * points];
        }

        coder::b_prctile(a, b_refYVals_size, ci65);
        for (i2 = 0; i2 < e_loop_ub; i2++) {
          a[i2] = refYVals[b_i].f1[i2 + refYVals[b_i].f1.size(0) * points];
        }

        refArray[5 * points] = ci95[0];
        refArray[5 * points + 1] = ci65[0];
        refArray[5 * points + 2] = coder::mean(a, c_refYVals_size);
        refArray[5 * points + 3] = ci65[1];
        refArray[5 * points + 4] = ci95[1];
      }

      allPredInts->reflectivity[b_i].f1.set_size(5, refArray.size(1));
      loop_ub = refArray.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < 5; i2++) {
          allPredInts->reflectivity[b_i].f1[i2 + 5 * i1] = refArray[i2 + 5 * i1];
        }
      }
    }

    //  Also the SLD's
    if (!domains) {
      i = static_cast<int32_T>(numberOfContrasts);
      i1 = static_cast<int32_T>(numberOfContrasts);
      allPredInts->sld.set_size(i1, 1);
      for (b_i = 0; b_i < i; b_i++) {
        sldArray.set_size(5, sldYVals[b_i].f1.size(1));
        loop_ub = sldYVals[b_i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 5; i2++) {
            sldArray[i2 + 5 * i1] = 0.0;
          }
        }

        i1 = sldYVals[b_i].f1.size(1);
        for (points = 0; points < i1; points++) {
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * points];
          }

          coder::prctile(a, refYVals_size, ci95);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * points];
          }

          coder::b_prctile(a, refYVals_size, ci65);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * points];
          }

          sldArray[5 * points] = ci95[0];
          sldArray[5 * points + 1] = ci65[0];
          sldArray[5 * points + 2] = coder::mean(a, refYVals_size);
          sldArray[5 * points + 3] = ci65[1];
          sldArray[5 * points + 4] = ci95[1];
        }

        allPredInts->sld[b_i].f1.set_size(5, sldArray.size(1));
        loop_ub = sldArray.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 5; i2++) {
            allPredInts->sld[b_i].f1[i2 + 5 * i1] = sldArray[i2 + 5 * i1];
          }
        }
      }
    } else {
      i = static_cast<int32_T>(numberOfContrasts);
      i1 = static_cast<int32_T>(numberOfContrasts);
      allPredInts->sld.set_size(i1, 2);
      for (b_i = 0; b_i < i; b_i++) {
        sldArray1.set_size(5, sldYVals[b_i].f1.size(1));
        loop_ub = sldYVals[b_i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 5; i2++) {
            sldArray1[i2 + 5 * i1] = 0.0;
          }
        }

        sldArray2.set_size(5, sldYVals[b_i + sldYVals.size(0)].f1.size(1));
        loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 5; i2++) {
            sldArray2[i2 + 5 * i1] = 0.0;
          }
        }

        i1 = sldYVals[b_i].f1.size(1);
        for (points = 0; points < i1; points++) {
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * points];
          }

          coder::prctile(a, refYVals_size, ci951);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * points];
          }

          coder::b_prctile(a, refYVals_size, ci651);
          loop_ub = sldYVals[b_i].f1.size(0);
          refYVals_size = sldYVals[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i].f1[i2 + sldYVals[b_i].f1.size(0) * points];
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
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i + sldYVals.size(0)].f1[i2 + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * points];
          }

          coder::prctile(a, refYVals_size, ci952);
          loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          refYVals_size = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i + sldYVals.size(0)].f1[i2 + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * points];
          }

          coder::b_prctile(a, refYVals_size, ci652);
          loop_ub = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          refYVals_size = sldYVals[b_i + sldYVals.size(0)].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            a[i2] = sldYVals[b_i + sldYVals.size(0)].f1[i2 + sldYVals[b_i +
              sldYVals.size(0)].f1.size(0) * points];
          }

          sldArray2[5 * points] = ci952[0];
          sldArray2[5 * points + 1] = ci652[0];
          sldArray2[5 * points + 2] = coder::mean(a, refYVals_size);
          sldArray2[5 * points + 3] = ci652[1];
          sldArray2[5 * points + 4] = ci952[1];
        }

        allPredInts->sld[b_i].f1.set_size(5, sldArray1.size(1));
        loop_ub = sldArray1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 5; i2++) {
            allPredInts->sld[b_i].f1[i2 + 5 * i1] = sldArray1[i2 + 5 * i1];
          }
        }

        allPredInts->sld[b_i + allPredInts->sld.size(0)].f1.set_size(5,
          sldArray2.size(1));
        loop_ub = sldArray2.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 5; i2++) {
            allPredInts->sld[b_i + allPredInts->sld.size(0)].f1[i2 + 5 * i1] =
              sldArray2[i2 + 5 * i1];
          }
        }
      }
    }
  }
}

// End of code generation (refPercentileConfidenceIntervals.cpp)
