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
#include "extractProblemParams.h"
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
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> simulationLimits;
      ::coder::array<cell_wrap_44, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_9, 2U> a__3;
      ::coder::array<cell_wrap_9, 2U> contrastLayersIndices;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<cell_wrap_9, 2U> layersDetails;
      ::coder::array<cell_wrap_9, 1U> contrastLayers;
      ::coder::array<cell_wrap_9, 1U> contrastSlds;
      ::coder::array<double, 2U> a__1;
      ::coder::array<double, 2U> a__2;
      ::coder::array<double, 2U> b_layers;
      ::coder::array<double, 2U> backgroundParamValues;
      ::coder::array<double, 2U> contrastCustomFiles;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> paramValues;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> r8;
      ::coder::array<double, 2U> repeatLayers;
      ::coder::array<double, 2U> resample;
      ::coder::array<double, 2U> resolutionParamValues;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double nParams;
      double numSimulationPoints;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int geometry_size[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_index;
      int b_loop_ub;
      int c_loop_ub;
      int i;
      int i1;
      int i4;
      int i5;
      int loop_ub;
      char geometry_data[10000];
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
      numberOfContrasts = extractProblemParams(problemStruct, geometry_data,
        geometry_size, contrastBackgroundIndices, contrastResolutionIndices,
        a__1, backgroundParamValues, resolutionParamValues, qzshifts,
        scalefactors, bulkIns, bulkOuts, a__2, dataPresent, paramValues,
        resample, contrastBackgroundTypes, contrastBackgroundActions,
        contrastResolutionTypes, contrastCustomFiles, repeatLayers, data,
        dataLimits, simulationLimits, contrastLayersIndices, layersDetails,
        customFiles, a__3, nParams, useImaginary);
      calcSld = controls->calcSldDuringFit;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      i = static_cast<int>(numberOfContrasts);
      i1 = static_cast<int>(numberOfContrasts);
      shiftedData.set_size(i);
      backgrounds.set_size(i);
      resolutions.set_size(i);
      contrastLayers.set_size(i);
      contrastSlds.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
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
        for (int i2{0}; i2 < 6; i2++) {
          contrastLayers[b_i].f1[contrastLayers[b_i].f1.size(0) * i2] = 0.0;
        }

        contrastSlds[b_i].f1.set_size(1, 3);
        contrastSlds[b_i].f1[0] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0)] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0) * 2] = 0.0;
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::l_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::n_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::o_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only
        //  needs to be done once, and so is done outside the contrasts
        //  loop
        allocateParamsToLayers(paramValues, layersDetails, layerValues);
        subRoughs.set_size(i);
        contrastLayers.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers.
          subRoughs[b_i] = paramValues[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry.
          allocateLayersForContrast(contrastLayersIndices[b_i].f1, layerValues,
            r1);
          contrastLayers[b_i].f1.set_size(r1.size(0), 6);
          b_index = r1.size(0);
          for (int i2{0}; i2 < 6; i2++) {
            for (int i3{0}; i3 < b_index; i3++) {
              contrastLayers[b_i].f1[i3 + contrastLayers[b_i].f1.size(0) * i2] =
                r1[i3 + r1.size(0) * i2];
            }
          }
        }
        break;

       case 1:
        //  Process the custom models
        processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
                              numberOfContrasts, customFiles, paramValues,
                              useImaginary, contrastLayers, subRoughs);
        break;

       case 2:
        //  Process the custom models
        b_processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
          numberOfContrasts, customFiles, paramValues, useImaginary,
          contrastSlds, subRoughs);
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
      if (coder::internal::c_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          layers.set_size(i, 1);
          resampledLayers.set_size(i, 1);
          chis.set_size(i);
          sldProfiles.set_size(i, 1);
          simulation.set_size(i);
          reflectivity.set_size(i);
          b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,b_loop_ub,i4,i5,c_loop_ub)

          for (int c_i = 0; c_i <= b_index; c_i++) {
            iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
            iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
            iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
            iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
            iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
            iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
            iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
            dv2[0] = dataLimits[c_i].f1[0];
            dv2[1] = dataLimits[c_i].f1[1];
            dv3[0] = simulationLimits[c_i].f1[0];
            dv3[1] = simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
              contrastResolutionIndices[c_i].f1.data(), iv4,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[c_i].f1.data(), iv5, (const char *)
              contrastResolutionTypes[c_i].f1.data(), iv6, customFiles,
              scalefactors[c_i], dataPresent[c_i], data[c_i].f1, dv2, dv3,
              numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
            d = coreCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              shiftedData[c_i].f1, simulationXData, b_dataIndices,
              backgrounds[c_i].f1, resolutions[c_i].f1, (const char *)
              contrastBackgroundActions[c_i].f1.data(), iv3,
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[c_i], contrastSlds[c_i].f1, nParams,
              reflectivity[c_i].f1, simulation[c_i].f1, r4, r3, r2);
            b_loop_ub = r4.size(0);
            sldProfiles[c_i].f1.set_size(r4.size(0), 2);
            for (i4 = 0; i4 < 2; i4++) {
              for (i5 = 0; i5 < b_loop_ub; i5++) {
                sldProfiles[c_i].f1[i5 + sldProfiles[c_i].f1.size(0) * i4] =
                  r4[i5 + r4.size(0) * i4];
              }
            }

            b_loop_ub = r3.size(0);
            layers[c_i].f1.set_size(r3.size(0), 4);
            c_loop_ub = r2.size(0);
            resampledLayers[c_i].f1.set_size(r2.size(0), 4);
            for (i4 = 0; i4 < 4; i4++) {
              for (i5 = 0; i5 < b_loop_ub; i5++) {
                layers[c_i].f1[i5 + layers[c_i].f1.size(0) * i4] = r3[i5 +
                  r3.size(0) * i4];
              }

              for (i5 = 0; i5 < c_loop_ub; i5++) {
                resampledLayers[c_i].f1[i5 + resampledLayers[c_i].f1.size(0) *
                  i4] = r2[i5 + r2.size(0) * i4];
              }
            }

            chis[c_i] = d;
          }
        } else {
          layers.set_size(i, 1);
          resampledLayers.set_size(i, 1);
          chis.set_size(i);
          sldProfiles.set_size(i, 1);
          simulation.set_size(i);
          reflectivity.set_size(i);
          for (int b_i{0}; b_i < i; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[1];
            iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
            iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
            iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
            iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
            iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
            iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
            b_dv[0] = dataLimits[b_i].f1[0];
            b_dv[1] = dataLimits[b_i].f1[1];
            b_dv1[0] = simulationLimits[b_i].f1[0];
            b_dv1[1] = simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[b_i].f1.data(), switch_expression_size,
              (const double *)contrastResolutionIndices[b_i].f1.data(), iv,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
              contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
              scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
              numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
              shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[1];
            chis[b_i] = coreCustomXYCalculation(bulkIns[b_i], bulkOuts[b_i],
              shiftedData[b_i].f1, b_simulationXData, dataIndices,
              backgrounds[b_i].f1, resolutions[b_i].f1, (const char *)
              contrastBackgroundActions[b_i].f1.data(), switch_expression_size,
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[b_i], contrastSlds[b_i].f1, nParams,
              reflectivity[b_i].f1, simulation[b_i].f1, r6, r8, r7);
            b_index = r6.size(0);
            sldProfiles[b_i].f1.set_size(r6.size(0), 2);
            for (int i2{0}; i2 < 2; i2++) {
              for (int i3{0}; i3 < b_index; i3++) {
                sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] =
                  r6[i3 + r6.size(0) * i2];
              }
            }

            b_index = r8.size(0);
            layers[b_i].f1.set_size(r8.size(0), 4);
            loop_ub = r7.size(0);
            resampledLayers[b_i].f1.set_size(r7.size(0), 4);
            for (int i2{0}; i2 < 4; i2++) {
              for (int i3{0}; i3 < b_index; i3++) {
                layers[b_i].f1[i3 + layers[b_i].f1.size(0) * i2] = r8[i3 +
                  r8.size(0) * i2];
              }

              for (int i3{0}; i3 < loop_ub; i3++) {
                resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) *
                  i2] = r7[i3 + r7.size(0) * i2];
              }
            }
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        layers.set_size(i, 1);
        resampledLayers.set_size(i, 1);
        chis.set_size(i);
        sldProfiles.set_size(i, 1);
        simulation.set_size(i);
        reflectivity.set_size(i);
        b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,b_loop_ub,i4,i5,c_loop_ub)

        for (int c_i = 0; c_i <= b_index; c_i++) {
          iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          dv2[0] = dataLimits[c_i].f1[0];
          dv2[1] = dataLimits[c_i].f1[1];
          dv3[0] = simulationLimits[c_i].f1[0];
          dv3[1] = simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
            contrastResolutionIndices[c_i].f1.data(), iv4, backgroundParamValues,
            resolutionParamValues, (const char *)contrastBackgroundTypes[c_i].
            f1.data(), iv5, (const char *)contrastResolutionTypes[c_i].f1.data(),
            iv6, customFiles, scalefactors[c_i], dataPresent[c_i], data[c_i].f1,
            dv2, dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i]
            .f1, shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          d = coreLayersCalculation(contrastLayers[c_i].f1, subRoughs[c_i],
            geometry_data, geometry_size, bulkIns[c_i], bulkOuts[c_i],
            resample[c_i], calcSld, shiftedData[c_i].f1, simulationXData,
            b_dataIndices, repeatLayers[c_i], backgrounds[c_i].f1,
            resolutions[c_i].f1, (const char *)contrastBackgroundActions[c_i].
            f1.data(), iv3, controls->parallel.data, controls->parallel.size,
            resampleMinAngle, resampleNPoints, nParams, reflectivity[c_i].f1,
            simulation[c_i].f1, r4, r3, r2);
          b_loop_ub = r4.size(0);
          sldProfiles[c_i].f1.set_size(r4.size(0), 2);
          for (i4 = 0; i4 < 2; i4++) {
            for (i5 = 0; i5 < b_loop_ub; i5++) {
              sldProfiles[c_i].f1[i5 + sldProfiles[c_i].f1.size(0) * i4] = r4[i5
                + r4.size(0) * i4];
            }
          }

          b_loop_ub = r3.size(1);
          layers[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i4 = 0; i4 < b_loop_ub; i4++) {
            c_loop_ub = r3.size(0);
            for (i5 = 0; i5 < c_loop_ub; i5++) {
              layers[c_i].f1[i5 + layers[c_i].f1.size(0) * i4] = r3[i5 + r3.size
                (0) * i4];
            }
          }

          b_loop_ub = r2.size(0);
          resampledLayers[c_i].f1.set_size(r2.size(0), 4);
          for (i4 = 0; i4 < 4; i4++) {
            for (i5 = 0; i5 < b_loop_ub; i5++) {
              resampledLayers[c_i].f1[i5 + resampledLayers[c_i].f1.size(0) * i4]
                = r2[i5 + r2.size(0) * i4];
            }
          }

          chis[c_i] = d;
        }
      } else {
        layers.set_size(i, 1);
        resampledLayers.set_size(i, 1);
        chis.set_size(i);
        sldProfiles.set_size(i, 1);
        simulation.set_size(i);
        reflectivity.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[1];
          iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
          b_dv[0] = dataLimits[b_i].f1[0];
          b_dv[1] = dataLimits[b_i].f1[1];
          b_dv1[0] = simulationLimits[b_i].f1[0];
          b_dv1[1] = simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[b_i].f1.data(), switch_expression_size, (
            const double *)contrastResolutionIndices[b_i].f1.data(), iv,
            backgroundParamValues, resolutionParamValues, (const char *)
            contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
            contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
            scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
            numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[1];
          chis[b_i] = coreLayersCalculation(contrastLayers[b_i].f1,
            subRoughs[b_i], geometry_data, geometry_size, bulkIns[b_i],
            bulkOuts[b_i], resample[b_i], calcSld, shiftedData[b_i].f1,
            b_simulationXData, dataIndices, repeatLayers[b_i], backgrounds[b_i].
            f1, resolutions[b_i].f1, (const char *)contrastBackgroundActions[b_i]
            .f1.data(), switch_expression_size, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints, nParams,
            reflectivity[b_i].f1, simulation[b_i].f1, r6, r7, r8);
          b_index = r6.size(0);
          sldProfiles[b_i].f1.set_size(r6.size(0), 2);
          for (int i2{0}; i2 < 2; i2++) {
            for (int i3{0}; i3 < b_index; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r6[i3
                + r6.size(0) * i2];
            }
          }

          b_index = r7.size(1);
          layers[b_i].f1.set_size(r7.size(0), r7.size(1));
          for (int i2{0}; i2 < b_index; i2++) {
            loop_ub = r7.size(0);
            for (int i3{0}; i3 < loop_ub; i3++) {
              layers[b_i].f1[i3 + layers[b_i].f1.size(0) * i2] = r7[i3 + r7.size
                (0) * i2];
            }
          }

          b_index = r8.size(0);
          resampledLayers[b_i].f1.set_size(r8.size(0), 4);
          for (int i2{0}; i2 < 4; i2++) {
            for (int i3{0}; i3 < b_index; i3++) {
              resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) * i2]
                = r8[i3 + r8.size(0) * i2];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < i1; b_i++) {
          b_layers.set_size(layers[b_i].f1.size(0), layers[b_i].f1.size(1));
          b_index = layers[b_i].f1.size(1);
          for (i = 0; i < b_index; i++) {
            loop_ub = layers[b_i].f1.size(0);
            for (int i2{0}; i2 < loop_ub; i2++) {
              b_layers[i2 + b_layers.size(0) * i] = layers[b_i].f1[i2 +
                layers[b_i].f1.size(0) * i];
            }
          }

          layers[b_i].f1.set_size(b_layers.size(0), b_layers.size(1));
          b_index = b_layers.size(1);
          for (i = 0; i < b_index; i++) {
            loop_ub = b_layers.size(0);
            for (int i2{0}; i2 < loop_ub; i2++) {
              layers[b_i].f1[i2 + layers[b_i].f1.size(0) * i] = b_layers[i2 +
                b_layers.size(0) * i];
            }
          }

          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1, r5);
          resampledLayers[b_i].f1.set_size(r5.size(0), 3);
          b_index = r5.size(0);
          for (i = 0; i < 3; i++) {
            for (int i2{0}; i2 < b_index; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i] =
                r5[i2 + r5.size(0) * i];
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
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> simulationLimits;
      ::coder::array<cell_wrap_44, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_9, 2U> a__3;
      ::coder::array<cell_wrap_9, 2U> contrastLayersIndices;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<cell_wrap_9, 2U> layersDetails;
      ::coder::array<cell_wrap_9, 1U> contrastLayers;
      ::coder::array<cell_wrap_9, 1U> contrastSlds;
      ::coder::array<double, 2U> a__1;
      ::coder::array<double, 2U> a__2;
      ::coder::array<double, 2U> b_layers;
      ::coder::array<double, 2U> backgroundParamValues;
      ::coder::array<double, 2U> contrastCustomFiles;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> paramValues;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> r8;
      ::coder::array<double, 2U> repeatLayers;
      ::coder::array<double, 2U> resample;
      ::coder::array<double, 2U> resolutionParamValues;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double nParams;
      double numSimulationPoints;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int geometry_size[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_index;
      int b_loop_ub;
      int c_loop_ub;
      int i;
      int i1;
      int i4;
      int i5;
      int loop_ub;
      char geometry_data[10000];
      char switch_expression_data[10000];
      boolean_T useImaginary;

      //  This is the main normal reflectivity calculation.
      //  It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  the appropriate core calculation, which carries out the calculation
      //  itself. The core layers calculation is common for both standard and
      //  custom layers, with an additional core custom XY calculation.
      //  Extract parameters from problemStruct
      numberOfContrasts = extractProblemParams(problemStruct, geometry_data,
        geometry_size, contrastBackgroundIndices, contrastResolutionIndices,
        a__1, backgroundParamValues, resolutionParamValues, qzshifts,
        scalefactors, bulkIns, bulkOuts, a__2, dataPresent, paramValues,
        resample, contrastBackgroundTypes, contrastBackgroundActions,
        contrastResolutionTypes, contrastCustomFiles, repeatLayers, data,
        dataLimits, simulationLimits, contrastLayersIndices, layersDetails,
        customFiles, a__3, nParams, useImaginary);
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      i = static_cast<int>(numberOfContrasts);
      i1 = static_cast<int>(numberOfContrasts);
      shiftedData.set_size(i);
      backgrounds.set_size(i);
      resolutions.set_size(i);
      contrastLayers.set_size(i);
      contrastSlds.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
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
        for (int i2{0}; i2 < 6; i2++) {
          contrastLayers[b_i].f1[contrastLayers[b_i].f1.size(0) * i2] = 0.0;
        }

        contrastSlds[b_i].f1.set_size(1, 3);
        contrastSlds[b_i].f1[0] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0)] = 0.0;
        contrastSlds[b_i].f1[contrastSlds[b_i].f1.size(0) * 2] = 0.0;
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::l_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::n_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::o_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only
        //  needs to be done once, and so is done outside the contrasts
        //  loop
        allocateParamsToLayers(paramValues, layersDetails, layerValues);
        subRoughs.set_size(i);
        contrastLayers.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers.
          subRoughs[b_i] = paramValues[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry.
          allocateLayersForContrast(contrastLayersIndices[b_i].f1, layerValues,
            r1);
          contrastLayers[b_i].f1.set_size(r1.size(0), 6);
          b_index = r1.size(0);
          for (int i2{0}; i2 < 6; i2++) {
            for (int i3{0}; i3 < b_index; i3++) {
              contrastLayers[b_i].f1[i3 + contrastLayers[b_i].f1.size(0) * i2] =
                r1[i3 + r1.size(0) * i2];
            }
          }
        }
        break;

       case 1:
        //  Process the custom models
        processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
                              numberOfContrasts, customFiles, paramValues,
                              useImaginary, contrastLayers, subRoughs);
        break;

       case 2:
        //  Process the custom models
        b_processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
          numberOfContrasts, customFiles, paramValues, useImaginary,
          contrastSlds, subRoughs);
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
      if (coder::internal::c_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          layers.set_size(i, 1);
          resampledLayers.set_size(i, 1);
          chis.set_size(i);
          sldProfiles.set_size(i, 1);
          simulation.set_size(i);
          reflectivity.set_size(i);
          b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,b_loop_ub,i4,i5,c_loop_ub)

          for (int c_i = 0; c_i <= b_index; c_i++) {
            iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
            iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
            iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
            iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
            iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
            iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
            iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
            dv2[0] = dataLimits[c_i].f1[0];
            dv2[1] = dataLimits[c_i].f1[1];
            dv3[0] = simulationLimits[c_i].f1[0];
            dv3[1] = simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
              contrastResolutionIndices[c_i].f1.data(), iv4,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[c_i].f1.data(), iv5, (const char *)
              contrastResolutionTypes[c_i].f1.data(), iv6, customFiles,
              scalefactors[c_i], dataPresent[c_i], data[c_i].f1, dv2, dv3,
              numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
            d = coreCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              shiftedData[c_i].f1, simulationXData, b_dataIndices,
              backgrounds[c_i].f1, resolutions[c_i].f1, (const char *)
              contrastBackgroundActions[c_i].f1.data(), iv3,
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[c_i], contrastSlds[c_i].f1, nParams,
              reflectivity[c_i].f1, simulation[c_i].f1, r4, r3, r2);
            b_loop_ub = r4.size(0);
            sldProfiles[c_i].f1.set_size(r4.size(0), 2);
            for (i4 = 0; i4 < 2; i4++) {
              for (i5 = 0; i5 < b_loop_ub; i5++) {
                sldProfiles[c_i].f1[i5 + sldProfiles[c_i].f1.size(0) * i4] =
                  r4[i5 + r4.size(0) * i4];
              }
            }

            b_loop_ub = r3.size(0);
            layers[c_i].f1.set_size(r3.size(0), 4);
            c_loop_ub = r2.size(0);
            resampledLayers[c_i].f1.set_size(r2.size(0), 4);
            for (i4 = 0; i4 < 4; i4++) {
              for (i5 = 0; i5 < b_loop_ub; i5++) {
                layers[c_i].f1[i5 + layers[c_i].f1.size(0) * i4] = r3[i5 +
                  r3.size(0) * i4];
              }

              for (i5 = 0; i5 < c_loop_ub; i5++) {
                resampledLayers[c_i].f1[i5 + resampledLayers[c_i].f1.size(0) *
                  i4] = r2[i5 + r2.size(0) * i4];
              }
            }

            chis[c_i] = d;
          }
        } else {
          layers.set_size(i, 1);
          resampledLayers.set_size(i, 1);
          chis.set_size(i);
          sldProfiles.set_size(i, 1);
          simulation.set_size(i);
          reflectivity.set_size(i);
          for (int b_i{0}; b_i < i; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[1];
            iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
            iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
            iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
            iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
            iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
            iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
            b_dv[0] = dataLimits[b_i].f1[0];
            b_dv[1] = dataLimits[b_i].f1[1];
            b_dv1[0] = simulationLimits[b_i].f1[0];
            b_dv1[1] = simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[b_i].f1.data(), switch_expression_size,
              (const double *)contrastResolutionIndices[b_i].f1.data(), iv,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
              contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
              scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
              numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
              shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[1];
            chis[b_i] = coreCustomXYCalculation(bulkIns[b_i], bulkOuts[b_i],
              shiftedData[b_i].f1, b_simulationXData, dataIndices,
              backgrounds[b_i].f1, resolutions[b_i].f1, (const char *)
              contrastBackgroundActions[b_i].f1.data(), switch_expression_size,
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[b_i], contrastSlds[b_i].f1, nParams,
              reflectivity[b_i].f1, simulation[b_i].f1, r6, r8, r7);
            b_index = r6.size(0);
            sldProfiles[b_i].f1.set_size(r6.size(0), 2);
            for (int i2{0}; i2 < 2; i2++) {
              for (int i3{0}; i3 < b_index; i3++) {
                sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] =
                  r6[i3 + r6.size(0) * i2];
              }
            }

            b_index = r8.size(0);
            layers[b_i].f1.set_size(r8.size(0), 4);
            loop_ub = r7.size(0);
            resampledLayers[b_i].f1.set_size(r7.size(0), 4);
            for (int i2{0}; i2 < 4; i2++) {
              for (int i3{0}; i3 < b_index; i3++) {
                layers[b_i].f1[i3 + layers[b_i].f1.size(0) * i2] = r8[i3 +
                  r8.size(0) * i2];
              }

              for (int i3{0}; i3 < loop_ub; i3++) {
                resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) *
                  i2] = r7[i3 + r7.size(0) * i2];
              }
            }
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        layers.set_size(i, 1);
        resampledLayers.set_size(i, 1);
        chis.set_size(i);
        sldProfiles.set_size(i, 1);
        simulation.set_size(i);
        reflectivity.set_size(i);
        b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,r4,simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3,b_loop_ub,i4,i5,c_loop_ub)

        for (int c_i = 0; c_i <= b_index; c_i++) {
          iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          dv2[0] = dataLimits[c_i].f1[0];
          dv2[1] = dataLimits[c_i].f1[1];
          dv3[0] = simulationLimits[c_i].f1[0];
          dv3[1] = simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
            contrastResolutionIndices[c_i].f1.data(), iv4, backgroundParamValues,
            resolutionParamValues, (const char *)contrastBackgroundTypes[c_i].
            f1.data(), iv5, (const char *)contrastResolutionTypes[c_i].f1.data(),
            iv6, customFiles, scalefactors[c_i], dataPresent[c_i], data[c_i].f1,
            dv2, dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i]
            .f1, shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          d = coreLayersCalculation(contrastLayers[c_i].f1, subRoughs[c_i],
            geometry_data, geometry_size, bulkIns[c_i], bulkOuts[c_i],
            resample[c_i], true, shiftedData[c_i].f1, simulationXData,
            b_dataIndices, repeatLayers[c_i], backgrounds[c_i].f1,
            resolutions[c_i].f1, (const char *)contrastBackgroundActions[c_i].
            f1.data(), iv3, controls->parallel.data, controls->parallel.size,
            resampleMinAngle, resampleNPoints, nParams, reflectivity[c_i].f1,
            simulation[c_i].f1, r4, r3, r2);
          b_loop_ub = r4.size(0);
          sldProfiles[c_i].f1.set_size(r4.size(0), 2);
          for (i4 = 0; i4 < 2; i4++) {
            for (i5 = 0; i5 < b_loop_ub; i5++) {
              sldProfiles[c_i].f1[i5 + sldProfiles[c_i].f1.size(0) * i4] = r4[i5
                + r4.size(0) * i4];
            }
          }

          b_loop_ub = r3.size(1);
          layers[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i4 = 0; i4 < b_loop_ub; i4++) {
            c_loop_ub = r3.size(0);
            for (i5 = 0; i5 < c_loop_ub; i5++) {
              layers[c_i].f1[i5 + layers[c_i].f1.size(0) * i4] = r3[i5 + r3.size
                (0) * i4];
            }
          }

          b_loop_ub = r2.size(0);
          resampledLayers[c_i].f1.set_size(r2.size(0), 4);
          for (i4 = 0; i4 < 4; i4++) {
            for (i5 = 0; i5 < b_loop_ub; i5++) {
              resampledLayers[c_i].f1[i5 + resampledLayers[c_i].f1.size(0) * i4]
                = r2[i5 + r2.size(0) * i4];
            }
          }

          chis[c_i] = d;
        }
      } else {
        layers.set_size(i, 1);
        resampledLayers.set_size(i, 1);
        chis.set_size(i);
        sldProfiles.set_size(i, 1);
        simulation.set_size(i);
        reflectivity.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[1];
          iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
          b_dv[0] = dataLimits[b_i].f1[0];
          b_dv[1] = dataLimits[b_i].f1[1];
          b_dv1[0] = simulationLimits[b_i].f1[0];
          b_dv1[1] = simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[b_i].f1.data(), switch_expression_size, (
            const double *)contrastResolutionIndices[b_i].f1.data(), iv,
            backgroundParamValues, resolutionParamValues, (const char *)
            contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
            contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
            scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
            numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[1];
          chis[b_i] = coreLayersCalculation(contrastLayers[b_i].f1,
            subRoughs[b_i], geometry_data, geometry_size, bulkIns[b_i],
            bulkOuts[b_i], resample[b_i], true, shiftedData[b_i].f1,
            b_simulationXData, dataIndices, repeatLayers[b_i], backgrounds[b_i].
            f1, resolutions[b_i].f1, (const char *)contrastBackgroundActions[b_i]
            .f1.data(), switch_expression_size, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints, nParams,
            reflectivity[b_i].f1, simulation[b_i].f1, r6, r7, r8);
          b_index = r6.size(0);
          sldProfiles[b_i].f1.set_size(r6.size(0), 2);
          for (int i2{0}; i2 < 2; i2++) {
            for (int i3{0}; i3 < b_index; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r6[i3
                + r6.size(0) * i2];
            }
          }

          b_index = r7.size(1);
          layers[b_i].f1.set_size(r7.size(0), r7.size(1));
          for (int i2{0}; i2 < b_index; i2++) {
            loop_ub = r7.size(0);
            for (int i3{0}; i3 < loop_ub; i3++) {
              layers[b_i].f1[i3 + layers[b_i].f1.size(0) * i2] = r7[i3 + r7.size
                (0) * i2];
            }
          }

          b_index = r8.size(0);
          resampledLayers[b_i].f1.set_size(r8.size(0), 4);
          for (int i2{0}; i2 < 4; i2++) {
            for (int i3{0}; i3 < b_index; i3++) {
              resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) * i2]
                = r8[i3 + r8.size(0) * i2];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < i1; b_i++) {
          b_layers.set_size(layers[b_i].f1.size(0), layers[b_i].f1.size(1));
          b_index = layers[b_i].f1.size(1);
          for (i = 0; i < b_index; i++) {
            loop_ub = layers[b_i].f1.size(0);
            for (int i2{0}; i2 < loop_ub; i2++) {
              b_layers[i2 + b_layers.size(0) * i] = layers[b_i].f1[i2 +
                layers[b_i].f1.size(0) * i];
            }
          }

          layers[b_i].f1.set_size(b_layers.size(0), b_layers.size(1));
          b_index = b_layers.size(1);
          for (i = 0; i < b_index; i++) {
            loop_ub = b_layers.size(0);
            for (int i2{0}; i2 < loop_ub; i2++) {
              layers[b_i].f1[i2 + layers[b_i].f1.size(0) * i] = b_layers[i2 +
                b_layers.size(0) * i];
            }
          }

          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1, r5);
          resampledLayers[b_i].f1.set_size(r5.size(0), 3);
          b_index = r5.size(0);
          for (i = 0; i < 3; i++) {
            for (int i2{0}; i2 < b_index; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i] =
                r5[i2 + r5.size(0) * i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (normalReflectivity.cpp)
