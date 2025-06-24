//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// customLayers.cpp
//
// Code generation for function 'customLayers'
//

// Include files
#include "customLayers.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "backSort.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "coreLayersCalculation.h"
#include "makeSimulationRange.h"
#include "nullAssignment.h"
#include "processCustomFunction.h"
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
    static double b_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], const ::coder::array<double, 2U>
      &backgroundParamValues, const ::coder::array<double, 2U>
      &scalefactorValues, const ::coder::array<double, 2U> &bulkInValues, const ::
      coder::array<double, 2U> &bulkOutValues, const ::coder::array<double, 2U>
      &resolutionParamValues, double dataPresent, const ::coder::array<double,
      2U> &data, const double dataLimits[2], const double simulationLimits[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double numSimulationPoints,
      double resampleMinAngle, double resampleNPoints, double resample, const
      char geometry_data[], const int geometry_size[2], double roughness,
      boolean_T calcSld, const ::coder::array<double, 2U> &contrastLayers, ::
      coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::array<
      double, 2U> &background, ::coder::array<double, 2U> &resolution, ::coder::
      array<double, 2U> &sldProfile, ::coder::array<double, 2U> &layers, ::coder::
      array<double, 2U> &resampledLayers, double &scalefactor, double &bulkIn,
      double &bulkOut, double &chi);
  }
}

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    static double b_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], const ::coder::array<double, 2U>
      &backgroundParamValues, const ::coder::array<double, 2U>
      &scalefactorValues, const ::coder::array<double, 2U> &bulkInValues, const ::
      coder::array<double, 2U> &bulkOutValues, const ::coder::array<double, 2U>
      &resolutionParamValues, double dataPresent, const ::coder::array<double,
      2U> &data, const double dataLimits[2], const double simulationLimits[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double numSimulationPoints,
      double resampleMinAngle, double resampleNPoints, double resample, const
      char geometry_data[], const int geometry_size[2], double roughness,
      boolean_T calcSld, const ::coder::array<double, 2U> &contrastLayers, ::
      coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::array<
      double, 2U> &background, ::coder::array<double, 2U> &resolution, ::coder::
      array<double, 2U> &sldProfile, ::coder::array<double, 2U> &layers, ::coder::
      array<double, 2U> &resampledLayers, double &scalefactor, double &bulkIn,
      double &bulkOut, double &chi)
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
      b_coreLayersCalculation(contrastLayers, roughness, geometry_data,
        geometry_size, bulkIn, bulkOut, resample, calcSld, b_shiftedData,
        simulationXData, dataIndices, resolution, background,
        backgroundAction_data, backgroundAction_size, parallel_data,
        parallel_size, resampleMinAngle, resampleNPoints, reflectivity,
        simulation, shiftedData, sldProfile, layers, resampledLayers);

      //  Calculate chi squared
      chi = chiSquared(shiftedData, reflectivity, nParams);
      return 0.0;
    }

    void b_customLayers(const ProblemDefinition &problemStruct, const Controls
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
      ::coder::array<cell_wrap_9, 1U> contrastLayers;
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
      double numberOfContrasts;
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
      int i2;
      int i3;
      int loop_ub;
      int nParams;
      int ub_loop;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      numberOfContrasts = problemStruct.numberOfContrasts;
      nParams = problemStruct.params.size(1);
      useImaginary = problemStruct.useImaginary;
      calcSld = controls->calcSldDuringFit;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      processCustomFunction(problemStruct.contrastBulkIns,
                            problemStruct.contrastBulkOuts,
                            problemStruct.bulkIns, problemStruct.bulkOuts,
                            problemStruct.contrastCustomFiles,
                            problemStruct.numberOfContrasts,
                            problemStruct.customFiles, problemStruct.params,
                            problemStruct.useImaginary, contrastLayers,
                            subRoughs);
      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Multi cored over all contrasts
        resampledLayers.set_size(static_cast<int>
          (problemStruct.numberOfContrasts), 1);
        layers.set_size(static_cast<int>(problemStruct.numberOfContrasts), 1);
        sldProfiles.set_size(static_cast<int>(problemStruct.numberOfContrasts),
                             1);
        resolutions.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        backgrounds.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        shiftedData.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        simulation.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        reflectivity.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        qzshifts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        scalefactors.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkIns.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkOuts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        chis.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,d,d1,d2,d3,iv5,iv6,dv2,dv3,iv7,iv8,iv9,c_loop_ub,i2,i3,d_loop_ub)

        for (int b_i = 0; b_i <= ub_loop; b_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[b_i].f1[0];
          dv2[1] = problemStruct.dataLimits[b_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[b_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[b_i].f1[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[b_i].f1)->data(), iv5,
                                problemStruct.contrastScalefactors[b_i],
                                problemStruct.contrastBulkIns[b_i],
                                problemStruct.contrastBulkOuts[b_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->data(),
                                iv6, problemStruct.backgroundParams,
                                problemStruct.scalefactors,
                                problemStruct.bulkIns, problemStruct.bulkOuts,
                                problemStruct.resolutionParams,
                                problemStruct.dataPresent[b_i],
                                problemStruct.data[b_i].f1, dv2, dv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundTypes[b_i].f1)->data(), iv7,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[b_i].f1)->data(),
                                iv9, problemStruct.customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, numSimulationPoints,
                                resampleMinAngle, resampleNPoints,
                                problemStruct.resample[b_i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[b_i],
                                calcSld, contrastLayers[b_i].f1,
                                reflectivity[b_i].f1, simulation[b_i].f1,
                                shiftedData[b_i].f1, backgrounds[b_i].f1,
                                resolutions[b_i].f1, r2, r1, r, d3, d2, d1, d);
          c_loop_ub = r2.size(0);
          sldProfiles[b_i].f1.set_size(r2.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r2[i3
                + r2.size(0) * i2];
            }
          }

          c_loop_ub = r1.size(1);
          layers[b_i].f1.set_size(r1.size(0), r1.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r1.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layers[b_i].f1[i3 + layers[b_i].f1.size(0) * i2] = r1[i3 + r1.size
                (0) * i2];
            }
          }

          c_loop_ub = r.size(0);
          resampledLayers[b_i].f1.set_size(r.size(0), 4);
          for (i2 = 0; i2 < 4; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) * i2]
                = r[i3 + r.size(0) * i2];
            }
          }

          qzshifts[b_i] = 0.0;
          scalefactors[b_i] = d3;
          bulkIns[b_i] = d2;
          bulkOuts[b_i] = d1;
          chis[b_i] = d;
        }
      } else {
        //  Single cored over all contrasts
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts);
        resampledLayers.set_size(ub_loop, 1);
        layers.set_size(ub_loop, 1);
        sldProfiles.set_size(ub_loop, 1);
        resolutions.set_size(ub_loop);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int i{0}; i < ub_loop; i++) {
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
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[i].f1[0];
          b_dv[1] = problemStruct.dataLimits[i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct.contrastScalefactors[i],
                                problemStruct.contrastBulkIns[i],
                                problemStruct.contrastBulkOuts[i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[i].f1)->data(), iv1,
                                problemStruct.backgroundParams,
                                problemStruct.scalefactors,
                                problemStruct.bulkIns, problemStruct.bulkOuts,
                                problemStruct.resolutionParams,
                                problemStruct.dataPresent[i],
                                problemStruct.data[i].f1, b_dv, b_dv1, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundTypes[i].f1)->data(), iv2,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[i].f1)->data(), iv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastResolutionTypes[i].f1)->data(), iv4,
                                problemStruct.customFiles, static_cast<double>
                                (problemStruct.params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                numSimulationPoints, resampleMinAngle,
                                resampleNPoints, problemStruct.resample[i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[i],
                                calcSld, contrastLayers[i].f1, reflectivity[i].
                                f1, simulation[i].f1, shiftedData[i].f1,
                                backgrounds[i].f1, resolutions[i].f1, r4, r5, r6,
                                d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r4.size(0);
          sldProfiles[i].f1.set_size(r4.size(0), 2);
          for (int c_i{0}; c_i < 2; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layers[i].f1.set_size(r5.size(0), r5.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[i].f1[i1 + layers[i].f1.size(0) * c_i] = r5[i1 + r5.size(0)
                * c_i];
            }
          }

          loop_ub = r6.size(0);
          resampledLayers[i].f1.set_size(r6.size(0), 4);
          for (int c_i{0}; c_i < 4; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r6[i1 + r6.size(0) * c_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        ub_loop = static_cast<int>(numberOfContrasts);
        for (int i{0}; i < ub_loop; i++) {
          b_layers.set_size(layers[i].f1.size(0), layers[i].f1.size(1));
          loop_ub = layers[i].f1.size(1);
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = layers[i].f1.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_layers[i1 + b_layers.size(0) * c_i] = layers[i].f1[i1 + layers[i]
                .f1.size(0) * c_i];
            }
          }

          layers[i].f1.set_size(b_layers.size(0), b_layers.size(1));
          loop_ub = b_layers.size(1);
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = b_layers.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[i].f1[i1 + layers[i].f1.size(0) * c_i] = b_layers[i1 +
                b_layers.size(0) * c_i];
            }
          }

          coder::internal::nullAssignment(layers[i].f1);
          coder::internal::nullAssignment(resampledLayers[i].f1, r3);
          resampledLayers[i].f1.set_size(r3.size(0), 3);
          loop_ub = r3.size(0);
          for (int c_i{0}; c_i < 3; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r3[i1 + r3.size(0) * c_i];
            }
          }
        }
      }
    }

    void customLayers(const ProblemDefinition &problemStruct, const Controls
                      *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                      array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                      &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                      array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                      &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation,
                      ::coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::
                      array<cell_wrap_8, 1U> &backgrounds, ::coder::array<
                      cell_wrap_7, 1U> &resolutions, ::coder::array<cell_wrap_9,
                      2U> &sldProfiles, ::coder::array<cell_wrap_9, 2U> &layers,
                      ::coder::array<cell_wrap_9, 2U> &resampledLayers, ::coder::
                      array<double, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_9, 1U> contrastLayers;
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
      double numberOfContrasts;
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
      int i2;
      int i3;
      int loop_ub;
      int nParams;
      int ub_loop;
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      numberOfContrasts = problemStruct.numberOfContrasts;
      nParams = problemStruct.params.size(1);
      useImaginary = problemStruct.useImaginary;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      processCustomFunction(problemStruct.contrastBulkIns,
                            problemStruct.contrastBulkOuts,
                            problemStruct.bulkIns, problemStruct.bulkOuts,
                            problemStruct.contrastCustomFiles,
                            problemStruct.numberOfContrasts,
                            problemStruct.customFiles, problemStruct.params,
                            problemStruct.useImaginary, contrastLayers,
                            subRoughs);
      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Multi cored over all contrasts
        resampledLayers.set_size(static_cast<int>
          (problemStruct.numberOfContrasts), 1);
        layers.set_size(static_cast<int>(problemStruct.numberOfContrasts), 1);
        sldProfiles.set_size(static_cast<int>(problemStruct.numberOfContrasts),
                             1);
        resolutions.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        backgrounds.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        shiftedData.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        simulation.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        reflectivity.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        qzshifts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        scalefactors.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkIns.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkOuts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        chis.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,d,d1,d2,d3,iv5,iv6,dv2,dv3,iv7,iv8,iv9,c_loop_ub,i2,i3,d_loop_ub)

        for (int b_i = 0; b_i <= ub_loop; b_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[b_i].f1[0];
          dv2[1] = problemStruct.dataLimits[b_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[b_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[b_i].f1[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[b_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[b_i].f1)->data(), iv5,
                                problemStruct.contrastScalefactors[b_i],
                                problemStruct.contrastBulkIns[b_i],
                                problemStruct.contrastBulkOuts[b_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->data(),
                                iv6, problemStruct.backgroundParams,
                                problemStruct.scalefactors,
                                problemStruct.bulkIns, problemStruct.bulkOuts,
                                problemStruct.resolutionParams,
                                problemStruct.dataPresent[b_i],
                                problemStruct.data[b_i].f1, dv2, dv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundTypes[b_i].f1)->data(), iv7,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[b_i].f1)->data(),
                                iv9, problemStruct.customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, numSimulationPoints,
                                resampleMinAngle, resampleNPoints,
                                problemStruct.resample[b_i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[b_i],
                                true, contrastLayers[b_i].f1, reflectivity[b_i].
                                f1, simulation[b_i].f1, shiftedData[b_i].f1,
                                backgrounds[b_i].f1, resolutions[b_i].f1, r2, r1,
                                r, d3, d2, d1, d);
          c_loop_ub = r2.size(0);
          sldProfiles[b_i].f1.set_size(r2.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r2[i3
                + r2.size(0) * i2];
            }
          }

          c_loop_ub = r1.size(1);
          layers[b_i].f1.set_size(r1.size(0), r1.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r1.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layers[b_i].f1[i3 + layers[b_i].f1.size(0) * i2] = r1[i3 + r1.size
                (0) * i2];
            }
          }

          c_loop_ub = r.size(0);
          resampledLayers[b_i].f1.set_size(r.size(0), 4);
          for (i2 = 0; i2 < 4; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) * i2]
                = r[i3 + r.size(0) * i2];
            }
          }

          qzshifts[b_i] = 0.0;
          scalefactors[b_i] = d3;
          bulkIns[b_i] = d2;
          bulkOuts[b_i] = d1;
          chis[b_i] = d;
        }
      } else {
        //  Single cored over all contrasts
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts);
        resampledLayers.set_size(ub_loop, 1);
        layers.set_size(ub_loop, 1);
        sldProfiles.set_size(ub_loop, 1);
        resolutions.set_size(ub_loop);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int i{0}; i < ub_loop; i++) {
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
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[i].f1[0];
          b_dv[1] = problemStruct.dataLimits[i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct.contrastScalefactors[i],
                                problemStruct.contrastBulkIns[i],
                                problemStruct.contrastBulkOuts[i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[i].f1)->data(), iv1,
                                problemStruct.backgroundParams,
                                problemStruct.scalefactors,
                                problemStruct.bulkIns, problemStruct.bulkOuts,
                                problemStruct.resolutionParams,
                                problemStruct.dataPresent[i],
                                problemStruct.data[i].f1, b_dv, b_dv1, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundTypes[i].f1)->data(), iv2,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[i].f1)->data(), iv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastResolutionTypes[i].f1)->data(), iv4,
                                problemStruct.customFiles, static_cast<double>
                                (problemStruct.params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                numSimulationPoints, resampleMinAngle,
                                resampleNPoints, problemStruct.resample[i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[i], true,
                                contrastLayers[i].f1, reflectivity[i].f1,
                                simulation[i].f1, shiftedData[i].f1,
                                backgrounds[i].f1, resolutions[i].f1, r4, r5, r6,
                                d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r4.size(0);
          sldProfiles[i].f1.set_size(r4.size(0), 2);
          for (int c_i{0}; c_i < 2; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layers[i].f1.set_size(r5.size(0), r5.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[i].f1[i1 + layers[i].f1.size(0) * c_i] = r5[i1 + r5.size(0)
                * c_i];
            }
          }

          loop_ub = r6.size(0);
          resampledLayers[i].f1.set_size(r6.size(0), 4);
          for (int c_i{0}; c_i < 4; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r6[i1 + r6.size(0) * c_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        ub_loop = static_cast<int>(numberOfContrasts);
        for (int i{0}; i < ub_loop; i++) {
          b_layers.set_size(layers[i].f1.size(0), layers[i].f1.size(1));
          loop_ub = layers[i].f1.size(1);
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = layers[i].f1.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_layers[i1 + b_layers.size(0) * c_i] = layers[i].f1[i1 + layers[i]
                .f1.size(0) * c_i];
            }
          }

          layers[i].f1.set_size(b_layers.size(0), b_layers.size(1));
          loop_ub = b_layers.size(1);
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = b_layers.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layers[i].f1[i1 + layers[i].f1.size(0) * c_i] = b_layers[i1 +
                b_layers.size(0) * c_i];
            }
          }

          coder::internal::nullAssignment(layers[i].f1);
          coder::internal::nullAssignment(resampledLayers[i].f1, r3);
          resampledLayers[i].f1.set_size(r3.size(0), 3);
          loop_ub = r3.size(0);
          for (int c_i{0}; c_i < 3; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r3[i1 + r3.size(0) * c_i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (customLayers.cpp)
