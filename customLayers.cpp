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
#include "constructBackground.h"
#include "constructResolution.h"
#include "coreLayersCalculation.h"
#include "extractProblemParams.h"
#include "makeSimulationRange.h"
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
      &backgroundParams, const ::coder::array<double, 2U> &scalefactors, const ::
      coder::array<double, 2U> &bulkIns, const ::coder::array<double, 2U>
      &bulkOuts, const ::coder::array<double, 2U> &resolutionParams, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double resample, const
      char geometry_data[], const int geometry_size[2], double roughness,
      boolean_T calcSld, const ::coder::array<double, 2U> &layer, ::coder::array<
      double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation, ::coder::
      array<double, 2U> &shiftedData, ::coder::array<double, 2U> &background, ::
      coder::array<double, 2U> &resolution, ::coder::array<double, 2U> &layerSld,
      ::coder::array<double, 2U> &sldProfile, ::coder::array<double, 2U>
      &resampledLayer, double &scalefactorValue, double &bulkInValue, double
      &bulkOutValue, double &chi);
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
      &backgroundParams, const ::coder::array<double, 2U> &scalefactors, const ::
      coder::array<double, 2U> &bulkIns, const ::coder::array<double, 2U>
      &bulkOuts, const ::coder::array<double, 2U> &resolutionParams, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double resample, const
      char geometry_data[], const int geometry_size[2], double roughness,
      boolean_T calcSld, const ::coder::array<double, 2U> &layer, ::coder::array<
      double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation, ::coder::
      array<double, 2U> &shiftedData, ::coder::array<double, 2U> &background, ::
      coder::array<double, 2U> &resolution, ::coder::array<double, 2U> &layerSld,
      ::coder::array<double, 2U> &sldProfile, ::coder::array<double, 2U>
      &resampledLayer, double &scalefactorValue, double &bulkInValue, double
      &bulkOutValue, double &chi)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 1U> simulationXData;
      double dataIndices[2];

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactors,
               bulkIns, bulkOuts, scalefactorValue, bulkInValue, bulkOutValue);

      //  Apply scale factors and q shifts to the data
      b_data.set_size(data.size(0), 6);
      for (int i{0}; i < 6; i++) {
        int loop_ub;
        loop_ub = data.size(0) - 1;
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(scalefactorValue, dataPresent, b_data, dataLimits, simLimits,
                b_shiftedData);
      makeSimulationRange(b_shiftedData, simLimits, simulationXData, dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParams, simulationXData,
                          dataIndices, resolution);

      //  Call the core layers calculation
      chi = coreLayersCalculation(layer, roughness, geometry_data, geometry_size,
        bulkInValue, bulkOutValue, resample, calcSld, b_shiftedData,
        simulationXData, dataIndices, repeatLayers, resolution, background,
        backgroundAction_data, backgroundAction_size, nParams, parallel_data,
        parallel_size, resampleMinAngle, resampleNPoints, useImaginary,
        sldProfile, reflectivity, simulation, shiftedData, layerSld,
        resampledLayer);
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
                        &resolutions, ::coder::array<cell_wrap_9, 2U> &layerSlds,
                        ::coder::array<cell_wrap_9, 2U> &sldProfiles, ::coder::
                        array<cell_wrap_9, 2U> &resampledLayers, ::coder::array<
                        double, 1U> &subRoughs)
    {
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      double dv3[2];
      double dv4[2];
      double dv5[2];
      double d;
      double d1;
      double d2;
      double d3;
      double resampleMinAngle;
      double resampleNPoints;
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int c_loop_ub;
      int d_loop_ub;
      int i2;
      int i3;
      int nParams;
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      useImaginary = problemStruct.useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      customLayers::processCustomFunction(problemStruct.contrastBulkIns,
        problemStruct.contrastBulkOuts, problemStruct.bulkIns,
        problemStruct.bulkOuts, problemStruct.contrastCustomFiles,
        problemStruct.numberOfContrasts, problemStruct.customFiles,
        problemStruct.params, problemStruct.useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::n_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int ub_loop;

        //  Multi cored over all contrasts
        qzshifts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        sldProfiles.set_size(static_cast<int>(problemStruct.numberOfContrasts),
                             1);
        layerSlds.set_size(static_cast<int>(problemStruct.numberOfContrasts), 1);
        resolutions.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        backgrounds.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        shiftedData.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        simulation.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        reflectivity.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        scalefactors.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkIns.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkOuts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        chis.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r3,d,d1,d2,d3,iv5,iv6,dv3,dv4,dv5,iv7,iv8,iv9,c_loop_ub,i2,i3,d_loop_ub)

        for (int b_i = 0; b_i <= ub_loop; b_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          dv3[0] = problemStruct.dataLimits[b_i].f1[0];
          dv3[1] = problemStruct.dataLimits[b_i].f1[1];
          dv4[0] = problemStruct.simulationLimits[b_i].f1[0];
          dv4[1] = problemStruct.simulationLimits[b_i].f1[1];
          dv5[0] = problemStruct.repeatLayers[b_i].f1[0];
          dv5[1] = problemStruct.repeatLayers[b_i].f1[1];
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
                                problemStruct.data[b_i].f1, dv3, dv4, dv5, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
                                iv7, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[b_i].f1)->data(),
                                iv9, problemStruct.customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary,
                                problemStruct.resample[b_i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[b_i],
                                true, resampledLayers[b_i].f1, reflectivity[b_i]
                                .f1, simulation[b_i].f1, r3, backgrounds[b_i].f1,
                                resolutions[b_i].f1, r2, r1, r, d3, d2, d1, d);
          c_loop_ub = r3.size(0);
          shiftedData[b_i].f1.set_size(r3.size(0), 3);
          for (i2 = 0; i2 < 3; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              shiftedData[b_i].f1[i3 + shiftedData[b_i].f1.size(0) * i2] = r3[i3
                + r3.size(0) * i2];
            }
          }

          c_loop_ub = r2.size(1);
          layerSlds[b_i].f1.set_size(r2.size(0), r2.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r2.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layerSlds[b_i].f1[i3 + layerSlds[b_i].f1.size(0) * i2] = r2[i3 +
                r2.size(0) * i2];
            }
          }

          c_loop_ub = r1.size(0);
          sldProfiles[b_i].f1.set_size(r1.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r1[i3
                + r1.size(0) * i2];
            }
          }

          c_loop_ub = r.size(1);
          resampledLayers[b_i].f1.set_size(r.size(0), r.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
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
        int ub_loop;

        //  Single cored over all contrasts
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts);
        qzshifts.set_size(ub_loop);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        resolutions.set_size(ub_loop);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int i{0}; i < ub_loop; i++) {
          double b_dv[2];
          double b_dv1[2];
          double dv2[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          int b_loop_ub;
          int loop_ub;
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
          dv2[0] = problemStruct.repeatLayers[i].f1[0];
          dv2[1] = problemStruct.repeatLayers[i].f1[1];
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
                                problemStruct.data[i].f1, b_dv, b_dv1, dv2, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[i].f1)->data(),
                                iv2, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[i].f1)->data(), iv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastResolutionTypes[i].f1)->data(), iv4,
                                problemStruct.customFiles, static_cast<double>
                                (problemStruct.params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct.useImaginary,
                                problemStruct.resample[i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[i], true,
                                resampledLayers[i].f1, reflectivity[i].f1,
                                simulation[i].f1, r4, backgrounds[i].f1,
                                resolutions[i].f1, r5, r6, r7, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r4.size(0);
          shiftedData[i].f1.set_size(r4.size(0), 3);
          for (int c_i{0}; c_i < 3; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layerSlds[i].f1.set_size(r5.size(0), r5.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(0);
          sldProfiles[i].f1.set_size(r6.size(0), 2);
          for (int c_i{0}; c_i < 2; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r6[i1 +
                r6.size(0) * c_i];
            }
          }

          loop_ub = r7.size(1);
          resampledLayers[i].f1.set_size(r7.size(0), r7.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r7.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r7[i1 + r7.size(0) * c_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }
    }

    void b_customLayers(const b_ProblemDefinition *problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U> &layerSlds,
                        ::coder::array<cell_wrap_9, 2U> &sldProfiles, ::coder::
                        array<cell_wrap_9, 2U> &resampledLayers, ::coder::array<
                        double, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_47, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_9, 2U> a__4;
      ::coder::array<cell_wrap_9, 2U> a__5;
      ::coder::array<cell_wrap_9, 2U> a__6;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<double, 2U> a__1;
      ::coder::array<double, 2U> a__2;
      ::coder::array<double, 2U> backgroundParamArray;
      ::coder::array<double, 2U> bulkInArray;
      ::coder::array<double, 2U> bulkOutArray;
      ::coder::array<double, 2U> cCustFiles;
      ::coder::array<double, 2U> contrastBulkInIndices;
      ::coder::array<double, 2U> contrastBulkOutIndices;
      ::coder::array<double, 2U> contrastQzshiftIndices;
      ::coder::array<double, 2U> contrastScalefactorIndices;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> params;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> resample;
      ::coder::array<double, 2U> resolutionParamArray;
      ::coder::array<double, 2U> scalefactorArray;
      double dv3[2];
      double dv4[2];
      double dv5[2];
      double a__3;
      double d;
      double d1;
      double d2;
      double d3;
      double nParams;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int geometry_size[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int c_loop_ub;
      int d_loop_ub;
      int i2;
      int i3;
      char geometry_data[10000];
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      numberOfContrasts = extractProblemParams(problemStruct, geometry_data,
        geometry_size, contrastBackgroundIndices, contrastQzshiftIndices,
        contrastScalefactorIndices, contrastBulkInIndices,
        contrastBulkOutIndices, contrastResolutionIndices, a__1,
        backgroundParamArray, scalefactorArray, bulkInArray, bulkOutArray,
        resolutionParamArray, a__2, dataPresent, params, resample,
        contrastBackgroundTypes, contrastBackgroundActions,
        contrastResolutionTypes, cCustFiles, repeatLayers, data, dataLimits,
        simLimits, a__4, a__5, customFiles, a__6, nParams, a__3, useImaginary);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      customLayers::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, customFiles, params, useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::n_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int ub_loop;

        //  Multi cored over all contrasts
        qzshifts.set_size(static_cast<int>(numberOfContrasts));
        sldProfiles.set_size(static_cast<int>(numberOfContrasts), 1);
        layerSlds.set_size(static_cast<int>(numberOfContrasts), 1);
        resolutions.set_size(static_cast<int>(numberOfContrasts));
        backgrounds.set_size(static_cast<int>(numberOfContrasts));
        shiftedData.set_size(static_cast<int>(numberOfContrasts));
        simulation.set_size(static_cast<int>(numberOfContrasts));
        reflectivity.set_size(static_cast<int>(numberOfContrasts));
        scalefactors.set_size(static_cast<int>(numberOfContrasts));
        bulkIns.set_size(static_cast<int>(numberOfContrasts));
        bulkOuts.set_size(static_cast<int>(numberOfContrasts));
        chis.set_size(static_cast<int>(numberOfContrasts));
        ub_loop = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r3,d,d1,d2,d3,iv5,iv6,dv3,dv4,dv5,iv7,iv8,iv9,c_loop_ub,i2,i3,d_loop_ub)

        for (int b_i = 0; b_i <= ub_loop; b_i++) {
          iv5[0] = (*(int (*)[2])contrastBackgroundIndices[b_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundIndices[b_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
          dv3[0] = dataLimits[b_i].f1[0];
          dv3[1] = dataLimits[b_i].f1[1];
          dv4[0] = simLimits[b_i].f1[0];
          dv4[1] = simLimits[b_i].f1[1];
          dv5[0] = repeatLayers[b_i].f1[0];
          dv5[1] = repeatLayers[b_i].f1[1];
          iv7[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv7[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv8[0] = (*(int (*)[2])contrastBackgroundActions[b_i].f1.size())[0];
          iv8[1] = (*(int (*)[2])contrastBackgroundActions[b_i].f1.size())[1];
          iv9[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
          iv9[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
          b_contrastCalculation((const double *)contrastBackgroundIndices[b_i].
                                f1.data(), iv5, contrastScalefactorIndices[b_i],
                                contrastBulkInIndices[b_i],
                                contrastBulkOutIndices[b_i], (const double *)
                                contrastResolutionIndices[b_i].f1.data(), iv6,
                                backgroundParamArray, scalefactorArray,
                                bulkInArray, bulkOutArray, resolutionParamArray,
                                dataPresent[b_i], data[b_i].f1, dv3, dv4, dv5, (
            const char *)contrastBackgroundTypes[b_i].f1.data(), iv7, (const
            char *)contrastBackgroundActions[b_i].f1.data(), iv8, (const char *)
                                contrastResolutionTypes[b_i].f1.data(), iv9,
                                customFiles, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[b_i],
                                geometry_data, geometry_size, subRoughs[b_i],
                                true, resampledLayers[b_i].f1, reflectivity[b_i]
                                .f1, simulation[b_i].f1, r3, backgrounds[b_i].f1,
                                resolutions[b_i].f1, r2, r1, r, d3, d2, d1, d);
          c_loop_ub = r3.size(0);
          shiftedData[b_i].f1.set_size(r3.size(0), 3);
          for (i2 = 0; i2 < 3; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              shiftedData[b_i].f1[i3 + shiftedData[b_i].f1.size(0) * i2] = r3[i3
                + r3.size(0) * i2];
            }
          }

          c_loop_ub = r2.size(1);
          layerSlds[b_i].f1.set_size(r2.size(0), r2.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r2.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layerSlds[b_i].f1[i3 + layerSlds[b_i].f1.size(0) * i2] = r2[i3 +
                r2.size(0) * i2];
            }
          }

          c_loop_ub = r1.size(0);
          sldProfiles[b_i].f1.set_size(r1.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r1[i3
                + r1.size(0) * i2];
            }
          }

          c_loop_ub = r.size(1);
          resampledLayers[b_i].f1.set_size(r.size(0), r.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
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
        int ub_loop;

        //  Single cored over all contrasts
        ub_loop = static_cast<int>(numberOfContrasts);
        qzshifts.set_size(ub_loop);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        resolutions.set_size(ub_loop);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int i{0}; i < ub_loop; i++) {
          double b_dv[2];
          double b_dv1[2];
          double dv2[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          int b_loop_ub;
          int loop_ub;
          iv[0] = (*(int (*)[2])contrastBackgroundIndices[i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastBackgroundIndices[i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastResolutionIndices[i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastResolutionIndices[i].f1.size())[1];
          b_dv[0] = dataLimits[i].f1[0];
          b_dv[1] = dataLimits[i].f1[1];
          b_dv1[0] = simLimits[i].f1[0];
          b_dv1[1] = simLimits[i].f1[1];
          dv2[0] = repeatLayers[i].f1[0];
          dv2[1] = repeatLayers[i].f1[1];
          iv2[0] = (*(int (*)[2])contrastBackgroundTypes[i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastBackgroundTypes[i].f1.size())[1];
          iv3[0] = (*(int (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundActions[i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionTypes[i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionTypes[i].f1.size())[1];
          b_contrastCalculation((const double *)contrastBackgroundIndices[i].
                                f1.data(), iv, contrastScalefactorIndices[i],
                                contrastBulkInIndices[i],
                                contrastBulkOutIndices[i], (const double *)
                                contrastResolutionIndices[i].f1.data(), iv1,
                                backgroundParamArray, scalefactorArray,
                                bulkInArray, bulkOutArray, resolutionParamArray,
                                dataPresent[i], data[i].f1, b_dv, b_dv1, dv2, (
            const char *)contrastBackgroundTypes[i].f1.data(), iv2, (const char *)
                                contrastBackgroundActions[i].f1.data(), iv3, (
            const char *)contrastResolutionTypes[i].f1.data(), iv4, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[i],
                                geometry_data, geometry_size, subRoughs[i], true,
                                resampledLayers[i].f1, reflectivity[i].f1,
                                simulation[i].f1, r4, backgrounds[i].f1,
                                resolutions[i].f1, r5, r6, r7, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r4.size(0);
          shiftedData[i].f1.set_size(r4.size(0), 3);
          for (int c_i{0}; c_i < 3; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layerSlds[i].f1.set_size(r5.size(0), r5.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(0);
          sldProfiles[i].f1.set_size(r6.size(0), 2);
          for (int c_i{0}; c_i < 2; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r6[i1 +
                r6.size(0) * c_i];
            }
          }

          loop_ub = r7.size(1);
          resampledLayers[i].f1.set_size(r7.size(0), r7.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r7.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r7[i1 + r7.size(0) * c_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }
    }

    void c_customLayers(const ProblemDefinition &problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U> &layerSlds,
                        ::coder::array<cell_wrap_9, 2U> &sldProfiles, ::coder::
                        array<cell_wrap_9, 2U> &resampledLayers, ::coder::array<
                        double, 1U> &subRoughs)
    {
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      double dv3[2];
      double dv4[2];
      double dv5[2];
      double d;
      double d1;
      double d2;
      double d3;
      double resampleMinAngle;
      double resampleNPoints;
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int c_loop_ub;
      int d_loop_ub;
      int i2;
      int i3;
      int nParams;
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
      nParams = problemStruct.params.size(1);
      useImaginary = problemStruct.useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      customLayers::processCustomFunction(problemStruct.contrastBulkIns,
        problemStruct.contrastBulkOuts, problemStruct.bulkIns,
        problemStruct.bulkOuts, problemStruct.contrastCustomFiles,
        problemStruct.numberOfContrasts, problemStruct.customFiles,
        problemStruct.params, problemStruct.useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::n_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int ub_loop;

        //  Multi cored over all contrasts
        qzshifts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        sldProfiles.set_size(static_cast<int>(problemStruct.numberOfContrasts),
                             1);
        layerSlds.set_size(static_cast<int>(problemStruct.numberOfContrasts), 1);
        resolutions.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        backgrounds.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        shiftedData.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        simulation.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        reflectivity.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        scalefactors.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkIns.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        bulkOuts.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        chis.set_size(static_cast<int>(problemStruct.numberOfContrasts));
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r3,d,d1,d2,d3,iv5,iv6,dv3,dv4,dv5,iv7,iv8,iv9,c_loop_ub,i2,i3,d_loop_ub)

        for (int b_i = 0; b_i <= ub_loop; b_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          dv3[0] = problemStruct.dataLimits[b_i].f1[0];
          dv3[1] = problemStruct.dataLimits[b_i].f1[1];
          dv4[0] = problemStruct.simulationLimits[b_i].f1[0];
          dv4[1] = problemStruct.simulationLimits[b_i].f1[1];
          dv5[0] = problemStruct.repeatLayers[b_i].f1[0];
          dv5[1] = problemStruct.repeatLayers[b_i].f1[1];
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
                                problemStruct.data[b_i].f1, dv3, dv4, dv5, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
                                iv7, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[b_i].f1)->data(),
                                iv9, problemStruct.customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary,
                                problemStruct.resample[b_i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[b_i],
                                calcSld, resampledLayers[b_i].f1,
                                reflectivity[b_i].f1, simulation[b_i].f1, r3,
                                backgrounds[b_i].f1, resolutions[b_i].f1, r2, r1,
                                r, d3, d2, d1, d);
          c_loop_ub = r3.size(0);
          shiftedData[b_i].f1.set_size(r3.size(0), 3);
          for (i2 = 0; i2 < 3; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              shiftedData[b_i].f1[i3 + shiftedData[b_i].f1.size(0) * i2] = r3[i3
                + r3.size(0) * i2];
            }
          }

          c_loop_ub = r2.size(1);
          layerSlds[b_i].f1.set_size(r2.size(0), r2.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r2.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layerSlds[b_i].f1[i3 + layerSlds[b_i].f1.size(0) * i2] = r2[i3 +
                r2.size(0) * i2];
            }
          }

          c_loop_ub = r1.size(0);
          sldProfiles[b_i].f1.set_size(r1.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r1[i3
                + r1.size(0) * i2];
            }
          }

          c_loop_ub = r.size(1);
          resampledLayers[b_i].f1.set_size(r.size(0), r.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
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
        int ub_loop;

        //  Single cored over all contrasts
        ub_loop = static_cast<int>(problemStruct.numberOfContrasts);
        qzshifts.set_size(ub_loop);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        resolutions.set_size(ub_loop);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int i{0}; i < ub_loop; i++) {
          double b_dv[2];
          double b_dv1[2];
          double dv2[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          int b_loop_ub;
          int loop_ub;
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
          dv2[0] = problemStruct.repeatLayers[i].f1[0];
          dv2[1] = problemStruct.repeatLayers[i].f1[1];
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
                                problemStruct.data[i].f1, b_dv, b_dv1, dv2, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[i].f1)->data(),
                                iv2, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[i].f1)->data(), iv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastResolutionTypes[i].f1)->data(), iv4,
                                problemStruct.customFiles, static_cast<double>
                                (problemStruct.params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct.useImaginary,
                                problemStruct.resample[i],
                                problemStruct.geometry.data,
                                problemStruct.geometry.size, subRoughs[i],
                                calcSld, resampledLayers[i].f1, reflectivity[i].
                                f1, simulation[i].f1, r4, backgrounds[i].f1,
                                resolutions[i].f1, r5, r6, r7, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r4.size(0);
          shiftedData[i].f1.set_size(r4.size(0), 3);
          for (int c_i{0}; c_i < 3; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layerSlds[i].f1.set_size(r5.size(0), r5.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(0);
          sldProfiles[i].f1.set_size(r6.size(0), 2);
          for (int c_i{0}; c_i < 2; c_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r6[i1 +
                r6.size(0) * c_i];
            }
          }

          loop_ub = r7.size(1);
          resampledLayers[i].f1.set_size(r7.size(0), r7.size(1));
          for (int c_i{0}; c_i < loop_ub; c_i++) {
            b_loop_ub = r7.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r7[i1 + r7.size(0) * c_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }
    }
  }
}

// End of code generation (customLayers.cpp)
