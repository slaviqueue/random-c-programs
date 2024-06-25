#pragma once

#include <stdio.h>

#define _VARNAME(var) #var
#define LOGS(str) printf(str "\n")
#define LOGV(value, format) printf(_VARNAME(value) ": %" format "\n", value)
#define LOGN() printf("\n")
