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
  struct struct15_T
  {
    real_T Y;
    real_T N;
  };

  struct cell_wrap_2
  {
    real_T f1[2];
  };

  struct cell_wrap_8
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_38
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_10
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct struct6_T
  {
    ::coder::array<real_T, 1U> allChis;
    real_T sumChi;
  };

  struct cell_wrap_1
  {
    ::coder::array<char_T, 2U> f1;
  };

  struct cell_wrap_31
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct struct14_T
  {
    real_T d;
    real_T N;
    real_T T;
    boolean_T parallel;
    real_T CPU;
    real_T lambda;
    real_T pUnitGamma;
    real_T nCR;
    real_T delta;
    real_T steps;
    real_T zeta;
    char_T outlier[3];
    boolean_T adaptPCR;
    real_T thinning;
    real_T epsilon;
    boolean_T ABC;
    boolean_T IO;
    boolean_T modout;
    boolean_T restart;
    boolean_T save;
    ::coder::array<real_T, 2U> R;
  };

  struct struct13_T
  {
    ::coder::bounded_array<real_T, 2000U, 2U> outlier;
    real_T RunTime;
    struct14_T DREAMPar;
    struct15_T Meas_info;
    real_T iteration;
    real_T iloc;
    real_T fx;
    ::coder::bounded_array<real_T, 2000U, 2U> AR;
    ::coder::array<real_T, 2U> R_stat;
    ::coder::array<real_T, 2U> CR;
  };

  struct struct1_T
  {
    ::coder::array<real_T, 2U> param;
    ::coder::array<real_T, 2U> backgroundParam;
    ::coder::array<real_T, 2U> scalefactor;
    ::coder::array<real_T, 2U> qzshift;
    ::coder::array<real_T, 2U> bulkIn;
    ::coder::array<real_T, 2U> bulkOut;
    ::coder::array<real_T, 2U> resolutionParam;
    ::coder::array<real_T, 2U> domainRatio;
  };

  struct struct3_T
  {
    ::coder::array<real_T, 2U> fitParam;
    ::coder::array<real_T, 2U> fitBackgroundParam;
    ::coder::array<real_T, 2U> fitQzshift;
    ::coder::array<real_T, 2U> fitScalefactor;
    ::coder::array<real_T, 2U> fitBulkIn;
    ::coder::array<real_T, 2U> fitBulkOut;
    ::coder::array<real_T, 2U> fitResolutionParam;
    ::coder::array<real_T, 2U> fitDomainRatio;
  };

  struct struct2_T
  {
    ::coder::bounded_array<char_T, 10000U, 2U> procedure;
    ::coder::bounded_array<char_T, 10000U, 2U> parallel;
    real_T resamPars[2];
    boolean_T calcSldDuringFit;
    ::coder::bounded_array<char_T, 10000U, 2U> display;
    real_T tolX;
    real_T tolFun;
    real_T maxFunEvals;
    real_T maxIter;
    real_T updateFreq;
    real_T updatePlotFreq;
    real_T populationSize;
    real_T fWeight;
    real_T crossoverProbability;
    real_T strategy;
    real_T targetValue;
    real_T numGenerations;
    real_T Nlive;
    real_T Nmcmc;
    real_T propScale;
    real_T nsTolerance;
    real_T nSamples;
    real_T nChains;
    real_T jumpProbability;
    real_T pUnitGamma;
    ::coder::bounded_array<char_T, 10000U, 2U> boundHandling;
    boolean_T adaptPCR;
    struct3_T checks;
  };

  struct struct7_T
  {
    ::coder::array<real_T, 1U> ssubs;
    ::coder::array<real_T, 1U> backgroundParams;
    ::coder::array<real_T, 1U> qzshifts;
    ::coder::array<real_T, 1U> scalefactors;
    ::coder::array<real_T, 1U> bulkIn;
    ::coder::array<real_T, 1U> bulkOut;
    ::coder::array<real_T, 1U> resolutionParams;
    ::coder::array<real_T, 1U> allSubRough;
    ::coder::array<real_T, 2U> resample;
  };

  struct struct5_T
  {
    ::coder::array<cell_wrap_8, 1U> reflectivity;
    ::coder::array<cell_wrap_8, 1U> simulation;
    ::coder::array<cell_wrap_38, 1U> shiftedData;
    ::coder::array<cell_wrap_10, 2U> layerSlds;
    ::coder::array<cell_wrap_10, 2U> sldProfiles;
    ::coder::array<cell_wrap_38, 2U> allLayers;
    struct6_T calculationResults;
    struct7_T contrastParams;
    ::coder::array<real_T, 2U> bestFitPars;
    ::coder::array<cell_wrap_1, 1U> fitNames;
  };

  struct cell_wrap_64
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct struct11_T
  {
    ::coder::array<real_T, 2U> par95;
    ::coder::array<real_T, 2U> par65;
    ::coder::array<real_T, 2U> mean;
  };

  struct cell_0
  {
    ::coder::array<char_T, 2U> f1;
    ::coder::array<char_T, 2U> f2;
    real_T f3;
    real_T f4;
  };

  struct struct4_T
  {
    ::coder::array<cell_0, 1U> param;
    ::coder::array<cell_0, 1U> backgroundParam;
    ::coder::array<cell_0, 1U> resolutionParam;
    ::coder::array<cell_0, 1U> bulkIn;
    ::coder::array<cell_0, 1U> bulkOut;
    ::coder::array<cell_0, 1U> qzshift;
    ::coder::array<cell_0, 1U> scalefactor;
    ::coder::array<cell_0, 1U> domainRatio;
    ::coder::array<cell_wrap_1, 1U> priorNames;
    ::coder::array<real_T, 2U> priorValues;
  };

  struct struct9_T
  {
    ::coder::array<cell_wrap_10, 1U> ref;
    ::coder::array<cell_wrap_10, 2U> sld;
    real_T chi;
    ::coder::array<cell_wrap_10, 1U> data;
  };

  struct struct10_T
  {
    ::coder::array<cell_wrap_10, 1U> refPredInts;
    ::coder::array<cell_wrap_10, 2U> sldPredInts;
    ::coder::array<cell_wrap_10, 1U> refXdata;
    ::coder::array<cell_wrap_10, 2U> sldXdata;
    ::coder::bounded_array<real_T, 1000U, 1U> sampleChi;
  };

  struct cell_wrap_3
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_4
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_5
  {
    ::coder::bounded_array<real_T, 10U, 2U> f1;
  };

  struct cell_wrap_6
  {
    ::coder::bounded_array<char_T, 10000U, 2U> f1;
  };

  struct cell_7
  {
    ::coder::array<cell_wrap_2, 2U> f1;
    ::coder::array<cell_wrap_3, 2U> f2;
    ::coder::array<cell_wrap_2, 2U> f3;
    ::coder::array<cell_wrap_2, 2U> f4;
    ::coder::array<cell_wrap_4, 2U> f5;
    ::coder::array<cell_wrap_5, 1U> f6;
    ::coder::array<cell_wrap_6, 2U> f7;
    ::coder::array<cell_wrap_6, 2U> f8;
    ::coder::array<cell_wrap_6, 2U> f9;
    ::coder::array<cell_wrap_6, 2U> f10;
    ::coder::array<cell_wrap_6, 2U> f11;
    ::coder::array<cell_wrap_6, 2U> f12;
    ::coder::array<cell_wrap_6, 2U> f13;
    ::coder::array<cell_wrap_6, 2U> f14;
    ::coder::array<cell_wrap_6, 2U> f15;
    ::coder::array<cell_wrap_6, 2U> f16;
    ::coder::array<cell_wrap_3, 2U> f17;
    ::coder::array<cell_wrap_2, 2U> f18;
    ::coder::array<cell_wrap_4, 2U> f19;
    ::coder::array<cell_wrap_6, 2U> f20;
  };

  struct struct0_T
  {
    ::coder::array<real_T, 2U> contrastBackgrounds;
    ::coder::array<real_T, 2U> contrastBackgroundsType;
    ::coder::bounded_array<char_T, 10000U, 2U> TF;
    ::coder::array<real_T, 2U> resample;
    ::coder::array<real_T, 2U> dataPresent;
    ::coder::array<real_T, 2U> oilChiDataPresent;
    real_T numberOfContrasts;
    ::coder::bounded_array<char_T, 10000U, 2U> geometry;
    boolean_T useImaginary;
    ::coder::array<real_T, 2U> contrastQzshifts;
    ::coder::array<real_T, 2U> contrastScalefactors;
    ::coder::array<real_T, 2U> contrastBulkIns;
    ::coder::array<real_T, 2U> contrastBulkOuts;
    ::coder::array<real_T, 2U> contrastResolutions;
    ::coder::array<real_T, 2U> backgroundParams;
    ::coder::array<real_T, 2U> qzshifts;
    ::coder::array<real_T, 2U> scalefactors;
    ::coder::array<real_T, 2U> bulkIn;
    ::coder::array<real_T, 2U> bulkOut;
    ::coder::array<real_T, 2U> resolutionParams;
    ::coder::array<real_T, 2U> params;
    real_T numberOfLayers;
    ::coder::bounded_array<char_T, 10000U, 2U> modelType;
    ::coder::array<real_T, 2U> contrastCustomFiles;
    ::coder::array<real_T, 2U> contrastDomainRatios;
    ::coder::array<real_T, 2U> domainRatio;
    real_T numberOfDomainContrasts;
    ::coder::array<real_T, 2U> fitParams;
    ::coder::array<real_T, 2U> otherParams;
    ::coder::array<real_T, 2U> fitLimits;
    ::coder::array<real_T, 2U> otherLimits;
  };

  struct struct16_T
  {
    real_T LogZ;
    ::coder::array<real_T, 2U> nestSamples;
    ::coder::array<real_T, 2U> postSamples;
  };

  struct struct12_T
  {
    ::coder::array<real_T, 3U> allChains;
    struct13_T dreamOutput;
    struct16_T nestOutput;
  };

  struct struct8_T
  {
    struct9_T bestFitsMean;
    struct10_T predlims;
    struct11_T parConfInts;
    ::coder::array<real_T, 2U> bestPars;
    struct12_T bayesRes;
    ::coder::array<real_T, 2U> chain;
  };

  struct RATMainTLS
  {
    struct {
      int32_T belowVals_data[10000];
      int32_T aboveVals_data[10000];
    } f0;

    struct {
      real_T thisContrastLayers1_data[6000];
      real_T thisContrastLayers2_data[6000];
    } f1;

    struct {
      real_T thisContrastLayers_data[6000];
    } f2;
  };
}

#endif

// End of code generation (RATMain_types.h)
