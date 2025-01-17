//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// applyBackgroundCorrection.cpp
//
// Code generation for function 'applyBackgroundCorrection'
//

// Include files
#include "applyBackgroundCorrection.h"
#include "find.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void applyBackgroundCorrection(::coder::array<real_T, 2U> &reflectivity, ::
    coder::array<real_T, 2U> &simulation, ::coder::array<real_T, 2U>
    &shiftedData, const ::coder::array<real_T, 2U> &background, const char_T
    backgroundAction_data[], const int32_T backgroundAction_size[2], ::coder::
    array<real_T, 2U> &outputData)
  {
    ::coder::array<real_T, 1U> b_background;
    ::coder::array<real_T, 1U> b_reflectivity;
    ::coder::array<real_T, 1U> c_shiftedData;
    ::coder::array<real_T, 1U> r;
    ::coder::array<int32_T, 1U> highXVals;
    ::coder::array<int32_T, 1U> lowXVals;
    ::coder::array<boolean_T, 1U> b_simulation;
    real_T b_shiftedData;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T k;

    //  Find where the data range lies within the simulation range
    b_shiftedData = shiftedData[0];
    k = simulation.size(0);
    b_simulation.set_size(k);
    for (i = 0; i < k; i++) {
      b_simulation[i] = (simulation[i] == b_shiftedData);
    }

    coder::eml_find(b_simulation, highXVals);
    lowXVals.set_size(highXVals.size(0));
    k = highXVals.size(0);
    for (i = 0; i < k; i++) {
      lowXVals[i] = highXVals[i];
    }

    b_shiftedData = shiftedData[shiftedData.size(0) - 1];
    k = simulation.size(0);
    b_simulation.set_size(k);
    for (i = 0; i < k; i++) {
      b_simulation[i] = (simulation[i] == b_shiftedData);
    }

    coder::eml_find(b_simulation, highXVals);

    //  Reduce ranges here - background is defined over the simulation range
    if (lowXVals[0] > highXVals[highXVals.size(0) - 1]) {
      i = 0;
      i1 = 0;
      i2 = 0;
    } else {
      i = lowXVals[0] - 1;
      i1 = lowXVals[0] - 1;
      i2 = highXVals[highXVals.size(0) - 1];
    }

    if (coder::internal::r_strcmp(backgroundAction_data, backgroundAction_size))
    {
      k = 0;
    } else if (coder::internal::s_strcmp(backgroundAction_data,
                backgroundAction_size)) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      //  Add the data to the simulation
      k = reflectivity.size(0) - 1;
      b_reflectivity.set_size(k + 1);
      for (i1 = 0; i1 <= k; i1++) {
        b_reflectivity[i1] = reflectivity[i1 + reflectivity.size(0)] +
          background[(i + i1) + background.size(0)];
      }

      k = b_reflectivity.size(0);
      for (i = 0; i < k; i++) {
        reflectivity[i + reflectivity.size(0)] = b_reflectivity[i];
      }

      k = simulation.size(0) - 1;
      b_reflectivity.set_size(k + 1);
      for (i = 0; i <= k; i++) {
        b_reflectivity[i] = simulation[i + simulation.size(0)] + background[i +
          background.size(0)];
      }

      k = b_reflectivity.size(0);
      for (i = 0; i < k; i++) {
        simulation[i + simulation.size(0)] = b_reflectivity[i];
      }
      break;

     case 1:
      //  Subtract the background data from the shiftedData
      k = shiftedData.size(0) - 1;
      c_shiftedData.set_size(shiftedData.size(0));
      for (int32_T i3{0}; i3 <= k; i3++) {
        c_shiftedData[i3] = shiftedData[i3 + shiftedData.size(0)] - background
          [(i + i3) + background.size(0)];
      }

      k = c_shiftedData.size(0);
      for (i = 0; i < k; i++) {
        shiftedData[i + shiftedData.size(0)] = c_shiftedData[i];
      }

      k = shiftedData.size(0);
      c_shiftedData.set_size(shiftedData.size(0));
      for (i = 0; i < k; i++) {
        c_shiftedData[i] = shiftedData[i + shiftedData.size(0) * 2];
      }

      coder::power(c_shiftedData, b_reflectivity);
      k = i2 - i1;
      b_background.set_size(k);
      for (i = 0; i < k; i++) {
        b_background[i] = background[(i1 + i) + background.size(0) * 2];
      }

      coder::power(b_background, r);
      k = b_reflectivity.size(0);
      for (i = 0; i < k; i++) {
        b_reflectivity[i] = b_reflectivity[i] + r[i];
      }

      i = b_reflectivity.size(0);
      for (k = 0; k < i; k++) {
        b_reflectivity[k] = std::sqrt(b_reflectivity[k]);
      }

      k = b_reflectivity.size(0);
      for (i = 0; i < k; i++) {
        shiftedData[i + shiftedData.size(0) * 2] = b_reflectivity[i];
      }

      //  Propagate the errors
      break;
    }

    //  Reduce data to original three columns
    k = shiftedData.size(0);
    outputData.set_size(shiftedData.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < k; i1++) {
        outputData[i1 + outputData.size(0) * i] = shiftedData[i1 +
          shiftedData.size(0) * i];
      }
    }
  }
}

// End of code generation (applyBackgroundCorrection.cpp)
