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
#include "coreLayersCalculation.h"
#include "processCustomFunction.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void b_contrastCalculation(real_T backgroundParamIndex, real_T
      qzshiftIndex, real_T scalefactorIndex, real_T bulkInIndex, real_T
      bulkOutIndex, real_T resolutionParamIndex, const ::coder::array<real_T, 2U>
      &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, real_T dataPresent, const ::coder::array<
      real_T, 2U> &data, const real_T dataLimits[2], const real_T simLimits[2],
      const real_T repeatLayers[2], real_T contrastBackgroundActions, real_T
      nParams, const char_T parallel_data[], const int32_T parallel_size[2],
      const real_T resampleParams[2], boolean_T useImaginary, real_T resample,
      const char_T geometry_data[], const int32_T geometry_size[2], real_T
      roughness, boolean_T calcSld, const ::coder::array<real_T, 2U> &layer,
      real_T *backgroundParamValue, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &layerSld, ::coder::
      array<real_T, 2U> &sldProfile, ::coder::array<real_T, 2U> &resampledLayer);
  }
}

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void b_contrastCalculation(real_T backgroundParamIndex, real_T
      qzshiftIndex, real_T scalefactorIndex, real_T bulkInIndex, real_T
      bulkOutIndex, real_T resolutionParamIndex, const ::coder::array<real_T, 2U>
      &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, real_T dataPresent, const ::coder::array<
      real_T, 2U> &data, const real_T dataLimits[2], const real_T simLimits[2],
      const real_T repeatLayers[2], real_T contrastBackgroundActions, real_T
      nParams, const char_T parallel_data[], const int32_T parallel_size[2],
      const real_T resampleParams[2], boolean_T useImaginary, real_T resample,
      const char_T geometry_data[], const int32_T geometry_size[2], real_T
      roughness, boolean_T calcSld, const ::coder::array<real_T, 2U> &layer,
      real_T *backgroundParamValue, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &layerSld, ::coder::
      array<real_T, 2U> &sldProfile, ::coder::array<real_T, 2U> &resampledLayer)
    {
      ::coder::array<real_T, 2U> b_sldProfile;
      int32_T loop_ub;

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(backgroundParamIndex, qzshiftIndex, scalefactorIndex, bulkInIndex,
               bulkOutIndex, resolutionParamIndex, backgroundParams, qzshifts,
               scalefactors, bulkIns, bulkOuts, resolutionParams,
               backgroundParamValue, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Call the core layers calculation
      coreLayersCalculation(layer, roughness, geometry_data, geometry_size,
                            *bulkInValue, *bulkOutValue, resample, calcSld,
                            *scalefactorValue, *qzshiftValue, dataPresent, data,
                            dataLimits, simLimits, repeatLayers,
                            *backgroundParamValue, *resolutionParamValue,
                            contrastBackgroundActions, nParams, parallel_data,
                            parallel_size, resampleParams, useImaginary,
                            b_sldProfile, reflectivity, simulation, shiftedData,
                            layerSld, resampledLayer, chi);
      sldProfile.set_size(b_sldProfile.size(0), b_sldProfile.size(1));
      loop_ub = b_sldProfile.size(1);
      for (int32_T i{0}; i < loop_ub; i++) {
        int32_T b_loop_ub;
        b_loop_ub = b_sldProfile.size(0);
        for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
          sldProfile[i1 + sldProfile.size(0) * i] = b_sldProfile[i1 +
            b_sldProfile.size(0) * i];
        }
      }
    }

    void b_customLayers(const f_struct_T *problemStruct, const cell_11
                        *problemCells, const struct2_T *controls, ::coder::array<
                        real_T, 1U> &backgroundParams, ::coder::array<real_T, 1U>
                        &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::
                        coder::array<real_T, 1U> &bulkIns, ::coder::array<real_T,
                        1U> &bulkOuts, ::coder::array<real_T, 1U>
                        &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                        coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::
                        array<cell_wrap_8, 1U> &simulation, ::coder::array<
                        cell_wrap_10, 1U> &shiftedData, ::coder::array<
                        cell_wrap_10, 1U> &layerSlds, ::coder::array<
                        cell_wrap_10, 1U> &sldProfiles, ::coder::array<
                        cell_wrap_10, 1U> &resampledLayers, ::coder::array<
                        real_T, 1U> &subRoughs)
    {
      ::coder::array<real_T, 2U> b_resampledLayers;
      ::coder::array<real_T, 2U> c_resampledLayers;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T d6;
      int32_T b_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i2;
      int32_T i3;
      int32_T nParams;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  The custom layers, nonPolarisedTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the 'core'
      //  calculation (the core layers nonPolarisedTF calc is shared between
      //  multiple calculation types).
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
      //  Extract individual parameters from problemStruct
      // Extract individual parameters from problem
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;

      //  Pre-Allocation of output arrays...
      //    --- End Memory Allocation ---
      //  Process the custom models
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIn,
        problemStruct->bulkOut, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemCells->f14,
        problemStruct->params, problemStruct->useImaginary, resampledLayers,
        subRoughs);
      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T ub_loop;

        //  Multi cored over all contrasts
        backgroundParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        sldProfiles.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        layerSlds.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        shiftedData.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        simulation.set_size(static_cast<int32_T>
                            (problemStruct->numberOfContrasts));
        reflectivity.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
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
 private(r,r1,c_resampledLayers,d,d1,d2,d3,d4,d5,d6,b_i,c_loop_ub,i2,d_loop_ub,i3)

        for (b_i = 0; b_i <= ub_loop; b_i++) {
          c_resampledLayers.set_size(resampledLayers[b_i].f1.size(0),
            resampledLayers[b_i].f1.size(1));
          c_loop_ub = resampledLayers[b_i].f1.size(1) - 1;
          for (i2 = 0; i2 <= c_loop_ub; i2++) {
            d_loop_ub = resampledLayers[b_i].f1.size(0) - 1;
            for (i3 = 0; i3 <= d_loop_ub; i3++) {
              c_resampledLayers[i3 + c_resampledLayers.size(0) * i2] =
                resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) *
                i2];
            }
          }

          b_contrastCalculation(problemStruct->contrastBackgrounds[b_i],
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
                                f1[b_i].f1,
                                problemStruct->contrastBackgroundActions[b_i],
                                static_cast<real_T>(nParams),
                                controls->parallel.data, controls->parallel.size,
                                controls->resampleParams, useImaginary,
                                problemStruct->resample[b_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[b_i],
                                calcSld, c_resampledLayers, &d6, &d5, &d4, &d3,
                                &d2, &d1, &d, reflectivity[b_i].f1,
                                simulation[b_i].f1, r1, layerSlds[b_i].f1, r,
                                resampledLayers[b_i].f1);
          c_loop_ub = r1.size(1);
          shiftedData[b_i].f1.set_size(r1.size(0), r1.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r1.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              shiftedData[b_i].f1[i3 + shiftedData[b_i].f1.size(0) * i2] = r1[i3
                + r1.size(0) * i2];
            }
          }

          c_loop_ub = r.size(0);
          sldProfiles[b_i].f1.set_size(r.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r[i3
                + r.size(0) * i2];
            }
          }

          backgroundParams[b_i] = d6;
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
        backgroundParams.set_size(ub_loop);
        sldProfiles.set_size(ub_loop);
        layerSlds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
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
          b_resampledLayers.set_size(resampledLayers[i].f1.size(0),
            resampledLayers[i].f1.size(1));
          loop_ub = resampledLayers[i].f1.size(1) - 1;
          for (c_i = 0; c_i <= loop_ub; c_i++) {
            b_loop_ub = resampledLayers[i].f1.size(0) - 1;
            for (i1 = 0; i1 <= b_loop_ub; i1++) {
              b_resampledLayers[i1 + b_resampledLayers.size(0) * c_i] =
                resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i];
            }
          }

          b_contrastCalculation(problemStruct->contrastBackgrounds[i],
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i],
                                problemStruct->contrastResolutionParams[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->dataPresent[i], problemCells->
                                f2[i].f1, problemCells->f3[i].f1,
                                problemCells->f4[i].f1, problemCells->f1[i].f1,
                                problemStruct->contrastBackgroundActions[i],
                                static_cast<real_T>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                controls->resampleParams,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i],
                                calcSld, b_resampledLayers, &backgroundParams[i],
                                &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &resolutionParams[i], &chis[i],
                                reflectivity[i].f1, simulation[i].f1, r2,
                                layerSlds[i].f1, r3, resampledLayers[i].f1);
          loop_ub = r2.size(1);
          shiftedData[i].f1.set_size(r2.size(0), r2.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r2.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r2[i1 +
                r2.size(0) * c_i];
            }
          }

          loop_ub = r3.size(0);
          sldProfiles[i].f1.set_size(r3.size(0), 2);
          for (c_i = 0; c_i < 2; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r3[i1 +
                r3.size(0) * c_i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (customLayers.cpp)
