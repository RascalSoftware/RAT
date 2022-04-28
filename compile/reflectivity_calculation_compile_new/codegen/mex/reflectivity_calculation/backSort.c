/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * backSort.c
 *
 * Code generation for function 'backSort'
 *
 */

/* Include files */
#include "backSort.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo gf_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    41,         /* lineNo */
    19,         /* colNo */
    "backs",    /* aName */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = {
    41,         /* lineNo */
    19,         /* colNo */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    44,         /* lineNo */
    21,         /* colNo */
    "shifts",   /* aName */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = {
    44,         /* lineNo */
    21,         /* colNo */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    47,         /* lineNo */
    13,         /* colNo */
    "sf",       /* aName */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = {
    47,         /* lineNo */
    13,         /* colNo */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    50,         /* lineNo */
    15,         /* colNo */
    "nba",      /* aName */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = {
    50,         /* lineNo */
    15,         /* colNo */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo kf_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    53,         /* lineNo */
    15,         /* colNo */
    "nbs",      /* aName */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = {
    53,         /* lineNo */
    15,         /* colNo */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    1             /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    57,         /* lineNo */
    21,         /* colNo */
    "res",      /* aName */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
    "backSort.m", /* pName */
    0             /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = {
    57,         /* lineNo */
    21,         /* colNo */
    "backSort", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/"
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
  const real_T *backs_data;
  const real_T *nba_data;
  const real_T *nbs_data;
  const real_T *res_data;
  const real_T *sf_data;
  const real_T *shifts_data;
  res_data = res->data;
  nbs_data = nbs->data;
  nba_data = nba->data;
  sf_data = sf->data;
  shifts_data = shifts->data;
  backs_data = backs->data;
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
    emlrtIntegerCheckR2012b(cBacks, &v_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cBacks < 1) || ((int32_T)cBacks > backs->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cBacks, 1, backs->size[1],
                                  &gf_emlrtBCI, (emlrtCTX)sp);
  }
  *backg = backs_data[(int32_T)cBacks - 1];
  /* thisShift = cShifts(i); */
  if (cShifts != (int32_T)muDoubleScalarFloor(cShifts)) {
    emlrtIntegerCheckR2012b(cShifts, &w_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cShifts < 1) || ((int32_T)cShifts > shifts->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cShifts, 1, shifts->size[1],
                                  &hf_emlrtBCI, (emlrtCTX)sp);
  }
  *qshift = shifts_data[(int32_T)cShifts - 1];
  /* thisScale = cScales(i); */
  if (cScales != (int32_T)muDoubleScalarFloor(cScales)) {
    emlrtIntegerCheckR2012b(cScales, &x_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cScales < 1) || ((int32_T)cScales > sf->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cScales, 1, sf->size[1],
                                  &if_emlrtBCI, (emlrtCTX)sp);
  }
  *b_sf = sf_data[(int32_T)cScales - 1];
  /* thisNbair = cNbas(i); */
  if (cNbas != (int32_T)muDoubleScalarFloor(cNbas)) {
    emlrtIntegerCheckR2012b(cNbas, &y_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cNbas < 1) || ((int32_T)cNbas > nba->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cNbas, 1, nba->size[1], &jf_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  *b_nba = nba_data[(int32_T)cNbas - 1];
  /* thisNbsub = cNbss(i); */
  if (cNbss != (int32_T)muDoubleScalarFloor(cNbss)) {
    emlrtIntegerCheckR2012b(cNbss, &ab_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)cNbss < 1) || ((int32_T)cNbss > nbs->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)cNbss, 1, nbs->size[1], &kf_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  *b_nbs = nbs_data[(int32_T)cNbss - 1];
  /* thisResol = cRes(i); */
  if (cRes != -1.0) {
    if (cRes != (int32_T)muDoubleScalarFloor(cRes)) {
      emlrtIntegerCheckR2012b(cRes, &bb_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)cRes < 1) || ((int32_T)cRes > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cRes, 1, res->size[1],
                                    &lf_emlrtBCI, (emlrtCTX)sp);
    }
    *resol = res_data[(int32_T)cRes - 1];
  } else {
    *resol = -1.0;
    /*  Negative value means we have a data resolution.. */
  }
  /* end */
}

/* End of code generation (backSort.c) */
