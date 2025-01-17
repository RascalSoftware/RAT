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
#include <functional>

// Function Definitions
namespace RAT
{
  void b_callCppFunction(const char_T pointer_data[], const int32_T
    pointer_size[2], const ::coder::array<real_T, 2U> &varargin_1, real_T
    varargin_2, const ::coder::array<real_T, 2U> &varargin_3, real_T varargin_4,
    ::coder::array<real_T, 2U> &output, real_T *varargout_1)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> outArray;
    ::coder::array<real_T, 2U> bulkOut;
    ::coder::array<real_T, 2U> params;
    ::coder::array<real_T, 2U> tempOutput;
    real_T outputSize[2];
    real_T bulkIn;
    int32_T i;
    int32_T loop_ub;
    int32_T num_tmp_tmp;
    char_T b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    params.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = varargin_1[i];
    }

    bulkIn = varargin_2;
    bulkOut.set_size(1, varargin_3.size(1));
    loop_ub = varargin_3.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = varargin_3[i];
    }

    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> paramsArray;
    real_T actualSize;
    paramsArray = convertPtr2Vector(&params[0], static_cast<real_T>
      (varargin_1.size(1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&bulkOut[0], static_cast<real_T>
      (varargin_3.size(1)));

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, varargin_4, 0.0, outArray, &outputSize[0], varargout_1);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int32_T>(actualSize);
    tempOutput.set_size(1, static_cast<int32_T>(actualSize));
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
    pointer_size[2], const ::coder::array<real_T, 2U> &varargin_1, real_T
    varargin_2, const ::coder::array<real_T, 2U> &varargin_3, real_T varargin_4,
    ::coder::array<real_T, 2U> &output, real_T *varargout_1)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> outArray;
    ::coder::array<real_T, 2U> bulkOut;
    ::coder::array<real_T, 2U> params;
    ::coder::array<real_T, 2U> tempOutput;
    real_T outputSize[2];
    real_T bulkIn;
    int32_T i;
    int32_T loop_ub;
    int32_T num_tmp_tmp;
    char_T b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    params.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = varargin_1[i];
    }

    bulkIn = varargin_2;
    bulkOut.set_size(1, varargin_3.size(1));
    loop_ub = varargin_3.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = varargin_3[i];
    }

    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> paramsArray;
    real_T actualSize;
    paramsArray = convertPtr2Vector(&params[0], static_cast<real_T>
      (varargin_1.size(1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&bulkOut[0], static_cast<real_T>
      (varargin_3.size(1)));

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, varargin_4, 1.0, outArray, &outputSize[0], varargout_1);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int32_T>(actualSize);
    tempOutput.set_size(1, static_cast<int32_T>(actualSize));
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
                       const ::coder::array<real_T, 2U> &varargin_1, real_T
                       varargin_2, const ::coder::array<real_T, 2U> &varargin_3,
                       real_T varargin_4, ::coder::array<real_T, 2U> &output,
                       real_T *varargout_1)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> outArray;
    ::coder::array<real_T, 2U> bulkOut;
    ::coder::array<real_T, 2U> params;
    ::coder::array<real_T, 2U> tempOutput;
    real_T outputSize[2];
    real_T bulkIn;
    int32_T i;
    int32_T loop_ub;
    int32_T num_tmp_tmp;
    char_T b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    params.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = varargin_1[i];
    }

    bulkIn = varargin_2;
    bulkOut.set_size(1, varargin_3.size(1));
    loop_ub = varargin_3.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = varargin_3[i];
    }

    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> paramsArray;
    real_T actualSize;
    paramsArray = convertPtr2Vector(&params[0], static_cast<real_T>
      (varargin_1.size(1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&bulkOut[0], static_cast<real_T>
      (varargin_3.size(1)));

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, varargin_4, outArray, &outputSize[0], varargout_1);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int32_T>(actualSize);
    tempOutput.set_size(1, static_cast<int32_T>(actualSize));
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
                       const ::coder::array<real_T, 1U> &varargin_1, const
                       real_T varargin_2_data[], const int32_T varargin_2_size[2],
                       ::coder::array<real_T, 1U> &output)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> dataArray;
    std::vector<double> outArray;
    std::vector<double> paramsArray;
    ::coder::array<real_T, 1U> xdata;
    real_T params_data[5];
    real_T actualSize;
    int32_T i;
    int32_T loop_ub;
    char_T b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0]);
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    xdata.set_size(varargin_1.size(0));
    loop_ub = varargin_1.size(0);
    for (i = 0; i < loop_ub; i++) {
      xdata[i] = varargin_1[i];
    }

    loop_ub = varargin_2_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&varargin_2_data[0], &varargin_2_data[loop_ub], &params_data[0]);
    }

    dataArray = convertPtr2Vector(&(xdata.data())[0], static_cast<real_T>
      (varargin_1.size(0)));
    paramsArray = convertPtr2Vector(&params_data[0], static_cast<real_T>
      (varargin_2_size[1]));
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&)>(&CallbackInterface::invoke)(callback, dataArray,
      paramsArray, outArray);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int32_T>(actualSize);
    output.set_size(static_cast<int32_T>(actualSize));
    for (i = 0; i < loop_ub; i++) {
      output[i] = 0.0;
    }

    convertVector2Ptr(outArray, &(output.data())[0]);
  }
}

// End of code generation (callCppFunction.cpp)
