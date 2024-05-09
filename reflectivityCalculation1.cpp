//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation1.cpp
//
// Code generation for function 'reflectivityCalculation1'
//

// Include files
#include "reflectivityCalculation1.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "customLayers.h"
#include "customXY.h"
#include "lower.h"
#include "rt_nonfinite.h"
#include "standardLayers.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    void b_reflectivityCalculation(const f_struct_T *problemStruct, const
      cell_11 *problemCells, const struct2_T *controls, c_struct_T
      *contrastParams, struct6_T *calculationResults, ::coder::array<cell_wrap_8,
      1U> &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::coder::
      array<cell_wrap_10, 1U> &shiftedData, ::coder::array<cell_wrap_10, 1U>
      &layerSlds, ::coder::array<cell_wrap_10, 1U> &sldProfiles, ::coder::array<
      cell_wrap_10, 1U> &resampledLayers)
    {
      ::coder::array<real_T, 1U> qzshifts;
      real_T y;
      int32_T switch_expression_size[2];
      int32_T b_index;
      int32_T i;
      char_T switch_expression_data[10000];

      //  Main function for the nonPolarisedTF reflectivity calculation.
      //  This function decides what type of model is being analysed and branches
      //  to the correct one. The main options are:
      //
      //  Standard Layers   - This is the equivalent of Standard Layers in RasCAL.
      //  Custom Layers     - This is also a layers calculation, but the
      //                      specification of the layers is done using a user
      //                      defined function.
      //  Custom XY         - This also has a model described by a user supplied
      //                      function, but in this case the function generates an
      //                      SLD profile (i.e. XY function) rather than a list of
      //                      layers.
      //
      //  We then decide on parallelisation options before calling the relevant
      //  version of the main custom layers calculation. It is more efficient to
      //  have multiple versions of the core calculation, each dealing with a
      //  different scheme for parallelisation. These are:
      //
      //  single            - single threaded reflectivity calculation.
      //  points            - parallelise over points.
      //  contrasts         - parallelise over contrasts.
      //
      //  Find out the model type from the input structs
      //  Pre-allocation - It's necessary to pre-define the types for all the
      //  arrays for compilation, so do this in this block.
      //  Pre-allocate the output arrays. This is necessary because otherwise the
      //  compiler complains with 'Output argument <....> is not assigned on some
      //  execution paths' error.
      i = static_cast<int32_T>(problemStruct->numberOfContrasts);
      reflectivity.set_size(i);
      simulation.set_size(i);
      shiftedData.set_size(i);
      layerSlds.set_size(i);
      sldProfiles.set_size(i);
      resampledLayers.set_size(i);
      for (int32_T b_i{0}; b_i < i; b_i++) {
        reflectivity[b_i].f1.set_size(2, 2);
        reflectivity[b_i].f1[0] = 1.0;
        reflectivity[b_i].f1[1] = 1.0;
        reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
        reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
        simulation[b_i].f1.set_size(2, 2);
        simulation[b_i].f1[0] = 1.0;
        simulation[b_i].f1[1] = 1.0;
        simulation[b_i].f1[simulation[b_i].f1.size(0)] = 1.0;
        simulation[b_i].f1[simulation[b_i].f1.size(0) + 1] = 1.0;
        shiftedData[b_i].f1.set_size(2, 3);
        layerSlds[b_i].f1.set_size(2, 3);
        sldProfiles[b_i].f1.set_size(2, 2);
        sldProfiles[b_i].f1[0] = 1.0;
        sldProfiles[b_i].f1[1] = 1.0;
        sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
        sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
        resampledLayers[b_i].f1.set_size(2, 3);
        for (b_index = 0; b_index < 3; b_index++) {
          shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * b_index] = 1.0;
          shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * b_index + 1] = 1.0;
          layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * b_index] = 1.0;
          layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * b_index + 1] = 1.0;
          resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * b_index] =
            1.0;
          resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * b_index + 1]
            = 1.0;
        }
      }

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
        standardLayers(problemStruct, problemCells, controls,
                       contrastParams->backgroundParams, qzshifts,
                       contrastParams->scalefactors, contrastParams->bulkIn,
                       contrastParams->bulkOut, contrastParams->resolutionParams,
                       calculationResults->chiValues, reflectivity, simulation,
                       shiftedData, layerSlds, sldProfiles, resampledLayers,
                       contrastParams->subRoughs);
        break;

       case 1:
        b_customLayers(problemStruct, problemCells, controls,
                       contrastParams->backgroundParams, qzshifts,
                       contrastParams->scalefactors, contrastParams->bulkIn,
                       contrastParams->bulkOut, contrastParams->resolutionParams,
                       calculationResults->chiValues, reflectivity, simulation,
                       shiftedData, layerSlds, sldProfiles, resampledLayers,
                       contrastParams->subRoughs);
        break;

       case 2:
        b_customXY(problemStruct, problemCells, controls,
                   contrastParams->backgroundParams, qzshifts,
                   contrastParams->scalefactors, contrastParams->bulkIn,
                   contrastParams->bulkOut, contrastParams->resolutionParams,
                   calculationResults->chiValues, reflectivity, simulation,
                   shiftedData, layerSlds, sldProfiles, resampledLayers,
                   contrastParams->subRoughs);
        break;
      }

      //  Package everything into structs for tidy output
      contrastParams->resample.set_size(1, problemStruct->resample.size(1));
      b_index = problemStruct->resample.size(1);
      for (i = 0; i < b_index; i++) {
        contrastParams->resample[i] = problemStruct->resample[i];
      }

      if (calculationResults->chiValues.size(0) == 0) {
        y = 0.0;
      } else {
        y = coder::nestedIter(calculationResults->chiValues,
                              calculationResults->chiValues.size(0));
      }

      calculationResults->sumChi = y;
    }
  }
}

// End of code generation (reflectivityCalculation1.cpp)
