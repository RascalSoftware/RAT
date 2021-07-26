//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation_spec.h
//
// Code generation for function 'reflectivity_calculation'
//

#ifndef REFLECTIVITY_CALCULATION_SPEC_H
#define REFLECTIVITY_CALCULATION_SPEC_H

// Include files
#ifdef REFLECTIVITY_CALCULATION_XIL_BUILD
#if defined(_MSC_VER) || defined(__LCC__)
#define REFLECTIVITY_CALCULATION_DLL_EXPORT __declspec(dllimport)
#else
#define REFLECTIVITY_CALCULATION_DLL_EXPORT                                    \
  __attribute__((visibility("default")))
#endif
#elif defined(BUILDING_REFLECTIVITY_CALCULATION)
#if defined(_MSC_VER) || defined(__LCC__)
#define REFLECTIVITY_CALCULATION_DLL_EXPORT __declspec(dllexport)
#else
#define REFLECTIVITY_CALCULATION_DLL_EXPORT                                    \
  __attribute__((visibility("default")))
#endif
#else
#define REFLECTIVITY_CALCULATION_DLL_EXPORT
#endif

#endif
// End of code generation (reflectivity_calculation_spec.h)
