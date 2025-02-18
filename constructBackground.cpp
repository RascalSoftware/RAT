//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// constructBackground.cpp
//
// Code generation for function 'constructBackground'
//

// Include files
#include "constructBackground.h"
#include "RATMain_types.h"
#include "callCppFunction.h"
#include "ifWhileCond.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace RAT
{
  void constructBackground(const ::coder::array<cell_wrap_10, 2U>
    &backgroundType, const real_T backgroundParamIndices_data[], const int32_T
    backgroundParamIndices_size[2], const ::coder::array<real_T, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<real_T, 2U> &backgroundParamArray, const ::coder::array<real_T,
    1U> &simulationXData, const real_T dataIndices[2], ::coder::array<real_T, 2U>
    &background)
  {
    ::coder::array<real_T, 1U> b_background;
    ::coder::array<real_T, 1U> thisBackground;
    real_T paramsArray_data[5];
    int32_T paramsArray_size[2];
    int32_T tmp_size[2];
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    boolean_T tmp_data[10000];

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
      i = 1;
    } else {
      i = static_cast<int32_T>(dataIndices[0]);
    }

    loop_ub = shiftedData.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      background[((i + i1) + background.size(0)) - 1] = shiftedData[i1 +
        shiftedData.size(0) * 4];
    }

    if (dataIndices[0] > dataIndices[1]) {
      i = 1;
    } else {
      i = static_cast<int32_T>(dataIndices[0]);
    }

    loop_ub = shiftedData.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      background[((i + i1) + background.size(0) * 2) - 1] = shiftedData[i1 +
        shiftedData.size(0) * 5];
    }

    coder::internal::t_strcmp(backgroundType, tmp_data, tmp_size);
    if (coder::internal::b_ifWhileCond(tmp_data, tmp_size)) {
      creal_T x;
      int8_T unnamed_idx_1;

      //  For a function background, the first index is actually that of the
      //  custom function
      //  The rest of the backgroundParamIndices are indicies to
      //  backgroundParams
      if (2 > backgroundParamIndices_size[1]) {
        i = -1;
        i1 = -1;
      } else {
        i = 0;
        i1 = backgroundParamIndices_size[1] - 1;
      }

      //  Make an array of real params
      unnamed_idx_1 = static_cast<int8_T>(i1 - i);
      paramsArray_size[0] = 1;
      paramsArray_size[1] = unnamed_idx_1;
      loop_ub = unnamed_idx_1;
      if (0 <= loop_ub - 1) {
        std::memset(&paramsArray_data[0], 0, loop_ub * sizeof(real_T));
      }

      i1 = static_cast<int8_T>(i1 - i);
      for (int32_T b_i{0}; b_i < i1; b_i++) {
        paramsArray_data[b_i] = backgroundParamArray[static_cast<int32_T>
          (backgroundParamIndices_data[(i + b_i) + 1]) - 1];
      }

      //  Evaluate the background function with these params...
      thisBackground.set_size(background.size(0));
      loop_ub = background.size(0);
      for (i = 0; i < loop_ub; i++) {
        thisBackground[i] = 0.0;
      }

      //  This is the correct type - for compilation
      tmp_size[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
        &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].
        f1)->size())[0];
      tmp_size[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
        &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].
        f1)->size())[1];
      x = coder::str2double((const char_T *)((::coder::array<char_T, 2U> *)
        &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].
        f1)->data(), tmp_size);
      if ((!std::isnan(x.re)) && (!std::isnan(x.im))) {
        loop_ub = background.size(0);
        b_background.set_size(background.size(0));
        for (i = 0; i < loop_ub; i++) {
          b_background[i] = background[i];
        }

        tmp_size[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
          &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1]
          .f1)->size())[0];
        tmp_size[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
          &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1]
          .f1)->size())[1];
        callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
          &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1]
          .f1)->data(), tmp_size, b_background, paramsArray_data,
                        paramsArray_size, thisBackground);
      }

      loop_ub = background.size(0) - 1;
      b_background.set_size(background.size(0));
      for (i = 0; i <= loop_ub; i++) {
        b_background[i] = background[i + background.size(0)] + thisBackground[i];
      }

      loop_ub = b_background.size(0);
      for (i = 0; i < loop_ub; i++) {
        background[i + background.size(0)] = b_background[i];
      }
    } else {
      //  We have either a constant background, or a data background with an
      //  optional offset. In either case we add the parameter to column 5 of
      //  the data. Hence we expect to run either zero or one iterations
      //  of this loop.
      i = backgroundParamIndices_size[1];
      for (int32_T b_i{0}; b_i < i; b_i++) {
        real_T b_backgroundParamArray;
        loop_ub = background.size(0) - 1;
        b_backgroundParamArray = backgroundParamArray[static_cast<int32_T>
          (backgroundParamIndices_data[b_i]) - 1];
        b_background.set_size(background.size(0));
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_background[i1] = background[i1 + background.size(0)] +
            b_backgroundParamArray;
        }

        loop_ub = b_background.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          background[i1 + background.size(0)] = b_background[i1];
        }
      }
    }
  }

  void constructBackground(const char_T backgroundType_data[], const int32_T
    backgroundType_size[2], const real_T backgroundParamIndices_data[], const
    int32_T backgroundParamIndices_size[2], const ::coder::array<real_T, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<real_T, 2U> &backgroundParamArray, const ::coder::array<real_T,
    1U> &simulationXData, const real_T dataIndices[2], ::coder::array<real_T, 2U>
    &background)
  {
    ::coder::array<real_T, 1U> b_background;
    ::coder::array<real_T, 1U> thisBackground;
    real_T paramsArray_data[5];
    int32_T iv[2];
    int32_T paramsArray_size[2];
    int32_T i;
    int32_T i1;
    int32_T loop_ub;

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
      i = 1;
    } else {
      i = static_cast<int32_T>(dataIndices[0]);
    }

    loop_ub = shiftedData.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      background[((i + i1) + background.size(0)) - 1] = shiftedData[i1 +
        shiftedData.size(0) * 4];
    }

    if (dataIndices[0] > dataIndices[1]) {
      i = 1;
    } else {
      i = static_cast<int32_T>(dataIndices[0]);
    }

    loop_ub = shiftedData.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      background[((i + i1) + background.size(0) * 2) - 1] = shiftedData[i1 +
        shiftedData.size(0) * 5];
    }

    if (coder::internal::n_strcmp(backgroundType_data, backgroundType_size)) {
      creal_T x;
      int8_T unnamed_idx_1;

      //  For a function background, the first index is actually that of the
      //  custom function
      //  The rest of the backgroundParamIndices are indicies to
      //  backgroundParams
      if (2 > backgroundParamIndices_size[1]) {
        i = -1;
        i1 = -1;
      } else {
        i = 0;
        i1 = backgroundParamIndices_size[1] - 1;
      }

      //  Make an array of real params
      unnamed_idx_1 = static_cast<int8_T>(i1 - i);
      paramsArray_size[0] = 1;
      paramsArray_size[1] = unnamed_idx_1;
      loop_ub = unnamed_idx_1;
      if (0 <= loop_ub - 1) {
        std::memset(&paramsArray_data[0], 0, loop_ub * sizeof(real_T));
      }

      i1 = static_cast<int8_T>(i1 - i);
      for (int32_T b_i{0}; b_i < i1; b_i++) {
        paramsArray_data[b_i] = backgroundParamArray[static_cast<int32_T>
          (backgroundParamIndices_data[(i + b_i) + 1]) - 1];
      }

      //  Evaluate the background function with these params...
      thisBackground.set_size(background.size(0));
      loop_ub = background.size(0);
      for (i = 0; i < loop_ub; i++) {
        thisBackground[i] = 0.0;
      }

      //  This is the correct type - for compilation
      iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].f1)
               ->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].f1)
               ->size())[1];
      x = coder::str2double((const char_T *)((::coder::array<char_T, 2U> *)
        &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].
        f1)->data(), iv);
      if ((!std::isnan(x.re)) && (!std::isnan(x.im))) {
        loop_ub = background.size(0);
        b_background.set_size(background.size(0));
        for (i = 0; i < loop_ub; i++) {
          b_background[i] = background[i];
        }

        iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                  static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].f1
                 )->size())[0];
        iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                  static_cast<int32_T>(backgroundParamIndices_data[0]) - 1].f1
                 )->size())[1];
        callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
          &customFiles[static_cast<int32_T>(backgroundParamIndices_data[0]) - 1]
          .f1)->data(), iv, b_background, paramsArray_data, paramsArray_size,
                        thisBackground);
      }

      loop_ub = background.size(0) - 1;
      b_background.set_size(background.size(0));
      for (i = 0; i <= loop_ub; i++) {
        b_background[i] = background[i + background.size(0)] + thisBackground[i];
      }

      loop_ub = b_background.size(0);
      for (i = 0; i < loop_ub; i++) {
        background[i + background.size(0)] = b_background[i];
      }
    } else {
      //  We have either a constant background, or a data background with an
      //  optional offset. In either case we add the parameter to column 5 of
      //  the data. Hence we expect to run either zero or one iterations
      //  of this loop.
      i = backgroundParamIndices_size[1];
      for (int32_T b_i{0}; b_i < i; b_i++) {
        real_T b_backgroundParamArray;
        loop_ub = background.size(0) - 1;
        b_backgroundParamArray = backgroundParamArray[static_cast<int32_T>
          (backgroundParamIndices_data[b_i]) - 1];
        b_background.set_size(background.size(0));
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_background[i1] = background[i1 + background.size(0)] +
            b_backgroundParamArray;
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
