//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  void shiftData(double scalefactor, double qzshift, double dataPresent, ::coder::
                 array<double, 2U> &data, const double dataLimits[2], const
                 double simLimits[2], ::coder::array<double, 2U> &shiftedData)
  {
    ::coder::array<double, 1U> c_data;
    ::coder::array<int, 1U> b_i;
    ::coder::array<boolean_T, 1U> c_data_data;
    ::coder::array<boolean_T, 1U> data_data;
    double b_dv[500];
    boolean_T b_data_data[10000];

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
    switch (static_cast<int>(dataPresent)) {
     case 1:
      {
        int b_data;
        int hiIndex;
        int i;
        int loop_ub;
        int lowIndex;
        if (scalefactor == 0.0) {
          scalefactor = 1.0E-30;
        }

        b_data = data.size(0) - 1;
        c_data.set_size(data.size(0));
        for (i = 0; i <= b_data; i++) {
          c_data[i] = data[i] + qzshift;
        }

        loop_ub = c_data.size(0);
        for (i = 0; i < loop_ub; i++) {
          data[i] = c_data[i];
        }

        b_data = data.size(0) - 1;
        c_data.set_size(data.size(0));
        for (i = 0; i <= b_data; i++) {
          c_data[i] = data[i + data.size(0)] / scalefactor;
        }

        loop_ub = c_data.size(0);
        for (i = 0; i < loop_ub; i++) {
          data[i + data.size(0)] = c_data[i];
        }

        b_data = data.size(0) - 1;
        c_data.set_size(data.size(0));
        for (i = 0; i <= b_data; i++) {
          c_data[i] = data[i + data.size(0) * 2] / scalefactor;
        }

        loop_ub = c_data.size(0);
        for (i = 0; i < loop_ub; i++) {
          data[i + data.size(0) * 2] = c_data[i];
        }

        loop_ub = data.size(0);
        b_data = data.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_data_data[i] = (data[i] < dataLimits[0]);
        }

        data_data.set(&b_data_data[0], b_data);
        coder::eml_find(data_data, b_i);
        if (b_i.size(0) != 0) {
          lowIndex = b_i[b_i.size(0) - 1];
        } else {
          lowIndex = 1;
        }

        loop_ub = data.size(0);
        b_data = data.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_data_data[i] = (data[i] > dataLimits[1]);
        }

        c_data_data.set(&b_data_data[0], b_data);
        coder::eml_find(c_data_data, b_i);
        if (b_i.size(0) != 0) {
          hiIndex = b_i[0];
        } else {
          hiIndex = data.size(0);
        }

        if (lowIndex > hiIndex) {
          i = 0;
          b_data = 0;
        } else {
          i = lowIndex - 1;
          b_data = hiIndex;
        }

        loop_ub = b_data - i;
        shiftedData.set_size(loop_ub, 6);
        for (b_data = 0; b_data < 6; b_data++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            shiftedData[i1 + shiftedData.size(0) * b_data] = data[(i + i1) +
              data.size(0) * b_data];
          }
        }
      }
      break;

     default:
      {
        int i;
        shiftedData.set_size(500, 6);
        for (i = 0; i < 6; i++) {
          for (int b_data{0}; b_data < 500; b_data++) {
            shiftedData[b_data + shiftedData.size(0) * i] = 0.0;
          }
        }

        coder::linspace(simLimits[0], simLimits[1], b_dv);
        for (i = 0; i < 500; i++) {
          shiftedData[i] = b_dv[i];
        }
      }
      break;
    }
  }
}

// End of code generation (shiftData.cpp)
