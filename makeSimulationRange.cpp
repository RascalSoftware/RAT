//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeSimulationRange.cpp
//
// Code generation for function 'makeSimulationRange'
//

// Include files
#include "makeSimulationRange.h"
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void makeSimulationRange(const ::coder::array<double, 2U> &data, const double
    simulationLimits[2], ::coder::array<double, 1U> &simulationXdata, double
    splits[2])
  {
    ::coder::array<double, 2U> firstSection;
    ::coder::array<double, 2U> lastSection;
    double b;
    double step;
    int firstSection_idx_0;
    int loop_ub;

    //  Construct the x data for the simulation. This consists of the x data from
    //  the supplied data, plus additional points above and below the data range
    //  as necessary.
    if (simulationLimits[0] < data[0]) {
      step = data[1] - data[0];
      b = data[0] - step;
      if (std::isnan(step) || std::isnan(b)) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if ((step == 0.0) || ((simulationLimits[0] < b) && (step < 0.0)) ||
                 ((b < simulationLimits[0]) && (step > 0.0))) {
        firstSection.set_size(1, 0);
      } else if ((std::isinf(simulationLimits[0]) || std::isinf(b)) && (std::
                  isinf(step) || (simulationLimits[0] == b))) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        firstSection.set_size(1, 1);
        firstSection[0] = simulationLimits[0];
      } else if ((std::floor(simulationLimits[0]) == simulationLimits[0]) &&
                 (std::floor(step) == step)) {
        loop_ub = static_cast<int>((b - simulationLimits[0]) / step);
        firstSection.set_size(1, loop_ub + 1);
        for (int i{0}; i <= loop_ub; i++) {
          firstSection[i] = simulationLimits[0] + step * static_cast<double>(i);
        }
      } else {
        coder::eml_float_colon(simulationLimits[0], step, b, firstSection);
      }
    } else {
      firstSection.set_size(1, 0);
    }

    b = data[data.size(0) - 1];
    if (simulationLimits[1] > b) {
      step = b - data[data.size(0) - 2];
      b += step;
      if (std::isnan(b) || std::isnan(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if ((step == 0.0) || ((b < simulationLimits[1]) && (step < 0.0)) ||
                 ((simulationLimits[1] < b) && (step > 0.0))) {
        lastSection.set_size(1, 0);
      } else if ((std::isinf(b) || std::isinf(simulationLimits[1])) && (std::
                  isinf(step) || (b == simulationLimits[1]))) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = b;
      } else if ((std::floor(b) == b) && (std::floor(step) == step)) {
        loop_ub = static_cast<int>((simulationLimits[1] - b) / step);
        lastSection.set_size(1, loop_ub + 1);
        for (int i{0}; i <= loop_ub; i++) {
          lastSection[i] = b + step * static_cast<double>(i);
        }
      } else {
        coder::eml_float_colon(b, step, simulationLimits[1], lastSection);
      }
    } else {
      lastSection.set_size(1, 0);
    }

    firstSection_idx_0 = firstSection.size(1);
    simulationXdata.set_size((data.size(0) + firstSection.size(1)) +
      lastSection.size(1));
    loop_ub = firstSection.size(1);
    for (int i{0}; i < loop_ub; i++) {
      simulationXdata[i] = firstSection[i];
    }

    loop_ub = data.size(0);
    for (int i{0}; i < loop_ub; i++) {
      simulationXdata[i + firstSection_idx_0] = data[i];
    }

    loop_ub = lastSection.size(1);
    for (int i{0}; i < loop_ub; i++) {
      simulationXdata[(i + firstSection_idx_0) + data.size(0)] = lastSection[i];
    }

    splits[0] = static_cast<unsigned int>(firstSection.size(1)) + 1U;
    splits[1] = static_cast<unsigned int>(firstSection.size(1)) + static_cast<
      unsigned int>(data.size(0));
  }
}

// End of code generation (makeSimulationRange.cpp)
