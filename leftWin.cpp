//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// leftWin.cpp
//
// Code generation for function 'leftWin'
//

// Include files
#include "leftWin.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  double leftWin(double S_x_I_no, double S_x_FVr_oa, double S_y_FVr_oa)
  {
    double I_z;

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Function:         I_z = left_win(S_x,S_y)
    //  Author:           Rainer Storn
    //  Description:      left_win(S_x,S_y) takes structures S_x and S_y as an argument.
    //                    The function returns 1 if the left structure of the input structures,
    //                    i.e. S_x, wins. If the right structure, S_y, wins, the result is 0.
    //  Parameters:       S_x.I_nc     (I)    Number of constraints (must be the same for x and y).
    //                    S_x.I_no     (I)    Number of objectives (must be the same for x and y).
    //                    S_x.FVr_ca   (I)    Constraint array containing the constraint violation values.
    //                                        If the value is 0 the constraint is met. If it is > 0 it is
    //                                        still violated.
    //                    S_x.FVr_oa   (I)    Objective array containing cost values which are supposed to be
    //                                        minimized.
    //  Return value:     I_z          (O)    If S_x wins over S_y then I_z=1 else I_z=0.
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Compare the objective function for two DE candidate points.
    //
    //  Parameters
    //  ----------
    //  S_x, S_y : struct
    //      The two points to compare.
    //
    //  Returns
    //  -------
    //  I_z : bool
    //      Whether S_x has a lower objective function value than S_y.
    //
    I_z = 1.0;

    // start with I_z=1
    // ----deal with the constraints first. If constraints are not met------
    // ----S_x can't win.---------------------------------------------------
    if ((S_x_I_no > 0.0) && (S_x_FVr_oa > S_y_FVr_oa)) {
      // if just one objective of S_x is less
      I_z = 0.0;
    }

    return I_z;
  }
}

// End of code generation (leftWin.cpp)
