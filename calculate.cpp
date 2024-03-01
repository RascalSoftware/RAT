//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calculate.cpp
//
// Code generation for function 'calculate'
//

// Include files
#include "calculate.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "parallelContrasts.h"
#include "parallelPoints.h"
#include "rt_nonfinite.h"
#include "single.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace standardLayers
    {
      void calculate(const f_struct_T *problemStruct, const cell_11
                     *problemCells, const struct2_T *controls, b_struct_T
                     *contrastParams, struct6_T *calculationResults, ::coder::
                     array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                     cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_10,
                     1U> &shiftedData, ::coder::array<cell_wrap_10, 1U>
                     &layerSlds, ::coder::array<cell_wrap_10, 1U> &sldProfiles, ::
                     coder::array<cell_wrap_10, 1U> &allLayers)
      {
        real_T y;
        int32_T i;
        int32_T loop_ub_tmp;

        //  Standard layers reflectivity calculation for nonPolarisedTF
        //  This function decides on parallelisation options before calling the
        //  relevant version ofthe main standard layers calculation. Parallelisation
        //  is either over the outer loop ('contrasts'), or the inner loop
        //  ('points'). The easiest way to do this is to have multiple versions of
        //  the same core calculation, rather than trying to make the parallel
        //  for loops conditional (although that would be much neater) There are:
        //  points    - parallelise over points in the reflectivity calculation
        //  contrasts - parallelise over contrasts (outer for loop)
        //  Pre-allocation - It's necessary to
        //  pre-define the types for all the arrays
        //  for compilation, so do this in this block.
        loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
        contrastParams->ssubs.set_size(loop_ub_tmp);
        contrastParams->backgroundParams.set_size(loop_ub_tmp);
        contrastParams->qzshifts.set_size(loop_ub_tmp);
        contrastParams->scalefactors.set_size(loop_ub_tmp);
        contrastParams->bulkIn.set_size(loop_ub_tmp);
        contrastParams->bulkOut.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->ssubs[i] = 0.0;
          contrastParams->backgroundParams[i] = 0.0;
          contrastParams->qzshifts[i] = 0.0;
          contrastParams->scalefactors[i] = 0.0;
          contrastParams->bulkIn[i] = 0.0;
          contrastParams->bulkOut[i] = 0.0;
        }

        calculationResults->allChis.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          calculationResults->allChis[i] = 0.0;
        }

        contrastParams->resolutionParams.set_size(loop_ub_tmp);
        contrastParams->allSubRough.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        shiftedData.set_size(loop_ub_tmp);
        layerSlds.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp);
        allLayers.set_size(loop_ub_tmp);
        for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
          contrastParams->resolutionParams[b_i] = 0.0;
          contrastParams->allSubRough[b_i] = 0.0;
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
          sldProfiles[b_i].f1.set_size(2, 2);
          sldProfiles[b_i].f1[0] = 1.0;
          sldProfiles[b_i].f1[1] = 1.0;
          sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
          sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
          allLayers[b_i].f1.set_size(2, 3);
          for (i = 0; i < 3; i++) {
            shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i] = 1.0;
            shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i + 1] = 1.0;
            layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i] = 1.0;
            layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i + 1] = 1.0;
            allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i] = 1.0;
            allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i + 1] = 1.0;
          }
        }

        //  ------- End type definitions -------------
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
                   calculationResults->allChis, reflectivity, simulation,
                   shiftedData, layerSlds, sldProfiles, allLayers,
                   contrastParams->allSubRough);
          break;

         case 1:
          parallelPoints(problemStruct, problemCells, controls,
                         contrastParams->ssubs, contrastParams->backgroundParams,
                         contrastParams->qzshifts, contrastParams->scalefactors,
                         contrastParams->bulkIn, contrastParams->bulkOut,
                         contrastParams->resolutionParams,
                         calculationResults->allChis, reflectivity, simulation,
                         shiftedData, layerSlds, sldProfiles, allLayers,
                         contrastParams->allSubRough);
          break;

         case 2:
          parallelContrasts(problemStruct, problemCells, controls,
                            contrastParams->ssubs,
                            contrastParams->backgroundParams,
                            contrastParams->qzshifts,
                            contrastParams->scalefactors, contrastParams->bulkIn,
                            contrastParams->bulkOut,
                            contrastParams->resolutionParams,
                            calculationResults->allChis, reflectivity,
                            simulation, shiftedData, layerSlds, sldProfiles,
                            allLayers, contrastParams->allSubRough);
          break;
        }

        //  Package everything into one array for tidy output
        contrastParams->resample.set_size(1, problemStruct->resample.size(1));
        loop_ub_tmp = problemStruct->resample.size(1);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->resample[i] = problemStruct->resample[i];
        }

        if (calculationResults->allChis.size(0) == 0) {
          y = 0.0;
        } else {
          y = coder::nestedIter(calculationResults->allChis,
                                calculationResults->allChis.size(0));
        }

        calculationResults->sumChi = y;
      }
    }
  }
}

// End of code generation (calculate.cpp)
