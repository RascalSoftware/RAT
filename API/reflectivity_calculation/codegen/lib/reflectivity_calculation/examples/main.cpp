//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
#include "main.h"
#include "allocateParamsToLayers.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_terminate.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_reflectivityCalculation.h"

// Function Declarations
static void argInit_1x2_real_T(double result[2]);
static coder::array<cell_wrap_0, 2U> argInit_1xUnbounded_cell_wrap_0();
static coder::array<cell_wrap_1, 2U> argInit_1xUnbounded_cell_wrap_1();
static coder::array<cell_wrap_2, 2U> argInit_1xUnbounded_cell_wrap_2();
static coder::array<cell_wrap_4, 2U> argInit_1xUnbounded_cell_wrap_4();
static coder::array<char, 2U> argInit_1xUnbounded_char_T();
static coder::array<double, 2U> argInit_1xUnbounded_real_T();
static void argInit_1xd5_real_T(double result_data[], int result_size[2]);
static coder::array<cell_wrap_3, 1U> argInit_Unboundedx1_cell_wrap_3();
static coder::array<double, 2U> argInit_Unboundedx2_real_T();
static coder::array<double, 2U> argInit_Unboundedx3_real_T();
static void argInit_cell_5(cell_5 *result);
static cell_wrap_0 argInit_cell_wrap_0();
static cell_wrap_1 argInit_cell_wrap_1();
static cell_wrap_2 argInit_cell_wrap_2();
static cell_wrap_3 argInit_cell_wrap_3();
static cell_wrap_4 argInit_cell_wrap_4();
static char argInit_char_T();
static coder::array<double, 2U> argInit_d1xUnbounded_real_T();
static double argInit_real_T();
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void argInit_struct2_T(struct2_T *result);
static void argInit_struct3_T(struct3_T *result);
static coder::array<double, 2U> c_argInit_UnboundedxUnbounded_r();
static void main_reflectivity_calculation();

// Function Definitions

//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  double result_tmp;

  // Loop over the array to initialize each element.
  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[1] = result_tmp;
}

//
// Arguments    : void
// Return Type  : coder::array<cell_wrap_0, 2U>
//
static coder::array<cell_wrap_0, 2U> argInit_1xUnbounded_cell_wrap_0()
{
  coder::array<cell_wrap_0, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < result.size(1); idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_cell_wrap_0();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<cell_wrap_1, 2U>
//
static coder::array<cell_wrap_1, 2U> argInit_1xUnbounded_cell_wrap_1()
{
  coder::array<cell_wrap_1, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < result.size(1); idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_cell_wrap_1();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<cell_wrap_2, 2U>
//
static coder::array<cell_wrap_2, 2U> argInit_1xUnbounded_cell_wrap_2()
{
  coder::array<cell_wrap_2, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < result.size(1); idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_cell_wrap_2();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<cell_wrap_4, 2U>
//
static coder::array<cell_wrap_4, 2U> argInit_1xUnbounded_cell_wrap_4()
{
  coder::array<cell_wrap_4, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < result.size(1); idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_cell_wrap_4();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<char, 2U>
//
static coder::array<char, 2U> argInit_1xUnbounded_char_T()
{
  coder::array<char, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < result.size(1); idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_char_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_1xUnbounded_real_T()
{
  coder::array<double, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < result.size(1); idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }

  return result;
}

//
// Arguments    : double result_data[]
//                int result_size[2]
// Return Type  : void
//
static void argInit_1xd5_real_T(double result_data[], int result_size[2])
{
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 1;
  result_size[1] = 2;

  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : coder::array<cell_wrap_3, 1U>
//
static coder::array<cell_wrap_3, 1U> argInit_Unboundedx1_cell_wrap_3()
{
  coder::array<cell_wrap_3, 1U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);

  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_cell_wrap_3();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx2_real_T()
{
  coder::array<double, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);

  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < result.size(0); idx0++) {
    double result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + result.size(0)] = result_tmp;
  }

  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx3_real_T()
{
  coder::array<double, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 3);

  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < result.size(0); idx0++) {
    double result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + result.size(0)] = result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + result.size(0) * 2] = result_tmp;
  }

  return result;
}

//
// Arguments    : cell_5 *result
// Return Type  : void
//
static void argInit_cell_5(cell_5 *result)
{
  coder::array<cell_wrap_0, 2U> result_tmp;
  coder::array<cell_wrap_4, 2U> b_result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_1xUnbounded_cell_wrap_0();
  result->f1 = result_tmp;
  result->f2 = argInit_1xUnbounded_cell_wrap_1();
  result->f3 = result_tmp;
  result->f4 = result_tmp;
  result->f5 = argInit_1xUnbounded_cell_wrap_2();
  result->f6 = argInit_Unboundedx1_cell_wrap_3();
  b_result_tmp = argInit_1xUnbounded_cell_wrap_4();
  result->f7 = b_result_tmp;
  result->f8 = b_result_tmp;
  result->f9 = b_result_tmp;
  result->f10 = b_result_tmp;
  result->f11 = b_result_tmp;
  result->f12 = b_result_tmp;
  result->f13 = b_result_tmp;
}

//
// Arguments    : void
// Return Type  : cell_wrap_0
//
static cell_wrap_0 argInit_cell_wrap_0()
{
  cell_wrap_0 result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x2_real_T(result.f1);
  return result;
}

//
// Arguments    : void
// Return Type  : cell_wrap_1
//
static cell_wrap_1 argInit_cell_wrap_1()
{
  cell_wrap_1 result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.f1 = argInit_Unboundedx3_real_T();
  return result;
}

