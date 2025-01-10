//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
    real_T f1[2];
  };

  struct cell_wrap_11
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct struct12_T
  {
    real_T nParams;
    real_T nChains;
    real_T nGenerations;
    boolean_T parallel;
    real_T CPU;
    real_T jumpProbability;
    real_T pUnitGamma;
    real_T nCR;
    real_T delta;
    real_T steps;
    real_T zeta;
    char_T outlier[3];
    boolean_T adaptPCR;
    real_T thinning;
    boolean_T ABC;
    real_T epsilon;
    boolean_T IO;
    boolean_T storeOutput;
    ::coder::array<real_T, 2U> R;
  };

  struct struct13_T
  {
    ::coder::array<real_T, 3U> allChains;
    ::coder::bounded_array<real_T, 2000U, 2U> outlierChains;
    real_T runtime;
    real_T iteration;
    real_T modelOutput;
    ::coder::bounded_array<real_T, 2000U, 2U> AR;
    ::coder::array<real_T, 2U> R_stat;
    ::coder::array<real_T, 2U> CR;
  };

  struct cell_wrap_1
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_48
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_7
  {
    ::coder::array<char_T, 2U> f1;
  };

  struct cell_wrap_10
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct struct2_T
  {
    ::coder::array<real_T, 2U> params;
    ::coder::array<real_T, 2U> backgroundParams;
    ::coder::array<real_T, 2U> scalefactors;
    ::coder::array<real_T, 2U> qzshifts;
    ::coder::array<real_T, 2U> bulkIns;
    ::coder::array<real_T, 2U> bulkOuts;
    ::coder::array<real_T, 2U> resolutionParams;
    ::coder::array<real_T, 2U> domainRatios;
  };

  struct struct4_T
  {
    ::coder::bounded_array<char_T, 10000U, 2U> procedure;
    ::coder::bounded_array<char_T, 10000U, 2U> parallel;
    real_T resampleMinAngle;
    real_T resampleNPoints;
    boolean_T calcSldDuringFit;
    ::coder::bounded_array<char_T, 10000U, 2U> display;
    real_T xTolerance;
    real_T funcTolerance;
    real_T maxFuncEvals;
    real_T maxIterations;
    real_T updateFreq;
    real_T updatePlotFreq;
    real_T populationSize;
    real_T fWeight;
    real_T crossoverProbability;
    real_T strategy;
    real_T targetValue;
    real_T numGenerations;
    real_T nLive;
    real_T nMCMC;
    real_T propScale;
    real_T nsTolerance;
    real_T nSamples;
    real_T nChains;
    real_T jumpProbability;
    real_T pUnitGamma;
    ::coder::bounded_array<char_T, 10000U, 2U> boundHandling;
    boolean_T adaptPCR;
    ::coder::bounded_array<char_T, 10000U, 2U> IPCFilePath;
  };

  struct cell_wrap_8
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_9
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct struct7_T
  {
    ::coder::array<real_T, 1U> chiValues;
    real_T sumChi;
  };

  struct struct8_T
  {
    ::coder::array<real_T, 1U> scalefactors;
    ::coder::array<real_T, 1U> bulkIn;
    ::coder::array<real_T, 1U> bulkOut;
    ::coder::array<real_T, 1U> resolutionParams;
    ::coder::array<real_T, 1U> subRoughs;
    ::coder::array<real_T, 2U> resample;
  };

  struct struct6_T
  {
    ::coder::array<cell_wrap_8, 1U> reflectivity;
    ::coder::array<cell_wrap_8, 1U> simulation;
    ::coder::array<cell_wrap_9, 1U> shiftedData;
    ::coder::array<cell_wrap_9, 1U> backgrounds;
    ::coder::array<cell_wrap_10, 2U> layerSlds;
    ::coder::array<cell_wrap_10, 2U> sldProfiles;
    ::coder::array<cell_wrap_10, 2U> resampledLayers;
    struct7_T calculationResults;
    struct8_T contrastParams;
    ::coder::array<real_T, 2U> fitParams;
    ::coder::array<cell_wrap_7, 1U> fitNames;
  };

  struct struct3_T
  {
    ::coder::array<real_T, 2U> params;
    ::coder::array<real_T, 2U> backgroundParams;
    ::coder::array<real_T, 2U> scalefactors;
    ::coder::array<real_T, 2U> qzshifts;
    ::coder::array<real_T, 2U> bulkIns;
    ::coder::array<real_T, 2U> bulkOuts;
    ::coder::array<real_T, 2U> resolutionParams;
    ::coder::array<real_T, 2U> domainRatios;
  };

  struct cell_6
  {
    ::coder::bounded_array<char_T, 10000U, 2U> f1;
    ::coder::bounded_array<char_T, 10000U, 2U> f2;
    real_T f3;
    real_T f4;
  };

  struct struct5_T
  {
    ::coder::array<cell_6, 1U> params;
    ::coder::array<cell_6, 1U> backgroundParams;
    ::coder::array<cell_6, 1U> scalefactors;
    ::coder::array<cell_6, 1U> qzshifts;
    ::coder::array<cell_6, 1U> bulkIns;
    ::coder::array<cell_6, 1U> bulkOuts;
    ::coder::array<cell_6, 1U> resolutionParams;
    ::coder::array<cell_6, 1U> domainRatios;
    ::coder::array<cell_wrap_7, 1U> priorNames;
    ::coder::array<real_T, 2U> priorValues;
  };

  struct struct10_T
  {
    ::coder::array<cell_wrap_11, 1U> reflectivity;
    ::coder::array<cell_wrap_11, 2U> sld;
    ::coder::bounded_array<real_T, 1000U, 1U> sampleChi;
  };

  struct struct11_T
  {
    ::coder::array<real_T, 2U> percentile95;
    ::coder::array<real_T, 2U> percentile65;
    ::coder::array<real_T, 2U> mean;
  };

  struct cell_wrap_3
  {
    ::coder::bounded_array<real_T, 5U, 2U> f1;
  };

  struct cell_wrap_0
  {
    ::coder::bounded_array<char_T, 10000U, 2U> f1;
  };

  struct cell_wrap_4
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_5
  {
    ::coder::bounded_array<real_T, 10U, 2U> f1;
  };

  struct struct1_T
  {
    ::coder::array<cell_wrap_0, 2U> params;
    ::coder::array<cell_wrap_0, 2U> backgroundParams;
    ::coder::array<cell_wrap_0, 2U> scalefactors;
    ::coder::array<cell_wrap_0, 2U> qzshifts;
    ::coder::array<cell_wrap_0, 2U> bulkIns;
    ::coder::array<cell_wrap_0, 2U> bulkOuts;
    ::coder::array<cell_wrap_0, 2U> resolutionParams;
    ::coder::array<cell_wrap_0, 2U> domainRatios;
    ::coder::array<cell_wrap_0, 2U> contrasts;
  };

  struct struct0_T
  {
    ::coder::bounded_array<char_T, 10000U, 2U> TF;
    ::coder::array<real_T, 2U> resample;
    ::coder::array<cell_wrap_1, 2U> data;
    ::coder::array<real_T, 2U> dataPresent;
    ::coder::array<cell_wrap_2, 2U> dataLimits;
    ::coder::array<cell_wrap_2, 2U> simulationLimits;
    ::coder::array<real_T, 2U> oilChiDataPresent;
    real_T numberOfContrasts;
    ::coder::bounded_array<char_T, 10000U, 2U> geometry;
    boolean_T useImaginary;
    ::coder::array<cell_wrap_2, 2U> repeatLayers;
    ::coder::array<cell_wrap_3, 2U> contrastBackgroundParams;
    ::coder::array<cell_wrap_0, 2U> contrastBackgroundTypes;
    ::coder::array<cell_wrap_0, 2U> contrastBackgroundActions;
    ::coder::array<real_T, 2U> contrastQzshifts;
    ::coder::array<real_T, 2U> contrastScalefactors;
    ::coder::array<real_T, 2U> contrastBulkIns;
    ::coder::array<real_T, 2U> contrastBulkOuts;
    ::coder::array<real_T, 2U> contrastResolutionParams;
    ::coder::array<real_T, 2U> backgroundParams;
    ::coder::array<real_T, 2U> qzshifts;
    ::coder::array<real_T, 2U> scalefactors;
    ::coder::array<real_T, 2U> bulkIns;
    ::coder::array<real_T, 2U> bulkOuts;
    ::coder::array<real_T, 2U> resolutionParams;
    ::coder::array<real_T, 2U> params;
    real_T numberOfLayers;
    ::coder::array<cell_wrap_4, 2U> contrastLayers;
    ::coder::array<cell_wrap_5, 2U> layersDetails;
    ::coder::array<cell_wrap_0, 2U> customFiles;
    ::coder::bounded_array<char_T, 10000U, 2U> modelType;
    ::coder::array<real_T, 2U> contrastCustomFiles;
    ::coder::array<real_T, 2U> contrastDomainRatios;
    ::coder::array<real_T, 2U> domainRatios;
    real_T numberOfDomainContrasts;
    ::coder::array<cell_wrap_4, 2U> domainContrastLayers;
    ::coder::array<real_T, 2U> fitParams;
    ::coder::array<real_T, 2U> otherParams;
    ::coder::array<real_T, 2U> fitLimits;
    ::coder::array<real_T, 2U> otherLimits;
    struct1_T names;
    struct2_T checks;
  };

  struct struct14_T
  {
    real_T LogZ;
    ::coder::array<real_T, 2U> nestSamples;
    ::coder::array<real_T, 2U> postSamples;
  };

  struct struct9_T
  {
    struct10_T predictionIntervals;
    struct11_T confidenceIntervals;
    struct12_T dreamParams;
    struct13_T dreamOutput;
    struct14_T nestedSamplerOutput;
    ::coder::array<real_T, 2U> chain;
  };
}

#endif

// End of code generation (RATMain_types.h)
