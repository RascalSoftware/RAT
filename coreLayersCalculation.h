//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// coreLayersCalculation.h
//
// Code generation for function 'coreLayersCalculation'
//
#ifndef CORELAYERSCALCULATION_H
#define CORELAYERSCALCULATION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    void coreLayersCalculation(const ::coder::array<real_T, 2U> &layers, real_T
      rough, const char_T geometry_data[], const int32_T geometry_size[2],
      real_T bulkIn, real_T bulkOut, real_T resample, boolean_T calcSld, const ::
      coder::array<real_T, 2U> &shiftedData, const ::coder::array<real_T, 1U>
      &simulationXData, const real_T dataIndices[2], const real_T repeatLayers[2],
      const ::coder::array<real_T, 2U> &resolution, const ::coder::array<real_T,
      2U> &background, const char_T backgroundAction_data[], const int32_T
      backgroundAction_size[2], real_T params, const char_T parallelPoints_data[],
      const int32_T parallelPoints_size[2], real_T resampleMinAngle, real_T
      resampleNPoints, boolean_T useImaginary, ::coder::array<real_T, 2U>
      &sldProfile, ::coder::array<real_T, 2U> &reflect, ::coder::array<real_T,
      2U> &simulation, ::coder::array<real_T, 2U> &b_shiftedData, ::coder::array<
      real_T, 2U> &theseLayers, ::coder::array<real_T, 2U> &resamLayers, real_T *
      chiSq);
  }
}

#endif

// End of code generation (coreLayersCalculation.h)
