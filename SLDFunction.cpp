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
  void SLDFunction(double x, const ::coder::array<double, 2U> &SLD, ::coder::
                   array<double, 1U> &sldVal)
  {
    ::coder::array<double, 1U> aboveY;
    ::coder::array<double, 1U> aboveY_data;
    ::coder::array<double, 1U> r;
    ::coder::array<int, 1U> where;
    ::coder::array<boolean_T, 1U> b_SLD;
    double b_aboveY_data;
    double belowY_data;
    double deltaY_data;
    double tmp_data;
    int tmp_size[2];
    int below_data;
    int below_size;
    int i;
    int loop_ub;
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
    b_SLD.set_size(SLD.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_SLD[i] = (SLD[i] == x);
    }

    coder::eml_find(b_SLD, where);
    if (where.size(0) != 0) {
      sldVal.set_size(where.size(0));
      loop_ub = where.size(0);
      for (i = 0; i < loop_ub; i++) {
        sldVal[i] = SLD[(where[i] + SLD.size(0)) - 1];
      }
    } else {
      int aboveY_size;
      loop_ub = SLD.size(0);
      b_SLD.set_size(SLD.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_SLD[i] = (x > SLD[i]);
      }

      coder::b_eml_find(b_SLD, (int *)&below_data, &below_size);
      loop_ub = SLD.size(0);
      b_SLD.set_size(SLD.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_SLD[i] = (x < SLD[i]);
      }

      coder::c_eml_find(b_SLD, where);
      for (i = 0; i < below_size; i++) {
        belowY_data = SLD[(below_data + SLD.size(0)) - 1];
      }

      aboveY.set_size(where.size(0));
      loop_ub = where.size(0);
      for (i = 0; i < loop_ub; i++) {
        aboveY[i] = SLD[(where[i] + SLD.size(0)) - 1];
      }

      aboveY_size = aboveY.size(0);
      loop_ub = aboveY.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_aboveY_data = aboveY[i] - belowY_data;
      }

      aboveY_data.set(&b_aboveY_data, aboveY_size);
      coder::b_abs(aboveY_data, r);
      aboveY_size = where.size(0);
      loop_ub = where.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_aboveY_data = SLD[where[i] - 1] - SLD[below_data - 1];
      }

      coder::internal::mrdiv((const double *)r.data(), (*(int (*)[1])r.size())[0],
        (const double *)&b_aboveY_data, aboveY_size, (double *)&tmp_data,
        tmp_size);
      for (i = 0; i < below_size; i++) {
        b_aboveY_data = x - SLD[below_data - 1];
      }

      loop_ub = tmp_size[1];
      for (i = 0; i < loop_ub; i++) {
        for (aboveY_size = 0; aboveY_size < below_size; aboveY_size++) {
          deltaY_data = b_aboveY_data * tmp_data;
        }
      }

      for (i = 0; i < below_size; i++) {
        b_belowY_data = (belowY_data < aboveY[0]);
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

  void b_SLDFunction(double x, const ::coder::array<double, 2U> &SLD, ::coder::
                     array<double, 1U> &sldVal)
  {
    ::coder::array<double, 1U> b_aboveY_data;
    ::coder::array<double, 1U> r;
    ::coder::array<int, 1U> b_i;
    ::coder::array<boolean_T, 1U> SLD_data;
    ::coder::array<boolean_T, 1U> c_SLD_data;
    ::coder::array<boolean_T, 1U> d_SLD_data;
    double aboveY_data;
    double belowY_data;
    double c_aboveY_data;
    double deltaY_data;
    double tmp_data;
    int tmp_size[2];
    int SLD_size;
    int below_data;
    int below_size;
    int i;
    int loop_ub;
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
    coder::eml_find(SLD_data, b_i);
    if (b_i.size(0) != 0) {
      sldVal.set_size(b_i.size(0));
      loop_ub = b_i.size(0);
      for (i = 0; i < loop_ub; i++) {
        sldVal[i] = SLD[(b_i[i] + SLD.size(0)) - 1];
      }
    } else {
      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x > SLD[i]);
      }

      c_SLD_data.set(&b_SLD_data[0], SLD_size);
      coder::b_eml_find(c_SLD_data, (int *)&below_data, &below_size);
      loop_ub = SLD.size(0);
      SLD_size = SLD.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_SLD_data[i] = (x < SLD[i]);
      }

      d_SLD_data.set(&b_SLD_data[0], SLD_size);
      coder::c_eml_find(d_SLD_data, b_i);
      for (i = 0; i < below_size; i++) {
        belowY_data = SLD[(below_data + SLD.size(0)) - 1];
      }

      SLD_size = b_i.size(0);
      loop_ub = b_i.size(0);
      for (i = 0; i < loop_ub; i++) {
        aboveY_data = SLD[(b_i[i] + SLD.size(0)) - 1];
      }

      for (i = 0; i < SLD_size; i++) {
        c_aboveY_data = aboveY_data - belowY_data;
      }

      b_aboveY_data.set(&c_aboveY_data, SLD_size);
      coder::b_abs(b_aboveY_data, r);
      SLD_size = b_i.size(0);
      loop_ub = b_i.size(0);
      for (i = 0; i < loop_ub; i++) {
        c_aboveY_data = SLD[b_i[i] - 1] - SLD[below_data - 1];
      }

      coder::internal::mrdiv((const double *)r.data(), (*(int (*)[1])r.size())[0],
        (const double *)&c_aboveY_data, SLD_size, (double *)&tmp_data, tmp_size);
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
