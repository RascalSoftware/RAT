//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sldFunc.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "sldFunc.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// sldVal = sldFunc(x,SLD)
//  SLD = [x rho;....xn rho]
//    x = value in Angstrom.
//
//  This function returns the SLD (y) value associated with the
//  supplied value of x. SLD is a two column, XY array defining an
//  SLD profile. This function interpolates the SLD profile
//  to return the SLD at the specific value of X. X can be a vector of
//  multiple points.
//
//  (c) Arwel Hughes 2019.
//  Last modified - AVH, 26/11/19.
//  global sldProfile
//
//  SLD = sldProfile;
//
// Arguments    : real_T x
//                const ::coder::array<real_T, 2U> &SLD
//                ::coder::array<real_T, 1U> &sldVal
// Return Type  : void
//
namespace RAT
{
  void sldFunc(real_T x, const ::coder::array<real_T, 2U> &SLD, ::coder::array<
               real_T, 1U> &sldVal)
  {
    ::coder::array<int32_T, 1U> belowVals;
    ::coder::array<int32_T, 1U> where;
    ::coder::array<boolean_T, 1U> b_SLD;
    int32_T loop_ub;

    // SLD = getappdata(0,'sldFuncSLD');
    b_SLD.set_size(SLD.size(0));
    loop_ub = SLD.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      b_SLD[i] = (SLD[i] == x);
    }

