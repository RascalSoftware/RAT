/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * linear_DE_new_test.c
 *
 * Code generation for function 'linear_DE_new_test'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "linear_DE_new_test.h"
#include "rascal_deopt.h"

/* Function Definitions */
void intrafun(const double p_data[], const double problem_data[15], double
              *S_MSE_I_nc, double *S_MSE_FVr_ca, double *S_MSE_I_no, double
              *S_MSE_FVr_oa)
{
  double y[5];
  int k;
  double a;

  /*  S_MSE.I_nc      = []; */
  /*  S_MSE.FVr_ca    = []; */
  /*  S_MSE.I_no      = []; */
  /*  S_MSE.FVr_oa(1) = []; */
  for (k = 0; k < 5; k++) {
    a = problem_data[5 + k] - (p_data[0] * problem_data[k] + p_data[1]);
    y[k] = a * a / problem_data[10 + k];
  }

  *S_MSE_FVr_oa = y[0];
  for (k = 0; k < 4; k++) {
    *S_MSE_FVr_oa += y[k + 1];
  }

  *S_MSE_I_nc = 0.0;

  /* no constraints                 THESE FIRST FEW VALS MAY BE WRONG */
  *S_MSE_FVr_ca = 0.0;

  /* no constraint array */
  *S_MSE_I_no = 1.0;

  /* number of objectives (costs) */
}

void linear_DE_new_test(const struct0_T *problem)
{
  double S_struct_FVr_minbound[2];
  double S_struct_FVr_maxbound[2];
  int i2;
  double unusedExpr[2];

  /* Value to reach */
  /* 1: use bounds as bound constraints, 0: no bound constraints */
  /*  I_NP            number of population members */
  /*  I_itermax       maximum number of iterations (generations) */
  /* problem.maxiter; */
  /*  F_weight        DE-stepsize F_weight ex [0, 2] */
  /*  F_CR            crossover probabililty constant ex [0, 1] */
  /*  I_strategy     1 --> DE/rand/1: */
  /*                       the classical version of DE. */
  /*                 2 --> DE/local-to-best/1: */
  /*                       a version which has been used by quite a number */
  /*                       of scientists. Attempts a balance between robustness */
  /*                       and fast convergence. */
  /*                 3 --> DE/best/1 with jitter: */
  /*                       taylored for small population sizes and fast convergence. */
  /*                       Dimensionality should not be too high. */
  /*                 4 --> DE/rand/1 with per-vector-dither: */
  /*                       Classical DE with dither to become even more robust. */
  /*                 5 --> DE/rand/1 with per-generation-dither: */
  /*                       Classical DE with dither to become even more robust. */
  /*                       Choosing F_weight = 0.3 is a good start here. */
  /*                 6 --> DE/rand/1 either-or-algorithm: */
  /*                       Alternates between differential mutation and three-point- */
  /*                       recombination.            */
  /*  I_refresh     intermediate output will be produced after "I_refresh" */
  /*                iterations. No intermediate output will be produced */
  /*                if I_refresh is < 1 */
  /*  I_plotting    Will use plotting if set to 1. Will skip plotting otherwise. */
  /* -----Definition of tolerance scheme-------------------------------------- */
  /* -----The scheme is sampled at I_lentol points---------------------------- */
  /* ordinate running from -1 to +1 */
  /* upper limit is 1 */
  /* lower limit is -1 */
  /* Tell comiler abut variable sizes */
  /* -----tie all important values to a structure that can be passed along---- */
  for (i2 = 0; i2 < 2; i2++) {
    S_struct_FVr_minbound[i2] = problem->fitconstr[i2];
    S_struct_FVr_maxbound[i2] = problem->fitconstr[2 + i2];
  }

  rascal_deopt(problem->data, S_struct_FVr_minbound, S_struct_FVr_maxbound,
               unusedExpr);
}

/* End of code generation (linear_DE_new_test.c) */
