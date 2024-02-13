//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parallelContrasts.cpp
//
// Code generation for function 'parallelContrasts'
//

// Include files
#include "parallelContrasts.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "coreLayersCalculation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace standardLayers
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
        ::coder::array<cell_wrap_22, 2U> outParameterisedLayers;
        ::coder::array<real_T, 2U> reflect;
        ::coder::array<real_T, 2U> resampledLayers;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul;
        ::coder::array<real_T, 2U> sldProfile;
        ::coder::array<real_T, 2U> thisContrastLayers_data;
        RATMainTLS *RATMainTLSThread;
        real_T thisBackground;
        real_T thisBulkIn;
        real_T thisBulkOut;
        real_T thisChiSquared;
        real_T thisQzshift;
        real_T thisResol;
        real_T thisScalefactor;
        real_T thisSsubs;
        int32_T thisContrastLayers_size[2];
        int32_T b_i;
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub;
        int32_T nParams;
        int32_T ub_loop;
        boolean_T calcSld;
        boolean_T useImaginary;
        RATMainTLSThread = emlrtGetThreadStackData();

        //  Standard Layers calculation paralelised over the outer loop
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
        //      * allData: Array of all the data arrays.
        //      * dataLimits: Min max limits in q for the data arrays.
        //      * simLimits: Limits in Q for the reflectivity simulations.
        //      * layersDetails: Master array of all available layers.
        //      * contrastLayers: Which specific combination of arrays are needed for each contrast.
        //      * customFiles:Filenames and path for any custom files used.
        //  Extract individual parameters from problemStruct
        // Extract individual parameters from problem
        nParams = problemStruct->params.size(1);
        calcSld = controls->calcSldDuringFit;
        useImaginary = problemStruct->useImaginary;

        //  Allocate the memory for the output arrays before the main loop
        backgroundParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));

        //  end memory allocation.
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only needs
        //  to be done once, and so is done outside the contrasts loop
        allocateParamsToLayers(problemStruct->params, problemCells->f6,
          outParameterisedLayers);

        //  Resample parameters if required
        //  Loop over all the contrasts
        outSsubs.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        sldProfiles.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        reflectivity.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        simulation.set_size(static_cast<int32_T>
                            (problemStruct->numberOfContrasts));
        shiftedData.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        layerSlds.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        chis.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        scalefactors.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        bulkIns.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        bulkOuts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        resolutionParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        allRoughs.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        allLayers.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(RATMainTLSThread,sldProfile,reflect,simul,shiftedDat,resampledLayers,thisSsubs,thisChiSquared,thisContrastLayers_size,thisResol,thisBulkOut,thisBulkIn,thisScalefactor,thisQzshift,thisBackground,i,loop_ub,b_i,b_loop_ub,i1) \
 firstprivate(thisContrastLayers_data)

        {
          RATMainTLSThread = emlrtGetThreadStackData();

#pragma omp for nowait

          for (i = 0; i <= ub_loop; i++) {
            //  Extract the relevant parameter values for this contrast
            //  from the input arrays.
            //  First need to decide which values of the backgrounds, scalefactors
            //  data shifts and bulk contrasts are associated with this contrast
            backSort(problemStruct->contrastBackgrounds[i],
                     problemStruct->contrastQzshifts[i],
                     problemStruct->contrastScalefactors[i],
                     problemStruct->contrastBulkIns[i],
                     problemStruct->contrastBulkOuts[i],
                     problemStruct->contrastResolutions[i],
                     problemStruct->backgroundParams, problemStruct->qzshifts,
                     problemStruct->scalefactors, problemStruct->bulkIn,
                     problemStruct->bulkOut, problemStruct->resolutionParams,
                     &thisBackground, &thisQzshift, &thisScalefactor,
                     &thisBulkIn, &thisBulkOut, &thisResol);

            //  Also need to determine which layers from the overall layers list
            //  are required for this contrast, and put them in the correct order
            //  according to geometry
            allocateLayersForContrast(problemCells->f5[i].f1,
              outParameterisedLayers, useImaginary,
              RATMainTLSThread->f2.thisContrastLayers_data,
              thisContrastLayers_size);

            //  For the other parameters, we extract the correct ones from the input
            //  arrays
            //  Substrate roughness is always first parameter for standard layers
            //  Now call the core layers reflectivity calculation
            //  In this case we are single cored, so we do not parallelise over
            //  points
            //  Call the core layers calculation
            thisContrastLayers_data.set
              (&RATMainTLSThread->f2.thisContrastLayers_data[0],
               thisContrastLayers_size[0], thisContrastLayers_size[1]);
            coreLayersCalculation(thisContrastLayers_data, problemStruct->
                                  params[0], problemStruct->geometry.data,
                                  problemStruct->geometry.size, thisBulkIn,
                                  thisBulkOut, problemStruct->resample[i],
                                  calcSld, thisScalefactor, thisQzshift,
                                  problemStruct->dataPresent[i],
                                  problemCells->f2[i].f1, problemCells->f3[i].f1,
                                  problemCells->f4[i].f1, problemCells->f1[i].f1,
                                  thisBackground, thisResol,
                                  problemStruct->contrastBackgroundsType[i],
                                  static_cast<real_T>(nParams),
                                  controls->resamPars, useImaginary, sldProfile,
                                  reflect, simul, shiftedDat, layerSlds[i].f1,
                                  resampledLayers, &thisChiSquared, &thisSsubs);

            //  Store returned values for this contrast in the output arrays.
            //  As well as the calculated profiles, we also store a record of
            //  the other values (background, scalefactors etc) for each contrast
            //  for future use.
            outSsubs[i] = thisSsubs;
            loop_ub = sldProfile.size(1);
            sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
            for (b_i = 0; b_i < loop_ub; b_i++) {
              b_loop_ub = sldProfile.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i] =
                  sldProfile[i1 + sldProfile.size(0) * b_i];
              }
            }

            loop_ub = reflect.size(0);
            reflectivity[i].f1.set_size(reflect.size(0), 2);
            b_loop_ub = simul.size(0);
            simulation[i].f1.set_size(simul.size(0), 2);
            for (b_i = 0; b_i < 2; b_i++) {
              for (i1 = 0; i1 < loop_ub; i1++) {
                reflectivity[i].f1[i1 + reflectivity[i].f1.size(0) * b_i] =
                  reflect[i1 + reflect.size(0) * b_i];
              }

              for (i1 = 0; i1 < b_loop_ub; i1++) {
                simulation[i].f1[i1 + simulation[i].f1.size(0) * b_i] = simul[i1
                  + simul.size(0) * b_i];
              }
            }

            loop_ub = shiftedDat.size(1);
            shiftedData[i].f1.set_size(shiftedDat.size(0), shiftedDat.size(1));
            for (b_i = 0; b_i < loop_ub; b_i++) {
              b_loop_ub = shiftedDat.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] =
                  shiftedDat[i1 + shiftedDat.size(0) * b_i];
              }
            }

            chis[i] = thisChiSquared;
            backgroundParams[i] = thisBackground;
            qzshifts[i] = thisQzshift;
            scalefactors[i] = thisScalefactor;
            bulkIns[i] = thisBulkIn;
            bulkOuts[i] = thisBulkOut;
            resolutionParams[i] = thisResol;
            allRoughs[i] = problemStruct->params[0];
            loop_ub = resampledLayers.size(1);
            allLayers[i].f1.set_size(resampledLayers.size(0),
              resampledLayers.size(1));
            for (b_i = 0; b_i < loop_ub; b_i++) {
              b_loop_ub = resampledLayers.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                allLayers[i].f1[i1 + allLayers[i].f1.size(0) * b_i] =
                  resampledLayers[i1 + resampledLayers.size(0) * b_i];
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (parallelContrasts.cpp)
