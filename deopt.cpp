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
#include "ifWhileCond.h"
#include "isRATStopped.h"
#include "leftWin.h"
#include "mergesort.h"
#include "print_processing.h"
#include "rand.h"
#include "randperm.h"
#include "rem.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "sprintf.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void deopt(const d_struct_T *problem, const cell_16 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, const
             g_struct_T *S_struct, ::coder::array<real_T, 2U> &FVr_bestmem)
  {
    ::coder::array<struct_T, 1U> S_val;
    ::coder::array<real_T, 2U> FM_bm;
    ::coder::array<real_T, 2U> FM_origin;
    ::coder::array<real_T, 2U> FM_pm1;
    ::coder::array<real_T, 2U> FM_pm2;
    ::coder::array<real_T, 2U> FM_pm3;
    ::coder::array<real_T, 2U> FM_pm5;
    ::coder::array<real_T, 2U> FM_pop;
    ::coder::array<real_T, 2U> FM_ui;
    ::coder::array<real_T, 2U> FVr_a1;
    ::coder::array<real_T, 2U> FVr_a2;
    ::coder::array<real_T, 2U> FVr_a3;
    ::coder::array<real_T, 2U> FVr_a4;
    ::coder::array<real_T, 2U> FVr_a5;
    ::coder::array<real_T, 2U> FVr_bestmemit;
    ::coder::array<real_T, 2U> FVr_rot;
    ::coder::array<real_T, 2U> FVr_rt;
    ::coder::array<real_T, 2U> b;
    ::coder::array<real_T, 2U> b_FM_pop;
    ::coder::array<real_T, 2U> b_FVr_rot;
    ::coder::array<real_T, 2U> b_FVr_rt;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 1U> b_b;
    ::coder::array<real_T, 1U> f1;
    ::coder::array<char_T, 2U> charStr;
    ::coder::array<boolean_T, 2U> FM_mpo;
    ::coder::array<boolean_T, 2U> FM_mui;
    d_struct_T b_problem;
    e_struct_T a__1;
    e_struct_T a__2;
    e_struct_T a__3;
    e_struct_T result;
    struct_T S_tempval;
    struct_T a__4;
    real_T validatedHoleFilling[5];
    real_T p[4];
    real_T F_CR;
    real_T I_D;
    real_T I_NP;
    real_T I_iter;
    real_T I_itermax;
    real_T I_strategy;
    real_T S_bestval_FVr_oa;
    real_T d;
    real_T fWeight;
    int32_T iv[4];
    int32_T b_FVr_a1;
    int32_T b_loop_ub_tmp;
    int32_T i;
    int32_T i1;
    int32_T k;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    uint32_T I_best_index;
    boolean_T exitg1;
    boolean_T tmp_data;

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
    //  stopflag = 0;
    I_NP = S_struct->I_NP;
    fWeight = S_struct->fWeight;
    F_CR = S_struct->F_CR;
    I_D = S_struct->I_D;
    I_itermax = S_struct->I_itermax;
    I_strategy = S_struct->I_strategy;

    // -----Check input variables---------------------------------------------
    if (S_struct->I_NP < 5.0) {
      I_NP = 5.0;
      e_triggerEvent();
    }

    if ((S_struct->F_CR < 0.0) || (S_struct->F_CR > 1.0)) {
      F_CR = 0.5;
      f_triggerEvent();
    }

    if (S_struct->I_itermax <= 0.0) {
      I_itermax = 200.0;
      g_triggerEvent();
    }

    // -----Initialize population and some arrays-------------------------------
    loop_ub_tmp = static_cast<int32_T>(I_NP);
    b_loop_ub_tmp = static_cast<int32_T>(S_struct->I_D);
    FM_pop.set_size(loop_ub_tmp, b_loop_ub_tmp);

    // initialise FM_pop to gain speed
    // ----FM_pop is a matrix of size I_NPx(I_D+1). It will be initialized------
    // ----with random values between the min and max values of the-------------
    // ----parameters-----------------------------------------------------------
    for (k = 0; k < loop_ub_tmp; k++) {
      coder::b_rand(I_D, r);
      loop_ub = S_struct->FVr_minbound.size(1);
      for (i = 0; i < loop_ub; i++) {
        d = S_struct->FVr_minbound[i];
        FM_pop[k + FM_pop.size(0) * i] = d + r[i] * (S_struct->FVr_maxbound[i] -
          d);
      }
    }

    //  number of function evaluations
    // ------Evaluate the best member after initialization----------------------
    coder::repmat(I_NP, S_val);
    I_best_index = 1U;

    //  start with first population member
    loop_ub = FM_pop.size(1);
    b_FM_pop.set_size(1, FM_pop.size(1));
    for (i = 0; i < loop_ub; i++) {
      b_FM_pop[i] = FM_pop[FM_pop.size(0) * i];
    }

    b_problem = *problem;
    intrafun(b_FM_pop, &b_problem, problemCells, problemLimits, controls,
             &(S_val.data())[0], &a__1);
    S_bestval_FVr_oa = S_val[0].FVr_oa;

    //  best objective function value so far
    i = static_cast<int32_T>(I_NP + -1.0);
    for (k = 0; k < i; k++) {
      //  check the remaining members
      loop_ub = FM_pop.size(1);
      b_FM_pop.set_size(1, FM_pop.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_FM_pop[i1] = FM_pop[(k + FM_pop.size(0) * i1) + 1];
      }

      b_problem = *problem;
      intrafun(b_FM_pop, &b_problem, problemCells, problemLimits, controls,
               &S_val[k + 1], &a__2);
      if (leftWin(S_val[k + 1], S_bestval_FVr_oa) == 1.0) {
        I_best_index = k + 2U;

        //  save its location
        S_bestval_FVr_oa = S_val[k + 1].FVr_oa;
      }
    }

    loop_ub = FM_pop.size(1);
    FVr_bestmemit.set_size(1, FM_pop.size(1));
    for (i = 0; i < loop_ub; i++) {
      FVr_bestmemit[i] = FM_pop[(static_cast<int32_T>(I_best_index) +
        FM_pop.size(0) * i) - 1];
    }

    //  best member of current iteration
    //  best member ever
    // ------DE-Minimization---------------------------------------------
    // ------FM_popold is the population which has to compete. It is--------
    // ------static through one iteration. FM_pop is the newly--------------
    // ------emerging population.----------------------------------------
    //  initialise population matrix 1
    //  initialise population matrix 2
    //  initialise population matrix 3
    //  initialise population matrix 4
    //  initialise population matrix 5
    FM_bm.set_size(loop_ub_tmp, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        FM_bm[i1 + FM_bm.size(0) * i] = 0.0;
      }
    }

    //  initialise FVr_bestmember  matrix
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
      for (i = 0; i <= loop_ub; i++) {
        FVr_rot[i] = i;
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
    FVr_bestmem.set_size(1, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      FVr_bestmem[i] = 0.0;
    }

    //
    //
    // FM_pop = zeros(I_NP,2);
    if (S_bestval_FVr_oa <= S_struct->F_VTR) {
      //  In this case the while loop should never run so reset
      //  the best result to the initial value
      FVr_bestmem.set_size(1, problem->params.size(1));
      loop_ub = problem->params.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_bestmem[i] = problem->params[i];
      }
    }

    I_iter = 1.0;
    exitg1 = false;
    while ((!exitg1) && ((I_iter < I_itermax) && (S_bestval_FVr_oa >
             S_struct->F_VTR))) {
      real_T a;

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
      p[2] = iv[2];
      p[3] = iv[3];

      //  index pointer array
      coder::randperm(I_NP, r);
      FVr_a1.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_a1[FVr_a1.size(0) * i] = r[i];
      }

      //  shuffle locations of vectors
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[0];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      FVr_rt.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_rt[FVr_rt.size(0) * i] = r[i];
      }

      //  rotate indices by ind(1) positions
      FVr_a2.set_size(1, FVr_rt.size(1));
      loop_ub = FVr_rt.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < 1; i1++) {
          FVr_a2[FVr_a2.size(0) * i] = FVr_a1[static_cast<int32_T>
            (FVr_rt[FVr_rt.size(0) * i] + 1.0) - 1];
        }
      }

      //  rotate vector locations
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[1];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      FVr_a3.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_a3[FVr_a3.size(0) * i] = FVr_a2[static_cast<int32_T>(r[i] + 1.0) - 1];
      }

      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[1];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[2];
      }

      coder::b_rem(b_FVr_rot, I_NP, b_FM_pop);
      FVr_a4.set_size(1, b_FM_pop.size(1));
      loop_ub = b_FM_pop.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_a4[FVr_a4.size(0) * i] = FVr_a3[static_cast<int32_T>(b_FM_pop[i] +
          1.0) - 1];
      }

      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[3];
      }

      coder::b_rem(b_FVr_rot, I_NP, b_FVr_rt);
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[2];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      FVr_a5.set_size(1, b_FVr_rt.size(1));
      loop_ub = b_FVr_rt.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_a5[FVr_a5.size(0) * i] = FVr_a4[static_cast<int32_T>(b_FVr_rt[i] +
          1.0) - 1];
      }

      b_FVr_a1 = FVr_a1.size(1);
      loop_ub = FM_pop.size(1);
      FM_pm1.set_size(FVr_a1.size(1), FM_pop.size(1));
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_pm1[i1 + FM_pm1.size(0) * i] = FM_pop[(static_cast<int32_T>
            (FVr_a1[i1]) + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 1
      b_FVr_a1 = FVr_rt.size(1);
      loop_ub = FM_pop.size(1);
      FM_pm2.set_size(FVr_rt.size(1), FM_pop.size(1));
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_pm2[i1 + FM_pm2.size(0) * i] = FM_pop[(static_cast<int32_T>
            (FVr_a2[i1]) + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 2
      b_FVr_rot.set_size(1, FVr_rot.size(1));
      loop_ub = FVr_rot.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_rot[i] = FVr_rot[i] + p[1];
      }

      coder::b_rem(b_FVr_rot, I_NP, r);
      b_FVr_a1 = r.size(1);
      loop_ub = FM_pop.size(1);
      coder::b_rem(b_FVr_rot, I_NP, r);
      FM_pm3.set_size(r.size(1), FM_pop.size(1));
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_pm3[i1 + FM_pm3.size(0) * i] = FM_pop[(static_cast<int32_T>
            (FVr_a3[i1]) + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 3
      //  shuffled population 4
      b_FVr_a1 = b_FVr_rt.size(1);
      loop_ub = FM_pop.size(1);
      FM_pm5.set_size(b_FVr_rt.size(1), FM_pop.size(1));
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_pm5[i1 + FM_pm5.size(0) * i] = FM_pop[(static_cast<int32_T>
            (FVr_a5[i1]) + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 5
      for (k = 0; k < loop_ub_tmp; k++) {
        //  population filled with the best member
        loop_ub = FVr_bestmemit.size(1);
        for (i = 0; i < loop_ub; i++) {
          FM_bm[k + FM_bm.size(0) * i] = FVr_bestmemit[i];
        }

        //  of the last iteration
      }

      coder::b_rand(I_NP, I_D, b);
      FM_mui.set_size(b.size(0), b.size(1));
      loop_ub = b.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_a1 = b.size(0);
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_mui[i1 + FM_mui.size(0) * i] = (b[i1 + b.size(0) * i] < F_CR);
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
      FM_mpo.set_size(FM_mui.size(0), FM_mui.size(1));
      loop_ub = FM_mui.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_a1 = FM_mui.size(0);
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_mpo[i1 + FM_mpo.size(0) * i] = (static_cast<real_T>(FM_mui[i1 +
            FM_mui.size(0) * i]) < 0.5);
        }
      }

      //  inverse mask to FM_mui
      FM_origin.set_size(loop_ub_tmp, 2);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          FM_origin[i1 + FM_origin.size(0) * i] = 0.0;
        }
      }

      if (I_strategy == 1.0) {
        // fprintf('Iteration: %d,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %d\n',I_iter,S_bestval.FVr_oa(1),fWeight,F_CR,I_NP));rategy == 1)                             % DE/rand/1
        //  differential variation
        FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
              static_cast<real_T>(FM_mpo[i1 + FM_mpo.size(0) * i]) + (FM_pm3[i1
              + FM_pm3.size(0) * i] + fWeight * (FM_pm1[i1 + FM_pm1.size(0) * i]
              - FM_pm2[i1 + FM_pm2.size(0) * i])) * static_cast<real_T>
              (FM_mui[i1 + FM_mui.size(0) * i]);
          }
        }

        //  crossover
        FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
        loop_ub = FM_pm3.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pm3.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) *
              i];
          }
        }
      } else if (I_strategy == 2.0) {
        //  DE/local-to-best/1
        FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        FM_origin.set_size(FM_pop.size(0), FM_pop.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            d = FM_pop[i1 + FM_pop.size(0) * i];
            FM_ui[i1 + FM_ui.size(0) * i] = d * static_cast<real_T>(FM_mpo[i1 +
              FM_mpo.size(0) * i]) + ((d + fWeight * (FM_bm[i1 + FM_bm.size(0) *
              i] - d)) + fWeight * (FM_pm1[i1 + FM_pm1.size(0) * i] - FM_pm2[i1
              + FM_pm2.size(0) * i])) * static_cast<real_T>(FM_mui[i1 +
              FM_mui.size(0) * i]);
            FM_origin[i1 + FM_origin.size(0) * i] = d;
          }
        }
      } else if (I_strategy == 3.0) {
        //  DE/best/1 with jitter
        coder::b_rand(I_NP, I_D, b);
        FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
              static_cast<real_T>(FM_mpo[i1 + FM_mpo.size(0) * i]) + (FM_bm[i1 +
              FM_bm.size(0) * i] + (FM_pm1[i1 + FM_pm1.size(0) * i] - FM_pm2[i1
              + FM_pm2.size(0) * i]) * (9.9999999999988987E-5 * b[i1 + b.size(0)
              * i] + fWeight)) * static_cast<real_T>(FM_mui[i1 + FM_mui.size(0) *
              i]);
          }
        }

        FM_origin.set_size(FM_bm.size(0), FM_bm.size(1));
        loop_ub = FM_bm.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_bm.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_bm[i1 + FM_bm.size(0) * i];
          }
        }
      } else if (I_strategy == 4.0) {
        //  DE/rand/1 with per-vector-dither
        coder::b_rand(I_NP, b_b);
        f1.set_size(b_b.size(0));
        loop_ub = b_b.size(0);
        for (i = 0; i < loop_ub; i++) {
          f1[i] = (1.0 - fWeight) * b_b[i] + fWeight;
        }

        for (k = 0; k < b_loop_ub_tmp; k++) {
          loop_ub = f1.size(0);
          for (i = 0; i < loop_ub; i++) {
            FM_pm5[i + FM_pm5.size(0) * k] = f1[i];
          }
        }

        //  differential variation
        FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
        loop_ub = FM_pm3.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pm3.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) *
              i];
          }
        }

        FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
              static_cast<real_T>(FM_mpo[i1 + FM_mpo.size(0) * i]) + (FM_pm3[i1
              + FM_pm3.size(0) * i] + (FM_pm1[i1 + FM_pm1.size(0) * i] -
              FM_pm2[i1 + FM_pm2.size(0) * i]) * FM_pm5[i1 + FM_pm5.size(0) * i])
              * static_cast<real_T>(FM_mui[i1 + FM_mui.size(0) * i]);
          }
        }

        //  crossover
      } else if (I_strategy == 5.0) {
        //  DE/rand/1 with per-vector-dither
        a = (1.0 - fWeight) * coder::b_rand() + fWeight;

        //  differential variation
        FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
        loop_ub = FM_pm3.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pm3.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) *
              i];
          }
        }

        FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
              static_cast<real_T>(FM_mpo[i1 + FM_mpo.size(0) * i]) + (FM_pm3[i1
              + FM_pm3.size(0) * i] + (FM_pm1[i1 + FM_pm1.size(0) * i] -
              FM_pm2[i1 + FM_pm2.size(0) * i]) * a) * static_cast<real_T>
              (FM_mui[i1 + FM_mui.size(0) * i]);
          }
        }

        //  crossover
      } else {
        //  either-or-algorithm
        if (coder::b_rand() < 0.5) {
          //  Pmu = 0.5
          FM_ui.set_size(FM_pm3.size(0), FM_pm3.size(1));
          loop_ub = FM_pm3.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pm3.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_ui[i1 + FM_ui.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) * i] +
                fWeight * (FM_pm1[i1 + FM_pm1.size(0) * i] - FM_pm2[i1 +
                           FM_pm2.size(0) * i]);
            }
          }

          //  differential variation
          FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
          loop_ub = FM_pm3.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pm3.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0)
                * i];
            }
          }
        } else {
          //  use F-K-Rule: K = 0.5(F+1)
          a = 0.5 * (fWeight + 1.0);
          FM_ui.set_size(FM_pm3.size(0), FM_pm3.size(1));
          loop_ub = FM_pm3.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pm3.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              d = FM_pm3[i1 + FM_pm3.size(0) * i];
              FM_ui[i1 + FM_ui.size(0) * i] = d + a * ((FM_pm1[i1 + FM_pm1.size
                (0) * i] + FM_pm2[i1 + FM_pm2.size(0) * i]) - 2.0 * d);
            }
          }
        }

        FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
              static_cast<real_T>(FM_mpo[i1 + FM_mpo.size(0) * i]) + FM_ui[i1 +
              FM_ui.size(0) * i] * static_cast<real_T>(FM_mui[i1 + FM_mui.size(0)
              * i]);
          }
        }

        //  crossover
      }

      // -----Optional parent+child selection-----------------------------------------
      // -----Select which vectors are allowed to enter the new population------------
      for (k = 0; k < loop_ub_tmp; k++) {
        // =====Only use this if boundary constraints are needed==================
        for (int32_T j{0}; j < b_loop_ub_tmp; j++) {
          // ----boundary constraints via bounce back-------
          d = FM_ui[k + FM_ui.size(0) * j];
          a = S_struct->FVr_maxbound[j];
          if (d > a) {
            d = a + coder::b_rand() * (FM_origin[k + FM_origin.size(0) * j] - a);
            FM_ui[k + FM_ui.size(0) * j] = d;
          }

          a = S_struct->FVr_minbound[j];
          if (d < a) {
            d = a + coder::b_rand() * (FM_origin[k + FM_origin.size(0) * j] - a);
            FM_ui[k + FM_ui.size(0) * j] = d;
          }
        }

        // =====End boundary constraints==========================================
        loop_ub = FM_ui.size(1);
        b_FM_pop.set_size(1, FM_ui.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_FM_pop[i] = FM_ui[k + FM_ui.size(0) * i];
        }

        b_problem = *problem;
        intrafun(b_FM_pop, &b_problem, problemCells, problemLimits, controls,
                 &S_tempval, &a__3);

        //  check cost of competitor
        if (leftWin(S_tempval, S_val[k].FVr_oa) == 1.0) {
          loop_ub = FM_ui.size(1);
          for (i = 0; i < loop_ub; i++) {
            FM_pop[k + FM_pop.size(0) * i] = FM_ui[k + FM_ui.size(0) * i];
          }

          //  replace old vector with new one (for new iteration)
          S_val[k] = S_tempval;

          //  save value in "cost array"
          // ----we update S_bestval only in case of success to save time-----------
          if (leftWin(S_tempval, S_bestval_FVr_oa) == 1.0) {
            S_bestval_FVr_oa = S_tempval.FVr_oa;

            //  new best value
            loop_ub = FM_ui.size(1);
            FVr_bestmem.set_size(1, FM_ui.size(1));
            for (i = 0; i < loop_ub; i++) {
              FVr_bestmem[i] = FM_ui[k + FM_ui.size(0) * i];
            }

            //  new best parameter vector ever
          }
        }
      }

      //  for k = 1:NP
      FVr_bestmemit.set_size(1, FVr_bestmem.size(1));
      loop_ub = FVr_bestmem.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_bestmemit[i] = FVr_bestmem[i];
      }

      //  freeze the best member of this iteration for the coming
      //  iteration. This is needed for some of the strategies.
      // ----Output section----------------------------------------------------------
      if (((rt_remd_snf(I_iter, 1.0) == 0.0) || (I_iter == 1.0)) && coder::
          internal::bb_strcmp(controls->display.data, controls->display.size)) {
        coder::internal::print_processing(I_iter, S_bestval_FVr_oa, fWeight,
          F_CR, I_NP, validatedHoleFilling);
        coder::snPrint(validatedHoleFilling[0], validatedHoleFilling[1],
                       validatedHoleFilling[2], validatedHoleFilling[3],
                       validatedHoleFilling[4], charStr);
        triggerEvent(charStr);

        // disp(S_bestval);
        // var(FM_pop)
        //         format long e;
        //         for n=1:I_D
        //            fprintf('best(%d) = %g\n',n,FVr_bestmem(n));
        //         end
        //          if (I_plotting == 1)
        //             PlotIt(FVr_bestmem,problem);
        //          end
        //         stopflag = 0;
      }

      //  Trigger the output event...
      if (rt_remd_snf(I_iter, controls->updatePlotFreq) == 0.0) {
        b_problem = *problem;
        intrafun(FVr_bestmem, &b_problem, problemCells, problemLimits, controls,
                 &a__4, &result);
        triggerEvent(&result, problem->TF.data, problem->TF.size,
                     problem->resample, problem->dataPresent,
                     problem->modelType.data, problem->modelType.size,
                     problemCells->f21);
      }

      isRATStopped(controls->IPCFilePath.data, controls->IPCFilePath.size,
                   (boolean_T *)&tmp_data, &b_FVr_a1);
      if (coder::internal::ifWhileCond((const boolean_T *)&tmp_data, b_FVr_a1))
      {
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          h_triggerEvent();
        }

        exitg1 = true;
      } else {
        //    if stopflag == 0
        I_iter++;

        //    else
        //        I_iter = I_itermax + 1;
        //    end
      }
    }

    // ---end while ((I_iter < I_itermax) ...
  }
}

// End of code generation (deopt.cpp)
