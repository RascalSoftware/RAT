//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parseResultToStruct.cpp
//
// Code generation for function 'parseResultToStruct'
//

// Include files
#include "parseResultToStruct.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void parseResultToStruct(const e_struct_T *contrastParams, const cell_wrap_9
    resultCells[6], ::coder::array<cell_wrap_8, 2U> &result_reflectivity, ::
    coder::array<cell_wrap_8, 2U> &result_simulation, ::coder::array<cell_wrap_8,
    2U> &result_shiftedData, ::coder::array<cell_wrap_8, 2U> &result_layerSlds, ::
    coder::array<cell_wrap_8, 2U> &result_sldProfiles, ::coder::array<
    cell_wrap_8, 2U> &result_allLayers, real_T *result_calculationResults_sumChi,
    e_struct_T *result_contrastParams)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    result_reflectivity.set_size(resultCells[0].f1.size(0), resultCells[0].
      f1.size(1));
    loop_ub = resultCells[0].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = resultCells[0].f1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result_reflectivity[i1 + result_reflectivity.size(0) * i] = resultCells
          [0].f1[i1 + resultCells[0].f1.size(0) * i];
      }
    }

    //  Reflectivity art points
    result_simulation.set_size(resultCells[1].f1.size(0), resultCells[1].f1.size
      (1));
    loop_ub = resultCells[1].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = resultCells[1].f1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result_simulation[i1 + result_simulation.size(0) * i] = resultCells[1].
          f1[i1 + resultCells[1].f1.size(0) * i];
      }
    }

    //  Reflectivity between sim limits
    result_shiftedData.set_size(resultCells[2].f1.size(0), resultCells[2].
      f1.size(1));
    loop_ub = resultCells[2].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = resultCells[2].f1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result_shiftedData[i1 + result_shiftedData.size(0) * i] = resultCells[2]
          .f1[i1 + resultCells[2].f1.size(0) * i];
      }
    }

    //  Data corrected for sfs
    result_layerSlds.set_size(resultCells[3].f1.size(0), resultCells[3].f1.size
      (1));
    loop_ub = resultCells[3].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = resultCells[3].f1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result_layerSlds[i1 + result_layerSlds.size(0) * i] = resultCells[3]
          .f1[i1 + resultCells[3].f1.size(0) * i];
      }
    }

    //  Layers if defined (i.e. not customXY)
    result_sldProfiles.set_size(resultCells[4].f1.size(0), resultCells[4].
      f1.size(1));
    loop_ub = resultCells[4].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = resultCells[4].f1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result_sldProfiles[i1 + result_sldProfiles.size(0) * i] = resultCells[4]
          .f1[i1 + resultCells[4].f1.size(0) * i];
      }
    }

    //  Calculated SLD profiles
    result_allLayers.set_size(resultCells[5].f1.size(0), resultCells[5].f1.size
      (1));
    loop_ub = resultCells[5].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = resultCells[5].f1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result_allLayers[i1 + result_allLayers.size(0) * i] = resultCells[5]
          .f1[i1 + resultCells[5].f1.size(0) * i];
      }
    }

    //  Resampled layers
    //  For compile, we can't remove a field, so just clear it for now...
    // contrastParams = rmfield(contrastParams,'calculations');
    *result_contrastParams = *contrastParams;
    *result_calculationResults_sumChi = contrastParams->calculations.sumChi;
  }
}

// End of code generation (parseResultToStruct.cpp)
