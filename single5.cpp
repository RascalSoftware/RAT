//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// single5.cpp
//
// Code generation for function 'single5'
//

// Include files
#include "single5.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "applyBackgroundCorrection.h"
#include "averageReflectivity.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "processCustomFunction3.h"
#include "resampleLayers.h"
#include "resampleLayersReIm.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    namespace customXY
    {
      void b_single(const f_struct_T *problemStruct, const cell_11 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &outSsubs, ::coder::array<real_T, 1U> &backgroundParams, ::
                    coder::array<real_T, 1U> &qzshifts, ::coder::array<real_T,
                    1U> &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                    coder::array<real_T, 1U> &bulkOuts, ::coder::array<real_T,
                    1U> &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                    coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                    cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_10,
                    1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
                    &layerSlds, ::coder::array<cell_wrap_10, 2U>
                    &domainSldProfiles, ::coder::array<cell_wrap_10, 2U>
                    &allLayers, ::coder::array<real_T, 1U> &allRoughs)
      {
        ::coder::array<cell_wrap_39, 1U> tempAllLayers;
        ::coder::array<cell_wrap_39, 1U> tempLayerSlds;
        ::coder::array<cell_wrap_39, 1U> tempSldProfiles;
        ::coder::array<real_T, 2U> b_domainSldProfiles;
        ::coder::array<real_T, 2U> b_problemCells;
        ::coder::array<real_T, 2U> c_domainSldProfiles;
        ::coder::array<real_T, 2U> r;
        ::coder::array<real_T, 2U> r3;
        ::coder::array<real_T, 2U> r8;
        ::coder::array<real_T, 2U> reflect1;
        ::coder::array<real_T, 2U> reflect2;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul1;
        ::coder::array<real_T, 2U> simul2;
        ::coder::array<real_T, 2U> totReflect;
        cell_wrap_10 r1;
        cell_wrap_10 r2;
        cell_wrap_10 r4;
        cell_wrap_10 r5;
        cell_wrap_10 r6;
        cell_wrap_10 r7;
        int32_T b_i;
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T i2;
        int32_T loop_ub;
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
        // Pre-Allocation...
        i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgroundParams.set_size(i);

        //  Resampling parameters
        useImaginary = problemStruct->useImaginary;

        //  Default for compile.
        processCustomFunction(problemStruct->contrastBulkIns,
                              problemStruct->contrastBulkOuts,
                              problemStruct->bulkIn, problemStruct->bulkOut,
                              problemStruct->contrastCustomFiles,
                              problemStruct->numberOfContrasts,
                              problemCells->f14, problemStruct->params,
                              domainSldProfiles, allRoughs);
        outSsubs.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        tempLayerSlds.set_size(i);
        tempAllLayers.set_size(i);
        tempSldProfiles.set_size(i);
        shiftedData.set_size(i);
        reflectivity.set_size(i);
        simulation.set_size(i);
        chis.set_size(i);
        layerSlds.set_size(i, 2);
        for (b_i = 0; b_i < i; b_i++) {
          outSsubs[b_i] = allRoughs[b_i];
          backSort(problemStruct->contrastBackgrounds[b_i],
                   problemStruct->contrastQzshifts[b_i],
                   problemStruct->contrastScalefactors[b_i],
                   problemStruct->contrastBulkIns[b_i],
                   problemStruct->contrastBulkOuts[b_i],
                   problemStruct->contrastResolutions[b_i],
                   problemStruct->backgroundParams, problemStruct->qzshifts,
                   problemStruct->scalefactors, problemStruct->bulkIn,
                   problemStruct->bulkOut, problemStruct->resolutionParams,
                   &backgroundParams[b_i], &qzshifts[b_i], &scalefactors[b_i],
                   &bulkIns[b_i], &bulkOuts[b_i], &resolutionParams[b_i]);

          //  Get the domain ratio for this contrast
          //  Resample the sld profiles
          if (!useImaginary) {
            resampleLayers(domainSldProfiles[b_i].f1, controls->resamPars, r);
            r1.f1.set_size(r.size(0), 3);
            loop_ub = r.size(0);
            for (i1 = 0; i1 < 3; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                r1.f1[i2 + r1.f1.size(0) * i1] = r[i2 + r.size(0) * i1];
              }
            }

            resampleLayers(domainSldProfiles[b_i + domainSldProfiles.size(0)].f1,
                           controls->resamPars, r);
            r2.f1.set_size(r.size(0), 3);
            loop_ub = r.size(0);
            for (i1 = 0; i1 < 3; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                r2.f1[i2 + r2.f1.size(0) * i1] = r[i2 + r.size(0) * i1];
              }
            }
          } else {
            loop_ub = domainSldProfiles[b_i].f1.size(0);
            b_domainSldProfiles.set_size(domainSldProfiles[b_i].f1.size(0), 2);
            for (i1 = 0; i1 < 2; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                b_domainSldProfiles[i2 + b_domainSldProfiles.size(0) * i1] =
                  domainSldProfiles[b_i].f1[i2 + domainSldProfiles[b_i].f1.size
                  (0) * i1];
              }
            }

            loop_ub = domainSldProfiles[b_i].f1.size(0);
            c_domainSldProfiles.set_size(domainSldProfiles[b_i].f1.size(0), 2);
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_domainSldProfiles[i1] = domainSldProfiles[b_i].f1[i1];
              c_domainSldProfiles[i1 + c_domainSldProfiles.size(0)] =
                domainSldProfiles[b_i].f1[i1 + domainSldProfiles[b_i].f1.size(0)
                * 2];
            }

            b_resampleLayersReIm(b_domainSldProfiles, c_domainSldProfiles,
                                 controls->resamPars, r3);
            r1.f1.set_size(r3.size(0), 4);
            loop_ub = r3.size(0);
            for (i1 = 0; i1 < 4; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                r1.f1[i2 + r1.f1.size(0) * i1] = r3[i2 + r3.size(0) * i1];
              }
            }

            loop_ub = domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size
              (0);
            b_domainSldProfiles.set_size(domainSldProfiles[b_i +
              domainSldProfiles.size(0)].f1.size(0), 2);
            for (i1 = 0; i1 < 2; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                b_domainSldProfiles[i2 + b_domainSldProfiles.size(0) * i1] =
                  domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[i2 +
                  domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) *
                  i1];
              }
            }

            loop_ub = domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size
              (0);
            c_domainSldProfiles.set_size(domainSldProfiles[b_i +
              domainSldProfiles.size(0)].f1.size(0), 2);
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_domainSldProfiles[i1] = domainSldProfiles[b_i +
                domainSldProfiles.size(0)].f1[i1];
              c_domainSldProfiles[i1 + c_domainSldProfiles.size(0)] =
                domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[i1 +
                domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) *
                2];
            }

            b_resampleLayersReIm(b_domainSldProfiles, c_domainSldProfiles,
                                 controls->resamPars, r3);
            r2.f1.set_size(r3.size(0), 4);
            loop_ub = r3.size(0);
            for (i1 = 0; i1 < 4; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                r2.f1[i2 + r2.f1.size(0) * i1] = r3[i2 + r3.size(0) * i1];
              }
            }
          }

          tempLayerSlds[b_i].f1[0] = r1;
          tempLayerSlds[b_i].f1[1] = r2;
          loop_ub = r1.f1.size(1);
          r4.f1.set_size(r1.f1.size(0), r1.f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r1.f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r4.f1[i2 + r4.f1.size(0) * i1] = r1.f1[i2 + r1.f1.size(0) * i1];
            }
          }

          loop_ub = r2.f1.size(1);
          r5.f1.set_size(r2.f1.size(0), r2.f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r2.f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r5.f1[i2 + r5.f1.size(0) * i1] = r2.f1[i2 + r2.f1.size(0) * i1];
            }
          }

          tempAllLayers[b_i].f1[0] = r4;
          tempAllLayers[b_i].f1[1] = r5;
          r6.f1.set_size(domainSldProfiles[b_i].f1.size(0),
                         domainSldProfiles[b_i].f1.size(1));
          loop_ub = domainSldProfiles[b_i].f1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = domainSldProfiles[b_i].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r6.f1[i2 + r6.f1.size(0) * i1] = domainSldProfiles[b_i].f1[i2 +
                domainSldProfiles[b_i].f1.size(0) * i1];
            }
          }

          r7.f1.set_size(domainSldProfiles[b_i + domainSldProfiles.size(0)].
                         f1.size(0), domainSldProfiles[b_i +
                         domainSldProfiles.size(0)].f1.size(1));
          loop_ub = domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = domainSldProfiles[b_i + domainSldProfiles.size(0)].
              f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r7.f1[i2 + r7.f1.size(0) * i1] = domainSldProfiles[b_i +
                domainSldProfiles.size(0)].f1[i2 + domainSldProfiles[b_i +
                domainSldProfiles.size(0)].f1.size(0) * i1];
            }
          }

          tempSldProfiles[b_i].f1[0] = r6;
          tempSldProfiles[b_i].f1[1] = r7;
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

          r8.set_size(r1.f1.size(0), r1.f1.size(1));
          loop_ub = r1.f1.size(1) - 1;
          for (i1 = 0; i1 <= loop_ub; i1++) {
            b_loop_ub = r1.f1.size(0) - 1;
            for (i2 = 0; i2 <= b_loop_ub; i2++) {
              r8[i2 + r8.size(0) * i1] = r1.f1[i2 + r1.f1.size(0) * i1];
            }
          }

          callReflectivity(bulkIns[b_i], bulkOuts[b_i], problemCells->f4[b_i].f1,
                           problemCells->f1[b_i].f1, shiftedDat, r8,
                           allRoughs[b_i], resolutionParams[b_i], useImaginary,
                           reflect1, simul1);
          r8.set_size(r2.f1.size(0), r2.f1.size(1));
          loop_ub = r2.f1.size(1) - 1;
          for (i1 = 0; i1 <= loop_ub; i1++) {
            b_loop_ub = r2.f1.size(0) - 1;
            for (i2 = 0; i2 <= b_loop_ub; i2++) {
              r8[i2 + r8.size(0) * i1] = r2.f1[i2 + r2.f1.size(0) * i1];
            }
          }

          callReflectivity(bulkIns[b_i], bulkOuts[b_i], problemCells->f4[b_i].f1,
                           problemCells->f1[b_i].f1, shiftedDat, r8,
                           allRoughs[b_i], resolutionParams[b_i], useImaginary,
                           reflect2, simul2);
          applyBackgroundCorrection(reflect1, simul1, shiftedDat,
            backgroundParams[b_i], problemStruct->contrastBackgroundsType[b_i]);
          applyBackgroundCorrection(reflect2, simul2, shiftedDat,
            backgroundParams[b_i], problemStruct->contrastBackgroundsType[b_i]);

          //  Calculate the average reflectivities....
          averageReflectivity(reflect1, reflect2, simul1, simul2,
                              problemStruct->domainRatio[static_cast<int32_T>
                              (problemStruct->contrastDomainRatios[b_i]) - 1],
                              totReflect, simulation[b_i].f1);
          loop_ub = totReflect.size(0);
          reflectivity[b_i].f1.set_size(totReflect.size(0), 2);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              reflectivity[b_i].f1[i2 + reflectivity[b_i].f1.size(0) * i1] =
                totReflect[i2 + totReflect.size(0) * i1];
            }
          }

          if (problemStruct->dataPresent[b_i] != 0.0) {
            chis[b_i] = chiSquared(shiftedDat, totReflect, static_cast<real_T>
              (problemStruct->params.size(1)));
          } else {
            chis[b_i] = 0.0;
          }
        }

        allLayers.set_size(i, 2);
        for (b_i = 0; b_i < i; b_i++) {
          loop_ub = tempSldProfiles[b_i].f1[0].f1.size(1);
          domainSldProfiles[b_i].f1.set_size(tempSldProfiles[b_i].f1[0].f1.size
            (0), tempSldProfiles[b_i].f1[0].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempSldProfiles[b_i].f1[0].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              domainSldProfiles[b_i].f1[i2 + domainSldProfiles[b_i].f1.size(0) *
                i1] = tempSldProfiles[b_i].f1[0].f1[i2 + tempSldProfiles[b_i]
                .f1[0].f1.size(0) * i1];
            }
          }

          loop_ub = tempSldProfiles[b_i].f1[1].f1.size(1);
          domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.set_size
            (tempSldProfiles[b_i].f1[1].f1.size(0), tempSldProfiles[b_i].f1[1].
             f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempSldProfiles[b_i].f1[1].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[i2 +
                domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) *
                i1] = tempSldProfiles[b_i].f1[1].f1[i2 + tempSldProfiles[b_i]
                .f1[1].f1.size(0) * i1];
            }
          }

          loop_ub = tempAllLayers[b_i].f1[0].f1.size(1);
          allLayers[b_i].f1.set_size(tempAllLayers[b_i].f1[0].f1.size(0),
            tempAllLayers[b_i].f1[0].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempAllLayers[b_i].f1[0].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              allLayers[b_i].f1[i2 + allLayers[b_i].f1.size(0) * i1] =
                tempAllLayers[b_i].f1[0].f1[i2 + tempAllLayers[b_i].f1[0].
                f1.size(0) * i1];
            }
          }

          loop_ub = tempAllLayers[b_i].f1[1].f1.size(1);
          allLayers[b_i + allLayers.size(0)].f1.set_size(tempAllLayers[b_i].f1[1]
            .f1.size(0), tempAllLayers[b_i].f1[1].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempAllLayers[b_i].f1[1].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              allLayers[b_i + allLayers.size(0)].f1[i2 + allLayers[b_i +
                allLayers.size(0)].f1.size(0) * i1] = tempAllLayers[b_i].f1[1].
                f1[i2 + tempAllLayers[b_i].f1[1].f1.size(0) * i1];
            }
          }

          loop_ub = tempLayerSlds[b_i].f1[0].f1.size(1);
          layerSlds[b_i].f1.set_size(tempLayerSlds[b_i].f1[0].f1.size(0),
            tempLayerSlds[b_i].f1[0].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempLayerSlds[b_i].f1[0].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
                tempLayerSlds[b_i].f1[0].f1[i2 + tempLayerSlds[b_i].f1[0].
                f1.size(0) * i1];
            }
          }

          loop_ub = tempLayerSlds[b_i].f1[1].f1.size(1);
          layerSlds[b_i + layerSlds.size(0)].f1.set_size(tempLayerSlds[b_i].f1[1]
            .f1.size(0), tempLayerSlds[b_i].f1[1].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempLayerSlds[b_i].f1[1].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i + layerSlds.size(0)].f1[i2 + layerSlds[b_i +
                layerSlds.size(0)].f1.size(0) * i1] = tempLayerSlds[b_i].f1[1].
                f1[i2 + tempLayerSlds[b_i].f1[1].f1.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (single5.cpp)
