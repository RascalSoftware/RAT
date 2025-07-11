//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// applyBackgroundCorrection.cpp
//
// Code generation for function 'applyBackgroundCorrection'
//

// Include files
#include "applyBackgroundCorrection.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "strcmp.h"
#include "coderException.hpp"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, int in3, int in4);
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 2U> &in3, const ::coder::array<double, 2U> &in4, int in5, int
    in6);
  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, int in3, int in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2)
  {
    ::coder::array<double, 1U> b_in1;
    int in1_idx_0;
    int stride_0_0;
    int stride_1_0;
    in1_idx_0 = in1.size(0);
    b_in1.set_size(in1_idx_0);
    stride_0_0 = (in1.size(0) != 1);
    stride_1_0 = (in2.size(0) != 1);
    for (int i{0}; i < in1_idx_0; i++) {
      b_in1[i] = in1[i * stride_0_0 + in1.size(0)] + in2[i * stride_1_0 +
        in2.size(0)];
    }

    in1_idx_0 = b_in1.size(0);
    for (int i{0}; i < in1_idx_0; i++) {
      in1[i + in1.size(0)] = b_in1[i];
    }
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, int in3, int in4)
  {
    ::coder::array<double, 1U> b_in1;
    int in1_idx_0;
    int stride_0_0;
    int stride_1_0;
    in1_idx_0 = in1.size(0);
    b_in1.set_size(in1_idx_0);
    stride_0_0 = (in1.size(0) != 1);
    stride_1_0 = ((in4 - in3) + 1 != 1);
    for (int i{0}; i < in1_idx_0; i++) {
      b_in1[i] = in1[i * stride_0_0 + in1.size(0)] - in2[(in3 + i * stride_1_0)
        + in2.size(0)];
    }

    in1_idx_0 = b_in1.size(0);
    for (int i{0}; i < in1_idx_0; i++) {
      in1[i + in1.size(0)] = b_in1[i];
    }
  }

  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 2U> &in3, const ::coder::array<double, 2U> &in4, int in5, int
    in6)
  {
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    i = (in6 - in5) + 1;
    if (i == 1) {
      loop_ub = in3.size(0);
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in3.size(0) != 1);
    stride_1_0 = (i != 1);
    for (i = 0; i < loop_ub; i++) {
      double b_varargin_1;
      double varargin_1;
      varargin_1 = in3[i * stride_0_0 + in3.size(0) * 2];
      b_varargin_1 = in4[(in5 + i * stride_1_0) + in4.size(0) * 2];
      in1[i] = varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1;
    }
  }

  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, int in3, int in4)
  {
    ::coder::array<double, 1U> b_in1;
    int in1_idx_0;
    int stride_0_0;
    int stride_1_0;
    in1_idx_0 = in1.size(0);
    b_in1.set_size(in1_idx_0);
    stride_0_0 = (in1.size(0) != 1);
    stride_1_0 = ((in4 - in3) + 1 != 1);
    for (int i{0}; i < in1_idx_0; i++) {
      b_in1[i] = in1[i * stride_0_0 + in1.size(0)] + in2[(in3 + i * stride_1_0)
        + in2.size(0)];
    }

    in1_idx_0 = b_in1.size(0);
    for (int i{0}; i < in1_idx_0; i++) {
      in1[i + in1.size(0)] = b_in1[i];
    }
  }

  void applyBackgroundCorrection(::coder::array<double, 2U> &reflectivity, ::
    coder::array<double, 2U> &simulation, ::coder::array<double, 2U>
    &shiftedData, const ::coder::array<double, 2U> &background, const char
    backgroundAction_data[], const int backgroundAction_size[2])
  {
    ::coder::array<double, 1U> b_reflectivity;
    ::coder::array<double, 1U> r1;
    ::coder::array<int, 1U> highXVals;
    ::coder::array<int, 1U> lowXVals;
    ::coder::array<char, 2U> r;
    ::coder::array<boolean_T, 1U> b_simulation;
    double b_shiftedData;
    int i;
    int i1;
    int i2;
    int i3;
    int k;

    //  Find where the data range lies within the simulation range
    b_shiftedData = shiftedData[0];
    b_simulation.set_size(simulation.size(0));
    k = simulation.size(0);
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
    b_simulation.set_size(simulation.size(0));
    k = simulation.size(0);
    for (i = 0; i < k; i++) {
      b_simulation[i] = (simulation[i] == b_shiftedData);
    }

    coder::eml_find(b_simulation, highXVals);

    //  Reduce ranges here - background is defined over the simulation range
    i = highXVals[highXVals.size(0) - 1];
    if (lowXVals[0] > i) {
      i1 = 0;
      i = 0;
      i2 = 0;
      i3 = 0;
    } else {
      i1 = lowXVals[0] - 1;
      i2 = lowXVals[0] - 1;
      i3 = highXVals[highXVals.size(0) - 1];
    }

    if (coder::internal::s_strcmp(backgroundAction_data, backgroundAction_size))
    {
      k = 0;
    } else if (coder::internal::t_strcmp(backgroundAction_data,
                backgroundAction_size)) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      //  Add the data to the simulation
      if (reflectivity.size(0) == i - i1) {
        k = reflectivity.size(0);
        b_reflectivity.set_size(k);
        for (i = 0; i < k; i++) {
          b_reflectivity[i] = reflectivity[i + reflectivity.size(0)] +
            background[(i1 + i) + background.size(0)];
        }

        k = b_reflectivity.size(0);
        for (i = 0; i < k; i++) {
          reflectivity[i + reflectivity.size(0)] = b_reflectivity[i];
        }
      } else {
        c_binary_expand_op(reflectivity, background, i1, i - 1);
      }

      if (simulation.size(0) == background.size(0)) {
        k = simulation.size(0);
        b_reflectivity.set_size(k);
        for (i = 0; i < k; i++) {
          b_reflectivity[i] = simulation[i + simulation.size(0)] + background[i
            + background.size(0)];
        }

        k = b_reflectivity.size(0);
        for (i = 0; i < k; i++) {
          simulation[i + simulation.size(0)] = b_reflectivity[i];
        }
      } else {
        binary_expand_op(simulation, background);
      }
      break;

     case 1:
      {
        int i4;

        //  Subtract the background data from the shiftedData
        i4 = i - i1;
        if (shiftedData.size(0) == i4) {
          k = shiftedData.size(0);
          b_reflectivity.set_size(k);
          for (i = 0; i < k; i++) {
            b_reflectivity[i] = shiftedData[i + shiftedData.size(0)] -
              background[(i1 + i) + background.size(0)];
          }

          k = b_reflectivity.size(0);
          for (i = 0; i < k; i++) {
            shiftedData[i + shiftedData.size(0)] = b_reflectivity[i];
          }
        } else {
          binary_expand_op(shiftedData, background, i1, i - 1);
        }

        if (shiftedData.size(0) == i4) {
          r1.set_size(shiftedData.size(0));
          k = shiftedData.size(0);
          for (i = 0; i < k; i++) {
            double varargin_1;
            b_shiftedData = shiftedData[i + shiftedData.size(0) * 2];
            varargin_1 = background[(i2 + i) + background.size(0) * 2];
            r1[i] = b_shiftedData * b_shiftedData + varargin_1 * varargin_1;
          }
        } else {
          binary_expand_op(r1, shiftedData, background, i2, i3 - 1);
        }

        i = r1.size(0);
        for (k = 0; k < i; k++) {
          r1[k] = std::sqrt(r1[k]);
        }

        k = shiftedData.size(0);
        for (i = 0; i < k; i++) {
          shiftedData[i + shiftedData.size(0) * 2] = r1[i];
        }

        //  Propagate the errors
      }
      break;

     default:
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      coder::c_sprintf(backgroundAction_data, backgroundAction_size, r);
      coderException(1.0, &r[0]);
      break;
    }
  }
}

// End of code generation (applyBackgroundCorrection.cpp)
