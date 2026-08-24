//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// normalReflectivity.cpp
//
// Code generation for function 'normalReflectivity'
//

// Include files
#include "normalReflectivity.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "coreCustomXYCalculation.h"
#include "coreLayersCalculation.h"
#include "lower.h"
#include "nullAssignment.h"
#include "processCustomFunction.h"
#include "rt_nonfinite.h"
#include "setupCoreReflectivityCalculation.h"
#include "sprintf.h"
#include "strcmp.h"
#include "coderException.hpp"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    void b_normalReflectivity(const ProblemDefinition &problemStruct, const
      Controls *controls, ::coder::array<cell_wrap_7, 1U> &reflectivity, ::coder::
      array<cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8, 1U>
      &shiftedData, ::coder::array<cell_wrap_8, 1U> &backgrounds, ::coder::array<
      cell_wrap_7, 1U> &resolutions, ::coder::array<cell_wrap_7, 2U>
      &sldProfiles, ::coder::array<cell_wrap_9, 2U> &layers, ::coder::array<
      cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U> &qzshifts, ::
      coder::array<double, 1U> &scalefactors, ::coder::array<double, 1U>
      &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double, 1U>
      &subRoughs, ::coder::array<double, 1U> &chis)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_9, 1U> contrastLayers;
      ::coder::array<cell_wrap_9, 1U> contrastSlds;
      ::coder::array<double, 2U> b_layers;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> r8;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int i2;
      int i3;
      int loop_ub;
      int loop_ub_tmp;
      int nParams;
      char switch_expression_data[10000];
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main normal reflectivity calculation.
      //  It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  the appropriate core calculation, which carries out the calculation
      //  itself. The core layers calculation is common for both standard and
      //  custom layers, with an additional core custom XY calculation.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;
      nParams = problemStruct.params.size(1);
      calcSld = controls->calcSLD;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Find the actual values from the indices given in each contrast
      scalefactors.set_size(problemStruct.contrastScalefactors.size(1));
      loop_ub = problemStruct.contrastScalefactors.size(1);
      for (int i{0}; i < loop_ub; i++) {
        scalefactors[i] = problemStruct.scalefactors[static_cast<int>
          (problemStruct.contrastScalefactors[i]) - 1];
      }

      bulkIns.set_size(problemStruct.contrastBulkIns.size(1));
      loop_ub = problemStruct.contrastBulkIns.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkIns[i] = problemStruct.bulkIns[static_cast<int>
          (problemStruct.contrastBulkIns[i]) - 1];
      }

      bulkOuts.set_size(problemStruct.contrastBulkOuts.size(1));
      loop_ub = problemStruct.contrastBulkOuts.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkOuts[i] = problemStruct.bulkOuts[static_cast<int>
          (problemStruct.contrastBulkOuts[i]) - 1];
      }

      //  qzshifts are not included as a parameter in RAT,
      //  so we set up dummy values for the reflectivity calculation
      loop_ub_tmp = static_cast<int>(problemStruct.numberOfContrasts);
      qzshifts.set_size(loop_ub_tmp);
      for (int i{0}; i < loop_ub_tmp; i++) {
        qzshifts[i] = 0.0;
      }

      //  Allocate the memory for the output arrays before the main loop
      shiftedData.set_size(loop_ub_tmp);
      backgrounds.set_size(loop_ub_tmp);
      resolutions.set_size(loop_ub_tmp);
      contrastLayers.set_size(loop_ub_tmp);
      contrastSlds.set_size(loop_ub_tmp);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        shiftedData[b_i].f1.set_size(1, 3);
        backgrounds[b_i].f1.set_size(1, 3);
        shiftedData[b_i].f1[0] = 0.0;
        backgrounds[b_i].f1[0] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0)] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0)] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * 2] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0) * 2] = 0.0;
        resolutions[b_i].f1.set_size(1, 2);
        resolutions[b_i].f1[0] = 0.0;
        resolutions[b_i].f1[resolutions[b_i].f1.size(0)] = 0.0;
        contrastLayers[b_i].f1.set_size(1, 6);
        for (int i{0}; i < 6; i++) {
          contrastLayers[b_i].f1[contrastLayers[b_i].f1.size(0) * i] = 0.0;
        }

        contrastSlds[b_i].f1.set_size(1, 3);
        contrastSlds[b_i].f1[0] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0)] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0) * 2] = 0.0;
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::k_strcmp(switch_expression_data,
           switch_expression_size)) {
        loop_ub = 0;
      } else if (coder::internal::n_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub = 1;
      } else if (coder::internal::o_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub = 2;
      } else {
        loop_ub = -1;
      }

      switch (loop_ub) {
       case 0:
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only
        //  needs to be done once, and so is done outside the contrasts
        //  loop
        allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
          layerValues);
        subRoughs.set_size(loop_ub_tmp);
        contrastLayers.set_size(loop_ub_tmp);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers.
          subRoughs[b_i] = problemStruct.params[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry.
          allocateLayersForContrast(problemStruct.contrastLayers[b_i].f1,
            layerValues, r1);
          contrastLayers[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i{0}; i < 6; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              contrastLayers[b_i].f1[i1 + contrastLayers[b_i].f1.size(0) * i] =
                r1[i1 + r1.size(0) * i];
            }
          }
        }
        break;

       case 1:
        //  Process the custom models
        processCustomFunction(bulkIns, bulkOuts,
                              problemStruct.contrastCustomFiles,
                              problemStruct.numberOfContrasts,
                              problemStruct.customFiles, problemStruct.params,
                              problemStruct.useImaginary, contrastLayers,
                              subRoughs);
        break;

       case 2:
        //  Process the custom models
        b_processCustomFunction(bulkIns, bulkOuts,
          problemStruct.contrastCustomFiles, problemStruct.numberOfContrasts,
          problemStruct.customFiles, problemStruct.params,
          problemStruct.useImaginary, contrastSlds, subRoughs);
        break;

       default:
        //  Ensures a proper exception is thrown in the generated C++ code.
        //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
        //  and other parameters if message is a formatspec.
        //
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
        coder::b_sprintf(problemStruct.modelType.data,
                         problemStruct.modelType.size, r);
        coderException(1.0, &r[0]);
        break;
      }

      //  Run the core calculation for each contrast
      if (coder::internal::l_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          layers.set_size(loop_ub_tmp, 1);
          resampledLayers.set_size(loop_ub_tmp, 1);
          chis.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 1);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          loop_ub = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,c_loop_ub,i2,i3,d_loop_ub)

          for (int c_i = 0; c_i <= loop_ub; c_i++) {
            iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [1];
            iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [0];
            iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [1];
            iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [0];
            iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [1];
            iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [0];
            iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [1];
            dv2[0] = problemStruct.dataLimits[c_i].f1[0];
            dv2[1] = problemStruct.dataLimits[c_i].f1[1];
            dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
            dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)
              ->data(), iv3, (const double *)((::coder::array<double, 2U> *)
              &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
              problemStruct.backgroundParams, problemStruct.resolutionParams, (
              const char *)((::coder::array<char, 2U> *)
                            &problemStruct.contrastBackgroundTypes[c_i].f1)
              ->data(), iv5, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastResolutionTypes[c_i].f1)->data(), iv6,
              problemStruct.customFiles, scalefactors[c_i],
              problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2,
              dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [1];
            d = coreCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              shiftedData[c_i].f1, simulationXData, b_dataIndices,
              backgrounds[c_i].f1, resolutions[c_i].f1, (const char *)((::coder::
              array<char, 2U> *)&problemStruct.contrastBackgroundActions[c_i].f1)
              ->data(), iv3, controls->parallel.data, controls->parallel.size,
              resampleMinAngle, resampleNPoints, subRoughs[c_i],
              contrastSlds[c_i].f1, static_cast<double>(nParams),
              reflectivity[c_i].f1, simulation[c_i].f1, r4, r3, r2);
            c_loop_ub = r4.size(0);
            sldProfiles[c_i].f1.set_size(r4.size(0), 2);
            for (i2 = 0; i2 < 2; i2++) {
              for (i3 = 0; i3 < c_loop_ub; i3++) {
                sldProfiles[c_i].f1[i3 + sldProfiles[c_i].f1.size(0) * i2] =
                  r4[i3 + r4.size(0) * i2];
              }
            }

            c_loop_ub = r3.size(0);
            layers[c_i].f1.set_size(r3.size(0), 4);
            d_loop_ub = r2.size(0);
            resampledLayers[c_i].f1.set_size(r2.size(0), 4);
            for (i2 = 0; i2 < 4; i2++) {
              for (i3 = 0; i3 < c_loop_ub; i3++) {
                layers[c_i].f1[i3 + layers[c_i].f1.size(0) * i2] = r3[i3 +
                  r3.size(0) * i2];
              }

              for (i3 = 0; i3 < d_loop_ub; i3++) {
                resampledLayers[c_i].f1[i3 + resampledLayers[c_i].f1.size(0) *
                  i2] = r2[i3 + r2.size(0) * i2];
              }
            }

            chis[c_i] = d;
          }
        } else {
          layers.set_size(loop_ub_tmp, 1);
          resampledLayers.set_size(loop_ub_tmp, 1);
          chis.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 1);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
            iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [0];
            iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [1];
            iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [0];
            iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [1];
            iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [0];
            iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [1];
            b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
            b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
            b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
            b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)
              ->data(), switch_expression_size, (const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastResolutionParams[b_i].f1)
              ->data(), iv, problemStruct.backgroundParams,
              problemStruct.resolutionParams, (const char *)((::coder::array<
              char, 2U> *)&problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
              iv1, (const char *)((::coder::array<char, 2U> *)
                                  &problemStruct.contrastResolutionTypes[b_i].f1)
              ->data(), iv2, problemStruct.customFiles,
              problemStruct.scalefactors[static_cast<int>
              (problemStruct.contrastScalefactors[b_i]) - 1],
              problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
              b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].
              f1, shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
            chis[b_i] = coreCustomXYCalculation(problemStruct.bulkIns[
              static_cast<int>(problemStruct.contrastBulkIns[b_i]) - 1],
              problemStruct.bulkOuts[static_cast<int>
              (problemStruct.contrastBulkOuts[b_i]) - 1], shiftedData[b_i].f1,
              b_simulationXData, dataIndices, backgrounds[b_i].f1,
              resolutions[b_i].f1, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastBackgroundActions[b_i].f1)->data(),
              switch_expression_size, controls->parallel.data,
              controls->parallel.size, resampleMinAngle, resampleNPoints,
              subRoughs[b_i], contrastSlds[b_i].f1, static_cast<double>(nParams),
              reflectivity[b_i].f1, simulation[b_i].f1, r6, r8, r7);
            loop_ub = r6.size(0);
            sldProfiles[b_i].f1.set_size(r6.size(0), 2);
            for (int i{0}; i < 2; i++) {
              for (int i1{0}; i1 < loop_ub; i1++) {
                sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0) * i] =
                  r6[i1 + r6.size(0) * i];
              }
            }

            loop_ub = r8.size(0);
            layers[b_i].f1.set_size(r8.size(0), 4);
            b_loop_ub = r7.size(0);
            resampledLayers[b_i].f1.set_size(r7.size(0), 4);
            for (int i{0}; i < 4; i++) {
              for (int i1{0}; i1 < loop_ub; i1++) {
                layers[b_i].f1[i1 + layers[b_i].f1.size(0) * i] = r8[i1 +
                  r8.size(0) * i];
              }

              for (int i1{0}; i1 < b_loop_ub; i1++) {
                resampledLayers[b_i].f1[i1 + resampledLayers[b_i].f1.size(0) * i]
                  = r7[i1 + r7.size(0) * i];
              }
            }
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        layers.set_size(loop_ub_tmp, 1);
        resampledLayers.set_size(loop_ub_tmp, 1);
        chis.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 1);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        loop_ub = loop_ub_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,c_loop_ub,i2,i3,d_loop_ub)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)->data
            (), iv3, (const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[c_i].f1)->data(),
            iv5, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[c_i].f1
            )->data(), iv6, problemStruct.customFiles, scalefactors[c_i],
            problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2, dv3,
            numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
            shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          d = coreLayersCalculation(contrastLayers[c_i].f1, subRoughs[c_i],
            problemStruct.geometry.data, problemStruct.geometry.size,
            bulkIns[c_i], bulkOuts[c_i], problemStruct.resample[c_i], calcSld,
            shiftedData[c_i].f1, simulationXData, b_dataIndices,
            problemStruct.repeatLayers[c_i], backgrounds[c_i].f1,
            resolutions[c_i].f1, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv3,
            controls->parallel.data, controls->parallel.size, resampleMinAngle,
            resampleNPoints, static_cast<double>(nParams), reflectivity[c_i].f1,
            simulation[c_i].f1, r4, r3, r2);
          c_loop_ub = r4.size(0);
          sldProfiles[c_i].f1.set_size(r4.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[c_i].f1[i3 + sldProfiles[c_i].f1.size(0) * i2] = r4[i3
                + r4.size(0) * i2];
            }
          }

          c_loop_ub = r3.size(1);
          layers[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r3.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layers[c_i].f1[i3 + layers[c_i].f1.size(0) * i2] = r3[i3 + r3.size
                (0) * i2];
            }
          }

          c_loop_ub = r2.size(0);
          resampledLayers[c_i].f1.set_size(r2.size(0), 4);
          for (i2 = 0; i2 < 4; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              resampledLayers[c_i].f1[i3 + resampledLayers[c_i].f1.size(0) * i2]
                = r2[i3 + r2.size(0) * i2];
            }
          }

          chis[c_i] = d;
        }
      } else {
        layers.set_size(loop_ub_tmp, 1);
        resampledLayers.set_size(loop_ub_tmp, 1);
        chis.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 1);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
          b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->data
            (), switch_expression_size, (const double *)((::coder::array<double,
            2U> *)&problemStruct.contrastResolutionParams[b_i].f1)->data(), iv,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
            iv1, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[b_i].f1
            )->data(), iv2, problemStruct.customFiles,
            problemStruct.scalefactors[static_cast<int>
            (problemStruct.contrastScalefactors[b_i]) - 1],
            problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
            b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
          chis[b_i] = coreLayersCalculation(contrastLayers[b_i].f1,
            subRoughs[b_i], problemStruct.geometry.data,
            problemStruct.geometry.size, problemStruct.bulkIns[static_cast<int>
            (problemStruct.contrastBulkIns[b_i]) - 1], problemStruct.bulkOuts[
            static_cast<int>(problemStruct.contrastBulkOuts[b_i]) - 1],
            problemStruct.resample[b_i], calcSld, shiftedData[b_i].f1,
            b_simulationXData, dataIndices, problemStruct.repeatLayers[b_i],
            backgrounds[b_i].f1, resolutions[b_i].f1, (const char *)((::coder::
            array<char, 2U> *)&problemStruct.contrastBackgroundActions[b_i].f1
            )->data(), switch_expression_size, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            static_cast<double>(nParams), reflectivity[b_i].f1, simulation[b_i].
            f1, r6, r7, r8);
          loop_ub = r6.size(0);
          sldProfiles[b_i].f1.set_size(r6.size(0), 2);
          for (int i{0}; i < 2; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0) * i] = r6[i1
                + r6.size(0) * i];
            }
          }

          loop_ub = r7.size(1);
          layers[b_i].f1.set_size(r7.size(0), r7.size(1));
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = r7.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[b_i].f1[i1 + layers[b_i].f1.size(0) * i] = r7[i1 + r7.size
                (0) * i];
            }
          }

          loop_ub = r8.size(0);
          resampledLayers[b_i].f1.set_size(r8.size(0), 4);
          for (int i{0}; i < 4; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[b_i].f1[i1 + resampledLayers[b_i].f1.size(0) * i] =
                r8[i1 + r8.size(0) * i];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          b_layers.set_size(layers[b_i].f1.size(0), layers[b_i].f1.size(1));
          loop_ub = layers[b_i].f1.size(1);
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = layers[b_i].f1.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_layers[i1 + b_layers.size(0) * i] = layers[b_i].f1[i1 +
                layers[b_i].f1.size(0) * i];
            }
          }

          layers[b_i].f1.set_size(b_layers.size(0), b_layers.size(1));
          loop_ub = b_layers.size(1);
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = b_layers.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[b_i].f1[i1 + layers[b_i].f1.size(0) * i] = b_layers[i1 +
                b_layers.size(0) * i];
            }
          }

          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1, r5);
          resampledLayers[b_i].f1.set_size(r5.size(0), 3);
          loop_ub = r5.size(0);
          for (int i{0}; i < 3; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[b_i].f1[i1 + resampledLayers[b_i].f1.size(0) * i] =
                r5[i1 + r5.size(0) * i];
            }
          }
        }
      }
    }

    void normalReflectivity(const ProblemDefinition &problemStruct, const
      Controls *controls, ::coder::array<cell_wrap_7, 1U> &reflectivity, ::coder::
      array<cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8, 1U>
      &shiftedData, ::coder::array<cell_wrap_8, 1U> &backgrounds, ::coder::array<
      cell_wrap_7, 1U> &resolutions, ::coder::array<cell_wrap_7, 2U>
      &sldProfiles, ::coder::array<cell_wrap_9, 2U> &layers, ::coder::array<
      cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U> &qzshifts, ::
      coder::array<double, 1U> &scalefactors, ::coder::array<double, 1U>
      &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double, 1U>
      &subRoughs, ::coder::array<double, 1U> &chis)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_9, 1U> contrastLayers;
      ::coder::array<cell_wrap_9, 1U> contrastSlds;
      ::coder::array<double, 2U> b_layers;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> r8;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int i2;
      int i3;
      int loop_ub;
      int loop_ub_tmp;
      int nParams;
      char switch_expression_data[10000];
      boolean_T useImaginary;

      //  This is the main normal reflectivity calculation.
      //  It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  the appropriate core calculation, which carries out the calculation
      //  itself. The core layers calculation is common for both standard and
      //  custom layers, with an additional core custom XY calculation.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;
      nParams = problemStruct.params.size(1);
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Find the actual values from the indices given in each contrast
      scalefactors.set_size(problemStruct.contrastScalefactors.size(1));
      loop_ub = problemStruct.contrastScalefactors.size(1);
      for (int i{0}; i < loop_ub; i++) {
        scalefactors[i] = problemStruct.scalefactors[static_cast<int>
          (problemStruct.contrastScalefactors[i]) - 1];
      }

      bulkIns.set_size(problemStruct.contrastBulkIns.size(1));
      loop_ub = problemStruct.contrastBulkIns.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkIns[i] = problemStruct.bulkIns[static_cast<int>
          (problemStruct.contrastBulkIns[i]) - 1];
      }

      bulkOuts.set_size(problemStruct.contrastBulkOuts.size(1));
      loop_ub = problemStruct.contrastBulkOuts.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkOuts[i] = problemStruct.bulkOuts[static_cast<int>
          (problemStruct.contrastBulkOuts[i]) - 1];
      }

      //  qzshifts are not included as a parameter in RAT,
      //  so we set up dummy values for the reflectivity calculation
      loop_ub_tmp = static_cast<int>(problemStruct.numberOfContrasts);
      qzshifts.set_size(loop_ub_tmp);
      for (int i{0}; i < loop_ub_tmp; i++) {
        qzshifts[i] = 0.0;
      }

      //  Allocate the memory for the output arrays before the main loop
      shiftedData.set_size(loop_ub_tmp);
      backgrounds.set_size(loop_ub_tmp);
      resolutions.set_size(loop_ub_tmp);
      contrastLayers.set_size(loop_ub_tmp);
      contrastSlds.set_size(loop_ub_tmp);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        shiftedData[b_i].f1.set_size(1, 3);
        backgrounds[b_i].f1.set_size(1, 3);
        shiftedData[b_i].f1[0] = 0.0;
        backgrounds[b_i].f1[0] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0)] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0)] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * 2] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0) * 2] = 0.0;
        resolutions[b_i].f1.set_size(1, 2);
        resolutions[b_i].f1[0] = 0.0;
        resolutions[b_i].f1[resolutions[b_i].f1.size(0)] = 0.0;
        contrastLayers[b_i].f1.set_size(1, 6);
        for (int i{0}; i < 6; i++) {
          contrastLayers[b_i].f1[contrastLayers[b_i].f1.size(0) * i] = 0.0;
        }

        contrastSlds[b_i].f1.set_size(1, 3);
        contrastSlds[b_i].f1[0] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0)] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0) * 2] = 0.0;
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::k_strcmp(switch_expression_data,
           switch_expression_size)) {
        loop_ub = 0;
      } else if (coder::internal::n_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub = 1;
      } else if (coder::internal::o_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub = 2;
      } else {
        loop_ub = -1;
      }

      switch (loop_ub) {
       case 0:
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only
        //  needs to be done once, and so is done outside the contrasts
        //  loop
        allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
          layerValues);
        subRoughs.set_size(loop_ub_tmp);
        contrastLayers.set_size(loop_ub_tmp);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers.
          subRoughs[b_i] = problemStruct.params[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry.
          allocateLayersForContrast(problemStruct.contrastLayers[b_i].f1,
            layerValues, r1);
          contrastLayers[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i{0}; i < 6; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              contrastLayers[b_i].f1[i1 + contrastLayers[b_i].f1.size(0) * i] =
                r1[i1 + r1.size(0) * i];
            }
          }
        }
        break;

       case 1:
        //  Process the custom models
        processCustomFunction(bulkIns, bulkOuts,
                              problemStruct.contrastCustomFiles,
                              problemStruct.numberOfContrasts,
                              problemStruct.customFiles, problemStruct.params,
                              problemStruct.useImaginary, contrastLayers,
                              subRoughs);
        break;

       case 2:
        //  Process the custom models
        b_processCustomFunction(bulkIns, bulkOuts,
          problemStruct.contrastCustomFiles, problemStruct.numberOfContrasts,
          problemStruct.customFiles, problemStruct.params,
          problemStruct.useImaginary, contrastSlds, subRoughs);
        break;

       default:
        //  Ensures a proper exception is thrown in the generated C++ code.
        //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
        //  and other parameters if message is a formatspec.
        //
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
        coder::b_sprintf(problemStruct.modelType.data,
                         problemStruct.modelType.size, r);
        coderException(1.0, &r[0]);
        break;
      }

      //  Run the core calculation for each contrast
      if (coder::internal::l_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          layers.set_size(loop_ub_tmp, 1);
          resampledLayers.set_size(loop_ub_tmp, 1);
          chis.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 1);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          loop_ub = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,c_loop_ub,i2,i3,d_loop_ub)

          for (int c_i = 0; c_i <= loop_ub; c_i++) {
            iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [1];
            iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [0];
            iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [1];
            iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [0];
            iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [1];
            iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [0];
            iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [1];
            dv2[0] = problemStruct.dataLimits[c_i].f1[0];
            dv2[1] = problemStruct.dataLimits[c_i].f1[1];
            dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
            dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)
              ->data(), iv3, (const double *)((::coder::array<double, 2U> *)
              &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
              problemStruct.backgroundParams, problemStruct.resolutionParams, (
              const char *)((::coder::array<char, 2U> *)
                            &problemStruct.contrastBackgroundTypes[c_i].f1)
              ->data(), iv5, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastResolutionTypes[c_i].f1)->data(), iv6,
              problemStruct.customFiles, scalefactors[c_i],
              problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2,
              dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [1];
            d = coreCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              shiftedData[c_i].f1, simulationXData, b_dataIndices,
              backgrounds[c_i].f1, resolutions[c_i].f1, (const char *)((::coder::
              array<char, 2U> *)&problemStruct.contrastBackgroundActions[c_i].f1)
              ->data(), iv3, controls->parallel.data, controls->parallel.size,
              resampleMinAngle, resampleNPoints, subRoughs[c_i],
              contrastSlds[c_i].f1, static_cast<double>(nParams),
              reflectivity[c_i].f1, simulation[c_i].f1, r4, r3, r2);
            c_loop_ub = r4.size(0);
            sldProfiles[c_i].f1.set_size(r4.size(0), 2);
            for (i2 = 0; i2 < 2; i2++) {
              for (i3 = 0; i3 < c_loop_ub; i3++) {
                sldProfiles[c_i].f1[i3 + sldProfiles[c_i].f1.size(0) * i2] =
                  r4[i3 + r4.size(0) * i2];
              }
            }

            c_loop_ub = r3.size(0);
            layers[c_i].f1.set_size(r3.size(0), 4);
            d_loop_ub = r2.size(0);
            resampledLayers[c_i].f1.set_size(r2.size(0), 4);
            for (i2 = 0; i2 < 4; i2++) {
              for (i3 = 0; i3 < c_loop_ub; i3++) {
                layers[c_i].f1[i3 + layers[c_i].f1.size(0) * i2] = r3[i3 +
                  r3.size(0) * i2];
              }

              for (i3 = 0; i3 < d_loop_ub; i3++) {
                resampledLayers[c_i].f1[i3 + resampledLayers[c_i].f1.size(0) *
                  i2] = r2[i3 + r2.size(0) * i2];
              }
            }

            chis[c_i] = d;
          }
        } else {
          layers.set_size(loop_ub_tmp, 1);
          resampledLayers.set_size(loop_ub_tmp, 1);
          chis.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 1);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
            iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [0];
            iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [1];
            iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [0];
            iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [1];
            iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [0];
            iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [1];
            b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
            b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
            b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
            b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)
              ->data(), switch_expression_size, (const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastResolutionParams[b_i].f1)
              ->data(), iv, problemStruct.backgroundParams,
              problemStruct.resolutionParams, (const char *)((::coder::array<
              char, 2U> *)&problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
              iv1, (const char *)((::coder::array<char, 2U> *)
                                  &problemStruct.contrastResolutionTypes[b_i].f1)
              ->data(), iv2, problemStruct.customFiles,
              problemStruct.scalefactors[static_cast<int>
              (problemStruct.contrastScalefactors[b_i]) - 1],
              problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
              b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].
              f1, shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
            chis[b_i] = coreCustomXYCalculation(problemStruct.bulkIns[
              static_cast<int>(problemStruct.contrastBulkIns[b_i]) - 1],
              problemStruct.bulkOuts[static_cast<int>
              (problemStruct.contrastBulkOuts[b_i]) - 1], shiftedData[b_i].f1,
              b_simulationXData, dataIndices, backgrounds[b_i].f1,
              resolutions[b_i].f1, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastBackgroundActions[b_i].f1)->data(),
              switch_expression_size, controls->parallel.data,
              controls->parallel.size, resampleMinAngle, resampleNPoints,
              subRoughs[b_i], contrastSlds[b_i].f1, static_cast<double>(nParams),
              reflectivity[b_i].f1, simulation[b_i].f1, r6, r8, r7);
            loop_ub = r6.size(0);
            sldProfiles[b_i].f1.set_size(r6.size(0), 2);
            for (int i{0}; i < 2; i++) {
              for (int i1{0}; i1 < loop_ub; i1++) {
                sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0) * i] =
                  r6[i1 + r6.size(0) * i];
              }
            }

            loop_ub = r8.size(0);
            layers[b_i].f1.set_size(r8.size(0), 4);
            b_loop_ub = r7.size(0);
            resampledLayers[b_i].f1.set_size(r7.size(0), 4);
            for (int i{0}; i < 4; i++) {
              for (int i1{0}; i1 < loop_ub; i1++) {
                layers[b_i].f1[i1 + layers[b_i].f1.size(0) * i] = r8[i1 +
                  r8.size(0) * i];
              }

              for (int i1{0}; i1 < b_loop_ub; i1++) {
                resampledLayers[b_i].f1[i1 + resampledLayers[b_i].f1.size(0) * i]
                  = r7[i1 + r7.size(0) * i];
              }
            }
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        layers.set_size(loop_ub_tmp, 1);
        resampledLayers.set_size(loop_ub_tmp, 1);
        chis.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 1);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        loop_ub = loop_ub_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,c_loop_ub,i2,i3,d_loop_ub)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)->data
            (), iv3, (const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[c_i].f1)->data(),
            iv5, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[c_i].f1
            )->data(), iv6, problemStruct.customFiles, scalefactors[c_i],
            problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2, dv3,
            numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
            shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          d = coreLayersCalculation(contrastLayers[c_i].f1, subRoughs[c_i],
            problemStruct.geometry.data, problemStruct.geometry.size,
            bulkIns[c_i], bulkOuts[c_i], problemStruct.resample[c_i], true,
            shiftedData[c_i].f1, simulationXData, b_dataIndices,
            problemStruct.repeatLayers[c_i], backgrounds[c_i].f1,
            resolutions[c_i].f1, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv3,
            controls->parallel.data, controls->parallel.size, resampleMinAngle,
            resampleNPoints, static_cast<double>(nParams), reflectivity[c_i].f1,
            simulation[c_i].f1, r4, r3, r2);
          c_loop_ub = r4.size(0);
          sldProfiles[c_i].f1.set_size(r4.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[c_i].f1[i3 + sldProfiles[c_i].f1.size(0) * i2] = r4[i3
                + r4.size(0) * i2];
            }
          }

          c_loop_ub = r3.size(1);
          layers[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r3.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layers[c_i].f1[i3 + layers[c_i].f1.size(0) * i2] = r3[i3 + r3.size
                (0) * i2];
            }
          }

          c_loop_ub = r2.size(0);
          resampledLayers[c_i].f1.set_size(r2.size(0), 4);
          for (i2 = 0; i2 < 4; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              resampledLayers[c_i].f1[i3 + resampledLayers[c_i].f1.size(0) * i2]
                = r2[i3 + r2.size(0) * i2];
            }
          }

          chis[c_i] = d;
        }
      } else {
        layers.set_size(loop_ub_tmp, 1);
        resampledLayers.set_size(loop_ub_tmp, 1);
        chis.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 1);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
          b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->data
            (), switch_expression_size, (const double *)((::coder::array<double,
            2U> *)&problemStruct.contrastResolutionParams[b_i].f1)->data(), iv,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
            iv1, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[b_i].f1
            )->data(), iv2, problemStruct.customFiles,
            problemStruct.scalefactors[static_cast<int>
            (problemStruct.contrastScalefactors[b_i]) - 1],
            problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
            b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
          chis[b_i] = coreLayersCalculation(contrastLayers[b_i].f1,
            subRoughs[b_i], problemStruct.geometry.data,
            problemStruct.geometry.size, problemStruct.bulkIns[static_cast<int>
            (problemStruct.contrastBulkIns[b_i]) - 1], problemStruct.bulkOuts[
            static_cast<int>(problemStruct.contrastBulkOuts[b_i]) - 1],
            problemStruct.resample[b_i], true, shiftedData[b_i].f1,
            b_simulationXData, dataIndices, problemStruct.repeatLayers[b_i],
            backgrounds[b_i].f1, resolutions[b_i].f1, (const char *)((::coder::
            array<char, 2U> *)&problemStruct.contrastBackgroundActions[b_i].f1
            )->data(), switch_expression_size, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            static_cast<double>(nParams), reflectivity[b_i].f1, simulation[b_i].
            f1, r6, r7, r8);
          loop_ub = r6.size(0);
          sldProfiles[b_i].f1.set_size(r6.size(0), 2);
          for (int i{0}; i < 2; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0) * i] = r6[i1
                + r6.size(0) * i];
            }
          }

          loop_ub = r7.size(1);
          layers[b_i].f1.set_size(r7.size(0), r7.size(1));
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = r7.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[b_i].f1[i1 + layers[b_i].f1.size(0) * i] = r7[i1 + r7.size
                (0) * i];
            }
          }

          loop_ub = r8.size(0);
          resampledLayers[b_i].f1.set_size(r8.size(0), 4);
          for (int i{0}; i < 4; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[b_i].f1[i1 + resampledLayers[b_i].f1.size(0) * i] =
                r8[i1 + r8.size(0) * i];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          b_layers.set_size(layers[b_i].f1.size(0), layers[b_i].f1.size(1));
          loop_ub = layers[b_i].f1.size(1);
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = layers[b_i].f1.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_layers[i1 + b_layers.size(0) * i] = layers[b_i].f1[i1 +
                layers[b_i].f1.size(0) * i];
            }
          }

          layers[b_i].f1.set_size(b_layers.size(0), b_layers.size(1));
          loop_ub = b_layers.size(1);
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = b_layers.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[b_i].f1[i1 + layers[b_i].f1.size(0) * i] = b_layers[i1 +
                b_layers.size(0) * i];
            }
          }

          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1, r5);
          resampledLayers[b_i].f1.set_size(r5.size(0), 3);
          loop_ub = r5.size(0);
          for (int i{0}; i < 3; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[b_i].f1[i1 + resampledLayers[b_i].f1.size(0) * i] =
                r5[i1 + r5.size(0) * i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (normalReflectivity.cpp)
