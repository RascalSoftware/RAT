//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// extractProblemParams.cpp
//
// Code generation for function 'extractProblemParams'
//

// Include files
#include "extractProblemParams.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void extractProblemParams(
    const struct0_T *problemDef, double *numberOfContrasts,
    coder::array<char, 2U> &geometry, coder::array<double, 2U> &cBacks,
    coder::array<double, 2U> &cShifts, coder::array<double, 2U> &cScales,
    coder::array<double, 2U> &cNbas, coder::array<double, 2U> &cNbss,
    coder::array<double, 2U> &cRes, coder::array<double, 2U> &backs,
    coder::array<double, 2U> &shifts, coder::array<double, 2U> &sf,
    coder::array<double, 2U> &nba, coder::array<double, 2U> &nbs,
    coder::array<double, 2U> &res, coder::array<double, 2U> &dataPresent,
    double *nParams, coder::array<double, 2U> &params, double *numberOfLayers,
    coder::array<double, 2U> &resample, coder::array<double, 2U> &backsType)
{
  int b_nParams;
  int i;
  int loop_ub;
  // Extract individual parameters from problemDef
  geometry.set_size(1, problemDef->geometry.size(1));
  loop_ub = problemDef->geometry.size(1);
  for (i = 0; i < loop_ub; i++) {
    geometry[i] = problemDef->geometry[i];
  }
  cBacks.set_size(1, problemDef->contrastBacks.size(1));
  loop_ub = problemDef->contrastBacks.size(1);
  for (i = 0; i < loop_ub; i++) {
    cBacks[i] = problemDef->contrastBacks[i];
  }
  cShifts.set_size(1, problemDef->contrastShifts.size(1));
  loop_ub = problemDef->contrastShifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    cShifts[i] = problemDef->contrastShifts[i];
  }
  cScales.set_size(1, problemDef->contrastScales.size(1));
  loop_ub = problemDef->contrastScales.size(1);
  for (i = 0; i < loop_ub; i++) {
    cScales[i] = problemDef->contrastScales[i];
  }
  cNbas.set_size(1, problemDef->contrastNbas.size(1));
  loop_ub = problemDef->contrastNbas.size(1);
  for (i = 0; i < loop_ub; i++) {
    cNbas[i] = problemDef->contrastNbas[i];
  }
  cNbss.set_size(1, problemDef->contrastNbss.size(1));
  loop_ub = problemDef->contrastNbss.size(1);
  for (i = 0; i < loop_ub; i++) {
    cNbss[i] = problemDef->contrastNbss[i];
  }
  cRes.set_size(1, problemDef->contrastRes.size(1));
  loop_ub = problemDef->contrastRes.size(1);
  for (i = 0; i < loop_ub; i++) {
    cRes[i] = problemDef->contrastRes[i];
  }
  backs.set_size(1, problemDef->backs.size(1));
  loop_ub = problemDef->backs.size(1);
  for (i = 0; i < loop_ub; i++) {
    backs[i] = problemDef->backs[i];
  }
  shifts.set_size(1, problemDef->shifts.size(1));
  loop_ub = problemDef->shifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    shifts[i] = problemDef->shifts[i];
  }
  sf.set_size(1, problemDef->sf.size(1));
  loop_ub = problemDef->sf.size(1);
  for (i = 0; i < loop_ub; i++) {
    sf[i] = problemDef->sf[i];
  }
  nba.set_size(1, problemDef->nba.size(1));
  loop_ub = problemDef->nba.size(1);
  for (i = 0; i < loop_ub; i++) {
    nba[i] = problemDef->nba[i];
  }
  nbs.set_size(1, problemDef->nbs.size(1));
  loop_ub = problemDef->nbs.size(1);
  for (i = 0; i < loop_ub; i++) {
    nbs[i] = problemDef->nbs[i];
  }
  res.set_size(1, problemDef->res.size(1));
  loop_ub = problemDef->res.size(1);
  for (i = 0; i < loop_ub; i++) {
    res[i] = problemDef->res[i];
  }
  dataPresent.set_size(1, problemDef->dataPresent.size(1));
  loop_ub = problemDef->dataPresent.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataPresent[i] = problemDef->dataPresent[i];
  }
  b_nParams = problemDef->params.size(1);
  params.set_size(1, problemDef->params.size(1));
  loop_ub = problemDef->params.size(1);
  for (i = 0; i < loop_ub; i++) {
    params[i] = problemDef->params[i];
  }
  resample.set_size(1, problemDef->resample.size(1));
  loop_ub = problemDef->resample.size(1);
  for (i = 0; i < loop_ub; i++) {
    resample[i] = problemDef->resample[i];
  }
  backsType.set_size(1, problemDef->contrastBacksType.size(1));
  loop_ub = problemDef->contrastBacksType.size(1);
  for (i = 0; i < loop_ub; i++) {
    backsType[i] = problemDef->contrastBacksType[i];
  }
  *numberOfContrasts = problemDef->numberOfContrasts;
  *nParams = b_nParams;
  *numberOfLayers = problemDef->numberOfLayers;
}

