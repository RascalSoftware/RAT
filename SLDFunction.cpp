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
#include "abs.h"
#include "find.h"
#include "ifWhileCond.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void SLDFunction(real_T x, const ::coder::array<real_T, 2U> &SLD, ::coder::
                   array<real_T, 1U> &sldVal)
  {
    ::coder::array<real_T, 1U> b_aboveY_data;
    ::coder::array<real_T, 1U> b_i;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<boolean_T, 1U> SLD_data;
    real_T aboveY_data;
    real_T belowY_data;
    real_T c_aboveY_data;
    real_T deltaY_data;
    real_T tmp_data;
    int32_T tmp_size[2];
    int32_T SLD_size;
    int32_T above_data;
    int32_T below_data;
    int32_T i;
    int32_T loop_ub;
    boolean_T b_SLD_data[10000];
    boolean_T b_belowY_data;

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
        sldVal[i] = SLD[(static_cast<int32_T>(b_i[i]) + SLD.size(0)) - 1];
      }
    } else {
      int32_T below_size;
      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x > SLD[i]);
      }

      coder::b_eml_find(b_SLD_data, SLD_size, (int32_T *)&above_data, &loop_ub);
      below_size = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        below_data = above_data;
      }

      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x < SLD[i]);
      }

      coder::c_eml_find(b_SLD_data, SLD_size, (int32_T *)&above_data, &loop_ub);
      for (i = 0; i < below_size; i++) {
        belowY_data = SLD[(below_data + SLD.size(0)) - 1];
      }

      for (i = 0; i < loop_ub; i++) {
        aboveY_data = SLD[(above_data + SLD.size(0)) - 1];
      }

      for (i = 0; i < loop_ub; i++) {
        c_aboveY_data = aboveY_data - belowY_data;
      }

      b_aboveY_data.set(&c_aboveY_data, loop_ub);
      coder::b_abs(b_aboveY_data, b_i);
      for (i = 0; i < loop_ub; i++) {
        c_aboveY_data = SLD[above_data - 1] - SLD[below_data - 1];
      }

      coder::internal::mrdiv((const real_T *)b_i.data(), (*(int32_T (*)[1])
        b_i.size())[0], (const real_T *)&c_aboveY_data, loop_ub, (real_T *)
        &tmp_data, tmp_size);
      for (i = 0; i < below_size; i++) {
        c_aboveY_data = x - SLD[below_data - 1];
      }

      loop_ub = tmp_size[1];
      for (i = 0; i < loop_ub; i++) {
        for (SLD_size = 0; SLD_size < below_size; SLD_size++) {
          deltaY_data = c_aboveY_data * tmp_data;
        }
      }

      for (i = 0; i < below_size; i++) {
        b_belowY_data = (belowY_data < aboveY_data);
      }

      if (coder::internal::ifWhileCond((const boolean_T *)&b_belowY_data,
           below_size)) {
        sldVal.set_size(below_size);
        for (i = 0; i < below_size; i++) {
          sldVal[0] = belowY_data + deltaY_data;
        }
      } else {
        sldVal.set_size(below_size);
        for (i = 0; i < below_size; i++) {
          sldVal[0] = belowY_data - deltaY_data;
        }
      }
    }
  }
}

// End of code generation (SLDFunction.cpp)
