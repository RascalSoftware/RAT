//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  backSort.cpp
//
//  Code generation for function 'backSort'
//


// Include files
#include "backSort.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtBCInfo yd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  41,                                  // lineNo
  13,                                  // colNo
  "backs",                             // aName
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo y_emlrtDCI = { 41,  // lineNo
  13,                                  // colNo
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ae_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  14,                                  // colNo
  "shifts",                            // aName
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI = { 44, // lineNo
  14,                                  // colNo
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo be_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  47,                                  // lineNo
  10,                                  // colNo
  "sf",                                // aName
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo bb_emlrtDCI = { 47, // lineNo
  10,                                  // colNo
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ce_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  11,                                  // colNo
  "nba",                               // aName
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI = { 50, // lineNo
  11,                                  // colNo
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo de_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  53,                                  // lineNo
  11,                                  // colNo
  "nbs",                               // aName
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI = { 53, // lineNo
  11,                                  // colNo
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ee_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  56,                                  // lineNo
  13,                                  // colNo
  "res",                               // aName
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI = { 56, // lineNo
  13,                                  // colNo
  "backSort",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",// pName 
  1                                    // checkKind
};

// Function Definitions
void backSort(const emlrtStack *sp, real_T cBacks, real_T cShifts, real_T
              cScales, real_T cNbas, real_T cNbss, real_T cRes, const coder::
              array<real_T, 2U> &backs, const coder::array<real_T, 2U> &shifts,
              const coder::array<real_T, 2U> &sf, const coder::array<real_T, 2U>
              &nba, const coder::array<real_T, 2U> &nbs, const coder::array<
              real_T, 2U> &res, real_T *backg, real_T *qshift, real_T *b_sf,
              real_T *b_nba, real_T *b_nbs, real_T *resol)
{
  int32_T i;

  // Distributes the background and shift values among the different contrasts.
  //
  // [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) 
  //  Inputs:
  //        nc = number of contrasts (double)
  //        cBacks = Which backround value is associated with each contrast?
  //        cShifts = Which qz_shift value is associated with each contrast?
  //        cScales = Which scalefactor value is associated with each contrast?
  //        cNba = Which NBa value is associated with each contrast?
  //        cNbs = Which Nbs value is associated with each contrast?
  //        cRes = Which resolution value is associated with each contrast?
  //        backs = List of all background values.
  //        shifts = List of all qz-shift values
  //        sf = List of all scalefactor values
  //        nba = List of all nba values
  //        nbs = List of all nbs values
  //        res = List of all resolution values
  //
  //  Outputs:
  //        backgs = list of actual background values for each contrast
  //        qshifts = list of actual shift values for each contrast
  //        sfs = list of actual shift values for each contrast
  //        nbas = list of actual shift values for each contrast
  //        nbss = list of actual shift values for each contrast
  //        nbss = list of actual shift values for each contrast
  //  backgs = 0;%zeros(1,nc);
  //  qshifts = 0;%zeros(1,nc);
  //  sfs = 0;%zeros(1,nc);
  //  nbas = 0;%zeros(1,nc);
  //  nbss = 0;%zeros(1,nc);
  //  resols = 0;%zeros(1,nc);
  // for i = 1:nc
  // thisBack = cBacks(i);
  if (cBacks != static_cast<int32_T>(muDoubleScalarFloor(cBacks))) {
    emlrtIntegerCheckR2012b(cBacks, &y_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(cBacks);
  if ((i < 1) || (i > backs.size(1))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, backs.size(1), &yd_emlrtBCI, sp);
  }

  *backg = backs[i - 1];

  // thisShift = cShifts(i);
  if (cShifts != static_cast<int32_T>(muDoubleScalarFloor(cShifts))) {
    emlrtIntegerCheckR2012b(cShifts, &ab_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(cShifts);
  if ((i < 1) || (i > shifts.size(1))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, shifts.size(1), &ae_emlrtBCI, sp);
  }

  *qshift = shifts[i - 1];

  // thisScale = cScales(i);
  if (cScales != static_cast<int32_T>(muDoubleScalarFloor(cScales))) {
    emlrtIntegerCheckR2012b(cScales, &bb_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(cScales);
  if ((i < 1) || (i > sf.size(1))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, sf.size(1), &be_emlrtBCI, sp);
  }

  *b_sf = sf[i - 1];

  // thisNbair = cNbas(i);
  if (cNbas != static_cast<int32_T>(muDoubleScalarFloor(cNbas))) {
    emlrtIntegerCheckR2012b(cNbas, &cb_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(cNbas);
  if ((i < 1) || (i > nba.size(1))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, nba.size(1), &ce_emlrtBCI, sp);
  }

  *b_nba = nba[i - 1];

  // thisNbsub = cNbss(i);
  if (cNbss != static_cast<int32_T>(muDoubleScalarFloor(cNbss))) {
    emlrtIntegerCheckR2012b(cNbss, &db_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(cNbss);
  if ((i < 1) || (i > nbs.size(1))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, nbs.size(1), &de_emlrtBCI, sp);
  }

  *b_nbs = nbs[i - 1];

  // thisResol = cRes(i);
  if (cRes != static_cast<int32_T>(muDoubleScalarFloor(cRes))) {
    emlrtIntegerCheckR2012b(cRes, &eb_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(cRes);
  if ((i < 1) || (i > res.size(1))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, res.size(1), &ee_emlrtBCI, sp);
  }

  *resol = res[i - 1];

  // end
}

// End of code generation (backSort.cpp)
