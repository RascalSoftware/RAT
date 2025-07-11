//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction1.cpp
//
// Code generation for function 'processCustomFunction1'
//

// Include files
#include "processCustomFunction1.h"
#include "RATMain_data.h"
#include "RATMain_types.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coderException.hpp"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    void b_processCustomFunction(const ::coder::array<double, 1U> &bulkIns,
      const ::coder::array<double, 1U> &bulkOuts, const ::coder::array<double,
      2U> &contrastCustomFiles, double numberOfContrasts, const ::coder::array<
      cell_wrap_10, 2U> &customFiles, const ::coder::array<double, 2U>
      &paramValues, boolean_T useImaginary, ::coder::array<cell_wrap_9, 1U>
      &outputs1, ::coder::array<cell_wrap_9, 1U> &outputs2, ::coder::array<
      double, 1U> &subRoughs)
    {
      ::coder::array<double, 2U> b_output1;
      ::coder::array<double, 2U> c_output1;
      ::coder::array<double, 2U> d_output1;
      ::coder::array<double, 2U> output1;
      int i;

      //  Top-level function for processing custom layers for all the contrasts
      i = static_cast<int>(numberOfContrasts);
      subRoughs.set_size(i);
      outputs1.set_size(i);
      outputs2.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
        creal_T x;
        double d;
        int iv[2];
        int b_loop_ub;
        int i1;
        int i2;
        int loop_ub;

        //  Choose which custom file is associated with this contrast
        d = contrastCustomFiles[b_i];
        iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                  static_cast<int>(d) - 1].f1)->size())[0];
        iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                  static_cast<int>(d) - 1].f1)->size())[1];
        x = coder::internal::str2double((const char *)((::coder::array<char, 2U>
          *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv);
        if (std::isnan(x.re) || std::isnan(x.im)) {
          char b_cv[22];

          //  Excecute a custom model function in the base Matlab workspace.
          //  Calling matlab from other languages should be implemented in their wrapper
          //  Ensures a proper exception is thrown in the generated C++ code.
          //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
          //  and other parameters if message is a formatspec.
          //
          //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
          //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
          for (i1 = 0; i1 < 22; i1++) {
            b_cv[i1] = cv1[i1];
          }

          coderException(0.0, &b_cv[0]);
        } else {
          iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(d) - 1].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(d) - 1].f1)->size())[1];
          subRoughs[b_i] = b_callCppFunction((const char *)((::coder::array<char,
            2U> *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv,
            paramValues, bulkIns[b_i], bulkOuts, (static_cast<double>(b_i) + 1.0)
            - 1.0, output1);
          loop_ub = output1.size(1);
          b_output1.set_size(output1.size(0), output1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = output1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              b_output1[i2 + b_output1.size(0) * i1] = output1[i2 + output1.size
                (0) * i1];
            }
          }

          iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(contrastCustomFiles[b_i]) - 1].f1)->size())
            [0];
          iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(contrastCustomFiles[b_i]) - 1].f1)->size())
            [1];
          c_callCppFunction((const char *)((::coder::array<char, 2U> *)
            &customFiles[static_cast<int>(contrastCustomFiles[b_i]) - 1].f1)
                            ->data(), iv, paramValues, bulkIns[b_i], bulkOuts, (
            static_cast<double>(b_i) + 1.0) - 1.0, output1);
        }

        //  If SLD is real, add dummy imaginary column
        if (!useImaginary) {
          int result;
          signed char b_input_sizes_idx_1;
          signed char input_sizes_idx_1;
          signed char sizes_idx_1;
          boolean_T empty_non_axis_sizes;
          if (b_output1.size(1) < 3) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = 2;
            i2 = 3;
          }

          if (b_output1.size(0) != 0) {
            result = b_output1.size(0);
          } else {
            result = 0;
          }

          empty_non_axis_sizes = (result == 0);
          if (empty_non_axis_sizes || (b_output1.size(0) != 0)) {
            input_sizes_idx_1 = 2;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || (b_output1.size(0) != 0)) {
            b_input_sizes_idx_1 = 1;
          } else {
            b_input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || ((b_output1.size(0) != 0) && (i2 - i1 != 0)))
          {
            sizes_idx_1 = static_cast<signed char>(i2 - i1);
          } else {
            sizes_idx_1 = 0;
          }

          c_output1.set_size(b_output1.size(0), 2);
          loop_ub = b_output1.size(0);
          for (int i3{0}; i3 < 2; i3++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              c_output1[b_loop_ub + c_output1.size(0) * i3] =
                b_output1[b_loop_ub + b_output1.size(0) * i3];
            }
          }

          loop_ub = i2 - i1;
          d_output1.set_size(b_output1.size(0), loop_ub);
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_loop_ub = b_output1.size(0);
            for (int i3{0}; i3 < b_loop_ub; i3++) {
              d_output1[i3 + d_output1.size(0) * i2] = b_output1[i3 +
                b_output1.size(0) * (i1 + i2)];
            }
          }

          outputs1[b_i].f1.set_size(result, (input_sizes_idx_1 +
            b_input_sizes_idx_1) + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * i1] =
                c_output1[i2 + result * i1];
            }
          }

          loop_ub = b_input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * input_sizes_idx_1]
                = 0.0;
            }
          }

          loop_ub = sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * ((i1 +
                input_sizes_idx_1) + b_input_sizes_idx_1)] = d_output1[i2 +
                result * i1];
            }
          }

          if (output1.size(1) < 3) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = 2;
            i2 = 3;
          }

          loop_ub = output1.size(0);
          if (output1.size(0) != 0) {
            result = output1.size(0);
          } else {
            result = 0;
          }

          empty_non_axis_sizes = (result == 0);
          if (empty_non_axis_sizes || (output1.size(0) != 0)) {
            input_sizes_idx_1 = 2;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || (output1.size(0) != 0)) {
            b_input_sizes_idx_1 = 1;
          } else {
            b_input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || ((output1.size(0) != 0) && (i2 - i1 != 0)))
          {
            sizes_idx_1 = static_cast<signed char>(i2 - i1);
          } else {
            sizes_idx_1 = 0;
          }

          c_output1.set_size(output1.size(0), 2);
          for (int i3{0}; i3 < 2; i3++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              c_output1[b_loop_ub + c_output1.size(0) * i3] = output1[b_loop_ub
                + output1.size(0) * i3];
            }
          }

          loop_ub = i2 - i1;
          d_output1.set_size(output1.size(0), loop_ub);
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_loop_ub = output1.size(0);
            for (int i3{0}; i3 < b_loop_ub; i3++) {
              d_output1[i3 + d_output1.size(0) * i2] = output1[i3 + output1.size
                (0) * (i1 + i2)];
            }
          }

          outputs2[b_i].f1.set_size(result, (input_sizes_idx_1 +
            b_input_sizes_idx_1) + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * i1] =
                c_output1[i2 + result * i1];
            }
          }

          loop_ub = b_input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * input_sizes_idx_1]
                = 0.0;
            }
          }

          loop_ub = sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * ((i1 +
                input_sizes_idx_1) + b_input_sizes_idx_1)] = d_output1[i2 +
                result * i1];
            }
          }
        } else {
          outputs1[b_i].f1.set_size(b_output1.size(0), b_output1.size(1));
          loop_ub = b_output1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = b_output1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * i1] =
                b_output1[i2 + b_output1.size(0) * i1];
            }
          }

          loop_ub = output1.size(1);
          outputs2[b_i].f1.set_size(output1.size(0), output1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = output1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * i1] = output1[i2
                + output1.size(0) * i1];
            }
          }
        }
      }
    }

    void processCustomFunction(const ::coder::array<double, 1U> &bulkIns, const ::
      coder::array<double, 1U> &bulkOuts, const ::coder::array<double, 2U>
      &contrastCustomFiles, double numberOfContrasts, const ::coder::array<
      cell_wrap_10, 2U> &customFiles, const ::coder::array<double, 2U>
      &paramValues, boolean_T useImaginary, ::coder::array<cell_wrap_9, 1U>
      &outputs1, ::coder::array<cell_wrap_9, 1U> &outputs2, ::coder::array<
      double, 1U> &subRoughs)
    {
      ::coder::array<double, 2U> b_output1;
      ::coder::array<double, 2U> c_output1;
      ::coder::array<double, 2U> d_output1;
      ::coder::array<double, 2U> output1;
      int i;

      //  Top-level function for processing custom layers for all the contrasts
      i = static_cast<int>(numberOfContrasts);
      subRoughs.set_size(i);
      outputs1.set_size(i);
      outputs2.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
        creal_T x;
        double d;
        int iv[2];
        int b_loop_ub;
        int i1;
        int i2;
        int loop_ub;

        //  Choose which custom file is associated with this contrast
        d = contrastCustomFiles[b_i];
        iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                  static_cast<int>(d) - 1].f1)->size())[0];
        iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                  static_cast<int>(d) - 1].f1)->size())[1];
        x = coder::internal::str2double((const char *)((::coder::array<char, 2U>
          *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv);
        if (std::isnan(x.re) || std::isnan(x.im)) {
          char b_cv[22];

          //  Excecute a custom model function in the base Matlab workspace.
          //  Calling matlab from other languages should be implemented in their wrapper
          //  Ensures a proper exception is thrown in the generated C++ code.
          //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
          //  and other parameters if message is a formatspec.
          //
          //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
          //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
          for (i1 = 0; i1 < 22; i1++) {
            b_cv[i1] = cv1[i1];
          }

          coderException(0.0, &b_cv[0]);
        } else {
          iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(d) - 1].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(d) - 1].f1)->size())[1];
          subRoughs[b_i] = b_callCppFunction((const char *)((::coder::array<char,
            2U> *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv,
            paramValues, bulkIns[b_i], bulkOuts, (static_cast<double>(b_i) + 1.0)
            - 1.0, output1);
          loop_ub = output1.size(1);
          b_output1.set_size(output1.size(0), output1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = output1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              b_output1[i2 + b_output1.size(0) * i1] = output1[i2 + output1.size
                (0) * i1];
            }
          }

          iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(contrastCustomFiles[b_i]) - 1].f1)->size())
            [0];
          iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(contrastCustomFiles[b_i]) - 1].f1)->size())
            [1];
          c_callCppFunction((const char *)((::coder::array<char, 2U> *)
            &customFiles[static_cast<int>(contrastCustomFiles[b_i]) - 1].f1)
                            ->data(), iv, paramValues, bulkIns[b_i], bulkOuts, (
            static_cast<double>(b_i) + 1.0) - 1.0, output1);
        }

        //  If SLD is real, add dummy imaginary column
        if (!useImaginary) {
          int result;
          signed char b_input_sizes_idx_1;
          signed char input_sizes_idx_1;
          signed char sizes_idx_1;
          boolean_T empty_non_axis_sizes;
          if (b_output1.size(1) < 3) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = 2;
            i2 = b_output1.size(1);
          }

          if (b_output1.size(0) != 0) {
            result = b_output1.size(0);
          } else {
            result = 0;
          }

          empty_non_axis_sizes = (result == 0);
          if (empty_non_axis_sizes || (b_output1.size(0) != 0)) {
            input_sizes_idx_1 = 2;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || (b_output1.size(0) != 0)) {
            b_input_sizes_idx_1 = 1;
          } else {
            b_input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || ((b_output1.size(0) != 0) && (i2 - i1 != 0)))
          {
            sizes_idx_1 = static_cast<signed char>(i2 - i1);
          } else {
            sizes_idx_1 = 0;
          }

          c_output1.set_size(b_output1.size(0), 2);
          loop_ub = b_output1.size(0);
          for (int i3{0}; i3 < 2; i3++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              c_output1[b_loop_ub + c_output1.size(0) * i3] =
                b_output1[b_loop_ub + b_output1.size(0) * i3];
            }
          }

          loop_ub = i2 - i1;
          d_output1.set_size(b_output1.size(0), loop_ub);
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_loop_ub = b_output1.size(0);
            for (int i3{0}; i3 < b_loop_ub; i3++) {
              d_output1[i3 + d_output1.size(0) * i2] = b_output1[i3 +
                b_output1.size(0) * (i1 + i2)];
            }
          }

          outputs1[b_i].f1.set_size(result, (input_sizes_idx_1 +
            b_input_sizes_idx_1) + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * i1] =
                c_output1[i2 + result * i1];
            }
          }

          loop_ub = b_input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * input_sizes_idx_1]
                = 0.0;
            }
          }

          loop_ub = sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * ((i1 +
                input_sizes_idx_1) + b_input_sizes_idx_1)] = d_output1[i2 +
                result * i1];
            }
          }

          if (output1.size(1) < 3) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = 2;
            i2 = output1.size(1);
          }

          loop_ub = output1.size(0);
          if (output1.size(0) != 0) {
            result = output1.size(0);
          } else {
            result = 0;
          }

          empty_non_axis_sizes = (result == 0);
          if (empty_non_axis_sizes || (output1.size(0) != 0)) {
            input_sizes_idx_1 = 2;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || (output1.size(0) != 0)) {
            b_input_sizes_idx_1 = 1;
          } else {
            b_input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || ((output1.size(0) != 0) && (i2 - i1 != 0)))
          {
            sizes_idx_1 = static_cast<signed char>(i2 - i1);
          } else {
            sizes_idx_1 = 0;
          }

          c_output1.set_size(output1.size(0), 2);
          for (int i3{0}; i3 < 2; i3++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              c_output1[b_loop_ub + c_output1.size(0) * i3] = output1[b_loop_ub
                + output1.size(0) * i3];
            }
          }

          loop_ub = i2 - i1;
          d_output1.set_size(output1.size(0), loop_ub);
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_loop_ub = output1.size(0);
            for (int i3{0}; i3 < b_loop_ub; i3++) {
              d_output1[i3 + d_output1.size(0) * i2] = output1[i3 + output1.size
                (0) * (i1 + i2)];
            }
          }

          outputs2[b_i].f1.set_size(result, (input_sizes_idx_1 +
            b_input_sizes_idx_1) + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * i1] =
                c_output1[i2 + result * i1];
            }
          }

          loop_ub = b_input_sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * input_sizes_idx_1]
                = 0.0;
            }
          }

          loop_ub = sizes_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < result; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * ((i1 +
                input_sizes_idx_1) + b_input_sizes_idx_1)] = d_output1[i2 +
                result * i1];
            }
          }
        } else {
          outputs1[b_i].f1.set_size(b_output1.size(0), b_output1.size(1));
          loop_ub = b_output1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = b_output1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              outputs1[b_i].f1[i2 + outputs1[b_i].f1.size(0) * i1] =
                b_output1[i2 + b_output1.size(0) * i1];
            }
          }

          loop_ub = output1.size(1);
          outputs2[b_i].f1.set_size(output1.size(0), output1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = output1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              outputs2[b_i].f1[i2 + outputs2[b_i].f1.size(0) * i1] = output1[i2
                + output1.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (processCustomFunction1.cpp)
