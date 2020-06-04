/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * left_win.c
 *
 * Code generation for function 'left_win'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "linear_DE_new_test.h"
#include "left_win.h"

/* Function Definitions */
double left_win(double S_x_I_no, double S_x_FVr_oa, double S_y_FVr_oa)
{
  double I_z;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Function:         I_z = left_win(S_x,S_y) */
  /*  Author:           Rainer Storn */
  /*  Description:      left_win(S_x,S_y) takes structures S_x and S_y as an argument. */
  /*                    The function returns 1 if the left structure of the input structures, */
  /*                    i.e. S_x, wins. If the right structure, S_y, wins, the result is 0. */
  /*  Parameters:       S_x.I_nc     (I)    Number of constraints (must be the same for x and y). */
  /*                    S_x.I_no     (I)    Number of objectives (must be the same for x and y). */
  /*                    S_x.FVr_ca   (I)    Constraint array containing the constraint violation values. */
  /*                                        If the value is 0 the constraint is met. If it is > 0 it is */
  /*                                        still violated. */
  /*                    S_x.FVr_oa   (I)    Objective array containing cost values which are supposed to be */
  /*                                        minimized. */
  /*  Return value:     I_z          (O)    If S_x wins over S_y then I_z=1 else I_z=0. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  I_z = 1.0;

  /* start with I_z=1 */
  /* ----deal with the constraints first. If constraints are not met------ */
  /* ----S_x can't win.--------------------------------------------------- */
  if ((S_x_I_no > 0.0) && (S_x_FVr_oa > S_y_FVr_oa)) {
    /* if just one objective of S_x is less */
    I_z = 0.0;
  }

  return I_z;
}

/* End of code generation (left_win.c) */
