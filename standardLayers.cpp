//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardLayers.cpp
//
// Code generation for function 'standardLayers'
//

// Include files
#include "standardLayers.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "coreLayersCalculation.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void contrastCalculation(real_T backgroundParamIndex, real_T
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
      roughness, boolean_T calcSld, const ::coder::array<real_T, 2U>
      &contrastLayers, const ::coder::array<cell_wrap_32, 2U>
      &outParameterisedLayers, real_T *backgroundParamValue, real_T
      *qzshiftValue, real_T *scalefactorValue, real_T *bulkInValue, real_T
      *bulkOutValue, real_T *resolutionParamValue, real_T *chi, ::coder::array<
      real_T, 2U> &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::
      array<real_T, 2U> &shiftedData, real_T layerSld_data[], int32_T
      layerSld_size[2], ::coder::array<real_T, 2U> &sldProfile, ::coder::array<
      real_T, 2U> &resampledLayer);
  }
}

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void contrastCalculation(real_T backgroundParamIndex, real_T
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
      roughness, boolean_T calcSld, const ::coder::array<real_T, 2U>
      &contrastLayers, const ::coder::array<cell_wrap_32, 2U>
      &outParameterisedLayers, real_T *backgroundParamValue, real_T
      *qzshiftValue, real_T *scalefactorValue, real_T *bulkInValue, real_T
      *bulkOutValue, real_T *resolutionParamValue, real_T *chi, ::coder::array<
      real_T, 2U> &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::
      array<real_T, 2U> &shiftedData, real_T layerSld_data[], int32_T
      layerSld_size[2], ::coder::array<real_T, 2U> &sldProfile, ::coder::array<
      real_T, 2U> &resampledLayer)
    {
      ::coder::array<real_T, 2U> b_sldProfile;
      ::coder::array<real_T, 2U> layerSld;
      ::coder::array<real_T, 2U> thisContrastLayers_data;
      RATMainTLS *RATMainTLSThread;
      int32_T thisContrastLayers_size[2];
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      RATMainTLSThread = emlrtGetThreadStackData();

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(backgroundParamIndex, qzshiftIndex, scalefactorIndex, bulkInIndex,
               bulkOutIndex, resolutionParamIndex, backgroundParams, qzshifts,
               scalefactors, bulkIns, bulkOuts, resolutionParams,
               backgroundParamValue, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      allocateLayersForContrast(contrastLayers, outParameterisedLayers,
        useImaginary, RATMainTLSThread->f2.thisContrastLayers_data,
        thisContrastLayers_size);

      //  Call the core layers calculation
      thisContrastLayers_data.set(&RATMainTLSThread->f2.thisContrastLayers_data
        [0], thisContrastLayers_size[0], thisContrastLayers_size[1]);
      coreLayersCalculation(thisContrastLayers_data, roughness, geometry_data,
                            geometry_size, *bulkInValue, *bulkOutValue, resample,
                            calcSld, *scalefactorValue, *qzshiftValue,
                            dataPresent, data, dataLimits, simLimits,
                            repeatLayers, *backgroundParamValue,
                            *resolutionParamValue, contrastBackgroundActions,
                            nParams, parallel_data, parallel_size,
                            resampleParams, useImaginary, b_sldProfile,
                            reflectivity, simulation, shiftedData, layerSld,
                            resampledLayer, chi);
      sldProfile.set_size(b_sldProfile.size(0), b_sldProfile.size(1));
      loop_ub = b_sldProfile.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = b_sldProfile.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          sldProfile[i1 + sldProfile.size(0) * i] = b_sldProfile[i1 +
            b_sldProfile.size(0) * i];
        }
      }

      layerSld_size[0] = layerSld.size(0);
      layerSld_size[1] = layerSld.size(1);
      loop_ub = layerSld.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = layerSld.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          layerSld_data[i1 + layerSld_size[0] * i] = layerSld[i1 + layerSld.size
            (0) * i];
        }
      }
    }

    void standardLayers(const d_struct_T *problemStruct, const cell_11
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
      ::coder::array<cell_wrap_32, 2U> outParameterisedLayers;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      real_T b_tmp_data[4000];
      real_T tmp_data[4000];
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T d6;
      int32_T b_tmp_size[2];
      int32_T tmp_size[2];
      int32_T b_i;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i3;
      int32_T i4;
      int32_T nParams;
      boolean_T calcSld;
      boolean_T useImaginary;

      // all
      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'standardLayersCore', which carries out the calculation iteself.
      //  The core calculation is common for both standard and custom layers.
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

      //  Allocate the memory for the output arrays before the main loop
      //  end memory allocation
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct->params, problemCells->f6,
        outParameterisedLayers);

      //  Substrate roughness is always first parameter for standard layers
      i = static_cast<int32_T>(problemStruct->numberOfContrasts);
      subRoughs.set_size(i);
      for (b_i = 0; b_i < i; b_i++) {
        subRoughs[b_i] = problemStruct->params[0];
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T loop_ub;

        //  Loop over all the contrasts
        resampledLayers.set_size(i);
        sldProfiles.set_size(i);
        layerSlds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        backgroundParams.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        loop_ub = i - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r2,r3,d,d1,d2,d3,d4,d5,d6,b_tmp_data,b_tmp_size,c_i,c_loop_ub,i3,d_loop_ub,i4)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          contrastCalculation(problemStruct->contrastBackgroundParams[c_i],
                              problemStruct->contrastQzshifts[c_i],
                              problemStruct->contrastScalefactors[c_i],
                              problemStruct->contrastBulkIns[c_i],
                              problemStruct->contrastBulkOuts[c_i],
                              problemStruct->contrastResolutionParams[c_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->dataPresent[c_i], problemCells->
                              f2[c_i].f1, problemCells->f3[c_i].f1,
                              problemCells->f4[c_i].f1, problemCells->f1[c_i].f1,
                              problemStruct->contrastBackgroundActions[c_i],
                              static_cast<real_T>(nParams),
                              controls->parallel.data, controls->parallel.size,
                              controls->resampleParams, useImaginary,
                              problemStruct->resample[c_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, subRoughs[c_i],
                              calcSld, problemCells->f5[c_i].f1,
                              outParameterisedLayers, &d6, &d5, &d4, &d3, &d2,
                              &d1, &d, reflectivity[c_i].f1, simulation[c_i].f1,
                              r3, b_tmp_data, b_tmp_size, r2,
                              resampledLayers[c_i].f1);
          c_loop_ub = r3.size(1);
          shiftedData[c_i].f1.set_size(r3.size(0), r3.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r3.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r3[i4
                + r3.size(0) * i3];
            }
          }

          c_loop_ub = b_tmp_size[1];
          layerSlds[c_i].f1.set_size(b_tmp_size[0], b_tmp_size[1]);
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = b_tmp_size[0];
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layerSlds[c_i].f1[i4 + layerSlds[c_i].f1.size(0) * i3] =
                b_tmp_data[i4 + b_tmp_size[0] * i3];
            }
          }

          c_loop_ub = r2.size(0);
          sldProfiles[c_i].f1.set_size(r2.size(0), 2);
          for (i3 = 0; i3 < 2; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r2[i4
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
        //  Loop over all the contrasts
        resampledLayers.set_size(i);
        sldProfiles.set_size(i);
        layerSlds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        backgroundParams.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        for (b_i = 0; b_i < i; b_i++) {
          int32_T b_loop_ub;
          int32_T i1;
          int32_T i2;
          int32_T loop_ub;
          contrastCalculation(problemStruct->contrastBackgroundParams[b_i],
                              problemStruct->contrastQzshifts[b_i],
                              problemStruct->contrastScalefactors[b_i],
                              problemStruct->contrastBulkIns[b_i],
                              problemStruct->contrastBulkOuts[b_i],
                              problemStruct->contrastResolutionParams[b_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->dataPresent[b_i], problemCells->
                              f2[b_i].f1, problemCells->f3[b_i].f1,
                              problemCells->f4[b_i].f1, problemCells->f1[b_i].f1,
                              problemStruct->contrastBackgroundActions[b_i],
                              static_cast<real_T>(problemStruct->params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              controls->resampleParams,
                              problemStruct->useImaginary,
                              problemStruct->resample[b_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, subRoughs[b_i],
                              calcSld, problemCells->f5[b_i].f1,
                              outParameterisedLayers, &backgroundParams[b_i],
                              &qzshifts[b_i], &scalefactors[b_i], &bulkIns[b_i],
                              &bulkOuts[b_i], &resolutionParams[b_i], &chis[b_i],
                              reflectivity[b_i].f1, simulation[b_i].f1, r,
                              tmp_data, tmp_size, r1, resampledLayers[b_i].f1);
          loop_ub = r.size(1);
          shiftedData[b_i].f1.set_size(r.size(0), r.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] = r[i2
                + r.size(0) * i1];
            }
          }

          loop_ub = tmp_size[1];
          layerSlds[b_i].f1.set_size(tmp_size[0], tmp_size[1]);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tmp_size[0];
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
                tmp_data[i2 + tmp_size[0] * i1];
            }
          }

          loop_ub = r1.size(0);
          sldProfiles[b_i].f1.set_size(r1.size(0), 2);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r1[i2
                + r1.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (standardLayers.cpp)