    coder::eml_find(b_SLD, where);
    if (where.size(0) != 0) {
      sldVal.set_size(where.size(0));
      loop_ub = where.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        sldVal[i] = SLD[(where[i] + SLD.size(0)) - 1];
      }
    } else {
      real_T deltaY;
      real_T deltaY_tmp;
      b_SLD.set_size(SLD.size(0));
      loop_ub = SLD.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        b_SLD[i] = (x > SLD[i]);
      }

      coder::eml_find(b_SLD, where);
      belowVals.set_size(where.size(0));
      loop_ub = where.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        belowVals[i] = where[i];
      }

      b_SLD.set_size(SLD.size(0));
      loop_ub = SLD.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        b_SLD[i] = (x < SLD[i]);
      }

      coder::eml_find(b_SLD, where);
      deltaY_tmp = SLD[(where[0] + SLD.size(0)) - 1];
      deltaY = (x - SLD[belowVals[belowVals.size(0) - 1] - 1]) * (std::abs
        (deltaY_tmp - SLD[(belowVals[belowVals.size(0) - 1] + SLD.size(0)) - 1])
        / (SLD[where[0] - 1] - SLD[belowVals[belowVals.size(0) - 1] - 1]));
      if (SLD[(belowVals[belowVals.size(0) - 1] + SLD.size(0)) - 1] < deltaY_tmp)
      {
        sldVal.set_size(1);
        sldVal[0] = SLD[(belowVals[belowVals.size(0) - 1] + SLD.size(0)) - 1] +
          deltaY;
      } else {
        sldVal.set_size(1);
        sldVal[0] = SLD[(belowVals[belowVals.size(0) - 1] + SLD.size(0)) - 1] -
          deltaY;
      }

      // sldVal = interp1(z,rho,x);
    }
  }

  //
  // sldVal = sldFunc(x,SLD)
  //  SLD = [x rho;....xn rho]
  //    x = value in Angstrom.
  //
  //  This function returns the SLD (y) value associated with the
  //  supplied value of x. SLD is a two column, XY array defining an
  //  SLD profile. This function interpolates the SLD profile
  //  to return the SLD at the specific value of X. X can be a vector of
  //  multiple points.
  //
  //  (c) Arwel Hughes 2019.
  //  Last modified - AVH, 26/11/19.
  //  global sldProfile
  //
  //  SLD = sldProfile;
  //
  // Arguments    : real_T x
  //                const real_T SLD_data[]
  //                const int32_T SLD_size[2]
  //                real_T sldVal_data[]
  //                int32_T *sldVal_size
  // Return Type  : void
  //
  void sldFunc(real_T x, const real_T SLD_data[], const int32_T SLD_size[2],
               real_T sldVal_data[], int32_T *sldVal_size)
  {
    ::coder::array<int32_T, 1U> b_i;
    ::coder::array<int32_T, 1U> c_i;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<boolean_T, 1U> c_SLD_data;
    ::coder::array<boolean_T, 1U> d_SLD_data;
    ::coder::array<boolean_T, 1U> e_SLD_data;
    ::coder::array<boolean_T, 1U> f_SLD_data;
    ::coder::array<boolean_T, 1U> g_SLD_data;
    int32_T loop_ub;
    boolean_T b_SLD_data[2];

    // SLD = getappdata(0,'sldFuncSLD');
    loop_ub = SLD_size[0];
    for (int32_T i{0}; i < loop_ub; i++) {
      b_SLD_data[i] = (SLD_data[i] == x);
    }

    c_SLD_data.set(&b_SLD_data[0], SLD_size[0]);
    coder::eml_find(c_SLD_data, r);
    b_i.set_size(r.size(0));
    loop_ub = r.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      b_i[i] = r[i];
    }

    if (b_i.size(0) != 0) {
      *sldVal_size = b_i.size(0);
      loop_ub = b_i.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        sldVal_data[i] = SLD_data[(b_i[i] + SLD_size[0]) - 1];
      }
    } else {
      real_T deltaY;
      int32_T belowVals_data[2];
      int32_T belowVals_size;
      loop_ub = SLD_size[0];
      for (int32_T i{0}; i < loop_ub; i++) {
        b_SLD_data[i] = (x > SLD_data[i]);
      }

      d_SLD_data.set(&b_SLD_data[0], SLD_size[0]);
      coder::eml_find(d_SLD_data, r);
      b_i.set_size(r.size(0));
      loop_ub = r.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        b_i[i] = r[i];
      }

      loop_ub = SLD_size[0];
      for (int32_T i{0}; i < loop_ub; i++) {
        b_SLD_data[i] = (x > SLD_data[i]);
      }

      e_SLD_data.set(&b_SLD_data[0], SLD_size[0]);
      coder::eml_find(e_SLD_data, r);
      belowVals_size = r.size(0);
      loop_ub = r.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        belowVals_data[i] = r[i];
      }

      loop_ub = SLD_size[0];
      for (int32_T i{0}; i < loop_ub; i++) {
        b_SLD_data[i] = (x < SLD_data[i]);
      }

      f_SLD_data.set(&b_SLD_data[0], SLD_size[0]);
      coder::eml_find(f_SLD_data, r);
      c_i.set_size(r.size(0));
      loop_ub = r.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        c_i[i] = r[i];
      }

      loop_ub = SLD_size[0];
      for (int32_T i{0}; i < loop_ub; i++) {
        b_SLD_data[i] = (x < SLD_data[i]);
      }

      g_SLD_data.set(&b_SLD_data[0], SLD_size[0]);
      coder::eml_find(g_SLD_data, r);
      belowVals_size = belowVals_data[belowVals_size - 1];
      deltaY = (x - SLD_data[b_i[b_i.size(0) - 1] - 1]) * (std::abs(SLD_data[(r
        [0] + SLD_size[0]) - 1] - SLD_data[(belowVals_size + SLD_size[0]) - 1]) /
        (SLD_data[r[0] - 1] - SLD_data[belowVals_size - 1]));
      if (SLD_data[(b_i[b_i.size(0) - 1] + SLD_size[0]) - 1] < SLD_data[(c_i[0]
           + SLD_size[0]) - 1]) {
        *sldVal_size = 1;
        sldVal_data[0] = deltaY;
      } else {
        *sldVal_size = 1;
        sldVal_data[0] = SLD_data[(b_i[b_i.size(0) - 1] + SLD_size[0]) - 1] -
          deltaY;
      }

      // sldVal = interp1(z,rho,x);
    }
  }
}

//
// File trailer for sldFunc.cpp
//
// [EOF]
//