//
// Arguments    : void
// Return Type  : cell_wrap_2
//
static cell_wrap_2 argInit_cell_wrap_2()
{
  cell_wrap_2 result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.f1 = argInit_d1xUnbounded_real_T();
  return result;
}

//
// Arguments    : void
// Return Type  : cell_wrap_3
//
static cell_wrap_3 argInit_cell_wrap_3()
{
  cell_wrap_3 result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1xd5_real_T(result.f1.data, result.f1.size);
  return result;
}

//
// Arguments    : void
// Return Type  : cell_wrap_4
//
static cell_wrap_4 argInit_cell_wrap_4()
{
  cell_wrap_4 result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.f1 = argInit_1xUnbounded_char_T();
  return result;
}

//
// Arguments    : void
// Return Type  : char
//
static char argInit_char_T()
{
  return '?';
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_d1xUnbounded_real_T()
{
  coder::array<double, 2U> result;
  int idx0;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);

  // Loop over the array to initialize each element.
  idx0 = 0;
  while (idx0 < result.size(0)) {
    for (idx0 = 0; idx0 < result.size(1); idx0++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[result.size(0) * idx0] = argInit_real_T();
    }

    idx0 = 1;
  }

  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T *result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp;
  coder::array<double, 2U> b_result_tmp;
  coder::array<char, 2U> c_result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result->numberOfLayers = result_tmp;
  b_result_tmp = argInit_1xUnbounded_real_T();
  result->contrastBacks = b_result_tmp;
  result->contrastBacksType = b_result_tmp;
  c_result_tmp = argInit_1xUnbounded_char_T();
  result->TF = c_result_tmp;
  result->resample = b_result_tmp;
  result->dataPresent = b_result_tmp;
  result->numberOfContrasts = result_tmp;
  result->geometry = c_result_tmp;
  result->contrastShifts = b_result_tmp;
  result->contrastScales = b_result_tmp;
  result->contrastNbas = b_result_tmp;
  result->contrastNbss = b_result_tmp;
  result->contrastRes = b_result_tmp;
  result->backs = b_result_tmp;
  result->shifts = b_result_tmp;
  result->sf = b_result_tmp;
  result->nba = b_result_tmp;
  result->nbs = b_result_tmp;
  result->res = b_result_tmp;
  result->params = b_result_tmp;
  result->modelType = c_result_tmp;
  result->modelFilename = c_result_tmp;
  result->path = c_result_tmp;
  result->modelLanguage = c_result_tmp;
  b_result_tmp = c_argInit_UnboundedxUnbounded_r();
  result->fitpars = b_result_tmp;
  result->otherpars = b_result_tmp;
  result->fitconstr = b_result_tmp;
  result->otherconstr = b_result_tmp;
}

//
// Arguments    : struct1_T *result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T *result)
{
  coder::array<double, 2U> result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_Unboundedx2_real_T();
  result->params = result_tmp;
  result->backs = result_tmp;
  result->scales = result_tmp;
  result->shifts = result_tmp;
  result->nba = result_tmp;
  result->nbs = result_tmp;
  result->res = result_tmp;
}

//
// Arguments    : struct2_T *result
// Return Type  : void
//
static void argInit_struct2_T(struct2_T *result)
{
  double result_tmp;
  coder::array<char, 2U> b_result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result->tolFun = result_tmp;
  result->maxFunEvals = result_tmp;
  result->maxIter = result_tmp;
  result->populationSize = result_tmp;
  result->F_weight = result_tmp;
  result->F_CR = result_tmp;
  result->VTR = result_tmp;
  result->numGen = result_tmp;
  result->Nlive = result_tmp;
  result->nmcmc = result_tmp;
  result->propScale = result_tmp;
  result->nsTolerance = result_tmp;
  result->calcSld = result_tmp;
  b_result_tmp = argInit_1xUnbounded_char_T();
  result->para = b_result_tmp;
  result->proc = b_result_tmp;
  result->display = b_result_tmp;
  result->tolX = result_tmp;
  result->strategy = argInit_1xUnbounded_real_T();
  argInit_struct3_T(&result->checks);
}

//
// Arguments    : struct3_T *result
// Return Type  : void
//
static void argInit_struct3_T(struct3_T *result)
{
  coder::array<double, 2U> result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_1xUnbounded_real_T();
  result->params_fitYesNo = result_tmp;
  result->backs_fitYesNo = result_tmp;
  result->shifts_fitYesNo = result_tmp;
  result->scales_fitYesNo = result_tmp;
  result->nbairs_fitYesNo = result_tmp;
  result->nbsubs_fitYesNo = result_tmp;
  result->resol_fitYesNo = result_tmp;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> c_argInit_UnboundedxUnbounded_r()
{
  coder::array<double, 2U> result;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);

  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < result.size(0); idx0++) {
    for (int idx1 = 0; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_real_T();
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_reflectivity_calculation()
{
  struct0_T problemDef;
  cell_5 problemDef_cells;
  struct1_T problemDef_limits;
  struct2_T controls;
  struct4_T problem;
  cell_7 result;

  // Initialize function 'reflectivity_calculation' input arguments.
  // Initialize function input argument 'problemDef'.
  argInit_struct0_T(&problemDef);

  // Initialize function input argument 'problemDef_cells'.
  argInit_cell_5(&problemDef_cells);

  // Initialize function input argument 'problemDef_limits'.
  argInit_struct1_T(&problemDef_limits);

  // Initialize function input argument 'controls'.
  argInit_struct2_T(&controls);

  // Call the entry-point 'reflectivity_calculation'.
  reflectivity_calculation(&problemDef, &problemDef_cells, &problemDef_limits,
    &controls, &problem, &result);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. 
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_reflectivity_calculation();

  // Terminate the application.
  // You do not need to do this more than one time.
  reflectivity_calculation_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
