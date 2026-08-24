//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// reflectivityCalculation.cpp
//
// Code generation for function 'reflectivityCalculation'
//

// Include files
#include "reflectivityCalculation.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "domainsReflectivity.h"
#include "getFitNames.h"
#include "normalReflectivity.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "strcmp.h"
#include "sum.h"
#include "coderException.hpp"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  void b_reflectivityCalculation(const ProblemDefinition &problemStruct, const
    Controls *controls, b_struct_T &result)
  {
    ::coder::array<cell_wrap_7, 2U> sldProfiles;
    ::coder::array<cell_wrap_9, 2U> layers;
    ::coder::array<cell_wrap_9, 2U> resampledLayers;
    ::coder::array<double, 1U> a__1;
    ::coder::array<double, 1U> a__2;
    ::coder::array<char, 2U> r;
    int b_index;

    //  Compute the reflectivity and SLD curves for a given model using the Abeles matrix formalism.
    //
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
    //  * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  Parameters
    //  ----------
    //  problemStruct : struct
    //      The project class as a struct (generated via parseClassToStructs)
    //  controls : struct
    //      The controls struct (generated via parseClassToStructs)
    //
    //  Returns
    //  -------
    //  result : struct
    //      The results of the calculation.
    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::i_strcmp(problemStruct.TF.data, problemStruct.TF.size))
    {
      b_index = 0;
    } else if (coder::internal::j_strcmp(problemStruct.TF.data,
                problemStruct.TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      normalTF::b_normalReflectivity(problemStruct, controls,
        result.reflectivity, result.simulation, result.shiftedData,
        result.backgrounds, result.resolutions, sldProfiles, layers,
        resampledLayers, a__1, result.contrastParams.scalefactors,
        result.contrastParams.bulkIn, result.contrastParams.bulkOut,
        result.contrastParams.subRoughs, result.calculationResults.chiValues);
      result.sldProfiles.set_size(sldProfiles.size(0), 1);
      b_index = sldProfiles.size(0);
      for (int i{0}; i < b_index; i++) {
        result.sldProfiles[i] = sldProfiles[i];
      }

      result.layers.set_size(layers.size(0), 1);
      b_index = layers.size(0);
      for (int i{0}; i < b_index; i++) {
        result.layers[i] = layers[i];
      }

      result.resampledLayers.set_size(resampledLayers.size(0), 1);
      b_index = resampledLayers.size(0);
      for (int i{0}; i < b_index; i++) {
        result.resampledLayers[i] = resampledLayers[i];
      }
      break;

     case 1:
      {
        int b_loop_ub;
        int loop_ub;
        domainsTF::b_domainsReflectivity(problemStruct, controls,
          result.reflectivity, result.simulation, result.shiftedData,
          result.backgrounds, result.resolutions, sldProfiles, layers,
          resampledLayers, a__2, result.contrastParams.scalefactors,
          result.contrastParams.bulkIn, result.contrastParams.bulkOut,
          result.contrastParams.subRoughs, result.calculationResults.chiValues);
        result.sldProfiles.set_size(sldProfiles.size(0), 2);
        result.layers.set_size(layers.size(0), 2);
        result.resampledLayers.set_size(resampledLayers.size(0), 2);
        b_index = sldProfiles.size(0);
        loop_ub = layers.size(0);
        b_loop_ub = resampledLayers.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < b_index; i1++) {
            result.sldProfiles[i1 + result.sldProfiles.size(0) * i] =
              sldProfiles[i1 + sldProfiles.size(0) * i];
          }

          for (int i1{0}; i1 < loop_ub; i1++) {
            result.layers[i1 + result.layers.size(0) * i] = layers[i1 +
              layers.size(0) * i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            result.resampledLayers[i1 + result.resampledLayers.size(0) * i] =
              resampledLayers[i1 + resampledLayers.size(0) * i];
          }
        }
      }
      break;

     default:
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      coder::d_sprintf(problemStruct.TF.data, problemStruct.TF.size, r);
      coderException(1.0, &r[0]);
      break;
    }

    //  Make the result struct
    result.calculationResults.sumChi = coder::sum
      (result.calculationResults.chiValues);
    result.contrastParams.resample.set_size(1, problemStruct.resample.size(1));
    b_index = problemStruct.resample.size(1);
    for (int i{0}; i < b_index; i++) {
      result.contrastParams.resample[i] = problemStruct.resample[i];
    }

    result.fitParams.set_size(1, problemStruct.fitParams.size(1));
    b_index = problemStruct.fitParams.size(1);
    for (int i{0}; i < b_index; i++) {
      result.fitParams[i] = problemStruct.fitParams[i];
    }

    getFitNames(problemStruct.names.params, problemStruct.names.backgroundParams,
                problemStruct.names.scalefactors, problemStruct.names.bulkIns,
                problemStruct.names.bulkOuts,
                problemStruct.names.resolutionParams,
                problemStruct.names.domainRatios, problemStruct.checks.params,
                problemStruct.checks.backgroundParams,
                problemStruct.checks.scalefactors, problemStruct.checks.bulkIns,
                problemStruct.checks.bulkOuts,
                problemStruct.checks.resolutionParams,
                problemStruct.checks.domainRatios, result.fitNames);
  }

  void reflectivityCalculation(const ProblemDefinition &problemStruct, const
    Controls *controls, b_struct_T &result)
  {
    ::coder::array<cell_wrap_7, 2U> sldProfiles;
    ::coder::array<cell_wrap_9, 2U> layers;
    ::coder::array<cell_wrap_9, 2U> resampledLayers;
    ::coder::array<double, 1U> a__1;
    ::coder::array<double, 1U> a__2;
    ::coder::array<char, 2U> r;
    int b_index;

    //  Compute the reflectivity and SLD curves for a given model using the Abeles matrix formalism.
    //
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
    //  * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  Parameters
    //  ----------
    //  problemStruct : struct
    //      The project class as a struct (generated via parseClassToStructs)
    //  controls : struct
    //      The controls struct (generated via parseClassToStructs)
    //
    //  Returns
    //  -------
    //  result : struct
    //      The results of the calculation.
    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::i_strcmp(problemStruct.TF.data, problemStruct.TF.size))
    {
      b_index = 0;
    } else if (coder::internal::j_strcmp(problemStruct.TF.data,
                problemStruct.TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      normalTF::normalReflectivity(problemStruct, controls, result.reflectivity,
        result.simulation, result.shiftedData, result.backgrounds,
        result.resolutions, sldProfiles, layers, resampledLayers, a__1,
        result.contrastParams.scalefactors, result.contrastParams.bulkIn,
        result.contrastParams.bulkOut, result.contrastParams.subRoughs,
        result.calculationResults.chiValues);
      result.sldProfiles.set_size(sldProfiles.size(0), 1);
      b_index = sldProfiles.size(0);
      for (int i{0}; i < b_index; i++) {
        result.sldProfiles[i] = sldProfiles[i];
      }

      result.layers.set_size(layers.size(0), 1);
      b_index = layers.size(0);
      for (int i{0}; i < b_index; i++) {
        result.layers[i] = layers[i];
      }

      result.resampledLayers.set_size(resampledLayers.size(0), 1);
      b_index = resampledLayers.size(0);
      for (int i{0}; i < b_index; i++) {
        result.resampledLayers[i] = resampledLayers[i];
      }
      break;

     case 1:
      {
        int b_loop_ub;
        int loop_ub;
        domainsTF::domainsReflectivity(problemStruct, controls,
          result.reflectivity, result.simulation, result.shiftedData,
          result.backgrounds, result.resolutions, sldProfiles, layers,
          resampledLayers, a__2, result.contrastParams.scalefactors,
          result.contrastParams.bulkIn, result.contrastParams.bulkOut,
          result.contrastParams.subRoughs, result.calculationResults.chiValues);
        result.sldProfiles.set_size(sldProfiles.size(0), 2);
        result.layers.set_size(layers.size(0), 2);
        result.resampledLayers.set_size(resampledLayers.size(0), 2);
        b_index = sldProfiles.size(0);
        loop_ub = layers.size(0);
        b_loop_ub = resampledLayers.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < b_index; i1++) {
            result.sldProfiles[i1 + result.sldProfiles.size(0) * i] =
              sldProfiles[i1 + sldProfiles.size(0) * i];
          }

          for (int i1{0}; i1 < loop_ub; i1++) {
            result.layers[i1 + result.layers.size(0) * i] = layers[i1 +
              layers.size(0) * i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            result.resampledLayers[i1 + result.resampledLayers.size(0) * i] =
              resampledLayers[i1 + resampledLayers.size(0) * i];
          }
        }
      }
      break;

     default:
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      coder::d_sprintf(problemStruct.TF.data, problemStruct.TF.size, r);
      coderException(1.0, &r[0]);
      break;
    }

    //  Make the result struct
    result.calculationResults.sumChi = coder::sum
      (result.calculationResults.chiValues);
    result.contrastParams.resample.set_size(1, problemStruct.resample.size(1));
    b_index = problemStruct.resample.size(1);
    for (int i{0}; i < b_index; i++) {
      result.contrastParams.resample[i] = problemStruct.resample[i];
    }

    result.fitParams.set_size(1, problemStruct.fitParams.size(1));
    b_index = problemStruct.fitParams.size(1);
    for (int i{0}; i < b_index; i++) {
      result.fitParams[i] = problemStruct.fitParams[i];
    }

    getFitNames(problemStruct.names.params, problemStruct.names.backgroundParams,
                problemStruct.names.scalefactors, problemStruct.names.bulkIns,
                problemStruct.names.bulkOuts,
                problemStruct.names.resolutionParams,
                problemStruct.names.domainRatios, problemStruct.checks.params,
                problemStruct.checks.backgroundParams,
                problemStruct.checks.scalefactors, problemStruct.checks.bulkIns,
                problemStruct.checks.bulkOuts,
                problemStruct.checks.resolutionParams,
                problemStruct.checks.domainRatios, result.fitNames);
  }
}

// End of code generation (reflectivityCalculation.cpp)
