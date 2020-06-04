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
#include "callReflectivity.h"
#include "main.h"
#include "callReflectivity_terminate.h"
#include "callReflectivity_emxAPI.h"
#include "callReflectivity_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static void argInit_51x3_real_T(double result[153]);
static void argInit_d42x3_real_T(double result_data[], int result_size[2]);
static double argInit_real_T(void);
static void main_callReflectivity(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  double result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;
}

static void argInit_51x3_real_T(double result[153])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 51; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 51] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 102] = argInit_real_T();
  }
}

static void argInit_d42x3_real_T(double result_data[], int result_size[2])
{
  int idx0;
  double result_data_tmp;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 2;
  result_size[1] = 3;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data_tmp = argInit_real_T();
    result_data[idx0] = result_data_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[idx0 + 2] = result_data_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[idx0 + 4] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_callReflectivity(void)
{
  emxArray_real_T *Simulation;
  double nbairs_tmp;
  double simLimits_tmp[2];
  double this_data[153];
  double layers_data[126];
  int layers_size[2];
  double reflectivity[102];
  emxInitArray_real_T(&Simulation, 2);

  /* Initialize function 'callReflectivity' input arguments. */
  nbairs_tmp = argInit_real_T();

  /* Initialize function input argument 'simLimits'. */
  argInit_1x2_real_T(simLimits_tmp);

  /* Initialize function input argument 'repeatLayers'. */
  /* Initialize function input argument 'this_data'. */
  argInit_51x3_real_T(this_data);

  /* Initialize function input argument 'layers'. */
  argInit_d42x3_real_T(layers_data, layers_size);

  /* Call the entry-point 'callReflectivity'. */
  callReflectivity(nbairs_tmp, nbairs_tmp, simLimits_tmp, simLimits_tmp,
                   this_data, layers_data, layers_size, argInit_real_T(),
                   argInit_real_T(), argInit_real_T(), reflectivity, Simulation);
  emxDestroyArray_real_T(Simulation);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  callReflectivity_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_callReflectivity();

  /* Terminate the application.
     You do not need to do this more than one time. */
  callReflectivity_terminate();
  return 0;
}

/* End of code generation (main.c) */
