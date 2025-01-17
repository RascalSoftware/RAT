//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation.cpp
//
// Code generation for function 'reflectivityCalculation'
//

// Include files
#include "reflectivityCalculation.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "customLayers.h"
#include "customLayers1.h"
#include "customXY.h"
#include "customXY1.h"
#include "getFitNames.h"
#include "lower.h"
#include "rt_nonfinite.h"
#include "standardLayers.h"
#include "standardLayers1.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  void b_reflectivityCalculation(const e_struct_T *problemStruct, const
    struct4_T *controls, struct6_T *result)
  {
    ::coder::array<cell_wrap_11, 2U> layerSlds;
    ::coder::array<cell_wrap_11, 2U> resampledLayers;
    ::coder::array<cell_wrap_11, 2U> sldProfiles;
    ::coder::array<real_T, 1U> qzshifts;
    real_T y;
    int32_T switch_expression_size[2];
    int32_T b_index;
    int32_T i;
    char_T switch_expression_data[10000];

    //  Main entry point into the reflectivity calculation for the toolbox.
    //  This is the main function that is called by any of the minimisers or
    //  analysis tools from the rest of the toolbox.
    //
    //  The main job of this function is to decide which type of calculation
    //  (i.e. 'Target function') is required, and call the relevant routines.
    //  Different model types are specified in sub functions.
    //  The types of available target functions are:
    //
    //  * normal    - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples.
    //
    //  * oil water - Target function for oil-water samples
    //
    //  * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  * magnetic  - Target function for cases for polarised neutrons with polarisation analysis.
    //
    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::h_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      b_index = 0;
    } else if (coder::internal::i_strcmp(problemStruct->TF.data,
                problemStruct->TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      coder::lower(problemStruct->modelType.data, problemStruct->modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::j_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::k_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::l_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        normalTF::b_standardLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 1:
        normalTF::c_customLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 2:
        normalTF::b_customXY(problemStruct, controls, qzshifts,
                             result->contrastParams.scalefactors,
                             result->contrastParams.bulkIn,
                             result->contrastParams.bulkOut,
                             result->calculationResults.chiValues,
                             result->reflectivity, result->simulation,
                             result->shiftedData, result->backgrounds,
                             result->resolutions, layerSlds, sldProfiles,
                             resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;
      }

      // case coderEnums.calculationTypes.OilWater
      // contrastParams = oilWaterTFReflectivityCalculation(problemStruct,controls);
      // case coderEnums.calculationTypes.Magnetic
      // contrastParams = polarisedTFReflectivityCalculation(problemStruct,controls);
      break;

     case 1:
      {
        coder::lower(problemStruct->modelType.data,
                     problemStruct->modelType.size, switch_expression_data,
                     switch_expression_size);
        if (coder::internal::j_strcmp(switch_expression_data,
             switch_expression_size)) {
          b_index = 0;
        } else if (coder::internal::k_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 1;
        } else if (coder::internal::l_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 2;
        } else {
          b_index = -1;
        }

        switch (b_index) {
         case 0:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::b_standardLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 1:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::c_customLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 2:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::b_customXY(problemStruct, controls, qzshifts,
                                  result->contrastParams.scalefactors,
                                  result->contrastParams.bulkIn,
                                  result->contrastParams.bulkOut,
                                  result->calculationResults.chiValues,
                                  result->reflectivity, result->simulation,
                                  result->shiftedData, result->backgrounds,
                                  result->resolutions, layerSlds, sldProfiles,
                                  resampledLayers,
                                  result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;
        }
      }
      break;
    }

    //  Make the result struct
    if (result->calculationResults.chiValues.size(0) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(result->calculationResults.chiValues,
                            result->calculationResults.chiValues.size(0));
    }

    result->calculationResults.sumChi = y;
    result->contrastParams.resample.set_size(1, problemStruct->resample.size(1));
    b_index = problemStruct->resample.size(1);
    for (i = 0; i < b_index; i++) {
      result->contrastParams.resample[i] = problemStruct->resample[i];
    }

    result->fitParams.set_size(1, problemStruct->fitParams.size(1));
    b_index = problemStruct->fitParams.size(1);
    for (i = 0; i < b_index; i++) {
      result->fitParams[i] = problemStruct->fitParams[i];
    }

    getFitNames(problemStruct->names.params,
                problemStruct->names.backgroundParams,
                problemStruct->names.scalefactors, problemStruct->names.qzshifts,
                problemStruct->names.bulkIns, problemStruct->names.bulkOuts,
                problemStruct->names.resolutionParams,
                problemStruct->names.domainRatios, problemStruct->checks.params,
                problemStruct->checks.backgroundParams,
                problemStruct->checks.scalefactors,
                problemStruct->checks.qzshifts, problemStruct->checks.bulkIns,
                problemStruct->checks.bulkOuts,
                problemStruct->checks.resolutionParams,
                problemStruct->checks.domainRatios, result->fitNames);
  }

  void reflectivityCalculation(const e_struct_T *problemStruct, const struct4_T *
    controls, struct6_T *result)
  {
    ::coder::array<cell_wrap_11, 2U> layerSlds;
    ::coder::array<cell_wrap_11, 2U> resampledLayers;
    ::coder::array<cell_wrap_11, 2U> sldProfiles;
    ::coder::array<real_T, 1U> qzshifts;
    real_T y;
    int32_T switch_expression_size[2];
    int32_T b_index;
    int32_T i;
    char_T switch_expression_data[10000];

    //  Main entry point into the reflectivity calculation for the toolbox.
    //  This is the main function that is called by any of the minimisers or
    //  analysis tools from the rest of the toolbox.
    //
    //  The main job of this function is to decide which type of calculation
    //  (i.e. 'Target function') is required, and call the relevant routines.
    //  Different model types are specified in sub functions.
    //  The types of available target functions are:
    //
    //  * normal    - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples.
    //
    //  * oil water - Target function for oil-water samples
    //
    //  * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  * magnetic  - Target function for cases for polarised neutrons with polarisation analysis.
    //
    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::h_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      b_index = 0;
    } else if (coder::internal::i_strcmp(problemStruct->TF.data,
                problemStruct->TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      coder::lower(problemStruct->modelType.data, problemStruct->modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::j_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::k_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::l_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        normalTF::standardLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 1:
        normalTF::b_customLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 2:
        normalTF::b_customXY(problemStruct, controls, qzshifts,
                             result->contrastParams.scalefactors,
                             result->contrastParams.bulkIn,
                             result->contrastParams.bulkOut,
                             result->calculationResults.chiValues,
                             result->reflectivity, result->simulation,
                             result->shiftedData, result->backgrounds,
                             result->resolutions, layerSlds, sldProfiles,
                             resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;
      }

      // case coderEnums.calculationTypes.OilWater
      // contrastParams = oilWaterTFReflectivityCalculation(problemStruct,controls);
      // case coderEnums.calculationTypes.Magnetic
      // contrastParams = polarisedTFReflectivityCalculation(problemStruct,controls);
      break;

     case 1:
      {
        coder::lower(problemStruct->modelType.data,
                     problemStruct->modelType.size, switch_expression_data,
                     switch_expression_size);
        if (coder::internal::j_strcmp(switch_expression_data,
             switch_expression_size)) {
          b_index = 0;
        } else if (coder::internal::k_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 1;
        } else if (coder::internal::l_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 2;
        } else {
          b_index = -1;
        }

        switch (b_index) {
         case 0:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::standardLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 1:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::b_customLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 2:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::b_customXY(problemStruct, controls, qzshifts,
                                  result->contrastParams.scalefactors,
                                  result->contrastParams.bulkIn,
                                  result->contrastParams.bulkOut,
                                  result->calculationResults.chiValues,
                                  result->reflectivity, result->simulation,
                                  result->shiftedData, result->backgrounds,
                                  result->resolutions, layerSlds, sldProfiles,
                                  resampledLayers,
                                  result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;
        }
      }
      break;
    }

    //  Make the result struct
    if (result->calculationResults.chiValues.size(0) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(result->calculationResults.chiValues,
                            result->calculationResults.chiValues.size(0));
    }

    result->calculationResults.sumChi = y;
    result->contrastParams.resample.set_size(1, problemStruct->resample.size(1));
    b_index = problemStruct->resample.size(1);
    for (i = 0; i < b_index; i++) {
      result->contrastParams.resample[i] = problemStruct->resample[i];
    }

    result->fitParams.set_size(1, problemStruct->fitParams.size(1));
    b_index = problemStruct->fitParams.size(1);
    for (i = 0; i < b_index; i++) {
      result->fitParams[i] = problemStruct->fitParams[i];
    }

    getFitNames(problemStruct->names.params,
                problemStruct->names.backgroundParams,
                problemStruct->names.scalefactors, problemStruct->names.qzshifts,
                problemStruct->names.bulkIns, problemStruct->names.bulkOuts,
                problemStruct->names.resolutionParams,
                problemStruct->names.domainRatios, problemStruct->checks.params,
                problemStruct->checks.backgroundParams,
                problemStruct->checks.scalefactors,
                problemStruct->checks.qzshifts, problemStruct->checks.bulkIns,
                problemStruct->checks.bulkOuts,
                problemStruct->checks.resolutionParams,
                problemStruct->checks.domainRatios, result->fitNames);
  }

  void reflectivityCalculation(const e_struct_T *problemStruct, const struct4_T *
    controls, f_struct_T *result)
  {
    ::coder::array<cell_wrap_11, 2U> layerSlds;
    ::coder::array<cell_wrap_11, 2U> resampledLayers;
    ::coder::array<cell_wrap_11, 2U> sldProfiles;
    ::coder::array<real_T, 1U> qzshifts;
    real_T y;
    int32_T switch_expression_size[2];
    int32_T b_index;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    char_T switch_expression_data[10000];

    //  Main entry point into the reflectivity calculation for the toolbox.
    //  This is the main function that is called by any of the minimisers or
    //  analysis tools from the rest of the toolbox.
    //
    //  The main job of this function is to decide which type of calculation
    //  (i.e. 'Target function') is required, and call the relevant routines.
    //  Different model types are specified in sub functions.
    //  The types of available target functions are:
    //
    //  * normal    - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples.
    //
    //  * oil water - Target function for oil-water samples
    //
    //  * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  * magnetic  - Target function for cases for polarised neutrons with polarisation analysis.
    //
    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::h_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      b_index = 0;
    } else if (coder::internal::i_strcmp(problemStruct->TF.data,
                problemStruct->TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      coder::lower(problemStruct->modelType.data, problemStruct->modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::j_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::k_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::l_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        normalTF::b_standardLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 1:
        normalTF::c_customLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 2:
        normalTF::b_customXY(problemStruct, controls, qzshifts,
                             result->contrastParams.scalefactors,
                             result->contrastParams.bulkIn,
                             result->contrastParams.bulkOut,
                             result->calculationResults.chiValues,
                             result->reflectivity, result->simulation,
                             result->shiftedData, result->backgrounds,
                             result->resolutions, layerSlds, sldProfiles,
                             resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;
      }

      // case coderEnums.calculationTypes.OilWater
      // contrastParams = oilWaterTFReflectivityCalculation(problemStruct,controls);
      // case coderEnums.calculationTypes.Magnetic
      // contrastParams = polarisedTFReflectivityCalculation(problemStruct,controls);
      break;

     case 1:
      {
        coder::lower(problemStruct->modelType.data,
                     problemStruct->modelType.size, switch_expression_data,
                     switch_expression_size);
        if (coder::internal::j_strcmp(switch_expression_data,
             switch_expression_size)) {
          b_index = 0;
        } else if (coder::internal::k_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 1;
        } else if (coder::internal::l_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 2;
        } else {
          b_index = -1;
        }

        switch (b_index) {
         case 0:
          {
            int32_T b_loop_ub;
            domainsTF::b_standardLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 1:
          {
            int32_T b_loop_ub;
            domainsTF::c_customLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 2:
          {
            int32_T b_loop_ub;
            domainsTF::b_customXY(problemStruct, controls, qzshifts,
                                  result->contrastParams.scalefactors,
                                  result->contrastParams.bulkIn,
                                  result->contrastParams.bulkOut,
                                  result->calculationResults.chiValues,
                                  result->reflectivity, result->simulation,
                                  result->shiftedData, result->backgrounds,
                                  result->resolutions, layerSlds, sldProfiles,
                                  resampledLayers,
                                  result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;
        }
      }
      break;
    }

    //  Make the result struct
    if (result->calculationResults.chiValues.size(0) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(result->calculationResults.chiValues,
                            result->calculationResults.chiValues.size(0));
    }

    result->calculationResults.sumChi = y;
    result->contrastParams.resample.set_size(1, problemStruct->resample.size(1));
    b_index = problemStruct->resample.size(1);
    for (i = 0; i < b_index; i++) {
      result->contrastParams.resample[i] = problemStruct->resample[i];
    }

    result->fitParams.set_size(problemStruct->fitParams.size(0),
      problemStruct->fitParams.size(1));
    b_index = problemStruct->fitParams.size(1);
    for (i = 0; i < b_index; i++) {
      loop_ub = problemStruct->fitParams.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        result->fitParams[i1 + result->fitParams.size(0) * i] =
          problemStruct->fitParams[i1 + problemStruct->fitParams.size(0) * i];
      }
    }

    getFitNames(problemStruct->names.params,
                problemStruct->names.backgroundParams,
                problemStruct->names.scalefactors, problemStruct->names.qzshifts,
                problemStruct->names.bulkIns, problemStruct->names.bulkOuts,
                problemStruct->names.resolutionParams,
                problemStruct->names.domainRatios, problemStruct->checks.params,
                problemStruct->checks.backgroundParams,
                problemStruct->checks.scalefactors,
                problemStruct->checks.qzshifts, problemStruct->checks.bulkIns,
                problemStruct->checks.bulkOuts,
                problemStruct->checks.resolutionParams,
                problemStruct->checks.domainRatios, result->fitNames);
  }

  void reflectivityCalculation(const struct0_T *problemStruct, const struct4_T
    *controls, struct6_T *result)
  {
    ::coder::array<cell_wrap_11, 2U> layerSlds;
    ::coder::array<cell_wrap_11, 2U> resampledLayers;
    ::coder::array<cell_wrap_11, 2U> sldProfiles;
    ::coder::array<real_T, 1U> qzshifts;
    real_T y;
    int32_T switch_expression_size[2];
    int32_T b_index;
    int32_T i;
    char_T switch_expression_data[10000];

    //  Main entry point into the reflectivity calculation for the toolbox.
    //  This is the main function that is called by any of the minimisers or
    //  analysis tools from the rest of the toolbox.
    //
    //  The main job of this function is to decide which type of calculation
    //  (i.e. 'Target function') is required, and call the relevant routines.
    //  Different model types are specified in sub functions.
    //  The types of available target functions are:
    //
    //  * normal    - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples.
    //
    //  * oil water - Target function for oil-water samples
    //
    //  * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  * magnetic  - Target function for cases for polarised neutrons with polarisation analysis.
    //
    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::h_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      b_index = 0;
    } else if (coder::internal::i_strcmp(problemStruct->TF.data,
                problemStruct->TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      coder::lower(problemStruct->modelType.data, problemStruct->modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::j_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::k_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::l_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        normalTF::standardLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 1:
        normalTF::b_customLayers(problemStruct, controls, qzshifts,
          result->contrastParams.scalefactors, result->contrastParams.bulkIn,
          result->contrastParams.bulkOut, result->calculationResults.chiValues,
          result->reflectivity, result->simulation, result->shiftedData,
          result->backgrounds, result->resolutions, layerSlds, sldProfiles,
          resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;

       case 2:
        normalTF::b_customXY(problemStruct, controls, qzshifts,
                             result->contrastParams.scalefactors,
                             result->contrastParams.bulkIn,
                             result->contrastParams.bulkOut,
                             result->calculationResults.chiValues,
                             result->reflectivity, result->simulation,
                             result->shiftedData, result->backgrounds,
                             result->resolutions, layerSlds, sldProfiles,
                             resampledLayers, result->contrastParams.subRoughs);
        result->layerSlds.set_size(layerSlds.size(0), 1);
        b_index = layerSlds.size(0);
        for (i = 0; i < b_index; i++) {
          result->layerSlds[i] = layerSlds[i];
        }

        result->sldProfiles.set_size(sldProfiles.size(0), 1);
        b_index = sldProfiles.size(0);
        for (i = 0; i < b_index; i++) {
          result->sldProfiles[i] = sldProfiles[i];
        }

        result->resampledLayers.set_size(resampledLayers.size(0), 1);
        b_index = resampledLayers.size(0);
        for (i = 0; i < b_index; i++) {
          result->resampledLayers[i] = resampledLayers[i];
        }
        break;
      }

      // case coderEnums.calculationTypes.OilWater
      // contrastParams = oilWaterTFReflectivityCalculation(problemStruct,controls);
      // case coderEnums.calculationTypes.Magnetic
      // contrastParams = polarisedTFReflectivityCalculation(problemStruct,controls);
      break;

     case 1:
      {
        coder::lower(problemStruct->modelType.data,
                     problemStruct->modelType.size, switch_expression_data,
                     switch_expression_size);
        if (coder::internal::j_strcmp(switch_expression_data,
             switch_expression_size)) {
          b_index = 0;
        } else if (coder::internal::k_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 1;
        } else if (coder::internal::l_strcmp(switch_expression_data,
                    switch_expression_size)) {
          b_index = 2;
        } else {
          b_index = -1;
        }

        switch (b_index) {
         case 0:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::standardLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 1:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::b_customLayers(problemStruct, controls, qzshifts,
              result->contrastParams.scalefactors, result->contrastParams.bulkIn,
              result->contrastParams.bulkOut,
              result->calculationResults.chiValues, result->reflectivity,
              result->simulation, result->shiftedData, result->backgrounds,
              result->resolutions, layerSlds, sldProfiles, resampledLayers,
              result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;

         case 2:
          {
            int32_T b_loop_ub;
            int32_T loop_ub;
            domainsTF::b_customXY(problemStruct, controls, qzshifts,
                                  result->contrastParams.scalefactors,
                                  result->contrastParams.bulkIn,
                                  result->contrastParams.bulkOut,
                                  result->calculationResults.chiValues,
                                  result->reflectivity, result->simulation,
                                  result->shiftedData, result->backgrounds,
                                  result->resolutions, layerSlds, sldProfiles,
                                  resampledLayers,
                                  result->contrastParams.subRoughs);
            result->layerSlds.set_size(layerSlds.size(0), 2);
            result->sldProfiles.set_size(sldProfiles.size(0), 2);
            result->resampledLayers.set_size(resampledLayers.size(0), 2);
            b_index = layerSlds.size(0);
            loop_ub = sldProfiles.size(0);
            b_loop_ub = resampledLayers.size(0);
            for (i = 0; i < 2; i++) {
              int32_T i1;
              for (i1 = 0; i1 < b_index; i1++) {
                result->layerSlds[i1 + result->layerSlds.size(0) * i] =
                  layerSlds[i1 + layerSlds.size(0) * i];
              }

              for (i1 = 0; i1 < loop_ub; i1++) {
                result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
                  sldProfiles[i1 + sldProfiles.size(0) * i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                result->resampledLayers[i1 + result->resampledLayers.size(0) * i]
                  = resampledLayers[i1 + resampledLayers.size(0) * i];
              }
            }
          }
          break;
        }
      }
      break;
    }

    //  Make the result struct
    if (result->calculationResults.chiValues.size(0) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(result->calculationResults.chiValues,
                            result->calculationResults.chiValues.size(0));
    }

    result->calculationResults.sumChi = y;
    result->contrastParams.resample.set_size(1, problemStruct->resample.size(1));
    b_index = problemStruct->resample.size(1);
    for (i = 0; i < b_index; i++) {
      result->contrastParams.resample[i] = problemStruct->resample[i];
    }

    result->fitParams.set_size(1, problemStruct->fitParams.size(1));
    b_index = problemStruct->fitParams.size(1);
    for (i = 0; i < b_index; i++) {
      result->fitParams[i] = problemStruct->fitParams[i];
    }

    getFitNames(problemStruct->names.params,
                problemStruct->names.backgroundParams,
                problemStruct->names.scalefactors, problemStruct->names.qzshifts,
                problemStruct->names.bulkIns, problemStruct->names.bulkOuts,
                problemStruct->names.resolutionParams,
                problemStruct->names.domainRatios, problemStruct->checks.params,
                problemStruct->checks.backgroundParams,
                problemStruct->checks.scalefactors,
                problemStruct->checks.qzshifts, problemStruct->checks.bulkIns,
                problemStruct->checks.bulkOuts,
                problemStruct->checks.resolutionParams,
                problemStruct->checks.domainRatios, result->fitNames);
  }
}

// End of code generation (reflectivityCalculation.cpp)
