//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// callCppFunction.cpp
//
// Code generation for function 'callCppFunction'
//

// Include files
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "validate_print_arguments.h"
#include "classHandle.hpp"
#include "coderException.hpp"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <functional>

// Function Definitions
namespace RAT
{
  double b_callCppFunction(const char pointer_data[], const int pointer_size[2],
    const ::coder::array<double, 2U> &varargin_1, double varargin_2, const ::
    coder::array<double, 1U> &varargin_3, double varargin_4, ::coder::array<
    double, 2U> &output)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> outArray;
    ::coder::array<double, 2U> params;
    ::coder::array<double, 2U> tempOutput;
    ::coder::array<double, 1U> bulkOut;
    ::coder::array<char, 2U> charStr;
    double outputSize[2];
    double actualSize;
    double bulkIn;
    double d;
    double varargout_1;
    int i;
    int loop_ub;
    int loop_ub_tmp;
    char b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0], static_cast<double>(pointer_size[1]));
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    params.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = varargin_1[i];
    }

    bulkIn = varargin_2;
    bulkOut.set_size(varargin_3.size(0));
    loop_ub = varargin_3.size(0);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = varargin_3[i];
    }

    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> paramsArray;
    paramsArray = convertPtr2Vector(&params[0], static_cast<double>
      (varargin_1.size(1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&(bulkOut.data())[0], static_cast<double>
      (varargin_3.size(0)));

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, varargin_4, 0.0, outArray, &outputSize[0], &varargout_1);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int>(actualSize);
    tempOutput.set_size(1, static_cast<int>(actualSize));
    for (i = 0; i < loop_ub; i++) {
      tempOutput[i] = 0.0;
    }

    convertVector2Ptr(outArray, &tempOutput[0]);
    d = std::round(outputSize[0] * outputSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = static_cast<int>(d);
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }

    if (i != actualSize) {
      double validatedHoleFilling[3];

      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      coder::internal::validate_print_arguments(actualSize, outputSize[0],
        outputSize[1], validatedHoleFilling);
      coder::snPrint(validatedHoleFilling[0], validatedHoleFilling[1],
                     validatedHoleFilling[2], charStr);
      coderException(2.0, &charStr[0]);
    }

    loop_ub_tmp = static_cast<int>(outputSize[1]);
    loop_ub = static_cast<int>(outputSize[0]);
    output.set_size(loop_ub, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        output[i1 + output.size(0) * i] = tempOutput[i + loop_ub_tmp * i1];
      }
    }

    return varargout_1;
  }

  double c_callCppFunction(const char pointer_data[], const int pointer_size[2],
    const ::coder::array<double, 2U> &varargin_1, double varargin_2, const ::
    coder::array<double, 1U> &varargin_3, double varargin_4, ::coder::array<
    double, 2U> &output)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> outArray;
    ::coder::array<double, 2U> params;
    ::coder::array<double, 2U> tempOutput;
    ::coder::array<double, 1U> bulkOut;
    ::coder::array<char, 2U> charStr;
    double outputSize[2];
    double actualSize;
    double bulkIn;
    double d;
    double varargout_1;
    int i;
    int loop_ub;
    int loop_ub_tmp;
    char b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0], static_cast<double>(pointer_size[1]));
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    params.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = varargin_1[i];
    }

    bulkIn = varargin_2;
    bulkOut.set_size(varargin_3.size(0));
    loop_ub = varargin_3.size(0);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = varargin_3[i];
    }

    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> paramsArray;
    paramsArray = convertPtr2Vector(&params[0], static_cast<double>
      (varargin_1.size(1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&(bulkOut.data())[0], static_cast<double>
      (varargin_3.size(0)));

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, varargin_4, 1.0, outArray, &outputSize[0], &varargout_1);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int>(actualSize);
    tempOutput.set_size(1, static_cast<int>(actualSize));
    for (i = 0; i < loop_ub; i++) {
      tempOutput[i] = 0.0;
    }

    convertVector2Ptr(outArray, &tempOutput[0]);
    d = std::round(outputSize[0] * outputSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = static_cast<int>(d);
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }

    if (i != actualSize) {
      double validatedHoleFilling[3];

      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      coder::internal::validate_print_arguments(actualSize, outputSize[0],
        outputSize[1], validatedHoleFilling);
      coder::snPrint(validatedHoleFilling[0], validatedHoleFilling[1],
                     validatedHoleFilling[2], charStr);
      coderException(2.0, &charStr[0]);
    }

    loop_ub_tmp = static_cast<int>(outputSize[1]);
    loop_ub = static_cast<int>(outputSize[0]);
    output.set_size(loop_ub, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        output[i1 + output.size(0) * i] = tempOutput[i + loop_ub_tmp * i1];
      }
    }

    return varargout_1;
  }

  double callCppFunction(const char pointer_data[], const int pointer_size[2],
    const ::coder::array<double, 2U> &varargin_1, double varargin_2, const ::
    coder::array<double, 1U> &varargin_3, double varargin_4, ::coder::array<
    double, 2U> &output)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> outArray;
    ::coder::array<double, 2U> params;
    ::coder::array<double, 2U> tempOutput;
    ::coder::array<double, 1U> bulkOut;
    ::coder::array<char, 2U> charStr;
    double outputSize[2];
    double actualSize;
    double bulkIn;
    double d;
    double varargout_1;
    int i;
    int loop_ub;
    int loop_ub_tmp;
    char b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0], static_cast<double>(pointer_size[1]));
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    params.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = varargin_1[i];
    }

    bulkIn = varargin_2;
    bulkOut.set_size(varargin_3.size(0));
    loop_ub = varargin_3.size(0);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = varargin_3[i];
    }

    std::vector<double> bulkInArray;
    std::vector<double> bulkOutArray;
    std::vector<double> paramsArray;
    paramsArray = convertPtr2Vector(&params[0], static_cast<double>
      (varargin_1.size(1)));
    bulkInArray = convertPtr2Vector(&bulkIn, 1.0);
    bulkOutArray = convertPtr2Vector(&(bulkOut.data())[0], static_cast<double>
      (varargin_3.size(0)));

    //  domain should either before 0 or 1. A value less than zero indicates no domains
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&, int, std::vector<double>&, double*, double*)>
      (&CallbackInterface::invoke)(callback, paramsArray, bulkInArray,
      bulkOutArray, varargin_4, outArray, &outputSize[0], &varargout_1);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int>(actualSize);
    tempOutput.set_size(1, static_cast<int>(actualSize));
    for (i = 0; i < loop_ub; i++) {
      tempOutput[i] = 0.0;
    }

    convertVector2Ptr(outArray, &tempOutput[0]);
    d = std::round(outputSize[0] * outputSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = static_cast<int>(d);
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }

    if (i != actualSize) {
      double validatedHoleFilling[3];

      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      coder::internal::validate_print_arguments(actualSize, outputSize[0],
        outputSize[1], validatedHoleFilling);
      coder::snPrint(validatedHoleFilling[0], validatedHoleFilling[1],
                     validatedHoleFilling[2], charStr);
      coderException(2.0, &charStr[0]);
    }

    loop_ub_tmp = static_cast<int>(outputSize[1]);
    loop_ub = static_cast<int>(outputSize[0]);
    output.set_size(loop_ub, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        output[i1 + output.size(0) * i] = tempOutput[i + loop_ub_tmp * i1];
      }
    }

    return varargout_1;
  }

  void callCppFunction(const char pointer_data[], const int pointer_size[2],
                       const ::coder::array<double, 1U> &varargin_1, const
                       double varargin_2_data[], const int varargin_2_size[2], ::
                       coder::array<double, 1U> &output)
  {
    CallbackInterface * callback;
    ClassHandle<CallbackInterface> * callbackHandle;
    std::vector<double> dataArray;
    std::vector<double> outArray;
    std::vector<double> paramsArray;
    ::coder::array<double, 1U> xdata;
    double params_data[5];
    double actualSize;
    int loop_ub;
    char b_pointer_data[10000];

    //  Calls a Cpp custom function stored at the given pointer address.
    //
    //  data = callCppFunction(pointer, xdata, params)
    //  [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);
    loop_ub = pointer_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&pointer_data[0], &pointer_data[loop_ub], &b_pointer_data[0]);
    }

    callbackHandle = convertString2HandlePtr<CallbackInterface>(&b_pointer_data
      [0], static_cast<double>(pointer_size[1]));
    callback = std::mem_fn(&ClassHandle<CallbackInterface>::ptr)(callbackHandle);
    outArray = { };

    xdata.set_size(varargin_1.size(0));
    loop_ub = varargin_1.size(0);
    for (int i{0}; i < loop_ub; i++) {
      xdata[i] = varargin_1[i];
    }

    loop_ub = varargin_2_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&varargin_2_data[0], &varargin_2_data[loop_ub], &params_data[0]);
    }

    dataArray = convertPtr2Vector(&(xdata.data())[0], static_cast<double>
      (varargin_1.size(0)));
    paramsArray = convertPtr2Vector(&params_data[0], static_cast<double>
      (varargin_2_size[1]));
    std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<
                     double>&)>(&CallbackInterface::invoke)(callback, dataArray,
      paramsArray, outArray);
    actualSize = getVectorSize(outArray);
    loop_ub = static_cast<int>(actualSize);
    output.set_size(static_cast<int>(actualSize));
    for (int i{0}; i < loop_ub; i++) {
      output[i] = 0.0;
    }

    convertVector2Ptr(outArray, &(output.data())[0]);
  }
}

// End of code generation (callCppFunction.cpp)
