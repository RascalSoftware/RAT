//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// shiftData.cpp
//
// Code generation for function 'shiftData'
//

// Include files
#include "shiftData.h"
#include "find.h"
#include "linspace.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void shiftData(double scalefactor, double dataPresent, ::coder::array<double,
                 2U> &data, const double dataLimits[2], const double simLimits[2],
                 ::coder::array<double, 2U> &shiftedData)
  {
    ::coder::array<double, 1U> b_data;
    ::coder::array<int, 1U> b_i;
    ::coder::array<boolean_T, 1U> b_data_data;
    ::coder::array<boolean_T, 1U> c_data_data;
    boolean_T data_data[10000];

    //  Shifts the data according to scale factor. If there is no data, makes
    //  x-data over the simulation range.
    //
    //  INPUTS:
    //      * scalefactor: problemStruct.scalefactors
    //      * qzshift: problemStruct.qzhifts
    //      * dataPresent: problemStruct.dataPresent
    //      * data: problemStruct.data
    //      * dataLimits: problemStruct.dataLimits
    //      * simLimits: problemStruct.simLimits
    //
    //  OUTPUTS:
    //      * shiftedData: Data shifted using given scale factor
    if (static_cast<int>(dataPresent) == 1) {
      int data_size;
      int hiIndex;
      int i;
      int loop_ub;
      int lowIndex;
      if (scalefactor == 0.0) {
        scalefactor = 1.0E-30;
      }

      b_data.set_size(data.size(0));
      loop_ub = data.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_data[i] = data[i];
      }

      loop_ub = b_data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data[i] = b_data[i];
      }

      b_data.set_size(data.size(0));
      loop_ub = data.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_data[i] = data[i + data.size(0)] / scalefactor;
      }

      loop_ub = b_data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data[i + data.size(0)] = b_data[i];
      }

      b_data.set_size(data.size(0));
      loop_ub = data.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_data[i] = data[i + data.size(0) * 2] / scalefactor;
      }

      loop_ub = b_data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data[i + data.size(0) * 2] = b_data[i];
      }

      data_size = data.size(0);
      loop_ub = data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data_data[i] = (data[i] < dataLimits[0]);
      }

      b_data_data.set(&data_data[0], data_size);
      coder::eml_find(b_data_data, b_i);
      if (b_i.size(0) != 0) {
        lowIndex = b_i[b_i.size(0) - 1];
      } else {
        lowIndex = 1;
      }

      data_size = data.size(0);
      loop_ub = data.size(0);
      for (i = 0; i < loop_ub; i++) {
        data_data[i] = (data[i] > dataLimits[1]);
      }

      c_data_data.set(&data_data[0], data_size);
      coder::eml_find(c_data_data, b_i);
      if (b_i.size(0) != 0) {
        hiIndex = b_i[0];
      } else {
        hiIndex = data.size(0);
      }

      if (lowIndex > hiIndex) {
        i = 0;
        data_size = 0;
      } else {
        i = lowIndex - 1;
        data_size = hiIndex;
      }

      loop_ub = data_size - i;
      shiftedData.set_size(loop_ub, 6);
      for (data_size = 0; data_size < 6; data_size++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          shiftedData[i1 + shiftedData.size(0) * data_size] = data[(i + i1) +
            data.size(0) * data_size];
        }
      }
    } else {
      double b_dv[500];
      shiftedData.set_size(500, 6);
      for (int i{0}; i < 6; i++) {
        for (int data_size{0}; data_size < 500; data_size++) {
          shiftedData[data_size + shiftedData.size(0) * i] = 0.0;
        }
      }

      coder::linspace(simLimits[0], simLimits[1], b_dv);
      for (int i{0}; i < 500; i++) {
        shiftedData[i] = b_dv[i];
      }
    }
  }
}

// End of code generation (shiftData.cpp)
