/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * backSort.c
 *
 * Code generation for function 'backSort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "backSort.h"

/* Function Definitions */
void backSort(double cBacks, double cShifts, double cScales, double cNbas,
              double cNbss, double cRes, const emxArray_real_T *backs, const
              emxArray_real_T *shifts, const emxArray_real_T *sf, const
              emxArray_real_T *nba, const emxArray_real_T *nbs, const
              emxArray_real_T *res, double *backg, double *qshift, double *b_sf,
              double *b_nba, double *b_nbs, double *resol)
{
  /* Distributes the background and shift values among the different contrasts. */
  /*  */
  /* [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) */
  /*  Inputs: */
  /*        nc = number of contrasts (double) */
  /*        cBacks = Which backround value is associated with each contrast? */
  /*        cShifts = Which qz_shift value is associated with each contrast? */
  /*        cScales = Which scalefactor value is associated with each contrast? */
  /*        cNba = Which NBa value is associated with each contrast? */
  /*        cNbs = Which Nbs value is associated with each contrast? */
  /*        cRes = Which resolution value is associated with each contrast? */
  /*        backs = List of all background values. */
  /*        shifts = List of all qz-shift values */
  /*        sf = List of all scalefactor values */
  /*        nba = List of all nba values */
  /*        nbs = List of all nbs values */
  /*        res = List of all resolution values */
  /*  */
  /*  Outputs: */
  /*        backgs = list of actual background values for each contrast */
  /*        qshifts = list of actual shift values for each contrast       */
  /*        sfs = list of actual shift values for each contrast      */
  /*        nbas = list of actual shift values for each contrast      */
  /*        nbss = list of actual shift values for each contrast */
  /*        nbss = list of actual shift values for each contrast   */
  /*  backgs = 0;%zeros(1,nc); */
  /*  qshifts = 0;%zeros(1,nc); */
  /*  sfs = 0;%zeros(1,nc); */
  /*  nbas = 0;%zeros(1,nc); */
  /*  nbss = 0;%zeros(1,nc); */
  /*  resols = 0;%zeros(1,nc); */
  /* for i = 1:nc */
  /* thisBack = cBacks(i); */
  *backg = backs->data[(int)cBacks - 1];

  /* thisShift = cShifts(i); */
  *qshift = shifts->data[(int)cShifts - 1];

  /* thisScale = cScales(i); */
  *b_sf = sf->data[(int)cScales - 1];

  /* thisNbair = cNbas(i); */
  *b_nba = nba->data[(int)cNbas - 1];

  /* thisNbsub = cNbss(i); */
  *b_nbs = nbs->data[(int)cNbss - 1];

  /* thisResol = cRes(i); */
  *resol = res->data[(int)cRes - 1];

  /* end */
}

/* End of code generation (backSort.c) */
