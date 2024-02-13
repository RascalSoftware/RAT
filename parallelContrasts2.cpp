//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parallelContrasts2.cpp
//
// Code generation for function 'parallelContrasts2'
//

// Include files
#include "parallelContrasts2.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "processCustomFunction1.h"
#include "resampleLayers.h"
#include "resampleLayersReIm.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace customXY
    {
      void parallelContrasts(const d_struct_T *problemStruct, const cell_11
        *problemCells, const struct2_T *controls, ::coder::array<real_T, 1U>
        &outSsubs, ::coder::array<real_T, 1U> &backgroundParams, ::coder::array<
        real_T, 1U> &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::coder::
        array<real_T, 1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
        coder::array<real_T, 1U> &resolutionParams, ::coder::array<real_T, 1U>
        &chis, ::coder::array<cell_wrap_20, 1U> &reflectivity, ::coder::array<
        cell_wrap_20, 1U> &simulation, ::coder::array<cell_wrap_8, 1U>
        &shiftedData, ::coder::array<cell_wrap_8, 1U> &layerSlds, ::coder::array<
        cell_wrap_8, 1U> &sldProfiles, ::coder::array<cell_wrap_8, 1U>
        &allLayers, ::coder::array<real_T, 1U> &allRoughs)
      {
        ::coder::array<real_T, 2U> b_problemCells;
        ::coder::array<real_T, 2U> b_sldProfiles;
        ::coder::array<real_T, 2U> layerSld;
        ::coder::array<real_T, 2U> r;
        ::coder::array<real_T, 2U> r1;
        ::coder::array<real_T, 2U> reSLD;
        ::coder::array<real_T, 2U> reflect;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul;
        real_T d;
        real_T d1;
        real_T d2;
        real_T d3;
        real_T d4;
        real_T d5;
        int32_T b_i;
        int32_T b_loop_ub;
        int32_T i1;
        int32_T i2;
        int32_T loop_ub;
        int32_T loop_ub_tmp;
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
        //      * allData: Array of all the data arrays.
        //      * dataLimits: Min max limits in q for the data arrays.
        //      * simLimits: Limits in Q for the reflectivity simulations.
        //      * layersDetails: Master array of all available layers.
        //      * contrastLayers: Which specific combination of arrays are needed for each contrast.
        //      * customFiles:Filenames and path for any custom files used.
        //         % Layers details N/A
        //  Extract individual parameters from problemStruct
        // Extract individual parameters from problem
        nParams = problemStruct->params.size(1);

        // Pre-Allocation...
        loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgroundParams.set_size(loop_ub_tmp);
        outSsubs.set_size(loop_ub_tmp);
        for (int32_T i{0}; i < loop_ub_tmp; i++) {
          outSsubs[i] = 0.0;
        }

        //  Resampling parameters
        useImaginary = problemStruct->useImaginary;
        processCustomFunction(problemStruct->contrastBulkIns,
                              problemStruct->contrastBulkOuts,
                              problemStruct->bulkIn, problemStruct->bulkOut,
                              problemStruct->contrastCustomFiles,
                              problemStruct->numberOfContrasts,
                              problemCells->f14, problemStruct->params,
                              sldProfiles, allRoughs);
        qzshifts.set_size(loop_ub_tmp);
        scalefactors.set_size(loop_ub_tmp);
        bulkIns.set_size(loop_ub_tmp);
        bulkOuts.set_size(loop_ub_tmp);
        resolutionParams.set_size(loop_ub_tmp);
        layerSlds.set_size(loop_ub_tmp);
        allLayers.set_size(loop_ub_tmp);
        shiftedData.set_size(loop_ub_tmp);
        chis.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        loop_ub_tmp--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,b_sldProfiles,b_problemCells,r1,reSLD,layerSld,reflect,simul,shiftedDat,d,d1,d2,d3,d4,d5,b_i,loop_ub,i1,i2,b_loop_ub)

        for (b_i = 0; b_i <= loop_ub_tmp; b_i++) {
          backSort(problemStruct->contrastBackgrounds[b_i],
                   problemStruct->contrastQzshifts[b_i],
                   problemStruct->contrastScalefactors[b_i],
                   problemStruct->contrastBulkIns[b_i],
                   problemStruct->contrastBulkOuts[b_i],
                   problemStruct->contrastResolutions[b_i],
                   problemStruct->backgroundParams, problemStruct->qzshifts,
                   problemStruct->scalefactors, problemStruct->bulkIn,
                   problemStruct->bulkOut, problemStruct->resolutionParams, &d5,
                   &d4, &d3, &d2, &d1, &d);
          backgroundParams[b_i] = d5;
          qzshifts[b_i] = d4;
          scalefactors[b_i] = d3;
          bulkIns[b_i] = d2;
          bulkOuts[b_i] = d1;
          resolutionParams[b_i] = d;

          //  Resample the layers
          if (!useImaginary) {
            resampleLayers(sldProfiles[b_i].f1, controls->resamPars, r1);
            layerSld.set_size(r1.size(0), 3);
            loop_ub = r1.size(0);
            for (i1 = 0; i1 < 3; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                layerSld[i2 + layerSld.size(0) * i1] = r1[i2 + r1.size(0) * i1];
              }
            }
          } else {
            loop_ub = sldProfiles[b_i].f1.size(0);
            reSLD.set_size(sldProfiles[b_i].f1.size(0), 2);
            for (i1 = 0; i1 < 2; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                reSLD[i2 + reSLD.size(0) * i1] = sldProfiles[b_i].f1[i2 +
                  sldProfiles[b_i].f1.size(0) * i1];
              }
            }

            loop_ub = sldProfiles[b_i].f1.size(0);
            b_sldProfiles.set_size(sldProfiles[b_i].f1.size(0), 2);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_sldProfiles[i1] = sldProfiles[b_i].f1[i1];
              b_sldProfiles[i1 + b_sldProfiles.size(0)] = sldProfiles[b_i].f1[i1
                + sldProfiles[b_i].f1.size(0) * 2];
            }

            b_resampleLayersReIm(reSLD, b_sldProfiles, controls->resamPars, r);
            layerSld.set_size(r.size(0), 4);
            loop_ub = r.size(0);
            for (i1 = 0; i1 < 4; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                layerSld[i2 + layerSld.size(0) * i1] = r[i2 + r.size(0) * i1];
              }
            }
          }

          layerSlds[b_i].f1.set_size(layerSld.size(0), layerSld.size(1));
          loop_ub = layerSld.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = layerSld.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
                layerSld[i2 + layerSld.size(0) * i1];
            }
          }

          allLayers[b_i].f1.set_size(layerSld.size(0), layerSld.size(1));
          loop_ub = layerSld.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = layerSld.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              allLayers[b_i].f1[i2 + allLayers[b_i].f1.size(0) * i1] =
                layerSld[i2 + layerSld.size(0) * i1];
            }
          }

          b_problemCells.set_size(problemCells->f2[problemCells->f2.size(0) *
            b_i].f1.size(0), problemCells->f2[problemCells->f2.size(0) * b_i].
            f1.size(1));
          loop_ub = problemCells->f2[b_i].f1.size(1) - 1;
          for (i1 = 0; i1 <= loop_ub; i1++) {
            b_loop_ub = problemCells->f2[b_i].f1.size(0) - 1;
            for (i2 = 0; i2 <= b_loop_ub; i2++) {
              b_problemCells[i2 + b_problemCells.size(0) * i1] =
                problemCells->f2[b_i].f1[i2 + problemCells->f2[b_i].f1.size(0) *
                i1];
            }
          }

          shiftData(scalefactors[b_i], qzshifts[b_i], problemStruct->
                    dataPresent[b_i], b_problemCells, problemCells->f3[b_i].f1,
                    problemCells->f4[b_i].f1, shiftedDat);
          shiftedData[b_i].f1.set_size(shiftedDat.size(0), shiftedDat.size(1));
          loop_ub = shiftedDat.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = shiftedDat.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] =
                shiftedDat[i2 + shiftedDat.size(0) * i1];
            }
          }

          callReflectivity(bulkIns[b_i], bulkOuts[b_i], problemCells->f4[b_i].f1,
                           problemCells->f1[b_i].f1, shiftedDat, layerSld, 0.0,
                           resolutionParams[b_i], useImaginary, reflect, simul);
          applyBackgroundCorrection(reflect, simul, shiftedDat,
            backgroundParams[b_i], problemStruct->contrastBackgroundsType[b_i]);
          loop_ub = reflect.size(0);
          reflectivity[b_i].f1.set_size(reflect.size(0), 2);
          b_loop_ub = simul.size(0);
          simulation[b_i].f1.set_size(simul.size(0), 2);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              reflectivity[b_i].f1[i2 + reflectivity[b_i].f1.size(0) * i1] =
                reflect[i2 + reflect.size(0) * i1];
            }

            for (i2 = 0; i2 < b_loop_ub; i2++) {
              simulation[b_i].f1[i2 + simulation[b_i].f1.size(0) * i1] =
                simul[i2 + simul.size(0) * i1];
            }
          }

          if (problemStruct->dataPresent[b_i] != 0.0) {
            chis[b_i] = chiSquared(shiftedDat, reflect, static_cast<real_T>
              (nParams));
          } else {
            chis[b_i] = 0.0;
          }
        }
      }
    }
  }
}

// End of code generation (parallelContrasts2.cpp)
