//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain_internal_types.h
//
// Code generation for function 'RATMain'
//
#ifndef RATMAIN_INTERNAL_TYPES_H
#define RATMAIN_INTERNAL_TYPES_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
namespace RAT
{
  struct cell_wrap_51
  {
    double f1[6];
  };

  struct struct_T
  {
    double LogZ;
    double LogZErr;
    ::coder::bounded_array<double, 2U, 2U> nestSamples;
    ::coder::bounded_array<double, 2U, 2U> postSamples;
  };

  struct cell_wrap_49
  {
    ::coder::array<double, 1U> f1;
  };

  struct cell_wrap_45
  {
    ::coder::array<cell_wrap_11, 1U> f1;
  };

  struct cell_wrap_46
  {
    ::coder::array<cell_wrap_11, 2U> f1;
  };

  struct cell_wrap_44
  {
    ::coder::array<double, 2U> f1;
  };

  struct ParamNames
  {
    ::coder::array<cell_wrap_10, 2U> params;
    ::coder::array<cell_wrap_10, 2U> backgroundParams;
    ::coder::array<cell_wrap_10, 2U> scalefactors;
    ::coder::array<cell_wrap_10, 2U> bulkIns;
    ::coder::array<cell_wrap_10, 2U> bulkOuts;
    ::coder::array<cell_wrap_10, 2U> resolutionParams;
    ::coder::array<cell_wrap_10, 2U> domainRatios;
    ::coder::array<cell_wrap_10, 2U> contrasts;
  };

  struct ProblemDefinition
  {
    ::coder::bounded_array<char, 10000U, 2U> TF;
    ::coder::array<double, 2U> resample;
    ::coder::array<cell_wrap_1, 2U> data;
    ::coder::array<double, 2U> dataPresent;
    ::coder::array<cell_wrap_2, 2U> dataLimits;
    ::coder::array<cell_wrap_2, 2U> simulationLimits;
    double numberOfContrasts;
    ::coder::bounded_array<char, 10000U, 2U> geometry;
    boolean_T useImaginary;
    ::coder::array<double, 2U> repeatLayers;
    ::coder::array<cell_wrap_44, 2U> contrastBackgroundParams;
    ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
    ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
    ::coder::array<double, 2U> contrastScalefactors;
    ::coder::array<double, 2U> contrastBulkIns;
    ::coder::array<double, 2U> contrastBulkOuts;
    ::coder::array<cell_wrap_9, 2U> contrastResolutionParams;
    ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
    ::coder::array<double, 2U> backgroundParams;
    ::coder::array<double, 2U> scalefactors;
    ::coder::array<double, 2U> bulkIns;
    ::coder::array<double, 2U> bulkOuts;
    ::coder::array<double, 2U> resolutionParams;
    ::coder::array<double, 2U> params;
    double numberOfLayers;
    ::coder::array<cell_wrap_9, 2U> contrastLayers;
    ::coder::array<cell_wrap_9, 2U> layersDetails;
    ::coder::array<cell_wrap_10, 2U> customFiles;
    ::coder::bounded_array<char, 10000U, 2U> modelType;
    ::coder::array<double, 2U> contrastCustomFiles;
    ::coder::array<double, 2U> contrastDomainRatios;
    ::coder::array<double, 2U> domainRatios;
    double numberOfDomainContrasts;
    ::coder::array<cell_wrap_9, 2U> domainContrastLayers;
    ::coder::array<double, 2U> fitParams;
    ::coder::array<double, 2U> fitLimits;
    ::coder::array<cell_wrap_10, 1U> priorNames;
    ::coder::array<double, 2U> priorValues;
    ParamNames names;
    CheckFlags checks;
  };

  struct b_struct_T
  {
    ::coder::array<cell_wrap_7, 1U> reflectivity;
    ::coder::array<cell_wrap_7, 1U> simulation;
    ::coder::array<cell_wrap_8, 1U> shiftedData;
    ::coder::array<cell_wrap_8, 1U> backgrounds;
    ::coder::array<cell_wrap_7, 1U> resolutions;
    ::coder::array<cell_wrap_7, 2U> sldProfiles;
    ::coder::array<cell_wrap_9, 2U> layers;
    ::coder::array<cell_wrap_9, 2U> resampledLayers;
    CalculationResults calculationResults;
    ContrastParams contrastParams;
    ::coder::array<double, 2U> fitParams;
    ::coder::array<cell_wrap_10, 1U> fitNames;
  };

  struct c_struct_T
  {
    PredictionIntervals predictionIntervals;
    ConfidenceIntervals confidenceIntervals;
    DreamParams dreamParams;
    DreamOutput dreamOutput;
    struct_T nestedSamplerOutput;
    ::coder::array<double, 2U> chain;
  };

  struct d_struct_T
  {
    ::coder::array<cell_wrap_11, 1U> reflectivity;
    ::coder::array<cell_wrap_11, 2U> sld;
    double sampleChi[1000];
  };

  struct e_struct_T
  {
    d_struct_T predictionIntervals;
    ConfidenceIntervals confidenceIntervals;
  };

  struct f_struct_T
  {
    ::coder::bounded_array<double, 2000U, 2U> outlierChains;
    double runtime;
    DreamParams DREAMPar;
    double iteration;
    double iloc;
    double modelOutput;
    ::coder::bounded_array<double, 2000U, 2U> AR;
    ::coder::array<double, 2U> R_stat;
    ::coder::array<double, 2U> CR;
  };

  struct g_struct_T
  {
    double iterations;
    double funcCount;
    char algorithm[33];
    ::coder::array<char, 2U> message;
  };

  struct h_struct_T
  {
    double I_lentol;
    double FVr_x[50];
    double FVr_lim_up[50];
    double FVr_lim_lo[50];
    double I_NP;
    double fWeight;
    double F_CR;
    double I_D;
    ::coder::array<double, 2U> FVr_minbound;
    ::coder::array<double, 2U> FVr_maxbound;
    double I_bnd_constr;
    double I_itermax;
    double F_VTR;
    double I_strategy;
    double I_refresh;
    double I_plotting;
    ::coder::array<double, 2U> FM_pop;
    ::coder::array<double, 2U> FVr_bestmem;
  };

  struct cell_52
  {
    ::coder::array<double, 2U> f1;
  };

  struct i_struct_T
  {
    ::coder::array<double, 1U> LB;
    ::coder::array<double, 1U> UB;
    ::coder::array<double, 1U> BoundClass;
  };

  struct j_struct_T
  {
    double I_no;
    double FVr_oa;
  };
}

#endif

// End of code generation (RATMain_internal_types.h)
