/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "linear_DE_new_test.h"
#include "main.h"
#include "linear_DE_new_test_terminate.h"
#include "linear_DE_new_test_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static void argInit_2x1_real_T(double result[2]);
static void argInit_2x2_real_T(double result[4]);
static void argInit_5x3_real_T(double result[15]);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void main_linear_DE_new_test(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_2x1_real_T(double result[2])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_2x2_real_T(double result[4])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 1)] = argInit_real_T();
    }
  }
}

static void argInit_5x3_real_T(double result[15])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    for (idx1 = 0; idx1 < 3; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 5 * idx1] = argInit_real_T();
    }
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void argInit_struct0_T(struct0_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_5x3_real_T(result->data);
  argInit_1x2_real_T(result->fitpars);
  argInit_2x2_real_T(result->fitconstr);
  argInit_struct1_T(&result->S_struct);
}

static void argInit_struct1_T(struct1_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->I_lentol = argInit_real_T();
  result->FVr_x = argInit_real_T();
  result->FVr_lim_up = argInit_real_T();
  result->FVr_lim_lo = argInit_real_T();
  result->I_NP = argInit_real_T();
  result->F_weight = argInit_real_T();
  result->F_CR = argInit_real_T();
  result->I_D = argInit_real_T();
  argInit_2x1_real_T(result->FVr_minbound);
  argInit_2x1_real_T(result->FVr_maxbound);
  argInit_2x2_real_T(result->I_bnd_constr);
  result->I_itermax = argInit_real_T();
  result->F_VTR = argInit_real_T();
  result->I_strategy = argInit_real_T();
  result->I_refresh = argInit_real_T();
  result->I_plotting = argInit_real_T();
}

static void main_linear_DE_new_test(void)
{
  struct0_T problem;

  /* Initialize function 'linear_DE_new_test' input arguments. */
  /* Initialize function input argument 'problem'. */
  argInit_struct0_T(&problem);

  /* Initialize function input argument 'controls'. */
  /* Call the entry-point 'linear_DE_new_test'. */
  linear_DE_new_test(&problem);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  linear_DE_new_test_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_linear_DE_new_test();

  /* Terminate the application.
     You do not need to do this more than one time. */
  linear_DE_new_test_terminate();
  return 0;
}

/* End of code generation (main.c) */
