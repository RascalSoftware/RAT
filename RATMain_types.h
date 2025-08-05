//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain_types.h
//
// Code generation for function 'RATMain'
//
#ifndef RATMAIN_TYPES_H
#define RATMAIN_TYPES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#define MAX_THREADS                    omp_get_max_threads()

// Type Definitions
namespace RAT
{
  struct cell_wrap_2
  {
    double f1[2];
  };

  struct cell_wrap_11
  {
    ::coder::array<double, 2U> f1;
  };

  struct DreamParams
  {
    double nParams;
    double nChains;
    double nGenerations;
    boolean_T parallel;
    double CPU;
    double jumpProbability;
    double pUnitGamma;
    double nCR;
    double delta;
    double steps;
    double zeta;
    char outlier[3];
    boolean_T adaptPCR;
    double thinning;
    boolean_T ABC;
    double epsilon;
    boolean_T IO;
    boolean_T storeOutput;
    ::coder::array<double, 2U> R;
  };

  struct DreamOutput
  {
    ::coder::array<double, 3U> allChains;
    ::coder::bounded_array<double, 2000U, 2U> outlierChains;
    double runtime;
    double iteration;
    ::coder::bounded_array<double, 2000U, 2U> AR;
    ::coder::array<double, 2U> R_stat;
    ::coder::array<double, 2U> CR;
  };

  struct cell_wrap_1
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_10
  {
    ::coder::array<char, 2U> f1;
  };

  struct cell_wrap_9
  {
    ::coder::array<double, 2U> f1;
  };

  struct CheckFlags
  {
    ::coder::array<double, 2U> params;
    ::coder::array<double, 2U> backgroundParams;
    ::coder::array<double, 2U> scalefactors;
    ::coder::array<double, 2U> bulkIns;
    ::coder::array<double, 2U> bulkOuts;
    ::coder::array<double, 2U> resolutionParams;
    ::coder::array<double, 2U> domainRatios;
  };

  struct Controls
  {
    ::coder::bounded_array<char, 10000U, 2U> procedure;
    ::coder::bounded_array<char, 10000U, 2U> parallel;
    double numSimulationPoints;
    double resampleMinAngle;
    double resampleNPoints;
    ::coder::bounded_array<char, 10000U, 2U> display;
    double xTolerance;
    double funcTolerance;
    double maxFuncEvals;
    double maxIterations;
    double updateFreq;
    double updatePlotFreq;
    double populationSize;
    double fWeight;
    double crossoverProbability;
    double strategy;
    double targetValue;
    double numGenerations;
    double nLive;
    double nMCMC;
    double propScale;
    double nsTolerance;
    double nSamples;
    double nChains;
    double jumpProbability;
    double pUnitGamma;
    ::coder::bounded_array<char, 10000U, 2U> boundHandling;
    boolean_T adaptPCR;
    boolean_T calcSLD;
    ::coder::bounded_array<char, 10000U, 2U> IPCFilePath;
  };

  struct cell_wrap_7
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_8
  {
    ::coder::array<double, 2U> f1;
  };

  struct CalculationResults
  {
    ::coder::array<double, 1U> chiValues;
    double sumChi;
  };

  struct ContrastParams
  {
    ::coder::array<double, 1U> scalefactors;
    ::coder::array<double, 1U> bulkIn;
    ::coder::array<double, 1U> bulkOut;
    ::coder::array<double, 1U> subRoughs;
    ::coder::array<double, 2U> resample;
  };

  struct PredictionIntervals
  {
    ::coder::array<cell_wrap_11, 1U> reflectivity;
    ::coder::array<cell_wrap_11, 2U> sld;
    ::coder::bounded_array<double, 1000U, 1U> sampleChi;
  };

  struct ConfidenceIntervals
  {
    ::coder::array<double, 2U> percentile95;
    ::coder::array<double, 2U> percentile65;
    ::coder::array<double, 2U> mean;
  };

  struct cell_wrap_3
  {
    ::coder::bounded_array<double, 5U, 2U> f1;
  };

