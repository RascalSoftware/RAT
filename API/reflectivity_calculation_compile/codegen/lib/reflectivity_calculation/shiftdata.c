/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * shiftdata.c
 *
 * Code generation for function 'shiftdata'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "shiftdata.h"

/* Function Definitions */
void shiftdata(double scalefac, double horshift, double dataPresent, double
               data[153], const double dataLimits[2], double shifted_data_data[],
               int shifted_data_size[2])
{
  int hiIndex;
  int idx;
  double d0;
  boolean_T exitg1;
  boolean_T x[51];
  signed char ii_data[51];
  int lowIndex;
  int i10;

  /* Shifts the data according to scale factor */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  switch ((int)dataPresent) {
   case 1:
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }

    for (hiIndex = 0; hiIndex < 51; hiIndex++) {
      d0 = data[hiIndex] + horshift;
      data[hiIndex] = d0;
      data[51 + hiIndex] /= scalefac;
      data[102 + hiIndex] /= scalefac;
      x[hiIndex] = (d0 < dataLimits[0]);
    }

    idx = 0;
    hiIndex = 0;
    exitg1 = false;
    while ((!exitg1) && (hiIndex < 51)) {
      if (x[hiIndex]) {
        idx++;
        ii_data[idx - 1] = (signed char)(hiIndex + 1);
        if (idx >= 51) {
          exitg1 = true;
        } else {
          hiIndex++;
        }
      } else {
        hiIndex++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    if (idx != 0) {
      lowIndex = ii_data[idx - 1];
    } else {
      lowIndex = 1;
    }

    for (hiIndex = 0; hiIndex < 51; hiIndex++) {
      x[hiIndex] = (data[hiIndex] > dataLimits[1]);
    }

    idx = 0;
    hiIndex = 0;
    exitg1 = false;
    while ((!exitg1) && (hiIndex < 51)) {
      if (x[hiIndex]) {
        idx++;
        ii_data[idx - 1] = (signed char)(hiIndex + 1);
        if (idx >= 51) {
          exitg1 = true;
        } else {
          hiIndex++;
        }
      } else {
        hiIndex++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    if (idx != 0) {
      hiIndex = ii_data[0];
    } else {
      hiIndex = 51;
    }

    if (lowIndex > hiIndex) {
      lowIndex = 1;
      hiIndex = 0;
    }

    idx = hiIndex - lowIndex;
    shifted_data_size[0] = idx + 1;
    shifted_data_size[1] = 3;
    for (hiIndex = 0; hiIndex < 3; hiIndex++) {
      for (i10 = 0; i10 <= idx; i10++) {
        shifted_data_data[i10 + shifted_data_size[0] * hiIndex] = data
          [((lowIndex + i10) + 51 * hiIndex) - 1];
      }
    }
    break;

   default:
    shifted_data_size[0] = 51;
    shifted_data_size[1] = 3;
    memcpy(&shifted_data_data[0], &data[0], 153U * sizeof(double));
    break;
  }

  /*  function Ref = makeFresnelData(problem,contrast) */
  /*   */
  /*      this_data = problem.shifted_data{contrast}; */
  /*      xdata = this_data(:,1); */
  /*      nbair = problem.nbairs(contrast); */
  /*      nbsub = problem.nbsubs(contrast); */
  /*      slds = [0 0 0]; */
  /*      resol = problem.resolution; */
  /*      resolType = problem.resolType; */
  /*      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol) */
  /*      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats, */
  /*      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); */
}

/* End of code generation (shiftdata.c) */
