//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customBilayer_spec.h
//
// Code generation for function 'customBilayer'
//

#ifndef CUSTOMBILAYER_SPEC_H
#define CUSTOMBILAYER_SPEC_H

// Include files
#ifdef CUSTOMBILAYER_XIL_BUILD
#if defined(_MSC_VER) || defined(__LCC__)
#define CUSTOMBILAYER_DLL_EXPORT __declspec(dllimport)
#else
#define CUSTOMBILAYER_DLL_EXPORT __attribute__((visibility("default")))
#endif
#elif defined(BUILDING_CUSTOMBILAYER)
#if defined(_MSC_VER) || defined(__LCC__)
#define CUSTOMBILAYER_DLL_EXPORT __declspec(dllexport)
#else
#define CUSTOMBILAYER_DLL_EXPORT __attribute__((visibility("default")))
#endif
#else
#define CUSTOMBILAYER_DLL_EXPORT
#endif

#endif
// End of code generation (customBilayer_spec.h)
