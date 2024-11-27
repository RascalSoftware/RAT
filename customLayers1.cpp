//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customLayers1.cpp
//
// Code generation for function 'customLayers1'
//

// Include files
#include "customLayers1.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "backSort.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "coreLayersCalculation.h"
#include "extractProblemParams.h"
#include "processCustomFunction2.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    static void b_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, real_T domainRatioIndex, const ::coder::array<real_T,
      2U> &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, const ::coder::array<real_T, 2U>
      &domainRatios, real_T dataPresent, const ::coder::array<real_T, 2U> &data,
      const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_3, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T resample, const char_T geometry_data[],
      const int32_T geometry_size[2], real_T roughness, boolean_T calcSld, const
      ::coder::array<real_T, 2U> &calcAllLayers1, const ::coder::array<real_T,
      2U> &calcAllLayers2, real_T *qzshiftValue, real_T *scalefactorValue,
      real_T *bulkInValue, real_T *bulkOutValue, real_T *resolutionParamValue,
      real_T *chi, ::coder::array<real_T, 2U> &reflectivity, ::coder::array<
      real_T, 2U> &simulation, ::coder::array<real_T, 2U> &shiftedData, ::coder::
      array<real_T, 2U> &background, cell_wrap_12 layerSld[2], cell_wrap_10
      sldProfile[2], cell_wrap_12 resampledLayer[2]);
  }
}

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    static void b_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, real_T domainRatioIndex, const ::coder::array<real_T,
      2U> &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, const ::coder::array<real_T, 2U>
      &domainRatios, real_T dataPresent, const ::coder::array<real_T, 2U> &data,
      const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_3, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T resample, const char_T geometry_data[],
      const int32_T geometry_size[2], real_T roughness, boolean_T calcSld, const
      ::coder::array<real_T, 2U> &calcAllLayers1, const ::coder::array<real_T,
      2U> &calcAllLayers2, real_T *qzshiftValue, real_T *scalefactorValue,
      real_T *bulkInValue, real_T *bulkOutValue, real_T *resolutionParamValue,
      real_T *chi, ::coder::array<real_T, 2U> &reflectivity, ::coder::array<
      real_T, 2U> &simulation, ::coder::array<real_T, 2U> &shiftedData, ::coder::
      array<real_T, 2U> &background, cell_wrap_12 layerSld[2], cell_wrap_10
      sldProfile[2], cell_wrap_12 resampledLayer[2])
    {
      ::coder::array<real_T, 2U> a__4;
      ::coder::array<real_T, 2U> b_data;
      ::coder::array<real_T, 2U> b_shiftedData;
      ::coder::array<real_T, 2U> reflect1;
      ::coder::array<real_T, 2U> reflect2;
      ::coder::array<real_T, 2U> simul1;
      ::coder::array<real_T, 2U> simul2;
      cell_wrap_10 r;
      cell_wrap_10 r3;
      cell_wrap_12 r1;
      cell_wrap_12 r2;
      cell_wrap_12 r4;
      cell_wrap_12 r5;
      real_T a__5;
      real_T a__6;
      real_T domainRatios_tmp;
      int32_T b_loop_ub;
      int32_T i;
      int32_T loop_ub;

      //  Get the domain ratio for this contrast
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
      for (i = 0; i < 6; i++) {
        for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
          b_data[b_loop_ub + b_data.size(0) * i] = data[b_loop_ub + data.size(0)
            * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simLimits, background);

      //  Call the core layers calculation - need to do this once for each
      //  domain
      nonPolarisedTF::coreLayersCalculation(calcAllLayers1, roughness,
        geometry_data, geometry_size, *bulkInValue, *bulkOutValue, resample,
        calcSld, b_shiftedData, simLimits, repeatLayers, *resolutionParamValue,
        background, backgroundAction_data, backgroundAction_size, nParams,
        parallel_data, parallel_size, resampleMinAngle, resampleNPoints,
        useImaginary, r.f1, reflect1, simul1, a__4, r1.f1, r2.f1, &a__5);
      nonPolarisedTF::coreLayersCalculation(calcAllLayers2, roughness,
        geometry_data, geometry_size, *bulkInValue, *bulkOutValue, resample,
        calcSld, b_shiftedData, simLimits, repeatLayers, *resolutionParamValue,
        background, backgroundAction_data, backgroundAction_size, nParams,
        parallel_data, parallel_size, resampleMinAngle, resampleNPoints,
        useImaginary, r3.f1, reflect2, simul2, shiftedData, r4.f1, r5.f1, &a__6);

      //  Calculate the average reflectivities....
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      domainRatios_tmp = domainRatios[static_cast<int32_T>(domainRatioIndex) - 1];
      loop_ub = reflect1.size(0);
      b_loop_ub = reflect1.size(0);
      reflectivity.set_size(reflect1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        reflectivity[i] = reflect1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        reflectivity[i + reflectivity.size(0)] = domainRatios_tmp * reflect1[i +
          reflect1.size(0)] + (1.0 - domainRatios_tmp) * reflect2[i +
          reflect2.size(0)];
      }

      loop_ub = simul1.size(0);
      b_loop_ub = simul1.size(0);
      simulation.set_size(simul1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        simulation[i] = simul1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        simulation[i + simulation.size(0)] = domainRatios_tmp * simul1[i +
          simul1.size(0)] + (1.0 - domainRatios_tmp) * simul2[i + simul2.size(0)];
      }

      //  Get an overall chi-squared for the new averaged curve..
      *chi = chiSquared(shiftedData, reflectivity, nParams);

      //  Store returned values for this contrast in the output arrays.
      sldProfile[0] = r;
      sldProfile[1] = r3;
      layerSld[0] = r1;
      layerSld[1] = r4;
      resampledLayer[0] = r2;
      resampledLayer[1] = r5;
    }

    void b_customLayers(const d_struct_T *problemStruct, const cell_16
                        *problemCells, const struct2_T *controls, ::coder::array<
                        real_T, 1U> &qzshifts, ::coder::array<real_T, 1U>
                        &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                        coder::array<real_T, 1U> &bulkOuts, ::coder::array<
                        real_T, 1U> &resolutionParams, ::coder::array<real_T, 1U>
                        &chis, ::coder::array<cell_wrap_10, 1U> &reflectivity, ::
                        coder::array<cell_wrap_10, 1U> &simulation, ::coder::
                        array<cell_wrap_11, 1U> &shiftedData, ::coder::array<
                        cell_wrap_11, 1U> &backgrounds, ::coder::array<
                        cell_wrap_12, 2U> &domainLayerSlds, ::coder::array<
                        cell_wrap_12, 2U> &domainSldProfiles, ::coder::array<
                        cell_wrap_12, 2U> &domainResampledLayers, ::coder::array<
                        real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_12, 2U> calcAllLayers;
      ::coder::array<cell_wrap_12, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_12, 1U> calcAllLayers2;
      ::coder::array<cell_wrap_66, 1U> layerSlds;
      ::coder::array<cell_wrap_66, 1U> resampledLayers;
      ::coder::array<cell_wrap_67, 1U> sldProfiles;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T numberOfContrasts;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      int32_T unnamed_idx_0_tmp_tmp;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  The custom layers, domainsTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers domainsTF calc is shared
      //  between multiple calculation types).
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
      numberOfContrasts = problemStruct->numberOfContrasts;
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      unnamed_idx_0_tmp_tmp = static_cast<int32_T>
        (problemStruct->numberOfContrasts);
      calcAllLayers1.set_size(unnamed_idx_0_tmp_tmp);
      calcAllLayers2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        calcAllLayers1[i].f1.set_size(2, 1);
        calcAllLayers1[i].f1[0] = 1.0;
        calcAllLayers1[i].f1[1] = 1.0;
        calcAllLayers2[i].f1.set_size(2, 1);
        calcAllLayers2[i].f1[0] = 1.0;
        calcAllLayers2[i].f1[1] = 1.0;
      }

      //  Process the custom models....
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIn,
        problemStruct->bulkOut, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemCells->f14,
        problemStruct->params, problemStruct->useImaginary, calcAllLayers,
        subRoughs);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = calcAllLayers[i].f1.size(1);
        calcAllLayers1[i].f1.set_size(calcAllLayers[i].f1.size(0),
          calcAllLayers[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers1[i].f1[i2 + calcAllLayers1[i].f1.size(0) * i1] =
              calcAllLayers[i].f1[i2 + calcAllLayers[i].f1.size(0) * i1];
          }
        }

        loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(1);
        calcAllLayers2[i].f1.set_size(calcAllLayers[i + calcAllLayers.size(0)].
          f1.size(0), calcAllLayers[i + calcAllLayers.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers2[i].f1[i2 + calcAllLayers2[i].f1.size(0) * i1] =
              calcAllLayers[i + calcAllLayers.size(0)].f1[i2 + calcAllLayers[i +
              calcAllLayers.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Parallel over all contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        loop_ub = unnamed_idx_0_tmp_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,d,d1,d2,d3,d4,d5,iv2,c_i,iv3,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
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
          b_contrastCalculation(problemStruct->contrastBackgroundParams[c_i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[c_i].f1.size,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i],
                                problemStruct->contrastResolutionParams[c_i],
                                problemStruct->contrastDomainRatios[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatio,
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
                                resampleNPoints, useImaginary,
                                problemStruct->resample[c_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[c_i],
                                calcSld, calcAllLayers1[c_i].f1,
                                calcAllLayers2[c_i].f1, &d5, &d4, &d3, &d2, &d1,
                                &d, reflectivity[c_i].f1, simulation[c_i].f1, r,
                                backgrounds[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r.size(0);
          shiftedData[c_i].f1.set_size(r.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r[i4
                + r.size(0) * i3];
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
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          b_contrastCalculation(problemStruct->contrastBackgroundParams[i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[i].f1.size,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i],
                                problemStruct->contrastResolutionParams[i],
                                problemStruct->contrastDomainRatios[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatio,
                                problemStruct->dataPresent[i], problemCells->
                                f2[i].f1, problemCells->f3[i].f1,
                                problemCells->f4[i].f1, problemCells->f1[i].f1,
                                (const char_T *)((::coder::array<char_T, 2U> *)
            &problemStruct->contrastBackgroundTypes[i].f1)->data(), iv, (const
            char_T *)((::coder::array<char_T, 2U> *)
                      &problemStruct->contrastBackgroundActions[i].f1)->data(),
                                iv1, problemCells->f14, static_cast<real_T>
                                (problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i],
                                calcSld, calcAllLayers1[i].f1, calcAllLayers2[i]
                                .f1, &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &resolutionParams[i], &chis[i],
                                reflectivity[i].f1, simulation[i].f1, r1,
                                backgrounds[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(0);
          shiftedData[i].f1.set_size(r1.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int32_T>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }

    void b_customLayers(const f_struct_T *problemStruct, const cell_16
                        *problemCells, const struct2_T *controls, ::coder::array<
                        real_T, 1U> &qzshifts, ::coder::array<real_T, 1U>
                        &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                        coder::array<real_T, 1U> &bulkOuts, ::coder::array<
                        real_T, 1U> &resolutionParams, ::coder::array<real_T, 1U>
                        &chis, ::coder::array<cell_wrap_10, 1U> &reflectivity, ::
                        coder::array<cell_wrap_10, 1U> &simulation, ::coder::
                        array<cell_wrap_11, 1U> &shiftedData, ::coder::array<
                        cell_wrap_11, 1U> &backgrounds, ::coder::array<
                        cell_wrap_12, 2U> &domainLayerSlds, ::coder::array<
                        cell_wrap_12, 2U> &domainSldProfiles, ::coder::array<
                        cell_wrap_12, 2U> &domainResampledLayers, ::coder::array<
                        real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_12, 2U> calcAllLayers;
      ::coder::array<cell_wrap_12, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_12, 1U> calcAllLayers2;
      ::coder::array<cell_wrap_66, 1U> layerSlds;
      ::coder::array<cell_wrap_66, 1U> resampledLayers;
      ::coder::array<cell_wrap_67, 1U> sldProfiles;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T numberOfContrasts;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      int32_T unnamed_idx_0_tmp_tmp;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  The custom layers, domainsTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers domainsTF calc is shared
      //  between multiple calculation types).
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
      numberOfContrasts = problemStruct->numberOfContrasts;
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      unnamed_idx_0_tmp_tmp = static_cast<int32_T>
        (problemStruct->numberOfContrasts);
      calcAllLayers1.set_size(unnamed_idx_0_tmp_tmp);
      calcAllLayers2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        calcAllLayers1[i].f1.set_size(2, 1);
        calcAllLayers1[i].f1[0] = 1.0;
        calcAllLayers1[i].f1[1] = 1.0;
        calcAllLayers2[i].f1.set_size(2, 1);
        calcAllLayers2[i].f1[0] = 1.0;
        calcAllLayers2[i].f1[1] = 1.0;
      }

      //  Process the custom models....
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIn,
        problemStruct->bulkOut, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemCells->f14,
        problemStruct->params, problemStruct->useImaginary, calcAllLayers,
        subRoughs);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = calcAllLayers[i].f1.size(1);
        calcAllLayers1[i].f1.set_size(calcAllLayers[i].f1.size(0),
          calcAllLayers[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers1[i].f1[i2 + calcAllLayers1[i].f1.size(0) * i1] =
              calcAllLayers[i].f1[i2 + calcAllLayers[i].f1.size(0) * i1];
          }
        }

        loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(1);
        calcAllLayers2[i].f1.set_size(calcAllLayers[i + calcAllLayers.size(0)].
          f1.size(0), calcAllLayers[i + calcAllLayers.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers2[i].f1[i2 + calcAllLayers2[i].f1.size(0) * i1] =
              calcAllLayers[i + calcAllLayers.size(0)].f1[i2 + calcAllLayers[i +
              calcAllLayers.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Parallel over all contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        loop_ub = unnamed_idx_0_tmp_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,d,d1,d2,d3,d4,d5,iv2,c_i,iv3,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
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
          b_contrastCalculation(problemStruct->contrastBackgroundParams[c_i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[c_i].f1.size,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i],
                                problemStruct->contrastResolutionParams[c_i],
                                problemStruct->contrastDomainRatios[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatio,
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
                                resampleNPoints, useImaginary,
                                problemStruct->resample[c_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[c_i],
                                calcSld, calcAllLayers1[c_i].f1,
                                calcAllLayers2[c_i].f1, &d5, &d4, &d3, &d2, &d1,
                                &d, reflectivity[c_i].f1, simulation[c_i].f1, r,
                                backgrounds[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r.size(0);
          shiftedData[c_i].f1.set_size(r.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r[i4
                + r.size(0) * i3];
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
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          b_contrastCalculation(problemStruct->contrastBackgroundParams[i].
                                f1.data, problemStruct->
                                contrastBackgroundParams[i].f1.size,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i],
                                problemStruct->contrastResolutionParams[i],
                                problemStruct->contrastDomainRatios[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIn, problemStruct->bulkOut,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatio,
                                problemStruct->dataPresent[i], problemCells->
                                f2[i].f1, problemCells->f3[i].f1,
                                problemCells->f4[i].f1, problemCells->f1[i].f1,
                                (const char_T *)((::coder::array<char_T, 2U> *)
            &problemStruct->contrastBackgroundTypes[i].f1)->data(), iv, (const
            char_T *)((::coder::array<char_T, 2U> *)
                      &problemStruct->contrastBackgroundActions[i].f1)->data(),
                                iv1, problemCells->f14, static_cast<real_T>
                                (problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i],
                                calcSld, calcAllLayers1[i].f1, calcAllLayers2[i]
                                .f1, &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &resolutionParams[i], &chis[i],
                                reflectivity[i].f1, simulation[i].f1, r1,
                                backgrounds[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(0);
          shiftedData[i].f1.set_size(r1.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int32_T>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }

    void b_customLayers(const struct0_T *problemStruct, const cell_9
                        *problemCells, const struct2_T *controls, ::coder::array<
                        real_T, 1U> &qzshifts, ::coder::array<real_T, 1U>
                        &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                        coder::array<real_T, 1U> &bulkOuts, ::coder::array<
                        real_T, 1U> &resolutionParams, ::coder::array<real_T, 1U>
                        &chis, ::coder::array<cell_wrap_10, 1U> &reflectivity, ::
                        coder::array<cell_wrap_10, 1U> &simulation, ::coder::
                        array<cell_wrap_11, 1U> &shiftedData, ::coder::array<
                        cell_wrap_11, 1U> &backgrounds, ::coder::array<
                        cell_wrap_12, 2U> &domainLayerSlds, ::coder::array<
                        cell_wrap_12, 2U> &domainSldProfiles, ::coder::array<
                        cell_wrap_12, 2U> &domainResampledLayers, ::coder::array<
                        real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_12, 2U> calcAllLayers;
      ::coder::array<cell_wrap_12, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_12, 1U> calcAllLayers2;
      ::coder::array<cell_wrap_14, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_3, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_3, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_66, 1U> layerSlds;
      ::coder::array<cell_wrap_66, 1U> resampledLayers;
      ::coder::array<cell_wrap_67, 1U> sldProfiles;
      ::coder::array<real_T, 2U> backgroundParamArray;
      ::coder::array<real_T, 2U> bulkInArray;
      ::coder::array<real_T, 2U> bulkOutArray;
      ::coder::array<real_T, 2U> cCustFiles;
      ::coder::array<real_T, 2U> contrastBulkInIndices;
      ::coder::array<real_T, 2U> contrastBulkOutIndices;
      ::coder::array<real_T, 2U> contrastDomainRatioIndices;
      ::coder::array<real_T, 2U> contrastQzshiftIndices;
      ::coder::array<real_T, 2U> contrastResolutionParamIndices;
      ::coder::array<real_T, 2U> contrastScalefactorIndices;
      ::coder::array<real_T, 2U> dataPresent;
      ::coder::array<real_T, 2U> domainRatioArray;
      ::coder::array<real_T, 2U> params;
      ::coder::array<real_T, 2U> qzshiftArray;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> resample;
      ::coder::array<real_T, 2U> resolutionParamArray;
      ::coder::array<real_T, 2U> scalefactorArray;
      cell_16 expl_temp;
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
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T unnamed_idx_0;
      int32_T unnamed_idx_0_tmp_tmp;
      char_T geometry_data[10000];
      boolean_T useImaginary;

      //  The custom layers, domainsTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers domainsTF calc is shared
      //  between multiple calculation types).
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
      //  Extract individual parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, geometry_data,
                           geometry_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionParamIndices,
                           contrastDomainRatioIndices, backgroundParamArray,
                           qzshiftArray, scalefactorArray, bulkInArray,
                           bulkOutArray, resolutionParamArray, domainRatioArray,
                           dataPresent, &nParams, params, &a__3, resample,
                           contrastBackgroundTypes, contrastBackgroundActions,
                           cCustFiles, &useImaginary);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      unnamed_idx_0_tmp_tmp = static_cast<int32_T>(numberOfContrasts);
      unnamed_idx_0 = static_cast<int32_T>(numberOfContrasts);
      calcAllLayers1.set_size(unnamed_idx_0_tmp_tmp);
      calcAllLayers2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        calcAllLayers1[i].f1.set_size(2, 1);
        calcAllLayers1[i].f1[0] = 1.0;
        calcAllLayers1[i].f1[1] = 1.0;
        calcAllLayers2[i].f1.set_size(2, 1);
        calcAllLayers2[i].f1[0] = 1.0;
        calcAllLayers2[i].f1[1] = 1.0;
      }

      //  Process the custom models....
      customLayers::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, expl_temp.f14, params, useImaginary, calcAllLayers,
        subRoughs);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = calcAllLayers[i].f1.size(1);
        calcAllLayers1[i].f1.set_size(calcAllLayers[i].f1.size(0),
          calcAllLayers[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers1[i].f1[i2 + calcAllLayers1[i].f1.size(0) * i1] =
              calcAllLayers[i].f1[i2 + calcAllLayers[i].f1.size(0) * i1];
          }
        }

        loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(1);
        calcAllLayers2[i].f1.set_size(calcAllLayers[i + calcAllLayers.size(0)].
          f1.size(0), calcAllLayers[i + calcAllLayers.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers2[i].f1[i2 + calcAllLayers2[i].f1.size(0) * i1] =
              calcAllLayers[i + calcAllLayers.size(0)].f1[i2 + calcAllLayers[i +
              calcAllLayers.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Parallel over all contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        unnamed_idx_0_tmp_tmp = static_cast<int32_T>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,d,d1,d2,d3,d4,d5,iv2,c_i,iv3,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= unnamed_idx_0_tmp_tmp; c_i++) {
          iv2[0] = (*(int32_T (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv2[1] = (*(int32_T (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv3[0] = (*(int32_T (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv3[1] = (*(int32_T (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          b_contrastCalculation(contrastBackgroundIndices[c_i].f1.data,
                                contrastBackgroundIndices[c_i].f1.size,
                                contrastQzshiftIndices[c_i],
                                contrastScalefactorIndices[c_i],
                                contrastBulkInIndices[c_i],
                                contrastBulkOutIndices[c_i],
                                contrastResolutionParamIndices[c_i],
                                contrastDomainRatioIndices[c_i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, domainRatioArray,
                                dataPresent[c_i], expl_temp.f2[c_i].f1,
                                expl_temp.f3[c_i].f1, expl_temp.f4[c_i].f1,
                                expl_temp.f1[c_i].f1, (const char_T *)
                                contrastBackgroundTypes[c_i].f1.data(), iv2, (
            const char_T *)contrastBackgroundActions[c_i].f1.data(), iv3,
                                expl_temp.f14, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[c_i],
                                geometry_data, geometry_size, subRoughs[c_i],
                                true, calcAllLayers1[c_i].f1, calcAllLayers2[c_i]
                                .f1, &d5, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r,
                                backgrounds[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r.size(0);
          shiftedData[c_i].f1.set_size(r.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r[i4
                + r.size(0) * i3];
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
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int32_T (*)[2])contrastBackgroundTypes[i].f1.size())[0];
          iv[1] = (*(int32_T (*)[2])contrastBackgroundTypes[i].f1.size())[1];
          iv1[0] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv1[1] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[1];
          b_contrastCalculation(contrastBackgroundIndices[i].f1.data,
                                contrastBackgroundIndices[i].f1.size,
                                contrastQzshiftIndices[i],
                                contrastScalefactorIndices[i],
                                contrastBulkInIndices[i],
                                contrastBulkOutIndices[i],
                                contrastResolutionParamIndices[i],
                                contrastDomainRatioIndices[i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, domainRatioArray,
                                dataPresent[i], expl_temp.f2[i].f1,
                                expl_temp.f3[i].f1, expl_temp.f4[i].f1,
                                expl_temp.f1[i].f1, (const char_T *)
                                contrastBackgroundTypes[i].f1.data(), iv, (const
            char_T *)contrastBackgroundActions[i].f1.data(), iv1, expl_temp.f14,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[i],
                                geometry_data, geometry_size, subRoughs[i], true,
                                calcAllLayers1[i].f1, calcAllLayers2[i].f1,
                                &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &resolutionParams[i], &chis[i],
                                reflectivity[i].f1, simulation[i].f1, r1,
                                backgrounds[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(0);
          shiftedData[i].f1.set_size(r1.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int32_T>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0, 2);
      domainLayerSlds.set_size(unnamed_idx_0, 2);
      domainResampledLayers.set_size(unnamed_idx_0, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }
  }
}

// End of code generation (customLayers1.cpp)
