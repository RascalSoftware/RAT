//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customXY.cpp
//
// Code generation for function 'customXY'
//

// Include files
#include "customXY.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "extractProblemParams.h"
#include "makeSimulationRange.h"
#include "processCustomFunction1.h"
#include "resampleLayers.h"
#include "resampleLayersReIm.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    static void c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double qzshiftIndex, double
      scalefactorIndex, double bulkInIndex, double bulkOutIndex, const double
      resolutionParamIndex_data[], const int resolutionParamIndex_size[2], const
      ::coder::array<double, 2U> &backgroundParams, const ::coder::array<double,
      2U> &qzshifts, const ::coder::array<double, 2U> &scalefactors, const ::
      coder::array<double, 2U> &bulkIns, const ::coder::array<double, 2U>
      &bulkOuts, const ::coder::array<double, 2U> &resolutionParams, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double roughness, const ::
      coder::array<double, 2U> &sldProfile, double *qzshiftValue, double
      *scalefactorValue, double *bulkInValue, double *bulkOutValue, double *chi,
      ::coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::array<
      double, 2U> &background, ::coder::array<double, 2U> &resolution, ::coder::
      array<double, 2U> &layerSld, ::coder::array<double, 2U> &resampledLayer);
  }
}

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    static void c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double qzshiftIndex, double
      scalefactorIndex, double bulkInIndex, double bulkOutIndex, const double
      resolutionParamIndex_data[], const int resolutionParamIndex_size[2], const
      ::coder::array<double, 2U> &backgroundParams, const ::coder::array<double,
      2U> &qzshifts, const ::coder::array<double, 2U> &scalefactors, const ::
      coder::array<double, 2U> &bulkIns, const ::coder::array<double, 2U>
      &bulkOuts, const ::coder::array<double, 2U> &resolutionParams, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double roughness, const ::
      coder::array<double, 2U> &sldProfile, double *qzshiftValue, double
      *scalefactorValue, double *bulkInValue, double *bulkOutValue, double *chi,
      ::coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::array<
      double, 2U> &background, ::coder::array<double, 2U> &resolution, ::coder::
      array<double, 2U> &layerSld, ::coder::array<double, 2U> &resampledLayer)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_layerSld;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> b_sldProfile;
      ::coder::array<double, 2U> c_sldProfile;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 1U> simulationXData;
      double dataIndices[2];
      int b_loop_ub;
      int i;
      int i1;
      int loop_ub;

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               qzshifts, scalefactors, bulkIns, bulkOuts, qzshiftValue,
               scalefactorValue, bulkInValue, bulkOutValue);

      //  Resample the layers
      if (!useImaginary) {
        b_resampleLayers(sldProfile, resampleMinAngle, resampleNPoints, r);
        layerSld.set_size(r.size(0), 3);
        loop_ub = r.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            layerSld[i1 + layerSld.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }
      } else {
        loop_ub = sldProfile.size(0);
        b_sldProfile.set_size(loop_ub, 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_sldProfile[i1 + b_sldProfile.size(0) * i] = sldProfile[i1 +
              sldProfile.size(0) * i];
          }
        }

        loop_ub = sldProfile.size(0);
        b_loop_ub = sldProfile.size(0);
        c_sldProfile.set_size(loop_ub, 2);
        for (i = 0; i < loop_ub; i++) {
          c_sldProfile[i] = sldProfile[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          c_sldProfile[i + c_sldProfile.size(0)] = sldProfile[i +
            sldProfile.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile, c_sldProfile, resampleMinAngle,
                           resampleNPoints, r);
        layerSld.set_size(r.size(0), 4);
        loop_ub = r.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            layerSld[i1 + layerSld.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }
      }

      resampledLayer.set_size(layerSld.size(0), layerSld.size(1));
      loop_ub = layerSld.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = layerSld.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          resampledLayer[i1 + resampledLayer.size(0) * i] = layerSld[i1 +
            layerSld.size(0) * i];
        }
      }

      b_data.set_size(data.size(0), 6);
      loop_ub = data.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      makeSimulationRange(b_shiftedData, simLimits, simulationXData, dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParams, simulationXData,
                          dataIndices, resolution);
      b_layerSld.set_size(layerSld.size(0), layerSld.size(1));
      loop_ub = layerSld.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_loop_ub = layerSld.size(0) - 1;
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          b_layerSld[i1 + b_layerSld.size(0) * i] = layerSld[i1 + layerSld.size
            (0) * i];
        }
      }

      callReflectivity(*bulkInValue, *bulkOutValue, simulationXData, dataIndices,
                       repeatLayers, b_layerSld, roughness, resolution,
                       parallel_data, parallel_size, useImaginary, reflectivity,
                       simulation);
      applyBackgroundCorrection(reflectivity, simulation, b_shiftedData,
        background, backgroundAction_data, backgroundAction_size, shiftedData);
      if (dataPresent != 0.0) {
        *chi = chiSquared(shiftedData, reflectivity, nParams);
      } else {
        *chi = 0.0;
      }
    }

    void b_customXY(const ProblemDefinition *problemStruct, const Controls
                    *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                    array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                    &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                    array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                    &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                    coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                    cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7,
                    1U> &resolutions, ::coder::array<cell_wrap_9, 2U> &layerSlds,
                    ::coder::array<cell_wrap_9, 2U> &sldProfiles, ::coder::array<
                    cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U>
                    &subRoughs)
    {
      ::coder::array<cell_wrap_33, 1U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> r8;
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      double resampleMinAngle;
      double resampleNPoints;
      int iv[2];
      int iv1[2];
      int iv2[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_loop_ub;
      int c_i;
      int c_loop_ub;
      int d_loop_ub;
      int i;
      int i1;
      int i2;
      int i3;
      int i4;
      int loop_ub;
      int nParams;
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      //  Process the custom models
      customXY::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIns,
        problemStruct->bulkOuts, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemStruct->customFiles,
        problemStruct->params, r, subRoughs);
      sldProfiles.set_size(r.size(0), 1);
      for (i = 0; i < r.size(0); i++) {
        sldProfiles[i].f1.set_size(r[i].f1.size(0), r[i].f1.size(1));
        loop_ub = r[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = r[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            sldProfiles[i].f1[i2 + sldProfiles[i].f1.size(0) * i1] = r[i].f1[i2
              + r[i].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        qzshifts.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        resampledLayers.set_size(static_cast<int>
          (problemStruct->numberOfContrasts), 1);
        layerSlds.set_size(static_cast<int>(problemStruct->numberOfContrasts), 1);
        resolutions.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        backgrounds.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        shiftedData.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        simulation.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        reflectivity.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        scalefactors.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        bulkIns.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        bulkOuts.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        chis.set_size(static_cast<int>(problemStruct->numberOfContrasts));
        loop_ub = static_cast<int>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,r3,r4,r5,d,d1,d2,d3,d4,c_loop_ub,c_i,i3,iv5,d_loop_ub,i4,iv6,iv7,iv8,iv9)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          c_loop_ub = sldProfiles[c_i].f1.size(1);
          r5.set_size(sldProfiles[c_i].f1.size(0), sldProfiles[c_i].f1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = sldProfiles[c_i].f1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              r5[i4 + r5.size(0) * i3] = sldProfiles[c_i].f1[i4 +
                sldProfiles[c_i].f1.size(0) * i3];
            }
          }

          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[c_i].f1)->size())
            [0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[c_i].f1)->size())
            [1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[c_i].f1)->size())[1];
          c_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct->contrastBackgroundParams[c_i].f1)->data(), iv5,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct->contrastResolutionParams[c_i].f1)->data(),
                                iv6, problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[c_i],
                                problemStruct->data[c_i].f1,
                                problemStruct->dataLimits[c_i].f1,
                                problemStruct->simulationLimits[c_i].f1,
                                problemStruct->repeatLayers[c_i].f1, (const char
            *)((::coder::array<char, 2U> *)
               &problemStruct->contrastBackgroundTypes[c_i].f1)->data(), iv7, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct->contrastBackgroundActions[c_i].f1)
                                ->data(), iv8, (const char *)((::coder::array<
            char, 2U> *)&problemStruct->contrastResolutionTypes[c_i].f1)->data(),
                                iv9, problemStruct->customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                r5, &d4, &d3, &d2, &d1, &d, reflectivity[c_i].f1,
                                simulation[c_i].f1, r4, backgrounds[c_i].f1,
                                resolutions[c_i].f1, r3, r1);
          c_loop_ub = r4.size(0);
          shiftedData[c_i].f1.set_size(r4.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r4[i4
                + r4.size(0) * i3];
            }
          }

          c_loop_ub = r3.size(1);
          layerSlds[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r3.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layerSlds[c_i].f1[i4 + layerSlds[c_i].f1.size(0) * i3] = r3[i4 +
                r3.size(0) * i3];
            }
          }

          sldProfiles[c_i].f1.set_size(r5.size(0), r5.size(1));
          c_loop_ub = r5.size(1);
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r5.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r5[i4
                + r5.size(0) * i3];
            }
          }

          c_loop_ub = r1.size(1);
          resampledLayers[c_i].f1.set_size(r1.size(0), r1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              resampledLayers[c_i].f1[i4 + resampledLayers[c_i].f1.size(0) * i3]
                = r1[i4 + r1.size(0) * i3];
            }
          }

          qzshifts[c_i] = d4;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        i = static_cast<int>(problemStruct->numberOfContrasts);
        qzshifts.set_size(i);
        resampledLayers.set_size(i, 1);
        layerSlds.set_size(i, 1);
        resolutions.set_size(i);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        chis.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          loop_ub = sldProfiles[b_i].f1.size(1);
          r2.set_size(sldProfiles[b_i].f1.size(0), sldProfiles[b_i].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfiles[b_i].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r2[i2 + r2.size(0) * i1] = sldProfiles[b_i].f1[i2 +
                sldProfiles[b_i].f1.size(0) * i1];
            }
          }

          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct->contrastBackgroundParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct->contrastBackgroundParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[b_i].f1)->size())
            [0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[b_i].f1)->size())
            [1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[b_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[b_i].f1)->size())[1];
          c_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct->contrastBackgroundParams[b_i].f1)->data(), iv,
                                problemStruct->contrastQzshifts[b_i],
                                problemStruct->contrastScalefactors[b_i],
                                problemStruct->contrastBulkIns[b_i],
                                problemStruct->contrastBulkOuts[b_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct->contrastResolutionParams[b_i].f1)->data(),
                                iv1, problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[b_i],
                                problemStruct->data[b_i].f1,
                                problemStruct->dataLimits[b_i].f1,
                                problemStruct->simulationLimits[b_i].f1,
                                problemStruct->repeatLayers[b_i].f1, (const char
            *)((::coder::array<char, 2U> *)
               &problemStruct->contrastBackgroundTypes[b_i].f1)->data(), iv2, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct->contrastBackgroundActions[b_i].f1)
                                ->data(), iv3, (const char *)((::coder::array<
            char, 2U> *)&problemStruct->contrastResolutionTypes[b_i].f1)->data(),
                                iv4, problemStruct->customFiles, static_cast<
                                double>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary, subRoughs[b_i], r2,
                                &qzshifts[b_i], &scalefactors[b_i], &bulkIns[b_i],
                                &bulkOuts[b_i], &chis[b_i], reflectivity[b_i].f1,
                                simulation[b_i].f1, r6, backgrounds[b_i].f1,
                                resolutions[b_i].f1, r7, r8);
          loop_ub = r6.size(0);
          shiftedData[b_i].f1.set_size(r6.size(0), 3);
          for (i1 = 0; i1 < 3; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] = r6[i2
                + r6.size(0) * i1];
            }
          }

          loop_ub = r7.size(1);
          layerSlds[b_i].f1.set_size(r7.size(0), r7.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r7.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] = r7[i2 +
                r7.size(0) * i1];
            }
          }

          sldProfiles[b_i].f1.set_size(r2.size(0), r2.size(1));
          loop_ub = r2.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r2.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r2[i2
                + r2.size(0) * i1];
            }
          }

          loop_ub = r8.size(1);
          resampledLayers[b_i].f1.set_size(r8.size(0), r8.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r8.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r8[i2 + r8.size(0) * i1];
            }
          }
        }
      }
    }

    void b_customXY(const b_ProblemDefinition *problemStruct, const Controls
                    *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                    array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                    &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                    array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                    &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                    coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                    cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7,
                    1U> &resolutions, ::coder::array<cell_wrap_9, 2U> &layerSlds,
                    ::coder::array<cell_wrap_9, 2U> &sldProfiles, ::coder::array<
                    cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U>
                    &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_33, 1U> r;
      ::coder::array<cell_wrap_47, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_9, 2U> a__6;
      ::coder::array<cell_wrap_9, 2U> a__7;
      ::coder::array<cell_wrap_9, 2U> a__8;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<double, 2U> a__2;
      ::coder::array<double, 2U> a__3;
      ::coder::array<double, 2U> a__5;
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
      ::coder::array<double, 2U> qzshiftArray;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> r3;
      ::coder::array<double, 2U> r4;
      ::coder::array<double, 2U> r5;
      ::coder::array<double, 2U> r6;
      ::coder::array<double, 2U> r7;
      ::coder::array<double, 2U> r8;
      ::coder::array<double, 2U> resolutionParamArray;
      ::coder::array<double, 2U> scalefactorArray;
      double a__4;
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      double nParams;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int a__1_size[2];
      int iv[2];
      int iv1[2];
      int iv2[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int b_loop_ub;
      int c_i;
      int c_loop_ub;
      int d_loop_ub;
      int i;
      int i1;
      int i2;
      int i3;
      int i4;
      int loop_ub;
      char a__1_data[10000];
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, a__1_data,
                           a__1_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionIndices, a__2, backgroundParamArray,
                           qzshiftArray, scalefactorArray, bulkInArray,
                           bulkOutArray, resolutionParamArray, a__3, dataPresent,
                           &nParams, params, &a__4, a__5,
                           contrastBackgroundTypes, contrastBackgroundActions,
                           contrastResolutionTypes, cCustFiles, &useImaginary,
                           repeatLayers, data, dataLimits, simLimits, a__6, a__7,
                           customFiles, a__8);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      //  Process the custom models
      customXY::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, customFiles, params, r, subRoughs);
      sldProfiles.set_size(r.size(0), 1);
      for (i = 0; i < r.size(0); i++) {
        sldProfiles[i].f1.set_size(r[i].f1.size(0), r[i].f1.size(1));
        loop_ub = r[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = r[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            sldProfiles[i].f1[i2 + sldProfiles[i].f1.size(0) * i1] = r[i].f1[i2
              + r[i].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        qzshifts.set_size(static_cast<int>(numberOfContrasts));
        resampledLayers.set_size(static_cast<int>(numberOfContrasts), 1);
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
        loop_ub = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,r3,r4,r5,d,d1,d2,d3,d4,c_loop_ub,c_i,i3,iv4,d_loop_ub,i4,iv5,iv6,iv7,iv8)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          c_loop_ub = sldProfiles[c_i].f1.size(1);
          r5.set_size(sldProfiles[c_i].f1.size(0), sldProfiles[c_i].f1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = sldProfiles[c_i].f1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              r5[i4 + r5.size(0) * i3] = sldProfiles[c_i].f1[i4 +
                sldProfiles[c_i].f1.size(0) * i3];
            }
          }

          iv4[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv5[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv7[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv7[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          iv8[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv8[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          c_contrastCalculation((const double *)contrastBackgroundIndices[c_i].
                                f1.data(), iv4, contrastQzshiftIndices[c_i],
                                contrastScalefactorIndices[c_i],
                                contrastBulkInIndices[c_i],
                                contrastBulkOutIndices[c_i], (const double *)
                                contrastResolutionIndices[c_i].f1.data(), iv5,
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, dataPresent[c_i], data[c_i]
                                .f1, dataLimits[c_i].f1, simLimits[c_i].f1,
                                repeatLayers[c_i].f1, (const char *)
                                contrastBackgroundTypes[c_i].f1.data(), iv6, (
            const char *)contrastBackgroundActions[c_i].f1.data(), iv7, (const
            char *)contrastResolutionTypes[c_i].f1.data(), iv8, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                r5, &d4, &d3, &d2, &d1, &d, reflectivity[c_i].f1,
                                simulation[c_i].f1, r4, backgrounds[c_i].f1,
                                resolutions[c_i].f1, r3, r1);
          c_loop_ub = r4.size(0);
          shiftedData[c_i].f1.set_size(r4.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r4[i4
                + r4.size(0) * i3];
            }
          }

          c_loop_ub = r3.size(1);
          layerSlds[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r3.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layerSlds[c_i].f1[i4 + layerSlds[c_i].f1.size(0) * i3] = r3[i4 +
                r3.size(0) * i3];
            }
          }

          sldProfiles[c_i].f1.set_size(r5.size(0), r5.size(1));
          c_loop_ub = r5.size(1);
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r5.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r5[i4
                + r5.size(0) * i3];
            }
          }

          c_loop_ub = r1.size(1);
          resampledLayers[c_i].f1.set_size(r1.size(0), r1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              resampledLayers[c_i].f1[i4 + resampledLayers[c_i].f1.size(0) * i3]
                = r1[i4 + r1.size(0) * i3];
            }
          }

          qzshifts[c_i] = d4;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        i = static_cast<int>(numberOfContrasts);
        qzshifts.set_size(i);
        resampledLayers.set_size(i, 1);
        layerSlds.set_size(i, 1);
        resolutions.set_size(i);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        chis.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          loop_ub = sldProfiles[b_i].f1.size(1);
          r2.set_size(sldProfiles[b_i].f1.size(0), sldProfiles[b_i].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfiles[b_i].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r2[i2 + r2.size(0) * i1] = sldProfiles[b_i].f1[i2 +
                sldProfiles[b_i].f1.size(0) * i1];
            }
          }

          a__1_size[0] = (*(int (*)[2])contrastBackgroundIndices[b_i].f1.size())
            [0];
          a__1_size[1] = (*(int (*)[2])contrastBackgroundIndices[b_i].f1.size())
            [1];
          iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastBackgroundActions[b_i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastBackgroundActions[b_i].f1.size())[1];
          iv3[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
          c_contrastCalculation((const double *)contrastBackgroundIndices[b_i].
                                f1.data(), a__1_size, contrastQzshiftIndices[b_i],
                                contrastScalefactorIndices[b_i],
                                contrastBulkInIndices[b_i],
                                contrastBulkOutIndices[b_i], (const double *)
                                contrastResolutionIndices[b_i].f1.data(), iv,
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, dataPresent[b_i], data[b_i]
                                .f1, dataLimits[b_i].f1, simLimits[b_i].f1,
                                repeatLayers[b_i].f1, (const char *)
                                contrastBackgroundTypes[b_i].f1.data(), iv1, (
            const char *)contrastBackgroundActions[b_i].f1.data(), iv2, (const
            char *)contrastResolutionTypes[b_i].f1.data(), iv3, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[b_i],
                                r2, &qzshifts[b_i], &scalefactors[b_i],
                                &bulkIns[b_i], &bulkOuts[b_i], &chis[b_i],
                                reflectivity[b_i].f1, simulation[b_i].f1, r6,
                                backgrounds[b_i].f1, resolutions[b_i].f1, r7, r8);
          loop_ub = r6.size(0);
          shiftedData[b_i].f1.set_size(r6.size(0), 3);
          for (i1 = 0; i1 < 3; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] = r6[i2
                + r6.size(0) * i1];
            }
          }

          loop_ub = r7.size(1);
          layerSlds[b_i].f1.set_size(r7.size(0), r7.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r7.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] = r7[i2 +
                r7.size(0) * i1];
            }
          }

          sldProfiles[b_i].f1.set_size(r2.size(0), r2.size(1));
          loop_ub = r2.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r2.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r2[i2
                + r2.size(0) * i1];
            }
          }

          loop_ub = r8.size(1);
          resampledLayers[b_i].f1.set_size(r8.size(0), r8.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r8.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r8[i2 + r8.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (customXY.cpp)
