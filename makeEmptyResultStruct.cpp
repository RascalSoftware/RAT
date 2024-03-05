//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeEmptyResultStruct.cpp
//
// Code generation for function 'makeEmptyResultStruct'
//

// Include files
#include "makeEmptyResultStruct.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "structConstructorHelper.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<real_T, 1U> &t17_ssubs, const ::coder::
                   array<real_T, 1U> &t17_backgroundParams, const ::coder::array<
                   real_T, 1U> &t17_qzshifts, const ::coder::array<real_T, 1U>
                   &t17_scalefactors, const ::coder::array<real_T, 1U>
                   &t17_bulkIn, const ::coder::array<real_T, 1U> &t17_bulkOut,
                   const ::coder::array<real_T, 1U> &t17_resolutionParams, const
                   ::coder::array<real_T, 1U> &t17_allSubRough, const ::coder::
                   array<real_T, 2U> &t17_resample, b_struct_T *b);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<real_T, 1U> &t17_ssubs, const ::coder::
                   array<real_T, 1U> &t17_backgroundParams, const ::coder::array<
                   real_T, 1U> &t17_qzshifts, const ::coder::array<real_T, 1U>
                   &t17_scalefactors, const ::coder::array<real_T, 1U>
                   &t17_bulkIn, const ::coder::array<real_T, 1U> &t17_bulkOut,
                   const ::coder::array<real_T, 1U> &t17_resolutionParams, const
                   ::coder::array<real_T, 1U> &t17_allSubRough, const ::coder::
                   array<real_T, 2U> &t17_resample, b_struct_T *b)
  {
    int32_T i;
    int32_T loop_ub;
    b->ssubs.set_size(t17_ssubs.size(0));
    loop_ub = t17_ssubs.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->ssubs[i] = t17_ssubs[i];
    }

    b->backgroundParams.set_size(t17_backgroundParams.size(0));
    loop_ub = t17_backgroundParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->backgroundParams[i] = t17_backgroundParams[i];
    }

    b->qzshifts.set_size(t17_qzshifts.size(0));
    loop_ub = t17_qzshifts.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->qzshifts[i] = t17_qzshifts[i];
    }

    b->scalefactors.set_size(t17_scalefactors.size(0));
    loop_ub = t17_scalefactors.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->scalefactors[i] = t17_scalefactors[i];
    }

    b->bulkIn.set_size(t17_bulkIn.size(0));
    loop_ub = t17_bulkIn.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->bulkIn[i] = t17_bulkIn[i];
    }

    b->bulkOut.set_size(t17_bulkOut.size(0));
    loop_ub = t17_bulkOut.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->bulkOut[i] = t17_bulkOut[i];
    }

    b->resolutionParams.set_size(t17_resolutionParams.size(0));
    loop_ub = t17_resolutionParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->resolutionParams[i] = t17_resolutionParams[i];
    }

    b->allSubRough.set_size(t17_allSubRough.size(0));
    loop_ub = t17_allSubRough.size(0);
    for (i = 0; i < loop_ub; i++) {
      b->allSubRough[i] = t17_allSubRough[i];
    }

    b->resample.set_size(1, t17_resample.size(1));
    loop_ub = t17_resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      b->resample[i] = t17_resample[i];
    }
  }

  void makeEmptyResultStruct(real_T nContrasts, real_T nPars, boolean_T domains,
    ::coder::array<cell_wrap_8, 1U> &result_reflectivity, ::coder::array<
    cell_wrap_8, 1U> &result_simulation, ::coder::array<cell_wrap_26, 1U>
    &result_shiftedData, ::coder::array<cell_wrap_10, 2U> &result_layerSlds, ::
    coder::array<cell_wrap_10, 2U> &result_sldProfiles, ::coder::array<
    cell_wrap_26, 2U> &result_allLayers, struct6_T *result_calculationResults,
    b_struct_T *result_contrastParams, ::coder::array<real_T, 2U>
    &result_bestFitPars, ::coder::array<cell_wrap_1, 1U> &result_fitNames)
  {
    ::coder::array<cell_wrap_1, 1U> g_f1;
    ::coder::array<cell_wrap_10, 2U> d_f1;
    ::coder::array<cell_wrap_10, 2U> e_f1;
    ::coder::array<cell_wrap_26, 2U> f_f1;
    ::coder::array<cell_wrap_26, 1U> c_f1;
    ::coder::array<cell_wrap_8, 1U> b_f1;
    ::coder::array<cell_wrap_8, 1U> f1;
    ::coder::array<real_T, 2U> t18_resample;
    ::coder::array<real_T, 1U> t18_allSubRough;
    ::coder::array<real_T, 1U> t18_backgroundParams;
    ::coder::array<real_T, 1U> t18_bulkIn;
    ::coder::array<real_T, 1U> t18_bulkOut;
    ::coder::array<real_T, 1U> t18_qzshifts;
    ::coder::array<real_T, 1U> t18_resolutionParams;
    ::coder::array<real_T, 1U> t18_scalefactors;
    ::coder::array<real_T, 1U> t18_ssubs;
    ::coder::array<int8_T, 1U> calculationResults_allChis;
    b_struct_T r;
    c_struct_T b_expl_temp;
    cell_wrap_14 r1;
    cell_wrap_14 r2;
    cell_wrap_15 r3;
    cell_wrap_16 r4;
    cell_wrap_16 r5;
    cell_wrap_17 r6;
    cell_wrap_18 r7;
    struct6_T expl_temp;
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T loop_ub_tmp;

    //  A function to make an empty container to hold the results of
    //  reflectivity calculations. The struct has the following format:
    //
    //  nPar = number of fitted parameters
    //  nContrasts = number of contrasts
    //
    //  result =
    //
    //    struct with fields:
    //
    //        reflectivity: [nContrastsx1 cell]
    //          simulation: [nContrastsx1 cell]
    //         shiftedData: [nContrastsx1 cell]
    //           layerSlds: [nContrastsx1 cell]
    //         sldProfiles: [nContrastsx1 cell]
    //           allLayers: [nContrastsx1 cell]
    //  calculationResults: [1x1 struct]
    //      contrastParams: [1x1 struct]
    //         bestFitPars: [1xnPars double]
    //            fitNames: [nParsx1 cell]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) result.calculationResults
    loop_ub_tmp = static_cast<int32_T>(nContrasts);
    calculationResults_allChis.set_size(loop_ub_tmp);

    //  --------------------------------------------------------------------
    //  (2) result.contrastParams
    t18_ssubs.set_size(loop_ub_tmp);
    t18_backgroundParams.set_size(loop_ub_tmp);
    t18_qzshifts.set_size(loop_ub_tmp);
    t18_scalefactors.set_size(loop_ub_tmp);
    t18_bulkIn.set_size(loop_ub_tmp);
    t18_bulkOut.set_size(loop_ub_tmp);
    t18_resolutionParams.set_size(loop_ub_tmp);
    t18_allSubRough.set_size(loop_ub_tmp);
    t18_resample.set_size(1, loop_ub_tmp);

    //  -------------------------------------------------------------------
    //  Make the final structure...
    f1.set_size(loop_ub_tmp);
    b_f1.set_size(loop_ub_tmp);
    c_f1.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      calculationResults_allChis[i] = 0;
      t18_ssubs[i] = 0.0;
      t18_backgroundParams[i] = 0.0;
      t18_qzshifts[i] = 0.0;
      t18_scalefactors[i] = 0.0;
      t18_bulkIn[i] = 0.0;
      t18_bulkOut[i] = 0.0;
      t18_resolutionParams[i] = 0.0;
      t18_allSubRough[i] = 0.0;
      t18_resample[i] = 0.0;
      f1[i].f1.set_size(2, 2);
      f1[i].f1[0] = 1.0;
      f1[i].f1[1] = 1.0;
      f1[i].f1[f1[i].f1.size(0)] = 1.0;
      f1[i].f1[f1[i].f1.size(0) + 1] = 1.0;
      b_f1[i].f1.set_size(2, 2);
      b_f1[i].f1[0] = 1.0;
      b_f1[i].f1[1] = 1.0;
      b_f1[i].f1[b_f1[i].f1.size(0)] = 1.0;
      b_f1[i].f1[b_f1[i].f1.size(0) + 1] = 1.0;
      c_f1[i].f1.set_size(2, 3);
      for (b_i = 0; b_i < 3; b_i++) {
        c_f1[i].f1[c_f1[i].f1.size(0) * b_i] = 1.0;
        c_f1[i].f1[c_f1[i].f1.size(0) * b_i + 1] = 1.0;
      }
    }

    if (domains) {
      d_f1.set_size(loop_ub_tmp, 2);
      e_f1.set_size(loop_ub_tmp, 2);
      f_f1.set_size(loop_ub_tmp, 2);
      for (i = 0; i < loop_ub_tmp; i++) {
        d_f1[i].f1.set_size(2, 3);
        d_f1[i + d_f1.size(0)].f1.set_size(2, 3);
        e_f1[i].f1.set_size(2, 2);
        e_f1[i + e_f1.size(0)].f1.set_size(2, 2);
        e_f1[i].f1[0] = 1.0;
        e_f1[i + e_f1.size(0)].f1[0] = 1.0;
        e_f1[i].f1[1] = 1.0;
        e_f1[i + e_f1.size(0)].f1[1] = 1.0;
        e_f1[i].f1[e_f1[i].f1.size(0)] = 1.0;
        e_f1[i + e_f1.size(0)].f1[e_f1[i + e_f1.size(0)].f1.size(0)] = 1.0;
        e_f1[i].f1[e_f1[i].f1.size(0) + 1] = 1.0;
        e_f1[i + e_f1.size(0)].f1[e_f1[i + e_f1.size(0)].f1.size(0) + 1] = 1.0;
        f_f1[i].f1.set_size(2, 3);
        f_f1[i + f_f1.size(0)].f1.set_size(2, 3);
        for (b_i = 0; b_i < 3; b_i++) {
          d_f1[i].f1[d_f1[i].f1.size(0) * b_i] = 1.0;
          d_f1[i + d_f1.size(0)].f1[d_f1[i + d_f1.size(0)].f1.size(0) * b_i] =
            1.0;
          d_f1[i].f1[d_f1[i].f1.size(0) * b_i + 1] = 1.0;
          d_f1[i + d_f1.size(0)].f1[d_f1[i + d_f1.size(0)].f1.size(0) * b_i + 1]
            = 1.0;
          f_f1[i].f1[f_f1[i].f1.size(0) * b_i] = 1.0;
          f_f1[i + f_f1.size(0)].f1[f_f1[i + f_f1.size(0)].f1.size(0) * b_i] =
            1.0;
          f_f1[i].f1[f_f1[i].f1.size(0) * b_i + 1] = 1.0;
          f_f1[i + f_f1.size(0)].f1[f_f1[i + f_f1.size(0)].f1.size(0) * b_i + 1]
            = 1.0;
        }
      }
    } else {
      d_f1.set_size(loop_ub_tmp, 1);
      e_f1.set_size(loop_ub_tmp, 1);
      f_f1.set_size(loop_ub_tmp, 1);
      for (i = 0; i < loop_ub_tmp; i++) {
        d_f1[i].f1.set_size(2, 3);
        e_f1[i].f1.set_size(2, 2);
        e_f1[i].f1[0] = 1.0;
        e_f1[i].f1[1] = 1.0;
        e_f1[i].f1[e_f1[i].f1.size(0)] = 1.0;
        e_f1[i].f1[e_f1[i].f1.size(0) + 1] = 1.0;
        f_f1[i].f1.set_size(2, 3);
        for (b_i = 0; b_i < 3; b_i++) {
          d_f1[i].f1[d_f1[i].f1.size(0) * b_i] = 1.0;
          d_f1[i].f1[d_f1[i].f1.size(0) * b_i + 1] = 1.0;
          f_f1[i].f1[f_f1[i].f1.size(0) * b_i] = 1.0;
          f_f1[i].f1[f_f1[i].f1.size(0) * b_i + 1] = 1.0;
        }
      }
    }

    loop_ub_tmp = static_cast<int32_T>(nPars);
    g_f1.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      g_f1[i].f1.set_size(1, 0);
    }

    cast(t18_ssubs, t18_backgroundParams, t18_qzshifts, t18_scalefactors,
         t18_bulkIn, t18_bulkOut, t18_resolutionParams, t18_allSubRough,
         t18_resample, &r);
    expl_temp.sumChi = 0.0;
    expl_temp.allChis.set_size(calculationResults_allChis.size(0));
    loop_ub = calculationResults_allChis.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      expl_temp.allChis[b_i] = 0.0;
    }

    r1.f1 = f1;
    r2.f1 = b_f1;
    r3.f1 = c_f1;
    r4.f1 = d_f1;
    r5.f1 = e_f1;
    r6.f1 = f_f1;
    t18_resample.set_size(1, loop_ub_tmp);
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      t18_resample[b_i] = 0.0;
    }

    r7.f1 = g_f1;
    coder::internal::structConstructorHelper(&r1, &r2, &r3, &r4, &r5, &r6,
      &expl_temp, &r, t18_resample, &r7, &b_expl_temp);
    result_reflectivity.set_size(b_expl_temp.reflectivity.size(0));
    loop_ub = b_expl_temp.reflectivity.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_reflectivity[b_i] = b_expl_temp.reflectivity[b_i];
    }

    result_simulation.set_size(b_expl_temp.simulation.size(0));
    loop_ub = b_expl_temp.simulation.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_simulation[b_i] = b_expl_temp.simulation[b_i];
    }

    result_shiftedData.set_size(b_expl_temp.shiftedData.size(0));
    loop_ub = b_expl_temp.shiftedData.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_shiftedData[b_i] = b_expl_temp.shiftedData[b_i];
    }

    result_layerSlds.set_size(b_expl_temp.layerSlds.size(0),
      b_expl_temp.layerSlds.size(1));
    loop_ub = b_expl_temp.layerSlds.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loop_ub_tmp = b_expl_temp.layerSlds.size(0);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result_layerSlds[i1 + result_layerSlds.size(0) * b_i] =
          b_expl_temp.layerSlds[i1 + b_expl_temp.layerSlds.size(0) * b_i];
      }
    }

    result_sldProfiles.set_size(b_expl_temp.sldProfiles.size(0),
      b_expl_temp.sldProfiles.size(1));
    loop_ub = b_expl_temp.sldProfiles.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loop_ub_tmp = b_expl_temp.sldProfiles.size(0);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result_sldProfiles[i1 + result_sldProfiles.size(0) * b_i] =
          b_expl_temp.sldProfiles[i1 + b_expl_temp.sldProfiles.size(0) * b_i];
      }
    }

    result_allLayers.set_size(b_expl_temp.allLayers.size(0),
      b_expl_temp.allLayers.size(1));
    loop_ub = b_expl_temp.allLayers.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loop_ub_tmp = b_expl_temp.allLayers.size(0);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result_allLayers[i1 + result_allLayers.size(0) * b_i] =
          b_expl_temp.allLayers[i1 + b_expl_temp.allLayers.size(0) * b_i];
      }
    }

    *result_calculationResults = b_expl_temp.calculationResults;
    *result_contrastParams = b_expl_temp.contrastParams;
    result_bestFitPars.set_size(1, b_expl_temp.bestFitPars.size(1));
    loop_ub = b_expl_temp.bestFitPars.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_bestFitPars[b_i] = b_expl_temp.bestFitPars[b_i];
    }

    result_fitNames.set_size(b_expl_temp.fitNames.size(0));
    loop_ub = b_expl_temp.fitNames.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_fitNames[b_i] = b_expl_temp.fitNames[b_i];
    }
  }
}

// End of code generation (makeEmptyResultStruct.cpp)
