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
#include "backSort.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo fc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    41,         /* lineNo */
    13,         /* colNo */
    "backs",    /* aName */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    41,         /* lineNo */
    13,         /* colNo */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    44,         /* lineNo */
    14,         /* colNo */
    "shifts",   /* aName */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    44,         /* lineNo */
    14,         /* colNo */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    47,         /* lineNo */
    10,         /* colNo */
    "sf",       /* aName */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    47,         /* lineNo */
    10,         /* colNo */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    50,         /* lineNo */
    11,         /* colNo */
    "nba",      /* aName */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    50,         /* lineNo */
    11,         /* colNo */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    53,         /* lineNo */
    11,         /* colNo */
    "nbs",      /* aName */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    53,         /* lineNo */
    11,         /* colNo */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    57,         /* lineNo */
    17,         /* colNo */
    "res",      /* aName */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    57,         /* lineNo */
    17,         /* colNo */
    "backSort", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

/* Function Definitions */
void backSort(const emlrtStack *sp, real_T cBacks, real_T cShifts,
              real_T cScales, real_T cNbas, real_T cNbss, real_T cRes,
              const emxArray_real_T *backs, const emxArray_real_T *shifts,
              const emxArray_real_T *sf, const emxArray_real_T *nba,
              const emxArray_real_T *nbs, const emxArray_real_T *res,
              real_T *backg, real_T *qshift, real_T *b_sf, real_T *b_nba,
              real_T *b_nbs, real_T *resol)
{
  /* Distributes the background and shift values among the different contrasts.
   */
  /*  */
  /* [backgs,qshifts,sfs,nbas,nbss,resols] =
   * backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res)
   */
  /*  Inputs: */
  /*        nc = number of contrasts (double) */
  /*        cBacks = Which backround value is associated with each contrast? */
  /*        cShifts = Which qz_shift value is associated with each contrast? */
  /*        cScales = Which scalefactor value is associated with each contrast?
   */
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
  if (cBacks != (int32_T)muDoubleScalarFloor(cBacks)) {
    emlrtIntegerCheckR2012b(cBacks, &g_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cBacks < 1) || ((int32_T)cBacks > backs->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cBacks, 1, backs->size[1],
                                  &fc_emlrtBCI, (emlrtCTX)sp);
  }
  *backg = backs->data[(int32_T)cBacks - 1];
  /* thisShift = cShifts(i); */
  if (cShifts != (int32_T)muDoubleScalarFloor(cShifts)) {
    emlrtIntegerCheckR2012b(cShifts, &h_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cShifts < 1) || ((int32_T)cShifts > shifts->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cShifts, 1, shifts->size[1],
                                  &gc_emlrtBCI, (emlrtCTX)sp);
  }
  *qshift = shifts->data[(int32_T)cShifts - 1];
  /* thisScale = cScales(i); */
  if (cScales != (int32_T)muDoubleScalarFloor(cScales)) {
    emlrtIntegerCheckR2012b(cScales, &i_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cScales < 1) || ((int32_T)cScales > sf->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cScales, 1, sf->size[1],
                                  &hc_emlrtBCI, (emlrtCTX)sp);
  }
  *b_sf = sf->data[(int32_T)cScales - 1];
  /* thisNbair = cNbas(i); */
  if (cNbas != (int32_T)muDoubleScalarFloor(cNbas)) {
    emlrtIntegerCheckR2012b(cNbas, &j_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cNbas < 1) || ((int32_T)cNbas > nba->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cNbas, 1, nba->size[1], &ic_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  *b_nba = nba->data[(int32_T)cNbas - 1];
  /* thisNbsub = cNbss(i); */
  if (cNbss != (int32_T)muDoubleScalarFloor(cNbss)) {
    emlrtIntegerCheckR2012b(cNbss, &k_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cNbss < 1) || ((int32_T)cNbss > nbs->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cNbss, 1, nbs->size[1], &jc_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  *b_nbs = nbs->data[(int32_T)cNbss - 1];
  /* thisResol = cRes(i); */
  if (cRes != -1.0) {
    if (cRes != (int32_T)muDoubleScalarFloor(cRes)) {
      emlrtIntegerCheckR2012b(cRes, &l_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)cRes < 1) || ((int32_T)cRes > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cRes, 1, res->size[1],
                                    &kc_emlrtBCI, (emlrtCTX)sp);
    }
    *resol = res->data[(int32_T)cRes - 1];
  } else {
    *resol = -1.0;
    /*  Negative value means we have a data resolution.. */
  }
  /* end */
}

/* End of code generation (backSort.c) */
