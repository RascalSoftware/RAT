//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// constructResolution.cpp
//
// Code generation for function 'constructResolution'
//

// Include files
#include "constructResolution.h"
#include "length.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void constructResolution(const char resolutionType_data[], const int
    resolutionType_size[2], const double resolutionParamIndex_data[], const int
    resolutionParamIndex_size[2], const ::coder::array<double, 2U> &shiftedData,
    const ::coder::array<double, 2U> &resolutionParamValues, const ::coder::
    array<double, 1U> &simulationXData, const double dataIndices[2], ::coder::
    array<double, 2U> &resolution)
  {
    ::coder::array<double, 1U> b_resolution;
    int i;
    int i1;
    int loop_ub;

    //  Apply resolution parameters to the resolution.
    //
    //  For data and constant resolutions, this means taking any predefined
    //  resolution data and adding any supplied parameters.
    resolution.set_size(simulationXData.size(0), 2);
    loop_ub = simulationXData.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        resolution[i1 + resolution.size(0) * i] = 0.0;
      }
    }

    loop_ub = simulationXData.size(0);
    for (i = 0; i < loop_ub; i++) {
      resolution[i] = simulationXData[i];
    }

    if (coder::internal::q_strcmp(resolutionType_data, resolutionType_size)) {
      //  If we are using data resolutions and the simulation range is larger
      //  than the data range, we extend the data resolution to the simulation
      //  range using the resolution values at the ends of the curve.
      loop_ub = static_cast<int>(dataIndices[0]);
      for (i = 0; i < loop_ub; i++) {
        resolution[i + resolution.size(0)] = shiftedData[shiftedData.size(0) * 3];
      }

      if (dataIndices[0] > dataIndices[1]) {
        i = 0;
        i1 = 0;
      } else {
        i = static_cast<int>(dataIndices[0]) - 1;
        i1 = static_cast<int>(dataIndices[1]);
      }

      loop_ub = i1 - i;
      for (i1 = 0; i1 < loop_ub; i1++) {
        resolution[(i + i1) + resolution.size(0)] = shiftedData[i1 +
          shiftedData.size(0) * 3];
      }

      if (dataIndices[1] > resolution.size(0)) {
        i = 0;
        i1 = 0;
      } else {
        i = static_cast<int>(dataIndices[1]) - 1;
        i1 = resolution.size(0);
      }

      loop_ub = i1 - i;
      for (i1 = 0; i1 < loop_ub; i1++) {
        resolution[(i + i1) + resolution.size(0)] = shiftedData
          [(shiftedData.size(0) + shiftedData.size(0) * 3) - 1];
      }
    } else {
      //  For a constant resolution, we expect exactly one index here, but must
      //  account for the case where resolutionParamIndex is empty.
      i = coder::internal::intlength(resolutionParamIndex_size[0],
        resolutionParamIndex_size[1]);
      for (int b_i{0}; b_i < i; b_i++) {
        double b_resolutionParamValues;
        b_resolutionParamValues = resolutionParamValues[static_cast<int>
          (resolutionParamIndex_data[b_i]) - 1];
        b_resolution.set_size(resolution.size(0));
        loop_ub = resolution.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_resolution[i1] = resolution[i1 + resolution.size(0)] +
            b_resolutionParamValues;
        }

        loop_ub = b_resolution.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          resolution[i1 + resolution.size(0)] = b_resolution[i1];
        }
      }
    }

    //  We must add eps (~10^-16) here in order to ensure we do not have any
    //  values identical to 0.0 in the resolution as this will cause a divide by
    //  zero error when the resolution correction is applied to the reflectivity.
    b_resolution.set_size(resolution.size(0));
    loop_ub = resolution.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_resolution[i] = resolution[i + resolution.size(0)] +
        2.2204460492503131E-16;
    }

    loop_ub = b_resolution.size(0);
    for (i = 0; i < loop_ub; i++) {
      resolution[i + resolution.size(0)] = b_resolution[i];
    }
  }
}

// End of code generation (constructResolution.cpp)
