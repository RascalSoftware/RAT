//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// simplexIntrafun.cpp
//
// Code generation for function 'simplexIntrafun'
//

// Include files
#include "simplexIntrafun.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "simplexXTransform.h"
#include "unpackParams.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void simplexIntrafun(const ::coder::array<real_T, 1U> &x, const d_struct_T
                       *problemStruct, const ::coder::array<cell_wrap_2, 2U>
                       &problemCells_f1, const ::coder::array<cell_wrap_8, 2U>
                       &problemCells_f2, const ::coder::array<cell_wrap_2, 2U>
                       &problemCells_f3, const ::coder::array<cell_wrap_2, 2U>
                       &problemCells_f4, const ::coder::array<cell_wrap_8, 2U>
                       &problemCells_f5, const ::coder::array<cell_wrap_8, 1U>
                       &problemCells_f6, const ::coder::array<cell_wrap_1, 2U>
                       &problemCells_f14, const ::coder::array<cell_wrap_8, 2U>
                       &problemCells_f19, const struct2_T *controls, const
                       l_struct_T *params, real_T *fval, e_struct_T
                       *b_problemStruct, cell_wrap_9 result[6])
  {
    ::coder::array<real_T, 1U> xtrans;
    cell_11 expl_temp;
    d_struct_T c_problemStruct;
    int32_T i;
    int32_T xtrans_idx_0;
    c_problemStruct = *problemStruct;

    //  transform variables, then call original function
    simplexXTransform(x, params->LB, params->UB, params->BoundClass, xtrans);

    // Unpck the params..
    xtrans_idx_0 = xtrans.size(0);
    c_problemStruct.fitParams.set_size(xtrans.size(0), 1);
    for (i = 0; i < 1; i++) {
      for (int32_T i1{0}; i1 < xtrans_idx_0; i1++) {
        c_problemStruct.fitParams[i1] = xtrans[i1];
      }
    }

    unpackParams(&c_problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    expl_temp.f19.set_size(1, problemCells_f19.size(1));
    xtrans_idx_0 = problemCells_f19.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f19[i] = problemCells_f19[i];
    }

    expl_temp.f14.set_size(1, problemCells_f14.size(1));
    xtrans_idx_0 = problemCells_f14.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f14[i] = problemCells_f14[i];
    }

    expl_temp.f6.set_size(problemCells_f6.size(0));
    xtrans_idx_0 = problemCells_f6.size(0);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f6[i] = problemCells_f6[i];
    }

    expl_temp.f5.set_size(1, problemCells_f5.size(1));
    xtrans_idx_0 = problemCells_f5.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f5[i] = problemCells_f5[i];
    }

    expl_temp.f4.set_size(1, problemCells_f4.size(1));
    xtrans_idx_0 = problemCells_f4.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f4[i] = problemCells_f4[i];
    }

    expl_temp.f3.set_size(1, problemCells_f3.size(1));
    xtrans_idx_0 = problemCells_f3.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f3[i] = problemCells_f3[i];
    }

    expl_temp.f2.set_size(1, problemCells_f2.size(1));
    xtrans_idx_0 = problemCells_f2.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f2[i] = problemCells_f2[i];
    }

    expl_temp.f1.set_size(1, problemCells_f1.size(1));
    xtrans_idx_0 = problemCells_f1.size(1);
    for (i = 0; i < xtrans_idx_0; i++) {
      expl_temp.f1[i] = problemCells_f1[i];
    }

    reflectivityCalculation(&c_problemStruct, &expl_temp, controls,
      b_problemStruct, result);
    *fval = b_problemStruct->calculations.sumChi;
  }
}

// End of code generation (simplexIntrafun.cpp)
