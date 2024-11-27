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
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "extractProblemParams.h"
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
  namespace nonPolarisedTF
  {
    static void c_contrastCalculation(const real_T backgroundParamIndex_data[],
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
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_3, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T roughness, const ::coder::array<real_T, 2U>
      &sldProfile, real_T *qzshiftValue, real_T *scalefactorValue, real_T
      *bulkInValue, real_T *bulkOutValue, real_T *resolutionParamValue, real_T
      *chi, ::coder::array<real_T, 2U> &reflectivity, ::coder::array<real_T, 2U>
      &simulation, ::coder::array<real_T, 2U> &shiftedData, ::coder::array<
      real_T, 2U> &background, ::coder::array<real_T, 2U> &layerSld, ::coder::
      array<real_T, 2U> &resampledLayer);
  }
}

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void c_contrastCalculation(const real_T backgroundParamIndex_data[],
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
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_3, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T roughness, const ::coder::array<real_T, 2U>
      &sldProfile, real_T *qzshiftValue, real_T *scalefactorValue, real_T
      *bulkInValue, real_T *bulkOutValue, real_T *resolutionParamValue, real_T
      *chi, ::coder::array<real_T, 2U> &reflectivity, ::coder::array<real_T, 2U>
      &simulation, ::coder::array<real_T, 2U> &shiftedData, ::coder::array<
      real_T, 2U> &background, ::coder::array<real_T, 2U> &layerSld, ::coder::
      array<real_T, 2U> &resampledLayer)
    {
      ::coder::array<real_T, 2U> b_data;
      ::coder::array<real_T, 2U> b_layerSld;
      ::coder::array<real_T, 2U> b_shiftedData;
      ::coder::array<real_T, 2U> b_sldProfile;
      ::coder::array<real_T, 2U> c_sldProfile;
      ::coder::array<real_T, 2U> r;
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               resolutionParamIndex, qzshifts, scalefactors, bulkIns, bulkOuts,
               resolutionParams, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

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
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simLimits, background);
      b_layerSld.set_size(layerSld.size(0), layerSld.size(1));
      loop_ub = layerSld.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_loop_ub = layerSld.size(0) - 1;
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          b_layerSld[i1 + b_layerSld.size(0) * i] = layerSld[i1 + layerSld.size
            (0) * i];
        }
      }

      callReflectivity(*bulkInValue, *bulkOutValue, simLimits, repeatLayers,
                       b_shiftedData, b_layerSld, roughness,
                       *resolutionParamValue, parallel_data, parallel_size,
                       useImaginary, reflectivity, simulation);
      applyBackgroundCorrection(reflectivity, simulation, b_shiftedData,
        background, backgroundAction_data, backgroundAction_size, shiftedData);
      if (dataPresent != 0.0) {
        *chi = chiSquared(shiftedData, reflectivity, nParams);
      } else {
        *chi = 0.0;
      }
    }

    void b_customXY(const d_struct_T *problemStruct, const cell_16 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::coder::
                    array<real_T, 1U> &bulkIns, ::coder::array<real_T, 1U>
                    &bulkOuts, ::coder::array<real_T, 1U> &resolutionParams, ::
                    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_10,
                    1U> &reflectivity, ::coder::array<cell_wrap_10, 1U>
                    &simulation, ::coder::array<cell_wrap_11, 1U> &shiftedData, ::
                    coder::array<cell_wrap_11, 1U> &backgrounds, ::coder::array<
                    cell_wrap_12, 2U> &layerSlds, ::coder::array<cell_wrap_12,
                    2U> &sldProfiles, ::coder::array<cell_wrap_12, 2U>
                    &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_36, 1U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      ::coder::array<real_T, 2U> r8;
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
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      boolean_T useImaginary;

      //  Extract individual cell arrays
      //  Splits up the master input list of all arrays into separate arrays
      //
      //  INPUTS:
      //      * problemCells: cell array where all the project data is grouped together.
      //
      //  OUTPUTS:
      //      * repeatLayers: controls repeating of the layers stack.
      //      * data: Array of all the data arrays.
      //      * dataLimits: Min max limits in q for the data arrays.
      //      * simLimits: Limits in Q for the reflectivity simulations.
      //      * layersDetails: Master array of all available layers.
      //      * contrastLayers: Which specific combination of arrays are needed for each contrast.
      //      * customFiles:Filenames and path for any custom files used.
      //         % Layers details N/A
      //  Extract individual parameters from problemStruct
      // Extract individual parameters from problem
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      //  Process the custom models
      customXY::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIn,
        problemStruct->bulkOut, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemCells->f14,
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
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        resampledLayers.set_size(static_cast<int32_T>
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
        loop_ub = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,r3,r4,r5,d,d1,d2,d3,d4,d5,c_loop_ub,c_i,i3,iv2,d_loop_ub,i4,iv3)

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

          iv2[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv3[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          c_contrastCalculation(problemStruct->contrastBackgroundParams[c_i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[c_i].f1.size,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i],
                                problemStruct->contrastResolutionParams[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[c_i],
                                problemCells->f2[c_i].f1, problemCells->f3[c_i].
                                f1, problemCells->f4[c_i].f1, problemCells->
                                f1[c_i].f1, (const char_T *)((::coder::array<
            char_T, 2U> *)&problemStruct->contrastBackgroundTypes[c_i].f1)->data
                                (), iv2, (const char_T *)((::coder::array<char_T,
            2U> *)&problemStruct->contrastBackgroundActions[c_i].f1)->data(),
                                iv3, problemCells->f14, static_cast<real_T>
                                (nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                r5, &d5, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r4,
                                backgrounds[c_i].f1, r3, r1);
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

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        qzshifts.set_size(i);
        resampledLayers.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          loop_ub = sldProfiles[b_i].f1.size(1);
          r2.set_size(sldProfiles[b_i].f1.size(0), sldProfiles[b_i].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfiles[b_i].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r2[i2 + r2.size(0) * i1] = sldProfiles[b_i].f1[i2 +
                sldProfiles[b_i].f1.size(0) * i1];
            }
          }

          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          c_contrastCalculation(problemStruct->contrastBackgroundParams[b_i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[b_i].f1.size,
                                problemStruct->contrastQzshifts[b_i],
                                problemStruct->contrastScalefactors[b_i],
                                problemStruct->contrastBulkIns[b_i],
                                problemStruct->contrastBulkOuts[b_i],
                                problemStruct->contrastResolutionParams[b_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[b_i],
                                problemCells->f2[b_i].f1, problemCells->f3[b_i].
                                f1, problemCells->f4[b_i].f1, problemCells->
                                f1[b_i].f1, (const char_T *)((::coder::array<
            char_T, 2U> *)&problemStruct->contrastBackgroundTypes[b_i].f1)->data
                                (), iv, (const char_T *)((::coder::array<char_T,
            2U> *)&problemStruct->contrastBackgroundActions[b_i].f1)->data(),
                                iv1, problemCells->f14, static_cast<real_T>
                                (problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary, subRoughs[b_i], r2,
                                &qzshifts[b_i], &scalefactors[b_i], &bulkIns[b_i],
                                &bulkOuts[b_i], &resolutionParams[b_i],
                                &chis[b_i], reflectivity[b_i].f1, simulation[b_i]
                                .f1, r6, backgrounds[b_i].f1, r7, r8);
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

    void b_customXY(const f_struct_T *problemStruct, const cell_16 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::coder::
                    array<real_T, 1U> &bulkIns, ::coder::array<real_T, 1U>
                    &bulkOuts, ::coder::array<real_T, 1U> &resolutionParams, ::
                    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_10,
                    1U> &reflectivity, ::coder::array<cell_wrap_10, 1U>
                    &simulation, ::coder::array<cell_wrap_11, 1U> &shiftedData, ::
                    coder::array<cell_wrap_11, 1U> &backgrounds, ::coder::array<
                    cell_wrap_12, 2U> &layerSlds, ::coder::array<cell_wrap_12,
                    2U> &sldProfiles, ::coder::array<cell_wrap_12, 2U>
                    &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_36, 1U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      ::coder::array<real_T, 2U> r8;
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
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      boolean_T useImaginary;

      //  Extract individual cell arrays
      //  Splits up the master input list of all arrays into separate arrays
      //
      //  INPUTS:
      //      * problemCells: cell array where all the project data is grouped together.
      //
      //  OUTPUTS:
      //      * repeatLayers: controls repeating of the layers stack.
      //      * data: Array of all the data arrays.
      //      * dataLimits: Min max limits in q for the data arrays.
      //      * simLimits: Limits in Q for the reflectivity simulations.
      //      * layersDetails: Master array of all available layers.
      //      * contrastLayers: Which specific combination of arrays are needed for each contrast.
      //      * customFiles:Filenames and path for any custom files used.
      //         % Layers details N/A
      //  Extract individual parameters from problemStruct
      // Extract individual parameters from problem
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      //  Process the custom models
      customXY::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIn,
        problemStruct->bulkOut, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemCells->f14,
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
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        resampledLayers.set_size(static_cast<int32_T>
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
        loop_ub = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,r3,r4,r5,d,d1,d2,d3,d4,d5,c_loop_ub,c_i,i3,iv2,d_loop_ub,i4,iv3)

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

          iv2[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv3[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          c_contrastCalculation(problemStruct->contrastBackgroundParams[c_i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[c_i].f1.size,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i],
                                problemStruct->contrastResolutionParams[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[c_i],
                                problemCells->f2[c_i].f1, problemCells->f3[c_i].
                                f1, problemCells->f4[c_i].f1, problemCells->
                                f1[c_i].f1, (const char_T *)((::coder::array<
            char_T, 2U> *)&problemStruct->contrastBackgroundTypes[c_i].f1)->data
                                (), iv2, (const char_T *)((::coder::array<char_T,
            2U> *)&problemStruct->contrastBackgroundActions[c_i].f1)->data(),
                                iv3, problemCells->f14, static_cast<real_T>
                                (nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                r5, &d5, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r4,
                                backgrounds[c_i].f1, r3, r1);
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

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        qzshifts.set_size(i);
        resampledLayers.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          loop_ub = sldProfiles[b_i].f1.size(1);
          r2.set_size(sldProfiles[b_i].f1.size(0), sldProfiles[b_i].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfiles[b_i].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r2[i2 + r2.size(0) * i1] = sldProfiles[b_i].f1[i2 +
                sldProfiles[b_i].f1.size(0) * i1];
            }
          }

          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          c_contrastCalculation(problemStruct->contrastBackgroundParams[b_i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[b_i].f1.size,
                                problemStruct->contrastQzshifts[b_i],
                                problemStruct->contrastScalefactors[b_i],
                                problemStruct->contrastBulkIns[b_i],
                                problemStruct->contrastBulkOuts[b_i],
                                problemStruct->contrastResolutionParams[b_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[b_i],
                                problemCells->f2[b_i].f1, problemCells->f3[b_i].
                                f1, problemCells->f4[b_i].f1, problemCells->
                                f1[b_i].f1, (const char_T *)((::coder::array<
            char_T, 2U> *)&problemStruct->contrastBackgroundTypes[b_i].f1)->data
                                (), iv, (const char_T *)((::coder::array<char_T,
            2U> *)&problemStruct->contrastBackgroundActions[b_i].f1)->data(),
                                iv1, problemCells->f14, static_cast<real_T>
                                (problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary, subRoughs[b_i], r2,
                                &qzshifts[b_i], &scalefactors[b_i], &bulkIns[b_i],
                                &bulkOuts[b_i], &resolutionParams[b_i],
                                &chis[b_i], reflectivity[b_i].f1, simulation[b_i]
                                .f1, r6, backgrounds[b_i].f1, r7, r8);
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

    void b_customXY(const struct0_T *problemStruct, const cell_9 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::coder::
                    array<real_T, 1U> &bulkIns, ::coder::array<real_T, 1U>
                    &bulkOuts, ::coder::array<real_T, 1U> &resolutionParams, ::
                    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_10,
                    1U> &reflectivity, ::coder::array<cell_wrap_10, 1U>
                    &simulation, ::coder::array<cell_wrap_11, 1U> &shiftedData, ::
                    coder::array<cell_wrap_11, 1U> &backgrounds, ::coder::array<
                    cell_wrap_12, 2U> &layerSlds, ::coder::array<cell_wrap_12,
                    2U> &sldProfiles, ::coder::array<cell_wrap_12, 2U>
                    &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_14, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_3, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_3, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_36, 1U> r;
      ::coder::array<real_T, 2U> a__4;
      ::coder::array<real_T, 2U> a__5;
      ::coder::array<real_T, 2U> a__7;
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
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      ::coder::array<real_T, 2U> r8;
      ::coder::array<real_T, 2U> resolutionParamArray;
      ::coder::array<real_T, 2U> scalefactorArray;
      cell_16 expl_temp;
      real_T a__6;
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
      int32_T a__3_size[2];
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      char_T a__3_data[10000];
      boolean_T useImaginary;

      //  Extract individual cell arrays
      cast(problemCells, &expl_temp);

      //  Splits up the master input list of all arrays into separate arrays
      //
      //  INPUTS:
      //      * problemCells: cell array where all the project data is grouped together.
      //
      //  OUTPUTS:
      //      * repeatLayers: controls repeating of the layers stack.
      //      * data: Array of all the data arrays.
      //      * dataLimits: Min max limits in q for the data arrays.
      //      * simLimits: Limits in Q for the reflectivity simulations.
      //      * layersDetails: Master array of all available layers.
      //      * contrastLayers: Which specific combination of arrays are needed for each contrast.
      //      * customFiles:Filenames and path for any custom files used.
      //         % Layers details N/A
      //  Extract individual parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, a__3_data,
                           a__3_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionParamIndices, a__4,
                           backgroundParamArray, qzshiftArray, scalefactorArray,
                           bulkInArray, bulkOutArray, resolutionParamArray, a__5,
                           dataPresent, &nParams, params, &a__6, a__7,
                           contrastBackgroundTypes, contrastBackgroundActions,
                           cCustFiles, &useImaginary);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      //  Process the custom models
      customXY::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, expl_temp.f14, params, r, subRoughs);
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
        qzshifts.set_size(static_cast<int32_T>(numberOfContrasts));
        resampledLayers.set_size(static_cast<int32_T>(numberOfContrasts), 1);
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
        loop_ub = static_cast<int32_T>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,r3,r4,r5,d,d1,d2,d3,d4,d5,c_loop_ub,c_i,i3,iv1,d_loop_ub,i4,iv2)

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

          iv1[0] = (*(int32_T (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv1[1] = (*(int32_T (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv2[0] = (*(int32_T (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv2[1] = (*(int32_T (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          c_contrastCalculation(contrastBackgroundIndices[c_i].f1.data,
                                contrastBackgroundIndices[c_i].f1.size,
                                contrastQzshiftIndices[c_i],
                                contrastScalefactorIndices[c_i],
                                contrastBulkInIndices[c_i],
                                contrastBulkOutIndices[c_i],
                                contrastResolutionParamIndices[c_i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, dataPresent[c_i],
                                expl_temp.f2[c_i].f1, expl_temp.f3[c_i].f1,
                                expl_temp.f4[c_i].f1, expl_temp.f1[c_i].f1, (
            const char_T *)contrastBackgroundTypes[c_i].f1.data(), iv1, (const
            char_T *)contrastBackgroundActions[c_i].f1.data(), iv2,
                                expl_temp.f14, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                r5, &d5, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r4,
                                backgrounds[c_i].f1, r3, r1);
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

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        i = static_cast<int32_T>(numberOfContrasts);
        qzshifts.set_size(i);
        resampledLayers.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          loop_ub = sldProfiles[b_i].f1.size(1);
          r2.set_size(sldProfiles[b_i].f1.size(0), sldProfiles[b_i].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfiles[b_i].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r2[i2 + r2.size(0) * i1] = sldProfiles[b_i].f1[i2 +
                sldProfiles[b_i].f1.size(0) * i1];
            }
          }

          a__3_size[0] = (*(int32_T (*)[2])contrastBackgroundTypes[b_i].f1.size())
            [0];
          a__3_size[1] = (*(int32_T (*)[2])contrastBackgroundTypes[b_i].f1.size())
            [1];
          iv[0] = (*(int32_T (*)[2])contrastBackgroundActions[b_i].f1.size())[0];
          iv[1] = (*(int32_T (*)[2])contrastBackgroundActions[b_i].f1.size())[1];
          c_contrastCalculation(contrastBackgroundIndices[b_i].f1.data,
                                contrastBackgroundIndices[b_i].f1.size,
                                contrastQzshiftIndices[b_i],
                                contrastScalefactorIndices[b_i],
                                contrastBulkInIndices[b_i],
                                contrastBulkOutIndices[b_i],
                                contrastResolutionParamIndices[b_i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, dataPresent[b_i],
                                expl_temp.f2[b_i].f1, expl_temp.f3[b_i].f1,
                                expl_temp.f4[b_i].f1, expl_temp.f1[b_i].f1, (
            const char_T *)contrastBackgroundTypes[b_i].f1.data(), a__3_size, (
            const char_T *)contrastBackgroundActions[b_i].f1.data(), iv,
                                expl_temp.f14, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[b_i],
                                r2, &qzshifts[b_i], &scalefactors[b_i],
                                &bulkIns[b_i], &bulkOuts[b_i],
                                &resolutionParams[b_i], &chis[b_i],
                                reflectivity[b_i].f1, simulation[b_i].f1, r6,
                                backgrounds[b_i].f1, r7, r8);
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