  struct cell_wrap_0
  {
    ::coder::bounded_array<char, 10000U, 2U> f1;
  };

  struct cell_wrap_4
  {
    ::coder::bounded_array<double, 5U, 2U> f1;
  };

  struct cell_wrap_5
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_6
  {
    ::coder::bounded_array<double, 10U, 2U> f1;
  };

  struct b_ParamNames
  {
    ::coder::array<cell_wrap_0, 2U> params;
    ::coder::array<cell_wrap_0, 2U> backgroundParams;
    ::coder::array<cell_wrap_0, 2U> scalefactors;
    ::coder::array<cell_wrap_0, 2U> bulkIns;
    ::coder::array<cell_wrap_0, 2U> bulkOuts;
    ::coder::array<cell_wrap_0, 2U> resolutionParams;
    ::coder::array<cell_wrap_0, 2U> domainRatios;
    ::coder::array<cell_wrap_0, 2U> contrasts;
  };

  struct b_ProblemDefinition
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
    ::coder::array<cell_wrap_3, 2U> contrastBackgroundParams;
    ::coder::array<cell_wrap_0, 2U> contrastBackgroundTypes;
    ::coder::array<cell_wrap_0, 2U> contrastBackgroundActions;
    ::coder::array<double, 2U> contrastScalefactors;
    ::coder::array<double, 2U> contrastBulkIns;
    ::coder::array<double, 2U> contrastBulkOuts;
    ::coder::array<cell_wrap_4, 2U> contrastResolutionParams;
    ::coder::array<cell_wrap_0, 2U> contrastResolutionTypes;
    ::coder::array<double, 2U> backgroundParams;
    ::coder::array<double, 2U> scalefactors;
    ::coder::array<double, 2U> bulkIns;
    ::coder::array<double, 2U> bulkOuts;
    ::coder::array<double, 2U> resolutionParams;
    ::coder::array<double, 2U> params;
    double numberOfLayers;
    ::coder::array<cell_wrap_5, 2U> contrastLayers;
    ::coder::array<cell_wrap_6, 2U> layersDetails;
    ::coder::array<cell_wrap_0, 2U> customFiles;
    ::coder::bounded_array<char, 10000U, 2U> modelType;
    ::coder::array<double, 2U> contrastCustomFiles;
    ::coder::array<double, 2U> contrastDomainRatios;
    ::coder::array<double, 2U> domainRatios;
    double numberOfDomainContrasts;
    ::coder::array<cell_wrap_5, 2U> domainContrastLayers;
    ::coder::array<double, 2U> fitParams;
    ::coder::array<double, 2U> fitLimits;
    ::coder::array<cell_wrap_0, 1U> priorNames;
    ::coder::array<double, 2U> priorValues;
    b_ParamNames names;
    CheckFlags checks;
  };

  struct Results
  {
    ::coder::array<cell_wrap_7, 1U> reflectivity;
    ::coder::array<cell_wrap_7, 1U> simulation;
    ::coder::array<cell_wrap_8, 1U> shiftedData;
    ::coder::array<cell_wrap_8, 1U> backgrounds;
    ::coder::array<cell_wrap_7, 1U> resolutions;
    ::coder::array<cell_wrap_9, 2U> sldProfiles;
    ::coder::array<cell_wrap_9, 2U> layers;
    ::coder::array<cell_wrap_9, 2U> resampledLayers;
    CalculationResults calculationResults;
    ContrastParams contrastParams;
    ::coder::array<double, 2U> fitParams;
    ::coder::array<cell_wrap_10, 1U> fitNames;
  };

  struct NestedSamplerOutput
  {
    double LogZ;
    double LogZErr;
    ::coder::array<double, 2U> nestSamples;
    ::coder::array<double, 2U> postSamples;
  };

  struct BayesResults
  {
    PredictionIntervals predictionIntervals;
    ConfidenceIntervals confidenceIntervals;
    DreamParams dreamParams;
    DreamOutput dreamOutput;
    NestedSamplerOutput nestedSamplerOutput;
    ::coder::array<double, 2U> chain;
  };
}

#endif

// End of code generation (RATMain_types.h)
