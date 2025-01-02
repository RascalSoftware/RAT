//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "coreLayersCalculation.h"
#include "extractProblemParams.h"
#include "processCustomFunction.h"
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
    static void b_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, const ::coder::array<real_T, 2U> &backgroundParams,
      const ::coder::array<real_T, 2U> &qzshifts, const ::coder::array<real_T,
      2U> &scalefactors, const ::coder::array<real_T, 2U> &bulkIns, const ::
      coder::array<real_T, 2U> &bulkOuts, const ::coder::array<real_T, 2U>
      &resolutionParams, real_T dataPresent, const ::coder::array<real_T, 2U>
      &data, const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_7, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T resample, const char_T geometry_data[],
      const int32_T geometry_size[2], real_T roughness, boolean_T calcSld, const
      ::coder::array<real_T, 2U> &layer, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background, ::coder::
      array<real_T, 2U> &layerSld, ::coder::array<real_T, 2U> &sldProfile, ::
      coder::array<real_T, 2U> &resampledLayer);
  }
}

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    static void b_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, const ::coder::array<real_T, 2U> &backgroundParams,
      const ::coder::array<real_T, 2U> &qzshifts, const ::coder::array<real_T,
      2U> &scalefactors, const ::coder::array<real_T, 2U> &bulkIns, const ::
      coder::array<real_T, 2U> &bulkOuts, const ::coder::array<real_T, 2U>
      &resolutionParams, real_T dataPresent, const ::coder::array<real_T, 2U>
      &data, const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_7, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T resample, const char_T geometry_data[],
      const int32_T geometry_size[2], real_T roughness, boolean_T calcSld, const
      ::coder::array<real_T, 2U> &layer, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background, ::coder::
      array<real_T, 2U> &layerSld, ::coder::array<real_T, 2U> &sldProfile, ::
      coder::array<real_T, 2U> &resampledLayer)
    {
      ::coder::array<real_T, 2U> b_data;
      ::coder::array<real_T, 2U> b_shiftedData;
      int32_T loop_ub;

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               resolutionParamIndex, qzshifts, scalefactors, bulkIns, bulkOuts,
               resolutionParams, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Apply scale factors and q shifts to the data
      b_data.set_size(data.size(0), 6);
      loop_ub = data.size(0) - 1;
      for (int32_T i{0}; i < 6; i++) {
        for (int32_T i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simLimits, background);

      //  Call the core layers calculation
      coreLayersCalculation(layer, roughness, geometry_data, geometry_size,
                            *bulkInValue, *bulkOutValue, resample, calcSld,
                            b_shiftedData, simLimits, repeatLayers,
                            *resolutionParamValue, background,
                            backgroundAction_data, backgroundAction_size,
                            nParams, parallel_data, parallel_size,
                            resampleMinAngle, resampleNPoints, useImaginary,
                            sldProfile, reflectivity, simulation, shiftedData,
                            layerSld, resampledLayer, chi);
    }

    void b_customLayers(const e_struct_T *problemStruct, const struct4_T
                        *controls, ::coder::array<real_T, 1U> &qzshifts, ::coder::
                        array<real_T, 1U> &scalefactors, ::coder::array<real_T,
                        1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                        coder::array<real_T, 1U> &resolutionParams, ::coder::
                        array<real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                        &reflectivity, ::coder::array<cell_wrap_8, 1U>
                        &simulation, ::coder::array<cell_wrap_9, 1U>
                        &shiftedData, ::coder::array<cell_wrap_9, 1U>
                        &backgrounds, ::coder::array<cell_wrap_10, 2U>
                        &layerSlds, ::coder::array<cell_wrap_10, 2U>
                        &sldProfiles, ::coder::array<cell_wrap_10, 2U>
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T iv4[2];
      int32_T iv5[2];
      int32_T b_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i2;
      int32_T i3;
      int32_T nParams;
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIns,
        problemStruct->bulkOuts, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemStruct->customFiles,
        problemStruct->params, problemStruct->useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T ub_loop;

        //  Multi cored over all contrasts
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        sldProfiles.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts), 1);
        layerSlds.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts),
                           1);
        backgrounds.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        shiftedData.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        simulation.set_size(static_cast<int32_T>
                            (problemStruct->numberOfContrasts));
        reflectivity.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        scalefactors.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        bulkIns.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        bulkOuts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        resolutionParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        chis.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r3,d,d1,d2,d3,d4,d5,iv3,b_i,iv4,iv5,c_loop_ub,i2,i3,d_loop_ub)

        for (b_i = 0; b_i <= ub_loop; b_i++) {
          iv3[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                     &problemStruct->contrastBackgroundParams[b_i].f1)->size())
            [0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                     &problemStruct->contrastBackgroundParams[b_i].f1)->size())
            [1];
          iv4[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv4[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv5[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv5[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          b_contrastCalculation((const real_T *)((::coder::array<real_T, 2U> *)
            &problemStruct->contrastBackgroundParams[b_i].f1)->data(), iv3,
                                problemStruct->contrastQzshifts[b_i],
                                problemStruct->contrastScalefactors[b_i],
                                problemStruct->contrastBulkIns[b_i],
                                problemStruct->contrastBulkOuts[b_i],
                                problemStruct->contrastResolutionParams[b_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[b_i],
                                problemStruct->data[b_i].f1,
                                problemStruct->dataLimits[b_i].f1,
                                problemStruct->simulationLimits[b_i].f1,
                                problemStruct->repeatLayers[b_i].f1, (const
            char_T *)((::coder::array<char_T, 2U> *)
                      &problemStruct->contrastBackgroundTypes[b_i].f1)->data(),
                                iv4, (const char_T *)((::coder::array<char_T, 2U>
            *)&problemStruct->contrastBackgroundActions[b_i].f1)->data(), iv5,
                                problemStruct->customFiles, static_cast<real_T>
                                (nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary,
                                problemStruct->resample[b_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[b_i],
                                true, resampledLayers[b_i].f1, &d5, &d4, &d3,
                                &d2, &d1, &d, reflectivity[b_i].f1,
                                simulation[b_i].f1, r3, backgrounds[b_i].f1, r2,
                                r1, r);
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

          qzshifts[b_i] = d5;
          scalefactors[b_i] = d4;
          bulkIns[b_i] = d3;
          bulkOuts[b_i] = d2;
          resolutionParams[b_i] = d1;
          chis[b_i] = d;
        }
      } else {
        int32_T ub_loop;

        //  Single cored over all contrasts
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts);
        qzshifts.set_size(ub_loop);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int32_T i{0}; i < ub_loop; i++) {
          int32_T b_loop_ub;
          int32_T c_i;
          int32_T i1;
          int32_T loop_ub;
          iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[1];
          iv2[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          b_contrastCalculation((const real_T *)((::coder::array<real_T, 2U> *)
            &problemStruct->contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i],
                                problemStruct->contrastResolutionParams[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[i],
                                problemStruct->data[i].f1,
                                problemStruct->dataLimits[i].f1,
                                problemStruct->simulationLimits[i].f1,
                                problemStruct->repeatLayers[i].f1, (const char_T
            *)((::coder::array<char_T, 2U> *)
               &problemStruct->contrastBackgroundTypes[i].f1)->data(), iv1, (
            const char_T *)((::coder::array<char_T, 2U> *)
                            &problemStruct->contrastBackgroundActions[i].f1)
                                ->data(), iv2, problemStruct->customFiles,
                                static_cast<real_T>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i], true,
                                resampledLayers[i].f1, &qzshifts[i],
                                &scalefactors[i], &bulkIns[i], &bulkOuts[i],
                                &resolutionParams[i], &chis[i], reflectivity[i].
                                f1, simulation[i].f1, r4, backgrounds[i].f1, r5,
                                r6, r7);
          loop_ub = r4.size(0);
          shiftedData[i].f1.set_size(r4.size(0), 3);
          for (c_i = 0; c_i < 3; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layerSlds[i].f1.set_size(r5.size(0), r5.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(0);
          sldProfiles[i].f1.set_size(r6.size(0), 2);
          for (c_i = 0; c_i < 2; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r6[i1 +
                r6.size(0) * c_i];
            }
          }

          loop_ub = r7.size(1);
          resampledLayers[i].f1.set_size(r7.size(0), r7.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r7.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r7[i1 + r7.size(0) * c_i];
            }
          }
        }
      }
    }

    void b_customLayers(const struct0_T *problemStruct, const struct4_T
                        *controls, ::coder::array<real_T, 1U> &qzshifts, ::coder::
                        array<real_T, 1U> &scalefactors, ::coder::array<real_T,
                        1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                        coder::array<real_T, 1U> &resolutionParams, ::coder::
                        array<real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                        &reflectivity, ::coder::array<cell_wrap_8, 1U>
                        &simulation, ::coder::array<cell_wrap_9, 1U>
                        &shiftedData, ::coder::array<cell_wrap_9, 1U>
                        &backgrounds, ::coder::array<cell_wrap_10, 2U>
                        &layerSlds, ::coder::array<cell_wrap_10, 2U>
                        &sldProfiles, ::coder::array<cell_wrap_10, 2U>
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> a__4;
      ::coder::array<cell_wrap_10, 2U> a__5;
      ::coder::array<cell_wrap_10, 2U> a__6;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_47, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_7, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_7, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_7, 2U> customFiles;
      ::coder::array<real_T, 2U> a__1;
      ::coder::array<real_T, 2U> a__2;
      ::coder::array<real_T, 2U> backgroundParamArray;
      ::coder::array<real_T, 2U> bulkInArray;
      ::coder::array<real_T, 2U> bulkOutArray;
      ::coder::array<real_T, 2U> cCustFiles;
      ::coder::array<real_T, 2U> contrastBulkInIndices;
      ::coder::array<real_T, 2U> contrastBulkOutIndices;
      ::coder::array<real_T, 2U> contrastQzshiftIndices;
      ::coder::array<real_T, 2U> contrastResolutionParamIndices;
      ::coder::array<real_T, 2U> contrastScalefactorIndices;
      ::coder::array<real_T, 2U> dataPresent;
      ::coder::array<real_T, 2U> params;
      ::coder::array<real_T, 2U> qzshiftArray;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      ::coder::array<real_T, 2U> resample;
      ::coder::array<real_T, 2U> resolutionParamArray;
      ::coder::array<real_T, 2U> scalefactorArray;
      real_T a__3;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T nParams;
      real_T numberOfContrasts;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T geometry_size[2];
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T iv4[2];
      int32_T iv5[2];
      int32_T b_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i2;
      int32_T i3;
      char_T geometry_data[10000];
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, geometry_data,
                           geometry_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionParamIndices, a__1,
                           backgroundParamArray, qzshiftArray, scalefactorArray,
                           bulkInArray, bulkOutArray, resolutionParamArray, a__2,
                           dataPresent, &nParams, params, &a__3, resample,
                           contrastBackgroundTypes, contrastBackgroundActions,
                           cCustFiles, &useImaginary, repeatLayers, data,
                           dataLimits, simLimits, a__4, a__5, customFiles, a__6);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      customLayers::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, customFiles, params, useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T ub_loop;

        //  Multi cored over all contrasts
        qzshifts.set_size(static_cast<int32_T>(numberOfContrasts));
        sldProfiles.set_size(static_cast<int32_T>(numberOfContrasts), 1);
        layerSlds.set_size(static_cast<int32_T>(numberOfContrasts), 1);
        backgrounds.set_size(static_cast<int32_T>(numberOfContrasts));
        shiftedData.set_size(static_cast<int32_T>(numberOfContrasts));
        simulation.set_size(static_cast<int32_T>(numberOfContrasts));
        reflectivity.set_size(static_cast<int32_T>(numberOfContrasts));
        scalefactors.set_size(static_cast<int32_T>(numberOfContrasts));
        bulkIns.set_size(static_cast<int32_T>(numberOfContrasts));
        bulkOuts.set_size(static_cast<int32_T>(numberOfContrasts));
        resolutionParams.set_size(static_cast<int32_T>(numberOfContrasts));
        chis.set_size(static_cast<int32_T>(numberOfContrasts));
        ub_loop = static_cast<int32_T>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r3,d,d1,d2,d3,d4,d5,iv3,b_i,iv4,iv5,c_loop_ub,i2,i3,d_loop_ub)

        for (b_i = 0; b_i <= ub_loop; b_i++) {
          iv3[0] = (*(int32_T (*)[2])contrastBackgroundIndices[b_i].f1.size())[0];
          iv3[1] = (*(int32_T (*)[2])contrastBackgroundIndices[b_i].f1.size())[1];
          iv4[0] = (*(int32_T (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv4[1] = (*(int32_T (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv5[0] = (*(int32_T (*)[2])contrastBackgroundActions[b_i].f1.size())[0];
          iv5[1] = (*(int32_T (*)[2])contrastBackgroundActions[b_i].f1.size())[1];
          b_contrastCalculation((const real_T *)contrastBackgroundIndices[b_i].
                                f1.data(), iv3, contrastQzshiftIndices[b_i],
                                contrastScalefactorIndices[b_i],
                                contrastBulkInIndices[b_i],
                                contrastBulkOutIndices[b_i],
                                contrastResolutionParamIndices[b_i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, dataPresent[b_i], data[b_i]
                                .f1, dataLimits[b_i].f1, simLimits[b_i].f1,
                                repeatLayers[b_i].f1, (const char_T *)
                                contrastBackgroundTypes[b_i].f1.data(), iv4, (
            const char_T *)contrastBackgroundActions[b_i].f1.data(), iv5,
                                customFiles, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[b_i],
                                geometry_data, geometry_size, subRoughs[b_i],
                                true, resampledLayers[b_i].f1, &d5, &d4, &d3,
                                &d2, &d1, &d, reflectivity[b_i].f1,
                                simulation[b_i].f1, r3, backgrounds[b_i].f1, r2,
                                r1, r);
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

          qzshifts[b_i] = d5;
          scalefactors[b_i] = d4;
          bulkIns[b_i] = d3;
          bulkOuts[b_i] = d2;
          resolutionParams[b_i] = d1;
          chis[b_i] = d;
        }
      } else {
        int32_T ub_loop;

        //  Single cored over all contrasts
        ub_loop = static_cast<int32_T>(numberOfContrasts);
        qzshifts.set_size(ub_loop);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int32_T i{0}; i < ub_loop; i++) {
          int32_T b_loop_ub;
          int32_T c_i;
          int32_T i1;
          int32_T loop_ub;
          iv[0] = (*(int32_T (*)[2])contrastBackgroundIndices[i].f1.size())[0];
          iv[1] = (*(int32_T (*)[2])contrastBackgroundIndices[i].f1.size())[1];
          iv1[0] = (*(int32_T (*)[2])contrastBackgroundTypes[i].f1.size())[0];
          iv1[1] = (*(int32_T (*)[2])contrastBackgroundTypes[i].f1.size())[1];
          iv2[0] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv2[1] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[1];
          b_contrastCalculation((const real_T *)contrastBackgroundIndices[i].
                                f1.data(), iv, contrastQzshiftIndices[i],
                                contrastScalefactorIndices[i],
                                contrastBulkInIndices[i],
                                contrastBulkOutIndices[i],
                                contrastResolutionParamIndices[i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, dataPresent[i], data[i].f1,
                                dataLimits[i].f1, simLimits[i].f1,
                                repeatLayers[i].f1, (const char_T *)
                                contrastBackgroundTypes[i].f1.data(), iv1, (
            const char_T *)contrastBackgroundActions[i].f1.data(), iv2,
                                customFiles, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[i],
                                geometry_data, geometry_size, subRoughs[i], true,
                                resampledLayers[i].f1, &qzshifts[i],
                                &scalefactors[i], &bulkIns[i], &bulkOuts[i],
                                &resolutionParams[i], &chis[i], reflectivity[i].
                                f1, simulation[i].f1, r4, backgrounds[i].f1, r5,
                                r6, r7);
          loop_ub = r4.size(0);
          shiftedData[i].f1.set_size(r4.size(0), 3);
          for (c_i = 0; c_i < 3; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layerSlds[i].f1.set_size(r5.size(0), r5.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(0);
          sldProfiles[i].f1.set_size(r6.size(0), 2);
          for (c_i = 0; c_i < 2; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r6[i1 +
                r6.size(0) * c_i];
            }
          }

          loop_ub = r7.size(1);
          resampledLayers[i].f1.set_size(r7.size(0), r7.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r7.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r7[i1 + r7.size(0) * c_i];
            }
          }
        }
      }
    }

    void c_customLayers(const e_struct_T *problemStruct, const struct4_T
                        *controls, ::coder::array<real_T, 1U> &qzshifts, ::coder::
                        array<real_T, 1U> &scalefactors, ::coder::array<real_T,
                        1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                        coder::array<real_T, 1U> &resolutionParams, ::coder::
                        array<real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                        &reflectivity, ::coder::array<cell_wrap_8, 1U>
                        &simulation, ::coder::array<cell_wrap_9, 1U>
                        &shiftedData, ::coder::array<cell_wrap_9, 1U>
                        &backgrounds, ::coder::array<cell_wrap_10, 2U>
                        &layerSlds, ::coder::array<cell_wrap_10, 2U>
                        &sldProfiles, ::coder::array<cell_wrap_10, 2U>
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T iv4[2];
      int32_T iv5[2];
      int32_T b_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i2;
      int32_T i3;
      int32_T nParams;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  The custom layers, normalTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers normalTF calc is
      //  shared between multiple calculation types).
      //  Extract parameters from problemStruct
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      //  Process the custom models
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIns,
        problemStruct->bulkOuts, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemStruct->customFiles,
        problemStruct->params, problemStruct->useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T ub_loop;

        //  Multi cored over all contrasts
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        sldProfiles.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts), 1);
        layerSlds.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts),
                           1);
        backgrounds.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        shiftedData.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        simulation.set_size(static_cast<int32_T>
                            (problemStruct->numberOfContrasts));
        reflectivity.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        scalefactors.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        bulkIns.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        bulkOuts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        resolutionParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        chis.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r3,d,d1,d2,d3,d4,d5,iv3,b_i,iv4,iv5,c_loop_ub,i2,i3,d_loop_ub)

        for (b_i = 0; b_i <= ub_loop; b_i++) {
          iv3[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                     &problemStruct->contrastBackgroundParams[b_i].f1)->size())
            [0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                     &problemStruct->contrastBackgroundParams[b_i].f1)->size())
            [1];
          iv4[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv4[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv5[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv5[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          b_contrastCalculation((const real_T *)((::coder::array<real_T, 2U> *)
            &problemStruct->contrastBackgroundParams[b_i].f1)->data(), iv3,
                                problemStruct->contrastQzshifts[b_i],
                                problemStruct->contrastScalefactors[b_i],
                                problemStruct->contrastBulkIns[b_i],
                                problemStruct->contrastBulkOuts[b_i],
                                problemStruct->contrastResolutionParams[b_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[b_i],
                                problemStruct->data[b_i].f1,
                                problemStruct->dataLimits[b_i].f1,
                                problemStruct->simulationLimits[b_i].f1,
                                problemStruct->repeatLayers[b_i].f1, (const
            char_T *)((::coder::array<char_T, 2U> *)
                      &problemStruct->contrastBackgroundTypes[b_i].f1)->data(),
                                iv4, (const char_T *)((::coder::array<char_T, 2U>
            *)&problemStruct->contrastBackgroundActions[b_i].f1)->data(), iv5,
                                problemStruct->customFiles, static_cast<real_T>
                                (nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary,
                                problemStruct->resample[b_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[b_i],
                                calcSld, resampledLayers[b_i].f1, &d5, &d4, &d3,
                                &d2, &d1, &d, reflectivity[b_i].f1,
                                simulation[b_i].f1, r3, backgrounds[b_i].f1, r2,
                                r1, r);
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

          qzshifts[b_i] = d5;
          scalefactors[b_i] = d4;
          bulkIns[b_i] = d3;
          bulkOuts[b_i] = d2;
          resolutionParams[b_i] = d1;
          chis[b_i] = d;
        }
      } else {
        int32_T ub_loop;

        //  Single cored over all contrasts
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts);
        qzshifts.set_size(ub_loop);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (int32_T i{0}; i < ub_loop; i++) {
          int32_T b_loop_ub;
          int32_T c_i;
          int32_T i1;
          int32_T loop_ub;
          iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[1];
          iv2[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          b_contrastCalculation((const real_T *)((::coder::array<real_T, 2U> *)
            &problemStruct->contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i],
                                problemStruct->contrastResolutionParams[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[i],
                                problemStruct->data[i].f1,
                                problemStruct->dataLimits[i].f1,
                                problemStruct->simulationLimits[i].f1,
                                problemStruct->repeatLayers[i].f1, (const char_T
            *)((::coder::array<char_T, 2U> *)
               &problemStruct->contrastBackgroundTypes[i].f1)->data(), iv1, (
            const char_T *)((::coder::array<char_T, 2U> *)
                            &problemStruct->contrastBackgroundActions[i].f1)
                                ->data(), iv2, problemStruct->customFiles,
                                static_cast<real_T>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i],
                                calcSld, resampledLayers[i].f1, &qzshifts[i],
                                &scalefactors[i], &bulkIns[i], &bulkOuts[i],
                                &resolutionParams[i], &chis[i], reflectivity[i].
                                f1, simulation[i].f1, r4, backgrounds[i].f1, r5,
                                r6, r7);
          loop_ub = r4.size(0);
          shiftedData[i].f1.set_size(r4.size(0), 3);
          for (c_i = 0; c_i < 3; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(1);
          layerSlds[i].f1.set_size(r5.size(0), r5.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r5.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(0);
          sldProfiles[i].f1.set_size(r6.size(0), 2);
          for (c_i = 0; c_i < 2; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r6[i1 +
                r6.size(0) * c_i];
            }
          }

          loop_ub = r7.size(1);
          resampledLayers[i].f1.set_size(r7.size(0), r7.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r7.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r7[i1 + r7.size(0) * c_i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (customLayers.cpp)
