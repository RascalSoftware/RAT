//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runSimplex.cpp
//
// Code generation for function 'runSimplex'
//

// Include files
#include "runSimplex.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "fMinSearch.h"
#include "packParams.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "simplexXTransform.h"
#include "strcmp.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void runSimplex(d_struct_T *problemStruct, const cell_11 *problemCells, const
                  struct1_T *problemLimits, const struct2_T *controls,
                  e_struct_T *contrastParams, cell_wrap_9 result[6])
  {
    static const char_T b_cv1[6]{ 'n', 'o', 't', 'i', 'f', 'y' };

    static const char_T b_cv[5]{ 'f', 'i', 'n', 'a', 'l' };

    ::coder::array<cell_wrap_1, 1U> b_problemStruct;
    ::coder::array<real_T, 1U> x;
    ::coder::array<real_T, 1U> x0u;
    j_struct_T a__4;
    l_struct_T expl_temp;
    real_T a__2;
    real_T a__3;
    int32_T dis_size[2];
    int32_T b_i;
    int32_T i;
    int32_T outsize_idx_0;
    char_T dis_data[6];
    packParams(problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, b_problemStruct);
    if (coder::internal::r_strcmp(controls->display.data, controls->display.size))
    {
      outsize_idx_0 = 0;
    } else if (coder::internal::s_strcmp(controls->display.data,
                controls->display.size)) {
      outsize_idx_0 = 1;
    } else if (coder::internal::t_strcmp(controls->display.data,
                controls->display.size)) {
      outsize_idx_0 = 2;
    } else if (coder::internal::u_strcmp(controls->display.data,
                controls->display.size)) {
      outsize_idx_0 = 3;
    } else {
      outsize_idx_0 = -1;
    }

    switch (outsize_idx_0) {
     case 0:
      dis_size[0] = 1;
      dis_size[1] = 4;
      dis_data[0] = 'n';
      dis_data[1] = 'o';
      dis_data[2] = 'n';
      dis_data[3] = 'e';
      break;

     case 1:
      dis_size[0] = 1;
      dis_size[1] = 4;
      dis_data[0] = 'i';
      dis_data[1] = 't';
      dis_data[2] = 'e';
      dis_data[3] = 'r';
      break;

     case 2:
      dis_size[0] = 1;
      dis_size[1] = 6;
      for (i = 0; i < 6; i++) {
        dis_data[i] = b_cv1[i];
      }
      break;

     case 3:
      dis_size[0] = 1;
      dis_size[1] = 5;
      for (i = 0; i < 5; i++) {
        dis_data[i] = b_cv[i];
      }
      break;

     default:
      dis_size[0] = 1;
      dis_size[1] = 5;
      for (i = 0; i < 5; i++) {
        dis_data[i] = b_cv[i];
      }
      break;
    }

    outsize_idx_0 = problemStruct->fitLimits.size(0);
    expl_temp.LB.set_size(outsize_idx_0);
    for (i = 0; i < outsize_idx_0; i++) {
      expl_temp.LB[i] = problemStruct->fitLimits[i];
    }

    outsize_idx_0 = problemStruct->fitLimits.size(0);
    expl_temp.UB.set_size(outsize_idx_0);
    for (i = 0; i < outsize_idx_0; i++) {
      expl_temp.UB[i] = problemStruct->fitLimits[i +
        problemStruct->fitLimits.size(0)];
    }

    //  size checks
    if (problemStruct->fitLimits.size(0) == 0) {
      outsize_idx_0 = problemStruct->fitParams.size(0) *
        problemStruct->fitParams.size(1);
      expl_temp.LB.set_size(outsize_idx_0);
      for (i = 0; i < outsize_idx_0; i++) {
        expl_temp.LB[i] = rtMinusInf;
      }
    }

    if (problemStruct->fitLimits.size(0) == 0) {
      outsize_idx_0 = problemStruct->fitParams.size(0) *
        problemStruct->fitParams.size(1);
      expl_temp.UB.set_size(outsize_idx_0);
      for (i = 0; i < outsize_idx_0; i++) {
        expl_temp.UB[i] = rtInf;
      }
    }

    //  stuff into a struct to pass around
    // varargin;
    // problemStruct.modelFilename;%fun;
    //  0 --> unconstrained variable
    //  1 --> lower bound only
    //  2 --> upper bound only
    //  3 --> dual finite bounds
    outsize_idx_0 = problemStruct->fitParams.size(0) *
      problemStruct->fitParams.size(1);
    expl_temp.BoundClass.set_size(outsize_idx_0);
    for (i = 0; i < outsize_idx_0; i++) {
      expl_temp.BoundClass[i] = 0.0;
    }

    i = problemStruct->fitParams.size(0) * problemStruct->fitParams.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      expl_temp.BoundClass[b_i] = static_cast<real_T>((!std::isinf
        (expl_temp.LB[b_i])) && (!std::isnan(expl_temp.LB[b_i]))) + static_cast<
        real_T>(((!std::isinf(expl_temp.UB[b_i])) && (!std::isnan
                  (expl_temp.UB[b_i]))) << 1);
    }

    //  transform starting values into their unconstrained
    //  surrogates. Check for infeasible starting guesses.
    outsize_idx_0 = problemStruct->fitParams.size(0) *
      problemStruct->fitParams.size(1);
    x0u.set_size(outsize_idx_0);
    for (i = 0; i < outsize_idx_0; i++) {
      x0u[i] = problemStruct->fitParams[i];
    }

    i = problemStruct->fitParams.size(0) * problemStruct->fitParams.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      switch (static_cast<int32_T>(expl_temp.BoundClass[b_i])) {
       case 1:
        //  lower bound only
        if (problemStruct->fitParams[b_i] <= expl_temp.LB[b_i]) {
          //  infeasible starting value. Use bound.
          x0u[b_i] = 0.0;
        } else {
          x0u[b_i] = std::sqrt(problemStruct->fitParams[b_i] - expl_temp.LB[b_i]);
        }
        break;

       case 2:
        //  upper bound only
        if (problemStruct->fitParams[b_i] >= expl_temp.UB[b_i]) {
          //  infeasible starting value. use bound.
          x0u[b_i] = 0.0;
        } else {
          x0u[b_i] = std::sqrt(expl_temp.UB[b_i] - problemStruct->fitParams[b_i]);
        }
        break;

       case 3:
        //  lower and upper bounds
        if (problemStruct->fitParams[b_i] <= expl_temp.LB[b_i]) {
          //  infeasible starting value
          x0u[b_i] = -1.5707963267948966;
        } else if (problemStruct->fitParams[b_i] >= expl_temp.UB[b_i]) {
          //  infeasible starting value
          x0u[b_i] = 1.5707963267948966;
        } else {
          x0u[b_i] = 2.0 * (problemStruct->fitParams[b_i] - expl_temp.LB[b_i]) /
            (expl_temp.UB[b_i] - expl_temp.LB[b_i]) - 1.0;
          x0u[b_i] = std::asin(std::fmax(-1.0, std::fmin(1.0, x0u[b_i])));
        }
        break;

       default:
        //  unconstrained variable. x0u(i) is set.
        break;
      }
    }

    //  now we can call fminsearch, but with our own
    //  intra-objective function.
    fMinSearch(x0u, controls->maxIter, controls->maxFunEvals, controls->tolX,
               controls->tolFun, dis_data, dis_size, problemStruct,
               problemCells->f1, problemCells->f2, problemCells->f3,
               problemCells->f4, problemCells->f5, problemCells->f6,
               problemCells->f14, problemCells->f19, controls, &expl_temp, &a__2,
               &a__3, &a__4);

    // [xu,fval,exitflag,output] = simplex(@simplexIntrafun,x0u,problemStruct,problemCells,problemLimits,controls,options,params,300);
    //  undo the variable transformations into the original space
    simplexXTransform(x0u, expl_temp.LB, expl_temp.UB, expl_temp.BoundClass, x);

    //  final reshape
    // x = reshape(x,xsize);
    outsize_idx_0 = x.size(0);
    problemStruct->fitParams.set_size(x.size(0), 1);
    for (i = 0; i < 1; i++) {
      for (int32_T i1{0}; i1 < outsize_idx_0; i1++) {
        problemStruct->fitParams[i1] = x[i1];
      }
    }

    unpackParams(problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    reflectivityCalculation(problemStruct, problemCells, controls,
      contrastParams, result);
  }
}

// End of code generation (runSimplex.cpp)
