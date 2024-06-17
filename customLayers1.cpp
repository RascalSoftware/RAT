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
#include "RATMain_types.h"
#include "backSort.h"
#include "chiSquared.h"
#include "coreLayersCalculation.h"
#include "processCustomFunction2.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_39, 2U> &b, ::coder::array<
                   cell_wrap_10, 2U> &c);
  namespace domainsTF
  {
    static void b_contrastCalculation(real_T backgroundParamIndex, real_T
      qzshiftIndex, real_T scalefactorIndex, real_T bulkInIndex, real_T
      bulkOutIndex, real_T resolutionParamIndex, real_T domainRatioIndex, const ::
      coder::array<real_T, 2U> &backgroundParams, const ::coder::array<real_T,
      2U> &qzshifts, const ::coder::array<real_T, 2U> &scalefactors, const ::
      coder::array<real_T, 2U> &bulkIns, const ::coder::array<real_T, 2U>
      &bulkOuts, const ::coder::array<real_T, 2U> &resolutionParams, const ::
      coder::array<real_T, 2U> &domainRatios, real_T dataPresent, const ::coder::
      array<real_T, 2U> &data, const real_T dataLimits[2], const real_T
      simLimits[2], const real_T repeatLayers[2], real_T
      contrastBackgroundActions, real_T nParams, const char_T parallel_data[],
      const int32_T parallel_size[2], const real_T resampleParams[2], boolean_T
      useImaginary, real_T resample, const char_T geometry_data[], const int32_T
      geometry_size[2], real_T roughness, boolean_T calcSld, const ::coder::
      array<real_T, 2U> &calcAllLayers1, const ::coder::array<real_T, 2U>
      &calcAllLayers2, real_T *backgroundParamValue, real_T *qzshiftValue,
      real_T *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue,
      real_T *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, cell_wrap_10 layerSld[2], cell_wrap_10
      sldProfile[2], cell_wrap_10 resampledLayer[2]);
  }
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_39, 2U> &b, ::coder::array<
                   cell_wrap_10, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), 2);
    i = b.size(0) << 1;
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  namespace domainsTF
  {
    static void b_contrastCalculation(real_T backgroundParamIndex, real_T
      qzshiftIndex, real_T scalefactorIndex, real_T bulkInIndex, real_T
      bulkOutIndex, real_T resolutionParamIndex, real_T domainRatioIndex, const ::
      coder::array<real_T, 2U> &backgroundParams, const ::coder::array<real_T,
      2U> &qzshifts, const ::coder::array<real_T, 2U> &scalefactors, const ::
      coder::array<real_T, 2U> &bulkIns, const ::coder::array<real_T, 2U>
      &bulkOuts, const ::coder::array<real_T, 2U> &resolutionParams, const ::
      coder::array<real_T, 2U> &domainRatios, real_T dataPresent, const ::coder::
      array<real_T, 2U> &data, const real_T dataLimits[2], const real_T
      simLimits[2], const real_T repeatLayers[2], real_T
      contrastBackgroundActions, real_T nParams, const char_T parallel_data[],
      const int32_T parallel_size[2], const real_T resampleParams[2], boolean_T
      useImaginary, real_T resample, const char_T geometry_data[], const int32_T
      geometry_size[2], real_T roughness, boolean_T calcSld, const ::coder::
      array<real_T, 2U> &calcAllLayers1, const ::coder::array<real_T, 2U>
      &calcAllLayers2, real_T *backgroundParamValue, real_T *qzshiftValue,
      real_T *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue,
      real_T *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, cell_wrap_10 layerSld[2], cell_wrap_10
      sldProfile[2], cell_wrap_10 resampledLayer[2])
    {
      ::coder::array<real_T, 2U> a__5;
      ::coder::array<real_T, 2U> reflect1;
      ::coder::array<real_T, 2U> reflect2;
      ::coder::array<real_T, 2U> simul1;
      ::coder::array<real_T, 2U> simul2;
      ::coder::array<real_T, 2U> sldProfile1;
      ::coder::array<real_T, 2U> sldProfile2;
      cell_wrap_10 r;
      cell_wrap_10 r1;
      cell_wrap_10 r2;
      cell_wrap_10 r3;
      cell_wrap_10 r4;
      cell_wrap_10 r5;
      real_T a__4;
      real_T a__6;
      real_T domainRatios_tmp;
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(backgroundParamIndex, qzshiftIndex, scalefactorIndex, bulkInIndex,
               bulkOutIndex, resolutionParamIndex, backgroundParams, qzshifts,
               scalefactors, bulkIns, bulkOuts, resolutionParams,
               backgroundParamValue, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Call the core layers calculation - need to do this once for each
      //  domain
      nonPolarisedTF::coreLayersCalculation(calcAllLayers1, roughness,
        geometry_data, geometry_size, *bulkInValue, *bulkOutValue, resample,
        calcSld, *scalefactorValue, *qzshiftValue, dataPresent, data, dataLimits,
        simLimits, repeatLayers, *backgroundParamValue, *resolutionParamValue,
        contrastBackgroundActions, nParams, parallel_data, parallel_size,
        resampleParams, useImaginary, sldProfile1, reflect1, simul1, shiftedData,
        r.f1, r1.f1, &a__4);
      nonPolarisedTF::coreLayersCalculation(calcAllLayers2, roughness,
        geometry_data, geometry_size, *bulkInValue, *bulkOutValue, resample,
        calcSld, *scalefactorValue, *qzshiftValue, dataPresent, data, dataLimits,
        simLimits, repeatLayers, *backgroundParamValue, *resolutionParamValue,
        contrastBackgroundActions, nParams, parallel_data, parallel_size,
        resampleParams, useImaginary, sldProfile2, reflect2, simul2, a__5, r2.f1,
        r3.f1, &a__6);

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
      r4.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
      loop_ub = sldProfile1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r4.f1[i1 + r4.f1.size(0) * i] = sldProfile1[i1 + sldProfile1.size(0) *
            i];
        }
      }

      r5.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
      loop_ub = sldProfile2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r5.f1[i1 + r5.f1.size(0) * i] = sldProfile2[i1 + sldProfile2.size(0) *
            i];
        }
      }

      sldProfile[0] = r4;
      sldProfile[1] = r5;
      layerSld[0] = r;
      layerSld[1] = r2;
      resampledLayer[0] = r1;
      resampledLayer[1] = r3;
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
                        cell_wrap_10, 2U> &domainLayerSlds, ::coder::array<
                        cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                        cell_wrap_10, 2U> &domainResampledLayers, ::coder::array<
                        real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_10, 2U> calcAllLayers;
      ::coder::array<cell_wrap_10, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_10, 1U> calcAllLayers2;
      ::coder::array<cell_wrap_39, 2U> r;
      ::coder::array<cell_wrap_52, 1U> layerSlds;
      ::coder::array<cell_wrap_52, 1U> resampledLayers;
      ::coder::array<cell_wrap_52, 1U> sldProfiles;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T d6;
      real_T numberOfContrasts;
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      int32_T ub_loop;
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

      //  Pre-Allocation of output arrays...
      ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts);
      calcAllLayers1.set_size(ub_loop);
      calcAllLayers2.set_size(ub_loop);
      for (i = 0; i < ub_loop; i++) {
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
        problemStruct->params, problemStruct->useImaginary, r, subRoughs);
      cast(r, calcAllLayers);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        int32_T i2;
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
        resampledLayers.set_size(ub_loop);
        sldProfiles.set_size(ub_loop);
        layerSlds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        backgroundParams.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        domainResampledLayers.set_size(ub_loop, 2);
        domainLayerSlds.set_size(ub_loop, 2);
        domainSldProfiles.set_size(ub_loop, 2);
        ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,d,d1,d2,d3,d4,d5,d6,c_i,c_loop_ub,i3,d_loop_ub,i4)

        for (c_i = 0; c_i <= ub_loop; c_i++) {
          b_contrastCalculation(problemStruct->contrastBackgroundParams[c_i],
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
                                f1[c_i].f1,
                                problemStruct->contrastBackgroundActions[c_i],
                                static_cast<real_T>(nParams),
                                controls->parallel.data, controls->parallel.size,
                                controls->resampleParams, useImaginary,
                                problemStruct->resample[c_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[c_i],
                                calcSld, calcAllLayers1[c_i].f1,
                                calcAllLayers2[c_i].f1, &d6, &d5, &d4, &d3, &d2,
                                &d1, &d, reflectivity[c_i].f1, simulation[c_i].
                                f1, r2, layerSlds[c_i].f1, sldProfiles[c_i].f1,
                                resampledLayers[c_i].f1);
          c_loop_ub = r2.size(1);
          shiftedData[c_i].f1.set_size(r2.size(0), r2.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r2.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r2[i4
                + r2.size(0) * i3];
            }
          }

          backgroundParams[c_i] = d6;
          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        resampledLayers.set_size(ub_loop);
        sldProfiles.set_size(ub_loop);
        layerSlds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        backgroundParams.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        domainResampledLayers.set_size(ub_loop, 2);
        domainLayerSlds.set_size(ub_loop, 2);
        domainSldProfiles.set_size(ub_loop, 2);
        for (i = 0; i < ub_loop; i++) {
          b_contrastCalculation(problemStruct->contrastBackgroundParams[i],
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
                                problemStruct->contrastBackgroundActions[i],
                                static_cast<real_T>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                controls->resampleParams,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i],
                                calcSld, calcAllLayers1[i].f1, calcAllLayers2[i]
                                .f1, &backgroundParams[i], &qzshifts[i],
                                &scalefactors[i], &bulkIns[i], &bulkOuts[i],
                                &resolutionParams[i], &chis[i], reflectivity[i].
                                f1, simulation[i].f1, r1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(1);
          shiftedData[i].f1.set_size(r1.size(0), r1.size(1));
          for (b_i = 0; b_i < loop_ub; b_i++) {
            b_loop_ub = r1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      ub_loop = static_cast<int32_T>(numberOfContrasts);
      for (i = 0; i < ub_loop; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(1);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0),
          sldProfiles[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = sldProfiles[i].f1[0].f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i].f1[i1 + domainSldProfiles[i].f1.size(0) * b_i] =
              sldProfiles[i].f1[0].f1[i1 + sldProfiles[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = sldProfiles[i].f1[1].f1.size(1);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), sldProfiles[i].f1[1].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i1 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * b_i]
              = sldProfiles[i].f1[1].f1[i1 + sldProfiles[i].f1[1].f1.size(0) *
              b_i];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            domainLayerSlds[i].f1[i1 + domainLayerSlds[i].f1.size(0) * b_i] =
              layerSlds[i].f1[0].f1[i1 + layerSlds[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i1 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * b_i] =
              layerSlds[i].f1[1].f1[i1 + layerSlds[i].f1[1].f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size(0)
              * b_i] = resampledLayers[i].f1[0].f1[i1 + resampledLayers[i].f1[0]
              .f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i1 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * b_i] = resampledLayers[i].f1[1].f1[i1 + resampledLayers[i].f1[1]
              .f1.size(0) * b_i];
          }
        }
      }
    }
  }
}

// End of code generation (customLayers1.cpp)
