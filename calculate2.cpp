//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calculate2.cpp
//
// Code generation for function 'calculate2'
//

// Include files
#include "calculate2.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "parallelContrasts2.h"
#include "parallelPoints2.h"
#include "rt_nonfinite.h"
#include "single2.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace customXY
    {
      void calculate(const d_struct_T *problemStruct, const cell_11
                     *problemCells, const struct2_T *controls, e_struct_T
                     *contrastParams, ::coder::array<cell_wrap_20, 1U>
                     &reflectivity, ::coder::array<cell_wrap_20, 1U> &simulation,
                     ::coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::
                     array<cell_wrap_8, 1U> &layerSlds, ::coder::array<
                     cell_wrap_8, 1U> &sldProfiles, ::coder::array<cell_wrap_8,
                     1U> &allLayers)
      {
        real_T y;
        int32_T i;
        int32_T loop_ub_tmp;

        //  Custom XP profile reflectivity calculation for nonPolarisedTF
        //  This function decides on parallelisation options before calling the
        //  relevant version of the main custom XY calculation. It is more
        //  efficient to have multiple versions of the core calculation, each dealing
        //  with a different scheme for parallelisation. These are:
        //  single    - single threaded reflectivity calculation
        //  points    - parallelise over points in the reflectivity calculation
        //  contrasts - parallelise over contrasts.
        //  Pre-allocation - It's necessary to
        //  pre-allocate the memory for all the arrays
        //  for compilation, so do this in this block.
        loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
        contrastParams->ssubs.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->ssubs[i] = 0.0;
        }

        contrastParams->backgroundParams.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->backgroundParams[i] = 0.0;
        }

        contrastParams->qzshifts.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->qzshifts[i] = 0.0;
        }

        contrastParams->scalefactors.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->scalefactors[i] = 0.0;
        }

        contrastParams->bulkIn.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->bulkIn[i] = 0.0;
        }

        contrastParams->bulkOut.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->bulkOut[i] = 0.0;
        }

        contrastParams->calculations.allChis.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->calculations.allChis[i] = 0.0;
        }

        contrastParams->resolutionParams.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->resolutionParams[i] = 0.0;
        }

        contrastParams->allSubRough.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->allSubRough[i] = 0.0;
        }

        reflectivity.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        shiftedData.set_size(loop_ub_tmp);
        layerSlds.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp);
        allLayers.set_size(loop_ub_tmp);
        for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
          reflectivity[b_i].f1.set_size(2, 2);
          reflectivity[b_i].f1[0] = 1.0;
          reflectivity[b_i].f1[1] = 1.0;
          reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
          reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
          simulation[b_i].f1.set_size(2, 2);
          simulation[b_i].f1[0] = 1.0;
          simulation[b_i].f1[1] = 1.0;
          simulation[b_i].f1[simulation[b_i].f1.size(0)] = 1.0;
          simulation[b_i].f1[simulation[b_i].f1.size(0) + 1] = 1.0;
          shiftedData[b_i].f1.set_size(2, 3);
          layerSlds[b_i].f1.set_size(2, 3);
          for (i = 0; i < 3; i++) {
            shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i] = 1.0;
            shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i + 1] = 1.0;
            layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i] = 1.0;
            layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i + 1] = 1.0;
          }

          sldProfiles[b_i].f1.set_size(2, 2);
          sldProfiles[b_i].f1[0] = 1.0;
          sldProfiles[b_i].f1[1] = 1.0;
          sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
          sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
          allLayers[b_i].f1.set_size(2, 1);
          allLayers[b_i].f1[0] = 1.0;
          allLayers[b_i].f1[1] = 1.0;
        }

        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          loop_ub_tmp = 0;
        } else if (coder::internal::n_strcmp(controls->parallel.data,
                    controls->parallel.size)) {
          loop_ub_tmp = 1;
        } else if (coder::internal::o_strcmp(controls->parallel.data,
                    controls->parallel.size)) {
          loop_ub_tmp = 2;
        } else {
          loop_ub_tmp = -1;
        }

        switch (loop_ub_tmp) {
         case 0:
          b_single(problemStruct, problemCells, controls, contrastParams->ssubs,
                   contrastParams->backgroundParams, contrastParams->qzshifts,
                   contrastParams->scalefactors, contrastParams->bulkIn,
                   contrastParams->bulkOut, contrastParams->resolutionParams,
                   contrastParams->calculations.allChis, reflectivity,
                   simulation, shiftedData, layerSlds, sldProfiles, allLayers,
                   contrastParams->allSubRough);
          break;

         case 1:
          parallelPoints(problemStruct, problemCells, controls,
                         contrastParams->ssubs, contrastParams->backgroundParams,
                         contrastParams->qzshifts, contrastParams->scalefactors,
                         contrastParams->bulkIn, contrastParams->bulkOut,
                         contrastParams->resolutionParams,
                         contrastParams->calculations.allChis, reflectivity,
                         simulation, shiftedData, layerSlds, sldProfiles,
                         allLayers, contrastParams->allSubRough);
          break;

         case 2:
          parallelContrasts(problemStruct, problemCells, controls,
                            contrastParams->ssubs,
                            contrastParams->backgroundParams,
                            contrastParams->qzshifts,
                            contrastParams->scalefactors, contrastParams->bulkIn,
                            contrastParams->bulkOut,
                            contrastParams->resolutionParams,
                            contrastParams->calculations.allChis, reflectivity,
                            simulation, shiftedData, layerSlds, sldProfiles,
                            allLayers, contrastParams->allSubRough);
          break;
        }

        if (contrastParams->calculations.allChis.size(0) == 0) {
          y = 0.0;
        } else {
          y = coder::nestedIter(contrastParams->calculations.allChis,
                                contrastParams->calculations.allChis.size(0));
        }

        contrastParams->calculations.sumChi = y;
        contrastParams->resample.set_size(1, contrastParams->allSubRough.size(0));
        loop_ub_tmp = contrastParams->allSubRough.size(0);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->resample[i] = 1.0;
        }
      }
    }
  }
}

// End of code generation (calculate2.cpp)
