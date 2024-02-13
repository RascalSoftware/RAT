//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// callCppFunction.cpp
//
// Code generation for function 'callCppFunction'
//

// Include files
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "classHandle.hpp"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <functional>

// Function Definitions
namespace RAT
{
  void b_callCppFunction(const char_T pointer_data[], const int32_T
    pointer_size[2], ::coder::array<real_T, 2U> &params, real_T bulkIn, ::coder::
    array<real_T, 2U> &bulkOut, real_T contrast, ::coder::array<real_T, 2U>
    &output, real_T *subRough)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> outArray;
    std::vector<double> paramsArray;
    ::coder::array<real_T, 2U> tempOutput;
    real_T outputSize[2];
    real_T d;
    int32_T i;
    int32_T loop_ub;
    int32_T num_tmp_tmp;
    char_T b_pointer_data[10000];
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    paramsArray = convertPtr2Vector(&params[0], static_cast<real_T>(params.size
      (1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&bulkOut[0], static_cast<real_T>
      (bulkOut.size(1)));
    outArray = { };

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, contrast, 0.0, outArray, &outputSize[0], subRough);
    d = std::round(outputSize[0] * outputSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        loop_ub = static_cast<int32_T>(d);
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }

    tempOutput.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      tempOutput[i] = 0.0;
    }

    convertVector2Ptr(outArray, &tempOutput[0]);
    loop_ub = static_cast<int32_T>(outputSize[1]);
    num_tmp_tmp = static_cast<int32_T>(outputSize[0]);
    output.set_size(num_tmp_tmp, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (int32_T i1{0}; i1 < num_tmp_tmp; i1++) {
        output[i1 + output.size(0) * i] = tempOutput[i + loop_ub * i1];
      }
    }
  }

  void c_callCppFunction(const char_T pointer_data[], const int32_T
    pointer_size[2], ::coder::array<real_T, 2U> &params, real_T bulkIn, ::coder::
    array<real_T, 2U> &bulkOut, real_T contrast, ::coder::array<real_T, 2U>
    &output, real_T *subRough)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> outArray;
    std::vector<double> paramsArray;
    ::coder::array<real_T, 2U> tempOutput;
    real_T outputSize[2];
    real_T d;
    int32_T i;
    int32_T loop_ub;
    int32_T num_tmp_tmp;
    char_T b_pointer_data[10000];
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    paramsArray = convertPtr2Vector(&params[0], static_cast<real_T>(params.size
      (1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&bulkOut[0], static_cast<real_T>
      (bulkOut.size(1)));
    outArray = { };

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, contrast, 1.0, outArray, &outputSize[0], subRough);
    d = std::round(outputSize[0] * outputSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        loop_ub = static_cast<int32_T>(d);
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }

    tempOutput.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      tempOutput[i] = 0.0;
    }

    convertVector2Ptr(outArray, &tempOutput[0]);
    loop_ub = static_cast<int32_T>(outputSize[1]);
    num_tmp_tmp = static_cast<int32_T>(outputSize[0]);
    output.set_size(num_tmp_tmp, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (int32_T i1{0}; i1 < num_tmp_tmp; i1++) {
        output[i1 + output.size(0) * i] = tempOutput[i + loop_ub * i1];
      }
    }
  }

  void callCppFunction(const char_T pointer_data[], const int32_T pointer_size[2],
                       ::coder::array<real_T, 2U> &params, real_T bulkIn, ::
                       coder::array<real_T, 2U> &bulkOut, real_T contrast, ::
                       coder::array<real_T, 2U> &output, real_T *subRough)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> outArray;
    std::vector<double> paramsArray;
    ::coder::array<real_T, 2U> tempOutput;
    real_T outputSize[2];
    real_T d;
    int32_T i;
    int32_T loop_ub;
    int32_T num_tmp_tmp;
    char_T b_pointer_data[10000];
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    paramsArray = convertPtr2Vector(&params[0], static_cast<real_T>(params.size
      (1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&bulkOut[0], static_cast<real_T>
      (bulkOut.size(1)));
    outArray = { };

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, contrast, outArray, &outputSize[0], subRough);
    d = std::round(outputSize[0] * outputSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        loop_ub = static_cast<int32_T>(d);
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }

    tempOutput.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      tempOutput[i] = 0.0;
    }

    convertVector2Ptr(outArray, &tempOutput[0]);
    loop_ub = static_cast<int32_T>(outputSize[1]);
    num_tmp_tmp = static_cast<int32_T>(outputSize[0]);
    output.set_size(num_tmp_tmp, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (int32_T i1{0}; i1 < num_tmp_tmp; i1++) {
        output[i1 + output.size(0) * i] = tempOutput[i + loop_ub * i1];
      }
    }
  }
}

// End of code generation (callCppFunction.cpp)
