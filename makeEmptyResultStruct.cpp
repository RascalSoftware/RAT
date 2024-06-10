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
  static void cast(const ::coder::array<real_T, 1U> &t12_backgroundParams, const
                   ::coder::array<real_T, 1U> &t12_scalefactors, const ::coder::
                   array<real_T, 1U> &t12_bulkIn, const ::coder::array<real_T,
                   1U> &t12_bulkOut, const ::coder::array<real_T, 1U>
                   &t12_resolutionParams, const ::coder::array<real_T, 1U>
                   &t12_subRoughs, const ::coder::array<real_T, 2U>
                   &t12_resample, ::coder::array<real_T, 1U>
                   &t13_backgroundParams, ::coder::array<real_T, 1U>
                   &t13_scalefactors, ::coder::array<real_T, 1U> &t13_bulkIn, ::
                   coder::array<real_T, 1U> &t13_bulkOut, ::coder::array<real_T,
                   1U> &t13_resolutionParams, ::coder::array<real_T, 1U>
                   &t13_subRoughs, ::coder::array<real_T, 2U> &t13_resample);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<real_T, 1U> &t12_backgroundParams, const
                   ::coder::array<real_T, 1U> &t12_scalefactors, const ::coder::
                   array<real_T, 1U> &t12_bulkIn, const ::coder::array<real_T,
                   1U> &t12_bulkOut, const ::coder::array<real_T, 1U>
                   &t12_resolutionParams, const ::coder::array<real_T, 1U>
                   &t12_subRoughs, const ::coder::array<real_T, 2U>
                   &t12_resample, ::coder::array<real_T, 1U>
                   &t13_backgroundParams, ::coder::array<real_T, 1U>
                   &t13_scalefactors, ::coder::array<real_T, 1U> &t13_bulkIn, ::
                   coder::array<real_T, 1U> &t13_bulkOut, ::coder::array<real_T,
                   1U> &t13_resolutionParams, ::coder::array<real_T, 1U>
                   &t13_subRoughs, ::coder::array<real_T, 2U> &t13_resample)
  {
    int32_T i;
    int32_T loop_ub;
    t13_backgroundParams.set_size(t12_backgroundParams.size(0));
    loop_ub = t12_backgroundParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      t13_backgroundParams[i] = t12_backgroundParams[i];
    }

    t13_scalefactors.set_size(t12_scalefactors.size(0));
    loop_ub = t12_scalefactors.size(0);
    for (i = 0; i < loop_ub; i++) {
      t13_scalefactors[i] = t12_scalefactors[i];
    }

    t13_bulkIn.set_size(t12_bulkIn.size(0));
    loop_ub = t12_bulkIn.size(0);
    for (i = 0; i < loop_ub; i++) {
      t13_bulkIn[i] = t12_bulkIn[i];
    }

    t13_bulkOut.set_size(t12_bulkOut.size(0));
    loop_ub = t12_bulkOut.size(0);
    for (i = 0; i < loop_ub; i++) {
      t13_bulkOut[i] = t12_bulkOut[i];
    }

    t13_resolutionParams.set_size(t12_resolutionParams.size(0));
    loop_ub = t12_resolutionParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      t13_resolutionParams[i] = t12_resolutionParams[i];
    }

    t13_subRoughs.set_size(t12_subRoughs.size(0));
    loop_ub = t12_subRoughs.size(0);
    for (i = 0; i < loop_ub; i++) {
      t13_subRoughs[i] = t12_subRoughs[i];
    }

    t13_resample.set_size(1, t12_resample.size(1));
    loop_ub = t12_resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      t13_resample[i] = t12_resample[i];
    }
  }

  void makeEmptyResultStruct(real_T nContrasts, real_T nParams, boolean_T
    domains, ::coder::array<cell_wrap_8, 1U> &result_reflectivity, ::coder::
    array<cell_wrap_8, 1U> &result_simulation, ::coder::array<cell_wrap_38, 1U>
    &result_shiftedData, ::coder::array<cell_wrap_10, 2U> &result_layerSlds, ::
    coder::array<cell_wrap_10, 2U> &result_sldProfiles, ::coder::array<
    cell_wrap_38, 2U> &result_resampledLayers, struct6_T
    *result_calculationResults, c_struct_T *result_contrastParams, ::coder::
    array<real_T, 2U> &result_fitParams, ::coder::array<cell_wrap_1, 1U>
    &result_fitNames)
  {
    ::coder::array<cell_wrap_1, 1U> g_f1;
    ::coder::array<cell_wrap_10, 2U> d_f1;
    ::coder::array<cell_wrap_10, 2U> e_f1;
    ::coder::array<cell_wrap_38, 2U> f_f1;
    ::coder::array<cell_wrap_38, 1U> c_f1;
    ::coder::array<cell_wrap_8, 1U> b_f1;
    ::coder::array<cell_wrap_8, 1U> f1;
    ::coder::array<real_T, 2U> t14_resample;
    ::coder::array<real_T, 1U> t14_backgroundParams;
    ::coder::array<real_T, 1U> t14_bulkIn;
    ::coder::array<real_T, 1U> t14_bulkOut;
    ::coder::array<real_T, 1U> t14_resolutionParams;
    ::coder::array<real_T, 1U> t14_scalefactors;
    ::coder::array<real_T, 1U> t14_subRoughs;
    ::coder::array<int8_T, 1U> calculationResults_chiValues;
    c_struct_T expl_temp;
    cell_wrap_27 r;
    cell_wrap_27 r1;
    cell_wrap_28 r2;
    cell_wrap_29 r3;
    cell_wrap_29 r4;
    cell_wrap_30 r5;
    cell_wrap_31 r6;
    d_struct_T c_expl_temp;
    struct6_T b_expl_temp;
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
    //     resampledLayers: [nContrastsx1 cell]
    //  calculationResults: [1x1 struct]
    //      contrastParams: [1x1 struct]
    //           fitParams: [1xnParams double]
    //            fitNames: [nParamsx1 cell]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) result.calculationResults
    loop_ub_tmp = static_cast<int32_T>(nContrasts);
    calculationResults_chiValues.set_size(loop_ub_tmp);

    //  --------------------------------------------------------------------
    //  (2) result.contrastParams
    t14_backgroundParams.set_size(loop_ub_tmp);
    t14_scalefactors.set_size(loop_ub_tmp);
    t14_bulkIn.set_size(loop_ub_tmp);
    t14_bulkOut.set_size(loop_ub_tmp);
    t14_resolutionParams.set_size(loop_ub_tmp);
    t14_subRoughs.set_size(loop_ub_tmp);
    t14_resample.set_size(1, loop_ub_tmp);

    //  -------------------------------------------------------------------
    //  Make the final structure...
    f1.set_size(loop_ub_tmp);
    b_f1.set_size(loop_ub_tmp);
    c_f1.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      calculationResults_chiValues[i] = 0;
      t14_backgroundParams[i] = 0.0;
      t14_scalefactors[i] = 0.0;
      t14_bulkIn[i] = 0.0;
      t14_bulkOut[i] = 0.0;
      t14_resolutionParams[i] = 0.0;
      t14_subRoughs[i] = 0.0;
      t14_resample[i] = 0.0;
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

    loop_ub_tmp = static_cast<int32_T>(nParams);
    g_f1.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      g_f1[i].f1.set_size(1, 0);
    }

    cast(t14_backgroundParams, t14_scalefactors, t14_bulkIn, t14_bulkOut,
         t14_resolutionParams, t14_subRoughs, t14_resample,
         expl_temp.backgroundParams, expl_temp.scalefactors, expl_temp.bulkIn,
         expl_temp.bulkOut, expl_temp.resolutionParams, expl_temp.subRoughs,
         expl_temp.resample);
    b_expl_temp.sumChi = 0.0;
    b_expl_temp.chiValues.set_size(calculationResults_chiValues.size(0));
    loop_ub = calculationResults_chiValues.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_expl_temp.chiValues[b_i] = 0.0;
    }

    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    r3.f1 = d_f1;
    r4.f1 = e_f1;
    r5.f1 = f_f1;
    t14_resample.set_size(1, loop_ub_tmp);
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      t14_resample[b_i] = 0.0;
    }

    r6.f1 = g_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4, &r5,
      &b_expl_temp, &expl_temp, t14_resample, &r6, &c_expl_temp);
    result_reflectivity.set_size(c_expl_temp.reflectivity.size(0));
    loop_ub = c_expl_temp.reflectivity.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_reflectivity[b_i] = c_expl_temp.reflectivity[b_i];
    }

    result_simulation.set_size(c_expl_temp.simulation.size(0));
    loop_ub = c_expl_temp.simulation.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_simulation[b_i] = c_expl_temp.simulation[b_i];
    }

    result_shiftedData.set_size(c_expl_temp.shiftedData.size(0));
    loop_ub = c_expl_temp.shiftedData.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_shiftedData[b_i] = c_expl_temp.shiftedData[b_i];
    }

    result_layerSlds.set_size(c_expl_temp.layerSlds.size(0),
      c_expl_temp.layerSlds.size(1));
    loop_ub = c_expl_temp.layerSlds.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loop_ub_tmp = c_expl_temp.layerSlds.size(0);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result_layerSlds[i1 + result_layerSlds.size(0) * b_i] =
          c_expl_temp.layerSlds[i1 + c_expl_temp.layerSlds.size(0) * b_i];
      }
    }

    result_sldProfiles.set_size(c_expl_temp.sldProfiles.size(0),
      c_expl_temp.sldProfiles.size(1));
    loop_ub = c_expl_temp.sldProfiles.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loop_ub_tmp = c_expl_temp.sldProfiles.size(0);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result_sldProfiles[i1 + result_sldProfiles.size(0) * b_i] =
          c_expl_temp.sldProfiles[i1 + c_expl_temp.sldProfiles.size(0) * b_i];
      }
    }

    result_resampledLayers.set_size(c_expl_temp.resampledLayers.size(0),
      c_expl_temp.resampledLayers.size(1));
    loop_ub = c_expl_temp.resampledLayers.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loop_ub_tmp = c_expl_temp.resampledLayers.size(0);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result_resampledLayers[i1 + result_resampledLayers.size(0) * b_i] =
          c_expl_temp.resampledLayers[i1 + c_expl_temp.resampledLayers.size(0) *
          b_i];
      }
    }

    *result_calculationResults = c_expl_temp.calculationResults;
    *result_contrastParams = c_expl_temp.contrastParams;
    result_fitParams.set_size(1, c_expl_temp.fitParams.size(1));
    loop_ub = c_expl_temp.fitParams.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_fitParams[b_i] = c_expl_temp.fitParams[b_i];
    }

    result_fitNames.set_size(c_expl_temp.fitNames.size(0));
    loop_ub = c_expl_temp.fitNames.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      result_fitNames[b_i] = c_expl_temp.fitNames[b_i];
    }
  }
}

// End of code generation (makeEmptyResultStruct.cpp)
