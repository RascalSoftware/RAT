//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// SLDFunction.cpp
//
// Code generation for function 'SLDFunction'
//

// Include files
#include "SLDFunction.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void SLDFunction(real_T x, const ::coder::array<real_T, 2U> &SLD, ::coder::
                   array<real_T, 1U> &sldVal)
  {
    ::coder::array<int32_T, 1U> b_i;
    ::coder::array<int32_T, 1U> c_i;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<boolean_T, 1U> SLD_data;
    ::coder::array<boolean_T, 1U> c_SLD_data;
    ::coder::array<boolean_T, 1U> d_SLD_data;
    ::coder::array<boolean_T, 1U> e_SLD_data;
    ::coder::array<boolean_T, 1U> f_SLD_data;
    RATMainTLS *RATMainTLSThread;
    int32_T SLD_size;
    int32_T i;
    int32_T loop_ub;
    boolean_T b_SLD_data[10000];
    RATMainTLSThread = emlrtGetThreadStackData();

    //  sldVal = SLDFunction(x,SLD)
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
    // SLD = getappdata(0,'SLDFunctionSLD');
    loop_ub = SLD.size(0);
    SLD_size = SLD.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_SLD_data[i] = (SLD[i] == x);
    }

    SLD_data.set(&b_SLD_data[0], SLD_size);
    coder::eml_find(SLD_data, r);
    b_i.set_size(r.size(0));
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_i[i] = r[i];
    }

    if (b_i.size(0) != 0) {
      sldVal.set_size(b_i.size(0));
      loop_ub = b_i.size(0);
      for (i = 0; i < loop_ub; i++) {
        sldVal[i] = SLD[(b_i[i] + SLD.size(0)) - 1];
      }
    } else {
      real_T deltaY;
      int32_T belowVals_size;
      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x > SLD[i]);
      }

      c_SLD_data.set(&b_SLD_data[0], SLD_size);
      coder::eml_find(c_SLD_data, r);
      b_i.set_size(r.size(0));
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_i[i] = r[i];
      }

      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x > SLD[i]);
      }

      d_SLD_data.set(&b_SLD_data[0], SLD_size);
      coder::eml_find(d_SLD_data, r);
      belowVals_size = r.size(0);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        RATMainTLSThread->f0.belowVals_data[i] = r[i];
      }

      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x < SLD[i]);
      }

      e_SLD_data.set(&b_SLD_data[0], SLD_size);
      coder::eml_find(e_SLD_data, r);
      c_i.set_size(r.size(0));
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        c_i[i] = r[i];
      }

      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x < SLD[i]);
      }

      f_SLD_data.set(&b_SLD_data[0], SLD_size);
      coder::eml_find(f_SLD_data, r);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        RATMainTLSThread->f0.aboveVals_data[i] = r[i];
      }

      deltaY = (x - SLD[b_i[b_i.size(0) - 1] - 1]) * (std::abs(SLD
        [(RATMainTLSThread->f0.aboveVals_data[0] + SLD.size(0)) - 1] - SLD
        [(RATMainTLSThread->f0.belowVals_data[belowVals_size - 1] + SLD.size(0))
        - 1]) / (SLD[RATMainTLSThread->f0.aboveVals_data[0] - 1] -
                 SLD[RATMainTLSThread->f0.belowVals_data[belowVals_size - 1] - 1]));
      if (SLD[(b_i[b_i.size(0) - 1] + SLD.size(0)) - 1] < SLD[(c_i[0] + SLD.size
           (0)) - 1]) {
        sldVal.set_size(1);
        sldVal[0] = SLD[(b_i[b_i.size(0) - 1] + SLD.size(0)) - 1] + deltaY;
      } else {
        sldVal.set_size(1);
        sldVal[0] = SLD[(b_i[b_i.size(0) - 1] + SLD.size(0)) - 1] - deltaY;
      }

      // sldVal = interp1(z,rho,x);
    }
  }
}

// End of code generation (SLDFunction.cpp)
