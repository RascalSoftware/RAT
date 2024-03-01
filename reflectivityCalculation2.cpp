//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation2.cpp
//
// Code generation for function 'reflectivityCalculation2'
//

// Include files
#include "reflectivityCalculation2.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "calculate3.h"
#include "calculate4.h"
#include "calculate5.h"
#include "lower.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    void b_reflectivityCalculation(const f_struct_T *problemStruct, const
      cell_11 *problemCells, const struct2_T *controls, b_struct_T
      *contrastParams, struct6_T *calculationResults, ::coder::array<cell_wrap_8,
      1U> &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::coder::
      array<cell_wrap_10, 1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
      &layerSlds, ::coder::array<cell_wrap_10, 2U> &domainSldProfiles, ::coder::
      array<cell_wrap_10, 2U> &allLayers)
    {
      ::coder::array<cell_wrap_10, 2U> b_domainSldProfiles;
      ::coder::array<cell_wrap_10, 2U> b_layerSlds;
      ::coder::array<cell_wrap_10, 2U> r;
      int32_T switch_expression_size[2];
      int32_T b_i;
      int32_T loop_ub_tmp;
      char_T switch_expression_data[10000];

      //  Main function for the domainsTF reflectivity calculation
      //  This function decides what type of model is being analysed and barnches
      //  to the correct one. The main options are:
      //  layers            - This is the equivalent of Standard Layers in RasCAL
      //  Custom Layers     - This is also a layers calculation, but the
      //                    specification of the layers is dne using a user defined
      //                    function.
      //  Custom XY         - This also has a model described by a user supplied
      //                    function, but in this case the function generates an
      //                    SLD profile (i.e. XY function) rather than a list of
      //                    layers.
      //  Find out the model type from the input structs
      //  Pre-allocate the output arrays.. this is necessary because otherwise
      //  the compiler complains with 'Output argument <....> is not assigned on
      //  some execution paths' error.
      loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
      contrastParams->ssubs.set_size(loop_ub_tmp);
      contrastParams->backgroundParams.set_size(loop_ub_tmp);
      contrastParams->qzshifts.set_size(loop_ub_tmp);
      contrastParams->scalefactors.set_size(loop_ub_tmp);
      contrastParams->bulkIn.set_size(loop_ub_tmp);
      contrastParams->bulkOut.set_size(loop_ub_tmp);
      contrastParams->resolutionParams.set_size(loop_ub_tmp);
      contrastParams->allSubRough.set_size(loop_ub_tmp);
      contrastParams->resample.set_size(1, loop_ub_tmp);
      calculationResults->allChis.set_size(loop_ub_tmp);
      calculationResults->sumChi = 0.0;
      reflectivity.set_size(loop_ub_tmp);
      simulation.set_size(loop_ub_tmp);
      shiftedData.set_size(loop_ub_tmp);
      layerSlds.set_size(loop_ub_tmp, 2);
      domainSldProfiles.set_size(loop_ub_tmp, 2);
      allLayers.set_size(loop_ub_tmp, 2);
      for (int32_T i{0}; i < loop_ub_tmp; i++) {
        contrastParams->ssubs[i] = 0.0;
        contrastParams->backgroundParams[i] = 0.0;
        contrastParams->qzshifts[i] = 0.0;
        contrastParams->scalefactors[i] = 0.0;
        contrastParams->bulkIn[i] = 0.0;
        contrastParams->bulkOut[i] = 0.0;
        contrastParams->resolutionParams[i] = 0.0;
        contrastParams->allSubRough[i] = 0.0;
        contrastParams->resample[i] = 0.0;
        calculationResults->allChis[i] = 0.0;
        reflectivity[i].f1.set_size(2, 2);
        reflectivity[i].f1[0] = 1.0;
        reflectivity[i].f1[1] = 1.0;
        reflectivity[i].f1[reflectivity[i].f1.size(0)] = 1.0;
        reflectivity[i].f1[reflectivity[i].f1.size(0) + 1] = 1.0;
        simulation[i].f1.set_size(2, 2);
        simulation[i].f1[0] = 1.0;
        simulation[i].f1[1] = 1.0;
        simulation[i].f1[simulation[i].f1.size(0)] = 1.0;
        simulation[i].f1[simulation[i].f1.size(0) + 1] = 1.0;
        shiftedData[i].f1.set_size(2, 3);
        layerSlds[i].f1.set_size(2, 3);
        layerSlds[i + layerSlds.size(0)].f1.set_size(2, 3);
        domainSldProfiles[i].f1.set_size(2, 2);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size(2, 2);
        domainSldProfiles[i].f1[0] = 1.0;
        domainSldProfiles[i + domainSldProfiles.size(0)].f1[0] = 1.0;
        domainSldProfiles[i].f1[1] = 1.0;
        domainSldProfiles[i + domainSldProfiles.size(0)].f1[1] = 1.0;
        domainSldProfiles[i].f1[domainSldProfiles[i].f1.size(0)] = 1.0;
        domainSldProfiles[i + domainSldProfiles.size(0)].f1[domainSldProfiles[i
          + domainSldProfiles.size(0)].f1.size(0)] = 1.0;
        domainSldProfiles[i].f1[domainSldProfiles[i].f1.size(0) + 1] = 1.0;
        domainSldProfiles[i + domainSldProfiles.size(0)].f1[domainSldProfiles[i
          + domainSldProfiles.size(0)].f1.size(0) + 1] = 1.0;
        allLayers[i].f1.set_size(2, 3);
        allLayers[i + allLayers.size(0)].f1.set_size(2, 3);
        for (b_i = 0; b_i < 3; b_i++) {
          shiftedData[i].f1[shiftedData[i].f1.size(0) * b_i] = 1.0;
          shiftedData[i].f1[shiftedData[i].f1.size(0) * b_i + 1] = 1.0;
          layerSlds[i].f1[layerSlds[i].f1.size(0) * b_i] = 1.0;
          layerSlds[i + layerSlds.size(0)].f1[layerSlds[i + layerSlds.size(0)].
            f1.size(0) * b_i] = 1.0;
          layerSlds[i].f1[layerSlds[i].f1.size(0) * b_i + 1] = 1.0;
          layerSlds[i + layerSlds.size(0)].f1[layerSlds[i + layerSlds.size(0)].
            f1.size(0) * b_i + 1] = 1.0;
          allLayers[i].f1[allLayers[i].f1.size(0) * b_i] = 1.0;
          allLayers[i + allLayers.size(0)].f1[allLayers[i + allLayers.size(0)].
            f1.size(0) * b_i] = 1.0;
          allLayers[i].f1[allLayers[i].f1.size(0) * b_i + 1] = 1.0;
          allLayers[i + allLayers.size(0)].f1[allLayers[i + allLayers.size(0)].
            f1.size(0) * b_i + 1] = 1.0;
        }
      }

      coder::lower(problemStruct->modelType.data, problemStruct->modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::j_strcmp(switch_expression_data,
           switch_expression_size)) {
        loop_ub_tmp = 0;
      } else if (coder::internal::k_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub_tmp = 1;
      } else if (coder::internal::l_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub_tmp = 2;
      } else {
        loop_ub_tmp = -1;
      }

      switch (loop_ub_tmp) {
       case 0:
        //  Standard layers calculation
        standardLayers::calculate(problemStruct, problemCells, controls,
          contrastParams, calculationResults, reflectivity, simulation,
          shiftedData, layerSlds, domainSldProfiles, allLayers);
        break;

       case 1:
        {
          int32_T i1;
          int32_T loop_ub;

          //  Custom layers with user supplied custom model file
          customLayers::calculate(problemStruct, problemCells, controls,
            contrastParams, calculationResults, reflectivity, simulation,
            shiftedData, b_layerSlds, b_domainSldProfiles, r);
          layerSlds.set_size(b_layerSlds.size(0), 2);
          domainSldProfiles.set_size(b_domainSldProfiles.size(0), 2);
          loop_ub_tmp = b_layerSlds.size(0);
          loop_ub = b_domainSldProfiles.size(0);
          for (b_i = 0; b_i < 2; b_i++) {
            for (i1 = 0; i1 < loop_ub_tmp; i1++) {
              layerSlds[i1 + layerSlds.size(0) * b_i] = b_layerSlds[i1 +
                b_layerSlds.size(0) * b_i];
            }

            for (i1 = 0; i1 < loop_ub; i1++) {
              domainSldProfiles[i1 + domainSldProfiles.size(0) * b_i] =
                b_domainSldProfiles[i1 + b_domainSldProfiles.size(0) * b_i];
            }
          }

          allLayers.set_size(r.size(0), r.size(1));
          loop_ub_tmp = r.size(1);
          for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
            loop_ub = r.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              allLayers[i1 + allLayers.size(0) * b_i] = r[i1 + r.size(0) * b_i];
            }
          }
        }
        break;

       case 2:
        {
          int32_T i1;
          int32_T loop_ub;

          //  Custom SLD profile with user defined model file
          customXY::calculate(problemStruct, problemCells, controls,
                              contrastParams, calculationResults, reflectivity,
                              simulation, shiftedData, b_layerSlds,
                              b_domainSldProfiles, r);
          layerSlds.set_size(b_layerSlds.size(0), 2);
          domainSldProfiles.set_size(b_domainSldProfiles.size(0), 2);
          loop_ub_tmp = b_layerSlds.size(0);
          loop_ub = b_domainSldProfiles.size(0);
          for (b_i = 0; b_i < 2; b_i++) {
            for (i1 = 0; i1 < loop_ub_tmp; i1++) {
              layerSlds[i1 + layerSlds.size(0) * b_i] = b_layerSlds[i1 +
                b_layerSlds.size(0) * b_i];
            }

            for (i1 = 0; i1 < loop_ub; i1++) {
              domainSldProfiles[i1 + domainSldProfiles.size(0) * b_i] =
                b_domainSldProfiles[i1 + b_domainSldProfiles.size(0) * b_i];
            }
          }

          allLayers.set_size(r.size(0), r.size(1));
          loop_ub_tmp = r.size(1);
          for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
            loop_ub = r.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              allLayers[i1 + allLayers.size(0) * b_i] = r[i1 + r.size(0) * b_i];
            }
          }
        }
        break;
      }
    }
  }
}

// End of code generation (reflectivityCalculation2.cpp)