void extractProblemParams(
    const struct0_T *problemDef, double *numberOfContrasts,
    coder::array<char, 2U> &geometry, coder::array<double, 2U> &cBacks,
    coder::array<double, 2U> &cShifts, coder::array<double, 2U> &cScales,
    coder::array<double, 2U> &cNbas, coder::array<double, 2U> &cNbss,
    coder::array<double, 2U> &cRes, coder::array<double, 2U> &backs,
    coder::array<double, 2U> &shifts, coder::array<double, 2U> &sf,
    coder::array<double, 2U> &nba, coder::array<double, 2U> &nbs,
    coder::array<double, 2U> &res, coder::array<double, 2U> &dataPresent,
    double *nParams, coder::array<double, 2U> &params, double *numberOfLayers,
    coder::array<double, 2U> &resample, coder::array<double, 2U> &backsType,
    coder::array<double, 2U> &cFiles)
{
  int b_nParams;
  int i;
  int loop_ub;
  // Extract individual parameters from problemDef
  geometry.set_size(1, problemDef->geometry.size(1));
  loop_ub = problemDef->geometry.size(1);
  for (i = 0; i < loop_ub; i++) {
    geometry[i] = problemDef->geometry[i];
  }
  cBacks.set_size(1, problemDef->contrastBacks.size(1));
  loop_ub = problemDef->contrastBacks.size(1);
  for (i = 0; i < loop_ub; i++) {
    cBacks[i] = problemDef->contrastBacks[i];
  }
  cShifts.set_size(1, problemDef->contrastShifts.size(1));
  loop_ub = problemDef->contrastShifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    cShifts[i] = problemDef->contrastShifts[i];
  }
  cScales.set_size(1, problemDef->contrastScales.size(1));
  loop_ub = problemDef->contrastScales.size(1);
  for (i = 0; i < loop_ub; i++) {
    cScales[i] = problemDef->contrastScales[i];
  }
  cNbas.set_size(1, problemDef->contrastNbas.size(1));
  loop_ub = problemDef->contrastNbas.size(1);
  for (i = 0; i < loop_ub; i++) {
    cNbas[i] = problemDef->contrastNbas[i];
  }
  cNbss.set_size(1, problemDef->contrastNbss.size(1));
  loop_ub = problemDef->contrastNbss.size(1);
  for (i = 0; i < loop_ub; i++) {
    cNbss[i] = problemDef->contrastNbss[i];
  }
  cRes.set_size(1, problemDef->contrastRes.size(1));
  loop_ub = problemDef->contrastRes.size(1);
  for (i = 0; i < loop_ub; i++) {
    cRes[i] = problemDef->contrastRes[i];
  }
  backs.set_size(1, problemDef->backs.size(1));
  loop_ub = problemDef->backs.size(1);
  for (i = 0; i < loop_ub; i++) {
    backs[i] = problemDef->backs[i];
  }
  shifts.set_size(1, problemDef->shifts.size(1));
  loop_ub = problemDef->shifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    shifts[i] = problemDef->shifts[i];
  }
  sf.set_size(1, problemDef->sf.size(1));
  loop_ub = problemDef->sf.size(1);
  for (i = 0; i < loop_ub; i++) {
    sf[i] = problemDef->sf[i];
  }
  nba.set_size(1, problemDef->nba.size(1));
  loop_ub = problemDef->nba.size(1);
  for (i = 0; i < loop_ub; i++) {
    nba[i] = problemDef->nba[i];
  }
  nbs.set_size(1, problemDef->nbs.size(1));
  loop_ub = problemDef->nbs.size(1);
  for (i = 0; i < loop_ub; i++) {
    nbs[i] = problemDef->nbs[i];
  }
  res.set_size(1, problemDef->res.size(1));
  loop_ub = problemDef->res.size(1);
  for (i = 0; i < loop_ub; i++) {
    res[i] = problemDef->res[i];
  }
  dataPresent.set_size(1, problemDef->dataPresent.size(1));
  loop_ub = problemDef->dataPresent.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataPresent[i] = problemDef->dataPresent[i];
  }
  b_nParams = problemDef->params.size(1);
  params.set_size(1, problemDef->params.size(1));
  loop_ub = problemDef->params.size(1);
  for (i = 0; i < loop_ub; i++) {
    params[i] = problemDef->params[i];
  }
  resample.set_size(1, problemDef->resample.size(1));
  loop_ub = problemDef->resample.size(1);
  for (i = 0; i < loop_ub; i++) {
    resample[i] = problemDef->resample[i];
  }
  backsType.set_size(1, problemDef->contrastBacksType.size(1));
  loop_ub = problemDef->contrastBacksType.size(1);
  for (i = 0; i < loop_ub; i++) {
    backsType[i] = problemDef->contrastBacksType[i];
  }
  cFiles.set_size(1, problemDef->contrastCustomFiles.size(1));
  loop_ub = problemDef->contrastCustomFiles.size(1);
  for (i = 0; i < loop_ub; i++) {
    cFiles[i] = problemDef->contrastCustomFiles[i];
  }
  *numberOfContrasts = problemDef->numberOfContrasts;
  *nParams = b_nParams;
  *numberOfLayers = problemDef->numberOfLayers;
}

// End of code generation (extractProblemParams.cpp)
