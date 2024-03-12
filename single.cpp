//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// single.cpp
//
// Code generation for function 'single'
//

// Include files
#include "single.h"
#include "RATMain_internal_types.h"
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
      void b_single(const f_struct_T *problemStruct, const cell_11 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &outSsubs, ::coder::array<real_T, 1U> &backgroundParams, ::
                    coder::array<real_T, 1U> &qzshifts, ::coder::array<real_T,
                    1U> &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                    coder::array<real_T, 1U> &bulkOuts, ::coder::array<real_T,
                    1U> &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                    coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                    cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_10,
                    1U> &shiftedData, ::coder::array<cell_wrap_10, 1U>
                    &layerSlds, ::coder::array<cell_wrap_10, 1U> &sldProfiles, ::
                    coder::array<cell_wrap_10, 1U> &allLayers, ::coder::array<
                    real_T, 1U> &allRoughs)
      {
        static real_T thisContrastLayers_data[6000];
        ::coder::array<cell_wrap_31, 2U> outParameterisedLayers;
        ::coder::array<real_T, 2U> b_thisContrastLayers_data;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> sldProfile;
        real_T thisBackground;
        real_T thisBulkIn;
        real_T thisBulkOut;
        real_T thisQzshift;
        real_T thisResol;
        real_T thisRough;
        real_T thisScalefactor;
        int32_T thisContrastLayers_size[2];
        int32_T i;
        boolean_T useImaginary;

        //  Single threaded version of the Standard Layers calculation
        //  This is the main reflectivity calculation of the standard layers
        //  calculation type. It extracts the required parameters for the contrasts
        //  from the input arrays, then passes the main calculation to
        //  'standardLayersCore', which carries out the calculation itself.
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
        useImaginary = problemStruct->useImaginary;

        //  Allocate the memory for the output arrays before the main loop
        i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgroundParams.set_size(i);

        //  end memory allocation.
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only needs
        //  to be done once, and so is done outside the contrasts loop
        allocateParamsToLayers(problemStruct->params, problemCells->f6,
          outParameterisedLayers);

        //  Resample params if requiired
        //  Substrate roughness is always first parameter for standard layers
        thisRough = problemStruct->params[0];

        //  Loop over all the contrasts
        outSsubs.set_size(i);
        sldProfiles.set_size(i);
        reflectivity.set_size(i);
        simulation.set_size(i);
        shiftedData.set_size(i);
        layerSlds.set_size(i);
        chis.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        allRoughs.set_size(i);
        allLayers.set_size(i);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          int32_T b_loop_ub;
          int32_T i1;
          int32_T i2;
          int32_T loop_ub;

          //  Extract the relevant parameter values for this contrast
          //  from the input arrays.
          //  First need to decide which values of the backgrounds, scalefactors
          //  data shifts and bulk contrasts are associated with this contrast
          backSort(problemStruct->contrastBackgrounds[b_i],
                   problemStruct->contrastQzshifts[b_i],
                   problemStruct->contrastScalefactors[b_i],
                   problemStruct->contrastBulkIns[b_i],
                   problemStruct->contrastBulkOuts[b_i],
                   problemStruct->contrastResolutions[b_i],
                   problemStruct->backgroundParams, problemStruct->qzshifts,
                   problemStruct->scalefactors, problemStruct->bulkIn,
                   problemStruct->bulkOut, problemStruct->resolutionParams,
                   &thisBackground, &thisQzshift, &thisScalefactor, &thisBulkIn,
                   &thisBulkOut, &thisResol);

          //  Also need to determine which layers from the overall layers list
          //  are required for this contrast, and put them in the correct order
          //  according to geometry
          allocateLayersForContrast(problemCells->f5[b_i].f1,
            outParameterisedLayers, useImaginary, thisContrastLayers_data,
            thisContrastLayers_size);

          //  For the other parameters, we extract the correct ones from the input
          //  arrays
          //  Call the core layers calculation
          b_thisContrastLayers_data.set(&thisContrastLayers_data[0],
            thisContrastLayers_size[0], thisContrastLayers_size[1]);
          coreLayersCalculation(b_thisContrastLayers_data, thisRough,
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, thisBulkIn,
                                thisBulkOut, problemStruct->resample[b_i],
                                controls->calcSldDuringFit, thisScalefactor,
                                thisQzshift, problemStruct->dataPresent[b_i],
                                problemCells->f2[b_i].f1, problemCells->f3[b_i].
                                f1, problemCells->f4[b_i].f1, problemCells->
                                f1[b_i].f1, thisBackground, thisResol,
                                problemStruct->contrastBackgroundsType[b_i],
                                static_cast<real_T>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                controls->resamPars, useImaginary, sldProfile,
                                reflectivity[b_i].f1, simulation[b_i].f1,
                                shiftedDat, layerSlds[b_i].f1, allLayers[b_i].f1,
                                &chis[b_i], &outSsubs[b_i]);

          //  Store returned values for this contrast in the output arrays.
          //  As well as the calculated profiles, we also store a record of
          //  the other values (background, scalefactors etc) for each contrast
          //  for future use.
          loop_ub = sldProfile.size(1);
          sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfile.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] =
                sldProfile[i2 + sldProfile.size(0) * i1];
            }
          }

          loop_ub = shiftedDat.size(1);
          shiftedData[b_i].f1.set_size(shiftedDat.size(0), shiftedDat.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = shiftedDat.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] =
                shiftedDat[i2 + shiftedDat.size(0) * i1];
            }
          }

          backgroundParams[b_i] = thisBackground;
          qzshifts[b_i] = thisQzshift;
          scalefactors[b_i] = thisScalefactor;
          bulkIns[b_i] = thisBulkIn;
          bulkOuts[b_i] = thisBulkOut;
          resolutionParams[b_i] = thisResol;
          allRoughs[b_i] = thisRough;
        }
      }
    }
  }
}

// End of code generation (single.cpp)
