/* Copyright 2020 The MathWorks, Inc. */
#include "coder_setenv.h"

#ifdef _MSC_VER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#else
#define _POSIX_C_SOURCE 200112L
#include <stdlib.h>
#endif

void portableSetEnv(const char* aName, const char* aValue) {
#ifdef _MSC_VER
    char* pvBuffer = (char*)malloc(strlen(aName) + strlen(aValue) + 2);
    sprintf(pvBuffer, "%s=%s", aName, aValue);
    _putenv(pvBuffer);
    free(pvBuffer);
#else
    setenv(aName, aValue, 1);
#endif
}
