//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// setupCoreReflectivityCalculation.cpp
//
// Code generation for function 'setupCoreReflectivityCalculation'
//

// Include files
#include "setupCoreReflectivityCalculation.h"
#include "RATMain_types.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "makeSimulationRange.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void setupCoreReflectivityCalculation(const double backgroundParamIndex_data[],
    const int backgroundParamIndex_size[2], const double
    resolutionParamIndex_data[], const int resolutionParamIndex_size[2], const ::
    coder::array<double, 2U> &backgroundParams, const ::coder::array<double, 2U>
    &resolutionParams, const char backgroundType_data[], const int
    backgroundType_size[2], const char resolutionType_data[], const int
    resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U> &customFiles,
    double scalefactor, double dataPresent, const ::coder::array<double, 2U>
    &data, const double dataLimits[2], const double simulationLimits[2], double
    numSimulationPoints, ::coder::array<double, 2U> &background, ::coder::array<
    double, 2U> &resolution, ::coder::array<double, 2U> &shiftedData, ::coder::
    array<double, 1U> &simulationXData, double dataIndices[2])
  {
    ::coder::array<double, 2U> b_data;
    ::coder::array<double, 2U> fullShiftedData;
    int loop_ub;

    //  Apply scale factors and q shifts to the data
    b_data.set_size(data.size(0), 6);
    for (int i{0}; i < 6; i++) {
      loop_ub = data.size(0) - 1;
      for (int i1{0}; i1 <= loop_ub; i1++) {
        b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
      }
    }

    shiftData(scalefactor, dataPresent, b_data, dataLimits, simulationLimits,
              numSimulationPoints, fullShiftedData);
    makeSimulationRange(fullShiftedData, simulationLimits, simulationXData,
                        dataIndices);
    constructBackground(backgroundType_data, backgroundType_size,
                        backgroundParamIndex_data, backgroundParamIndex_size,
                        fullShiftedData, customFiles, backgroundParams,
                        simulationXData, dataIndices, background);
    constructResolution(resolutionType_data, resolutionType_size,
                        resolutionParamIndex_data, resolutionParamIndex_size,
                        fullShiftedData, resolutionParams, simulationXData,
                        dataIndices, resolution);

    //  Reduce data to original three columns
    shiftedData.set_size(fullShiftedData.size(0), 3);
    loop_ub = fullShiftedData.size(0);
    for (int i{0}; i < 3; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        shiftedData[i1 + shiftedData.size(0) * i] = fullShiftedData[i1 +
          fullShiftedData.size(0) * i];
      }
    }
  }
}

// End of code generation (setupCoreReflectivityCalculation.cpp)
