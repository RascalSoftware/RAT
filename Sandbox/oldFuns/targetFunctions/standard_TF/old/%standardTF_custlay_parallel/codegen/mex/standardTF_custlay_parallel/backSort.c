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
#include "standardTF_custlay_parallel.h"
#include "backSort.h"

/* Variable Definitions */
static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "backs",                             /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 39,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  14,                                  /* colNo */
  "shifts",                            /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 42,  /* lineNo */
  14,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  10,                                  /* colNo */
  "sf",                                /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 45,  /* lineNo */
  10,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  11,                                  /* colNo */
  "nba",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 48,  /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  11,                                  /* colNo */
  "nbs",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 51,  /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  13,                                  /* colNo */
  "res",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 54,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void backSort(const emlrtStack *sp, real_T cBacks, real_T cShifts, real_T
              cScales, real_T cNbas, real_T cNbss, real_T cRes, const
              emxArray_real_T *backs, const emxArray_real_T *shifts, const
              emxArray_real_T *sf, const emxArray_real_T *nba, const
              emxArray_real_T *nbs, const emxArray_real_T *res, real_T *backg,
              real_T *qshift, real_T *b_sf, real_T *b_nba, real_T *b_nbs, real_T
              *resol)
{
  int32_T i4;
  int32_T i5;

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
  i4 = backs->size[1];
  if (cBacks != (int32_T)muDoubleScalarFloor(cBacks)) {
    emlrtIntegerCheckR2012b(cBacks, &r_emlrtDCI, sp);
  }

  i5 = (int32_T)cBacks;
  if (!((i5 >= 1) && (i5 <= i4))) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tb_emlrtBCI, sp);
  }

  *backg = backs->data[i5 - 1];

  /* thisShift = cShifts(i); */
  i4 = shifts->size[1];
  if (cShifts != (int32_T)muDoubleScalarFloor(cShifts)) {
    emlrtIntegerCheckR2012b(cShifts, &s_emlrtDCI, sp);
  }

  i5 = (int32_T)cShifts;
  if (!((i5 >= 1) && (i5 <= i4))) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ub_emlrtBCI, sp);
  }

  *qshift = shifts->data[i5 - 1];

  /* thisScale = cScales(i); */
  i4 = sf->size[1];
  if (cScales != (int32_T)muDoubleScalarFloor(cScales)) {
    emlrtIntegerCheckR2012b(cScales, &t_emlrtDCI, sp);
  }

  i5 = (int32_T)cScales;
  if (!((i5 >= 1) && (i5 <= i4))) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vb_emlrtBCI, sp);
  }

  *b_sf = sf->data[i5 - 1];

  /* thisNbair = cNbas(i); */
  i4 = nba->size[1];
  if (cNbas != (int32_T)muDoubleScalarFloor(cNbas)) {
    emlrtIntegerCheckR2012b(cNbas, &u_emlrtDCI, sp);
  }

  i5 = (int32_T)cNbas;
  if (!((i5 >= 1) && (i5 <= i4))) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wb_emlrtBCI, sp);
  }

  *b_nba = nba->data[i5 - 1];

  /* thisNbsub = cNbss(i); */
  i4 = nbs->size[1];
  if (cNbss != (int32_T)muDoubleScalarFloor(cNbss)) {
    emlrtIntegerCheckR2012b(cNbss, &v_emlrtDCI, sp);
  }

  i5 = (int32_T)cNbss;
  if (!((i5 >= 1) && (i5 <= i4))) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xb_emlrtBCI, sp);
  }

  *b_nbs = nbs->data[i5 - 1];

  /* thisResol = cRes(i); */
  i4 = res->size[1];
  if (cRes != (int32_T)muDoubleScalarFloor(cRes)) {
    emlrtIntegerCheckR2012b(cRes, &w_emlrtDCI, sp);
  }

  i5 = (int32_T)cRes;
  if (!((i5 >= 1) && (i5 <= i4))) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yb_emlrtBCI, sp);
  }

  *resol = res->data[i5 - 1];

  /* end */
}

/* End of code generation (backSort.c) */
