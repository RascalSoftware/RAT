//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// deopt.cpp
//
// Code generation for function 'deopt'
//

// Include files
#include "deopt.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "leftWin.h"
#include "mergesort.h"
#include "print_processing.h"
#include "rand.h"
#include "randperm.h"
#include "rem.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  void deopt(const d_struct_T *problem, const ::coder::array<cell_wrap_2, 2U>
             &problemCells_f1, const ::coder::array<cell_wrap_8, 2U>
             &problemCells_f2, const ::coder::array<cell_wrap_2, 2U>
             &problemCells_f3, const ::coder::array<cell_wrap_2, 2U>
             &problemCells_f4, const ::coder::array<cell_wrap_8, 2U>
             &problemCells_f5, const ::coder::array<cell_wrap_8, 1U>
             &problemCells_f6, const ::coder::array<cell_wrap_1, 2U>
             &problemCells_f14, const ::coder::array<cell_wrap_8, 2U>
             &problemCells_f19, const char_T controls_parallel_data[], const
             int32_T controls_parallel_size[2], const real_T controls_resamPars
             [2], boolean_T controls_calcSldDuringFit, const char_T
             controls_display_data[], const int32_T controls_display_size[2],
             const struct3_T *controls_checks, const k_struct_T *S_struct, ::
             coder::array<real_T, 2U> &FVr_bestmem)
  {
    ::coder::array<struct_T, 1U> S_val;
    ::coder::array<real_T, 2U> FM_pm3;
    ::coder::array<real_T, 2U> FM_pop;
    ::coder::array<real_T, 2U> FM_ui;
    ::coder::array<real_T, 2U> FVr_a1;
    ::coder::array<real_T, 2U> FVr_a2;
    ::coder::array<real_T, 2U> FVr_a3;
    ::coder::array<real_T, 2U> FVr_rot;
    ::coder::array<real_T, 2U> FVr_rt;
    ::coder::array<real_T, 2U> b_FM_pop;
    ::coder::array<real_T, 2U> b_FVr_rot;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::array<boolean_T, 2U> FM_mui;
    d_struct_T b_problem;
    real_T validatedHoleFilling[5];
    real_T p[4];
    real_T F_CR;
    real_T I_D;
    real_T I_NP;
    real_T I_iter;
    real_T I_itermax;
    real_T S_bestval_FVr_oa;
    real_T b;
    real_T fWeight;
    int32_T iv[4];
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T k;
    int32_T loop_ub;
    int32_T loop_ub_tmp;

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Function:         [FVr_bestmem,S_bestval,I_nfeval] = deopt(fname,S_struct)
    //
    //  Author:           Rainer Storn, Ken Price, Arnold Neumaier, Jim Van Zandt
    //  Description:      Minimization of a user-supplied function with respect to x(1:I_D),
    //                    using the differential evolution (DE) algorithm.
    //                    DE works best if [FVr_minbound,FVr_maxbound] covers the region where the
    //                    global minimum is expected. DE is also somewhat sensitive to
    //                    the choice of the stepsize fWeight. A good initial guess is to
    //                    choose fWeight from interval [0.5, 1], e.g. 0.8. F_CR, the crossover
    //                    probability constant from interval [0, 1] helps to maintain
    //                    the diversity of the population but should be close to 1 for most.
    //                    practical cases. Only separable problems do better with CR close to 0.
    //                    If the parameters are correlated, high values of F_CR work better.
    //                    The reverse is true for no correlation.
    //
    //                    The number of population members I_NP is also not very critical. A
    //                    good initial guess is 10*I_D. Depending on the difficulty of the
    //                    problem I_NP can be lower than 10*I_D or must be higher than 10*I_D
    //                    to achieve convergence.
    //
    //                    deopt is a vectorized variant of DE which, however, has a
    //                    property which differs from the original version of DE:
    //                    The random selection of vectors is performed by shuffling the
    //                    population array. Hence a certain vector can't be chosen twice
    //                    in the same term of the perturbation expression.
    //                    Due to the vectorized expressions deopt executes fairly fast
    //                    in MATLAB's interpreter environment.
    //
    //  Parameters:       fname        (I)    String naming a function f(x,y) to minimize.
    //                    S_struct     (I)    Problem data vector (must remain fixed during the
    //                                        minimization). For details see Rundeopt.m.
    //                    ---------members of S_struct----------------------------------------------------
    //                    F_VTR        (I)    "Value To Reach". deopt will stop its minimization
    //                                        if either the maximum number of iterations "I_itermax"
    //                                        is reached or the best parameter vector "FVr_bestmem"
    //                                        has found a value f(FVr_bestmem,y) <= F_VTR.
    //                    FVr_minbound (I)    Vector of lower bounds FVr_minbound(1) ... FVr_minbound(I_D)
    //                                        of initial population.
    //                                        *** note: these are not bound constraints!! ***
    //                    FVr_maxbound (I)    Vector of upper bounds FVr_maxbound(1) ... FVr_maxbound(I_D)
    //                                        of initial population.
    //                    I_D          (I)    Number of parameters of the objective function.
    //                    I_NP         (I)    Number of population members.
    //                    I_itermax    (I)    Maximum number of iterations (generations).
    //                    fWeight     (I)    DE-stepsize fWeight from interval [0, 2].
    //                    F_CR         (I)    Crossover probability constant from interval [0, 1].
    //                    I_strategy   (I)    1 --> DE/rand/1
    //                                        2 --> DE/local-to-best/1
    //                                        3 --> DE/best/1 with jitter
    //                                        4 --> DE/rand/1 with per-vector-dither
    //                                        5 --> DE/rand/1 with per-generation-dither
    //                                        6 --> DE/rand/1 either-or-algorithm
    //                    I_refresh     (I)   Intermediate output will be produced after "I_refresh"
    //                                        iterations. No intermediate output will be produced
    //                                        if I_refresh is < 1.
    //
    //  Return value:     FVr_bestmem      (O)    Best parameter vector.
    //                    S_bestval.I_nc   (O)    Number of constraints
    //                    S_bestval.FVr_ca (O)    Constraint values. 0 means the constraints
    //                                            are met. Values > 0 measure the distance
    //                                            to a particular constraint.
    //                    S_bestval.I_no   (O)    Number of objectives.
    //                    S_bestval.FVr_oa (O)    Objective function values.
    //                    I_nfeval         (O)    Number of function evaluations.
    //
    //  Note:
    //  This program is free software; you can redistribute it and/or modify
    //  it under the terms of the GNU General Public License as published by
    //  the Free Software Foundation; either version 1, or (at your option)
    //  any later version.
    //
    //  This program is distributed in the hope that it will be useful,
    //  but WITHOUT ANY WARRANTY; without even the implied warranty of
    //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    //  GNU General Public License for more details. A copy of the GNU
    //  General Public License can be obtained from the
    //  Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // -----This is just for notational convenience and to keep the code uncluttered.--------
    I_NP = S_struct->I_NP;
    fWeight = S_struct->fWeight;
    F_CR = S_struct->F_CR;
    I_D = S_struct->I_D;
    I_itermax = S_struct->I_itermax;

    // -----Check input variables---------------------------------------------
    if (S_struct->I_NP < 5.0) {
      I_NP = 5.0;
      printf(" I_NP increased to minimal value 5\n");
      fflush(stdout);
    }

    if ((S_struct->F_CR < 0.0) || (S_struct->F_CR > 1.0)) {
      F_CR = 0.5;
      printf("F_CR should be from interval [0,1]; set to default value 0.5\n");
      fflush(stdout);
    }

    if (S_struct->I_itermax <= 0.0) {
      I_itermax = 200.0;
      printf("I_itermax should be > 0; set to default value 200\n");
      fflush(stdout);
    }

    // -----Initialize population and some arrays-------------------------------
    i = static_cast<int32_T>(I_NP);
    loop_ub_tmp = static_cast<int32_T>(S_struct->I_D);
    FM_pop.set_size(i, loop_ub_tmp);

    // initialize FM_pop to gain speed
    // ----FM_pop is a matrix of size I_NPx(I_D+1). It will be initialized------
    // ----with random values between the min and max values of the-------------
    // ----parameters-----------------------------------------------------------
    for (k = 0; k < i; k++) {
      coder::b_rand(I_D, r);
      b_FM_pop.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FM_pop[i1] = r[i1];
      }

      loop_ub = S_struct->FVr_minbound.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b = S_struct->FVr_minbound[i1];
        FM_pop[k + FM_pop.size(0) * i1] = b + b_FM_pop[i1] *
          (S_struct->FVr_maxbound[i1] - b);
      }
    }

    //  number of function evaluations
    // ------Evaluate the best member after initialization----------------------
    coder::repmat(I_NP, S_val);

    //  start with first population member
    loop_ub = FM_pop.size(1);
    b_FM_pop.set_size(1, FM_pop.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_FM_pop[i1] = FM_pop[FM_pop.size(0) * i1];
    }

    b_problem = *problem;
    S_val[0] = intrafun(b_FM_pop, &b_problem, controls_parallel_data,
                        controls_parallel_size, controls_resamPars,
                        controls_calcSldDuringFit, controls_checks,
                        problemCells_f1, problemCells_f2, problemCells_f3,
                        problemCells_f4, problemCells_f5, problemCells_f6,
                        problemCells_f14, problemCells_f19);
    S_bestval_FVr_oa = S_val[0].FVr_oa;

    //  best objective function value so far
    i1 = static_cast<int32_T>(I_NP + -1.0);
    for (k = 0; k < i1; k++) {
      struct_T expl_temp;

      //  check the remaining members
      loop_ub = FM_pop.size(1);
      b_FM_pop.set_size(1, FM_pop.size(1));
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_FM_pop[i2] = FM_pop[(k + FM_pop.size(0) * i2) + 1];
      }

      b_problem = *problem;
      expl_temp = intrafun(b_FM_pop, &b_problem, controls_parallel_data,
                           controls_parallel_size, controls_resamPars,
                           controls_calcSldDuringFit, controls_checks,
                           problemCells_f1, problemCells_f2, problemCells_f3,
                           problemCells_f4, problemCells_f5, problemCells_f6,
                           problemCells_f14, problemCells_f19);
      S_val[k + 1] = expl_temp;
      if (leftWin(expl_temp.I_no, expl_temp.FVr_oa, S_bestval_FVr_oa) == 1.0) {
        //  save its location
        S_bestval_FVr_oa = expl_temp.FVr_oa;
      }
    }

    //  best member of current iteration
    //  best member ever
    // ------DE-Minimization---------------------------------------------
    // ------FM_popold is the population which has to compete. It is--------
    // ------static through one iteration. FM_pop is the newly--------------
    // ------emerging population.----------------------------------------
    //  initialize population matrix 1
    //  initialize population matrix 2
    //  initialize population matrix 3
    //  initialize population matrix 4
    //  initialize population matrix 5
    //  initialize FVr_bestmember  matrix
    //  intermediate population of perturbed vectors
    //  mask for intermediate population
    //  mask for old population
    if (I_NP - 1.0 < 0.0) {
      FVr_rot.set_size(1, 0);
    } else if (std::isinf(I_NP - 1.0) && (0.0 == I_NP - 1.0)) {
      FVr_rot.set_size(1, 1);
      FVr_rot[0] = rtNaN;
    } else {
      loop_ub = static_cast<int32_T>(std::floor(I_NP - 1.0));
      FVr_rot.set_size(1, loop_ub + 1);
      for (i1 = 0; i1 <= loop_ub; i1++) {
        FVr_rot[i1] = i1;
      }
    }

    //  rotating index array (size I_NP)
    //  rotating index array (size I_D)
    //  another rotating index array
    //  rotating index array for exponential crossover
    //  index array
    //  index array
    //  index array
    //  index array
    //  index array
    FVr_bestmem.set_size(1, loop_ub_tmp);
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      FVr_bestmem[i1] = 0.0;
    }

    //
    //
    // FM_pop = zeros(I_NP,2);
    I_iter = 1.0;
    while ((I_iter < I_itermax) && (S_bestval_FVr_oa > S_struct->F_VTR)) {
      int32_T b_FVr_a1;

      //  save the old population
      // S_struct.FM_pop = FM_pop;
      coder::b_rand(p);
      iv[0] = 0;
      iv[1] = 0;
      iv[2] = 0;
      iv[3] = 0;
      coder::internal::b_mergesort(iv, p);
      p[0] = iv[0];
      p[1] = iv[1];

      //  index pointer array
      coder::randperm(I_NP, r);
      FVr_a1.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        FVr_a1[FVr_a1.size(0) * i1] = r[i1];
      }

      //  shuffle locations of vectors
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FVr_rot[i1] = FVr_rot[i1] + p[0];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      FVr_rt.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        FVr_rt[FVr_rt.size(0) * i1] = r[i1];
      }

      //  rotate indices by ind(1) positions
      FVr_a2.set_size(1, FVr_rt.size(1));
      loop_ub = FVr_rt.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < 1; i2++) {
          FVr_a2[FVr_a2.size(0) * i1] = FVr_a1[static_cast<int32_T>
            (FVr_rt[FVr_rt.size(0) * i1] + 1.0) - 1];
        }
      }

      //  rotate vector locations
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FVr_rot[i1] = FVr_rot[i1] + p[1];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      FVr_a3.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        FVr_a3[FVr_a3.size(0) * i1] = FVr_a2[static_cast<int32_T>(r[i1] + 1.0) -
          1];
      }

      //  shuffled population 1
      //  shuffled population 2
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FVr_rot[i1] = FVr_rot[i1] + p[1];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      b_FVr_a1 = r.size(1);
      loop_ub = FM_pop.size(1);
      coder::b_rem(b_FVr_rot, I_NP, r);
      FM_pm3.set_size(r.size(1), FM_pop.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < b_FVr_a1; i2++) {
          FM_pm3[i2 + FM_pm3.size(0) * i1] = FM_pop[(static_cast<int32_T>
            (FVr_a3[i2]) + FM_pop.size(0) * i1) - 1];
        }
      }

      //  shuffled population 3
      //  shuffled population 4
      //  shuffled population 5
      coder::b_rand(I_NP, I_D, r1);
      FM_mui.set_size(r1.size(0), r1.size(1));
      loop_ub = r1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FVr_a1 = r1.size(0);
        for (i2 = 0; i2 < b_FVr_a1; i2++) {
          FM_mui[i2 + FM_mui.size(0) * i1] = (r1[i2 + r1.size(0) * i1] < F_CR);
        }
      }

      //  all random numbers < F_CR are 1, 0 otherwise
      // ----Insert this if you want exponential crossover.----------------
      // FM_mui = sort(FM_mui');	  % transpose, collect 1's in each column
      // for k  = 1:I_NP
      //   n = floor(rand*I_D);
      //   if (n > 0)
      //      FVr_rtd     = rem(FVr_rotd+n,I_D);
      //      FM_mui(:,k) = FM_mui(FVr_rtd+1,k); %rotate column k by n
      //   end
      // end
      // FM_mui = FM_mui';			  % transpose back
      // ----End: exponential crossover------------------------------------
      //  inverse mask to FM_mui
      //  DE/rand/1 with per-vector-dither
      b = (1.0 - fWeight) * coder::b_rand() + fWeight;

      //  differential variation
      FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
      loop_ub = FM_pop.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FVr_a1 = FM_pop.size(0);
        for (i2 = 0; i2 < b_FVr_a1; i2++) {
          boolean_T b_b;
          b_b = FM_mui[i2 + FM_mui.size(0) * i1];
          FM_ui[i2 + FM_ui.size(0) * i1] = FM_pop[i2 + FM_pop.size(0) * i1] *
            static_cast<real_T>(static_cast<real_T>(b_b) < 0.5) + (FM_pm3[i2 +
            FM_pm3.size(0) * i1] + (FM_pop[(static_cast<int32_T>(FVr_a1[i2]) +
            FM_pop.size(0) * i1) - 1] - FM_pop[(static_cast<int32_T>(FVr_a2[i2])
            + FM_pop.size(0) * i1) - 1]) * b) * static_cast<real_T>(b_b);
        }
      }

      //  crossover
      // -----Optional parent+child selection-----------------------------------------
      // -----Select which vectors are allowed to enter the new population------------
      for (k = 0; k < i; k++) {
        struct_T S_tempval;

        // =====Only use this if boundary constraints are needed==================
        for (int32_T j{0}; j < loop_ub_tmp; j++) {
          real_T d;

          // ----boundary constraints via bounce back-------
          b = FM_ui[k + FM_ui.size(0) * j];
          d = S_struct->FVr_maxbound[j];
          if (b > d) {
            b = d + coder::b_rand() * (FM_pm3[k + FM_pm3.size(0) * j] - d);
            FM_ui[k + FM_ui.size(0) * j] = b;
          }

          d = S_struct->FVr_minbound[j];
          if (b < d) {
            b = d + coder::b_rand() * (FM_pm3[k + FM_pm3.size(0) * j] - d);
            FM_ui[k + FM_ui.size(0) * j] = b;
          }
        }

        // =====End boundary constraints==========================================
        loop_ub = FM_ui.size(1);
        b_FM_pop.set_size(1, FM_ui.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_FM_pop[i1] = FM_ui[k + FM_ui.size(0) * i1];
        }

        b_problem = *problem;
        S_tempval = intrafun(b_FM_pop, &b_problem, controls_parallel_data,
                             controls_parallel_size, controls_resamPars,
                             controls_calcSldDuringFit, controls_checks,
                             problemCells_f1, problemCells_f2, problemCells_f3,
                             problemCells_f4, problemCells_f5, problemCells_f6,
                             problemCells_f14, problemCells_f19);

        //  check cost of competitor
        if (leftWin(S_tempval.I_no, S_tempval.FVr_oa, S_val[k].FVr_oa) == 1.0) {
          loop_ub = FM_ui.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            FM_pop[k + FM_pop.size(0) * i1] = FM_ui[k + FM_ui.size(0) * i1];
          }

          //  replace old vector with new one (for new iteration)
          S_val[k] = S_tempval;

          //  save value in "cost array"
          // ----we update S_bestval only in case of success to save time-----------
          if (leftWin(S_tempval.I_no, S_tempval.FVr_oa, S_bestval_FVr_oa) == 1.0)
          {
            S_bestval_FVr_oa = S_tempval.FVr_oa;

            //  new best value
            loop_ub = FM_ui.size(1);
            FVr_bestmem.set_size(1, FM_ui.size(1));
            for (i1 = 0; i1 < loop_ub; i1++) {
              FVr_bestmem[i1] = FM_ui[k + FM_ui.size(0) * i1];
            }

            //  new best parameter vector ever
          }
        }
      }

      //  for k = 1:NP
      //  freeze the best member of this iteration for the coming
      //  iteration. This is needed for some of the strategies.
      // ----Output section----------------------------------------------------------
      if (((rt_remd_snf(I_iter, 1.0) == 0.0) || (I_iter == 1.0)) && coder::
          internal::w_strcmp(controls_display_data, controls_display_size)) {
        coder::internal::print_processing(I_iter, S_bestval_FVr_oa, fWeight,
          F_CR, I_NP, validatedHoleFilling);
        printf("Iteration: %g,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %g\n\n",
               validatedHoleFilling[0], validatedHoleFilling[1],
               validatedHoleFilling[2], validatedHoleFilling[3],
               validatedHoleFilling[4]);
        fflush(stdout);

        // disp(S_bestval);
        // var(FM_pop)
        //         format long e;
        //         for n=1:I_D
        //            fprintf('best(%d) = %g\n',n,FVr_bestmem(n));
        //         end
        //          if (I_plotting == 1)
        //             PlotIt(FVr_bestmem,problem);
        //          end
      }

      I_iter++;
    }

    // ---end while ((I_iter < I_itermax) ...
    //  problemStruct.fitParams = x;
    //  problemStruct = unpackParams(problemStruct,controls);
    //  [problem,res] = reflectivityCalculation(problemStruct,problemCells,controls);
  }
}

// End of code generation (deopt.cpp)
