//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// standardLayers.cpp
//
// Code generation for function 'standardLayers'
//

// Include files
#include "standardLayers.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "coreLayersCalculation.h"
#include "makeSimulationRange.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    static double contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], const ::coder::array<double, 2U>
      &backgroundParamValues, const ::coder::array<double, 2U>
      &scalefactorValues, const ::coder::array<double, 2U> &bulkInValues, const ::
      coder::array<double, 2U> &bulkOutValues, const ::coder::array<double, 2U>
      &resolutionParamValues, double dataPresent, const ::coder::array<double,
      2U> &data, const double dataLimits[2], const double simulationLimits[2],
      double repeatLayers, const char backgroundType_data[], const int
      backgroundType_size[2], const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &layerIndices, const ::coder::array<cell_wrap_51, 2U>
      &layerValues, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::
      array<double, 2U> &background, ::coder::array<double, 2U> &resolution, ::
      coder::array<double, 2U> &sldProfile, ::coder::array<double, 2U> &layers, ::
      coder::array<double, 2U> &resampledLayers, double &scalefactor, double
      &bulkIn, double &bulkOut, double &chi);
  }
}

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    static double contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], const ::coder::array<double, 2U>
      &backgroundParamValues, const ::coder::array<double, 2U>
      &scalefactorValues, const ::coder::array<double, 2U> &bulkInValues, const ::
      coder::array<double, 2U> &bulkOutValues, const ::coder::array<double, 2U>
      &resolutionParamValues, double dataPresent, const ::coder::array<double,
      2U> &data, const double dataLimits[2], const double simulationLimits[2],
      double repeatLayers, const char backgroundType_data[], const int
      backgroundType_size[2], const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &layerIndices, const ::coder::array<cell_wrap_51, 2U>
      &layerValues, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::
      array<double, 2U> &background, ::coder::array<double, 2U> &resolution, ::
      coder::array<double, 2U> &sldProfile, ::coder::array<double, 2U> &layers, ::
      coder::array<double, 2U> &resampledLayers, double &scalefactor, double
      &bulkIn, double &bulkOut, double &chi)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 1U> simulationXData;
      double dataIndices[2];

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactorValues,
               bulkInValues, bulkOutValues, scalefactor, bulkIn, bulkOut);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      //  Apply scale factors and q shifts to the data
      b_data.set_size(data.size(0), 6);
      for (int i{0}; i < 6; i++) {
        int loop_ub;
        loop_ub = data.size(0) - 1;
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(scalefactor, dataPresent, b_data, dataLimits, simulationLimits,
                numSimulationPoints, b_shiftedData);
      makeSimulationRange(b_shiftedData, simulationLimits, simulationXData,
                          dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParamValues,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParamValues, simulationXData,
                          dataIndices, resolution);

      //  Call the core layers calculation
      allocateLayersForContrast(layerIndices, layerValues, b_data);
      coreLayersCalculation(b_data, roughness, geometry_data, geometry_size,
                            bulkIn, bulkOut, resample, calcSld, b_shiftedData,
                            simulationXData, dataIndices, repeatLayers,
                            resolution, background, backgroundAction_data,
                            backgroundAction_size, parallel_data, parallel_size,
                            resampleMinAngle, resampleNPoints, reflectivity,
                            simulation, shiftedData, sldProfile, layers,
                            resampledLayers);

      //  Calculate chi squared
      chi = chiSquared(shiftedData, reflectivity, nParams);
      return 0.0;
    }

    void b_standardLayers(const ProblemDefinition &problemStruct, const Controls
                          *controls, ::coder::array<double, 1U> &qzshifts, ::
                          coder::array<double, 1U> &scalefactors, ::coder::array<
                          double, 1U> &bulkIns, ::coder::array<double, 1U>
                          &bulkOuts, ::coder::array<double, 1U> &chis, ::coder::
                          array<cell_wrap_7, 1U> &reflectivity, ::coder::array<
                          cell_wrap_7, 1U> &simulation, ::coder::array<
                          cell_wrap_8, 1U> &shiftedData, ::coder::array<
                          cell_wrap_8, 1U> &backgrounds, ::coder::array<
                          cell_wrap_7, 1U> &resolutions, ::coder::array<
                          cell_wrap_9, 2U> &sldProfiles, ::coder::array<
                          cell_wrap_9, 2U> &layers, ::coder::array<cell_wrap_9,
                          2U> &resampledLayers, ::coder::array<double, 1U>
                          &subRoughs)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<double, 2U> b_layers;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      double dv2[2];
      double dv3[2];
      double d;
      double d1;
      double d2;
      double d3;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int i;
      int i3;
      int i4;
      int loop_ub;
      int nParams;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;

      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      calcSld = controls->calcSldDuringFit;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
        layerValues);

      //  Substrate roughness is always first parameter for standard layers
      i = static_cast<int>(problemStruct.numberOfContrasts);
      subRoughs.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
        subRoughs[b_i] = problemStruct.params[0];
      }

      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        layers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        resolutions.set_size(i);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        chis.set_size(i);
        loop_ub = i - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,d,d1,d2,d3,iv5,iv6,dv2,dv3,iv7,iv8,iv9,c_loop_ub,i3,i4,d_loop_ub)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[c_i].f1)->data(), iv5,
                              problemStruct.contrastScalefactors[c_i],
                              problemStruct.contrastBulkIns[c_i],
                              problemStruct.contrastBulkOuts[c_i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv6,
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.dataPresent[c_i],
                              problemStruct.data[c_i].f1, dv2, dv3,
                              problemStruct.repeatLayers[c_i], (const char *)((::
            coder::array<char, 2U> *)&problemStruct.contrastBackgroundTypes[c_i]
            .f1)->data(), iv7, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[c_i].f1)->data(),
                              iv9, problemStruct.customFiles, static_cast<double>
                              (nParams), controls->parallel.data,
                              controls->parallel.size, numSimulationPoints,
                              resampleMinAngle, resampleNPoints,
                              problemStruct.resample[c_i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[c_i],
                              calcSld, problemStruct.contrastLayers[c_i].f1,
                              layerValues, reflectivity[c_i].f1, simulation[c_i]
                              .f1, shiftedData[c_i].f1, backgrounds[c_i].f1,
                              resolutions[c_i].f1, r2, r1, r, d3, d2, d1, d);
          c_loop_ub = r2.size(0);
          sldProfiles[c_i].f1.set_size(r2.size(0), 2);
          for (i3 = 0; i3 < 2; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r2[i4
                + r2.size(0) * i3];
            }
          }

          c_loop_ub = r1.size(1);
          layers[c_i].f1.set_size(r1.size(0), r1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layers[c_i].f1[i4 + layers[c_i].f1.size(0) * i3] = r1[i4 + r1.size
                (0) * i3];
            }
          }

          c_loop_ub = r.size(0);
          resampledLayers[c_i].f1.set_size(r.size(0), 4);
          for (i3 = 0; i3 < 4; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              resampledLayers[c_i].f1[i4 + resampledLayers[c_i].f1.size(0) * i3]
                = r[i4 + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        layers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        resolutions.set_size(i);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        chis.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
          b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[b_i].f1)->data(), iv,
                              problemStruct.contrastScalefactors[b_i],
                              problemStruct.contrastBulkIns[b_i],
                              problemStruct.contrastBulkOuts[b_i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[b_i].f1)->data(), iv1,
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.dataPresent[b_i],
                              problemStruct.data[b_i].f1, b_dv, b_dv1,
                              problemStruct.repeatLayers[b_i], (const char *)((::
            coder::array<char, 2U> *)&problemStruct.contrastBackgroundTypes[b_i]
            .f1)->data(), iv2, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->data(), iv3, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[b_i].f1)->data(),
                              iv4, problemStruct.customFiles, static_cast<double>
                              (problemStruct.params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              numSimulationPoints, resampleMinAngle,
                              resampleNPoints, problemStruct.resample[b_i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[b_i],
                              calcSld, problemStruct.contrastLayers[b_i].f1,
                              layerValues, reflectivity[b_i].f1, simulation[b_i]
                              .f1, shiftedData[b_i].f1, backgrounds[b_i].f1,
                              resolutions[b_i].f1, r4, r5, r6, d4, d5, d6, d7);
          chis[b_i] = d7;
          bulkOuts[b_i] = d6;
          bulkIns[b_i] = d5;
          scalefactors[b_i] = d4;
          loop_ub = r4.size(0);
          sldProfiles[b_i].f1.set_size(r4.size(0), 2);
          for (int i1{0}; i1 < 2; i1++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r4[i2
                + r4.size(0) * i1];
            }
          }

          loop_ub = r5.size(1);
          layers[b_i].f1.set_size(r5.size(0), r5.size(1));
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = r5.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              layers[b_i].f1[i2 + layers[b_i].f1.size(0) * i1] = r5[i2 + r5.size
                (0) * i1];
            }
          }

          loop_ub = r6.size(0);
          resampledLayers[b_i].f1.set_size(r6.size(0), 4);
          for (int i1{0}; i1 < 4; i1++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r6[i2 + r6.size(0) * i1];
            }
          }

          qzshifts[b_i] = 0.0;
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < i; b_i++) {
          b_layers.set_size(layers[b_i].f1.size(0), layers[b_i].f1.size(1));
          loop_ub = layers[b_i].f1.size(1);
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = layers[b_i].f1.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              b_layers[i2 + b_layers.size(0) * i1] = layers[b_i].f1[i2 +
                layers[b_i].f1.size(0) * i1];
            }
          }

          layers[b_i].f1.set_size(b_layers.size(0), b_layers.size(1));
          loop_ub = b_layers.size(1);
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = b_layers.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              layers[b_i].f1[i2 + layers[b_i].f1.size(0) * i1] = b_layers[i2 +
                b_layers.size(0) * i1];
            }
          }

          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1, r3);
          resampledLayers[b_i].f1.set_size(r3.size(0), 3);
          loop_ub = r3.size(0);
          for (int i1{0}; i1 < 3; i1++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r3[i2 + r3.size(0) * i1];
            }
          }
        }
      }
    }

    void standardLayers(const ProblemDefinition &problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U>
                        &sldProfiles, ::coder::array<cell_wrap_9, 2U> &layers, ::
                        coder::array<cell_wrap_9, 2U> &resampledLayers, ::coder::
                        array<double, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<double, 2U> b_layers;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      double dv2[2];
      double dv3[2];
      double d;
      double d1;
      double d2;
      double d3;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int i;
      int i3;
      int i4;
      int loop_ub;
      int nParams;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;

      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
        layerValues);

      //  Substrate roughness is always first parameter for standard layers
      i = static_cast<int>(problemStruct.numberOfContrasts);
      subRoughs.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
        subRoughs[b_i] = problemStruct.params[0];
      }

      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        layers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        resolutions.set_size(i);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        chis.set_size(i);
        loop_ub = i - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,d,d1,d2,d3,iv5,iv6,dv2,dv3,iv7,iv8,iv9,c_loop_ub,i3,i4,d_loop_ub)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[c_i].f1)->data(), iv5,
                              problemStruct.contrastScalefactors[c_i],
                              problemStruct.contrastBulkIns[c_i],
                              problemStruct.contrastBulkOuts[c_i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv6,
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.dataPresent[c_i],
                              problemStruct.data[c_i].f1, dv2, dv3,
                              problemStruct.repeatLayers[c_i], (const char *)((::
            coder::array<char, 2U> *)&problemStruct.contrastBackgroundTypes[c_i]
            .f1)->data(), iv7, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[c_i].f1)->data(),
                              iv9, problemStruct.customFiles, static_cast<double>
                              (nParams), controls->parallel.data,
                              controls->parallel.size, numSimulationPoints,
                              resampleMinAngle, resampleNPoints,
                              problemStruct.resample[c_i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[c_i], true,
                              problemStruct.contrastLayers[c_i].f1, layerValues,
                              reflectivity[c_i].f1, simulation[c_i].f1,
                              shiftedData[c_i].f1, backgrounds[c_i].f1,
                              resolutions[c_i].f1, r2, r1, r, d3, d2, d1, d);
          c_loop_ub = r2.size(0);
          sldProfiles[c_i].f1.set_size(r2.size(0), 2);
          for (i3 = 0; i3 < 2; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r2[i4
                + r2.size(0) * i3];
            }
          }

          c_loop_ub = r1.size(1);
          layers[c_i].f1.set_size(r1.size(0), r1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layers[c_i].f1[i4 + layers[c_i].f1.size(0) * i3] = r1[i4 + r1.size
                (0) * i3];
            }
          }

          c_loop_ub = r.size(0);
          resampledLayers[c_i].f1.set_size(r.size(0), 4);
          for (i3 = 0; i3 < 4; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              resampledLayers[c_i].f1[i4 + resampledLayers[c_i].f1.size(0) * i3]
                = r[i4 + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        layers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        resolutions.set_size(i);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        chis.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
          b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[b_i].f1)->data(), iv,
                              problemStruct.contrastScalefactors[b_i],
                              problemStruct.contrastBulkIns[b_i],
                              problemStruct.contrastBulkOuts[b_i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[b_i].f1)->data(), iv1,
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.dataPresent[b_i],
                              problemStruct.data[b_i].f1, b_dv, b_dv1,
                              problemStruct.repeatLayers[b_i], (const char *)((::
            coder::array<char, 2U> *)&problemStruct.contrastBackgroundTypes[b_i]
            .f1)->data(), iv2, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->data(), iv3, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[b_i].f1)->data(),
                              iv4, problemStruct.customFiles, static_cast<double>
                              (problemStruct.params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              numSimulationPoints, resampleMinAngle,
                              resampleNPoints, problemStruct.resample[b_i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[b_i], true,
                              problemStruct.contrastLayers[b_i].f1, layerValues,
                              reflectivity[b_i].f1, simulation[b_i].f1,
                              shiftedData[b_i].f1, backgrounds[b_i].f1,
                              resolutions[b_i].f1, r4, r5, r6, d4, d5, d6, d7);
          chis[b_i] = d7;
          bulkOuts[b_i] = d6;
          bulkIns[b_i] = d5;
          scalefactors[b_i] = d4;
          loop_ub = r4.size(0);
          sldProfiles[b_i].f1.set_size(r4.size(0), 2);
          for (int i1{0}; i1 < 2; i1++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r4[i2
                + r4.size(0) * i1];
            }
          }

          loop_ub = r5.size(1);
          layers[b_i].f1.set_size(r5.size(0), r5.size(1));
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = r5.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              layers[b_i].f1[i2 + layers[b_i].f1.size(0) * i1] = r5[i2 + r5.size
                (0) * i1];
            }
          }

          loop_ub = r6.size(0);
          resampledLayers[b_i].f1.set_size(r6.size(0), 4);
          for (int i1{0}; i1 < 4; i1++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r6[i2 + r6.size(0) * i1];
            }
          }

          qzshifts[b_i] = 0.0;
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < i; b_i++) {
          b_layers.set_size(layers[b_i].f1.size(0), layers[b_i].f1.size(1));
          loop_ub = layers[b_i].f1.size(1);
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = layers[b_i].f1.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              b_layers[i2 + b_layers.size(0) * i1] = layers[b_i].f1[i2 +
                layers[b_i].f1.size(0) * i1];
            }
          }

          layers[b_i].f1.set_size(b_layers.size(0), b_layers.size(1));
          loop_ub = b_layers.size(1);
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = b_layers.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              layers[b_i].f1[i2 + layers[b_i].f1.size(0) * i1] = b_layers[i2 +
                b_layers.size(0) * i1];
            }
          }

          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1, r3);
          resampledLayers[b_i].f1.set_size(r3.size(0), 3);
          loop_ub = r3.size(0);
          for (int i1{0}; i1 < 3; i1++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r3[i2 + r3.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (standardLayers.cpp)
