/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * rascal_deopt.c
 *
 * Code generation for function 'rascal_deopt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "linear_DE_new_test.h"
#include "rascal_deopt.h"
#include "rand.h"
#include "left_win.h"
#include "rem.h"
#include "randperm.h"
#include "repmat.h"

/* Function Definitions */
void rascal_deopt(const double problem_data[15], const double
                  S_struct_FVr_minbound[2], const double S_struct_FVr_maxbound[2],
                  double FVr_bestmem[2])
{
  double FM_pop_data[40];
  signed char FM_pop_size[2];
  int i0;
  int k;
  double FVr_rt_data[20];
  int tmp_size[2];
  int loop_ub;
  double b_FM_pop_data[2];
  struct_T S_val_data[20];
  int S_val_size[1];
  double S_bestval_FVr_oa;
  signed char FVr_rot_data[20];
  int I_iter;
  double dv0[4];
  double FVr_ind_data[4];
  double tmp_data[20];
  double FVr_a1_data[400];
  double b_FVr_rot_data[20];
  int FVr_rot_size[2];
  int FVr_rt_size_idx_1;
  double b_FVr_rt_data[400];
  double FVr_a2_data[400];
  int b_FVr_rot_size[2];
  double FVr_a3_data[400];
  int FM_pm3_size_idx_0;
  double FM_ui_data[40];
  double FM_pm3_data[40];
  boolean_T FM_mui_data[40];
  double f1;
  double S_val_data_FVr_ca;
  double S_val_data_I_no;
  double S_val_data_FVr_oa;
  double S_tempval_I_nc;
  double S_tempval_FVr_ca;
  double S_tempval_I_no;
  double S_tempval_FVr_oa;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Function:         [FVr_bestmem,S_bestval,I_nfeval] = deopt(fname,S_struct) */
  /*                      */
  /*  Author:           Rainer Storn, Ken Price, Arnold Neumaier, Jim Van Zandt */
  /*  Description:      Minimization of a user-supplied function with respect to x(1:I_D), */
  /*                    using the differential evolution (DE) algorithm. */
  /*                    DE works best if [FVr_minbound,FVr_maxbound] covers the region where the */
  /*                    global minimum is expected. DE is also somewhat sensitive to */
  /*                    the choice of the stepsize F_weight. A good initial guess is to */
  /*                    choose F_weight from interval [0.5, 1], e.g. 0.8. F_CR, the crossover */
  /*                    probability constant from interval [0, 1] helps to maintain */
  /*                    the diversity of the population but should be close to 1 for most.  */
  /*                    practical cases. Only separable problems do better with CR close to 0. */
  /*                    If the parameters are correlated, high values of F_CR work better. */
  /*                    The reverse is true for no correlation. */
  /*  */
  /*                    The number of population members I_NP is also not very critical. A */
  /*                    good initial guess is 10*I_D. Depending on the difficulty of the */
  /*                    problem I_NP can be lower than 10*I_D or must be higher than 10*I_D */
  /*                    to achieve convergence. */
  /*  */
  /*                    deopt is a vectorized variant of DE which, however, has a */
  /*                    property which differs from the original version of DE: */
  /*                    The random selection of vectors is performed by shuffling the */
  /*                    population array. Hence a certain vector can't be chosen twice */
  /*                    in the same term of the perturbation expression. */
  /*                    Due to the vectorized expressions deopt executes fairly fast */
  /*                    in MATLAB's interpreter environment. */
  /*  */
  /*  Parameters:       fname        (I)    String naming a function f(x,y) to minimize. */
  /*                    S_struct     (I)    Problem data vector (must remain fixed during the */
  /*                                        minimization). For details see Rundeopt.m. */
  /*                    ---------members of S_struct---------------------------------------------------- */
  /*                    F_VTR        (I)    "Value To Reach". deopt will stop its minimization */
  /*                                        if either the maximum number of iterations "I_itermax" */
  /*                                        is reached or the best parameter vector "FVr_bestmem"  */
  /*                                        has found a value f(FVr_bestmem,y) <= F_VTR. */
  /*                    FVr_minbound (I)    Vector of lower bounds FVr_minbound(1) ... FVr_minbound(I_D) */
  /*                                        of initial population. */
  /*                                        *** note: these are not bound constraints!! *** */
  /*                    FVr_maxbound (I)    Vector of upper bounds FVr_maxbound(1) ... FVr_maxbound(I_D) */
  /*                                        of initial population. */
  /*                    I_D          (I)    Number of parameters of the objective function.  */
  /*                    I_NP         (I)    Number of population members. */
  /*                    I_itermax    (I)    Maximum number of iterations (generations). */
  /*                    F_weight     (I)    DE-stepsize F_weight from interval [0, 2]. */
  /*                    F_CR         (I)    Crossover probability constant from interval [0, 1]. */
  /*                    I_strategy   (I)    1 --> DE/rand/1              */
  /*                                        2 --> DE/local-to-best/1              */
  /*                                        3 --> DE/best/1 with jitter   */
  /*                                        4 --> DE/rand/1 with per-vector-dither            */
  /*                                        5 --> DE/rand/1 with per-generation-dither */
  /*                                        6 --> DE/rand/1 either-or-algorithm */
  /*                    I_refresh     (I)   Intermediate output will be produced after "I_refresh" */
  /*                                        iterations. No intermediate output will be produced */
  /*                                        if I_refresh is < 1. */
  /*                                         */
  /*  Return value:     FVr_bestmem      (O)    Best parameter vector. */
  /*                    S_bestval.I_nc   (O)    Number of constraints */
  /*                    S_bestval.FVr_ca (O)    Constraint values. 0 means the constraints */
  /*                                            are met. Values > 0 measure the distance */
  /*                                            to a particular constraint. */
  /*                    S_bestval.I_no   (O)    Number of objectives. */
  /*                    S_bestval.FVr_oa (O)    Objective function values. */
  /*                    I_nfeval         (O)    Number of function evaluations. */
  /*  */
  /*  Note: */
  /*  This program is free software; you can redistribute it and/or modify */
  /*  it under the terms of the GNU General Public License as published by */
  /*  the Free Software Foundation; either version 1, or (at your option) */
  /*  any later version. */
  /*  */
  /*  This program is distributed in the hope that it will be useful, */
  /*  but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*  GNU General Public License for more details. A copy of the GNU  */
  /*  General Public License can be obtained from the  */
  /*  Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* [FVr_bestmem,S_bestval,I_nfeval] */
  /* coder.varsize(S_val(:),[Inf 1],[1 0]); */
  /* -----This is just for notational convenience and to keep the code uncluttered.-------- */
  /* coder.varsize('FM_pop',[S_struct.I_NP,2],[1 0]); */
  /* S_val = [0 0]; */
  /* coder.varsize('FM_pop',[20,2],[0 0]); */
  /* FM_pop = zeros(I_NP,2); */
  /* -----Check input variables--------------------------------------------- */
  /* -----Initialize population and some arrays------------------------------- */
  /* initialize FM_pop to gain speed */
  /* ----FM_pop is a matrix of size I_NPx(I_D+1). It will be initialized------ */
  /* ----with random values between the min and max values of the------------- */
  /* ----parameters----------------------------------------------------------- */
  for (i0 = 0; i0 < 2; i0++) {
    FM_pop_size[i0] = (signed char)(20 + -18 * i0);
  }

  for (k = 0; k < 20; k++) {
    b_rand(2.0, FVr_rt_data, tmp_size);
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_FM_pop_data[i0] = FVr_rt_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      FM_pop_data[k + FM_pop_size[0] * i0] = S_struct_FVr_minbound[i0] +
        b_FM_pop_data[i0] * (S_struct_FVr_maxbound[i0] -
        S_struct_FVr_minbound[i0]);
    }
  }

  /* FM_popold     = zeros(size(FM_pop));  % toggle population */
  /*  best population member ever */
  /*  best population member in iteration */
  /*  number of function evaluations */
  /* ------Evaluate the best member after initialization---------------------- */
  /* str = struct('I_nc',0,'FVr_ca',0,'I_no',0,'FVr_oa',0); */
  /*  S_MSE.FVr_ca    = []; */
  /*  S_MSE.I_no      = []; */
  /*  S_MSE.FVr_oa(1) = []; */
  repmat(S_val_data, S_val_size);

  /*  start with first population member */
  for (i0 = 0; i0 < 2; i0++) {
    b_FM_pop_data[i0] = FM_pop_data[FM_pop_size[0] * i0];
  }

  intrafun(b_FM_pop_data, problem_data, &S_val_data[0].I_nc, &S_val_data[0].
           FVr_ca, &S_val_data[0].I_no, &S_val_data[0].FVr_oa);
  S_bestval_FVr_oa = S_val_data[0].FVr_oa;

  /*  best objective function value so far */
  for (k = 0; k < 19; k++) {
    /*  check the remaining members */
    for (i0 = 0; i0 < 2; i0++) {
      b_FM_pop_data[i0] = FM_pop_data[(k + FM_pop_size[0] * i0) + 1];
    }

    intrafun(b_FM_pop_data, problem_data, &S_val_data[k + 1].I_nc, &S_val_data[k
             + 1].FVr_ca, &S_val_data[k + 1].I_no, &S_val_data[k + 1].FVr_oa);
    if (left_win(S_val_data[k + 1].I_no, S_val_data[k + 1].FVr_oa,
                 S_bestval_FVr_oa) == 1.0) {
      /*  save its location */
      S_bestval_FVr_oa = S_val_data[k + 1].FVr_oa;
    }
  }

  /*  best member of current iteration */
  /*  FVr_bestmemit = FM_pop(I_best_index,:); */
  /*  S_bestvalit   = S_bestval;              % best value of current iteration */
  /*  best member ever */
  /* ------DE-Minimization--------------------------------------------- */
  /* ------FM_popold is the population which has to compete. It is-------- */
  /* ------static through one iteration. FM_pop is the newly-------------- */
  /* ------emerging population.---------------------------------------- */
  /*  initialize population matrix 1 */
  /*  initialize population matrix 2 */
  /*  initialize population matrix 3 */
  /*  initialize population matrix 4 */
  /*  initialize population matrix 5 */
  /*  initialize FVr_bestmember  matrix */
  /*  intermediate population of perturbed vectors */
  /*  mask for intermediate population */
  /*  mask for old population */
  for (i0 = 0; i0 < 20; i0++) {
    FVr_rot_data[i0] = (signed char)i0;
  }

  /*  rotating index array (size I_NP) */
  /*  rotating index array (size I_D) */
  /*  another rotating index array */
  /*  rotating index array for exponential crossover */
  /*  index array */
  /*  index array */
  /*  index array */
  /*  index array */
  /*  index array */
  for (i0 = 0; i0 < 2; i0++) {
    FVr_bestmem[i0] = 0.0;
  }

  /*  */
  /*  */
  /* FM_pop = zeros(I_NP,2); */
  I_iter = 1;
  while ((I_iter < 1000) && (S_bestval_FVr_oa > 1.0E-5)) {
    /*  save the old population */
    /* S_struct.FM_pop = FM_pop; */
    randperm(dv0);
    for (i0 = 0; i0 < 4; i0++) {
      FVr_ind_data[i0] = dv0[i0];
    }

    /*  index pointer array */
    b_randperm(tmp_data, tmp_size);
    memcpy(&FVr_a1_data[0], &tmp_data[0], 20U * sizeof(double));

    /*  shuffle locations of vectors */
    FVr_rot_size[0] = 1;
    FVr_rot_size[1] = 20;
    for (i0 = 0; i0 < 20; i0++) {
      b_FVr_rot_data[i0] = (double)FVr_rot_data[i0] + FVr_ind_data[0];
    }

    b_rem(b_FVr_rot_data, FVr_rot_size, FVr_rt_data, tmp_size);
    FVr_rt_size_idx_1 = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_FVr_rt_data[i0] = FVr_rt_data[i0];
    }

    /*  rotate indices by ind(1) positions */
    loop_ub = tmp_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      FVr_a2_data[i0] = FVr_a1_data[(int)(b_FVr_rt_data[i0] + 1.0) - 1];
    }

    /*  rotate vector locations */
    b_FVr_rot_size[0] = 1;
    b_FVr_rot_size[1] = 20;
    for (i0 = 0; i0 < 20; i0++) {
      b_FVr_rot_data[i0] = (double)FVr_rot_data[i0] + FVr_ind_data[1];
    }

    b_rem(b_FVr_rot_data, b_FVr_rot_size, FVr_rt_data, tmp_size);
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      FVr_a3_data[i0] = FVr_a2_data[(int)(FVr_rt_data[i0] + 1.0) - 1];
    }

    /*  shuffled population 1 */
    /*  shuffled population 2 */
    loop_ub = tmp_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (k = 0; k < 1; k++) {
        b_FVr_rot_data[i0] = FVr_a3_data[i0];
      }
    }

    FM_pm3_size_idx_0 = tmp_size[1];
    for (i0 = 0; i0 < 2; i0++) {
      loop_ub = tmp_size[1];
      for (k = 0; k < loop_ub; k++) {
        FM_pm3_data[k + FM_pm3_size_idx_0 * i0] = FM_pop_data[((int)
          b_FVr_rot_data[k] + FM_pop_size[0] * i0) - 1];
      }
    }

    /*  shuffled population 3 */
    /*  shuffled population 4 */
    /*  shuffled population 5 */
    d_rand(FM_ui_data, tmp_size);
    for (i0 = 0; i0 < 40; i0++) {
      FM_mui_data[i0] = (FM_ui_data[i0] < 0.9);
    }

    /*  all random numbers < F_CR are 1, 0 otherwise */
    /* ----Insert this if you want exponential crossover.---------------- */
    /* FM_mui = sort(FM_mui');	  % transpose, collect 1's in each column */
    /* for k  = 1:I_NP */
    /*   n = floor(rand*I_D); */
    /*   if (n > 0) */
    /*      FVr_rtd     = rem(FVr_rotd+n,I_D); */
    /*      FM_mui(:,k) = FM_mui(FVr_rtd+1,k); %rotate column k by n */
    /*   end */
    /* end */
    /* FM_mui = FM_mui';			  % transpose back */
    /* ----End: exponential crossover------------------------------------ */
    /*  inverse mask to FM_mui */
    /*  DE/rand/1 with per-vector-dither */
    f1 = 0.7 * e_rand() + 0.3;

    /*  differential variation */
    for (i0 = 0; i0 < 20; i0++) {
      for (k = 0; k < 1; k++) {
        b_FVr_rot_data[i0] = FVr_a1_data[i0];
      }
    }

    for (i0 = 0; i0 < FVr_rt_size_idx_1; i0++) {
      for (k = 0; k < 1; k++) {
        FVr_rt_data[i0] = FVr_a2_data[i0];
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      for (k = 0; k < 20; k++) {
        FM_ui_data[k + 20 * i0] = FM_pop_data[k + FM_pop_size[0] * i0] * (double)
          ((double)FM_mui_data[k + 20 * i0] < 0.5) + (FM_pm3_data[k +
          FM_pm3_size_idx_0 * i0] + (FM_pop_data[((int)b_FVr_rot_data[k] +
          FM_pop_size[0] * i0) - 1] - FM_pop_data[((int)FVr_rt_data[k] +
          FM_pop_size[0] * i0) - 1]) * f1) * (double)FM_mui_data[k + 20 * i0];
      }
    }

    /*  crossover */
    /* -----Optional parent+child selection----------------------------------------- */
    /* -----Select which vectors are allowed to enter the new population------------ */
    for (k = 0; k < 20; k++) {
      f1 = S_val_data[k].I_nc;
      S_val_data_FVr_ca = S_val_data[k].FVr_ca;
      S_val_data_I_no = S_val_data[k].I_no;
      S_val_data_FVr_oa = S_val_data[k].FVr_oa;

      /* =====Only use this if boundary constraints are needed================== */
      for (FVr_rt_size_idx_1 = 0; FVr_rt_size_idx_1 < 2; FVr_rt_size_idx_1++) {
        /* ----boundary constraints via bounce back------- */
        if (FM_ui_data[k + 20 * FVr_rt_size_idx_1] >
            S_struct_FVr_maxbound[FVr_rt_size_idx_1]) {
          FM_ui_data[k + 20 * FVr_rt_size_idx_1] =
            S_struct_FVr_maxbound[FVr_rt_size_idx_1] + e_rand() * (FM_pm3_data[k
            + FM_pm3_size_idx_0 * FVr_rt_size_idx_1] -
            S_struct_FVr_maxbound[FVr_rt_size_idx_1]);
        }

        if (FM_ui_data[k + 20 * FVr_rt_size_idx_1] <
            S_struct_FVr_minbound[FVr_rt_size_idx_1]) {
          FM_ui_data[k + 20 * FVr_rt_size_idx_1] =
            S_struct_FVr_minbound[FVr_rt_size_idx_1] + e_rand() * (FM_pm3_data[k
            + FM_pm3_size_idx_0 * FVr_rt_size_idx_1] -
            S_struct_FVr_minbound[FVr_rt_size_idx_1]);
        }
      }

      /* =====End boundary constraints========================================== */
      for (i0 = 0; i0 < 2; i0++) {
        b_FM_pop_data[i0] = FM_ui_data[k + 20 * i0];
      }

      intrafun(b_FM_pop_data, problem_data, &S_tempval_I_nc, &S_tempval_FVr_ca,
               &S_tempval_I_no, &S_tempval_FVr_oa);

      /*  check cost of competitor */
      if (left_win(S_tempval_I_no, S_tempval_FVr_oa, S_val_data[k].FVr_oa) ==
          1.0) {
        for (i0 = 0; i0 < 2; i0++) {
          FM_pop_data[k + FM_pop_size[0] * i0] = FM_ui_data[k + 20 * i0];
        }

        /*  replace old vector with new one (for new iteration) */
        f1 = S_tempval_I_nc;
        S_val_data_FVr_ca = S_tempval_FVr_ca;
        S_val_data_I_no = S_tempval_I_no;
        S_val_data_FVr_oa = S_tempval_FVr_oa;

        /*  save value in "cost array" */
        /* ----we update S_bestval only in case of success to save time----------- */
        if (left_win(S_tempval_I_no, S_tempval_FVr_oa, S_bestval_FVr_oa) == 1.0)
        {
          S_bestval_FVr_oa = S_tempval_FVr_oa;

          /*  new best value */
          for (i0 = 0; i0 < 2; i0++) {
            FVr_bestmem[i0] = FM_ui_data[k + 20 * i0];
          }

          /*  new best parameter vector ever */
        }
      }

      S_val_data[k].I_nc = f1;
      S_val_data[k].FVr_ca = S_val_data_FVr_ca;
      S_val_data[k].I_no = S_val_data_I_no;
      S_val_data[k].FVr_oa = S_val_data_FVr_oa;
    }

    /*  for k = 1:NP */
    /*  freeze the best member of this iteration for the coming  */
    /*  iteration. This is needed for some of the strategies. */
    /* ----Output section---------------------------------------------------------- */
    I_iter++;
  }

  /* ---end while ((I_iter < I_itermax) ... */
}

/* End of code generation (rascal_deopt.c) */
