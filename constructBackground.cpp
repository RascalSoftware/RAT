//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// constructBackground.cpp
//
// Code generation for function 'constructBackground'
//

// Include files
#include "constructBackground.h"
#include "RATMain_types.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 1U> &in2);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 1U> &in2)
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
      b_in1[i] = in1[i * stride_0_0 + in1.size(0)] + in2[i * stride_1_0];
    }

    in1_idx_0 = b_in1.size(0);
    for (int i{0}; i < in1_idx_0; i++) {
      in1[i + in1.size(0)] = b_in1[i];
    }
  }

  void constructBackground(const char backgroundType_data[], const int
    backgroundType_size[2], const double backgroundParamIndices_data[], const
    int backgroundParamIndices_size[2], const ::coder::array<double, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<double, 2U> &backgroundParamValues, const ::coder::array<double,
    1U> &simulationXData, const double dataIndices[2], ::coder::array<double, 2U>
    &background)
  {
    ::coder::array<double, 1U> b_background;
    ::coder::array<double, 1U> functionBackground;
    double paramsArray_data[5];
    int paramsArray_size[2];
    int i;
    int i1;
    int loop_ub;

    //  Apply background parameters to the background.
    //
    //  For function backgrounds, this means running the function using the
    //  defined parameters. For data and constant backgrounds, this means taking
    //  any predefined background data and adding any supplied parameters.
    background.set_size(simulationXData.size(0), 3);
    loop_ub = simulationXData.size(0);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        background[i1 + background.size(0) * i] = 0.0;
      }
    }

    loop_ub = simulationXData.size(0);
    for (i = 0; i < loop_ub; i++) {
      background[i] = simulationXData[i];
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
      background[(i + i1) + background.size(0)] = shiftedData[i1 +
        shiftedData.size(0) * 4];
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
      background[(i + i1) + background.size(0) * 2] = shiftedData[i1 +
        shiftedData.size(0) * 5];
    }

    if (coder::internal::p_strcmp(backgroundType_data, backgroundType_size)) {
      creal_T x;
      int iv[2];

      //  For a function background, the first index is actually that of the
      //  custom function
      //  The rest of the backgroundParamIndices are indices to
      //  backgroundParams
      if (backgroundParamIndices_size[1] < 2) {
        i = 0;
        i1 = 0;
      } else {
        i = 1;
        i1 = backgroundParamIndices_size[1];
      }

      //  Make an array of real params
      loop_ub = i1 - i;
      paramsArray_size[0] = 1;
      paramsArray_size[1] = loop_ub;
      if (loop_ub - 1 >= 0) {
        std::memset(&paramsArray_data[0], 0, static_cast<unsigned int>(loop_ub) *
                    sizeof(double));
      }

      for (int b_i{0}; b_i < loop_ub; b_i++) {
        paramsArray_data[b_i] = backgroundParamValues[static_cast<int>
          (backgroundParamIndices_data[i + b_i]) - 1];
      }

      //  Evaluate the background function with these params...
      functionBackground.set_size(background.size(0));
      loop_ub = background.size(0);
      for (i = 0; i < loop_ub; i++) {
        functionBackground[i] = 0.0;
      }

      //  This is the correct type - for compilation
      iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                static_cast<int>(backgroundParamIndices_data[0]) - 1].f1)->size())
        [0];
      iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                static_cast<int>(backgroundParamIndices_data[0]) - 1].f1)->size())
        [1];
      x = coder::internal::str2double((const char *)((::coder::array<char, 2U> *)
        &customFiles[static_cast<int>(backgroundParamIndices_data[0]) - 1].f1)
        ->data(), iv);
      if ((!std::isnan(x.re)) && (!std::isnan(x.im))) {
        b_background.set_size(background.size(0));
        loop_ub = background.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_background[i] = background[i];
        }

        iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                  static_cast<int>(backgroundParamIndices_data[0]) - 1].f1)
                 ->size())[0];
        iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                  static_cast<int>(backgroundParamIndices_data[0]) - 1].f1)
                 ->size())[1];
        callCppFunction((const char *)((::coder::array<char, 2U> *)&customFiles[
          static_cast<int>(backgroundParamIndices_data[0]) - 1].f1)->data(), iv,
                        b_background, paramsArray_data, paramsArray_size,
                        functionBackground);
      }

      if (background.size(0) == functionBackground.size(0)) {
        b_background.set_size(background.size(0));
        loop_ub = background.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_background[i] = background[i + background.size(0)] +
            functionBackground[i];
        }

        loop_ub = b_background.size(0);
        for (i = 0; i < loop_ub; i++) {
          background[i + background.size(0)] = b_background[i];
        }
      } else {
        binary_expand_op(background, functionBackground);
      }
    } else {
      //  We have either a constant background, or a data background with an
      //  optional offset. In either case we add the parameter to column 5 of
      //  the data. Hence we expect to run either zero or one iterations
      //  of this loop.
      i = backgroundParamIndices_size[1];
      for (int b_i{0}; b_i < i; b_i++) {
        double b_backgroundParamValues;
        b_backgroundParamValues = backgroundParamValues[static_cast<int>
          (backgroundParamIndices_data[b_i]) - 1];
        b_background.set_size(background.size(0));
        loop_ub = background.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_background[i1] = background[i1 + background.size(0)] +
            b_backgroundParamValues;
        }

        loop_ub = b_background.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          background[i1 + background.size(0)] = b_background[i1];
        }
      }
    }
  }
}

// End of code generation (constructBackground.cpp)
